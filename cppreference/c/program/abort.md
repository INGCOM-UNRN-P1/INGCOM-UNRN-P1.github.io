From cppreference.com

< [c](../../c.html "c")‎ | [program](../program.html "c/program")

[ C](../../c.html "c")

[Compiler support](../compiler_support.html "c/compiler support")  
---  
[Language](../language.html "c/language")  
[Headers](../header.html "c/header")  
[Type support](../types.html "c/types")  
[Program utilities](../program.html "c/program")  
[Variadic function support](../variadic.html "c/variadic")  
[Error handling](../error.html "c/error")  
[Dynamic memory management](../memory.html "c/memory")  
[Strings library](../string.html "c/string")  
[Algorithms](../algorithm.html "c/algorithm")  
[Numerics](../numeric.html "c/numeric")  
[Date and time utilities](../chrono.html "c/chrono")  
[Input/output support](../io.html "c/io")  
[Localization support](../locale.html "c/locale")  
[Concurrency support](../thread.html "c/thread") (C11)  
[Technical Specifications](../experimental.html "c/experimental")  
[Symbol index](../index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

[ Program support utilities](../program.html "c/program")

Program termination  
---  
| **abort**  
---  
[exit](exit.html "c/program/exit")  
[quick_exit](quick_exit.html "c/program/quick exit")(C11)  
[_Exit](_Exit.html "c/program/ Exit")(C99)  
  
| [atexit](atexit.html "c/program/atexit")  
---  
[at_quick_exit](at_quick_exit.html "c/program/at quick exit")(C11)  
[EXIT_SUCCESSEXIT_FAILURE](EXIT_status.html "c/program/EXIT status")  
  
Unreachable control flow  
[unreachable](unreachable.html "c/program/unreachable")(C23)  
Communicating with the environment  
| [getenvgetenv_s](getenv.html "c/program/getenv")(C11)  
---  
  
| [system](system.html "c/program/system")  
---  
  
  
  
Memory alignment query  
[memalignment](memalignment.html "c/program/memalignment")(C23)  
Signals  
| [signal](signal.html "c/program/signal")  
---  
[raise](raise.html "c/program/raise")  
[sig_atomic_t](sig_atomic_t.html "c/program/sig atomic t")  
  
| [SIG_DFLSIG_IGN](SIG_strategies.html "c/program/SIG strategies")  
---  
[SIG_ERR](SIG_ERR.html "c/program/SIG ERR")  
  
Signal types  
| [SIGABRTSIGFPESIGILL](SIG_types.html "c/program/SIG types")  
---  
  
| [SIGINTSIGSEGVSIGTERM](SIG_types.html "c/program/SIG types")  
---  
  
Non-local jumps  
| [setjmp](setjmp.html "c/program/setjmp")  
---  
  
| [longjmp](longjmp.html "c/program/longjmp")  
---  
  
Types  
[jmp_buf](jmp_buf.html "c/program/jmp buf")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/navbar_content&action=edit)

Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
void abort(void); |  | (until C11)  
_Noreturn void abort(void); |  |  (since C11)   
(until C23)  
[[noreturn]] void abort(void); |  |  (since C23)  
| |   
  
Causes abnormal program termination unless [SIGABRT](SIG_types.html "c/program/SIG types") is being caught by a signal handler passed to signal and the handler does not return. 

Functions passed to [atexit()](atexit.html "c/program/atexit") are not called. Whether open resources such as files are closed is implementation defined. An implementation defined status is returned to the host environment that indicates unsuccessful execution. 

## Contents

  * [1 Parameters](abort.html#Parameters)
  * [2 Return value](abort.html#Return_value)
  * [3 Notes](abort.html#Notes)
  * [4 Example](abort.html#Example)
  * [5 References](abort.html#References)
  * [6 See also](abort.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/abort&action=edit&section=1 "Edit section: Parameters")] Parameters

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/abort&action=edit&section=2 "Edit section: Return value")] Return value

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/abort&action=edit&section=3 "Edit section: Notes")] Notes

POSIX [specifies](https://pubs.opengroup.org/onlinepubs/9699919799/functions/abort.html) that the `abort()` function overrides blocking or ignoring the `SIGABRT` signal. 

Some compiler intrinsics, e.g. [`__builtin_trap`](https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html) (gcc, clang, and icc) or [`__fastfail`](https://learn.microsoft.com/en-us/cpp/intrinsics/fastfail)/[`__debugbreak`](https://learn.microsoft.com/en-us/cpp/intrinsics/debugbreak) (msvc), can be used to terminate the program as fast as possible. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/abort&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        [FILE](../io/FILE.html) *fp = [fopen](../io/fopen.html)("data.txt","r");
        if (fp == [NULL](../types/NULL.html))
        {
            [fprintf](../io/fprintf.html)([stderr](../io/std_streams.html), "error opening file data.txt in function main()\n");
            abort();
        }
     
        /* Normal processing continues here. */
        [fclose](../io/fclose.html)(fp);
        [printf](../io/fprintf.html)("Normal Return\n");
        return 0;
    }

Output: 
    
    
    error opening file data.txt in function main()

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/abort&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.4.1 The abort function (p: 255) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.4.1 The abort function (p: 350) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.4.1 The abort function (p: 315) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.4.1 The abort function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/abort&action=edit&section=6 "Edit section: See also")] See also

[ exit](exit.html "c/program/exit") |  causes normal program termination with cleaning up   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_exit&action=edit)  
---|---  
[ atexit](atexit.html "c/program/atexit") |  registers a function to be called on [exit()](exit.html "c/program/exit") invocation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_atexit&action=edit)  
[ quick_exit](quick_exit.html "c/program/quick exit")(C11) |  causes normal program termination without completely cleaning up   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_quick_exit&action=edit)  
[C++ documentation](../../cpp/utility/program/abort.html "cpp/utility/program/abort") for abort  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/abort&oldid=167782](https://en.cppreference.com/mwiki/index.php?title=c/program/abort&oldid=167782)" 

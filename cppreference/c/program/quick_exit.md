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
| [abort](abort.html "c/program/abort")  
---  
[exit](exit.html "c/program/exit")  
**quick_exit**(C11)  
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
_Noreturn void quick_exit( int exit_code ); |  | (since C11)   
(until C23)  
[[noreturn]] void quick_exit( int exit_code ); |  |  (since C23)  
| |   
  
Causes normal program termination to occur without completely cleaning the resources. 

Functions passed to [at_quick_exit](at_quick_exit.html "c/program/at quick exit") are called in reverse order of their registration. After calling the registered functions, calls [_Exit](_Exit.html)(exit_code). 

Functions passed to [atexit](atexit.html "c/program/atexit") or signal handlers passed to [signal](signal.html "c/program/signal") are not called. 

## Contents

  * [1 Parameters](quick_exit.html#Parameters)
  * [2 Return value](quick_exit.html#Return_value)
  * [3 Example](quick_exit.html#Example)
  * [4 References](quick_exit.html#References)
  * [5 See also](quick_exit.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/quick_exit&action=edit&section=1 "Edit section: Parameters")] Parameters

exit_code  |  \-  |  exit status of the program   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/quick_exit&action=edit&section=2 "Edit section: Return value")] Return value

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/quick_exit&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdlib.h>
    #include <stdio.h>
     
    void f1(void)
    {
        [puts](../io/puts.html)("pushed first");
        [fflush](../io/fflush.html)([stdout](../io/std_streams.html));
    }
     
    void f2(void)
    {
        [puts](../io/puts.html)("pushed second");
    }
     
    void f3(void)
    {
        [puts](../io/puts.html)("won't be called");
    }
     
    int main(void)
    {
        [at_quick_exit](at_quick_exit.html)(f1);
        [at_quick_exit](at_quick_exit.html)(f2);
        [atexit](atexit.html)(f3);
        quick_exit(0);
    }

Output: 
    
    
    pushed second
    pushed first

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/quick_exit&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.4.7 The quick_exit function (p: 257) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.4.7 The quick_exit function (p: 353) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/quick_exit&action=edit&section=5 "Edit section: See also")] See also

[ abort](abort.html "c/program/abort") |  causes abnormal program termination (without cleaning up)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_abort&action=edit)  
---|---  
[ atexit](atexit.html "c/program/atexit") |  registers a function to be called on [exit()](exit.html "c/program/exit") invocation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_atexit&action=edit)  
[ at_quick_exit](at_quick_exit.html "c/program/at quick exit")(C11) |  registers a function to be called on **`quick_exit`** invocation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_at_quick_exit&action=edit)  
[C++ documentation](../../cpp/utility/program/quick_exit.html "cpp/utility/program/quick exit") for quick_exit  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/quick_exit&oldid=154418](https://en.cppreference.com/mwiki/index.php?title=c/program/quick_exit&oldid=154418)" 

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
**exit**  
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
void exit( int exit_code ); |  | (until C11)  
_Noreturn void exit( int exit_code ); |  |  (since C11)   
(until C23)  
[[noreturn]] void exit( int exit_code ); |  |  (since C23)  
| |   
  
Causes normal program termination to occur. 

Several cleanup steps are performed: 

  * functions passed to [atexit](atexit.html "c/program/atexit") are called, in reverse order of registration 
  * all C streams are flushed and closed 
  * files created by [tmpfile](../io/tmpfile.html "c/io/tmpfile") are removed 
  * control is returned to the host environment. If `exit_code` is zero or [EXIT_SUCCESS](EXIT_status.html "c/program/EXIT status"), an implementation-defined status indicating successful termination is returned. If `exit_code` is [EXIT_FAILURE](EXIT_status.html "c/program/EXIT status"), an implementation-defined status indicating unsuccessful termination is returned. In other cases implementation-defined status value is returned. 



## Contents

  * [1 Notes](exit.html#Notes)
  * [2 Parameters](exit.html#Parameters)
  * [3 Return value](exit.html#Return_value)
  * [4 Example](exit.html#Example)
  * [5 References](exit.html#References)
  * [6 See also](exit.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/exit&action=edit&section=1 "Edit section: Notes")] Notes

The functions registered with [at_quick_exit](at_quick_exit.html "c/program/at quick exit") are not called. 

The behavior is undefined if a program calls `exit` more than once, or if it calls `exit` and [quick_exit](quick_exit.html "c/program/quick exit")

The behavior is undefined if during a call to a function registered with [atexit](atexit.html "c/program/atexit"), the function exits with [longjmp](longjmp.html "c/program/longjmp"). 

Returning from the [the main function](../language/main_function.html "c/language/main function"), either by a `return` statement or by reaching the end of the function, executes `exit()`, passing the argument of the return statement (or ​0​ if implicit return was used) as `exit_code`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/exit&action=edit&section=2 "Edit section: Parameters")] Parameters

exit_code  |  \-  |  exit status of the program   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/exit&action=edit&section=3 "Edit section: Return value")] Return value

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/exit&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        [FILE](../io/FILE.html) *fp = [fopen](../io/fopen.html)("data.txt","r");
        if (fp == [NULL](../types/NULL.html))
        {
           [fprintf](../io/fprintf.html)([stderr](../io/std_streams.html), "error opening file data.txt in function main()\n");
           exit( [EXIT_FAILURE](EXIT_status.html) );
        }
        [fclose](../io/fclose.html)(fp);
        [printf](../io/fprintf.html)("Normal Return\n");
        return [EXIT_SUCCESS](EXIT_status.html) ;
    }

Possible output: 
    
    
    error opening file data.txt in function main()

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/exit&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.4.4 The exit function (p: 256) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.4.4 The exit function (p: 351-352) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.4.3 The exit function (p: 315-316) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.4.3 The exit function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/exit&action=edit&section=6 "Edit section: See also")] See also

[ abort](abort.html "c/program/abort") |  causes abnormal program termination (without cleaning up)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_abort&action=edit)  
---|---  
[ atexit](atexit.html "c/program/atexit") |  registers a function to be called on **exit()** invocation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_atexit&action=edit)  
[ quick_exit](quick_exit.html "c/program/quick exit")(C11) |  causes normal program termination without completely cleaning up   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_quick_exit&action=edit)  
[C++ documentation](../../cpp/utility/program/exit.html "cpp/utility/program/exit") for exit  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/exit&oldid=154433](https://en.cppreference.com/mwiki/index.php?title=c/program/exit&oldid=154433)" 

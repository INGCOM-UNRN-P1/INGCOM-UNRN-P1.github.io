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
**sig_atomic_t**  
  
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

Defined in header `[`<signal.h>`](../header/signal.html "c/header/signal")` |  |   
---|---|---  
typedef /* unspecified */ sig_atomic_t; |  |   
| |   
  
An integer type which can be accessed as an atomic entity even in the presence of asynchronous interrupts made by signals. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/sig_atomic_t&action=edit&section=1 "Edit section: Example")] Example

Run this code
    
    
    #include <signal.h>
    #include <stdio.h>
     
    volatile sig_atomic_t gSignalStatus = 0;
     
    void signal_handler(int status)
    {
        gSignalStatus = status;
    }
     
    int main(void)
    {
        /* Install a signal handler. */
        [signal](signal.html)([SIGINT](SIG_types.html), signal_handler);
     
        [printf](../io/fprintf.html)("SignalValue:    %d\n", gSignalStatus);
        [printf](../io/fprintf.html)("Sending signal: %d\n", [SIGINT](SIG_types.html));
        [raise](raise.html)([SIGINT](SIG_types.html));
        [printf](../io/fprintf.html)("SignalValue:    %d\n", gSignalStatus);
    }

Possible output: 
    
    
    SignalValue:    0
    Sending signal: 2
    SignalValue:    2

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/sig_atomic_t&action=edit&section=2 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.14/2 Signal handling <signal.h> (p: 194-195) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.14/2 Signal handling <signal.h> (p: 265) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.14/2 Signal handling <signal.h> (p: 246) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.7 SIGNAL HANDLING <signal.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/sig_atomic_t&action=edit&section=3 "Edit section: See also")] See also

[ signal](signal.html "c/program/signal") |  sets a signal handler for particular signal   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_signal&action=edit)  
---|---  
[C++ documentation](../../cpp/utility/program/sig_atomic_t.html "cpp/utility/program/sig atomic t") for sig_atomic_t  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/sig_atomic_t&oldid=140328](https://en.cppreference.com/mwiki/index.php?title=c/program/sig_atomic_t&oldid=140328)" 

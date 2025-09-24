From cppreference.com

< [c](../c.html "c")

[ C](../c.html "c")

[Compiler support](compiler_support.html "c/compiler support")  
---  
[Language](language.html "c/language")  
[Headers](header.html "c/header")  
[Type support](types.html "c/types")  
**Program utilities**  
[Variadic function support](variadic.html "c/variadic")  
[Error handling](error.html "c/error")  
[Dynamic memory management](memory.html "c/memory")  
[Strings library](string.html "c/string")  
[Algorithms](algorithm.html "c/algorithm")  
[Numerics](numeric.html "c/numeric")  
[Date and time utilities](chrono.html "c/chrono")  
[Input/output support](io.html "c/io")  
[Localization support](locale.html "c/locale")  
[Concurrency support](thread.html "c/thread") (C11)  
[Technical Specifications](experimental.html "c/experimental")  
[Symbol index](index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

**Program support utilities**

Program termination  
---  
| [abort](program/abort.html "c/program/abort")  
---  
[exit](program/exit.html "c/program/exit")  
[quick_exit](program/quick_exit.html "c/program/quick exit")(C11)  
[_Exit](program/_Exit.html "c/program/ Exit")(C99)  
  
| [atexit](program/atexit.html "c/program/atexit")  
---  
[at_quick_exit](program/at_quick_exit.html "c/program/at quick exit")(C11)  
[EXIT_SUCCESSEXIT_FAILURE](program/EXIT_status.html "c/program/EXIT status")  
  
Unreachable control flow  
[unreachable](program/unreachable.html "c/program/unreachable")(C23)  
Communicating with the environment  
| [getenvgetenv_s](program/getenv.html "c/program/getenv")(C11)  
---  
  
| [system](program/system.html "c/program/system")  
---  
  
  
  
Memory alignment query  
[memalignment](program/memalignment.html "c/program/memalignment")(C23)  
Signals  
| [signal](program/signal.html "c/program/signal")  
---  
[raise](program/raise.html "c/program/raise")  
[sig_atomic_t](program/sig_atomic_t.html "c/program/sig atomic t")  
  
| [SIG_DFLSIG_IGN](program/SIG_strategies.html "c/program/SIG strategies")  
---  
[SIG_ERR](program/SIG_ERR.html "c/program/SIG ERR")  
  
Signal types  
| [SIGABRTSIGFPESIGILL](program/SIG_types.html "c/program/SIG types")  
---  
  
| [SIGINTSIGSEGVSIGTERM](program/SIG_types.html "c/program/SIG types")  
---  
  
Non-local jumps  
| [setjmp](program/setjmp.html "c/program/setjmp")  
---  
  
| [longjmp](program/longjmp.html "c/program/longjmp")  
---  
  
Types  
[jmp_buf](program/jmp_buf.html "c/program/jmp buf")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/navbar_content&action=edit)

## Contents

  * [1 Program termination](program.html#Program_termination)
  * [2 Unreachable control flow](program.html#Unreachable_control_flow)
  * [3 Communicating with the environment](program.html#Communicating_with_the_environment)
  * [4 Memory alignment query](program.html#Memory_alignment_query)
  * [5 Signals](program.html#Signals)
    * [5.1 Signal types](program.html#Signal_types)
  * [6 Non-local jumps](program.html#Non-local_jumps)
    * [6.1 Types](program.html#Types)
  * [7 References](program.html#References)
  * [8 See also](program.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program&action=edit&section=1 "Edit section: Program termination")] Program termination

The following functions manage program termination and resources cleanup. 

Defined in header `[`<stdlib.h>`](header/stdlib.html "c/header/stdlib")`  
---  
[ abort](program/abort.html "c/program/abort") |  causes abnormal program termination (without cleaning up)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_abort&action=edit)  
[ exit](program/exit.html "c/program/exit") |  causes normal program termination with cleaning up   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_exit&action=edit)  
[ quick_exit](program/quick_exit.html "c/program/quick exit")(C11) |  causes normal program termination without completely cleaning up   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_quick_exit&action=edit)  
[ _Exit](program/_Exit.html "c/program/ Exit")(C99) |  causes normal program termination without cleaning up   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_Exit&action=edit)  
[ atexit](program/atexit.html "c/program/atexit") |  registers a function to be called on [exit()](program/exit.html "c/program/exit") invocation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_atexit&action=edit)  
[ at_quick_exit](program/at_quick_exit.html "c/program/at quick exit")(C11) |  registers a function to be called on [`quick_exit`](program/quick_exit.html "c/program/quick exit") invocation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_at_quick_exit&action=edit)  
[ EXIT_SUCCESSEXIT_FAILURE](program/EXIT_status.html "c/program/EXIT status") |  indicates program execution execution status   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_EXIT_status&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program&action=edit&section=2 "Edit section: Unreachable control flow")] Unreachable control flow

Defined in header `[`<stddef.h>`](header/stddef.html "c/header/stddef")`  
---  
[ unreachable](program/unreachable.html "c/program/unreachable")(C23) |  marks unreachable point of execution   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_unreachable&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program&action=edit&section=3 "Edit section: Communicating with the environment")] Communicating with the environment

Defined in header `[`<stdlib.h>`](header/stdlib.html "c/header/stdlib")`  
---  
[ system](program/system.html "c/program/system") |  calls the host environment's command processor   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_system&action=edit)  
[ getenvgetenv_s](program/getenv.html "c/program/getenv")(C11) |  access to the list of environment variables   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_getenv&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program&action=edit&section=4 "Edit section: Memory alignment query")] Memory alignment query

Defined in header `[`<stdlib.h>`](header/stdlib.html "c/header/stdlib")`  
---  
[ memalignment](program/memalignment.html "c/program/memalignment")(C23) |  queries the alignment of a pointer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_memalignment&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program&action=edit&section=5 "Edit section: Signals")] Signals

Several functions and macro constants for signal management are provided. 

Defined in header `[`<signal.h>`](header/signal.html "c/header/signal")`  
---  
[ signal](program/signal.html "c/program/signal") |  sets a signal handler for particular signal   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_signal&action=edit)  
[ raise](program/raise.html "c/program/raise") |  runs the signal handler for particular signal   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_raise&action=edit)  
[ sig_atomic_t](program/sig_atomic_t.html "c/program/sig atomic t") |  the integer type that can be accessed as an atomic entity from an asynchronous signal handler   
(typedef)  
[ SIG_DFLSIG_IGN](program/SIG_strategies.html "c/program/SIG strategies") |  defines signal handling strategies   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_SIG_strategies&action=edit)  
[ SIG_ERR](program/SIG_ERR.html "c/program/SIG ERR") |  error was encountered   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_SIG_ERR&action=edit)  
  
#####  Signal types   
  
[ SIGABRTSIGFPESIGILLSIGINTSIGSEGVSIGTERM](program/SIG_types.html "c/program/SIG types") |  defines signal types   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_SIG_types&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program&action=edit&section=6 "Edit section: Non-local jumps")] Non-local jumps

Defined in header `[`<setjmp.h>`](header/setjmp.html "c/header/setjmp")`  
---  
[ setjmp](program/setjmp.html "c/program/setjmp") |  saves the context   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_setjmp&action=edit)  
[ longjmp](program/longjmp.html "c/program/longjmp") |  jumps to specified location   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_longjmp&action=edit)  
  
#####  Types   
  
[ jmp_buf](program/jmp_buf.html "c/program/jmp buf") |  execution context type   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_jmp_buf&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program&action=edit&section=7 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.13 Non-local jumps <setjmp.h> (p: 283-284) 



    

  * 7.14 Signal handling <signal.h> (p: 285-287) 



    

  * 7.24 General utilities <stdlib.h> (p: 356-374) 



    

  * 7.33.9 Signal handling <signal.h> (p: 458) 



    

  * 7.33.16 General utilities <stdlib.h> (p: 458) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.13 Nonlocal jumps <setjmp.h> (p: 191-192) 



    

  * 7.14 Signal handling <signal.h> (p: 193-195) 



    

  * 7.22 General utilities <stdlib.h> (p: 248-262) 



    

  * 7.31.7 Signal handling <signal.h> (p: 332) 



    

  * 7.31.12 General utilities <stdlib.h> (p: 333) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.13 Nonlocal jumps <setjmp.h> (p: 262-264) 



    

  * 7.14 Signal handling <signal.h> (p: 265-267) 



    

  * 7.22 General utilities <stdlib.h> (p: 340-360) 



    

  * 7.31.7 Signal handling <signal.h> (p: 455) 



    

  * 7.31.12 General utilities <stdlib.h> (p: 456) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.13 Nonlocal jumps <setjmp.h> (p: 243-245) 



    

  * 7.14 Signal handling <signal.h> (p: 246-248) 



    

  * 7.20 General utilities <stdlib.h> (p: 306-324) 



    

  * 7.26.6 Signal handling <signal.h> (p: 401) 



    

  * 7.26.10 General utilities <stdlib.h> (p: 402) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.6 NON-LOCAL JUMPS <setjmp.h>



    

  * 4.7 SIGNAL HANDLING <signal.h>



    

  * 4.10 GENERAL UTILITIES <stdlib.h>



    

  * 4.13.5 Signal handling <signal.h>



    

  * 7.13.7 General utilities <stdlib.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program&action=edit&section=8 "Edit section: See also")] See also

[C++ documentation](../cpp/utility/program.html "cpp/utility/program") for Program support utilities  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program&oldid=180217](https://en.cppreference.com/mwiki/index.php?title=c/program&oldid=180217)" 

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
[sig_atomic_t](sig_atomic_t.html "c/program/sig atomic t")  
  
| [SIG_DFLSIG_IGN](SIG_strategies.html "c/program/SIG strategies")  
---  
[SIG_ERR](SIG_ERR.html "c/program/SIG ERR")  
  
Signal types  
| **SIGABRT SIGFPESIGILL**  
---  
  
| **SIGINT SIGSEGVSIGTERM**  
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
#define SIGTERM /*implementation defined*/ |  |   
#define SIGSEGV /*implementation defined*/ |  |   
#define SIGINT /*implementation defined*/ |  |   
#define SIGILL /*implementation defined*/ |  |   
#define SIGABRT /*implementation defined*/ |  |   
#define SIGFPE /*implementation defined*/ |  |   
| |   
  
Each of the above macro constants expands to an integer constant expression with distinct values, which represent different signals sent to the program. 

Constant  |  Explanation   
---|---  
`SIGTERM` |  termination request, sent to the program   
`SIGSEGV` |  invalid memory access (segmentation fault)   
`SIGINT` |  external interrupt, usually initiated by the user   
`SIGILL` |  invalid program image, such as invalid instruction   
`SIGABRT` |  abnormal termination condition, as is e.g. initiated by [abort()](abort.html "c/program/abort")  
`SIGFPE` |  erroneous arithmetic operation such as divide by zero   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/SIG_types&action=edit&section=1 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.14/3 Signal handling <signal.h> (p: 193) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.14/3 Signal handling <signal.h> (p: 265) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.14/3 Signal handling <signal.h> (p: 246) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.7 SIGNAL HANDLING <signal.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/SIG_types&action=edit&section=2 "Edit section: See also")] See also

[ signal](signal.html "c/program/signal") |  sets a signal handler for particular signal   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_signal&action=edit)  
---|---  
[ raise](raise.html "c/program/raise") |  runs the signal handler for particular signal   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_raise&action=edit)  
[C++ documentation](../../cpp/utility/program/SIG_types.html "cpp/utility/program/SIG types") for signal types  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/SIG_types&oldid=140335](https://en.cppreference.com/mwiki/index.php?title=c/program/SIG_types&oldid=140335)" 

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
**jmp_buf**  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/navbar_content&action=edit)

Defined in header `[`<setjmp.h>`](../header/setjmp.html "c/header/setjmp")` |  |   
---|---|---  
typedef /* unspecified */ jmp_buf; |  |   
| |   
  
The `jmp_buf` type is an array type suitable for storing information to restore a calling environment. The stored information is sufficient to restore execution at the correct block of the program and invocation of that block. The state of floating-point status flags, or open files, or any other data is not stored in an object of type `jmp_buf`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/jmp_buf&action=edit&section=1 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.13/2 Nonlocal jumps <setjmp.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.13/2 Nonlocal jumps <setjmp.h> (p: 191) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.13/2 Nonlocal jumps <setjmp.h> (p: 262) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.13/2 Nonlocal jumps <setjmp.h> (p: 243) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.6 NON-LOCAL JUMPS <setjmp.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/jmp_buf&action=edit&section=2 "Edit section: See also")] See also

[ setjmp](setjmp.html "c/program/setjmp") |  saves the context   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_setjmp&action=edit)  
---|---  
[ longjmp](longjmp.html "c/program/longjmp") |  jumps to specified location   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_longjmp&action=edit)  
[C++ documentation](../../cpp/utility/program/jmp_buf.html "cpp/utility/program/jmp buf") for jmp_buf  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/jmp_buf&oldid=180111](https://en.cppreference.com/mwiki/index.php?title=c/program/jmp_buf&oldid=180111)" 

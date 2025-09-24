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
**raise**  
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

Defined in header `[`<signal.h>`](../header/signal.html "c/header/signal")` |  |   
---|---|---  
int raise( int sig ); |  |   
| |   
  
Sends signal sig to the program. The signal handler, specified using [signal()](signal.html "c/program/signal"), is invoked. 

If the user-defined signal handling strategy is not set using [signal()](signal.html "c/program/signal") yet, it is implementation-defined whether the signal will be ignored or default handler will be invoked. 

## Contents

  * [1 Parameters](raise.html#Parameters)
  * [2 Return value](raise.html#Return_value)
  * [3 Example](raise.html#Example)
  * [4 References](raise.html#References)
  * [5 See also](raise.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/raise&action=edit&section=1 "Edit section: Parameters")] Parameters

sig  |  \-  |  the signal to be sent. It can be an implementation-defined value or one of the following values:  |  [ SIGABRTSIGFPESIGILLSIGINTSIGSEGVSIGTERM](SIG_types.html "c/program/SIG types") |  defines signal types   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_SIG_types&action=edit)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/raise&action=edit&section=2 "Edit section: Return value")] Return value

​0​ upon success, non-zero value on failure. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/raise&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <signal.h>
    #include <stdio.h>
     
    void signal_handler(int [signal](signal.html))
    {
        [printf](../io/fprintf.html)("Received signal %d\n", [signal](signal.html));
    }
     
    int main(void)
    {
        // Install a signal handler.
        [signal](signal.html)([SIGTERM](SIG_types.html), signal_handler);
     
        [printf](../io/fprintf.html)("Sending signal %d\n", [SIGTERM](SIG_types.html));
        raise([SIGTERM](SIG_types.html));
        [printf](../io/fprintf.html)("Exit main()\n");
    }

Output: 
    
    
    Sending signal 15
    Received signal 15
    Exit main()

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/raise&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.14.2.1 The raise function (p: 194-195) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.14.2.1 The raise function (p: 267) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.14.2.1 The raise function (p: 248) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.7.2.1 The raise function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/raise&action=edit&section=5 "Edit section: See also")] See also

[ signal](signal.html "c/program/signal") |  sets a signal handler for particular signal   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_signal&action=edit)  
---|---  
[C++ documentation](../../cpp/utility/program/raise.html "cpp/utility/program/raise") for raise  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/raise&oldid=140326](https://en.cppreference.com/mwiki/index.php?title=c/program/raise&oldid=140326)" 

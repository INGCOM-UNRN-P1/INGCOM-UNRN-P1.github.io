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
  
| **atexit**  
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
int atexit( void (*func)(void) ); |  |   
| |   
  
Registers the function pointed to by `func` to be called on normal program termination (via [exit()](exit.html "c/program/exit") or returning from `main()`). The functions will be called in reverse order they were registered, i.e. the function registered last will be executed first. 

The same function may be registered more than once. 

The implementation is guaranteed to support the registration of at least 32 functions. The exact limit is implementation-defined. 

## Contents

  * [1 Parameters](atexit.html#Parameters)
  * [2 Return value](atexit.html#Return_value)
  * [3 Example](atexit.html#Example)
  * [4 References](atexit.html#References)
  * [5 See also](atexit.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/atexit&action=edit&section=1 "Edit section: Parameters")] Parameters

func  |  \-  |  pointer to a function to be called on normal program termination   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/atexit&action=edit&section=2 "Edit section: Return value")] Return value

​0​ if the registration succeeds, nonzero value otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/atexit&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdlib.h>
    #include <stdio.h>
     
    void f1(void)
    {
        [puts](../io/puts.html)("f1");
    }
     
    void f2(void)
    {
        [puts](../io/puts.html)("f2");
    }
     
    int main(void)
    {
        if ( ! atexit(f1) && ! atexit(f2) && ! atexit(f2) )
            return [EXIT_SUCCESS](EXIT_status.html) ;
     
        // atexit registration failed
        return [EXIT_FAILURE](EXIT_status.html) ;
     
    }   // <- if registration was successful calls f2, f2, f1

Output: 
    
    
    f2
    f2
    f1

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/atexit&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.4.2 The atexit function (p: 255) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.4.2 The atexit function (p: 350) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.4.2 The atexit function (p: 315) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 7.10.4.2 The atexit function (p: 156) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/atexit&action=edit&section=5 "Edit section: See also")] See also

[ at_quick_exit](at_quick_exit.html "c/program/at quick exit")(C11) |  registers a function to be called on [`quick_exit`](quick_exit.html "c/program/quick exit") invocation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_at_quick_exit&action=edit)  
---|---  
[C++ documentation](../../cpp/utility/program/atexit.html "cpp/utility/program/atexit") for atexit  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/atexit&oldid=172244](https://en.cppreference.com/mwiki/index.php?title=c/program/atexit&oldid=172244)" 

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
**_Exit**(C99)  
  
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
void _Exit( int exit_code ); |  | (since C99)   
(until C11)  
_Noreturn void _Exit( int exit_code ); |  |  (since C11)   
(until C23)  
[[noreturn]] void _Exit( int exit_code ); |  |  (since C23)  
| |   
  
Causes normal program termination to occur without completely cleaning the resources. 

Functions passed to [at_quick_exit()](at_quick_exit.html "c/program/at quick exit") or [atexit()](atexit.html "c/program/atexit") are not called. Whether open streams with unwritten buffered data are flushed, open streams are closed, or temporary files are removed is implementation-defined. 

If `exit_code` is 0 or [EXIT_SUCCESS](EXIT_status.html "c/program/EXIT status"), an implementation-defined status indicating successful termination is returned to the host environment. If `exit_code` is [EXIT_FAILURE](EXIT_status.html "c/program/EXIT status"), an implementation-defined status, indicating _unsuccessful_ termination, is returned. In other cases an implementation-defined status value is returned. 

## Contents

  * [1 Parameters](_Exit.html#Parameters)
  * [2 Return value](_Exit.html#Return_value)
  * [3 Example](_Exit.html#Example)
  * [4 References](_Exit.html#References)
  * [5 See also](_Exit.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/_Exit&action=edit&section=1 "Edit section: Parameters")] Parameters

exit_code  |  \-  |  exit status of the program   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/_Exit&action=edit&section=2 "Edit section: Return value")] Return value

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/_Exit&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdlib.h>
    #include <stdio.h>
     
    /* _Exit does not call functions registered with atexit. */
    void f1(void)
    {
        [puts](../io/puts.html)("pushed first");
    }
     
    void f2(void)
    {
        [puts](../io/puts.html)("pushed second");
    }
     
    int main(void)
    {
        [printf](../io/fprintf.html)("Enter main()\n");
        [atexit](atexit.html)(f1);
        [atexit](atexit.html)(f2);
        [fflush](../io/fflush.html)([stdout](../io/std_streams.html));   /* _Exit may not flush unwritten buffered data */
        _Exit(0);
    }

Output: 
    
    
    Enter main()

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/_Exit&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.4.5 The _Exit function (p: 256) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.4.5 The _Exit function (p: 352) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.4.4 The _Exit function (p: 316) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/_Exit&action=edit&section=5 "Edit section: See also")] See also

[ abort](abort.html "c/program/abort") |  causes abnormal program termination (without cleaning up)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_abort&action=edit)  
---|---  
[ exit](exit.html "c/program/exit") |  causes normal program termination with cleaning up   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_exit&action=edit)  
[C++ documentation](../../cpp/utility/program/_Exit.html "cpp/utility/program/ Exit") for _Exit  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/_Exit&oldid=154416](https://en.cppreference.com/mwiki/index.php?title=c/program/_Exit&oldid=154416)" 

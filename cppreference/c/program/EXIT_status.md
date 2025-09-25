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
**EXIT_SUCCESS EXIT_FAILURE**  
  
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
#define EXIT_SUCCESS /*implementation defined*/ |  |   
#define EXIT_FAILURE /*implementation defined*/ |  |   
| |   
  
The `EXIT_SUCCESS` and `EXIT_FAILURE` macros expand into integral constant expressions that can be used as arguments to the [exit](exit.html "c/program/exit") function (and, therefore, as the values to return from the [main function](../language/main_function.html "c/language/main function")), and indicate program execution status. 

Constant  |  Description   
---|---  
`EXIT_SUCCESS` |  successful execution of a program   
`EXIT_FAILURE` |  unsuccessful execution of a program   
  
## Contents

  * [1 Notes](EXIT_status.html#Notes)
  * [2 Example](EXIT_status.html#Example)
  * [3 References](EXIT_status.html#References)
  * [4 See also](EXIT_status.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/EXIT_status&action=edit&section=1 "Edit section: Notes")] Notes

Both `EXIT_SUCCESS` and the value zero indicate successful program execution status (see [exit](exit.html "c/program/exit")), although it is not required that `EXIT_SUCCESS` equals zero. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/EXIT_status&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        [FILE](../io/FILE.html)* fp = [fopen](../io/fopen.html)("data.txt", "r");
        if (fp == [NULL](../types/NULL.html))
        {
           [fprintf](../io/fprintf.html)([stderr](../io/std_streams.html), "fopen() failed in file %s at line #%d", __FILE__, __LINE__);
           [exit](exit.html)(EXIT_FAILURE);
        }
     
        /* Normal processing continues here. */
        [fclose](../io/fclose.html)(fp);
        [printf](../io/fprintf.html)("Normal Return\n");
     
        return EXIT_SUCCESS;
    }

Output: 
    
    
    fopen() failed in file main.cpp at line #9

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/EXIT_status&action=edit&section=3 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.22/3 General utilities <stdlib.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22/3 General utilities <stdlib.h> (p: 248) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22/3 General utilities <stdlib.h> (p: 340) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20/3 General utilities <stdlib.h> (p: 306) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10 General utilities <stdlib.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/EXIT_status&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../cpp/utility/program/EXIT_status.html "cpp/utility/program/EXIT status") for EXIT_SUCCESS, EXIT_FAILURE  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/EXIT_status&oldid=178295](https://en.cppreference.com/mwiki/index.php?title=c/program/EXIT_status&oldid=178295)" 

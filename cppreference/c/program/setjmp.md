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
| **setjmp**  
---  
  
| [longjmp](longjmp.html "c/program/longjmp")  
---  
  
Types  
[jmp_buf](jmp_buf.html "c/program/jmp buf")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/navbar_content&action=edit)

Defined in header `[`<setjmp.h>`](../header/setjmp.html "c/header/setjmp")` |  |   
---|---|---  
#define setjmp(env) /* implementation-defined */ |  |   
| |   
  
Saves the current execution context into a variable `env` of type [jmp_buf](jmp_buf.html "c/program/jmp buf"). This variable can later be used to restore the current execution context by [longjmp](longjmp.html "c/program/longjmp") function. That is, when a call to [longjmp](longjmp.html "c/program/longjmp") function is made, the execution continues at the particular call site that constructed the [jmp_buf](jmp_buf.html "c/program/jmp buf") variable passed to [longjmp](longjmp.html "c/program/longjmp"). In that case `setjmp` returns the value passed to [longjmp](longjmp.html "c/program/longjmp"). 

The invocation of `setjmp` must appear only in one of the following contexts: 

  1. The entire controlling expression of [`if`](../language/if.html "c/language/if"), [`switch`](../language/switch.html "c/language/switch"), [`while`](../language/while.html "c/language/while"), [`do-while`](../language/do.html "c/language/do"), [`for`](../language/for.html "c/language/for").
         
         switch(setjmp(env)) { // ...

  2. One operand of a relational or equality operator with the other operand an integer constant expression, with the resulting expression being the entire controlling expression of [`if`](../language/if.html "c/language/if"), [`switch`](../language/switch.html "c/language/switch"), [`while`](../language/while.html "c/language/while"), [`do-while`](../language/do.html "c/language/do"), [`for`](../language/for.html "c/language/for").
         
         if(setjmp(env) > 10) { // ...

  3. The operand of a unary ! operator with the resulting expression being the entire controlling expression of [`if`](../language/if.html "c/language/if"), [`switch`](../language/switch.html "c/language/switch"), [`while`](../language/while.html "c/language/while"), [`do-while`](../language/do.html "c/language/do"), [`for`](../language/for.html "c/language/for").
         
         while(!setjmp(env)) { // ...

  4. The entire expression of an [expression statement](../language/statements.html#Expression_statements "c/language/statements") (possibly cast to `void`).
         
         setjmp(env);




If `setjmp` appears in any other context, the behavior is undefined. 

Upon return to the scope of `setjmp`: 

  * all accessible objects, floating-point status flags, and other components of the abstract machine have the same values as they had when [longjmp](longjmp.html "c/program/longjmp") was executed, 
  * except for the non-[`volatile`](../language/volatile.html "c/language/volatile") local variables in the function containing the invocation of `setjmp`, whose values are indeterminate if they have been changed since the `setjmp` invocation. 



## Contents

  * [1 Parameters](setjmp.html#Parameters)
  * [2 Return value](setjmp.html#Return_value)
  * [3 Notes](setjmp.html#Notes)
  * [4 Example](setjmp.html#Example)
  * [5 References](setjmp.html#References)
  * [6 See also](setjmp.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/setjmp&action=edit&section=1 "Edit section: Parameters")] Parameters

env  |  \-  |  variable to save the execution state of the program to.   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/setjmp&action=edit&section=2 "Edit section: Return value")] Return value

​0​ if the macro was called by the original code and the execution context was saved to `env`. 

Non-zero value if a non-local jump was just performed. The return value is the same as passed to [longjmp](longjmp.html "c/program/longjmp"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/setjmp&action=edit&section=3 "Edit section: Notes")] Notes

Above requirements forbid using return value of `setjmp` in data flow (e.g. to initialize or assign an object with it). The return value can only be either used in control flow or discarded. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/setjmp&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <setjmp.h>
    #include <stdnoreturn.h>
     
    [jmp_buf](jmp_buf.html) my_jump_buffer;
     
    noreturn void foo(int status) 
    {
        [printf](../io/fprintf.html)("foo(%d) called\n", status);
        [longjmp](longjmp.html)(my_jump_buffer, status + 1); // will return status+1 out of setjmp
    }
     
    int main(void)
    {
        volatile int count = 0; // modified local vars in setjmp scope must be volatile
        if (setjmp(my_jump_buffer) != 5) // compare against constant in an if
            foo(++count);
    }

Output: 
    
    
    foo(1) called
    foo(2) called
    foo(3) called
    foo(4) called

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/setjmp&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.13.1.1 The setjmp macro (p: 191) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.13.1.1 The setjmp macro (p: 262-263) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.13.1.1 The setjmp macro (p: 243-244) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.6.1 The setjmp macro 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/setjmp&action=edit&section=6 "Edit section: See also")] See also

[ longjmp](longjmp.html "c/program/longjmp") |  jumps to specified location   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_longjmp&action=edit)  
---|---  
[C++ documentation](../../cpp/utility/program/setjmp.html "cpp/utility/program/setjmp") for setjmp  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/setjmp&oldid=148503](https://en.cppreference.com/mwiki/index.php?title=c/program/setjmp&oldid=148503)" 

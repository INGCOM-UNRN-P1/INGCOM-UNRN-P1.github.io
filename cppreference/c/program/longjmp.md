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
  
| **longjmp**  
---  
  
Types  
[jmp_buf](jmp_buf.html "c/program/jmp buf")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/navbar_content&action=edit)

Defined in header `[`<setjmp.h>`](../header/setjmp.html "c/header/setjmp")` |  |   
---|---|---  
void longjmp( [jmp_buf](jmp_buf.html) env, int status ); |  |  (until C11)  
_Noreturn void longjmp( [jmp_buf](jmp_buf.html) env, int status ); |  |  (since C11)   
(until C23)  
[[noreturn]] void longjmp( [jmp_buf](jmp_buf.html) env, int status ); |  |  (since C23)  
| |   
  
Loads the execution context `env` saved by a previous call to [setjmp](setjmp.html "c/program/setjmp"). This function does not return. Control is transferred to the call site of the macro [setjmp](setjmp.html "c/program/setjmp") that set up `env`. That [setjmp](setjmp.html "c/program/setjmp") then returns the value, passed as the `status`. 

If the function that called [setjmp](setjmp.html "c/program/setjmp") has exited (whether by return or by a different `longjmp` higher up the stack), the behavior is undefined. In other words, only long jumps up the call stack are allowed. 

Jumping across threads (if the function that called `setjmp` was executed by another thread) is also undefined behavior.  | (since C11)  
---|---  
If when [setjmp](setjmp.html "c/program/setjmp") was called, a [VLA](../language/array.html "c/language/array") or another [variably-modified type](../language/declarations.html "c/language/declarations") variable was in scope and control left that scope, `longjmp` to that `setjmp` invokes undefined behavior even if control remained within the function. On the way up the stack, `longjmp` does not deallocate any VLAs, memory leaks may occur if their lifetimes are terminated in this way: 
    
    
    void g(int n)
    {
        int a[n]; // a may remain allocated
        h(n); // does not return
    }
    void h(int n)
    {
        int b[n]; // b may remain allocated
        longjmp(buf, 2); // might cause a memory leak for h's b and g's a
    }

| (since C99)  
---|---  
  
## Contents

  * [1 Parameters](longjmp.html#Parameters)
  * [2 Return value](longjmp.html#Return_value)
  * [3 Notes](longjmp.html#Notes)
  * [4 Example](longjmp.html#Example)
  * [5 References](longjmp.html#References)
  * [6 See also](longjmp.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/longjmp&action=edit&section=1 "Edit section: Parameters")] Parameters

env  |  \-  |  variable referring to the execution state of the program saved by [setjmp](setjmp.html "c/program/setjmp")  
---|---|---  
status  |  \-  |  the value to return from [setjmp](setjmp.html "c/program/setjmp"). If it is equal to ​0​, 1 is used instead   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/longjmp&action=edit&section=2 "Edit section: Return value")] Return value

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/longjmp&action=edit&section=3 "Edit section: Notes")] Notes

`longjmp` is intended for handling unexpected error conditions where the function cannot return meaningfully. This is similar to exception handling in other programming languages. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/longjmp&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <setjmp.h>
    #include <stdnoreturn.h>
     
    [jmp_buf](jmp_buf.html) my_jump_buffer;
     
    noreturn void foo(int status) 
    {
        [printf](../io/fprintf.html)("foo(%d) called\n", status);
        longjmp(my_jump_buffer, status + 1); // will return status+1 out of setjmp
    }
     
    int main(void)
    {
        volatile int count = 0; // modified local vars in setjmp scope must be volatile
        if ([setjmp](setjmp.html)(my_jump_buffer) != 5) // compare against constant in an if
            foo(++count);
    }

Output: 
    
    
    foo(1) called
    foo(2) called
    foo(3) called
    foo(4) called

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/longjmp&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.13.2.1 The longjmp macro (p: 191-192) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.13.2.1 The longjmp macro (p: 263-264) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.13.2.1 The longjmp macro (p: 244-245) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.6.2.1 The longjmp function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/longjmp&action=edit&section=6 "Edit section: See also")] See also

[ setjmp](setjmp.html "c/program/setjmp") |  saves the context   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_setjmp&action=edit)  
---|---  
[C++ documentation](../../cpp/utility/program/longjmp.html "cpp/utility/program/longjmp") for longjmp  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/longjmp&oldid=154421](https://en.cppreference.com/mwiki/index.php?title=c/program/longjmp&oldid=154421)" 

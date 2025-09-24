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
**memalignment**(C23)  
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
[size_t](../types/size_t.html) memalignment( const void *p ); |  |  (since C23)  
| |   
  
Returns the maximum alignment satisfied by the provided address. The return value can be greater than any alignment value supported by the implementation. If `p` is a null pointer value, ​0​ is returned to indicate that the pointer cannot be used to access an object of any type. 

If the return value compares is greater than or equal to alignof(T), the alignment requirement for the type `T` is satisfied by the pointer. 

A [freestanding implementation](../language/conformance.html "c/language/conformance") needs to provide `memalignment`. 

## Contents

  * [1 Parameters](memalignment.html#Parameters)
  * [2 Return value](memalignment.html#Return_value)
  * [3 Notes](memalignment.html#Notes)
  * [4 Example](memalignment.html#Example)
  * [5 References](memalignment.html#References)
  * [6 See also](memalignment.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/memalignment&action=edit&section=1 "Edit section: Parameters")] Parameters

p  |  \-  |  pointer to query alignment   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/memalignment&action=edit&section=2 "Edit section: Return value")] Return value

The alignment value of `p`, or ​0​ if `p` is a null pointer value. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/memalignment&action=edit&section=3 "Edit section: Notes")] Notes

On common platforms where 

  * null pointers are cast to integer ​0​, 
  * pointer values are directly cast to the numeric values of virtual addresses, and 
  * [size_t](../types/size_t.html "c/types/size t") is same as [uintptr_t](../types/integer.html "c/types/integer"), 



this function can be implemented as return ([size_t](../types/size_t.html))p & -([size_t](../types/size_t.html))p;. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/memalignment&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main()
    {
        alignas(128) int i = 0;
        [printf](../io/fprintf.html)("%zu\n%zu\n", memalignment(nullptr), memalignment(&i));
    }

Possible output: 
    
    
    0
    128

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/memalignment&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.24.9.1 The memalignment function (p: 374) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/memalignment&action=edit&section=6 "Edit section: See also")] See also

[ aligned_alloc](../memory/aligned_alloc.html "c/memory/aligned alloc")(C11) |  allocates aligned memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_aligned_alloc&action=edit)  
---|---  
[ free_aligned_sized](../memory/free_aligned_sized.html "c/memory/free aligned sized")(C23) |  deallocates previously allocated sized and aligned memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_free_aligned_sized&action=edit)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/memalignment&oldid=176982](https://en.cppreference.com/mwiki/index.php?title=c/program/memalignment&oldid=176982)" 

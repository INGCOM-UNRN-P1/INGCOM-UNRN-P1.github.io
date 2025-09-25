From cppreference.com

< [c](../../c.html "c")‎ | [memory](../memory.html "c/memory")

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

[ Dynamic memory management](../memory.html "c/memory")

[malloc](malloc.html "c/memory/malloc")  
---  
[calloc](calloc.html "c/memory/calloc")  
[realloc](realloc.html "c/memory/realloc")  
**free**  
[free_sized](free_sized.html "c/memory/free sized")(C23)  
[free_aligned_sized](free_aligned_sized.html "c/memory/free aligned sized")(C23)  
[aligned_alloc](aligned_alloc.html "c/memory/aligned alloc")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/navbar_content&action=edit)

Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
void free( void *ptr ); |  |   
| |   
  
Deallocates the space previously allocated by [malloc()](malloc.html "c/memory/malloc"), [calloc()](calloc.html "c/memory/calloc"), aligned_alloc(),(since C11) or [realloc()](realloc.html "c/memory/realloc"). 

If `ptr` is a null pointer, the function does nothing. 

The behavior is undefined if the value of `ptr` does not equal a value returned earlier by [malloc()](malloc.html "c/memory/malloc"), [calloc()](calloc.html "c/memory/calloc"), [realloc()](realloc.html "c/memory/realloc"), or aligned_alloc()(since C11). 

The behavior is undefined if the memory area referred to by `ptr` has already been deallocated, that is, `free()`, free_sized(), free_aligned_sized()(since C23), or [realloc()](realloc.html "c/memory/realloc") has already been called with `ptr` as the argument and no calls to [malloc()](malloc.html "c/memory/malloc"), [calloc()](calloc.html "c/memory/calloc"), [realloc()](realloc.html "c/memory/realloc"), or aligned_alloc()(since C11) resulted in a pointer equal to `ptr` afterwards. 

The behavior is undefined if after `free()` returns, an access is made through the pointer `ptr` (unless another allocation function happened to result in a pointer value equal to `ptr`). 

`free` is thread-safe: it behaves as though only accessing the memory locations visible through its argument, and not any static storage. A call to `free` that deallocates a region of memory _synchronizes-with_ a call to any subsequent allocation function that allocates the same or a part of the same region of memory. This synchronization occurs after any access to the memory by the deallocating function and before any access to the memory by the allocation function. There is a single total order of all allocation and deallocation functions operating on each particular region of memory.  | (since C11)  
---|---  
  
## Contents

  * [1 Parameters](free.html#Parameters)
  * [2 Return value](free.html#Return_value)
  * [3 Notes](free.html#Notes)
  * [4 Example](free.html#Example)
  * [5 References](free.html#References)
  * [6 See also](free.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/free&action=edit&section=1 "Edit section: Parameters")] Parameters

ptr  |  \-  |  pointer to the memory to deallocate   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/free&action=edit&section=2 "Edit section: Return value")] Return value

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/free&action=edit&section=3 "Edit section: Notes")] Notes

The function accepts (and does nothing with) the null pointer to reduce the amount of special-casing. Whether allocation succeeds or not, the pointer returned by an allocation function can be passed to `free()`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/free&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdlib.h>
     
    int main(void)
    {
        int *p1 = [malloc](malloc.html)(10*sizeof *p1);
        free(p1); // every allocated pointer must be freed
     
        int *p2 = [calloc](calloc.html)(10, sizeof *p2);
        int *p3 = [realloc](realloc.html)(p2, 1000*sizeof *p3);
        if(p3) // p3 not null means p2 was freed by realloc
           free(p3);
        else // p3 null means p2 was not freed
           free(p2);
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/free&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.24.3.3 The free function (p: 365) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.3.3 The free function (p: 254) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.3.3 The free function (p: 348) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.3.2 The free function (p: 313) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.3.2 The free function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/free&action=edit&section=6 "Edit section: See also")] See also

[ malloc](malloc.html "c/memory/malloc") |  allocates memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_malloc&action=edit)  
---|---  
[ free_sized](free_sized.html "c/memory/free sized")(C23) |  deallocates previously allocated sized memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_free_sized&action=edit)  
[ free_aligned_sized](free_aligned_sized.html "c/memory/free aligned sized")(C23) |  deallocates previously allocated sized and aligned memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_free_aligned_sized&action=edit)  
[C++ documentation](../../cpp/memory/c/free.html "cpp/memory/c/free") for free  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/memory/free&oldid=175228](https://en.cppreference.com/mwiki/index.php?title=c/memory/free&oldid=175228)" 

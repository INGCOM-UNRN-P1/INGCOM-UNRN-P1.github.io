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
[free](free.html "c/memory/free")  
[free_sized](free_sized.html "c/memory/free sized")(C23)  
**free_aligned_sized**(C23)  
[aligned_alloc](aligned_alloc.html "c/memory/aligned alloc")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/navbar_content&action=edit)

Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
void free_aligned_sized( void* ptr, [size_t](../types/size_t.html) alignment, [size_t](../types/size_t.html) size ); |  |  (since C23)  
| |   
  
If ptr is a null pointer or the result obtained from a call to aligned_alloc, where alignment is equal to the requested allocation alignment and size is equal to the requested allocation size, this function is equivalent to [free](free.html)(ptr). Otherwise, the behavior is undefined. 

The result of an [malloc](malloc.html "c/memory/malloc"), [calloc](calloc.html "c/memory/calloc"), or [realloc](realloc.html "c/memory/realloc") call may not be passed to `free_aligned_sized`. 

`free_aligned_sized` is thread-safe: it behaves as though only accessing the memory locations visible through its argument, and not any static storage. 

A call to `free_aligned_sized` that deallocates a region of memory _synchronizes-with_ a call to any subsequent allocation function that allocates the same or a part of the same region of memory. This synchronization occurs after any access to the memory by the deallocating function and before any access to the memory by the allocation function. There is a single total order of all allocation and deallocation functions operating on each particular region of memory. 

## Contents

  * [1 Parameters](free_aligned_sized.html#Parameters)
  * [2 Return value](free_aligned_sized.html#Return_value)
  * [3 Example](free_aligned_sized.html#Example)
  * [4 References](free_aligned_sized.html#References)
  * [5 See also](free_aligned_sized.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/free_aligned_sized&action=edit&section=1 "Edit section: Parameters")] Parameters

ptr  |  \-  |  pointer to the memory to deallocate   
---|---|---  
alignment  |  \-  |  alignment of memory to deallocate   
size  |  \-  |  size of memory to deallocate   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/free_aligned_sized&action=edit&section=2 "Edit section: Return value")] Return value

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/free_aligned_sized&action=edit&section=3 "Edit section: Example")] Example

| This section is incomplete  
Reason: no example   
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/free_aligned_sized&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.24.3.5 The free_sized function (p: 366) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/free_aligned_sized&action=edit&section=5 "Edit section: See also")] See also

[ aligned_alloc](aligned_alloc.html "c/memory/aligned alloc")(C11) |  allocates aligned memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_aligned_alloc&action=edit)  
---|---  
[ free](free.html "c/memory/free") |  deallocates previously allocated memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_free&action=edit)  
[ free_sized](free_sized.html "c/memory/free sized")(C23) |  deallocates previously allocated sized memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_free_sized&action=edit)  
[ malloc](malloc.html "c/memory/malloc") |  allocates memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_malloc&action=edit)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/memory/free_aligned_sized&oldid=175230](https://en.cppreference.com/mwiki/index.php?title=c/memory/free_aligned_sized&oldid=175230)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo no example](../../Category%253ATodo_no_example.html "Category:Todo no example")



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
[free_aligned_sized](free_aligned_sized.html "c/memory/free aligned sized")(C23)  
**aligned_alloc**(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/navbar_content&action=edit)

Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
void *aligned_alloc( [size_t](../types/size_t.html) alignment, [size_t](../types/size_t.html) size ); |  |  (since C11)  
| |   
  
Allocate size bytes of uninitialized storage whose alignment is specified by alignment. The size parameter must be an integral multiple of alignment. 

`aligned_alloc` is thread-safe: it behaves as though only accessing the memory locations visible through its argument, and not any static storage. 

A previous call to [free](free.html "c/memory/free"), free_sized, and free_aligned_sized(since C23) or [realloc](realloc.html "c/memory/realloc") that deallocates a region of memory _synchronizes-with_ a call to `aligned_alloc` that allocates the same or a part of the same region of memory. This synchronization occurs after any access to the memory by the deallocating function and before any access to the memory by `aligned_alloc`. There is a single total order of all allocation and deallocation functions operating on each particular region of memory. 

## Contents

  * [1 Parameters](aligned_alloc.html#Parameters)
  * [2 Return value](aligned_alloc.html#Return_value)
  * [3 Notes](aligned_alloc.html#Notes)
  * [4 Example](aligned_alloc.html#Example)
  * [5 References](aligned_alloc.html#References)
  * [6 See also](aligned_alloc.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/aligned_alloc&action=edit&section=1 "Edit section: Parameters")] Parameters

alignment  |  \-  |  specifies the alignment. Must be a valid alignment supported by the implementation.   
---|---|---  
size  |  \-  |  number of bytes to allocate. An integral multiple of alignment  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/aligned_alloc&action=edit&section=2 "Edit section: Return value")] Return value

On success, returns the pointer to the beginning of newly allocated memory. To avoid a memory leak, the returned pointer must be deallocated with [free](free.html "c/memory/free") or [realloc](realloc.html "c/memory/realloc"). 

On failure, returns a null pointer. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/aligned_alloc&action=edit&section=3 "Edit section: Notes")] Notes

Passing a size which is not an integral multiple of alignment or an alignment which is not valid or not supported by the implementation causes the function to fail and return a null pointer (C11, as published, specified undefined behavior in this case, this was corrected by [DR460](https://open-std.org/JTC1/SC22/WG14/www/docs/summary.htm#dr_460)). Removal of size restrictions to make it possible to allocate small objects at restrictive alignment boundaries (similar to [`alignas`](../language/alignas.html "c/language/ Alignas")) has been proposed by [N2072](https://open-std.org/JTC1/SC22/WG14/www/docs/n2072.htm). 

As an example of the "supported by the implementation" requirement, POSIX function [`posix_memalign`](https://pubs.opengroup.org/onlinepubs/9699919799/functions/posix_memalign.html) accepts any alignment that is a power of two and a multiple of sizeof(void *), and POSIX-based implementations of `aligned_alloc` inherit this requirements. 

Fundamental alignments are always supported. If alignment is a power of two and not greater than _Alignof([max_align_t](../types/max_align_t.html)), `aligned_alloc` may simply call [malloc](malloc.html "c/memory/malloc"). 

Regular [malloc](malloc.html "c/memory/malloc") aligns memory suitable for any object type with a fundamental alignment. The `aligned_alloc` is useful for over-aligned allocations, such as to [SSE](https://en.wikipedia.org/wiki/Streaming_SIMD_Extensions "enwiki:Streaming SIMD Extensions"), cache line, or [VM page](https://en.wikipedia.org/wiki/Page_\(computer_memory\)#Multiple_page_sizes "enwiki:Page \(computer memory\)") boundary. 

This function is not supported in Microsoft C Runtime library because its implementation of std::free is [unable to handle aligned allocations](https://learn.microsoft.com/en-us/cpp/standard-library/cstdlib#remarks-6) of any kind. Instead, MS CRT provides [`_aligned_malloc`](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/aligned-malloc) (to be freed with [`_aligned_free`](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/aligned-free)). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/aligned_alloc&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        int *p1 = [malloc](malloc.html)(10*sizeof *p1);
        [printf](../io/fprintf.html)("default-aligned addr:   %p\n", (void*)p1);
        [free](free.html)(p1);
     
        int *p2 = aligned_alloc(1024, 1024*sizeof *p2);
        [printf](../io/fprintf.html)("1024-byte aligned addr: %p\n", (void*)p2);
        [free](free.html)(p2);
    }

Possible output: 
    
    
    default-aligned addr:   0x1e40c20
    1024-byte aligned addr: 0x1e41000

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/aligned_alloc&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.22.3.1 The aligned_alloc function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.3.1 The aligned_alloc function (p: 253) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.3.1 The aligned_alloc function (p: 347-348) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/aligned_alloc&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/memory/c/aligned_alloc.html "cpp/memory/c/aligned alloc") for aligned_alloc  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/memory/aligned_alloc&oldid=157842](https://en.cppreference.com/mwiki/index.php?title=c/memory/aligned_alloc&oldid=157842)" 

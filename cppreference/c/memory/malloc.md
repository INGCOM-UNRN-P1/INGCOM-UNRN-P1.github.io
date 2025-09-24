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

**malloc**  
---  
[calloc](calloc.html "c/memory/calloc")  
[realloc](realloc.html "c/memory/realloc")  
[free](free.html "c/memory/free")  
[free_sized](free_sized.html "c/memory/free sized")(C23)  
[free_aligned_sized](free_aligned_sized.html "c/memory/free aligned sized")(C23)  
[aligned_alloc](aligned_alloc.html "c/memory/aligned alloc")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/navbar_content&action=edit)

Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
void *malloc( [size_t](../types/size_t.html) size ); |  |   
| |   
  
Allocates `size` bytes of uninitialized storage. 

If allocation succeeds, returns a pointer that is suitably aligned for any object type with [fundamental alignment](../language/object.html#Alignment "c/language/object"). 

If `size` is zero, the behavior of `malloc` is implementation-defined. For example, a null pointer may be returned. Alternatively, a non-null pointer may be returned; but such a pointer should not be [dereferenced](../language/operator_member_access.html "c/language/operator member access"), and should be passed to [free](free.html "c/memory/free") to avoid memory leaks. 

`malloc` is thread-safe: it behaves as though only accessing the memory locations visible through its argument, and not any static storage. A previous call to [free](free.html "c/memory/free"), free_sized, and free_aligned_sized(since C23) or [realloc](realloc.html "c/memory/realloc") that deallocates a region of memory _synchronizes-with_ a call to `malloc` that allocates the same or a part of the same region of memory. This synchronization occurs after any access to the memory by the deallocating function and before any access to the memory by `malloc`. There is a single total order of all allocation and deallocation functions operating on each particular region of memory.  | (since C11)  
---|---  
  
## Contents

  * [1 Parameters](malloc.html#Parameters)
  * [2 Return value](malloc.html#Return_value)
  * [3 Example](malloc.html#Example)
  * [4 References](malloc.html#References)
  * [5 See also](malloc.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/malloc&action=edit&section=1 "Edit section: Parameters")] Parameters

size  |  \-  |  number of bytes to allocate   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/malloc&action=edit&section=2 "Edit section: Return value")] Return value

On success, returns the pointer to the beginning of newly allocated memory. To avoid a memory leak, the returned pointer must be deallocated with [free()](free.html "c/memory/free") or [realloc()](realloc.html "c/memory/realloc"). 

On failure, returns a null pointer. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/malloc&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>   
    #include <stdlib.h> 
     
    int main(void) 
    {
        int *p1 = malloc(4*sizeof(int));  // allocates enough for an array of 4 int
        int *p2 = malloc(sizeof(int[4])); // same, naming the type directly
        int *p3 = malloc(4*sizeof *p3);   // same, without repeating the type name
     
        if(p1) {
            for(int n=0; n<4; ++n) // populate the array
                p1[n] = n*n;
            for(int n=0; n<4; ++n) // print it back out
                [printf](../io/fprintf.html)("p1[%d] == %d\n", n, p1[n]);
        }
     
        [free](free.html)(p1);
        [free](free.html)(p2);
        [free](free.html)(p3);
    }

Output: 
    
    
    p1[0] == 0
    p1[1] == 1
    p1[2] == 4
    p1[3] == 9

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/malloc&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.3.4 The malloc function (p: 254) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.3.4 The malloc function (p: 349) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.3.3 The malloc function (p: 314) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.3.3 The malloc function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/malloc&action=edit&section=5 "Edit section: See also")] See also

[ free](free.html "c/memory/free") |  deallocates previously allocated memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_free&action=edit)  
---|---  
[C++ documentation](../../cpp/memory/c/malloc.html "cpp/memory/c/malloc") for malloc  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/memory/malloc&oldid=157841](https://en.cppreference.com/mwiki/index.php?title=c/memory/malloc&oldid=157841)" 

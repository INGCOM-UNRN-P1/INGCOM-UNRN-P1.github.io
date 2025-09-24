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
**calloc**  
[realloc](realloc.html "c/memory/realloc")  
[free](free.html "c/memory/free")  
[free_sized](free_sized.html "c/memory/free sized")(C23)  
[free_aligned_sized](free_aligned_sized.html "c/memory/free aligned sized")(C23)  
[aligned_alloc](aligned_alloc.html "c/memory/aligned alloc")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/navbar_content&action=edit)

Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
void* calloc( [size_t](../types/size_t.html) num, [size_t](../types/size_t.html) size ); |  |   
| |   
  
Allocates memory for an array of num objects of size and initializes all bytes in the allocated storage to zero. 

If allocation succeeds, returns a pointer to the lowest (first) byte in the allocated memory block that is suitably aligned for any object type with [fundamental alignment](../language/object.html#Alignment "c/language/object"). 

If size is zero, the behavior is implementation defined (null pointer may be returned, or some non-null pointer may be returned that may not be used to access storage). 

`calloc` is thread-safe: it behaves as though only accessing the memory locations visible through its argument, and not any static storage. A previous call to [free](free.html "c/memory/free"), free_sized, and free_aligned_sized(since C23) or [realloc](realloc.html "c/memory/realloc") that deallocates a region of memory _synchronizes-with_ a call to `calloc` that allocates the same or a part of the same region of memory. This synchronization occurs after any access to the memory by the deallocating function and before any access to the memory by `calloc`. There is a single total order of all allocation and deallocation functions operating on each particular region of memory.  | (since C11)  
---|---  
  
## Contents

  * [1 Parameters](calloc.html#Parameters)
  * [2 Return value](calloc.html#Return_value)
  * [3 Notes](calloc.html#Notes)
  * [4 Example](calloc.html#Example)
  * [5 References](calloc.html#References)
  * [6 See also](calloc.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/calloc&action=edit&section=1 "Edit section: Parameters")] Parameters

num  |  \-  |  number of objects   
---|---|---  
size  |  \-  |  size of each object   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/calloc&action=edit&section=2 "Edit section: Return value")] Return value

On success, returns the pointer to the beginning of newly allocated memory. To avoid a memory leak, the returned pointer must be deallocated with [free()](free.html "c/memory/free") or [realloc()](realloc.html "c/memory/realloc"). 

On failure, returns a null pointer. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/calloc&action=edit&section=3 "Edit section: Notes")] Notes

Due to the alignment requirements, the number of allocated bytes is not necessarily equal to num * size. 

Initialization to all bits zero does not guarantee that a floating-point or a pointer would be initialized to 0.0 and the null pointer value, respectively (although that is true on all common platforms). 

Originally (in C89), support for zero size was added to accommodate code such as 
    
    
    OBJ* p = calloc(0, sizeof(OBJ)); // "zero-length" placeholder
    ...
    while(1)
    {
        p = [realloc](realloc.html)(p, c * sizeof(OBJ)); // reallocations until size settles
        ... // code that may change c or break out of loop
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/calloc&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        int* p1 = calloc(4, sizeof(int));    // allocate and zero out an array of 4 int
        int* p2 = calloc(1, sizeof(int[4])); // same, naming the array type directly
        int* p3 = calloc(4, sizeof *p3);     // same, without repeating the type name
     
        if (p2)
        {
            for (int n = 0; n < 4; ++n) // print the array
                [printf](../io/fprintf.html)("p2[%d] == %d\n", n, p2[n]);
        }
     
        [free](free.html)(p1);
        [free](free.html)(p2);
        [free](free.html)(p3);
    }

Output: 
    
    
    p2[0] == 0
    p2[1] == 0
    p2[2] == 0
    p2[3] == 0

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/calloc&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.22.3.2 The calloc function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.3.2 The calloc function (p: 253) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.3.2 The calloc function (p: 348) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.3.1 The calloc function (p: 313) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.3.1 The calloc function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/memory/calloc&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/memory/c/calloc.html "cpp/memory/c/calloc") for calloc  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/memory/calloc&oldid=157923](https://en.cppreference.com/mwiki/index.php?title=c/memory/calloc&oldid=157923)" 

From cppreference.com

< [c](../../c.html "c")‎ | [algorithm](../algorithm.html "c/algorithm")

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

[ Algorithms](../algorithm.html "c/algorithm")

**qsort qsort_s**(C11)  
---  
[bsearchbsearch_s](bsearch.html "c/algorithm/bsearch")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/algorithm/navbar_content&action=edit)

Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
void qsort( void* ptr, [size_t](../types/size_t.html) count, [size_t](../types/size_t.html) size,  
int (*comp)(const void*, const void*) ); |  (1)  |   
errno_t qsort_s( void* ptr, rsize_t count, rsize_t size,  
int (*comp)(const void*, const void*, void*),  
void* context ); |  (2)  |  (since C11)  
| |   
  
1) Sorts the given array pointed to by ptr in ascending order. The array contains count elements of size bytes. Function pointed to by comp is used for object comparison.

2) Same as (1), except that the additional context parameter context is passed to comp and that the following errors are detected at runtime and call the currently installed [constraint handler](../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * count or size is greater than RSIZE_MAX
  * ptr or comp is a null pointer (unless count is zero) 


    As with all bounds-checked functions, `qsort_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<stdlib.h>`](../header/stdlib.html "c/header/stdlib").

If comp indicates two elements as equivalent, their order in the resulting sorted array is unspecified. 

## Contents

  * [1 Parameters](qsort.html#Parameters)
  * [2 Return value](qsort.html#Return_value)
  * [3 Notes](qsort.html#Notes)
  * [4 Example](qsort.html#Example)
  * [5 References](qsort.html#References)
  * [6 See also](qsort.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/algorithm/qsort&action=edit&section=1 "Edit section: Parameters")] Parameters

ptr  |  \-  |  pointer to the array to sort   
---|---|---  
count  |  \-  |  number of elements in the array   
size  |  \-  |  size of each element in the array in bytes   
comp  |  \-  |  comparison function which returns ​a negative integer value if the first argument is _less_ than the second, a positive integer value if the first argument is _greater_ than the second and zero if the arguments are equivalent.  
The signature of the comparison function should be equivalent to the following:  int cmp(const void *a, const void *b); The function must not modify the objects passed to it and must return consistent results when called for the same objects, regardless of their positions in the array. ​   
context  |  \-  |  additional information (e.g., collating sequence), passed to comp as the third argument   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/algorithm/qsort&action=edit&section=2 "Edit section: Return value")] Return value

1) (none)

2) zero on success, non-zero if a runtime constraints violation was detected

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/algorithm/qsort&action=edit&section=3 "Edit section: Notes")] Notes

Despite the name, neither C nor POSIX standards require this function to be implemented using [quicksort](https://en.wikipedia.org/wiki/Quicksort "enwiki:Quicksort") or make any complexity or stability guarantees. 

Unlike other bounds-checked functions, `qsort_s` does not treat arrays of zero size as a runtime constraint violation and instead returns successfully without altering the array (the other function that accepts arrays of zero size is bsearch_s). 

The implementation of `qsort_s` in the [Windows CRT](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/qsort-s) is incompatible with the C standard. The Microsoft's version is declared as: void qsort_s(void *base, [size_t](../types/size_t.html) num, [size_t](../types/size_t.html) width,  
int (*compare )(void *, const void *, const void *), void * context);. It does not return a value, and the comparison function has a reversed parameter order with regard to the standard: the context is passed first. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/algorithm/qsort&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <limits.h>
    #include <stdio.h>
    #include <stdlib.h>
     
    int compare_ints(const void* a, const void* b)
    {
        int arg1 = *(const int*)a;
        int arg2 = *(const int*)b;
     
        if (arg1 < arg2) return -1;
        if (arg1 > arg2) return 1;
        return 0;
     
        // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
     
        // return arg1 - arg2; // erroneous shortcut: undefined behavior in case of
                               // integer overflow, such as with INT_MIN here
    }
     
    int main(void)
    {
        int ints[] = {-2, 99, 0, -743, 2, [INT_MIN](../types/limits.html), 4};
        int size = sizeof ints / sizeof *ints;
     
        qsort(ints, size, sizeof(int), compare_ints);
     
        for (int i = 0; i < size; i++)
            [printf](../io/fprintf.html)("%d ", ints[i]);
     
        [printf](../io/fprintf.html)("\n");
    }

Output: 
    
    
    -2147483648 -743 -2 0 2 4 99

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/algorithm/qsort&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.22.5.2 The qsort function (p: TBD) 



    

  * K.3.6.3.2 The qsort_s function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.5.2 The qsort function (p: 258-259) 



    

  * K.3.6.3.2 The qsort_s function (p: 442-443) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.5.2 The qsort function (p: 355-356) 



    

  * K.3.6.3.2 The qsort_s function (p: 609) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.5.2 The qsort function (p: 319) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.5.2 The qsort function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/algorithm/qsort&action=edit&section=6 "Edit section: See also")] See also

[ bsearchbsearch_s](bsearch.html "c/algorithm/bsearch")(C11) |  searches an array for an element of unspecified type   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/algorithm/dsc_bsearch&action=edit)  
---|---  
[C++ documentation](../../cpp/algorithm/qsort.html "cpp/algorithm/qsort") for qsort  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/algorithm/qsort&oldid=168864](https://en.cppreference.com/mwiki/index.php?title=c/algorithm/qsort&oldid=168864)" 

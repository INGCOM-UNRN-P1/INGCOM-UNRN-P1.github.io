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

[qsortqsort_s](qsort.html "c/algorithm/qsort")(C11)  
---  
**bsearch bsearch_s**(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/algorithm/navbar_content&action=edit)

Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
void* bsearch( const void *key, const void *ptr, [size_t](../types/size_t.html) count, [size_t](../types/size_t.html) size,  
int (*comp)(const void*, const void*) ); |  (1)  |   
void* bsearch_s( const void *key, const void *ptr, rsize_t count, rsize_t size,  
int (*comp)(const void *, const void *, void *),  
void *context ); |  (2)  |  (since C11)  
/*QVoid*/* bsearch( const void *key, /*QVoid*/ *ptr, [size_t](../types/size_t.html) count, [size_t](../types/size_t.html) size,  
int (*comp)(const void*, const void*) ); |  (3)  |  (since C23)  
/*QVoid*/* bsearch_s( const void *key, /*QVoid*/ *ptr, rsize_t count, rsize_t size,  
int (*comp)(const void *, const void *, void *),  
void *context ); |  (4)  |  (since C23)  
| |   
  
1) Finds an element equal to element pointed to by `key` in an array pointed to by `ptr`. The array contains `count` elements of `size` bytes and must be partitioned with respect to `key`, that is, all the elements that compare less than must appear before all the elements that compare equal to, and those must appear before all the elements that compare greater than the key object. A fully sorted array satisfies these requirements. The elements are compared using function pointed to by `comp`. The behavior is undefined if the array is not already partitioned with respect to `*key` in ascending order according to the same criterion that `comp` uses.

2) Same as (1), except that the additional state argument `context` is passed to `comp` and that the following errors are detected at runtime and call the currently installed [constraint handler](../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * `count` or `size` is greater than RSIZE_MAX
  * `key`, `ptr` or `comp` is a null pointer (unless `count` is zero) 


    As with all bounds-checked functions, `bsearch_s` (and the corresponding type-generic macro)(since C23) is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<stdlib.h>`](../header/stdlib.html "c/header/stdlib").

3,4) Type-generic macros equivalent to (1) and (2) respectively. Let `T` be a unqualified object type (including void). 

    

  * If `ptr` is of type const T*, the return type is const void*. 
  * Otherwise, if `ptr` is of type T*, the return type is void*. 
  * Otherwise, the behavior is undefined. 


If a macro definition of each of these generic functions is suppressed to access an actual function (e.g. if (bsearch), (bsearch_s), or a function pointer is used), the actual function declaration (1) or (2) becomes visible.

If the array contains several elements that `comp` would indicate as equal to the element searched for, then it is unspecified which element the function will return as the result. 

Direct usages of actual functions (1) and (2) are deprecated.  | (since C23)  
---|---  
  
## Contents

  * [1 Parameters](bsearch.html#Parameters)
  * [2 Return value](bsearch.html#Return_value)
  * [3 Notes](bsearch.html#Notes)
  * [4 Example](bsearch.html#Example)
  * [5 References](bsearch.html#References)
  * [6 See also](bsearch.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/algorithm/bsearch&action=edit&section=1 "Edit section: Parameters")] Parameters

key  |  \-  |  pointer to the element to search for   
---|---|---  
ptr  |  \-  |  pointer to the array to examine   
count  |  \-  |  number of element in the array   
size  |  \-  |  size of each element in the array in bytes   
comp  |  \-  |  comparison function which returns ​a negative integer value if the first argument is _less_ than the second, a positive integer value if the first argument is _greater_ than the second and zero if the arguments are equivalent. `key` is passed as the first argument, an element from the array as the second.  
The signature of the comparison function should be equivalent to the following:  int cmp(const void *a, const void *b); The function must not modify the objects passed to it and must return consistent results when called for the same objects, regardless of their positions in the array. ​   
context  |  \-  |  state of the comparator (e.g., collating sequence), passed to `comp` as the third argument   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/algorithm/bsearch&action=edit&section=2 "Edit section: Return value")] Return value

1) Pointer to an element in the array that compares equal to *key, or null pointer if such element has not been found.

2) Same as (1), except that the null pointer is also returned on runtime constraints violations.

3,4) Same as (1) and (2) respectively, except that cv-qualification is adjusted.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/algorithm/bsearch&action=edit&section=3 "Edit section: Notes")] Notes

Despite the name, neither C nor POSIX standards require this function to be implemented using binary search or make any complexity guarantees. 

Unlike other bounds-checked functions, `bsearch_s` does not treat arrays of zero size as a runtime constraint violation and instead indicates element not found (the other function that accepts arrays of zero size is qsort_s). 

Until `bsearch_s`, users of `bsearch` often used global variables to represent the state of the comparator. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/algorithm/bsearch&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdlib.h>
    #include <stdio.h>
     
    struct data {
        int nr;
        char const *value;
    } dat[] = {
        {1, "Foo"}, {2, "Bar"}, {3, "Hello"}, {4, "World"}
    };
     
    int data_cmp(void const *lhs, void const *rhs) 
    {
        struct data const *const l = lhs;
        struct data const *const r = rhs;
     
        if (l->nr < r->nr) return -1;
        else if (l->nr > r->nr) return 1;
        else return 0;
     
        // return (l->nr > r->nr) - (l->nr < r->nr); // possible shortcut
        // return l->nr - r->nr; // erroneous shortcut (fails if INT_MIN is present)
    }
     
    int main(void) 
    {
        struct data key = { .nr = 3 };
        struct data const *res = bsearch(&key, dat, sizeof dat / sizeof dat[0],
                                         sizeof dat[0], data_cmp);
        if (res) {
            [printf](../io/fprintf.html)("No %d: %s\n", res->nr, res->value);
        } else {
            [printf](../io/fprintf.html)("No %d not found\n", key.nr);
        }
    }

Output: 
    
    
    No 3: Hello

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/algorithm/bsearch&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.5.1 The bsearch function (p: 258) 



    

  * K.3.6.3.1 The bsearch_s function (p: 441-442) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.5.1 The bsearch function (p: 355) 



    

  * K.3.6.3.1 The bsearch_s function (p: 608-609) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.5.1 The bsearch function (p: 318-319) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.5.1 The bsearch function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/algorithm/bsearch&action=edit&section=6 "Edit section: See also")] See also

[ qsortqsort_s](qsort.html "c/algorithm/qsort")(C11) |  sorts a range of elements with unspecified type   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/algorithm/dsc_qsort&action=edit)  
---|---  
[C++ documentation](../../cpp/algorithm/bsearch.html "cpp/algorithm/bsearch") for bsearch  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/algorithm/bsearch&oldid=144569](https://en.cppreference.com/mwiki/index.php?title=c/algorithm/bsearch&oldid=144569)" 

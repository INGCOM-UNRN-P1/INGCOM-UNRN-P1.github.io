From cppreference.com

< [c](../../c.html "c")‎ | [types](../types.html "c/types")

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

[ Type support](../types.html "c/types")

[size_t](size_t.html "c/types/size t")  
---  
**ptrdiff_t**  
[nullptr_t](nullptr_t.html "c/types/nullptr t")(C23)  
[NULL](NULL.html "c/types/NULL")  
[max_align_t](max_align_t.html "c/types/max align t")(C11)  
[offsetof](offsetof.html "c/types/offsetof")  
[ Numeric limits](limits.html "c/types/limits")  
[ Fixed width integer types](integer.html "c/types/integer") (C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/navbar_content&action=edit)

Defined in header `[`<stddef.h>`](../header/stddef.html "c/header/stddef")` |  |   
---|---|---  
typedef /*implementation-defined*/ ptrdiff_t; |  |   
| |   
  
`ptrdiff_t` is the signed integer type of the result of [subtracting two pointers](../language/operator_arithmetic.html#Pointer_arithmetic "c/language/operator arithmetic"). 

The bit width of `ptrdiff_t` is not less than 17.  | (since C99)  
(until C23)  
---|---  
The bit width of `ptrdiff_t` is not less than 16.  | (since C23)  
  
## Contents

  * [1 Notes](ptrdiff_t.html#Notes)
  * [2 Possible implementation](ptrdiff_t.html#Possible_implementation)
  * [3 Example](ptrdiff_t.html#Example)
  * [4 References](ptrdiff_t.html#References)
  * [5 See also](ptrdiff_t.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/ptrdiff_t&action=edit&section=1 "Edit section: Notes")] Notes

`ptrdiff_t` is used for pointer arithmetic and array indexing, if negative values are possible. Programs that use other types, such as int, may fail on, e.g. 64-bit systems when the index exceeds [INT_MAX](limits.html "c/types/limits") or if it relies on 32-bit modular arithmetic. 

Only pointers to elements of the same array (including the pointer one past the end of the array) may be subtracted from each other. 

If an array is so large (greater than [PTRDIFF_MAX](limits.html "c/types/limits") elements, but equal to or less than [SIZE_MAX](limits.html "c/types/limits") bytes), that the difference between two pointers may not be representable as `ptrdiff_t`, the result of subtracting two such pointers is undefined. 

For char arrays shorter than [PTRDIFF_MAX](limits.html "c/types/limits"), `ptrdiff_t` acts as the signed counterpart of [size_t](size_t.html "c/types/size t"): it can store the size of the array of any type and is, on most platforms, synonymous with `intptr_t`). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/ptrdiff_t&action=edit&section=2 "Edit section: Possible implementation")] Possible implementation
    
    
    typedef typeof((int*)nullptr - (int*)nullptr) ptrdiff_t; // valid since C23  
  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/ptrdiff_t&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stddef.h>
    #include <stdint.h>
    #include <stdio.h>
     
    int main(void)
    {
        const [size_t](size_t.html) N = 100;
        int numbers[N];
     
        [printf](../io/fprintf.html)("PTRDIFF_MAX = %ld\n", [PTRDIFF_MAX](limits.html));
        int *p1 = &numbers[18], *p2 = &numbers[23];
        ptrdiff_t diff = p2 - p1;
        [printf](../io/fprintf.html)("p2-p1 = %td\n", diff);
    }

Possible output: 
    
    
    PTRDIFF_MAX = 9223372036854775807
    p2-p1 = 5

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/ptrdiff_t&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.19 Common definitions <stddef.h> (p: TBD) 



    

  * 7.20.3 Limits of other integer types (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.19 Common definitions <stddef.h> (p: 211) 



    

  * 7.20.3 Limits of other integer types (p: 215) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.19 Common definitions <stddef.h> (p: 288) 



    

  * 7.20.3 Limits of other integer types (p: 293) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.17 Common definitions <stddef.h> (p: 253) 



    

  * 7.18.3 Limits of other integer types (p: 258) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.1.6 Common definitions <stddef.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/ptrdiff_t&action=edit&section=5 "Edit section: See also")] See also

[ size_t](size_t.html "c/types/size t") |  unsigned integer type returned by the [`sizeof`](../language/sizeof.html "c/language/sizeof") operator   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_size_t&action=edit)  
---|---  
[ offsetof](offsetof.html "c/types/offsetof") |  byte offset from the beginning of a struct type to specified member   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_offsetof&action=edit)  
[C++ documentation](../../cpp/types/ptrdiff_t.html "cpp/types/ptrdiff t") for ptrdiff_t  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/types/ptrdiff_t&oldid=171717](https://en.cppreference.com/mwiki/index.php?title=c/types/ptrdiff_t&oldid=171717)" 

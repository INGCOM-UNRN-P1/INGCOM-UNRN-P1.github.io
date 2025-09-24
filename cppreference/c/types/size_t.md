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

**size_t**  
---  
[ptrdiff_t](ptrdiff_t.html "c/types/ptrdiff t")  
[nullptr_t](nullptr_t.html "c/types/nullptr t")(C23)  
[NULL](NULL.html "c/types/NULL")  
[max_align_t](max_align_t.html "c/types/max align t")(C11)  
[offsetof](offsetof.html "c/types/offsetof")  
[ Numeric limits](limits.html "c/types/limits")  
[ Fixed width integer types](integer.html "c/types/integer") (C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/navbar_content&action=edit)

Defined in header `[`<stddef.h>`](../header/stddef.html "c/header/stddef")` |  |   
---|---|---  
Defined in header `[`<stdio.h>`](../header/stdio.html "c/header/stdio")` |  |   
Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")` |  |   
Defined in header `[`<string.h>`](../header/string.html "c/header/string")` |  |   
Defined in header `[`<time.h>`](../header/time.html "c/header/time")` |  |   
Defined in header `[`<uchar.h>`](../header/uchar.html "c/header/uchar")` |  | (since C11)  
Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")` |  | (since C95)  
typedef /*implementation-defined*/ size_t; |  |   
| |   
  
`size_t` is the unsigned integer type of the result of [`sizeof`](../language/sizeof.html "c/language/sizeof"), [offsetof](offsetof.html "c/types/offsetof") and _Alignof(until C23)alignof(since C23), depending on the [data model](../language/arithmetic_types.html#Data_models "c/language/arithmetic types"). 

The bit width of `size_t` is not less than 16.  | (since C99)  
---|---  
  
## Contents

  * [1 Notes](size_t.html#Notes)
  * [2 Possible implementation](size_t.html#Possible_implementation)
  * [3 Example](size_t.html#Example)
  * [4 References](size_t.html#References)
  * [5 See also](size_t.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/size_t&action=edit&section=1 "Edit section: Notes")] Notes

`size_t` can store the maximum size of a theoretically possible object of any type (including array). 

`size_t` is commonly used for array indexing and loop counting. Programs that use other types, such as unsigned int, for array indexing may fail on, e.g. 64-bit systems when the index exceeds [UINT_MAX](limits.html "c/types/limits") or if it relies on 32-bit modular arithmetic. 

###  Possible implementation

typedef typeof(sizeof(0)) size_t; | (since C23)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/size_t&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stddef.h>
    #include <stdint.h>
    #include <stdio.h>
     
    int main(void)
    {
        const size_t N = 101;
        int numbers[N];
        size_t sum = 0;
        for (size_t ndx = 0; ndx < N; ++ndx)
            sum += numbers[ndx] = ndx;
        size_t size = sizeof numbers;
        [printf](../io/fprintf.html)("sum = %zu\n", sum);
        [printf](../io/fprintf.html)("size = %zu\n", size);
        [printf](../io/fprintf.html)("SIZE_MAX = %zu\n", [SIZE_MAX](limits.html));
    }

Possible output: 
    
    
    sum = 5050
    size = 404
    SIZE_MAX = 18446744073709551615

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/size_t&action=edit&section=4 "Edit section: References")] References

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



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/size_t&action=edit&section=5 "Edit section: See also")] See also

[ ptrdiff_t](ptrdiff_t.html "c/types/ptrdiff t") |  signed integer type returned when subtracting two pointers   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_ptrdiff_t&action=edit)  
---|---  
[ offsetof](offsetof.html "c/types/offsetof") |  byte offset from the beginning of a struct type to specified member   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_offsetof&action=edit)  
[C++ documentation](../../cpp/types/size_t.html "cpp/types/size t") for size_t  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/types/size_t&oldid=183044](https://en.cppreference.com/mwiki/index.php?title=c/types/size_t&oldid=183044)" 

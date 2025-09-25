From cppreference.com

< [c](../c.html "c")

[ C](../c.html "c")

[Compiler support](compiler_support.html "c/compiler support")  
---  
[Language](language.html "c/language")  
[Headers](header.html "c/header")  
**Type support**  
[Program utilities](program.html "c/program")  
[Variadic function support](variadic.html "c/variadic")  
[Error handling](error.html "c/error")  
[Dynamic memory management](memory.html "c/memory")  
[Strings library](string.html "c/string")  
[Algorithms](algorithm.html "c/algorithm")  
[Numerics](numeric.html "c/numeric")  
[Date and time utilities](chrono.html "c/chrono")  
[Input/output support](io.html "c/io")  
[Localization support](locale.html "c/locale")  
[Concurrency support](thread.html "c/thread") (C11)  
[Technical Specifications](experimental.html "c/experimental")  
[Symbol index](index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

**Type support**

[size_t](types/size_t.html "c/types/size t")  
---  
[ptrdiff_t](types/ptrdiff_t.html "c/types/ptrdiff t")  
[nullptr_t](types/nullptr_t.html "c/types/nullptr t")(C23)  
[NULL](types/NULL.html "c/types/NULL")  
[max_align_t](types/max_align_t.html "c/types/max align t")(C11)  
[offsetof](types/offsetof.html "c/types/offsetof")  
[ Numeric limits](types/limits.html "c/types/limits")  
[ Fixed width integer types](types/integer.html "c/types/integer") (C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/navbar_content&action=edit)

See also [type system overview](language/types.html "c/language/types") and [arithmetic types defined by the language](language/arithmetic_types.html "c/language/arithmetic types"). 

## Contents

  * [1 Basic types](types.html#Basic_types)
    * [1.1 Additional basic types and convenience macros](types.html#Additional_basic_types_and_convenience_macros)
    * [1.2 Fixed width integer types (since C99)](types.html#Fixed_width_integer_types_.28since_C99.29)
    * [1.3 Numeric limits](types.html#Numeric_limits)
  * [2 Notes](types.html#Notes)
  * [3 Example](types.html#Example)
  * [4 References](types.html#References)
  * [5 See also](types.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types&action=edit&section=1 "Edit section: Basic types")] Basic types

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types&action=edit&section=2 "Edit section: Additional basic types and convenience macros")] Additional basic types and convenience macros

Defined in header `[`<stddef.h>`](header/stddef.html "c/header/stddef")`  
---  
[ size_t](types/size_t.html "c/types/size t") |  unsigned integer type returned by the [`sizeof`](language/sizeof.html "c/language/sizeof") operator   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_size_t&action=edit)  
[ ptrdiff_t](types/ptrdiff_t.html "c/types/ptrdiff t") |  signed integer type returned when subtracting two pointers   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_ptrdiff_t&action=edit)  
[ nullptr_t](types/nullptr_t.html "c/types/nullptr t")(C23) |  the type of the predefined null pointer constant [`nullptr`](language/nullptr.html "c/language/nullptr")   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_nullptr_t&action=edit)  
[ NULL](types/NULL.html "c/types/NULL") |  implementation-defined null pointer constant   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_NULL&action=edit)  
[ max_align_t](types/max_align_t.html "c/types/max align t")(C11) |  a type with alignment requirement as great as any other scalar type   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_max_align_t&action=edit)  
[ offsetof](types/offsetof.html "c/types/offsetof") |  byte offset from the beginning of a struct type to specified member   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_offsetof&action=edit)  
Defined in header `[`<stdbool.h>`](header/stdbool.html "c/header/stdbool")`  
bool(C99)(removed in C23) |  convenience macro, expands to [`_Bool`](keyword/_Bool.html "c/keyword/ Bool")   
(keyword macro)  
true(C99)(removed in C23) |  expands to integer constant 1   
(macro constant)  
false(C99)(removed in C23) |  expands to integer constant ​0​   
(macro constant)  
__bool_true_false_are_defined(C99)(deprecated in C23) |  expands to integer constant 1   
(macro constant)  
Defined in header `[`<stdalign.h>`](header/stdalign.html "c/header/stdalign")`  
alignas(C11)(removed in C23) |  convenience macro, expands to keyword [`_Alignas`](keyword/_Alignas.html "c/keyword/ Alignas")   
(keyword macro)  
alignof(C11)(removed in C23) |  convenience macro, expands to keyword [`_Alignof`](keyword/_Alignof.html "c/keyword/ Alignof")   
(keyword macro)  
__alignas_is_defined(C11)(removed in C23) |  expands to integer constant 1   
(macro constant)  
__alignof_is_defined(C11)(removed in C23) |  expands to integer constant 1   
(macro constant)  
Defined in header `[`<stdnoreturn.h>`](header/stdnoreturn.html "c/header/stdnoreturn")`  
noreturn(C11)(deprecated in C23) |  convenience macro, expands to [`_Noreturn`](keyword/_Noreturn.html "c/keyword/ Noreturn")   
(keyword macro)  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types&action=edit&section=3 "Edit section: Fixed width integer types \(since C99\)")] [Fixed width integer types](types/integer.html "c/types/integer") (since C99)

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types&action=edit&section=4 "Edit section: Numeric limits")] [Numeric limits](types/limits.html "c/types/limits")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types&action=edit&section=5 "Edit section: Notes")] Notes

The type of true and false is int rather than _Bool. A program may undefine and perhaps then redefine the macros bool, true and false. However, such ability is a deprecated feature.  | (since C99)  
(until C23)  
---|---  
The type of true and false is bool. It is unspecified whether any of bool, _Bool, true, or false is implemented as a predefined macro. If bool, true, or false (but not _Bool) is defined as a predefined macro, a program may undefine and perhaps redefine it.  | (since C23)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types&action=edit&section=6 "Edit section: Example")] Example

Run this code
    
    
    #include <stdalign.h>
    #include <stdbool.h>
    #include <stdio.h>
     
    int main(void)
    {
        [printf](io/fprintf.html)("%d %d %d\n", true && false, true || false, !false);
        [printf](io/fprintf.html)("%d %d\n", true ^ true, true + true);
        [printf](io/fprintf.html)("%zu\n", alignof(short));
    }

Possible output: 
    
    
    0 1 1
    0 2
    2

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types&action=edit&section=7 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.15 Alignment <stdalign.h> (p: TBD) 



    

  * 7.18 Boolean type and values <stdbool.h> (p: TBD) 



    

  * 7.19 Common definitions <stddef.h> (p: TBD) 



    

  * 7.23 _Noreturn <stdnoreturn.h> (p: TBD) 



    

  * 7.31.9 Boolean type and values <stdbool.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.15 Alignment <stdalign.h> (p: 196) 



    

  * 7.18 Boolean type and values <stdbool.h> (p: 210) 



    

  * 7.19 Common definitions <stddef.h> (p: 211) 



    

  * 7.23 _Noreturn <stdnoreturn.h> (p: 263) 



    

  * 7.31.9 Boolean type and values <stdbool.h> (p: 332) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.15 Alignment <stdalign.h> (p: 268) 



    

  * 7.18 Boolean type and values <stdbool.h> (p: 287) 



    

  * 7.19 Common definitions <stddef.h> (p: 288) 



    

  * 7.23 _Noreturn <stdnoreturn.h> (p: 361) 



    

  * 7.31.9 Boolean type and values <stdbool.h> (p: 456) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.18 Boolean type and values <stdbool.h> (p: 253) 



    

  * 7.19 Common definitions <stddef.h> (p: 254) 



    

  * 7.26.7 Boolean type and values <stdbool.h> (p: 401) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.1.5 Common definitions <stddef.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types&action=edit&section=8 "Edit section: See also")] See also

[C++ documentation](../cpp/utility/rtti.html "cpp/types") for Type support library  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/types&oldid=180056](https://en.cppreference.com/mwiki/index.php?title=c/types&oldid=180056)" 

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
[ptrdiff_t](ptrdiff_t.html "c/types/ptrdiff t")  
[nullptr_t](nullptr_t.html "c/types/nullptr t")(C23)  
[NULL](NULL.html "c/types/NULL")  
[max_align_t](max_align_t.html "c/types/max align t")(C11)  
[offsetof](offsetof.html "c/types/offsetof")  
[ Numeric limits](limits.html "c/types/limits")  
**Fixed width integer types** (C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/navbar_content&action=edit)

## Contents

  * [1 Types](integer.html#Types)
  * [2 Macro constants](integer.html#Macro_constants)
    * [2.1 Signed integers : width](integer.html#Signed_integers_:_width)
    * [2.2 Signed integers : minimum value](integer.html#Signed_integers_:_minimum_value)
    * [2.3 Signed integers : maximum value](integer.html#Signed_integers_:_maximum_value)
    * [2.4 Unsigned integers : width](integer.html#Unsigned_integers_:_width)
    * [2.5 Unsigned integers : maximum value](integer.html#Unsigned_integers_:_maximum_value)
  * [3 Function macros for minimum-width integer constants](integer.html#Function_macros_for_minimum-width_integer_constants)
  * [4 Format macro constants](integer.html#Format_macro_constants)
    * [4.1 Format constants for the fprintf family of functions](integer.html#Format_constants_for_the_fprintf_family_of_functions)
    * [4.2 Format constants for the fscanf family of functions](integer.html#Format_constants_for_the_fscanf_family_of_functions)
  * [5 Example](integer.html#Example)
  * [6 References](integer.html#References)
  * [7 See also](integer.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/integer&action=edit&section=1 "Edit section: Types")] Types

Defined in header `[`<stdint.h>`](../header/stdint.html "c/header/stdint")`  
---  
`**int8_t**`  
`**int16_t**`  
`**int32_t**`  
`**int64_t**` |  signed integer type with width of  
exactly 8, 16, 32 and 64 bits respectively  
with no padding bits and using 2's complement for negative values  
(provided only if the implementation directly supports the type)   
`**int_fast8_t**`  
`**int_fast16_t**`  
`**int_fast32_t**`  
`**int_fast64_t**` |  fastest signed integer type with width of  
at least 8, 16, 32 and 64 bits respectively   
`**int_least8_t**`  
`**int_least16_t**`  
`**int_least32_t**`  
`**int_least64_t**` |  smallest signed integer type with width of  
at least 8, 16, 32 and 64 bits respectively   
`**intmax_t**` |  maximum width integer type   
`**intptr_t**` |  integer type capable of holding a pointer   
`**uint8_t**`  
`**uint16_t**`  
`**uint32_t**`  
`**uint64_t**` |  unsigned integer type with width of  
exactly 8, 16, 32 and 64 bits respectively   
(provided only if the implementation directly supports the type)   
`**uint_fast8_t**`  
`**uint_fast16_t**`  
`**uint_fast32_t**`  
`**uint_fast64_t**` |  fastest unsigned integer type with width of  
at least 8, 16, 32 and 64 bits respectively   
`**uint_least8_t**`  
`**uint_least16_t**`  
`**uint_least32_t**`  
`**uint_least64_t**` |  smallest unsigned integer type with width of  
at least 8, 16, 32 and 64 bits respectively   
`**uintmax_t**` |  maximum width unsigned integer type   
`**uintptr_t**` |  unsigned integer type capable of holding a pointer   
  
The implementation may define typedef names `int _N_ _t`, `int_fast _N_ _t`, `int_least _N_ _t`, `uint _N_ _t`, `uint_fast _N_ _t`, and `uint_least _N_ _t` when _N_ is not 8, 16, 32 or 64. Typedef names of the form `int _N_ _t` may only be defined if the implementation supports an integer type of that width with no padding. Thus, uint24_t denotes an unsigned integer type with a width of exactly 24 bits. 

Each of the macros listed in below is defined if and only if the implementation defines the corresponding typedef name. The macros `INT _N_ _C` and `UINT _N_ _C` correspond to the typedef names `int_least _N_ _t` and `uint_least _N_ _t`, respectively. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/integer&action=edit&section=2 "Edit section: Macro constants")] Macro constants

Defined in header `[`<stdint.h>`](../header/stdint.html "c/header/stdint")`  
---  
  
#####  Signed integers : width   
  
INT8_WIDTHINT16_WIDTHINT32_WIDTHINT64_WIDTH(C23)(optional) |  bit width of an object of type int8_t, int16_t, int32_t, int64_t (exactly 8, 16, 32, 64)   
(macro constant)  
INT_FAST8_WIDTHINT_FAST16_WIDTHINT_FAST32_WIDTHINT_FAST64_WIDTH(C23) |  bit width of an object of type int_fast8_t, int_fast16_t, int_fast32_t, int_fast64_t   
(macro constant)  
INT_LEAST8_WIDTHINT_LEAST16_WIDTHINT_LEAST32_WIDTHINT_LEAST64_WIDTH(C23) |  bit width of an object of type int_least8_t, int_least16_t, int_least32_t, int_least64_t   
(macro constant)  
INTPTR_WIDTH(C23)(optional) |  bit width of an object of type intptr_t   
(macro constant)  
INTMAX_WIDTH(C23) |  bit width of an object of type intmax_t   
(macro constant)  
  
#####  Signed integers : minimum value   
  
INT8_MININT16_MININT32_MININT64_MIN |  minimum value of an object of type int8_t, int16_t, int32_t, int64_t   
(macro constant)  
INT_FAST8_MININT_FAST16_MININT_FAST32_MININT_FAST64_MIN |  minimum value of an object of type int_fast8_t, int_fast16_t, int_fast32_t, int_fast64_t   
(macro constant)  
INT_LEAST8_MININT_LEAST16_MININT_LEAST32_MININT_LEAST64_MIN |  minimum value of an object of type int_least8_t, int_least16_t, int_least32_t, int_least64_t   
(macro constant)  
INTPTR_MIN |  minimum value of an object of type intptr_t   
(macro constant)  
INTMAX_MIN |  minimum value of an object of type intmax_t   
(macro constant)  
  
#####  Signed integers : maximum value   
  
INT8_MAXINT16_MAXINT32_MAXINT64_MAX |  maximum value of an object of type int8_t, int16_t, int32_t, int64_t   
(macro constant)  
INT_FAST8_MAXINT_FAST16_MAXINT_FAST32_MAXINT_FAST64_MAX |  maximum value of an object of type int_fast8_t, int_fast16_t, int_fast32_t, int_fast64_t   
(macro constant)  
INT_LEAST8_MAXINT_LEAST16_MAXINT_LEAST32_MAXINT_LEAST64_MAX |  maximum value of an object of type int_least8_t, int_least16_t, int_least32_t, int_least64_t   
(macro constant)  
INTPTR_MAX |  maximum value of an object of type intptr_t   
(macro constant)  
INTMAX_MAX |  maximum value of an object of type intmax_t   
(macro constant)  
  
#####  Unsigned integers : width   
  
UINT8_WIDTHUINT16_WIDTHUINT32_WIDTHUINT64_WIDTH(C23)(optional) |  bit width of an object of type uint8_t, uint16_t, uint32_t, uint64_t (exactly 8, 16, 32, 64)   
(macro constant)  
UINT_FAST8_WIDTHUINT_FAST16_WIDTHUINT_FAST32_WIDTHUINT_FAST64_WIDTH(C23) |  bit width of an object of type uint_fast8_t, uint_fast16_t, uint_fast32_t, uint_fast64_t   
(macro constant)  
UINT_LEAST8_WIDTHUINT_LEAST16_WIDTHUINT_LEAST32_WIDTHUINT_LEAST64_WIDTH(C23) |  bit width of an object of type uint_least8_t, uint_least16_t, uint_least32_t, uint_least64_t   
(macro constant)  
UINTPTR_WIDTH(C23)(optional) |  bit width of an object of type uintptr_t   
(macro constant)  
UINTMAX_WIDTH(C23) |  bit width of an object of type uintmax_t   
(macro constant)  
  
#####  Unsigned integers : maximum value   
  
UINT8_MAXUINT16_MAXUINT32_MAXUINT64_MAX |  maximum value of an object of type uint8_t, uint16_t, uint32_t, uint64_t   
(macro constant)  
UINT_FAST8_MAXUINT_FAST16_MAXUINT_FAST32_MAXUINT_FAST64_MAX |  maximum value of an object of type uint_fast8_t, uint_fast16_t, uint_fast32_t, uint_fast64_t   
(macro constant)  
UINT_LEAST8_MAXUINT_LEAST16_MAXUINT_LEAST32_MAXUINT_LEAST64_MAX |  maximum value of an object of type uint_least8_t, uint_least16_t, uint_least32_t, uint_least64_t   
(macro constant)  
UINTPTR_MAX |  maximum value of an object of type uintptr_t   
(macro constant)  
UINTMAX_MAX |  maximum value of an object of type uintmax_t   
(macro constant)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/integer&action=edit&section=3 "Edit section: Function macros for minimum-width integer constants")] Function macros for minimum-width integer constants

INT8_CINT16_CINT32_CINT64_C |  expands to an integer constant expression having the value specified by its argument and the type int_least8_t, int_least16_t, int_least32_t, int_least64_t respectively   
(function macro)  
---|---  
INTMAX_C |  expands to an integer constant expression having the value specified by its argument and the type intmax_t   
(function macro)  
UINT8_CUINT16_CUINT32_CUINT64_C |  expands to an integer constant expression having the value specified by its argument and the type uint_least8_t, uint_least16_t, uint_least32_t, uint_least64_t respectively   
(function macro)  
UINTMAX_C |  expands to an integer constant expression having the value specified by its argument and the type uintmax_t   
(function macro)  
      
    
    #include <stdint.h>
    UINT64_C(0x123) // might expand to 0x123ULL or 0x123UL

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/integer&action=edit&section=4 "Edit section: Format macro constants")] Format macro constants

Defined in header `[`<inttypes.h>`](../header/inttypes.html "c/header/inttypes")`  
---  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/integer&action=edit&section=5 "Edit section: Format constants for the fprintf family of functions")] Format constants for the [fprintf](../io/fprintf.html "c/io/fprintf") family of functions

Each of the `PRI` macros listed here is defined if and only if the implementation defines the corresponding typedef name. 

Equivalent  
for int or  
unsigned int | Description  | Macros for data types   
---|---|---  
  
  
  
  
`[u]int**x** _t`  
  
  
  
| `[u]int_least**x** _t` | `[u]int_fast**x** _t` | `[u]intmax_t` | `[u]intptr_t`  
`d` | output of a signed decimal integer value  | PRId**x** | PRIdLEAST**x** | PRIdFAST**x** | PRIdMAX  | PRIdPTR   
`i` | PRIi**x** | PRIiLEAST**x** | PRIiFAST**x** | PRIiMAX  | PRIiPTR   
`u` | output of an unsigned decimal integer value  | PRIu**x** | PRIuLEAST**x** | PRIuFAST**x** | PRIuMAX  | PRIuPTR   
`o` | output of an unsigned octal integer value  | PRIo**x** | PRIoLEAST**x** | PRIoFAST**x** | PRIoMAX  | PRIoPTR   
`x` | output of an unsigned lowercase hexadecimal integer value  | PRIx**x** | PRIxLEAST**x** | PRIxFAST**x** | PRIxMAX  | PRIxPTR   
`X` | output of an unsigned uppercase hexadecimal integer value  | PRIX**x** | PRIXLEAST**x** | PRIXFAST**x** | PRIXMAX  | PRIXPTR   
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/integer&action=edit&section=6 "Edit section: Format constants for the fscanf family of functions")] Format constants for the [fscanf](../io/fscanf.html "c/io/fscanf") family of functions

Each of the `SCN` macros listed in here is defined if and only if the implementation defines the corresponding typedef name and has a suitable [fscanf](../io/fscanf.html "c/io/fscanf") length modifier for the type. 

Equivalent  
for int or  
unsigned int | Description  | Macros for data types   
---|---|---  
  
  
  
  
`[u]int**x** _t`  
  
  
  
| `[u]int_least**x** _t` | `[u]int_fast**x** _t` | `[u]intmax_t` | `[u]intptr_t`  
`d` | input of a signed decimal integer value  | SCNd**x** | SCNdLEAST**x** | SCNdFAST**x** | SCNdMAX  | SCNdPTR   
`i` | input of a signed integer value (base is determined by the first characters parsed)  | SCNi**x** | SCNiLEAST**x** | SCNiFAST**x** | SCNiMAX  | SCNiPTR   
`u` | input of an unsigned decimal integer value  | SCNu**x** | SCNuLEAST**x** | SCNuFAST**x** | SCNuMAX  | SCNuPTR   
`o` | input of an unsigned octal integer value  | SCNo**x** | SCNoLEAST**x** | SCNoFAST**x** | SCNoMAX  | SCNoPTR   
`x` | input of an unsigned hexadecimal integer value  | SCNx**x** | SCNxLEAST**x** | SCNxFAST**x** | SCNxMAX  | SCNxPTR   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/integer&action=edit&section=7 "Edit section: Example")] Example

See also [C++ compatibility note](../../cpp/language/user_literal.html#Notes "cpp/language/user literal") regarding spaces before [format macros](integer.html#Format_macro_constants) used in this example.

Run this code
    
    
    #include <inttypes.h>
    #include <stdio.h>
     
    int main(void)
    {
        [printf](../io/fprintf.html)("%zu\n", sizeof(int64_t));
        [printf](../io/fprintf.html)("%s\n", PRId64);
        [printf](../io/fprintf.html)("%+" PRId64 "\n", INT64_MIN);
        [printf](../io/fprintf.html)("%+" PRId64 "\n", INT64_MAX);
     
        int64_t n = 7;
        [printf](../io/fprintf.html)("%+" PRId64 "\n", n);
    }

Possible output: 
    
    
    8
    lld
    -9223372036854775808
    +9223372036854775807
    +7

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/integer&action=edit&section=8 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.8.1 Macros for format specifiers (p: TBD) 



    

  * 7.18 Integer types <stdint.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.8.1 Macros for format specifiers (p: 158-159) 



    

  * 7.18 Integer types <stdint.h> (p: 212-216) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.8.1 Macros for format specifiers (p: 217-218) 



    

  * 7.18 Integer types <stdint.h> (p: 289-295) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.8.1 Macros for format specifiers (p: 198-199) 



    

  * 7.18 Integer types <stdint.h> (p: 255-261) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/integer&action=edit&section=9 "Edit section: See also")] See also

  * [Arithmetic types](../language/arithmetic_types.html "c/language/arithmetic types")

[C++ documentation](../../cpp/types/integer.html "cpp/types/integer") for Fixed width integer types  
---  
[C++ documentation](../../cpp/language/user_literal.html "cpp/language/user literal") for User-defined literals ([formatting macros note](../../cpp/language/user_literal.html#Notes "cpp/language/user literal"))  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/types/integer&oldid=157582](https://en.cppreference.com/mwiki/index.php?title=c/types/integer&oldid=157582)" 

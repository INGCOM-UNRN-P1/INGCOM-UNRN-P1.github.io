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
**Numeric limits**  
[ Fixed width integer types](integer.html "c/types/integer") (C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/navbar_content&action=edit)

**Numeric limits**

[FLT_ROUNDS](limits/FLT_ROUNDS.html "c/types/limits/FLT ROUNDS")  
---  
[FLT_EVAL_METHOD](limits/FLT_EVAL_METHOD.html "c/types/limits/FLT EVAL METHOD")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/limits/navbar_content&action=edit)

## Contents

  * [1 Limits of integer types](limits.html#Limits_of_integer_types)
    * [1.1 Limits of core language integer types](limits.html#Limits_of_core_language_integer_types)
    * [1.2 Limits of library type aliases](limits.html#Limits_of_library_type_aliases)
    * [1.3 Notes](limits.html#Notes)
    * [1.4 Example](limits.html#Example)
  * [2 Limits of floating-point types](limits.html#Limits_of_floating-point_types)
    * [2.1 Example](limits.html#Example_2)
  * [3 References](limits.html#References)
  * [4 See also](limits.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/limits&action=edit&section=1 "Edit section: Limits of integer types")] Limits of integer types

#####  Limits of core language integer types   
  
---  
Defined in header `[`<limits.h>`](../header/limits.html "c/header/limits")`  
BOOL_WIDTH(C23) |  bit width of _Bool   
(macro constant)  
CHAR_BIT |  bit width of byte   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_CHAR_BIT&action=edit)  
MB_LEN_MAX |  maximum number of bytes in a multibyte character   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_MB_LEN_MAX&action=edit)  
CHAR_WIDTH(C23) |  bit width of char, same as `CHAR_BIT`   
(macro constant)  
CHAR_MIN |  minimum value of char   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_CHAR_MIN&action=edit)  
CHAR_MAX |  maximum value of char   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_CHAR_MAX&action=edit)  
SCHAR_WIDTHSHRT_WIDTHINT_WIDTHLONG_WIDTHLLONG_WIDTH(C23)(C23)(C23)(C23)(C23) |  bit width of signed char, short, int, long, and long long respectively   
(macro constant)  
SCHAR_MINSHRT_MININT_MINLONG_MINLLONG_MIN(C99) |  minimum value of signed char, short, int, long and long long respectively   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_signed_MIN&action=edit)  
SCHAR_MAXSHRT_MAXINT_MAXLONG_MAXLLONG_MAX(C99) |  maximum value of signed char, short, int, long and long long respectively   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_signed_MAX&action=edit)  
UCHAR_WIDTHUSHRT_WIDTHUINT_WIDTHULONG_WIDTHULLONG_WIDTH(C23)(C23)(C23)(C23)(C23) |  bit width of unsigned char, unsigned short, unsigned int, unsigned long, and unsigned long long respectively   
(macro constant)  
UCHAR_MAXUSHRT_MAXUINT_MAXULONG_MAXULLONG_MAX(C99) |  maximum value of unsigned char, unsigned short, unsigned int,  
unsigned long and unsigned long long respectively   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_unsigned_MAX&action=edit)  
BITINT_MAXWIDTH(C23) |  maximum width N supported by the declaration of a bit-precise integer in the type specifier _BitInt(N), greater than or equal to `ULLONG_WIDTH`   
(macro constant)  
  
#####  Limits of library type aliases   
  
Defined in header `[`<stdint.h>`](../header/stdint.html "c/header/stdint")`  
PTRDIFF_WIDTH(C23) |  bit width of object of [ptrdiff_t](ptrdiff_t.html "c/types/ptrdiff t") type   
(macro constant)  
PTRDIFF_MIN(C99) |  minimum value of [ptrdiff_t](ptrdiff_t.html "c/types/ptrdiff t")   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_PTRDIFF_MIN&action=edit)  
PTRDIFF_MAX(C99) |  maximum value of [ptrdiff_t](ptrdiff_t.html "c/types/ptrdiff t")   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_PTRDIFF_MAX&action=edit)  
SIZE_WIDTH(C23) |  bit width of object of [size_t](size_t.html "c/types/size t") type   
(macro constant)  
SIZE_MAX(C99) |  maximum value of [size_t](size_t.html "c/types/size t")   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_SIZE_MAX&action=edit)  
SIG_ATOMIC_WIDTH(C23) |  bit width of object of [sig_atomic_t](../program/sig_atomic_t.html "c/program/sig atomic t") type   
(macro constant)  
SIG_ATOMIC_MIN(C99) |  minimum value of [sig_atomic_t](../program/sig_atomic_t.html "c/program/sig atomic t")   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_SIG_ATOMIC_MIN&action=edit)  
SIG_ATOMIC_MAX(C99) |  maximum value of [sig_atomic_t](../program/sig_atomic_t.html "c/program/sig atomic t")   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_SIG_ATOMIC_MAX&action=edit)  
WINT_WIDTH(C23) |  bit width of object of wint_t type   
(macro constant)  
WINT_MIN(C99) |  minimum value of `wint_t`   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_WINT_MIN&action=edit)  
WINT_MAX(C99) |  maximum value of `wint_t`   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_WINT_MAX&action=edit)  
Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")`  
Defined in header `[`<stdint.h>`](../header/stdint.html "c/header/stdint")`  
WCHAR_WIDTH(C23) |  bit width of object of wchar_t type   
(macro constant)  
WCHAR_MIN(C99) |  minimum value of wchar_t   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_WCHAR_MIN&action=edit)  
WCHAR_MAX(C99) |  maximum value of wchar_t   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_WCHAR_MAX&action=edit)  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/limits&action=edit&section=2 "Edit section: Notes")] Notes

The types of these constants, other than `CHAR_BIT` and `MB_LEN_MAX`, are required to match the results of the [integral promotions](../language/conversion.html#Integer_promotions "c/language/conversion") as applied to objects of the types they describe: `CHAR_MAX` may have type int or unsigned int, but never char. Similarly `USHRT_MAX` may not be of an unsigned type: its type may be int. 

A freestanding implementation may lack [sig_atomic_t](../program/sig_atomic_t.html "c/program/sig atomic t") and/or wint_t typedef names, in which case the `SIG_ATOMIC_*` and/or `WINT_*` macros are correspondingly absent. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/limits&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <limits.h>
    #include <stdint.h>
    #include <stdio.h>
     
    int main(void)
    {
        [printf](../io/fprintf.html)("CHAR_BIT       = %d\n", CHAR_BIT);
        [printf](../io/fprintf.html)("MB_LEN_MAX     = %d\n\n", MB_LEN_MAX);
     
        [printf](../io/fprintf.html)("CHAR_MIN       = %+d\n", CHAR_MIN);
        [printf](../io/fprintf.html)("CHAR_MAX       = %+d\n", CHAR_MAX);
        [printf](../io/fprintf.html)("SCHAR_MIN      = %+d\n", SCHAR_MIN);
        [printf](../io/fprintf.html)("SCHAR_MAX      = %+d\n", SCHAR_MAX);
        [printf](../io/fprintf.html)("UCHAR_MAX      = %u\n\n", UCHAR_MAX);
     
        [printf](../io/fprintf.html)("SHRT_MIN       = %+d\n", SHRT_MIN);
        [printf](../io/fprintf.html)("SHRT_MAX       = %+d\n", SHRT_MAX);
        [printf](../io/fprintf.html)("USHRT_MAX      = %u\n\n", USHRT_MAX);
     
        [printf](../io/fprintf.html)("INT_MIN        = %+d\n", INT_MIN);
        [printf](../io/fprintf.html)("INT_MAX        = %+d\n", INT_MAX);
        [printf](../io/fprintf.html)("UINT_MAX       = %u\n\n", UINT_MAX);
     
        [printf](../io/fprintf.html)("LONG_MIN       = %+ld\n", LONG_MIN);
        [printf](../io/fprintf.html)("LONG_MAX       = %+ld\n", LONG_MAX);
        [printf](../io/fprintf.html)("ULONG_MAX      = %lu\n\n", ULONG_MAX);
     
        [printf](../io/fprintf.html)("LLONG_MIN      = %+lld\n", LLONG_MIN);
        [printf](../io/fprintf.html)("LLONG_MAX      = %+lld\n", LLONG_MAX);
        [printf](../io/fprintf.html)("ULLONG_MAX     = %llu\n\n", ULLONG_MAX);
     
        [printf](../io/fprintf.html)("PTRDIFF_MIN    = %td\n", PTRDIFF_MIN);
        [printf](../io/fprintf.html)("PTRDIFF_MAX    = %+td\n", PTRDIFF_MAX);
        [printf](../io/fprintf.html)("SIZE_MAX       = %zu\n", SIZE_MAX);
        [printf](../io/fprintf.html)("SIG_ATOMIC_MIN = %+jd\n",([intmax_t](integer.html))SIG_ATOMIC_MIN);
        [printf](../io/fprintf.html)("SIG_ATOMIC_MAX = %+jd\n",([intmax_t](integer.html))SIG_ATOMIC_MAX);
        [printf](../io/fprintf.html)("WCHAR_MIN      = %+jd\n",([intmax_t](integer.html))WCHAR_MIN);
        [printf](../io/fprintf.html)("WCHAR_MAX      = %+jd\n",([intmax_t](integer.html))WCHAR_MAX);
        [printf](../io/fprintf.html)("WINT_MIN       = %jd\n", ([intmax_t](integer.html))WINT_MIN);
        [printf](../io/fprintf.html)("WINT_MAX       = %jd\n", ([intmax_t](integer.html))WINT_MAX);
    }

Possible output: 
    
    
    CHAR_BIT       = 8
    MB_LEN_MAX     = 16
     
    CHAR_MIN       = -128
    CHAR_MAX       = +127
    SCHAR_MIN      = -128
    SCHAR_MAX      = +127
    UCHAR_MAX      = 255
     
    SHRT_MIN       = -32768
    SHRT_MAX       = +32767
    USHRT_MAX      = 65535
     
    INT_MIN        = -2147483648
    INT_MAX        = +2147483647
    UINT_MAX       = 4294967295
     
    LONG_MIN       = -9223372036854775808
    LONG_MAX       = +9223372036854775807
    ULONG_MAX      = 18446744073709551615
     
    LLONG_MIN      = -9223372036854775808
    LLONG_MAX      = +9223372036854775807
    ULLONG_MAX     = 18446744073709551615
     
    PTRDIFF_MIN    = -9223372036854775808
    PTRDIFF_MAX    = +9223372036854775807
    SIZE_MAX       = 18446744073709551615
    SIG_ATOMIC_MIN = -2147483648
    SIG_ATOMIC_MAX = +2147483647
    WCHAR_MIN      = -2147483648
    WCHAR_MAX      = +2147483647
    WINT_MIN       = 0
    WINT_MAX       = 4294967295

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/limits&action=edit&section=4 "Edit section: Limits of floating-point types")] Limits of floating-point types

Defined in header `[`<float.h>`](../header/float.html "c/header/float")`  
---  
FLT_RADIX |  the radix (integer base) used by the representation of all three floating-point types   
(macro constant)  
DECIMAL_DIG(C99) |  conversion from long double to decimal with at least `DECIMAL_DIG` digits and back to long double is the identity conversion: this is the decimal precision required to serialize/deserialize a long double   
(macro constant)  
FLT_DECIMAL_DIGDBL_DECIMAL_DIGLDBL_DECIMAL_DIG(C11) |  conversion from float/double/long double to decimal with at least `FLT_DECIMAL_DIG`/`DBL_DECIMAL_DIG`/`LDBL_DECIMAL_DIG` digits and back is the identity conversion: this is the decimal precision required to serialize/deserialize a floating-point value. Defined to at least 6, 10, and 10 respectively, or 9 for IEEE float and 17 for IEEE double (see also the C++ analog: [`max_digits10`](../../cpp/types/numeric_limits/max_digits10.html "cpp/types/numeric limits/max digits10"))   
(macro constant)  
FLT_MINDBL_MINLDBL_MIN |  minimum, normalized, positive value of float, double and long double respectively   
(macro constant)  
FLT_TRUE_MINDBL_TRUE_MINLDBL_TRUE_MIN(C11) |  minimum positive value of float, double and long double respectively   
(macro constant)  
FLT_MAXDBL_MAXLDBL_MAX |  maximum finite value of float, double and long double respectively   
(macro constant)  
FLT_EPSILONDBL_EPSILONLDBL_EPSILON |  absolute value difference between 1.0 and the next representable value for float, double and long double respectively   
(macro constant)  
FLT_DIGDBL_DIGLDBL_DIG |  number of decimal digits that are guaranteed to be preserved in text → float/double/long double → text roundtrip without change due to rounding or overflow (see the C++ analog [`digits10`](../../cpp/types/numeric_limits/digits10.html "cpp/types/numeric limits/digits10") for detail)   
(macro constant)  
FLT_MANT_DIGDBL_MANT_DIGLDBL_MANT_DIG |  number of base-`FLT_RADIX` digits that are in the floating-point mantissa and that can be represented without losing precision for float, double and long double respectively   
(macro constant)  
FLT_MIN_EXPDBL_MIN_EXPLDBL_MIN_EXP |  minimum negative integer such that `FLT_RADIX` raised by power one less than that integer is a normalized float, double and long double respectively   
(macro constant)  
FLT_MIN_10_EXPDBL_MIN_10_EXPLDBL_MIN_10_EXP |  minimum negative integer such that 10 raised to that power is a normalized float, double and long double respectively   
(macro constant)  
FLT_MAX_EXPDBL_MAX_EXPLDBL_MAX_EXP |  maximum positive integer such that `FLT_RADIX` raised by power one less than that integer is a representable finite float, double and long double respectively   
(macro constant)  
FLT_MAX_10_EXPDBL_MAX_10_EXPLDBL_MAX_10_EXP |  maximum positive integer such that 10 raised to that power is a representable finite float, double and long double respectively   
(macro constant)  
[ FLT_ROUNDS](limits/FLT_ROUNDS.html "c/types/limits/FLT ROUNDS") |  rounding mode of floating-point arithmetic   
(macro constant)  
[ FLT_EVAL_METHOD](limits/FLT_EVAL_METHOD.html "c/types/limits/FLT EVAL METHOD")(C99) |  specifies in what precision all arithmetic operations are done   
(macro constant)  
FLT_HAS_SUBNORMDBL_HAS_SUBNORMLDBL_HAS_SUBNORM(C11)(deprecated in C23) |  whether the type supports subnormal ([denormal](https://en.wikipedia.org/wiki/Denormal_number "enwiki:Denormal number")) numbers:  
-1 – indeterminable, ​0​ – absent, 1 – present   
(macro constant)  
---|---  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/limits&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <float.h>
    #include <math.h>
    #include <stdio.h>
     
    int main(void)
    {
        [printf](../io/fprintf.html)("DECIMAL_DIG     = %d\n", DECIMAL_DIG);
        [printf](../io/fprintf.html)("FLT_DECIMAL_DIG = %d\n", FLT_DECIMAL_DIG);
        [printf](../io/fprintf.html)("FLT_RADIX       = %d\n", FLT_RADIX);
        [printf](../io/fprintf.html)("FLT_MIN         = %e\n", FLT_MIN);
        [printf](../io/fprintf.html)("FLT_MAX         = %e\n", FLT_MAX);
        [printf](../io/fprintf.html)("FLT_EPSILON     = %e\n", FLT_EPSILON);
        [printf](../io/fprintf.html)("FLT_DIG         = %d\n", FLT_DIG);
        [printf](../io/fprintf.html)("FLT_MANT_DIG    = %d\n", FLT_MANT_DIG);
        [printf](../io/fprintf.html)("FLT_MIN_EXP     = %d\n", FLT_MIN_EXP);
        [printf](../io/fprintf.html)("FLT_MIN_10_EXP  = %d\n", FLT_MIN_10_EXP);
        [printf](../io/fprintf.html)("FLT_MAX_EXP     = %d\n", FLT_MAX_EXP);
        [printf](../io/fprintf.html)("FLT_MAX_10_EXP  = %d\n", FLT_MAX_10_EXP);
        [printf](../io/fprintf.html)("FLT_ROUNDS      = %d\n", [FLT_ROUNDS](limits/FLT_ROUNDS.html));
        [printf](../io/fprintf.html)("FLT_EVAL_METHOD = %d\n", [FLT_EVAL_METHOD](limits/FLT_EVAL_METHOD.html));
        [printf](../io/fprintf.html)("FLT_HAS_SUBNORM = %d\n", FLT_HAS_SUBNORM);
    }

Possible output: 
    
    
    DECIMAL_DIG     = 37
    FLT_DECIMAL_DIG = 9
    FLT_RADIX       = 2
    FLT_MIN         = 1.175494e-38
    FLT_MAX         = 3.402823e+38
    FLT_EPSILON     = 1.192093e-07
    FLT_DIG         = 6
    FLT_MANT_DIG    = 24
    FLT_MIN_EXP     = -125
    FLT_MIN_10_EXP  = -37
    FLT_MAX_EXP     = 128
    FLT_MAX_10_EXP  = 38
    FLT_ROUNDS      = 1
    FLT_EVAL_METHOD = 1
    FLT_HAS_SUBNORM = 1

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/limits&action=edit&section=6 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 5.2.4.2 Numerical limits (p: TBD) 



    

  * 7.22.3 Limits of other integer types (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 5.2.4.2 Numerical limits (p: 20-27) 



    

  * 7.20.3 Limits of other integer types (p: 215-216) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 5.2.4.2 Numerical limits (p: 26-34) 



    

  * 7.20.3 Limits of other integer types (p: 293-294) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 5.2.4.2 Numerical limits (p: 21-28) 



    

  * 7.18.3 Limits of other integer types (p: 259-260) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 2.2.4.2 Numerical limits 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/limits&action=edit&section=7 "Edit section: See also")] See also

[C++ documentation](../../cpp/types/climits.html "cpp/types/climits") for C numeric limits interface  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/types/limits&oldid=180103](https://en.cppreference.com/mwiki/index.php?title=c/types/limits&oldid=180103)" 

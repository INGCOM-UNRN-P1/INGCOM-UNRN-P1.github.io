From cppreference.com

< [c](../../c.html "c")‎ | [header](../header.html "c/header")

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

[ Standard Library headers ](../header.html "c/header")

| [`<assert.h>`](assert.html "c/header/assert")  
---  
[`<complex.h>`](complex.html "c/header/complex") (C99)  
[`<ctype.h>`](ctype.html "c/header/ctype")  
[`<errno.h>`](errno.html "c/header/errno")  
[`<fenv.h>`](fenv.html "c/header/fenv") (C99)  
**`< float.h>`**  
[`<inttypes.h>`](inttypes.html "c/header/inttypes") (C99)` `  
[`<iso646.h>`](iso646.html "c/header/iso646") (C95)  
[`<limits.h>`](limits.html "c/header/limits")  
[`<locale.h>`](locale.html "c/header/locale")  
[`<math.h>`](math.html "c/header/math")  
  
| [`<setjmp.h>`](setjmp.html "c/header/setjmp")  
---  
[`<signal.h>`](signal.html "c/header/signal")  
[`<stdalign.h>`](stdalign.html "c/header/stdalign") (C11*)  
[`<stdarg.h>`](stdarg.html "c/header/stdarg")  
[`<stdatomic.h>`](stdatomic.html "c/header/stdatomic") (C11)` `  
[`<stdbit.h>`](stdbit.html "c/header/stdbit") (C23)  
[`<stdbool.h>`](stdbool.html "c/header/stdbool") (C99*)  
[`<stdckdint.h>`](stdckdint.html "c/header/stdckdint") (C23)  
[`<stddef.h>`](stddef.html "c/header/stddef")  
[`<stdint.h>`](stdint.html "c/header/stdint") (C99)  
[`<stdio.h>`](stdio.html "c/header/stdio")  
  
| [`<stdlib.h>`](stdlib.html "c/header/stdlib")  
---  
[`<stdmchar.h>`](stdmchar.html "c/header/stdmchar") (C29)  
[`<stdnoreturn.h>`](stdnoreturn.html "c/header/stdnoreturn") (C11*)  
[`<string.h>`](string.html "c/header/string")  
[`<tgmath.h>`](tgmath.html "c/header/tgmath") (C99)  
[`<threads.h>`](threads.html "c/header/threads") (C11)  
[`<time.h>`](time.html "c/header/time")  
[`<uchar.h>`](uchar.html "c/header/uchar") (C11)  
[`<wchar.h>`](wchar.html "c/header/wchar") (C95)  
[`<wctype.h>`](wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header is part of the [type support](../types.html "c/types") library, in particular its [numeric limits](../types/limits.html "c/types/limits") interface. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/float&action=edit&section=1 "Edit section: Macros")] Macros

FLT_RADIX |  the radix (integer base) used by the representation of all three floating-point types   
(macro constant)  
---|---  
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
[ FLT_ROUNDS](../types/limits/FLT_ROUNDS.html "c/types/limits/FLT ROUNDS") |  rounding mode of floating-point arithmetic   
(macro constant)  
[ FLT_EVAL_METHOD](../types/limits/FLT_EVAL_METHOD.html "c/types/limits/FLT EVAL METHOD")(C99) |  specifies in what precision all arithmetic operations are done   
(macro constant)  
FLT_HAS_SUBNORMDBL_HAS_SUBNORMLDBL_HAS_SUBNORM(C11)(deprecated in C23) |  whether the type supports subnormal ([denormal](https://en.wikipedia.org/wiki/Denormal_number "enwiki:Denormal number")) numbers:  
-1 – indeterminable, ​0​ – absent, 1 – present   
(macro constant)  
---|---  
| This section is incomplete  
Reason: Add macros from B.6.2, B.6.3   
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/float&action=edit&section=2 "Edit section: Synopsis")] Synopsis
    
    
    #define FLT_ROUNDS           /* see definition */
    #define FLT_EVAL_METHOD      /* see definition */
    #define FLT_HAS_SUBNORM      /* see definition */
    #define DBL_HAS_SUBNORM      /* see definition */
    #define LDBL_HAS_SUBNORM     /* see definition */
    #define FLT_RADIX            /* see definition */
    #define FLT_MANT_DIG         /* see definition */
    #define DBL_MANT_DIG         /* see definition */
    #define LDBL_MANT_DIG        /* see definition */
    #define FLT_DECIMAL_DIG      /* see definition */
    #define DBL_DECIMAL_DIG      /* see definition */
    #define LDBL_DECIMAL_DIG     /* see definition */
    #define DECIMAL_DIG          /* see definition */
    #define FLT_DIG              /* see definition */
    #define DBL_DIG              /* see definition */
    #define LDBL_DIG             /* see definition */
    #define FLT_MIN_EXP          /* see definition */
    #define DBL_MIN_EXP          /* see definition */
    #define LDBL_MIN_EXP         /* see definition */
    #define FLT_MIN_10_EXP       /* see definition */
    #define DBL_MIN_10_EXP       /* see definition */
    #define LDBL_MIN_10_EXP      /* see definition */
    #define FLT_MAX_EXP          /* see definition */
    #define DBL_MAX_EXP          /* see definition */
    #define LDBL_MAX_EXP         /* see definition */
    #define FLT_MAX_10_EXP       /* see definition */
    #define DBL_MAX_10_EXP       /* see definition */
    #define LDBL_MAX_10_EXP      /* see definition */
    #define FLT_MAX              /* see definition */
    #define DBL_MAX              /* see definition */
    #define LDBL_MAX             /* see definition */
    #define FLT_EPSILON          /* see definition */
    #define DBL_EPSILON          /* see definition */
    #define LDBL_EPSILON         /* see definition */
    #define FLT_MIN              /* see definition */
    #define DBL_MIN              /* see definition */
    #define LDBL_MIN             /* see definition */
    #define FLT_TRUE_MIN         /* see definition */
    #define DBL_TRUE_MIN         /* see definition */
    #define LDBL_TRUE_MIN        /* see definition */

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/float&oldid=180105](https://en.cppreference.com/mwiki/index.php?title=c/header/float&oldid=180105)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



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
[`<float.h>`](float.html "c/header/float")  
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
**`< tgmath.h>`** (C99)  
[`<threads.h>`](threads.html "c/header/threads") (C11)  
[`<time.h>`](time.html "c/header/time")  
[`<uchar.h>`](uchar.html "c/header/uchar") (C11)  
[`<wchar.h>`](wchar.html "c/header/wchar") (C95)  
[`<wctype.h>`](wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header is part of [numeric](../numeric.html#Type-generic_math "c/numeric") library and provides [type-generic macros](../numeric/tgmath.html "c/numeric/tgmath") that determine which real or, when applicable, complex function to call based on the types of the arguments. 

###  Includes  
  
---  
[`<math.h>`](math.html "c/header/math")  
[`<complex.h>`](complex.html "c/header/complex")  
  
  


| This section is incomplete  
Reason: 7.28 Type-generic math <tgmath.h>  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/tgmath&action=edit&section=1 "Edit section: Synopsis")] Synopsis

| This section is incomplete  
Reason: B.27 Type-generic math <tgmath.h>  
---|---  
      
    
    #include <math.h>
    #include <complex.h>
     
    #define __STDC_VERSION_TGMATH_H__ 202311L
    #define acos              /* see description */
    #define acosh             /* see description */
    #define acospi            /* see description */
    #define asin              /* see description */
    #define asinh             /* see description */
    #define asinpi            /* see description */
    #define atan              /* see description */
    #define atan2             /* see description */
    #define atan2pi           /* see description */
    #define atanh             /* see description */
    #define atanpi            /* see description */
    #define cbrt              /* see description */
    #define ceil              /* see description */
    #define compoundn         /* see description */
    #define copysign          /* see description */
    #define cos               /* see description */
    #define cosh              /* see description */
    #define cospi             /* see description */
    #define dadd              /* see description */
    #define ddiv              /* see description */
    #define dfma              /* see description */
    #define dmul              /* see description */
    #define dsqrt             /* see description */
    #define dsub              /* see description */
    #define erf               /* see description */
    #define erfc              /* see description */
    #define exp               /* see description */
    #define exp10             /* see description */
    #define exp10m1           /* see description */
    #define exp2              /* see description */
    #define exp2m1            /* see description */
    #define expm1             /* see description */
    #define fabs              /* see description */
    #define fadd              /* see description */
    #define fdim              /* see description */
    #define fdiv              /* see description */
    #define ffma              /* see description */
    #define floor             /* see description */
    #define fma               /* see description */
    #define fmax              /* see description */
    #define fmaximum          /* see description */
    #define fmaximum_mag      /* see description */
    #define fmaximum_mag_num  /* see description */
    #define fmaximum_num      /* see description */
    #define fmin              /* see description */
    #define fminimum          /* see description */
    #define fminimum_mag      /* see description */
    #define fminimum_mag_num  /* see description */
    #define fminimum_num      /* see description */
    #define fmod              /* see description */
    #define fmul              /* see description */
    #define frexp             /* see description */
    #define fromfp            /* see description */
    #define fromfpx           /* see description */
    #define fsqrt             /* see description */
    #define fsub              /* see description */
    #define hypot             /* see description */
    #define ilogb             /* see description */
    #define ldexp             /* see description */
    #define lgamma            /* see description */
    #define llogb             /* see description */
    #define llrint            /* see description */
    #define llround           /* see description */
    #define log               /* see description */
    #define log10             /* see description */
    #define log10p1           /* see description */
    #define log1p             /* see description */
    #define log2              /* see description */
    #define log2p1            /* see description */
    #define logb              /* see description */
    #define logp1             /* see description */
    #define lrint             /* see description */
    #define lround            /* see description */
    #define nearbyint         /* see description */
    #define nextafter         /* see description */
    #define nextdown          /* see description */
    #define nexttoward        /* see description */
    #define nextup            /* see description */
    #define pow               /* see description */
    #define pown              /* see description */
    #define powr              /* see description */
    #define remainder         /* see description */
    #define remquo            /* see description */
    #define rint              /* see description */
    #define rootn             /* see description */
    #define round             /* see description */
    #define roundeven         /* see description */
    #define rsqrt             /* see description */
    #define scalbln           /* see description */
    #define scalbn            /* see description */
    #define sin               /* see description */
    #define sinh              /* see description */
    #define sinpi             /* see description */
    #define sqrt              /* see description */
    #define tan               /* see description */
    #define tanh              /* see description */
    #define tanpi             /* see description */
    #define tgamma            /* see description */
    #define trunc             /* see description */
    #define ufromfp           /* see description */
    #define ufromfpx          /* see description */

Only if the implementation does not define __STDC_NO_COMPLEX__: 
    
    
    #ifndef __STDC_WANT_LIB_EXT1__
    #define carg  /* see description */
    #define cimag /* see description */
    #define conj  /* see description */
    #define cproj /* see description */
    #define creal /* see description */
    #endif

Only if the implementation defines __STDC_IEC_60559_DFP__: 
    
    
    #define d32add      /* see description */
    #define d32div      /* see description */
    #define d32fma      /* see description */
    #define d32mul      /* see description */
    #define d32sqrt     /* see description */
    #define d32sub      /* see description */
    #define d64add      /* see description */
    #define d64div      /* see description */
    #define d64fma      /* see description */
    #define d64mul      /* see description */
    #define d64sqrt     /* see description */
    #define d64sub      /* see description */
    #define llquantexp  /* see description */
    #define quantize    /* see description */
    #define quantum     /* see description */
    #define samequantum /* see description */

Only if the implementation defines __STDC_IEC_60559_TYPES__ and additionally the user code defines __STDC_WANT_IEC_60559_TYPES_EXT__ before any inclusion of `<tgmath.h>`: 
    
    
    #ifdef __STDC_WANT_IEC_60559_TYPES_EXT__
    #define /*dMadd*/   /* see description */
    #define /*dMdiv*/   /* see description */
    #define /*dMfma*/   /* see description */
    #define /*dMmul*/   /* see description */
    #define /*dMsqrt*/  /* see description */
    #define /*dMsub*/   /* see description */
    #define /*dMxadd*/  /* see description */
    #define /*dMxdiv*/  /* see description */
    #define /*dMxfma*/  /* see description */
    #define /*dMxmul*/  /* see description */
    #define /*dMxsqrt*/ /* see description */
    #define /*dMxsub*/  /* see description */
    #define /*fMadd*/   /* see description */
    #define /*fMdiv*/   /* see description */
    #define /*fMfma*/   /* see description */
    #define /*fMmul*/   /* see description */
    #define /*fMsqrt*/  /* see description */
    #define /*fMsub*/   /* see description */
    #define /*fMxadd*/  /* see description */
    #define /*fMxdiv*/  /* see description */
    #define /*fMxfma*/  /* see description */
    #define /*fMxmul*/  /* see description */
    #define /*fMxsqrt*/ /* see description */
    #define /*fMxsub*/  /* see description */

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/tgmath&oldid=180736](https://en.cppreference.com/mwiki/index.php?title=c/header/tgmath&oldid=180736)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



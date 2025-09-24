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
**`< complex.h>`** (C99)  
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
[`<tgmath.h>`](tgmath.html "c/header/tgmath") (C99)  
[`<threads.h>`](threads.html "c/header/threads") (C11)  
[`<time.h>`](time.html "c/header/time")  
[`<uchar.h>`](uchar.html "c/header/uchar") (C11)  
[`<wchar.h>`](wchar.html "c/header/wchar") (C95)  
[`<wctype.h>`](wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header is part of the [complex number arithmetic](../numeric/complex.html "c/numeric/complex") library. 

| 

## Contents

  * [1 Types](complex.html#Types)
  * [2 The imaginary constant](complex.html#The_imaginary_constant)
  * [3 Manipulation](complex.html#Manipulation)
  * [4 Exponential functions](complex.html#Exponential_functions)
  * [5 Power functions](complex.html#Power_functions)
  * [6 Trigonometric functions](complex.html#Trigonometric_functions)
  * [7 Hyperbolic functions](complex.html#Hyperbolic_functions)
  * [8 Synopsis](complex.html#Synopsis)

  
---  
  
#####  Types   
  
[ imaginary](../numeric/complex/imaginary.html "c/numeric/complex/imaginary")(C99) |  imaginary type macro   
(keyword macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_imaginary&action=edit)  
[ complex](../numeric/complex/complex.html "c/numeric/complex/complex")(C99) |  complex type macro   
(keyword macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_complex&action=edit)  
  
#####  The imaginary constant   
  
[ _Imaginary_I](../numeric/complex/Imaginary_I.html "c/numeric/complex/Imaginary I")(C99) |  the imaginary unit constant i   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_Imaginary_I&action=edit)  
[ _Complex_I](../numeric/complex/Complex_I.html "c/numeric/complex/Complex I")(C99) |  the complex unit constant i   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_Complex_I&action=edit)  
[ I](../numeric/complex/I.html "c/numeric/complex/I")(C99) |  the complex or imaginary unit constant i   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_I&action=edit)  
  
#####  Manipulation   
  
[ CMPLXCMPLXFCMPLXL](../numeric/complex/CMPLX.html "c/numeric/complex/CMPLX")(C11)(C11)(C11) |  constructs a complex number from real and imaginary parts   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_CMPLX&action=edit)  
[ crealcrealfcreall](../numeric/complex/creal.html "c/numeric/complex/creal")(C99)(C99)(C99) |  computes the real part of a complex number   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_creal&action=edit)  
[ cimagcimagfcimagl](../numeric/complex/cimag.html "c/numeric/complex/cimag")(C99)(C99)(C99) |  computes the imaginary part a complex number   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cimag&action=edit)  
[ cabscabsfcabsl](../numeric/complex/cabs.html "c/numeric/complex/cabs")(C99)(C99)(C99) |  computes the magnitude of a complex number   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cabs&action=edit)  
[ cargcargfcargl](../numeric/complex/carg.html "c/numeric/complex/carg")(C99)(C99)(C99) |  computes the phase angle of a complex number   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_carg&action=edit)  
[ conjconjfconjl](../numeric/complex/conj.html "c/numeric/complex/conj")(C99)(C99)(C99) |  computes the complex conjugate   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_conj&action=edit)  
[ cprojcprojfcprojl](../numeric/complex/cproj.html "c/numeric/complex/cproj")(C99)(C99)(C99) |  computes the projection on Riemann sphere   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cproj&action=edit)  
  
#####  Exponential functions   
  
[ cexpcexpfcexpl](../numeric/complex/cexp.html "c/numeric/complex/cexp")(C99)(C99)(C99) |  computes the complex base-e exponential   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cexp&action=edit)  
[ clogclogfclogl](../numeric/complex/clog.html "c/numeric/complex/clog")(C99)(C99)(C99) |  computes the complex natural logarithm   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_clog&action=edit)  
  
#####  Power functions   
  
[ cpowcpowfcpowl](../numeric/complex/cpow.html "c/numeric/complex/cpow")(C99)(C99)(C99) |  computes the complex power function   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cpow&action=edit)  
[ csqrtcsqrtfcsqrtl](../numeric/complex/csqrt.html "c/numeric/complex/csqrt")(C99)(C99)(C99) |  computes the complex square root   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_csqrt&action=edit)  
  
#####  Trigonometric functions   
  
[ csincsinfcsinl](../numeric/complex/csin.html "c/numeric/complex/csin")(C99)(C99)(C99) |  computes the complex sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_csin&action=edit)  
[ ccosccosfccosl](../numeric/complex/ccos.html "c/numeric/complex/ccos")(C99)(C99)(C99) |  computes the complex cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ccos&action=edit)  
[ ctanctanfctanl](../numeric/complex/ctan.html "c/numeric/complex/ctan")(C99)(C99)(C99) |  computes the complex tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ctan&action=edit)  
[ casincasinfcasinl](../numeric/complex/casin.html "c/numeric/complex/casin")(C99)(C99)(C99) |  computes the complex arc sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_casin&action=edit)  
[ cacoscacosfcacosl](../numeric/complex/cacos.html "c/numeric/complex/cacos")(C99)(C99)(C99) |  computes the complex arc cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cacos&action=edit)  
[ catancatanfcatanl](../numeric/complex/catan.html "c/numeric/complex/catan")(C99)(C99)(C99) |  computes the complex arc tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_catan&action=edit)  
  
#####  Hyperbolic functions   
  
[ csinhcsinhfcsinhl](../numeric/complex/csinh.html "c/numeric/complex/csinh")(C99)(C99)(C99) |  computes the complex hyperbolic sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_csinh&action=edit)  
[ ccoshccoshfccoshl](../numeric/complex/ccosh.html "c/numeric/complex/ccosh")(C99)(C99)(C99) |  computes the complex hyperbolic cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ccosh&action=edit)  
[ ctanhctanhfctanhl](../numeric/complex/ctanh.html "c/numeric/complex/ctanh")(C99)(C99)(C99) |  computes the complex hyperbolic tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ctanh&action=edit)  
[ casinhcasinhfcasinhl](../numeric/complex/casinh.html "c/numeric/complex/casinh")(C99)(C99)(C99) |  computes the complex arc hyperbolic sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_casinh&action=edit)  
[ cacoshcacoshfcacoshl](../numeric/complex/cacosh.html "c/numeric/complex/cacosh")(C99)(C99)(C99) |  computes the complex arc hyperbolic cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cacosh&action=edit)  
[ catanhcatanhfcatanhl](../numeric/complex/catanh.html "c/numeric/complex/catanh")(C99)(C99)(C99) |  computes the complex arc hyperbolic tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_catanh&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/complex&action=edit&section=1 "Edit section: Synopsis")] Synopsis
    
    
    #define __STDC_VERSION_COMPLEX_H__ 202311L
     
    #define complex       _Complex
    #define imaginary     /* implementation-defined */
    #define _Imaginary_I  /* implementation-defined */
    #define _Complex_I    /* implementation-defined */
    #define I             _Complex_I
     
    #pragma STDC CX_LIMITED_RANGE /*on-off-switch*/
     
    double [complex](../numeric/complex/complex.html) [cacos](../numeric/complex/cacos.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [cacosf](../numeric/complex/cacos.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [cacosl](../numeric/complex/cacos.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [casin](../numeric/complex/casin.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [casinf](../numeric/complex/casin.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [casinl](../numeric/complex/casin.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [catan](../numeric/complex/catan.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [catanf](../numeric/complex/catan.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [catanl](../numeric/complex/catan.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [ccos](../numeric/complex/ccos.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [ccosf](../numeric/complex/ccos.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [ccosl](../numeric/complex/ccos.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [csin](../numeric/complex/csin.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [csinf](../numeric/complex/csin.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [csinl](../numeric/complex/csin.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [ctan](../numeric/complex/ctan.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [ctanf](../numeric/complex/ctan.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [ctanl](../numeric/complex/ctan.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [cacosh](../numeric/complex/cacosh.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [cacoshf](../numeric/complex/cacosh.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [cacoshl](../numeric/complex/cacosh.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [casinh](../numeric/complex/casinh.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [casinhf](../numeric/complex/casinh.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [casinhl](../numeric/complex/casinh.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [catanh](../numeric/complex/catanh.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [catanhf](../numeric/complex/catanh.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [catanhl](../numeric/complex/catanh.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [ccosh](../numeric/complex/ccosh.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [ccoshf](../numeric/complex/ccosh.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [ccoshl](../numeric/complex/ccosh.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [csinh](../numeric/complex/csinh.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [csinhf](../numeric/complex/csinh.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [csinhl](../numeric/complex/csinh.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [ctanh](../numeric/complex/ctanh.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [ctanhf](../numeric/complex/ctanh.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [ctanhl](../numeric/complex/ctanh.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [cexp](../numeric/complex/cexp.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [cexpf](../numeric/complex/cexp.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [cexpl](../numeric/complex/cexp.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [clog](../numeric/complex/clog.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [clogf](../numeric/complex/clog.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [clogl](../numeric/complex/clog.html)(long double [complex](../numeric/complex/complex.html) z);
    double [cabs](../numeric/complex/cabs.html)(double [complex](../numeric/complex/complex.html) z);
    float [cabsf](../numeric/complex/cabs.html)(float [complex](../numeric/complex/complex.html) z);
    long double [cabsl](../numeric/complex/cabs.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [cpow](../numeric/complex/cpow.html)(double [complex](../numeric/complex/complex.html) x, double [complex](../numeric/complex/complex.html) y);
    float [complex](../numeric/complex/complex.html) [cpowf](../numeric/complex/cpow.html)(float [complex](../numeric/complex/complex.html) x, float [complex](../numeric/complex/complex.html) y);
    long double [complex](../numeric/complex/complex.html) [cpowl](../numeric/complex/cpow.html)(long double [complex](../numeric/complex/complex.html) x, long double [complex](../numeric/complex/complex.html) y);
    double [complex](../numeric/complex/complex.html) [csqrt](../numeric/complex/csqrt.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [csqrtf](../numeric/complex/csqrt.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [csqrtl](../numeric/complex/csqrt.html)(long double [complex](../numeric/complex/complex.html) z);
    double [carg](../numeric/complex/carg.html)(double [complex](../numeric/complex/complex.html) z);
    float [cargf](../numeric/complex/carg.html)(float [complex](../numeric/complex/complex.html) z);
    long double [cargl](../numeric/complex/carg.html)(long double [complex](../numeric/complex/complex.html) z);
    double [cimag](../numeric/complex/cimag.html)(double [complex](../numeric/complex/complex.html) z);
    float [cimagf](../numeric/complex/cimag.html)(float [complex](../numeric/complex/complex.html) z);
    long double [cimagl](../numeric/complex/cimag.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [CMPLX](../numeric/complex/CMPLX.html)(double x, double y);
    float [complex](../numeric/complex/complex.html) [CMPLXF](../numeric/complex/CMPLX.html)(float x, float y);
    long double [complex](../numeric/complex/complex.html) [CMPLXL](../numeric/complex/CMPLX.html)(long double x, long double y);
    double [complex](../numeric/complex/complex.html) [conj](../numeric/complex/conj.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [conjf](../numeric/complex/conj.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [conjl](../numeric/complex/conj.html)(long double [complex](../numeric/complex/complex.html) z);
    double [complex](../numeric/complex/complex.html) [cproj](../numeric/complex/cproj.html)(double [complex](../numeric/complex/complex.html) z);
    float [complex](../numeric/complex/complex.html) [cprojf](../numeric/complex/cproj.html)(float [complex](../numeric/complex/complex.html) z);
    long double [complex](../numeric/complex/complex.html) [cprojl](../numeric/complex/cproj.html)(long double [complex](../numeric/complex/complex.html) z);
    double [creal](../numeric/complex/creal.html)(double [complex](../numeric/complex/complex.html) z);
    float [crealf](../numeric/complex/creal.html)(float [complex](../numeric/complex/complex.html) z);
    long double [creall](../numeric/complex/creal.html)(long double [complex](../numeric/complex/complex.html) z);
     
    // Only if the implementation defines __STDC_IEC_60559_TYPES__ and additionally the user
    // code defines __STDC_WANT_IEC_60559_TYPES_EXT__ before any inclusion of <complex.h>:
    #ifdef __STDC_WANT_IEC_60559_TYPES_EXT__
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*cacosfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*cacosfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*casinfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*casinfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*catanfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*catanfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*ccosfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*ccosfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*csinfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*csinfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*ctanfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*ctanfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*cacoshfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*cacoshfNx*/( /*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*casinhfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*casinhfNx*/( /*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*catanhfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*catanhfNx*/( /*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*ccoshfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*ccoshfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*csinhfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*csinhfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*ctanhfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*ctanhfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*cexpfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*cexpfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*clogfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*clogfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ /*cabsfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ /*cabsfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*cpowfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) x, /*_FloatN*/ [complex](../numeric/complex/complex.html) y);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*cpowfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) x, /*_FloatNx*/ [complex](../numeric/complex/complex.html) y);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*csqrtfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*csqrtfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ /*cargfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ /*cargfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ /*cimagfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ /*cimagfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*CMPLXFN*/(/*_FloatN*/ x, /*_FloatN*/ y);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*CMPLXFNX*/(/*_FloatNx*/ x, /*_FloatNx*/ y);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*conjfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*conjfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ [complex](../numeric/complex/complex.html) /*cprojfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ [complex](../numeric/complex/complex.html) /*cprojfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatN*/ /*crealfN*/(/*_FloatN*/ [complex](../numeric/complex/complex.html) z);
    /*_FloatNx*/ /*crealfNx*/(/*_FloatNx*/ [complex](../numeric/complex/complex.html) z);
    #endif

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/complex&oldid=180079](https://en.cppreference.com/mwiki/index.php?title=c/header/complex&oldid=180079)" 

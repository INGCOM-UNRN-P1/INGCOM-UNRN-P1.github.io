From cppreference.com

< [c](../../c.html "c")‎ | [numeric](../numeric.html "c/numeric")

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

[ Numerics](../numeric.html "c/numeric")

[Common mathematical functions](math.html "c/numeric/math")  
---  
[Floating-point environment](fenv.html "c/numeric/fenv") (C99)  
[Pseudo-random number generation](random.html "c/numeric/random")  
**Complex number arithmetic** (C99)  
[Type-generic math](tgmath.html "c/numeric/tgmath") (C99)  
[Bit manipulation](../numeric.html#Bit_manipulation "c/numeric") (C23)  
[Checked integer arithmetic](../numeric.html#Checked_integer_arithmetic "c/numeric") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/navbar_content&action=edit)

**Complex number arithmetic**

Types and the imaginary constant  
---  
| [complex](complex/complex.html "c/numeric/complex/complex")(C99)  
---  
[_Complex_I](complex/Complex_I.html "c/numeric/complex/Complex I")(C99)  
[CMPLX](complex/CMPLX.html "c/numeric/complex/CMPLX")(C11)  
  
| [imaginary](complex/imaginary.html "c/numeric/complex/imaginary")(C99)  
---  
[_Imaginary_I](complex/Imaginary_I.html "c/numeric/complex/Imaginary I")(C99)  
[I](complex/I.html "c/numeric/complex/I")(C99)  
  
Manipulation  
| [cimag](complex/cimag.html "c/numeric/complex/cimag")(C99)  
---  
[creal](complex/creal.html "c/numeric/complex/creal")(C99)  
[carg](complex/carg.html "c/numeric/complex/carg")(C99)  
  
| [cabs](complex/cabs.html "c/numeric/complex/cabs")(C99)  
---  
[conj](complex/conj.html "c/numeric/complex/conj")(C99)  
[cproj](complex/cproj.html "c/numeric/complex/cproj")(C99)  
  
Power and exponential functions  
| [cexp](complex/cexp.html "c/numeric/complex/cexp")(C99)  
---  
[clog](complex/clog.html "c/numeric/complex/clog")(C99)  
  
| [cpow](complex/cpow.html "c/numeric/complex/cpow")(C99)  
---  
[csqrt](complex/csqrt.html "c/numeric/complex/csqrt")(C99)  
  
Trigonometric functions  
| [ccos](complex/ccos.html "c/numeric/complex/ccos")(C99)  
---  
[csin](complex/csin.html "c/numeric/complex/csin")(C99)  
[ctan](complex/ctan.html "c/numeric/complex/ctan")(C99)  
  
| [cacos](complex/cacos.html "c/numeric/complex/cacos")(C99)  
---  
[casin](complex/casin.html "c/numeric/complex/casin")(C99)  
[catan](complex/catan.html "c/numeric/complex/catan")(C99)  
  
Hyperbolic functions  
| [ccosh](complex/ccosh.html "c/numeric/complex/ccosh")(C99)  
---  
[csinh](complex/csinh.html "c/numeric/complex/csinh")(C99)  
[ctanh](complex/ctanh.html "c/numeric/complex/ctanh")(C99)  
  
| [cacosh](complex/cacosh.html "c/numeric/complex/cacosh")(C99)  
---  
[casinh](complex/casinh.html "c/numeric/complex/casinh")(C99)  
[catanh](complex/catanh.html "c/numeric/complex/catanh")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/navbar_content&action=edit)

If the macro constant `__STDC_NO_COMPLEX__` is defined by the implementation, the complex types, the header [`<complex.h>`](../header/complex.html "c/header/complex") and all of the names listed here are not provided.  | (since C11)  
---|---  
  
The C programming language, as of C99, supports complex number math with the three built-in types double _Complex, float _Complex, and long double _Complex (see [`_Complex`](../keyword/_Complex.html "c/keyword/ Complex")). When the header [`<complex.h>`](../header/complex.html "c/header/complex") is included, the three complex number types are also accessible as double [complex](complex/complex.html), float [complex](complex/complex.html), long double [complex](complex/complex.html). 

In addition to the complex types, the three imaginary types may be supported: double _Imaginary, float _Imaginary, and long double _Imaginary (see [`_Imaginary`](../keyword/_Imaginary.html "c/keyword/ Imaginary")). When the header [`<complex.h>`](../header/complex.html "c/header/complex") is included, the three imaginary types are also accessible as double [imaginary](complex/imaginary.html), float [imaginary](complex/imaginary.html), and long double [imaginary](complex/imaginary.html). 

Standard arithmetic operators +, -, *, / can be used with real, complex, and imaginary types in any combination. 

A compiler that defines `__STDC_IEC_559_COMPLEX__` is recommended, but not required to support imaginary numbers. POSIX recommends checking if the macro [_Imaginary_I](complex/Imaginary_I.html "c/numeric/complex/Imaginary I") is defined to identify imaginary number support.  | (since C99)  
(until C11)  
---|---  
Imaginary numbers are supported if `__STDC_IEC_559_COMPLEX__` or `__STDC_IEC_60559_COMPLEX__`(since C23) is defined.  | (since C11)  
---  
Defined in header `[`<complex.h>`](../header/complex.html "c/header/complex")`  
| 

## Contents

  * [1 Types](complex.html#Types)
  * [2 The imaginary constant](complex.html#The_imaginary_constant)
  * [3 Manipulation](complex.html#Manipulation)
  * [4 Exponential functions](complex.html#Exponential_functions)
  * [5 Power functions](complex.html#Power_functions)
  * [6 Trigonometric functions](complex.html#Trigonometric_functions)
  * [7 Hyperbolic functions](complex.html#Hyperbolic_functions)
  * [8 Notes](complex.html#Notes)
  * [9 Example](complex.html#Example)
  * [10 References](complex.html#References)
  * [11 See also](complex.html#See_also)

  
---  
  
#####  Types   
  
[ imaginary](complex/imaginary.html "c/numeric/complex/imaginary")(C99) |  imaginary type macro   
(keyword macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_imaginary&action=edit)  
[ complex](complex/complex.html "c/numeric/complex/complex")(C99) |  complex type macro   
(keyword macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_complex&action=edit)  
  
#####  The imaginary constant   
  
[ _Imaginary_I](complex/Imaginary_I.html "c/numeric/complex/Imaginary I")(C99) |  the imaginary unit constant i   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_Imaginary_I&action=edit)  
[ _Complex_I](complex/Complex_I.html "c/numeric/complex/Complex I")(C99) |  the complex unit constant i   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_Complex_I&action=edit)  
[ I](complex/I.html "c/numeric/complex/I")(C99) |  the complex or imaginary unit constant i   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_I&action=edit)  
  
#####  Manipulation   
  
[ CMPLXCMPLXFCMPLXL](complex/CMPLX.html "c/numeric/complex/CMPLX")(C11)(C11)(C11) |  constructs a complex number from real and imaginary parts   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_CMPLX&action=edit)  
[ crealcrealfcreall](complex/creal.html "c/numeric/complex/creal")(C99)(C99)(C99) |  computes the real part of a complex number   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_creal&action=edit)  
[ cimagcimagfcimagl](complex/cimag.html "c/numeric/complex/cimag")(C99)(C99)(C99) |  computes the imaginary part a complex number   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cimag&action=edit)  
[ cabscabsfcabsl](complex/cabs.html "c/numeric/complex/cabs")(C99)(C99)(C99) |  computes the magnitude of a complex number   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cabs&action=edit)  
[ cargcargfcargl](complex/carg.html "c/numeric/complex/carg")(C99)(C99)(C99) |  computes the phase angle of a complex number   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_carg&action=edit)  
[ conjconjfconjl](complex/conj.html "c/numeric/complex/conj")(C99)(C99)(C99) |  computes the complex conjugate   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_conj&action=edit)  
[ cprojcprojfcprojl](complex/cproj.html "c/numeric/complex/cproj")(C99)(C99)(C99) |  computes the projection on Riemann sphere   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cproj&action=edit)  
  
#####  Exponential functions   
  
[ cexpcexpfcexpl](complex/cexp.html "c/numeric/complex/cexp")(C99)(C99)(C99) |  computes the complex base-e exponential   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cexp&action=edit)  
[ clogclogfclogl](complex/clog.html "c/numeric/complex/clog")(C99)(C99)(C99) |  computes the complex natural logarithm   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_clog&action=edit)  
  
#####  Power functions   
  
[ cpowcpowfcpowl](complex/cpow.html "c/numeric/complex/cpow")(C99)(C99)(C99) |  computes the complex power function   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cpow&action=edit)  
[ csqrtcsqrtfcsqrtl](complex/csqrt.html "c/numeric/complex/csqrt")(C99)(C99)(C99) |  computes the complex square root   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_csqrt&action=edit)  
  
#####  Trigonometric functions   
  
[ csincsinfcsinl](complex/csin.html "c/numeric/complex/csin")(C99)(C99)(C99) |  computes the complex sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_csin&action=edit)  
[ ccosccosfccosl](complex/ccos.html "c/numeric/complex/ccos")(C99)(C99)(C99) |  computes the complex cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ccos&action=edit)  
[ ctanctanfctanl](complex/ctan.html "c/numeric/complex/ctan")(C99)(C99)(C99) |  computes the complex tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ctan&action=edit)  
[ casincasinfcasinl](complex/casin.html "c/numeric/complex/casin")(C99)(C99)(C99) |  computes the complex arc sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_casin&action=edit)  
[ cacoscacosfcacosl](complex/cacos.html "c/numeric/complex/cacos")(C99)(C99)(C99) |  computes the complex arc cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cacos&action=edit)  
[ catancatanfcatanl](complex/catan.html "c/numeric/complex/catan")(C99)(C99)(C99) |  computes the complex arc tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_catan&action=edit)  
  
#####  Hyperbolic functions   
  
[ csinhcsinhfcsinhl](complex/csinh.html "c/numeric/complex/csinh")(C99)(C99)(C99) |  computes the complex hyperbolic sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_csinh&action=edit)  
[ ccoshccoshfccoshl](complex/ccosh.html "c/numeric/complex/ccosh")(C99)(C99)(C99) |  computes the complex hyperbolic cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ccosh&action=edit)  
[ ctanhctanhfctanhl](complex/ctanh.html "c/numeric/complex/ctanh")(C99)(C99)(C99) |  computes the complex hyperbolic tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ctanh&action=edit)  
[ casinhcasinhfcasinhl](complex/casinh.html "c/numeric/complex/casinh")(C99)(C99)(C99) |  computes the complex arc hyperbolic sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_casinh&action=edit)  
[ cacoshcacoshfcacoshl](complex/cacosh.html "c/numeric/complex/cacosh")(C99)(C99)(C99) |  computes the complex arc hyperbolic cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cacosh&action=edit)  
[ catanhcatanhfcatanhl](complex/catanh.html "c/numeric/complex/catanh")(C99)(C99)(C99) |  computes the complex arc hyperbolic tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_catanh&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex&action=edit&section=1 "Edit section: Notes")] Notes

The following function names are potentially(since C23) reserved for future addition to [`<complex.h>`](../header/complex.html "c/header/complex") and are not available for use in the programs that include that header: cerf, cerfc, cexp2, cexpm1, clog10, clog1p, clog2, clgamma, ctgamma, csinpi, ccospi, ctanpi, casinpi, cacospi, catanpi, ccompoundn, cpown, cpowr, crootn, crsqrt, cexp10m1, cexp10, cexp2m1, clog10p1, clog2p1, clogp1(since C23), along with their -`f` and -`l` suffixed variants. 

Although the C standard names the inverse hyperbolic with "complex arc hyperbolic sine" etc., the inverse functions of the hyperbolic functions are the area functions. Their argument is the area of a hyperbolic sector, not an arc. The correct names are "complex inverse hyperbolic sine" etc. Some authors use "complex area hyperbolic sine" etc. 

A complex or imaginary number is infinite if one of its parts is infinite, even if the other part is NaN. 

A complex or imaginary number is finite if both parts are neither infinities nor NaNs. 

A complex or imaginary number is a zero if both parts are positive or negative zeroes. 

While MSVC does provide a [`<complex.h>`](https://learn.microsoft.com/en-us/cpp/c-runtime-library/complex-math-support) header, it does not implement complex numbers as native types, but as structs, which are incompatible with standard C complex types and do not support the +, -, *, / operators. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <complex.h>
    #include <stdio.h>
    #include <tgmath.h>
     
    int main(void)
    {
        double [complex](complex/complex.html) z1 = I * I;     // imaginary unit squared
        [printf](../io/fprintf.html)("I * I = %.1f%+.1fi\n", [creal](complex/creal.html)(z1), [cimag](complex/cimag.html)(z1));
     
        double [complex](complex/complex.html) z2 = [pow](math/pow.html)(I, 2); // imaginary unit squared
        [printf](../io/fprintf.html)("pow(I, 2) = %.1f%+.1fi\n", [creal](complex/creal.html)(z2), [cimag](complex/cimag.html)(z2));
     
        double PI = [acos](math/acos.html)(-1);
        double [complex](complex/complex.html) z3 = [exp](math/exp.html)(I * PI); // Euler's formula
        [printf](../io/fprintf.html)("exp(I*PI) = %.1f%+.1fi\n", [creal](complex/creal.html)(z3), [cimag](complex/cimag.html)(z3));
     
        double [complex](complex/complex.html) z4 = 1 + 2 * I, z5 = 1 - 2 * I; // conjugates
        [printf](../io/fprintf.html)("(1+2i)*(1-2i) = %.1f%+.1fi\n", [creal](complex/creal.html)(z4 * z5), [cimag](complex/cimag.html)(z4 * z5));
    }

Output: 
    
    
    I * I = -1.0+0.0i
    pow(I, 2) = -1.0+0.0i
    exp(I*PI) = -1.0+0.0i
    (1+2i)*(1-2i) = 5.0+0.0i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex&action=edit&section=3 "Edit section: References")] References

Extended content  
---  
  
  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.10.8.3/1/2 `__STDC_NO_COMPLEX__` (p: TBD) 



    

  * 6.10.8.3/1/2 `__STDC_IEC_559_COMPLEX__` (p: TBD) 



    

  * 7.3 Complex arithmetic `<complex.h>` (p: TBD) 



    

  * 7.25 Type-generic math `<tgmath.h>` (p: TBD) 



    

  * 7.31.1 Complex arithmetic `<complex.h>` (p: TBD) 



    

  * Annex G (normative) IEC 60559-compatible complex arithmetic (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.10.8.3/1/2 `__STDC_NO_COMPLEX__` (p: 128) 



    

  * 6.10.8.3/1/2 `__STDC_IEC_559_COMPLEX__` (p: 128) 



    

  * 7.3 Complex arithmetic `<complex.h>` (p: 136-144) 



    

  * 7.25 Type-generic math `<tgmath.h>` (p: 272-273) 



    

  * 7.31.1 Complex arithmetic `<complex.h>` (p: 391) 



    

  * Annex G (normative) IEC 60559-compatible complex arithmetic (p: 469-479) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.10.8.3/1/2 `__STDC_NO_COMPLEX__` (p: 177) 



    

  * 6.10.8.3/1/2 `__STDC_IEC_559_COMPLEX__` (p: 177) 



    

  * 7.3 Complex arithmetic `<complex.h>` (p: 188-199) 



    

  * 7.25 Type-generic math `<tgmath.h>` (p: 373-375) 



    

  * 7.31.1 Complex arithmetic `<complex.h>` (p: 455) 



    

  * Annex G (normative) IEC 60559-compatible complex arithmetic (p: 532-545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.10.8/2 `__STDC_IEC_559_COMPLEX__` (p: 161) 



    

  * 7.3 Complex arithmetic `<complex.h>` (p: 170-180) 



    

  * 7.22 Type-generic math `<tgmath.h>` (p: 335-337) 



    

  * 7.26.1 Complex arithmetic `<complex.h>` (p: 401) 



    

  * Annex G (informative) IEC 60559-compatible complex arithmetic (p: 467-480) 

  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../cpp/numeric/complex.html "cpp/numeric/complex") for Complex number arithmetic  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex&oldid=180042](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex&oldid=180042)" 

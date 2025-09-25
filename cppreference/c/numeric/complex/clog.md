From cppreference.com

< [c](../../../c.html "c")‎ | [numeric](../../numeric.html "c/numeric")‎ | [complex](../complex.html "c/numeric/complex")

[ C](../../../c.html "c")

[Compiler support](../../compiler_support.html "c/compiler support")  
---  
[Language](../../language.html "c/language")  
[Headers](../../header.html "c/header")  
[Type support](../../types.html "c/types")  
[Program utilities](../../program.html "c/program")  
[Variadic function support](../../variadic.html "c/variadic")  
[Error handling](../../error.html "c/error")  
[Dynamic memory management](../../memory.html "c/memory")  
[Strings library](../../string.html "c/string")  
[Algorithms](../../algorithm.html "c/algorithm")  
[Numerics](../../numeric.html "c/numeric")  
[Date and time utilities](../../chrono.html "c/chrono")  
[Input/output support](../../io.html "c/io")  
[Localization support](../../locale.html "c/locale")  
[Concurrency support](../../thread.html "c/thread") (C11)  
[Technical Specifications](../../experimental.html "c/experimental")  
[Symbol index](../../index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

[ Numerics](../../numeric.html "c/numeric")

[Common mathematical functions](../math.html "c/numeric/math")  
---  
[Floating-point environment](../fenv.html "c/numeric/fenv") (C99)  
[Pseudo-random number generation](../random.html "c/numeric/random")  
[Complex number arithmetic](../complex.html "c/numeric/complex") (C99)  
[Type-generic math](../tgmath.html "c/numeric/tgmath") (C99)  
[Bit manipulation](../../numeric.html#Bit_manipulation "c/numeric") (C23)  
[Checked integer arithmetic](../../numeric.html#Checked_integer_arithmetic "c/numeric") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/navbar_content&action=edit)

[ Complex number arithmetic](../complex.html "c/numeric/complex")

Types and the imaginary constant  
---  
| [complex](complex.html "c/numeric/complex/complex")(C99)  
---  
[_Complex_I](Complex_I.html "c/numeric/complex/Complex I")(C99)  
[CMPLX](CMPLX.html "c/numeric/complex/CMPLX")(C11)  
  
| [imaginary](imaginary.html "c/numeric/complex/imaginary")(C99)  
---  
[_Imaginary_I](Imaginary_I.html "c/numeric/complex/Imaginary I")(C99)  
[I](I.html "c/numeric/complex/I")(C99)  
  
Manipulation  
| [cimag](cimag.html "c/numeric/complex/cimag")(C99)  
---  
[creal](creal.html "c/numeric/complex/creal")(C99)  
[carg](carg.html "c/numeric/complex/carg")(C99)  
  
| [cabs](cabs.html "c/numeric/complex/cabs")(C99)  
---  
[conj](conj.html "c/numeric/complex/conj")(C99)  
[cproj](cproj.html "c/numeric/complex/cproj")(C99)  
  
Power and exponential functions  
| [cexp](cexp.html "c/numeric/complex/cexp")(C99)  
---  
**clog**(C99)  
  
| [cpow](cpow.html "c/numeric/complex/cpow")(C99)  
---  
[csqrt](csqrt.html "c/numeric/complex/csqrt")(C99)  
  
Trigonometric functions  
| [ccos](ccos.html "c/numeric/complex/ccos")(C99)  
---  
[csin](csin.html "c/numeric/complex/csin")(C99)  
[ctan](ctan.html "c/numeric/complex/ctan")(C99)  
  
| [cacos](cacos.html "c/numeric/complex/cacos")(C99)  
---  
[casin](casin.html "c/numeric/complex/casin")(C99)  
[catan](catan.html "c/numeric/complex/catan")(C99)  
  
Hyperbolic functions  
| [ccosh](ccosh.html "c/numeric/complex/ccosh")(C99)  
---  
[csinh](csinh.html "c/numeric/complex/csinh")(C99)  
[ctanh](ctanh.html "c/numeric/complex/ctanh")(C99)  
  
| [cacosh](cacosh.html "c/numeric/complex/cacosh")(C99)  
---  
[casinh](casinh.html "c/numeric/complex/casinh")(C99)  
[catanh](catanh.html "c/numeric/complex/catanh")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/navbar_content&action=edit)

Defined in header `[`<complex.h>`](../../header/complex.html "c/header/complex")` |  |   
---|---|---  
float [complex](complex.html) clogf( float [complex](complex.html) z ); |  (1)  |  (since C99)  
double [complex](complex.html) clog( double [complex](complex.html) z ); |  (2)  |  (since C99)  
long double [complex](complex.html) clogl( long double [complex](complex.html) z ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define log( z ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes the complex natural (base-_e_) logarithm of `z` with branch cut along the negative real axis.

4) Type-generic macro: If `z` has type long double [complex](complex.html), `clogl` is called. if `z` has type double [complex](complex.html), `clog` is called, if `z` has type float [complex](complex.html), `clogf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (logf, [log](../math/log.html), logl). If `z` is imaginary, the corresponding complex number version is called.

## Contents

  * [1 Parameters](clog.html#Parameters)
  * [2 Return value](clog.html#Return_value)
  * [3 Error handling and special values](clog.html#Error_handling_and_special_values)
  * [4 Notes](clog.html#Notes)
  * [5 Example](clog.html#Example)
  * [6 References](clog.html#References)
  * [7 See also](clog.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/clog&action=edit&section=1 "Edit section: Parameters")] Parameters

z  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/clog&action=edit&section=2 "Edit section: Return value")] Return value

If no errors occur, the complex natural logarithm of `z` is returned, in the range of a strip in the interval [−iπ, +iπ] along the imaginary axis and mathematically unbounded along the real axis. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/clog&action=edit&section=3 "Edit section: Error handling and special values")] Error handling and special values

Errors are reported consistent with [math_errhandling](../math/math_errhandling.html "c/numeric/math/math errhandling")

If the implementation supports IEEE floating-point arithmetic, 

  * The function is continuous onto the branch cut taking into account the sign of imaginary part 
  * clog([conj](conj.html)(z)) == [conj](conj.html)(clog(z))
  * If `z` is `-0+0i`, the result is `-∞+πi` and [FE_DIVBYZERO](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised 
  * If `z` is `+0+0i`, the result is `-∞+0i` and [FE_DIVBYZERO](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised 
  * If `z` is `x+∞i` (for any finite x), the result is `+∞+πi/2`
  * If `z` is `x+NaNi` (for any finite x), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised 
  * If `z` is `-∞+yi` (for any finite positive y), the result is `+∞+πi`
  * If `z` is `+∞+yi` (for any finite positive y), the result is `+∞+0i`
  * If `z` is `-∞+∞i`, the result is `+∞+3πi/4`
  * If `z` is `+∞+∞i`, the result is `+∞+πi/4`
  * If `z` is `±∞+NaNi`, the result is `+∞+NaNi`
  * If `z` is `NaN+yi` (for any finite y), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised 
  * If `z` is `NaN+∞i`, the result is `+∞+NaNi`
  * If `z` is `NaN+NaNi`, the result is `NaN+NaNi`



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/clog&action=edit&section=4 "Edit section: Notes")] Notes

The natural logarithm of a complex number z with polar coordinate components (r,θ) equals ln r + i(θ+2nπ), with the principal value ln r + iθ

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/clog&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <math.h>
    #include <complex.h>
     
    int main(void)
    {
        double [complex](complex.html) z = clog(I); // r = 1, θ = pi/2
        [printf](../../io/fprintf.html)("2*log(i) = %.1f%+fi\n", [creal](creal.html)(2*z), [cimag](cimag.html)(2*z));
     
        double [complex](complex.html) z2 = clog([sqrt](../math/sqrt.html)(2)/2 + [sqrt](../math/sqrt.html)(2)/2*I); // r = 1, θ = pi/4
        [printf](../../io/fprintf.html)("4*log(sqrt(2)/2+sqrt(2)i/2) = %.1f%+fi\n", [creal](creal.html)(4*z2), [cimag](cimag.html)(4*z2));
     
        double [complex](complex.html) z3 = clog(-1); // r = 1, θ = pi
        [printf](../../io/fprintf.html)("log(-1+0i) = %.1f%+fi\n", [creal](creal.html)(z3), [cimag](cimag.html)(z3));
     
        double [complex](complex.html) z4 = clog([conj](conj.html)(-1)); // or clog(CMPLX(-1, -0.0)) in C11
        [printf](../../io/fprintf.html)("log(-1-0i) (the other side of the cut) = %.1f%+fi\n", [creal](creal.html)(z4), [cimag](cimag.html)(z4));
    }

Output: 
    
    
    2*log(i) = 0.0+3.141593i
    4*log(sqrt(2)/2+sqrt(2)i/2) = 0.0+3.141593i
    log(-1+0i) = 0.0+3.141593i
    log(-1-0i) (the other side of the cut) = 0.0-3.141593i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/clog&action=edit&section=6 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.7.2 The clog functions (p: 195) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



    

  * G.6.3.2 The clog functions (p: 543-544) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.7.2 The clog functions (p: 176-177) 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



    

  * G.6.3.2 The clog functions (p: 478-479) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/clog&action=edit&section=7 "Edit section: See also")] See also

[ cexpcexpfcexpl](cexp.html "c/numeric/complex/cexp")(C99)(C99)(C99) |  computes the complex base-e exponential   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cexp&action=edit)  
---|---  
[ loglogflogl](../math/log.html "c/numeric/math/log")(C99)(C99) |  computes natural (base-_e_) logarithm (\\({\small \ln{x} }\\)ln(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_log&action=edit)  
[C++ documentation](../../../cpp/numeric/complex/log.html "cpp/numeric/complex/log") for log  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/clog&oldid=96195](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/clog&oldid=96195)" 

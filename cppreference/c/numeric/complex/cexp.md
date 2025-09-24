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
| **cexp**(C99)  
---  
[clog](clog.html "c/numeric/complex/clog")(C99)  
  
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
float [complex](complex.html) cexpf( float [complex](complex.html) z ); |  (1)  |  (since C99)  
double [complex](complex.html) cexp( double [complex](complex.html) z ); |  (2)  |  (since C99)  
long double [complex](complex.html) cexpl( long double [complex](complex.html) z ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define exp( z ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes the complex base-_e_ exponential of `z`.

4) Type-generic macro: If `z` has type long double [complex](complex.html), `cexpl` is called. if `z` has type double [complex](complex.html), `cexp` is called, if `z` has type float [complex](complex.html), `cexpf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (expf, [exp](../math/exp.html), expl). If `z` is imaginary, the corresponding complex argument version is called.

## Contents

  * [1 Parameters](cexp.html#Parameters)
  * [2 Return value](cexp.html#Return_value)
  * [3 Error handling and special values](cexp.html#Error_handling_and_special_values)
  * [4 Notes](cexp.html#Notes)
  * [5 Example](cexp.html#Example)
  * [6 References](cexp.html#References)
  * [7 See also](cexp.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cexp&action=edit&section=1 "Edit section: Parameters")] Parameters

z  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cexp&action=edit&section=2 "Edit section: Return value")] Return value

If no errors occur, _e_ raised to the power of `z`, \\(\small e^z\\)ez  
is returned. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cexp&action=edit&section=3 "Edit section: Error handling and special values")] Error handling and special values

Errors are reported consistent with [`math_errhandling`](../math/math_errhandling.html "c/numeric/math/math errhandling"). 

If the implementation supports IEEE floating-point arithmetic, 

  * cexp([conj](conj.html)(z)) == [conj](conj.html)(cexp(z))
  * If `z` is `±0+0i`, the result is `1+0i`
  * If `z` is `x+∞i` (for any finite x), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised. 
  * If `z` is `x+NaNi` (for any finite x), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised. 
  * If `z` is `+∞+0i`, the result is `+∞+0i`
  * If `z` is `-∞+yi` (for any finite y), the result is `+0cis(y)`
  * If `z` is `+∞+yi` (for any finite nonzero y), the result is `+∞cis(y)`
  * If `z` is `-∞+∞i`, the result is `±0±0i` (signs are unspecified) 
  * If `z` is `+∞+∞i`, the result is `±∞+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised (the sign of the real part is unspecified) 
  * If `z` is `-∞+NaNi`, the result is `±0±0i` (signs are unspecified) 
  * If `z` is `+∞+NaNi`, the result is `±∞+NaNi` (the sign of the real part is unspecified) 
  * If `z` is `NaN+0i`, the result is `NaN+0i`
  * If `z` is `NaN+yi` (for any nonzero y), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised 
  * If `z` is `NaN+NaNi`, the result is `NaN+NaNi`



where \\(\small{\rm cis}(y)\\)cis(y) is \\(\small \cos(y)+{\rm i}\sin(y)\\)cos(y) + i sin(y)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cexp&action=edit&section=4 "Edit section: Notes")] Notes

The complex exponential function \\(\small e^z\\)ez  
for \\(\small z = x + {\rm i}y\\)z = x+iy equals \\(\small e^x {\rm cis}(y)\\)ex  
cis(y), or, \\(\small e^x (\cos(y)+{\rm i}\sin(y))\\)ex  
(cos(y) + i sin(y))

The exponential function is an _entire function_ in the complex plane and has no branch cuts. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cexp&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <math.h>
    #include <complex.h>
     
    int main(void)
    {
        double PI = [acos](../math/acos.html)(-1);
        double [complex](complex.html) z = cexp(I * PI); // Euler's formula
        [printf](../../io/fprintf.html)("exp(i*pi) = %.1f%+.1fi\n", [creal](creal.html)(z), [cimag](cimag.html)(z));
     
    }

Output: 
    
    
    exp(i*pi) = -1.0+0.0i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cexp&action=edit&section=6 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.7.1 The cexp functions (p: 194) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



    

  * G.6.3.1 The cexp functions (p: 543) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.7.1 The cexp functions (p: 176) 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



    

  * G.6.3.1 The cexp functions (p: 478) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cexp&action=edit&section=7 "Edit section: See also")] See also

[ clogclogfclogl](clog.html "c/numeric/complex/clog")(C99)(C99)(C99) |  computes the complex natural logarithm   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_clog&action=edit)  
---|---  
[ expexpfexpl](../math/exp.html "c/numeric/math/exp")(C99)(C99) |  computes _e_ raised to the given power (\\({\small e^x}\\)ex)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_exp&action=edit)  
[C++ documentation](../../../cpp/numeric/complex/exp.html "cpp/numeric/complex/exp") for exp  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cexp&oldid=147325](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cexp&oldid=147325)" 

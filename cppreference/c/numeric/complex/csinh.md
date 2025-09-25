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
**csinh**(C99)  
[ctanh](ctanh.html "c/numeric/complex/ctanh")(C99)  
  
| [cacosh](cacosh.html "c/numeric/complex/cacosh")(C99)  
---  
[casinh](casinh.html "c/numeric/complex/casinh")(C99)  
[catanh](catanh.html "c/numeric/complex/catanh")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/navbar_content&action=edit)

Defined in header `[`<complex.h>`](../../header/complex.html "c/header/complex")` |  |   
---|---|---  
float [complex](complex.html) csinhf( float [complex](complex.html) z ); |  (1)  |  (since C99)  
double [complex](complex.html) csinh( double [complex](complex.html) z ); |  (2)  |  (since C99)  
long double [complex](complex.html) csinhl( long double [complex](complex.html) z ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define sinh( z ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes the complex hyperbolic sine of `z`.

4) Type-generic macro: If `z` has type long double [complex](complex.html), `csinhl` is called. if `z` has type double [complex](complex.html), `csinh` is called, if `z` has type float [complex](complex.html), `csinhf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (sinhf, [sinh](../math/sinh.html), sinhl). If `z` is imaginary, then the macro invokes the corresponding real version of the function [sin](../math/sin.html "c/numeric/math/sin"), implementing the formula sinh(iy) = i sin(y), and the return type is imaginary.

## Contents

  * [1 Parameters](csinh.html#Parameters)
  * [2 Return value](csinh.html#Return_value)
  * [3 Error handling and special values](csinh.html#Error_handling_and_special_values)
  * [4 Notes](csinh.html#Notes)
  * [5 Example](csinh.html#Example)
  * [6 References](csinh.html#References)
  * [7 See also](csinh.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csinh&action=edit&section=1 "Edit section: Parameters")] Parameters

z  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csinh&action=edit&section=2 "Edit section: Return value")] Return value

If no errors occur, complex hyperbolic sine of `z` is returned 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csinh&action=edit&section=3 "Edit section: Error handling and special values")] Error handling and special values

Errors are reported consistent with [math_errhandling](../math/math_errhandling.html "c/numeric/math/math errhandling")

If the implementation supports IEEE floating-point arithmetic, 

  * csinh([conj](conj.html)(z)) == [conj](conj.html)(csinh(z))
  * csinh(z) == -csinh(-z)
  * If `z` is `+0+0i`, the result is `+0+0i`
  * If `z` is `+0+∞i`, the result is `±0+NaNi` (the sign of the real part is unspecified) and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised 
  * If `z` is `+0+NaNi`, the result is `±0+NaNi`
  * If `z` is `x+∞i` (for any positive finite x), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised 
  * If `z` is `x+NaNi` (for any positive finite x), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised 
  * If `z` is `+∞+0i`, the result is `+∞+0i`
  * If `z` is `+∞+yi` (for any positive finite y), the result is `+∞cis(y)`
  * If `z` is `+∞+∞i`, the result is `±∞+NaNi` (the sign of the real part is unspecified) and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised 
  * If `z` is `+∞+NaNi`, the result is `±∞+NaNi` (the sign of the real part is unspecified) 
  * If `z` is `NaN+0i`, the result is `NaN+0i`
  * If `z` is `NaN+yi` (for any finite nonzero y), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised 
  * If `z` is `NaN+NaNi`, the result is `NaN+NaNi`



where cis(y) is cos(y) + i sin(y)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csinh&action=edit&section=4 "Edit section: Notes")] Notes

Mathematical definition of hyperbolic sine is sinh z = ez  
-e-z  
  
---  
2  
  
Hyperbolic sine is an entire function in the complex plane and has no branch cuts. It is periodic with respect to the imaginary component, with period 2πi 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csinh&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <math.h>
    #include <complex.h>
     
    int main(void)
    {
        double [complex](complex.html) z = csinh(1);  // behaves like real sinh along the real line
        [printf](../../io/fprintf.html)("sinh(1+0i) = %f%+fi (sinh(1)=%f)\n", [creal](creal.html)(z), [cimag](cimag.html)(z), [sinh](../math/sinh.html)(1));
     
        double [complex](complex.html) z2 = csinh(I); // behaves like sine along the imaginary line
        [printf](../../io/fprintf.html)("sinh(0+1i) = %f%+fi ( sin(1)=%f)\n", [creal](creal.html)(z2), [cimag](cimag.html)(z2), [sin](../math/sin.html)(1));
    }

Output: 
    
    
    sinh(1+0i) = 1.175201+0.000000i (sinh(1)=1.175201)
    sinh(0+1i) = 0.000000+0.841471i ( sin(1)=0.841471)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csinh&action=edit&section=6 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.6.5 The csinh functions (p: 194) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



    

  * G.6.2.5 The csinh functions (p: 541-542) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.6.5 The csinh functions (p: 175-176) 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



    

  * G.6.2.5 The csinh functions (p: 476-477) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csinh&action=edit&section=7 "Edit section: See also")] See also

[ ccoshccoshfccoshl](ccosh.html "c/numeric/complex/ccosh")(C99)(C99)(C99) |  computes the complex hyperbolic cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ccosh&action=edit)  
---|---  
[ ctanhctanhfctanhl](ctanh.html "c/numeric/complex/ctanh")(C99)(C99)(C99) |  computes the complex hyperbolic tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ctanh&action=edit)  
[ casinhcasinhfcasinhl](casinh.html "c/numeric/complex/casinh")(C99)(C99)(C99) |  computes the complex arc hyperbolic sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_casinh&action=edit)  
[ sinhsinhfsinhl](../math/sinh.html "c/numeric/math/sinh")(C99)(C99) |  computes hyperbolic sine (\\({\small\sinh{x} }\\)sinh(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_sinh&action=edit)  
[C++ documentation](../../../cpp/numeric/complex/sinh.html "cpp/numeric/complex/sinh") for sinh  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csinh&oldid=96389](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csinh&oldid=96389)" 

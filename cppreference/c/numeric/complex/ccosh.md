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
| **ccosh**(C99)  
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
float [complex](complex.html) ccoshf( float [complex](complex.html) z ); |  (1)  |  (since C99)  
double [complex](complex.html) ccosh( double [complex](complex.html) z ); |  (2)  |  (since C99)  
long double [complex](complex.html) ccoshl( long double [complex](complex.html) z ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define cosh( z ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes the complex hyperbolic cosine of `z`.

4) Type-generic macro: If `z` has type long double [complex](complex.html), `ccoshl` is called. if `z` has type double [complex](complex.html), `ccosh` is called, if `z` has type float [complex](complex.html), `ccoshf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (coshf, [cosh](../math/cosh.html), coshl). If `z` is imaginary, then the macro invokes the corresponding real version of the function [cos](../math/cos.html "c/numeric/math/cos"), implementing the formula cosh(iy) = cos(y), and the return type is real.

## Contents

  * [1 Parameters](ccosh.html#Parameters)
  * [2 Return value](ccosh.html#Return_value)
  * [3 Error handling and special values](ccosh.html#Error_handling_and_special_values)
  * [4 Notes](ccosh.html#Notes)
  * [5 Example](ccosh.html#Example)
  * [6 References](ccosh.html#References)
  * [7 See also](ccosh.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ccosh&action=edit&section=1 "Edit section: Parameters")] Parameters

z  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ccosh&action=edit&section=2 "Edit section: Return value")] Return value

If no errors occur, complex hyperbolic cosine of `z` is returned 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ccosh&action=edit&section=3 "Edit section: Error handling and special values")] Error handling and special values

Errors are reported consistent with [math_errhandling](../math/math_errhandling.html "c/numeric/math/math errhandling")

If the implementation supports IEEE floating-point arithmetic, 

  * ccosh([conj](conj.html)(z)) == [conj](conj.html)(ccosh(z))
  * ccosh(z) == ccosh(-z)
  * If `z` is `+0+0i`, the result is `1+0i`
  * If `z` is `+0+∞i`, the result is `NaN±0i` (the sign of the imaginary part is unspecified) and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised 
  * If `z` is `+0+NaNi`, the result is `NaN±0i` (the sign of the imaginary part is unspecified) 
  * If `z` is `x+∞i` (for any finite non-zero x), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised 
  * If `z` is `x+NaNi` (for any finite non-zero x), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised 
  * If `z` is `+∞+0i`, the result is `+∞+0i`
  * If `z` is `+∞+yi` (for any finite non-zero y), the result is `+∞cis(y)`
  * If `z` is `+∞+∞i`, the result is `±∞+NaNi` (the sign of the real part is unspecified) and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised 
  * If `z` is `+∞+NaN`, the result is `+∞+NaN`
  * If `z` is `NaN+0i`, the result is `NaN±0i` (the sign of the imaginary part is unspecified) 
  * If `z` is `NaN+yi` (for any finite non-zero y), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised 
  * If `z` is `NaN+NaNi`, the result is `NaN+NaNi`



where cis(y) is cos(y) + i sin(y)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ccosh&action=edit&section=4 "Edit section: Notes")] Notes

Mathematical definition of hyperbolic cosine is cosh z = ez  
+e-z  
  
---  
2  
  
Hyperbolic cosine is an entire function in the complex plane and has no branch cuts. It is periodic with respect to the imaginary component, with period 2πi 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ccosh&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <math.h>
    #include <complex.h>
     
    int main(void)
    {
        double [complex](complex.html) z = ccosh(1);  // behaves like real cosh along the real line
        [printf](../../io/fprintf.html)("cosh(1+0i) = %f%+fi (cosh(1)=%f)\n", [creal](creal.html)(z), [cimag](cimag.html)(z), [cosh](../math/cosh.html)(1));
     
        double [complex](complex.html) z2 = ccosh(I); // behaves like real cosine along the imaginary line
        [printf](../../io/fprintf.html)("cosh(0+1i) = %f%+fi ( cos(1)=%f)\n", [creal](creal.html)(z2), [cimag](cimag.html)(z2), [cos](../math/cos.html)(1));
    }

Output: 
    
    
    cosh(1+0i) = 1.543081+0.000000i (cosh(1)=1.543081)
    cosh(0+1i) = 0.540302+0.000000i ( cos(1)=0.540302)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ccosh&action=edit&section=6 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.6.4 The ccosh functions (p: 193) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



    

  * G.6.2.4 The ccosh functions (p: 541) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.6.4 The ccosh functions (p: 175) 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



    

  * G.6.2.4 The ccosh functions (p: 476) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ccosh&action=edit&section=7 "Edit section: See also")] See also

[ csinhcsinhfcsinhl](csinh.html "c/numeric/complex/csinh")(C99)(C99)(C99) |  computes the complex hyperbolic sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_csinh&action=edit)  
---|---  
[ ctanhctanhfctanhl](ctanh.html "c/numeric/complex/ctanh")(C99)(C99)(C99) |  computes the complex hyperbolic tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ctanh&action=edit)  
[ cacoshcacoshfcacoshl](cacosh.html "c/numeric/complex/cacosh")(C99)(C99)(C99) |  computes the complex arc hyperbolic cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cacosh&action=edit)  
[ coshcoshfcoshl](../math/cosh.html "c/numeric/math/cosh")(C99)(C99) |  computes hyperbolic cosine (\\({\small\cosh{x} }\\)cosh(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_cosh&action=edit)  
[C++ documentation](../../../cpp/numeric/complex/cosh.html "cpp/numeric/complex/cosh") for cosh  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ccosh&oldid=96399](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ccosh&oldid=96399)" 

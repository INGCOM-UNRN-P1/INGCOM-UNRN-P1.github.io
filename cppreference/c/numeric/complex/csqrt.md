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
**csqrt**(C99)  
  
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
float [complex](complex.html) csqrtf( float [complex](complex.html) z ); |  (1)  |  (since C99)  
double [complex](complex.html) csqrt( double [complex](complex.html) z ); |  (2)  |  (since C99)  
long double [complex](complex.html) csqrtl( long double [complex](complex.html) z ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define sqrt( z ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes the complex square root of `z` with branch cut along the negative real axis.

4) Type-generic macro: If `z` has type long double [complex](complex.html), `csqrtl` is called. if `z` has type double [complex](complex.html), `csqrt` is called, if `z` has type float [complex](complex.html), `csqrtf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (sqrtf, [sqrt](../math/sqrt.html), sqrtl). If `z` is imaginary, the corresponding complex number version is called.

## Contents

  * [1 Parameters](csqrt.html#Parameters)
  * [2 Return value](csqrt.html#Return_value)
  * [3 Error handling and special values](csqrt.html#Error_handling_and_special_values)
  * [4 Example](csqrt.html#Example)
  * [5 References](csqrt.html#References)
  * [6 See also](csqrt.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csqrt&action=edit&section=1 "Edit section: Parameters")] Parameters

z  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csqrt&action=edit&section=2 "Edit section: Return value")] Return value

If no errors occur, returns the square root of `z`, in the range of the right half-plane, including the imaginary axis ([0; +∞) along the real axis and (−∞; +∞) along the imaginary axis.) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csqrt&action=edit&section=3 "Edit section: Error handling and special values")] Error handling and special values

Errors are reported consistent with [math_errhandling](../math/math_errhandling.html "c/numeric/math/math errhandling")

If the implementation supports IEEE floating-point arithmetic, 

  * The function is continuous onto the branch cut taking into account the sign of imaginary part 
  * csqrt([conj](conj.html)(z)) == [conj](conj.html)(csqrt(z))
  * If `z` is `±0+0i`, the result is `+0+0i`
  * If `z` is `x+∞i`, the result is `+∞+∞i` even if x is NaN 
  * If `z` is `x+NaNi`, the result is `NaN+NaNi` (unless x is ±∞) and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised 
  * If `z` is `-∞+yi`, the result is `+0+∞i` for finite positive y 
  * If `z` is `+∞+yi`, the result is `+∞+0i)` for finite positive y 
  * If `z` is `-∞+NaNi`, the result is `NaN±∞i` (sign of imaginary part unspecified) 
  * If `z` is `+∞+NaNi`, the result is `+∞+NaNi`
  * If `z` is `NaN+yi`, the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised 
  * If `z` is `NaN+NaNi`, the result is `NaN+NaNi`



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csqrt&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <complex.h>
     
    int main(void)
    {
        double [complex](complex.html) z1 = csqrt(-4);
        [printf](../../io/fprintf.html)("Square root of -4 is %.1f%+.1fi\n", [creal](creal.html)(z1), [cimag](cimag.html)(z1));
     
        double [complex](complex.html) z2 = csqrt([conj](conj.html)(-4)); // or, in C11, CMPLX(-4, -0.0)
        [printf](../../io/fprintf.html)("Square root of -4-0i, the other side of the cut, is "
               "%.1f%+.1fi\n", [creal](creal.html)(z2), [cimag](cimag.html)(z2));
    }

Output: 
    
    
    Square root of -4 is 0.0+2.0i
    Square root of -4-0i, the other side of the cut, is 0.0-2.0i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csqrt&action=edit&section=5 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.8.3 The csqrt functions (p: 196) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



    

  * G.6.4.2 The csqrt functions (p: 544) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.8.3 The csqrt functions (p: 178) 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



    

  * G.6.4.2 The csqrt functions (p: 479) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csqrt&action=edit&section=6 "Edit section: See also")] See also

[ cpowcpowfcpowl](cpow.html "c/numeric/complex/cpow")(C99)(C99)(C99) |  computes the complex power function   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cpow&action=edit)  
---|---  
[ sqrtsqrtfsqrtl](../math/sqrt.html "c/numeric/math/sqrt")(C99)(C99) |  computes square root (\\(\small{\sqrt{x} }\\)√x)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_sqrt&action=edit)  
[C++ documentation](../../../cpp/numeric/complex/sqrt.html "cpp/numeric/complex/sqrt") for sqrt  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csqrt&oldid=96381](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csqrt&oldid=96381)" 

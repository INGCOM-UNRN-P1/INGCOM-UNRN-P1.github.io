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
[csinh](csinh.html "c/numeric/complex/csinh")(C99)  
[ctanh](ctanh.html "c/numeric/complex/ctanh")(C99)  
  
| **cacosh**(C99)  
---  
[casinh](casinh.html "c/numeric/complex/casinh")(C99)  
[catanh](catanh.html "c/numeric/complex/catanh")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/navbar_content&action=edit)

Defined in header `[`<complex.h>`](../../header/complex.html "c/header/complex")` |  |   
---|---|---  
float [complex](complex.html) cacoshf( float [complex](complex.html) z ); |  (1)  |  (since C99)  
double [complex](complex.html) cacosh( double [complex](complex.html) z ); |  (2)  |  (since C99)  
long double [complex](complex.html) cacoshl( long double [complex](complex.html) z ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define acosh( z ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes complex arc hyperbolic cosine of a complex value `z` with branch cut at values less than 1 along the real axis.

4) Type-generic macro: If `z` has type long double [complex](complex.html), `cacoshl` is called. if `z` has type double [complex](complex.html), `cacosh` is called, if `z` has type float [complex](complex.html), `cacoshf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (acoshf, [acosh](../math/acosh.html), acoshl). If `z` is imaginary, then the macro invokes the corresponding complex number version and the return type is complex.

## Contents

  * [1 Parameters](cacosh.html#Parameters)
  * [2 Return value](cacosh.html#Return_value)
  * [3 Error handling and special values](cacosh.html#Error_handling_and_special_values)
  * [4 Notes](cacosh.html#Notes)
  * [5 Example](cacosh.html#Example)
  * [6 References](cacosh.html#References)
  * [7 See also](cacosh.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacosh&action=edit&section=1 "Edit section: Parameters")] Parameters

z  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacosh&action=edit&section=2 "Edit section: Return value")] Return value

The complex arc hyperbolic cosine of `z` in the interval [0; ∞) along the real axis and in the interval [−iπ; +iπ] along the imaginary axis. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacosh&action=edit&section=3 "Edit section: Error handling and special values")] Error handling and special values

Errors are reported consistent with [math_errhandling](../math/math_errhandling.html "c/numeric/math/math errhandling")

If the implementation supports IEEE floating-point arithmetic, 

  * cacosh([conj](conj.html)(z)) == [conj](conj.html)(cacosh(z))
  * If `z` is `±0+0i`, the result is `+0+iπ/2`
  * If `z` is `+x+∞i` (for any finite x), the result is `+∞+iπ/2`
  * If `z` is `+x+NaNi` (for non-zero finite x), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised. 
  * If `z` is `0+NaNi`, the result is `NaN±iπ/2`, where the sign of the imaginary part is unspecified 
  * If `z` is `-∞+yi` (for any positive finite y), the result is `+∞+iπ`
  * If `z` is `+∞+yi` (for any positive finite y), the result is `+∞+0i`
  * If `z` is `-∞+∞i`, the result is `+∞+3iπ/4`
  * If `z` is `+∞+∞i`, the result is `+∞+iπ/4`
  * If `z` is `±∞+NaNi`, the result is `+∞+NaNi`
  * If `z` is `NaN+yi` (for any finite y), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised. 
  * If `z` is `NaN+∞i`, the result is `+∞+NaNi`
  * If `z` is `NaN+NaNi`, the result is `NaN+NaNi`



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacosh&action=edit&section=4 "Edit section: Notes")] Notes

Although the C standard names this function "complex arc hyperbolic cosine", the inverse functions of the hyperbolic functions are the area functions. Their argument is the area of a hyperbolic sector, not an arc. The correct name is "complex inverse hyperbolic cosine", and, less common, "complex area hyperbolic cosine". 

Inverse hyperbolic cosine is a multivalued function and requires a branch cut on the complex plane. The branch cut is conventionally placed at the line segment (-∞,+1) of the real axis. 

The mathematical definition of the principal value of the inverse hyperbolic cosine is acosh z = ln(z + √z+1 √z-1)

For any z, acosh(z) = √z-1  
---  
√1-z  
acos(z), or simply i acos(z) in the upper half of the complex plane. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacosh&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <complex.h>
     
    int main(void)
    {
        double [complex](complex.html) z = cacosh(0.5);
        [printf](../../io/fprintf.html)("cacosh(+0.5+0i) = %f%+fi\n", [creal](creal.html)(z), [cimag](cimag.html)(z));
     
        double [complex](complex.html) z2 = [conj](conj.html)(0.5); // or cacosh(CMPLX(0.5, -0.0)) in C11
        [printf](../../io/fprintf.html)("cacosh(+0.5-0i) (the other side of the cut) = %f%+fi\n", [creal](creal.html)(z2), [cimag](cimag.html)(z2));
     
        // in upper half-plane, acosh(z) = i*acos(z) 
        double [complex](complex.html) z3 = [casinh](casinh.html)(1+I);
        [printf](../../io/fprintf.html)("casinh(1+1i) = %f%+fi\n", [creal](creal.html)(z3), [cimag](cimag.html)(z3));
        double [complex](complex.html) z4 = I*[casin](casin.html)(1+I);
        [printf](../../io/fprintf.html)("I*asin(1+1i) = %f%+fi\n", [creal](creal.html)(z4), [cimag](cimag.html)(z4));
    }

Output: 
    
    
    cacosh(+0.5+0i) = 0.000000-1.047198i
    cacosh(+0.5-0i) (the other side of the cut) = 0.500000-0.000000i
    casinh(1+1i) = 1.061275+0.666239i
    I*asin(1+1i) = -1.061275+0.666239i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacosh&action=edit&section=6 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.6.1 The cacosh functions (p: 192) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



    

  * G.6.2.1 The cacosh functions (p: 539-540) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.6.1 The cacosh functions (p: 174) 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



    

  * G.6.2.1 The cacosh functions (p: 474-475) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacosh&action=edit&section=7 "Edit section: See also")] See also

[ cacoscacosfcacosl](cacos.html "c/numeric/complex/cacos")(C99)(C99)(C99) |  computes the complex arc cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cacos&action=edit)  
---|---  
[ casinhcasinhfcasinhl](casinh.html "c/numeric/complex/casinh")(C99)(C99)(C99) |  computes the complex arc hyperbolic sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_casinh&action=edit)  
[ catanhcatanhfcatanhl](catanh.html "c/numeric/complex/catanh")(C99)(C99)(C99) |  computes the complex arc hyperbolic tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_catanh&action=edit)  
[ ccoshccoshfccoshl](ccosh.html "c/numeric/complex/ccosh")(C99)(C99)(C99) |  computes the complex hyperbolic cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ccosh&action=edit)  
[ acoshacoshfacoshl](../math/acosh.html "c/numeric/math/acosh")(C99)(C99)(C99) |  computes inverse hyperbolic cosine (\\({\small\operatorname{arcosh}{x} }\\)arcosh(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_acosh&action=edit)  
[C++ documentation](../../../cpp/numeric/complex/acosh.html "cpp/numeric/complex/acosh") for acosh  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacosh&oldid=121959](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacosh&oldid=121959)" 

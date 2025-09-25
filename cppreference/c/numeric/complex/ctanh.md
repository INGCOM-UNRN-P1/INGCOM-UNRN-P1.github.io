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
**ctanh**(C99)  
  
| [cacosh](cacosh.html "c/numeric/complex/cacosh")(C99)  
---  
[casinh](casinh.html "c/numeric/complex/casinh")(C99)  
[catanh](catanh.html "c/numeric/complex/catanh")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/navbar_content&action=edit)

Defined in header `[`<complex.h>`](../../header/complex.html "c/header/complex")` |  |   
---|---|---  
float [complex](complex.html) ctanhf( float [complex](complex.html) z ); |  (1)  |  (since C99)  
double [complex](complex.html) ctanh( double [complex](complex.html) z ); |  (2)  |  (since C99)  
long double [complex](complex.html) ctanhl( long double [complex](complex.html) z ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define tanh( z ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes the complex hyperbolic tangent of `z`.

4) Type-generic macro: If `z` has type long double [complex](complex.html), `ctanhl` is called. if `z` has type double [complex](complex.html), `ctanh` is called, if `z` has type float [complex](complex.html), `ctanhf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (tanhf, [tanh](../math/tanh.html), tanhl). If `z` is imaginary, then the macro invokes the corresponding real version of the function [tan](../math/tan.html "c/numeric/math/tan"), implementing the formula tanh(iy) = i tan(y), and the return type is imaginary.

## Contents

  * [1 Parameters](ctanh.html#Parameters)
  * [2 Return value](ctanh.html#Return_value)
  * [3 Error handling and special values](ctanh.html#Error_handling_and_special_values)
  * [4 Notes](ctanh.html#Notes)
  * [5 Example](ctanh.html#Example)
  * [6 References](ctanh.html#References)
  * [7 See also](ctanh.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctanh&action=edit&section=1 "Edit section: Parameters")] Parameters

z  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctanh&action=edit&section=2 "Edit section: Return value")] Return value

If no errors occur, complex hyperbolic tangent of `z` is returned 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctanh&action=edit&section=3 "Edit section: Error handling and special values")] Error handling and special values

Errors are reported consistent with [math_errhandling](../math/math_errhandling.html "c/numeric/math/math errhandling")

If the implementation supports IEEE floating-point arithmetic, 

  * ctanh([conj](conj.html)(z)) == [conj](conj.html)(ctanh(z))
  * ctanh(-z) == -ctanh(z)
  * If `z` is `+0+0i`, the result is `+0+0i`
  * If `z` is `x+∞i` (for any[[1]](ctanh.html#cite_note-1) finite x), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised 
  * If `z` is `x+NaN` (for any[[2]](ctanh.html#cite_note-2) finite x), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised 
  * If `z` is `+∞+yi` (for any finite positive y), the result is `1+0i`
  * If `z` is `+∞+∞i`, the result is `1±0i` (the sign of the imaginary part is unspecified) 
  * If `z` is `+∞+NaNi`, the result is `1±0i` (the sign of the imaginary part is unspecified) 
  * If `z` is `NaN+0i`, the result is `NaN+0i`
  * If `z` is `NaN+yi` (for any non-zero y), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised 
  * If `z` is `NaN+NaNi`, the result is `NaN+NaNi`


  1. [↑](ctanh.html#cite_ref-1) per [DR471](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1892.htm#dr_471), this only holds for non-zero x. If `z` is `0+∞i`, the result should be `0+NaNi`
  2. [↑](ctanh.html#cite_ref-2) per [DR471](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1892.htm#dr_471), this only holds for non-zero x. If `z` is `0+NaNi`, the result should be `0+NaNi`



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctanh&action=edit&section=4 "Edit section: Notes")] Notes

Mathematical definition of hyperbolic tangent is tanh z = ez  
-e-z  
  
---  
ez  
+e-z  
  
  
Hyperbolic tangent is an analytical function on the complex plane and has no branch cuts. It is periodic with respect to the imaginary component, with period πi, and has poles of the first order along the imaginary line, at coordinates (0, π(1/2 + n)). However no common floating-point representation is able to represent π/2 exactly, thus there is no value of the argument for which a pole error occurs. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctanh&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <math.h>
    #include <complex.h>
     
    int main(void)
    {
        double [complex](complex.html) z = ctanh(1);  // behaves like real tanh along the real line
        [printf](../../io/fprintf.html)("tanh(1+0i) = %f%+fi (tanh(1)=%f)\n", [creal](creal.html)(z), [cimag](cimag.html)(z), [tanh](../math/tanh.html)(1));
     
        double [complex](complex.html) z2 = ctanh(I); // behaves like tangent along the imaginary line
        [printf](../../io/fprintf.html)("tanh(0+1i) = %f%+fi ( tan(1)=%f)\n", [creal](creal.html)(z2), [cimag](cimag.html)(z2), [tan](../math/tan.html)(1));
    }

Output: 
    
    
    tanh(1+0i) = 0.761594+0.000000i (tanh(1)=0.761594)
    tanh(0+1i) = 0.000000+1.557408i ( tan(1)=1.557408)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctanh&action=edit&section=6 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.6.6 The ctanh functions (p: 194) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



    

  * G.6.2.6 The ctanh functions (p: 542) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.6.6 The ctanh functions (p: 176) 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



    

  * G.6.2.6 The ctanh functions (p: 477) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctanh&action=edit&section=7 "Edit section: See also")] See also

[ csinhcsinhfcsinhl](csinh.html "c/numeric/complex/csinh")(C99)(C99)(C99) |  computes the complex hyperbolic sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_csinh&action=edit)  
---|---  
[ ccoshccoshfccoshl](ccosh.html "c/numeric/complex/ccosh")(C99)(C99)(C99) |  computes the complex hyperbolic cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ccosh&action=edit)  
[ catanhcatanhfcatanhl](catanh.html "c/numeric/complex/catanh")(C99)(C99)(C99) |  computes the complex arc hyperbolic tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_catanh&action=edit)  
[ tanhtanhftanhl](../math/tanh.html "c/numeric/math/tanh")(C99)(C99) |  computes hyperbolic tangent (\\({\small\tanh{x} }\\)tanh(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_tanh&action=edit)  
[C++ documentation](../../../cpp/numeric/complex/tanh.html "cpp/numeric/complex/tanh") for tanh  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctanh&oldid=96281](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctanh&oldid=96281)" 

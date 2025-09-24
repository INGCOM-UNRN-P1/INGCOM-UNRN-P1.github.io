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
**ctan**(C99)  
  
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
float [complex](complex.html) ctanf( float [complex](complex.html) z ); |  (1)  |  (since C99)  
double [complex](complex.html) ctan( double [complex](complex.html) z ); |  (2)  |  (since C99)  
long double [complex](complex.html) ctanl( long double [complex](complex.html) z ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define tan( z ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes the complex tangent of `z`.

4) Type-generic macro: If `z` has type long double [complex](complex.html), `ctanl` is called. if `z` has type double [complex](complex.html), `ctan` is called, if `z` has type float [complex](complex.html), `ctanf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (tanf, [tan](../math/tan.html), tanl). If `z` is imaginary, then the macro invokes the corresponding real version of the function [tanh](../math/tanh.html "c/numeric/math/tanh"), implementing the formula tan(iy) = i tanh(y), and the return type is imaginary.

## Contents

  * [1 Parameters](ctan.html#Parameters)
  * [2 Return value](ctan.html#Return_value)
  * [3 Notes](ctan.html#Notes)
  * [4 Example](ctan.html#Example)
  * [5 References](ctan.html#References)
  * [6 See also](ctan.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctan&action=edit&section=1 "Edit section: Parameters")] Parameters

z  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctan&action=edit&section=2 "Edit section: Return value")] Return value

If no errors occur, the complex tangent of `z` is returned. 

Errors and special cases are handled as if the operation is implemented by -i * [ctanh](ctanh.html)(i*z), where `i` is the imaginary unit. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctan&action=edit&section=3 "Edit section: Notes")] Notes

Tangent is an analytical function on the complex plain and has no branch cuts. It is periodic with respect to the real component, with period πi, and has poles of the first order along the real line, at coordinates (π(1/2 + n), 0). However no common floating-point representation is able to represent π/2 exactly, thus there is no value of the argument for which a pole error occurs. 

Mathematical definition of the tangent is tan z = i(e-iz  
-eiz  
)  
---  
e-iz  
+eiz  
  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctan&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <math.h>
    #include <complex.h>
     
    int main(void)
    {
        double [complex](complex.html) z = ctan(1);  // behaves like real tangent along the real line
        [printf](../../io/fprintf.html)("tan(1+0i) = %f%+fi ( tan(1)=%f)\n", [creal](creal.html)(z), [cimag](cimag.html)(z), [tan](../math/tan.html)(1));
     
        double [complex](complex.html) z2 = ctan(I); // behaves like tanh along the imaginary line 
        [printf](../../io/fprintf.html)("tan(0+1i) = %f%+fi (tanh(1)=%f)\n", [creal](creal.html)(z2), [cimag](cimag.html)(z2), [tanh](../math/tanh.html)(1));
    }

Output: 
    
    
    tan(1+0i) = 1.557408+0.000000i ( tan(1)=1.557408)
    tan(0+1i) = 0.000000+0.761594i (tanh(1)=0.761594)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctan&action=edit&section=5 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.5.6 The ctan functions (p: 192) 



    

  * 7.25 Type-generic complex <tgmath.h> (p: 373-375) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.5.6 The ctan functions (p: 174) 



    

  * 7.22 Type-generic complex <tgcomplex.h> (p: 335-337) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctan&action=edit&section=6 "Edit section: See also")] See also

[ ctanhctanhfctanhl](ctanh.html "c/numeric/complex/ctanh")(C99)(C99)(C99) |  computes the complex hyperbolic tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ctanh&action=edit)  
---|---  
[ csincsinfcsinl](csin.html "c/numeric/complex/csin")(C99)(C99)(C99) |  computes the complex sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_csin&action=edit)  
[ ccosccosfccosl](ccos.html "c/numeric/complex/ccos")(C99)(C99)(C99) |  computes the complex cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ccos&action=edit)  
[ catancatanfcatanl](catan.html "c/numeric/complex/catan")(C99)(C99)(C99) |  computes the complex arc tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_catan&action=edit)  
[ tantanftanl](../math/tan.html "c/numeric/math/tan")(C99)(C99) |  computes tangent (\\({\small\tan{x} }\\)tan(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_tan&action=edit)  
[C++ documentation](../../../cpp/numeric/complex/tan.html "cpp/numeric/complex/tan") for tan  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctan&oldid=77468](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/ctan&oldid=77468)" 

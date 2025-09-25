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
  
| **cabs**(C99)  
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
  
| [cacosh](cacosh.html "c/numeric/complex/cacosh")(C99)  
---  
[casinh](casinh.html "c/numeric/complex/casinh")(C99)  
[catanh](catanh.html "c/numeric/complex/catanh")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/navbar_content&action=edit)

Defined in header `[`<complex.h>`](../../header/complex.html "c/header/complex")` |  |   
---|---|---  
float cabsf( float [complex](complex.html) z ); |  (1)  |  (since C99)  
double cabs( double [complex](complex.html) z ); |  (2)  |  (since C99)  
long double cabsl( long double [complex](complex.html) z ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define fabs( z ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes the complex absolute value (also known as norm, modulus, or magnitude) of `z`.

4) Type-generic macro: if `z` has type long double [complex](complex.html) or long double [imaginary](imaginary.html), `cabsl` is called. If `z` has type float [complex](complex.html) or float [imaginary](imaginary.html), `cabsf` is called. If `z` has type double [complex](complex.html) or double [imaginary](imaginary.html), `cabs` is called. For real and integer types, the corresponding version of [fabs](../math/fabs.html "c/numeric/math/fabs") is called.

## Contents

  * [1 Parameters](cabs.html#Parameters)
  * [2 Return value](cabs.html#Return_value)
  * [3 Example](cabs.html#Example)
  * [4 References](cabs.html#References)
  * [5 See also](cabs.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cabs&action=edit&section=1 "Edit section: Parameters")] Parameters

z  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cabs&action=edit&section=2 "Edit section: Return value")] Return value

If no errors occur, returns the absolute value (norm, magnitude) of `z`. 

Errors and special cases are handled as if the function is implemented as [hypot](../math/hypot.html)([creal](creal.html)(z), [cimag](cimag.html)(z))

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cabs&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <complex.h>
     
    int main(void)
    {
        double [complex](complex.html) z = 1.0 + 1.0*I;
        [printf](../../io/fprintf.html)("%.1f%+.1fi cartesian is rho=%f theta=%f polar\n",
               [creal](creal.html)(z), [cimag](cimag.html)(z), cabs(z), [carg](carg.html)(z));
    }

Output: 
    
    
    1.0+1.0i cartesian is rho=1.414214 theta=0.785398 polar

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cabs&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.8.1 The cabs functions (p: 195) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.8.1 The cabs functions (p: 177) 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cabs&action=edit&section=5 "Edit section: See also")] See also

[ cargcargfcargl](carg.html "c/numeric/complex/carg")(C99)(C99)(C99) |  computes the phase angle of a complex number   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_carg&action=edit)  
---|---  
[ abslabsllabs](../math/abs.html "c/numeric/math/abs")(C99) |  computes absolute value of an integral value (\\(\small{|x|}\\)|x|)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_abs&action=edit)  
[ fabsfabsffabsl](../math/fabs.html "c/numeric/math/fabs")(C99)(C99) |  computes absolute value of a floating-point value (\\(\small{|x|}\\)|x|)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_fabs&action=edit)  
[ hypothypotfhypotl](../math/hypot.html "c/numeric/math/hypot")(C99)(C99)(C99) |  computes square root of the sum of the squares of two given numbers (\\(\scriptsize{\sqrt{x^2+y^2} }\\)√x2  
+y2  
)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_hypot&action=edit)  
[C++ documentation](../../../cpp/numeric/complex/abs.html "cpp/numeric/complex/abs") for abs  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cabs&oldid=77459](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cabs&oldid=77459)" 

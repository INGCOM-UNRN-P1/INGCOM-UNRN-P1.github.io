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
**CMPLX**(C11)  
  
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
  
| [cacosh](cacosh.html "c/numeric/complex/cacosh")(C99)  
---  
[casinh](casinh.html "c/numeric/complex/casinh")(C99)  
[catanh](catanh.html "c/numeric/complex/catanh")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/navbar_content&action=edit)

Defined in header `[`<complex.h>`](../../header/complex.html "c/header/complex")` |  |   
---|---|---  
float [complex](complex.html) CMPLXF( float real, float imag ); |  |  (since C11)  
double [complex](complex.html) CMPLX( double real, double imag ); |  |  (since C11)  
long double [complex](complex.html) CMPLXL( long double real, long double imag ); |  |  (since C11)  
| |   
  
Each of these macros expands to an expression that evaluates to the value of the specified complex type, with the real part having the value of `real` (converted to the specified argument type) and the imaginary part having the value of `imag` (converted to the specified argument type) 

The expressions are suitable for use as initializers for objects with static or thread storage duration, as long as the expressions `real` and `imag` are also suitable. 

## Contents

  * [1 Parameters](CMPLX.html#Parameters)
  * [2 Return value](CMPLX.html#Return_value)
  * [3 Notes](CMPLX.html#Notes)
  * [4 Example](CMPLX.html#Example)
  * [5 References](CMPLX.html#References)
  * [6 See also](CMPLX.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/CMPLX&action=edit&section=1 "Edit section: Parameters")] Parameters

real  |  \-  |  the real part of the complex number to return   
---|---|---  
imag  |  \-  |  the imaginary part of the complex number to return   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/CMPLX&action=edit&section=2 "Edit section: Return value")] Return value

A complex number composed of `real` and `imag` as the real and imaginary parts. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/CMPLX&action=edit&section=3 "Edit section: Notes")] Notes

These macros are implemented as if the imaginary types are supported (even if they are otherwise not supported and [_Imaginary_I](Imaginary_I.html "c/numeric/complex/Imaginary I") is actually undefined) and as if defined as follows: 
    
    
    #define CMPLX(x, y) ((double complex)((double)(x) + _Imaginary_I * (double)(y)))
    #define CMPLXF(x, y) ((float complex)((float)(x) + _Imaginary_I * (float)(y)))
    #define CMPLXL(x, y) ((long double complex)((long double)(x) + \
                          _Imaginary_I * (long double)(y)))

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/CMPLX&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <complex.h>
     
    int main(void)
    {
        double [complex](complex.html) z = CMPLX(0.0, -0.0);
        [printf](../../io/fprintf.html)("z = %.1f%+.1fi\n", [creal](creal.html)(z), [cimag](cimag.html)(z));
    }

Output: 
    
    
    z = 0.0-0.0i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/CMPLX&action=edit&section=5 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.9.3 The CMPLX macros (p: 197) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/CMPLX&action=edit&section=6 "Edit section: See also")] See also

[ _Imaginary_I](Imaginary_I.html "c/numeric/complex/Imaginary I")(C99) |  the imaginary unit constant i   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_Imaginary_I&action=edit)  
---|---  
[C++ documentation](../../../cpp/numeric/complex/complex.html "cpp/numeric/complex/complex") for complex  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/CMPLX&oldid=77485](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/CMPLX&oldid=77485)" 

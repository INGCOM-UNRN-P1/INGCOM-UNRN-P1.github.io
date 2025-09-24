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
**carg**(C99)  
  
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
float cargf( float [complex](complex.html) z ); |  (1)  |  (since C99)  
double carg( double [complex](complex.html) z ); |  (2)  |  (since C99)  
long double cargl( long double [complex](complex.html) z ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define carg( z ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes the argument (also called phase angle) of `z`, with a branch cut along the negative real axis.

4) Type-generic macro: if `z` has type long double [complex](complex.html), long double [imaginary](imaginary.html), or long double, `cargl` is called. If `z` has type float [complex](complex.html), float [imaginary](imaginary.html), or float, `cargf` is called. If `z` has type double [complex](complex.html), double [imaginary](imaginary.html), double, or any integer type, `carg` is called.

## Contents

  * [1 Parameters](carg.html#Parameters)
  * [2 Return value](carg.html#Return_value)
  * [3 Example](carg.html#Example)
  * [4 References](carg.html#References)
  * [5 See also](carg.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/carg&action=edit&section=1 "Edit section: Parameters")] Parameters

z  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/carg&action=edit&section=2 "Edit section: Return value")] Return value

If no errors occur, returns the phase angle of `z` in the interval [−π; π]. 

Errors and special cases are handled as if the function is implemented as [atan2](../math/atan2.html)([cimag](cimag.html)(z), [creal](creal.html)(z))

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/carg&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <complex.h>
     
    int main(void) 
    {
        double [complex](complex.html) z1 = 1.0+0.0*I;
        [printf](../../io/fprintf.html)("phase angle of %.1f%+.1fi is %f\n", [creal](creal.html)(z1), [cimag](cimag.html)(z1), carg(z1));
     
        double [complex](complex.html) z2 = 0.0+1.0*I;
        [printf](../../io/fprintf.html)("phase angle of %.1f%+.1fi is %f\n", [creal](creal.html)(z2), [cimag](cimag.html)(z2), carg(z2));
     
        double [complex](complex.html) z3 = -1.0+0.0*I;
        [printf](../../io/fprintf.html)("phase angle of %.1f%+.1fi is %f\n", [creal](creal.html)(z3), [cimag](cimag.html)(z3), carg(z3));
     
        double [complex](complex.html) z4 = [conj](conj.html)(z3); // or CMPLX(-1, -0.0)
        [printf](../../io/fprintf.html)("phase angle of %.1f%+.1fi (the other side of the cut) is %f\n",
                 [creal](creal.html)(z4), [cimag](cimag.html)(z4), carg(z4));
    }

Output: 
    
    
    phase angle of 1.0+0.0i is 0.000000
    phase angle of 0.0+1.0i is 1.570796
    phase angle of -1.0+0.0i is 3.141593
    phase angle of -1.0-0.0i (the other side of the cut) is -3.141593

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/carg&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.9.1 The carg functions (p: 196) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.9.1 The carg functions (p: 178) 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/carg&action=edit&section=5 "Edit section: See also")] See also

[ cabscabsfcabsl](cabs.html "c/numeric/complex/cabs")(C99)(C99)(C99) |  computes the magnitude of a complex number   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_cabs&action=edit)  
---|---  
[ atan2atan2fatan2l](../math/atan2.html "c/numeric/math/atan2")(C99)(C99) |  computes arc tangent, using signs to determine quadrants   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_atan2&action=edit)  
[C++ documentation](../../../cpp/numeric/complex/arg.html "cpp/numeric/complex/arg") for arg  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/carg&oldid=95595](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/carg&oldid=95595)" 

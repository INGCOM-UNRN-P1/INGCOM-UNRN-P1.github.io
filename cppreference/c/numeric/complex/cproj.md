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
**cproj**(C99)  
  
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
float [complex](complex.html) cprojf( float [complex](complex.html) z ); |  (1)  |  (since C99)  
double [complex](complex.html) cproj( double [complex](complex.html) z ); |  (2)  |  (since C99)  
long double [complex](complex.html) cprojl( long double [complex](complex.html) z ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define cproj( z ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes the projection of `z` on the Riemann sphere.

4) Type-generic macro: if `z` has type long double [complex](complex.html), long double [imaginary](imaginary.html), or long double, `cprojl` is called. If `z` has type float [complex](complex.html), float [imaginary](imaginary.html), or float, `cprojf` is called. If `z` has type double [complex](complex.html), double [imaginary](imaginary.html), double, or any integer type, `cproj` is called.

For most `z`, cproj(z)==z, but all complex infinities, even the numbers where one component is infinite and the other is NaN, become positive real infinity, INFINITY+0.0*I or INFINITY-0.0*I. The sign of the imaginary (zero) component is the sign of [cimag](cimag.html)(z). 

## Contents

  * [1 Parameters](cproj.html#Parameters)
  * [2 Return value](cproj.html#Return_value)
  * [3 Notes](cproj.html#Notes)
  * [4 Example](cproj.html#Example)
  * [5 References](cproj.html#References)
  * [6 See also](cproj.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cproj&action=edit&section=1 "Edit section: Parameters")] Parameters

z  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cproj&action=edit&section=2 "Edit section: Return value")] Return value

The projection of `z` on the Riemann sphere. 

This function is fully specified for all possible inputs and is not subject to any errors described in [math_errhandling](../math/math_errhandling.html "c/numeric/math/math errhandling")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cproj&action=edit&section=3 "Edit section: Notes")] Notes

The `cproj` function helps model the Riemann sphere by mapping all infinities to one (give or take the sign of the imaginary zero), and should be used just before any operation, especially comparisons, that might give spurious results for any of the other infinities. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cproj&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <complex.h>
    #include <math.h>
     
    int main(void)
    {
        double [complex](complex.html) z1 = cproj(1 + 2*I);
        [printf](../../io/fprintf.html)("cproj(1+2i) = %.1f%+.1fi\n", [creal](creal.html)(z1),[cimag](cimag.html)(z1));
     
        double [complex](complex.html) z2 = cproj(INFINITY+2.0*I);
        [printf](../../io/fprintf.html)("cproj(Inf+2i) = %.1f%+.1fi\n", [creal](creal.html)(z2),[cimag](cimag.html)(z2));
     
        double [complex](complex.html) z3 = cproj(INFINITY-2.0*I);
        [printf](../../io/fprintf.html)("cproj(Inf-2i) = %.1f%+.1fi\n", [creal](creal.html)(z3),[cimag](cimag.html)(z3));
    }

Output: 
    
    
    cproj(1+2i) = 1.0+2.0i
    cproj(Inf+2i) = inf+0.0i
    cproj(Inf-2i) = inf-0.0i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cproj&action=edit&section=5 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.9.5 The cproj functions (p: 198) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.9.4 The cproj functions (p: 179) 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cproj&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../../cpp/numeric/complex/proj.html "cpp/numeric/complex/proj") for proj  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cproj&oldid=119329](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cproj&oldid=119329)" 

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
**conj**(C99)  
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
float [complex](complex.html) conjf( float [complex](complex.html) z ); |  (1)  |  (since C99)  
double [complex](complex.html) conj( double [complex](complex.html) z ); |  (2)  |  (since C99)  
long double [complex](complex.html) conjl( long double [complex](complex.html) z ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define conj( z ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes the [complex conjugate](https://en.wikipedia.org/wiki/Complex_conjugate "enwiki:Complex conjugate") of `z` by reversing the sign of the imaginary part.

4) Type-generic macro: if `z` has type long double [complex](complex.html), long double [imaginary](imaginary.html), or long double, `conjl` is called. If `z` has type float [complex](complex.html), float [imaginary](imaginary.html), or float, `conjf` is called. If `z` has type double [complex](complex.html), double [imaginary](imaginary.html), double, or any integer type, `conj` is called.

## Contents

  * [1 Parameters](conj.html#Parameters)
  * [2 Return value](conj.html#Return_value)
  * [3 Notes](conj.html#Notes)
  * [4 Example](conj.html#Example)
  * [5 References](conj.html#References)
  * [6 See also](conj.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/conj&action=edit&section=1 "Edit section: Parameters")] Parameters

z  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/conj&action=edit&section=2 "Edit section: Return value")] Return value

The complex conjugate of `z`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/conj&action=edit&section=3 "Edit section: Notes")] Notes

On C99 implementations that do not implement I as [_Imaginary_I](Imaginary_I.html "c/numeric/complex/Imaginary I"), `conj` may be used to obtain complex numbers with negative zero imaginary part. In C11, the macro [CMPLX](CMPLX.html "c/numeric/complex/CMPLX") is used for that purpose. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/conj&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <complex.h>
     
    int main(void)
    {
        double [complex](complex.html) z = 1.0 + 2.0*I;
        double [complex](complex.html) z2 = conj(z);
        [printf](../../io/fprintf.html)("The conjugate of %.1f%+.1fi is %.1f%+.1fi\n",
                [creal](creal.html)(z), [cimag](cimag.html)(z), [creal](creal.html)(z2), [cimag](cimag.html)(z2));
     
        [printf](../../io/fprintf.html)("Their product is %.1f%+.1fi\n", [creal](creal.html)(z*z2), [cimag](cimag.html)(z*z2));
    }

Output: 
    
    
    The conjugate of 1.0+2.0i is 1.0-2.0i
    Their product is 5.0+0.0i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/conj&action=edit&section=5 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.9.4 The conj functions (p: 198) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.9.3 The conj functions (p: 179) 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/conj&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../../cpp/numeric/complex/conj.html "cpp/numeric/complex/conj") for conj  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/conj&oldid=77461](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/conj&oldid=77461)" 

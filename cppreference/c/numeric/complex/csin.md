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
**csin**(C99)  
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
float [complex](complex.html) csinf( float [complex](complex.html) z ); |  (1)  |  (since C99)  
double [complex](complex.html) csin( double [complex](complex.html) z ); |  (2)  |  (since C99)  
long double [complex](complex.html) csinl( long double [complex](complex.html) z ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define sin( z ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes the complex sine of `z`.

4) Type-generic macro: If `z` has type long double [complex](complex.html), `csinl` is called. if `z` has type double [complex](complex.html), `csin` is called, if `z` has type float [complex](complex.html), `csinf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (sinf, [sin](../math/sin.html), sinl). If `z` is imaginary, then the macro invokes the corresponding real version of the function [sinh](../math/sinh.html "c/numeric/math/sinh"), implementing the formula sin(iy) = i ∙ sinh(y), and the return type of the macro is imaginary.

## Contents

  * [1 Parameters](csin.html#Parameters)
  * [2 Return value](csin.html#Return_value)
  * [3 Notes](csin.html#Notes)
  * [4 Example](csin.html#Example)
  * [5 References](csin.html#References)
  * [6 See also](csin.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csin&action=edit&section=1 "Edit section: Parameters")] Parameters

z  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csin&action=edit&section=2 "Edit section: Return value")] Return value

If no errors occur, the complex sine of `z`. 

Errors and special cases are handled as if the operation is implemented by -I * [csinh](csinh.html)(I*z)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csin&action=edit&section=3 "Edit section: Notes")] Notes

The sine is an entire function on the complex plane, and has no branch cuts. 

Mathematical definition of the sine is sin z = eiz  
-e-iz  
  
---  
2i  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csin&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <math.h>
    #include <complex.h>
     
    int main(void)
    {
        double [complex](complex.html) z = csin(1);  // behaves like real sine along the real line
        [printf](../../io/fprintf.html)("sin(1+0i) = %f%+fi ( sin(1)=%f)\n", [creal](creal.html)(z), [cimag](cimag.html)(z), [sin](../math/sin.html)(1));
     
        double [complex](complex.html) z2 = csin(I); // behaves like sinh along the imaginary line 
        [printf](../../io/fprintf.html)("sin(0+1i) = %f%+fi (sinh(1)=%f)\n", [creal](creal.html)(z2), [cimag](cimag.html)(z2), [sinh](../math/sinh.html)(1));
    }

Output: 
    
    
    sin(1+0i) = 0.841471+0.000000i ( sin(1)=0.841471)
    sin(0+1i) = 0.000000+1.175201i (sinh(1)=1.175201)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csin&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.3.5.5 The csin functions (p: 138-139) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 272-273) 



    

  * G.7 Type-generic math <tgmath.h> (p: 397) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.5.5 The csin functions (p: 191-192) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.5.5 The csin functions (p: 173) 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csin&action=edit&section=6 "Edit section: See also")] See also

[ ccosccosfccosl](ccos.html "c/numeric/complex/ccos")(C99)(C99)(C99) |  computes the complex cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ccos&action=edit)  
---|---  
[ ctanctanfctanl](ctan.html "c/numeric/complex/ctan")(C99)(C99)(C99) |  computes the complex tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ctan&action=edit)  
[ casincasinfcasinl](casin.html "c/numeric/complex/casin")(C99)(C99)(C99) |  computes the complex arc sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_casin&action=edit)  
[ sinsinfsinl](../math/sin.html "c/numeric/math/sin")(C99)(C99) |  computes sine (\\({\small\sin{x} }\\)sin(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_sin&action=edit)  
[C++ documentation](../../../cpp/numeric/complex/sin.html "cpp/numeric/complex/sin") for sin  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csin&oldid=138914](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/csin&oldid=138914)" 

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
  
| **cpow**(C99)  
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
float [complex](complex.html) cpowf( float [complex](complex.html) x, float [complex](complex.html) y ); |  (1)  |  (since C99)  
double [complex](complex.html) cpow( double [complex](complex.html) x, double [complex](complex.html) y ); |  (2)  |  (since C99)  
long double [complex](complex.html) cpowl( long double [complex](complex.html) x, long double [complex](complex.html) y ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define pow( x, y ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes the complex power function xy  
, with branch cut for the first parameter along the negative real axis.

4) Type-generic macro: If any argument has type long double [complex](complex.html), `cpowl` is called. if any argument has type double [complex](complex.html), `cpow` is called, if any argument has type float [complex](complex.html), `cpowf` is called. If the arguments are real or integer, then the macro invokes the corresponding real function (powf, [pow](../math/pow.html), powl). If any argument is imaginary, the corresponding complex number version is called.

## Contents

  * [1 Parameters](cpow.html#Parameters)
  * [2 Return value](cpow.html#Return_value)
  * [3 Example](cpow.html#Example)
  * [4 References](cpow.html#References)
  * [5 See also](cpow.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cpow&action=edit&section=1 "Edit section: Parameters")] Parameters

x, y  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cpow&action=edit&section=2 "Edit section: Return value")] Return value

If no errors occur, the complex power xy  
, is returned. 

Errors and special cases are handled as if the operation is implemented by [cexp](cexp.html)(y*[clog](clog.html)(x)), except that the implementation is allowed to treat special cases more carefully. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cpow&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <complex.h>
     
    int main(void)
    {    
        double [complex](complex.html) z = cpow(1.0+2.0*I, 2);
        [printf](../../io/fprintf.html)("(1+2i)^2 = %.1f%+.1fi\n", [creal](creal.html)(z), [cimag](cimag.html)(z));
     
        double [complex](complex.html) z2 = cpow(-1, 0.5);
        [printf](../../io/fprintf.html)("(-1+0i)^0.5 = %.1f%+.1fi\n", [creal](creal.html)(z2), [cimag](cimag.html)(z2));
     
        double [complex](complex.html) z3 = cpow([conj](conj.html)(-1), 0.5); // other side of the cut
        [printf](../../io/fprintf.html)("(-1-0i)^0.5 = %.1f%+.1fi\n", [creal](creal.html)(z3), [cimag](cimag.html)(z3));
     
        double [complex](complex.html) z4 = cpow(I, I); // i^i = exp(-pi/2)
        [printf](../../io/fprintf.html)("i^i = %f%+fi\n", [creal](creal.html)(z4), [cimag](cimag.html)(z4));
    }

Output: 
    
    
    (1+2i)^2 = -3.0+4.0i
    (-1+0i)^0.5 = 0.0+1.0i
    (-1-0i)^0.5 = 0.0-1.0i
    i^i = 0.207880+0.000000i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cpow&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.8.2 The cpow functions (p: 195-196) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



    

  * G.6.4.1 The cpow functions (p: 544) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.8.2 The cpow functions (p: 177) 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



    

  * G.6.4.1 The cpow functions (p: 479) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cpow&action=edit&section=5 "Edit section: See also")] See also

[ csqrtcsqrtfcsqrtl](csqrt.html "c/numeric/complex/csqrt")(C99)(C99)(C99) |  computes the complex square root   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_csqrt&action=edit)  
---|---  
[ powpowfpowl](../math/pow.html "c/numeric/math/pow")(C99)(C99) |  computes a number raised to the given power (\\(\small{x^y}\\)xy)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_pow&action=edit)  
[C++ documentation](../../../cpp/numeric/complex/pow.html "cpp/numeric/complex/pow") for pow  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cpow&oldid=77465](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cpow&oldid=77465)" 

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
  
| **cacos**(C99)  
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
float [complex](complex.html) cacosf( float [complex](complex.html) z ); |  (1)  |  (since C99)  
double [complex](complex.html) cacos( double [complex](complex.html) z ); |  (2)  |  (since C99)  
long double [complex](complex.html) cacosl( long double [complex](complex.html) z ); |  (3)  |  (since C99)  
Defined in header `[`<tgmath.h>`](../../header/tgmath.html "c/header/tgmath")` |  |   
#define acos( z ) |  (4)  |  (since C99)  
| |   
  
1-3) Computes the complex arc cosine of `z` with branch cuts outside the interval [−1,+1] along the real axis.

4) Type-generic macro: If `z` has type long double [complex](complex.html), `cacosl` is called. if `z` has type double [complex](complex.html), `cacos` is called, if `z` has type float [complex](complex.html), `cacosf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (acosf, [acos](../math/acos.html), acosl). If `z` is imaginary, then the macro invokes the corresponding complex number version.

## Contents

  * [1 Parameters](cacos.html#Parameters)
  * [2 Return value](cacos.html#Return_value)
  * [3 Error handling and special values](cacos.html#Error_handling_and_special_values)
  * [4 Notes](cacos.html#Notes)
  * [5 Example](cacos.html#Example)
  * [6 References](cacos.html#References)
  * [7 See also](cacos.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacos&action=edit&section=1 "Edit section: Parameters")] Parameters

z  |  \-  |  complex argument   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacos&action=edit&section=2 "Edit section: Return value")] Return value

If no errors occur, complex arc cosine of `z` is returned, in the range a strip unbounded along the imaginary axis and in the interval [0; π] along the real axis. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacos&action=edit&section=3 "Edit section: Error handling and special values")] Error handling and special values

Errors are reported consistent with [`math_errhandling`](../math/math_errhandling.html "c/numeric/math/math errhandling"). 

If the implementation supports IEEE floating-point arithmetic, 

  * cacos([conj](conj.html)(z)) == [conj](conj.html)(cacos(z))
  * If `z` is `±0+0i`, the result is `π/2-0i`
  * If `z` is `±0+NaNi`, the result is `π/2+NaNi`
  * If `z` is `x+∞i` (for any finite x), the result is `π/2-∞i`
  * If `z` is `x+NaNi` (for any nonzero finite x), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised. 
  * If `z` is `-∞+yi` (for any positive finite y), the result is `π-∞i`
  * If `z` is `+∞+yi` (for any positive finite y), the result is `+0-∞i`
  * If `z` is `-∞+∞i`, the result is `3π/4-∞i`
  * If `z` is `+∞+∞i`, the result is `π/4-∞i`
  * If `z` is `±∞+NaNi`, the result is `NaN±∞i` (the sign of the imaginary part is unspecified) 
  * If `z` is `NaN+yi` (for any finite y), the result is `NaN+NaNi` and [FE_INVALID](../fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") may be raised 
  * If `z` is `NaN+∞i`, the result is `NaN-∞i`
  * If `z` is `NaN+NaNi`, the result is `NaN+NaNi`



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacos&action=edit&section=4 "Edit section: Notes")] Notes

Inverse cosine (or arc cosine) is a multivalued function and requires a branch cut on the complex plane. The branch cut is conventially placed at the line segments (-∞,-1) and (1,∞) of the real axis. 

The mathematical definition of the principal value of arc cosine is acos z = 1  
---  
2  
π + _i_ ln(_i_ z + √1-z2  
)

For any z, acos(z) = π - acos(-z)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacos&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <math.h>
    #include <complex.h>
     
    int main(void)
    {
        double [complex](complex.html) z = cacos(-2);
        [printf](../../io/fprintf.html)("cacos(-2+0i) = %f%+fi\n", [creal](creal.html)(z), [cimag](cimag.html)(z));
     
        double [complex](complex.html) z2 = cacos([conj](conj.html)(-2)); // or CMPLX(-2, -0.0)
        [printf](../../io/fprintf.html)("cacos(-2-0i) (the other side of the cut) = %f%+fi\n", [creal](creal.html)(z2), [cimag](cimag.html)(z2));
     
        // for any z, acos(z) = pi - acos(-z)
        double pi = [acos](../math/acos.html)(-1);
        double [complex](complex.html) z3 = [ccos](ccos.html)(pi-z2);
        [printf](../../io/fprintf.html)("ccos(pi - cacos(-2-0i) = %f%+fi\n", [creal](creal.html)(z3), [cimag](cimag.html)(z3));
    }

Output: 
    
    
    cacos(-2+0i) = 3.141593-1.316958i
    cacos(-2-0i) (the other side of the cut) = 3.141593+1.316958i
    ccos(pi - cacos(-2-0i) = 2.000000+0.000000i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacos&action=edit&section=6 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.5.1 The cacos functions (p: 190) 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



    

  * G.6.1.1 The cacos functions (p: 539) 



    

  * G.7 Type-generic math <tgmath.h> (p: 545) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.5.1 The cacos functions (p: 172) 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



    

  * G.6.1.1 The cacos functions (p: 474) 



    

  * G.7 Type-generic math <tgmath.h> (p: 480) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacos&action=edit&section=7 "Edit section: See also")] See also

[ casincasinfcasinl](casin.html "c/numeric/complex/casin")(C99)(C99)(C99) |  computes the complex arc sine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_casin&action=edit)  
---|---  
[ catancatanfcatanl](catan.html "c/numeric/complex/catan")(C99)(C99)(C99) |  computes the complex arc tangent   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_catan&action=edit)  
[ ccosccosfccosl](ccos.html "c/numeric/complex/ccos")(C99)(C99)(C99) |  computes the complex cosine   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_ccos&action=edit)  
[ acosacosfacosl](../math/acos.html "c/numeric/math/acos")(C99)(C99) |  computes arc cosine (\\({\small\arccos{x} }\\)arccos(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_acos&action=edit)  
[C++ documentation](../../../cpp/numeric/complex/acos.html "cpp/numeric/complex/acos") for acos  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacos&oldid=136775](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/cacos&oldid=136775)" 

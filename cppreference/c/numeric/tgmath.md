From cppreference.com

< [c](../../c.html "c")‎ | [numeric](../numeric.html "c/numeric")

[ C](../../c.html "c")

[Compiler support](../compiler_support.html "c/compiler support")  
---  
[Language](../language.html "c/language")  
[Headers](../header.html "c/header")  
[Type support](../types.html "c/types")  
[Program utilities](../program.html "c/program")  
[Variadic function support](../variadic.html "c/variadic")  
[Error handling](../error.html "c/error")  
[Dynamic memory management](../memory.html "c/memory")  
[Strings library](../string.html "c/string")  
[Algorithms](../algorithm.html "c/algorithm")  
[Numerics](../numeric.html "c/numeric")  
[Date and time utilities](../chrono.html "c/chrono")  
[Input/output support](../io.html "c/io")  
[Localization support](../locale.html "c/locale")  
[Concurrency support](../thread.html "c/thread") (C11)  
[Technical Specifications](../experimental.html "c/experimental")  
[Symbol index](../index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

[ Numerics](../numeric.html "c/numeric")

[Common mathematical functions](math.html "c/numeric/math")  
---  
[Floating-point environment](fenv.html "c/numeric/fenv") (C99)  
[Pseudo-random number generation](random.html "c/numeric/random")  
[Complex number arithmetic](complex.html "c/numeric/complex") (C99)  
**Type-generic math** (C99)  
[Bit manipulation](../numeric.html#Bit_manipulation "c/numeric") (C23)  
[Checked integer arithmetic](../numeric.html#Checked_integer_arithmetic "c/numeric") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/navbar_content&action=edit)

The header [`<tgmath.h>`](../header/tgmath.html "c/header/tgmath") includes the headers [`<math.h>`](../header/math.html "c/header/math") and [`<complex.h>`](../header/complex.html "c/header/complex") and defines several [type-generic macros](../language/generic.html "c/language/generic") that determine which real or, when applicable, complex function to call based on the types of the arguments. 

For each macro, the parameters whose corresponding real type in the unsuffixed [`<math.h>`](../header/math.html "c/header/math") function is double are known as _generic parameters_ (for example, both parameters of [pow](math/pow.html "c/numeric/math/pow") are generic parameters, but only the first parameter of [scalbn](math/scalbn.html "c/numeric/math/scalbn") is a generic parameter). 

When a [`<tgmath.h>`](../header/tgmath.html "c/header/tgmath")'s macro is used the types of the arguments passed to the generic parameters determine which function is selected by the macro as described below. If the types of the arguments are not [compatible](../language/compatible_type.html#Compatible_types "c/language/type") with the parameter types of the selected function, the behavior is undefined (e.g. if a complex argument is passed into a real-only [`<tgmath.h>`](../header/tgmath.html "c/header/tgmath")'s macro: float [complex](complex/complex.html) fc; [ceil](math/ceil.html)(fc); or double [complex](complex/complex.html) dc; double d; [fmax](math/fmax.html)(dc, d); are examples of undefined behavior). 

Note: type-generic macros were implemented in implementation-defined manner in C99, but C11 keyword [`_Generic`](../keyword/_Generic.html "c/keyword/ Generic") makes it possible to implement these macros in portable manner. 

## Contents

  * [1 Complex/real type-generic macros](tgmath.html#Complex.2Freal_type-generic_macros)
  * [2 Real-only functions](tgmath.html#Real-only_functions)
  * [3 Complex-only functions](tgmath.html#Complex-only_functions)
  * [4 Example](tgmath.html#Example)
  * [5 References](tgmath.html#References)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/tgmath&action=edit&section=1 "Edit section: Complex/real type-generic macros")] Complex/real type-generic macros

For all functions that have both real and complex counterparts, a type-generic macro `XXX` exists, which calls either of: 

  * real function: 



    

  * float variant `XXXf`
  * double variant `XXX`
  * long double variant `XXXl`



  * complex function: 



    

  * float variant `cXXXf`
  * double variant `cXXX`
  * long double variant `cXXXl`



An exception to the above rule is the `fabs` macro (see the table below). 

The function to call is determined as follows: 

  * If any of the arguments for the generic parameters is imaginary, the behavior is specified on each function reference page individually (in particular, `sin`, `cos`, `tan`, `cosh`, `sinh`, `tanh`, `asin`, `atan`, `asinh`, and `atanh` call _real_ functions, the return types of `sin`, `tan`, `sinh`, `tanh`, `asin`, `atan`, `asinh`, and `atanh` are imaginary, and the return types of `cos` and `cosh` are real). 
  * If any of the arguments for the generic parameters is complex, then the complex function is called, otherwise the real function is called. 
  * If any of the arguments for the generic parameters is long double, then the long double variant is called. Otherwise, if any of the parameters is double or integer, then the double variant is called. Otherwise, float variant is called. 



The type-generic macros are as follows: 

Type-generic   
macro  | Real function   
variants  | Complex function   
variants   
---|---|---  
| float | double | long double | float | double | long double  
fabs  | [`fabsf`](math/fabs.html "c/numeric/math/fabs") | [`fabs`](math/fabs.html "c/numeric/math/fabs") | [`fabsl`](math/fabs.html "c/numeric/math/fabs") | [`cabsf`](complex/cabs.html "c/numeric/complex/cabs") | [`cabs`](complex/cabs.html "c/numeric/complex/cabs") | [`cabsl`](complex/cabs.html "c/numeric/complex/cabs")  
exp  | [`expf`](math/exp.html "c/numeric/math/exp") | [`exp`](math/exp.html "c/numeric/math/exp") | [`expl`](math/exp.html "c/numeric/math/exp") | [`cexpf`](complex/cexp.html "c/numeric/complex/cexp") | [`cexp`](complex/cexp.html "c/numeric/complex/cexp") | [`cexpl`](complex/cexp.html "c/numeric/complex/cexp")  
log  | [`logf`](math/log.html "c/numeric/math/log") | [`log`](math/log.html "c/numeric/math/log") | [`logl`](math/log.html "c/numeric/math/log") | [`clogf`](complex/clog.html "c/numeric/complex/clog") | [`clog`](complex/clog.html "c/numeric/complex/clog") | [`clogl`](complex/clog.html "c/numeric/complex/clog")  
pow  | [`powf`](math/pow.html "c/numeric/math/pow") | [`pow`](math/pow.html "c/numeric/math/pow") | [`powl`](math/pow.html "c/numeric/math/pow") | [`cpowf`](complex/cpow.html "c/numeric/complex/cpow") | [`cpow`](complex/cpow.html "c/numeric/complex/cpow") | [`cpowl`](complex/cpow.html "c/numeric/complex/cpow")  
sqrt  | [`sqrtf`](math/sqrt.html "c/numeric/math/sqrt") | [`sqrt`](math/sqrt.html "c/numeric/math/sqrt") | [`sqrtl`](math/sqrt.html "c/numeric/math/sqrt") | [`csqrtf`](complex/csqrt.html "c/numeric/complex/csqrt") | [`csqrt`](complex/csqrt.html "c/numeric/complex/csqrt") | [`csqrtl`](complex/csqrt.html "c/numeric/complex/csqrt")  
sin  | [`sinf`](math/sin.html "c/numeric/math/sin") | [`sin`](math/sin.html "c/numeric/math/sin") | [`sinl`](math/sin.html "c/numeric/math/sin") | [`csinf`](complex/csin.html "c/numeric/complex/csin") | [`csin`](complex/csin.html "c/numeric/complex/csin") | [`csinl`](complex/csin.html "c/numeric/complex/csin")  
cos  | [`cosf`](math/cos.html "c/numeric/math/cos") | [`cos`](math/cos.html "c/numeric/math/cos") | [`cosl`](math/cos.html "c/numeric/math/cos") | [`ccosf`](complex/ccos.html "c/numeric/complex/ccos") | [`ccos`](complex/ccos.html "c/numeric/complex/ccos") | [`ccosl`](complex/ccos.html "c/numeric/complex/ccos")  
tan  | [`tanf`](math/tan.html "c/numeric/math/tan") | [`tan`](math/tan.html "c/numeric/math/tan") | [`tanl`](math/tan.html "c/numeric/math/tan") | [`ctanf`](complex/ctan.html "c/numeric/complex/ctan") | [`ctan`](complex/ctan.html "c/numeric/complex/ctan") | [`ctanl`](complex/ctan.html "c/numeric/complex/ctan")  
asin  | [`asinf`](math/asin.html "c/numeric/math/asin") | [`asin`](math/asin.html "c/numeric/math/asin") | [`asinl`](math/asin.html "c/numeric/math/asin") | [`casinf`](complex/casin.html "c/numeric/complex/casin") | [`casin`](complex/casin.html "c/numeric/complex/casin") | [`casinl`](complex/casin.html "c/numeric/complex/casin")  
acos  | [`acosf`](math/acos.html "c/numeric/math/acos") | [`acos`](math/acos.html "c/numeric/math/acos") | [`acosl`](math/acos.html "c/numeric/math/acos") | [`cacosf`](complex/cacos.html "c/numeric/complex/cacos") | [`cacos`](complex/cacos.html "c/numeric/complex/cacos") | [`cacosl`](complex/cacos.html "c/numeric/complex/cacos")  
atan  | [`atanf`](math/atan.html "c/numeric/math/atan") | [`atan`](math/atan.html "c/numeric/math/atan") | [`atanl`](math/atan.html "c/numeric/math/atan") | [`catanf`](complex/catan.html "c/numeric/complex/catan") | [`catan`](complex/catan.html "c/numeric/complex/catan") | [`catanl`](complex/catan.html "c/numeric/complex/catan")  
sinh  | [`sinhf`](math/sinh.html "c/numeric/math/sinh") | [`sinh`](math/sinh.html "c/numeric/math/sinh") | [`sinhl`](math/sinh.html "c/numeric/math/sinh") | [`csinhf`](complex/csinh.html "c/numeric/complex/csinh") | [`csinh`](complex/csinh.html "c/numeric/complex/csinh") | [`csinhl`](complex/csinh.html "c/numeric/complex/csinh")  
cosh  | [`coshf`](math/cosh.html "c/numeric/math/cosh") | [`cosh`](math/cosh.html "c/numeric/math/cosh") | [`coshl`](math/cosh.html "c/numeric/math/cosh") | [`ccoshf`](complex/ccosh.html "c/numeric/complex/ccosh") | [`ccosh`](complex/ccosh.html "c/numeric/complex/ccosh") | [`ccoshl`](complex/ccosh.html "c/numeric/complex/ccosh")  
tanh  | [`tanhf`](math/tanh.html "c/numeric/math/tanh") | [`tanh`](math/tanh.html "c/numeric/math/tanh") | [`tanhl`](math/tanh.html "c/numeric/math/tanh") | [`ctanhf`](complex/ctanh.html "c/numeric/complex/ctanh") | [`ctanh`](complex/ctanh.html "c/numeric/complex/ctanh") | [`ctanhl`](complex/ctanh.html "c/numeric/complex/ctanh")  
asinh  | [`asinhf`](math/asinh.html "c/numeric/math/asinh") | [`asinh`](math/asinh.html "c/numeric/math/asinh") | [`asinhl`](math/asinh.html "c/numeric/math/asinh") | [`casinhf`](complex/casinh.html "c/numeric/complex/casinh") | [`casinh`](complex/casinh.html "c/numeric/complex/casinh") | [`casinhl`](complex/casinh.html "c/numeric/complex/casinh")  
acosh  | [`acoshf`](math/acosh.html "c/numeric/math/acosh") | [`acosh`](math/acosh.html "c/numeric/math/acosh") | [`acoshl`](math/acosh.html "c/numeric/math/acosh") | [`cacoshf`](complex/cacosh.html "c/numeric/complex/cacosh") | [`cacosh`](complex/cacosh.html "c/numeric/complex/cacosh") | [`cacoshl`](complex/cacosh.html "c/numeric/complex/cacosh")  
atanh  | [`atanhf`](math/atanh.html "c/numeric/math/atanh") | [`atanh`](math/atanh.html "c/numeric/math/atanh") | [`atanhl`](math/atanh.html "c/numeric/math/atanh") | [`catanhf`](complex/catanh.html "c/numeric/complex/catanh") | [`catanh`](complex/catanh.html "c/numeric/complex/catanh") | [`catanhl`](complex/catanh.html "c/numeric/complex/catanh")  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/tgmath&action=edit&section=2 "Edit section: Real-only functions")] Real-only functions

For all functions that do not have complex counterparts, with the exception of `modf`, a type-generic macro `XXX` exists, which calls either of the variants of a real function: 

  * float variant `XXXf`
  * double variant `XXX`
  * long double variant `XXXl`



The function to call is determined as follows: 

  * If any of the arguments for the generic parameters is long double, then the long double variant is called. Otherwise, if any of the arguments for the generic parameters is double, then the double variant is called. Otherwise, float variant is called. 

Type-generic   
macro  | Real function   
variants   
---|---  
| float | double | long double  
atan2  | [`atan2f`](math/atan2.html "c/numeric/math/atan2") | [`atan2`](math/atan2.html "c/numeric/math/atan2") | [`atan2l`](math/atan2.html "c/numeric/math/atan2")  
cbrt  | [`cbrtf`](math/cbrt.html "c/numeric/math/cbrt") | [`cbrt`](math/cbrt.html "c/numeric/math/cbrt") | [`cbrtl`](math/cbrt.html "c/numeric/math/cbrt")  
ceil  | [`ceilf`](math/ceil.html "c/numeric/math/ceil") | [`ceil`](math/ceil.html "c/numeric/math/ceil") | [`ceill`](math/ceil.html "c/numeric/math/ceil")  
copysign  | [`copysignf`](math/copysign.html "c/numeric/math/copysign") | [`copysign`](math/copysign.html "c/numeric/math/copysign") | [`copysignl`](math/copysign.html "c/numeric/math/copysign")  
erf  | [`erff`](math/erf.html "c/numeric/math/erf") | [`erf`](math/erf.html "c/numeric/math/erf") | [`erfl`](math/erf.html "c/numeric/math/erf")  
erfc  | [`erfcf`](math/erfc.html "c/numeric/math/erfc") | [`erfc`](math/erfc.html "c/numeric/math/erfc") | [`erfcl`](math/erfc.html "c/numeric/math/erfc")  
exp2  | [`exp2f`](math/exp2.html "c/numeric/math/exp2") | [`exp2`](math/exp2.html "c/numeric/math/exp2") | [`exp2l`](math/exp2.html "c/numeric/math/exp2")  
expm1  | [`expm1f`](math/expm1.html "c/numeric/math/expm1") | [`expm1`](math/expm1.html "c/numeric/math/expm1") | [`expm1l`](math/expm1.html "c/numeric/math/expm1")  
fdim  | [`fdimf`](math/fdim.html "c/numeric/math/fdim") | [`fdim`](math/fdim.html "c/numeric/math/fdim") | [`fdiml`](math/fdim.html "c/numeric/math/fdim")  
floor  | [`floorf`](math/floor.html "c/numeric/math/floor") | [`floor`](math/floor.html "c/numeric/math/floor") | [`floorl`](math/floor.html "c/numeric/math/floor")  
fma  | [`fmaf`](math/fma.html "c/numeric/math/fma") | [`fma`](math/fma.html "c/numeric/math/fma") | [`fmal`](math/fma.html "c/numeric/math/fma")  
fmax  | [`fmaxf`](math/fmax.html "c/numeric/math/fmax") | [`fmax`](math/fmax.html "c/numeric/math/fmax") | [`fmaxl`](math/fmax.html "c/numeric/math/fmax")  
fmin  | [`fminf`](math/fmin.html "c/numeric/math/fmin") | [`fmin`](math/fmin.html "c/numeric/math/fmin") | [`fminl`](math/fmin.html "c/numeric/math/fmin")  
fmod  | [`fmodf`](math/fmod.html "c/numeric/math/fmod") | [`fmod`](math/fmod.html "c/numeric/math/fmod") | [`fmodl`](math/fmod.html "c/numeric/math/fmod")  
frexp  | [`frexpf`](math/frexp.html "c/numeric/math/frexp") | [`frexp`](math/frexp.html "c/numeric/math/frexp") | [`frexpl`](math/frexp.html "c/numeric/math/frexp")  
hypot  | [`hypotf`](math/hypot.html "c/numeric/math/hypot") | [`hypot`](math/hypot.html "c/numeric/math/hypot") | [`hypotl`](math/hypot.html "c/numeric/math/hypot")  
ilogb  | [`ilogbf`](math/ilogb.html "c/numeric/math/ilogb") | [`ilogb`](math/ilogb.html "c/numeric/math/ilogb") | [`ilogbl`](math/ilogb.html "c/numeric/math/ilogb")  
ldexp  | [`ldexpf`](math/ldexp.html "c/numeric/math/ldexp") | [`ldexp`](math/ldexp.html "c/numeric/math/ldexp") | [`ldexpl`](math/ldexp.html "c/numeric/math/ldexp")  
lgamma  | [`lgammaf`](math/lgamma.html "c/numeric/math/lgamma") | [`lgamma`](math/lgamma.html "c/numeric/math/lgamma") | [`lgammal`](math/lgamma.html "c/numeric/math/lgamma")  
llrint  | [`llrintf`](math/rint.html "c/numeric/math/rint") | [`llrint`](math/rint.html "c/numeric/math/rint") | [`llrintl`](math/rint.html "c/numeric/math/rint")  
llround  | [`llroundf`](math/round.html "c/numeric/math/round") | [`llround`](math/round.html "c/numeric/math/round") | [`llroundl`](math/round.html "c/numeric/math/round")  
log10  | [`log10f`](math/log10.html "c/numeric/math/log10") | [`log10`](math/log10.html "c/numeric/math/log10") | [`log10l`](math/log10.html "c/numeric/math/log10")  
log1p  | [`log1pf`](math/log1p.html "c/numeric/math/log1p") | [`log1p`](math/log1p.html "c/numeric/math/log1p") | [`log1pl`](math/log1p.html "c/numeric/math/log1p")  
log2  | [`log2f`](math/log2.html "c/numeric/math/log2") | [`log2`](math/log2.html "c/numeric/math/log2") | [`log2l`](math/log2.html "c/numeric/math/log2")  
logb  | [`logbf`](math/logb.html "c/numeric/math/logb") | [`logb`](math/logb.html "c/numeric/math/logb") | [`logbl`](math/logb.html "c/numeric/math/logb")  
lrint  | [`lrintf`](math/rint.html "c/numeric/math/rint") | [`lrint`](math/rint.html "c/numeric/math/rint") | [`lrintl`](math/rint.html "c/numeric/math/rint")  
lround  | [`lroundf`](math/round.html "c/numeric/math/round") | [`lround`](math/round.html "c/numeric/math/round") | [`lroundl`](math/round.html "c/numeric/math/round")  
nearbyint  | [`nearbyintf`](math/nearbyint.html "c/numeric/math/nearbyint") | [`nearbyint`](math/nearbyint.html "c/numeric/math/nearbyint") | [`nearbyintl`](math/nearbyint.html "c/numeric/math/nearbyint")  
nextafter  | [`nextafterf`](math/nexttoward.html "c/numeric/math/nextafter") | [`nextafter`](math/nexttoward.html "c/numeric/math/nextafter") | [`nextafterl`](math/nexttoward.html "c/numeric/math/nextafter")  
nexttoward  | [`nexttowardf`](math/nexttoward.html "c/numeric/math/nextafter") | [`nexttoward`](math/nexttoward.html "c/numeric/math/nextafter") | [`nexttowardl`](math/nexttoward.html "c/numeric/math/nextafter")  
remainder  | [`remainderf`](math/remainder.html "c/numeric/math/remainder") | [`remainder`](math/remainder.html "c/numeric/math/remainder") | [`remainderl`](math/remainder.html "c/numeric/math/remainder")  
remquo  | [`remquof`](math/remquo.html "c/numeric/math/remquo") | [`remquo`](math/remquo.html "c/numeric/math/remquo") | [`remquol`](math/remquo.html "c/numeric/math/remquo")  
rint  | [`rintf`](math/rint.html "c/numeric/math/rint") | [`rint`](math/rint.html "c/numeric/math/rint") | [`rintl`](math/rint.html "c/numeric/math/rint")  
round  | [`roundf`](math/round.html "c/numeric/math/round") | [`round`](math/round.html "c/numeric/math/round") | [`roundl`](math/round.html "c/numeric/math/round")  
scalbln  | [`scalblnf`](math/scalbn.html "c/numeric/math/scalbn") | [`scalbln`](math/scalbn.html "c/numeric/math/scalbn") | [`scalblnl`](math/scalbn.html "c/numeric/math/scalbn")  
scalbn  | [`scalbnf`](math/scalbn.html "c/numeric/math/scalbn") | [`scalbn`](math/scalbn.html "c/numeric/math/scalbn") | [`scalbnl`](math/scalbn.html "c/numeric/math/scalbn")  
tgamma  | [`tgammaf`](math/tgamma.html "c/numeric/math/tgamma") | [`tgamma`](math/tgamma.html "c/numeric/math/tgamma") | [`tgammal`](math/tgamma.html "c/numeric/math/tgamma")  
trunc  | [`truncf`](math/trunc.html "c/numeric/math/trunc") | [`trunc`](math/trunc.html "c/numeric/math/trunc") | [`truncl`](math/trunc.html "c/numeric/math/trunc")  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/tgmath&action=edit&section=3 "Edit section: Complex-only functions")] Complex-only functions

For all complex number functions that do not have real counterparts, a type-generic macro `cXXX` exists, which calls either of the variants of a complex function: 

  * float [complex](complex/complex.html) variant `cXXXf`
  * double [complex](complex/complex.html) variant `cXXX`
  * long double [complex](complex/complex.html) variant `cXXXl`



The function to call is determined as follows: 

  * If any of the arguments for the generic parameters is real, complex, or imaginary, then the appropriate complex function is called. 

Type-generic   
macro  | Complex function   
variants   
---|---  
| float | double | long double  
carg  | [`cargf`](complex/carg.html "c/numeric/complex/carg") | [`carg`](complex/carg.html "c/numeric/complex/carg") | [`cargl`](complex/carg.html "c/numeric/complex/carg")  
conj  | [`conjf`](complex/conj.html "c/numeric/complex/conj") | [`conj`](complex/conj.html "c/numeric/complex/conj") | [`conjl`](complex/conj.html "c/numeric/complex/conj")  
creal  | [`crealf`](complex/creal.html "c/numeric/complex/creal") | [`creal`](complex/creal.html "c/numeric/complex/creal") | [`creall`](complex/creal.html "c/numeric/complex/creal")  
cimag  | [`cimagf`](complex/cimag.html "c/numeric/complex/cimag") | [`cimag`](complex/cimag.html "c/numeric/complex/cimag") | [`cimagl`](complex/cimag.html "c/numeric/complex/cimag")  
cproj  | [`cprojf`](complex/cproj.html "c/numeric/complex/cproj") | [`cproj`](complex/cproj.html "c/numeric/complex/cproj") | [`cprojl`](complex/cproj.html "c/numeric/complex/cproj")  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/tgmath&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <tgmath.h>
     
    int main(void)
    {
        int i = 2;
        [printf](../io/fprintf.html)("sqrt(2) = %f\n", [sqrt](math/sqrt.html)(i)); // argument type is int, calls sqrt
     
        float f = 0.5;
        [printf](../io/fprintf.html)("sin(0.5f) = %f\n", [sin](math/sin.html)(f)); // argument type is float, calls sinf
     
        float [complex](complex/complex.html) dc = 1 + 0.5*I;
        float [complex](complex/complex.html) z = [sqrt](math/sqrt.html)(dc); // argument type is float complex, calls csqrtf
        [printf](../io/fprintf.html)("sqrt(1 + 0.5i) = %f+%fi\n",
               [creal](complex/creal.html)(z),  // argument type is float complex, calls crealf
               [cimag](complex/cimag.html)(z)); // argument type is float complex, calls cimagf
    }

Output: 
    
    
    sqrt(2) = 1.414214
    sin(0.5f) = 0.479426
    sqrt(1 + 0.5i) = 1.029086+0.242934i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/tgmath&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.25 Type-generic math <tgmath.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.25 Type-generic math <tgmath.h> (p: 272-273) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.25 Type-generic math <tgmath.h> (p: 373-375) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.22 Type-generic math <tgmath.h> (p: 335-337) 



Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/tgmath&oldid=180676](https://en.cppreference.com/mwiki/index.php?title=c/numeric/tgmath&oldid=180676)" 

From cppreference.com

< [c](../../c.html "c")‎ | [header](../header.html "c/header")

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

[ Standard Library headers ](../header.html "c/header")

| [`<assert.h>`](assert.html "c/header/assert")  
---  
[`<complex.h>`](complex.html "c/header/complex") (C99)  
[`<ctype.h>`](ctype.html "c/header/ctype")  
[`<errno.h>`](errno.html "c/header/errno")  
[`<fenv.h>`](fenv.html "c/header/fenv") (C99)  
[`<float.h>`](float.html "c/header/float")  
[`<inttypes.h>`](inttypes.html "c/header/inttypes") (C99)` `  
[`<iso646.h>`](iso646.html "c/header/iso646") (C95)  
[`<limits.h>`](limits.html "c/header/limits")  
[`<locale.h>`](locale.html "c/header/locale")  
**`< math.h>`**  
  
| [`<setjmp.h>`](setjmp.html "c/header/setjmp")  
---  
[`<signal.h>`](signal.html "c/header/signal")  
[`<stdalign.h>`](stdalign.html "c/header/stdalign") (C11*)  
[`<stdarg.h>`](stdarg.html "c/header/stdarg")  
[`<stdatomic.h>`](stdatomic.html "c/header/stdatomic") (C11)` `  
[`<stdbit.h>`](stdbit.html "c/header/stdbit") (C23)  
[`<stdbool.h>`](stdbool.html "c/header/stdbool") (C99*)  
[`<stdckdint.h>`](stdckdint.html "c/header/stdckdint") (C23)  
[`<stddef.h>`](stddef.html "c/header/stddef")  
[`<stdint.h>`](stdint.html "c/header/stdint") (C99)  
[`<stdio.h>`](stdio.html "c/header/stdio")  
  
| [`<stdlib.h>`](stdlib.html "c/header/stdlib")  
---  
[`<stdmchar.h>`](stdmchar.html "c/header/stdmchar") (C29)  
[`<stdnoreturn.h>`](stdnoreturn.html "c/header/stdnoreturn") (C11*)  
[`<string.h>`](string.html "c/header/string")  
[`<tgmath.h>`](tgmath.html "c/header/tgmath") (C99)  
[`<threads.h>`](threads.html "c/header/threads") (C11)  
[`<time.h>`](time.html "c/header/time")  
[`<uchar.h>`](uchar.html "c/header/uchar") (C11)  
[`<wchar.h>`](wchar.html "c/header/wchar") (C95)  
[`<wctype.h>`](wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header is part of the [mathematics](../numeric/math.html "c/numeric/math") library. 

  


| This section is incomplete  
Reason: recheck add more from B.11 Mathematics <math.h>  
---|---  
  
## Contents

  * [1 Types](math.html#Types)
  * [2 Constants](math.html#Constants)
    * [2.1 Classification](math.html#Classification)
  * [3 Functions](math.html#Functions)
    * [3.1 Basic operations](math.html#Basic_operations)
    * [3.2 Exponential functions](math.html#Exponential_functions)
    * [3.3 Power functions](math.html#Power_functions)
    * [3.4 Trigonometric functions](math.html#Trigonometric_functions)
    * [3.5 Hyperbolic functions](math.html#Hyperbolic_functions)
    * [3.6 Error and gamma functions](math.html#Error_and_gamma_functions)
    * [3.7 Nearest integer floating-point operations](math.html#Nearest_integer_floating-point_operations)
    * [3.8 Floating-point manipulation functions](math.html#Floating-point_manipulation_functions)
    * [3.9 Classification and comparison](math.html#Classification_and_comparison)
  * [4 Synopsis](math.html#Synopsis)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/math&action=edit&section=1 "Edit section: Types")] Types

[ float_t](../numeric/math/float_t.html "c/numeric/math/float t")(C99) |  most efficient floating-point type at least as wide as float   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_float_t&action=edit)  
---|---  
[ double_t](../numeric/math/float_t.html "c/numeric/math/float t")(C99) |  most efficient floating-point type at least as wide as double   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_double_t&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/math&action=edit&section=2 "Edit section: Constants")] Constants

[ HUGE_VALFHUGE_VALHUGE_VALL](../numeric/math/HUGE_VALL.html "c/numeric/math/HUGE VAL")(C99)(C99) |  indicates value too big to be representable (infinity) by float, double and long double respectively   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_HUGE_VAL&action=edit)  
---|---  
[ INFINITY](../numeric/math/INFINITY.html "c/numeric/math/INFINITY")(C99) |  evaluates to positive infinity or the value guaranteed to overflow a float   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_INFINITY&action=edit)  
[ NAN](../numeric/math/NAN.html "c/numeric/math/NAN")(C99) |  evaluates to a quiet NaN of type float   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_NAN&action=edit)  
[ FP_FAST_FMAFFP_FAST_FMAFP_FAST_FMAL](../numeric/math/fma.html "c/numeric/math/fma")(C99)(C99)(C99) |  indicates that the fma function generally executes about as fast as, or faster than, a multiply and an add of double operands   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_FP_FAST_FMA&action=edit)  
[ FP_ILOGB0FP_ILOGBNAN](../numeric/math/ilogb.html "c/numeric/math/ilogb")(C99)(C99) |  evaluates to [ilogb](../numeric/math/ilogb.html)(x) if x is zero or NaN, respectively   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_FP_ILOGB0&action=edit)  
[ math_errhandlingMATH_ERRNOMATH_ERREXCEPT](../numeric/math/math_errhandling.html "c/numeric/math/math errhandling")(C99)(C99)(C99) |  defines the error handling mechanism used by the common mathematical functions   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_math_errhandling&action=edit)  
  
#####  Classification   
  
[ FP_NORMALFP_SUBNORMALFP_ZEROFP_INFINITEFP_NAN](../numeric/math/FP_categories.html "c/numeric/math/FP categories")(C99)(C99)(C99)(C99)(C99) |  indicates a floating-point category   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_FP_categories&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/math&action=edit&section=3 "Edit section: Functions")] Functions

#####  Basic operations   
  
---  
[ fabsfabsffabsl](../numeric/math/fabs.html "c/numeric/math/fabs")(C99)(C99) |  computes absolute value of a floating-point value (\\(\small{|x|}\\)|x|)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_fabs&action=edit)  
[ fmodfmodffmodl](../numeric/math/fmod.html "c/numeric/math/fmod")(C99)(C99) |  computes remainder of the floating-point division operation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_fmod&action=edit)  
[ remainderremainderfremainderl](../numeric/math/remainder.html "c/numeric/math/remainder")(C99)(C99)(C99) |  computes signed remainder of the floating-point division operation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_remainder&action=edit)  
[ remquoremquofremquol](../numeric/math/remquo.html "c/numeric/math/remquo")(C99)(C99)(C99) |  computes signed remainder as well as the three last bits of the division operation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_remquo&action=edit)  
[ fmafmaffmal](../numeric/math/fma.html "c/numeric/math/fma")(C99)(C99)(C99) |  computes fused multiply-add operation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_fma&action=edit)  
[ fmaxfmaxffmaxl](../numeric/math/fmax.html "c/numeric/math/fmax")(C99)(C99)(C99) |  determines larger of two floating-point values   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_fmax&action=edit)  
[ fminfminffminl](../numeric/math/fmin.html "c/numeric/math/fmin")(C99)(C99)(C99) |  determines smaller of two floating-point values   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_fmin&action=edit)  
[ fdimfdimffdiml](../numeric/math/fdim.html "c/numeric/math/fdim")(C99)(C99)(C99) |  determines positive difference of two floating-point values (\\({\small\max{(0, x-y)} }\\)max(0, x-y))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_fdim&action=edit)  
[ nannanfnanl](../numeric/math/nan.html "c/numeric/math/nan")(C99)(C99)(C99) |  returns a NaN (not-a-number)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_fnan&action=edit)  
  
#####  Exponential functions   
  
[ expexpfexpl](../numeric/math/exp.html "c/numeric/math/exp")(C99)(C99) |  computes _e_ raised to the given power (\\({\small e^x}\\)ex)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_exp&action=edit)  
[ exp2exp2fexp2l](../numeric/math/exp2.html "c/numeric/math/exp2")(C99)(C99)(C99) |  computes _2_ raised to the given power (\\({\small 2^x}\\)2x)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_exp2&action=edit)  
[ expm1expm1fexpm1l](../numeric/math/expm1.html "c/numeric/math/expm1")(C99)(C99)(C99) |  computes _e_ raised to the given power, minus one (\\({\small e^x-1}\\)ex-1)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_expm1&action=edit)  
[ loglogflogl](../numeric/math/log.html "c/numeric/math/log")(C99)(C99) |  computes natural (base-_e_) logarithm (\\({\small \ln{x} }\\)ln(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_log&action=edit)  
[ log10log10flog10l](../numeric/math/log10.html "c/numeric/math/log10")(C99)(C99) |  computes common (base-_10_) logarithm (\\({\small \log_{10}{x} }\\)log10(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_log10&action=edit)  
[ log2log2flog2l](../numeric/math/log2.html "c/numeric/math/log2")(C99)(C99)(C99) |  computes base-2 logarithm (\\({\small \log_{2}{x} }\\)log2(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_log2&action=edit)  
[ log1plog1pflog1pl](../numeric/math/log1p.html "c/numeric/math/log1p")(C99)(C99)(C99) |  computes natural (base-_e_) logarithm of 1 plus the given number (\\({\small \ln{(1+x)} }\\)ln(1+x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_log1p&action=edit)  
  
#####  Power functions   
  
[ powpowfpowl](../numeric/math/pow.html "c/numeric/math/pow")(C99)(C99) |  computes a number raised to the given power (\\(\small{x^y}\\)xy)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_pow&action=edit)  
[ sqrtsqrtfsqrtl](../numeric/math/sqrt.html "c/numeric/math/sqrt")(C99)(C99) |  computes square root (\\(\small{\sqrt{x} }\\)√x)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_sqrt&action=edit)  
[ cbrtcbrtfcbrtl](../numeric/math/cbrt.html "c/numeric/math/cbrt")(C99)(C99)(C99) |  computes cube root (\\(\small{\sqrt[3]{x} }\\)3√x)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_cbrt&action=edit)  
[ hypothypotfhypotl](../numeric/math/hypot.html "c/numeric/math/hypot")(C99)(C99)(C99) |  computes square root of the sum of the squares of two given numbers (\\(\scriptsize{\sqrt{x^2+y^2} }\\)√x2  
+y2  
)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_hypot&action=edit)  
  
#####  Trigonometric functions   
  
[ sinsinfsinl](../numeric/math/sin.html "c/numeric/math/sin")(C99)(C99) |  computes sine (\\({\small\sin{x} }\\)sin(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_sin&action=edit)  
[ coscosfcosl](../numeric/math/cos.html "c/numeric/math/cos")(C99)(C99) |  computes cosine (\\({\small\cos{x} }\\)cos(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_cos&action=edit)  
[ tantanftanl](../numeric/math/tan.html "c/numeric/math/tan")(C99)(C99) |  computes tangent (\\({\small\tan{x} }\\)tan(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_tan&action=edit)  
[ asinasinfasinl](../numeric/math/asin.html "c/numeric/math/asin")(C99)(C99) |  computes arc sine (\\({\small\arcsin{x} }\\)arcsin(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_asin&action=edit)  
[ acosacosfacosl](../numeric/math/acos.html "c/numeric/math/acos")(C99)(C99) |  computes arc cosine (\\({\small\arccos{x} }\\)arccos(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_acos&action=edit)  
[ atanatanfatanl](../numeric/math/atan.html "c/numeric/math/atan")(C99)(C99) |  computes arc tangent (\\({\small\arctan{x} }\\)arctan(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_atan&action=edit)  
[ atan2atan2fatan2l](../numeric/math/atan2.html "c/numeric/math/atan2")(C99)(C99) |  computes arc tangent, using signs to determine quadrants   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_atan2&action=edit)  
  
#####  Hyperbolic functions   
  
[ sinhsinhfsinhl](../numeric/math/sinh.html "c/numeric/math/sinh")(C99)(C99) |  computes hyperbolic sine (\\({\small\sinh{x} }\\)sinh(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_sinh&action=edit)  
[ coshcoshfcoshl](../numeric/math/cosh.html "c/numeric/math/cosh")(C99)(C99) |  computes hyperbolic cosine (\\({\small\cosh{x} }\\)cosh(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_cosh&action=edit)  
[ tanhtanhftanhl](../numeric/math/tanh.html "c/numeric/math/tanh")(C99)(C99) |  computes hyperbolic tangent (\\({\small\tanh{x} }\\)tanh(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_tanh&action=edit)  
[ asinhasinhfasinhl](../numeric/math/asinh.html "c/numeric/math/asinh")(C99)(C99)(C99) |  computes inverse hyperbolic sine (\\({\small\operatorname{arsinh}{x} }\\)arsinh(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_asinh&action=edit)  
[ acoshacoshfacoshl](../numeric/math/acosh.html "c/numeric/math/acosh")(C99)(C99)(C99) |  computes inverse hyperbolic cosine (\\({\small\operatorname{arcosh}{x} }\\)arcosh(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_acosh&action=edit)  
[ atanhatanhfatanhl](../numeric/math/atanh.html "c/numeric/math/atanh")(C99)(C99)(C99) |  computes inverse hyperbolic tangent (\\({\small\operatorname{artanh}{x} }\\)artanh(x))   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_atanh&action=edit)  
  
#####  Error and gamma functions   
  
[ erferfferfl](../numeric/math/erf.html "c/numeric/math/erf")(C99)(C99)(C99) |  computes error function   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_erf&action=edit)  
[ erfcerfcferfcl](../numeric/math/erfc.html "c/numeric/math/erfc")(C99)(C99)(C99) |  computes complementary error function   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_erfc&action=edit)  
[ tgammatgammaftgammal](../numeric/math/tgamma.html "c/numeric/math/tgamma")(C99)(C99)(C99) |  computes gamma function   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_tgamma&action=edit)  
[ lgammalgammaflgammal](../numeric/math/lgamma.html "c/numeric/math/lgamma")(C99)(C99)(C99) |  computes natural (base-_e_) logarithm of the gamma function   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_lgamma&action=edit)  
  
#####  Nearest integer floating-point operations   
  
[ ceilceilfceill](../numeric/math/ceil.html "c/numeric/math/ceil")(C99)(C99) |  computes smallest integer not less than the given value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_ceil&action=edit)  
[ floorfloorffloorl](../numeric/math/floor.html "c/numeric/math/floor")(C99)(C99) |  computes largest integer not greater than the given value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_floor&action=edit)  
[ trunctruncftruncl](../numeric/math/trunc.html "c/numeric/math/trunc")(C99)(C99)(C99) |  rounds to nearest integer not greater in magnitude than the given value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_trunc&action=edit)  
[ roundroundfroundllroundlroundflroundlllroundllroundfllroundl](../numeric/math/round.html "c/numeric/math/round")(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99) |  rounds to nearest integer, rounding away from zero in halfway cases   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_round&action=edit)  
[ nearbyintnearbyintfnearbyintl](../numeric/math/nearbyint.html "c/numeric/math/nearbyint")(C99)(C99)(C99) |  rounds to an integer using current rounding mode   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_nearbyint&action=edit)  
[ rintrintfrintllrintlrintflrintlllrintllrintfllrintl](../numeric/math/rint.html "c/numeric/math/rint")(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99) |  rounds to an integer using current rounding mode with   
exception if the result differs   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_rint&action=edit)  
  
#####  Floating-point manipulation functions   
  
[ frexpfrexpffrexpl](../numeric/math/frexp.html "c/numeric/math/frexp")(C99)(C99) |  breaks a number into significand and a power of 2   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_frexp&action=edit)  
[ ldexpldexpfldexpl](../numeric/math/ldexp.html "c/numeric/math/ldexp")(C99)(C99) |  multiplies a number by 2 raised to a power   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_ldexp&action=edit)  
[ modfmodffmodfl](../numeric/math/modf.html "c/numeric/math/modf")(C99)(C99) |  breaks a number into integer and fractional parts   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_modf&action=edit)  
[ scalbnscalbnfscalbnlscalblnscalblnfscalblnl](../numeric/math/scalbn.html "c/numeric/math/scalbn")(C99)(C99)(C99)(C99)(C99)(C99) |  computes efficiently a number times [FLT_RADIX](../types/limits.html "c/types/limits") raised to a power   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_scalbn&action=edit)  
[ ilogbilogbfilogbl](../numeric/math/ilogb.html "c/numeric/math/ilogb")(C99)(C99)(C99) |  extracts exponent of the given number   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_ilogb&action=edit)  
[ logblogbflogbl](../numeric/math/logb.html "c/numeric/math/logb")(C99)(C99)(C99) |  extracts exponent of the given number   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_logb&action=edit)  
[ nextafternextafterfnextafterlnexttowardnexttowardfnexttowardl](../numeric/math/nexttoward.html "c/numeric/math/nextafter")(C99)(C99)(C99)(C99)(C99)(C99) |  determines next representable floating-point value towards the given value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_nextafter&action=edit)  
[ copysigncopysignfcopysignl](../numeric/math/copysign.html "c/numeric/math/copysign")(C99)(C99)(C99) |  produces a value with the magnitude of a given value and the sign of another given value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_copysign&action=edit)  
  
#####  Classification and comparison   
  
[ fpclassify](../numeric/math/fpclassify.html "c/numeric/math/fpclassify")(C99) |  classifies the given floating-point value   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_fpclassify&action=edit)  
[ isfinite](../numeric/math/isfinite.html "c/numeric/math/isfinite")(C99) |  checks if the given number has finite value   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_isfinite&action=edit)  
[ isinf](../numeric/math/isinf.html "c/numeric/math/isinf")(C99) |  checks if the given number is infinite   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_isinf&action=edit)  
[ isnan](../numeric/math/isnan.html "c/numeric/math/isnan")(C99) |  checks if the given number is NaN   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_isnan&action=edit)  
[ isnormal](../numeric/math/isnormal.html "c/numeric/math/isnormal")(C99) |  checks if the given number is normal   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_isnormal&action=edit)  
[ signbit](../numeric/math/signbit.html "c/numeric/math/signbit")(C99) |  checks if the given number is negative   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_signbit&action=edit)  
[ isgreater](../numeric/math/isgreater.html "c/numeric/math/isgreater")(C99) |  checks if the first floating-point argument is greater than the second   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_isgreater&action=edit)  
[ isgreaterequal](../numeric/math/isgreaterequal.html "c/numeric/math/isgreaterequal")(C99) |  checks if the first floating-point argument is greater or equal than the second   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_isgreaterequal&action=edit)  
[ isless](../numeric/math/isless.html "c/numeric/math/isless")(C99) |  checks if the first floating-point argument is less than the second   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_isless&action=edit)  
[ islessequal](../numeric/math/islessequal.html "c/numeric/math/islessequal")(C99) |  checks if the first floating-point argument is less or equal than the second   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_islessequal&action=edit)  
[ islessgreater](../numeric/math/islessgreater.html "c/numeric/math/islessgreater")(C99) |  checks if the first floating-point argument is less or greater than the second   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_islessgreater&action=edit)  
[ isunordered](../numeric/math/isunordered.html "c/numeric/math/isunordered")(C99) |  checks if two floating-point values are unordered   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_isunordered&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/math&action=edit&section=4 "Edit section: Synopsis")] Synopsis

| This section is incomplete  
Reason: 

  * add synopses from B.11 Mathematics <math.h>
  * place obligatory and optional parts in different sections 

  
---|---  
      
    
    #define __STDC_VERSION_MATH_H__ 202311L
    // TODO: ...

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/math&oldid=180107](https://en.cppreference.com/mwiki/index.php?title=c/header/math&oldid=180107)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



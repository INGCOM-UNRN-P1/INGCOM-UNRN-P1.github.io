From cppreference.com

< [c](../../c.html "c")‎ | [symbol index](../index.html "c/symbol index")

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

  
This page tries to list all the macro symbols that are available from the _Standard Library_. The symbols are written as follows: 

  * Function-like macro names with `()`. 
  * [Type-generic macro](../numeric/tgmath.html "c/numeric/tgmath") names marked with (generic). 



## Contents

  * [1 _ A B C D E F H I K L M N O P R S T U V W X](macro.html#A_B_C_D_E_F_H_I_K_L_M_N_O_P_R_S_T_U_V_W_X)
    * [1.1 _ (underscore)](macro.html#.28underscore.29)
    * [1.2 A](macro.html#A)
    * [1.3 B](macro.html#B)
    * [1.4 C](macro.html#C)
    * [1.5 D](macro.html#D)
    * [1.6 E](macro.html#E)
    * [1.7 F](macro.html#F)
    * [1.8 H](macro.html#H)
    * [1.9 I](macro.html#I)
    * [1.10 K](macro.html#K)
    * [1.11 L](macro.html#L)
    * [1.12 M](macro.html#M)
    * [1.13 N](macro.html#N)
    * [1.14 O](macro.html#O)
    * [1.15 P](macro.html#P)
    * [1.16 R](macro.html#R)
    * [1.17 S](macro.html#S)
    * [1.18 T](macro.html#T)
    * [1.19 U](macro.html#U)
    * [1.20 V](macro.html#V)
    * [1.21 W](macro.html#W)
    * [1.22 X](macro.html#X)
    * [1.23 See also](macro.html#See_also)

  
---  
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=1 "Edit section: A B C D E F H I K L M N O P R S T U V W X")]

> `[_](macro.html#.28underscore.29) [ A](macro.html#A) [ B](macro.html#B) [ C](macro.html#C) [ D](macro.html#D) [ E](macro.html#E) [ F](macro.html#F) [ H](macro.html#H) [ I](macro.html#I) [ K](macro.html#K) [ L](macro.html#L) [ M](macro.html#M) [ N](macro.html#N) [ O](macro.html#O) [ P](macro.html#P) [ R](macro.html#R) [ S](macro.html#S) [ T](macro.html#T) [ U](macro.html#U) [ V](macro.html#V) [ W](macro.html#W) [ X](macro.html#X) `

  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=2 "Edit section: \(underscore\)")] _ (underscore)

[`__alignas_is_defined`](../types.html "c/types") (since C11)  
[`__alignof_is_defined`](../types.html "c/types") (since C11)  
[`__bool_true_false_are_defined`](../types.html "c/types") (since C99)  
[`_Complex_I`](../numeric/complex.html "c/numeric/complex") (since C99)  
[`_Imaginary_I`](../numeric/complex.html "c/numeric/complex") (since C99)  
[`_IOFBF`](../io.html "c/io")  
[`_IOLBF`](../io.html "c/io")  
[`_IONBF`](../io.html "c/io")  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=3 "Edit section: A")] A

[`acos()`](../numeric/math/acos.html "c/numeric/math/acos") (generic) (since C99)  
[`acosh()`](../numeric/math/acosh.html "c/numeric/math/acosh") (generic) (since C99)  
[`alignas`](../types.html "c/types") (keyword macro) (since C11)  
[`alignof`](../types.html "c/types") (keyword macro) (since C11)  
[`and`](../language/operator_alternative.html "c/language/operator alternative") (operator macro) (since C95)  
[`and_eq`](../language/operator_alternative.html "c/language/operator alternative") (operator macro) (since C95)  
[`asin()`](../numeric/math/asin.html "c/numeric/math/asin") (generic) (since C99)  
[`asinh()`](../numeric/math/asinh.html "c/numeric/math/asinh") (generic) (since C99)  
[`assert()`](../error/assert.html "c/error/assert")  
[`atan()`](../numeric/math/atan.html "c/numeric/math/atan") (generic) (since C99)  
[`atan2()`](../numeric/math/atan2.html "c/numeric/math/atan2") (generic) (since C99)  
[`atanh()`](../numeric/math/atanh.html "c/numeric/math/atanh") (generic) (since C99)  


`ATOMIC__TYPE_ _LOCK_FREE`  
---  
[`ATOMIC_BOOL_LOCK_FREE`](../atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts") (since C11)  
[`ATOMIC_CHAR_LOCK_FREE`](../atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts") (since C11)  
[`ATOMIC_CHAR16_T_LOCK_FREE`](../atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts") (since C11)  
[`ATOMIC_CHAR32_T_LOCK_FREE`](../atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts") (since C11)  
[`ATOMIC_INT_LOCK_FREE`](../atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts") (since C11)  
[`ATOMIC_LONG_LOCK_FREE`](../atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts") (since C11)  
[`ATOMIC_POINTER_LOCK_FREE`](../atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts") (since C11)  
[`ATOMIC_LLONG_LOCK_FREE`](../atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts") (since C11)  
[`ATOMIC_SHORT_LOCK_FREE`](../atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts") (since C11)  
[`ATOMIC_WCHAR_T_LOCK_FREE`](../atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts") (since C11)  
  
  
[`ATOMIC_FLAG_INIT`](../atomic/ATOMIC_FLAG_INIT.html "c/atomic/ATOMIC FLAG INIT") (since C11)  
[`ATOMIC_VAR_INIT()`](../atomic/ATOMIC_VAR_INIT.html "c/atomic/ATOMIC VAR INIT") (since C11)(deprecated in C17)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=4 "Edit section: B")] B

[`bitand`](../language/operator_alternative.html "c/language/operator alternative") (operator macro) (since C95)  
[`bitor`](../language/operator_alternative.html "c/language/operator alternative") (operator macro) (since C95)  
[`bool`](../types.html "c/types") (keyword macro) (since C99)  
[`BOOL_WIDTH`](../types/limits.html "c/types/limits") (since C23)  
[`BUFSIZ`](../io.html "c/io")  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=5 "Edit section: C")] C

[`carg()`](../numeric/complex/carg.html "c/numeric/complex/carg") (generic) (since C99)  
[`cbrt()`](../numeric/math/cbrt.html "c/numeric/math/cbrt") (generic) (since C99)  
[`ceil()`](../numeric/math/ceil.html "c/numeric/math/ceil") (generic) (since C99)  
[`CHAR_BIT`](../types/limits.html "c/types/limits")  
[`CHAR_MAX`](../types/limits.html "c/types/limits")  
[`CHAR_MIN`](../types/limits.html "c/types/limits")  
[`CHAR_WIDTH`](../types/limits.html "c/types/limits") (since C23)  
[`cimag()`](../numeric/complex/cimag.html "c/numeric/complex/cimag") (generic) (since C99)  
[`CLOCKS_PER_SEC`](../chrono/CLOCKS_PER_SEC.html "c/chrono/CLOCKS PER SEC")  
[`CMPLX()`](../numeric/complex/CMPLX.html "c/numeric/complex/CMPLX") (since C11)  
[`CMPLXF()`](../numeric/complex/CMPLX.html "c/numeric/complex/CMPLX") (since C11)  
[`CMPLXL()`](../numeric/complex/CMPLX.html "c/numeric/complex/CMPLX") (since C11)  
[`compl`](../language/operator_alternative.html "c/language/operator alternative") (operator macro) (since C95)  
[`complex`](../numeric/complex/complex.html "c/numeric/complex/complex") (keyword macro) (since C99)  
[`conj()`](../numeric/complex/conj.html "c/numeric/complex/conj") (generic) (since C99)  
[`copysign()`](../numeric/math/copysign.html "c/numeric/math/copysign") (generic) (since C99)  
[`cos()`](../numeric/math/cos.html "c/numeric/math/cos") (generic) (since C99)  
[`cosh()`](../numeric/math/cosh.html "c/numeric/math/cosh") (generic) (since C99)  
[`cproj()`](../numeric/complex/cproj.html "c/numeric/complex/cproj") (generic) (since C99)  
[`creal()`](../numeric/complex/creal.html "c/numeric/complex/creal") (generic) (since C99)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=6 "Edit section: D")] D

[`DBL_DECIMAL_DIG`](../types/limits.html "c/types/limits") (since C11)  
[`DBL_DIG`](../types/limits.html "c/types/limits")  
[`DBL_EPSILON`](../types/limits.html "c/types/limits")  
[`DBL_HAS_SUBNORM`](../types/limits.html "c/types/limits") (since C11)  
[`DBL_MANT_DIG`](../types/limits.html "c/types/limits")  
[`DBL_MAX`](../types/limits.html "c/types/limits")  
[`DBL_MAX_10_EXP`](../types/limits.html "c/types/limits")  
[`DBL_MAX_EXP`](../types/limits.html "c/types/limits")  
[`DBL_MIN`](../types/limits.html "c/types/limits")  
[`DBL_MIN_10_EXP`](../types/limits.html "c/types/limits")  
[`DBL_MIN_EXP`](../types/limits.html "c/types/limits")  
[`DBL_TRUE_MIN`](../types/limits.html "c/types/limits") (since C11)  
[`DECIMAL_DIG`](../types/limits.html "c/types/limits") (since C99)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=7 "Edit section: E")] E

[`EDOM`](../error/errno_macros.html "c/error/errno macros")  
[`EILSEQ`](../error/errno_macros.html "c/error/errno macros") (since C95)  
[`EOF`](../io.html "c/io")  
[`ERANGE`](../error/errno_macros.html "c/error/errno macros")  
[`erf()`](../numeric/math/erf.html "c/numeric/math/erf") (generic) (since C99)  
[`erfc()`](../numeric/math/erfc.html "c/numeric/math/erfc") (generic) (since C99)  
[`errno`](../error/errno.html "c/error/errno") (macro variable)  
[`EXIT_FAILURE`](../program/EXIT_status.html "c/program/EXIT status")  
[`EXIT_SUCCESS`](../program/EXIT_status.html "c/program/EXIT status")  
[`exp()`](../numeric/math/exp.html "c/numeric/math/exp") (generic) (since C99)  
[`exp2()`](../numeric/math/exp2.html "c/numeric/math/exp2") (generic) (since C99)  
[`expm1()`](../numeric/math/expm1.html "c/numeric/math/expm1") (generic) (since C99)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=8 "Edit section: F")] F

[`fabs()`](../numeric/math/fabs.html "c/numeric/math/fabs") (generic) (since C99)  
[`false`](../types.html "c/types") (since C99)  
[`fdim()`](../numeric/math/fdim.html "c/numeric/math/fdim") (generic) (since C99)  
[`FE_ALL_EXCEPT`](../numeric/fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") (since C99)  
[`FE_DFL_ENV`](../numeric/fenv/FE_DFL_ENV.html "c/numeric/fenv/FE DFL ENV") (since C99)  
[`FE_DIVBYZERO`](../numeric/fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") (since C99)  
[`FE_DOWNWARD`](../numeric/fenv/FE_round.html "c/numeric/fenv/FE round") (since C99)  
[`FE_INEXACT`](../numeric/fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") (since C99)  
[`FE_INVALID`](../numeric/fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") (since C99)  
[`FE_OVERFLOW`](../numeric/fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") (since C99)  
[`FE_TONEAREST`](../numeric/fenv/FE_round.html "c/numeric/fenv/FE round") (since C99)  
[`FE_TOWARDZERO`](../numeric/fenv/FE_round.html "c/numeric/fenv/FE round") (since C99)  
[`FE_UNDERFLOW`](../numeric/fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") (since C99)  
[`FE_UPWARD`](../numeric/fenv/FE_round.html "c/numeric/fenv/FE round") (since C99)  
[`FILENAME_MAX`](../io.html "c/io")  
[`floor()`](../numeric/math/floor.html "c/numeric/math/floor") (generic) (since C99)  
[`FLT_DECIMAL_DIG`](../types/limits.html "c/types/limits") (since C11)  
[`FLT_DIG`](../types/limits.html "c/types/limits")  
[`FLT_EPSILON`](../types/limits.html "c/types/limits")  
[`FLT_EVAL_METHOD`](../types/limits/FLT_EVAL_METHOD.html "c/types/limits/FLT EVAL METHOD") (since C99)  
[`FLT_HAS_SUBNORM`](../types/limits.html "c/types/limits") (since C11)  
[`FLT_MANT_DIG`](../types/limits.html "c/types/limits")  
[`FLT_MAX`](../types/limits.html "c/types/limits")  
[`FLT_MAX_10_EXP`](../types/limits.html "c/types/limits")  
[`FLT_MAX_EXP`](../types/limits.html "c/types/limits")  
[`FLT_MIN`](../types/limits.html "c/types/limits")  
[`FLT_MIN_10_EXP`](../types/limits.html "c/types/limits")  
[`FLT_MIN_EXP`](../types/limits.html "c/types/limits")  
[`FLT_RADIX`](../types/limits.html "c/types/limits")  
[`FLT_ROUNDS`](../types/limits/FLT_ROUNDS.html "c/types/limits/FLT ROUNDS")  
[`FLT_TRUE_MIN`](../types/limits.html "c/types/limits") (since C11)  
[`fma()`](../numeric/math/fma.html "c/numeric/math/fma") (generic) (since C99)  
[`fmax()`](../numeric/math/fmax.html "c/numeric/math/fmax") (generic) (since C99)  
[`fmin()`](../numeric/math/fmin.html "c/numeric/math/fmin") (generic) (since C99)  
[`fmod()`](../numeric/math/fmod.html "c/numeric/math/fmod") (generic) (since C99)  
[`FOPEN_MAX`](../io.html "c/io")  
[`FP_FAST_FMA`](../numeric/math/fma.html "c/numeric/math/fma") (since C99)  
[`FP_FAST_FMAF`](../numeric/math/fma.html "c/numeric/math/fma") (since C99)  
[`FP_FAST_FMAL`](../numeric/math/fma.html "c/numeric/math/fma") (since C99)  
[`FP_ILOGB0`](../numeric/math/ilogb.html "c/numeric/math/ilogb") (since C99)  
[`FP_ILOGBNAN`](../numeric/math/ilogb.html "c/numeric/math/ilogb") (since C99)  
[`FP_INFINITE`](../numeric/math/FP_categories.html "c/numeric/math/FP categories") (since C99)  
[`FP_NAN`](../numeric/math/FP_categories.html "c/numeric/math/FP categories") (since C99)  
[`FP_NORMAL`](../numeric/math/FP_categories.html "c/numeric/math/FP categories") (since C99)  
[`FP_SUBNORMAL`](../numeric/math/FP_categories.html "c/numeric/math/FP categories") (since C99)  
[`FP_ZERO`](../numeric/math/FP_categories.html "c/numeric/math/FP categories") (since C99)  
[`fpclassify()`](../numeric/math/fpclassify.html "c/numeric/math/fpclassify") (since C99)  
[`frexp()`](../numeric/math/frexp.html "c/numeric/math/frexp") (generic) (since C99)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=9 "Edit section: H")] H

[`HUGE_VAL`](../numeric/math/HUGE_VALL.html "c/numeric/math/HUGE VAL")  
[`HUGE_VALF`](../numeric/math/HUGE_VALL.html "c/numeric/math/HUGE VAL") (since C99)  
[`HUGE_VALL`](../numeric/math/HUGE_VALL.html "c/numeric/math/HUGE VAL") (since C99)  
[`hypot()`](../numeric/math/hypot.html "c/numeric/math/hypot") (generic) (since C99)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=10 "Edit section: I")] I

[`I`](../numeric/complex/I.html "c/numeric/complex/I") (since C99)  
[`ilogb()`](../numeric/math/ilogb.html "c/numeric/math/ilogb") (generic) (since C99)  
[`imaginary`](../numeric/complex/imaginary.html "c/numeric/complex/imaginary") (keyword macro) (since C99)  
[`INFINITY`](../numeric/math/INFINITY.html "c/numeric/math/INFINITY") (since C99)  


`INT _WIDTH_ _MAX`  
---  
[`INT_FAST16_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`INT_FAST32_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`INT_FAST64_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`INT_FAST8_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`INT_LEAST16_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`INT_LEAST32_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`INT_LEAST64_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`INT_LEAST8_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`INT16_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`INT32_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`INT64_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`INT8_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`INTMAX_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`INTPTR_MAX`](../types/integer.html "c/types/integer") (since C99)  
  
  
`INT _WIDTH_ _MIN`  
---  
[`INT_FAST16_MIN`](../types/integer.html "c/types/integer") (since C99)  
[`INT_FAST32_MIN`](../types/integer.html "c/types/integer") (since C99)  
[`INT_FAST64_MIN`](../types/integer.html "c/types/integer") (since C99)  
[`INT_FAST8_MIN`](../types/integer.html "c/types/integer") (since C99)  
[`INT_LEAST16_MIN`](../types/integer.html "c/types/integer") (since C99)  
[`INT_LEAST32_MIN`](../types/integer.html "c/types/integer") (since C99)  
[`INT_LEAST64_MIN`](../types/integer.html "c/types/integer") (since C99)  
[`INT_LEAST8_MIN`](../types/integer.html "c/types/integer") (since C99)  
[`INT16_MIN`](../types/integer.html "c/types/integer") (since C99)  
[`INT32_MIN`](../types/integer.html "c/types/integer") (since C99)  
[`INT64_MIN`](../types/integer.html "c/types/integer") (since C99)  
[`INT8_MIN`](../types/integer.html "c/types/integer") (since C99)  
[`INTMAX_MIN`](../types/integer.html "c/types/integer") (since C99)  
[`INTPTR_MIN`](../types/integer.html "c/types/integer") (since C99)  
  
  
`INT _WIDTH_ _WIDTH`  
---  
[`INT_FAST16_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`INT_FAST32_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`INT_FAST64_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`INT_FAST8_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`INT_LEAST16_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`INT_LEAST32_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`INT_LEAST64_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`INT_LEAST8_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`INT16_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`INT32_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`INT64_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`INT8_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`INTMAX_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`INTPTR_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
  
  
[`INT_MAX`](../types/limits.html "c/types/limits")  
[`INT_MIN`](../types/limits.html "c/types/limits")  
[`INT_WIDTH`](../types/limits.html "c/types/limits") (since C23)  
[`INT16_C()`](../types/integer.html "c/types/integer") (since C99)  
[`INT32_C()`](../types/integer.html "c/types/integer") (since C99)  
[`INT64_C()`](../types/integer.html "c/types/integer") (since C99)  
[`INT8_C()`](../types/integer.html "c/types/integer") (since C99)  
[`INTMAX_C()`](../types/integer.html "c/types/integer") (since C99)  
[`isfinite()`](../numeric/math/isfinite.html "c/numeric/math/isfinite") (since C99)  
[`isgreater()`](../numeric/math/isgreater.html "c/numeric/math/isgreater") (since C99)  
[`isgreaterequal()`](../numeric/math/isgreaterequal.html "c/numeric/math/isgreaterequal") (since C99)  
[`isinf()`](../numeric/math/isinf.html "c/numeric/math/isinf") (since C99)  
[`isless()`](../numeric/math/isless.html "c/numeric/math/isless") (since C99)  
[`islessequal()`](../numeric/math/islessequal.html "c/numeric/math/islessequal") (since C99)  
[`islessgreater()`](../numeric/math/islessgreater.html "c/numeric/math/islessgreater") (since C99)  
[`isnan()`](../numeric/math/isnan.html "c/numeric/math/isnan") (since C99)  
[`isnormal()`](../numeric/math/isnormal.html "c/numeric/math/isnormal") (since C99)  
[`isunordered()`](../numeric/math/isunordered.html "c/numeric/math/isunordered") (since C99)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=11 "Edit section: K")] K

[`kill_dependency()`](../atomic/kill_dependency.html "c/atomic/kill dependency") (since C11)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=12 "Edit section: L")] L

[`L_tmpnam`](../io.html "c/io")  
[`L_tmpnam_s`](../io.html "c/io") (since C11)  
[`LC_ALL`](../locale/LC_categories.html "c/locale/LC categories")  
[`LC_COLLATE`](../locale/LC_categories.html "c/locale/LC categories")  
[`LC_CTYPE`](../locale/LC_categories.html "c/locale/LC categories")  
[`LC_MONETARY`](../locale/LC_categories.html "c/locale/LC categories")  
[`LC_NUMERIC`](../locale/LC_categories.html "c/locale/LC categories")  
[`LC_TIME`](../locale/LC_categories.html "c/locale/LC categories")  
[`LDBL_DECIMAL_DIG`](../types/limits.html "c/types/limits") (since C11)  
[`LDBL_DIG`](../types/limits.html "c/types/limits")  
[`LDBL_EPSILON`](../types/limits.html "c/types/limits")  
[`LDBL_HAS_SUBNORM`](../types/limits.html "c/types/limits") (since C11)  
[`LDBL_MANT_DIG`](../types/limits.html "c/types/limits")  
[`LDBL_MAX`](../types/limits.html "c/types/limits")  
[`LDBL_MAX_10_EXP`](../types/limits.html "c/types/limits")  
[`LDBL_MAX_EXP`](../types/limits.html "c/types/limits")  
[`LDBL_MIN`](../types/limits.html "c/types/limits")  
[`LDBL_MIN_10_EXP`](../types/limits.html "c/types/limits")  
[`LDBL_MIN_EXP`](../types/limits.html "c/types/limits")  
[`LDBL_TRUE_MIN`](../types/limits.html "c/types/limits") (since C11)  
[`ldexp()`](../numeric/math/ldexp.html "c/numeric/math/ldexp") (generic) (since C99)  
[`lgamma()`](../numeric/math/lgamma.html "c/numeric/math/lgamma") (generic) (since C99)  
[`LLONG_MAX`](../types/limits.html "c/types/limits") (since C99)  
[`LLONG_MIN`](../types/limits.html "c/types/limits") (since C99)  
[`LLONG_WIDTH`](../types/limits.html "c/types/limits") (since C23)  
[`llrint()`](../numeric/math/rint.html "c/numeric/math/rint") (generic) (since C99)  
[`llround()`](../numeric/math/round.html "c/numeric/math/round") (generic) (since C99)  
[`log()`](../numeric/math/log.html "c/numeric/math/log") (generic) (since C99)  
[`log10()`](../numeric/math/log10.html "c/numeric/math/log10") (generic) (since C99)  
[`log1p()`](../numeric/math/log1p.html "c/numeric/math/log1p") (generic) (since C99)  
[`log2()`](../numeric/math/log2.html "c/numeric/math/log2") (generic) (since C99)  
[`logb()`](../numeric/math/logb.html "c/numeric/math/logb") (generic) (since C99)  
[`LONG_MAX`](../types/limits.html "c/types/limits")  
[`LONG_MIN`](../types/limits.html "c/types/limits")  
[`LONG_WIDTH`](../types/limits.html "c/types/limits") (since C23)  
[`lrint()`](../numeric/math/rint.html "c/numeric/math/rint") (generic) (since C99)  
[`lround()`](../numeric/math/round.html "c/numeric/math/round") (generic) (since C99)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=13 "Edit section: M")] M

[`MATH_ERREXCEPT`](../numeric/math/math_errhandling.html "c/numeric/math/math errhandling") (since C99)  
[`math_errhandling`](../numeric/math/math_errhandling.html "c/numeric/math/math errhandling") (since C99)  
[`MATH_ERRNO`](../numeric/math/math_errhandling.html "c/numeric/math/math errhandling") (since C99)  
[`MB_CUR_MAX`](../string/multibyte.html "c/string/multibyte") (macro variable)  
[`MB_LEN_MAX`](../string/multibyte.html "c/string/multibyte")  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=14 "Edit section: N")] N

[`NAN`](../numeric/math/NAN.html "c/numeric/math/NAN") (since C99)  
[`nearbyint()`](../numeric/math/nearbyint.html "c/numeric/math/nearbyint") (generic) (since C99)  
[`nextafter()`](../numeric/math/nexttoward.html "c/numeric/math/nextafter") (generic) (since C99)  
[`nexttoward()`](../numeric/math/nexttoward.html "c/numeric/math/nexttoward") (generic) (since C99)  
[`noreturn`](../types.html "c/types") (keyword macro) (since C11)  
[`not`](../language/operator_alternative.html "c/language/operator alternative") (operator macro) (since C95)  
[`not_eq`](../language/operator_alternative.html "c/language/operator alternative") (operator macro) (since C95)  
[`NULL`](../types/NULL.html "c/types/NULL")  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=15 "Edit section: O")] O

[`offsetof()`](../types/offsetof.html "c/types/offsetof")  
[`ONCE_FLAG_INIT`](../thread/ONCE_FLAG_INIT.html "c/thread/call once") (since C11)  
[`or`](../language/operator_alternative.html "c/language/operator alternative") (operator macro) (since C95)  
[`or_eq`](../language/operator_alternative.html "c/language/operator alternative") (operator macro) (since C95)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=16 "Edit section: P")] P

[`pow()`](../numeric/math/pow.html "c/numeric/math/pow") (generic) (since C99)  


`PRI{d i o u x X}_WIDTH_ ` (macro string)  
---  
[`PRId16`](../types/integer.html "c/types/integer") (since C99)  
[`PRId32`](../types/integer.html "c/types/integer") (since C99)  
[`PRId64`](../types/integer.html "c/types/integer") (since C99)  
[`PRId8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIdFAST16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIdFAST32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIdFAST64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIdFAST8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIdLEAST16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIdLEAST32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIdLEAST64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIdLEAST8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIdMAX`](../types/integer.html "c/types/integer") (since C99)  
[`PRIdPTR`](../types/integer.html "c/types/integer") (since C99)  
[`PRIi16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIi32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIi64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIi8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIiFAST16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIiFAST32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIiFAST64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIiFAST8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIiLEAST16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIiLEAST32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIiLEAST64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIiLEAST8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIiMAX`](../types/integer.html "c/types/integer") (since C99)  
[`PRIiPTR`](../types/integer.html "c/types/integer") (since C99)  
[`PRIo16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIo32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIo64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIo8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIoFAST16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIoFAST32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIoFAST64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIoFAST8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIoLEAST16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIoLEAST32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIoLEAST64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIoLEAST8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIoMAX`](../types/integer.html "c/types/integer") (since C99)  
[`PRIoPTR`](../types/integer.html "c/types/integer") (since C99)  
[`PRIu16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIu32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIu64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIu8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIuFAST16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIuFAST32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIuFAST64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIuFAST8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIuLEAST16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIuLEAST32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIuLEAST64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIuLEAST8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIuMAX`](../types/integer.html "c/types/integer") (since C99)  
[`PRIuPTR`](../types/integer.html "c/types/integer") (since C99)  
[`PRIx16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIX16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIx32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIX32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIx64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIX64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIx8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIX8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIxFAST16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIXFAST16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIxFAST32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIXFAST32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIxFAST64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIXFAST64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIxFAST8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIXFAST8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIxLEAST16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIXLEAST16`](../types/integer.html "c/types/integer") (since C99)  
[`PRIxLEAST32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIXLEAST32`](../types/integer.html "c/types/integer") (since C99)  
[`PRIxLEAST64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIXLEAST64`](../types/integer.html "c/types/integer") (since C99)  
[`PRIxLEAST8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIXLEAST8`](../types/integer.html "c/types/integer") (since C99)  
[`PRIxMAX`](../types/integer.html "c/types/integer") (since C99)  
[`PRIXMAX`](../types/integer.html "c/types/integer") (since C99)  
[`PRIxPTR`](../types/integer.html "c/types/integer") (since C99)  
[`PRIXPTR`](../types/integer.html "c/types/integer") (since C99)  
  
  
[`PTRDIFF_MAX`](../types/limits.html "c/types/limits") (since C99)  
[`PTRDIFF_MIN`](../types/limits.html "c/types/limits") (since C99)  
[`PTRDIFF_WIDTH`](../types/limits.html "c/types/limits") (since C23)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=17 "Edit section: R")] R

[`RAND_MAX`](../numeric/random/RAND_MAX.html "c/numeric/random/RAND MAX")  
[`remainder()`](../numeric/math/remainder.html "c/numeric/math/remainder") (generic) (since C99)  
[`remquo()`](../numeric/math/remquo.html "c/numeric/math/remquo") (generic) (since C99)  
[`rint()`](../numeric/math/rint.html "c/numeric/math/rint") (generic) (since C99)  
[`round()`](../numeric/math/round.html "c/numeric/math/round") (generic) (since C99)  
[`RSIZE_MAX`](../error.html "c/error") (macro variable) (since C11)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=18 "Edit section: S")] S

[`scalbln()`](../numeric/math/scalbn.html "c/numeric/math/scalbn") (generic) (since C99)  
[`scalbn()`](../numeric/math/scalbn.html "c/numeric/math/scalbn") (generic) (since C99)  
[`SCHAR_MAX`](../types/limits.html "c/types/limits")  
[`SCHAR_MIN`](../types/limits.html "c/types/limits")  
[`SCHAR_WIDTH`](../types/limits.html "c/types/limits") (since C23)  


`SCN{d i o u x}_WIDTH_ ` (macro string)  
---  
[`SCNd16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNd32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNd64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNd8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNdFAST16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNdFAST32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNdFAST64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNdFAST8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNdLEAST16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNdLEAST32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNdLEAST64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNdLEAST8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNdMAX`](../types/integer.html "c/types/integer") (since C99)  
[`SCNdPTR`](../types/integer.html "c/types/integer") (since C99)  
[`SCNi16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNi32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNi64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNi8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNiFAST16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNiFAST32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNiFAST64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNiFAST8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNiLEAST16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNiLEAST32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNiLEAST64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNiLEAST8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNiMAX`](../types/integer.html "c/types/integer") (since C99)  
[`SCNiPTR`](../types/integer.html "c/types/integer") (since C99)  
[`SCNo16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNo32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNo64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNo8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNoFAST16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNoFAST32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNoFAST64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNoFAST8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNoLEAST16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNoLEAST32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNoLEAST64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNoLEAST8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNoMAX`](../types/integer.html "c/types/integer") (since C99)  
[`SCNoPTR`](../types/integer.html "c/types/integer") (since C99)  
[`SCNu16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNu32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNu64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNu8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNuFAST16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNuFAST32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNuFAST64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNuFAST8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNuLEAST16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNuLEAST32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNuLEAST64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNuLEAST8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNuMAX`](../types/integer.html "c/types/integer") (since C99)  
[`SCNuPTR`](../types/integer.html "c/types/integer") (since C99)  
[`SCNx16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNx32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNx64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNx8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNxFAST16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNxFAST32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNxFAST64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNxFAST8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNxLEAST16`](../types/integer.html "c/types/integer") (since C99)  
[`SCNxLEAST32`](../types/integer.html "c/types/integer") (since C99)  
[`SCNxLEAST64`](../types/integer.html "c/types/integer") (since C99)  
[`SCNxLEAST8`](../types/integer.html "c/types/integer") (since C99)  
[`SCNxMAX`](../types/integer.html "c/types/integer") (since C99)  
[`SCNxPTR`](../types/integer.html "c/types/integer") (since C99)  
  
  
[`SEEK_CUR`](../io.html "c/io")  
[`SEEK_END`](../io.html "c/io")  
[`SEEK_SET`](../io.html "c/io")  
[`setjmp()`](../program/setjmp.html "c/program/setjmp")  
[`SHRT_MAX`](../types/limits.html "c/types/limits")  
[`SHRT_MIN`](../types/limits.html "c/types/limits")  
[`SHRT_WIDTH`](../types/limits.html "c/types/limits") (since C23)  
[`SIG_ATOMIC_MAX`](../types/limits.html "c/types/limits") (since C99)  
[`SIG_ATOMIC_MIN`](../types/limits.html "c/types/limits") (since C99)  
[`SIG_ATOMIC_WIDTH`](../types/limits.html "c/types/limits") (since C23)  
[`SIG_DFL`](../program/SIG_strategies.html "c/program/SIG strategies")  
[`SIG_ERR`](../program/SIG_ERR.html "c/program/SIG ERR")  
[`SIG_IGN`](../program/SIG_strategies.html "c/program/SIG strategies")  
[`SIGABRT`](../program/SIG_types.html "c/program/SIG types")  
[`SIGFPE`](../program/SIG_types.html "c/program/SIG types")  
[`SIGILL`](../program/SIG_types.html "c/program/SIG types")  
[`SIGINT`](../program/SIG_types.html "c/program/SIG types")  
[`signbit()`](../numeric/math/signbit.html "c/numeric/math/signbit") (since C99)  
[`SIGSEGV`](../program/SIG_types.html "c/program/SIG types")  
[`SIGTERM`](../program/SIG_types.html "c/program/SIG types")  
[`sin()`](../numeric/math/sin.html "c/numeric/math/sin") (generic) (since C99)  
[`sinh()`](../numeric/math/sinh.html "c/numeric/math/sinh") (generic) (since C99)  
[`SIZE_MAX`](../types/limits.html "c/types/limits") (since C99)  
[`SIZE_WIDTH`](../types/limits.html "c/types/limits") (since C23)  
[`sqrt()`](../numeric/math/sqrt.html "c/numeric/math/sqrt") (generic) (since C99)  
[`static_assert`](../error/static_assert.html "c/error/static assert") (keyword macro) (since C11)  
[`stderr`](../io/std_streams.html "c/io/std streams")  
[`stdin`](../io/std_streams.html "c/io/std streams")  
[`stdout`](../io/std_streams.html "c/io/std streams")  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=19 "Edit section: T")] T

[`tan()`](../numeric/math/tan.html "c/numeric/math/tan") (generic) (since C99)  
[`tanh()`](../numeric/math/tanh.html "c/numeric/math/tanh") (generic) (since C99)  
[`tgamma()`](../numeric/math/tgamma.html "c/numeric/math/tgamma") (generic) (since C99)  
[`thread_local`](../thread.html "c/thread") (keyword macro) (since C11)  
[`TIME_UTC`](../chrono/timespec_get.html "c/chrono/timespec get") (since C11)  
[`TMP_MAX`](../io.html "c/io")  
[`TMP_MAX_S`](../io.html "c/io") (since C11)  
[`true`](../types.html "c/types") (since C99)  
[`trunc()`](../numeric/math/trunc.html "c/numeric/math/trunc") (generic) (since C99)  
[`TSS_DTOR_ITERATIONS`](../thread/TSS_DTOR_ITERATIONS.html "c/thread/TSS DTOR ITERATIONS") (since C11)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=20 "Edit section: U")] U

[`UCHAR_MAX`](../types/limits.html "c/types/limits")  
[`UCHAR_WIDTH`](../types/limits.html "c/types/limits") (since C23)  


`UINT _WIDTH_ _MAX`  
---  
[`UINT_FAST16_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`UINT_FAST32_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`UINT_FAST64_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`UINT_FAST8_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`UINT_LEAST16_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`UINT_LEAST32_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`UINT_LEAST64_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`UINT_LEAST8_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`UINT16_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`UINT32_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`UINT64_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`UINT8_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`UINTMAX_MAX`](../types/integer.html "c/types/integer") (since C99)  
[`UINTPTR_MAX`](../types/integer.html "c/types/integer") (since C99)  
  
  
`UINT _WIDTH_ _WIDTH`  
---  
[`UINT_FAST16_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`UINT_FAST32_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`UINT_FAST64_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`UINT_FAST8_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`UINT_LEAST16_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`UINT_LEAST32_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`UINT_LEAST64_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`UINT_LEAST8_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`UINT16_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`UINT32_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`UINT64_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`UINT8_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`UINTMAX_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
[`UINTPTR_WIDTH`](../types/integer.html "c/types/integer") (since C23)  
  
  
[`UINT_MAX`](../types/limits.html "c/types/limits")  
[`UINT_WIDTH`](../types/limits.html "c/types/limits") (since C23)  
[`UINT16_C()`](../types/integer.html "c/types/integer") (since C99)  
[`UINT32_C()`](../types/integer.html "c/types/integer") (since C99)  
[`UINT64_C()`](../types/integer.html "c/types/integer") (since C99)  
[`UINT8_C()`](../types/integer.html "c/types/integer") (since C99)  
[`UINTMAX_C()`](../types/integer.html "c/types/integer") (since C99)  
[`ULLONG_MAX`](../types/limits.html "c/types/limits") (since C99)  
[`ULLONG_WIDTH`](../types/limits.html "c/types/limits") (since C23)  
[`ULONG_MAX`](../types/limits.html "c/types/limits")  
[`ULONG_WIDTH`](../types/limits.html "c/types/limits") (since C23)  
[`USHRT_MAX`](../types/limits.html "c/types/limits")  
[`USHRT_WIDTH`](../types/limits.html "c/types/limits") (since C23)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=21 "Edit section: V")] V

[`va_arg()`](../variadic/va_arg.html "c/variadic/va arg")  
[`va_copy()`](../variadic/va_copy.html "c/variadic/va copy") (since C99)  
[`va_end()`](../variadic/va_end.html "c/variadic/va end")  
[`va_list`](../variadic/va_list.html "c/variadic/va list")  
[`va_start()`](../variadic/va_start.html "c/variadic/va start")  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=22 "Edit section: W")] W

[`WCHAR_MAX`](../types/limits.html "c/types/limits") (since C99)  
[`WCHAR_MIN`](../types/limits.html "c/types/limits") (since C99)  
[`WCHAR_WIDTH`](../types/limits.html "c/types/limits") (since C23)  
[`WEOF`](../string/wide.html "c/string/wide") (since C95)  
[`WINT_MAX`](../types/limits.html "c/types/limits") (since C99)  
[`WINT_MIN`](../types/limits.html "c/types/limits") (since C99)  
[`WINT_WIDTH`](../types/limits.html "c/types/limits") (since C23)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=23 "Edit section: X")] X

[`xor`](../language/operator_alternative.html "c/language/operator alternative") (operator macro) (since C95)  
[`xor_eq`](../language/operator_alternative.html "c/language/operator alternative") (operator macro) (since C95)  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&action=edit&section=24 "Edit section: See also")] See also

[C++ documentation](../../cpp/symbol_index/macro.html "cpp/symbol index/macro") for Macro Symbol Index  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&oldid=130989](https://en.cppreference.com/mwiki/index.php?title=c/symbol_index/macro&oldid=130989)" 

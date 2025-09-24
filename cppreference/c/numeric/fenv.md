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
**Floating-point environment** (C99)  
[Pseudo-random number generation](random.html "c/numeric/random")  
[Complex number arithmetic](complex.html "c/numeric/complex") (C99)  
[Type-generic math](tgmath.html "c/numeric/tgmath") (C99)  
[Bit manipulation](../numeric.html#Bit_manipulation "c/numeric") (C23)  
[Checked integer arithmetic](../numeric.html#Checked_integer_arithmetic "c/numeric") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/navbar_content&action=edit)

**Floating-point environment**

Functions  
---  
[feclearexcept](fenv/feclearexcept.html "c/numeric/fenv/feclearexcept")(C99)  
[fetestexcept](fenv/fetestexcept.html "c/numeric/fenv/fetestexcept")(C99)  
[feraiseexcept](fenv/feraiseexcept.html "c/numeric/fenv/feraiseexcept")(C99)  
[fegetexceptflagfesetexceptflag](fenv/feexceptflag.html "c/numeric/fenv/feexceptflag")(C99)(C99)  
[fegetroundfesetround](fenv/feround.html "c/numeric/fenv/feround")(C99)(C99)  
[fegetenvfesetenv](fenv/feenv.html "c/numeric/fenv/feenv")(C99)  
[feholdexcept](fenv/feholdexcept.html "c/numeric/fenv/feholdexcept")(C99)  
[feupdateenv](fenv/feupdateenv.html "c/numeric/fenv/feupdateenv")(C99)  
Macro constants  
[FE_ALL_EXCEPTFE_DIVBYZEROFE_INEXACTFE_INVALIDFE_OVERFLOWFE_UNDERFLOW](fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions")(C99)  
[FE_DOWNWARDFE_TONEARESTFE_TOWARDZEROFE_UPWARD](fenv/FE_round.html "c/numeric/fenv/FE round")(C99)  
[FE_DFL_ENV](fenv/FE_DFL_ENV.html "c/numeric/fenv/FE DFL ENV")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/navbar_content&action=edit)

The floating-point environment is the set of floating-point status flags and control modes supported by the implementation. It is thread-local, each thread inherits the initial state of its floating-point environment from the parent thread. Floating-point operations modify the floating-point status flags to indicate abnormal results or auxiliary information. The state of floating-point control modes affects the outcomes of some floating-point operations. 

The floating-point environment access and modification is only meaningful when [` #pragma STDC FENV_ACCESS`](../../cpp/preprocessor/impl.html "cpp/preprocessor/impl") is set to `ON`. Otherwise the implementation is free to assume that floating-point control modes are always the default ones and that floating-point status flags are never tested or modified. In practice, few current compilers, such as HP aCC, Oracle Studio, and IBM XL, support the #pragma explicitly, but most compilers allow meaningful access to the floating-point environment anyway. 

## Contents

  * [1 Types](fenv.html#Types)
  * [2 Functions](fenv.html#Functions)
  * [3 Macros](fenv.html#Macros)
  * [4 References](fenv.html#References)
  * [5 See also](fenv.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv&action=edit&section=1 "Edit section: Types")] Types

Defined in header `[`<fenv.h>`](../header/fenv.html "c/header/fenv")`  
---  
fenv_t |  The type representing the entire floating-point environment   
fexcept_t |  The type representing all floating-point status flags collectively   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv&action=edit&section=2 "Edit section: Functions")] Functions

[ feclearexcept](fenv/feclearexcept.html "c/numeric/fenv/feclearexcept")(C99) |  clears the specified floating-point status flags   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feclearexcept&action=edit)  
---|---  
[ fetestexcept](fenv/fetestexcept.html "c/numeric/fenv/fetestexcept")(C99) |  determines which of the specified floating-point status flags are set   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_fetestexcept&action=edit)  
[ feraiseexcept](fenv/feraiseexcept.html "c/numeric/fenv/feraiseexcept")(C99) |  raises the specified floating-point exceptions   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feraiseexcept&action=edit)  
[ fegetexceptflagfesetexceptflag](fenv/feexceptflag.html "c/numeric/fenv/feexceptflag")(C99)(C99) |  copies the state of the specified floating-point status flags from or to the floating-point environment   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feexceptflag&action=edit)  
[ fegetroundfesetround](fenv/feround.html "c/numeric/fenv/feround")(C99)(C99) |  gets or sets rounding direction   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feround&action=edit)  
[ fegetenvfesetenv](fenv/feenv.html "c/numeric/fenv/feenv")(C99) |  saves or restores the current floating-point environment   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feenv&action=edit)  
[ feholdexcept](fenv/feholdexcept.html "c/numeric/fenv/feholdexcept")(C99) |  saves the environment, clears all status flags and ignores all future errors   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feholdexcept&action=edit)  
[ feupdateenv](fenv/feupdateenv.html "c/numeric/fenv/feupdateenv")(C99) |  restores the floating-point environment and raises the previously raise exceptions   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feupdateenv&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv&action=edit&section=3 "Edit section: Macros")] Macros

[ FE_ALL_EXCEPTFE_DIVBYZEROFE_INEXACTFE_INVALIDFE_OVERFLOWFE_UNDERFLOW](fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions")(C99) |  floating-point exceptions   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_FE_exceptions&action=edit)  
---|---  
[ FE_DOWNWARDFE_TONEARESTFE_TOWARDZEROFE_UPWARD](fenv/FE_round.html "c/numeric/fenv/FE round")(C99) |  floating-point rounding direction   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_FE_round&action=edit)  
[ FE_DFL_ENV](fenv/FE_DFL_ENV.html "c/numeric/fenv/FE DFL ENV")(C99) |  default floating-point environment   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_FE_DFL_ENV&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.6 Floating-point environment <fenv.h> (p: TBD) 



    

  * 7.31.4 Floating-point environment <fenv.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.6 Floating-point environment <fenv.h> (p: 150-156) 



    

  * 7.31.4 Floating-point environment <fenv.h> (p: 332) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.6 Floating-point environment <fenv.h> (p: 206-215) 



    

  * 7.31.4 Floating-point environment <fenv.h> (p: 455) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.6 Floating-point environment <fenv.h> (p: 187-196) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv&action=edit&section=5 "Edit section: See also")] See also

[C++ documentation](../../cpp/numeric/fenv.html "cpp/numeric/fenv") for Floating-point environment  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv&oldid=180048](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv&oldid=180048)" 

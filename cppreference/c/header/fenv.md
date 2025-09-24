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
**`< fenv.h>`** (C99)  
[`<float.h>`](float.html "c/header/float")  
[`<inttypes.h>`](inttypes.html "c/header/inttypes") (C99)` `  
[`<iso646.h>`](iso646.html "c/header/iso646") (C95)  
[`<limits.h>`](limits.html "c/header/limits")  
[`<locale.h>`](locale.html "c/header/locale")  
[`<math.h>`](math.html "c/header/math")  
  
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

This header is part of the [floating-point environment](../numeric/fenv.html "c/numeric/fenv") library. 

## Contents

  * [1 Types](fenv.html#Types)
  * [2 Functions](fenv.html#Functions)
  * [3 Macros](fenv.html#Macros)
  * [4 Synopsis](fenv.html#Synopsis)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/fenv&action=edit&section=1 "Edit section: Types")] Types

Defined in header `**`< fenv.h>`**`  
---  
fenv_t |  The type representing the entire floating-point environment   
fexcept_t |  The type representing all floating-point status flags collectively   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/fenv&action=edit&section=2 "Edit section: Functions")] Functions

[ feclearexcept](../numeric/fenv/feclearexcept.html "c/numeric/fenv/feclearexcept")(C99) |  clears the specified floating-point status flags   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feclearexcept&action=edit)  
---|---  
[ fetestexcept](../numeric/fenv/fetestexcept.html "c/numeric/fenv/fetestexcept")(C99) |  determines which of the specified floating-point status flags are set   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_fetestexcept&action=edit)  
[ feraiseexcept](../numeric/fenv/feraiseexcept.html "c/numeric/fenv/feraiseexcept")(C99) |  raises the specified floating-point exceptions   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feraiseexcept&action=edit)  
[ fegetexceptflagfesetexceptflag](../numeric/fenv/feexceptflag.html "c/numeric/fenv/feexceptflag")(C99)(C99) |  copies the state of the specified floating-point status flags from or to the floating-point environment   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feexceptflag&action=edit)  
[ fegetroundfesetround](../numeric/fenv/feround.html "c/numeric/fenv/feround")(C99)(C99) |  gets or sets rounding direction   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feround&action=edit)  
[ fegetenvfesetenv](../numeric/fenv/feenv.html "c/numeric/fenv/feenv")(C99) |  saves or restores the current floating-point environment   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feenv&action=edit)  
[ feholdexcept](../numeric/fenv/feholdexcept.html "c/numeric/fenv/feholdexcept")(C99) |  saves the environment, clears all status flags and ignores all future errors   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feholdexcept&action=edit)  
[ feupdateenv](../numeric/fenv/feupdateenv.html "c/numeric/fenv/feupdateenv")(C99) |  restores the floating-point environment and raises the previously raise exceptions   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feupdateenv&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/fenv&action=edit&section=3 "Edit section: Macros")] Macros

[ FE_ALL_EXCEPTFE_DIVBYZEROFE_INEXACTFE_INVALIDFE_OVERFLOWFE_UNDERFLOW](../numeric/fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions")(C99) |  floating-point exceptions   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_FE_exceptions&action=edit)  
---|---  
[ FE_DOWNWARDFE_TONEARESTFE_TOWARDZEROFE_UPWARD](../numeric/fenv/FE_round.html "c/numeric/fenv/FE round")(C99) |  floating-point rounding direction   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_FE_round&action=edit)  
[ FE_DFL_ENV](../numeric/fenv/FE_DFL_ENV.html "c/numeric/fenv/FE DFL ENV")(C99) |  default floating-point environment   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_FE_DFL_ENV&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/fenv&action=edit&section=4 "Edit section: Synopsis")] Synopsis
    
    
    #define __STDC_VERSION_FENV_H__ 202311L
     
    #define FE_ALL_EXCEPT         /* see description */
    #define FE_DIVBYZERO          /* see description */
    #define FE_INEXACT            /* see description */
    #define FE_INVALID            /* see description */
    #define FE_OVERFLOW           /* see description */
    #define FE_UNDERFLOW          /* see description */
    #define FE_DOWNWARD           /* see description */
    #define FE_TONEARESTFROMZERO  /* see description */
    #define FE_TONEAREST          /* see description */
    #define FE_TOWARDZERO         /* see description */
    #define FE_UPWARD             /* see description */
    #define FE_DFL_ENV            /* see description */
    #define FE_DFL_MODE           /* see description */
     
    #define fenv_t                /* see description */
    #define fexcept_t             /* see description */
    #define femode_t              /* see description */
     
    #pragma STDC FENV_ACCESS      /*on-off-switch*/
    #pragma STDC FENV_ROUND       direction
    #pragma STDC FENV_ROUND       FE_DYNAMIC
     
    // functions
    int [feclearexcept](../numeric/fenv/feclearexcept.html)(int excepts);
    int [fegetexceptflag](../numeric/fenv/feexceptflag.html)(fexcept_t* flagp, int excepts);
    int [feraiseexcept](../numeric/fenv/feraiseexcept.html)(int excepts);
    int fesetexcept(int excepts);
    int [fesetexceptflag](../numeric/fenv/feexceptflag.html)(const fexcept_t* flagp, int excepts);
    int fetestexceptflag(const fexcept_t* flagp, int excepts);
    int [fetestexcept](../numeric/fenv/fetestexcept.html)(int excepts);
    int fegetmode(femode_t* modep);
    int [fegetround](../numeric/fenv/feround.html)(void);
    int fesetmode(const femode_t* modep);
    int [fesetround](../numeric/fenv/feround.html)(int rnd);
    int [fegetenv](../numeric/fenv/feenv.html)(fenv_t* envp);
    int [feholdexcept](../numeric/fenv/feholdexcept.html)(fenv_t* envp);
    int [fesetenv](../numeric/fenv/feenv.html)(const fenv_t* envp);
    int [feupdateenv](../numeric/fenv/feupdateenv.html)(const fenv_t* envp);
     
    // Only if the implementation defines __STDC_IEC_60559_DFP__:
    #define FE_DEC_DOWNWARD            /* implementation-defined */
    #define FE_DEC_TONEARESTFROMZERO   /* implementation-defined */
    #define FE_DEC_TONEAREST           /* implementation-defined */
    #define FE_DEC_TOWARDZERO          /* implementation-defined */
    #define FE_DEC_UPWARD              /* implementation-defined */
     
    #pragma STDC FENV_DEC_ROUND /*dec-direction*/
    int fe_dec_getround(void);
    int fe_dec_setround(int rnd);
     
    // Only if the implementation follows the recommended practice from F.2.2:
    #define FE_SNANS_ALWAYS_SIGNAL /* implementation-defined */

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/fenv&oldid=180080](https://en.cppreference.com/mwiki/index.php?title=c/header/fenv&oldid=180080)" 

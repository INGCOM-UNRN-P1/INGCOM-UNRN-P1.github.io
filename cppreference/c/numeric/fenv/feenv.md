From cppreference.com

< [c](../../../c.html "c")‎ | [numeric](../../numeric.html "c/numeric")‎ | [fenv](../fenv.html "c/numeric/fenv")

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

[ Floating-point environment](../fenv.html "c/numeric/fenv")

Functions  
---  
[feclearexcept](feclearexcept.html "c/numeric/fenv/feclearexcept")(C99)  
[fetestexcept](fetestexcept.html "c/numeric/fenv/fetestexcept")(C99)  
[feraiseexcept](feraiseexcept.html "c/numeric/fenv/feraiseexcept")(C99)  
[fegetexceptflagfesetexceptflag](feexceptflag.html "c/numeric/fenv/feexceptflag")(C99)(C99)  
[fegetroundfesetround](feround.html "c/numeric/fenv/feround")(C99)(C99)  
**fegetenv fesetenv**(C99)  
[feholdexcept](feholdexcept.html "c/numeric/fenv/feholdexcept")(C99)  
[feupdateenv](feupdateenv.html "c/numeric/fenv/feupdateenv")(C99)  
Macro constants  
[FE_ALL_EXCEPTFE_DIVBYZEROFE_INEXACTFE_INVALIDFE_OVERFLOWFE_UNDERFLOW](FE_exceptions.html "c/numeric/fenv/FE exceptions")(C99)  
[FE_DOWNWARDFE_TONEARESTFE_TOWARDZEROFE_UPWARD](FE_round.html "c/numeric/fenv/FE round")(C99)  
[FE_DFL_ENV](FE_DFL_ENV.html "c/numeric/fenv/FE DFL ENV")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/navbar_content&action=edit)

Defined in header `[`<fenv.h>`](../../header/fenv.html "c/header/fenv")` |  |   
---|---|---  
int fegetenv( fenv_t* envp ); |  (1)  |  (since C99)  
int fesetenv( const fenv_t* envp ); |  (2)  |  (since C99)  
| |   
  
1) Attempts to store the status of the floating-point environment in the object pointed to by `envp`. 

2) Attempts to establish the floating-point environment from the object pointed to by `envp`. The value of that object must be previously obtained by a call to [feholdexcept](feholdexcept.html "c/numeric/fenv/feholdexcept") or `fegetenv` or be a floating-point macro constant. If any of the floating-point status flags are set in `envp`, they become set in the environment (and are then testable with [fetestexcept](fetestexcept.html "c/numeric/fenv/fetestexcept")), but the corresponding floating-point exceptions are not raised (execution continues uninterrupted) 

## Contents

  * [1 Parameters](feenv.html#Parameters)
  * [2 Return value](feenv.html#Return_value)
  * [3 Example](feenv.html#Example)
  * [4 References](feenv.html#References)
  * [5 See also](feenv.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feenv&action=edit&section=1 "Edit section: Parameters")] Parameters

envp  |  \-  |  pointer to the object of type fenv_t which holds the status of the floating-point environment   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feenv&action=edit&section=2 "Edit section: Return value")] Return value

​0​ on success, non-zero otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feenv&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <math.h>
    #include <fenv.h>
     
    #pragma STDC FENV_ACCESS ON
     
    void show_fe_exceptions(void)
    {
        [printf](../../io/fprintf.html)("current exceptions raised: ");
        if([fetestexcept](fetestexcept.html)([FE_DIVBYZERO](FE_exceptions.html)))     [printf](../../io/fprintf.html)(" FE_DIVBYZERO");
        if([fetestexcept](fetestexcept.html)([FE_INEXACT](FE_exceptions.html)))       [printf](../../io/fprintf.html)(" FE_INEXACT");
        if([fetestexcept](fetestexcept.html)([FE_INVALID](FE_exceptions.html)))       [printf](../../io/fprintf.html)(" FE_INVALID");
        if([fetestexcept](fetestexcept.html)([FE_OVERFLOW](FE_exceptions.html)))      [printf](../../io/fprintf.html)(" FE_OVERFLOW");
        if([fetestexcept](fetestexcept.html)([FE_UNDERFLOW](FE_exceptions.html)))     [printf](../../io/fprintf.html)(" FE_UNDERFLOW");
        if([fetestexcept](fetestexcept.html)([FE_ALL_EXCEPT](FE_exceptions.html))==0) [printf](../../io/fprintf.html)(" none");
        [printf](../../io/fprintf.html)("\n");
    }
     
    void show_fe_rounding_method(void)
    {
        [printf](../../io/fprintf.html)("current rounding method:    ");
        switch ([fegetround](feround.html)()) {
               case [FE_TONEAREST](FE_round.html):  [printf](../../io/fprintf.html) ("FE_TONEAREST");  break;
               case [FE_DOWNWARD](FE_round.html):   [printf](../../io/fprintf.html) ("FE_DOWNWARD");   break;
               case [FE_UPWARD](FE_round.html):     [printf](../../io/fprintf.html) ("FE_UPWARD");     break;
               case [FE_TOWARDZERO](FE_round.html): [printf](../../io/fprintf.html) ("FE_TOWARDZERO"); break;
               default:            [printf](../../io/fprintf.html) ("unknown");
        };
        [printf](../../io/fprintf.html)("\n");
    }
     
    void show_fe_environment(void)
    {
        show_fe_exceptions();
        show_fe_rounding_method();
    }    
     
    int main(void)
    {
        fenv_t curr_env;
        int rtn;
     
        /* Show default environment. */
        show_fe_environment();
        [printf](../../io/fprintf.html)("\n");
     
        /* Perform some computation under default environment. */
        [printf](../../io/fprintf.html)("+11.5 -> %+4.1f\n", [rint](../math/rint.html)(+11.5)); /* midway between two integers */
        [printf](../../io/fprintf.html)("+12.5 -> %+4.1f\n", [rint](../math/rint.html)(+12.5)); /* midway between two integers */
        show_fe_environment();
        [printf](../../io/fprintf.html)("\n");
     
        /* Save current environment. */
        rtn = fegetenv(&curr_env);
     
        /* Perform some computation with new rounding method. */
        [feclearexcept](feclearexcept.html)([FE_ALL_EXCEPT](FE_exceptions.html));
        [fesetround](feround.html)([FE_DOWNWARD](FE_round.html));
        [printf](../../io/fprintf.html)("1.0/0.0 = %f\n", 1.0/0.0);
        [printf](../../io/fprintf.html)("+11.5 -> %+4.1f\n", [rint](../math/rint.html)(+11.5));
        [printf](../../io/fprintf.html)("+12.5 -> %+4.1f\n", [rint](../math/rint.html)(+12.5));
        show_fe_environment();
        [printf](../../io/fprintf.html)("\n");
     
        /* Restore previous environment. */
        rtn = fesetenv(&curr_env);
        show_fe_environment();
     
        return 0;
    }

Output: 
    
    
    current exceptions raised: none
    current rounding method:   FE_TONEAREST
     
    +11.5 -> +12.0
    +12.5 -> +12.0
    current exceptions raised: FE_INEXACT
    current rounding method:   FE_TONEAREST
     
    1.0/0.0 = inf
    +11.5 -> +11.0
    +12.5 -> +12.0
    current exceptions raised: FE_DIVBYZERO FE_INEXACT
    current rounding method:   FE_DOWNWARD
     
    current exceptions raised: FE_INEXACT
    current rounding method:   FE_TONEAREST

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feenv&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.6.4.1 The fegetenv function (p: 213) 



    

  * 7.6.4.3 The fesetenv function (p: 214) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.6.4.1 The fegetenv function (p: 194) 



    

  * 7.6.4.3 The fesetenv function (p: 195) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feenv&action=edit&section=5 "Edit section: See also")] See also

[ feholdexcept](feholdexcept.html "c/numeric/fenv/feholdexcept")(C99) |  saves the environment, clears all status flags and ignores all future errors   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feholdexcept&action=edit)  
---|---  
[ feupdateenv](feupdateenv.html "c/numeric/fenv/feupdateenv")(C99) |  restores the floating-point environment and raises the previously raise exceptions   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feupdateenv&action=edit)  
[ FE_DFL_ENV](FE_DFL_ENV.html "c/numeric/fenv/FE DFL ENV")(C99) |  default floating-point environment   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_FE_DFL_ENV&action=edit)  
[C++ documentation](../../../cpp/numeric/fenv/feenv.html "cpp/numeric/fenv/feenv") for fegetenv, fesetenv  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feenv&oldid=133798](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feenv&oldid=133798)" 

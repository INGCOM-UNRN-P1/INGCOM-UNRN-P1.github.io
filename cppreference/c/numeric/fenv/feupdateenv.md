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
[fegetenvfesetenv](feenv.html "c/numeric/fenv/feenv")(C99)  
[feholdexcept](feholdexcept.html "c/numeric/fenv/feholdexcept")(C99)  
**feupdateenv**(C99)  
Macro constants  
[FE_ALL_EXCEPTFE_DIVBYZEROFE_INEXACTFE_INVALIDFE_OVERFLOWFE_UNDERFLOW](FE_exceptions.html "c/numeric/fenv/FE exceptions")(C99)  
[FE_DOWNWARDFE_TONEARESTFE_TOWARDZEROFE_UPWARD](FE_round.html "c/numeric/fenv/FE round")(C99)  
[FE_DFL_ENV](FE_DFL_ENV.html "c/numeric/fenv/FE DFL ENV")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/navbar_content&action=edit)

Defined in header `[`<fenv.h>`](../../header/fenv.html "c/header/fenv")` |  |   
---|---|---  
int feupdateenv( const fenv_t* envp ); |  |  (since C99)  
| |   
  
First, remembers the currently raised floating-point exceptions, then restores the floating-point environment from the object pointed to by `envp` (similar to [fesetenv](feenv.html "c/numeric/fenv/feenv")), then raises the floating-point exceptions that were saved. 

This function may be used to end the non-stop mode established by an earlier call to [feholdexcept](feholdexcept.html "c/numeric/fenv/feholdexcept"). 

## Contents

  * [1 Parameters](feupdateenv.html#Parameters)
  * [2 Return value](feupdateenv.html#Return_value)
  * [3 Example](feupdateenv.html#Example)
  * [4 References](feupdateenv.html#References)
  * [5 See also](feupdateenv.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feupdateenv&action=edit&section=1 "Edit section: Parameters")] Parameters

envp  |  \-  |  pointer to the object of type fenv_t set by an earlier call to [feholdexcept](feholdexcept.html "c/numeric/fenv/feholdexcept") or `fegetenv` or equal to [FE_DFL_ENV](FE_DFL_ENV.html "c/numeric/fenv/FE DFL ENV")  
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feupdateenv&action=edit&section=2 "Edit section: Return value")] Return value

​0​ on success, non-zero otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feupdateenv&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <fenv.h>
    #include <float.h>
     
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
     
    double x2 (double x)   /* times two */
    {
        fenv_t curr_excepts;
     
        /* Save and clear current f-p environment. */
        [feholdexcept](feholdexcept.html)(&curr_excepts);
     
        /* Raise inexact and overflow exceptions. */
        [printf](../../io/fprintf.html)("In x2():  x = %f\n", x=x*2.0);
        show_fe_exceptions();
        [feclearexcept](feclearexcept.html)([FE_INEXACT](FE_exceptions.html));   /* hide inexact exception from caller */
     
        /* Merge caller's exceptions (FE_INVALID)        */
        /* with remaining x2's exceptions (FE_OVERFLOW). */
        feupdateenv(&curr_excepts);
        return x;
    }
     
    int main(void)
    {    
        [feclearexcept](feclearexcept.html)([FE_ALL_EXCEPT](FE_exceptions.html));
        [feraiseexcept](feraiseexcept.html)([FE_INVALID](FE_exceptions.html));   /* some computation with invalid argument */
        show_fe_exceptions();
        [printf](../../io/fprintf.html)("x2(DBL_MAX) = %f\n", x2([DBL_MAX](../../types/limits.html)));
        show_fe_exceptions();
     
        return 0;
    }

Output: 
    
    
    current exceptions raised:  FE_INVALID
    In x2():  x = inf
    current exceptions raised:  FE_INEXACT FE_OVERFLOW
    x2(DBL_MAX) = inf
    current exceptions raised:  FE_INVALID FE_OVERFLOW

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feupdateenv&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.6.4.4 The feupdateenv function (p: 214-215) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.6.4.4 The feupdateenv function (p: 195-196) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feupdateenv&action=edit&section=5 "Edit section: See also")] See also

[ feholdexcept](feholdexcept.html "c/numeric/fenv/feholdexcept")(C99) |  saves the environment, clears all status flags and ignores all future errors   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feholdexcept&action=edit)  
---|---  
[ fegetenvfesetenv](feenv.html "c/numeric/fenv/feenv")(C99) |  saves or restores the current floating-point environment   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feenv&action=edit)  
[ FE_DFL_ENV](FE_DFL_ENV.html "c/numeric/fenv/FE DFL ENV")(C99) |  default floating-point environment   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_FE_DFL_ENV&action=edit)  
[C++ documentation](../../../cpp/numeric/fenv/feupdateenv.html "cpp/numeric/fenv/feupdateenv") for feupdateenv  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feupdateenv&oldid=133800](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feupdateenv&oldid=133800)" 

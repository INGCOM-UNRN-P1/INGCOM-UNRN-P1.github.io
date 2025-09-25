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
**fetestexcept**(C99)  
[feraiseexcept](feraiseexcept.html "c/numeric/fenv/feraiseexcept")(C99)  
[fegetexceptflagfesetexceptflag](feexceptflag.html "c/numeric/fenv/feexceptflag")(C99)(C99)  
[fegetroundfesetround](feround.html "c/numeric/fenv/feround")(C99)(C99)  
[fegetenvfesetenv](feenv.html "c/numeric/fenv/feenv")(C99)  
[feholdexcept](feholdexcept.html "c/numeric/fenv/feholdexcept")(C99)  
[feupdateenv](feupdateenv.html "c/numeric/fenv/feupdateenv")(C99)  
Macro constants  
[FE_ALL_EXCEPTFE_DIVBYZEROFE_INEXACTFE_INVALIDFE_OVERFLOWFE_UNDERFLOW](FE_exceptions.html "c/numeric/fenv/FE exceptions")(C99)  
[FE_DOWNWARDFE_TONEARESTFE_TOWARDZEROFE_UPWARD](FE_round.html "c/numeric/fenv/FE round")(C99)  
[FE_DFL_ENV](FE_DFL_ENV.html "c/numeric/fenv/FE DFL ENV")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/navbar_content&action=edit)

Defined in header `[`<fenv.h>`](../../header/fenv.html "c/header/fenv")` |  |   
---|---|---  
int fetestexcept( int excepts ); |  |  (since C99)  
| |   
  
Determines which of the specified subset of the floating-point exceptions are currently set. The argument `excepts` is a bitwise OR of the [floating-point exception macros](FE_exceptions.html "c/numeric/fenv/FE exceptions"). 

## Contents

  * [1 Parameters](fetestexcept.html#Parameters)
  * [2 Return value](fetestexcept.html#Return_value)
  * [3 Example](fetestexcept.html#Example)
  * [4 References](fetestexcept.html#References)
  * [5 See also](fetestexcept.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/fetestexcept&action=edit&section=1 "Edit section: Parameters")] Parameters

excepts  |  \-  |  bitmask listing the exception flags to test   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/fetestexcept&action=edit&section=2 "Edit section: Return value")] Return value

Bitwise OR of the floating-point exception macros that are both included in `excepts` and correspond to floating-point exceptions currently set. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/fetestexcept&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <math.h>
    #include <fenv.h>
    #include <float.h>
     
    #pragma STDC FENV_ACCESS ON
     
    void show_fe_exceptions(void)
    {
        [printf](../../io/fprintf.html)("current exceptions raised: ");
        if(fetestexcept([FE_DIVBYZERO](FE_exceptions.html)))     [printf](../../io/fprintf.html)(" FE_DIVBYZERO");
        if(fetestexcept([FE_INEXACT](FE_exceptions.html)))       [printf](../../io/fprintf.html)(" FE_INEXACT");
        if(fetestexcept([FE_INVALID](FE_exceptions.html)))       [printf](../../io/fprintf.html)(" FE_INVALID");
        if(fetestexcept([FE_OVERFLOW](FE_exceptions.html)))      [printf](../../io/fprintf.html)(" FE_OVERFLOW");
        if(fetestexcept([FE_UNDERFLOW](FE_exceptions.html)))     [printf](../../io/fprintf.html)(" FE_UNDERFLOW");
        if(fetestexcept([FE_ALL_EXCEPT](FE_exceptions.html))==0) [printf](../../io/fprintf.html)(" none");
        [printf](../../io/fprintf.html)("\n");
    }
     
    int main(void)
    {
        /* Show default set of exception flags. */
        show_fe_exceptions();
     
        /* Perform some computations which raise exceptions. */
        [printf](../../io/fprintf.html)("1.0/0.0     = %f\n", 1.0/0.0);        /* FE_DIVBYZERO            */
        [printf](../../io/fprintf.html)("1.0/10.0    = %f\n", 1.0/10.0);       /* FE_INEXACT              */
        [printf](../../io/fprintf.html)("sqrt(-1)    = %f\n", [sqrt](../math/sqrt.html)(-1));       /* FE_INVALID              */
        [printf](../../io/fprintf.html)("DBL_MAX*2.0 = %f\n", [DBL_MAX](../../types/limits.html)*2.0);    /* FE_INEXACT FE_OVERFLOW  */
        [printf](../../io/fprintf.html)("nextafter(DBL_MIN/pow(2.0,52),0.0) = %.1f\n",
               [nextafter](../math/nexttoward.html)([DBL_MIN](../../types/limits.html)/[pow](../math/pow.html)(2.0,52),0.0));   /* FE_INEXACT FE_UNDERFLOW */
        show_fe_exceptions();
     
        return 0;
    }

Output: 
    
    
    current exceptions raised:  none
    1.0/0.0     = inf
    1.0/10.0    = 0.100000
    sqrt(-1)    = -nan
    DBL_MAX*2.0 = inf
    nextafter(DBL_MIN/pow(2.0,52),0.0) = 0.0
    current exceptions raised:  FE_DIVBYZERO FE_INEXACT FE_INVALID FE_OVERFLOW FE_UNDERFLOW

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/fetestexcept&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.6.2.5 The fetestexcept function (p: 211-212) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.6.2.5 The fetestexcept function (p: 192-193) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/fetestexcept&action=edit&section=5 "Edit section: See also")] See also

[ feclearexcept](feclearexcept.html "c/numeric/fenv/feclearexcept")(C99) |  clears the specified floating-point status flags   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feclearexcept&action=edit)  
---|---  
[C++ documentation](../../../cpp/numeric/fenv/fetestexcept.html "cpp/numeric/fenv/fetestexcept") for fetestexcept  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/fetestexcept&oldid=133794](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/fetestexcept&oldid=133794)" 

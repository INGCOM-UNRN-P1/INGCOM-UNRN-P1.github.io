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
**feraiseexcept**(C99)  
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
int feraiseexcept( int excepts ); |  |  (since C99)  
| |   
  
Attempts to raise all floating-point exceptions listed in `excepts` (a bitwise OR of the [floating-point exception macros](FE_exceptions.html "c/numeric/fenv/FE exceptions")). If one of the exceptions is [FE_OVERFLOW](FE_exceptions.html "c/numeric/fenv/FE exceptions") or [FE_UNDERFLOW](FE_exceptions.html), this function may additionally raise [FE_INEXACT](FE_exceptions.html "c/numeric/fenv/FE exceptions"). The order in which the exceptions are raised is unspecified, except that [FE_OVERFLOW](FE_exceptions.html "c/numeric/fenv/FE exceptions") and [FE_UNDERFLOW](FE_exceptions.html) are always raised before [FE_INEXACT](FE_exceptions.html "c/numeric/fenv/FE exceptions"). 

## Contents

  * [1 Parameters](feraiseexcept.html#Parameters)
  * [2 Return value](feraiseexcept.html#Return_value)
  * [3 Example](feraiseexcept.html#Example)
  * [4 References](feraiseexcept.html#References)
  * [5 See also](feraiseexcept.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feraiseexcept&action=edit&section=1 "Edit section: Parameters")] Parameters

excepts  |  \-  |  bitmask listing the exception flags to raise   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feraiseexcept&action=edit&section=2 "Edit section: Return value")] Return value

​0​ if all listed exceptions were raised, non-zero value otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feraiseexcept&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
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
        [feclearexcept](feclearexcept.html)([FE_ALL_EXCEPT](FE_exceptions.html));
        [printf](../../io/fprintf.html)("\n");
    }
     
    double some_computation(void)
    {
        /* Computation reaches a state that causes overflow. */
        int r = feraiseexcept([FE_OVERFLOW](FE_exceptions.html) | [FE_INEXACT](FE_exceptions.html));
        [printf](../../io/fprintf.html)("feraiseexcept() %s\n", (r?"fails":"succeeds"));
        return 0.0;
    }
     
    int main(void)
    {
        some_computation();
        show_fe_exceptions();
     
        return 0;
    }

Output: 
    
    
    feraiseexcept() succeeds
    current exceptions raised:  FE_INEXACT FE_OVERFLOW

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feraiseexcept&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.6.2.3 The feraiseexcept function (p: 210) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.6.2.3 The feraiseexcept function (p: 191) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feraiseexcept&action=edit&section=5 "Edit section: See also")] See also

[ feclearexcept](feclearexcept.html "c/numeric/fenv/feclearexcept")(C99) |  clears the specified floating-point status flags   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feclearexcept&action=edit)  
---|---  
[ fetestexcept](fetestexcept.html "c/numeric/fenv/fetestexcept")(C99) |  determines which of the specified floating-point status flags are set   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_fetestexcept&action=edit)  
[C++ documentation](../../../cpp/numeric/fenv/feraiseexcept.html "cpp/numeric/fenv/feraiseexcept") for feraiseexcept  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feraiseexcept&oldid=133795](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feraiseexcept&oldid=133795)" 

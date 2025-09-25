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
**fegetexceptflag fesetexceptflag**(C99)(C99)  
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
int fegetexceptflag( fexcept_t* flagp, int excepts ); |  (1)  |  (since C99)  
int fesetexceptflag( const fexcept_t* flagp, int excepts ); |  (2)  |  (since C99)  
| |   
  
1) Attempts to obtain the full contents of the floating-point exception flags that are listed in the bitmask argument `excepts`, which is a bitwise OR of the [floating-point exception macros](FE_exceptions.html "c/numeric/fenv/FE exceptions"). 

2) Attempts to copy the full contents of the floating-point exception flags that are listed in `excepts` from `flagp` into the floating-point environment. Does not raise any exceptions, only modifies the flags. 

The full contents of a floating-point exception flag is not necessarily a boolean value indicating whether the exception is raised or cleared. For example, it may be a struct which includes the boolean status and the address of the code that triggered the exception. These functions obtain all such content and obtain/store it in `flagp` in implementation-defined format. 

## Contents

  * [1 Parameters](feexceptflag.html#Parameters)
  * [2 Return value](feexceptflag.html#Return_value)
  * [3 Example](feexceptflag.html#Example)
  * [4 References](feexceptflag.html#References)
  * [5 See also](feexceptflag.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feexceptflag&action=edit&section=1 "Edit section: Parameters")] Parameters

flagp  |  \-  |  pointer to an fexcept_t object where the flags will be stored or read from   
---|---|---  
excepts  |  \-  |  bitmask listing the exception flags to get/set   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feexceptflag&action=edit&section=2 "Edit section: Return value")] Return value

​0​ on success, non-zero otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feexceptflag&action=edit&section=3 "Edit section: Example")] Example

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
        [printf](../../io/fprintf.html)("\n");
    }
     
    int main(void)
    {
        fexcept_t excepts;
     
        /* Setup a "current" set of exception flags. */
        [feraiseexcept](feraiseexcept.html)([FE_INVALID](FE_exceptions.html));
        show_fe_exceptions();
     
        /* Save current exception flags. */
        fegetexceptflag(&excepts,[FE_ALL_EXCEPT](FE_exceptions.html));
     
        /* Temporarily raise two other exceptions. */
        [feclearexcept](feclearexcept.html)([FE_ALL_EXCEPT](FE_exceptions.html));
        [feraiseexcept](feraiseexcept.html)([FE_OVERFLOW](FE_exceptions.html) | [FE_INEXACT](FE_exceptions.html));
        show_fe_exceptions();
     
        /* Restore previous exception flags. */
        fesetexceptflag(&excepts,[FE_ALL_EXCEPT](FE_exceptions.html));
        show_fe_exceptions();
     
        return 0;
    }

Output: 
    
    
    current exceptions raised: FE_INVALID
    current exceptions raised: FE_INEXACT FE_OVERFLOW
    current exceptions raised: FE_INVALID

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feexceptflag&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.6.2.2 The fegetexceptflag function (p: 210) 



    

  * 7.6.2.4 The fesetexceptflag function (p: 211) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.6.2.2 The fegetexceptflag function (p: 191) 



    

  * 7.6.2.4 The fesetexceptflag function (p: 192) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feexceptflag&action=edit&section=5 "Edit section: See also")] See also

[C++ documentation](../../../cpp/numeric/fenv/feexceptflag.html "cpp/numeric/fenv/feexceptflag") for fegetexceptflag, fesetexceptflag  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feexceptflag&oldid=133796](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feexceptflag&oldid=133796)" 

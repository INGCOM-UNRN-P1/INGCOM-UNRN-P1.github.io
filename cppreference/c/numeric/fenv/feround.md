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
**fegetround fesetround**(C99)(C99)  
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
int fesetround( int [round](../math/round.html) ); |  (1)  |  (since C99)  
int fegetround(); |  (2)  |  (since C99)  
| |   
  
1) Attempts to establish the floating-point rounding direction equal to the argument [round](../math/round.html), which is expected to be one of the [floating-point rounding macros](FE_round.html "c/numeric/fenv/FE round"). 

2) Returns the value of the [floating-point rounding macro](FE_round.html "c/numeric/fenv/FE round") that corresponds to the current rounding direction. 

## Contents

  * [1 Parameters](feround.html#Parameters)
  * [2 Return value](feround.html#Return_value)
  * [3 Notes](feround.html#Notes)
  * [4 Example](feround.html#Example)
  * [5 References](feround.html#References)
  * [6 See also](feround.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feround&action=edit&section=1 "Edit section: Parameters")] Parameters

round  |  \-  |  rounding direction, one of [floating-point rounding macros](FE_round.html "c/numeric/fenv/FE round")  
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feround&action=edit&section=2 "Edit section: Return value")] Return value

1) ​0​ on success, non-zero otherwise. 

2) the [floating-point rounding macro](FE_round.html "c/numeric/fenv/FE round") describing the current rounding direction or a negative value if the direction cannot be determined. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feround&action=edit&section=3 "Edit section: Notes")] Notes

The current rounding mode, reflecting the effects of the most recent `fesetround`, can also be queried with [FLT_ROUNDS](../../types/limits/FLT_ROUNDS.html "c/types/limits/FLT ROUNDS"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feround&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <fenv.h>
    #include <math.h>
    #include <stdio.h>
     
    // #pragma STDC FENV_ACCESS ON
     
    void show_fe_current_rounding_direction(void)
    {
        [printf](../../io/fprintf.html)("current rounding direction:  ");
        switch (fegetround())
        {
               case [FE_TONEAREST](FE_round.html):  [printf](../../io/fprintf.html) ("FE_TONEAREST");  break;
               case [FE_DOWNWARD](FE_round.html):   [printf](../../io/fprintf.html) ("FE_DOWNWARD");   break;
               case [FE_UPWARD](FE_round.html):     [printf](../../io/fprintf.html) ("FE_UPWARD");     break;
               case [FE_TOWARDZERO](FE_round.html): [printf](../../io/fprintf.html) ("FE_TOWARDZERO"); break;
               default:            [printf](../../io/fprintf.html) ("unknown");
        };
        [printf](../../io/fprintf.html)("\n");
    }
     
    int main(void)
    {
        /* Default rounding direction */
        show_fe_current_rounding_direction();
        [printf](../../io/fprintf.html)("+11.5 -> %+4.1f\n", [rint](../math/rint.html)(+11.5)); /* midway between two integers */
        [printf](../../io/fprintf.html)("+12.5 -> %+4.1f\n", [rint](../math/rint.html)(+12.5)); /* midway between two integers */
     
        /* Save current rounding direction. */
        int curr_direction = fegetround();
     
        /* Temporarily change current rounding direction. */
        fesetround([FE_DOWNWARD](FE_round.html));
        show_fe_current_rounding_direction();
        [printf](../../io/fprintf.html)("+11.5 -> %+4.1f\n", [rint](../math/rint.html)(+11.5));
        [printf](../../io/fprintf.html)("+12.5 -> %+4.1f\n", [rint](../math/rint.html)(+12.5));
     
        /* Restore default rounding direction. */
        fesetround(curr_direction);
        show_fe_current_rounding_direction();
     
        return 0;
    }

Possible output: 
    
    
    current rounding direction:  FE_TONEAREST
    +11.5 -> +12.0
    +12.5 -> +12.0
    current rounding direction:  FE_DOWNWARD
    +11.5 -> +11.0
    +12.5 -> +12.0
    current rounding direction:  FE_TONEAREST

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feround&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.6.3.1 The fegetround function (p: TBD) 



    

  * 7.6.3.2 The fesetround function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.6.3.1 The fegetround function (p: TBD) 



    

  * 7.6.3.2 The fesetround function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.6.3.1 The fegetround function (p: 212) 



    

  * 7.6.3.2 The fesetround function (p: 212-213) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.6.3.1 The fegetround function (p: 193) 



    

  * 7.6.3.2 The fesetround function (p: 193-194) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feround&action=edit&section=6 "Edit section: See also")] See also

[ nearbyintnearbyintfnearbyintl](../math/nearbyint.html "c/numeric/math/nearbyint")(C99)(C99)(C99) |  rounds to an integer using current rounding mode   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_nearbyint&action=edit)  
---|---  
[ rintrintfrintllrintlrintflrintlllrintllrintfllrintl](../math/rint.html "c/numeric/math/rint")(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99) |  rounds to an integer using current rounding mode with   
exception if the result differs   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_rint&action=edit)  
[C++ documentation](../../../cpp/numeric/fenv/feround.html "cpp/numeric/fenv/feround") for fegetround, fesetround  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feround&oldid=169737](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feround&oldid=169737)" 

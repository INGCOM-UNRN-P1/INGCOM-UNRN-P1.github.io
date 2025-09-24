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
[feupdateenv](feupdateenv.html "c/numeric/fenv/feupdateenv")(C99)  
Macro constants  
[FE_ALL_EXCEPTFE_DIVBYZEROFE_INEXACTFE_INVALIDFE_OVERFLOWFE_UNDERFLOW](FE_exceptions.html "c/numeric/fenv/FE exceptions")(C99)  
**FE_DOWNWARD FE_TONEARESTFE_TOWARDZEROFE_UPWARD**(C99)  
[FE_DFL_ENV](FE_DFL_ENV.html "c/numeric/fenv/FE DFL ENV")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/navbar_content&action=edit)

Defined in header `[`<fenv.h>`](../../header/fenv.html "c/header/fenv")` |  |   
---|---|---  
#define FE_DOWNWARD /*implementation defined*/ |  |  (since C99)  
#define FE_TONEAREST /*implementation defined*/ |  |  (since C99)  
#define FE_TOWARDZERO /*implementation defined*/ |  |  (since C99)  
#define FE_UPWARD /*implementation defined*/ |  |  (since C99)  
| |   
  
Each of these macro constants expands to a nonnegative integer constant expression, which can be used with [fesetround](feround.html "c/numeric/fenv/feround") and [fegetround](feround.html "c/numeric/fenv/feround") to indicate one of the supported floating-point rounding modes. The implementation may define additional rounding mode constants in [`<fenv.h>`](../../header/fenv.html "c/header/fenv"), which should all begin with `FE_` followed by at least one uppercase letter. Each macro is only defined if it is supported. 

Constant  |  Explanation   
---|---  
`FE_DOWNWARD` |  rounding towards negative infinity   
`FE_TONEAREST` |  rounding towards nearest representable value   
`FE_TOWARDZERO` |  rounding towards zero   
`FE_UPWARD` |  rounding towards positive infinity   
  
Additional rounding modes may be supported by an implementation. 

The current rounding mode affects the following: 

  * results of floating-point arithmetic operators outside of constant expressions 


    
    
    double x = 1;
    x / 10; // 0.09999999999999999167332731531132594682276248931884765625 or
            // 0.1000000000000000055511151231257827021181583404541015625

  * results of standard library [mathematical functions](../math.html "c/numeric/math")


    
    
    [sqrt](../math/sqrt.html)(2); // 1.41421356237309492343001693370752036571502685546875 or
             // 1.4142135623730951454746218587388284504413604736328125

  * floating-point to floating-point implicit conversion and casts 


    
    
    double d = 1 + [DBL_EPSILON](../../types/limits.html);
    float f = d; // 1.00000000000000000000000 or
                 // 1.00000011920928955078125

  * string conversions such as [strtod](../../string/byte/strtof.html "c/string/byte/strtof") or [printf](../../io/fprintf.html "c/io/fprintf")


    
    
    [strtof](../../string/byte/strtof.html)("0.1", [NULL](../../types/NULL.html)); // 0.0999999940395355224609375 or
                         // 0.100000001490116119384765625

  * the library rounding functions [nearbyint](../math/nearbyint.html "c/numeric/math/nearbyint"), [rint](../math/rint.html "c/numeric/math/rint"), [lrint](../math/rint.html "c/numeric/math/rint")


    
    
    [lrint](../math/rint.html)(2.1); // 2 or 3

The current rounding mode does NOT affect the following: 

  * floating-point to integer implicit conversion and casts (always towards zero) 
  * results of floating-point arithmetic operators in constant expressions executed at compile time (always to nearest) 
  * the library functions [round](../math/round.html "c/numeric/math/round"), [lround](../math/round.html "c/numeric/math/round"), [llround](../math/round.html "c/numeric/math/round"), [ceil](../math/ceil.html "c/numeric/math/ceil"), [floor](../math/floor.html "c/numeric/math/floor"), [trunc](../math/trunc.html "c/numeric/math/trunc")



As with any [floating-point environment](../fenv.html "c/numeric/fenv") functionality, rounding is only guaranteed if #pragma STDC FENV_ACCESS ON is set. 

Compilers that do not support the pragma may offer their own ways to support current rounding mode. For example Clang and GCC have the option `-frounding-math` intended to disable optimizations that would change the meaning of rounding-sensitive code. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_round&action=edit&section=1 "Edit section: Example")] Example

Run this code
    
    
    #include <fenv.h>
    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
     
    // #pragma STDC FENV_ACCESS ON
     
    int main()
    {
        [fesetround](feround.html)(FE_DOWNWARD);
        [puts](../../io/puts.html)("rounding down: ");
        [printf](../../io/fprintf.html)("           pi = %.22f\n", acosf(-1));
        [printf](../../io/fprintf.html)("strtof(\"1.1\") = %.22f\n", [strtof](../../string/byte/strtof.html)("1.1", [NULL](../../types/NULL.html)));
        [printf](../../io/fprintf.html)("    rint(2.1) = %.22f\n\n", rintf(2.1));
        [fesetround](feround.html)(FE_UPWARD);
        [puts](../../io/puts.html)("rounding up: ");
        [printf](../../io/fprintf.html)("           pi = %.22f\n", acosf(-1));
        [printf](../../io/fprintf.html)("strtof(\"1.1\") = %.22f\n", [strtof](../../string/byte/strtof.html)("1.1", [NULL](../../types/NULL.html)));
        [printf](../../io/fprintf.html)("    rint(2.1) = %.22f\n", rintf(2.1));
    }

Output: 
    
    
    rounding down:
               pi = 3.1415925025939941406250
    strtof("1.1") = 1.0999999046325683593750
        rint(2.1) = 2.0000000000000000000000
     
    rounding up:
               pi = 3.1415927410125732421875
    strtof("1.1") = 1.1000000238418579101563
        rint(2.1) = 3.0000000000000000000000

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_round&action=edit&section=2 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.6/8 Floating-point environment <fenv.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.6/8 Floating-point environment <fenv.h> (p: 151) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.6/8 Floating-point environment <fenv.h> (p: 207) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.6/7 Floating-point environment <fenv.h> (p: 188) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_round&action=edit&section=3 "Edit section: See also")] See also

[ fegetroundfesetround](feround.html "c/numeric/fenv/feround")(C99)(C99) |  gets or sets rounding direction   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feround&action=edit)  
---|---  
[C++ documentation](../../../cpp/numeric/fenv/FE_round.html "cpp/numeric/fenv/FE round") for floating-point rounding macros  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_round&oldid=164644](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_round&oldid=164644)" 

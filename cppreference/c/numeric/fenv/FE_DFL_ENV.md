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
[FE_DOWNWARDFE_TONEARESTFE_TOWARDZEROFE_UPWARD](FE_round.html "c/numeric/fenv/FE round")(C99)  
**FE_DFL_ENV**(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/navbar_content&action=edit)

Defined in header `[`<fenv.h>`](../../header/fenv.html "c/header/fenv")` |  |   
---|---|---  
#define FE_DFL_ENV /*implementation defined*/ |  |  (since C99)  
| |   
  
The macro constant **FE_DFL_ENV** expands to an expression of type const fenv_t*, which points to a full copy of the default floating-point environment, that is, the environment as loaded at program startup. 

Additional macros that begin with `FE_` followed by uppercase letters, and have the type const fenv_t*, may be supported by an implementation. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_DFL_ENV&action=edit&section=1 "Edit section: Example")] Example

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
     
    int main()
    {
        [printf](../../io/fprintf.html)("On startup:\n");
        show_fe_environment();
     
        // Change environment
        [fesetround](feround.html)([FE_DOWNWARD](FE_round.html));     // change rounding mode
        [feraiseexcept](feraiseexcept.html)([FE_INVALID](FE_exceptions.html));   // raise exception
        [printf](../../io/fprintf.html)("\nBefore restoration:\n");
        show_fe_environment();
     
        [fesetenv](feenv.html)(FE_DFL_ENV);    // restore
        [printf](../../io/fprintf.html)("\nAfter restoring default environment:\n");
        show_fe_environment();
    }

Output: 
    
    
    On startup:
    current exceptions raised:  none
    current rounding method:    FE_TONEAREST
     
    Before restoration:
    current exceptions raised:  FE_INVALID
    current rounding method:    FE_DOWNWARD
     
    After restoring default environment:
    current exceptions raised:  none
    current rounding method:    FE_TONEAREST

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_DFL_ENV&action=edit&section=2 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.6/9 Floating-point environment <fenv.h> (p: 208) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.6/8 Floating-point environment <fenv.h> (p: 188-189) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_DFL_ENV&action=edit&section=3 "Edit section: See also")] See also

[ fegetenvfesetenv](feenv.html "c/numeric/fenv/feenv")(C99) |  saves or restores the current floating-point environment   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feenv&action=edit)  
---|---  
[ feupdateenv](feupdateenv.html "c/numeric/fenv/feupdateenv")(C99) |  restores the floating-point environment and raises the previously raise exceptions   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feupdateenv&action=edit)  
[C++ documentation](../../../cpp/numeric/fenv/FE_DFL_ENV.html "cpp/numeric/fenv/FE DFL ENV") for FE_DFL_ENV  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_DFL_ENV&oldid=133803](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_DFL_ENV&oldid=133803)" 

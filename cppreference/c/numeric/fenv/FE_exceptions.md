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
**FE_ALL_EXCEPT FE_DIVBYZEROFE_INEXACTFE_INVALIDFE_OVERFLOWFE_UNDERFLOW**(C99)  
[FE_DOWNWARDFE_TONEARESTFE_TOWARDZEROFE_UPWARD](FE_round.html "c/numeric/fenv/FE round")(C99)  
[FE_DFL_ENV](FE_DFL_ENV.html "c/numeric/fenv/FE DFL ENV")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/navbar_content&action=edit)

Defined in header `[`<fenv.h>`](../../header/fenv.html "c/header/fenv")` |  |   
---|---|---  
#define FE_DIVBYZERO /*implementation defined power of 2*/ |  |  (since C99)  
#define FE_INEXACT /*implementation defined power of 2*/ |  |  (since C99)  
#define FE_INVALID /*implementation defined power of 2*/ |  |  (since C99)  
#define FE_OVERFLOW /*implementation defined power of 2*/ |  |  (since C99)  
#define FE_UNDERFLOW /*implementation defined power of 2*/ |  |  (since C99)  
#define FE_ALL_EXCEPT FE_DIVBYZERO | FE_INEXACT | \  
FE_INVALID | FE_OVERFLOW | \  
FE_UNDERFLOW |  |  (since C99)  
| |   
  
All these macro constants (except **FE_ALL_EXCEPT**) expand to integer constant expressions that are distinct powers of 2, which uniquely identify all supported floating-point exceptions. Each macro is only defined if it is supported. 

The macro constant **FE_ALL_EXCEPT** , which expands to the bitwise OR of all other `FE_*`, is always defined and is zero if floating-point exceptions are not supported by the implementation. 

Constant  |  Explanation   
---|---  
`FE_DIVBYZERO` |  pole error occurred in an earlier floating-point operation   
`FE_INEXACT` |  inexact result: rounding was necessary to store the result of an earlier floating-point operation   
`FE_INVALID` |  domain error occurred in an earlier floating-point operation   
`FE_OVERFLOW` |  the result of an earlier floating-point operation was too large to be representable   
`FE_UNDERFLOW` |  the result of an earlier floating-point operation was subnormal with a loss of precision   
`FE_ALL_EXCEPT` |  bitwise OR of all supported floating-point exceptions   
  
The implementation may define additional macro constants in `<fenv.h>` to identify additional floating-point exceptions. All such constants begin with `FE_` followed by at least one uppercase letter. 

See [math_errhandling](../math/math_errhandling.html "c/numeric/math/math errhandling") for further details. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_exceptions&action=edit&section=1 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <math.h>
    #include <float.h>
    #include <fenv.h>
     
    #pragma STDC FENV_ACCESS ON
    void show_fe_exceptions(void)
    {
        [printf](../../io/fprintf.html)("exceptions raised:");
        if([fetestexcept](fetestexcept.html)(FE_DIVBYZERO)) [printf](../../io/fprintf.html)(" FE_DIVBYZERO");
        if([fetestexcept](fetestexcept.html)(FE_INEXACT))   [printf](../../io/fprintf.html)(" FE_INEXACT");
        if([fetestexcept](fetestexcept.html)(FE_INVALID))   [printf](../../io/fprintf.html)(" FE_INVALID");
        if([fetestexcept](fetestexcept.html)(FE_OVERFLOW))  [printf](../../io/fprintf.html)(" FE_OVERFLOW");
        if([fetestexcept](fetestexcept.html)(FE_UNDERFLOW)) [printf](../../io/fprintf.html)(" FE_UNDERFLOW");
        [feclearexcept](feclearexcept.html)(FE_ALL_EXCEPT);
        [printf](../../io/fprintf.html)("\n");
    }
     
    int main(void)
    {
        [printf](../../io/fprintf.html)("MATH_ERREXCEPT is %s\n",
               math_errhandling & MATH_ERREXCEPT ? "set" : "not set");
     
        [printf](../../io/fprintf.html)("0.0/0.0 = %f\n", 0.0/0.0);
        show_fe_exceptions();
     
        [printf](../../io/fprintf.html)("1.0/0.0 = %f\n", 1.0/0.0);
        show_fe_exceptions();
     
        [printf](../../io/fprintf.html)("1.0/10.0 = %f\n", 1.0/10.0);
        show_fe_exceptions();
     
        [printf](../../io/fprintf.html)("sqrt(-1) = %f\n", [sqrt](../math/sqrt.html)(-1));
        show_fe_exceptions();
     
        [printf](../../io/fprintf.html)("DBL_MAX*2.0 = %f\n", [DBL_MAX](../../types/limits.html)*2.0);
        show_fe_exceptions();
     
        [printf](../../io/fprintf.html)("nextafter(DBL_MIN/pow(2.0,52),0.0) = %.1f\n",
                          [nextafter](../math/nexttoward.html)([DBL_MIN](../../types/limits.html)/[pow](../math/pow.html)(2.0,52),0.0));
        show_fe_exceptions();
    }

Possible output: 
    
    
    MATH_ERREXCEPT is set
    0.0/0.0 = nan
    exceptions raised: FE_INVALID
    1.0/0.0 = inf
    exceptions raised: FE_DIVBYZERO
    1.0/10.0 = 0.100000
    exceptions raised: FE_INEXACT
    sqrt(-1) = -nan
    exceptions raised: FE_INVALID
    DBL_MAX*2.0 = inf
    exceptions raised: FE_INEXACT FE_OVERFLOW
    nextafter(DBL_MIN/pow(2.0,52),0.0) = 0.0
    exceptions raised: FE_INEXACT FE_UNDERFLOW

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_exceptions&action=edit&section=2 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.6/6 Floating-point environment <fenv.h> (p: 207) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.6/5 Floating-point environment <fenv.h> (p: 188) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_exceptions&action=edit&section=3 "Edit section: See also")] See also

[ math_errhandlingMATH_ERRNOMATH_ERREXCEPT](../math/math_errhandling.html "c/numeric/math/math errhandling")(C99)(C99)(C99) |  defines the error handling mechanism used by the common mathematical functions   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_math_errhandling&action=edit)  
---|---  
[C++ documentation](../../../cpp/numeric/fenv/FE_exceptions.html "cpp/numeric/fenv/FE exceptions") for floating-point exception macros  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_exceptions&oldid=133801](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/FE_exceptions&oldid=133801)" 

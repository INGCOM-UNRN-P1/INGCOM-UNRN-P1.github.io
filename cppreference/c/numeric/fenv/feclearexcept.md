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
**feclearexcept**(C99)  
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
[FE_DFL_ENV](FE_DFL_ENV.html "c/numeric/fenv/FE DFL ENV")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/navbar_content&action=edit)

Defined in header `[`<fenv.h>`](../../header/fenv.html "c/header/fenv")` |  |   
---|---|---  
int feclearexcept( int excepts ); |  |  (since C99)  
| |   
  
Attempts to clear the floating-point exceptions that are listed in the bitmask argument `excepts`, which is a bitwise OR of the [floating-point exception macros](FE_exceptions.html "c/numeric/fenv/FE exceptions"). 

## Contents

  * [1 Parameters](feclearexcept.html#Parameters)
  * [2 Return value](feclearexcept.html#Return_value)
  * [3 Example](feclearexcept.html#Example)
  * [4 References](feclearexcept.html#References)
  * [5 See also](feclearexcept.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feclearexcept&action=edit&section=1 "Edit section: Parameters")] Parameters

excepts  |  \-  |  bitmask listing the exception flags to clear   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feclearexcept&action=edit&section=2 "Edit section: Return value")] Return value

​0​ if all indicated exceptions were successfully cleared or if `excepts` is zero. Returns a non-zero value on error. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feclearexcept&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <fenv.h>
    #include <stdio.h>
    #include <math.h>
    #include <float.h>
     
    /*
     * A possible implementation of hypot which makes use of many advanced
     * floating-point features.
     */
    double hypot_demo(double a, double b) {
      const int range_problem = [FE_OVERFLOW](FE_exceptions.html) | [FE_UNDERFLOW](FE_exceptions.html);
      feclearexcept(range_problem);
      // try a fast algorithm
      double result = [sqrt](../math/sqrt.html)(a * a + b * b);
      if (![fetestexcept](fetestexcept.html)(range_problem))  // no overflow or underflow
        return result;                   // return the fast result
      // do a more complicated calculation to avoid overflow or underflow
      int a_exponent,b_exponent;
      [frexp](../math/frexp.html)(a, &a_exponent);
      [frexp](../math/frexp.html)(b, &b_exponent);
     
      if (a_exponent - b_exponent > [DBL_MAX_EXP](../../types/limits.html))
        return [fabs](../math/fabs.html)(a) + [fabs](../math/fabs.html)(b);        // we can ignore the smaller value
      // scale so that fabs(a) is near 1
      double a_scaled = [scalbn](../math/scalbn.html)(a, -a_exponent);
      double b_scaled = [scalbn](../math/scalbn.html)(b, -a_exponent);
      // overflow and underflow is now impossible 
      result = [sqrt](../math/sqrt.html)(a_scaled * a_scaled + b_scaled * b_scaled);
      // undo scaling
      return [scalbn](../math/scalbn.html)(result, a_exponent);
    }
     
    int main(void)
    {
      // Normal case takes the fast route
      [printf](../../io/fprintf.html)("hypot(%f, %f) = %f\n", 3.0, 4.0, hypot_demo(3.0, 4.0));
      // Extreme case takes the slow but more accurate route
      [printf](../../io/fprintf.html)("hypot(%e, %e) = %e\n", [DBL_MAX](../../types/limits.html) / 2.0, 
                                    [DBL_MAX](../../types/limits.html) / 2.0, 
                                    hypot_demo([DBL_MAX](../../types/limits.html) / 2.0, [DBL_MAX](../../types/limits.html) / 2.0));
     
      return 0;
    }

Output: 
    
    
    hypot(3.000000, 4.000000) = 5.000000
    hypot(8.988466e+307, 8.988466e+307) = 1.271161e+308

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feclearexcept&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.6.2.1 The feclearexcept function (p: 209) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.6.2.1 The feclearexcept function (p: 190) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feclearexcept&action=edit&section=5 "Edit section: See also")] See also

[ fetestexcept](fetestexcept.html "c/numeric/fenv/fetestexcept")(C99) |  determines which of the specified floating-point status flags are set   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_fetestexcept&action=edit)  
---|---  
[C++ documentation](../../../cpp/numeric/fenv/feclearexcept.html "cpp/numeric/fenv/feclearexcept") for feclearexcept  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feclearexcept&oldid=133793](https://en.cppreference.com/mwiki/index.php?title=c/numeric/fenv/feclearexcept&oldid=133793)" 

From cppreference.com

< [c](../../../c.html "c")‎ | [numeric](../../numeric.html "c/numeric")‎ | [complex](../complex.html "c/numeric/complex")

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

[ Complex number arithmetic](../complex.html "c/numeric/complex")

Types and the imaginary constant  
---  
| [complex](complex.html "c/numeric/complex/complex")(C99)  
---  
**_Complex_I**(C99)  
[CMPLX](CMPLX.html "c/numeric/complex/CMPLX")(C11)  
  
| [imaginary](imaginary.html "c/numeric/complex/imaginary")(C99)  
---  
[_Imaginary_I](Imaginary_I.html "c/numeric/complex/Imaginary I")(C99)  
[I](I.html "c/numeric/complex/I")(C99)  
  
Manipulation  
| [cimag](cimag.html "c/numeric/complex/cimag")(C99)  
---  
[creal](creal.html "c/numeric/complex/creal")(C99)  
[carg](carg.html "c/numeric/complex/carg")(C99)  
  
| [cabs](cabs.html "c/numeric/complex/cabs")(C99)  
---  
[conj](conj.html "c/numeric/complex/conj")(C99)  
[cproj](cproj.html "c/numeric/complex/cproj")(C99)  
  
Power and exponential functions  
| [cexp](cexp.html "c/numeric/complex/cexp")(C99)  
---  
[clog](clog.html "c/numeric/complex/clog")(C99)  
  
| [cpow](cpow.html "c/numeric/complex/cpow")(C99)  
---  
[csqrt](csqrt.html "c/numeric/complex/csqrt")(C99)  
  
Trigonometric functions  
| [ccos](ccos.html "c/numeric/complex/ccos")(C99)  
---  
[csin](csin.html "c/numeric/complex/csin")(C99)  
[ctan](ctan.html "c/numeric/complex/ctan")(C99)  
  
| [cacos](cacos.html "c/numeric/complex/cacos")(C99)  
---  
[casin](casin.html "c/numeric/complex/casin")(C99)  
[catan](catan.html "c/numeric/complex/catan")(C99)  
  
Hyperbolic functions  
| [ccosh](ccosh.html "c/numeric/complex/ccosh")(C99)  
---  
[csinh](csinh.html "c/numeric/complex/csinh")(C99)  
[ctanh](ctanh.html "c/numeric/complex/ctanh")(C99)  
  
| [cacosh](cacosh.html "c/numeric/complex/cacosh")(C99)  
---  
[casinh](casinh.html "c/numeric/complex/casinh")(C99)  
[catanh](catanh.html "c/numeric/complex/catanh")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/navbar_content&action=edit)

Defined in header `[`<complex.h>`](../../header/complex.html "c/header/complex")` |  |   
---|---|---  
#define _Complex_I /* unspecified */ |  |  (since C99)  
| |   
  
The `_Complex_I` macro expands to a value of type const float _Complex with the value of the imaginary unit. 

## Contents

  * [1 Notes](Complex_I.html#Notes)
  * [2 Example](Complex_I.html#Example)
  * [3 References](Complex_I.html#References)
  * [4 See also](Complex_I.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/Complex_I&action=edit&section=1 "Edit section: Notes")] Notes

This macro may be used when I is not available, such as when it has been undefined by the application. 

Unlike [_Imaginary_I](Imaginary_I.html "c/numeric/complex/Imaginary I") and [CMPLX](CMPLX.html "c/numeric/complex/CMPLX"), use of this macro to construct a complex number may lose the sign of zero on the imaginary part. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/Complex_I&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <complex.h>
     
    #undef I
    #define J _Complex_I // can be used to redefine I
     
    int main(void)
    {
        // can be used to construct a complex number
        double [complex](complex.html) z = 1.0 + 2.0 * _Complex_I;
        [printf](../../io/fprintf.html)("1.0 + 2.0 * _Complex_I = %.1f%+.1fi\n", [creal](creal.html)(z), [cimag](cimag.html)(z));
     
        // sign of zero may not be preserved
        double [complex](complex.html) z2 = 0.0 + -0.0 * _Complex_I;
        [printf](../../io/fprintf.html)("0.0 + -0.0 * _Complex_I = %.1f%+.1fi\n", [creal](creal.html)(z2), [cimag](cimag.html)(z2));
    }

Possible output: 
    
    
    1.0 + 2.0 * _Complex_I = 1.0+2.0i
    0.0 + -0.0 * _Complex_I = 0.0+0.0i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/Complex_I&action=edit&section=3 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.3.1/4 _Complex_I (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.3.1/4 _Complex_I (p: 136) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.1/4 _Complex_I (p: 188) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.1/2 _Complex_I (p: 170) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/Complex_I&action=edit&section=4 "Edit section: See also")] See also

[ _Imaginary_I](Imaginary_I.html "c/numeric/complex/Imaginary I")(C99) |  the imaginary unit constant i   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_Imaginary_I&action=edit)  
---|---  
[ I](I.html "c/numeric/complex/I")(C99) |  the complex or imaginary unit constant i   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_I&action=edit)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/Complex_I&oldid=147475](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/Complex_I&oldid=147475)" 

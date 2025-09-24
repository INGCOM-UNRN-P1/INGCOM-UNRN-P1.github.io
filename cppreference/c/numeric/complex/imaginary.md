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
[_Complex_I](Complex_I.html "c/numeric/complex/Complex I")(C99)  
[CMPLX](CMPLX.html "c/numeric/complex/CMPLX")(C11)  
  
| **imaginary**(C99)  
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
#define imaginary _Imaginary |  |  (since C99)  
| |   
  
This macro expands to the keyword [`_Imaginary`](../../keyword/_Imaginary.html "c/keyword/ Imaginary"). 

This is a convenience macro that makes it possible to use float imaginary, double imaginary, and long double imaginary as an alternative way to write the three pure imaginary C types float _Imaginary, double _Imaginary, and long double _Imaginary

As with any pure imaginary number support in C, this macro is only defined if the imaginary numbers are supported. 

A compiler that defines __STDC_IEC_559_COMPLEX__ is not required to support imaginary numbers. POSIX recommends checking if the macro [_Imaginary_I](Imaginary_I.html) is defined to identify imaginary number support.  | (since C99)  
(until C11)  
---|---  
Imaginary numbers are supported if __STDC_IEC_559_COMPLEX__ is defined.  | (since C11)  
  
## Contents

  * [1 Notes](imaginary.html#Notes)
  * [2 Example](imaginary.html#Example)
  * [3 References](imaginary.html#References)
  * [4 See also](imaginary.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/imaginary&action=edit&section=1 "Edit section: Notes")] Notes

Programs are allowed to undefine and perhaps redefine the imaginary macro. 

To date, only Oracle C compiler is known to have implemented imaginary types. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/imaginary&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <complex.h>
     
    int main(void)
    {
        double imaginary i = -2.0*I; // pure imaginary
        double f = 1.0; // pure real
        double [complex](complex.html) z = f + i; // complex number
        [printf](../../io/fprintf.html)("z = %.1f%+.1fi\n", [creal](creal.html)(z), [cimag](cimag.html)(z));
    }

Output: 
    
    
    z = 1.0-2.0i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/imaginary&action=edit&section=3 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.3.1/5 imaginary (p: 136) 



    

  * G.6/1 imaginary (p: 391-392) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.1/5 imaginary (p: 188) 



    

  * G.6/1 imaginary (p: 537) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.1/3 imaginary (p: 170) 



    

  * G.6/1 imaginary (p: 472) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/imaginary&action=edit&section=4 "Edit section: See also")] See also

[ complex](complex.html "c/numeric/complex/complex")(C99) |  complex type macro   
(keyword macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_complex&action=edit)  
---|---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/imaginary&oldid=168850](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/imaginary&oldid=168850)" 

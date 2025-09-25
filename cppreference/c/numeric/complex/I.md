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
  
| [imaginary](imaginary.html "c/numeric/complex/imaginary")(C99)  
---  
[_Imaginary_I](Imaginary_I.html "c/numeric/complex/Imaginary I")(C99)  
**I**(C99)  
  
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
#define I /* unspecified */ |  |  (since C99)  
| |   
  
The `I` macro expands to either [_Complex_I](Complex_I.html "c/numeric/complex/Complex I") or [_Imaginary_I](Imaginary_I.html "c/numeric/complex/Imaginary I"). If the implementation does not support imaginary types, then the macro always expands to [_Complex_I](Complex_I.html "c/numeric/complex/Complex I"). 

A program may undefine and perhaps then redefine the macro I. 

## Contents

  * [1 Notes](I.html#Notes)
  * [2 Example](I.html#Example)
  * [3 References](I.html#References)
  * [4 See also](I.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/I&action=edit&section=1 "Edit section: Notes")] Notes

The macro is not named i, which is the name of the imaginary unit in mathematics, because the name `i` was already used in many C programs, e.g. as a loop counter variable. 

The macro I is often used to form complex numbers, with expressions such as x + y*I. If `I` is defined as [_Complex_I](Complex_I.html "c/numeric/complex/Complex I"), then such expression may create a value with imaginary component `+0.0` even when `y` is `-0.0`, which is significant for complex number functions with branch cuts. The macro [CMPLX](CMPLX.html "c/numeric/complex/CMPLX") provides a way to construct a complex number precisely. 

GCC provides a non-portable extension that allows imaginary constants to be specified with the suffix `i` on integer literals: `1.0fi`, `1.0i`, and `1.0li` are imaginary units in GNU C. A similar approach is part of standard C++ as of C++14 (`1.0if`, `1.0i`, and `1.0il` are the imaginary units in C++) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/I&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <complex.h>
     
    int main(void)
    {
        [printf](../../io/fprintf.html)("I = %.1f%+.1fi\n", [creal](creal.html)(I), [cimag](cimag.html)(I));
     
        double [complex](complex.html) z1 = I * I;     // imaginary unit squared
        [printf](../../io/fprintf.html)("I * I = %.1f%+.1fi\n", [creal](creal.html)(z1), [cimag](cimag.html)(z1));
     
        double [complex](complex.html) z = 1.0 + 2.0*I; // usual way to form a complex number pre-C11
        [printf](../../io/fprintf.html)("z = %.1f%+.1fi\n", [creal](creal.html)(z), [cimag](cimag.html)(z));
    }

Output: 
    
    
    I = 0.0+1.0i
    I * I = -1.0+0.0i
    z = 1.0+2.0i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/I&action=edit&section=3 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.1/6 I (p: 188) 



    

  * G.6/1 I (p: 537) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.1/4 I (p: 170) 



    

  * G.6/1 I (p: 472) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/I&action=edit&section=4 "Edit section: See also")] See also

[ _Imaginary_I](Imaginary_I.html "c/numeric/complex/Imaginary I")(C99) |  the imaginary unit constant i   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_Imaginary_I&action=edit)  
---|---  
[ _Complex_I](Complex_I.html "c/numeric/complex/Complex I")(C99) |  the complex unit constant i   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_Complex_I&action=edit)  
[ CMPLXCMPLXFCMPLXL](CMPLX.html "c/numeric/complex/CMPLX")(C11)(C11)(C11) |  constructs a complex number from real and imaginary parts   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_CMPLX&action=edit)  
[C++ documentation](../../../cpp/numeric/complex/operator%2522%2522i.html "cpp/numeric/complex/operator""i") for operator""i  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/I&oldid=77426](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/I&oldid=77426)" 

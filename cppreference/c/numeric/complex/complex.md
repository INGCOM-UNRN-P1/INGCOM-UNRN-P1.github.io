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
| **complex**(C99)  
---  
[_Complex_I](Complex_I.html "c/numeric/complex/Complex I")(C99)  
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
#define complex _Complex |  |  (since C99)  
| |   
  
This macro expands to a type specifier used to identify [complex types](../../language/arithmetic_types.html#Complex_floating_types "c/language/arithmetic types"). 

A program may undefine and perhaps then redefine the `complex` macro. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/complex&action=edit&section=1 "Edit section: Example")] Example

Run this code
    
    
    #include <complex.h>
    #include <math.h>
    #include <stdio.h>
     
    void print_complex(const char* note, complex z)
    {
        [printf](../../io/fprintf.html)("%s %f%+f*i\n", note, [creal](creal.html)(z), [cimag](cimag.html)(z));
    }
     
    int main(void)
    {
        double complex z = -1.0 + 2.0*I;
        print_complex("z  =", z);
        print_complex("z\u00B2 =", z * z);
        double complex z2 = [ccos](ccos.html)(2.0 * [carg](carg.html)(z)) + [csin](csin.html)(2.0 * [carg](carg.html)(z))*I;
        print_complex("z\u00B2 =", [cabs](cabs.html)(z) * [cabs](cabs.html)(z) * z2);
    }

Output: 
    
    
    z  = -1.000000+2.000000*i
    z² = -3.000000-4.000000*i
    z² = -3.000000-4.000000*i

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/complex&action=edit&section=2 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.3.1/4 complex (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.3.1/4 complex (p: 136) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.3.1/4 complex (p: 188) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.3.1/2 complex (p: 170) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/complex&action=edit&section=3 "Edit section: See also")] See also

[ imaginary](imaginary.html "c/numeric/complex/imaginary")(C99) |  imaginary type macro   
(keyword macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/complex/dsc_imaginary&action=edit)  
---|---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/complex&oldid=169480](https://en.cppreference.com/mwiki/index.php?title=c/numeric/complex/complex&oldid=169480)" 

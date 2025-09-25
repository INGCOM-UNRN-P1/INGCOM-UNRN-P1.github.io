From cppreference.com

< [c](../c.html "c")

[ C](../c.html "c")

[Compiler support](compiler_support.html "c/compiler support")  
---  
[Language](language.html "c/language")  
[Headers](header.html "c/header")  
[Type support](types.html "c/types")  
[Program utilities](program.html "c/program")  
[Variadic function support](variadic.html "c/variadic")  
[Error handling](error.html "c/error")  
[Dynamic memory management](memory.html "c/memory")  
[Strings library](string.html "c/string")  
[Algorithms](algorithm.html "c/algorithm")  
**Numerics**  
[Date and time utilities](chrono.html "c/chrono")  
[Input/output support](io.html "c/io")  
[Localization support](locale.html "c/locale")  
[Concurrency support](thread.html "c/thread") (C11)  
[Technical Specifications](experimental.html "c/experimental")  
[Symbol index](index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

**Numerics**

[Common mathematical functions](numeric/math.html "c/numeric/math")  
---  
[Floating-point environment](numeric/fenv.html "c/numeric/fenv") (C99)  
[Pseudo-random number generation](numeric/random.html "c/numeric/random")  
[Complex number arithmetic](numeric/complex.html "c/numeric/complex") (C99)  
[Type-generic math](numeric/tgmath.html "c/numeric/tgmath") (C99)  
[Bit manipulation](numeric.html#Bit_manipulation "c/numeric") (C23)  
[Checked integer arithmetic](numeric.html#Checked_integer_arithmetic "c/numeric") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/navbar_content&action=edit)

The C numerics library includes common mathematical functions and types, as well as support for random number generation. 

## Contents

  * [1 Common mathematical functions](numeric.html#Common_mathematical_functions)
  * [2 Floating-point environment](numeric.html#Floating-point_environment)
  * [3 Pseudo-random number generation](numeric.html#Pseudo-random_number_generation)
  * [4 Complex number arithmetic](numeric.html#Complex_number_arithmetic)
  * [5 Type-generic math](numeric.html#Type-generic_math)
  * [6 Bit manipulation (since C23)](numeric.html#Bit_manipulation_.28since_C23.29)
  * [7 Checked integer arithmetic (since C23)](numeric.html#Checked_integer_arithmetic_.28since_C23.29)
  * [8 See also](numeric.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric&action=edit&section=1 "Edit section: Common mathematical functions")] [Common mathematical functions](numeric/math.html "c/numeric/math")

The header [`<math.h>`](header/math.html "c/header/math") provides [standard C library mathematical functions](numeric/math.html "c/numeric/math") such as [fabs](numeric/math/fabs.html "c/numeric/math/fabs"), [sqrt](numeric/math/sqrt.html "c/numeric/math/sqrt"), and [sin](numeric/math/sin.html "c/numeric/math/sin"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric&action=edit&section=2 "Edit section: Floating-point environment")] [Floating-point environment](numeric/fenv.html "c/numeric/fenv")

The header [`<fenv.h>`](header/fenv.html "c/header/fenv") defines [flags and functions related to exceptional floating-point state](numeric/fenv.html "c/numeric/fenv"), such as overflow and division by zero. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric&action=edit&section=3 "Edit section: Pseudo-random number generation")] [Pseudo-random number generation](numeric/random.html "c/numeric/random")

The header [`<stdlib.h>`](header/stdlib.html "c/header/stdlib") also includes C-style random number generation via [srand](numeric/random/srand.html "c/numeric/random/srand") and [rand](numeric/random/rand.html "c/numeric/random/rand"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric&action=edit&section=4 "Edit section: Complex number arithmetic")] [Complex number arithmetic](numeric/complex.html "c/numeric/complex")

The header [`<complex.h>`](header/complex.html "c/header/complex") provides types and functions to work with [complex numbers](numeric/complex.html "c/numeric/complex"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric&action=edit&section=5 "Edit section: Type-generic math")] [Type-generic math](numeric/tgmath.html "c/numeric/tgmath")

The header [`<tgmath.h>`](header/tgmath.html "c/header/tgmath") provides some macros for a function which names XXX: 

  * real function: 



    

  * float variant `XXXf`
  * double variant `XXX`
  * long double variant `XXXl`



  * complex function: 



    

  * float variant `cXXXf`
  * double variant `cXXX`
  * long double variant `cXXXl`



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric&action=edit&section=6 "Edit section: Bit manipulation \(since C23\)")] [Bit manipulation](numeric/bit_manip.html "c/numeric/bit manip") (since C23)

The header [`<stdbit.h>`](header/stdbit.html "c/header/stdbit") provides macros and functions to work with the [byte ordering](numeric/bit_manip.html#Macros "c/numeric/bit manip") and [byte and bit representation](numeric/bit_manip.html#Functions "c/numeric/bit manip") of C objects. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric&action=edit&section=7 "Edit section: Checked integer arithmetic \(since C23\)")] Checked integer arithmetic (since C23)

Provides some [type-generic macros](language/generic.html "c/language/generic") for checked integer arithmetic: 

Defined in header `[`<stdckdint.h>`](header/stdckdint.html "c/header/stdckdint")`  
---  
[ ckd_add](numeric/ckd_add.html "c/numeric/ckd add")(C23) |  checked addition operation on two integers  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_ckd_add&action=edit)  
[ ckd_sub](numeric/ckd_sub.html "c/numeric/ckd sub")(C23) |  checked subtraction operation on two integers  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_ckd_sub&action=edit)  
[ ckd_mul](numeric/ckd_mul.html "c/numeric/ckd mul")(C23) |  checked multiplication operation on two integers  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_ckd_mul&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric&action=edit&section=8 "Edit section: See also")] See also

[C++ documentation](../cpp/numeric.html "cpp/numeric") for Numerics library  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric&oldid=180191](https://en.cppreference.com/mwiki/index.php?title=c/numeric&oldid=180191)" 

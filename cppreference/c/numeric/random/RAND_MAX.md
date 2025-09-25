From cppreference.com

< [c](../../../c.html "c")‎ | [numeric](../../numeric.html "c/numeric")‎ | [random](../random.html "c/numeric/random")

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

[ Pseudo-random number generation](../random.html "c/numeric/random")

[rand](rand.html "c/numeric/random/rand")  
---  
[srand](srand.html "c/numeric/random/srand")  
**RAND_MAX**  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/random/navbar_content&action=edit)

Defined in header `[`<stdlib.h>`](../../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
#define RAND_MAX /*implementation defined*/ |  |   
| |   
  
Expands to an integer constant expression equal to the maximum value returned by the function [rand()](rand.html "c/numeric/random/rand"). This value is implementation dependent. It's guaranteed that this value is at least 32767. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/RAND_MAX&action=edit&section=1 "Edit section: Example")] Example

Run this code
    
    
    #include <limits.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
     
    int main(void)
    {
        [srand](srand.html)([time](../../chrono/time.html)([NULL](../../types/NULL.html))); // use current time as seed for random generator
        [printf](../../io/fprintf.html)("RAND_MAX: %i\n", RAND_MAX);
        [printf](../../io/fprintf.html)("INT_MAX: %i\n", [INT_MAX](../../types/limits.html));
        [printf](../../io/fprintf.html)("Random value on [0,1]: %f\n", (double)[rand](rand.html)() / RAND_MAX);
    }

Possible output: 
    
    
    RAND_MAX: 2147483647
    INT_MAX: 2147483647
    Random value on [0,1]: 0.362509

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/RAND_MAX&action=edit&section=2 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22/3 General utilities <stdlib.h> (p: 248) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22/3 General utilities <stdlib.h> (p: 340) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20/3 General utilities <stdlib.h> (p: 306) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10 GENERAL UTILITIES <stdlib.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/RAND_MAX&action=edit&section=3 "Edit section: See also")] See also

[ rand](rand.html "c/numeric/random/rand") |  generates a pseudo-random number   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/random/dsc_rand&action=edit)  
---|---  
[ srand](srand.html "c/numeric/random/srand") |  seeds pseudo-random number generator   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/random/dsc_srand&action=edit)  
[C++ documentation](../../../cpp/numeric/random/RAND_MAX.html "cpp/numeric/random/RAND MAX") for RAND_MAX  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/RAND_MAX&oldid=140566](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/RAND_MAX&oldid=140566)" 

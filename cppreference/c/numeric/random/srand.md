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
**srand**  
[RAND_MAX](RAND_MAX.html "c/numeric/random/RAND MAX")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/random/navbar_content&action=edit)

Defined in header `[`<stdlib.h>`](../../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
void srand( unsigned seed ); |  |   
| |   
  
Seeds the pseudo-random number generator used by [rand()](rand.html "c/numeric/random/rand") with the value `seed`. 

If `rand()` is used before any calls to `srand()`, `rand()` behaves as if it was seeded with srand(1). 

Each time `rand()` is seeded with the same `seed`, it must produce the same sequence of values. 

`srand()` is not guaranteed to be thread-safe. 

## Contents

  * [1 Parameters](srand.html#Parameters)
  * [2 Return value](srand.html#Return_value)
  * [3 Notes](srand.html#Notes)
  * [4 Example](srand.html#Example)
  * [5 References](srand.html#References)
  * [6 See also](srand.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/srand&action=edit&section=1 "Edit section: Parameters")] Parameters

seed  |  \-  |  the seed value   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/srand&action=edit&section=2 "Edit section: Return value")] Return value

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/srand&action=edit&section=3 "Edit section: Notes")] Notes

Generally speaking, the pseudo-random number generator should only be seeded once, before any calls to `rand()`, and the start of the program. It should not be repeatedly seeded, or reseeded every time you wish to generate a new batch of pseudo-random numbers. 

Standard practice is to use the result of a call to [time](../../chrono/time.html)(0) as the seed. However, `time()` returns a [time_t](../../chrono/time_t.html "c/chrono/time t") value, and `time_t` is not guaranteed to be an integral type. In practice, though, every major implementation defines `time_t` to be an integral type, and this is also what POSIX requires. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/srand&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
     
    int main(void)
    {
        srand([time](../../chrono/time.html)([NULL](../../types/NULL.html))); //use current time as seed for random generator
        int random_variable = [rand](rand.html)();
        [printf](../../io/fprintf.html)("Random value on [0,%d]: %d\n", [RAND_MAX](RAND_MAX.html), random_variable);
    }

Possible output: 
    
    
    Random value on [0 2147483647]: 1373858591

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/srand&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.2.2 The srand function (p: 252-253) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.2.2 The srand function (p: 346-347) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.2.2 The srand function (p: 312-313) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.2.2 The srand function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/srand&action=edit&section=6 "Edit section: See also")] See also

[ rand](rand.html "c/numeric/random/rand") |  generates a pseudo-random number   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/random/dsc_rand&action=edit)  
---|---  
[ RAND_MAX](RAND_MAX.html "c/numeric/random/RAND MAX") |  maximum possible value generated by [rand](rand.html)()   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/random/dsc_RAND_MAX&action=edit)  
[C++ documentation](../../../cpp/numeric/random/srand.html "cpp/numeric/random/srand") for srand  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/srand&oldid=140570](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/srand&oldid=140570)" 

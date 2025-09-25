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

**rand**  
---  
[srand](srand.html "c/numeric/random/srand")  
[RAND_MAX](RAND_MAX.html "c/numeric/random/RAND MAX")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/random/navbar_content&action=edit)

Defined in header `[`<stdlib.h>`](../../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
int rand(); |  |   
| |   
  
Returns a pseudo-random integer value between ​0​ and [RAND_MAX](RAND_MAX.html "c/numeric/random/RAND MAX") (`0` and `RAND_MAX` included). 

[srand()](srand.html "c/numeric/random/srand") seeds the pseudo-random number generator used by `rand()`. If `rand()` is used before any calls to `srand()`, `rand()` behaves as if it was seeded with [srand](srand.html)(1). Each time `rand()` is seeded with `srand()`, it must produce the same sequence of values. 

`rand()` is not guaranteed to be thread-safe. 

## Contents

  * [1 Parameters](rand.html#Parameters)
  * [2 Return value](rand.html#Return_value)
  * [3 Notes](rand.html#Notes)
  * [4 Example](rand.html#Example)
  * [5 References](rand.html#References)
  * [6 See also](rand.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/rand&action=edit&section=1 "Edit section: Parameters")] Parameters

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/rand&action=edit&section=2 "Edit section: Return value")] Return value

Pseudo-random integer value between ​0​ and [RAND_MAX](RAND_MAX.html "c/numeric/random/RAND MAX"), inclusive. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/rand&action=edit&section=3 "Edit section: Notes")] Notes

There are no guarantees as to the quality of the random sequence produced. In the past, some implementations of `rand()` have had serious shortcomings in the randomness, distribution and period of the sequence produced (in one well-known example, the low-order bit simply alternated between `1` and `0` between calls). `rand()` is not recommended for serious random-number generation needs, like cryptography. 

POSIX requires that the period of the pseudo-random number generator used by `rand` be at least 232  
. 

POSIX offered a thread-safe version of rand called `rand_r`, which is obsolete in favor of the [`drand48`](http://pubs.opengroup.org/onlinepubs/9699919799/functions/drand48.html) family of functions. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/rand&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
     
    int main(void)
    {
        [srand](srand.html)([time](../../chrono/time.html)([NULL](../../types/NULL.html))); // use current time as seed for random generator
        int random_variable = rand();
        [printf](../../io/fprintf.html)("Random value on [0,%d]: %d\n", [RAND_MAX](RAND_MAX.html), random_variable);
     
        // roll a 6-sided die 20 times
        for (int n=0; n != 20; ++n) {
            int x = 7;
            while(x > 6) 
                x = 1 + rand()/(([RAND_MAX](RAND_MAX.html) + 1u)/6); // Note: 1+rand()%6 is biased
            [printf](../../io/fprintf.html)("%d ",  x); 
        }
    }

Possible output: 
    
    
    Random value on [0,2147483647]: 448749574
    3 1 3 1 4 2 2 1 3 6 4 4 3 1 6 2 3 2 6 1

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/rand&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.2.1 The rand function (p: 252) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.2.1 The rand function (p: 346) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.2.1 The rand function (p: 312) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.2.1 The rand function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/rand&action=edit&section=6 "Edit section: See also")] See also

[ srand](srand.html "c/numeric/random/srand") |  seeds pseudo-random number generator   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/random/dsc_srand&action=edit)  
---|---  
[ RAND_MAX](RAND_MAX.html "c/numeric/random/RAND MAX") |  maximum possible value generated by rand()   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/random/dsc_RAND_MAX&action=edit)  
[C++ documentation](../../../cpp/numeric/random/rand.html "cpp/numeric/random/rand") for rand  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/rand&oldid=140569](https://en.cppreference.com/mwiki/index.php?title=c/numeric/random/rand&oldid=140569)" 

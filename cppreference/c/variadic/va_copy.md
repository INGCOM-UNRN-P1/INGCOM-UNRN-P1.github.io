From cppreference.com

< [c](../../c.html "c")‎ | [variadic](../variadic.html "c/variadic")

[ C](../../c.html "c")

[Compiler support](../compiler_support.html "c/compiler support")  
---  
[Language](../language.html "c/language")  
[Headers](../header.html "c/header")  
[Type support](../types.html "c/types")  
[Program utilities](../program.html "c/program")  
[Variadic function support](../variadic.html "c/variadic")  
[Error handling](../error.html "c/error")  
[Dynamic memory management](../memory.html "c/memory")  
[Strings library](../string.html "c/string")  
[Algorithms](../algorithm.html "c/algorithm")  
[Numerics](../numeric.html "c/numeric")  
[Date and time utilities](../chrono.html "c/chrono")  
[Input/output support](../io.html "c/io")  
[Localization support](../locale.html "c/locale")  
[Concurrency support](../thread.html "c/thread") (C11)  
[Technical Specifications](../experimental.html "c/experimental")  
[Symbol index](../index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

[ Variadic functions](../variadic.html "c/variadic")

[va_start](va_start.html "c/variadic/va start")  
---  
[va_arg](va_arg.html "c/variadic/va arg")  
**va_copy**(C99)  
[va_end](va_end.html "c/variadic/va end")  
[va_list](va_list.html "c/variadic/va list")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/navbar_content&action=edit)

Defined in header `[`<stdarg.h>`](../header/stdarg.html "c/header/stdarg")` |  |   
---|---|---  
void va_copy( va_list dest, va_list src ); |  |  (since C99)  
| |   
  
The `va_copy` macro copies `src` to `dest`. 

va_end should be called on `dest` before the function returns or any subsequent re-initialization of `dest` (via calls to va_start or va_copy). 

## Contents

  * [1 Parameters](va_copy.html#Parameters)
  * [2 Expanded value](va_copy.html#Expanded_value)
  * [3 Example](va_copy.html#Example)
  * [4 References](va_copy.html#References)
  * [5 See also](va_copy.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_copy&action=edit&section=1 "Edit section: Parameters")] Parameters

dest  |  \-  |  an instance of the va_list type to initialize   
---|---|---  
src  |  \-  |  the source va_list that will be used to initialize `dest`  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_copy&action=edit&section=2 "Edit section: Expanded value")] Expanded value

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_copy&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdarg.h>
    #include <math.h>
     
    double sample_stddev(int count, ...) 
    {
        /* Compute the mean with args1. */
        double sum = 0;
        va_list args1;
        va_start(args1, count);
        va_list args2;
        va_copy(args2, args1);   /* copy va_list object */
        for (int i = 0; i < count; ++i) {
            double num = va_arg(args1, double);
            sum += num;
        }
        va_end(args1);
        double mean = sum / count;
     
        /* Compute standard deviation with args2 and mean. */
        double sum_sq_diff = 0;
        for (int i = 0; i < count; ++i) {
            double num = va_arg(args2, double);
            sum_sq_diff += (num-mean) * (num-mean);
        }
        va_end(args2);
        return [sqrt](../numeric/math/sqrt.html)(sum_sq_diff / count);
    }
     
    int main(void) 
    {
        [printf](../io/fprintf.html)("%f\n", sample_stddev(4, 25.0, 27.3, 26.9, 25.7));
    }

Possible output: 
    
    
    0.920258

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_copy&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.16.1.2 The va_copy macro (p: 270) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.15.1.2 The va_copy macro (p: 250) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_copy&action=edit&section=5 "Edit section: See also")] See also

[ va_arg](va_arg.html "c/variadic/va arg") |  accesses the next variadic function argument   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_arg&action=edit)  
---|---  
[ va_end](va_end.html "c/variadic/va end") |  ends traversal of the variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_end&action=edit)  
[ va_list](va_list.html "c/variadic/va list") |  holds the information needed by va_start, va_arg, va_end, and va_copy   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_list&action=edit)  
[ va_start](va_start.html "c/variadic/va start") |  enables access to variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_start&action=edit)  
[C++ documentation](../../cpp/utility/variadic/va_copy.html "cpp/utility/variadic/va copy") for va_copy  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_copy&oldid=117388](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_copy&oldid=117388)" 

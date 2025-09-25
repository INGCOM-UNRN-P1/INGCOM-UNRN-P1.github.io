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
**va_arg**  
[va_copy](va_copy.html "c/variadic/va copy")(C99)  
[va_end](va_end.html "c/variadic/va end")  
[va_list](va_list.html "c/variadic/va list")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/navbar_content&action=edit)

Defined in header `[`<stdarg.h>`](../header/stdarg.html "c/header/stdarg")` |  |   
---|---|---  
T va_arg( va_list ap, T ); |  |   
| |   
  
The `va_arg` macro expands to an expression of type T that corresponds to the next parameter from the va_list ap. 

Prior to calling `va_arg`, ap must be initialized by a call to either va_start or va_copy, with no intervening call to va_end. Each invocation of the `va_arg` macro modifies ap to point to the next variable argument. 

If the type of the next argument in ap (after promotions) is not [compatible](../language/compatible_type.html#Compatible_types "c/language/type") with T, the behavior is undefined, unless: 

  * one type is a signed integer type, the other type is the corresponding unsigned integer type, and the value is representable in both types; or 
  * one type is pointer to void and the other is a pointer to a character type. 



If `va_arg` is called when there are no more arguments in ap, the behavior is undefined. 

## Contents

  * [1 Parameters](va_arg.html#Parameters)
  * [2 Expanded value](va_arg.html#Expanded_value)
  * [3 Example](va_arg.html#Example)
  * [4 References](va_arg.html#References)
  * [5 See also](va_arg.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_arg&action=edit&section=1 "Edit section: Parameters")] Parameters

ap  |  \-  |  an instance of the va_list type   
---|---|---  
T  |  \-  |  the type of the next parameter in ap  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_arg&action=edit&section=2 "Edit section: Expanded value")] Expanded value

the next variable parameter in ap

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_arg&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <math.h>
    #include <stdarg.h>
    #include <stdio.h>
     
    double stddev(int count, ...)
    {
        double sum = 0;
        double sum_sq = 0;
        va_list args;
        va_start(args, count);
        for (int i = 0; i < count; ++i)
        {
            double num = va_arg(args, double);
            sum += num;
            sum_sq += num*num;
        }
        va_end(args);
        return [sqrt](../numeric/math/sqrt.html)(sum_sq / count - (sum / count) * (sum / count));
    }
     
    int main(void)
    {
        [printf](../io/fprintf.html)("%f\n", stddev(4, 25.0, 27.3, 26.9, 25.7));
    }

Output: 
    
    
    0.920258

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_arg&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.16.2.2 The va_arg macro (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.16.1.1 The va_arg macro (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.16.1.1 The va_arg macro (p: 269-270) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.15.1.1 The va_arg macro (p: 249-250) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.8.1.2 The va_arg macro 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_arg&action=edit&section=5 "Edit section: See also")] See also

[ va_copy](va_copy.html "c/variadic/va copy")(C99) |  makes a copy of the variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_copy&action=edit)  
---|---  
[ va_end](va_end.html "c/variadic/va end") |  ends traversal of the variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_end&action=edit)  
[ va_list](va_list.html "c/variadic/va list") |  holds the information needed by va_start, va_arg, va_end, and va_copy   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_list&action=edit)  
[ va_start](va_start.html "c/variadic/va start") |  enables access to variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_start&action=edit)  
[C++ documentation](../../cpp/utility/variadic/va_arg.html "cpp/utility/variadic/va arg") for va_arg  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_arg&oldid=179734](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_arg&oldid=179734)" 

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

**va_start**  
---  
[va_arg](va_arg.html "c/variadic/va arg")  
[va_copy](va_copy.html "c/variadic/va copy")(C99)  
[va_end](va_end.html "c/variadic/va end")  
[va_list](va_list.html "c/variadic/va list")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/navbar_content&action=edit)

Defined in header `[`<stdarg.h>`](../header/stdarg.html "c/header/stdarg")` |  |   
---|---|---  
void va_start( va_list ap, parmN ); |  | (until C23)  
void va_start( va_list ap, ... ); |  |  (since C23)  
| |   
  
The `va_start` macro enables access to the variable arguments following the named argument `parmN`(until C23). 

`va_start` shall be invoked with an instance to a valid va_list object `ap` before any calls to va_arg. 

If `parmN` is declared with `register` storage class specifier, with an array type, with a function type, or with a type not compatible with the type that results from default argument promotions, the behavior is undefined.  | (until C23)  
---|---  
Only the first argument passed to `va_start` is evaluated. Any additional arguments are neither expanded nor used in any way.  | (since C23)  
  
## Contents

  * [1 Parameters](va_start.html#Parameters)
  * [2 Expanded value](va_start.html#Expanded_value)
  * [3 Example](va_start.html#Example)
  * [4 References](va_start.html#References)
  * [5 See also](va_start.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_start&action=edit&section=1 "Edit section: Parameters")] Parameters

ap  |  \-  |  an instance of the va_list type   
---|---|---  
parmN  |  \-  |  the named parameter preceding the first variable parameter   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_start&action=edit&section=2 "Edit section: Expanded value")] Expanded value

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_start&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdarg.h>
     
    int add_nums_C99(int count, ...)
    {
        int result = 0;
        va_list args;
        va_start(args, count); // count can be omitted since C23
     
        for (int i = 0; i < count; ++i) {
            result += va_arg(args, int);
        }
     
        va_end(args);
        return result;
    }
     
    #if __STDC_VERSION__ > 201710L
    // Same as above, valid since C23
    int add_nums_C23(...)
    {
        int result = 0;
        va_list args;
        va_start(args);
     
        int count = va_arg(args, int);
        for (int i = 0; i < count; ++i) {
            result += va_arg(args, int);
        }
     
        va_end(args);
        return result;
    }
    #endif
     
    int main(void)
    {
        [printf](../io/fprintf.html)("%d\n", add_nums_C99(4, 25, 25, 50, 50));
    #if __STDC_VERSION__ > 201710L
        [printf](../io/fprintf.html)("%d\n", add_nums_C23(4, 25, 25, 50, 50));
    #endif
    }

Possible output: 
    
    
    150
    150

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_start&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.16.1.4 The va_start macro (p: 198-199) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.16.1.4 The va_start macro (p: 271-272) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.15.1.4 The va_start macro (p: 251-252) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.8.1.1 The va_start macro 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_start&action=edit&section=5 "Edit section: See also")] See also

[ va_arg](va_arg.html "c/variadic/va arg") |  accesses the next variadic function argument   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_arg&action=edit)  
---|---  
[ va_copy](va_copy.html "c/variadic/va copy")(C99) |  makes a copy of the variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_copy&action=edit)  
[ va_end](va_end.html "c/variadic/va end") |  ends traversal of the variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_end&action=edit)  
[ va_list](va_list.html "c/variadic/va list") |  holds the information needed by va_start, va_arg, va_end, and va_copy   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_list&action=edit)  
[C++ documentation](../../cpp/utility/variadic/va_start.html "cpp/utility/variadic/va start") for va_start  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_start&oldid=142169](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_start&oldid=142169)" 

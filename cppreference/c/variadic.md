From cppreference.com

< [c](../c.html "c")

[ C](../c.html "c")

[Compiler support](compiler_support.html "c/compiler support")  
---  
[Language](language.html "c/language")  
[Headers](header.html "c/header")  
[Type support](types.html "c/types")  
[Program utilities](program.html "c/program")  
**Variadic function support**  
[Error handling](error.html "c/error")  
[Dynamic memory management](memory.html "c/memory")  
[Strings library](string.html "c/string")  
[Algorithms](algorithm.html "c/algorithm")  
[Numerics](numeric.html "c/numeric")  
[Date and time utilities](chrono.html "c/chrono")  
[Input/output support](io.html "c/io")  
[Localization support](locale.html "c/locale")  
[Concurrency support](thread.html "c/thread") (C11)  
[Technical Specifications](experimental.html "c/experimental")  
[Symbol index](index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

**Variadic functions**

[va_start](variadic/va_start.html "c/variadic/va start")  
---  
[va_arg](variadic/va_arg.html "c/variadic/va arg")  
[va_copy](variadic/va_copy.html "c/variadic/va copy")(C99)  
[va_end](variadic/va_end.html "c/variadic/va end")  
[va_list](variadic/va_list.html "c/variadic/va list")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/navbar_content&action=edit)

Variadic functions are functions (e.g. [printf](io/fprintf.html "c/io/fprintf")) which take a variable number of arguments. 

The declaration of a variadic function uses an ellipsis as the last parameter, e.g. int [printf](io/fprintf.html)(const char* format, ...);. See [variadic arguments](language/variadic.html "c/language/variadic") for additional detail on the syntax and automatic argument conversions. 

Accessing the variadic arguments from the function body uses the following library facilities: 

| 

## Contents

  * [1 Types](variadic.html#Types)
  * [2 Macros](variadic.html#Macros)
  * [3 Example](variadic.html#Example)
  * [4 References](variadic.html#References)
  * [5 See also](variadic.html#See_also)

  
---  
  
#####  Types   
  
[ va_list](variadic/va_list.html "c/variadic/va list") |  holds the information needed by va_start, va_arg, va_end, and va_copy   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_list&action=edit)  
  
#####  Macros   
  
Defined in header `[`<stdarg.h>`](header/stdarg.html "c/header/stdarg")`  
[ va_start](variadic/va_start.html "c/variadic/va start") |  enables access to variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_start&action=edit)  
[ va_arg](variadic/va_arg.html "c/variadic/va arg") |  accesses the next variadic function argument   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_arg&action=edit)  
[ va_copy](variadic/va_copy.html "c/variadic/va copy")(C99) |  makes a copy of the variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_copy&action=edit)  
[ va_end](variadic/va_end.html "c/variadic/va end") |  ends traversal of the variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_end&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic&action=edit&section=1 "Edit section: Example")] Example

Print values of different types.

Run this code
    
    
    #include <stdarg.h>
    #include <stdio.h>
     
    void simple_printf(const char* fmt, ...)
    {
        va_list args;
     
        for (va_start(args, fmt); *fmt != '\0'; ++fmt)
        {
            switch(*fmt)
            {
                case 'd':
                {
                    int i = va_arg(args, int);
                    [printf](io/fprintf.html)("%d\n", i);
                    break;
                }
                case 'c':
                {
                    // A 'char' variable will be promoted to 'int'
                    // A character literal in C is already 'int' by itself
                    int c = va_arg(args, int);
                    [printf](io/fprintf.html)("%c\n", c);
                    break;
                }
                case 'f':
                {
                    double d = va_arg(args, double);
                    [printf](io/fprintf.html)("%f\n", d);
                    break;
                }
                default:
                    [puts](io/puts.html)("Unknown formatter!");
                    goto END;
            }
        }
    END:
        va_end(args);
    }
     
    int main(void)
    {
        simple_printf("dcff", 3, 'a', 1.969, 42.5);
    }

Output: 
    
    
    3
    a
    1.969000
    42.50000

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic&action=edit&section=2 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.16 Variable arguments <stdarg.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.16 Variable arguments <stdarg.h> (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.16 Variable arguments <stdarg.h> (p: 269-272) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.15 Variable arguments <stdarg.h> (p: 249-252) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.8 VARIABLE ARGUMENTS <stdarg.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic&action=edit&section=3 "Edit section: See also")] See also

[C++ documentation](../cpp/utility/variadic.html "cpp/utility/variadic") for Variadic functions  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/variadic&oldid=180120](https://en.cppreference.com/mwiki/index.php?title=c/variadic&oldid=180120)" 

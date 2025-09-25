From cppreference.com

< [c](../../c.html "c")‎ | [language](../language.html "c/language")

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

[ C language](../language.html "c/language")

[Basic concepts](basic_concepts.html "c/language/basic concepts")  
---  
[ Keywords](../keyword.html "c/keyword")  
[ Preprocessor](../preprocessor.html "c/preprocessor")  
[ Statements](statements.html "c/language/statements")  
[ Expressions](operators.html "c/language/expressions")  
[ Initialization](initialization.html "c/language/initialization")  
[ Declarations](declarations.html "c/language/declarations")  
[ Functions](functions.html "c/language/functions")  
Miscellaneous  
[ History of C](history.html "c/language/history")  
[Technical Specifications](../experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

[ Functions](functions.html "c/language/functions")

[ function declaration](function_declaration.html "c/language/function declaration")  
---  
[ function definition](function_definition.html "c/language/function definition")  
**variadic arguments**  
[inline](inline.html "c/language/inline")(C99)  
[_Noreturn](noreturn.html "c/language/ Noreturn")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/functions/navbar_content&action=edit)

Variadic functions are functions that may be called with different number of arguments. 

Only prototyped [function declarations](function_declaration.html "c/language/function declaration") may be variadic. This is indicated by the parameter of the form ... which must appear last in the parameter list and must follow at least one named parameter(until C23). The ellipsis parameter and the proceeding parameter must be delimited by ,. 
    
    
    // Prototyped declaration
    int printx(const char* fmt, ...); // function declared this way
    printx("hello world");     // may be called with one
    printx("a=%d b=%d", a, b); // or more arguments
     
    int printz(...); // OK since C23 and in C++
    // Error until C23: ... must follow at least one named parameter
     
    // int printy(..., const char* fmt); // Error: ... must be the last
    // int printa(const char* fmt...);   // Error in C: ',' is required; OK in C++

At the [function call](operator_other.html#Function_call "c/language/operator other"), each argument that is a part of the variable argument list undergoes special implicit conversions known as [default argument promotions](conversion.html#Default_argument_promotions "c/language/conversion"). 

Within the body of a function that uses variadic arguments, the values of these arguments may be accessed using the [`<stdarg.h>` library facilities](../variadic.html "c/variadic"): 

Defined in header `[`<stdarg.h>`](../header/stdarg.html "c/header/stdarg")`  
---  
[ va_start](../variadic/va_start.html "c/variadic/va start") |  enables access to variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_start&action=edit)  
[ va_arg](../variadic/va_arg.html "c/variadic/va arg") |  accesses the next variadic function argument   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_arg&action=edit)  
[ va_copy](../variadic/va_copy.html "c/variadic/va copy")(C99) |  makes a copy of the variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_copy&action=edit)  
[ va_end](../variadic/va_end.html "c/variadic/va end") |  ends traversal of the variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_end&action=edit)  
[ va_list](../variadic/va_list.html "c/variadic/va list") |  holds the information needed by va_start, va_arg, va_end, and va_copy   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_list&action=edit)  
  
## Contents

  * [1 Notes](variadic.html#Notes)
  * [2 Example](variadic.html#Example)
  * [3 References](variadic.html#References)
  * [4 See also](variadic.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/variadic&action=edit&section=1 "Edit section: Notes")] Notes

Although old-style (prototype-less) [function declarations](function_declaration.html "c/language/function declaration") allow the subsequent function calls to use any number of arguments, they are not allowed to be variadic (as of C89). The definition of such function must specify a fixed number of parameters and cannot use the `stdarg.h` macros. 
    
    
    // old-style declaration, removed in C23
    int printx(); // function declared this way
    printx("hello world");     // may be called with one
    printx("a=%d b=%d", a, b); // or more arguments
    // the behavior of at least one of these calls is undefined, depending on
    // the number of parameters the function is defined to take

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/variadic&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <time.h>
    #include <stdarg.h>
     
    void tlog(const char* fmt,...)
    {
        char msg[50];
        [strftime](../chrono/strftime.html)(msg, sizeof msg, "%T", [localtime](../chrono/localtime.html)(&([time_t](../chrono/time_t.html)){[time](../chrono/time.html)([NULL](../types/NULL.html))}));
        [printf](../io/fprintf.html)("[%s] ", msg);
        va_list args;
        va_start(args, fmt);
        [vprintf](../io/vfprintf.html)(fmt, args);
        va_end(args);
    }
     
    int main(void)
    {
       tlog("logging %d %d %d...\n", 1, 2, 3);
    }

Output: 
    
    
    [10:21:38] logging 1 2 3...

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/variadic&action=edit&section=3 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.6.3/9 Function declarators (including prototypes) (p: 96) 



    

  * 7.16 Variable arguments <stdarg.h> (p: 197-199) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.6.3/9 Function declarators (including prototypes) (p: 133) 



    

  * 7.16 Variable arguments <stdarg.h> (p: 269-272) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.7.5.3/9 Function declarators (including prototypes) (p: 119) 



    

  * 7.15 Variable arguments <stdarg.h> (p: 249-252) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.5.4.3/5 Function declarators (including prototypes) 



    

  * 4.8 VARIABLE ARGUMENTS <stdarg.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/variadic&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/variadic_arguments.html "cpp/language/variadic arguments") for Variadic arguments  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/variadic&oldid=142118](https://en.cppreference.com/mwiki/index.php?title=c/language/variadic&oldid=142118)" 

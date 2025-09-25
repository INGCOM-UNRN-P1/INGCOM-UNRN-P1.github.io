From cppreference.com

< [c](../../c.html "c")‎ | [preprocessor](../preprocessor.html "c/preprocessor")

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

[Basic concepts](../language/basic_concepts.html "c/language/basic concepts")  
---  
[ Keywords](../keyword.html "c/keyword")  
[ Preprocessor](../preprocessor.html "c/preprocessor")  
[ Statements](../language/statements.html "c/language/statements")  
[ Expressions](../language/operators.html "c/language/expressions")  
[ Initialization](../language/initialization.html "c/language/initialization")  
[ Declarations](../language/declarations.html "c/language/declarations")  
[ Functions](../language/functions.html "c/language/functions")  
Miscellaneous  
[ History of C](../language/history.html "c/language/history")  
[Technical Specifications](../experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

[ Preprocessor](../preprocessor.html "c/preprocessor")

[#if#ifdef#ifndef#else#elif#elifdef#elifndef#endif](conditional.html "c/preprocessor/conditional")(C23)(C23)  
---  
[#define#undef#,## operators](replace.html "c/preprocessor/replace")  
[#include__has_include](include.html "c/preprocessor/include")(C23)  
**#error #warning**(C23)  
[#pragma_Pragma](impl.html "c/preprocessor/impl")(C99)  
[#line](line.html "c/preprocessor/line")  
[#embed__has_embed](embed.html "c/preprocessor/embed")(C23)(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/preprocessor/navbar_content&action=edit)

Shows the given error message and renders the program ill-formed, or given warning message without affect the validity of the program(since C23). 

## Contents

  * [1 Syntax](warning.html#Syntax)
  * [2 Explanation](warning.html#Explanation)
  * [3 Notes](warning.html#Notes)
  * [4 Example](warning.html#Example)
  * [5 References](warning.html#References)
  * [6 See also](warning.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/error&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**#error**` diagnostic-message |  (1)  |   
`**#warning**` diagnostic-message |  (2)  |  (since C23)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/error&action=edit&section=2 "Edit section: Explanation")] Explanation

1) After encountering the `#error` directive, an implementation displays the message diagnostic-message and renders the program ill-formed (the compilation stops).

2) Same as (1), except that the validity of the program is not affected and the compilation continues.

diagnostic-message can consist of several words not necessarily in quotes. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/error&action=edit&section=3 "Edit section: Notes")] Notes

Before its standardization in C23, `#warning` has been provided by many compilers in all modes as a conforming extension. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/error&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #if __STDC__ != 1
    #  error "Not a standard compliant compiler"
    #endif
     
    #if __STDC_VERSION__ >= 202311L
    #  warning "Using #warning as a standard feature"
    #endif
     
    #include <stdio.h>
     
    int main (void)
    {
        [printf](../io/fprintf.html)("The compiler used conforms to the ISO C Standard !!");
    }

Possible output: 
    
    
    The compiler used conforms to the ISO C Standard !!

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/error&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.10.5 Error directive (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.10.5 Error directive (p: 126-127) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.10.5 Error directive (p: 174) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.10.5 Error directive (p: 159) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.8.5 Error directive 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/error&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/preprocessor/warning.html "cpp/preprocessor/error") for Diagnostic directives  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/error&oldid=179531](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/error&oldid=179531)" 

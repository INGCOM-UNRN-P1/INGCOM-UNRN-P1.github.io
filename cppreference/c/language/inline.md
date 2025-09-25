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
[ variadic arguments](variadic.html "c/language/variadic")  
**inline**(C99)  
[_Noreturn](noreturn.html "c/language/ Noreturn")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/functions/navbar_content&action=edit)

Declares an [inline function](https://en.wikipedia.org/wiki/inline_function "enwiki:inline function"). 

## Contents

  * [1 Syntax](inline.html#Syntax)
  * [2 Explanation](inline.html#Explanation)
  * [3 Keywords](inline.html#Keywords)
  * [4 Notes](inline.html#Notes)
  * [5 Example](inline.html#Example)
  * [6 References](inline.html#References)
  * [7 See also](inline.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/inline&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
inline function_declaration |  |  (since C99)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/inline&action=edit&section=2 "Edit section: Explanation")] Explanation

The intent of the `**inline**` specifier is to serve as a hint for the compiler to perform optimizations, such as [function inlining](https://en.wikipedia.org/wiki/inline_expansion "enwiki:inline expansion"), which usually require the definition of a function to be visible at the call site. The compilers can (and usually do) ignore presence or absence of the `inline` specifier for the purpose of optimization. 

If the compiler performs function inlining, it replaces a call of that function with its body, avoiding the overhead of a function call (placing data on stack and retrieving the result), which may result in a larger executable as the code for the function has to be repeated multiple times. The result is similar to [function-like macros](../preprocessor/replace.html "c/preprocessor/replace"), except that identifiers and macros used in the function refer to the definitions visible at the point of definition, not at the point of call. 

Regardless of whether inlining takes place, the following semantics of inline functions are guaranteed: 

Any function with internal linkage may be declared `static inline` with no other restrictions. 

A non-static inline function cannot define a non-const function-local static and cannot refer to a file-scope static. 
    
    
    static int x;
     
    inline void f(void)
    {
        static int n = 1; // error: non-const static in a non-static inline function
        int k = x; // error: non-static inline function accesses a static variable
    }

If a non-static function is declared `inline`, then it must be defined in the same translation unit. The inline definition that does not use `extern` is not externally visible and does not prevent other translation units from defining the same function. This makes the `**inline**` keyword an alternative to `static` for defining functions inside header files, which may be included in multiple translation units of the same program. 

If a function is declared `inline` in some translation units, it does not need to be declared `inline` everywhere: at most one translation unit may also provide a regular, non-inline non-static function, or a function declared `extern inline`. This one translation unit is said to provide the _external definition_. In order to avoid undefined behavior, one external definition must exist in the program if the name of the function with external linkage is used in an expression, see [one definition rule](extern.html#One_definition_rule "c/language/extern"). 

The address of an inline function with external linkage is always the address of the external definition, but when this address is used to make a function call, it's unspecified whether the _inline definition_ (if present in the translation unit) or the _external definition_ is called. The static objects defined within an inline definition are distinct from the static objects defined within the external definition: 
    
    
    inline const char *saddr(void) // the inline definition for use in this file
    {
        static const char name[] = "saddr";
        return name;
    }
     
    int compare_name(void)
    {
        return saddr() == saddr(); // unspecified behavior, one call could be external
    }
     
    extern const char *saddr(void); // an external definition is generated, too

A C program should not depend on whether the inline version or the external version of a function is called, otherwise the behavior is unspecified. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/inline&action=edit&section=3 "Edit section: Keywords")] Keywords

[`inline`](../keyword/inline.html "c/keyword/inline")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/inline&action=edit&section=4 "Edit section: Notes")] Notes

The `inline` keyword was adopted from C++, but in C++, if a function is declared `inline`, it must be declared `inline` in every translation unit, and also every definition of an inline function must be exactly the same (in C, the definitions may be different, and depending on the differences only results in unspecified behavior). On the other hand, C++ allows non-const function-local statics and all function-local statics from different definitions of an inline function are the same in C++ but distinct in C. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/inline&action=edit&section=5 "Edit section: Example")] Example

Header file "test.h" 
    
    
    #ifndef TEST_H_INCLUDED
    #define TEST_H_INCLUDED
     
    inline int sum(int a, int b)
    {
        return a + b;
    }
     
    #endif

Source file "sum.c" 
    
    
    #include "test.h"
     
    extern inline int sum(int a, int b); // provides external definition

Source file "test1.c" 
    
    
    #include <stdio.h>
    #include "test.h"
     
    extern int f(void);
     
    int main(void)
    {
        [printf](../io/fprintf.html)("%d\n", sum(1, 2) + f());
    }

Source file "test2.c" 
    
    
    #include "test.h"
     
    int f(void)
    {
        return sum(3, 4);
    }

Output 
    
    
    10

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/inline&action=edit&section=6 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.4 Function specifiers (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.4 Function specifiers (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.4 Function specifiers (p: 125-127) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.7.4 Function specifiers (p: 112-113) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/inline&action=edit&section=7 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/inline.html "cpp/language/inline") for `inline` specifier  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/inline&oldid=159889](https://en.cppreference.com/mwiki/index.php?title=c/language/inline&oldid=159889)" 

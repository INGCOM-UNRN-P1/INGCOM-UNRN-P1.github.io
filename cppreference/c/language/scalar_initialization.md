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

[ Initialization](initialization.html "c/language/initialization")

[ Explicit initialization](initialization.html#Explicit_initialization "c/language/initialization")  
---  
[ Implicit initialization](initialization.html#Implicit_initialization "c/language/initialization")  
[ Empty initialization](initialization.html#Empty_initialization "c/language/initialization")  
**Scalar initialization**  
[ Array initialization](array_initialization.html "c/language/array initialization")  
[ Struct and union initialization](struct_initialization.html "c/language/struct initialization")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/initialization/navbar_content&action=edit)

When [initializing](initialization.html "c/language/initialization") an object of [scalar type](compatible_type.html#Type_groups "c/language/type"), the initializer must be a single expression 

The initializer for a scalar (an object of integer type including booleans and enumerated types, floating type including complex and imaginary, and pointer type including pointer to function) must be a single expression, optionally enclosed in braces, or an empty initializer(since C23):   
  
---  
`**=**` expression |  (1)  |   
`**=**` `**{**` expression `**}**` |  (2)  |   
`**=**` `**{**` `**}**` |  (3)  |  (since C23)  
  
1,2) The expression is evaluated, and its value, after [conversion as if by assignment](conversion.html "c/language/conversion") to the type of the object, becomes the initial value of the object being initialized.

3) The object is [empty-initialized](initialization.html#Empty_initialization "c/language/initialization"), i.e. initialized to numeric zero for an object of an arithmetic or enumeration type, or null pointer value for an object of a pointer type.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/scalar_initialization&action=edit&section=1 "Edit section: Notes")] Notes

Because of the rules that apply to conversions as if by assignment, [`const`](const.html "c/language/const") and [`volatile`](volatile.html "c/language/volatile") qualifiers on the declared type are ignored when determining which type to convert the expression to. 

See [initialization](initialization.html "c/language/initialization") for the rules that apply when no initializer is used. 

As with all other initializations, expression must be a [constant expression](constant_expression.html "c/language/constant expression") when initializing objects of static or thread-local [storage duration](storage_class_specifiers.html "c/language/storage duration"). 

The expression cannot be a [comma operator](operator_other.html#Comma_operator "c/language/operator other") (unless parenthesized) because the comma at the top level would be interpreted as the beginning of the next declarator. 

When initializing objects of floating-point type, all computations for the objects with automatic [storage duration](storage_class_specifiers.html "c/language/storage duration") are done as-if at execution time and are affected by the [current rounding](../numeric/fenv/FE_round.html "c/numeric/fenv/FE round"); floating-point errors are reported as specified in [`math_errhandling`](../numeric/math/math_errhandling.html "c/numeric/math/math errhandling"). For objects of static and thread-local storage duration, computations are done as-if at compile time, and no exceptions are raised: 
    
    
    void f(void)
    {
    #pragma STDC FENV_ACCESS ON
        static float v = 1.1e75; // does not raise exceptions: static init
     
        float u[] = { 1.1e75 }; // raises FE_INEXACT
        float w = 1.1e75;       // raises FE_INEXACT
     
        double x = 1.1e75; // may raise FE_INEXACT (depends on FLT_EVAL_METHOD)
        float y = 1.1e75f; // may raise FE_INEXACT (depends on FLT_EVAL_METHOD)
     
        long double z = 1.1e75; // does not raise exceptions (conversion is exact)
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/scalar_initialization&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <stdbool.h>
    int main(void)
    {
        bool b = true;
        const double d = 3.14;
        int k = 3.15; // conversion from double to int
        int n = {12}, // optional braces
           *p = &n,   // non-constant expression OK for automatic variable
           (*fp)(void) = main;
        enum {RED, BLUE} e = RED; // enumerations are scalar types as well
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/scalar_initialization&action=edit&section=3 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.9/11 Initialization (p: 101) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.9/11 Initialization (p: 140) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.7.8/11 Initialization (p: 126) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 6.5.7 Initialization 



Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/scalar_initialization&oldid=139692](https://en.cppreference.com/mwiki/index.php?title=c/language/scalar_initialization&oldid=139692)" 

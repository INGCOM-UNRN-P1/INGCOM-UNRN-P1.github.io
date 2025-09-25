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
**Functions**  
Miscellaneous  
[ History of C](history.html "c/language/history")  
[Technical Specifications](../experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

**Functions**

[ function declaration](function_declaration.html "c/language/function declaration")  
---  
[ function definition](function_definition.html "c/language/function definition")  
[ variadic arguments](variadic.html "c/language/variadic")  
[inline](inline.html "c/language/inline")(C99)  
[_Noreturn](noreturn.html "c/language/ Noreturn")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/functions/navbar_content&action=edit)

A function is a C language construct that associates a [compound statement](statements.html#Compound_statements "c/language/statements") (the function body) with an [identifier](identifiers.html "c/language/identifier") (the function name). Every C program begins execution from the [main function](main_function.html "c/language/main function"), which either terminates, or invokes other, user-defined or library functions. 
    
    
    // function definition.
    // defines a function with the name "sum" and with the body "{ return x+y; }"
    int sum(int x, int y) 
    {
        return x + y;
    }

A function is introduced by a [function declaration](function_declaration.html "c/language/function declaration") or a [function definition](function_definition.html "c/language/function definition"). 

Functions may accept zero or more _parameters_ , which are initialized from the _arguments_ of a [function call operator](operator_other.html#Function_call "c/language/operator other"), and may return a value to its caller by means of the [return statement](return.html "c/language/return"). 
    
    
    int n = sum(1, 2); // parameters x and y are initialized with the arguments 1 and 2

The body of a function is provided in a [function definition](function_definition.html "c/language/function definition"). Each non-[inline](inline.html "c/language/inline")(since C99) function that is used in an expression (unless [unevaluated](operators.html#Unevaluated_expressions "c/language/expressions")) must be [defined only once](extern.html#One_definition_rule "c/language/extern") in a program. 

There are no nested functions (except where allowed through non-standard compiler extensions): each function definition must appear at file scope, and functions have no access to the local variables from the caller: 
    
    
    int main(void) // the main function definition
    {
        int sum(int, int); // function declaration (may appear at any scope)
        int x = 1;  // local variable in main
        sum(1, 2); // function call
     
    //    int sum(int a, int b) // error: no nested functions
    //    {
    //        return  a + b; 
    //    }
    }
    int sum(int a, int b) // function definition
    {
    //    return x + a + b; //  error: main's x is not accessible within sum
        return a + b;
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/functions&action=edit&section=1 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.7.4 Function declarators (including prototypes) (p: TBD) 



    

  * 6.9.2 Function definitions (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.6.3 Function declarators (including prototypes) (p: 96-98) 



    

  * 6.9.1 Function definitions (p: 113-115) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.6.3 Function declarators (including prototypes) (p: 133-136) 



    

  * 6.9.1 Function definitions (p: 156-158) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.7.5.3 Function declarators (including prototypes) (p: 118-121) 



    

  * 6.9.1 Function definitions (p: 141-143) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.5.4.3 Function declarators (including prototypes) 



    

  * 3.7.1 Function definitions 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/functions&action=edit&section=2 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/function.html "cpp/language/function") for Declaring functions  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/functions&oldid=179341](https://en.cppreference.com/mwiki/index.php?title=c/language/functions&oldid=179341)" 

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
**function definition**  
[ variadic arguments](variadic.html "c/language/variadic")  
[inline](inline.html "c/language/inline")(C99)  
[_Noreturn](noreturn.html "c/language/ Noreturn")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/functions/navbar_content&action=edit)

A function definition associates the function body (a sequence of declarations and statements) with the function name and parameter list. Unlike [function declaration](function_declaration.html "c/language/function declaration"), function definitions are allowed at file scope only (there are no nested functions). 

C supports two different forms of function definitions:   
  
---  
attr-spec-seq(optional) specifiers-and-qualifiers parameter-list-declarator function-body |  (1)  |   
specifiers-and-qualifiers identifier-list-declarator declaration-list function-body |  (2)  |  (until C23)  
  
where 

attr-spec-seq |  \-  |  (C23)an optional list of [attributes](attributes.html "c/language/attributes"), applied to the function   
---|---|---  
specifiers-and-qualifiers |  \-  |  a combination of 

  * [type specifiers](declarations.html "c/language/declarations") that, possibly modified by the declarator, form the _return type_
  * [storage class specifiers](storage_class_specifiers.html "c/language/storage duration"), which determine the linkage of the identifier (`static`, `extern`, or none) 
  * function specifiers [`inline`](inline.html "c/language/inline"), [`_Noreturn`](noreturn.html "c/language/ Noreturn"), or none 

  
parameter-list-declarator |  \-  |  a declarator for a function type which uses a [parameter list](function_declaration.html "c/language/function declaration") to designate function parameters   
identifier-list-declarator |  \-  |  a declarator for a function type which uses a [identifier list](function_declaration.html "c/language/function declaration") to designate function parameters   
declaration-list |  \-  |  sequence of declarations that declare every identifier in identifier-list-declarator. These declarations cannot use initializers and the only [storage-class specifier](storage_class_specifiers.html "c/language/storage duration") allowed is register.   
function-body |  \-  |  a [compound statement](statements.html#Compound_statements "c/language/statements"), that is a brace-enclosed sequence of declarations and statements, that is executed whenever this function is called   
  
1) New-style (C89) function definition. This definition both introduces the function itself and serves as a function prototype for any future [function call expressions](operator_other.html#Function_call "c/language/operator other"), forcing conversions from argument expressions to the declared parameter types. 
    
    
    int max(int a, int b)
    {
        return a>b?a:b;
    }
     
    double g(void)
    {
        return 0.1;
    }

2) (until C23) Old-style (K&R) function definition. This definition does not behave as a prototype and any future [function call expressions](operator_other.html#Function_call "c/language/operator other") will perform default argument promotions. 
    
    
    int max(a, b)
    int a, b;
    {
        return a>b?a:b;
    }
    double g()
    {
        return 0.1;
    }

## Contents

  * [1 Explanation](function_definition.html#Explanation)
  * [2 __func__](function_definition.html#func)
  * [3 Notes](function_definition.html#Notes)
  * [4 Defect reports](function_definition.html#Defect_reports)
  * [5 References](function_definition.html#References)
  * [6 See also](function_definition.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/function_definition&action=edit&section=1 "Edit section: Explanation")] Explanation

As with [function declarations](function_declaration.html "c/language/function declaration"), the return type of the function, determined by the type specifier in specifiers-and-qualifiers and possibly modified by the declarator as usual in [declarations](declarations.html "c/language/declarations"), must be a complete non-array object type or the type void. If the return type would be cvr-qualified, it is adjusted to its unqualified version for the purpose of constructing the function type. 
    
    
    void f(char *s) { [puts](../io/puts.html)(s); } // return type is void
    int sum(int a, int b) { return a+b; } // return type is int
    int (*foo(const void *p))[3] { // return type is pointer to array of 3 int
        return [malloc](../memory/malloc.html)(sizeof(int[3]));
    }

As with [function declarations](function_declaration.html "c/language/function declaration"), the types of the parameters are adjusted from functions to pointers and from arrays to pointers for the purpose of constructing the function type and the top-level cvr-qualifiers of all parameter types are ignored for the purpose of determining [compatible function type](compatible_type.html#Compatible_types "c/language/type"). 

Unlike [function declarations](function_declaration.html "c/language/function declaration"), unnamed formal parameters are not allowed (otherwise, there would be conflicts in old-style (K&R) function definitions), they must be named even if they are not used within the function. The only exception is the special parameter list (void).  | (until C23)  
---|---  
Formal parameters may be unnamed in function definitions, because old-style (K&R) function definitions has been removed. Unnamed parameters are inaccessible by name within the function body.  | (since C23)  
      
    
    int f(int, int); // declaration
    // int f(int, int) { return 7; } // Error until C23, OK since C23
    int f(int a, int b) { return 7; } // definition
    int g(void) { return 8; } // OK: void doesn't declare a parameter

Within the function body, every named parameter is an [lvalue](value_category.html "c/language/value category") expression, they have automatic [storage duration](storage_class_specifiers.html "c/language/storage duration") and [block scope](scope.html "c/language/scope"). The layout of the parameters in memory (or if they are stored in memory at all) is unspecified: it is a part of the [calling convention](https://en.wikipedia.org/wiki/Calling_convention "enwiki:Calling convention"). 
    
    
    int main(int ac, char **av)
    {
        ac = 2; // parameters are lvalues
        av = (char *[]){"abc", "def", [NULL](../types/NULL.html)};
        f(ac, av);
    }

See [function call operator](operator_other.html#Function_call "c/language/operator other") for other details on the mechanics of a function call and [return](return.html "c/language/return") for returning from functions. 

###  __func__

Within every function-body, the special predefined variable __func__ with block scope and static storage duration is available, as if defined immediately after the opening brace by 
    
    
    static const char __func__[] = "function name";

This special identifier is sometimes used in combination with the [predefined macro constants](../preprocessor/replace.html "c/preprocessor/replace") __FILE__ and __LINE__, for example, by [assert](../error/assert.html "c/error/assert").  | (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/function_definition&action=edit&section=3 "Edit section: Notes")] Notes

The argument list must be explicitly present in the declarator, it cannot be inherited from a typedef 
    
    
    typedef int p(int q, int r); // p is a function type int(int, int)
    p f { return q + r; } // Error

In C89, specifiers-and-qualifiers was optional, and if omitted, the return type of the function defaulted to int (possibly amended by the declarator). In addition, old-style definition didn't require a declaration for every parameter in declaration-list. Any parameter whose declaration was missing had type int
    
    
    max(a, b) // a and b have type int, return type is int
    {
        return a>b?a:b;
    }

| (until C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/function_definition&action=edit&section=4 "Edit section: Defect reports")] Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards. 

DR  | Applied to  | Behavior as published  | Correct behavior   
---|---|---|---  
[DR 423](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_423) | C89  | the return type might be qualified  | the return type is implicitly disqualified   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/function_definition&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.9.1 Function definitions (p: 113-115) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.9.1 Function definitions (p: 156-158) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.9.1 Function definitions (p: 141-143) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.7.1 Function definitions 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/function_definition&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/function.html#Function_definition "cpp/language/function") for Function definition  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/function_definition&oldid=174898](https://en.cppreference.com/mwiki/index.php?title=c/language/function_definition&oldid=174898)" 

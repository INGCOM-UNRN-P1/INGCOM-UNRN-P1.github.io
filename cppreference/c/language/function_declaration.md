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

**function declaration**  
---  
[ function definition](function_definition.html "c/language/function definition")  
[ variadic arguments](variadic.html "c/language/variadic")  
[inline](inline.html "c/language/inline")(C99)  
[_Noreturn](noreturn.html "c/language/ Noreturn")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/functions/navbar_content&action=edit)

A function declaration introduces an [identifier](identifiers.html "c/language/identifier") that designates a function and, optionally, specifies the types of the function parameters (the _prototype_). Function declarations (unlike [definitions](function_definition.html "c/language/function definition")) may appear at block scope as well as file scope. 

## Contents

  * [1 Syntax](function_declaration.html#Syntax)
  * [2 Explanation](function_declaration.html#Explanation)
  * [3 Notes](function_declaration.html#Notes)
  * [4 Defect reports](function_declaration.html#Defect_reports)
  * [5 References](function_declaration.html#References)
  * [6 See also](function_declaration.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/function_declaration&action=edit&section=1 "Edit section: Syntax")] Syntax

In the [declaration grammar](declarations.html "c/language/declarations") of a function declaration, the type-specifier sequence, possibly modified by the declarator, designates the _return type_ (which may be any type other than array or function type), and the declarator has one of three(until C23)two(since C23) forms:   
  
---  
noptr-declarator `**(**` parameter-list `**)**` attr-spec-seq(optional) |  (1)  |   
noptr-declarator `**(**` identifier-list `**)**` attr-spec-seq(optional) |  (2)  |  (until C23)  
noptr-declarator `**(**` `**)**` attr-spec-seq(optional) |  (3)  |   
  
where 

noptr-declarator |  \-  |  any [declarator](declarations.html#Declarators "c/language/declarations") except unparenthesized pointer declarator. The identifier that is contained in this declarator is the identifier that becomes the function designator.   
---|---|---  
parameter-list |  \-  |  either the single keyword void or a comma-separated list of _parameters_ , which may end with an [ellipsis parameter](variadic.html "c/language/variadic")  
identifier-list |  \-  |  comma-separated list of identifiers, only possible if this declarator is used as part of old-style [function definition](function_definition.html "c/language/function definition")  
attr-spec-seq |  \-  |  (C23) an optional list of [attributes](attributes.html "c/language/attributes"), applied to the function type   
  
1) New-style (C89) function declaration. This declaration both introduces the function designator itself and also serves as a function prototype for any future [function call expressions](operator_other.html#Function_call "c/language/operator other"), forcing conversions from argument expressions to the declared parameter types and compile-time checks for the number of arguments. 
    
    
    int max(int a, int b); // declaration
    int n = max(12.01, 3.14); // OK, conversion from double to int

2) (until C23) Old-style (K&R) function definition. This declaration does not introduce a prototype and any future [function call expressions](operator_other.html#Function_call "c/language/operator other") will perform default argument promotions and will invoke undefined behavior if the number of arguments doesn't match the number of parameters. 
    
    
    int max(a, b)
        int a, b; // definition expects ints; the second call is undefined
    {
        return a > b ? a : b;
    }
     
    int n = max(true, (char)'a'); // calls max with two int args (after promotions)
     
    int n = max(12.01f, 3.14); // calls max with two double args (after promotions)

3) Non-prototype function declaration. This declaration does not introduce a prototype(until C23). A new style function declaration equivalent to the parameter-list void(since C23).

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/function_declaration&action=edit&section=2 "Edit section: Explanation")] Explanation

The return type of the function, determined by the type specifier in specifiers-and-qualifiers and possibly modified by the declarator as usual in [declarations](declarations.html "c/language/declarations"), must be a non-array object type or the type void. If the function declaration is not a definition, the return type can be [incomplete](compatible_type.html#Incomplete_types "c/language/type"). The return type cannot be cvr-qualified: any qualified return type is adjusted to its unqualified version for the purpose of constructing the function type. 
    
    
    void f(char *s);                    // return type is void
    int sum(int a, int b);              // return type of sum is int.
    int (*foo(const void *p))[3];       // return type is pointer to array of 3 int
     
    double const bar(void);             // declares function of type double(void)
    double (*barp)(void) = bar;         // OK: barp is a pointer to double(void)
    double const (*barpc)(void) = barp; // OK: barpc is also a pointer to double(void)

Function declarators can be combined with other declarators as long as they can share their type specifiers and qualifiers 
    
    
    int f(void), *fip(), (*pfi)(), *ap[3]; // declares two functions and two objects
    inline int g(int), n; // Error: inline qualifier is for functions only
    typedef int array_t[3];
    array_t a, h(); // Error: array type cannot be a return type for a function

If a function declaration appears outside of any function, the identifier it introduces has [file scope](scope.html "c/language/scope") and [external linkage](storage_class_specifiers.html "c/language/storage duration"), unless static is used or an earlier static declaration is visible. If the declaration occurs inside another function, the identifier has block scope (and also either internal or external linkage). 
    
    
    int main(void)
    {
        int f(int); // external linkage, block scope
        f(1); // definition needs to be available somewhere in the program
    }

The parameters in a declaration that is not part of a [function definition](function_definition.html "c/language/function definition")(until C23) do not need to be named: 
    
    
    int f(int, int); // declaration
    // int f(int, int) { return 7; } // Error: parameters must be named in definitions
    // This definition is allowed since C23

Each parameter in a parameter-list is a [declaration](declarations.html "c/language/declarations") that introduced a single variable, with the following additional properties: 

  * the identifier in the declarator is optional (except if this function declaration is part of a function definition)(until C23)


    
    
    int f(int, double); // OK
    int g(int a, double b); // also OK
    // int f(int, double) { return 1; } // Error: definition must name parameters
    // This definition is allowed since C23

  * the only [storage class specifier](storage_class_specifiers.html "c/language/storage duration") allowed for parameters is register, and it is ignored in function declarations that are not definitions 


    
    
    int f(static int x); // Error
    int f(int [static 10]); // OK (array index static is not a storage class specifier)

  * any parameter of array type is adjusted to the corresponding pointer type, which may be qualified if there are qualifiers between the square brackets of the array declarator(since C99)


    
    
    int f(int[]); // declares int f(int*)
    int g(const int[10]); // declares int g(const int*)
    int h(int[const volatile]); // declares int h(int * const volatile)
    int x(int[*]); // declares int x(int*)

  * any parameter of function type is adjusted to the corresponding pointer type 


    
    
    int f(char g(double)); // declares int f(char (*g)(double))
    int h(int(void)); // declares int h(int (*)(void))

  * the parameter list may terminate with `**, ...**` or be `**...**`(since C23), see [variadic functions](variadic.html "c/language/variadic") for details. 


    
    
    int f(int, ...);

  * parameters cannot have type void (but can have type pointer to void). The special parameter list that consists entirely of the keyword void is used to declare functions that take no parameters. 


    
    
    int f(void); // OK
    int g(void x); // Error

  * any identifier that appears in a parameter list that could be treated as a typedef name or as a parameter name is treated as a typedef name: int f([size_t](../types/size_t.html), [uintptr_t](../types/integer.html)) is parsed as a new-style declarator for a function taking two unnamed parameters of type [size_t](../types/size_t.html) and [uintptr_t](../types/integer.html), not an old-style declarator that begins the definition of a function taking two parameters named "[size_t](../types/size_t.html)" and "[uintptr_t](../types/integer.html)". 
  * parameters may have incomplete type and may use the VLA notation [*](since C99) (except that in a [function definition](function_definition.html "c/language/function definition"), the parameter types after array-to-pointer and function-to-pointer adjustment must be complete). 

[Attribute specifier sequences](attributes.html "c/language/attributes") can also applied to function parameters.  | (since C23)  
---|---  
  
See [function call operator](operator_other.html#Function_call "c/language/operator other") for other details on the mechanics of a function call and [return](return.html "c/language/return") for returning from functions. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/function_declaration&action=edit&section=3 "Edit section: Notes")] Notes

Unlike in C++, the declarators f() and f(void) have different meaning: the declarator f(void) is a new-style (prototype) declarator that declares a function that takes no parameters. The declarator f() is a declarator that declares a function that takes _unspecified_ number of parameters (unless used in a function definition) 
    
    
    int f(void); // declaration: takes no parameters
    int g(); // declaration: takes unknown parameters
     
    int main(void) {
        f(1); // compile-time error
        g(2); // undefined behavior
    }
     
    int f(void) { return 1; } // actual definition
    int g(a,b,c,d) int a,b,c,d; { return 2; } // actual definition

| (until C23)  
---|---  
  
Unlike in a [function definition](function_definition.html "c/language/function definition"), the parameter list may be inherited from a typedef 
    
    
    typedef int p(int q, int r); // p is a function type int(int, int)
    p f; // declares int f(int, int)

In C89, specifiers-and-qualifiers was optional, and if omitted, the return type of the function defaulted to int (possibly amended by the declarator). 
    
    
    *f() { // function returning int*
       return [NULL](../types/NULL.html);
    }

| (until C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/function_declaration&action=edit&section=4 "Edit section: Defect reports")] Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards. 

DR  | Applied to  | Behavior as published  | Correct behavior   
---|---|---|---  
[DR 423](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_423) | C89  | the return type might be qualified  | the return type is implicitly disqualified   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/function_declaration&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.7.4 Function declarators (including prototypes) (p: 130-132) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.6.3 Function declarators (including prototypes) (p: 96-98) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.6.3 Function declarators (including prototypes) (p: 133-136) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.7.5.3 Function declarators (including prototypes) (p: 118-121) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.5.4.3 Function declarators (including prototypes) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/function_declaration&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/function.html "cpp/language/function") for Function declaration  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/function_declaration&oldid=183166](https://en.cppreference.com/mwiki/index.php?title=c/language/function_declaration&oldid=183166)" 

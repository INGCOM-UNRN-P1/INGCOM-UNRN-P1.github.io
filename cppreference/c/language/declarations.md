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
**Declarations**  
[ Functions](functions.html "c/language/functions")  
Miscellaneous  
[ History of C](history.html "c/language/history")  
[Technical Specifications](../experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

**Declarations**

[Pointer](pointer.html "c/language/pointer")  
---  
[Array](array.html "c/language/array")  
[enum](enum.html "c/language/enum")  
[struct](struct.html "c/language/struct")  
[union](union.html "c/language/union")  
[Bit-field](bit_field.html "c/language/bit field")  
[Atomic types](atomic.html "c/language/atomic") (C11)  
[const](const.html "c/language/const")  
[constexpr](constexpr.html "c/language/constexpr")(C23)  
[volatile](volatile.html "c/language/volatile")  
[restrict](restrict.html "c/language/restrict")(C99)  
[Alignment specifiers](alignas.html "c/language/ Alignas")  
[Storage duration and linkage](storage_class_specifiers.html "c/language/storage duration")  
[External and tentative definitions](extern.html "c/language/extern")  
[typedef](typedef.html "c/language/typedef")  
[Static assertions](static_assert.html "c/language/ Static assert")  
[Attributes](attributes.html "c/language/attributes") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/declarations/navbar_content&action=edit)

A _declaration_ is a C language construct that introduces one or more [identifiers](identifiers.html "c/language/identifier") into the program and specifies their meaning and properties. 

Declarations may appear in any scope. Each declaration ends with a semicolon (just like [a statement](statements.html "c/language/statements")) and consists of two(until C23)three(since C23) distinct parts:   
  
---  
specifiers-and-qualifiers declarators-and-initializers ﻿(optional) `**;**` |  (1)  |   
attr-spec-seq specifiers-and-qualifiers declarators-and-initializers `**;**` |  (2)  |  (since C23)  
attr-spec-seq `**;**` |  (3)  |  (since C23)  
  
where 

specifiers-and-qualifiers |  \-  |  whitespace-separated list of, in any order, 

  * type specifiers: 



    

  * void
  * the name of an [arithmetic type](arithmetic_types.html "c/language/arithmetic types")
  * the name of an [atomic type](atomic.html "c/language/atomic")
  * a name earlier introduced by a [typedef](typedef.html "c/language/typedef") declaration 
  * [`struct`](struct.html "c/language/struct"), [`union`](union.html "c/language/union"), or [`enum`](enum.html "c/language/enum") specifier 
  * a [typeof](typeof_unqual.html "c/language/typeof") specifier (since C23)



  * zero or one storage-class specifiers: [`typedef`](typedef.html "c/language/typedef"), [`constexpr`](constexpr.html "c/language/constexpr"), [`auto`](auto.html "c/language/auto"), [register, static, extern, `_Thread_local`](storage_class_specifiers.html "c/language/storage duration")
  * zero or more type qualifiers: [`const`](const.html "c/language/const"), [`volatile`](volatile.html "c/language/volatile"), [`restrict`](restrict.html "c/language/restrict"), [`_Atomic`](atomic.html "c/language/atomic")
  * (only when declaring functions), zero or more function specifiers: [`inline`](inline.html "c/language/inline"), [`_Noreturn`](noreturn.html "c/language/ Noreturn")
  * zero or more alignment specifiers: [`_Alignas`](alignas.html "c/language/ Alignas")(since C11)(until C23)[`alignas`](alignas.html "c/language/alignas")(since C23)

  
  
---|---|---  
declarators-and-initializers |  \-  |  comma-separated list of declarators (each declarator provides additional type information and/or the identifier to declare). Declarators may be accompanied by [initializers](initialization.html "c/language/initialization"). The [enum](enum.html "c/language/enum"), [struct](struct.html "c/language/struct"), and [union](union.html "c/language/union") declarations may omit declarators, in which case they only introduce the enumeration constants and/or tags.   
attr-spec-seq |  \-  |  (C23)optional list of [attributes](attributes.html "c/language/attributes"), applied to the declared entities, or forms an attribute declaration if appears alone.   
  
1,2) Simple declaration. Introduces one or more identifiers which denotes objects, functions, struct/union/enum tags, typedefs, or enumeration constants.

3) Attribute declaration. Does not declares any identifier, and has implementation-defined meaning if the meaning is not specified by the standard.

For example, 
    
    
    int a, *b=[NULL](../types/NULL.html); // "int" is the type specifier,
                    // "a" is a declarator
                    // "*b" is a declarator and NULL is its initializer
    const int *f(void); // "int" is the type specifier
                        // "const" is the type qualifier
                        // "*f(void)" is the declarator
    enum COLOR {RED, GREEN, BLUE} c; // "enum COLOR {RED, GREEN, BLUE}" is the type specifier
                                     // "c" is the declarator

The type of each identifier introduced in a declaration is determined by a combination of the type specified by the type specifier and the type modifications applied by its declarator. The type of a variable might also be inferred if auto specifier is used.(since C23)

[Attributes](attributes.html "c/language/attributes")(since C23) may appear in specifiers-and-qualifiers, in which case they apply to the type determined by the preceding specifiers. 

## Contents

  * [1 Declarators](declarations.html#Declarators)
  * [2 Definitions](declarations.html#Definitions)
  * [3 Redeclaration](declarations.html#Redeclaration)
  * [4 Notes](declarations.html#Notes)
  * [5 References](declarations.html#References)
  * [6 See also](declarations.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/declarations&action=edit&section=1 "Edit section: Declarators")] Declarators

Each declarator is one of the following:   
  
---  
identifier attr-spec-seq ﻿(optional) |  (1)  |   
`**(**` declarator `**)**` |  (2)  |   
`*****` attr-spec-seq ﻿(optional) qualifiers ﻿(optional) declarator |  (3)  |   
noptr-declarator `**[**` `**static**`(optional) qualifiers ﻿(optional) expression `**]**` noptr-declarator `**[**` qualifiers ﻿(optional) `*****` `**]**` |  (4)  |   
noptr-declarator `**(**` parameters-or-identifiers `**)**` |  (5)  |   
  
1) the identifier that this declarator introduces.

2) any declarator may be enclosed in parentheses; this is required to introduce pointers to arrays and pointers to functions.

3) [pointer declarator](pointer.html "c/language/pointer"): the declaration S * cvr D; declares `D` as a cvr-qualified pointer to the type determined by `S`.

4) [array declarator](array.html "c/language/array"): the declaration S D[N] declares `D` as an array of `N` objects of the type determined by `S`. noptr-declarator is any other declarator except unparenthesized pointer declarator.

5) [function declarator](function_declaration.html "c/language/function declaration"): the declaration S D(params) declared `D` as a function taking the parameters `params` and returning `S`. noptr-declarator is any other declarator except unparenthesized pointer declarator.

The reasoning behind this syntax is that when the identifier declared by the declarator appears in an expression of the same form as the declarator, it would have the type specified by the type specifier sequence. 
    
    
    struct C
    {
        int member; // "int" is the type specifier
                    // "member" is the declarator
    } obj, *pObj = &obj;
    // "struct C { int member; }" is the type specifier
    // declarator "obj" defines an object of type struct C
    // declarator "*pObj" declares a pointer to C,
    // initializer "= &obj" provides the initial value for that pointer
     
    int a = 1, *p = [NULL](../types/NULL.html), f(void), (*pf)(double);
    // the type specifier is "int"
    // declarator "a" defines an object of type int
    //   initializer "=1" provides its initial value
    // declarator "*p" defines an object of type pointer to int
    //   initializer "=NULL" provides its initial value
    // declarator "f(void)" declares a function taking void and returning int
    // declarator "(*pf)(double)" defines an object of type pointer
    //   to function taking double and returning int
     
    int (*(*foo)(double))[3] = [NULL](../types/NULL.html);
    // the type specifier is int
    // 1. declarator "(*(*foo)(double))[3]" is an array declarator:
    //    the type declared is "/nested declarator/ array of 3 int"
    // 2. the nested declarator is "*(*foo)(double))", which is a pointer declarator
    //    the type declared is "/nested declarator/ pointer to array of 3 int"
    // 3. the nested declarator is "(*foo)(double)", which is a function declarator
    //    the type declared is "/nested declarator/ function taking double and returning
    //        pointer to array of 3 int"
    // 4. the nested declarator is "(*foo)" which is a (parenthesized, as required by
    //        function declarator syntax) pointer declarator.
    //    the type declared is "/nested declarator/ pointer to function taking double
    //        and returning pointer to array of 3 int"
    // 5. the nested declarator is "foo", which is an identifier.
    // The declaration introduces the identifier "foo" to refer to an object of type
    // "pointer to function taking double and returning pointer to array of 3 int"
    // The initializer "= NULL" provides the initial value of this pointer.
     
    // If "foo" is used in an expression of the form of the declarator, its type would be
    // int.
    int x = (*(*foo)(1.2))[0];

The end of every declarator that is not part of another declarator is a [sequence point](eval_order.html "c/language/eval order"). 

In all cases, attr-spec-seq is an optional sequence of [attributes](attributes.html "c/language/attributes")(since C23). When appearing immediately after the identifier, it applies to the object or function being declared. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/declarations&action=edit&section=2 "Edit section: Definitions")] Definitions

A _definition_ is a declaration that provides all information about the identifiers it declares. 

Every declaration of an [enum](enum.html "c/language/enum") or a [typedef](typedef.html "c/language/typedef") is a definition. 

For functions, a declaration that includes the function body is a [function definition](function_definition.html "c/language/function definition"): 
    
    
    int foo(double); // declaration
    int foo(double x) { return x; } // definition

For objects, a declaration that allocates storage ([automatic or static](storage_class_specifiers.html "c/language/storage duration"), but not extern) is a definition, while a declaration that does not allocate storage ([external declaration](extern.html "c/language/extern")) is not. 
    
    
    extern int n; // declaration
    int n = 10; // definition

For [structs](struct.html "c/language/struct") and [unions](union.html "c/language/union"), declarations that specify the list of members are definitions: 
    
    
    struct X; // declaration
    struct X { int n; }; // definition

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/declarations&action=edit&section=3 "Edit section: Redeclaration")] Redeclaration

A declaration cannot introduce an identifier if another declaration for the same identifier in the same [scope](scope.html "c/language/scope") appears earlier, except that 

  * Declarations of objects [with linkage](storage_class_specifiers.html "c/language/storage duration") (external or internal) can be repeated: 


    
    
    extern int x;
    int x = 10; // OK
    extern int x; // OK
     
    static int n;
    static int n = 10; // OK
    static int n; // OK

  * Non-VLA [typedef](typedef.html "c/language/typedef") can be repeated as long as it names the same type: 


    
    
    typedef int int_t;
    typedef int int_t; // OK

  * [struct](struct.html "c/language/struct") and [union](union.html "c/language/union") declarations can be repeated: 


    
    
    struct X;
    struct X { int n; };
    struct X;

These rules simplify the use of header files. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/declarations&action=edit&section=4 "Edit section: Notes")] Notes

In C89, declarations within any [compound statement](statements.html#Compound_statements "c/language/statements") (block scope) must appear in the beginning of the block, before any [statements](statements.html "c/language/statements"). Also, in C89, functions returning int may be implicitly declared by the [function call operator](operator_other.html#Function_call "c/language/operator other") and function parameters of type int do not have to be declared when using old-style [function definitions](function_definition.html "c/language/function definition").  | (until C99)  
---|---  
  
Empty declarators are prohibited; a simple declaration must have at least one declarator or declare at least one struct/union/enum tag, or introduce at least one enumeration constant. 

If any part of a declarator is a [variable-length array](array.html "c/language/array") (VLA) declarator, the entire declarator's type is known as "variably-modified type". Types defined from variably-modified types are also variably modified (VM). Declarations of any variably-modified types may appear only at [block scope](scope.html "c/language/scope") or function prototype scope and cannot be members of structs or unions. Although VLA can only have automatic or allocated [storage duration](storage_class_specifiers.html "c/language/storage duration"), a VM type such as a pointer to a VLA may be static. There are other restrictions on the use of VM types, see [goto](goto.html "c/language/goto"), [switch](switch.html "c/language/switch"). [longjmp](../program/longjmp.html "c/program/longjmp") | (since C99)  
---|---  
[static_asserts](static_assert.html "c/language/ Static assert") are considered to be declarations from the point of view of the C grammar (so that they may appear anywhere a declaration may appear), but they do not introduce any identifiers and do not follow the declaration syntax.  | (since C11)  
---|---  
[Attribute](attributes.html "c/language/attributes") declarations are also considered to be declarations (so that they may appear anywhere a declaration may appear), but they do not introduce any identifiers. A single `**;**` without attr-spec-seq is not an attribute declaration, but a statement.  | (since C23)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/declarations&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7 Declarations (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7 Declarations (p: 78-105) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7 Declarations (p: 108-145) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.7 Declarations (p: 97-130) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.5 Declarations 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/declarations&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/declarations.html "cpp/language/declarations") for Declarations  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/declarations&oldid=179842](https://en.cppreference.com/mwiki/index.php?title=c/language/declarations&oldid=179842)" 

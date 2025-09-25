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

[ Declarations](declarations.html "c/language/declarations")

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
**External and tentative definitions**  
[typedef](typedef.html "c/language/typedef")  
[Static assertions](static_assert.html "c/language/ Static assert")  
[Attributes](attributes.html "c/language/attributes") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/declarations/navbar_content&action=edit)

At the top level of a [translation unit](translation_phases.html "c/language/translation phases") (that is, a source file with all the #includes after the preprocessor), every C program is a sequence of [declarations](declarations.html "c/language/declarations"), which declare functions and objects with [external or internal linkage](storage_class_specifiers.html "c/language/storage duration"). These declarations are known as _external declarations_ because they appear outside of any function. 
    
    
    extern int n; // external declaration with external linkage
    int b = 1;    // external definition with external linkage
    static const char *c = "abc"; // external definition with internal linkage
     
    int f(void)    // external definition with external linkage
    {
        int a = 1; // non-external
        return b;
    }
     
    static void x(void) // external definition with internal linkage
    {
    }

Objects declared with an external declaration have static [storage duration](storage_class_specifiers.html "c/language/storage duration"), and as such cannot use auto or register specifiers except that auto can be used for type inference(since C23). The identifiers introduced by external declarations have [file scope](scope.html "c/language/scope"). 

## Contents

  * [1 Tentative definitions](extern.html#Tentative_definitions)
  * [2 One definition rule](extern.html#One_definition_rule)
  * [3 Notes](extern.html#Notes)
  * [4 References](extern.html#References)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/extern&action=edit&section=1 "Edit section: Tentative definitions")] Tentative definitions

A _tentative definition_ is an external declaration without an initializer, and either without a [storage-class specifier](storage_class_specifiers.html "c/language/storage duration") or with the specifier static. 

A _tentative definition_ is a declaration that may or may not act as a definition. If an actual external definition is found earlier or later in the same translation unit, then the tentative definition just acts as a declaration. 
    
    
    int i1 = 1;     // definition, external linkage
    int i1;         // tentative definition, acts as declaration because i1 is defined
    extern int i1;  // declaration, refers to the earlier definition
     
    extern int i2 = 3; // definition, external linkage
    int i2;            // tentative definition, acts as declaration because i2 is defined
    extern int i2;     // declaration, refers to the external linkage definition

If there are no definitions in the same translation unit, then the tentative definition acts as an actual definition that [empty-initializes](initialization.html#Empty_initialization "c/language/initialization") the object. 
    
    
    int i3;        // tentative definition, external linkage
    int i3;        // tentative definition, external linkage
    extern int i3; // declaration, external linkage
    // in this translation unit, i3 is defined as if by "int i3 = 0;"

Unlike the [extern](storage_class_specifiers.html "c/language/storage duration") declarations, which don't change the linkage of an identifier if a previous declaration established it, tentative definitions may disagree in linkage with another declaration of the same identifier. If two declarations for the same identifier are in scope and have different linkage, the behavior is undefined: 
    
    
    static int i4 = 2; // definition, internal linkage
    int i4;            // Undefined behavior: linkage disagreement with previous line
    extern int i4;     // declaration, refers to the internal linkage definition
     
    static int i5; // tentative definition, internal linkage
    int i5;        // Undefined behavior: linkage disagreement with previous line
    extern int i5; // refers to previous, whose linkage is internal

A tentative definition with internal linkage must have complete type. 
    
    
    static int i[]; // Error, incomplete type in a static tentative definition
    int i[]; // OK, equivalent to int i[1] = {0}; unless redeclared later in this file

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/extern&action=edit&section=2 "Edit section: One definition rule")] One definition rule

Each translation unit may have zero or one external definition of every identifier with [internal linkage](storage_class_specifiers.html "c/language/storage duration") (a static global). 

If an identifier with internal linkage is used in any expression other than a non-VLA,(since C99) [`sizeof`](sizeof.html "c/language/sizeof"), [`_Alignof`](alignof.html "c/language/ Alignof")(since C11)(until C23), [`alignof`](alignof.html "c/language/alignof")(since C23), or [`typeof`](typeof_unqual.html "c/language/typeof")(since C23), there must be one and only one external definition for that identifier in the translation unit. 

The entire program may have zero or one external definition of every identifier with [external linkage](storage_class_specifiers.html "c/language/storage duration"). 

If an identifier with external linkage is used in any expression other than a non-VLA,(since C99) [`sizeof`](sizeof.html "c/language/sizeof"), [`_Alignof`](alignof.html "c/language/ Alignof")(since C11)(until C23), [`alignof`](alignof.html "c/language/alignof")(since C23), or [`typeof`](typeof_unqual.html "c/language/typeof")(since C23), there must be one and only one external definition for that identifier somewhere in the entire program. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/extern&action=edit&section=3 "Edit section: Notes")] Notes

Inline definitions in different translation units are not constrained by one definition rule. See [`inline`](inline.html "c/language/inline") for the details on the inline function definitions.  | (since C99)  
---|---  
  
See [storage duration and linkage](storage_class_specifiers.html "c/language/storage duration") for the meaning of the keyword extern with declarations at file scope 

See [definitions](declarations.html#Definitions "c/language/declarations") for the distinction between declarations and definitions. 

Tentative definitions were invented to standardize various pre-C89 approaches to forward declaring identifiers with internal linkage. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/extern&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.9 External definitions (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.9 External definitions (p: 113-116) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.9 External definitions (p: 155-159) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.9 External definitions (p: 140-144) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.7 EXTERNAL DEFINITIONS 



Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/extern&oldid=180002](https://en.cppreference.com/mwiki/index.php?title=c/language/extern&oldid=180002)" 

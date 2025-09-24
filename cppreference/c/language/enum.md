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
**enum**  
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

An _enumerated type_ is a distinct [type](compatible_type.html "c/language/type") whose value is a value of its _underlying type_ (see below), which includes the values of explicitly named constants (_enumeration constants_). 

## Contents

  * [1 Syntax](enum.html#Syntax)
  * [2 Explanation](enum.html#Explanation)
  * [3 Notes](enum.html#Notes)
  * [4 Example](enum.html#Example)
  * [5 References](enum.html#References)
  * [6 Keywords](enum.html#Keywords)
  * [7 See also](enum.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/enum&action=edit&section=1 "Edit section: Syntax")] Syntax

Enumerated type is declared using the following _enumeration specifier_ as the type-specifier in the [declaration grammar](declarations.html "c/language/declarations"):   
  
---  
`**enum**` attr-spec-seq ﻿(optional) identifier ﻿(optional) `**{**` enumerator-list `**}**` |  (1)  |   
`**enum**` attr-spec-seq ﻿(optional) identifier ﻿(optional) `**:**` type `**{**` enumerator-list `**}**` |  (2)  |  (since C23)  
  
1) Declares an enumeration without a fixed underlying type.

2) Declares an enumeration of fixed underlying type type.

where enumerator-list is a comma-separated list(with trailing comma permitted)(since C99) of enumerator, each of which has the form:   
  
---  
enumeration-constant attr-spec-seq ﻿(optional) |  (1)  |   
enumeration-constant attr-spec-seq ﻿(optional) `**=**` constant-expression |  (2)  |   
  
where 

identifier, enumeration-constant |  \-  |  identifiers that are introduced by this declaration   
---|---|---  
constant-expression |  \-  |  [integer constant expression](constant_expression.html "c/language/constant expression") whose value is representable as a value of type int(until C23). If the enumeration has a fixed underlying type, representable as a value of type(since C23)  
attr-spec-seq |  \-  |  (C23)optional list of [attributes](attributes.html "c/language/attributes"), 

  * applied to the whole enumeration if appears after `**enum**`, 
  * applied to the enumerator if appears after enumeration-constant

  
  
As with [struct](struct.html "c/language/struct") or [union](union.html "c/language/union"), a declaration that introduced an enumerated type and one or more enumeration constants may also declare one or more objects of that type or type derived from it. 
    
    
    enum color { RED, GREEN, BLUE } c = RED, *cp = &c;
    // introduces the type enum color
    // the integer constants RED, GREEN, BLUE
    // the object c of type enum color
    // the object cp of type pointer to enum color

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/enum&action=edit&section=2 "Edit section: Explanation")] Explanation

Each enumeration-constant that appears in the body of an enumeration specifier becomes an [integer constant](constant_expression.html "c/language/constant expression") with type int(until C23) in the enclosing scope and can be used whenever integer constants are required (e.g. as a case label or as a non-VLA array size). 

During the processing of each enumeration constant in the enumerator list, the type of the enumeration constant shall be: 

  * the previously declared type, if it is a redeclaration of the same enumeration constant; or, 
  * the enumerated type, for an enumeration with fixed underlying type; or, 
  * int, if there are no previous enumeration constants in the enumerator list and no explicit = with a defining integer constant expression; or, 
  * int, if given explicitly with = and the value of the integer constant expression is representable by an int; or, 
  * the type of the integer constant expression, if given explicitly with = and if the value of the integer constant expression is not representable by int; or, 
  * the type of the value from last enumeration constant with 1 added to it. If such an integer constant expression would overflow or wraparound the value of the previous enumeration constant from the addition of 1, the type takes on either: 
    * a suitably sized signed integer type (excluding the bit-precise signed integer types) capable of representing the value of the previous enumeration constant plus 1; or, 
    * a suitably sized unsigned integer type (excluding the bit-precise unsigned integer types) capable of representing the value of the previous enumeration constant plus 1. 

A signed integer type is chosen if the previous enumeration constant being added is of signed integer type. An unsigned integer type is chosen if the previous enumeration constant is of unsigned integer type. If there is no suitably sized integer type described previous which can represent the new value, then the enumeration has no type which is capable of representing all of its values.  | (since C23)  
---|---  
      
    
    enum color { RED, GREEN, BLUE } r = RED;
    switch(r)
    {
    case RED:
        [puts](../io/puts.html)("red");
        break;
    case GREEN:
        [puts](../io/puts.html)("green");
        break;
    case BLUE:
        [puts](../io/puts.html)("blue");
        break;
    }

If enumeration-constant is followed by = constant-expression, its value is the value of that constant expression. If enumeration-constant is not followed by = constant-expression, its value is the value one greater than the value of the previous enumerator in the same enumeration. The value of the first enumerator (if it does not use = constant-expression) is zero. 
    
    
    enum Foo { A, B, C = 10, D, E = 1, F, G = F + C };
    // A=0, B=1, C=10, D=11, E=1, F=2, G=12

The identifier itself, if used, becomes the name of the enumerated type in the tags [name space](name_space.html "c/language/name space") and requires the use of the keyword enum (unless typedef'd into the ordinary name space). 
    
    
    enum color { RED, GREEN, BLUE };
    enum color r = RED; // OK
    // color x = GREEN; // Error: color is not in ordinary name space
    typedef enum color color_t;
    color_t x = GREEN; // OK

Each enumerated type without a fixed underlying type(since C23) is [compatible](compatible_type.html#Compatible_types "c/language/type") with one of: char, a signed integer type, or an unsigned integer type (excluding bool and the bit-precise integer types)(since C23). It is implementation-defined which type is compatible with any given enumerated type, but whatever it is, it must be capable of representing all enumerator values of that enumeration. For all enumerations with a fixed underlying type, the enumerated type is compatible with the underlying type of the enumeration.(since C23)

The enumeration member type for an enumerated type without fixed underlying type upon completion is: 

  * int if all the values of the enumeration are representable as an int; or, 
  * the enumerated type. 

| (since C23)  
---|---  
All enumerations have an underlying type. The underlying type can be explicitly specified using an enum-type-specifier and is its fixed underlying type. If it is not explicitly specified, the underlying type is the enumeration’s compatible type, which is either a signed or unsigned integer type, or char.  | (since C23)  
  
Enumerated types are integer types, and as such can be used anywhere other integer types can, including in [implicit conversions](conversion.html "c/language/conversion") and [arithmetic operators](operator_arithmetic.html "c/language/operator arithmetic"). 
    
    
    enum { ONE = 1, TWO } e;
    long n = ONE; // promotion
    double d = ONE; // conversion
    e = 1.2; // conversion, e is now ONE
    e = e + 1; // e is now TWO

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/enum&action=edit&section=3 "Edit section: Notes")] Notes

Unlike [struct](struct.html "c/language/struct") or [union](union.html "c/language/union"), there are no forward-declared enums in C: 
    
    
    enum Color; // Error: no forward-declarations for enums in C
    enum Color { RED, GREEN, BLUE };

Enumerations permit the declaration of named constants in a more convenient and structured fashion than does #define; they are visible in the debugger, obey scope rules, and participate in the type system. 
    
    
    #define TEN 10
    struct S { int x : TEN; }; // OK

or 
    
    
    enum { TEN = 10 };
    struct S { int x : TEN; }; // also OK

Since C23 [constexpr](constexpr.html "c/language/constexpr") can be used for the same purpose: 
    
    
    constexpr int TEN = 10;
    struct S { int x : TEN; }; // also OK

Moreover, as a [struct](struct.html "c/language/struct") or [union](union.html "c/language/union") does not establish its scope in C, an enumeration type and its enumeration constants may be introduced in the member specification of the former, and their scope is the same as of the former, afterwards. 
    
    
    struct Element
    {
        int z;
        enum State { SOLID, LIQUID, GAS, PLASMA } state;
    } oxygen = { 8, GAS };
     
    // type enum State and its enumeration constants stay visible here, e.g.
    void foo(void)
    {
        enum State e = LIQUID; // OK
        [printf](../io/fprintf.html)("%d %d %d ", e, oxygen.state, PLASMA); // prints 1 2 3
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/enum&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
     
    int main(void)
    {
        enum TV { FOX = 11, CNN = 25, ESPN = 15, HBO = 22, MAX = 30, NBC = 32 };
     
        [printf](../io/fprintf.html)("List of cable stations:\n");
        [printf](../io/fprintf.html)(" FOX: \t%2d\n", FOX);
        [printf](../io/fprintf.html)(" HBO: \t%2d\n", HBO);
        [printf](../io/fprintf.html)(" MAX: \t%2d\n", MAX);
    }

Output: 
    
    
    List of cable stations:
     FOX:   11
     HBO:   22
     MAX:   30

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/enum&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.2.5/21 Types (p: 39) 



    

  * 6.7.2.2 Enumeration specifiers (p: 107-112) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.2.5/16 Types (p: 32) 



    

  * 6.7.2.2 Enumeration specifiers (p: 84-85) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.2.5/16 Types (p: 41) 



    

  * 6.7.2.2 Enumeration specifiers (p: 117-118) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.2.5/16 Types (p: 35) 



    

  * 6.7.2.2 Enumeration specifiers (p: 105-106) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.1.2.5 Types 



    

  * 3.5.2.2 Enumeration specifiers 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/enum&action=edit&section=6 "Edit section: Keywords")] Keywords

[`enum`](../keyword/enum.html "c/keyword/enum")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/enum&action=edit&section=7 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/enum.html "cpp/language/enum") for enumeration declaration  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/enum&oldid=171799](https://en.cppreference.com/mwiki/index.php?title=c/language/enum&oldid=171799)" 

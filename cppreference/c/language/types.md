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

[ Basic Concepts](basic_concepts.html "c/language/basic concepts")

[ Comments](../comment.html "c/comment")  
---  
[ ASCII](ascii.html "c/language/ascii")  
[ Character sets](charset.html "c/language/charset")  
[ Translation phases](translation_phases.html "c/language/translation phases")  
[Punctuation](punctuators.html "c/language/punctuators")  
[Identifier](identifiers.html "c/language/identifier")  
[Scope](scope.html "c/language/scope")  
[Lifetime](lifetime.html "c/language/lifetime")  
[Lookup and name spaces](name_space.html "c/language/name space")  
**Type**  
[Arithmetic types](arithmetic_types.html "c/language/arithmetic types")  
[Objects and alignment](object.html "c/language/object")  
[The main() function](main_function.html "c/language/main function")  
[The as-if rule](as_if.html "c/language/as if")  
[Undefined behavior](behavior.html "c/language/behavior")  
[Memory model and data races](memory_model.html "c/language/memory model")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/basics/navbar_content&action=edit)

(See also [arithmetic types](arithmetic_types.html "c/language/arithmetic types") for the details on most built-in types and [the list of type-related utilities](../types.html "c/types") that are provided by the C library.)

[Objects](object.html "c/language/object"), [functions](functions.html "c/language/functions"), and [expressions](operators.html "c/language/expressions") have a property called _type_ , which determines the interpretation of the binary value stored in an object or evaluated by the expression. 

## Contents

  * [1 Type classification](compatible_type.html#Type_classification)
    * [1.1 Type groups](compatible_type.html#Type_groups)
  * [2 Compatible types](compatible_type.html#Compatible_types)
  * [3 Composite types](compatible_type.html#Composite_types)
  * [4 Incomplete types](compatible_type.html#Incomplete_types)
  * [5 Type names](compatible_type.html#Type_names)
  * [6 References](compatible_type.html#References)
  * [7 See also](compatible_type.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/type&action=edit&section=1 "Edit section: Type classification")] Type classification

The C type system consists of the following types: 

  * the type void
  * basic types 



    

  * the type char
  * signed integer types 



    

  * standard: signed char, short, int, long, long long(since C99)



    

    

  * bit-precise: _BitInt(N) where N is an integer constant expression that specifies the number of bits that are used to represent the type, including the sign bit. Each value of N designates a distinct type. 


| (since C23)  
---|---  
  
    

    

  * extended: implementation defined, e.g. __int128


| (since C99)  
  
    

  * unsigned integer types 



    

  * standard: _Bool,(since C99) unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long(since C99)



    

    

  * bit-precise: unsigned _BitInt(N) where `N` is an integer constant expression that specifies the number of bits that are used to represent the type. Each value of `N` designates a distinct type. This category includes the type unsigned _BitInt(1) which does not have a corresponding bit-precise signed integer type. 


| (since C23)  
---|---  
  
    

    

  * extended: implementation-defined, e.g. __uint128


| (since C99)  
  
    

  * floating-point types 



    

  * real floating-point types: float, double, long double



    

    

  * decimal real floating-point types: _Decimal32, _Decimal64, _Decimal128


| (since C23)  
---|---  
  
    

    

  * complex types: float _Complex, double _Complex, long double _Complex
  * imaginary types: float _Imaginary, double _Imaginary, long double _Imaginary


| (since C99)  
  
  * [enumerated types](enum.html "c/language/enum")


  * derived types 



    

  * [array types](array.html "c/language/array")
  * [structure types](struct.html "c/language/struct")
  * [union types](union.html "c/language/union")
  * [function types](functions.html "c/language/functions")
  * [pointer types](pointer.html "c/language/pointer")



    

  * [atomic types](atomic.html "c/language/atomic")


| (since C11)  
---|---  
  
For every type listed above several qualified versions of its type may exist, corresponding to the combinations of one, two, or all three of the [`const`](const.html "c/language/const"), [`volatile`](volatile.html "c/language/volatile"), and [`restrict`](restrict.html "c/language/restrict") qualifiers (where allowed by the qualifier's semantics). 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/type&action=edit&section=2 "Edit section: Type groups")] Type groups

  * _object types_ : all types that aren't function types 
  * _character types_ : char, signed char, unsigned char
  * _integer types_ : char, signed integer types, unsigned integer types, enumerated types 
  * _real types_ : integer types and real floating types 
  * [arithmetic types](arithmetic_types.html "c/language/arithmetic types"): integer types and floating types 
  * _scalar types_ : arithmetic types, pointer types, and [nullptr_t](../types/nullptr_t.html "c/types/nullptr t")(since C23)
  * _aggregate types_ : array types and structure types 
  * _derived declarator types_ : array types, function types, and pointer types 



Constructing a complete object type such that the number of bytes in its object representation is not representable in the type [size_t](../types/size_t.html "c/types/size t") (i.e. the result type of [`sizeof`](sizeof.html "c/language/sizeof") operator), including forming such a VLA type at runtime,(since C99) is undefined behavior. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/type&action=edit&section=3 "Edit section: Compatible types")] Compatible types

In a C program, the declarations referring to the same object or function in _different translation units_ do not have to use the same type. They only have to use sufficiently similar types, formally known as _compatible types_. Same applies to function calls and lvalue accesses; argument types must be _compatible_ with parameter types and lvalue expression type must be _compatible_ with the object type that is accessed. 

The types `T` and `U` are compatible, if 

  * they are the same type (same name or aliases introduced by a [`typedef`](typedef.html "c/language/typedef")) 
  * they are identically cvr-qualified versions of compatible unqualified types 
  * they are pointer types and are pointing to compatible types 
  * they are array types, and 



    

  * their element types are compatible, and 
  * if both have constant size, that size is the same. Note: arrays of unknown bound are compatible with any array of compatible element type. VLA is compatible with any array of compatible element type.(since C99)



  * they are both structure/union/enumeration types, and 



    

  * (C99)if one is declared with a tag, the other must also be declared with the same tag. 
  * if both are completed types, their members must correspond exactly in number, be declared with compatible types, and have matching names. 
  * additionally, if they are enumerations, corresponding members must also have the same values. 
  * additionally, if they are structures or unions, 



    

  * Corresponding members must be declared in the same order (structures only) 
  * Corresponding [bit-fields](bit_field.html "c/language/bit field") must have the same widths. 



  * one is an enumerated type and the other is that enumeration's underlying type 
  * they are function types, and 



    

  * their return types are compatible 
  * they both use parameter lists, the number of parameters (including the use of the ellipsis) is the same, and the corresponding parameter, after applying array-to-pointer and function-to-pointer type adjustments and after stripping top-level qualifiers, have compatible types 



    

  * one is an old-style (parameter-less) definition, the other has a parameter list, the parameter list does not use an ellipsis and each parameter is compatible (after function parameter type adjustment) with the corresponding old-style parameter after default argument promotions 
  * one is an old-style (parameter-less) declaration, the other has a parameter list, the parameter list does not use an ellipsis, and all parameters (after function parameter type adjustment) are unaffected by default argument promotions 


| (until C23)  
---|---  
  
The type char is not compatible with signed char and not compatible with unsigned char. 

If two declarations refer to the same object or function and do not use compatible types, the behavior of the program is undefined. 
    
    
    // Translation Unit 1
    struct S { int a; };
    extern struct S *x; // compatible with TU2's x, but not with TU3's x
     
    // Translation Unit 2
    struct S;
    extern struct S *x; // compatible with both x's
     
    // Translation Unit 3
    struct S { float a; };
    extern struct S *x; // compatible with TU2's x, but not with TU1's x
     
    // the behavior is undefined
    
    
    // Translation Unit 1
    #include <stdio.h>
     
    struct s { int i; }; // compatible with TU3's s, but not TU2's
    extern struct s x = {0}; // compatible with TU3's x
    extern void f(void); // compatible with TU2's f
     
    int main()
    {
        f();
        return x.i;
    }
     
    // Translation Unit 2
    struct s { float f; }; // compatible with TU4's s, but not TU1's s
    extern struct s y = {3.14}; // compatible with TU4's y
    void f() // compatible with TU1's f
    {
        return;
    }
     
    // Translation Unit 3
    struct s { int i; }; // compatible with TU1's s, but not TU2's s
    extern struct s x; // compatible with TU1's x
     
    // Translation Unit 4
    struct s { float f; }; // compatible with TU2's s, but not TU1's s
    extern struct s y; // compatible with TU2's y
     
    // the behavior is well-defined: only multiple declarations
    // of objects and functions must have compatible types, not the types themselves

Note: C++ has no concept of compatible types. A C program that declares two types that are compatible but not identical in different translation units is not a valid C++ program. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/type&action=edit&section=4 "Edit section: Composite types")] Composite types

A composite type can be constructed from two types that are compatible; it is a type that is compatible with both of the two types and satisfies the following conditions: 

  * If both types are array types, the following rules are applied: 



    

  * If one type is an array of known constant size, the composite type is an array of that size. 



    

  * Otherwise, if one type is a VLA whose size is specified by an expression that is not evaluated, a program necessitating the composite type of both types has undefined behavior. 
  * Otherwise, if one type is a VLA whose size is specified, the composite type is a VLA of that size. 
  * Otherwise, if one type is a VLA of unspecified size, the composite type is a VLA of unspecified size. 


| (since C99)  
---|---  
  
    

  * Otherwise, both types are arrays of unknown size and the composite type is an array of unknown size. 



    The element type of the composite type is the composite type of the two element types. 

  * If only one type is a function type with a parameter type list (a function prototype), the composite type is a function prototype with the parameter type list. 

| (until C23)  
---|---  
  
  * If both types are function types with parameter type lists, the type of each parameter in the composite parameter type list is the composite type of the corresponding parameters. 



These rules apply recursively to the types from which the two types are derived. 
    
    
    // Given the following two file scope declarations:
    int f(int (*)(), double (*)[3]);
    int f(int (*)(char *), double (*)[]); // C23: Error: conflicting types for 'f'
    // The resulting composite type for the function is:
    int f(int (*)(char *), double (*)[3]);

For an identifier with internal or external [linkage](storage_class_specifiers.html "c/language/storage duration") declared in a scope in which a prior declaration of that identifier is visible, if the prior declaration specifies internal or external linkage, the type of the identifier at the later declaration becomes the composite type. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/type&action=edit&section=5 "Edit section: Incomplete types")] Incomplete types

An incomplete type is an object type that lacks sufficient information to determine the size of the objects of that type. An incomplete type may be completed at some point in the translation unit. 

The following types are incomplete: 

  * the type void. This type cannot be completed. 
  * array type of unknown size. It can be completed by a later declaration that specifies the size. 


    
    
    extern char a[]; // the type of a is incomplete (this typically appears in a header)
    char a[10];      // the type of a is now complete (this typically appears in a source file)

  * structure or union type of unknown content. It can be completed by a declaration of the same structure or union that defines its content later in the same scope. 


    
    
    struct node
    {
        struct node* next; // struct node is incomplete at this point
    }; // struct node is complete at this point

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/type&action=edit&section=6 "Edit section: Type names")] Type names

A type may have to be named in context other than the [declaration](declarations.html "c/language/declarations"). In these situations, _type name_ is used, which is, grammatically, exactly the same as a list of _type-specifiers_ and _type-qualifiers_ , followed by the _declarator_ (see [declarations](declarations.html "c/language/declarations")) as would be used to declare a single object or function of this type, except that the identifier is omitted: 
    
    
    int n; // declaration of an int
    sizeof(int); // use of type name
     
    int *a[3]; // declaration of an array of 3 pointers to int
    sizeof(int *[3]); // use of type name
     
    int (*p)[3]; // declaration of a pointer to array of 3 int
    sizeof(int (*)[3]); // use of type name
     
    int (*a)[*] // declaration of pointer to VLA (in a function parameter)
    sizeof(int (*)[*]) // use of type name (in a function parameter)
     
    int *f(void); // declaration of function
    sizeof(int *(void)); // use of type name
     
    int (*p)(void); // declaration of pointer to function
    sizeof(int (*)(void)); // use of type name
     
    int (*const a[])(unsigned int, ...) = {0}; // array of pointers to functions
    sizeof(int (*const [])(unsigned int, ...)); // use of type name

Except the redundant parentheses around the identifier are meaningful in a type-name and represent "function with no parameter specification": 
    
    
    int (n); // declares n of type int
    sizeof(int ()); // uses type "function returning int"

Type names are used in the following situations: 

  * [cast](cast.html "c/language/cast")
  * [sizeof](sizeof.html "c/language/sizeof")



  * [compound literal](compound_literal.html "c/language/compound literal")

| (since C99)  
---|---  
  
  * [generic selection](generic.html "c/language/generic")
  * [`_Alignof`](alignof.html "c/language/ Alignof")(until C23)[`alignof`](alignof.html "c/language/alignof")(since C23)
  * [`_Alignas`](alignas.html "c/language/ Alignas")(until C23)[`alignas`](alignas.html "c/language/alignas")(since C23)
  * [_Atomic](atomic.html "c/language/atomic") (when used as a type specifier) 

| (since C11)  
  
  
A type name may introduce a new type: 
    
    
    void* p = (void*)(struct X { int i; } *)0;
    // type name "struct X {int i;}*" used in the cast expression
    // introduces the new type "struct X"
    struct X x = {1}; // struct X is now in scope

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/type&action=edit&section=7 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.2.5 Types (p: TBD) 



    

  * 6.2.6 Representations of types (p: TBD) 



    

  * 6.2.7 Compatible type and composite type (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.2.5 Types (p: 31-33) 



    

  * 6.2.6 Representations of types (p: 31-35) 



    

  * 6.2.7 Compatible type and composite type (p: 35-36) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.2.5 Types (p: 39-43) 



    

  * 6.2.6 Representations of types (p: 44-46) 



    

  * 6.2.7 Compatible type and composite type (p: 47-48) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.2.5 Types (p: 33-37) 



    

  * 6.2.6 Representations of types (p: 37-40) 



    

  * 6.2.7 Compatible type and composite type (p: 40-41) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.1.2.5 Types 



    

  * 3.1.2.6 Compatible type and composite type 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/type&action=edit&section=8 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/type-id.html "cpp/language/type") for Type  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/type&oldid=179352](https://en.cppreference.com/mwiki/index.php?title=c/language/type&oldid=179352)" 

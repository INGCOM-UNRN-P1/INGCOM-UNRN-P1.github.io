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
**const**  
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

Each individual type in the C [type system](compatible_type.html "c/language/type") has several _qualified_ versions of that type, corresponding to one, two, or all three of the `const`, [`volatile`](volatile.html "c/language/volatile"), and, for pointers to object types, [`restrict`](restrict.html "c/language/restrict") qualifiers. This page describes the effects of the `const` qualifier. 

Objects [declared](declarations.html "c/language/declarations") with const-qualified types may be placed in read-only memory by the compiler, and if the address of a const object is never taken in a program, it may not be stored at all. 

Any attempt to modify an object whose type is const-qualified results in undefined behavior. 
    
    
    const int n = 1; // object of const-qualified type
    int* p = (int*)&n;
    *p = 2; // undefined behavior

`const` semantics apply to [lvalue](value_category.html "c/language/value category") expressions only; whenever a const lvalue expression is used in context that does not require an lvalue, its `const` qualifier is lost (note that volatile qualifier, if present, isn't lost). 

The lvalue expressions that designate objects of const-qualified type and the lvalue expressions that designate objects of struct or union type with at least one member of const-qualified type (including members of recursively contained aggregates or unions), are not _modifiable lvalues_. In particular, they are not assignable: 
    
    
    const int n = 1; // object of const type
    n = 2; // error: the type of n is const-qualified
     
    int x = 2; // object of unqualified type
    const int* p = &x;
    *p = 3; // error: the type of the lvalue *p is const-qualified
     
    struct {int a; const int b; } s1 = {.b=1}, s2 = {.b=2};
    s1 = s2; // error: the type of s1 is unqualified, but it has a const member

A member of a const-qualified structure or union type acquires the qualification of the type it belongs to (both when accessed using the `**.**` operator or the `**- >**` operator). 
    
    
    struct s { int i; const int ci; } s;
    // the type of s.i is int, the type of s.ci is const int
    const struct s cs;
    // the types of cs.i and cs.ci are both const int

If an array type is declared with the const type qualifier (through the use of [typedef](typedef.html "c/language/typedef")), the array type is not const-qualified, but its element type is.  | (until C23)  
---|---  
An array type and its element type are always considered to be identically const-qualified.  | (since C23)  
      
    
    typedef int A[2][3];
    const A a = {{4, 5, 6}, {7, 8, 9}}; // array of array of const int
    int* pi = a[0]; // Error: a[0] has type const int*
    void *unqual_ptr = a; // OK until C23; error since C23
    // Notes: clang applies the rule in C++/C23 even in C89-C17 modes

If a function type is declared with the const type qualifier (through the use of [typedef](typedef.html "c/language/typedef")), the behavior is undefined. 

In a function declaration, the keyword `const` may appear inside the square brackets that are used to declare an array type of a function parameter. It qualifies the pointer type to which the array type is transformed. The following two declarations declare the same function: 
    
    
    void f(double x[const], const double y[const]);
    void f(double * const x, const double * const y);

| (since C99)  
---|---  
const-qualified compound literals do not necessarily designate distinct objects; they may share storage with other compound literals and with string literals that happen to have the same or overlapping representation. 
    
    
    const int* p1 = (const int[]){1, 2, 3};
    const int* p2 = (const int[]){2, 3, 4}; // the value of p2 may equal p1+1
    _Bool b = "foobar" + 3 == (const char[]){"bar"}; // the value of b may be 1

| (since C99)  
---|---  
  
A pointer to a non-const type can be implicitly converted to a pointer to const-qualified version of the same or [compatible](compatible_type.html "c/language/compatible type") type. The reverse conversion requires a cast expression. 
    
    
    int* p = 0;
    const int* cp = p; // OK: adds qualifiers (int to const int)
    p = cp; // Error: discards qualifiers (const int to int)
    p = (int*)cp; // OK: cast

Note that pointer to pointer to `T` is not convertible to pointer to pointer to `const T`; for two types to be compatible, their qualifications must be identical. 
    
    
    char *p = 0;
    const char **cpp = &p; // Error: char* and const char* are not compatible types
    char * const *pcp = &p; // OK, adds qualifiers (char* to char*const)

## Contents

  * [1 Keywords](const.html#Keywords)
  * [2 Notes](const.html#Notes)
  * [3 References](const.html#References)
  * [4 See also](const.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/const&action=edit&section=1 "Edit section: Keywords")] Keywords

[`const`](../../cpp/keyword/const.html "cpp/keyword/const")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/const&action=edit&section=2 "Edit section: Notes")] Notes

C adopted the _const_ qualifier from C++, but unlike in C++, expressions of const-qualified type in C are not [constant expressions](constant_expression.html "c/language/constant expression"); they may not be used as [case](switch.html "c/language/switch") labels or to initialize [static](static_storage_duration.html "c/language/static storage duration") and [thread](thread_storage_duration.html "c/language/thread storage duration") storage duration objects, [enumerators](enum.html "c/language/enum"), or [bit-field](bit_field.html "c/language/bit field") sizes. When they are used as [array](array.html "c/language/array") sizes, the resulting arrays are VLAs. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/const&action=edit&section=3 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.3 Type qualifiers (p: 87-90) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.3 Type qualifiers (p: 121-123) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.7.3 Type qualifiers (p: 108-110) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 6.5.3 Type qualifiers 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/const&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/cv.html "cpp/language/cv") for cv (`const` and `volatile`) type qualifiers  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/const&oldid=154456](https://en.cppreference.com/mwiki/index.php?title=c/language/const&oldid=154456)" 

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
**Initialization**  
[ Declarations](declarations.html "c/language/declarations")  
[ Functions](functions.html "c/language/functions")  
Miscellaneous  
[ History of C](history.html "c/language/history")  
[Technical Specifications](../experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

**Initialization**

[ Explicit initialization](initialization.html#Explicit_initialization "c/language/initialization")  
---  
[ Implicit initialization](initialization.html#Implicit_initialization "c/language/initialization")  
[ Empty initialization](initialization.html#Empty_initialization "c/language/initialization")  
[ Scalar initialization](scalar_initialization.html "c/language/scalar initialization")  
[ Array initialization](array_initialization.html "c/language/array initialization")  
[ Struct and union initialization](struct_initialization.html "c/language/struct initialization")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/initialization/navbar_content&action=edit)

A [declaration](declarations.html "c/language/declarations") of an object may provide its initial value through the process known as _initialization_. 

For each [declarator](declarations.html "c/language/declarations"), the initializer, if not omitted, may be one of the following:   
  
---  
`**=**` expression |  (1)  |   
`**=**` `**{**` initializer-list `**}**` |  (2)  |   
`**=**` `**{**` `**}**` |  (3)  |  (since C23)  
  
where initializer-list is a non-empty comma-separated list of initializer ﻿s (with an optional trailing comma), where each initializer has one of three possible forms:   
  
---  
expression |  (1)  |   
`**{**` initializer-list `**}**` |  (2)  |   
`**{**` `**}**` |  (3)  |  (since C23)  
designator-list `**=**` initializer |  (4)  |  (since C99)  
where designator-list is a list of either array designators of the form `**[**` constant-expression `**]**` or struct/union member designators of the form `**.**` identifier ﻿; see [array initialization](array_initialization.html "c/language/array initialization") and [struct initialization](struct_initialization.html "c/language/struct initialization"). Note: besides initializers, brace-enclosed initializer-list may appear in [compound literals](compound_literal.html "c/language/compound literal"), which are expressions of the form:  |   
---  
`**(**` type `**)**` `**{**` initializer-list `**}**` |  |   
`**(**` type `**)**` `**{**` `**}**` |  |  (since C23)  
(since C99)  
  
## Contents

  * [1 Explanation](initialization.html#Explanation)
    * [1.1 Explicit initialization](initialization.html#Explicit_initialization)
    * [1.2 Implicit initialization](initialization.html#Implicit_initialization)
    * [1.3 Empty initialization](initialization.html#Empty_initialization)
  * [2 Notes](initialization.html#Notes)
  * [3 Example](initialization.html#Example)
  * [4 References](initialization.html#References)
  * [5 See also](initialization.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/initialization&action=edit&section=1 "Edit section: Explanation")] Explanation

The initializer specifies the initial value stored in an object. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/initialization&action=edit&section=2 "Edit section: Explicit initialization")] Explicit initialization

If an initializer is provided, see 

  * [scalar initialization](scalar_initialization.html "c/language/scalar initialization") for the initialization of scalar types 
  * [array initialization](array_initialization.html "c/language/array initialization") for the initialization of array types 
  * [struct initialization](struct_initialization.html "c/language/struct initialization") for the initialization of struct and union types. 



#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/initialization&action=edit&section=3 "Edit section: Implicit initialization")] Implicit initialization

If an initializer is not provided: 

  * objects with automatic [storage duration](storage_class_specifiers.html "c/language/storage duration") are initialized to indeterminate values (which may be [trap representations](object.html "c/language/object")) 
  * objects with static and thread-local [storage duration](storage_class_specifiers.html "c/language/storage duration") are empty-initialized 



#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/initialization&action=edit&section=4 "Edit section: Empty initialization")] Empty initialization

An object is empty-initialized if it is explicitly initialized from initializer = {}.  | (since C23)  
---|---  
  
In some cases, an object is empty-initialized if it is not initialized explicitly, that is: 

  * pointers are initialized to null pointer values of their types 
  * objects of integral types are initialized to unsigned zero 
  * objects of floating types are initialized to positive zero 
  * all elements of arrays, all members of structs, and the first members of unions are empty-initialized, recursively, plus all padding bits are initialized to zero 



    (on platforms where null pointer values and floating zeroes have all-bit-zero representations, this form of initialization for statics is normally implemented by allocating them in the .bss section of the program image) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/initialization&action=edit&section=5 "Edit section: Notes")] Notes

When initializing an object of static or thread-local [storage duration](storage_class_specifiers.html "c/language/storage duration"), every expression in the initializer must be a [constant expression](constant_expression.html "c/language/constant expression") or [string literal](string_literal.html "c/language/string literal"). 

Initializers cannot be used in declarations of objects of incomplete type, VLAs, and block-scope objects with linkage. 

The initial values of function parameters are established as if by assignment from the arguments of a [function call](operator_other.html#Function_call "c/language/operator other"), rather than by initialization. 

If an indeterminate value is used as an argument to any standard library call, the behavior is undefined. Otherwise, the result of any expression involving indeterminate values is an indeterminate value (e.g. int n;, n may not compare equal to itself and it may appear to change its value on subsequent reads) 

There is no special construct in C corresponding to [value initialization](../../cpp/language/value_initialization.html "cpp/language/value initialization") in C++; however, = {0} (or (T){0} in compound literals)(since C99) can be used instead, as the C standard does not allow empty structs, empty unions, or arrays of zero length.  | (until C23)  
---|---  
The empty initializer = {} (or (T){} in compound literals) can be used to achieve the same semantics as [value initialization](../../cpp/language/value_initialization.html "cpp/language/value initialization") in C++.  | (since C23)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/initialization&action=edit&section=6 "Edit section: Example")] Example

Run this code
    
    
    #include <stdlib.h>
    int a[2]; // initializes a to {0, 0}
    int main(void)
    {
        int i;          // initializes i to an indeterminate value
        static int j;   // initializes j to 0
        int k = 1;      // initializes k to 1
     
        // initializes int x[3] to 1,3,5
        // initializes int* p to &x[0]
        int x[] = { 1, 3, 5 }, *p = x;
     
        // initializes w (an array of two structs) to
        // { { {1,0,0}, 0}, { {2,0,0}, 0} }
        struct {int a[3], b;} w[] = {[0].a = {1}, [1].a[0] = 2};
     
        // function call expression can be used for a local variable
        char* ptr = [malloc](../memory/malloc.html)(10);
        [free](../memory/free.html)(ptr);
     
    //  Error: objects with static storage duration require constant initializers
    //  static char* ptr = malloc(10);
     
    //  Error: VLA cannot be initialized
    //  int vla[n] = {0};
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/initialization&action=edit&section=7 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.9 Initialization (p: 100-105) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.9 Initialization (p: 139-144) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.7.8 Initialization (p: 125-130) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 6.5.7 Initialization 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/initialization&action=edit&section=8 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/initialization.html "cpp/language/initialization") for Initialization  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/initialization&oldid=147022](https://en.cppreference.com/mwiki/index.php?title=c/language/initialization&oldid=147022)" 

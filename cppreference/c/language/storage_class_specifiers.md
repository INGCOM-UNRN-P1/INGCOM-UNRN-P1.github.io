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
**Storage duration and linkage**  
[External and tentative definitions](extern.html "c/language/extern")  
[typedef](typedef.html "c/language/typedef")  
[Static assertions](static_assert.html "c/language/ Static assert")  
[Attributes](attributes.html "c/language/attributes") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/declarations/navbar_content&action=edit)

Specify _storage duration_ and _linkage_ of objects and functions: 

    

  * `**auto**` \- automatic duration and no linkage 
  * `**register**` \- automatic duration and no linkage; address of this variable cannot be taken 
  * `**static**` \- static duration and internal linkage (unless at block scope) 
  * `**extern**` \- static duration and external linkage (unless already declared internal) 



    

  * `**_Thread_local**`(until C23)`**thread_local**`(since C23) \- thread storage duration 


| (since C11)  
---|---  
  
## Contents

  * [1 Explanation](storage_class_specifiers.html#Explanation)
  * [2 Storage duration](storage_class_specifiers.html#Storage_duration)
    * [2.1 Linkage](storage_class_specifiers.html#Linkage)
    * [2.2 Linkage and libraries](storage_class_specifiers.html#Linkage_and_libraries)
  * [3 Keywords](storage_class_specifiers.html#Keywords)
  * [4 Notes](storage_class_specifiers.html#Notes)
  * [5 Example](storage_class_specifiers.html#Example)
  * [6 References](storage_class_specifiers.html#References)
  * [7 See also](storage_class_specifiers.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/storage_duration&action=edit&section=1 "Edit section: Explanation")] Explanation

Storage-class specifiers appear in [declarations](declarations.html "c/language/declarations") and [compound literal](compound_literal.html "c/language/compound literal") expressions(since C23). At most one specifier may be used, except that _Thread_local(until C23)[thread_local](../thread/thread_local.html)(since C23) may be combined with static or extern to adjust linkage(since C11). The storage-class specifiers determine two independent properties of the names they declare: _storage duration_ and _linkage_. 

1) The auto specifier is only allowed for objects declared at block scope (except function parameter lists). It indicates automatic storage duration and no linkage, which are the defaults for these kinds of declarations.

2) The register specifier is only allowed for objects declared at block scope, including function parameter lists. It indicates automatic storage duration and no linkage (which is the default for these kinds of declarations), but additionally hints the optimizer to store the value of this variable in a CPU register if possible. Regardless of whether this optimization takes place or not, variables declared register cannot be used as arguments to the [address-of operator](operator_member_access.html "c/language/operator member access"), cannot use [`_Alignas`](alignas.html "c/language/ Alignas")(until C23)[`alignas`](alignas.html "c/language/alignas")(since C23)(since C11), and register arrays are not convertible to pointers.

3) The static specifier specifies both static storage duration (unless combined with _Thread_local)(since C11) and internal linkage (unless used at block scope). It can be used with functions at file scope and with variables at both file and block scope, but not in function parameter lists.

4) The extern specifier specifies static storage duration (unless combined with _Thread_local(until C23)[thread_local](../thread/thread_local.html)(since C23))(since C11) and external linkage. It can be used with function and object declarations in both file and block scope (excluding function parameter lists). If extern appears on a redeclaration of an identifier that was already declared with internal linkage, the linkage remains internal. Otherwise (if the prior declaration was external, no-linkage, or is not in scope), the linkage is external.

5) _Thread_local(until C23)[thread_local](../thread/thread_local.html)(since C23) indicates _thread storage duration_. It cannot be used with function declarations. If it is used on a declaration of an object, it must be present on every declaration of the same object. If it is used on a block-scope declaration, it must be combined with either static or extern to decide linkage.  | (since C11)  
---|---  
  
If no storage-class specifier is provided, the defaults are: 

     extern for all functions 
     extern for objects at file scope 
     auto for objects at block scope 

For any struct or union declared with a storage-class specifier, the storage duration (but not linkage) applies to their members, recursively. 

Function declarations at block scope can use extern or none at all. Function declarations at file scope can use extern or static. 

Function parameters cannot use any storage-class specifiers other than register. Note that static has special meaning in function parameters of array type. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/storage_duration&action=edit&section=2 "Edit section: Storage duration")] Storage duration

Every [object](object.html "c/language/object") has a property called _storage duration_ , which limits the object [lifetime](lifetime.html "c/language/lifetime"). There are four kinds of storage duration in C: 

    

  * _**automatic**_ storage duration. The storage is allocated when the [block](statements.html#Compound_statements "c/language/statements") in which the object was declared is entered and deallocated when it is exited by any means ([goto](goto.html "c/language/goto"), [return](return.html "c/language/return"), reaching the end). One exception is the [VLAs](array.html#Variable-length_arrays "c/language/array"); their storage is allocated when the declaration is executed, not on block entry, and deallocated when the declaration goes out of scope, not when the block is exited(since C99). If the block is entered recursively, a new allocation is performed for every recursion level. All function parameters and non-static block-scope objects have this storage duration, as well as [compound literals](compound_literal.html "c/language/compound literal") used at block scope(until C23)
  * _**static**_ storage duration. The storage duration is the entire execution of the program, and the value stored in the object is initialized only once, prior to [main function](main_function.html "c/language/main function"). All objects declared static and all objects with either internal or external linkage that aren't declared _Thread_local(until C23)[thread_local](../thread/thread_local.html)(since C23)(since C11) have this storage duration. 



    

  * _**thread**_ storage duration. The storage duration is the entire execution of the thread in which it was created, and the value stored in the object is initialized when the thread is started. Each thread has its own, distinct, object. If the thread that executes the expression that accesses this object is not the thread that executed its initialization, the behavior is implementation-defined. All objects declared _Thread_local(until C23)[thread_local](../thread/thread_local.html)(since C23) have this storage duration. 


| (since C11)  
---|---  
  
    

  * _**allocated**_ storage duration. The storage is allocated and deallocated on request, using [dynamic memory allocation](../memory.html "c/memory") functions. 



#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/storage_duration&action=edit&section=3 "Edit section: Linkage")] Linkage

Linkage refers to the ability of an identifier (variable or function) to be referred to in other scopes. If a variable or function with the same identifier is declared in several scopes, but cannot be referred to from all of them, then several instances of the variable are generated. The following linkages are recognized: 

    

  * _**no linkage**_. The variable or function can be referred to only from the scope it is in (block scope). All block scope variables that are not declared `extern` have this linkage, as well as all function parameters and all identifiers that aren't functions or variables. 



    

  * _**internal linkage**_. The variable or function can be referred to from all scopes in the current translation unit. All file scope variables which are declared `static` or `constexpr`(since C23) have this linkage, and all file scope functions declared `static` (static function declarations are only allowed at file scope). 



    

  * _**external linkage**_. The variable or function can be referred to from any other translation units in the entire program. All file scope variables which are not declared `static` or `constexpr`(since C23) have this linkage, all file scope function declarations which are not declared `static`, all block scope function declarations, and, additionally, all variables or functions declared `extern` have this linkage unless a prior declaration with internal linkage is visible at that point. 



If the same identifier appears with both internal and external linkage in the same translation unit, the behavior is undefined. This is possible when [tentative definitions](extern.html "c/language/extern") are used. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/storage_duration&action=edit&section=4 "Edit section: Linkage and libraries")] Linkage and libraries

| This section is incomplete  
Reason: should this be a separate top-level entry in c/language under Miscellaneous?   
---|---  
  
Declarations with external linkage are commonly made available in header files so that all translation units that [#include](../preprocessor/include.html "c/preprocessor/include") the file may refer to the same identifier that are defined elsewhere. 

Any declaration with internal linkage that appears in a header file results in a separate and distinct object in each translation unit that includes that file. 

Library interface, header file "flib.h": 
    
    
    #ifndef FLIB_H
    #define FLIB_H
    void f(void);              // function declaration with external linkage
    extern int state;          // variable declaration with external linkage
    static const int size = 5; // definition of a read-only variable with internal linkage
    enum { MAX = 10 };         // constant definition
    inline int sum (int a, int b) { return a + b; } // inline function definition
    #endif // FLIB_H

Library implementation, source file "flib.c": 
    
    
    #include "flib.h"
     
    static void local_f(int s) {} // definition with internal linkage (only used in this file)
    static int local_state;       // definition with internal linkage (only used in this file)
     
    int state;                       // definition with external linkage (used by main.c)
    void f(void) { local_f(state); } // definition with external linkage (used by main.c)

Application code, source file "main.c": 
    
    
    #include "flib.h"
     
    int main(void)
    {
        int x[MAX] = {size}; // uses the constant and the read-only variable
        state = 7;           // modifies state in flib.c
        f();                 // calls f() in flib.c
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/storage_duration&action=edit&section=5 "Edit section: Keywords")] Keywords

[`auto`](../keyword/auto.html "c/keyword/auto"), [`register`](../keyword/register.html "c/keyword/register"), [`static`](../keyword/static.html "c/keyword/static"), [`extern`](../keyword/extern.html "c/keyword/extern"), [`_Thread_local`](../keyword/_Thread_local.html "c/keyword/ Thread local") [`thread_local`](../keyword/thread_local.html "c/keyword/thread local")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/storage_duration&action=edit&section=6 "Edit section: Notes")] Notes

The keyword _Thread_local is usually used through the convenience macro [thread_local](../thread/thread_local.html "c/thread/thread local"), defined in the header [`<threads.h>`](../header/threads.html "c/header/threads").  | (until C23)  
---|---  
  
The [`typedef`](typedef.html "c/language/typedef") and [`constexpr`](constexpr.html "c/language/constexpr")(since C23) specifiers are formally listed as storage-class specifiers in the C language grammar, but do not specify storage. 

The auto specifier is also used for type inference.  | (since C23)  
---|---  
  
Names at file scope that are const and not extern have external linkage in C (as the default for all file-scope declarations), but internal linkage in C++. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/storage_duration&action=edit&section=7 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    // static storage duration
    int A;
     
    int main(void)
    {
        [printf](../io/fprintf.html)("&A = %p\n", (void*)&A);
     
        // automatic storage duration
        int A = 1;   // hides global A
        [printf](../io/fprintf.html)("&A = %p\n", (void*)&A);
     
        // allocated storage duration
        int* ptr_1 = [malloc](../memory/malloc.html)(sizeof(int));   // start allocated storage duration
        [printf](../io/fprintf.html)("address of int in allocated memory = %p\n", (void*)ptr_1);
        [free](../memory/free.html)(ptr_1);                        // stop allocated storage duration
    }

Possible output: 
    
    
    &A = 0x600ae4
    &A = 0x7ffefb064f5c
    address of int in allocated memory = 0x1f28c30

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/storage_duration&action=edit&section=8 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.2.2 Linkages of identifiers (p: 35-36) 



    

  * 6.2.4 Storage durations of objects (p: 36-37) 



    

  * 6.7.1 Storage-class specifiers (p: 97-100) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.2.2 Linkages of identifiers (p: 29-30) 



    

  * 6.2.4 Storage durations of objects (p: 30) 



    

  * 6.7.1 Storage-class specifiers (p: 79) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.2.2 Linkages of identifiers (p: 36-37) 



    

  * 6.2.4 Storage durations of objects (p: 38-39) 



    

  * 6.7.1 Storage-class specifiers (p: 109-110) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.2.2 Linkages of identifiers (p: 30-31) 



    

  * 6.2.4 Storage durations of objects (p: 32) 



    

  * 6.7.1 Storage-class specifiers (p: 98-99) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.1.2.2 Linkages of identifiers 



    

  * 3.1.2.4 Storage durations of objects 



    

  * 3.5.1 Storage-class specifiers 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/storage_duration&action=edit&section=9 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/storage_duration.html "cpp/language/storage duration") for Storage class specifiers  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/storage_duration&oldid=179994](https://en.cppreference.com/mwiki/index.php?title=c/language/storage_duration&oldid=179994)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



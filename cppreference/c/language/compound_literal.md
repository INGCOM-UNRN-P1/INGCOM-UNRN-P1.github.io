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

[ Expressions](operators.html "c/language/expressions")

General  
---  
[Value category](value_category.html "c/language/value category")  
[Evaluation order and sequence points](eval_order.html "c/language/eval order")  
[Constant expressions](constant_expression.html "c/language/constant expression")  
[Implicit conversions](conversion.html "c/language/conversion")  
[Generic selection](generic.html "c/language/generic") (C11)  
[Constants and literals](operators.html#Constants_and_literals "c/language/expressions")  
[Integer constant](integer_constant.html "c/language/integer constant")  
[Floating constant](floating_constant.html "c/language/floating constant")  
[Character constant](character_constant.html "c/language/character constant")  
[`true`/`false`](bool_constant.html "c/language/bool constant")(C23)  
[`nullptr`](nullptr.html "c/language/nullptr")(C23)  
[String literal](string_literal.html "c/language/string literal")  
**Compound literal** (C99)  
[Operators](operators.html#Operators "c/language/expressions")  
[Operator precedence](operator_precedence.html "c/language/operator precedence")  
[Member access and indirection](operator_member_access.html "c/language/operator member access")  
[Logical operators](operator_logical.html "c/language/operator logical")  
[Comparison operators](operator_comparison.html "c/language/operator comparison")  
[Arithmetic operators](operator_arithmetic.html "c/language/operator arithmetic")  
[Assignment operators](operator_assignment.html "c/language/operator assignment")  
[Increment and decrement](operator_incdec.html "c/language/operator incdec")  
[Function call, comma, conditional operator](operator_other.html "c/language/operator other")  
[sizeof](sizeof.html "c/language/sizeof")  
[`_Alignof`](alignof.html "c/language/ Alignof")(C11*)  
[Cast operators](cast.html "c/language/cast")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

Constructs an unnamed object of specified type (which may be struct, union, or even array type) in-place. 

## Contents

  * [1 Syntax](compound_literal.html#Syntax)
  * [2 Explanation](compound_literal.html#Explanation)
  * [3 Notes](compound_literal.html#Notes)
  * [4 Example](compound_literal.html#Example)
  * [5 References](compound_literal.html#References)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/compound_literal&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**(**` storage-class-specifiers ﻿(optional)(since C23) type `**)**` `**{**` initializer-list `**}**` |  |  (since C99)  
`**(**` storage-class-specifiers ﻿(optional)(since C23) type `**)**` `**{**` initializer-list `**,**` `**}**` |  |  (since C99)  
`**(**` storage-class-specifiers ﻿(optional) type `**)**` `**{**` `**}**` |  |  (since C23)  
  
where 

storage-class-specifiers |  \-  |  (since C23) A list of [storage class specifiers](storage_class_specifiers.html "c/language/storage duration") that can contain only constexpr, static, register, or [thread_local](../thread/thread_local.html)  
---|---|---  
type |  \-  |  a [type name](compatible_type.html#Type_names "c/language/type") specifying any complete object type or an array of unknown size, but not a VLA   
initializer-list |  \-  |  list of initializers suitable for [initialization](initialization.html "c/language/initialization") of an object of type  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/compound_literal&action=edit&section=2 "Edit section: Explanation")] Explanation

The compound literal expression constructs an unnamed object of the type specified by type and initializes it as specified by initializer-list. [Designated initializers](initialization.html "c/language/initialization") are accepted. 

The type of the compound literal is type (except when type is an array of unknown size; its size is deduced from the initializer-list as in [array initialization](array_initialization.html "c/language/array initialization")). 

The value category of a compound literal is [lvalue](value_category.html "c/language/value category") (its address can be taken). 

The unnamed object to which the compound literal evaluates has static [storage duration](storage_class_specifiers.html "c/language/storage duration") if the compound literal occurs at file scope and automatic [storage duration](storage_class_specifiers.html "c/language/storage duration") if the compound literal occurs at block scope (in which case the object's [lifetime](lifetime.html "c/language/lifetime") ends at the end of the enclosing block). | (until C23)  
---|---  
If the compound literal is evaluated outside the body of a function and outside of any parameter list, it is associated with file scope; otherwise, it is associated with the enclosing block. Depending on this association, the storage-class specifiers (possibly empty), type name, and initializer list, if any, shall be such that they are valid specifiers for an object definition in file scope or block scope, respectively, of the following form:  |   
---  
storage-class-specifiers type `**typeof(**` type `**)**` ID `**=**` `**{**` initializer-list `**}**` `**;**` |  |   
where _ID_ is an identifier that is unique for the whole program. A compound literal provides an unnamed object whose value, type, storage duration and other properties are as if given by the definition syntax above; if the storage duration is automatic, the lifetime of the instance of the unnamed object is the current execution of the enclosing block. If the storage-class specifiers contain other specifiers than constexpr, static, register, or [thread_local](../thread/thread_local.html) the behavior is undefined. (since C23)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/compound_literal&action=edit&section=3 "Edit section: Notes")] Notes

Compound literals of const-qualified character or wide character array types may share storage with [string literals](string_literal.html "c/language/string literal"). 
    
    
    (const char []){"abc"} == "abc" // might be 1 or 0, unspecified

Each compound literal creates only a single object in its scope: 

Run this code
    
    
    #include <assert.h>
     
    int main(void)
    {
        struct S
        {
            int i;
        }
        *p = 0, *q;
        int j = 0;
    again:
        q = p,
        p = &((struct S){ j++ }); // creates an unnamed object of type S,
                                  // initializes it to the value formerly
                                  // held in j, then assigns the address
                                  // of this unnamed object to the pointer p
        if (j < 2)
            goto again; // note: if a loop were used, it would end scope here,
                        // which would terminate the lifetime of the compound
                        // literal leaving p as a dangling pointer
        [assert](../error/assert.html)(p == q && q->i == 1);
    }

Because compound literals are unnamed, a compound literal cannot reference itself (a named struct can include a pointer to itself). 

Although the syntax of a compound literal is similar to a [cast](cast.html "c/language/cast"), the important distinction is that a cast is a non-lvalue expression while a compound literal is an lvalue. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/compound_literal&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
     
    int *p = (int[]){2, 4}; // creates an unnamed static array of type int[2]
                            // initializes the array to the values {2, 4}
                            // creates pointer p to point at the first element of
                            // the array
    const float *pc = (const float []){1e0, 1e1, 1e2}; // read-only compound literal
     
    struct point {double x,y;};
     
    int main(void)
    {
        int n = 2, *p = &n;
        p = (int [2]){*p}; // creates an unnamed automatic array of type int[2]
                           // initializes the first element to the value formerly
                           // held in *p
                           // initializes the second element to zero
                           // stores the address of the first element in p
     
        void drawline1(struct point from, struct point to);
        void drawline2(struct point *from, struct point *to);
        drawline1(
            (struct point){.x=1, .y=1},  // creates two structs with block scope and
            (struct point){.x=3, .y=4}); // calls drawline1, passing them by value
        drawline2(
            &(struct point){.x=1, .y=1},  // creates two structs with block scope and
            &(struct point){.x=3, .y=4}); // calls drawline2, passing their addresses
    }
     
    void drawline1(struct point from, struct point to)
    {
        [printf](../io/fprintf.html)("drawline1: `from` @ %p {%.2f, %.2f}, `to` @ %p {%.2f, %.2f}\n",
            (void*)&from, from.x, from.y, (void*)&to, to.x, to.y);
    }
     
    void drawline2(struct point *from, struct point *to)
    {
        [printf](../io/fprintf.html)("drawline2: `from` @ %p {%.2f, %.2f}, `to` @ %p {%.2f, %.2f}\n",
            (void*)from, from->x, from->y, (void*)to, to->x, to->y);
    }

Possible output: 
    
    
    drawline1: `from` @ 0x7ffd24facea0 {1.00, 1.00}, `to` @ 0x7ffd24face90 {3.00, 4.00}
    drawline2: `from` @ 0x7ffd24facec0 {1.00, 1.00}, `to` @ 0x7ffd24faced0 {3.00, 4.00}

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/compound_literal&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.5.2.5 Compound literals (p: 77-80) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.5.2.5 Compound literals (p: 61-63) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.5.2.5 Compound literals (p: 85-87) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.5.2.5 Compound literals (p: 75-77) 



Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/compound_literal&oldid=182530](https://en.cppreference.com/mwiki/index.php?title=c/language/compound_literal&oldid=182530)" 

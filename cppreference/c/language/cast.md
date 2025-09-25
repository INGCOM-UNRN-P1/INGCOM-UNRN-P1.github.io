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
[Compound literal](compound_literal.html "c/language/compound literal") (C99)  
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
**Cast operators**  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

Performs explicit type conversion 

## Contents

  * [1 Syntax](cast.html#Syntax)
  * [2 Explanation](cast.html#Explanation)
  * [3 Notes](cast.html#Notes)
  * [4 Example](cast.html#Example)
  * [5 References](cast.html#References)
  * [6 See also](cast.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/cast&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**(**` type-name `**)**` expression |  |   
  
where 

type-name |  \-  |  either the type void or any [scalar type](compatible_type.html#Type_groups "c/language/type")  
---|---|---  
expression |  \-  |  any [expression](operators.html "c/language/expressions") of [scalar type](compatible_type.html#Type_groups "c/language/type") (unless type-name is void, in which case it can be anything)   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/cast&action=edit&section=2 "Edit section: Explanation")] Explanation

If type-name is void, then expression is evaluated for its side-effects and its returned value is discarded, same as when expression is used on its own, as an [expression statement](statements.html#Expression_statements "c/language/statements"). 

Otherwise, if type-name is exactly the type of expression, nothing is done (except that if expression has floating type and is represented with greater range and precision than its type indicates – see below). 

Otherwise, the value of expression is converted to the type named by type-name, as follows: 

Every [implicit conversion as if by assignment](conversion.html "c/language/conversion") is allowed. 

In addition to the implicit conversions, the following conversions are allowed: 

  * Any integer can be cast to any pointer type. Except for the null pointer constants such as [NULL](../types/NULL.html "c/types/NULL") (which [doesn't need a cast](conversion.html "c/language/conversion")), the result is implementation-defined, may not be correctly aligned, may not point to an object of the referenced type, and may be a [trap representation](object.html "c/language/object"). 
  * Any pointer type can be cast to any integer type. The result is implementation-defined, even for null pointer values (they do not necessarily result in the value zero). If the result cannot be represented in the target type, the behavior is undefined (unsigned integers do not implement modulo arithmetic on a cast from pointer). 
  * Any pointer to object can be cast to any other pointer to object. If the value is not correctly aligned for the target type, the behavior is undefined. Otherwise, if the value is converted back to the original type, it compares equal to the original value. If a pointer to object is cast to pointer to any character type, the result points at the lowest byte of the object and may be incremented up to sizeof the target type (in other words, can be used to examine [object representation](object.html "c/language/object") or to make a copy via [memcpy](../string/byte/memcpy.html "c/string/byte/memcpy") or [memmove](../string/byte/memmove.html "c/string/byte/memmove")). 
  * Any pointer to function can be cast to a pointer to any other function type. If the resulting pointer is converted back to the original type, it compares equal to the original value. If the converted pointer is used to make a function call, the behavior is undefined (unless the function types are [compatible](compatible_type.html#Compatible_types "c/language/type")). 
  * When casting between pointers (either object or function), if the original value is a null pointer value of its type, the result is the correct null pointer value for the target type. 



In any case (both when executing an implicit conversion and in the same-type cast), if expression and type-name are floating types and expression is represented with greater range and precision than its type indicates (see [FLT_EVAL_METHOD](../types/limits/FLT_EVAL_METHOD.html)), the range and precision are stripped off to match the target type. 

The [value category](value_category.html "c/language/value category") of the cast expression is always non-lvalue. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/cast&action=edit&section=3 "Edit section: Notes")] Notes

Because [`const`](const.html "c/language/const"), [`volatile`](volatile.html "c/language/volatile"), [`restrict`](restrict.html "c/language/restrict"), and [`_Atomic`](atomic.html "c/language/atomic") qualifiers have effect on [lvalues](value_category.html "c/language/value category") only, a cast to a cvr-qualified or atomic type is exactly equivalent to the cast to the corresponding unqualified type. 

The cast to void is sometimes useful to silence compiler warnings about unused results. 

The conversions not listed here are not allowed. In particular, 

  * there are no conversions between pointers and floating types; 
  * there are no conversions between pointers to functions and pointers to objects (including void*). 

If the implementation provides [intptr_t](../types/integer.html "c/types/integer") and/or [uintptr_t](../types/integer.html "c/types/integer"), then a cast from a pointer to an object type (including _cv_ void) to these types is always well-defined. However, this is not guaranteed for a function pointer.  | (since C99)  
---|---  
  
Note that conversions between function pointers and object pointers are accepted as extensions by many compilers, and expected by some usages of POSIX [`dlsym`](https://pubs.opengroup.org/onlinepubs/9799919799/functions/dlsym.html) function. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/cast&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
     
    int main(void)
    {
        // examining object representation is a legitimate use of cast
        const double d = 3.14;
        [printf](../io/fprintf.html)("The double %.2f (%a) is: ", d, d);
        for ([size_t](../types/size_t.html) n = 0; n != sizeof d; ++n)
            [printf](../io/fprintf.html)("%02X ", ((unsigned char*)&d)[n]);
     
        // edge cases
        struct S { int x; } s;
        // (struct S)s; // error; not a scalar type, even though
                        // casting to the same type does nothing
        (void)s; // okay to cast any type to void
    }

Output: 
    
    
    The double 3.14 (0x1.91eb851eb851fp+1) is: 1F 85 EB 51 B8 1E 09 40

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/cast&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.5.5 Cast operators (p: 83-84) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.5.4 Cast operators (p: 65-66) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.5.4 Cast operators (p: 91) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.5.4 Cast operators (p: 81) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.3.4 Cast operators 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/cast&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/explicit_cast.html "cpp/language/explicit cast") for explicit type conversion  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/cast&oldid=183160](https://en.cppreference.com/mwiki/index.php?title=c/language/cast&oldid=183160)" 

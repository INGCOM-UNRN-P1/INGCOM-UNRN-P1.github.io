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
**Value category**  
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
[Cast operators](cast.html "c/language/cast")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

Each [expression](operators.html "c/language/expressions") in C (an operator with its arguments, a function call, a constant, a variable name, etc) is characterized by two independent properties: a [type](compatible_type.html#Type "c/language/type") and a [value category](operators.html#General "c/language/expressions"). 

Every expression belongs to one of three value categories: lvalue, non-lvalue object (rvalue), and function designator. 

## Contents

  * [1 Lvalue expressions](value_category.html#Lvalue_expressions)
    * [1.1 Modifiable lvalue expressions](value_category.html#Modifiable_lvalue_expressions)
  * [2 Non-lvalue object expressions](value_category.html#Non-lvalue_object_expressions)
  * [3 Function designator expression](value_category.html#Function_designator_expression)
  * [4 References](value_category.html#References)
  * [5 See also](value_category.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/value_category&action=edit&section=1 "Edit section: Lvalue expressions")] Lvalue expressions

Lvalue expression is any expression with [object type](compatible_type.html#Type_groups "c/language/type") other than the type void, which potentially designates an [object](object.html "c/language/object") (the behavior is undefined if an lvalue does not actually designate an object when it is evaluated). In other words, lvalue expression evaluates to the _object identity ﻿_. The name of this value category (“left value”) is historic and reflects the use of lvalue expressions as the left-hand operand of the assignment operator in the CPL programming language. 

Lvalue expressions can be used in the following _lvalue contexts ﻿_ : 

  * as the operand of the [address-of operator](operator_member_access.html "c/language/operator member access") (except if the lvalue designates a [bit-field](bit_field.html "c/language/bit field") or was declared [register](storage_class_specifiers.html "c/language/storage duration")). 
  * as the operand of the pre/post [increment and decrement operators](operator_incdec.html "c/language/operator incdec"). 
  * as the left-hand operand of the [member access](operator_member_access.html "c/language/operator member access") (dot) operator. 
  * as the left-hand operand of the [assignment and compound assignment](operator_assignment.html "c/language/operator assignment") operators. 



If an lvalue expression is used in any context other than [`sizeof`](sizeof.html "c/language/sizeof"), [`_Alignof`](alignof.html "c/language/ Alignof"), or the operators listed above, non-array lvalues of any complete type undergo [lvalue conversion](conversion.html "c/language/conversion"), which models the memory load of the value of the object from its location. Similarly, array lvalues undergo [array-to-pointer conversion](conversion.html "c/language/conversion") when used in any context other than sizeof, `_Alignof`, address-of operator, or array initialization from a string literal. 

The semantics of [`const`](const.html "c/language/const")/[`volatile`](volatile.html "c/language/volatile")/[`restrict`](restrict.html "c/language/restrict")-qualifiers and [atomic](atomic.html "c/language/atomic") types apply to lvalues only (lvalue conversion strips the qualifiers and removes atomicity). 

The following expressions are lvalues: 

  * identifiers, including function named parameters, provided they were declared as designating objects (not functions or enumeration constants) 
  * [string literals](string_literal.html "c/language/string literal")
  * (C99) [compound literals](compound_literal.html "c/language/compound literal")
  * parenthesized expression if the unparenthesized expression is an lvalue 
  * the result of a member access (dot) operator if its left-hand argument is lvalue 
  * the result of a member access through pointer `**- >**` operator 
  * the result of the indirection (unary `*****`) operator applied to a pointer to object 
  * the result of the subscription operator (`**[]**`) 



#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/value_category&action=edit&section=2 "Edit section: Modifiable lvalue expressions")] Modifiable lvalue expressions

A _modifiable lvalue_ is any lvalue expression of complete, non-array type which is not [const](const.html "c/language/const")-qualified, and, if it's a struct/union, has no members that are [const](const.html "c/language/const")-qualified, recursively. 

Only modifiable lvalue expressions may be used as arguments to increment/decrement, and as left-hand arguments of assignment and compound assignment operators. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/value_category&action=edit&section=3 "Edit section: Non-lvalue object expressions")] Non-lvalue object expressions

Known as _rvalues ﻿_ , non-lvalue object expressions are the expressions of object types that do not designate objects, but rather values that have no object identity or storage location. The address of a non-lvalue object expression cannot be taken. 

The following expressions are non-lvalue object expressions: 

  * integer, character, and floating constants 
  * all operators not specified to return lvalues, including 



    

  * any function call expression 
  * any cast expression (note that compound literals, which look similar, are lvalues) 
  * member access operator (dot) applied to a non-lvalue structure/union, f().x, (x, s1).a, (s1 = s2).m
  * results of all arithmetic, relational, logical, and bitwise operators 
  * results of increment and decrement operators (note: pre-forms are lvalues in C++) 
  * results of assignment operators (note: also lvalues in C++) 
  * the conditional operator (note: is lvalue in C++ if both the second and third operands are lvalues of the same type) 
  * the comma operator (note: is lvalue in C++ if the second operand is) 
  * the address-of operator, even if neutralized by application to the result of unary `*****` operator 



As a special case, expressions of type void are assumed to be non-lvalue object expressions that yield a value which has no representation and requires no storage. 

Note that a struct/union rvalue that has a member (possibly nested) of array type does in fact designate an object with [temporary lifetime](lifetime.html "c/language/lifetime"). This object can be accessed through lvalue expressions that form by indexing the array member or by indirection through the pointer obtained by array-to-pointer conversion of the array member.  | (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/value_category&action=edit&section=4 "Edit section: Function designator expression")] Function designator expression

A function designator (the identifier introduced by a [function declaration](function_declaration.html "c/language/function declaration")) is an expression of function type. When used in any context other than the address-of operator, [`sizeof`](sizeof.html "c/language/sizeof"), and [`_Alignof`](alignof.html "c/language/ Alignof") (the last two generate compile errors when applied to functions), the function designator is always converted to a non-lvalue pointer to function. Note that the function-call operator is defined for pointers to functions and not for function designators themselves. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/value_category&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.3.2.1 Lvalues, arrays, and function designators (p: 48-49) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.3.2.1 Lvalues, arrays, and function designators (p: 40) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.3.2.1 Lvalues, arrays, and function designators (p: 54-55) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.3.2.1 Lvalues, arrays, and function designators (p: 46) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.2.2.1 Lvalues and function designators 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/value_category&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/value_category.html "cpp/language/value category") for Value categories  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/value_category&oldid=182490](https://en.cppreference.com/mwiki/index.php?title=c/language/value_category&oldid=182490)" 

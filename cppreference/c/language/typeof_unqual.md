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
[Cast operators](cast.html "c/language/cast")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

Determines the type of an object. 

## Contents

  * [1 Syntax](typeof_unqual.html#Syntax)
  * [2 Explanation](typeof_unqual.html#Explanation)
  * [3 Notes](typeof_unqual.html#Notes)
  * [4 Example](typeof_unqual.html#Example)
  * [5 References](typeof_unqual.html#References)
  * [6 See also](typeof_unqual.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/typeof&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**typeof(**` type `**)**` |  (1)  |   
`**typeof(**` expression `**)**` |  (2)  |   
`**typeof_unqual(**` type `**)**` |  (3)  |   
`**typeof_unqual(**` expression `**)**` |  (4)  |   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/typeof&action=edit&section=2 "Edit section: Explanation")] Explanation

1) produces the type-name with any nested typeof-specifier evaluated 

2) yields the type-name representing the type of its operand. No implicit conversions are applied to expression.

3,4) the same as (1) and (2) respectively but remove qualifiers

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/typeof&action=edit&section=3 "Edit section: Notes")] Notes

`typeof` and `typeof_unqual` are collectively called the _typeof operators_. The `typeof` operators cannot be applied to bit-field members. If the type of the operand is a variably modified type, the operand is evaluated; otherwise, the operand is not evaluated. The result of the `typeof_unqual` operator is the non-atomic unqualified type that would result from the `typeof` operator. The `typeof` operator preserves all qualifiers. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/typeof&action=edit&section=4 "Edit section: Example")] Example

| This section is incomplete  
Reason: no example   
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/typeof&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.2.5 The typeof specifiers (p: 115-118) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/typeof&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/decltype.html "cpp/language/decltype") for decltype  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/typeof&oldid=159494](https://en.cppreference.com/mwiki/index.php?title=c/language/typeof&oldid=159494)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo no example](../../Category%253ATodo_no_example.html "Category:Todo no example")



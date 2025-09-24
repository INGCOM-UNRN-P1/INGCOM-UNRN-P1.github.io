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
**Expressions**  
[ Initialization](initialization.html "c/language/initialization")  
[ Declarations](declarations.html "c/language/declarations")  
[ Functions](functions.html "c/language/functions")  
Miscellaneous  
[ History of C](history.html "c/language/history")  
[Technical Specifications](../experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

**Expressions**

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

An expression is a sequence of _operators_ and their _operands_ , that specifies a computation. 

Expression evaluation may produce a result (e.g., evaluation of 2 + 2 produces the result 4), may generate side-effects (e.g. evaluation of [printf](../io/fprintf.html)("%d", 4) sends the character '4' to the standard output stream), and may designate objects or functions. 

## Contents

  * [1 General](operators.html#General)
  * [2 Operators](operators.html#Operators)
    * [2.1 Conversions](operators.html#Conversions)
    * [2.2 Other](operators.html#Other)
  * [3 Primary expressions](operators.html#Primary_expressions)
    * [3.1 Constants and literals](operators.html#Constants_and_literals)
  * [4 Unevaluated expressions](operators.html#Unevaluated_expressions)
  * [5 References](operators.html#References)
  * [6 See also](operators.html#See_also)

  
---  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/expressions&action=edit&section=1 "Edit section: General")] General

  * [value categories](value_category.html "c/language/value category") (lvalue, non-lvalue object, function designator) classify expressions by their values 
  * [order of evaluation](eval_order.html "c/language/eval order") of arguments and subexpressions specifies the order in which intermediate results are obtained 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/expressions&action=edit&section=2 "Edit section: Operators")] Operators

Common operators   
---  
[assignment](operator_assignment.html "c/language/operator assignment") | [increment  
decrement](operator_incdec.html "c/language/operator incdec") | [arithmetic](operator_arithmetic.html "c/language/operator arithmetic") | [logical](operator_logical.html "c/language/operator logical") | [comparison](operator_comparison.html "c/language/operator comparison") | [member  
access](operator_member_access.html "c/language/operator member access") | [other](operator_other.html "c/language/operator other")  
a = b  
a += b  
a -= b  
a *= b  
a /= b  
a %= b  
a &= b  
a |= b  
a ^= b  
a <<= b  
a >>= b |  ++a  
\--a  
a++  
a\-- |  +a  
-a  
a + b  
a - b  
a * b  
a / b  
a % b  
~a  
a & b  
a | b  
a ^ b  
a << b  
a >> b |  !a  
a && b  
a || b |  a == b  
a != b  
a < b  
a > b  
a <= b  
a >= b |  a[b]  
*a  
&a  
a->b  
a.b |  a(...)  
a, b  
(type) a  
a ? b : c  
sizeof  
  
_Alignof  
(since C11)  
(until C23)  
  
alignof  
(since C23)  
  
  * [operator precedence](operator_precedence.html "c/language/operator precedence") defines the order in which operators are bound to their arguments 
  * [alternative representations](operator_alternative.html "c/language/operator alternative") are alternative spellings for some operators 



#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/expressions&action=edit&section=3 "Edit section: Conversions")] Conversions

  * [Implicit conversions](conversion.html "c/language/conversion") take place when types of operands do not match the expectations of operators 
  * [Casts](cast.html "c/language/cast") may be used to explicitly convert values from one type to another. 



#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/expressions&action=edit&section=4 "Edit section: Other")] Other

  * [constant expressions](constant_expression.html "c/language/constant expression") can be evaluated at compile time and used in compile-time context (non-VLA(since C99)array sizes, static initializers, etc) 



  * [generic selections](generic.html "c/language/generic") can execute different expressions depending on the types of the arguments 

| (since C11)  
---|---  
  
  * Floating-point arithmetic may raise exceptions and report errors as specified in [`math_errhandling`](../numeric/math/math_errhandling.html "c/numeric/math/math errhandling")
  * The standard [#pragmas](../preprocessor/impl.html "c/preprocessor/impl") `FENV_ACCESS`, `FP_CONTRACT`, and `CX_LIMITED_RANGE` as well as the [floating-point evaluation precision](../types/limits/FLT_EVAL_METHOD.html "c/types/limits/FLT EVAL METHOD") and [rounding direction](../numeric/fenv/FE_round.html "c/numeric/fenv/FE round") control the way floating-point arithmetic are executed. 

| (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/expressions&action=edit&section=5 "Edit section: Primary expressions")] Primary expressions

The operands of any operator may be other expressions or they may be _primary expressions_ (e.g. in 1 + 2 * 3, the operands of operator+ are the subexpression 2 * 3 and the primary expression 1). 

Primary expressions are any of the following: 

1) Constants and literals (e.g. 2 or "Hello, world")

2) Suitably declared [identifiers](identifiers.html "c/language/identifier") (e.g. n or [printf](../io/fprintf.html))

3) [Generic selections](generic.html "c/language/generic") | (since C11)  
---|---  
  
Any expression in parentheses is also classified as a primary expression: this guarantees that the parentheses have higher precedence than any operator. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/expressions&action=edit&section=6 "Edit section: Constants and literals")] Constants and literals

Constant values of certain types may be embedded in the source code of a C program using specialized expressions known as literals (for lvalue expressions) and constants (for non-lvalue expressions) 

  * [integer constants](integer_constant.html "c/language/integer constant") are decimal, octal, or hexadecimal numbers of integer type. 
  * [character constants](character_constant.html "c/language/character constant") are individual characters of type int suitable for conversion to a character type or of type char8_t,(since C23) char16_t, char32_t, or(since C11) wchar_t
  * [floating constants](floating_constant.html "c/language/floating constant") are values of type float, double, or long double



  * predefined constants [true/false](bool_constant.html "c/language/bool constant") are values of type bool
  * predefined constant [`nullptr`](nullptr.html "c/language/nullptr") is a value of type [nullptr_t](../types/nullptr_t.html "c/types/nullptr t")

| (since C23)  
---|---  
  
  * [string literals](string_literal.html "c/language/string literal") are sequences of characters of type char[], char8_t[](since C23), char16_t[], char32_t[],(since C11) or wchar_t[] that represent null-terminated strings 



  * [compound literals](compound_literal.html "c/language/compound literal") are values of struct, union, or array type directly embedded in program code 

| (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/expressions&action=edit&section=7 "Edit section: Unevaluated expressions")] Unevaluated expressions

The operands of the [sizeof operator](sizeof.html "c/language/sizeof") are expressions that are not evaluated (unless they are VLAs)(since C99). Thus, [size_t](../types/size_t.html) n = sizeof([printf](../io/fprintf.html)("%d", 4)); does not perform console output. 

The operands of the [`_Alignof`](alignof.html "c/language/ Alignof")(until C23)[`alignof`](alignof.html "c/language/alignof")(since C23) operator, the controlling expression of a [generic selection](generic.html "c/language/generic"), and size expressions of VLAs that are operands of `_Alignof`(until C23)alignof(since C23) are also expressions that are not evaluated.  | (since C11)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/expressions&action=edit&section=8 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.5 Expressions (p: TBD) 



    

  * 6.6 Constant expressions (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.5 Expressions (p: 55-75) 



    

  * 6.6 Constant expressions (p: 76-77) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.5 Expressions (p: 76-105) 



    

  * 6.6 Constant expressions (p: 106-107) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.5 Expressions (p: 67-94) 



    

  * 6.6 Constant expressions (p: 95-96) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.3 EXPRESSIONS 



    

  * 3.4 CONSTANT EXPRESSIONS 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/expressions&action=edit&section=9 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/expressions.html "cpp/language/expressions") for Expressions  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/expressions&oldid=178465](https://en.cppreference.com/mwiki/index.php?title=c/language/expressions&oldid=178465)" 

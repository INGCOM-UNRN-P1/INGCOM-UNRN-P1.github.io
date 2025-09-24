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
**Operator precedence**  
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

The following table lists the precedence and associativity of C operators. Operators are listed top to bottom, in descending precedence. 

Precedence  |  Operator  |  Description  |  Associativity   
---|---|---|---  
1  |  `++` `--` |  Suffix/postfix increment and decrement  |  Left-to-right   
`()` |  Function call   
`[]` |  Array subscripting   
`.` |  Structure and union member access   
`->` |  Structure and union member access through pointer   
`(_type_){_list_}` |  Compound literal(C99)  
2  |  `++` `--` |  Prefix increment and decrement[[note 1]](operator_precedence.html#cite_note-1) |  Right-to-left   
`+` `-` |  Unary plus and minus   
`!` `~` |  Logical NOT and bitwise NOT   
`(_type_)` |  Cast   
`*` |  Indirection (dereference)   
`&` |  Address-of   
`sizeof` |  Size-of[[note 2]](operator_precedence.html#cite_note-2)  
`_Alignof` |  Alignment requirement(C11)  
3  |  `*` `/` `%` |  Multiplication, division, and remainder  |  Left-to-right   
4  |  `+` `-` |  Addition and subtraction   
5  |  `<<` `>>` |  Bitwise left shift and right shift   
6  |  `<` `<=` |  For relational operators < and ≤ respectively   
`>` `>=` |  For relational operators > and ≥ respectively   
7  |  `==` `!=` |  For relational = and ≠ respectively   
8  |  `&` |  Bitwise AND   
9  |  `^` |  Bitwise XOR (exclusive or)   
10  |  `|` |  Bitwise OR (inclusive or)   
11  |  `&&` |  Logical AND   
12  |  `||` |  Logical OR   
13  |  `?:` |  Ternary conditional[[note 3]](operator_precedence.html#cite_note-3) |  Right-to-left   
14[[note 4]](operator_precedence.html#cite_note-4) |  `=` |  Simple assignment   
`+=` `-=` |  Assignment by sum and difference   
`*=` `/=` `%=` |  Assignment by product, quotient, and remainder   
`<<=` `>>=` |  Assignment by bitwise left shift and right shift   
`&=` `^=` `|=` |  Assignment by bitwise AND, XOR, and OR   
15  |  `,` |  Comma  |  Left-to-right   
  
  1. [↑](operator_precedence.html#cite_ref-1) The operand of prefix `++` and `--` can't be a type cast. This rule grammatically forbids some expressions that would be semantically invalid anyway. Some compilers ignore this rule and detect the invalidity semantically.
  2. [↑](operator_precedence.html#cite_ref-2) The operand of `sizeof` can't be a type cast: the expression sizeof (int) * p is unambiguously interpreted as (sizeof(int)) * p, but not sizeof((int)*p).
  3. [↑](operator_precedence.html#cite_ref-3) The expression in the middle of the conditional operator (between `**?**` and `**:**`) is parsed as if parenthesized: its precedence relative to `?:` is ignored.
  4. [↑](operator_precedence.html#cite_ref-4) Assignment operators' left operands must be unary (level-2 non-cast) expressions. This rule grammatically forbids some expressions that would be semantically invalid anyway. Many compilers ignore this rule and detect the invalidity semantically. For example, e = a < d ? a++ : a = d is an expression that cannot be parsed because of this rule. However, many compilers ignore this rule and parse it as e = ( ((a < d) ? (a++) : a) = d ), and then give an error because it is semantically invalid.



When parsing an expression, an operator which is listed on some row will be bound tighter (as if by parentheses) to its arguments than any operator that is listed on a row further below it. For example, the expression *p++ is parsed as *(p++), and not as (*p)++. 

Operators that are in the same cell (there may be several rows of operators listed in a cell) are evaluated with the same precedence, in the given direction. For example, the expression a=b=c is parsed as a=(b=c), and not as (a=b)=c because of right-to-left associativity. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_precedence&action=edit&section=1 "Edit section: Notes")] Notes

Precedence and associativity are independent from [order of evaluation](eval_order.html "c/language/eval order"). 

The standard itself doesn't specify precedence levels. They are derived from the grammar. 

In C++, the conditional operator has the same precedence as assignment operators, and prefix `++` and `--` and assignment operators don't have the restrictions about their operands. 

Associativity specification is redundant for unary operators and is only shown for completeness: unary prefix operators always associate right-to-left (sizeof ++*p is sizeof(++(*p))) and unary postfix operators always associate left-to-right (a[1][2]++ is ((a[1])[2])++). Note that the associativity is meaningful for member access operators, even though they are grouped with unary postfix operators: a.b++ is parsed (a.b)++ and not a.(b++). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_precedence&action=edit&section=2 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * A.2.1 Expressions 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * A.2.1 Expressions 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * A.2.1 Expressions 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * A.1.2.1 Expressions 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_precedence&action=edit&section=3 "Edit section: See also")] See also

[Order of evaluation](eval_order.html "c/language/eval order") of operator arguments at run time. 

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
[C++ documentation](../../cpp/language/operator_precedence.html "cpp/language/operator precedence") for C++ operator precedence  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/operator_precedence&oldid=155954](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_precedence&oldid=155954)" 

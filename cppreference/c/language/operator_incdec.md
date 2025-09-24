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
**Increment and decrement**  
[Function call, comma, conditional operator](operator_other.html "c/language/operator other")  
[sizeof](sizeof.html "c/language/sizeof")  
[`_Alignof`](alignof.html "c/language/ Alignof")(C11*)  
[Cast operators](cast.html "c/language/cast")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

Increment/decrement operators are unary operators that increment/decrement the value of a variable by 1. 

They can have postfix form:   
  
---  
expr `**++**` |  |   
expr `**--**` |  |   
  
As well as the prefix form:   
  
---  
`**++**` expr |  |   
`**--**` expr |  |   
  
The operand expr of both prefix and postfix increment or decrement must be a [modifiable lvalue](value_category.html "c/language/value category") of [integer type](compatible_type.html "c/language/type") (including `_Bool` and enums), real floating type, or a pointer type. It may be cvr-qualified, unqualified, or [atomic](atomic.html "c/language/atomic"). 

The result of the postfix increment and decrement operators is the value of expr. 

The result of the prefix increment operator is the result of adding the value `1` to the value of expr: the expression ++e is equivalent to e += 1. The result of the prefix decrement operator is the result of subtracting the value `1` from the value of expr: the expression \--e is equivalent to e -= 1. 

Increment operators initiate the side-effect of adding the value `1` of appropriate type to the operand. Decrement operators initiate the side-effect of subtracting the value `1` of appropriate type from the operand. As with any other side-effects, these operations complete at or before the next [sequence point](eval_order.html "c/language/eval order"). 
    
    
    int a = 1;
    int b = a++; // stores 1+a (which is 2) to a
                 // returns the old value of a (which is 1)
                 // After this line, b == 1 and a == 2
    a = 1;
    int c = ++a; // stores 1+a (which is 2) to a
                 // returns 1+a (which is 2)
                 // after this line, c == 2 and a == 2

Post-increment or post-decrement on any [atomic variable](atomic.html "c/language/atomic") is an atomic read-modify-write operation with memory order [memory_order_seq_cst](../atomic/memory_order.html "c/atomic/memory order").  | (since C11)  
---|---  
  
See [arithmetic operators](operator_arithmetic.html "c/language/operator arithmetic") for limitations on pointer arithmetic, as well as for implicit conversions applied to the operands. 

## Contents

  * [1 Notes](operator_incdec.html#Notes)
  * [2 Example](operator_incdec.html#Example)
  * [3 References](operator_incdec.html#References)
  * [4 See also](operator_incdec.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_incdec&action=edit&section=1 "Edit section: Notes")] Notes

Because of the side-effects involved, increment and decrement operators must be used with care to avoid undefined behavior due to violations of [sequencing rules](eval_order.html "c/language/eval order"). 

Increment/decrement operators are not defined for complex or imaginary types: the usual definition of adding/subtracting the real number 1 would have no effect on imaginary types, and making it add/subtract `i` for imaginaries but `1` for complex numbers would have made it handle `0+yi` different from `yi`. 

Unlike C++ (and some implementations of C), the increment/decrement expressions are never themselves lvalues: &++a is invalid. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_incdec&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        int a = 1;
        int b = 1;
     
        [printf](../io/fprintf.html)("original values: a == %d, b == %d\n", a, b);
        [printf](../io/fprintf.html)("result of postfix operators: a++ == %d, b-- == %d\n", a++, b--);
        [printf](../io/fprintf.html)("after postfix operators applied: a == %d, b == %d\n", a, b);
        [printf](../io/fprintf.html)("\n");
     
        // Reset a and b.
        a = 1;
        b = 1;
     
        [printf](../io/fprintf.html)("original values: a == %d, b == %d\n", a, b);
        [printf](../io/fprintf.html)("result of prefix operators: ++a == %d, --b == %d\n", ++a, --b);
        [printf](../io/fprintf.html)("after prefix operators applied: a == %d, b == %d\n", a, b);
    }

Output: 
    
    
    original values: a == 1, b == 1
    result of postfix operators: a++ == 1, b-- == 1
    after postfix operators applied: a == 2, b == 0
     
    original values: a == 1, b == 1
    result of prefix operators: ++a == 2, --b == 0
    after prefix operators applied: a == 2, b == 0

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_incdec&action=edit&section=3 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.5.2.4 Postfix increment and decrement operators (p: TBD) 



    

  * 6.5.3.1 Prefix increment and decrement operators (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.5.2.4 Postfix increment and decrement operators (p: TBD) 



    

  * 6.5.3.1 Prefix increment and decrement operators (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.5.2.4 Postfix increment and decrement operators (p: 85) 



    

  * 6.5.3.1 Prefix increment and decrement operators (p: 88) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.5.2.4 Postfix increment and decrement operators (p: 75) 



    

  * 6.5.3.1 Prefix increment and decrement operators (p: 78) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.3.2.4 Postfix increment and decrement operators 



    

  * 3.3.3.1 Prefix increment and decrement operators 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_incdec&action=edit&section=4 "Edit section: See also")] See also

[Operator precedence](operator_precedence.html "c/language/operator precedence")

Common operators   
---  
[assignment](operator_assignment.html "c/language/operator assignment") | **increment  
decrement** | [arithmetic](operator_arithmetic.html "c/language/operator arithmetic") | [logical](operator_logical.html "c/language/operator logical") | [comparison](operator_comparison.html "c/language/operator comparison") | [member  
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
[C++ documentation](../../cpp/language/operator_incdec.html "cpp/language/operator incdec") for Increment/decrement operators  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/operator_incdec&oldid=153216](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_incdec&oldid=153216)" 

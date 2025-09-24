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
**Logical operators**  
[Comparison operators](operator_comparison.html "c/language/operator comparison")  
[Arithmetic operators](operator_arithmetic.html "c/language/operator arithmetic")  
[Assignment operators](operator_assignment.html "c/language/operator assignment")  
[Increment and decrement](operator_incdec.html "c/language/operator incdec")  
[Function call, comma, conditional operator](operator_other.html "c/language/operator other")  
[sizeof](sizeof.html "c/language/sizeof")  
[`_Alignof`](alignof.html "c/language/ Alignof")(C11*)  
[Cast operators](cast.html "c/language/cast")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

Logical operators apply standard boolean algebra operations to their operands. 

Operator  |  Operator name  |  Example  |  Result   
---|---|---|---  
! |  logical NOT  |  !a |  the logical negation of **a**  
&& |  logical AND  |  a && b |  the logical AND of **a** and **b**  
|| |  logical OR  |  a || b |  the logical OR of **a** and **b**  
  
## Contents

  * [1 Logical NOT](operator_logical.html#Logical_NOT)
  * [2 Logical AND](operator_logical.html#Logical_AND)
  * [3 Logical OR](operator_logical.html#Logical_OR)
  * [4 References](operator_logical.html#References)
  * [5 See Also](operator_logical.html#See_Also)
  * [6 See also](operator_logical.html#See_also_2)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_logical&action=edit&section=1 "Edit section: Logical NOT")] Logical NOT

The logical NOT expression has the form   
  
---  
`**!**` expression |  |   
  
where 

expression |  \-  |  an expression of any [scalar type](compatible_type.html#Type_groups "c/language/type")  
---|---|---  
  
The logical NOT operator has type int. Its value is ​0​ if expression evaluates to a value that compares unequal to zero. Its value is 1 if expression evaluates to a value that compares equal to zero. (so !E is the same as (0==E)) 

Run this code
    
    
    #include <stdbool.h>
    #include <stdio.h>
    #include <ctype.h>
    int main(void)
    {
        bool b = !(2+2 == 4); // not true
        [printf](../io/fprintf.html)("!(2+2==4) = %s\n", b ? "true" : "false");
     
        int n = [isspace](../string/byte/isspace.html)('a'); // non-zero if 'a' is a space, zero otherwise
        int x = !!n; // "bang-bang", common C idiom for mapping integers to [0,1]
                     // (all non-zero values become 1)
        char *a[2] = {"non-space", "space"};
        [puts](../io/puts.html)(a[x]); // now x can be safely used as an index to array of 2 strings
    }

Output: 
    
    
    !(2+2==4) = false
    non-space

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_logical&action=edit&section=2 "Edit section: Logical AND")] Logical AND

The logical AND expression has the form   
  
---  
lhs `**& &**` rhs |  |   
  
where 

lhs |  \-  |  an expression of any scalar type   
---|---|---  
rhs |  \-  |  an expression of any scalar type, which is only evaluated if lhs does not compare equal to ​0​  
  
The logical-AND operator has type int and the value 1 if both lhs and rhs compare unequal to zero. It has the value ​0​ otherwise (if either lhs or rhs or both compare equal to zero). 

There is a [sequence point](eval_order.html "c/language/eval order") after the evaluation of lhs. If the result of lhs compares equal to zero, then rhs is not evaluated at all (so-called _short-circuit evaluation_) 

Run this code
    
    
    #include <stdbool.h>
    #include <stdio.h>
    int main(void)
    {
        bool b = 2+2==4 && 2*2==4; // b == true
     
        1 > 2 && [puts](../io/puts.html)("this won't print");
     
        char *p = "abc";
        if(p && *p) // common C idiom: if p is not null
                    // AND if p does not point at the end of the string
        {           // (note that thanks to short-circuit evaluation, this
                    //  will not attempt to dereference a null pointer)
        // ...      // ... then do some string processing
        }
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_logical&action=edit&section=3 "Edit section: Logical OR")] Logical OR

The logical OR expression has the form   
  
---  
lhs `**||**` rhs |  |   
  
where 

lhs |  \-  |  an expression of any scalar type   
---|---|---  
rhs |  \-  |  an expression of any scalar type, which is only evaluated if lhs compares equal to ​0​  
  
The logical-OR operator has type int and the value 1 if either lhs or rhs compare unequal to zero. It has value ​0​ otherwise (if both lhs and rhs compare equal to zero). 

There is a [sequence point](eval_order.html "c/language/eval order") after the evaluation of lhs. If the result of lhs compares unequal to zero, then rhs is not evaluated at all (so-called _short-circuit evaluation_) 

Run this code
    
    
    #include <stdbool.h>
    #include <stdio.h>
    #include <string.h>
    #include <errno.h>
    int main(void)
    {
        bool b = 2+2 == 4 || 2+2 == 5; // true
        [printf](../io/fprintf.html)("true or false = %s\n", b ? "true" : "false");
     
        // logical OR can be used simialar to perl's "or die", as long as rhs has scalar type
        [fopen](../io/fopen.html)("test.txt", "r") || [printf](../io/fprintf.html)("could not open test.txt: %s\n", [strerror](../string/byte/strerror.html)(errno));
    }

Possible output: 
    
    
    true or false = true
    could not open test.txt: No such file or directory

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_logical&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.5.3.3 Unary arithmetic operators (p: 89) 



    

  * 6.5.13 Logical AND operator (p: 99) 



    

  * 6.5.14 Logical OR operator (p: 99) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.5.3.3 Unary arithmetic operators (p: 79) 



    

  * 6.5.13 Logical AND operator (p: 89) 



    

  * 6.5.14 Logical OR operator (p: 89) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.3.3.3 Unary arithmetic operators 



    

  * 3.3.13 Logical AND operator 



    

  * 3.3.14 Logical OR operator 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_logical&action=edit&section=5 "Edit section: See Also")] See Also

[ Operator precedence](operator_precedence.html "c/language/operator precedence")

Common operators   
---  
[assignment](operator_assignment.html "c/language/operator assignment") | [increment  
decrement](operator_incdec.html "c/language/operator incdec") | [arithmetic](operator_arithmetic.html "c/language/operator arithmetic") | **logical** | [comparison](operator_comparison.html "c/language/operator comparison") | [member  
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
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_logical&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/operator_logical.html "cpp/language/operator logical") for Logical operators  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/operator_logical&oldid=171168](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_logical&oldid=171168)" 

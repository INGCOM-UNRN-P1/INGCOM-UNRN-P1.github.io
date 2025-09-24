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
**Comparison operators**  
[Arithmetic operators](operator_arithmetic.html "c/language/operator arithmetic")  
[Assignment operators](operator_assignment.html "c/language/operator assignment")  
[Increment and decrement](operator_incdec.html "c/language/operator incdec")  
[Function call, comma, conditional operator](operator_other.html "c/language/operator other")  
[sizeof](sizeof.html "c/language/sizeof")  
[`_Alignof`](alignof.html "c/language/ Alignof")(C11*)  
[Cast operators](cast.html "c/language/cast")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

Comparison operators are binary operators that test a condition and return **1** if that condition is logically **true** and **0** if that condition is **false**. 

Operator  |  Operator name  |  Example  |  Description   
---|---|---|---  
== |  equal to  |  a == b |  **a** is equal to **b**  
!= |  not equal to  |  a != b |  **a** is not equal to **b**  
< |  less than  |  a < b |  **a** is less than **b**  
> |  greater than  |  a > b |  **a** is greater than **b**  
<= |  less than or equal to  |  a <= b |  **a** is less than or equal to **b**  
>= |  greater than or equal to  |  a >= b |  **a** is greater than or equal to **b**  
  
## Contents

  * [1 Relational operators](operator_comparison.html#Relational_operators)
  * [2 Equality operators](operator_comparison.html#Equality_operators)
    * [2.1 Notes](operator_comparison.html#Notes)
  * [3 References](operator_comparison.html#References)
  * [4 See also](operator_comparison.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_comparison&action=edit&section=1 "Edit section: Relational operators")] Relational operators

The relational operator expressions have the form   
  
---  
lhs `**<**` rhs |  (1)  |   
lhs `**>**` rhs |  (2)  |   
lhs `**< =**` rhs |  (3)  |   
lhs `**> =**` rhs |  (4)  |   
  
1) less-than expression

2) greater-than expression

3) less or equal expression

4) greater or equal expression 

where 

lhs, rhs |  \-  |  expressions that both have real type or both have pointer to object type   
---|---|---  
  
The type of any relational operator expression is int, and its value (which is not an lvalue) is 1 when the specified relationship holds true and ​0​ when the specified relationship does not hold. 

If lhs and rhs are expressions of any [real type](types.html "c/language/types"), then 

  * [usual arithmetic conversions](conversion.html#Usual_arithmetic_conversions "c/language/conversion") are performed 
  * the values of the operands after conversion are compared in the usual mathematical sense (except that positive and negative zeroes compare equal and any comparison involving a NaN value returns zero) 



Note that complex and imaginary numbers cannot be compared with these operators. 

If lhs and rhs are expressions of pointer type, they must be both pointers to objects of [compatible types](types.html#Compatible_types "c/language/types"), except that qualifications of the pointed-to objects are ignored. 

  * a pointer to an object that is not an element of an array is treated as if it were pointing to an element of an array with one element 
  * if two pointers point to the same object, or both point one past the end of the same array, they compare equal 
  * if two pointers point to different elements of the same array, the one pointing at the element with the larger index compares greater. 
  * if one pointer points to the element of an array and the other pointer points one past the end of the same array, the one-past-the-end pointer compares greater 
  * if the two pointers point to members of the same [struct](struct.html "c/language/struct"), the pointer to the member declared later in the struct definition compares greater than then pointer to the member declared earlier. 
  * pointers to members of the same union compare equal 
  * all other pointer comparisons invoke undefined behavior 



Run this code
    
    
    #include <assert.h>
    int main(void)
    {
        [assert](../error/assert.html)(1 < 2);
        [assert](../error/assert.html)(2+2 <= 4.0); // int converts to double, two 4.0's compare equal
     
        struct { int x,y; } s;
        [assert](../error/assert.html)(&s.x < &s.y); // struct members compare in order of declaration
     
        double d = 0.0/0.0; // NaN
        [assert](../error/assert.html)( !(d < d) );
        [assert](../error/assert.html)( !(d > d) );
        [assert](../error/assert.html)( !(d <= d) );
        [assert](../error/assert.html)( !(d >= d) );
        [assert](../error/assert.html)( !(d == d) );
     
        float f = 0.1; // f = 0.100000001490116119384765625
        double g = 0.1; // g = 0.1000000000000000055511151231257827021181583404541015625
        [assert](../error/assert.html)(f > g); // different values
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_comparison&action=edit&section=2 "Edit section: Equality operators")] Equality operators

The equality operator expressions have the form   
  
---  
lhs `**==**` rhs |  (1)  |   
lhs `**!=**` rhs |  (2)  |   
  
1) equal-to expression

2) not equal to expression 

where 

lhs, rhs |  \-  |  expressions that 

  * both have any [arithmetic types](arithmetic_types.html "c/language/arithmetic types") (including complex and imaginary) 

| 

  * both have type [nullptr_t](../types/nullptr_t.html "c/types/nullptr t")
  * one has type [nullptr_t](../types/nullptr_t.html "c/types/nullptr t") and the other is a null pointer constant 

| (since C23)  
---|---  
  
  * both are pointers to objects or functions of [compatible](types.html#Compatible_types "c/language/types") types, ignoring qualifiers of the pointed-to types 
  * one is a pointer to object and the other is a pointer to (possibly qualified) void
  * one is a pointer to object or function and the other is a null pointer constant such as [NULL](../types/NULL.html "c/types/NULL") or nullptr(since C23)

  
  
The type of any equality operator expression is int, and its value (which is not an lvalue) is 1 when the specified relationship holds true and ​0​ when the specified relationship does not hold. 

  * if both operands have arithmetic types, [usual arithmetic conversions](conversion.html#Usual_arithmetic_conversions "c/language/conversion") are performed and the resulting values are compared in the usual mathematical sense (except that positive and negative zeroes compare equal and any comparison involving a NaN value, including equality with itself, returns zero). In particular, values of complex type are equal if their real parts compare equal and their imaginary parts compare equal. 



  * two [nullptr_t](../types/nullptr_t.html "c/types/nullptr t") value or one [nullptr_t](../types/nullptr_t.html "c/types/nullptr t") value and a null pointer constant compare equal 

| (since C23)  
---|---  
  
  * if one operand is a pointer and the other is a null pointer constant, the null pointer constant is first [converted](conversion.html "c/language/conversion") to the type of the pointer (which gives a null pointer value), and the two pointers are compared as described below 
  * if one operand is a pointer and the other is a pointer to void, the non-void pointer is [converted](conversion.html "c/language/conversion") to the pointer to void and the two pointers are compared as described below 
  * two pointers compare equal if any of the following is true: 



    

  * they are both null pointer values of their type 
  * they are both pointers to the same object or function 
  * one pointer is to a struct/union/array object and the other is to its first member/any member/first element 
  * they are both pointing one past the last element of the same array 
  * one is one past the end of an array, and the other is at the start of a different array (of the same type) that follows the first in a larger array or in a struct with no padding 



(as with relational operators, pointers to objects that aren't elements of any array behave as pointers to elements of arrays of size 1) 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_comparison&action=edit&section=3 "Edit section: Notes")] Notes

Objects of struct type do not compare equal automatically, and comparing them with [memcmp](../string/byte/memcmp.html "c/string/byte/memcmp") is not reliable because the padding bytes may have any values. 

Because pointer comparison works with pointers to void, the macro [NULL](../types/NULL.html "c/types/NULL") may be defined as (void*)0 in C, although that would be invalid in C++ where void pointers do not implicitly convert to typed pointers 

Care must be taken when comparing floating-point values for equality, because the results of many operations cannot be represented exactly and must be rounded. In practice, floating-point numbers are usually compared allowing for the difference of one or more units of the last place. 

Run this code
    
    
    #include <assert.h>
    int main(void)
    {
        [assert](../error/assert.html)(2+2 == 4.0); // int converts to double, two 4.0's compare equal
     
        int n[2][3] = {1,2,3,4,5,6};
        int* p1 = &n[0][2]; // last element in the first row
        int* p2 = &n[1][0]; // start of second row
        [assert](../error/assert.html)(p1+1 == p2); // compare equal
     
        double d = 0.0/0.0; // NaN
        [assert](../error/assert.html)( d != d ); // NaN does not equal itself
     
        float f = 0.1; // f = 0.100000001490116119384765625
        double g = 0.1; // g = 0.1000000000000000055511151231257827021181583404541015625
        [assert](../error/assert.html)(f != g); // different values
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_comparison&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.5.8 Relational operators (p: 68-69) 



    

  * 6.5.9 Equality operators (p: 69-70) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.5.8 Relational operators (p: 95-96) 



    

  * 6.5.9 Equality operators (p: 96-97) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.5.8 Relational operators (p: 85-86) 



    

  * 6.5.9 Equality operators (p: 86-87) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.3.8 Relational operators 



    

  * 3.3.9 Equality operators 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_comparison&action=edit&section=5 "Edit section: See also")] See also

[ Operator precedence](operator_precedence.html "c/language/operator precedence")

Common operators   
---  
[assignment](operator_assignment.html "c/language/operator assignment") | [increment  
decrement](operator_incdec.html "c/language/operator incdec") | [arithmetic](operator_arithmetic.html "c/language/operator arithmetic") | [logical](operator_logical.html "c/language/operator logical") | **comparison** | [member  
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
[C++ documentation](../../cpp/language/operator_comparison.html "cpp/language/operator comparison") for Comparison operators  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/operator_comparison&oldid=152706](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_comparison&oldid=152706)" 

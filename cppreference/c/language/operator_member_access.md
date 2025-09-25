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
**Member access and indirection**  
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

Member access operators allow access to the members of their operands. 

Operator  |  Operator name  |  Example  |  Description   
---|---|---|---  
[] |  array subscript  |  a[b] |  access the **b** th element of array **a**  
* |  pointer dereference  |  *a |  dereference the pointer **a** to access the object or function it refers to   
& |  address of  |  &a |  create a pointer that refers to the object or function **a**  
. |  member access  |  a.b |  access member **b** of [struct](struct.html "c/language/struct") or [union](union.html "c/language/union") **a**  
-> |  member access through pointer  |  a->b |  access member **b** of [struct](struct.html "c/language/struct") or [union](union.html "c/language/union") pointed to by **a**  
  
## Contents

  * [1 Subscript](operator_member_access.html#Subscript)
  * [2 Dereference](operator_member_access.html#Dereference)
  * [3 Address of](operator_member_access.html#Address_of)
  * [4 Member access](operator_member_access.html#Member_access)
  * [5 Member access through pointer](operator_member_access.html#Member_access_through_pointer)
  * [6 Defect reports](operator_member_access.html#Defect_reports)
  * [7 References](operator_member_access.html#References)
  * [8 See also](operator_member_access.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_member_access&action=edit&section=1 "Edit section: Subscript")] Subscript

The array subscript expression has the form   
  
---  
pointer-expression `**[**` integer-expression `**]**` |  (1)  |   
integer-expression `**[**` pointer-expression `**]**` |  (2)  |   
  
where 

pointer-expression |  \-  |  an [expression](operators.html "c/language/expressions") of type pointer to complete object   
---|---|---  
integer-expression |  \-  |  an [expression](operators.html "c/language/expressions") of integer type   
  
The subscript operator expression is an [lvalue expression](value_category.html "c/language/value category") whose type is the type of the object pointed to by pointer-expression. 

By definition, the subscript operator E1[E2] is exactly identical to *((E1)+(E2)). If pointer-expression is an array expression, it undergoes [lvalue-to-rvalue conversion](conversion.html "c/language/conversion") and becomes a pointer to the first element of the array. 

Due to the definition of the [addition between a pointer and an integer](operator_arithmetic.html "c/language/operator arithmetic"), the result is the element of the array with the index equal to the result of integer-expression (or, if pointer-expression was pointing at ith element of some array, the index of the result is i plus the result of integer-expression) 

Note: see [array](array.html "c/language/array") for the details on multidimensional arrays. 

Run this code
    
    
    #include <stdio.h>
    int main(void)
    {
        int a[3] = {1,2,3};
        [printf](../io/fprintf.html)("%d %d\n", a[2],  // n == 3
                          2[a]); // same, n == 3
        a[2] = 7; // subscripts are lvalues
     
        int n[2][3] = {{1,2,3},{4,5,6}};
        int (*p)[3] = &n[1]; // elements of n are arrays
        [printf](../io/fprintf.html)("%d %d %d\n", (*p)[0], p[0][1], p[0][2]); // access n[1][] via p
        int x = n[1][2]; // applying [] again to the array n[1]
        [printf](../io/fprintf.html)("%d\n", x);
     
        [printf](../io/fprintf.html)("%c %c\n", "abc"[2], 2["abc"]); // string literals are arrays too
    }

Output: 
    
    
    3 3
    4 5 6
    6
    c c

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_member_access&action=edit&section=2 "Edit section: Dereference")] Dereference

The _dereference_ or _indirection_ expression has the form   
  
---  
`*****` pointer-expression |  |   
  
where 

pointer-expression |  \-  |  an [expression](operators.html "c/language/expressions") of any pointer type   
---|---|---  
  
If pointer-expression is a pointer to function, the result of the dereference operator is a function designator for that function. 

If pointer-expression is a pointer to object, the result is an [lvalue expression](value_category.html "c/language/value category") that designates the pointed-to object. 

Dereferencing a null pointer, a pointer to an object outside of its lifetime (a dangling pointer), a misaligned pointer, or a pointer with indeterminate value is undefined behavior, except when the dereference operator is nullified by applying the address-of operator to its result, as in &*E. 

Run this code
    
    
    #include <stdio.h>
    int main(void)
    {
        int n = 1;
        int* p = &n;
        [printf](../io/fprintf.html)("*p = %d\n", *p); // the value of *p is what's stored in n
        *p = 7; // *p is lvalue
        [printf](../io/fprintf.html)("*p = %d\n", *p);
    }

Output: 
    
    
    *p = 1
    *p = 7

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_member_access&action=edit&section=3 "Edit section: Address of")] Address of

The address-of expression has the form   
  
---  
`**&**` function |  (1)  |   
`**&**` lvalue-expression |  (2)  |   
`**&**` `*****` expression |  (3)  |   
`**&**` expression `**[**` expression `**]**` |  (4)  |   
  
1) address of a function

2) address of an object

3) special case: `&` and `*` cancel each other, neither one is evaluated

4) special case: `&` and the `*` that is implied in `[]` cancel each other, only the addition implied in `[]` is evaluated.

where 

lvalue-expression |  \-  |  an [lvalue](value_category.html "c/language/value category") expression of any type that is not a [bit-field](bit_field.html "c/language/bit field") and does not have [register](storage_class_specifiers.html "c/language/storage duration") storage class   
---|---|---  
  
The address-of operator produces the [non-lvalue](value_category.html "c/language/value category") address of its operand, suitable for initializing a pointer to the type of the operand. If the operand is a function designator (1), the result is a pointer to function. If the operand is an object (2), the result is a pointer to object. 

If the operand is the dereference operator, no action is taken (so it's okay to apply &* to a null pointer), except that the result is not an lvalue. 

If the operand is an array index expression, no action is taken other than the array-to-pointer conversion and the addition, so &a[N] is valid for an array of size N (obtaining a pointer one past the end is okay, dereferencing it is not, but dereference cancels out in this expression). 

Run this code
    
    
    int f(char c) { return c;}
    int main(void)
    {
       int n = 1;
       int *p = &n; // address of object n
       int (*fp)(char) = &f; // address of function f
       int a[3] = {1,2,3};
       int *beg=a, *end=&a[3]; // same as end = a+3
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_member_access&action=edit&section=4 "Edit section: Member access")] Member access

The member access expression has the form   
  
---  
expression `**.**` member-name |  |   
  
where 

expression |  \-  |  an expression of [struct](struct.html "c/language/struct") or [union](union.html "c/language/union") type   
---|---|---  
member-name |  \-  |  an [identifier](identifiers.html "c/language/identifier") that names a member of the struct or union designated by expression  
  
The member access expression designates the named member of the [struct](struct.html "c/language/struct") or [union](union.html "c/language/union") designated by its left operand. It has the same [value category](value_category.html "c/language/value category") as its left operand. 

If the left operand is [const](const.html "c/language/const") or [volatile](volatile.html "c/language/volatile") qualified, the result is also qualified. If the left operand is [atomic](atomic.html "c/language/atomic"), the behavior is undefined. 

Note: besides identifiers that name objects of struct or union type, the following expressions may have struct or union types: [assignment](operator_assignment.html "c/language/operator assignment"), [function call](operator_other.html#Function_call "c/language/operator other"), [comma operator](operator_other.html#Comma_operator "c/language/operator other"), [conditional operator](operator_other.html#Conditional_operator "c/language/operator other"), and [compound literal](compound_literal.html "c/language/compound literal"). 

Run this code
    
    
    #include <stdio.h>
    struct s {int x;};
    struct s f(void) { return (struct s){1}; }
    int main(void)
    {
        struct s s;
        s.x = 1; // ok, changes the member of s
        int n = f().x; // f() is an expression of type struct s
    //  f().x = 1; // Error: this member access expression is not an lvalue
     
        const struct s sc;
    //  sc.x = 3;  // Error: sc.x is const, can't be assigned
     
        union { int x; double d; } u = {1};
        u.d = 0.1; // changes the active member of the union
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_member_access&action=edit&section=5 "Edit section: Member access through pointer")] Member access through pointer

The member access expression has the form   
  
---  
expression `**- >**` member-name |  |   
  
where 

expression |  \-  |  an expression of type [pointer](pointer.html "c/language/pointer") to [struct](struct.html "c/language/struct") or [union](union.html "c/language/union")  
---|---|---  
member-name |  \-  |  an [identifier](identifiers.html "c/language/identifier") that names a member of the struct or union pointed by expression  
  
The member access through pointer expression designates the named member of the [struct](struct.html "c/language/struct") or [union](union.html "c/language/union") type pointed to by its left operand. Its value category is always [lvalue](value_category.html "c/language/value category")

If the type pointed to by the left operand is [const](const.html "c/language/const") or [volatile](volatile.html "c/language/volatile") qualified, the result is also qualified. If the type pointed to by the left operand is [atomic](atomic.html "c/language/atomic"), the behavior is undefined. 

Run this code
    
    
    #include <stdio.h>
    struct s {int x;};
    int main(void)
    {
        struct s s={1}, *p = &s;
        p->x = 7; // changes the value of s.x through the pointer
        [printf](../io/fprintf.html)("%d\n", p->x); // prints 7
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_member_access&action=edit&section=6 "Edit section: Defect reports")] Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards. 

DR  | Applied to  | Behavior as published  | Correct behavior   
---|---|---|---  
[DR 076](https://www.open-std.org/jtc1/sc22/wg14/www/docs/dr_076.html) | C89  | unnessary indirection could not be cancelled by `&` | made cancellable   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_member_access&action=edit&section=7 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.5.2.1 Array subscripting (p: 57-58) 



    

  * 6.5.2.3 Structure and union members (p: 58-59) 



    

  * 6.5.3.2 Address and indirection operators (p: 59-61) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.5.2.1 Array subscripting (p: 80) 



    

  * 6.5.2.3 Structure and union members (p: 82-84) 



    

  * 6.5.3.2 Address and indirection operators (p: 88-89) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.5.2.1 Array subscripting (p: 70) 



    

  * 6.5.2.3 Structure and union members (p: 72-74) 



    

  * 6.5.3.2 Address and indirection operators (p: 78-79) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.3.2.1 Array subscripting 



    

  * 3.3.2.3 Structure and union members 



    

  * 3.3.3.2 Address and indirection operators 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_member_access&action=edit&section=8 "Edit section: See also")] See also

  * [Operator precedence](operator_precedence.html "c/language/operator precedence")

Common operators   
---  
[assignment](operator_assignment.html "c/language/operator assignment") | [increment  
decrement](operator_incdec.html "c/language/operator incdec") | [arithmetic](operator_arithmetic.html "c/language/operator arithmetic") | [logical](operator_logical.html "c/language/operator logical") | [comparison](operator_comparison.html "c/language/operator comparison") | **member  
access** | [other](operator_other.html "c/language/operator other")  
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
[C++ documentation](../../cpp/language/operator_member_access.html "cpp/language/operator member access") for Member access operators  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/operator_member_access&oldid=150169](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_member_access&oldid=150169)" 

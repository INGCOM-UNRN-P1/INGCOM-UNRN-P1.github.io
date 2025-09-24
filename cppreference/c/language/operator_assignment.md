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
**Assignment operators**  
[Increment and decrement](operator_incdec.html "c/language/operator incdec")  
[Function call, comma, conditional operator](operator_other.html "c/language/operator other")  
[sizeof](sizeof.html "c/language/sizeof")  
[`_Alignof`](alignof.html "c/language/ Alignof")(C11*)  
[Cast operators](cast.html "c/language/cast")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

Assignment and compound assignment operators are binary operators that modify the variable to their left using the value to their right. 

Operator  |  Operator name  |  Example  |  Description  |  Equivalent of   
---|---|---|---|---  
= |  basic assignment  |  a = b |  **a** becomes equal to **b** |  N/A  
+= |  addition assignment  |  a += b |  **a** becomes equal to the addition of **a** and **b** |  a = a + b  
-= |  subtraction assignment  |  a -= b |  **a** becomes equal to the subtraction of **b** from **a** |  a = a - b  
*= |  multiplication assignment  |  a *= b |  **a** becomes equal to the product of **a** and **b** |  a = a * b  
/= |  division assignment  |  a /= b |  **a** becomes equal to the division of **a** by **b** |  a = a / b  
%= |  modulo assignment  |  a %= b |  **a** becomes equal to the remainder of **a** divided by **b** |  a = a % b  
&= |  bitwise AND assignment  |  a &= b |  **a** becomes equal to the bitwise AND of **a** and **b** |  a = a & b  
|= |  bitwise OR assignment  |  a |= b |  **a** becomes equal to the bitwise OR of **a** and **b** |  a = a | b  
^= |  bitwise XOR assignment  |  a ^= b |  **a** becomes equal to the bitwise XOR of **a** and **b** |  a = a ^ b  
<<= |  bitwise left shift assignment  |  a <<= b |  **a** becomes equal to **a** left shifted by **b** |  a = a << b  
>>= |  bitwise right shift assignment  |  a >>= b |  **a** becomes equal to **a** right shifted by **b** |  a = a >> b  
  
## Contents

  * [1 Simple assignment](operator_assignment.html#Simple_assignment)
    * [1.1 Notes](operator_assignment.html#Notes)
  * [2 Compound assignment](operator_assignment.html#Compound_assignment)
  * [3 References](operator_assignment.html#References)
  * [4 See Also](operator_assignment.html#See_Also)
  * [5 See also](operator_assignment.html#See_also_2)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_assignment&action=edit&section=1 "Edit section: Simple assignment")] Simple assignment

The simple assignment operator expressions have the form   
  
---  
lhs `**=**` rhs |  |   
  
where 

lhs |  \-  |  [modifiable lvalue](value_category.html "c/language/value category") expression of any complete object type   
---|---|---  
rhs |  \-  |  expression of any type [implicitly convertible](conversion.html "c/language/conversion") to lhs or [compatible](compatible_type.html#Compatible_types "c/language/type") with lhs  
  
Assignment performs [implicit conversion](conversion.html "c/language/conversion") from the value of rhs to the type of lhs and then replaces the value in the object designated by lhs with the converted value of rhs. 

Assignment also returns the same value as what was stored in `lhs` (so that expressions such as a = b = c are possible). The [value category](value_category.html "c/language/value category") of the assignment operator is non-lvalue (so that expressions such as (a=b)=c are invalid). 

rhs and lhs must satisfy one of the following: 

  * both lhs and rhs have [compatible](compatible_type.html#Compatible_types "c/language/type") [struct](struct.html "c/language/struct") or [union](union.html "c/language/union") type, or.. 
  * rhs must be [implicitly convertible](conversion.html "c/language/conversion") to lhs, which implies 



    

  * both lhs and rhs have [arithmetic types](arithmetic_types.html "c/language/arithmetic types"), in which case lhs may be [volatile](volatile.html "c/language/volatile")-qualified or [atomic](atomic.html "c/language/atomic")(since C11)
  * both lhs and rhs have [pointer](pointer.html "c/language/pointer") to [compatible](compatible_type.html#Compatible_types "c/language/type") (ignoring qualifiers) types, or one of the pointers is a pointer to void, and the [conversion](conversion.html "c/language/conversion") would not add qualifiers to the pointed-to type. lhs may be [volatile](volatile.html "c/language/volatile") or [restrict](restrict.html "c/language/restrict")(since C99)-qualified or [atomic](atomic.html "c/language/atomic")(since C11). 
  * lhs is a (possibly qualified or atomic(since C11)) pointer and rhs is a null pointer constant such as [NULL](../types/NULL.html "c/types/NULL") or a [nullptr_t](../types/nullptr_t.html "c/types/nullptr t") value(since C23)



    

  * lhs has type (possibly qualified or atomic(since C11)) _Bool and rhs is a pointer or a [nullptr_t](../types/nullptr_t.html "c/types/nullptr t") value(since C23)


| (since C99)  
---|---  
  
    

  * lhs has type (possibly qualified or atomic) [nullptr_t](../types/nullptr_t.html "c/types/nullptr t") and rhs has type [nullptr_t](../types/nullptr_t.html "c/types/nullptr t")


| (since C23)  
---|---  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_assignment&action=edit&section=2 "Edit section: Notes")] Notes

If rhs and lhs overlap in memory (e.g. they are members of the same union), the behavior is undefined unless the overlap is exact and the types are [compatible](compatible_type.html#Compatible_types "c/language/type"). 

Although arrays are not assignable, an array wrapped in a struct is assignable to another object of the same (or compatible) struct type. 

The side effect of updating lhs is [sequenced after](eval_order.html "c/language/eval order") the value computations, but not the side effects of lhs and rhs themselves and the evaluations of the operands are, as usual, unsequenced relative to each other (so the expressions such as i=++i; are undefined) 

Assignment strips extra range and precision from floating-point expressions (see [FLT_EVAL_METHOD](../types/limits/FLT_EVAL_METHOD.html "c/types/limits/FLT EVAL METHOD")). 

In C++, assignment operators are lvalue expressions, not so in C. 

Run this code
    
    
    #include <stdio.h>
     
    int main(void)
    {
        // integers
        int i = 1, j = 2, k = 3; // initialization, not assignment
     
        i = j = k;   // values of i and j are now 3
    //  (i = j) = k; // Error: lvalue required
        [printf](../io/fprintf.html)("%d %d %d\n", i, j, k);
     
        // pointers
        const char c = 'A'; // initialization; not assignment
        const char *p = &c;  // initialization; not assignment
        const char **cpp = &p; // initialization; not assignment
     
    //  cpp = &p;   // Error: char** is not convertible to const char**
        *cpp = &c;  // OK, char* is convertible to const char*
        [printf](../io/fprintf.html)("%c \n", **cpp);
        cpp = 0;    // OK, null pointer constant is convertible to any pointer
     
        // arrays
        int arr1[2] = {1,2}, arr2[2] = {3, 4};
    //  arr1 = arr2; // Error: cannot assign to an array
        [printf](../io/fprintf.html)("arr1[0]=%d arr1[1]=%d arr2[0]=%d arr2[1]=%d\n",
                arr1[0],   arr1[1],   arr2[0],   arr2[1]);
     
        struct { int arr[2]; } sam1 = { {5, 6} }, sam2 = { {7, 8} };
        sam1 = sam2; // OK: can assign arrays wrapped in structs
     
        [printf](../io/fprintf.html)("%d %d \n", sam1.arr[0], sam1.arr[1]);
    }

Output: 
    
    
    3 3 3
    A
    arr1[0]=1 arr1[1]=2 arr2[0]=3 arr2[1]=4
    7 8

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_assignment&action=edit&section=3 "Edit section: Compound assignment")] Compound assignment

The compound assignment operator expressions have the form   
  
---  
lhs op rhs |  |   
  
where 

op |  \-  |  one of *=, /= %=, += -=, <<=, >>=, &=, ^=, |=  
---|---|---  
lhs, rhs |  \-  |  expressions with [arithmetic types](arithmetic_types.html "c/language/arithmetic types") (where lhs may be qualified or atomic), except when op is += or -=, which also accept pointer types with the same restrictions as + and -   
  
The expression lhs @= rhs is exactly the same as lhs `**=**` lhs @ `**(**` rhs `**)**`, except that lhs is evaluated only once. 

If lhs has [atomic](atomic.html "c/language/atomic") type, the operation behaves as a single atomic read-modify-write operation with memory order [memory_order_seq_cst](../atomic/memory_order.html "c/atomic/memory order"). For integer atomic types, the compound assignment @= is equivalent to: 
    
    
    T1* addr = &lhs;
    T2 val = rhs;
    T1 old = *addr;
    T1 new;
    do { new = old @ val } while (![atomic_compare_exchange_strong](../atomic/atomic_compare_exchange.html)(addr, &old, new);

| (since C11)  
---|---  
  
Run this code
    
    
    #include <stdio.h>
     
    int main(void)
    {
        int x = 10; 
        int hundred = 100; 
        int ten = 10; 
        int fifty = 50; 
     
        [printf](../io/fprintf.html)("%d %d %d %d\n", x, hundred, ten, fifty);
     
        hundred *= x; 
        ten     /= x; 
        fifty   %= x; 
     
        [printf](../io/fprintf.html)("%d %d %d %d\n", x, hundred, ten, fifty);
     
        return 0;
    }

Output: 
    
    
    10 100 10 50
    10 1000 1 0

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_assignment&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.5.16 Assignment operators (p: 72-73) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.5.16 Assignment operators (p: 101-104) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.5.16 Assignment operators (p: 91-93) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.3.16 Assignment operators 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_assignment&action=edit&section=5 "Edit section: See Also")] See Also

[ Operator precedence](operator_precedence.html "c/language/operator precedence")

Common operators   
---  
**assignment** | [increment  
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
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_assignment&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/operator_assignment.html "cpp/language/operator assignment") for Assignment operators  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/operator_assignment&oldid=142209](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_assignment&oldid=142209)" 

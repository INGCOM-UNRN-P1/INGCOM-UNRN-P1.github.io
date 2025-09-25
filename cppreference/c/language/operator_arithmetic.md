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
**Arithmetic operators**  
[Assignment operators](operator_assignment.html "c/language/operator assignment")  
[Increment and decrement](operator_incdec.html "c/language/operator incdec")  
[Function call, comma, conditional operator](operator_other.html "c/language/operator other")  
[sizeof](sizeof.html "c/language/sizeof")  
[`_Alignof`](alignof.html "c/language/ Alignof")(C11*)  
[Cast operators](cast.html "c/language/cast")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

Arithmetic operators apply standard mathematical operations to their operands. 

| This section is incomplete  
Reason: consider a more general-purpose ToC for this and other tables that cover multiple topics   
---|---  
Operator  |  Operator name  |  Example  |  Result   
---|---|---|---  
+ |  unary plus  |  +a |  the value of **a** after promotions   
- |  unary minus  |  -a |  the negative of **a**  
+ |  addition  |  a + b |  the addition of **a** and **b**  
- |  subtraction  |  a - b |  the subtraction of **b** from **a**  
* |  product  |  a * b |  the product of **a** and **b**  
/ |  division  |  a / b |  the division of **a** by **b**  
% |  remainder  |  a % b |  the remainder of **a** divided by **b**  
~ |  bitwise NOT  |  ~a |  the bitwise NOT of **a**  
& |  bitwise AND  |  a & b |  the bitwise AND of **a** and **b**  
| |  bitwise OR  |  a | b |  the bitwise OR of **a** and **b**  
^ |  bitwise XOR  |  a ^ b |  the bitwise XOR of **a** and **b**  
<< |  bitwise left shift  |  a << b |  **a** left shifted by **b**  
>> |  bitwise right shift  |  a >> b |  **a** right shifted by **b**  
  
## Contents

  * [1 Overflows](operator_arithmetic.html#Overflows)
    * [1.1 Floating-point environment](operator_arithmetic.html#Floating-point_environment)
    * [1.2 Floating-point contraction](operator_arithmetic.html#Floating-point_contraction)
  * [2 Unary arithmetic](operator_arithmetic.html#Unary_arithmetic)
    * [2.1 Notes](operator_arithmetic.html#Notes)
  * [3 Additive operators](operator_arithmetic.html#Additive_operators)
    * [3.1 Arithmetic addition and subtraction](operator_arithmetic.html#Arithmetic_addition_and_subtraction)
    * [3.2 Pointer arithmetic](operator_arithmetic.html#Pointer_arithmetic)
  * [4 Multiplicative operators](operator_arithmetic.html#Multiplicative_operators)
    * [4.1 Multiplication](operator_arithmetic.html#Multiplication)
    * [4.2 Division](operator_arithmetic.html#Division)
    * [4.3 Remainder](operator_arithmetic.html#Remainder)
  * [5 Bitwise logic](operator_arithmetic.html#Bitwise_logic)
  * [6 Shift operators](operator_arithmetic.html#Shift_operators)
  * [7 References](operator_arithmetic.html#References)
  * [8 See also](operator_arithmetic.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=1 "Edit section: Overflows")] Overflows

Unsigned integer arithmetic is always performed modulo 2n  
where n is the number of bits in that particular integer. E.g. for unsigned int, adding one to [UINT_MAX](../types/limits.html "c/types/limits") gives ​0​, and subtracting one from ​0​ gives [UINT_MAX](../types/limits.html "c/types/limits"). 

When signed integer arithmetic operation overflows (the result does not fit in the result type), the behavior is undefined: it may wrap around according to the rules of the representation (typically 2's complement), it may trap on some platforms or due to compiler options (e.g. `-ftrapv` in GCC and Clang), or may be completely [optimized out by the compiler](http://blog.llvm.org/2011/05/what-every-c-programmer-should-know_14.html). 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=2 "Edit section: Floating-point environment")] Floating-point environment

If [` #pragma STDC FENV_ACCESS`](../preprocessor/impl.html "c/preprocessor/impl") is set to `ON`, all floating-point arithmetic operators obey the current floating-point [rounding direction](../numeric/fenv/FE_round.html "c/numeric/fenv/FE round") and report floating-point arithmetic errors as specified in [`math_errhandling`](../numeric/math/math_errhandling.html "c/numeric/math/math errhandling") unless part of a [static initializer](initialization.html "c/language/initialization") (in which case floating-point exceptions are not raised and the rounding mode is to nearest) 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=3 "Edit section: Floating-point contraction")] Floating-point contraction

Unless [` #pragma STDC FP_CONTRACT`](../preprocessor/impl.html "c/preprocessor/impl") is set to `OFF`, all floating-point arithmetic may be performed as if the intermediate results have infinite range and precision, that is optimizations that omit rounding errors and floating-point exceptions that would be observed if the expression was evaluated exactly as written. For example, allows the implementation of (x*y) + z with a single fused multiply-add CPU instruction or optimization of a = x*x*x*x; as tmp = x*x; a = tmp*tmp. 

Unrelated to contracting, intermediate results of floating-point arithmetic may have range and precision that is different from the one indicated by its type, see [FLT_EVAL_METHOD](../types/limits/FLT_EVAL_METHOD.html "c/types/limits/FLT EVAL METHOD")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=4 "Edit section: Unary arithmetic")] Unary arithmetic

The unary arithmetic operator expressions have the form   
  
---  
`**+**` expression |  (1)  |   
`**-**` expression |  (2)  |   
  
1) unary plus (promotion)

2) unary minus (negation)

expression |  \-  |  expression of any [arithmetic type](arithmetic_types.html "c/language/arithmetic types")  
---|---|---  
  
Both unary plus and unary minus first apply [integral promotions](conversion.html "c/language/conversion") to their operand, and then 

  * unary plus returns the value after promotion 
  * unary minus returns the negative of the value after promotion (except that the negative of a NaN is another NaN) 



The type of the expression is the type after promotion, and the [value category](value_category.html "c/language/value category") is non-lvalue. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=5 "Edit section: Notes")] Notes

The unary minus invokes undefined behavior due to signed integer overflow when applied to [INT_MIN](../types/limits.html "c/types/limits"), [LONG_MIN](../types/limits.html "c/types/limits"), or [LLONG_MIN](../types/limits.html "c/types/limits"), on typical (2's complement) platforms. 

In C++, unary operator `**+**` can also be used with other built-in types such as arrays and functions, not so in C. 

Run this code
    
    
    #include <stdio.h>
    #include <complex.h>
    #include <limits.h>
     
    int main(void)
    {
        char c = 'a';
        [printf](../io/fprintf.html)("sizeof char: %zu sizeof int: %zu\n", sizeof c, sizeof +c);
     
        [printf](../io/fprintf.html)("-1, where 1 is signed: %d\n", -1);
     
        // Defined behavior since arithmetic is performed for unsigned integer.
        // Hence, the calculation is (-1) modulo (2 raised to n) = UINT_MAX, where n is
        // the number of bits of unsigned int. If unsigned int is 32-bit long, then this
        // gives (-1) modulo (2 raised to 32) = 4294967295
        [printf](../io/fprintf.html)("-1, where 1 is unsigned: %u\n", -1u); 
     
        // Undefined behavior because the mathematical value of -INT_MIN = INT_MAX + 1
        // (i.e. 1 more than the maximum possible value for signed int)
        //
        // printf("%d\n", -INT_MIN);
     
        // Undefined behavior because the mathematical value of -LONG_MIN = LONG_MAX + 1
        // (i.e. 1 more than the maximum possible value for signed long)
        //
        // printf("%ld\n", -LONG_MIN);
     
        // Undefined behavior because the mathematical value of -LLONG_MIN = LLONG_MAX + 1
        // (i.e. 1 more than the maximum possible value for signed long long)
        //
        // printf("%lld\n", -LLONG_MIN);
     
        double [complex](../numeric/complex/complex.html) z = 1 + 2*I;
        [printf](../io/fprintf.html)("-(1+2i) = %.1f%+.1f\n", [creal](../numeric/complex/creal.html)(-z), [cimag](../numeric/complex/cimag.html)(-z));
    }

Possible output: 
    
    
    sizeof char: 1 sizeof int: 4
    -1, where 1 is signed: -1
    -1, where 1 is unsigned: 4294967295
    -(1+2i) = -1.0-2.0

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=6 "Edit section: Additive operators")] Additive operators

The binary additive arithmetic operator expressions have the form   
  
---  
lhs `**+**` rhs |  (1)  |   
lhs `**-**` rhs |  (2)  |   
  
1) addition: lhs and rhs must be one of the following 

    

  * both have [arithmetic types](arithmetic_types.html "c/language/arithmetic types"), including complex and imaginary 
  * one is a pointer to complete object type, the other has integer type



2) subtraction: lhs and rhs must be one of the following 

    

  * both have [arithmetic types](arithmetic_types.html "c/language/arithmetic types"), including complex and imaginary 
  * lhs has pointer to complete object type, rhs has integer type 
  * both are pointers to complete objects of [compatible](compatible_type.html#Comparible_types "c/language/type") types, ignoring qualifiers



#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=7 "Edit section: Arithmetic addition and subtraction")] Arithmetic addition and subtraction

If both operands have [arithmetic types](arithmetic_types.html "c/language/arithmetic types"), then 

  * first, [usual arithmetic conversions](conversion.html#Usual_arithmetic_conversions "c/language/conversion") are performed 
  * then, the values of the operands after conversions are added or subtracted following the usual rules of mathematics (for subtraction, rhs is subtracted from lhs), except that 



    

  * if one operand is NaN, the result is NaN 
  * infinity minus infinity is NaN and [FE_INVALID](../numeric/fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised 
  * infinity plus the negative infinity is NaN and [FE_INVALID](../numeric/fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised 



Complex and imaginary addition and subtraction are defined as follows (note the result type is imaginary if both operands are imaginary and complex if one operand is real and the other imaginary, as specified by the usual arithmetic conversions): 

\+ or -  |  u  |  iv  |  u + iv   
---|---|---|---  
x  |  x ± u  |  x ± iv  |  (x ± u) ± iv   
iy  |  ±u + iy  |  i(y ± v)  |  ±u + i(y ± v)   
x + iy  |  (x ± u) + iy  |  x + i(y ± v)  |  (x ± u) + i(y ± v)   
  
  


Run this code
    
    
    // work in progress
    // note: take part of the c/language/conversion example

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=8 "Edit section: Pointer arithmetic")] Pointer arithmetic

  * If the pointer `P` points at an element of an array with index `I`, then 



    

  * P+N and N+P are pointers that point at an element of the same array with index `I+N`
  * P-N is a pointer that points at an element of the same array with index `I-N`



The behavior is defined only if both the original pointer and the result pointer are pointing at elements of the same array or one past the end of that array. Note that executing p-1 when p points at the first element of an array is undefined behavior and may fail on some platforms. 

  * If the pointer `P1` points at an element of an array with index `I` (or one past the end) and `P2` points at an element of the same array with index `J` (or one past the end), then 



    

  * P1-P2 has the value equal to I-J and the type [ptrdiff_t](../types/ptrdiff_t.html "c/types/ptrdiff t") (which is a signed integer type, typically half as large as the size of the largest object that can be declared) 



The behavior is defined only if the result fits in [ptrdiff_t](../types/ptrdiff_t.html "c/types/ptrdiff t"). 

For the purpose of pointer arithmetic, a pointer to an object that is not an element of any array is treated as a pointer to the first element of an array of size 1. 

Run this code
    
    
    // work in progress
    int n = 4, m = 3;
    int a[n][m];     // VLA of 4 VLAs of 3 ints each
    int (*p)[m] = a; // p == &a[0] 
    p = p + 1;       // p == &a[1] (pointer arithmetic works with VLAs just the same)
    (*p)[2] = 99;    // changes a[1][2]

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=9 "Edit section: Multiplicative operators")] Multiplicative operators

The binary multiplicative arithmetic operator expressions have the form   
  
---  
lhs `*****` rhs |  (1)  |   
lhs `**/**` rhs |  (2)  |   
lhs `**%**` rhs |  (3)  |   
  
1) multiplication. lhs and rhs must have [arithmetic types](arithmetic_types.html "c/language/arithmetic types")

2) division. lhs and rhs must have [arithmetic types](arithmetic_types.html "c/language/arithmetic types")

3) remainder. lhs and rhs must have [integer types](arithmetic_types.html "c/language/arithmetic types")

  * first, [usual arithmetic conversions](conversion.html#Usual_arithmetic_conversions "c/language/conversion") are performed. Then... 



#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=10 "Edit section: Multiplication")] Multiplication

The binary operator * performs multiplication of its operands (after usual arithmetic conversions) following the usual arithmetic definitions, except that 

  * if one operand is a NaN, the result is a NaN 
  * multiplication of infinity by zero gives NaN and [FE_INVALID](../numeric/fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised 
  * multiplication of infinity by a nonzero gives infinity (even for complex arguments) 



Because in C, any [complex value](arithmetic_types.html "c/language/arithmetic types") with at least one infinite part is an infinity even if its other part is a NaN, the usual arithmetic rules do not apply to complex-complex multiplication. Other combinations of floating operands follow the following table: 

*  |  u  |  iv  |  u + iv   
---|---|---|---  
x  |  xu  |  i(xv)  |  (xu) + i(xv)   
iy  |  i(yu)  |  −yv  |  (−yv) + i(yu)   
x + iy  |  (xu) + i(yu)  |  (−yv) + i(xv)  |  _special rules_  
  
Besides infinity handling, complex multiplication is not allowed to overflow intermediate results, except when [` #pragma STDC CX_LIMITED_RANGE`](../preprocessor/impl.html "c/preprocessor/impl") is set to `ON`, in which case the value may be calculated as if by (x+iy)×(u+iv) = (xu-yv)+i(yu+xv), as the programmer assumes the responsibility of limiting the range of the operands and dealing with the infinities. 

Despite disallowing undue overflow, complex multiplication may raise spurious floating-point exceptions (otherwise it is prohibitively difficult to implement non-overflowing versions) 

Run this code
    
    
    #include <stdio.h>
    #include <stdio.h>
    #include <complex.h>
    #include <math.h>
    int main(void)
    {
     
     
    // TODO simpler cases, take some from C++
     
     
       double [complex](../numeric/complex/complex.html) z = (1 + 0*I) * (INFINITY + I*INFINITY);
    // textbook formula would give
    // (1+i0)(∞+i∞) ⇒ (1×∞ – 0×∞) + i(0×∞+1×∞) ⇒ NaN + I*NaN
    // but C gives a complex infinity
       [printf](../io/fprintf.html)("%f + i*%f\n", [creal](../numeric/complex/creal.html)(z), [cimag](../numeric/complex/cimag.html)(z));
     
    // textbook formula would give
    // cexp(∞+iNaN) ⇒ exp(∞)×(cis(NaN)) ⇒ NaN + I*NaN
    // but C gives  ±∞+i*nan
       double [complex](../numeric/complex/complex.html) y = [cexp](../numeric/complex/cexp.html)(INFINITY + I*NAN);
       [printf](../io/fprintf.html)("%f + i*%f\n", [creal](../numeric/complex/creal.html)(y), [cimag](../numeric/complex/cimag.html)(y));
     
    }

Possible output: 
    
    
    inf + i*inf 
    inf + i*nan

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=11 "Edit section: Division")] Division

The binary operator `**/**` divides the first operand by the second (after usual arithmetic conversions) following the usual arithmetic definitions, except that 

  * when the type after usual arithmetic conversions is an integer type, the result is the algebraic quotient (not a fraction), rounded in implementation-defined direction(until C99)truncated towards zero(since C99)
  * if one operand is a NaN, the result is a NaN 
  * if the first operand is a complex infinity and the second operand is finite, then the result of the `**/**` operator is a complex infinity 
  * if the first operand is finite and the second operand is a complex infinity, then the result of the `**/**` operator is a zero. 



Because in C, any [complex value](arithmetic_types.html "c/language/arithmetic types") with at least one infinite part as an infinity even if its other part is a NaN, the usual arithmetic rules do not apply to complex-complex division. Other combinations of floating operands follow the following table: 

/  |  u  |  iv   
---|---|---  
x  |  x/u  |  i(−x/v)   
iy  |  i(y/u)  |  y/v   
x + iy  |  (x/u) + i(y/u)  |  (y/v) + i(−x/v)   
  
Besides infinity handling, complex division is not allowed to overflow intermediate results, except when [` #pragma STDC CX_LIMITED_RANGE`](../preprocessor/impl.html "c/preprocessor/impl") is set to `ON`, in which case the value may be calculated as if by (x+iy)/(u+iv) = [(xu+yv)+i(yu-xv)]/(u2  
+v2  
), as the programmer assumes the responsibility of limiting the range of the operands and dealing with the infinities. 

Despite disallowing undue overflow, complex division may raise spurious floating-point exceptions (otherwise it is prohibitively difficult to implement non-overflowing versions) 

If the second operand is zero, the behavior is undefined, except that if the IEEE floating-point arithmetic is supported, and the floating-point division is taking place, then 

  * Dividing a non-zero number by ±0.0 gives the correctly-signed infinity and [FE_DIVBYZERO](../numeric/fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised 
  * Dividing 0.0 by 0.0 gives NaN and [FE_INVALID](../numeric/fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") is raised 



#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=12 "Edit section: Remainder")] Remainder

The binary operator % yields the remainder of the division of the first operand by the second (after usual arithmetic conversions). 

The sign of the remainder is defined in such a way that if the quotient `a/b` is representable in the result type, then (a/b)*b + a%b == a. 

If the second operand is zero, the behavior is undefined. 

If the quotient `a/b` is not representable in the result type, the behavior of both `a/b` and `a%b` is undefined (that means INT_MIN%-1 is undefined on 2's complement systems) 

Note: the remainder operator does not work on floating-point types, the library function [fmod](../numeric/math/fmod.html "c/numeric/math/fmod") provides that functionality. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=13 "Edit section: Bitwise logic")] Bitwise logic

The bitwise arithmetic operator expressions have the form   
  
---  
`**~**` rhs |  (1)  |   
lhs `**&**` rhs |  (2)  |   
lhs `**|**` rhs |  (3)  |   
lhs `**^**` rhs |  (4)  |   
  
1) bitwise NOT

2) bitwise AND

3) bitwise OR

4) bitwise XOR 

where 

lhs, rhs |  \-  |  expressions of integer type   
---|---|---  
  
First, operators &, ^, and | perform [usual arithmetic conversions](conversion.html#Usual_arithmetic_conversions "c/language/conversion") on both operands and the operator ~ performs [integer promotions](conversion.html#Integer_promotions "c/language/conversion") on its only operand. 

Then, the corresponding binary logic operators are applied bitwise; that is, each bit of the result is set or cleared according to the logic operation (NOT, AND, OR, or XOR), applied to the corresponding bits of the operands. 

Note: bitwise operators are commonly used to manipulate bit sets and bit masks. 

Note: for unsigned types (after promotion), the expression ~E is equivalent to the maximum value representable by the result type minus the original value of E. 

Run this code
    
    
    #include <stdio.h>
    #include <stdint.h>
     
    int main(void)
    {
        [uint32_t](../types/integer.html) a = 0x12345678;
        [uint16_t](../types/integer.html) mask = 0x00f0;
     
        [printf](../io/fprintf.html)("Promoted mask:\t%#010x\n"
               "Value:\t\t%#x\n"
               "Setting bits:\t%#x\n"
               "Clearing bits:\t%#x\n"
               "Selecting bits:\t%#010x\n"
               , mask
               , a
               , a | mask
               , a & ~mask
               , a & mask
        );
    }

Possible output: 
    
    
    Promoted mask:  0x000000f0
    Value:          0x12345678
    Setting bits:   0x123456f8
    Clearing bits:  0x12345608
    Selecting bits: 0x00000070

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=14 "Edit section: Shift operators")] Shift operators

The bitwise shift operator expressions have the form   
  
---  
lhs `**< <**` rhs |  (1)  |   
lhs `**> >**` rhs |  (2)  |   
  
1) left shift of lhs by rhs bits

2) right shift of lhs by rhs bits 

where 

lhs, rhs |  \-  |  expressions of integer type   
---|---|---  
  
First, [integer promotions](conversion.html "c/language/conversion") are performed, individually, on each operand (Note: this is unlike other binary arithmetic operators, which all perform usual arithmetic conversions). The type of the result is the type of lhs after promotion. 

The behavior is undefined if rhs is negative or is greater or equal the number of bits in the promoted lhs. 

For unsigned lhs, the value of `LHS << RHS` is the value of LHS * 2RHS  
, reduced modulo maximum value of the return type plus 1 (that is, bitwise left shift is performed and the bits that get shifted out of the destination type are discarded). For signed lhs with nonnegative values, the value of `LHS << RHS` is LHS * 2RHS  
if it is representable in the promoted type of lhs, otherwise the behavior is undefined. 

For unsigned lhs and for signed lhs with nonnegative values, the value of `LHS >> RHS` is the integer part of LHS / 2RHS  
. For negative `LHS`, the value of `LHS >> RHS` is implementation-defined where in most implementations, this performs arithmetic right shift (so that the result remains negative). Thus in most implementations, right shifting a signed `LHS` fills the new higher-order bits with the original sign bit (i.e. with 0 if it was non-negative and 1 if it was negative). 

Run this code
    
    
    #include <stdio.h>
    enum {ONE=1, TWO=2};
    int main(void)
    {
        char c = 0x10;
        unsigned long long ulong_num = 0x123;
        [printf](../io/fprintf.html)("0x123 << 1  = %#llx\n"
               "0x123 << 63 = %#llx\n"   // overflow truncates high bits for unsigned numbers
               "0x10  << 10 = %#x\n",    // char is promoted to int
               ulong_num << 1, ulong_num << 63, c << 10);
        long long long_num = -1000;
        [printf](../io/fprintf.html)("-1000 >> 1 = %lld\n", long_num >> ONE);  // implementation defined
    }

Possible output: 
    
    
    0x123 << 1  = 0x246
    0x123 << 63 = 0x8000000000000000
    0x10  << 10 = 0x4000
    -1000 >> 1 = -500

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=15 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.5.3.3 Unary arithmetic operators (p: 64) 



    

  * 6.5.5 Multiplicative operators (p: 66) 



    

  * 6.5.6 Additive operators (p: 66-68) 



    

  * 6.5.7 Bitwise shift operators (p: 68) 



    

  * 6.5.10 Bitwise AND operator (p: 70) 



    

  * 6.5.11 Bitwise exclusive OR operator (p: 70) 



    

  * 6.5.12 Bitwise inclusive OR operator (p: 70-71) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.5.3.3 Unary arithmetic operators (p: 89) 



    

  * 6.5.5 Multiplicative operators (p: 92) 



    

  * 6.5.6 Additive operators (p: 92-94) 



    

  * 6.5.7 Bitwise shift operators (p: 94-95) 



    

  * 6.5.10 Bitwise AND operator (p: 97) 



    

  * 6.5.11 Bitwise exclusive OR operator (p: 98) 



    

  * 6.5.12 Bitwise inclusive OR operator (p: 98) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.5.3.3 Unary arithmetic operators (p: 79) 



    

  * 6.5.5 Multiplicative operators (p: 82) 



    

  * 6.5.6 Additive operators (p: 82-84) 



    

  * 6.5.7 Bitwise shift operators (p: 84-85) 



    

  * 6.5.10 Bitwise AND operator (p: 87) 



    

  * 6.5.11 Bitwise exclusive OR operator (p: 88) 



    

  * 6.5.12 Bitwise inclusive OR operator (p: 88) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.3.3.3 Unary arithmetic operators 



    

  * 3.3.5 Multiplicative operators 



    

  * 3.3.6 Additive operators 



    

  * 3.3.7 Bitwise shift operators 



    

  * 3.3.10 Bitwise AND operator 



    

  * 3.3.11 Bitwise exclusive OR operator 



    

  * 3.3.12 Bitwise inclusive OR operator 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&action=edit&section=16 "Edit section: See also")] See also

[Operator precedence](operator_precedence.html "c/language/operator precedence")

Common operators   
---  
[assignment](operator_assignment.html "c/language/operator assignment") | [increment  
decrement](operator_incdec.html "c/language/operator incdec") | **arithmetic** | [logical](operator_logical.html "c/language/operator logical") | [comparison](operator_comparison.html "c/language/operator comparison") | [member  
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
[C++ documentation](../../cpp/language/operator_arithmetic.html "cpp/language/operator arithmetic") for Arithmetic operators  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&oldid=176253](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_arithmetic&oldid=176253)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



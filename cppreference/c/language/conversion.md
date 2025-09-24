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
**Implicit conversions**  
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

When an expression is used in the context where a value of a different type is expected, _conversion_ may occur: 
    
    
    int n = 1L; // expression 1L has type long, int is expected
    n = 2.1; // expression 2.1 has type double, int is expected
    char* p = [malloc](../memory/malloc.html)(10); // expression malloc(10) has type void*, char* is expected

Conversions take place in the following situations: 

## Contents

  * [1 Conversion as if by assignment](conversion.html#Conversion_as_if_by_assignment)
  * [2 Default argument promotions](conversion.html#Default_argument_promotions)
  * [3 Usual arithmetic conversions](conversion.html#Usual_arithmetic_conversions)
  * [4 Value transformations](conversion.html#Value_transformations)
    * [4.1 Lvalue conversion](conversion.html#Lvalue_conversion)
    * [4.2 Array to pointer conversion](conversion.html#Array_to_pointer_conversion)
    * [4.3 Function to pointer conversion](conversion.html#Function_to_pointer_conversion)
  * [5 Implicit conversion semantics](conversion.html#Implicit_conversion_semantics)
    * [5.1 Compatible types](conversion.html#Compatible_types)
    * [5.2 Integer promotions](conversion.html#Integer_promotions)
    * [5.3 Boolean conversion](conversion.html#Boolean_conversion)
    * [5.4 Integer conversions](conversion.html#Integer_conversions)
    * [5.5 Real floating-integer conversions](conversion.html#Real_floating-integer_conversions)
    * [5.6 Real floating-point conversions](conversion.html#Real_floating-point_conversions)
    * [5.7 Complex type conversions](conversion.html#Complex_type_conversions)
    * [5.8 Imaginary type conversions](conversion.html#Imaginary_type_conversions)
    * [5.9 Real-complex conversions](conversion.html#Real-complex_conversions)
    * [5.10 Real-imaginary conversions](conversion.html#Real-imaginary_conversions)
    * [5.11 Complex-imaginary conversions](conversion.html#Complex-imaginary_conversions)
    * [5.12 Pointer conversions](conversion.html#Pointer_conversions)
  * [6 Notes](conversion.html#Notes)
  * [7 References](conversion.html#References)
  * [8 See also](conversion.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=1 "Edit section: Conversion as if by assignment")] Conversion as if by assignment

  * In the [assignment](operator_assignment.html "c/language/operator assignment") operator, the value of the right-hand operand is converted to the unqualified type of the left-hand operand. 
  * In [scalar initialization](scalar_initialization.html "c/language/scalar initialization"), the value of the initializer expression is converted to the unqualified type of the object being initialized. 
  * In a [function-call expression](operator_other.html "c/language/operator other"), to a function that has a prototype, the value of each argument expression is converted to the type of the unqualified declared types of the corresponding parameter. 
  * In a [return statement](return.html "c/language/return"), the value of the operand of return is converted to an object having the return type of the function. 



Note that actual assignment, in addition to the conversion, also removes extra range and precision from floating-point types and prohibits overlaps; those characteristics do not apply to conversion as if by assignment. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=2 "Edit section: Default argument promotions")] Default argument promotions

In a [function call expression](operator_other.html#Function_call "c/language/operator other") when the call is made to 

1) a [function without a prototype](function_declaration.html "c/language/function declaration") (until C23),

2) a [variadic function](variadic.html "c/language/variadic"), where the argument expression is one of the trailing arguments that are matched against the ellipsis parameter.

Each argument of integer type undergoes [integer promotion](conversion.html#Integer_promotions), and each argument of type float is implicitly converted to the type double. 
    
    
    int add_nums(int count, ...);
    int sum = add_nums(2, 'c', true); // add_nums is called with three ints: (2, 99, 1)

Note that float [complex](../numeric/complex/complex.html) and float [imaginary](../numeric/complex/imaginary.html) are not promoted to double [complex](../numeric/complex/complex.html) and double [imaginary](../numeric/complex/imaginary.html) in this context.  | (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=3 "Edit section: Usual arithmetic conversions")] Usual arithmetic conversions

The arguments of the following arithmetic operators undergo implicit conversions for the purpose of obtaining the _common real type ﻿_ , which is the type in which the calculation is performed: 

  * [binary arithmetic](operator_arithmetic.html "c/language/operator arithmetic") *, /, %, +, -, 
  * [relational operators](operator_comparison.html "c/language/operator comparison") <, >, <=, >=, ==, !=, 
  * [binary bitwise arithmetic](operator_arithmetic.html "c/language/operator arithmetic") &, ^, |, 
  * the [conditional operator](operator_other.html "c/language/operator other") ?:. 

1) If one operand has decimal floating type, the other operand shall not have standard floating, complex, or imaginary type. 

    

  * First, if the type of either operand is _Decimal128, the other operand is converted to _Decimal128. 
  * Otherwise, if the type of either operand is _Decimal64, the other operand is converted to _Decimal64. 
  * Otherwise, if the type of either operand is _Decimal32, the other operand is converted to _Decimal32.


| (since C23)  
---|---  
  
2) Otherwise, if one operand is long double, long double [complex](../numeric/complex/complex.html), or long double [imaginary](../numeric/complex/imaginary.html)(since C99), the other operand is implicitly converted as follows: 

    

  * integer or real floating type to long double



    

  * complex type to long double [complex](../numeric/complex/complex.html)
  * imaginary type to long double [imaginary](../numeric/complex/imaginary.html)


| (since C99)  
---|---  
  
3) Otherwise, if one operand is double, double [complex](../numeric/complex/complex.html), or double [imaginary](../numeric/complex/imaginary.html)(since C99), the other operand is implicitly converted as follows: 

    

  * integer or real floating type to double



    

  * complex type to double [complex](../numeric/complex/complex.html)
  * imaginary type to double [imaginary](../numeric/complex/imaginary.html)


| (since C99)  
---|---  
  
4) Otherwise, if one operand is float, float [complex](../numeric/complex/complex.html), or float [imaginary](../numeric/complex/imaginary.html)(since C99), the other operand is implicitly converted as follows: 

    

  * integer type to float (the only real type possible is float, which remains as-is) 



    

  * complex type remains float [complex](../numeric/complex/complex.html)
  * imaginary type remains float [imaginary](../numeric/complex/imaginary.html)


| (since C99)  
---|---  
  
5) Otherwise, both operands are integers. Both operands undergo [integer promotions](conversion.html#Integer_promotions); then, after integer promotion, one of the following cases applies: 

    

  * If the types are the same, that type is the common type. 
  * Else, the types are different: 
    * If the types have the same signedness (both signed or both unsigned), the operand whose type has the lesser _conversion rank ﻿_[[1]](conversion.html#cite_note-1) is implicitly converted[[2]](conversion.html#cite_note-2) to the other type. 
    * Else, the operands have different signedness: 
      * If the unsigned type has _conversion rank_ greater than or equal to the rank of the signed type, then the operand with the signed type is implicitly converted to the unsigned type. 
      * Else, the unsigned type has _conversion rank_ less than the signed type: 
        * If the signed type can represent all values of the unsigned type, then the operand with the unsigned type is implicitly converted to the signed type. 
        * Else, both operands undergo implicit conversion to the unsigned type counterpart of the signed operand's type. 



  1. [↑](conversion.html#cite_ref-1) Refer to [integer promotions](conversion.html#Integer_promotions) below for the rules on ranking.
  2. [↑](conversion.html#cite_ref-2) Refer to “integer conversions” under [implicit conversion semantics](conversion.html#Implicit_conversion_semantics) below.


    
    
    1.f + 20000001; // int is converted to float, giving 20000000.00
                    // addition and then rounding to float gives 20000000.00
     
    (char)'a' + 1L; // first, char 'a', which is 97, is promoted to int
                    // different types: int and long
                    // same signedness: both signed
                    // different rank: long is of greater rank than int
                    // therefore, int 97 is converted to long 97
                    // the result is 97 + 1 = 98 of type signed long
     
    2u - 10; // different types: unsigned int and signed int
             // different signedness
             // same rank
             // therefore, signed int 10 is converted to unsigned int 10
             // since the arithmetic operation is performed for unsigned integers
             // (see “Arithmetic operators” topic), the calculation performed is (2 - 10)
             // modulo (2 raised to n), where n is the number of value bits of unsigned int
             // if unsigned int is 32-bit long and there is no padding bits in its object
             // representation, then the result is (-8) modulo (2 raised to 32) = 4294967288
             // of type unsigned int
     
    5UL - 2ULL; // different types: unsigned long and unsigned long long
                // same signedness
                // different rank: rank of unsigned long long is greater
                // therefore, unsigned long 5 is converted to unsigned long long 5
                // since the arithmetic operation is performed for unsigned integers
                // (see “Arithmetic operators” topic),
                // if unsigned long long is 64-bit long, then
                // the result is (5 - 2) modulo (2 raised to 64) = 3 of type
                // unsigned long long
     
    0UL - 1LL; // different types: unsigned long and signed long long
               // different signedness
               // different rank: rank of signed long long is greater.
               // if ULONG_MAX > LLONG_MAX, then signed long long cannot represent all
               // unsigned long therefore, this is the last case: both operands are converted
               // to unsigned long long unsigned long 0 is converted to unsigned long long 0
               // long long 1 is converted to unsigned long long 1 since the arithmetic
               // operation is performed for unsigned integers
               // (see “Arithmetic operators” topic),
               // if unsigned long long is 64-bit long, then
               // the calculation is (0 - 1) modulo (2 raised to 64)
               // thus, the result is 18446744073709551615 (ULLONG_MAX) of type
               // unsigned long long

The result type is determined as follows: 

  * if both operands are complex, the result type is complex; 
  * if both operands are imaginary, the result type is imaginary; 
  * if both operands are real, the result type is real; 
  * if the two floating-point operands have different type domains (complex vs. real, complex vs imaginary, or imaginary vs. real), the result type is complex. 


    
    
    double [complex](../numeric/complex/complex.html) z = 1 + 2*I;
    double f = 3.0;
    z + f; // z remains as-is, f is converted to double, the result is double complex

| (since C99)  
---|---  
  
As always, the result of a floating-point operator may have greater range and precision than is indicated by its type (see [FLT_EVAL_METHOD](../types/limits/FLT_EVAL_METHOD.html)). 

Note: real and imaginary operands are not implicitly converted to complex because doing so would require extra computation, while producing undesirable results in certain cases involving infinities, NaNs and signed zeros. For example, if reals were converted to complex, 2.0×(3.0+i∞) would evaluate as (2.0+i0.0)×(3.0+i∞) ⇒ (2.0×3.0–0.0×∞) + i(2.0×∞+0.0×3.0) ⇒ NaN+i∞ rather than the correct 6.0+i∞. If imaginaries were converted to complex, i2.0×(∞+i3.0) would evaluate as (0.0+i2.0) × (∞+i3.0) ⇒ (0.0×∞ – 2.0×3.0) + i(0.0×3.0 + 2.0×∞) ⇒ NaN + i∞ instead of –6.0 + i∞.  | (since C99)  
---|---  
  
Note: regardless of usual arithmetic conversions, the calculation may always be performed in a narrower type than specified by these rules under the [as-if rule](as_if.html "c/language/as if"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=4 "Edit section: Value transformations")] Value transformations

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=5 "Edit section: Lvalue conversion")] Lvalue conversion

Any [lvalue expression](value_category.html "c/language/value category") of any non-array type, when used in any context other than 

  * as the operand of the [address-of operator](operator_member_access.html "c/language/operator member access") (if allowed), 
  * as the operand of the pre/post [increment and decrement operators](operator_incdec.html "c/language/operator incdec"), 
  * as the left-hand operand of the [member access](operator_member_access.html "c/language/operator member access") (dot) operator, 
  * as the left-hand operand of the [assignment and compound assignment](operator_assignment.html "c/language/operator assignment") operators, 
  * as the operand of [`sizeof`](sizeof.html "c/language/sizeof"), 



undergoes _lvalue conversion ﻿_ : the type remains the same, but loses [`const`](const.html "c/language/const")/[`volatile`](volatile.html "c/language/volatile")/[`restrict`](restrict.html "c/language/restrict")-qualifiers and [atomic](atomic.html "c/language/atomic") properties, if any. The value remains the same, but loses its lvalue properties (the address may no longer be taken). 

If the lvalue has incomplete type, the behavior is undefined. 

If the lvalue designates an object of automatic storage duration whose address was never taken and if that object was uninitialized (not declared with an initializer and no assignment to it has been performed prior to use), the behavior is undefined. 

This conversion models the memory load of the value of the object from its location. 
    
    
    volatile int n = 1;
    int x = n;            // lvalue conversion on n reads the value of n
    volatile int* p = &n; // no lvalue conversion: does not read the value of n

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=6 "Edit section: Array to pointer conversion")] Array to pointer conversion

Any [lvalue expression](value_category.html "c/language/value category")(until C99)[expression](operators.html "c/language/expressions")(since C99) of [array type](array.html "c/language/array"), when used in any context other than 

  * as the operand of the [address-of operator](operator_member_access.html "c/language/operator member access"), 
  * as the operand of [`sizeof`](sizeof.html "c/language/sizeof"), 
  * as the operand of [`typeof`](typeof_unqual.html "c/language/typeof") and [`typeof_unqual`](typeof_unqual.html "c/language/typeof unqual") (since C23), 
  * as the string literal used for [array initialization](array_initialization.html "c/language/array initialization"), 



undergoes a conversion to the non-lvalue pointer to its first element. 

If the array was declared [`register`](storage_class_specifiers.html "c/language/storage duration"), the behavior is undefined. 

A non-lvalue array, or any of its elements, is not accessible(until C99), has [temporary lifetime](lifetime.html#Temporary_lifetime "c/language/lifetime")(since C99). 

Run this code
    
    
    int a[3], b[3][4];
    int* p = a;      /* conversion to &a[0] */
    int (*q)[4] = b; /* conversion to &b[0] */
     
    struct S
    {
        int a[1];
    };
     
    struct S f(void)
    {
        struct S result = {{0}}; /* {0} since C99 */
        return result;
    }
     
    void g(void)
    {
        int* p = f().a;    /* error until C99; OK since C99 */
        int n  = f().a[0]; /* error until C99; OK since C99 */
        f().a[0] = 13;     /* error until C99; UB since C99 */
        (void)p, (void)n;
    }
     
    int main(void) { return 0; }

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=7 "Edit section: Function to pointer conversion")] Function to pointer conversion

Any function designator expression, when used in any context other than 

  * as the operand of the [address-of operator](operator_member_access.html "c/language/operator member access"), 
  * as the operand of [`sizeof`](sizeof.html "c/language/sizeof"), 
  * as the operand of [`typeof`](typeof_unqual.html "c/language/typeof") and [`typeof_unqual`](typeof_unqual.html "c/language/typeof unqual") (since C23), 



undergoes a conversion to the non-lvalue pointer to the function designated by the expression. 
    
    
    int f(int);
    int (*p)(int) = f; // conversion to &f
    (***p)(1); // repeated dereference to f and conversion back to &f

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=8 "Edit section: Implicit conversion semantics")] Implicit conversion semantics

Implicit conversion, whether _as if by assignment ﻿_ or a _usual arithmetic conversion ﻿_ , consists of two stages: 

1) value transformation (if applicable),

2) one of the conversions listed below (if it can produce the target type).

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=9 "Edit section: Compatible types")] Compatible types

Conversion of a value of any type to any [compatible type](types.html#Compatible_types "c/language/types") is always a no-op and does not change the representation. 
    
    
    [uint8_t](../types/integer.html) (*a)[10];         // if uint8_t is a typedef to unsigned char
    unsigned char (*b)[] = a; // then these pointer types are compatible

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=10 "Edit section: Integer promotions")] Integer promotions

Integer promotion is the implicit conversion of a value of any integer type with _rank_ less or equal to _rank_ of int or of a [bit-field](bit_field.html "c/language/bit field") of type _Bool(until C23)bool(since C23), int, signed int, unsigned int, to the value of type int or unsigned int. 

If int can represent the entire range of values of the original type (or the range of values of the original bit-field), the value is converted to type int. Otherwise the value is converted to unsigned int. 

The value from a bit-field of a bit-precise integer type is converted to the corresponding bit-precise integer type. Otherwise, bit-precise integer types are exempt from the integer promotion rules.  | (since C23)  
---|---  
  
Integer promotions preserve the value, including the sign: 
    
    
    int main(void)
    {
        void f(); // old-style function declaration
                  // since C23, void f(...) has the same behavior wrt promotions
        char x = 'a'; // integer conversion from int to char
        f(x); // integer promotion from char back to int
    }
     
    void f(x) int x; {} // the function expects int

_rank_ above is a property of every [integer type](compatible_type.html "c/language/type") and is defined as follows: 

1) the ranks of all signed integer types are different and increase with their precision: rank of signed char < rank of short < rank of int < rank of long int < rank of long long int

2) the ranks of all signed integer types equal the ranks of the corresponding unsigned integer types

3) the rank of any standard integer type is greater than the rank of any extended integer type or bit-precise integer type(since C23) of the same size (that is, rank of __int64 < rank of long long int, but rank of long long < rank of __int128 due to the rule (1))

4) rank of char equals rank of signed char and rank of unsigned char

5) the rank of _Bool(until C23)bool(since C23) is less than the rank of any other standard integer type

6) the rank of any enumerated type equals the rank of its compatible integer type

7) ranking is transitive: if rank of T1 < rank of T2 and rank of T2 < rank of T3 then rank of T1 < rank of T3.

8) the rank of a bit-precise signed integer type shall be greater than the rank of any standard integer type with less width or any bit-precise integer type with less width. 9) the rank of any bit-precise integer type relative to an extended integer type of the same width is implementation-defined. | (since C23)  
---|---  
  
10) any aspects of relative ranking of extended integer types not covered above are implementation defined.

Note: integer promotions are applied only 

  * as part of _usual arithmetic conversions_ (see above), 
  * as part of _default argument promotions_ (see above), 
  * to the operand of the unary arithmetic operators + and -, 
  * to the operand of the unary bitwise operator ~, 
  * to both operands of the shift operators << and >>. 



####  Boolean conversion

A value of any scalar type can be implicitly converted to _Bool(until C23)bool(since C23). The values that compare equal to an integer constant expression of value zero(until C23)are a zero (for arithmetic types), null (for pointer types) or have a type of [nullptr_t](../types/nullptr_t.html "c/types/nullptr t")(since C23) are converted to ​0​(until C23)false(since C23), all other values are converted to 1(until C23)true(since C23). 
    
    
    bool b1 = 0.5;              // b1 == 1 (0.5 converted to int would be zero)
    bool b2 = 2.0*[_Imaginary_I](../numeric/complex/Imaginary_I.html); // b2 == 1 (but converted to int would be zero)
    bool b3 = 0.0 + 3.0*I;      // b3 == 1 (but converted to int would be zero)
    bool b4 = 0.0 / 0.0;        // b4 == 1 (NaN does not compare equal to zero)
    bool b5 = nullptr;          // b5 == 0 (since C23: nullptr is converted to false)

| (since C99)  
---|---  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=12 "Edit section: Integer conversions")] Integer conversions

A value of any integer type can be implicitly converted to any other integer type. Except where covered by promotions and boolean conversions above, the rules are: 

  * if the target type can represent the value, the value is unchanged, 
  * otherwise, if the target type is unsigned, the value 2b  
, where b is the number of value bits in the target type, is repeatedly subtracted or added to the source value until the result fits in the target type. In other words, unsigned integers implement modulo arithmetic. 
  * otherwise, if the target type is signed, the behavior is implementation-defined (which may include raising a signal). 


    
    
    char x = 'a'; // int -> char, result unchanged
    unsigned char n = -123456; // target is unsigned, result is 192 (that is, -123456+483*256)
    signed char m = 123456;    // target is signed, result is implementation-defined
    [assert](../error/assert.html)(sizeof(int) > -1);  // assert fails:
                               // operator > requests conversion of -1 to size_t,
                               // target is unsigned, result is SIZE_MAX

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=13 "Edit section: Real floating-integer conversions")] Real floating-integer conversions

A finite value of any real floating type can be implicitly converted to any integer type. Except where covered by boolean conversion above, the rules are: 

  * The fractional part is discarded (truncated towards zero). 



    

  * If the resulting value can be represented by the target type, that value is used 
  * otherwise, the behavior is undefined. 


    
    
    int n = 3.14; // n == 3
    int x = 1e10; // undefined behavior for 32-bit int

A value of any integer type can be implicitly converted to any real floating type. 

  * if the value can be represented exactly by the target type, it is unchanged. 
  * if the value can be represented, but cannot be represented exactly, the result is an implementation-defined choice of either the nearest higher or nearest lower value, although if IEEE arithmetic is supported, rounding is to nearest. It is unspecified whether [FE_INEXACT](../numeric/fenv/FE_exceptions.html) is raised in this case. 
  * if the value cannot be represented, the behavior is undefined, although if IEEE arithmetic is supported, [FE_INVALID](../numeric/fenv/FE_exceptions.html) is raised and the result value is unspecified. 



The result of this conversion may have greater range and precision than its target type indicates (see [FLT_EVAL_METHOD](../types/limits/FLT_EVAL_METHOD.html)). 

If control over [FE_INEXACT](../numeric/fenv/FE_exceptions.html) is needed in floating-to-integer conversions, [rint](../numeric/math/rint.html "c/numeric/math/rint") and [nearbyint](../numeric/math/nearbyint.html "c/numeric/math/nearbyint") may be used. 
    
    
    double d = 10; // d = 10.00
    float f = 20000001; // f = 20000000.00 (FE_INEXACT)
    float x = 1 + (long long)[FLT_MAX](../types/limits.html); // undefined behavior

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=14 "Edit section: Real floating-point conversions")] Real floating-point conversions

A value of any real floating type can be implicitly converted to any other real floating type. 

  * If the value can be represented by the target type exactly, it is unchanged. 
  * if the value can be represented, but cannot be represented exactly, the result is the nearest higher or the nearest lower value (in other words, rounding direction is implementation-defined), although if IEEE arithmetic is supported, rounding is to nearest. 
  * if the value cannot be represented, the behavior is undefined | This section is incomplete  
Reason: check IEEE if appropriately-signed infinity is required   
---|---  
. 



The result of this conversion may have greater range and precision than its target type indicates (see [FLT_EVAL_METHOD](../types/limits/FLT_EVAL_METHOD.html)). 
    
    
    double d = 0.1; // d = 0.1000000000000000055511151231257827021181583404541015625
    float f = d;    // f = 0.100000001490116119384765625
    float x = 2 * (double)[FLT_MAX](../types/limits.html); // undefined

####  Complex type conversions

A value of any complex type can be implicitly converted to any other complex type. The real part and the imaginary part individually follow the conversion rules for the real floating types. 
    
    
    double [complex](../numeric/complex/complex.html) d = 0.1 + 0.1*I;
    float [complex](../numeric/complex/complex.html) f = d; // f is (0.100000001490116119384765625, 0.100000001490116119384765625)

####  Imaginary type conversions

A value of any imaginary type can be implicitly converted to any other imaginary type. The imaginary part follows the conversion rules for the real floating types. 
    
    
    double [imaginary](../numeric/complex/imaginary.html) d = 0.1*[_Imaginary_I](../numeric/complex/Imaginary_I.html);
    float [imaginary](../numeric/complex/imaginary.html) f = d; // f is 0.100000001490116119384765625*I

####  Real-complex conversions

A value of any real floating type can be implicitly converted to any complex type. 

  * The real part of the result is determined by the conversion rules for the real floating types. 
  * The imaginary part of the result is positive zero (or unsigned zero on non-IEEE systems). 

A value of any complex type can be implicitly converted to any real floating type. 

  * The real part is converted following the rules for the real floating types. 
  * The imaginary part is discarded. 

Note: in complex-to-real conversion, a NaN in the imaginary part will not propagate to the real result. 
    
    
    double [complex](../numeric/complex/complex.html) z = 0.5 + 3*I;
    float f = z;  // the imaginary part is discarded, f is set to 0.5
    z = f;        // sets z to 0.5 + 0*I

####  Real-imaginary conversions

A value of any imaginary type can be implicitly converted to any real type (integer or floating-point). The result is always a positive (or unsigned) zero, except when the target type is _Bool(until C23)bool(since C23), in which case boolean conversion rules apply. A value of any real type can be implicitly converted to any imaginary type. The result is always a positive imaginary zero. 
    
    
    double [imaginary](../numeric/complex/imaginary.html) z = 3*I;
    bool b = z;  // Boolean conversion: sets b to true 
    float f = z; // Real-imaginary conversion: sets f to 0.0 
    z = 3.14;    // Imaginary-real conversion: sets z to 0*_Imaginary_I

####  Complex-imaginary conversions

A value of any imaginary type can be implicitly converted to any complex type. 

  * The real part of the result is the positive zero. 
  * The imaginary part of the result follows the conversion rules for the corresponding real types. 

A value of any complex type can be implicitly converted to any imaginary type. 

  * The real part is discarded. 
  * The imaginary part of the result follows the conversion rules for the corresponding real types. 


    
    
    double [imaginary](../numeric/complex/imaginary.html) z = I * (3*I); // the complex result -3.0+0i loses real part
                                    // sets z to 0*_Imaginary_I

| (since C99)  
---|---  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=20 "Edit section: Pointer conversions")] Pointer conversions

A pointer to void can be implicitly converted to and from any pointer to object type with the following semantics: 

  * If a pointer to object is converted to a pointer to void and back, its value compares equal to the original pointer. 
  * No other guarantees are offered. 


    
    
    int* p = [malloc](../memory/malloc.html)(10 * sizeof(int)); // malloc returns void*

A pointer to an unqualified type may be implicitly converted to the pointer to qualified version of that type (in other words, [`const`](const.html "c/language/const"), [`volatile`](volatile.html "c/language/volatile"), and [`restrict`](restrict.html "c/language/restrict") qualifiers can be added). The original pointer and the result compare equal. 
    
    
    int n;
    const int* p = &n; // &n has type int*

Any integer [constant expression](constant_expression.html "c/language/constant expression") with value ​0​ as well as integer pointer expression with value zero cast to the type void* can be implicitly converted to any pointer type (both pointer to object and pointer to function). The result is the null pointer value of its type, guaranteed to compare unequal to any non-null pointer value of that type. This integer or void* expression is known as _null pointer constant_ and the standard library provides one definition of this constant as the macro [NULL](../types/NULL.html "c/types/NULL"). 
    
    
    int* p = 0;
    double* q = [NULL](../types/NULL.html);

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=21 "Edit section: Notes")] Notes

Although signed integer overflow in any arithmetic operator is undefined behavior, overflowing a signed integer type in an integer conversion is merely unspecified behavior. 

On the other hand, although unsigned integer overflow in any arithmetic operator (and in integer conversion) is a well-defined operation and follows the rules of modulo arithmetic, overflowing an unsigned integer in a floating-to-integer conversion is undefined behavior: the values of real floating type that can be converted to unsigned integer are the values from the open interval `(`-1`, ` _Unnn_MAX_ \+ 1`)`. 
    
    
    unsigned int n = -1.0; // undefined behavior

Conversions between pointers and integers (except from pointer to _Bool(until C23)bool(since C23) and(since C99)from integer constant expression with the value zero to pointer), between pointers to objects (except where either to or from is a pointer to void) and conversions between pointers to functions (except when the functions have compatible types) are never implicit and require a [cast operator](cast.html "c/language/cast"). 

There are no conversions (implicit or explicit) between pointers to functions and pointers to objects (including void*) or integers. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=22 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.3 Conversions (p: 44-50) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.3 Conversions (p: 37-41) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.3 Conversions (p: 50-56) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.3 Conversions (p: 42-48) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.2 Conversions 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&action=edit&section=23 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/implicit_cast.html "cpp/language/implicit cast") for Implicit conversions  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&oldid=182485](https://en.cppreference.com/mwiki/index.php?title=c/language/conversion&oldid=182485)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



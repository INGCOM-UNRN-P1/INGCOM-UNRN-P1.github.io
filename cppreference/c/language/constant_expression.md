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
**Constant expressions**  
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

Several varieties of expressions are known as _constant expressions_. 

## Contents

  * [1 Preprocessor constant expression](constant_expression.html#Preprocessor_constant_expression)
  * [2 Integer constant expression](constant_expression.html#Integer_constant_expression)
  * [3 Static initializer](constant_expression.html#Static_initializer)
  * [4 Floating-point constant expressions](constant_expression.html#Floating-point_constant_expressions)
  * [5 Notes](constant_expression.html#Notes)
  * [6 References](constant_expression.html#References)
  * [7 See also](constant_expression.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/constant_expression&action=edit&section=1 "Edit section: Preprocessor constant expression")] Preprocessor constant expression

The expression following [`#if` or `#elif`](../preprocessor/conditional.html "c/preprocessor/conditional") must expand to 

  * [operators](operators.html#Operators "c/language/expressions") other than [assignment](operator_assignment.html "c/language/operator assignment"), [increment, decrement](operator_incdec.html "c/language/operator incdec"), [function-call](operator_other.html#Function_call "c/language/operator other"), or [comma](operator_other.html#Comma_operator "c/language/operator other") whose arguments are preprocessor constant expressions 
  * [integer constants](integer_constant.html "c/language/integer constant")
  * [character constants](character_constant.html "c/language/character constant")
  * the special preprocessor operator `defined`. 



Character constants, when evaluated in `#if`-expressions, may be interpreted in the source character set, the execution character set, or some other implementation-defined character set. 

Integer arithmetic in `#if`-expressions is performed using the semantics of [intmax_t](../types/integer.html "c/types/integer") for signed types and [uintmax_t](../types/integer.html "c/types/integer") for unsigned types.  | (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/constant_expression&action=edit&section=2 "Edit section: Integer constant expression")] Integer constant expression

An integer constant expression is an expression that consists only of 

  * [operators](operators.html#Operators "c/language/expressions") other than [assignment](operator_assignment.html "c/language/operator assignment"), [increment, decrement](operator_incdec.html "c/language/operator incdec"), [function-call](operator_other.html#Function_call "c/language/operator other"), or [comma](operator_other.html#Comma_operator "c/language/operator other"), except that [cast](cast.html "c/language/cast") operators can only cast arithmetic types to integer types unless they are part of an operand to a sizeof , _Alignof(since C11)(until C23), alignas(since C23) or typeof/typeof_unqual(since C23) operator. 
  * [integer constants](integer_constant.html "c/language/integer constant")
  * [enumeration constants](enum.html "c/language/enum")
  * [character constants](character_constant.html "c/language/character constant")
  * [floating constants](floating_constant.html "c/language/floating constant"), but only if they are immediately used as operands of casts to integer type 
  * [`sizeof`](sizeof.html "c/language/sizeof") operators whose operands are not VLA(since C99)



  * _Alignof(until C23)alignas(since C23) operators 

| (since C11)  
---|---  
  
  * named and compound literal constants that are of integer type or that are of arithmetic type and are the immediate operands of casts 

| (since C23)  
---|---  
  
Integer constant expressions are evaluated at compile time. The following contexts require expressions that are known as _integer constant expressions_ : 

  * The size of a [bit-field](bit_field.html "c/language/bit field"). 
  * The value of an [enumeration constant](enum.html "c/language/enum")
  * The `case` label of a [switch statement](switch.html "c/language/switch")
  * The size of a non-VLA(since C99) array 
  * Integer to pointer implicit [conversion](conversion.html "c/language/conversion"). 



  * The index in an [array designator](array_initialization.html "c/language/array initialization")

| (since C99)  
---|---  
  
  * The first argument of [`_Static_assert`](static_assert.html "c/language/ Static assert")
  * The integer argument of [`_Alignof`](alignof.html "c/language/ Alignof")(until C23)[`alignof`](alignof.html "c/language/alignof")(since C23)

| (since C11)  
  
  * The number of bits N of a bit-precise integer type (_BitInt(N)) 

| (since C23)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/constant_expression&action=edit&section=3 "Edit section: Static initializer")] Static initializer

Expressions that are used in the [initializers](initialization.html "c/language/initialization") of objects with static and thread_local [storage duration](storage_class_specifiers.html "c/language/storage duration") or declared with the constexpr storage-class specifier(since C23) must be either string literals or expressions that may be one of the following 

1) _arithmetic constant expression_ , which is an expression of any arithmetic type that consists of 

    

  * [operators](operators.html#Operators "c/language/expressions") other than [assignment](operator_assignment.html "c/language/operator assignment"), [increment, decrement](operator_incdec.html "c/language/operator incdec"), [function-call](operator_other.html#Function_call "c/language/operator other"), or [comma](operator_other.html#Comma_operator "c/language/operator other"), except that [cast](cast.html "c/language/cast") operators must be converting arithmetic types to other arithmetic types unless they are part of an operand to a sizeof , _Alignof(since C11)(until C23), alignof(since C23) or typeof/typeof_unqual(since C23) operator 
  * [integer constants](integer_constant.html "c/language/integer constant")
  * [floating constants](floating_constant.html "c/language/floating constant")
  * [enumeration constants](enum.html "c/language/enum")
  * [character constants](character_constant.html "c/language/character constant")
  * [`sizeof`](sizeof.html "c/language/sizeof") operators whose operands are not VLA(since C99)



    

  * [`_Alignof`](alignof.html "c/language/ Alignof")(until C23)[`alignof`](alignof.html "c/language/alignof")(since C23) operators 


| (since C11)  
---|---  
  
    

  * named or compound literal constants of arithmetic type 


| (since C23)  
---|---  
  
2) a null pointer constant (e.g., [NULL](../types/NULL.html "c/types/NULL")).

3) _address constant expression_ , which is 

    

  * a null pointer 
  * [lvalue](value_category.html "c/language/value category") designating an object of static [storage duration](storage_class_specifiers.html "c/language/storage duration") or a function designator, converted to a pointer either 



    

  * by using the unary address-of operator 
  * by casting an integer constant to a pointer 
  * by array-to-pointer or function-to-pointer implicit [conversion](conversion.html "c/language/conversion").



4) _address constant expression_ of some complete object type, plus or minus an _integer constant expression_.

5) a _named constant_ which is, an identifier that is 

    

  * an enumeration constant 
  * a predefined constant (one of true, false or nullptr) 
  * declared with storage-class specifier constexpr and has an object type 


or a postfix expression that applies the `**.**` member access operator to a named constant of structure or union type, even recursively. 6) a _compound literal constant_ , which is 

    

  * a [compound literal](compound_literal.html "c/language/compound literal") with storage-class specifier constexpr
  * a postfix expression that applies the `**.**` member access operator to a compound literal constant of structure or union type, even recursively.


A _structure or union constant_ is a named constant or compound literal constant with structure or union type, respectively. If the member-access operator `**.**` accesses a member of a union constant, the accessed member shall be the same as the member that is initialized by the union constant’s initializer.  | (since C23)  
---|---  
  
7) constant expression of one of the other forms accepted by the implementation.

Unlike with integer constant expressions, static initializer expressions are not required to be evaluated at compile time; the compiler is at liberty to turn such initializers into executable code which is invoked prior to program startup. 
    
    
    static int i = 2 || 1 / 0; // initializes i to value 1

| This section is incomplete  
Reason: other mini-examples   
---|---  
  
The value of a floating-point static initializer is never less accurate than the value of the same expression executed at run time, but it may be better. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/constant_expression&action=edit&section=4 "Edit section: Floating-point constant expressions")] Floating-point constant expressions

Arithmetic constant expressions of floating-point types that are not used in static initializers are always evaluated as-if during run-time and are affected by the [current rounding](../numeric/fenv/FE_round.html "c/numeric/fenv/FE round") (if [`FENV_ACCESS`](../preprocessor/impl.html "c/preprocessor/impl") is on) and report errors as specified in [`math_errhandling`](../numeric/math/math_errhandling.html "c/numeric/math/math errhandling"). 
    
    
    void f(void)
    {
    #pragma STDC FENV_ACCESS ON
        static float x = 0.0 / 0.0; // static initializer: does not raise an exception
        float w[] = { 0.0 / 0.0 };  // raises an exception
        float y = 0.0 / 0.0;        // raises an exception
        double z = 0.0 / 0.0;       // raises an exception
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/constant_expression&action=edit&section=5 "Edit section: Notes")] Notes

If an expression evaluates to a value that is not representable by its type, it cannot be used as a constant expression. 

Implementations may accept other forms of constant expressions. However, these constant expressions are not considered as integer constant expressions, arithmetic constant expressions, or address constant expressions, and thus cannot be used in the contexts requiring these kinds of constant expressions. For example, int arr[(int)+1.0]; declares a VLA. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/constant_expression&action=edit&section=6 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.6 Constant expressions (p: 95-96) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.6 Constant expressions (p: 76-77) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.6 Constant expressions (p: 106-107) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.6 Constant expressions (p: 95-96) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.4 CONSTANT EXPRESSIONS 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/constant_expression&action=edit&section=7 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/constant_expression.html "cpp/language/constant expression") for Constant expressions  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/constant_expression&oldid=183172](https://en.cppreference.com/mwiki/index.php?title=c/language/constant_expression&oldid=183172)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



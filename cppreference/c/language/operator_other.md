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
[Increment and decrement](operator_incdec.html "c/language/operator incdec")  
**Function call, comma, conditional operator**  
[sizeof](sizeof.html "c/language/sizeof")  
[`_Alignof`](alignof.html "c/language/ Alignof")(C11*)  
[Cast operators](cast.html "c/language/cast")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

A collection of operators that do not fit into any of the other major categories. 

| This section is incomplete  
Reason: consider a more general-purpose ToC for this and other tables that cover multiple topics   
---|---  
Operator  |  Operator name  |  Example  |  Description   
---|---|---|---  
(...) |  [function call](operator_other.html#Function_call) |  f(...) |  call the function **f**(), with zero or more arguments   
, |  [comma operator](operator_other.html#Comma_operator) |  a, b |  evaluate expression **a** , disregard its return value and complete any side-effects, then evaluate expression **b** , returning the type and the result of this evaluation   
(type) |  [type cast](cast.html "c/language/cast") |  (type)a |  cast the type of **a** to **type**  
? : |  [conditional operator](operator_other.html#Conditional_operator) |  a ? b : c |  if **a** is logically true (does not evaluate to zero) then evaluate expression **b** , otherwise evaluate expression **c**  
sizeof |  [sizeof operator](sizeof.html "c/language/sizeof") |  sizeof a |  the size in bytes of **a**  
_Alignof  
(since C11) |  [_Alignof operator](alignof.html "c/language/ Alignof") |  _Alignof(type) |  the alignment required of **type**  
typeof |  [typeof operators](typeof_unqual.html "c/language/typeof") |  typeof(a) |  the type of **a**  
  
## Contents

  * [1 Function call](operator_other.html#Function_call)
    * [1.1 Call to a function with a prototype](operator_other.html#Call_to_a_function_with_a_prototype)
    * [1.2 Call to a function without a prototype](operator_other.html#Call_to_a_function_without_a_prototype)
    * [1.3 Notes](operator_other.html#Notes)
  * [2 Comma operator](operator_other.html#Comma_operator)
  * [3 Notes](operator_other.html#Notes_2)
  * [4 Cast operator](operator_other.html#Cast_operator)
  * [5 Conditional operator](operator_other.html#Conditional_operator)
    * [5.1 Notes](operator_other.html#Notes_3)
  * [6 sizeof operator](operator_other.html#sizeof_operator)
  * [7 _Alignof operator](operator_other.html#Alignof_operator)
  * [8 typeof operators](operator_other.html#typeof_operators)
  * [9 References](operator_other.html#References)
  * [10 See also](operator_other.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&action=edit&section=1 "Edit section: Function call")] Function call

The function call expression has the form   
  
---  
expression `**(**` argument-list ﻿(optional) `**)**` |  |   
  
where 

expression |  \-  |  any expression of pointer-to-function type (after [lvalue conversions](conversion.html#Lvalue_conversions "c/language/conversion"))   
---|---|---  
argument-list |  \-  |  comma-separated list of expressions (which cannot be comma operators) of any complete object type. May be omitted when calling functions that take no arguments.   
  
The behavior of the function call expression depends on whether the prototype of the function being called is [in scope](scope.html "c/language/scope") at the point of call. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&action=edit&section=2 "Edit section: Call to a function with a prototype")] Call to a function with a prototype

1) The number of parameters must equal the number of arguments (unless the ellipsis parameter is used).

2) The type of each parameter must be a type such that [implicit conversion as if by assignment](conversion.html "c/language/conversion") exists that converts the unqualified type of the corresponding argument to the type of the parameter.

Additionally, for every parameter of [array type](array.html "c/language/array") that uses the keyword `static` between `**[**` and `**]**`, the argument expression must designate a pointer to the element of an array with at least that many elements as specified in the size expression of the parameter. | (since C99)  
---|---  
  
3) The arguments are evaluated [in unspecified order and without sequencing](eval_order.html "c/language/eval order").

4) [Assignment](operator_assignment.html "c/language/operator assignment") is performed to copy the value of each argument to the corresponding function parameter, ignoring any type qualifiers on the parameter type and its possibly recursive elements or members, if any (note: the function can modify its parameters, and those changes do not affect the arguments; C function calls are only call-by-value). 

    

  * if there is a [trailing ellipsis](variadic.html "c/language/variadic") parameter, [Default argument promotions](https://en.cppreference.com/mwiki/index.php?title=conversion&action=edit&redlink=1 "conversion \(page does not exist\)") are performed on the remaining arguments, which are made available to va_list.



5) Function is executed, and the value it returns becomes the value of the function call expression (if the function returns void, the function call expression is a void expression) 
    
    
    void f(char* p, int x) {}
    int main(void)
    {
        f("abc", 3.14); // array to pointer and float to int conversions
    }

####  Call to a function without a prototype

1) The arguments are evaluated [in unspecified order and without sequencing](eval_order.html "c/language/eval order"). 2) [Default argument promotions](conversion.html#Default_argument_promotions "c/language/conversion") are performed on every argument expression. 3) [Assignment](operator_assignment.html "c/language/operator assignment") is performed to copy the value of each argument to the corresponding function parameter, ignoring any type qualifiers on the parameter type and its possibly recursive elements or members, if any. 4) Function is executed, and the value it returns becomes the value of the function call expression (if the function returns void, the function call expression is a void expression) 
    
    
    void f(); // no prototype
    int main(void)
    {
        f(1, 1.0f); // UB unless f is defined to take an int and a double
    }
    void f(int a, double c) {}

The behavior of a function call to a function without a prototype is undefined if 

  * the number of arguments does not match the number of parameters. 
  * the promoted types of the arguments are not [compatible](compatible_type.html#Compatible_types "c/language/type") with the promoted types of the parameters except that 



    

  * signed and unsigned versions of the same integer type are considered compatible if the value of the argument is representable by both types. 
  * pointers to void and pointers to (possibly cvr-qualified) character types are considered compatible 


| (until C23)  
---|---  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&action=edit&section=4 "Edit section: Notes")] Notes

The evaluations of expression that designates the function to be called and all arguments are [unsequenced](eval_order.html "c/language/eval order") with respect to each other (but there is a sequence point before the body of the function begins executing) 
    
    
    (*pf[f1()]) (f2(), f3() + f4()); // f1, f2, f3, f4 may be called in any order

Although function call is only defined for pointers to functions, it works with function designators due to the [function-to-pointer implicit conversion](conversion.html#Function_to_pointer_conversion "c/language/conversion"). 
    
    
    int f(void) { return 1; }
    int (*pf)(void) = f;
     
    int main(void)
    {
        f();    // convert f to pointer, then call
        (&f)(); // create a pointer to function, then call
     
        pf();    // call the function
        (*pf)(); // obtain the function designator, convert to pointer, then calls
     
        (****f)(); // convert to pointer, obtain the function, repeat 4x, then call
        (****pf)(); // also OK
    }

Functions that ignore unused arguments, such as [printf](../io/fprintf.html "c/io/fprintf"), must be called with a prototype in scope (the prototype of such functions necessarily uses the [trailing ellipsis](variadic.html "c/language/variadic") parameter) to avoid invoking undefined behavior. 

The current standard wording of the semantics of preparing function parameters is defective, because it specifies that parameters are assigned from arguments while calling, which incorrectly rejects const-qualified parameter or member types, and inappropriately applies the semantics of volatile which is unimplementable for function parameters on many platforms. A post-C11 defect report [DR427](https://open-std.org/JTC1/SC22/WG14/www/docs/n2396.htm#dr_427) proposed change of such semantics from assignment to initialization, but was closed as not-a-defect. 

A function call expression where expression consists entirely of an identifier and that identifier is undeclared acts as though the identifier is declared as 
    
    
    extern int identifier(); // returns int and has no prototype

So the following complete program is valid C89: 
    
    
    main()
    {
        int n = [atoi](../string/byte/atoi.html)("123"); // implicitly declares atoi as int atoi()
    }

| (until C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&action=edit&section=5 "Edit section: Comma operator")] Comma operator

The comma operator expression has the form   
  
---  
lhs `**,**` rhs |  |   
  
where 

lhs |  \-  |  any expression   
---|---|---  
rhs |  \-  |  any expression other than another comma operator (in other words, comma operator's [associativity](operator_precedence.html "c/language/operator precedence") is left-to-right)   
  
First, the left operand, lhs, is evaluated and its result value is discarded. 

Then, a [sequence point](eval_order.html "c/language/eval order") takes place, so that all side effects of lhs are complete. 

Then, the right operand, rhs, is evaluated and its result is returned by the comma operator as a [non-lvalue](value_category.html "c/language/value category"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&action=edit&section=6 "Edit section: Notes")] Notes

The type of the lhs may be void (that is, it may be a call to a function that returns void, or it can be an expression [cast](cast.html "c/language/cast") to void) 

The comma operator may be lvalue in C++, but never in C 

The comma operator may return a struct (the only other expressions that return structs are compound literals, function calls, assignments, and the conditional operator) 

In the following contexts, the comma operator cannot appear at the top level of an expression because the comma has a different meaning: 

  * argument list in a function call 
  * initializer expression or [initializer list](initialization.html "c/language/initialization")
  * [generic selection](generic.html "c/language/generic")



If the comma operator has to be used in such context, it must be parenthesized: 
    
    
    // int n = 2,3; // error, comma assumed to begin the next declarator
    // int a[2] = {1,2,3}; // error: more initializers than elements
    int n = (2,3), a[2] = {(1,2),3}; // OK
     
    f(a, (t=3, t+2), c); // OK, first, stores 3 in t, then calls f with three arguments

Top-level comma operator is also disallowed in array bounds 
    
    
    // int a[2,3]; // error
    int a[(2,3)]; // OK, VLA array of size 3 (VLA because (2,3) is not a constant expression)

Comma operator is not allowed in [constant expressions](constant_expression.html "c/language/constant expression"), regardless of whether it's on the top level or not 
    
    
    // static int n = (1,2); // Error: constant expression cannot call the comma operator

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&action=edit&section=7 "Edit section: Cast operator")] Cast operator

See [cast operator](cast.html "c/language/cast")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&action=edit&section=8 "Edit section: Conditional operator")] Conditional operator

The conditional operator expression has the form   
  
---  
condition `**?**` expression-true `**:**` expression-false |  |   
  
where 

condition |  \-  |  an expression of scalar type   
---|---|---  
expression-true |  \-  |  the expression that will be evaluated if condition compares unequal to zero   
expression-false |  \-  |  the expression that will be evaluated if condition compares equal to zero   
  
Only the following expressions are allowed as expression-true and expression-false

  * two expressions of any [arithmetic type](arithmetic_types.html "c/language/arithmetic types")
  * two expressions of the same [struct](struct.html "c/language/struct") or [union](union.html "c/language/union") type 
  * two expressions of void type 
  * two expressions of pointer type, pointing to types that are [compatible](compatible_type.html#Compatible_types "c/language/type"), ignoring cvr-qualifiers 



  * two expressions of [nullptr_t](../types/nullptr_t.html "c/types/nullptr t") type 

| (since C23)  
---|---  
  
  * one expression is a pointer and the other is the null pointer constant (such as [NULL](../types/NULL.html "c/types/NULL"))or a [nullptr_t](../types/nullptr_t.html "c/types/nullptr t") value(since C23)
  * one expression is a pointer to object and the other is a pointer to void (possibly qualified) 



1) First, evaluates condition. There is a [sequence point](eval_order.html "c/language/eval order") after this evaluation.

2) If the result of condition compares unequal to zero, executes expression-true, otherwise executes expression-false

3) Performs a [conversion](conversion.html "c/language/conversion") from the result of the evaluation to the _common type_ , defined as follows:

1) if the expressions have arithmetic type, the common type is the type after [usual arithmetic conversions](conversion.html#Usual_arithmetic_conversions "c/language/conversion")

2) if the expressions have struct/union type, the common type is that struct/union type

3) if the expressions are both void, the entire conditional operator expression is a void expression

4) if one is a pointer and the other is a null pointer constantor a [nullptr_t](../types/nullptr_t.html "c/types/nullptr t") value(since C23), the type is the type of that pointer

5) if both are pointers, the result is the pointer to the type that combines cvr-qualifiers of both pointed-to types (that is, if one is const int* and the other is volatile int*, the result is const volatile int*), and if the types were different, the pointed-to type is the [composite type](types.html#Composite_type "c/language/types").

6) if one is a pointer to void, the result is a pointer to void with combined cvr-qualifiers

7) if both have [nullptr_t](../types/nullptr_t.html "c/types/nullptr t") type, the common type is also [nullptr_t](../types/nullptr_t.html "c/types/nullptr t") | (since C23)  
---|---  
      
    
    #define ICE(x) (sizeof(*(1 ? ((void*)((x) * 0l)) : (int*)1)))
     
    // if x is an Integer Constant Expression then macro expands to
     
    sizeof(*(1 ? [NULL](../types/NULL.html) : (int *) 1))  // (void *)((x)*0l)) -> NULL
     
    // according to point (4) this further converts into
     
    sizeof(int)
     
    // if x is not an Integer Constant Expression then macro expands to
    // according to point (6)
     
    (sizeof(*(void *)(x))           // Error due incomplete type

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&action=edit&section=9 "Edit section: Notes")] Notes

The conditional operator is never an [lvalue expression](value_category.html "c/language/value category"), although it may return objects of struct/union type. The only other expressions that may return structs are [assignment](operator_assignment.html "c/language/operator assignment"), [comma](operator_other.html#Comma_operator), [function call](operator_other.html#Function_call), and [compound literal](compound_literal.html "c/language/compound literal"). 

Note that in C++, it may be an lvalue expression. 

See [operator precedence](operator_precedence.html "c/language/operator precedence") for the details on the relative precedence of this operator and assignment. 

Conditional operator has right-to-left associativity, which allows chaining 

Run this code
    
    
    #include <assert.h>
     
    enum vehicle { bus, airplane, train, car, horse, feet };
     
    enum vehicle choose(char arg)
    {
        return arg == 'B' ? bus      :
               arg == 'A' ? airplane :
               arg == 'T' ? train    :
               arg == 'C' ? car      :
               arg == 'H' ? horse    :
                            feet     ;
    }
     
    int main(void)
    {
        [assert](../error/assert.html)(choose('H') == horse && choose('F') == feet);
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&action=edit&section=10 "Edit section: sizeof operator")] `sizeof` operator

See [sizeof operator](sizeof.html "c/language/sizeof")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&action=edit&section=11 "Edit section: Alignof operator")] `_Alignof` operator

See [_Alignof operator](alignof.html "c/language/ Alignof")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&action=edit&section=12 "Edit section: typeof operators")] `typeof` operators

See [typeof operators](typeof_unqual.html "c/language/typeof")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&action=edit&section=13 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.5.2.2 Function calls (p: TBD) 



    

  * 6.5.3.4 The sizeof and _Alignof operators (p: TBD) 



    

  * 6.5.4 Cast operators (p: TBD) 



    

  * 6.5.15 Conditional operator (p: TBD) 



    

  * 6.5.17 Comma operator (p: TBD) 



    

  * 6.7.3.5 Typeof specifiers (p: 115-118) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.5.2.2 Function calls (p: 58-59) 



    

  * 6.5.3.4 The sizeof and _Alignof operators (p: 64-65) 



    

  * 6.5.4 Cast operators (p: 65-66) 



    

  * 6.5.15 Conditional operator (p: 71-72) 



    

  * 6.5.17 Comma operator (p: 75) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.5.2.2 Function calls (p: 81-82) 



    

  * 6.5.3.4 The sizeof and _Alignof operators (p: 90-91) 



    

  * 6.5.4 Cast operators (p: 91) 



    

  * 6.5.15 Conditional operator (p: 100) 



    

  * 6.5.17 Comma operator (p: 105) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.5.2.2 Function calls (p: 71-72) 



    

  * 6.5.3.4 The sizeof operator (p: 80-81) 



    

  * 6.5.4 Cast operators (p: 81) 



    

  * 6.5.15 Conditional operator (p: 90-91) 



    

  * 6.5.17 Comma operator (p: 94) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.3.2.2 Function calls 



    

  * 3.3.3.4 The sizeof operator 



    

  * 3.3.4 Cast operators 



    

  * 3.3.15 Conditional operator 



    

  * 3.3.17 Comma operator 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&action=edit&section=14 "Edit section: See also")] See also

  * [Operator precedence](operator_precedence.html "c/language/operator precedence")

Common operators   
---  
[assignment](operator_assignment.html "c/language/operator assignment") | [increment  
decrement](operator_incdec.html "c/language/operator incdec") | [arithmetic](operator_arithmetic.html "c/language/operator arithmetic") | [logical](operator_logical.html "c/language/operator logical") | [comparison](operator_comparison.html "c/language/operator comparison") | [member  
access](operator_member_access.html "c/language/operator member access") | **other**  
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
[C++ documentation](../../cpp/language/operator_other.html "cpp/language/operator other") for Other operators  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&oldid=161471](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_other&oldid=161471)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



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
**Evaluation order and sequence points**  
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
[Function call, comma, conditional operator](operator_other.html "c/language/operator other")  
[sizeof](sizeof.html "c/language/sizeof")  
[`_Alignof`](alignof.html "c/language/ Alignof")(C11*)  
[Cast operators](cast.html "c/language/cast")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

Order of evaluation of the operands of any C operator, including the order of evaluation of function arguments in a function-call expression, and the order of evaluation of the subexpressions within any expression is unspecified (except where noted below). The compiler will evaluate them in any order, and may choose another order when the same expression is evaluated again. 

There is no concept of left-to-right or right-to-left evaluation in C, which is not to be confused with left-to-right and right-to-left associativity of operators: the expression f1() + f2() + f3() is parsed as (f1() + f2()) + f3() due to left-to-right associativity of operator+, but the function call to f3() may be evaluated first, last, or between f1() or f2() at run time. 

## Contents

  * [1 Definitions](eval_order.html#Definitions)
    * [1.1 Evaluations](eval_order.html#Evaluations)
    * [1.2 Ordering](eval_order.html#Ordering)
  * [2 Rules](eval_order.html#Rules)
  * [3 Undefined behavior](eval_order.html#Undefined_behavior)
  * [4 See also](eval_order.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/eval_order&action=edit&section=1 "Edit section: Definitions")] Definitions

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/eval_order&action=edit&section=2 "Edit section: Evaluations")] Evaluations

There are two kinds of evaluations performed by the compiler for each expression or subexpression (both of which are optional): 

  * _value computation ﻿_ : calculation of the value that is returned by the expression. This may involve determination of the identity of the object ([lvalue evaluation](value_category.html "c/language/value category")) or reading the value previously assigned to an object (rvalue evaluation). 
  * _side effect ﻿_ : access (read or write) to an object designated by a [`volatile`](volatile.html "c/language/volatile") lvalue, modification (writing) to an object, atomic synchronization(since C11), modifying a file, modifying the floating-point environment (if supported), or calling a function that does any of those operations. 



If no side effects are produced by an expression and the compiler can determine that the value is not used, the expression [may not be evaluated](as_if.html "c/language/as if"). 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/eval_order&action=edit&section=3 "Edit section: Ordering")] Ordering

_Sequenced-before_ is an asymmetric, transitive, pair-wise relationship between evaluations within the same thread (it may extend across threads if atomic types and memory barriers are involved). 

  * If a [sequence point](https://en.wikipedia.org/wiki/Sequence_point "enwiki:Sequence point") is present between the subexpressions E1 and E2, then both value computation and side effects of E1 are _sequenced-before_ every value computation and side effect of E2. 



  * If evaluation A is sequenced before evaluation B, then evaluation of A will be complete before evaluation of B begins. 
  * If A is not sequenced before B and B is sequenced before A, then evaluation of B will be complete before evaluation of A begins. 
  * If A is not sequenced before B and B is not sequenced before A, then two possibilities exist: 
    * evaluations of A and B are unsequenced: they may be performed in any order and may overlap (within a single thread of execution, the compiler may interleave the CPU instructions that comprise A and B) 
    * evaluations of A and B are indeterminately-sequenced: they may be performed in any order but may not overlap: either A will be complete before B, or B will be complete before A. The order may be the opposite the next time the same expression is evaluated. 

| (since C11)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/eval_order&action=edit&section=4 "Edit section: Rules")] Rules

1) There is a sequence point after the evaluation of all function arguments and of the function designator, and before the actual function call.

2) There is a sequence point after evaluation of the first (left) operand and before evaluation of the second (right) operand of the following binary operators: `&&` (logical AND), `||` (logical OR), and `,` (comma).

3) There is a sequence point after evaluation of the first (left) operand and before evaluation of the second or third operand (whichever is evaluated) of the conditional operator `?:`

4) There is a sequence point after the evaluation of a full expression (an expression that is not a subexpression: typically something that ends with a semicolon or a [controlling statement](statements.html "c/language/statements") of if/switch/while/do) and before the next full expression.

5) There is a sequence point at the end of a full declarator. 6) There is a sequence point immediately before the return of a library function. 7) There is a sequence point after the action associated with each conversion specifier in formatted I/O (in particular, it is well-formed for [scanf](../io/fscanf.html "c/io/fscanf") to write different fields into the same variable and for [printf](../io/fprintf.html "c/io/fprintf") to read and modify or modify the same variable more than once using %n) 8) There are sequence points before and immediately after each call to a comparison function made by the library functions [qsort](../algorithm/qsort.html "c/algorithm/qsort") and [bsearch](../algorithm/bsearch.html "c/algorithm/bsearch"), as well as between any call to the comparison function and the movement of the associated objects made by [qsort](../algorithm/qsort.html "c/algorithm/qsort") | (since C99)  
---|---  
9) The value computations (but not the side-effects) of the operands to any operator are sequenced before the value computation of the result of the operator (but not its side-effects). 10) The side effect (modification of the left argument) of the direct assignment operator and of all compound assignment operators is sequenced after the value computation (but not the side effects) of both left and right arguments. 11) The value computation of the post-increment and post-decrement operators is sequenced before its side-effect. 12) A function call that is not sequenced before or sequenced after another function call is indeterminately sequenced (CPU instructions that constitute different function calls cannot be interleaved, even if the functions are inlined) 13) In [initialization](initialization.html "c/language/initialization") list expressions, all evaluations are indeterminately sequenced 14) With respect to an indeterminately-sequenced function call, the operation of compound assignment operators, and both prefix and postfix forms of increment and decrement operators are single evaluations.  | (since C11)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/eval_order&action=edit&section=5 "Edit section: Undefined behavior")] Undefined behavior

1) If a side effect on a scalar object is unsequenced relative to another side effect on the same scalar object, the [behavior is undefined](behavior.html#UB_and_optimization "c/language/behavior"). 
    
    
    i = ++i + i++; // undefined behavior
    i = i++ + 1; // undefined behavior
    f(++i, ++i); // undefined behavior
    f(i = -1, i = -1); // undefined behavior

2) If a side effect on a scalar object is unsequenced relative to a value computation using the value of the same scalar object, the behavior is undefined. 
    
    
    f(i, i++); // undefined behavior
    a[i] = i++; // undefined behavior

3) The above rules apply as long as at least one allowable ordering of subexpressions permits such an unsequenced side-effect.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/eval_order&action=edit&section=6 "Edit section: See also")] See also

[Operator precedence](operator_precedence.html "c/language/operator precedence") which defines how expressions are built from their source code representation. 

[C++ documentation](../../cpp/language/eval_order.html "cpp/language/eval order") for Order of evaluation  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/eval_order&oldid=183029](https://en.cppreference.com/mwiki/index.php?title=c/language/eval_order&oldid=183029)" 

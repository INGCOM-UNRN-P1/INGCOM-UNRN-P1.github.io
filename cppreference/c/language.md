From cppreference.com

< [c](../c.html "c")

[ C](../c.html "c")

[Compiler support](compiler_support.html "c/compiler support")  
---  
**Language**  
[Headers](header.html "c/header")  
[Type support](types.html "c/types")  
[Program utilities](program.html "c/program")  
[Variadic function support](variadic.html "c/variadic")  
[Error handling](error.html "c/error")  
[Dynamic memory management](memory.html "c/memory")  
[Strings library](string.html "c/string")  
[Algorithms](algorithm.html "c/algorithm")  
[Numerics](numeric.html "c/numeric")  
[Date and time utilities](chrono.html "c/chrono")  
[Input/output support](io.html "c/io")  
[Localization support](locale.html "c/locale")  
[Concurrency support](thread.html "c/thread") (C11)  
[Technical Specifications](experimental.html "c/experimental")  
[Symbol index](index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

**C language**

[Basic concepts](language/basic_concepts.html "c/language/basic concepts")  
---  
[ Keywords](keyword.html "c/keyword")  
[ Preprocessor](preprocessor.html "c/preprocessor")  
[ Statements](language/statements.html "c/language/statements")  
[ Expressions](language/operators.html "c/language/expressions")  
[ Initialization](language/initialization.html "c/language/initialization")  
[ Declarations](language/declarations.html "c/language/declarations")  
[ Functions](language/functions.html "c/language/functions")  
Miscellaneous  
[ History of C](language/history.html "c/language/history")  
[Technical Specifications](experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

This is a reference of the core C language constructs. 

**[Basic concepts](language/basic_concepts.html "c/language/basic concepts")** [ Comments](comment.html "c/comment")  
[ ASCII chart](language/ascii.html "c/language/ascii")  
[ Character sets and encodings](language/charset.html "c/language/charset")  
[ Translation phases](language/translation_phases.html "c/language/translation phases")  
[ Punctuation](language/punctuators.html "c/language/punctuators")  
[ Identifier ](language/identifiers.html "c/language/identifier") \- [ Scope](language/scope.html "c/language/scope") \- [ Lifetime](language/lifetime.html "c/language/lifetime")  
[ Lookup and Name Spaces](language/name_space.html "c/language/name space")  
[ Type](language/compatible_type.html "c/language/type") \- [ Arithmetic types](language/arithmetic_types.html "c/language/arithmetic types")  
[ Objects and Alignment](language/object.html "c/language/object")   
[ The `main` function](language/main_function.html "c/language/main function")  
[ As-if rule](language/as_if.html "c/language/as if")  
[ Undefined behavior](language/behavior.html "c/language/behavior")  
[ Memory model and Data races](language/memory_model.html "c/language/memory model")  
**[Keywords](keyword.html "c/keyword")** **[Preprocessor](preprocessor.html "c/preprocessor")** [ `#if` \- `#ifdef` \- `#ifndef` \- `#elif`](preprocessor/conditional.html "c/preprocessor/conditional")  
[ `#elifdef` \- `#elifndef`](preprocessor/conditional.html "c/preprocessor/conditional") (C23)  
[ `#define` \- `#` \- `##`](preprocessor/replace.html "c/preprocessor/replace")  
[`#include`](preprocessor/include.html "c/preprocessor/include") \- [`#pragma`](preprocessor/impl.html "c/preprocessor/impl")  
[`#line`](preprocessor/line.html "c/preprocessor/line") \- [`#error`](preprocessor/warning.html "c/preprocessor/error")  
[`#warning`](preprocessor/warning.html "c/preprocessor/error") (C23) \- [`#embed`](preprocessor/embed.html "c/preprocessor/embed") (C23) **[Statements](language/statements.html "c/language/statements")** [`if`](language/if.html "c/language/if") \- [`switch`](language/switch.html "c/language/switch")  
[`for`](language/for.html "c/language/for")  
[`while`](language/while.html "c/language/while") \- [`do`-`while`](language/do.html "c/language/do")  
[`continue`](language/continue.html "c/language/continue") \- [`break`](language/break.html "c/language/break")  
[`goto`](language/goto.html "c/language/goto") \- [`return`](language/return.html "c/language/return")  
|  **[Expressions](language/operators.html "c/language/expressions")** [ Value categories](language/value_category.html "c/language/value category")  
[ Evaluation order and sequencing](language/eval_order.html "c/language/eval order")  
[ Constants and literals](language/operators.html#Constants_and_literals "c/language/expressions")  
[Integer constants](language/integer_constant.html "c/language/integer constant")  
[Floating constants](language/floating_constant.html "c/language/floating constant")  
[Character constants](language/character_constant.html "c/language/character constant")  
[`true`/`false`](language/bool_constant.html "c/language/bool constant") (C23)  
[`nullptr`](language/nullptr.html "c/language/nullptr") (C23)  
[String literals](language/string_literal.html "c/language/string literal")  
[Compound literals](language/compound_literal.html "c/language/compound literal") (C99)  
[ Constant expressions](language/constant_expression.html "c/language/constant expression")  
[ Implicit conversions](language/conversion.html "c/language/conversion")   
[Operators](language/operators.html#Operators "c/language/expressions")  
[ Member access and indirection](language/operator_member_access.html "c/language/operator member access")  
[ Logical](language/operator_logical.html "c/language/operator logical") \- [ Comparison](language/operator_comparison.html "c/language/operator comparison")  
[ Arithmetic](language/operator_arithmetic.html "c/language/operator arithmetic") \- [ Assignment](language/operator_assignment.html "c/language/operator assignment")  
[ Increment and Decrement](language/operator_incdec.html "c/language/operator incdec")  
[ Call, Comma, Ternary](language/operator_other.html "c/language/operator other")  
[`sizeof`](language/sizeof.html "c/language/sizeof") \- [`alignof`](language/alignof.html "c/language/alignof") (C11)  
[ Cast operators](language/cast.html "c/language/cast")  
[ Operator precedence](language/operator_precedence.html "c/language/operator precedence")  
[ Generic selection](language/generic.html "c/language/generic") (C11)  
**[Initialization](language/initialization.html "c/language/initialization")** [ Scalar](language/scalar_initialization.html "c/language/scalar initialization")  
[ Array](language/array_initialization.html "c/language/array initialization")  
[ Structure/Union ](language/struct_initialization.html "c/language/struct initialization")  
|  **[Declarations](language/declarations.html "c/language/declarations")** [ Pointers](language/pointer.html "c/language/pointer") \- [ Arrays](language/array.html "c/language/array")  
[ Enumerations](language/enum.html "c/language/enum")  
[ Storage duration and Linkage ](language/storage_class_specifiers.html "c/language/storage duration")  
[`const`](language/const.html "c/language/const") \- [`volatile`](language/volatile.html "c/language/volatile") \- [`restrict`](language/restrict.html "c/language/restrict") (C99)  
[`struct`](language/struct.html "c/language/struct") \- [`union`](language/union.html "c/language/union") \- [ Bit-fields](language/bit_field.html "c/language/bit field")  
[`alignas`](language/alignas.html "c/language/alignas") (C11) \- [`typedef`](language/typedef.html "c/language/typedef")  
[`static_assert`](language/static_assert.html "c/language/static assert") (C11)  
[ Atomic types](language/atomic.html "c/language/atomic") (C11)  
[ External and tentative definitions](language/extern.html "c/language/extern")  
[ Attributes](language/attributes.html "c/language/attributes") (C23)  
**[Functions](language/functions.html "c/language/functions")** [ Function declaration](language/function_declaration.html "c/language/function declaration")  
[ Function definition](language/function_definition.html "c/language/function definition")  
[`inline`](language/inline.html "c/language/inline") (C99)  
[`_Noreturn`](language/noreturn.html "c/language/ Noreturn") (C11) (deprecated in C23)  
[ Variadic arguments](language/variadic.html "c/language/variadic")  
**Miscellaneous** [ History of C](language/history.html "c/language/history")  
[ Conformance](language/conformance.html "c/language/conformance")  
[ Inline assembly](language/asm.html "c/language/asm")  
[ Signal handling](https://en.cppreference.com/mwiki/index.php?title=c/language/signal&action=edit&redlink=1 "c/language/signal（页面不存在）")   
[ Analyzability](language/analyzability.html "c/language/analyzability") (C11)  
  
  
  
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language&action=edit&section=1 "Edit section: See also")] See also

[C++ documentation](../cpp/language.html "cpp/language") for language constructs  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language&oldid=182843](https://en.cppreference.com/mwiki/index.php?title=c/language&oldid=182843)" 

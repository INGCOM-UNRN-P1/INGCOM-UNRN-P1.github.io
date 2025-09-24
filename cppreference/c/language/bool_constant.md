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
**`true`/`false`**(C23)  
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

## Contents

  * [1 Syntax](bool_constant.html#Syntax)
  * [2 Explanation](bool_constant.html#Explanation)
  * [3 Notes](bool_constant.html#Notes)
  * [4 Example](bool_constant.html#Example)
  * [5 References](bool_constant.html#References)
  * [6 See also](bool_constant.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/bool_constant&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**true**` |  (1)  |  (since C23)  
`**false**` |  (2)  |  (since C23)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/bool_constant&action=edit&section=2 "Edit section: Explanation")] Explanation

Keywords true and false represent predefined constants. They are [non-lvalues](value_category.html#Non-lvalue_object_expressions "c/language/value category") of type [`bool`](types.html "c/language/types"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/bool_constant&action=edit&section=3 "Edit section: Notes")] Notes

See [integral conversions](conversion.html#Integer_conversions "c/language/conversion") for implicit conversions from bool to other types and [boolean conversions](conversion.html#Boolean_conversion "c/language/conversion") for the implicit conversions from other types to bool. 

Until C23, true and false were implemented as macros provided in [`<stdbool.h>`](../header/stdbool.html "c/header/stdbool"). An implementation may also define bool, true, and false as predefined macros in C23 for compatibility. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/bool_constant&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <assert.h>
     
    int main()
    {
        [assert](../error/assert.html)(true == 1 && 0 == false);
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/bool_constant&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.4.4.6 Predefined constants (p: 66) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/bool_constant&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/bool_literal.html "cpp/language/bool literal") for Boolean literals  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/bool_constant&oldid=176320](https://en.cppreference.com/mwiki/index.php?title=c/language/bool_constant&oldid=176320)" 

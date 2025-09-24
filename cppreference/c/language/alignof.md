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
[Function call, comma, conditional operator](operator_other.html "c/language/operator other")  
[sizeof](sizeof.html "c/language/sizeof")  
**`_Alignof`**(C11*)  
[Cast operators](cast.html "c/language/cast")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

Queries the alignment requirement of its operand type. 

## Contents

  * [1 Syntax](alignof.html#Syntax)
  * [2 Explanation](alignof.html#Explanation)
  * [3 Notes](alignof.html#Notes)
  * [4 Keywords](alignof.html#Keywords)
  * [5 Example](alignof.html#Example)
  * [6 Defect reports](alignof.html#Defect_reports)
  * [7 References](alignof.html#References)
  * [8 See also](alignof.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignof&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**_Alignof(**` type-name `**)**` |  |  (since C11)(deprecated in C23)  
`**alignof(**` type-name `**)**` |  |  (since C23)  
This operator is typically used through the convenience macro [`alignof`](../types.html "c/types"), which is provided in the header [`<stdalign.h>`](../header/stdalign.html "c/header/stdalign") | (until C23)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignof&action=edit&section=2 "Edit section: Explanation")] Explanation

Returns the [alignment requirement](object.html#Alignment "c/language/object") of the type [named](compatible_type.html#Type_names "c/language/type") by type-name. If type-name is an array type, the result is the alignment requirement of the array element type. The type-name cannot be function type or an incomplete type. 

The result is an integer constant of type [size_t](../types/size_t.html "c/types/size t"). 

The operand is not evaluated (so external identifiers used in the operand do not have to be defined). 

If type-name is a [VLA](array.html "c/language/array") type, its size expression is not evaluated. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignof&action=edit&section=3 "Edit section: Notes")] Notes

The use of `_Alignof`(until C23)`alignof`(since C23) with expressions is allowed by some C compilers as a non-standard extension. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignof&action=edit&section=4 "Edit section: Keywords")] Keywords

[`alignof`](../keyword/alignof.html "c/keyword/alignof"), [`_Alignof`](../keyword/_Alignof.html "c/keyword/ Alignof")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignof&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdalign.h>
    #include <stddef.h>
    #include <stdio.h>
     
    int main(void)
    {
        [printf](../io/fprintf.html)("Alignment of char = %zu\n", alignof(char));
        [printf](../io/fprintf.html)("Alignment of max_align_t = %zu\n", alignof([max_align_t](../types/max_align_t.html)));
        [printf](../io/fprintf.html)("alignof(float[10]) = %zu\n", alignof(float[10]));
        [printf](../io/fprintf.html)("alignof(struct{char c; int n;}) = %zu\n",
                alignof(struct {char c; int n;}));
    }

Possible output: 
    
    
    Alignment of char = 1
    Alignment of max_align_t = 16
    alignof(float[10]) = 4
    alignof(struct{char c; int n;}) = 4

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignof&action=edit&section=6 "Edit section: Defect reports")] Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards. 

DR  | Applied to  | Behavior as published  | Correct behavior   
---|---|---|---  
[DR 494](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_494) | C11  | whether the size expression in a VLA is evaluated in `_Alignof` was unspecified  | it is unevaluated   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignof&action=edit&section=7 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.5.3.4 The sizeof and alignof operators (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.5.3.4 The sizeof and _Alignof operators (p: 64-65) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.5.3.4 The sizeof and _Alignof operators (p: 90-91) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignof&action=edit&section=8 "Edit section: See also")] See also

[ max_align_t](../types/max_align_t.html "c/types/max align t")(C11) |  a type with alignment requirement as great as any other scalar type   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_max_align_t&action=edit)  
---|---  
[`_Alignas`](alignas.html "c/language/ Alignas")(until C23)[`alignas`](alignas.html "c/language/ Alignas")(since C23) |  sets alignment requirements of an object  
(specifier)  
[C++ documentation](../../cpp/language/alignof.html "cpp/language/alignof") for `alignof` operator  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignof&oldid=180142](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignof&oldid=180142)" 

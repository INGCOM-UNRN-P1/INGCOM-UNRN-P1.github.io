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
**Generic selection** (C11)  
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

Provides a way to choose one of several expressions at compile time, based on a type of a controlling expression 

## Contents

  * [1 Syntax](generic.html#Syntax)
  * [2 Explanation](generic.html#Explanation)
  * [3 Notes](generic.html#Notes)
  * [4 Keywords](generic.html#Keywords)
  * [5 Example](generic.html#Example)
  * [6 Defect reports](generic.html#Defect_reports)
  * [7 References](generic.html#References)
  * [8 See also](generic.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/generic&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**_Generic**` `**(**` controlling-expression `**,**` association-list `**)**` |  |  (since C11)  
  
where association-list is a comma-separated list of associations, each of which has the syntax   
  
---  
type-name `**:**` expression |  |   
`**default**` `**:**` expression |  |   
  
where 

type-name |  \-  |  any complete [object type](compatible_type.html "c/language/type") that isn't variably-modified (that is, not VLA or pointer to VLA).   
---|---|---  
controlling-expression |  \-  |  any expression (except for the [comma operator](operator_other.html#Comma_operator "c/language/operator other")) whose type must be compatible with one of the type-names if the default association is not used   
expression |  \-  |  any expression (except for the [comma operator](operator_other.html#Comma_operator "c/language/operator other")) of any type and value category   
  
No two type-names in the association-list may specify [compatible types](compatible_type.html#Compatible_types "c/language/type"). There may be only one association that uses the keyword default. If default is not used and none of the type-names are compatible with the type of the controlling expression, the program will not compile. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/generic&action=edit&section=2 "Edit section: Explanation")] Explanation

First, the type of controlling-expression undergoes [lvalue conversions](conversion.html#Lvalue_conversions "c/language/conversion"). The conversion is performed in type domain only: it discards the top-level cvr-qualifiers and atomicity and applies array-to-pointer/function-to-pointer transformations to the type of the controlling expression, without initiating any side-effects or calculating any values. 

The type after conversion is compared with type-names from the list of associations. 

If the type is [compatible](compatible_type.html#Compatible_types "c/language/type") with the type-name of one of the associations, then the type, value, and [value category](value_category.html "c/language/value category") of the generic selection are the type, value, and value category of the expression that appears after the colon for that type-name. 

If none of the type-names are compatible with the type of the controlling-expression, and the default association is provided, then the type, value, and value category of the generic selection are the type, value, and value category of the expression after the `default :` label. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/generic&action=edit&section=3 "Edit section: Notes")] Notes

The controlling-expression and the expressions of the selections that are not chosen are never evaluated. 

Because of the lvalue conversions, "abc" matches char* and not char[4] and (int const){0} matches int, and not const int. 

All [value categories](value_category.html "c/language/value category"), including function designators and void expressions, are allowed as expressions in a generic selection, and if selected, the generic selection itself has the same value category. 

The [type-generic math macros](../numeric/tgmath.html "c/numeric/tgmath") from [`<tgmath.h>`](../header/tgmath.html "c/header/tgmath"), introduced in C99, were implemented in compiler-specific manner. Generic selections, introduced in C11, gave the programmers the ability to write similar type-dependent code. 

Generic selection is similar to overloading in C++ (where one of several functions is chosen at compile time based on the types of the arguments), except that it makes the selection between arbitrary expressions. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/generic&action=edit&section=4 "Edit section: Keywords")] Keywords

[`_Generic`](../keyword/_Generic.html "c/keyword/ Generic"), [`default`](../keyword/default.html "c/keyword/default")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/generic&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <math.h>
    #include <stdio.h>
     
    // Possible implementation of the tgmath.h macro cbrt
    #define cbrt(X) _Generic((X),     \
                  long double: cbrtl, \
                      default: cbrt,  \
                        float: cbrtf  \
                  )(X)
     
    int main(void)
    {
        double x = 8.0;
        const float y = 3.375;
        [printf](../io/fprintf.html)("cbrt(8.0) = %f\n", [cbrt](../numeric/math/cbrt.html)(x));    // selects the default cbrt
        [printf](../io/fprintf.html)("cbrtf(3.375) = %f\n", [cbrt](../numeric/math/cbrt.html)(y)); // converts const float to float,
                                                // then selects cbrtf
    }

Output: 
    
    
    cbrt(8.0) = 2.000000
    cbrtf(3.375) = 1.500000

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/generic&action=edit&section=6 "Edit section: Defect reports")] Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards. 

DR  | Applied to  | Behavior as published  | Correct behavior   
---|---|---|---  
[DR 481](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_481) | C11  | it was underspecified if the controlling expression undergoes lvalue conversions  | it undergoes   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/generic&action=edit&section=7 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.5.1.1 Generic selection (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.5.1.1 Generic selection (p: 56-57) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.5.1.1 Generic selection (p: 78-79) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/generic&action=edit&section=8 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/templates.html "cpp/language/templates") for Templates  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/generic&oldid=178619](https://en.cppreference.com/mwiki/index.php?title=c/language/generic&oldid=178619)" 

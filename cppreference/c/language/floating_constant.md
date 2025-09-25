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
**Floating constant**  
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

Allows values of floating type to be used directly in expressions. 

## Contents

  * [1 Syntax](floating_constant.html#Syntax)
  * [2 Explanation](floating_constant.html#Explanation)
    * [2.1 Suffixes](floating_constant.html#Suffixes)
    * [2.2 Optional parts](floating_constant.html#Optional_parts)
    * [2.3 Representable values](floating_constant.html#Representable_values)
  * [3 Notes](floating_constant.html#Notes)
  * [4 Example](floating_constant.html#Example)
  * [5 References](floating_constant.html#References)
  * [6 See also](floating_constant.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/floating_constant&action=edit&section=1 "Edit section: Syntax")] Syntax

A floating constant is a [non-lvalue](value_category.html "c/language/value category") expression having the form:   
  
---  
significand exponent ﻿(optional) suffix ﻿(optional) |  |   
  
Where the significand has the form   
  
---  
whole-number ﻿(optional) `**.**`(optional) fraction ﻿(optional) |  |   
  
The exponent has the form   
  
---  
`**e**` | `**E**` exponent-sign ﻿(optional) digit-sequence |  (1)  |   
`**p**` | `**P**` exponent-sign ﻿(optional) digit-sequence |  (2)  |  (since C99)  
  
1) The exponent syntax for a decimal floating-point constant

2) The exponent syntax for hexadecimal floating-point constant

Optional single quotes (`**'**`) can be inserted between the digits as a separator, they are ignored when compiling.  | (since C23)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/floating_constant&action=edit&section=2 "Edit section: Explanation")] Explanation

If the significand begins with the character sequence `0x` or `0X`, the floating constant is a _hexadecimal floating constant_. Otherwise, it is a _decimal floating constant_. For a _hexadecimal floating constant_ , the significand is interpreted as a hexadecimal rational number, and the digit-sequence of the exponent is interpreted as the integer power of 2 to which the significand has to be scaled. 
    
    
    double d = 0x1.2p3; // hex fraction 1.2 (decimal 1.125) scaled by 2^3, that is 9.0

| (since C99)  
---|---  
  
For a _decimal floating constant_ , the significand is interpreted as a decimal rational number, and the digit-sequence of the exponent is interpreted as the integer power of 10 to which the significand has to be scaled. 
    
    
    double d = 1.2e3; // decimal fraction 1.2 scaled by 10^3, that is 1200.0

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/floating_constant&action=edit&section=3 "Edit section: Suffixes")] Suffixes

An unsuffixed floating constant has type double. If suffix is the letter `**f**` or `**F**`, the floating constant has type float. If suffix is the letter `**l**` or `**L**`, the floating constant has type long double. 

If the implementation predefines macro `__STDC_IEC_60559_BFP__`, the following suffixes and corresponding floating constants are additionally supported: 

  * if suffix is `**df**` or `**DF**`, the floating constant has type _Decimal32; 
  * if suffix is `**dd**` or `**DD**`, the floating constant has type _Decimal64; 
  * if suffix is `**dl**` or `**DL**`, the floating constant has type _Decimal128. 

Suffixes for decimal floating-point types are not allowed in hexadecimal floating constants.  | (since C23)  
---|---  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/floating_constant&action=edit&section=4 "Edit section: Optional parts")] Optional parts

If the exponent is present and fractional part is not used, the decimal separator may be omitted: 
    
    
    double x = 1e0; // floating-point 1.0 (period not used)

For decimal floating constants, the exponent part is optional. If it is omitted, the period is not optional, and either the whole-number or the fraction must be present. 
    
    
    double x = 1.; // floating-point 1.0 (fractional part optional)
    double y = .1; // floating-point 0.1 (whole-number part optional)

For hexadecimal floating constants, the exponent is not optional to avoid ambiguity resulting from an `**f**` suffix being mistaken as a hexadecimal digit.  | (since C99)  
---|---  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/floating_constant&action=edit&section=5 "Edit section: Representable values")] Representable values

The result of evaluating a floating constant is either the nearest representable value or the larger or smaller representable value immediately adjacent to the nearest representable value, chosen in an implementation-defined manner (in other words, [default rounding direction](../numeric/fenv/FE_round.html "c/numeric/fenv/FE round") during translation is implementation-defined). 

All floating constants of the same source form convert to the same internal format with the same value. Floating constants of different source forms, e.g. 1.23 and 1.230, need not to convert to the same internal format and value. 

Floating-point constants may convert to more range and precision than is indicated by their type, if indicated by [FLT_EVAL_METHOD](../types/limits/FLT_EVAL_METHOD.html "c/types/limits/FLT EVAL METHOD"). For example, the constant 0.1f may act as if it were 0.1L in an expression. The result of evaluating a hexadecimal floating constant, if [FLT_RADIX](../types/limits.html "c/types/limits") is 2, is the exact value represented by the floating constant, correctly rounded to the target type.  | (since C99)  
---|---  
Floating constants of decimal floating-point type that have the same numerical value \\(\small x\\)x but different quantum exponents, e.g. 1230.dd, 1230.0dd, and 1.23e3dd, have distinguishable internal representations. The quantum exponent \\(\small q\\)q of a floating constant of a decimal floating-point type is determined in the manner that \\(\small 10^q\\)10q  
represents 1 at the place of last digit of the significand when possible. If the quantum exponent \\(\small q\\)q and the coefficient \\(\small c = x\cdot 10^{-q}\\)c=x·10-q  
determined above cannot represented exactly in the type of the floating constant, \\(\small q\\)q is increased as needed within the limit of the type, and \\(\small c\\)c is reduced correspondingly, with needed rounding. The rounding may result in zero or infinity. If (the possibly rounded) \\(\small c\\)c is still out of the permitted range after \\(\small q\\)q reaches the maximum value, the resulted floating constant has value positive infinity.  | (since C23)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/floating_constant&action=edit&section=6 "Edit section: Notes")] Notes

Default [rounding direction](../numeric/fenv/FE_round.html "c/numeric/fenv/FE round") and [precision](../types/limits/FLT_EVAL_METHOD.html "c/types/limits/FLT EVAL METHOD") are in effect when the floating constants are converted into internal representations, and [floating-point exceptions](../numeric/fenv/FE_exceptions.html "c/numeric/fenv/FE exceptions") are not raised even if [` #pragma STDC FENV_ACCESS`](../preprocessor/impl.html "c/preprocessor/impl") is in effect (for execution-time conversion of character strings, [strtod](../string/byte/strtof.html "c/string/byte/strtof") can be used). Note that this differs from [arithmetic constant expressions](constant_expression.html "c/language/constant expression") of floating type. 

Letters in the floating constants are case-insensitive, except that uppercase and lowercase cannot be both used in suffixes for decimal floating-point types(since C23): 0x1.ep+3 and 0X1.EP+3 represent the same floating-point value 15.0. 

The decimal point specified by [setlocale](../locale/setlocale.html "c/locale/setlocale") has no effect on the syntax of floating constants: the decimal point character is always the period. 

Unlike integers, not every floating value can be represented directly by decimal or even hexadecimal(since C99) constant syntax: macros [`NAN`](../numeric/math/NAN.html "c/numeric/math/NAN") and [`INFINITY`](../numeric/math/INFINITY.html "c/numeric/math/INFINITY") as well as functions such as [nan](../numeric/math/nan.html "c/numeric/math/nan") offer ways to generate those special values(since C99). Note that 0x1.FFFFFEp128f, which might appear to be an IEEE float NaN, in fact overflows to an infinity in that format. 

There are no negative floating constants; an expression such as -1.2 is the [arithmetic operator](operator_arithmetic.html "c/language/operator arithmetic") unary minus applied to the floating constant 1.2. Note that the special value negative zero may be constructed with -0.0. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/floating_constant&action=edit&section=7 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
     
    int main(void)
    {
        [printf](../io/fprintf.html)("15.0     = %a\n", 15.0);
        [printf](../io/fprintf.html)("0x1.ep+3 = %f\n", 0x1.ep+3);
     
        // Constants outside the range of type double.
        [printf](../io/fprintf.html)("+2.0e+308 --> %g\n",  2.0e+308);
        [printf](../io/fprintf.html)("+1.0e-324 --> %g\n",  1.0e-324);
        [printf](../io/fprintf.html)("-1.0e-324 --> %g\n", -1.0e-324);
        [printf](../io/fprintf.html)("-2.0e+308 --> %g\n", -2.0e+308);
    }

Output: 
    
    
    15.0     = 0x1.ep+3
    0x1.ep+3 = 15.000000
    +2.0e+308 --> inf
    +1.0e-324 --> 0
    -1.0e-324 --> -0
    -2.0e+308 --> -inf

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/floating_constant&action=edit&section=8 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.4.4.2 Floating constants (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.4.4.2 Floating constants (p: 47-48) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.4.4.2 Floating constants (p: 65-66) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.4.4.2 Floating constants (p: 57-58) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.1.3.1 Floating constants 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/floating_constant&action=edit&section=9 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/floating_literal.html "cpp/language/floating literal") for Floating-point literal  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/floating_constant&oldid=153211](https://en.cppreference.com/mwiki/index.php?title=c/language/floating_constant&oldid=153211)" 

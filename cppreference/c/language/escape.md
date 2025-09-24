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
[`_Alignof`](alignof.html "c/language/ Alignof")(C11*)  
[Cast operators](cast.html "c/language/cast")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

Escape sequences are used to represent certain special characters within [string literals](string_literal.html "c/language/string literal") and [character constants](character_constant.html "c/language/character constant"). 

The following escape sequences are available. ISO C requires a diagnostic if the backslash is followed by any character not listed here: 

Escape  
sequence  |  Description  |  Representation   
---|---|---  
Simple escape sequences   
`**\'**` |  single quote  |  byte `0x27` in ASCII encoding   
`**\"**` |  double quote  |  byte `0x22` in ASCII encoding   
`**\?**` |  question mark  |  byte `0x3f` in ASCII encoding   
`**\\**` |  backslash  |  byte `0x5c` in ASCII encoding   
`**\a**` |  audible bell  |  byte `0x07` in ASCII encoding   
`**\b**` |  backspace  |  byte `0x08` in ASCII encoding   
`**\f**` |  form feed - new page  |  byte `0x0c` in ASCII encoding   
`**\n**` |  line feed - new line  |  byte `0x0a` in ASCII encoding   
`**\r**` |  carriage return  |  byte `0x0d` in ASCII encoding   
`**\t**` |  horizontal tab  |  byte `0x09` in ASCII encoding   
`**\v**` |  vertical tab  |  byte `0x0b` in ASCII encoding   
Numeric escape sequences   
`**\_nnn_**` |  arbitrary octal value  |  code unit `_nnn_`  
`**\x _n..._**` |  arbitrary hexadecimal value  |  code unit `_n..._` (arbitrary number of hexadecimal digits)   
Universal character names   
`**\u _nnnn_**` (since C99) |  [ Unicode](https://en.wikipedia.org/wiki/Unicode "enwiki:Unicode") value in allowed range;  
may result in several code units  |  code point `U+_nnnn_`  
`**\U _nnnnnnnn_**` (since C99) |  [ Unicode](https://en.wikipedia.org/wiki/Unicode "enwiki:Unicode") value in allowed range;  
may result in several code units  |  code point `U+_nnnnnnnn_`  
| 

## Contents

  * [1 Range of universal character names](escape.html#Range_of_universal_character_names)
  * [2 Notes](escape.html#Notes)
  * [3 Example](escape.html#Example)
  * [4 References](escape.html#References)
  * [5 See also](escape.html#See_also)

  
---  
  
###  Range of universal character names

If a universal character name corresponds to a code point that is not `0x24` ('$'), `0x40` ('@'), nor `0x60` ('`') and less than `0xA0`, or a surrogate code point (the range `0xD800-0xDFFF`, inclusive), or greater than `0x10FFFF`, i.e. not a Unicode code point(since C23), the program is ill-formed. In other words, members of [basic source character set](translation_phases.html "c/language/translation phases") and control characters (in ranges `0x0-0x1F` and `0x7F-0x9F`) cannot be expressed in universal character names. 

(since C99)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/escape&action=edit&section=2 "Edit section: Notes")] Notes

\0 is the most commonly used octal escape sequence, because it represents the terminating null character in null-terminated strings. 

The new-line character \n has special meaning when used in [text mode I/O](../io.html "c/io"): it is converted to the OS-specific newline byte or byte sequence. 

Octal escape sequences have a length limit of three octal digits but terminate at the first character that is not a valid octal digit if encountered sooner. 

Hexadecimal escape sequences have no length limit and terminate at the first character that is not a valid hexadecimal digit. If the value represented by a single hexadecimal escape sequence does not fit the range of values represented by the character type used in this string literal or character constant (char, char8_t(since C23), char16_t, char32_t(since C11), or wchar_t), the result is unspecified. 

A universal character name in a narrow string literal or a 16-bit string literal(since C11) may map to more than one code unit, e.g. \U0001f34c is 4 char code units in UTF-8 (\xF0\x9F\x8D\x8C) and 2 char16_t code units in UTF-16 (\xD83C\xDF4C)(since C11).  | (since C99)  
---|---  
A universal character name corresponding to a code pointer greater than `0x10FFFF` (which is undefined in ISO/ISC 10646) can be used in [character constants](character_constant.html "c/language/character constant") and [string literals](string_literal.html "c/language/string literal"). Such usage is not allowed in C++20.  | (since C99)  
(until C23)  
---|---  
The question mark escape sequence \? is used to prevent [trigraphs](operator_alternative.html "c/language/operator alternative") from being interpreted inside string literals: a string such as "??/" is compiled as "\", but if the second question mark is escaped, as in "?\?/", it becomes "??/" | (until C23)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/escape&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
     
    int main(void)
    {
        [printf](../io/fprintf.html)("This\nis\na\ntest\n\nShe said, \"How are you?\"\n");
    }

Output: 
    
    
    This
    is
    a
    test
     
    She said, "How are you?"

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/escape&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 5.2.2 Character display semantics (p: 18-19) 



    

  * 6.4.3 Universal Character names (p: 44) 



    

  * 6.4.4.4 Character constants (p: 48-50) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 5.2.2 Character display semantics (p: 24-25) 



    

  * 6.4.3 Universal Character names (p: 61) 



    

  * 6.4.4.4 Character constants (p: 67-70) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 5.2.2 Character display semantics (p: 19-20) 



    

  * 6.4.3 Universal Character names (p: 53) 



    

  * 6.4.4.4 Character constants (p: 59-61) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 2.2.2 Character display semantics 



    

  * 3.1.3.4 Character constants 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/escape&action=edit&section=5 "Edit section: See also")] See also

  * [ASCII chart](ascii.html "c/language/ascii")

[C++ documentation](../../cpp/language/escape.html "cpp/language/escape") for Escape sequences  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/escape&oldid=158256](https://en.cppreference.com/mwiki/index.php?title=c/language/escape&oldid=158256)" 

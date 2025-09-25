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
**Character constant**  
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

## Contents

  * [1 Syntax](character_constant.html#Syntax)
  * [2 Notes](character_constant.html#Notes)
  * [3 Example](character_constant.html#Example)
  * [4 References](character_constant.html#References)
  * [5 See also](character_constant.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/character_constant&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**'**` c-char `**'**` |  (1)  |   
`**u8'**` c-char `**'**` |  (2)  |  (since C23)  
`**u'**` c-char `**'**` |  (3)  |  (since C11)  
`**U'**` c-char `**'**` |  (4)  |  (since C11)  
`**L'**` c-char `**'**` |  (5)  |   
`**'**` c-char-sequence `**'**` |  (6)  |   
`**L'**` c-char-sequence `**'**` |  (7)  |   
`**u'**` c-char-sequence `**'**` |  (8)  |  (since C11)(removed in C23)  
`**U'**` c-char-sequence `**'**` |  (9)  |  (since C11)(removed in C23)  
  
where 

  * c-char is either 



    

  * a character from the basic source character set minus single-quote (`**'**`), backslash (`**\**`), or the newline character. 
  * escape sequence: one of special character escapes \' \" \? \\\ \a \b \f \n \r \t \v, hex escapes \x... or octal escapes \\... as defined in [escape sequences](escape.html "c/language/escape"). 



    

  * universal character name, \u... or \U... as defined in [escape sequences](escape.html "c/language/escape"). 


| (since C99)  
---|---  
  
  * c-char-sequence is a sequence of two or more c-chars. 



1) single-byte integer character constant, e.g. 'a' or '\n' or '\13'. Such constant has type int and a value equal to the representation of c-char in the execution character set as a value of type char mapped to int. If c-char is not representable as a single byte in the execution character set, the value is implementation-defined.

2) UTF-8 character constant, e.g. u8'a'. Such constant has type char8_t and the value equal to ISO 10646 code point value of c-char, provided that the code point value is representable with a single UTF-8 code unit (that is, c-char is in the range 0x0-0x7F, inclusive). If c-char is not representable with a single UTF-8 code unit, the program is ill-formed.

3) 16-bit wide character constant, e.g. u'貓', but not u'🍌' (u'\U0001f34c'). Such constant has type char16_t and a value equal to the value of c-char in the 16-bit encoding produced by [mbrtoc16](../string/multibyte/mbrtoc16.html "c/string/multibyte/mbrtoc16") (normally UTF-16). If c-char is not representable or maps to more than one 16-bit character, the value is implementation-defined. 4) 32-bit wide character constant, e.g. U'貓' or U'🍌'. Such constant has type char32_t and a value equal to the value of c-char in in the 32-bit encoding produced by [mbrtoc32](../string/multibyte/mbrtoc32.html "c/string/multibyte/mbrtoc32") (normally UTF-32). If c-char is not representable or maps to more than one 32-bit character, the value is implementation-defined.  | (until C23)  
---|---  
3) UTF-16 character constant, e.g. u'貓', but not u'🍌' (u'\U0001f34c'). Such constant has type char16_t and the value equal to ISO 10646 code point value of c-char, provided that the code point value is representable with a single UTF-16 code unit (that is, c-char is in the range 0x0-0xD7FF or 0xE000-0xFFFF, inclusive). If c-char is not representable with a single UTF-16 code unit, the program is ill-formed. 4) UTF-32 character constant, e.g. U'貓' or U'🍌'. Such constant has type char32_t and the value equal to ISO 10646 code point value of c-char, provided that the code point value is representable with a single UTF-32 code unit (that is, c-char is in the range 0x0-0xD7FF or 0xE000-0x10FFFF, inclusive). If c-char is not representable with a single UTF-32 code unit, the program is ill-formed.  | (since C23)  
  
5) wide character constant, e.g. L'β' or L'貓. Such constant has type wchar_t and a value equal to the value of c-char in the execution wide character set (that is, the value that would be produced by [mbtowc](../string/multibyte/mbtowc.html "c/string/multibyte/mbtowc")). If c-char is not representable or maps to more than one wide character (e.g. a non-BMP value on Windows where wchar_t is 16-bit), the value is implementation-defined .

6) multicharacter constant, e.g. 'AB', has type int and implementation-defined value.

7) wide multicharacter constant, e.g. L'AB', has type wchar_t and implementation-defined value.

8) 16-bit multicharacter constant, e.g. u'CD', has type char16_t and implementation-defined value.

9) 32-bit multicharacter constant, e.g. U'XY', has type char32_t and implementation-defined value.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/character_constant&action=edit&section=2 "Edit section: Notes")] Notes

Multicharacter constants were inherited by C from the B programming language. Although not specified by the C standard, most compilers (MSVC is a notable exception) implement multicharacter constants as specified in B: the values of each char in the constant initialize successive bytes of the resulting integer, in big-endian zero-padded right-adjusted order, e.g. the value of '\1' is 0x00000001 and the value of '\1\2\3\4' is 0x01020304. 

In C++, encodable ordinary character literals have type char, rather than int. 

Unlike [integer constants](integer_constant.html "c/language/integer constant"), a character constant may have a negative value if char is signed: on such implementations '\xFF' is an int with the value -1. 

When used in a controlling expression of [` #if`](../preprocessor/conditional.html "c/preprocessor/conditional") or [` #elif`](../preprocessor/conditional.html "c/preprocessor/conditional"), character constants may be interpreted in terms of the source character set, the execution character set, or some other implementation-defined character set. 

16/32-bit multicharacter constants are not widely supported and removed in C23. Some common implementations (e.g. clang) do not accept them at all. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/character_constant&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stddef.h>
    #include <stdio.h>
    #include <uchar.h>
     
    int main(void)
    {
        [printf](../io/fprintf.html)("constant value     \n");
        [printf](../io/fprintf.html)("-------- ----------\n");
     
        // integer character constants,
        int c1='a'; [printf](../io/fprintf.html)("'a':\t %#010x\n", c1);
        int c2='🍌'; [printf](../io/fprintf.html)("'🍌':\t %#010x\n\n", c2); // implementation-defined
     
        // multicharacter constant
        int c3='ab'; [printf](../io/fprintf.html)("'ab':\t %#010x\n\n", c3); // implementation-defined
     
        // 16-bit wide character constants
        char16_t uc1 = u'a'; [printf](../io/fprintf.html)("'a':\t %#010x\n", (int)uc1);
        char16_t uc2 = u'¢'; [printf](../io/fprintf.html)("'¢':\t %#010x\n", (int)uc2);
        char16_t uc3 = u'猫'; [printf](../io/fprintf.html)("'猫':\t %#010x\n", (int)uc3);
        // implementation-defined (🍌 maps to two 16-bit characters)
        char16_t uc4 = u'🍌'; [printf](../io/fprintf.html)("'🍌':\t %#010x\n\n", (int)uc4);
     
        // 32-bit wide character constants
        char32_t Uc1 = U'a'; [printf](../io/fprintf.html)("'a':\t %#010x\n", (int)Uc1);
        char32_t Uc2 = U'¢'; [printf](../io/fprintf.html)("'¢':\t %#010x\n", (int)Uc2);
        char32_t Uc3 = U'猫'; [printf](../io/fprintf.html)("'猫':\t %#010x\n", (int)Uc3);
        char32_t Uc4 = U'🍌'; [printf](../io/fprintf.html)("'🍌':\t %#010x\n\n", (int)Uc4);
     
        // wide character constants
        wchar_t wc1 = L'a'; [printf](../io/fprintf.html)("'a':\t %#010x\n", (int)wc1);
        wchar_t wc2 = L'¢'; [printf](../io/fprintf.html)("'¢':\t %#010x\n", (int)wc2);
        wchar_t wc3 = L'猫'; [printf](../io/fprintf.html)("'猫':\t %#010x\n", (int)wc3);
        wchar_t wc4 = L'🍌'; [printf](../io/fprintf.html)("'🍌':\t %#010x\n\n", (int)wc4);
    }

Possible output: 
    
    
    constant value     
    -------- ----------
    'a':	 0x00000061
    '🍌':	 0xf09f8d8c
     
    'ab':	 0x00006162
    'a':	 0x00000061
    '¢':	 0x000000a2
    '猫':	 0x0000732b
    '🍌':	 0x0000df4c
     
    'a':	 0x00000061
    '¢':	 0x000000a2
    '猫':	 0x0000732b
    '🍌':	 0x0001f34c
    'a':	 0x00000061
    '¢':	 0x000000a2
    '猫':	 0x0000732b
    '🍌':	 0x0001f34c

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/character_constant&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.4.4.5 Character constants (p: 63-66) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.4.4.4 Character constants (p: 48-50) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.4.4.4 Character constants (p: 67-70) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.4.4.4 Character constants (p: 59-61) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.1.3.4 Character constants 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/character_constant&action=edit&section=5 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/character_literal.html "cpp/language/character literal") for Character literal  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/character_constant&oldid=183161](https://en.cppreference.com/mwiki/index.php?title=c/language/character_constant&oldid=183161)" 

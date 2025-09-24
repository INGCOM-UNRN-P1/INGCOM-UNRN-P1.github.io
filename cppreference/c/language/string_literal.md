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
**String literal**  
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

Constructs an unnamed object of specified character array type in-place, used when a character string needs to be embedded in source code. 

## Contents

  * [1 Syntax](string_literal.html#Syntax)
  * [2 Explanation](string_literal.html#Explanation)
  * [3 Notes](string_literal.html#Notes)
  * [4 Example](string_literal.html#Example)
  * [5 References](string_literal.html#References)
  * [6 See also](string_literal.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/string_literal&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**"**` s-char-sequence `**"**` |  (1)  |   
`**u8"**` s-char-sequence `**"**` |  (2)  |  (since C11)  
`**u"**` s-char-sequence `**"**` |  (3)  |  (since C11)  
`**U"**` s-char-sequence `**"**` |  (4)  |  (since C11)  
`**L"**` s-char-sequence `**"**` |  (5)  |   
  
where 

s-char-sequence |  \-  |  zero or more characters, each of which is either a multibyte character from the source character set (excluding (`**"**`), `**\**`, and newline), or character escape, hex escape, octal escape, or universal character name(since C99) as defined in [escape sequences](escape.html "c/language/escape").   
---|---|---  
  
1) _character string literal_ : The type of the literal is char[N], where `N` is the size of the string in code units of the execution narrow encoding, including the null terminator. Each char element in the array is initialized from the next character in s-char-sequence using the execution character set.

2) _UTF-8 string literal_ : The type of the literal is char[N](until C23)char8_t[N](since C23), where `N` is the size of the string in UTF-8 code units including the null terminator. Each char(until C23)char8_t(since C23) element in the array is initialized from the next multibyte character in s-char-sequence using UTF-8 encoding.

3) 16-bit wide string literal: The type of the literal is char16_t[N], where `N` is the size of the string in code units of implementation-defined 16-bit encoding (typically UTF-16), including the null terminator. Each char16_t element in the array is initialized as if by executing [mbrtoc16](../string/multibyte/mbrtoc16.html "c/string/multibyte/mbrtoc16") in implementation-defined locale. 4) 32-bit wide string literal: The type of the literal is char32_t[N], where `N` is the size of the string in code units of implementation-defined 32-bit encoding (typically UTF-32), including the null terminator. Each char32_t element in the array is initialized as if by executing [mbrtoc32](../string/multibyte/mbrtoc32.html "c/string/multibyte/mbrtoc32") in implementation-defined locale.  | (until C23)  
---|---  
3) _UTF-16 string literal_ : The type of the literal is char16_t[N], where `N` is the size of the string in UTF-16 code units including the null terminator. Each char16_t element in the array is initialized from the next multibyte character in s-char-sequence using UTF-16 encoding. 4) _UTF-32 string literal_ : The type of the literal is char32_t[N], where `N` is the size of the string in UTF-32 code units including the null terminator. Each char32_t element in the array is initialized from the next multibyte character in s-char-sequence using UTF-32 encoding.  | (since C23)  
  
5) wide string literal: The type of the literal is wchar_t[N], where `N` is the size of the string in code units of the execution wide encoding, including the null terminator. Each wchar_t element in the array is initialized as if by executing [mbstowcs](../string/multibyte/mbstowcs.html "c/string/multibyte/mbstowcs") in implementation-defined locale.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/string_literal&action=edit&section=2 "Edit section: Explanation")] Explanation

First, at [translation phase 6](translation_phases.html "c/language/translation phases") (after macro expansion), the adjacent string literals (that is, string literals separated by whitespace only) are concatenated. 

Only two narrow or two wide string literals may be concatenated.  | (until C99)  
---|---  
If one literal is unprefixed, the resulting string literal has the width/encoding specified by the prefixed literal. 
    
    
    L"Δx = %" [PRId16](../types/integer.html) // at phase 4, PRId16 expands to "d"
                     // at phase 6, L"Δx = %" and "d" form L"Δx = %d"

| (since C99)  
If the two string literals have different encoding prefixes, concatenation is implementation-defined, except that a UTF-8 string literal and a wide string literal cannot be concatenated.  | (since C11)  
(until C23)  
---|---  
If the two string literals have different encoding prefixes, concatenation is ill-formed.  | (since C23)  
  
Secondly, at [translation phase 7](translation_phases.html "c/language/translation phases"), a terminating null character is added to each string literal, and then each literal initializes an unnamed array with static [storage duration](storage_class_specifiers.html "c/language/storage duration") and length just enough to contain the contents of the string literal plus one for the null terminator. 
    
    
    char* p = "\x12" "3"; // creates a static char[3] array holding {'\x12', '3', '\0'}
                          // sets p to point to the first element of the array

String literals are **not modifiable** (and in fact may be placed in read-only memory such as `.rodata`). If a program attempts to modify the static array formed by a string literal, the behavior is undefined. 
    
    
    char* p = "Hello";
    p[1] = 'M'; // Undefined behavior
    char a[] = "Hello";
    a[1] = 'M'; // OK: a is not a string literal

It is neither required nor forbidden for identical string literals to refer to the same location in memory. Moreover, overlapping string literals or string literals that are substrings of other string literals may be combined. 
    
    
    "def" == 3+"abcdef"; // may be 1 or 0, implementation-defined

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/string_literal&action=edit&section=3 "Edit section: Notes")] Notes

A string literal is not necessarily a string; if a string literal has embedded null characters, it represents an array which contains more than one string: 
    
    
    char* p = "abc\0def"; // strlen(p) == 3, but the array has size 8

If a valid hex digit follows a hex escape in a string literal, it would fail to compile as an invalid escape sequence, but string concatenation can be used as a workaround: 
    
    
    //char* p = "\xfff"; // error: hex escape sequence out of range
    char* p = "\xff""f"; // okay, the literal is char[3] holding {'\xff', 'f', '\0'}

String literals can be used to [initialize arrays](array_initialization.html "c/language/array initialization"), and if the size of the array is one less the size of the string literal, the null terminator is ignored: 
    
    
    char a1[] = "abc"; // a1 is char[4] holding {'a', 'b', 'c', '\0'}
    char a2[4] = "abc"; // a2 is char[4] holding {'a', 'b', 'c', '\0'}
    char a3[3] = "abc"; // a3 is char[3] holding {'a', 'b', 'c'}

The encoding of character string literals (1) and wide string literals (5) is implementation-defined. For example, gcc selects them with the [commandline options](https://gcc.gnu.org/onlinedocs/cpp/Invocation.html) -fexec-charset and -fwide-exec-charset. 

Although mixed wide string literal concatenation is allowed in C11, almost all compilers reject such concatenation (the only known exception is [SDCC](http://sdcc.sourceforge.net/)), and its usage experience is unknown. As a result, allowance of mixed wide string literal concatenation is removed in C23. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/string_literal&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <inttypes.h>
    #include <locale.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <uchar.h>
     
    int main(void)
    {
        char s1[] = "a猫🍌"; // or "a\u732B\U0001F34C"
    #if __STDC_VERSION__ >= 202311L
        char8_t
    #else
        char
    #endif
        s2[] = u8"a猫🍌";
        char16_t s3[] = u"a猫🍌";
        char32_t s4[] = U"a猫🍌";
        wchar_t s5[] = L"a猫🍌";
     
        [setlocale](../locale/setlocale.html)([LC_ALL](../locale/LC_categories.html), "en_US.utf8");
        [printf](../io/fprintf.html)("  \"%s\" is a char[%zu] holding     { ", s1, sizeof s1 / sizeof *s1);
        for([size_t](../types/size_t.html) n = 0; n < sizeof s1 / sizeof *s1; ++n)
            [printf](../io/fprintf.html)("0x%02X ", +(unsigned char)s1[n]);
        [puts](../io/puts.html)("}");
        [printf](../io/fprintf.html)(
    #if __STDC_VERSION__ >= 202311L
        "u8\"%s\" is a char8_t[%zu] holding  { "
    #else
        "u8\"%s\" is a char[%zu] holding     { "
    #endif
    , s2, sizeof s2 / sizeof *s2);
        for([size_t](../types/size_t.html) n = 0; n < sizeof s2 / sizeof *s2; ++n)
    #if __STDC_VERSION__ >= 202311L
           [printf](../io/fprintf.html)("0x%02X ", s2[n]);
    #else
           [printf](../io/fprintf.html)("0x%02X ", +(unsigned char)s2[n]);
    #endif
        [puts](../io/puts.html)("}");
        [printf](../io/fprintf.html)(" u\"a猫🍌\" is a char16_t[%zu] holding { ", sizeof s3 / sizeof *s3);
        for([size_t](../types/size_t.html) n = 0; n < sizeof s3 / sizeof *s3; ++n)
           [printf](../io/fprintf.html)("0x%04" [PRIXLEAST16](../types/integer.html)" ", s3[n]);
        [puts](../io/puts.html)("}");
        [printf](../io/fprintf.html)(" U\"a猫🍌\" is a char32_t[%zu] holding { ", sizeof s4 / sizeof *s4);
        for([size_t](../types/size_t.html) n = 0; n < sizeof s4 / sizeof *s4; ++n)
           [printf](../io/fprintf.html)("0x%08" [PRIXLEAST32](../types/integer.html)" ", s4[n]);
        [puts](../io/puts.html)("}");
        [printf](../io/fprintf.html)(" L\"%ls\" is a wchar_t[%zu] holding  { ", s5, sizeof s5 / sizeof *s5);
        for([size_t](../types/size_t.html) n = 0; n < sizeof s5 / sizeof *s5; ++n)
           [printf](../io/fprintf.html)("0x%08X ", (unsigned)s5[n]);
        [puts](../io/puts.html)("}");
    }

Possible output: 
    
    
      "a猫🍌" is a char[9] holding     { 0x61 0xE7 0x8C 0xAB 0xF0 0x9F 0x8D 0x8C 0x00 }
    u8"a猫🍌" is a char[9] holding     { 0x61 0xE7 0x8C 0xAB 0xF0 0x9F 0x8D 0x8C 0x00 }
     u"a猫🍌" is a char16_t[5] holding { 0x0061 0x732B 0xD83C 0xDF4C 0x0000 }
     U"a猫🍌" is a char32_t[4] holding { 0x00000061 0x0000732B 0x0001F34C 0x00000000 }
     L"a猫🍌" is a wchar_t[4] holding  { 0x00000061 0x0000732B 0x0001F34C 0x00000000 }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/string_literal&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.4.5 String literals (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.4.5 String literals (p: 50-52) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.4.5 String literals (p: 70-72) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.4.5 String literals (p: 62-63) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.1.4 String literals 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/string_literal&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/string_literal.html "cpp/language/string literal") for string literal  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/string_literal&oldid=150263](https://en.cppreference.com/mwiki/index.php?title=c/language/string_literal&oldid=150263)" 

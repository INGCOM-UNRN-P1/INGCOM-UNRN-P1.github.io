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

[ Basic Concepts](basic_concepts.html "c/language/basic concepts")

[ Comments](../comment.html "c/comment")  
---  
[ ASCII](ascii.html "c/language/ascii")  
**Character sets**  
[ Translation phases](translation_phases.html "c/language/translation phases")  
[Punctuation](punctuators.html "c/language/punctuators")  
[Identifier](identifiers.html "c/language/identifier")  
[Scope](scope.html "c/language/scope")  
[Lifetime](lifetime.html "c/language/lifetime")  
[Lookup and name spaces](name_space.html "c/language/name space")  
[Type](compatible_type.html "c/language/type")  
[Arithmetic types](arithmetic_types.html "c/language/arithmetic types")  
[Objects and alignment](object.html "c/language/object")  
[The main() function](main_function.html "c/language/main function")  
[The as-if rule](as_if.html "c/language/as if")  
[Undefined behavior](behavior.html "c/language/behavior")  
[Memory model and data races](memory_model.html "c/language/memory model")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/basics/navbar_content&action=edit)

## Contents

  * [1 Basic character set](charset.html#Basic_character_set)
  * [2 Basic execution character set](charset.html#Basic_execution_character_set)
  * [3 Literal encodings](charset.html#Literal_encodings)
  * [4 See also](charset.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/charset&action=edit&section=1 "Edit section: Basic character set")] Basic character set

The _basic character set_ consists of the following 95 characters: 

Code point | Character | Glyph   
---|---|---  
U+0009 | Character tabulation |   
U+000B | Line tabulation |   
U+000C | Form feed (FF) |   
U+0020 | Space |   
U+0021 | Exclamation mark | `**!**`  
U+0022 | Quotation mark | `**"**`  
U+0023 | Number sign | `**#**`  
U+0025 | Percent sign | `**%**`  
U+0026 | Ampersand | `**&**`  
U+0027 | Apostrophe | `**'**`  
U+0028 | Left parenthesis | `**(**`  
U+0029 | Right parenthesis | `**)**`  
U+002A | Asterisk | `*****`  
U+002B | Plus sign | `**+**`  
U+002C | Comma | `**,**`  
U+002D | Hyphen-minus | `**-**`  
U+002E | Full stop | `**.**`  
U+002F | Solidus | `**/**`  
U+0030 .. U+0039 | Digit zero .. nine | `**0 1 2 3 4 5 6 7 8 9**`  
U+003A | Colon | `**:**`  
U+003B | Semicolon | `**;**`  
U+003C | Less-than sign | `**<**`  
U+003D | Equals sign | `**=**`  
U+003E | Greater-than sign | `**>**`  
U+003F | Question mark | `**?**`  
U+0041 .. U+005A | Latin capital letter A .. Z | `**A B C D E F G H I J K L M**` `**N O P Q R S T U V W X Y Z**`  
U+005B | Left square bracket | `**[**`  
U+005C | Reverse solidus | `**\**`  
U+005D | Right square bracket | `**]**`  
U+005E | Circumflex accent | `**^**`  
U+005F | Low line | `**_**`  
U+0061 .. U+007A | Latin small letter a .. z | `**a b c d e f g h i j k l m**` `**n o p q r s t u v w x y z**`  
U+007B | Left curly bracket | `**{**`  
U+007C | Vertical line | `**|**`  
U+007D | Right curly bracket | `**}**`  
U+007E | Tilde | `**~**`  
  
Unlike C++, the U+000A LINE FEED (LF) character is not included in basic character set. Instead, there shall be some way of indicating the end of each line of text in the source file and the document treats such an end-of-line indicator as if it were a single new-line character. 

Basic character set is also known as _basic source character set_. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/charset&action=edit&section=2 "Edit section: Basic execution character set")] Basic execution character set

The _basic execution character set_ contains all the members of the basic character set, plus the following characters: 

Code unit  |  Character   
---|---  
U+0000 | Null   
U+0007 | Bell   
U+0008 | Backspace   
U+000A | Line feed (LF)   
U+000D | Carriage return (CR)   
  
For each basic execution character set, the values of the members shall be non-negative and distinct from one another. In both the source and execution basic character sets, the value of each character after 0 in the above list of decimal digits shall be one greater than the value of the previous. The U+0000 NULL character has the value 0. 

The representation of each member of the basic execution character sets fit in a byte. 

In C++, basic execution character set is also known as _basic literal character set_ and _basic execution wide-character set_. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/charset&action=edit&section=3 "Edit section: Literal encodings")] Literal encodings

The _literal encoding_ is an implementation-defined mapping of the characters of the execution character set to the values in a [character constant](character_constant.html "c/language/character constant") or [string literal](string_literal.html "c/language/string literal") without encoding prefix. It supports a mapping from all the basic execution character set values into the implementation-defined encoding. It may contain multibyte character sequences. 

The following characters are not in basic execution character set, but they are required to be encoded as a single byte in an ordinary character constant or ordinary string literal.  |  Code point | Character | Glyph   
---|---|---  
U+0024 | Dollar Sign | `**$**`  
U+0040 | Commercial At | `**@**`  
U+0060 | Grave Accent | `**`**`  
(since C23)  
  
The _wide literal encoding_ is an implementation-defined mapping of the characters of the execution character set to the values in an `L`-prefixed character constant or string literal. It supports a mapping from all the basic execution character set values into the implementation-defined encoding. If an implementation does not define `__STDC_MB_MIGHT_NEQ_WC__`, the mapping produces values identical to the literal encoding for all the basic execution character set values. One or more values may map to one or more values of the extended execution character set. 

The UTF-8 encoding is used for mapping characters of the execution character set to a `u8`-prefixed character constant or(since C23) string literal. An implementation-defined encoding(until C23)The UTF-16 encoding(since C23) is used for mapping characters of the execution character set to a `u`-prefixed character constant or string literal. An implementation-defined encoding(until C23)The UTF-32 encoding(since C23) is used for mapping characters of the execution character set to a `U`-prefixed character constant or string literal.  | (since C11)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/charset&action=edit&section=4 "Edit section: See also")] See also

[ASCII chart](ascii.html "c/language/ascii")  
---  
[C++ documentation](../../cpp/language/charset.html "cpp/language/charset") for Character sets and encodings  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/charset&oldid=151269](https://en.cppreference.com/mwiki/index.php?title=c/language/charset&oldid=151269)" 

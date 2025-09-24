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
[ Character sets](charset.html "c/language/charset")  
**Translation phases**  
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

The C source file is processed by the compiler _as if_ the following phases take place, in this exact order. Actual implementation may combine these actions or process them differently as long as the behavior is the same. 

## Contents

  * [1 Phase 1](translation_phases.html#Phase_1)
  * [2 Phase 2](translation_phases.html#Phase_2)
  * [3 Phase 3](translation_phases.html#Phase_3)
  * [4 Phase 4](translation_phases.html#Phase_4)
  * [5 Phase 5](translation_phases.html#Phase_5)
  * [6 Phase 6](translation_phases.html#Phase_6)
  * [7 Phase 7](translation_phases.html#Phase_7)
  * [8 Phase 8](translation_phases.html#Phase_8)
  * [9 References](translation_phases.html#References)
  * [10 See also](translation_phases.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/translation_phases&action=edit&section=1 "Edit section: Phase 1")] Phase 1

1) The individual bytes of the source code file (which is generally a text file in some multibyte encoding such as UTF-8) are mapped, in implementation defined manner, to the characters of the _source character set_. In particular, OS-dependent end-of-line indicators are replaced by newline characters. 

    The _source character set_ is a multibyte character set which includes the _basic source character set_ as a single-byte subset, consisting of the following 96 characters:

a) 5 whitespace characters (space, horizontal tab, vertical tab, form feed, new-line)

b) 10 digit characters from '0' to '9'

c) 52 letters from 'a' to 'z' and from 'A' to 'Z'

d) 29 punctuation characters: _ { } [ ] # ( ) < > % : ; . ? * + - / ^ & | ~ ! = , \ " '

2) [Trigraph sequences](operator_alternative.html "c/language/operator alternative") are replaced by corresponding single-character representations.(until C23)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/translation_phases&action=edit&section=2 "Edit section: Phase 2")] Phase 2

1) Whenever backslash appears at the end of a line (immediately followed by the newline character), both backslash and newline are deleted, combining two physical source lines into one logical source line. This is a single-pass operation: a line ending in two backslashes followed by an empty line does not combine three lines into one. 

Run this code
    
    
    #include <stdio.h>
     
    #define PUTS p\
    u\
    t\
    s
    /* Line splicing is in phase 2 while macros
     * are tokenized in phase 3 and expanded in phase 4,
     * so the above is equivalent to #define PUTS puts
     */
     
    int main(void)
    {
     /* Use line splicing to call puts */ PUT\
    S\
    ("Output ends here\\
    0Not printed" /* After line splicing, the remaining backslash
                   * escapes the 0, ending the string early.
                   */
    );
    }

2) If a non-empty source file does not end with a newline character after this step (whether it had no newline originally, or it ended with a backslash), the behavior is undefined.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/translation_phases&action=edit&section=3 "Edit section: Phase 3")] Phase 3

1) The source file is decomposed into [comment](../comment.html "c/comment"), sequences of whitespace characters (space, horizontal tab, new-line, vertical tab, and form-feed), and _preprocessing tokens_ , which are the following

a) header names: <stdio.h> or "myfile.h"

b) [identifiers](identifiers.html "c/language/identifier")

c) preprocessing numbers, which cover [integer constants](integer_constant.html "c/language/integer constant") and [floating constants](floating_constant.html "c/language/floating constant"), but also cover some invalid tokens such as 1..E+3.foo or 0JBK

d) [character constants](character_constant.html "c/language/character constant") and [string literals](string_literal.html "c/language/string literal")

e) operators and punctuators, such as +, <<=, <%, or ##.

f) individual non-whitespace characters that do not fit in any other category

2) Each comment is replaced by one space character

3) Newlines are kept, and it's implementation-defined whether non-newline whitespace sequences may be collapsed into single space characters.

If the input has been parsed into preprocessing tokens up to a given character, the next preprocessing token is generally taken to be the longest sequence of characters that could constitute a preprocessing token, even if that would cause subsequent analysis to fail. This is commonly known as _maximal munch_. 
    
    
    int foo = 1;
    // int bar = 0xE+foo; // error: invalid preprocessing number 0xE+foo
    int bar = 0xE/*Comment expands to a space*/+foo; // OK: 0xE + foo
    int baz = 0xE + foo; // OK: 0xE + foo
    int pub = bar+++baz; // OK: bar++ + baz
    int ham = bar++-++baz; // OK: bar++ - ++baz
    // int qux = bar+++++baz; // error: bar++ ++ +baz, not bar++ + ++baz
    int qux = bar+++/*Saving comment*/++baz; // OK: bar++ + ++baz

The sole exception to the maximal munch rule is: 

  * Header name preprocessing tokens are only formed within a [` #include`](../preprocessor/include.html "c/preprocessor/include") or [` #embed`](../preprocessor/embed.html "c/preprocessor/embed")(since C23) directive, in [`__has_include`](../preprocessor/include.html "c/preprocessor/include") and [`__has_embed`](../preprocessor/embed.html "c/preprocessor/embed") expressions(since C23) and in implementation-defined locations within a [` #pragma`](../preprocessor/impl.html "c/preprocessor/impl") directive. 


    
    
    #define MACRO_1 1
    #define MACRO_2 2
    #define MACRO_3 3
    #define MACRO_EXPR (MACRO_1 <MACRO_2> MACRO_3) // OK: <MACRO_2> is not a header-name

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/translation_phases&action=edit&section=4 "Edit section: Phase 4")] Phase 4

1) [Preprocessor](../preprocessor.html "c/preprocessor") is executed.

2) Each file introduced with the [#include](../preprocessor/include.html "c/preprocessor/include") directive goes through phases 1 through 4, recursively.

3) At the end of this phase, all preprocessor directives are removed from the source.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/translation_phases&action=edit&section=5 "Edit section: Phase 5")] Phase 5

1) All characters and [escape sequences](escape.html "c/language/escape") in [character constants](character_constant.html "c/language/character constant") and [string literals](string_literal.html "c/language/string literal") are converted from _source character set_ to _execution character set_ (which may be a multibyte character set such as UTF-8, as long as all 96 characters from the _basic source character set_ listed in phase 1 have single-byte representations). If the character specified by an escape sequence isn't a member of the execution character set, the result is implementation-defined, but is guaranteed to not be a null (wide) character.

Note: the conversion performed at this stage can be controlled by command line options in some implementations: gcc and clang use -finput-charset to specify the encoding of the source character set, -fexec-charset and -fwide-exec-charset to specify the encodings of the execution character set in the string literals and character constants that don't have an encoding prefix(since C11). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/translation_phases&action=edit&section=6 "Edit section: Phase 6")] Phase 6

Adjacent [string literals](string_literal.html "c/language/string literal") are concatenated. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/translation_phases&action=edit&section=7 "Edit section: Phase 7")] Phase 7

Compilation takes place: the tokens are syntactically and semantically analyzed and translated as a translation unit. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/translation_phases&action=edit&section=8 "Edit section: Phase 8")] Phase 8

Linking takes place: Translation units and library components needed to satisfy external references are collected into a program image which contains information needed for execution in its execution environment (the OS). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/translation_phases&action=edit&section=9 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 5.1.1.2 Translation phases (p: TBD) 



    

  * 5.2.1 Character sets (p: TBD) 



    

  * 6.4 Lexical elements (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 5.1.1.2 Translation phases (p: 9-10) 



    

  * 5.2.1 Character sets (p: 17) 



    

  * 6.4 Lexical elements (p: 41-54) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 5.1.1.2 Translation phases (p: 10-11) 



    

  * 5.2.1 Character sets (p: 22-24) 



    

  * 6.4 Lexical elements (p: 57-75) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 5.1.1.2 Translation phases (p: 9-10) 



    

  * 5.2.1 Character sets (p: 17-19) 



    

  * 6.4 Lexical elements (p: 49-66) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 2.1.1.2 Translation phases 



    

  * 2.2.1 Character sets 



    

  * 3.1 Lexical elements 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/translation_phases&action=edit&section=10 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/translation_phases.html "cpp/language/translation phases") for Phases of translation  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/translation_phases&oldid=160564](https://en.cppreference.com/mwiki/index.php?title=c/language/translation_phases&oldid=160564)" 

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

C source code may be written in any 8-bit character set that includes the [ISO 646:1983](https://en.wikipedia.org/wiki/ISO_646 "enwiki:ISO 646") invariant character set, even non-ASCII ones. However, several C operators and punctuators require characters that are outside of the ISO 646 codeset: `{, }, [, ], #, \, ^, |, ~`. To be able to use character encodings where some or all of these symbols do not exist (such as the German [DIN 66003](https://en.wikipedia.org/wiki/DIN_66003 "enwiki:DIN 66003")), there are two possibilities: alternative spellings of operators that use these characters or special combinations of two or three ISO 646 compatible characters that are interpreted as if they were a single non-ISO 646 character. 

## Contents

  * [1 Operator macros (C95)](operator_alternative.html#Operator_macros_.28C95.29)
  * [2 Alternative tokens (C95)](operator_alternative.html#Alternative_tokens_.28C95.29)
  * [3 Trigraphs (removed in C23)](operator_alternative.html#Trigraphs_.28removed_in_C23.29)
    * [3.1 Example](operator_alternative.html#Example)
    * [3.2 See also](operator_alternative.html#See_also)

  
---  
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_alternative&action=edit&section=1 "Edit section: Operator macros \(C95\)")] Operator macros (C95)

There are alternative spellings for the operators that use non-ISO646 characters, defined in [`<iso646.h>`](../header/iso646.html "c/header/iso646") as macros: 

Defined in header `[`<iso646.h>`](../header/iso646.html "c/header/iso646")`  
---  
Primary  |  Alternative   
`&&` |  `and`   
(operator macro)  
`&=` |  `and_eq`   
(operator macro)  
`&` |  `bitand`   
(operator macro)  
`|` |  `bitor`   
(operator macro)  
`~` |  `compl`   
(operator macro)  
`!` |  `not`   
(operator macro)  
`!=` |  `not_eq`   
(operator macro)  
`||` |  `or`   
(operator macro)  
`|=` |  `or_eq`   
(operator macro)  
`^` |  `xor`   
(operator macro)  
`^=` |  `xor_eq`   
(operator macro)  
  
The characters & and ! are invariant under ISO-646, but alternatives are provided for the operators that use these characters anyway to accommodate even more restrictive historical charsets. 

There is no alternative spelling (such as eq) for the equality operator == because the character = was present in all supported charsets. 

## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_alternative&action=edit&section=2 "Edit section: Alternative tokens \(C95\)")] Alternative tokens (C95)

The following alternative tokens are part of the core language, and, in all respects of the language, each alternative token behaves exactly the same as its primary token, except for its spelling (the [stringification operator](../preprocessor/replace.html "c/preprocessor/replace") can make the spelling visible). The two-letter alternative tokens are sometimes called "digraphs" (even though it is four letters long %:%: is also considered a digraph). 

  


Primary  |  Alternative   
---|---  
`{` | `<%`  
``} | `%>`  
`[` | `<:`  
`]` | `:>`  
`#` | `%:`  
`##` | `%:%:`  
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_alternative&action=edit&section=3 "Edit section: Trigraphs \(removed in C23\)")] Trigraphs (removed in C23)

The following three-character groups (trigraphs) are [parsed before comments and string literals are recognized](translation_phases.html "c/language/translation phases"), and each appearance of a trigraph is replaced by the corresponding primary character: 

Primary  |  Trigraph   
---|---  
`{` | `??<`  
``} | `??>`  
`[` | `??(`  
`]` | `??)`  
`#` | `??=`  
`\` | `??/`  
`^` | `??'`  
`|` | `??!`  
`~` | `??-`  
  
Because trigraphs are processed early, a comment such as // Will the next line be executed?????/ will effectively comment out the following line, and the string literal such as "What's going on??!" is parsed as "What's going on|". 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_alternative&action=edit&section=4 "Edit section: Example")] Example

Demonstrates alternative operator spellings from the [`<iso646.h>`](../header/iso646.html "c/header/iso646") as well as use of digraphs and trigraphs. If command line arguments contain spaces they should be wrapped in the quotation marks, e.g., "Third World!".

Run this code
    
    
    %:include <stdio.h>
    %:include <stdlib.h>
    ??=include <iso646.h>
     
    int main(int argc, char** argv)
    ??<
        if (argc > 1 and argv<:1:> not_eq [NULL](../types/NULL.html))
        <%
           [printf](../io/fprintf.html)("Hello %s??/n", argv<:1:>);
        %>
        else
        <%
           [printf](../io/fprintf.html)("Hello %s??/n", argc? argv??(42??'42??) : __FILE__);
        %>
     
        return EXIT_SUCCESS;
    ??>

Possible output: 
    
    
    Hello ./a.out

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_alternative&action=edit&section=5 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/operator_alternative.html "cpp/language/operator alternative") for Alternative operator representations  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/operator_alternative&oldid=180061](https://en.cppreference.com/mwiki/index.php?title=c/language/operator_alternative&oldid=180061)" 

From cppreference.com

< [c](../../c.html "c")‎ | [preprocessor](../preprocessor.html "c/preprocessor")

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

[Basic concepts](../language/basic_concepts.html "c/language/basic concepts")  
---  
[ Keywords](../keyword.html "c/keyword")  
[ Preprocessor](../preprocessor.html "c/preprocessor")  
[ Statements](../language/statements.html "c/language/statements")  
[ Expressions](../language/operators.html "c/language/expressions")  
[ Initialization](../language/initialization.html "c/language/initialization")  
[ Declarations](../language/declarations.html "c/language/declarations")  
[ Functions](../language/functions.html "c/language/functions")  
Miscellaneous  
[ History of C](../language/history.html "c/language/history")  
[Technical Specifications](../experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

[ Preprocessor](../preprocessor.html "c/preprocessor")

[#if#ifdef#ifndef#else#elif#elifdef#elifndef#endif](conditional.html "c/preprocessor/conditional")(C23)(C23)  
---  
[#define#undef#,## operators](replace.html "c/preprocessor/replace")  
[#include__has_include](include.html "c/preprocessor/include")(C23)  
[#error#warning](warning.html "c/preprocessor/error")(C23)  
[#pragma_Pragma](impl.html "c/preprocessor/impl")(C99)  
[#line](line.html "c/preprocessor/line")  
**#embed __has_embed**(C23)(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/preprocessor/navbar_content&action=edit)

#embed is a preprocessor directive to include (binary) resources in the build, where a resource is defined as a source of data accessible from the translation environment. 

## Contents

  * [1 Syntax](embed.html#Syntax)
  * [2 Explanation](embed.html#Explanation)
  * [3 Parameters](embed.html#Parameters)
    * [3.1 limit](embed.html#limit)
    * [3.2 suffix](embed.html#suffix)
    * [3.3 prefix](embed.html#prefix)
    * [3.4 if_empty](embed.html#if_empty)
  * [4 Example](embed.html#Example)
  * [5 References](embed.html#References)
  * [6 See also](embed.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/embed&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**#embed <**` h-char-sequence `**>**` embed-parameter-sequence ﻿(optional) new-line |  (1)  |   
`**#embed "**` q-char-sequence `**"**` embed-parameter-sequence ﻿(optional) new-line |  (2)  |   
`**#embed**` pp-tokens new-line |  (3)  |   
`**__has_embed**` `**(**` `**"**` q-char-sequence `**"**` embed-parameter-sequence ﻿(optional) `**)**`  
`**__has_embed**` `**(**` `**<**` h-char-sequence `**>**` embed-parameter-sequence ﻿(optional) `**)**` |  (4)  |   
`**__has_embed**` `**(**` string-literal pp-balanced-token-sequence ﻿(optional) `**)**`  
`**__has_embed**` `**(**` `**<**` h-pp-tokens `**>**` pp-balanced-token-sequence ﻿(optional) `**)**` |  (5)  |   
  
1) Searches for a resource identified uniquely by h-char-sequence and replaces the directive by a comma separated list of integers corresponding to the data of the resource.

2) Searches for a resource identified by q-char-sequence and replaces the directive by a list of integers corresponding to the data of the resource. It may fallback to (1).

3) If neither (1) nor (2) is matched, pp-tokens will undergo macro replacement. The directive after replacement will be tried to match with (1) or (2) again.

4) Checks whether a resource is available for embedding, whether it is empty or not and whether the parameters passed are supported by the implementation.

5) If (4) is not matched, h-pp-tokens and pp-balanced-token-sequence will undergo macro replacement. The directive after replacement will be tried to match with (4) again.

new-line |  \-  |  The new-line character   
---|---|---  
h-char-sequence |  \-  |  A sequence of one or more h-chars, where the appearance of any of the following causes undefined behavior: 

  * the character '
  * the character "
  * the character \
  * the character sequence //
  * the character sequence /*

  
h-char |  \-  |  Any member of the [source character set](../language/translation_phases.html#Phase_5 "c/language/translation phases") except new-line and >  
q-char-sequence |  \-  |  A sequence of one or more q-chars, where the appearance of any of the following causes undefined behavior: 

  * the character '
  * the character \
  * the character sequence //
  * the character sequence /*

  
q-char |  \-  |  Any member of the [source character set](../language/translation_phases.html#Phase_5 "c/language/translation phases") except new-line and "  
pp-tokens |  \-  |  A sequence of one or more [preprocessing tokens](../language/translation_phases.html#Phase_3 "c/language/translation phases")  
string-literal |  \-  |  A [string literal](../language/string_literal.html "c/language/string literal")  
h-pp-tokens |  \-  |  A sequence of one or more [preprocessing tokens](../language/translation_phases.html#Phase_3 "c/language/translation phases") except >  
embed-parameter-sequence |  \-  |  A sequence of one or more pp-parameter ﻿s. Note that unlike an attribute-list, this sequence is not comma separated.   
pp-parameter |  \-  |  An attribute-token (see: [attributes](../language/attributes.html "c/language/attributes")) but comprised of preprocessing tokens instead of tokens.   
pp-balanced-token-sequence |  \-  |  A balanced-token-sequence (see: [attributes](../language/attributes.html "c/language/attributes")) but comprised of preprocessing tokens instead of tokens   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/embed&action=edit&section=2 "Edit section: Explanation")] Explanation

1) Searches for the resource identified by h-char-sequence in implementation-defined manner.

2) Searches for the resource identified by q-char-sequence in implementation-defined manner. For (1,2), the implementations typically use a mechanism similar to, but distinct from, the implementation-defined search paths used for [source file inclusion](include.html "c/preprocessor/include"). The construct __has_embed(__FILE__ ... appears in one of the examples in the standard, suggesting, in case (2) at least, that the directory where the current file resides is expected to be searched.

3) The preprocessing tokens after `**embed**` in the directive are processed just as in normal text (i.e., each identifier currently defined as a macro name is replaced by its replacement list of preprocessing tokens). The directive resulting after all replacements shall match one of the two previous forms. The method by which a sequence of preprocessing tokens between < and > preprocessing token pair or a pair of " characters is combined into a single header name preprocessing token is implementation-defined.

4) The resource identified by h-char-sequence or q-char-sequence is searched for as if that preprocessing token sequence were the pp-tokens in syntax (3), except that no further macro expansion is performed. If such a directive would not satisfy the syntactic requirements of an #embed directive, the program is ill-formed. The __has_embed expression evaluates to __STDC_EMBED_FOUND__ if the search for the resource succeeds, the resource is non empty and all the parameters are supported, to __STDC_EMBED_EMPTY__ if the resource is empty and all the parameters are supported, and to __STDC_EMBED_NOT_FOUND__ if the search fails or one of the parameters passed is not supported by the implementation.

5) This form is considered only if syntax (4) does not match, in which case the preprocessing tokens are processed just as in normal text.

In the case the resource is not found or one of the parameters is not supported by the implementation, the program is ill-formed. 

__has_embed can be expanded in the expression of [` #if`](conditional.html "c/preprocessor/conditional") and [` #elif`](conditional.html "c/preprocessor/conditional"). It is treated as a defined macro by [` #ifdef`](conditional.html "c/preprocessor/conditional"), [` #ifndef`](conditional.html "c/preprocessor/conditional"), [` #elifdef`](conditional.html "c/preprocessor/conditional"), [` #elifndef`](conditional.html "c/preprocessor/conditional") and [`defined`](conditional.html "c/preprocessor/conditional") but cannot be used anywhere else. 

A resource has an _implementation resource width_ which is the implementation-defined size in bits of the located resource. Its _resource width_ is the implementation resource width unless modified by a `limit` parameter. If the resource width is 0, the resource is considered empty. The _embed element width_ is equal to [CHAR_BIT](../types/limits.html) unless modified by an implementation defined parameter. The resource width must be divisible by the embed element width. 

The expansion of a `#embed` directive is a token sequence formed from the list of integer [constant expressions](../language/constant_expression.html "c/language/constant expression") described below. The group of tokens for each integer constant expression in the list is separated in the token sequence from the group of tokens for the previous integer constant expression in the list by a comma. The sequence neither begins nor ends in a comma. If the list of integer constant expressions is empty, the token sequence is empty. The directive is replaced by its expansion and, with the presence of certain embed parameters, additional or replacement token sequences. 

The values of the integer constant expressions in the expanded sequence are determined by an implementation-defined mapping of the resource’s data. Each integer constant expression’s value is in the range `[`0`, `2embed element width`)`. If: 

  1. The list of integer constant expressions is used to initialize an array of a type compatible with unsigned char, or compatible with char if char cannot hold negative values, and 
  2. The embed element width is equal to [CHAR_BIT](../types/limits.html), 



then the contents of the initialized elements of the array are as-if the resource’s binary data is [fread](../io/fread.html "c/io/fread") into the array at translation time. 

Implementations are encouraged to take into account translation-time bit and byte orders as well as execution-time bit and byte orders to more appropriately represent the resource’s binary data from the directive. This maximizes the chance that, if the resource referenced at translation time through the #embed directive is the same one accessed through execution-time means, the data that is e.g. [fread](../io/fread.html "c/io/fread") or similar into contiguous storage will compare bit-for-bit equal to an array of character type initialized from an #embed directive’s expanded contents. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/embed&action=edit&section=3 "Edit section: Parameters")] Parameters

The standard defines the parameters `limit`, `prefix`, `suffix` and `if_empty`. Any other parameter that appears in the directive must be implementation-defined, or the program is ill-formed. Implementation-defined embed parameters may change the semantics of the directive. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/embed&action=edit&section=4 "Edit section: limit")] limit  
  
---  
`**limit(**` constant-expression `**)**` |  (1)  |   
`**__limit__(**` constant-expression `**)**` |  (2)  |   
  
The `limit` embed parameter can appear at most once in the embed parameter sequence. It must have an argument, which must be an integer (preprocessor) [constant expression](../language/constant_expression.html "c/language/constant expression") that evaluates to a non negative number and does not contain the token defined. The resource width is set to the minimum of the integer constant expression multiplied by the embed element width and the implementation resource width. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/embed&action=edit&section=5 "Edit section: suffix")] suffix  
  
---  
`**suffix(**` pp-balanced-token-sequence ﻿(optional) `**)**` |  (1)  |   
`**__suffix__(**` pp-balanced-token-sequence ﻿(optional) `**)**` |  (2)  |   
  
The `suffix` embed parameter can appear at most once in the embed parameter sequence. It must have a (possibly empty) preprocessor argument clause. If the resource is non empty, the contents of the parameter clause are placed immediately after the expansion of the directive. Otherwise, it has no effect. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/embed&action=edit&section=6 "Edit section: prefix")] prefix  
  
---  
`**prefix(**` pp-balanced-token-sequence ﻿(optional) `**)**` |  (1)  |   
`**__prefix__(**` pp-balanced-token-sequence ﻿(optional) `**)**` |  (2)  |   
  
The `prefix` embed parameter can appear at most once in the embed parameter sequence. It must have a (possibly empty) preprocessor argument clause. If the resource is non empty, the contents of the parameter clause are placed immediately before the expansion of the directive. Otherwise, it has no effect. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/embed&action=edit&section=7 "Edit section: if empty")] if_empty  
  
---  
`**if_empty(**` pp-balanced-token-sequence ﻿(optional) `**)**` |  (1)  |   
`**__if_empty__(**` pp-balanced-token-sequence ﻿(optional) `**)**` |  (2)  |   
  
The `if_empty` embed parameter can appear at most once in the embed parameter sequence. It must have a (possibly empty) preprocessor argument clause. If the resource is empty, the contents of the parameter clause replace the directive. Otherwise, it has no effect. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/embed&action=edit&section=8 "Edit section: Example")] Example

Run this code
    
    
    #include <stdint.h>
    #include <stdio.h>
     
    const [uint8_t](../types/integer.html) image_data[] =
    {
    #embed "image.png"
    };
     
    const char message[] =
    {
    #embed "message.txt" if_empty('M', 'i', 's', 's', 'i', 'n', 'g', '\n')
    ,'\0' // null terminator
    };
     
    void dump(const [uint8_t](../types/integer.html) arr[], [size_t](../types/size_t.html) size)
    {
        for ([size_t](../types/size_t.html) i = 0; i != size; ++i)
            [printf](../io/fprintf.html)("%02X%c", arr[i], (i + 1) % 16 ? ' ' : '\n');
        [puts](../io/puts.html)("");
    }
     
    int main()
    {
        [puts](../io/puts.html)("image_data[]:");
        dump(image_data, sizeof image_data);
        [puts](../io/puts.html)("message[]:");
        dump((const [uint8_t](../types/integer.html)*)message, sizeof message);
    }

Possible output: 
    
    
    image_data[]:
    89 50 4E 47 0D 0A 1A 0A 00 00 00 0D 49 48 44 52
    00 00 00 01 00 00 00 01 01 03 00 00 00 25 DB 56
    ...
    message[]:
    4D 69 73 73 69 6E 67 0A 00

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/embed&action=edit&section=9 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.4.7 Header names (p: 69) 



    

  * 6.10.1 Conditional inclusion (p: 165-169) 



    

  * 6.10.2 Binary resource inclusion (p: 170-177) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/embed&action=edit&section=10 "Edit section: See also")] See also

[C++ documentation](../../cpp/preprocessor/embed.html "cpp/preprocessor/embed") for Resource inclusion (since C++26)  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/embed&oldid=182215](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/embed&oldid=182215)" 

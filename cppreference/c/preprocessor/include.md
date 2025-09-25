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
**#include __has_include**(C23)  
[#error#warning](warning.html "c/preprocessor/error")(C23)  
[#pragma_Pragma](impl.html "c/preprocessor/impl")(C99)  
[#line](line.html "c/preprocessor/line")  
[#embed__has_embed](embed.html "c/preprocessor/embed")(C23)(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/preprocessor/navbar_content&action=edit)

Includes another source file into the current source file at the line immediately after the directive. 

## Contents

  * [1 Syntax](include.html#Syntax)
  * [2 Explanation](include.html#Explanation)
  * [3 Notes](include.html#Notes)
  * [4 Example](include.html#Example)
  * [5 References](include.html#References)
  * [6 See also](include.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/include&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**#include <**` h-char-sequence `**>**` new-line |  (1)  |   
`**#include "**` q-char-sequence `**"**` new-line |  (2)  |   
`**#include**` pp-tokens new-line |  (3)  |   
`**__has_include**` `**(**` `**"**` q-char-sequence `**"**` `**)**`  
`**__has_include**` `**(**` `**<**` h-char-sequence `**>**` `**)**` |  (4)  |  (since C23)  
`**__has_include**` `**(**` string-literal `**)**`  
`**__has_include**` `**(**` `**<**` h-pp-tokens `**>**` `**)**` |  (5)  |  (since C23)  
  
1) Searches for a header identified uniquely by h-char-sequence and replaces the directive by the entire contents of the header.

2) Searches for a source file identified by q-char-sequence and replaces the directive by the entire contents of the source file. It may fallback to (1) and treat q-char-sequence as a header identifier.

3) If neither (1) nor (2) is matched, pp-tokens will undergo macro replacement. The directive after replacement will be tried to match with (1) or (2) again.

4) Checks whether a header or source file is available for inclusion.

5) If (4) is not matched, h-pp-tokens will undergo macro replacement. The directive after replacement will be tried to match with (4) again.

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
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/include&action=edit&section=2 "Edit section: Explanation")] Explanation

1) Searches for the file identified by h-char-sequence in implementation-defined manner. The intent of this syntax is to search for the files under control of the implementation. Typical implementations search only standard include directories. The standard C library is implicitly included in these standard include directories. The standard include directories usually can be controlled by the user through compiler options.

2) Searches for the file identified by q-char-sequence in implementation-defined manner. The intent of this syntax is to search for the files that are not controlled by the implementation. Typical implementations first search the directory where the current file resides and, only if the file is not found, search the standard include directories as with (1).

3) The preprocessing tokens after `**include**` in the directive are processed just as in normal text (i.e., each identifier currently defined as a macro name is replaced by its replacement list of preprocessing tokens). The directive resulting after all replacements shall match one of the two previous forms. The method by which a sequence of preprocessing tokens between < and > preprocessing token pair or a pair of " characters is combined into a single header name preprocessing token is implementation-defined.

4) The header or source file identified by h-char-sequence or q-char-sequence is searched for as if that preprocessing token sequence were the pp-tokens in syntax (3), except that no further macro expansion is performed. If such a directive would not satisfy the syntactic requirements of an #include directive, the program is ill-formed. The `__has_include` expression evaluates to 1 if the search for the source file succeeds, and to ​0​ if the search fails.

5) This form is considered only if syntax (4) does not match, in which case the preprocessing tokens are processed just as in normal text.

In the case the file is not found, the program is ill-formed. 

`__has_include` can be expanded in the expression of [` #if`](conditional.html "c/preprocessor/conditional") and [` #elif`](conditional.html "c/preprocessor/conditional"). It is treated as a defined macro by [` #ifdef`](conditional.html "c/preprocessor/conditional"), [` #ifndef`](conditional.html "c/preprocessor/conditional"), [` #elifdef`](conditional.html "c/preprocessor/conditional"), [` #elifndef`](conditional.html "c/preprocessor/conditional") and [`defined`](conditional.html "c/preprocessor/conditional") but cannot be used anywhere else.  | (since C23)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/include&action=edit&section=3 "Edit section: Notes")] Notes

Typical implementations search only standard include directories for syntax (1). The standard C library is implicitly included in these standard include directories. The standard include directories usually can be controlled by the user through compiler options. 

The intent of syntax (2) is to search for the files that are not controlled by the implementation. Typical implementations first search the directory where the current file resides then falls back to (1). 

When a file is included, it is processed by [translation phases](../language/translation_phases.html "c/language/translation phases") 1-4, which may include, recursively, expansion of the nested `#include` directives, up to an implementation-defined nesting limit. To avoid repeated inclusion of the same file and endless recursion when a file includes itself, perhaps transitively, _header guards_ are commonly used: the entire header is wrapped in 
    
    
    #ifndef FOO_H_INCLUDED /* any name uniquely mapped to file name */
    #define FOO_H_INCLUDED
    // contents of the file are here
    #endif

Many compilers also implement the non-standard [`pragma`](impl.html "c/preprocessor/impl") #pragma once with similar effects: it disables processing of a file if the same file (where file identity is determined in OS-specific way) has already been included. 

A `__has_include` result of 1 only means that a header or source file with the specified name exists. It does not mean that the header or source file, when included, would not cause an error or would contain anything useful. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/include&action=edit&section=4 "Edit section: Example")] Example

| This section is incomplete  
Reason: no example   
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/include&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.4.7 Header names (p: 69) 



    

  * 6.10.1 Conditional inclusion (p: 165-169) 



    

  * 6.10.2 Source file inclusion (p: 169-170) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.10.2 Source file inclusion (p: 119-120) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.10.2 Source file inclusion (p: 164-166) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.10.2 Source file inclusion (p: 149-151) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.8.2 Source file inclusion 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/include&action=edit&section=6 "Edit section: See also")] See also

[A list of C Standard Library header files](../header.html "c/header")  
---  
[C++ documentation](../../cpp/preprocessor/include.html "cpp/preprocessor/include") for Source file inclusion  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/include&oldid=159893](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/include&oldid=159893)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo no example](../../Category%253ATodo_no_example.html "Category:Todo no example")



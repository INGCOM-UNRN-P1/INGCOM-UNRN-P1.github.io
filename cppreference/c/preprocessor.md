From cppreference.com

< [c](../c.html "c")

[ C](../c.html "c")

[Compiler support](compiler_support.html "c/compiler support")  
---  
[Language](language.html "c/language")  
[Headers](header.html "c/header")  
[Type support](types.html "c/types")  
[Program utilities](program.html "c/program")  
[Variadic function support](variadic.html "c/variadic")  
[Error handling](error.html "c/error")  
[Dynamic memory management](memory.html "c/memory")  
[Strings library](string.html "c/string")  
[Algorithms](algorithm.html "c/algorithm")  
[Numerics](numeric.html "c/numeric")  
[Date and time utilities](chrono.html "c/chrono")  
[Input/output support](io.html "c/io")  
[Localization support](locale.html "c/locale")  
[Concurrency support](thread.html "c/thread") (C11)  
[Technical Specifications](experimental.html "c/experimental")  
[Symbol index](index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

[ C language](language.html "c/language")

[Basic concepts](language/basic_concepts.html "c/language/basic concepts")  
---  
[ Keywords](keyword.html "c/keyword")  
**Preprocessor**  
[ Statements](language/statements.html "c/language/statements")  
[ Expressions](language/operators.html "c/language/expressions")  
[ Initialization](language/initialization.html "c/language/initialization")  
[ Declarations](language/declarations.html "c/language/declarations")  
[ Functions](language/functions.html "c/language/functions")  
Miscellaneous  
[ History of C](language/history.html "c/language/history")  
[Technical Specifications](experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

**Preprocessor**

[#if#ifdef#ifndef#else#elif#elifdef#elifndef#endif](preprocessor/conditional.html "c/preprocessor/conditional")(C23)(C23)  
---  
[#define#undef#,## operators](preprocessor/replace.html "c/preprocessor/replace")  
[#include__has_include](preprocessor/include.html "c/preprocessor/include")(C23)  
[#error#warning](preprocessor/warning.html "c/preprocessor/error")(C23)  
[#pragma_Pragma](preprocessor/impl.html "c/preprocessor/impl")(C99)  
[#line](preprocessor/line.html "c/preprocessor/line")  
[#embed__has_embed](preprocessor/embed.html "c/preprocessor/embed")(C23)(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/preprocessor/navbar_content&action=edit)

The preprocessor is executed at [translation phase 4](language/translation_phases.html#Phase_4 "c/language/translation phases"), before the compilation. The result of preprocessing is a single file which is then passed to the actual compiler. 

## Contents

  * [1 Directives](preprocessor.html#Directives)
  * [2 Capabilities](preprocessor.html#Capabilities)
  * [3 Footnotes](preprocessor.html#Footnotes)
  * [4 Example](preprocessor.html#Example)
  * [5 References](preprocessor.html#References)
  * [6 See also](preprocessor.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor&action=edit&section=1 "Edit section: Directives")] Directives

The preprocessing directives control the behavior of the preprocessor. Each directive occupies one line and has the following format: 

  * `#` character 
  * preprocessing instruction (one of `define`, `undef`, `include`, `if`, `ifdef`, `ifndef`, `else`, `elif`, `elifdef`, `elifndef`(since C23), `endif`, `line`, `embed`(since C23), `error`, `warning`(since C23), `pragma`) [[1]](preprocessor.html#cite_note-1)
  * arguments (depends on the instruction) 
  * line break. 



The null directive (`#` followed by a line break) is allowed and has no effect. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor&action=edit&section=2 "Edit section: Capabilities")] Capabilities

The preprocessor has the source file translation capabilities: 

  * **[conditionally](preprocessor/conditional.html "c/preprocessor/conditional")** compile of parts of source file (controlled by directive `#if`, `#ifdef`, `#ifndef`, `#else`, `#elif`, `#elifdef`, `#elifndef`(since C23) and `#endif`). 
  * **[replace](preprocessor/replace.html "c/preprocessor/replace")** text macros while possibly concatenating or quoting identifiers (controlled by directives `#define` and `#undef`, and operators `#` and `##`) 
  * **[include](preprocessor/include.html "c/preprocessor/include")** other files (controlled by directive `#include` and checked with `__has_include`(since C23)) 
  * cause an **[error](preprocessor/warning.html "c/preprocessor/error")** or **[warning](preprocessor/warning.html "c/preprocessor/error")**(since C23) (controlled by directive `#error` or `#warning` respectively(since C23)) 



The following aspects of the preprocessor can be controlled: 

  * **[implementation defined](preprocessor/impl.html "c/preprocessor/impl")** behavior (controlled by directive `#pragma` and operator `_Pragma`(since C99)) 
  * **[file name and line information](preprocessor/line.html "c/preprocessor/line")** available to the preprocessor (controlled by directives `#line`) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor&action=edit&section=3 "Edit section: Footnotes")] Footnotes

  1. [↑](preprocessor.html#cite_ref-1) These are the directives defined by the standard. The standard does not define behavior for other directives: they might be ignored, have some useful meaning, or make the program ill-formed. Even if otherwise ignored, they are removed from the source code when the preprocessor is done. A common non-standard extension is the directive [#warning](preprocessor/warning.html "c/preprocessor/error") which emits a user-defined message during compilation.(until C23)



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor&action=edit&section=4 "Edit section: Example")] Example

| This section is incomplete  
Reason: no example   
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.10 Preprocessing directives (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.10 Preprocessing directives (p: 117-129) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.10 Preprocessing directives (p: 160-178) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.10 Preprocessing directives (p: 145-162) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.8 Preprocessing directives 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor&action=edit&section=6 "Edit section: See also")] See also

[C documentation](preprocessor/replace.html#Predefined_macros "c/preprocessor/replace") for Predefined Macro Symbols  
---  
[C documentation](symbol_index/macro.html "c/symbol index/macro") for Macro Symbol Index  
[C++ documentation](../cpp/preprocessor.html "cpp/preprocessor") for Preprocessor  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/preprocessor&oldid=179530](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor&oldid=179530)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo no example](../Category%253ATodo_no_example.html "Category:Todo no example")



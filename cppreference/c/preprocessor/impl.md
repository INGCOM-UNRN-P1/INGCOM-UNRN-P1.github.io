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
**#pragma _Pragma**(C99)  
[#line](line.html "c/preprocessor/line")  
[#embed__has_embed](embed.html "c/preprocessor/embed")(C23)(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/preprocessor/navbar_content&action=edit)

Implementation defined behavior is controlled by `#pragma` directive. 

## Contents

  * [1 Syntax](impl.html#Syntax)
  * [2 Explanation](impl.html#Explanation)
  * [3 Standard pragmas](impl.html#Standard_pragmas)
  * [4 Non-standard pragmas](impl.html#Non-standard_pragmas)
    * [4.1 #pragma once](impl.html#.23pragma_once)
    * [4.2 #pragma pack](impl.html#.23pragma_pack)
  * [5 References](impl.html#References)
  * [6 See also](impl.html#See_also)
  * [7 External links](impl.html#External_links)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/impl&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**#pragma**` pragma_params |  (1)  |   
`**_Pragma**` `**(**` string-literal `**)**` |  (2)  |  (since C99)  
  
1) Behaves in an implementation-defined manner (unless pragma_params is one of the standard pragmas shown below).

2) Removes the encoding prefix (if any), the outer quotes, and leading/trailing whitespace from string-literal, replaces each `\"` with `"` and each `\\` with `\`, then tokenizes the result (as in [translation stage 3](../language/translation_phases.html "c/language/translation phases")), and then uses the result as if the input to `#pragma` in (1).

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/impl&action=edit&section=2 "Edit section: Explanation")] Explanation

The pragma directive controls implementation-specific behavior of the compiler, such as disabling compiler warnings or changing alignment requirements. Any pragma that is not recognized is ignored. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/impl&action=edit&section=3 "Edit section: Standard pragmas")] Standard pragmas

The following three pragmas are defined by the language standard:   
  
---  
`**#pragma STDC FENV_ACCESS**` arg |  (1)  |  (since C99)  
`**#pragma STDC FP_CONTRACT**` arg |  (2)  |  (since C99)  
`**#pragma STDC CX_LIMITED_RANGE**` arg |  (3)  |  (since C99)  
  
where arg is either `**ON**` or `**OFF**` or `**DEFAULT**`. 

1) If set to `**ON**`, informs the compiler that the program will access or modify [floating-point environment](../numeric/fenv.html "c/numeric/fenv"), which means that optimizations that could subvert flag tests and mode changes (e.g., global common subexpression elimination, code motion, and constant folding) are prohibited. The default value is implementation-defined, usually `**OFF**`.

2) Allows _contracting_ of floating-point expressions, that is optimizations that omit rounding errors and floating-point exceptions that would be observed if the expression was evaluated exactly as written. For example, allows the implementation of (x * y) + z with a single fused multiply-add CPU instruction. The default value is implementation-defined, usually `**ON**`.

3) Informs the compiler that multiplication, division, and absolute value of complex numbers may use simplified mathematical formulas (x+iy)×(u+iv) = (xu-yv)+i(yu+xv), (x+iy)/(u+iv) = [(xu+yv)+i(yu-xv)]/(u2  
+v2  
), and |x+iy| = √x2  
+y2  
, despite the possibility of intermediate overflow. In other words, the programmer guarantees that the range of the values that will be passed to those function is limited. The default value is `**OFF**`.

Note: compilers that do not support these pragmas may provide equivalent compile-time options, such as gcc's `-fcx-limited-range` and `-ffp-contract`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/impl&action=edit&section=4 "Edit section: Non-standard pragmas")] Non-standard pragmas

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/impl&action=edit&section=5 "Edit section: #pragma once")] #pragma once

#pragma once is a non-standard pragma that is supported by the [vast majority of modern compilers](https://en.wikipedia.org/wiki/Pragma_once#Portability "enwiki:Pragma once"). If it appears in a header file, it indicates that it is only to be parsed once, even if it is (directly or indirectly) included multiple times in the same source file. 

Standard approach to preventing multiple inclusion of the same header is by using [include guards](https://en.wikipedia.org/wiki/Include_guard "enwiki:Include guard"): 
    
    
    #ifndef LIBRARY_FILENAME_H
    #define LIBRARY_FILENAME_H
    // contents of the header
    #endif /* LIBRARY_FILENAME_H */

So that all but the first inclusion of the header in any translation unit are excluded from compilation. All modern compilers record the fact that a header file uses an include guard and do not re-parse the file if it is encountered again, as long as the guard is still defined (see e.g. [gcc](https://gcc.gnu.org/onlinedocs/cpp/Once-Only-Headers.html)). 

With #pragma once, the same header appears as 
    
    
    #pragma once
    // contents of the header

Unlike header guards, this pragma makes it impossible to erroneously use the same macro name in more than one file. On the other hand, since with #pragma once files are excluded based on their filesystem-level identity, this can't protect against including a header twice if it exists in more than one location in a project. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/impl&action=edit&section=6 "Edit section: #pragma pack")] #pragma pack

This family of pragmas control the maximum alignment for subsequently defined structure and union members.   
  
---  
`**#pragma pack( arg) **` |  (1)  |   
`**#pragma pack()**` |  (2)  |   
`**#pragma pack(push)**` |  (3)  |   
`**#pragma pack(push, arg) **` |  (4)  |   
`**#pragma pack(pop)**` |  (5)  |   
  
where arg is a small power of two and specifies the new alignment in bytes. 

1) Sets the current alignment to value arg.

2) Sets the current alignment to the default value (specified by a command-line option).

3) Pushes the value of the current alignment on an internal stack.

4) Pushes the value of the current alignment on the internal stack and then sets the current alignment to value arg.

5) Pops the top entry from the internal stack and then sets (restores) the current alignment to that value.

#pragma pack may decrease the alignment of a structure, however, it cannot make a structure overaligned. 

See also specific details for [GCC](https://gcc.gnu.org/onlinedocs/gcc/Structure-Layout-Pragmas.html) and [MSVC](https://docs.microsoft.com/en-us/cpp/preprocessor/pack). 

| This section is incomplete  
Reason: Explain the effects of this pragmas on data members and also the pros and cons of using them. Sources for reference: 

  * [Stack Overflow](https://stackoverflow.com/questions/3318410/pragma-pack-effect)

  
---|---  
| This section is incomplete  
Reason: no example   
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/impl&action=edit&section=7 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.10.6 Pragma directive (p: TBD) 



    

  * 6.10.9 Pragma operator (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.10.6 Pragma directive (p: 127) 



    

  * 6.10.9 Pragma operator (p: 129) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.10.6 Pragma directive (p: 174) 



    

  * 6.10.9 Pragma operator (p: 178) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.10.6 Pragma directive (p: 159) 



    

  * 6.10.9 Pragma operator (p: 161-162) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.8.6 Pragma directive 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/impl&action=edit&section=8 "Edit section: See also")] See also

[C++ documentation](../../cpp/preprocessor/impl.html "cpp/preprocessor/impl") for Implementation defined behavior control  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/impl&action=edit&section=9 "Edit section: External links")] External links

1\.  | [C++ pragmas in Visual Studio](https://docs.microsoft.com/en-us/cpp/preprocessor/pragma-directives-and-the-pragma-keyword)  
---|---  
2\.  | [Pragmas](https://gcc.gnu.org/onlinedocs/gcc/Pragmas.html) accepted by GCC   
3\.  | [Individual pragma descriptions](https://www.ibm.com/support/knowledgecenter/en/SSGH3R_16.1.0/com.ibm.xlcpp161.aix.doc/compiler_ref/pragma_descriptions.html) and [Standard pragmas](https://www.ibm.com/support/knowledgecenter/en/SSGH3R_16.1.0/com.ibm.xlcpp161.aix.doc/language_ref/std_pragmas.html) in IBM AIX XL C 16.1   
4\.  | [Appendix B. Pragmas](http://download.oracle.com/docs/cd/E19422-01/819-3690/Pragmas_App.html#73499) in Sun Studio 11 C++ User's Guide   
5\.  | [Intel C++ compiler pragmas](https://software.intel.com/content/www/us/en/develop/documentation/cpp-compiler-developer-guide-and-reference/top/compiler-reference/pragmas.html)  
6\.  | [HP aCC compiler pragmas](http://h21007.www2.hp.com/portal/download/files/unprot/aCxx/Online_Help/pragmas.htm)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/impl&oldid=182854](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/impl&oldid=182854)" 

[Categories](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")
  * [Todo no example](../../Category%253ATodo_no_example.html "Category:Todo no example")



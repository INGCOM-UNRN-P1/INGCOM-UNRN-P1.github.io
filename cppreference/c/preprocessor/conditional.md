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

**#if #ifdef#ifndef#else#elif#elifdef#elifndef#endif**(C23)(C23)  
---  
[#define#undef#,## operators](replace.html "c/preprocessor/replace")  
[#include__has_include](include.html "c/preprocessor/include")(C23)  
[#error#warning](warning.html "c/preprocessor/error")(C23)  
[#pragma_Pragma](impl.html "c/preprocessor/impl")(C99)  
[#line](line.html "c/preprocessor/line")  
[#embed__has_embed](embed.html "c/preprocessor/embed")(C23)(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/preprocessor/navbar_content&action=edit)

The preprocessor supports conditional compilation of parts of source file. This behavior is controlled by `#if`, `#else`, `#elif`, `#ifdef`, `#ifndef`, `#elifdef`, `#elifndef`(since C23), and `#endif` directives. 

## Contents

  * [1 Syntax](conditional.html#Syntax)
  * [2 Explanation](conditional.html#Explanation)
  * [3 Conditional evaluation](conditional.html#Conditional_evaluation)
    * [3.1 #if, #elif](conditional.html#.23if.2C_.23elif)
    * [3.2 Combined directives](conditional.html#Combined_directives)
  * [4 Notes](conditional.html#Notes)
  * [5 Example](conditional.html#Example)
  * [6 Defect reports](conditional.html#Defect_reports)
  * [7 References](conditional.html#References)
  * [8 See also](conditional.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/conditional&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**#if**` expression |  |   
`**#ifdef**` identifier |  |   
`**#ifndef**` identifier |  |   
`**#elif**` expression |  |   
`**#elifdef**` identifier |  |  (since C23)  
`**#elifndef**` identifier |  |  (since C23)  
`**#else**` |  |   
`**#endif**` |  |   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/conditional&action=edit&section=2 "Edit section: Explanation")] Explanation

The conditional preprocessing block starts with `#if`, `#ifdef` or `#ifndef` directive, then optionally includes any number of `#elif`, `#elifdef`, or `#elifndef`(since C23) directives, then optionally includes at most one `#else` directive and is terminated with `#endif` directive. Any inner conditional preprocessing blocks are processed separately. 

Each of `#if`, `#ifdef`, `#ifndef`, `#elif`, `#elifdef`, `#elifndef`(since C23), and `#else` directives control code block until first `#elif`, `#elifdef`, `#elifndef`(since C23), `#else`, `#endif` directive not belonging to any inner conditional preprocessing blocks. 

`#if`, `#ifdef` and `#ifndef` directives test the specified condition (see below) and if it evaluates to true, compiles the controlled code block. In that case subsequent `#else`, `#elifdef`, `#elifndef`,(since C23) and `#elif` directives are ignored. Otherwise, if the specified condition evaluates false, the controlled code block is skipped and the subsequent `#else`, `#elifdef`, `#elifndef`,(since C23) or `#elif` directive (if any) is processed. If the subsequent directive is `#else`, the code block controlled by the `#else` directive is unconditionally compiled. Otherwise, the `#elif`, `#elifdef`, or `#elifndef`(since C23) directive acts as if it was `#if` directive: checks for condition, compiles or skips the controlled code block based on the result, and in the latter case processes subsequent `#elif`, `#elifdef`, `#elifndef`,(since C23) and `#else` directives. The conditional preprocessing block is terminated by `#endif` directive. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/conditional&action=edit&section=3 "Edit section: Conditional evaluation")] Conditional evaluation

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/conditional&action=edit&section=4 "Edit section: #if, #elif")] #if, #elif

The expression is a constant expression, using only [constants](../language/operators.html#Constants_and_literals "c/language/expressions") and identifiers, defined using [` #define`](replace.html "c/preprocessor/replace") directive. Any identifier, which is not literal, non defined using [` #define`](replace.html "c/preprocessor/replace") directive, evaluates to ​0​ except true which evaluates to 1(since C23). 

The expression may contain unary operators in form `defined` identifier or `defined (`identifier`)` which return 1 if the identifier was defined using [` #define`](replace.html "c/preprocessor/replace") directive and ​0​ otherwise. In this context, __has_include, __has_embed and __has_c_attribute are treated as if they were the name of defined macros.(since C23) If the expression evaluates to nonzero value, the controlled code block is included and skipped otherwise. If any used identifier is not a constant, it is replaced with ​0​. 

In context of a preprocessor directive, a `__has_c_attribute` expression detects whether a given attribute token is supported and its supported version. See [Attribute testing](../language/attributes.html#Attribute_testing "c/language/attributes").  | (since C23)  
---|---  
  
Note: Until [DR 412](https://open-std.org/JTC1/SC22/WG14/www/docs/dr_412.htm), `#if _cond1_` ... `#elif _cond2_` is different from `#if _cond1_` ... `#else` followed by `#if _cond3_` because if `_cond1_` is true, the second `#if` is skipped and `_cond3_` does not need to be well-formed, while `#elif`'s `_cond2_` must be a valid expression. As of [DR 412](https://open-std.org/JTC1/SC22/WG14/www/docs/dr_412.htm), `#elif` that leads the skipped code block is also skipped. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/conditional&action=edit&section=5 "Edit section: Combined directives")] Combined directives

Checks if the identifier was [defined as a macro name](replace.html "c/preprocessor/replace"). 

`#ifdef` identifier is essentially equivalent to `#if defined` identifier. 

`#ifndef` identifier is essentially equivalent to `#if !defined` identifier. 

`#elifdef` identifier is essentially equivalent to `#elif defined` identifier. `#elifndef` identifier is essentially equivalent to `#elif !defined` identifier.  | (since C23)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/conditional&action=edit&section=6 "Edit section: Notes")] Notes

While `#elifdef` and `#elifndef` directives target C23, implementations may backport them to the older language modes as conforming extensions. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/conditional&action=edit&section=7 "Edit section: Example")] Example

Run this code
    
    
    #define ABCD 2
    #include <stdio.h>
     
    int main(void)
    {
     
    #ifdef ABCD
        [printf](../io/fprintf.html)("1: yes\n");
    #else
        [printf](../io/fprintf.html)("1: no\n");
    #endif
     
    #ifndef ABCD
        [printf](../io/fprintf.html)("2: no1\n");
    #elif ABCD == 2
        [printf](../io/fprintf.html)("2: yes\n");
    #else
        [printf](../io/fprintf.html)("2: no2\n");
    #endif
     
    #if !defined(DCBA) && (ABCD < 2 * 4 - 3)
        [printf](../io/fprintf.html)("3: yes\n");
    #endif
     
    // C23 directives #elifdef/#elifndef
    #ifdef CPU
        [printf](../io/fprintf.html)("4: no1\n");
    #elifdef GPU
        [printf](../io/fprintf.html)("4: no2\n");
    #elifndef RAM
        [printf](../io/fprintf.html)("4: yes\n"); // selected in C23 mode, may be selected in pre-C23 mode
    #else
        [printf](../io/fprintf.html)("4: no3\n"); // may be selected in pre-C23 mode
    #endif
    }

Possible output: 
    
    
    1: yes
    2: yes
    3: yes
    4: yes

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/conditional&action=edit&section=8 "Edit section: Defect reports")] Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards. 

DR  | Applied to  | Behavior as published  | Correct behavior   
---|---|---|---  
[DR 412](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_412) | C89  | failed `#elif`'s expression was required to be valid  | failed `#elif` is skipped   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/conditional&action=edit&section=9 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.10.1 Conditional inclusion (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.10.1 Conditional inclusion (p: 118-119) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.10.1 Conditional inclusion (p: 162-164) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.10.1 Conditional inclusion (p: 147-149) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.8.1 Conditional inclusion 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/conditional&action=edit&section=10 "Edit section: See also")] See also

[C++ documentation](../../cpp/preprocessor/conditional.html "cpp/preprocessor/conditional") for Conditional inclusion  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/conditional&oldid=154407](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/conditional&oldid=154407)" 

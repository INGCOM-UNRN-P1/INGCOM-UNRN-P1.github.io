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
**#define #undef#,## operators**  
[#include__has_include](include.html "c/preprocessor/include")(C23)  
[#error#warning](warning.html "c/preprocessor/error")(C23)  
[#pragma_Pragma](impl.html "c/preprocessor/impl")(C99)  
[#line](line.html "c/preprocessor/line")  
[#embed__has_embed](embed.html "c/preprocessor/embed")(C23)(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/preprocessor/navbar_content&action=edit)

The preprocessor supports text macro replacement and function-like text macro replacement. 

## Contents

  * [1 Syntax](replace.html#Syntax)
  * [2 Explanation](replace.html#Explanation)
    * [2.1 #define directives](replace.html#.23define_directives)
      * [2.1.1 Object-like macros](replace.html#Object-like_macros)
      * [2.1.2 Function-like macros](replace.html#Function-like_macros)
    * [2.2 # and ## operators](replace.html#.23_and_.23.23_operators)
    * [2.3 #undef directive](replace.html#.23undef_directive)
  * [3 Predefined macros](replace.html#Predefined_macros)
  * [4 Example](replace.html#Example)
  * [5 Defect reports](replace.html#Defect_reports)
  * [6 References](replace.html#References)
  * [7 See also](replace.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/replace&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**#define**` identifier replacement-list ﻿(optional) |  (1)  |   
`**#define**` identifier ﻿`**(**` parameters `**)**` replacement-list |  (2)  |   
`**#define**` identifier ﻿`**(**` parameters`**, ... )**` replacement-list |  (3)  |  (since C99)  
`**#define**` identifier ﻿`**( ... )**` replacement-list |  (4)  |  (since C99)  
`**#undef**` identifier |  (5)  |   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/replace&action=edit&section=2 "Edit section: Explanation")] Explanation

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/replace&action=edit&section=3 "Edit section: #define directives")] #define directives

The `#define` directives define the identifier as a macro, that is they instruct the compiler to replace all successive occurrences of identifier with replacement-list, which can be optionally additionally processed. If the identifier is already defined as any type of macro, the program is ill-formed unless the definitions are identical. 

##### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/replace&action=edit&section=4 "Edit section: Object-like macros")] Object-like macros

Object-like macros replace every occurrence of a defined identifier with replacement-list. Version (1) of the `#define` directive behaves exactly like that. 

##### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/replace&action=edit&section=5 "Edit section: Function-like macros")] Function-like macros

Function-like macros replace each occurrence of a defined identifier with replacement-list, additionally taking a number of arguments, which then replace corresponding occurrences of any of the parameters in the replacement-list. 

The syntax of a function-like macro invocation is similar to the syntax of a function call: each instance of the macro name followed by a ( as the next preprocessing token introduces the sequence of tokens that is replaced by the replacement-list. The sequence is terminated by the matching ) token, skipping intervening matched pairs of left and right parentheses. 

The number of arguments must be the same as the number of arguments in the macro definition (parameters) or the program is ill-formed. If the identifier is not in functional-notation, i.e., does not have parentheses after itself, it is not replaced at all. 

Version (2) of the `#define` directive defines a simple function-like macro. 

Version (3) of the `#define` directive defines a function-like macro with variable number of arguments. The additional arguments can be accessed using __VA_ARGS__ identifier, which is then replaced with arguments, supplied with the identifier to be replaced. 

Version (4) of the `#define` directive defines a function-like macro with variable number of arguments, but no regular arguments. The arguments can be accessed only with __VA_ARGS__ identifier, which is then replaced with arguments, supplied with identifier to be replaced. 

For versions (3,4), replacement-list may contain the token sequence `**__VA_OPT__ (**` content `**)**`, which is replaced by content if __VA_ARGS__ is non-empty, and expands to nothing otherwise. 
    
    
    #define F(...) f(0 __VA_OPT__(,) __VA_ARGS__)
    F(a, b, c) // replaced by f(0, a, b, c)
    F()        // replaced by f(0)
     
    #define G(X, ...) f(0, X __VA_OPT__(,) __VA_ARGS__)
    G(a, b, c) // replaced by f(0, a, b, c)
    G(a, )     // replaced by f(0, a)
    G(a)       // replaced by f(0, a)
     
    #define SDEF(sname, ...) S sname __VA_OPT__(= { __VA_ARGS__ })
    SDEF(foo);       // replaced by S foo;
    SDEF(bar, 1, 2); // replaced by S bar = { 1, 2 };

| (since C23)  
---|---  
  
  
Note: if an argument of a function-like macro includes commas that are not protected by matched pairs of left and right parentheses (such as macro(array[x = y, x + 1]) or [atomic_store](../atomic/atomic_store.html)(p, (struct S){ a, b });), the comma is interpreted as macro argument separator, causing a compilation failure due to argument count mismatch. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/replace&action=edit&section=6 "Edit section: # and ## operators")] # and ## operators

In function-like macros, a `#` operator before an identifier in the replacement-list runs the identifier through parameter replacement and encloses the result in quotes, effectively creating a string literal. In addition, the preprocessor adds backslashes to escape the quotes surrounding embedded string literals, if any, and doubles the backslashes within the string as necessary. All leading and trailing whitespace is removed, and any sequence of whitespace in the middle of the text (but not inside embedded string literals) is collapsed to a single space. This operation is called “stringification”. If the result of stringification is not a valid string literal, the behavior is undefined. 

When `#` appears before __VA_ARGS__, the entire expanded __VA_ARGS__ is enclosed in quotes: 
    
    
    #define showlist(...) puts(#__VA_ARGS__)
    showlist();            // expands to puts("")
    showlist(1, "x", int); // expands to puts("1, \"x\", int")

| (since C99)  
---|---  
  
A `##` operator between any two successive identifiers in the replacement-list runs parameter replacement on the two identifiers and then concatenates the result. This operation is called “concatenation” or “token pasting”. Only tokens that form a valid token together may be pasted: identifiers that form a longer identifier, digits that form a number, or operators `**+**` and `**=**` that form a `**+=**`. A comment cannot be created by pasting `**/**` and `*****` because comments are removed from text before macro substitution is considered. If the result of concatenation is not a valid token, the behavior is undefined. 

Note: Some compilers offer an extension that allows `##` to appear after a comma and before __VA_ARGS__, in which case the `##` does nothing when __VA_ARGS__ is non-empty, but removes the comma when __VA_ARGS__ is empty: this makes it possible to define macros such as [fprintf](../io/fprintf.html)([stderr](../io/std_streams.html), format, ##__VA_ARGS__). 

The order of evaluation of `#` and `##` operators is unspecified. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/replace&action=edit&section=7 "Edit section: #undef directive")] #undef directive

The `#undef` directive undefines the identifier, that is it cancels the previous definition of the identifier by `#define` directive. If the identifier does not have an associated macro, the directive is ignored. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/replace&action=edit&section=8 "Edit section: Predefined macros")] Predefined macros

The following macro names are predefined in any translation unit: 

__STDC__ |  expands to the integer constant 1. This macro is intended to indicate a conforming implementation   
(macro constant)  
---|---  
__STDC_VERSION__(C95) |  expands to an integer constant of type long whose value increases with each version of the C standard: 

  * 199409L (C95)
  * 199901L (C99)
  * 201112L (C11)
  * 201710L (C17)
  * 202311L (C23)   
(macro constant)

  
__STDC_HOSTED__(C99) |  expands to the integer constant 1 if the implementation is hosted (runs under an OS), ​0​ if freestanding (runs without an OS)   
(macro constant)  
__FILE__ |  expands to the name of the current file, as a character string literal, can be changed by the [`#line`](line.html "c/preprocessor/line") directive   
(macro constant)  
__LINE__ |  expands to the source file line number, an integer constant, can be changed by the [`#line`](line.html "c/preprocessor/line") directive   
(macro constant)  
__DATE__ |  expands to the date of translation, a character string literal of the form “Mmm dd yyyy”. The name of the month is as if generated by [asctime](../chrono/asctime.html "c/chrono/asctime") and the first character of “dd” is a space if the day of the month is less than 10   
(macro constant)  
__TIME__ |  expands to the time of translation, a character string literal of the form “hh:mm:ss”, as in the time generated by [asctime](../chrono/asctime.html)()   
(macro constant)  
__STDC_UTF_16__(C23) |  expands to 1 to indicate that char16_t use UTF-16 encoding   
(macro constant)  
__STDC_UTF_32__(C23) |  expands to 1 to indicate that char32_t use UTF-32 encoding   
(macro constant)  
__STDC_EMBED_NOT_FOUND____STDC_EMBED_FOUND____STDC_EMBED_EMPTY__(C23) |  expand to ​0​, 1, and 2, respectively   
(macro constant)  
  
The following additional macro names may be predefined by an implementation: 

__STDC_ISO_10646__(C99) |  expands to an integer constant of the form `yyyymmL`, if wchar_t uses Unicode; the date indicates the latest revision of Unicode supported   
(macro constant)  
---|---  
__STDC_IEC_559__(C99)(deprecated in C23) |  expands to 1 if IEC 60559 is supported   
(macro constant)  
__STDC_IEC_559_COMPLEX__(C99)(deprecated in C23) |  expands to 1 if IEC 60559 complex arithmetic is supported   
(macro constant)  
__STDC_UTF_16__(C11) |  expands to 1 if char16_t use UTF-16 encoding   
(macro constant)  
__STDC_UTF_32__(C11) |  expands to 1 if char32_t use UTF-32 encoding   
(macro constant)  
__STDC_MB_MIGHT_NEQ_WC__(C99) |  expands to 1 if 'x' == L'x' might be false for a member of the basic character set, such as on EBCDIC-based systems that use Unicode for wchar_t   
(macro constant)  
__STDC_ANALYZABLE__(C11) |  expands to 1 if [analyzability](../language/analyzability.html "c/language/analyzability") is supported   
(macro constant)  
__STDC_LIB_EXT1__(C11) |  expands to an integer constant 201112L if [bounds-checking interfaces](../error.html "c/error") are supported   
(macro constant)  
__STDC_NO_ATOMICS__(C11) |  expands to 1 if [atomic](../language/atomic.html "c/language/atomic") types and [atomic operations library](../thread.html#Atomic_operations "c/thread") are not supported   
(macro constant)  
__STDC_NO_COMPLEX__(C11) |  expands to 1 if [complex types](../language/arithmetic_types.html#Complex_floating_types "c/language/arithmetic types") and [complex math library](../numeric/complex.html "c/numeric/complex") are not supported   
(macro constant)  
__STDC_NO_THREADS__(C11) |  expands to 1 if [multithreading](../thread.html "c/thread") is not supported   
(macro constant)  
__STDC_NO_VLA__(C11) |  expands to 1 if [variable-length arrays](../language/array.html#Variable-length_arrays "c/language/array") and variably-modified types(until C23)of automatic storage duration(since C23) are not supported   
(macro constant)  
__STDC_IEC_60559_BFP__(C23) |  expands to 202311L if IEC 60559 binary floating-point arithmetic is supported   
(macro constant)  
__STDC_IEC_60559_DFP__(C23) |  expands to 202311L if IEC 60559 decimal floating-point arithmetic is supported   
(macro constant)  
__STDC_IEC_60559_COMPLEX__(C23) |  expands to 202311L if IEC 60559 complex arithmetic is supported   
(macro constant)  
__STDC_IEC_60559_TYPES__(C23) |  expands to 202311L if IEC 60559 interchange and extended types are supported   
(macro constant)  
  
The values of these macros (except for `__FILE__` and `__LINE__`) remain constant throughout the translation unit. Attempts to redefine or undefine these macros result in undefined behavior. 

The predefined variable __func__ (see [function definition](../language/function_definition.html#func "c/language/function definition") for details) is not a preprocessor macro, even though it is sometimes used together with `__FILE__` and `__LINE__`, e.g., by [assert](../error/assert.html "c/error/assert").  | (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/replace&action=edit&section=9 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
     
    // make function factory and use it
    #define FUNCTION(name, a) int fun_##name(int x) { return (a) * x; }
    FUNCTION(quadruple, 4)
    FUNCTION(double, 2)
    #undef FUNCTION
     
    #define FUNCTION 34
     
    #define OUTPUT(a) puts( #a )
     
    int main(void)
    {
        [printf](../io/fprintf.html)("quadruple(13): %d\n", fun_quadruple(13));
        [printf](../io/fprintf.html)("double(21): %d\n", fun_double(21));
        [printf](../io/fprintf.html)("%d\n", FUNCTION);
        OUTPUT(billion); // note the lack of quotes
    }

Output: 
    
    
    quadruple(13): 52
    double(21): 42
    34
    billion

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/replace&action=edit&section=10 "Edit section: Defect reports")] Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards. 

DR  | Applied to  | Behavior as published  | Correct behavior   
---|---|---|---  
[DR 321](https://www.open-std.org/jtc1/sc22/wg14/www/docs/dr_321.htm) | C99  | it was unclear if L'x' == 'x' always holds  
among the basic character set  | __STDC_MB_MIGHT_NEQ_WC__ added for the purpose   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/replace&action=edit&section=11 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.10.4 Macro replacement (p: 187-184) 



    

  * 6.10.9 Predefined macro names (p: 186-188) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.10.3 Macro replacement (p: 121-126) 



    

  * 6.10.8 Predefined macro names (p: 127-129) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.10.3 Macro replacement (p: 166-173) 



    

  * 6.10.8 Predefined macro names (p: 175-176) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.10.3 Macro replacement (p: 151-158) 



    

  * 6.10.8 Predefined macro names (p: 160-161) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.8.3 Macro replacement 



    

  * 3.8.8 Predefined macro names 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/replace&action=edit&section=12 "Edit section: See also")] See also

[C++ documentation](../../cpp/preprocessor/replace.html "cpp/preprocessor/replace") for Replacing text macros  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/replace&oldid=182852](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/replace&oldid=182852)" 

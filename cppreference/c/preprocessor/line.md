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
**#line**  
[#embed__has_embed](embed.html "c/preprocessor/embed")(C23)(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/preprocessor/navbar_content&action=edit)

Changes the current line number and file name in the preprocessor. 

## Contents

  * [1 Syntax](line.html#Syntax)
  * [2 Explanation](line.html#Explanation)
  * [3 Notes](line.html#Notes)
  * [4 Example](line.html#Example)
  * [5 References](line.html#References)
  * [6 See also](line.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/line&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**#line**` lineno |  (1)  |   
`**#line**` lineno `**"**` filename`**"**` |  (2)  |   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/line&action=edit&section=2 "Edit section: Explanation")] Explanation

1) Changes the current preprocessor line number to lineno. Occurrences of the macro __LINE__ beyond this point will expand to lineno plus the number of actual source code lines encountered since.

2) Also changes the current preprocessor file name to filename. Occurrences of the macro __FILE__ beyond this point will produce filename.

Any preprocessing tokens (macro constants or expressions) are permitted as arguments to #line as long as they expand to a valid decimal integer optionally following a valid character string. 

lineno must be a sequence of at least one decimal digit (the program is ill-formed, otherwise) and is always interpreted as decimal (even if it starts with `0`). 

If lineno is `0` or greater than `32767`(until C99)`2147483647`(since C99), the behavior is undefined. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/line&action=edit&section=3 "Edit section: Notes")] Notes

This directive is used by some automatic code generation tools which produce C source files from a file written in another language. In that case, #line directives may be inserted in the generated C file referencing line numbers and the file name of the original (human-editable) source file. 

The line number following the directive #line __LINE__ is unspecified (there are two possible values that __LINE__ can expand to in this case: number of endlines seen so far, or number of endlines seen so far plus the endline that ends the #line directive). This is the result of [DR 464](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2257.htm#dr_464), which applies retroactively. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/line&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <assert.h>
    #define FNAME "test.c"
    int main(void)
    {
    #line 777 FNAME
            [assert](../error/assert.html)(2+2 == 5);
    }

Possible output: 
    
    
    test: test.c:777: int main(): Assertion `2+2 == 5' failed.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/line&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.10.4 Line control (p: 126) 



    

  * J.1 Unspecified behavior 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.10.4 Line control (p: 173) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.10.4 Line control (p: 158) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.8.4 Line control 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/line&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/preprocessor/line.html "cpp/preprocessor/line") for Filename and line information  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/line&oldid=139846](https://en.cppreference.com/mwiki/index.php?title=c/preprocessor/line&oldid=139846)" 

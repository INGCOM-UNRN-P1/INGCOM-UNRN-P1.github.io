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

[ Functions](functions.html "c/language/functions")

[ function declaration](function_declaration.html "c/language/function declaration")  
---  
[ function definition](function_definition.html "c/language/function definition")  
[ variadic arguments](variadic.html "c/language/variadic")  
[inline](inline.html "c/language/inline")(C99)  
**_Noreturn**(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/functions/navbar_content&action=edit)

Specifies that the function does not return to its point of invocation. 

## Contents

  * [1 Syntax](noreturn.html#Syntax)
  * [2 Explanation](noreturn.html#Explanation)
  * [3 Keywords](noreturn.html#Keywords)
  * [4 Standard library](noreturn.html#Standard_library)
  * [5 Example](noreturn.html#Example)
  * [6 References](noreturn.html#References)
  * [7 See also](noreturn.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Noreturn&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
_Noreturn function_declaration |  |  (since C11)(deprecated in C23)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Noreturn&action=edit&section=2 "Edit section: Explanation")] Explanation

The `**_Noreturn**` keyword appears in a function declaration and specifies that the function does not return by executing the return statement or by reaching the end of the function body (it may return by executing [longjmp](../program/longjmp.html "c/program/longjmp")). If the function declared `_Noreturn` returns, the behavior is undefined. A compiler diagnostic is recommended if this can be detected. 

The `_Noreturn` specifier may appear more than once in the same function declaration, the behavior is the same as if it appeared once. 

This specifier is typically used through the convenience macro [`noreturn`](../types.html "c/types"), which is provided in the header `<stdnoreturn.h>`. 

`_Noreturn` function specifier is deprecated. `[[[noreturn](attributes/noreturn.html "c/language/attributes/noreturn")]]` attribute should be used instead. The macro `noreturn` is also deprecated.  | (since C23)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Noreturn&action=edit&section=3 "Edit section: Keywords")] Keywords

[`_Noreturn`](../keyword/_Noreturn.html "c/keyword/ Noreturn")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Noreturn&action=edit&section=4 "Edit section: Standard library")] Standard library

The following functions are `noreturn` in the standard library: 

  * [abort()](../program/abort.html "c/program/abort")
  * [exit()](../program/exit.html "c/program/exit")
  * [_Exit()](../program/_Exit.html "c/program/ Exit")
  * [quick_exit()](../program/quick_exit.html "c/program/quick exit")
  * [thrd_exit()](../thread/thrd_exit.html "c/thread/thrd exit")
  * [longjmp()](../program/longjmp.html "c/program/longjmp")



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Noreturn&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdnoreturn.h>
     
    // causes undefined behavior if i <= 0
    // exits if i > 0
    noreturn void exit_now(int i) // or _Noreturn void exit_now(int i)
    {
        if (i > 0)
            [exit](../program/exit.html)(i);
    }
     
    int main(void)
    {
        [puts](../io/puts.html)("Preparing to exit...");
        exit_now(2);
        [puts](../io/puts.html)("This code is never executed.");
    }

Output: 
    
    
    Preparing to exit...

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Noreturn&action=edit&section=6 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.4 Function specifiers (p: TBD) 



    

  * 7.23 _Noreturn <stdnoreturn.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.4 Function specifiers (p: 90-91) 



    

  * 7.23 _Noreturn <stdnoreturn.h> (p: 263) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.4 Function specifiers (p: 125-127) 



    

  * 7.23 _Noreturn <stdnoreturn.h> (p: 361) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Noreturn&action=edit&section=7 "Edit section: See also")] See also

`[[[noreturn](attributes/noreturn.html "c/language/attributes/noreturn")]]`(C23)`[[[_Noreturn](attributes/noreturn.html "c/language/attributes/noreturn")]]`(C23)(deprecated) |  indicates that the function does not return  
(attribute specifier)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/dsc_noreturn&action=edit)  
---|---  
[C++ documentation](../../cpp/language/attributes/noreturn.html "cpp/language/attributes/noreturn") for `[[noreturn]]`  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/_Noreturn&oldid=180091](https://en.cppreference.com/mwiki/index.php?title=c/language/_Noreturn&oldid=180091)" 

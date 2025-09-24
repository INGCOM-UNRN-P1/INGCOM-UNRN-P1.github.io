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

If the declarator or type specifier that declares the identifier appears outside of any block or list of parameters, the identifier has file scope, which terminates at the end of the translation unit. 

So, placement of an identifier's declaration (in a declarator or type specifier) outside any block or list of parameters means that the identifier has file scope. File scope of an identifier extends from the declaration to the end of the translation unit in which the declaration appears. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/file_scope&action=edit&section=1 "Edit section: Example")] Example

Identifiers a, b, f, and g have file scope.

Run this code
    
    
    #include <stdio.h>
     
    int a = 1;
    static int b = 2;
     
    void f (void) {[printf](../io/fprintf.html)("from function f()\n");}
    static void g (void) {[printf](../io/fprintf.html)("from function g()\n");}
     
    int main(void)
    {
        f();
        g();
     
        return 0;
    }
    /* end of this translation unit, end of file scope */

Possible output: 
    
    
    from function f()
    from function g()

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/file_scope&oldid=72742](https://en.cppreference.com/mwiki/index.php?title=c/language/file_scope&oldid=72742)" 

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

An object whose identifier is declared without the storage-class specifier _Thread_local, and either with external or internal [linkage](storage_class_specifiers.html#Linkage "c/language/storage duration") or with the storage-class specifier static, has static storage duration. Its lifetime is the entire execution of the program and its stored value is initialized only once, prior to program startup. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/static_storage_duration&action=edit&section=1 "Edit section: Notes")] Notes

Since its stored value is initialized only once, an object with static storage duration can profile the invocations of a function. 

The other use of the keyword static is [file scope](file_scope.html "c/language/file scope"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/static_storage_duration&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
     
    void f (void)
    {
        static int count = 0;   // static variable   
        int i = 0;              // automatic variable
        [printf](../io/fprintf.html)("%d %d\n", i++, count++);
    }
     
    int main(void)
    {
        for (int ndx=0; ndx<10; ++ndx)
            f();
    }

Output: 
    
    
    0 0
    0 1
    0 2
    0 3
    0 4
    0 5
    0 6
    0 7
    0 8
    0 9

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/static_storage_duration&oldid=109385](https://en.cppreference.com/mwiki/index.php?title=c/language/static_storage_duration&oldid=109385)" 

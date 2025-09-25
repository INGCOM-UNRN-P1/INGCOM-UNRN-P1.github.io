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

[ Basic Concepts](basic_concepts.html "c/language/basic concepts")

[ Comments](../comment.html "c/comment")  
---  
[ ASCII](ascii.html "c/language/ascii")  
[ Character sets](charset.html "c/language/charset")  
[ Translation phases](translation_phases.html "c/language/translation phases")  
[Punctuation](punctuators.html "c/language/punctuators")  
[Identifier](identifiers.html "c/language/identifier")  
[Scope](scope.html "c/language/scope")  
[Lifetime](lifetime.html "c/language/lifetime")  
[Lookup and name spaces](name_space.html "c/language/name space")  
[Type](compatible_type.html "c/language/type")  
[Arithmetic types](arithmetic_types.html "c/language/arithmetic types")  
[Objects and alignment](object.html "c/language/object")  
**The main() function**  
[The as-if rule](as_if.html "c/language/as if")  
[Undefined behavior](behavior.html "c/language/behavior")  
[Memory model and data races](memory_model.html "c/language/memory model")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/basics/navbar_content&action=edit)

Every C program coded to run in a hosted execution environment contains the definition (not the prototype) of a function named `**main**`, which is the designated start of the program.   
  
---  
int `**main**` `**(void)**` `**{**` body `**}**` |  (1)  |   
int `**main**` `**(**` int argc`**,**` char *argv[]`**)**` `**{**` body `**}**` |  (2)  |   
/* another implementation-defined signature */ (since C99) |  (3)  |   
  
## Contents

  * [1 Parameters](main_function.html#Parameters)
  * [2 Return value](main_function.html#Return_value)
  * [3 Explanation](main_function.html#Explanation)
  * [4 Example](main_function.html#Example)
  * [5 References](main_function.html#References)
  * [6 See also](main_function.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/main_function&action=edit&section=1 "Edit section: Parameters")] Parameters

argc  |  \-  |  Non-negative value representing the number of arguments passed to the program from the environment in which the program is run.   
---|---|---  
argv  |  \-  |  Pointer to the first element of an array of argc + 1 pointers, of which the last one is null and the previous ones, if any, point to strings that represent the arguments passed to the program from the host environment. If argv[0] is not a null pointer (or, equivalently, if argc > 0), it points to a string that represents the program name, which is empty if the program name is not available from the host environment.   
  
The names `argc` and `argv` stand for "argument count" and "argument vector", and are traditionally used, but other names may be chosen for the parameters, as well as different but equivalent declarations of their type: int main(int ac, char** av) is equally valid. 

A common implementation-defined form of main is int main(int argc, char *argv[], char *envp[]), where a third argument, of type char**, pointing at [an array of pointers to the _execution environment variables_](https://pubs.opengroup.org/onlinepubs/9699919799/functions/exec.html), is added. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/main_function&action=edit&section=2 "Edit section: Return value")] Return value

If the return statement is used, the return value is used as the argument to the implicit call to [exit()](../program/exit.html "c/program/exit") (see below for details). The values zero and [EXIT_SUCCESS](../program/EXIT_status.html "c/program/EXIT status") indicate successful termination, the value [EXIT_FAILURE](../program/EXIT_status.html "c/program/EXIT status") indicates unsuccessful termination. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/main_function&action=edit&section=3 "Edit section: Explanation")] Explanation

The `main` function is called at program startup, after all objects with static storage duration are initialized. It is the designated entry point to a program that is executed in a _hosted_ environment (that is, with an operating system). The name and type of the entry point to any _freestanding_ program (boot loaders, OS kernels, etc) are implementation-defined. 

The parameters of the two-parameter form of the main function allow arbitrary multibyte character strings to be passed from the execution environment (these are typically known as _command line arguments_). The pointers argv[1] .. argv[argc-1] point at the first characters in each of these strings. argv[0] (if non-null) is the pointer to the initial character of a null-terminated multibyte string that represents the name used to invoke the program itself (or, if this is not supported by the host environment, argv[0][0] is guaranteed to be zero). 

If the host environment cannot supply both lowercase and uppercase letters, the command line arguments are converted to lowercase. 

The strings are modifiable, and any modifications made persist until program termination, although these modifications do not propagate back to the host environment: they can be used, for example, with [strtok](../string/byte/strtok.html "c/string/byte/strtok"). 

The size of the array pointed to by `argv` is at least `argc+1`, and the last element, `argv[argc]`, is guaranteed to be a null pointer. 

The `main` function has several special properties: 

1) A prototype for this function cannot be supplied by the program.

2) If the return type of the main function is [compatible](compatible_type.html#Compatible_types "c/language/type") with int, then the return from the initial call to main (but not the return from any subsequent, recursive, call) is equivalent to executing the [exit](../program/exit.html "c/program/exit") function, with the value that the main function is returning passed as the argument (which then calls the functions registered with [atexit](../program/atexit.html "c/program/atexit"), flushes and closes all streams, and deletes the files created with [tmpfile](../io/tmpfile.html "c/io/tmpfile"), and returns control to the execution environment).

3) If the main function executes a return that specifies no value or, which is the same, reaches the terminating } without executing a return, the termination status returned to the host environment is undefined.  | (until C99)  
---|---  
If the return type of the main function is not [compatible](compatible_type.html#Compatible_types "c/language/type") with int (e.g. void main(void)), the value returned to the host environment is unspecified. If the return type is compatible with int and control reaches the terminating }, the value returned to the environment is the same as if executing return 0;.  | (since C99)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/main_function&action=edit&section=4 "Edit section: Example")] Example

Demonstrates how to inform a program about where to find its input and where to write its results. Invocation: ./a.out indatafile outdatafile

Run this code
    
    
    #include <stdio.h>
     
    int main(int argc, char *argv[])
    {
        [printf](../io/fprintf.html)("argc = %d\n", argc);
        for (int ndx = 0; ndx != argc; ++ndx)
            [printf](../io/fprintf.html)("argv[%d] --> %s\n", ndx, argv[ndx]);
        [printf](../io/fprintf.html)("argv[argc] = %p\n", (void*)argv[argc]);
    }

Possible output: 
    
    
    argc = 3
    argv[0] --> ./a.out
    argv[1] --> indatafile
    argv[2] --> outdatafile
    argv[argc] = (nil)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/main_function&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 5.1.2.2.1 Program startup (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 5.1.2.2.1 Program startup (p: 10-11) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 5.1.2.2.1 Program startup (p: 13) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 5.1.2.2.1 Program startup (p: 12) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 5.1.2.2 Hosted environment 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/main_function&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/main_function.html "cpp/language/main function") for `main` function  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/main_function&oldid=154725](https://en.cppreference.com/mwiki/index.php?title=c/language/main_function&oldid=154725)" 

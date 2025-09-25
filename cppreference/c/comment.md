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
[ Preprocessor](preprocessor.html "c/preprocessor")  
[ Statements](language/statements.html "c/language/statements")  
[ Expressions](language/operators.html "c/language/expressions")  
[ Initialization](language/initialization.html "c/language/initialization")  
[ Declarations](language/declarations.html "c/language/declarations")  
[ Functions](language/functions.html "c/language/functions")  
Miscellaneous  
[ History of C](language/history.html "c/language/history")  
[Technical Specifications](experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

[ Basic Concepts](language/basic_concepts.html "c/language/basic concepts")

**Comments**  
---  
[ ASCII](language/ascii.html "c/language/ascii")  
[ Character sets](language/charset.html "c/language/charset")  
[ Translation phases](language/translation_phases.html "c/language/translation phases")  
[Punctuation](language/punctuators.html "c/language/punctuators")  
[Identifier](language/identifiers.html "c/language/identifier")  
[Scope](language/scope.html "c/language/scope")  
[Lifetime](language/lifetime.html "c/language/lifetime")  
[Lookup and name spaces](language/name_space.html "c/language/name space")  
[Type](language/compatible_type.html "c/language/type")  
[Arithmetic types](language/arithmetic_types.html "c/language/arithmetic types")  
[Objects and alignment](language/object.html "c/language/object")  
[The main() function](language/main_function.html "c/language/main function")  
[The as-if rule](language/as_if.html "c/language/as if")  
[Undefined behavior](language/behavior.html "c/language/behavior")  
[Memory model and data races](language/memory_model.html "c/language/memory model")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/basics/navbar_content&action=edit)

Comments serve as a sort of in-code documentation. When inserted into a program, they are effectively ignored by the compiler; they are solely intended to be used as notes by the humans that read source code. 

## Contents

  * [1 Syntax](comment.html#Syntax)
  * [2 C-style](comment.html#C-style)
  * [3 C++-style](comment.html#C.2B.2B-style)
  * [4 Notes](comment.html#Notes)
  * [5 Example](comment.html#Example)
  * [6 References](comment.html#References)
  * [7 See also](comment.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/comment&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**/***` comment `***/**` |  (1)  |   
`**//**` comment |  (2)  |  (since C99)  
  
1) Often known as "C-style" or "multi-line" comments.

2) Often known as "C++-style" or "single-line" comments.

All comments are removed from the program at [translation phase 3](language/translation_phases.html "c/language/translation phases") by replacing each comment with a single whitespace character. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/comment&action=edit&section=2 "Edit section: C-style")] C-style

C-style comments are usually used to comment large blocks of text or small fragments of code; however, they can be used to comment single lines. To insert text as a C-style comment, simply surround the text with `/*` and `*/`. C-style comments tell the compiler to ignore all content between `/*` and `*/`. Although it is not part of the C standard, `/**` and `**/` are often used to indicate documentation blocks; this is legal because the second asterisk is simply treated as part of the comment. 

Except within a [character constant](language/character_constant.html "c/language/character constant"), a [string literal](language/string_literal.html "c/language/string literal"), or a comment, the characters `/*` introduce a comment. The contents of such a comment are examined only to identify multibyte characters and to find the characters `*/` that terminate the comment. C-style comments cannot be nested. 

###  C++-style

C++-style comments are usually used to comment single lines of text or code; however, they can be placed together to form multi-line comments. To insert text as a C++-style comment, simply precede the text with `//` and follow the text with the new line character. C++-style comments tell the compiler to ignore all content between `//` and a new line. Except within a [character constant](language/character_constant.html "c/language/character constant"), a [string literal](language/string_literal.html "c/language/string literal"), or a comment, the characters `//` introduce a comment that includes all multibyte characters up to, but not including, the next new-line character. The contents of such a comment are examined only to identify multibyte characters and to find the new-line character that terminates the comment. C++-style comments can be nested: 
    
    
    //  y = f(x);   // invoke algorithm

A C-style comment may appear within a C++-style comment: 
    
    
    //  y = f(x);   /* invoke algorithm */

A C++-style comment may appear within a C-style comment; this is a mechanism for excluding a small block of source code: 
    
    
    /*
        y = f(x);   // invoke algorithms
        z = g(x);
    */

| (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/comment&action=edit&section=4 "Edit section: Notes")] Notes

Because comments [are removed](language/translation_phases.html "c/language/translation phases") before the preprocessor stage, a macro cannot be used to form a comment and an unterminated C-style comment doesn't spill over from an #include'd file. 
    
    
    /* An attempt to use a macro to form a comment. */
    /* But, a space replaces characters "//".       */
    #ifndef DEBUG
        #define PRINTF //
    #else
        #define PRINTF printf
    #endif
    ...  
    PRINTF("Error in file %s at line %i\n", __FILE__, __LINE__);

Besides commenting out, other mechanisms used for source code exclusion are: 
    
    
    #if 0
        [puts](io/puts.html)("this will not be compiled");
        /* no conflict with C-style comments */
        // no conflict with C++-style comments
    #endif

and 
    
    
    if(0) {
        [puts](io/puts.html)("this will be compiled but not be executed");
        /* no conflict with C-style comments */
        // no conflict with C++-style comments
    }

The introduction of // comments in C99 was a breaking change in some rare circumstances: 
    
    
    a = b //*divisor:*/ c
    + d; /* C89 compiles a = b / c + d;
            C99 compiles a = b + d; */

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/comment&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    /*
    C-style comments can contain
    multiple lines.
    */
     
    /* Or, just one line. */
     
    // C++-style comments can comment one line.
     
    // Or, they can
    // be strung together.
     
    int main(void)
    {
      // The below code won't be run
      // puts("Hello");
     
      // The below code will be run
      [puts](io/puts.html)("World");
     
      // A note regarding backslash + newline.
      // Despite belonging to translation phase 2 (vs phase 3 for comments),
      // '\' still determines which portion of the source code is considered
      // as 'comments':
      // This comment will be promoted to the next line \
      puts("Won't be run"); // may issue a warning "multi-line comment"
      [puts](io/puts.html)("Hello, again");
    }

Output: 
    
    
    World
    Hello, again

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/comment&action=edit&section=6 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.4.9 Comments (p: 54) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.4.9 Comments (p: 75) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.4.9 Comments (p: 66) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.1.9 Comments 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/comment&action=edit&section=7 "Edit section: See also")] See also

[C++ documentation](../cpp/comments.html "cpp/comments") for Comments  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/comment&oldid=146308](https://en.cppreference.com/mwiki/index.php?title=c/comment&oldid=146308)" 

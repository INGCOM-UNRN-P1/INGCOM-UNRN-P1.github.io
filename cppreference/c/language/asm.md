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

Inline assembly (typically introduced by the asm keyword) gives the ability to embed assembly language source code within a C program. 

Unlike in C++, inline assembly is treated as an extension in C. It is conditionally supported and implementation defined, meaning that it may not be present and, even when provided by the implementation, it does not have a fixed meaning. 

## Contents

  * [1 Syntax](asm.html#Syntax)
  * [2 Explanation](asm.html#Explanation)
  * [3 Notes](asm.html#Notes)
  * [4 Examples](asm.html#Examples)
  * [5 References](asm.html#References)
  * [6 See also](asm.html#See_also)
  * [7 External links](asm.html#External_links)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/asm&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**asm (**` string_literal `**)**` `**;**` |  |   
| This section is incomplete  
Reason: write a note on GCC extended assembly syntax, since it is now supported by Intel, IBM, Sun (as of v12), etc   
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/asm&action=edit&section=2 "Edit section: Explanation")] Explanation

This kind of inline assembly syntax is accepted by the C++ standard and called _asm-declaration_ in C++. The string_literal is typically a short program written in assembly language, which is executed whenever this declaration is executed. Different C compilers have wildly varying rules for asm-declarations, and different conventions for the interaction with the surrounding C code. 

asm-declaration can appear inside a block (a function body or another compound statement), and, as all other declarations, this declaration can also appear outside a block. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/asm&action=edit&section=3 "Edit section: Notes")] Notes

MSVC does not support inline assembly on the ARM and x64 processors, and only support the form introduced by __asm on x86 processors. 

When compiling in ISO C mode by GCC or Clang (e.g. with option -std=c11), __asm__ must be used instead of asm. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/asm&action=edit&section=4 "Edit section: Examples")] Examples

Demonstrates two kinds of inline assembly syntax offered by the GCC compiler. This program will only work correctly on x86-64 platform under Linux. Note that the "standard inline assembly" is also treated as an extension in the C standard.

Run this code
    
    
    #include <stdio.h>
     
    extern int func(void);
    // the definition of func is written in assembly language
    __asm__(".globl func\n\t"
            ".type func, @function\n\t"
            "func:\n\t"
            ".cfi_startproc\n\t"
            "movl $7, %eax\n\t"
            "ret\n\t"
            ".cfi_endproc");
     
    int main(void)
    {
        int n = func();
        // gcc's extended inline assembly
        __asm__ ("leal (%0,%0,4),%0"
               : "=r" (n)
               : "0" (n));
        [printf](../io/fprintf.html)("7*5 = %d\n", n);
        [fflush](../io/fflush.html)([stdout](../io/std_streams.html)); // flush is intentional
     
        // standard inline assembly in C++
        __asm__ ("movq $60, %rax\n\t" // the exit syscall number on Linux
                 "movq $2,  %rdi\n\t" // this program returns 2
                 "syscall");
    }

Output: 
    
    
    7*5 = 35

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/asm&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * J.5.10 The asm keyword (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * J.5.10 The asm keyword (p: 422) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * J.5.10 The asm keyword (p: 580) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * J.5.10 The asm keyword (p: 512) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * G.5.10 The asm keyword 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/asm&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/asm.html "cpp/language/asm") for `asm` declaration  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/asm&action=edit&section=7 "Edit section: External links")] External links

1\.  | [GCC Inline Assembly HOWTO](https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html)  
---|---  
2\.  | [IBM XL C/C++ Inline Assembly](https://pic.dhe.ibm.com/infocenter/comphelp/v121v141/topic/com.ibm.xlcpp121.aix.doc/language_ref/asm.html)  
3\.  | [Intel C++ Inline Assembly](https://software.intel.com/en-us/cpp-compiler-developer-guide-and-reference-inline-assembly)  
4\.  | [Visual Studio Inline Assembler](https://learn.microsoft.com/en-us/cpp/assembler/inline/inline-assembler.aspx)  
5\.  | [Sun Studio 12 Asm Statements](https://blogs.oracle.com/x86be/entry/gcc_style_asm_inlining_support)  
6\.  | [Inline assembly for Itanium-based HP-UX](https://h21007.www2.hp.com/portal/site/dspp/menuitem.863c3e4cbcdc3f3515b49c108973a801?ciid=4308e2f5bde02110e2f5bde02110275d6e10RCRD)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/asm&oldid=178601](https://en.cppreference.com/mwiki/index.php?title=c/language/asm&oldid=178601)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



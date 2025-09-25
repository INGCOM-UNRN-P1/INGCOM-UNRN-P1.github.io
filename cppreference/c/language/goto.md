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

[ Statements](statements.html "c/language/statements")

Labels   
---  
[label : statement](statements.html#Labels "c/language/statements")  
Expression statements   
[expression ;](statements.html#Expression_statements "c/language/statements")  
Compound statements   
[{ statement... }](statements.html#Compound_statements "c/language/statements")  
Selection statements   
[if](if.html "c/language/if")  
[switch](switch.html "c/language/switch")  
Iteration statements   
[while](while.html "c/language/while")  
[do-while](do.html "c/language/do")  
[for](for.html "c/language/for")  
Jump statements   
[break](break.html "c/language/break")  
[continue](continue.html "c/language/continue")  
[return](return.html "c/language/return")  
**goto**  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/statements/navbar_content&action=edit)

Transfers control unconditionally to the desired location. 

Used when it is otherwise impossible to transfer control to the desired location using conventional constructs. 

## Contents

  * [1 Syntax](goto.html#Syntax)
  * [2 Explanation](goto.html#Explanation)
  * [3 Keywords](goto.html#Keywords)
  * [4 Notes](goto.html#Notes)
  * [5 Example](goto.html#Example)
  * [6 References](goto.html#References)
  * [7 See also](goto.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/goto&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
attr-spec-seq(optional) `**goto**` label `**;**` |  |   
label |  \-  |  target [label](statements.html#Labels "c/language/statements") for the `goto` statement   
---|---|---  
attr-spec-seq |  \-  |  (C23)optional list of [attributes](attributes.html "c/language/attributes"), applied to the `goto` statement   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/goto&action=edit&section=2 "Edit section: Explanation")] Explanation

The `goto` statement causes an unconditional jump (transfer of control) to the statement prefixed by the named label (which must appear in the same function as the goto statement), except when this jump would enter the scope of a [variable-length array](array.html "c/language/array") or another [variably-modified type](declarations.html "c/language/declarations").(since C99)

A label is an identifier followed by a colon (`**:**`) and a statement(until C23). Labels are the only identifiers that have _function scope_ : they can be used (in a goto statement) anywhere in the same function in which they appear. There may be multiple labels before any statement. 

Entering the scope of a non-variably modified variable is permitted: 
    
    
    goto lab1; // OK: going into the scope of a regular variable
        int n = 5;
    lab1:; // Note, n is uninitialized, as if declared by int n;
     
    //   goto lab2;   // Error: going into the scope of two VM types
         double a[n]; // a VLA
         int (*p)[n]; // a VM pointer
    lab2:

If `goto` leaves the scope of a VLA, it is deallocated (and may be reallocated if its initialization is executed again): 
    
    
    {
       int n = 1;
    label:;
       int a[n]; // re-allocated 10 times, each with a different size
       if (n++ < 10) goto label; // leaving the scope of a VM
    }

| (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/goto&action=edit&section=3 "Edit section: Keywords")] Keywords

[`goto`](../keyword/goto.html "c/keyword/goto")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/goto&action=edit&section=4 "Edit section: Notes")] Notes

Because declarations are not statements, a label before a declaration must use a null statement (a semicolon immediately after the colon). Same applies to a label before the end of a block.  | (until C23)  
---|---  
  
C++ imposes additional limitations on the `goto` statement, but allows labels before declarations (which are statements in C++). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/goto&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
     
    int main(void)
    {
        // goto can be used to leave a multi-level loop easily
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                [printf](../io/fprintf.html)("(%d;%d)\n",x,y);
                if (x + y >= 3) goto endloop;
            }
        }
    endloop:;
    }

Output: 
    
    
    (0;0)
    (0;1)
    (0;2)
    (1;0)
    (1;1)
    (1;2)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/goto&action=edit&section=6 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.8.6.1 The goto statement (p: 110-111) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.8.6.1 The goto statement (p: 152-153) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.8.6.1 The goto statement (p: 137-138) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.6.6.1 The goto statement 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/goto&action=edit&section=7 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/goto.html "cpp/language/goto") for `goto` statement  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/goto&oldid=130664](https://en.cppreference.com/mwiki/index.php?title=c/language/goto&oldid=130664)" 

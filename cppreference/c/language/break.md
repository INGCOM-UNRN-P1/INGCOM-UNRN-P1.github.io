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
**break**  
[continue](continue.html "c/language/continue")  
[return](return.html "c/language/return")  
[goto](goto.html "c/language/goto")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/statements/navbar_content&action=edit)

Causes the enclosing [for](for.html "c/language/for"), [while](while.html "c/language/while") or [do-while](do.html "c/language/do") loop or [switch statement](switch.html "c/language/switch") to terminate. 

Used when it is otherwise awkward to terminate the loop using the condition expression and conditional statements. 

## Contents

  * [1 Syntax](break.html#Syntax)
  * [2 Explanation](break.html#Explanation)
  * [3 Keywords](break.html#Keywords)
  * [4 Notes](break.html#Notes)
  * [5 Example](break.html#Example)
  * [6 References](break.html#References)
  * [7 See also](break.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/break&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
attr-spec-seq ﻿(optional) `**break**` `**;**` |  |   
attr-spec-seq |  \-  |  (C23) optional list of [attributes](attributes.html "c/language/attributes"), applied to the `break` statement   
---|---|---  
  
Appears only within the statement of a loop body ([`while`](while.html "c/language/while"), [`do-while`](do.html "c/language/do"), [`for`](for.html "c/language/for")) or within the statement of a [`switch`](switch.html "c/language/switch"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/break&action=edit&section=2 "Edit section: Explanation")] Explanation

After this statement the control is transferred to the statement or declaration immediately following the enclosing loop or switch, as if by [`goto`](goto.html "c/language/goto"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/break&action=edit&section=3 "Edit section: Keywords")] Keywords

[`break`](../keyword/break.html "c/keyword/break")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/break&action=edit&section=4 "Edit section: Notes")] Notes

A break statement cannot be used to break out of multiple nested loops. The [`goto` statement](goto.html "c/language/goto") may be used for this purpose. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/break&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
     
    int main(void)
    {
        int i = 2;
        switch (i)
        {
            case 1: [printf](../io/fprintf.html)("1");
            case 2: [printf](../io/fprintf.html)("2");   // i==2, so execution starts at this case label
            case 3: [printf](../io/fprintf.html)("3");
            case 4:
            case 5: [printf](../io/fprintf.html)("45");
                    break;         // execution of subsequent cases is terminated
            case 6: [printf](../io/fprintf.html)("6");
        }
        [printf](../io/fprintf.html)("\n");
     
        // Compare outputs from these two nested for loops.
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 5; k++)
                [printf](../io/fprintf.html)("%d%d ", j,k);
        [printf](../io/fprintf.html)("\n");
     
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 5; k++) // only this loop is exited by break
            {
                if (k == 2)
                    break;
                [printf](../io/fprintf.html)("%d%d ", j,k);
            }
        }
    }

Possible output: 
    
    
    2345
    00 01 02 03 04 10 11 12 13 14
    00 01 10 11

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/break&action=edit&section=6 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.8.6.3 The break statement (p: 111) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.8.6.3 The break statement (p: 153) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.8.6.3 The break statement (p: 138) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.6.6.3 The break statement 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/break&action=edit&section=7 "Edit section: See also")] See also

`[[[fallthrough](attributes/fallthrough.html "c/language/attributes/fallthrough")]]`(C23) |  indicates that the fall through from the previous case label is intentional and should not be diagnosed by a compiler that warns on fall-through  
(attribute specifier)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/dsc_fallthrough&action=edit)  
---|---  
[C++ documentation](../../cpp/language/break.html "cpp/language/break") for `break` statement  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/break&oldid=155195](https://en.cppreference.com/mwiki/index.php?title=c/language/break&oldid=155195)" 

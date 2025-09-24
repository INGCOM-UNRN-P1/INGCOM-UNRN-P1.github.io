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
**continue**  
[return](return.html "c/language/return")  
[goto](goto.html "c/language/goto")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/statements/navbar_content&action=edit)

Causes the remaining portion of the enclosing [for](for.html "c/language/for"), [while](while.html "c/language/while") or [ do-while](do.html "c/language/do") loop body to be skipped. 

Used when it is otherwise awkward to ignore the remaining portion of the loop using conditional statements. 

## Contents

  * [1 Syntax](continue.html#Syntax)
  * [2 Explanation](continue.html#Explanation)
  * [3 Keywords](continue.html#Keywords)
  * [4 Example](continue.html#Example)
  * [5 References](continue.html#References)
  * [6 See also](continue.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/continue&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
attr-spec-seq(optional) `**continue**` `**;**` |  |   
attr-spec-seq |  \-  |  (C23)optional list of [attributes](attributes.html "c/language/attributes"), applied to the `continue` statement   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/continue&action=edit&section=2 "Edit section: Explanation")] Explanation

The `continue` statement causes a jump, as if by [goto](goto.html "c/language/goto"), to the end of the loop body (it may only appear within the loop body of [for](for.html "c/language/for"), [while](while.html "c/language/while"), and [do-while](do.html "c/language/do") loops). 

For [while](while.html "c/language/while") loop, it acts as 
    
    
    while (/* ... */) {
       // ... 
       continue; // acts as goto contin;
       // ... 
       contin:;
    }

For [do-while](do.html "c/language/do") loop, it acts as: 
    
    
    do {
        // ... 
        continue; // acts as goto contin;
        // ... 
        contin:;
    } while (/* ... */);

For [for](for.html "c/language/for") loop, it acts as: 
    
    
    for (/* ... */) {
        // ... 
        continue; // acts as goto contin;
        // ... 
        contin:;
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/continue&action=edit&section=3 "Edit section: Keywords")] Keywords

[`continue`](../keyword/continue.html "c/keyword/continue")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/continue&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
     
    int main(void) 
    {
        for (int i = 0; i < 10; i++) {
            if (i != 5) continue;
            [printf](../io/fprintf.html)("%d ", i);             // this statement is skipped each time i != 5
        }
     
        [printf](../io/fprintf.html)("\n");
     
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 5; k++) { // only this loop is affected by continue
                if (k == 3) continue;
                [printf](../io/fprintf.html)("%d%d ", j, k);    // this statement is skipped each time k == 3
            }
        }
    }

Output: 
    
    
    5
    00 01 02 04 10 11 12 14

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/continue&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.8.6.2 The continue statement (p: 111) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.8.6.2 The continue statement (p: 153) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.8.6.2 The continue statement (p: 138) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.6.6.2 The continue statement 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/continue&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/continue.html "cpp/language/continue") for `continue` statement  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/continue&oldid=130663](https://en.cppreference.com/mwiki/index.php?title=c/language/continue&oldid=130663)" 

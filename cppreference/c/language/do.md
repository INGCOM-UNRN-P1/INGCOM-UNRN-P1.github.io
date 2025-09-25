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
**do-while**  
[for](for.html "c/language/for")  
Jump statements   
[break](break.html "c/language/break")  
[continue](continue.html "c/language/continue")  
[return](return.html "c/language/return")  
[goto](goto.html "c/language/goto")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/statements/navbar_content&action=edit)

Executes a statement repeatedly until the value of the condition expression becomes false. The test takes place after each iteration. 

## Contents

  * [1 Syntax](do.html#Syntax)
  * [2 Explanation](do.html#Explanation)
  * [3 Notes](do.html#Notes)
  * [4 Keywords](do.html#Keywords)
  * [5 Example](do.html#Example)
  * [6 References](do.html#References)
  * [7 See also](do.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/do&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
attr-spec-seq ﻿(optional) `**do**` statement `**while (**` expression `**)**` `**;**` |  |   
attr-spec-seq |  \-  |  (C23) an optional list of [attributes](attributes.html "c/language/attributes"), applied to the loop statement.   
---|---|---  
statement |  \-  |  any [statement](statements.html "c/language/statements"), typically a compound statement, which is the body of the loop.   
expression |  \-  |  any [expression](operators.html "c/language/expressions") of [scalar type](compatible_type.html#Type_groups "c/language/type"). This expression is evaluated after each iteration, and if it compares equal to zero, the loop is exited.   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/do&action=edit&section=2 "Edit section: Explanation")] Explanation

A do-while statement causes the statement (also called _the loop body_) to be executed repeatedly until the expression (also called _controlling expression_) compares equal to ​0​. The repetition occurs regardless of whether the loop body is entered normally or by a [goto](goto.html "c/language/goto") into the middle of statement. 

The evaluation of expression takes place after each execution of statement (whether entered normally or by a goto). If the controlling expression needs to be evaluated before the loop body, the [while loop](while.html "c/language/while") or the [for loop](for.html "c/language/for") may be used. 

If the execution of the loop needs to be terminated at some point, [break statement](break.html "c/language/break") can be used as terminating statement. 

If the execution of the loop needs to be continued at the end of the loop body, [continue statement](continue.html "c/language/continue") can be used as a shortcut. 

A program with an endless loop has undefined behavior if the loop has no observable behavior (I/O, volatile accesses, atomic or synchronization operation) in any part of its statement or expression. This allows the compilers to optimize out all unobservable loops without proving that they terminate. The only exceptions are the loops where expression is a constant expression; do {...} while(true); is always an endless loop. 

As with all other selection and iteration statements, the `do-while` statement establishes [block scope](scope.html "c/language/scope"): any identifier introduced in the expression goes out of scope after the statement.  | (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/do&action=edit&section=3 "Edit section: Notes")] Notes

Boolean and pointer expressions are often used as loop controlling expressions. The boolean value false and the null pointer value of any pointer type compare equal to zero. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/do&action=edit&section=4 "Edit section: Keywords")] Keywords

[`do`](../keyword/do.html "c/keyword/do"), [`while`](../keyword/while.html "c/keyword/while")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/do&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    enum { SIZE = 8 };
     
    int main(void)
    {
        // trivial example
        int array[SIZE], n = 0;
     
        do array[n++] = [rand](../numeric/random/rand.html)() % 2; // the loop body is a single expression statement
        while(n < SIZE);
     
        [puts](../io/puts.html)("Array filled!");
        n = 0;
     
        do
        { // the loop body is a compound statement
            [printf](../io/fprintf.html)("%d ", array[n]);
            ++n;
        } while (n < SIZE);
     
        [printf](../io/fprintf.html)("\n");
     
        // the loop from K&R itoa(). The do-while loop is used
        // because there is always at least one digit to generate
        int num = 1234, i=0;
        char s[10];
     
        do s[i++] = num % 10 + '0'; // get next digit in reverse order
        while ((num /= 10) > 0);
     
        s[i] = '\0';
        [puts](../io/puts.html)(s);
    }

Possible output: 
    
    
    Array filled!
    1 0 1 1 1 1 0 0
    4321

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/do&action=edit&section=6 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.8.6.3 The do statement (p: 156) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.8.5.2 The do statement (p: 109) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.8.5.2 The do statement (p: 151) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.8.5.2 The do statement (p: 136) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.6.5.2 The do statement 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/do&action=edit&section=7 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/do.html "cpp/language/do") for do-while loop  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/do&oldid=183392](https://en.cppreference.com/mwiki/index.php?title=c/language/do&oldid=183392)" 

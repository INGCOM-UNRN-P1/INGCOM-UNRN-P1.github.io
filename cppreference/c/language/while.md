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
**while**  
[do-while](do.html "c/language/do")  
[for](for.html "c/language/for")  
Jump statements   
[break](break.html "c/language/break")  
[continue](continue.html "c/language/continue")  
[return](return.html "c/language/return")  
[goto](goto.html "c/language/goto")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/statements/navbar_content&action=edit)

Executes a statement repeatedly, until the value of expression becomes equal to zero. The test takes place before each iteration. 

## Contents

  * [1 Syntax](while.html#Syntax)
  * [2 Explanation](while.html#Explanation)
  * [3 Notes](while.html#Notes)
  * [4 Keywords](while.html#Keywords)
  * [5 Example](while.html#Example)
  * [6 References](while.html#References)
  * [7 See also](while.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/while&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
attr-spec-seq(optional) `**while (**` expression `**)**` statement |  |   
expression |  \-  |  any [expression](operators.html "c/language/expressions") of [scalar type](compatible_type.html#Type_groups "c/language/type"). This expression is evaluated before each iteration, and if it compares equal to zero, the loop is exited.   
---|---|---  
statement |  \-  |  any [statement](statements.html "c/language/statements"), typically a compound statement, which serves as the body of the loop   
attr-spec-seq |  \-  |  (C23)optional list of [attributes](attributes.html "c/language/attributes"), applied to the loop statement   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/while&action=edit&section=2 "Edit section: Explanation")] Explanation

A `while` statement causes the statement (also called _the loop body_) to be executed repeatedly until the expression (also called _controlling expression_) compares equal to zero. The repetition occurs regardless of whether the loop body is entered normally or by a [goto](goto.html "c/language/goto") into the middle of statement. 

The evaluation of expression takes place before each execution of statement (unless entered by a goto). If the controlling expression needs to be evaluated after the loop body, the [do-while loop](do.html "c/language/do") may be used. 

If the execution of the loop needs to be terminated at some point, [ break statement](break.html "c/language/break") can be used as a terminating statement. 

If the execution of the loop needs to be continued at the end of the loop body, [ continue statement](continue.html "c/language/continue") can be used as a shortcut. 

A program with an endless loop has undefined behavior if the loop has no observable behavior (I/O, volatile accesses, atomic or synchronization operation) in any part of its statement or expression. This allows the compilers to optimize out all unobservable loops without proving that they terminate. The only exceptions are the loops where expression is a constant expression; while(true) is always an endless loop. 

As with all other selection and iteration statements, the while statement establishes [block scope](scope.html "c/language/scope"): any identifier introduced in the expression goes out of scope after the statement.  | (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/while&action=edit&section=3 "Edit section: Notes")] Notes

Boolean and pointer expressions are often used as loop controlling expressions. The boolean value `false` and the null pointer value of any pointer type compare equal to zero. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/while&action=edit&section=4 "Edit section: Keywords")] Keywords

[`while`](../keyword/while.html "c/keyword/while")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/while&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    enum { SIZE = 8 };
    int main(void)
    {
        // trivial example
        int array[SIZE], n = 0;
        while(n < SIZE) array[n++] = [rand](../numeric/random/rand.html)() % 2;
        [puts](../io/puts.html)("Array filled!");
        n = 0;
        while(n < SIZE) [printf](../io/fprintf.html)("%d ", array[n++]);
        [printf](../io/fprintf.html)("\n");
     
        // classic strcpy() implementation
        // (copies a null-terminated string from src to dst)
        char src[] = "Hello, world", dst[sizeof src], *p = dst, *q = src;
        while((*p++ = *q++)) // double parentheses (that are not strictly necessary)
                             // used to suppress warnings, ensuring that this is an
                             // assignment (as opposed to a comparison) by intention,
                             // whose result is used as a truth value
            ; // null statement
        [puts](../io/puts.html)(dst);
    }

Output: 
    
    
    Array filled!
    1 0 1 1 1 1 0 0 
    Hello, world

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/while&action=edit&section=6 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.8.5.1 The while statement (p: 109) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.8.5.1 The while statement (p: 151) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.8.5.1 The while statement (p: 136) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.6.5.1 The while statement 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/while&action=edit&section=7 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/while.html "cpp/language/while") for `while` loop  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/while&oldid=147751](https://en.cppreference.com/mwiki/index.php?title=c/language/while&oldid=147751)" 

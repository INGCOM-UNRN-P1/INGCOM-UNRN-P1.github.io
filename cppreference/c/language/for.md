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
**for**  
Jump statements   
[break](break.html "c/language/break")  
[continue](continue.html "c/language/continue")  
[return](return.html "c/language/return")  
[goto](goto.html "c/language/goto")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/statements/navbar_content&action=edit)

Executes a loop. 

Used as a shorter equivalent of [while loop](while.html "c/language/while"). 

## Contents

  * [1 Syntax](for.html#Syntax)
  * [2 Explanation](for.html#Explanation)
  * [3 Keywords](for.html#Keywords)
  * [4 Notes](for.html#Notes)
  * [5 Example](for.html#Example)
  * [6 References](for.html#References)
  * [7 See also](for.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/for&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
attr-spec-seq(since C23)(optional) `**for**` `**(**` init-clause `**;**` cond-expression `**;**` iteration-expression `**)**` loop-statement |  |   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/for&action=edit&section=2 "Edit section: Explanation")] Explanation

Behaves as follows: 

  * init-clause may be an expression or a declaration(since C99). 



    

  * An init-clause, which is an expression, is evaluated once, before the first evaluation of cond-expression and its result is discarded. 



    

  * An init-clause, which is a declaration, is in scope in the entire loop body, including the remainder of init-clause, the entire cond-expression, the entire iteration-expression and the entire loop-statement. Only `auto` and `register` [storage class specifiers](storage_class_specifiers.html "c/language/storage duration") are allowed for the variables declared in this declaration. 


| (since C99)  
---|---  
  
  * cond-expression is evaluated before the loop body. If the result of the expression is zero, the loop statement is exited immediately. 
  * iteration-expression is evaluated after the loop body and its result is discarded. After evaluating iteration-expression, control is transferred to cond-expression. 



init-clause, cond-expression, and iteration-expression are all optional. If cond-expression is omitted, it is replaced with a non-zero integer constant, which makes the loop endless: 
    
    
    for(;;) {
       [printf](../io/fprintf.html)("endless loop!");
    }

loop-statement is not optional, but it may be a null statement: 
    
    
    for(int n = 0; n < 10; ++n, [printf](../io/fprintf.html)("%d\n", n))
        ; // null statement

If the execution of the loop needs to be terminated at some point, a [ break statement](break.html "c/language/break") can be used anywhere within the loop-statement. 

The [ continue statement](continue.html "c/language/continue") used anywhere within the loop-statement transfers control to iteration-expression. 

A program with an endless loop has undefined behavior if the loop has no observable behavior (I/O, volatile accesses, atomic or synchronization operation) in any part of its cond-expression, iteration-expression or loop-statement. This allows the compilers to optimize out all unobservable loops without proving that they terminate. The only exceptions are the loops where cond-expression is omitted or is a constant expression; for(;;) is always an endless loop. 

As with all other selection and iteration statements, the for statement establishes [block scope](scope.html "c/language/scope"): any identifier introduced in the init-clause, cond-expression, or iteration-expression goes out of scope after the loop-statement.  | (since C99)  
---|---  
attr-spec-seq is an optional list of [attributes](attributes.html "c/language/attributes"), applied to the `for` statement.  | (since C23)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/for&action=edit&section=3 "Edit section: Keywords")] Keywords

[`for`](../keyword/for.html "c/keyword/for")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/for&action=edit&section=4 "Edit section: Notes")] Notes

The expression statement used as loop-statement establishes its own block scope, distinct from the scope of init-clause, unlike in C++: 
    
    
    for (int i = 0; ; ) {
        long i = 1;   // valid C, invalid C++
        // ...
    }

It is possible to enter the body of a loop using [goto](goto.html "c/language/goto"). When entering a loop in this manner, init-clause and cond-expression are not executed. (If control then reaches the end of the loop body, repetition may occur including execution of cond-expression.) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/for&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
    enum { SIZE = 8 };
    int main(void)
    {
        int array[SIZE];
        for([size_t](../types/size_t.html) i = 0 ; i < SIZE; ++i)
            array [i] = [rand](../numeric/random/rand.html)() % 2;
        [printf](../io/fprintf.html)("Array filled!\n");
        for ([size_t](../types/size_t.html) i = 0; i < SIZE; ++i)
            [printf](../io/fprintf.html)("%d ", array[i]);
        [putchar](../io/putchar.html)('\n');
    }

Possible output: 
    
    
    Array filled!
    1 0 1 1 1 1 0 0

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/for&action=edit&section=6 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.8.5.3 The for statement (p: 110) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.8.5.3 The for statement (p: 151) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.8.5.3 The for statement (p: 136) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.6.5.3 The for statement 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/for&action=edit&section=7 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/for.html "cpp/language/for") for `for` loop  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/for&oldid=135651](https://en.cppreference.com/mwiki/index.php?title=c/language/for&oldid=135651)" 

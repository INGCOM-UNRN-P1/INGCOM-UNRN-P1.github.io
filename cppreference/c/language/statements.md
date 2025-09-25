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
**Statements**  
[ Expressions](operators.html "c/language/expressions")  
[ Initialization](initialization.html "c/language/initialization")  
[ Declarations](declarations.html "c/language/declarations")  
[ Functions](functions.html "c/language/functions")  
Miscellaneous  
[ History of C](history.html "c/language/history")  
[Technical Specifications](../experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

**Statements**

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
[goto](goto.html "c/language/goto")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/statements/navbar_content&action=edit)

Statements are fragments of the C program that are executed in sequence. The body of any function is a compound statement, which, in turn is a sequence of statements and declarations: 
    
    
    int main(void)
    { // start of a compound statement
        int n = 1; // declaration (not a statement)
        n = n+1; // expression statement
        [printf](../io/fprintf.html)("n = %d\n", n); // expression statement
        return 0; // return statement
    } // end of compound statement, end of function body

  
There are five types of statements: 

1) [compound statements](statements.html#Compound_statements)

2) [expression statements](statements.html#Expression_statements)

3) [selection statements](statements.html#Selection_statements)

4) [iteration statements](statements.html#Iteration_statements)

5) [jump statements](statements.html#Jump_statements)

An [attribute specifier sequence](attributes.html "c/language/attributes") (attr-spec-seq) can be applied to an unlabeled statement, in which case (except for an expression statement) the attributes are applied to the respective statement.  | (since C23)  
---|---  
  
## Contents

  * [1 Labels](statements.html#Labels)
  * [2 Compound statements](statements.html#Compound_statements)
  * [3 Expression statements](statements.html#Expression_statements)
  * [4 Selection statements](statements.html#Selection_statements)
  * [5 Iteration statements](statements.html#Iteration_statements)
  * [6 Jump statements](statements.html#Jump_statements)
  * [7 References](statements.html#References)
  * [8 See also](statements.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/statements&action=edit&section=1 "Edit section: Labels")] Labels

Any statement can be _labeled_ , by providing a name followed by a colon before the statement itself.   
  
---  
attr-spec-seq(optional)(since C23) identifier `**:**` |  (1)  |   
attr-spec-seq(optional)(since C23) `**case**` constant-expression `**:**` |  (2)  |   
attr-spec-seq(optional)(since C23) `**default**` `**:**` |  (3)  |   
  
1) Target for [goto](goto.html "c/language/goto").

2) Case label in a [switch](switch.html "c/language/switch") statement.

3) Default label in a [switch](switch.html "c/language/switch") statement.

Any statement (but not a declaration) may be preceded by any number of _labels_ , each of which declares identifier to be a label name, which must be unique within the enclosing function (in other words, label names have [function scope](scope.html "c/language/scope")). 

Label declaration has no effect on its own, does not alter the flow of control, or modify the behavior of the statement that follows in any way. 

A label shall be followed by a statement.  | (until C23)  
---|---  
A label can appear without its following statement. If a label appears alone in a block, it behaves as if it is followed by a [null statement](statements.html#Expression_statements). The optional [attr-spec-seq](attributes.html "c/language/attributes") is applied to the label.  | (since C23)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/statements&action=edit&section=2 "Edit section: Compound statements")] Compound statements

A compound statement, or _block_ , is a brace-enclosed sequence of statements and declarations.   
  
---  
`**{**` statement `|` declaration...(optional) `**}**` |  |  (until C23)  
attr-spec-seq(optional) `**{**` unlabeled-statement `|` label `|` declaration...(optional) `**}**` |  |  (since C23)  
  
The compound statement allows a set of declarations and statements to be grouped into one unit that can be used anywhere a single statement is expected (for example, in an [if](if.html "c/language/if") statement or an iteration statement): 
    
    
    if (expr) // start of if-statement
    { // start of block
      int n = 1; // declaration
      [printf](../io/fprintf.html)("%d\n", n); // expression statement
    } // end of block, end of if-statement

Each compound statement introduces its own [block scope](scope.html "c/language/scope"). 

The initializers of the variables with automatic [storage duration](storage_class_specifiers.html "c/language/storage duration") declared inside a block and the VLA declarators are executed when flow of control passes over these declarations in order, as if they were statements: 
    
    
    int main(void)
    { // start of block
      { // start of block
           [puts](../io/puts.html)("hello"); // expression statement
           int n = [printf](../io/fprintf.html)("abc\n"); // declaration, prints "abc", stores 4 in n
           int a[n*[printf](../io/fprintf.html)("1\n")]; // declaration, prints "1", allocates 8*sizeof(int)
           [printf](../io/fprintf.html)("%zu\n", sizeof(a)); // expression statement
      } // end of block, scope of n and a ends
      int n = 7; // n can be reused
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/statements&action=edit&section=3 "Edit section: Expression statements")] Expression statements

An expression followed by a semicolon is a statement.   
  
---  
expression(optional) `**;**` |  (1)  |   
attr-spec-seq expression `**;**` |  (2)  |  (since C23)  
  
Most statements in a typical C program are expression statements, such as assignments or function calls. 

An expression statement without an expression is called a _null statement_. It is often used to provide an empty body to a [for](for.html "c/language/for") or [while](while.html "c/language/while") loop. It can also be used to carry a label in the end of a compound statement or before a declaration: 
    
    
    [puts](../io/puts.html)("hello"); // expression statement
    char *s;
    while (*s++ != '\0')
        ; // null statement

The optional [attr-spec-seq](attributes.html "c/language/attributes") is applied to the expression. An attr-spec-seq followed by `**;**` does not form an expression statement. It forms an [attribute declaration](declarations.html "c/language/declarations") instead.  | (since C23)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/statements&action=edit&section=4 "Edit section: Selection statements")] Selection statements

The selection statements choose between one of several statements depending on the value of an expression.   
  
---  
attr-spec-seq(optional)(since C23) `**if**` `**(**` expression `**)**` statement |  (1)  |   
attr-spec-seq(optional)(since C23) `**if**` `**(**` expression `**)**` statement `**else**` statement |  (2)  |   
attr-spec-seq(optional)(since C23) `**switch**` `**(**` expression `**)**` statement |  (3)  |   
  
1) [if](if.html "c/language/if") statement

2) [if](if.html "c/language/if") statement with an else clause

3) [switch](switch.html "c/language/switch") statement

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/statements&action=edit&section=5 "Edit section: Iteration statements")] Iteration statements

The iteration statements repeatedly execute a statement.   
  
---  
attr-spec-seq(optional)(since C23) `**while**` `**(**` expression `**)**` statement |  (1)  |   
attr-spec-seq(optional)(since C23) `**do**` statement `**while**` `**(**` expression `**)**` `**;**` |  (2)  |   
attr-spec-seq(optional)(since C23) `**for**` `**(**` init-clause `**;**` expression(optional) `**;**` expression(optional) `**)**` statement |  (3)  |   
  
1) [while](while.html "c/language/while") loop

2) [do-while](do.html "c/language/do") loop

3) [for](for.html "c/language/for") loop

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/statements&action=edit&section=6 "Edit section: Jump statements")] Jump statements

The jump statements unconditionally transfer flow control.   
  
---  
attr-spec-seq(optional)(since C23) `**break**` `**;**` |  (1)  |   
attr-spec-seq(optional)(since C23) `**continue**` `**;**` |  (2)  |   
attr-spec-seq(optional)(since C23) `**return**` expression(optional) `**;**` |  (3)  |   
attr-spec-seq(optional)(since C23) `**goto**` identifier `**;**` |  (4)  |   
  
1) [break](break.html "c/language/break") statement

2) [continue](continue.html "c/language/continue") statement

3) [return](return.html "c/language/return") statement with an optional expression

4) [goto](goto.html "c/language/goto") statement

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/statements&action=edit&section=7 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.8 Statements and blocks (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.8 Statements and blocks (p: 106-112) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.8 Statements and blocks (p: 146-154) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.8 Statements and blocks (p: 131-139) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.6 STATEMENTS 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/statements&action=edit&section=8 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/statements.html "cpp/language/statements") for Statements  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/statements&oldid=179343](https://en.cppreference.com/mwiki/index.php?title=c/language/statements&oldid=179343)" 

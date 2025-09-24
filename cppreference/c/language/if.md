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
**if**  
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

Conditionally executes code. 

Used where code needs to be executed only if some condition is true. 

## Contents

  * [1 Syntax](if.html#Syntax)
  * [2 Explanation](if.html#Explanation)
  * [3 Notes](if.html#Notes)
  * [4 Keywords](if.html#Keywords)
  * [5 Example](if.html#Example)
  * [6 References](if.html#References)
  * [7 See also](if.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/if&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
attr-spec-seq ﻿(optional) `**if (**` expression `**)**` statement-true |  (1)  |   
attr-spec-seq ﻿(optional) `**if (**` expression `**)**` statement-true `**else**` statement-false |  (2)  |   
attr-spec-seq |  \-  |  (C23) an optional list of [attributes](attributes.html "c/language/attributes"), applied to the if statement   
---|---|---  
expression |  \-  |  an [expression](operators.html "c/language/expressions") of any scalar type   
statement-true |  \-  |  any [statement](statements.html "c/language/statements") (often a compound statement), which is executed if expression compares not equal to ​0​  
statement-false |  \-  |  any [statement](statements.html "c/language/statements") (often a compound statement), which is executed if expression compares equal to ​0​  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/if&action=edit&section=2 "Edit section: Explanation")] Explanation

expression must be an expression of any [scalar type](compatible_type.html#Type_groups "c/language/type"). 

If expression compares not equal to the integer zero, statement-true is executed. 

In the form (2), if expression compares equal to the integer zero, statement-false is executed. 

As with all other selection and iteration statements, the entire if-statement has its own block scope: 
    
    
    enum {a, b};
     
    int different(void)
    {
        if (sizeof(enum {b, a}) != sizeof(int))
            return a; // a == 1
        return b; // b == 0 in C89, b == 1 in C99
    }

| (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/if&action=edit&section=3 "Edit section: Notes")] Notes

The else is always associated with the closest preceding if (in other words, if statement-true is also an if statement, then that inner if statement must contain an else part as well): 
    
    
    int j = 1;
    if (i > 1)
        if(j > 2)
            [printf](../io/fprintf.html)("%d > 1 and %d > 2\n", i, j);
        else // this else is part of if (j > 2), not part of if (i > 1)
            [printf](../io/fprintf.html)("%d > 1 and %d <= 2\n", i, j);

If statement-true is entered through a [goto](goto.html "c/language/goto"), statement-false is not executed. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/if&action=edit&section=4 "Edit section: Keywords")] Keywords

[`if`](../keyword/if.html "c/keyword/if"), [`else`](../keyword/else.html "c/keyword/else")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/if&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
     
    int main(void)
    {
        int i = 2;
        if (i > 2)
        {
            [printf](../io/fprintf.html)("i > 2 is true\n");
        }
        else
        {
            [printf](../io/fprintf.html)("i > 2 is false\n");
        }
     
        i = 3;
        if (i == 3)
            [printf](../io/fprintf.html)("i == 3\n");
     
        if (i != 3)
            [printf](../io/fprintf.html)("i != 3 is true\n");
        else
            [printf](../io/fprintf.html)("i != 3 is false\n");
    }

Output: 
    
    
    i > 2 is false
    i == 3
    i != 3 is false

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/if&action=edit&section=6 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.8.5.2 The if statement (p: 154) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.8.4.1 The if statement (p: 108-109) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.8.4.1 The if statement (p: 148-149) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.8.4.1 The if statement (p: 133-134) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.6.4.1 The if statement 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/if&action=edit&section=7 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/if.html "cpp/language/if") for if statement  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/if&oldid=183393](https://en.cppreference.com/mwiki/index.php?title=c/language/if&oldid=183393)" 

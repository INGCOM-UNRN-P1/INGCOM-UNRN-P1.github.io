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
**return**  
[goto](goto.html "c/language/goto")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/statements/navbar_content&action=edit)

Terminates current function and returns specified value to the caller function. 

## Contents

  * [1 Syntax](return.html#Syntax)
  * [2 Explanation](return.html#Explanation)
  * [3 Keywords](return.html#Keywords)
  * [4 Example](return.html#Example)
  * [5 References](return.html#References)
  * [6 See also](return.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/return&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
attr-spec-seq(optional) `**return**` expression `**;**` |  (1)  |   
attr-spec-seq(optional) `**return**` `**;**` |  (2)  |   
expression |  \-  |  expression used for initializing the return value of the function   
---|---|---  
attr-spec-seq |  \-  |  (C23)optional list of [attributes](attributes.html "c/language/attributes"), applied to the `return` statement   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/return&action=edit&section=2 "Edit section: Explanation")] Explanation

1) Evaluates the expression, terminates the current function and returns the result of the expression to the caller (the value returned becomes the value of the function call expression). Only valid if the function return type is not void.

2) Terminates the current function. Only valid if the function return type is void.

If the type of the expression is different from the return type of the function, its value is [converted](conversion.html "c/language/conversion") as if by assignment to an object whose type is the return type of the function, except that overlap between object representations is permitted: 
    
    
    struct s { double i; } f(void); // function returning struct s
    union { struct { int f1; struct s f2; } u1;
            struct { struct s f3; int f4; } u2; } g;
    struct s f(void)
    {
        return g.u1.f2;
    }
    int main(void)
    {
    // g.u2.f3 = g.u1.f2; // undefined behavior (overlap in assignment)
       g.u2.f3 = f();     // well-defined
    }

If the return type is a real floating type, the result may be represented in [greater range and precision](../types/limits/FLT_EVAL_METHOD.html "c/types/limits/FLT EVAL METHOD") than implied by the new type. 

Reaching the end of a function returning void is equivalent to return;. Reaching the end of any other value-returning function is undefined behavior if the result of the function is used in an expression (it is allowed to discard such return value). For `main`, see [`main` function](main_function.html "c/language/main function"). 

Executing the `return` statement in a [no-return function](noreturn.html "c/language/ Noreturn") is undefined behavior.  | (since C11)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/return&action=edit&section=3 "Edit section: Keywords")] Keywords

[`return`](../keyword/return.html "c/keyword/return")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/return&action=edit&section=4 "Edit section: Example")] Example

| This section is incomplete  
Reason: improve   
---|---  
  
Run this code
    
    
    #include <stdio.h>
     
    void fa(int i)
    {
        if (i == 2)
           return;
        [printf](../io/fprintf.html)("fa():   %d\n", i);
    } // implied return;
     
    int fb(int i)
    {
        if (i > 4)
           return 4;
        [printf](../io/fprintf.html)("fb():   %d\n", i);
        return 2;
    }
     
    int main(void)
    {
        fa(2);
        fa(1);
        int i = fb(5);   // the return value 4 used to initializes i
        i = fb(i);       // the return value 2 used as rhs of assignment
        [printf](../io/fprintf.html)("main(): %d\n", i);
    }

Output: 
    
    
    fa():   1
    fb():   4
    main(): 2

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/return&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.8.6.4 The return statement (p: 111-112) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.8.6.4 The return statement (p: 154) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.8.6.4 The return statement (p: 139) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.6.6.4 The return statement 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/return&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/return.html "cpp/language/return") for `return` statement  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/return&oldid=130665](https://en.cppreference.com/mwiki/index.php?title=c/language/return&oldid=130665)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



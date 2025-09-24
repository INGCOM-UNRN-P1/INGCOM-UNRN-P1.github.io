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
**switch**  
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

Executes code according to the value of an integral argument. 

Used where one or several out of many branches of code need to be executed according to an integral value. 

## Contents

  * [1 Syntax](switch.html#Syntax)
  * [2 Explanation](switch.html#Explanation)
  * [3 Keywords](switch.html#Keywords)
  * [4 Example](switch.html#Example)
  * [5 References](switch.html#References)
  * [6 See also](switch.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/switch&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
attr-spec-seq(optional) `**switch (**` expression `**)**` statement |  |   
attr-spec-seq |  \-  |  (C23)optional list of [attributes](attributes.html "c/language/attributes"), applied to the `switch` statement   
---|---|---  
expression |  \-  |  any [expression](operators.html "c/language/expressions") of [integer type](compatible_type.html#Type_groups "c/language/type") (char, signed or unsigned integer, or enumeration)   
statement |  \-  |  any [statement](statements.html "c/language/statements") (typically a compound statement). `**case:**` and `**default:**` labels are permitted in statement, and break; statement has special meaning.   
---  
`**case**` constant-expression `**:**` statement |  (1)  |  (until C23)  
attr-spec-seq(optional) `**case**` constant-expression `**:**` statement(optional) |  (1)  |  (since C23)  
`**default**` `**:**` statement |  (2)  |  (until C23)  
attr-spec-seq(optional) `**default**` `**:**` statement(optional) |  (2)  |  (since C23)  
constant-expression |  \-  |  any integer [constant expression](constant_expression.html "c/language/constant expression")  
---|---|---  
attr-spec-seq |  \-  |  (C23)optional list of [attributes](attributes.html "c/language/attributes"), applied to the label   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/switch&action=edit&section=2 "Edit section: Explanation")] Explanation

The body of a switch statement may have an arbitrary number of `case:` labels, as long as the values of all constant-expressions are unique (after [conversion](conversion.html "c/language/conversion") to the [promoted type](conversion.html#Integer_promotions "c/language/conversion") of expression). At most one `default:` label may be present (although nested switch statements may use their own `default:` labels or have `case:` labels whose constants are identical to the ones used in the enclosing switch). 

If expression evaluates to the value that is equal to the value of one of constant-expressions after conversion to the promoted type of expression, then control is transferred to the statement that is labeled with that constant-expression. 

If expression evaluates to a value that doesn't match any of the `case:` labels, and the `default:` label is present, control is transferred to the statement labeled with the `default:` label. 

If expression evaluates to a value that doesn't match any of the `case:` labels, and the `default:` label is not present, none of the switch body is executed. 

The [break](break.html "c/language/break") statement, when encountered anywhere in statement, exits the switch statement: 
    
    
    switch(1) {
        case 1 : [puts](../io/puts.html)("1"); // prints "1",
        case 2 : [puts](../io/puts.html)("2"); // then prints "2" ("fall-through")
    }
    
    
    switch(1) {
        case 1 : [puts](../io/puts.html)("1"); // prints "1"
                 break;     // and exits the switch
        case 2 : [puts](../io/puts.html)("2");
                 break;
    }

As with all other selection and iteration statements, the switch statement establishes [block scope](scope.html "c/language/scope"): any identifier introduced in the expression goes out of scope after the statement. If a VLA or another identifier with variably-modified type has a `case:` or a `default:` label within its scope, the entire switch statement must be in its scope (in other words, a VLA must be declared either before the entire switch or after the last label): 
    
    
    switch (expr)
    {
            int i = 4; // not a VLA; OK to declare here
            f(i); // never called
    //      int a[i]; // error: VLA cannot be declared here
        case 0:
            i = 17;
        default:
            int a[i]; // OK to declare VLA here
            [printf](../io/fprintf.html)("%d\n", i); // prints 17 if expr == 0, prints indeterminate value otherwise
    }

| (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/switch&action=edit&section=3 "Edit section: Keywords")] Keywords

[`switch`](../keyword/switch.html "c/keyword/switch"), [`case`](../keyword/case.html "c/keyword/case"), [`default`](../keyword/default.html "c/keyword/default")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/switch&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
     
    void func(int x)
    {
       [printf](../io/fprintf.html)("func(%d): ", x);
       switch(x)
       {
          case 1: [printf](../io/fprintf.html)("case 1, ");
          case 2: [printf](../io/fprintf.html)("case 2, ");
          case 3: [printf](../io/fprintf.html)("case 3.\n"); break;
          case 4: [printf](../io/fprintf.html)("case 4, ");
          case 5:
          case 6: [printf](../io/fprintf.html)("case 5 or case 6, ");
          default: [printf](../io/fprintf.html)("default.\n");
       }
    }
     
    int main(void)
    {
       for(int i = 1; i < 9; ++i) func(i);
    }

Output: 
    
    
    func(1): case 1, case 2, case 3.
    func(2): case 2, case 3.
    func(3): case 3.
    func(4): case 4, case 5 or case 6, default.
    func(5): case 5 or case 6, default.
    func(6): case 5 or case 6, default.
    func(7): default.
    func(8): default.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/switch&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.8.4.2 The switch statement (p: 108-109) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.8.4.2 The switch statement (p: 149-150) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.8.4.2 The switch statement (p: 134-135) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.6.4.2 The switch statement 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/switch&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/switch.html "cpp/language/switch") for `switch` statement  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/switch&oldid=138532](https://en.cppreference.com/mwiki/index.php?title=c/language/switch&oldid=138532)" 

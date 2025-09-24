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

[ Expressions](operators.html "c/language/expressions")

General  
---  
[Value category](value_category.html "c/language/value category")  
[Evaluation order and sequence points](eval_order.html "c/language/eval order")  
[Constant expressions](constant_expression.html "c/language/constant expression")  
[Implicit conversions](conversion.html "c/language/conversion")  
[Generic selection](generic.html "c/language/generic") (C11)  
[Constants and literals](operators.html#Constants_and_literals "c/language/expressions")  
[Integer constant](integer_constant.html "c/language/integer constant")  
[Floating constant](floating_constant.html "c/language/floating constant")  
[Character constant](character_constant.html "c/language/character constant")  
[`true`/`false`](bool_constant.html "c/language/bool constant")(C23)  
[`nullptr`](nullptr.html "c/language/nullptr")(C23)  
[String literal](string_literal.html "c/language/string literal")  
[Compound literal](compound_literal.html "c/language/compound literal") (C99)  
[Operators](operators.html#Operators "c/language/expressions")  
[Operator precedence](operator_precedence.html "c/language/operator precedence")  
[Member access and indirection](operator_member_access.html "c/language/operator member access")  
[Logical operators](operator_logical.html "c/language/operator logical")  
[Comparison operators](operator_comparison.html "c/language/operator comparison")  
[Arithmetic operators](operator_arithmetic.html "c/language/operator arithmetic")  
[Assignment operators](operator_assignment.html "c/language/operator assignment")  
[Increment and decrement](operator_incdec.html "c/language/operator incdec")  
[Function call, comma, conditional operator](operator_other.html "c/language/operator other")  
**sizeof**  
[`_Alignof`](alignof.html "c/language/ Alignof")(C11*)  
[Cast operators](cast.html "c/language/cast")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

Queries size of the object or type. 

Used when actual size of the object must be known. 

## Contents

  * [1 Syntax](sizeof.html#Syntax)
  * [2 Explanation](sizeof.html#Explanation)
  * [3 Notes](sizeof.html#Notes)
  * [4 Keywords](sizeof.html#Keywords)
  * [5 Example](sizeof.html#Example)
  * [6 References](sizeof.html#References)
  * [7 See also](sizeof.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/sizeof&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**sizeof(**` type `**)**` |  (1)  |   
`**sizeof**` expression `` |  (2)  |   
  
Both versions return a value of type [size_t](../types/size_t.html "c/types/size t"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/sizeof&action=edit&section=2 "Edit section: Explanation")] Explanation

1) Returns the size, in bytes, of the [object representation](object.html#Object_representation "c/language/object") of type

2) Returns the size, in bytes, of the object representation of the type of expression. No implicit conversions are applied to expression.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/sizeof&action=edit&section=3 "Edit section: Notes")] Notes

Depending on the computer architecture, a [byte](https://en.wikipedia.org/wiki/byte "enwiki:byte") may consist of 8 or more bits, the exact number provided as [CHAR_BIT](../types/limits.html "c/types/limits"). 

sizeof(char), sizeof(signed char), and sizeof(unsigned char) always return 1. 

sizeof cannot be used with function types, incomplete types (including void), or [bit-field](bit_field.html "c/language/bit field") lvalues. 

When applied to an operand that has [structure](struct.html "c/language/struct") or [union](union.html "c/language/union") type, the result is the total number of bytes in such an object, including internal and trailing padding. The trailing padding is such that if the object were an element of an array, the alignment requirement of the next element of this array would be satisfied, in other words, sizeof(T) returns the size of an element of a T[] array. 

If type is a [VLA](array.html "c/language/array") type and changing the value of its size expression would not affect the result of `sizeof`, it is unspecified whether or not the size expression is evaluated.  | (since C99)  
---|---  
  
Except if the type of expression is a [VLA](array.html "c/language/array"),(since C99)expression is not evaluated and the `sizeof` operator may be used in an integer [constant expression](constant_expression.html "c/language/constant expression"). 

If the type of expression is a [variable-length array](array.html "c/language/array") type, expression is evaluated and the size of the array it evaluates to is calculated at run time.  | (since C99)  
---|---  
  
Number of elements in any [array](array.html "c/language/array") a including VLA(since C99) may be determined with the expression sizeof a / sizeof a[0]. Note that if a has pointer type (such as after array-to-pointer conversion of function parameter type adjustment), this expression would simply divide the number of bytes in a pointer type by the number of bytes in the pointed type. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/sizeof&action=edit&section=4 "Edit section: Keywords")] Keywords

[`sizeof`](../keyword/sizeof.html "c/keyword/sizeof")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/sizeof&action=edit&section=5 "Edit section: Example")] Example

Sample output corresponds to a platform with 64-bit pointers and 32-bit int

Run this code
    
    
    #include <stdio.h>
     
    int main(void)
    {
        short x;
        // type argument:
        [printf](../io/fprintf.html)("sizeof(float)          = %zu\n", sizeof(float));
        [printf](../io/fprintf.html)("sizeof(void(*)(void))  = %zu\n", sizeof(void(*)(void)));
        [printf](../io/fprintf.html)("sizeof(char[10])       = %zu\n", sizeof(char[10]));
    //  printf("sizeof(void(void))     = %zu\n", sizeof(void(void))); // Error: function type
    //  printf("sizeof(char[])         = %zu\n", sizeof(char[])); // Error: incomplete type
     
        // expression argument:
        [printf](../io/fprintf.html)("sizeof 'a'             = %zu\n", sizeof 'a'); // type of 'a' is int
    //  printf("sizeof main            = %zu\n", sizeof main); // Error: Function type
        [printf](../io/fprintf.html)("sizeof &main           = %zu\n", sizeof &main);
        [printf](../io/fprintf.html)("sizeof \"hello\"         = %zu\n", sizeof "hello"); // type is char[6]
        [printf](../io/fprintf.html)("sizeof x               = %zu\n", sizeof x); // type of x is short
        [printf](../io/fprintf.html)("sizeof (x+1)           = %zu\n", sizeof(x + 1)); // type of x+1 is int
    }

Possible output: 
    
    
    sizeof(float)          = 4
    sizeof(void(*)(void))  = 8
    sizeof(char[10])       = 10
    sizeof 'a'             = 4
    sizeof &main           = 8
    sizeof "hello"         = 6
    sizeof x               = 2
    sizeof (x+1)           = 4

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/sizeof&action=edit&section=6 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.5.3.4 The sizeof and alignof operators (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.5.3.4 The sizeof and _Alignof operators (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.5.3.4 The sizeof and _Alignof operators (p: 90-91) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.5.3.4 The sizeof operator (p: 80-81) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.3.3.4 The sizeof operator 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/sizeof&action=edit&section=7 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/sizeof.html "cpp/language/sizeof") for `sizeof` operator  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/sizeof&oldid=154510](https://en.cppreference.com/mwiki/index.php?title=c/language/sizeof&oldid=154510)" 

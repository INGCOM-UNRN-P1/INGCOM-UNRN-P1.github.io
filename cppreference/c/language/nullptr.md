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
**`nullptr`**(C23)  
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
[sizeof](sizeof.html "c/language/sizeof")  
[`_Alignof`](alignof.html "c/language/ Alignof")(C11*)  
[Cast operators](cast.html "c/language/cast")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/expressions/navbar_content&action=edit)

## Contents

  * [1 Syntax](nullptr.html#Syntax)
  * [2 Explanation](nullptr.html#Explanation)
  * [3 Keywords](nullptr.html#Keywords)
  * [4 Example](nullptr.html#Example)
  * [5 References](nullptr.html#References)
  * [6 See also](nullptr.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/nullptr&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**nullptr**` |  |  (since C23)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/nullptr&action=edit&section=2 "Edit section: Explanation")] Explanation

The keyword `nullptr` denotes a predefined null pointer constant. It is a [non-lvalue](value_category.html#Non-lvalue_object_expressions "c/language/value category") of type [nullptr_t](../types/nullptr_t.html "c/types/nullptr t"). `nullptr` can be [converted](conversion.html "c/language/conversion") to a pointer types or bool, where the result is the null pointer value of that type or false respectively. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/nullptr&action=edit&section=3 "Edit section: Keywords")] Keywords

[`nullptr`](../keyword/nullptr.html "c/keyword/nullptr")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/nullptr&action=edit&section=4 "Edit section: Example")] Example

Demonstrates that a copy of `nullptr` can also be used as a null pointer constant.

Run this code
    
    
    #include <stddef.h>
    #include <stdio.h>
     
    void g(int*)
    {
        [puts](../io/puts.html)("Function g called");
    }
     
    #define DETECT_NULL_POINTER_CONSTANT(e) \
        _Generic(e,                         \
            void* : puts("void*"),          \
            nullptr_t : puts("nullptr_t"),  \
            default : puts("integer")       \
        )
     
    int main()
    {
        g(nullptr); // OK
        g([NULL](../types/NULL.html)); // OK
        g(0); // OK
     
        auto cloned_nullptr = nullptr;
        g(cloned_nullptr); // OK
     
        [[maybe_unused]] auto cloned_NULL = [NULL](../types/NULL.html);
    //  g(cloned_NULL); // implementation-defined: maybe OK
     
        [[maybe_unused]] auto cloned_zero = 0;
    //  g(cloned_zero); // Error
     
        DETECT_NULL_POINTER_CONSTANT(((void*)0));
        DETECT_NULL_POINTER_CONSTANT(0);
        DETECT_NULL_POINTER_CONSTANT(nullptr);
        DETECT_NULL_POINTER_CONSTANT([NULL](../types/NULL.html)); // implementation-defined
    }

Possible output: 
    
    
    Function g called
    Function g called
    Function g called
    Function g called
    void*
    integer
    nullptr_t
    void*

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/nullptr&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.4.4.6 Predefined constants (p: 66) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/nullptr&action=edit&section=6 "Edit section: See also")] See also

[ NULL](../types/NULL.html "c/types/NULL") |  implementation-defined null pointer constant   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_NULL&action=edit)  
---|---  
[ nullptr_t](../types/nullptr_t.html "c/types/nullptr t")(C23) |  the type of the predefined null pointer constant **`nullptr`**   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_nullptr_t&action=edit)  
[C++ documentation](../../cpp/language/nullptr.html "cpp/language/nullptr") for nullptr  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/nullptr&oldid=183159](https://en.cppreference.com/mwiki/index.php?title=c/language/nullptr&oldid=183159)" 

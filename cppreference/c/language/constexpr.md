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

[ Declarations](declarations.html "c/language/declarations")

[Pointer](pointer.html "c/language/pointer")  
---  
[Array](array.html "c/language/array")  
[enum](enum.html "c/language/enum")  
[struct](struct.html "c/language/struct")  
[union](union.html "c/language/union")  
[Bit-field](bit_field.html "c/language/bit field")  
[Atomic types](atomic.html "c/language/atomic") (C11)  
[const](const.html "c/language/const")  
**constexpr**(C23)  
[volatile](volatile.html "c/language/volatile")  
[restrict](restrict.html "c/language/restrict")(C99)  
[Alignment specifiers](alignas.html "c/language/ Alignas")  
[Storage duration and linkage](storage_class_specifiers.html "c/language/storage duration")  
[External and tentative definitions](extern.html "c/language/extern")  
[typedef](typedef.html "c/language/typedef")  
[Static assertions](static_assert.html "c/language/ Static assert")  
[Attributes](attributes.html "c/language/attributes") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/declarations/navbar_content&action=edit)

A scalar object declared with the constexpr storage-class specifier is a [constant](constant_expression.html "c/language/constant expression"). It must be fully and explicitly initialized according to the static initialization rules. It still has linkage appropriate to its declaration and it exists at runtime to have its address taken; it simply cannot be modified at runtime in any way, i.e., the compiler can use its knowledge of the object’s fixed value in any other [constant expression](constant_expression.html "c/language/constant expression"). 

Additionally, the constant expression that is used for the initializer of such a constant is checked at compile time. 

An initializer of floating-point type must be evaluated with the translation-time floating-point environment. 

There are some restrictions on the type of an object that can be declared with constexpr. Namely, the following constructs are not allowed to be constexpr: 

  * [Pointers](pointer.html "c/language/pointer") (except that null pointers can be constexpr), 
  * Variably modified types, 
  * [Atomic types](atomic.html "c/language/atomic"), 
  * [`volatile`](volatile.html "c/language/volatile") types, 
  * [`restrict`](restrict.html "c/language/restrict") pointers. 



## Contents

  * [1 Keywords](constexpr.html#Keywords)
  * [2 Example](constexpr.html#Example)
  * [3 References](constexpr.html#References)
  * [4 See also](constexpr.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/constexpr&action=edit&section=1 "Edit section: Keywords")] Keywords

[`constexpr`](../keyword/constexpr.html "c/keyword/constexpr")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/constexpr&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <fenv.h>
    #include <stdio.h>
     
    int main(void)
    {
        constexpr float f = 23.0f;
        constexpr float g = 33.0f;
        [fesetround](../numeric/fenv/feround.html)([FE_TOWARDZERO](../numeric/fenv/FE_round.html));
        constexpr float h = f / g; // is not affected by fesetround() above
        [printf](../io/fprintf.html)("%f\n", h);
    }

Output: 
    
    
    0.696969

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/constexpr&action=edit&section=3 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.2 Storage-class specifiers (p: 98-103) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/constexpr&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/constexpr.html "cpp/language/constexpr") for `constexpr` type specifier  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/constexpr&oldid=183173](https://en.cppreference.com/mwiki/index.php?title=c/language/constexpr&oldid=183173)" 

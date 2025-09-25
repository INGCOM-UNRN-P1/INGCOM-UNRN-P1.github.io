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
[constexpr](constexpr.html "c/language/constexpr")(C23)  
[volatile](volatile.html "c/language/volatile")  
[restrict](restrict.html "c/language/restrict")(C99)  
[Alignment specifiers](alignas.html "c/language/ Alignas")  
[Storage duration and linkage](storage_class_specifiers.html "c/language/storage duration")  
[External and tentative definitions](extern.html "c/language/extern")  
[typedef](typedef.html "c/language/typedef")  
**Static assertions**  
[Attributes](attributes.html "c/language/attributes") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/declarations/navbar_content&action=edit)

## Contents

  * [1 Syntax](static_assert.html#Syntax)
  * [2 Explanation](static_assert.html#Explanation)
  * [3 Keywords](static_assert.html#Keywords)
  * [4 Example](static_assert.html#Example)
  * [5 References](static_assert.html#References)
  * [6 See also](static_assert.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Static_assert&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**_Static_assert**` `**(**` expression `**,**` message `**)**` |  |  (since C11)(deprecated in C23)  
`**static_assert**` `**(**` expression `**,**` message `**)**` |  |  (since C23)  
`**_Static_assert**` `**(**` expression `**)**` |  |  (since C23)(deprecated in C23)  
`**static_assert**` `**(**` expression `**)**` |  |  (since C23)  
expression |  \-  |  any [integer constant expression](constant_expression.html "c/language/constant expression")  
---|---|---  
message |  \-  |  any [string literal](string_literal.html "c/language/string literal")  
This keyword is also available as convenience macro [`static_assert`](../error/static_assert.html "c/error/static assert"), available in the header [`<assert.h>`](../header/assert.html "c/header/assert").  | (until C23)  
---|---  
Both of `static_assert` and `_Static_assert` have the same effects. `_Static_assert` is a deprecated spelling that is kept for compatibility. An implementation may also define `static_assert` and/or `_Static_assert` as predefined macros, and `static_assert` is no longer provided by [`<assert.h>`](../header/assert.html "c/header/assert").  | (since C23)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Static_assert&action=edit&section=2 "Edit section: Explanation")] Explanation

The constant expression is evaluated at compile time and compared to zero. If it compares equal to zero, a compile-time error occurs and the compiler must display message as part of the error message (except that characters not in [basic character set](charset.html "c/language/charset") are not required to be displayed)(until C23)should display message (if provided) as part of the error message(since C23). 

Otherwise, if expression does not equal zero, nothing happens; no code is emitted. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Static_assert&action=edit&section=3 "Edit section: Keywords")] Keywords

[`_Static_assert`](../keyword/_Static_assert.html "c/keyword/ Static assert"), [`static_assert`](../keyword/static_assert.html "c/keyword/static assert")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Static_assert&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <assert.h> // no longer needed since C23
     
    int main(void)
    {
        // Test if math works, C23:
        static_assert((2 + 2) % 3 == 1, "Whoa dude, you knew!");
        // Pre-C23 alternative:
        _Static_assert(2 + 2 * 2 == 6, "Lucky guess!?");
     
        // This will produce an error at compile time.
        // static_assert(sizeof(int) < sizeof(char), "Unmet condition!");
     
        constexpr int _42 = 2 * 3 * 2 * 3 + 2 * 3;
        static_assert(_42 == 42); // the message string can be omitted.
     
        // const int _13 = 13;
        // Compile time error - not an integer constant expression:
        // static_assert(_13 == 13);
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Static_assert&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.11 Static assertions (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.10 Static assertions (p: 105) 



    

  * 7.2 Diagnostics <assert.h> (p: 135) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.10 Static assertions (p: 145) 



    

  * 7.2 Diagnostics <assert.h> (p: 186-187) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Static_assert&action=edit&section=6 "Edit section: See also")] See also

[ assert](../error/assert.html "c/error/assert") |  aborts the program if the user-specified condition is not true. May be disabled for release builds   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/dsc_assert&action=edit)  
---|---  
[C++ documentation](../../cpp/language/static_assert.html "cpp/language/static assert") for `static_assert` declaration  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/_Static_assert&oldid=180000](https://en.cppreference.com/mwiki/index.php?title=c/language/_Static_assert&oldid=180000)" 

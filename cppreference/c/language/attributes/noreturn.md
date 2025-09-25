From cppreference.com

< [c](../../../c.html "c")‎ | [language](../../language.html "c/language")‎ | [attributes](../attributes.html "c/language/attributes")

[ C](../../../c.html "c")

[Compiler support](../../compiler_support.html "c/compiler support")  
---  
[Language](../../language.html "c/language")  
[Headers](../../header.html "c/header")  
[Type support](../../types.html "c/types")  
[Program utilities](../../program.html "c/program")  
[Variadic function support](../../variadic.html "c/variadic")  
[Error handling](../../error.html "c/error")  
[Dynamic memory management](../../memory.html "c/memory")  
[Strings library](../../string.html "c/string")  
[Algorithms](../../algorithm.html "c/algorithm")  
[Numerics](../../numeric.html "c/numeric")  
[Date and time utilities](../../chrono.html "c/chrono")  
[Input/output support](../../io.html "c/io")  
[Localization support](../../locale.html "c/locale")  
[Concurrency support](../../thread.html "c/thread") (C11)  
[Technical Specifications](../../experimental.html "c/experimental")  
[Symbol index](../../index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

[ C language](../../language.html "c/language")

[Basic concepts](../basic_concepts.html "c/language/basic concepts")  
---  
[ Keywords](../../keyword.html "c/keyword")  
[ Preprocessor](../../preprocessor.html "c/preprocessor")  
[ Statements](../statements.html "c/language/statements")  
[ Expressions](../operators.html "c/language/expressions")  
[ Initialization](../initialization.html "c/language/initialization")  
[ Declarations](../declarations.html "c/language/declarations")  
[ Functions](../functions.html "c/language/functions")  
Miscellaneous  
[ History of C](../history.html "c/language/history")  
[Technical Specifications](../../experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

[ Declarations](../declarations.html "c/language/declarations")

[Pointer](../pointer.html "c/language/pointer")  
---  
[Array](../array.html "c/language/array")  
[enum](../enum.html "c/language/enum")  
[struct](../struct.html "c/language/struct")  
[union](../union.html "c/language/union")  
[Bit-field](../bit_field.html "c/language/bit field")  
[Atomic types](../atomic.html "c/language/atomic") (C11)  
[const](../const.html "c/language/const")  
[constexpr](../constexpr.html "c/language/constexpr")(C23)  
[volatile](../volatile.html "c/language/volatile")  
[restrict](../restrict.html "c/language/restrict")(C99)  
[Alignment specifiers](../alignas.html "c/language/ Alignas")  
[Storage duration and linkage](../storage_class_specifiers.html "c/language/storage duration")  
[External and tentative definitions](../extern.html "c/language/extern")  
[typedef](../typedef.html "c/language/typedef")  
[Static assertions](../static_assert.html "c/language/ Static assert")  
[Attributes](../attributes.html "c/language/attributes") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/declarations/navbar_content&action=edit)

[ Attributes](../attributes.html "c/language/attributes")

[deprecated](deprecated.html "c/language/attributes/deprecated")(C23)  
---  
[fallthrough](fallthrough.html "c/language/attributes/fallthrough")(C23)  
[nodiscard](nodiscard.html "c/language/attributes/nodiscard")(C23)  
[maybe_unused](maybe_unused.html "c/language/attributes/maybe unused")(C23)  
**noreturn _Noreturn**(C23)(C23)(deprecated)  
[unsequenced](reproducible.html "c/language/attributes/unsequenced")(C23)  
[reproducible](reproducible.html "c/language/attributes/reproducible")(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/navbar_content&action=edit)

Indicates that the function does not return. 

## Contents

  * [1 Syntax](noreturn.html#Syntax)
  * [2 Explanation](noreturn.html#Explanation)
  * [3 Standard library](noreturn.html#Standard_library)
  * [4 See also](noreturn.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/noreturn&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**[[**` `**noreturn**` `**]]**`  
`**[[**` `**__noreturn__**` `**]]**` |  |   
`**[[**` `**_Noreturn**` `**]]**`  
`**[[**` `**___Noreturn__**` `**]]**` |  |  (deprecated)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/noreturn&action=edit&section=2 "Edit section: Explanation")] Explanation

Indicates that the function does not return. 

This attribute applies to the name of the function and specifies that the function does not return by executing the return statement or by reaching the end of the function body (it may return by executing [longjmp](../../program/longjmp.html "c/program/longjmp")). The behavior is undefined if the function with this attribute actually returns. A compiler diagnostic is recommended if this can be detected. 

It has been previously denoted by the keyword [`_Noreturn`](../noreturn.html "c/language/ Noreturn") until it was deprecated since C23 and replaced by this attribute. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/noreturn&action=edit&section=3 "Edit section: Standard library")] Standard library

The following standard functions are declared with `noreturn` attribute (they used to be declared with [`_Noreturn`](../noreturn.html "c/language/ Noreturn") specifier until C23): 

  * [abort()](../../program/abort.html "c/program/abort")
  * [exit()](../../program/exit.html "c/program/exit")
  * [_Exit()](../../program/_Exit.html "c/program/ Exit")
  * [quick_exit()](../../program/quick_exit.html "c/program/quick exit")
  * [thrd_exit()](../../thread/thrd_exit.html "c/thread/thrd exit")
  * [longjmp()](../../program/longjmp.html "c/program/longjmp")



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/noreturn&action=edit&section=4 "Edit section: See also")] See also

[C documentation](../noreturn.html "c/language/ Noreturn") for _Noreturn  
---  
[C++ documentation](../../../cpp/language/attributes/noreturn.html "cpp/language/attributes/noreturn") for `[[noreturn]]`  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/noreturn&oldid=145161](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/noreturn&oldid=145161)" 

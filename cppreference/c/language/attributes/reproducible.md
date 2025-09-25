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
[noreturn_Noreturn](noreturn.html "c/language/attributes/noreturn")(C23)(C23)(deprecated)  
**unsequenced**(C23)  
[reproducible](reproducible.html "c/language/attributes/reproducible")(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/navbar_content&action=edit)

Provides the compiler with information about the access of objects by a function such that certain properties of function calls can be deduced. 

## Contents

  * [1 Syntax](reproducible.html#Syntax)
  * [2 Explanation](reproducible.html#Explanation)
    * [2.1 Effectless](reproducible.html#Effectless)
    * [2.2 Idempotent](reproducible.html#Idempotent)
    * [2.3 Stateless](reproducible.html#Stateless)
    * [2.4 Independent](reproducible.html#Independent)
  * [3 Notes](reproducible.html#Notes)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/unsequenced&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**[[**` `**unsequenced**` `**]]**`  
`**[[**` `**__unsequenced__**` `**]]**` |  (1)  |   
`**[[**` `**reproducible**` `**]]**`  
`**[[**` `**__reproducible__**` `**]]**` |  (2)  |   
  
1) Indicates that a function is [effectless](reproducible.html#Effectless), [idempotent](reproducible.html#Idempotent), [stateless](reproducible.html#Stateless), and [independent](reproducible.html#Independent).

2) Indicates that a function is effectless and idempotent.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/unsequenced&action=edit&section=2 "Edit section: Explanation")] Explanation

These attributes apply to a function declarator or to a type specifier that has a function type. The corresponding attribute is a property of the function type. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/unsequenced&action=edit&section=3 "Edit section: Effectless")] Effectless

An evaluation of a function call is effectless if any store operation that is sequenced during the call is the modification of an object that synchronizes with the call; if additionally the operation is observable, all access to the object must be based on a unique pointer parameter of the function. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/unsequenced&action=edit&section=4 "Edit section: Idempotent")] Idempotent

An evaluation E is idempotent if a second evaluation of E can be sequenced immediately after the original one without changing the resulting value, if any, or the observable state of the execution. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/unsequenced&action=edit&section=5 "Edit section: Stateless")] Stateless

A function F is stateless if any definition of an object of static or thread [storage duration](../storage_class_specifiers.html "c/language/storage duration") in F or in a function that is called by F is const but not volatile qualified. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/unsequenced&action=edit&section=6 "Edit section: Independent")] Independent

A function F is independent if for any object X that is observed by a call to F through an lvalue that is not based on a parameter of the call, all accesses to X in all calls to F during the same program execution observe the same value; otherwise if the access is based on a pointer parameter, there shall be a unique such pointer parameter P such that any access to X shall be to an lvalue that is based on P. 

An object X is observed by a function call if both synchronize, if X is not local to the call, if X has a lifetime that starts before the function call, and if an access of X is sequenced during the call; the last value of X, if any, that is stored before the call is said to be the value of X that is observed by the call. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/unsequenced&action=edit&section=7 "Edit section: Notes")] Notes

These attributes exist for the purpose of compiler optimization. 

If a function is reproducible, multiple subsequent calls can be treated as a single call. 

If a function is unsequenced, multiple subsequent calls can be treated as a single call, and the calls can be parallelized and reordered arbitrarily. 

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/unsequenced&oldid=168505](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/unsequenced&oldid=168505)" 

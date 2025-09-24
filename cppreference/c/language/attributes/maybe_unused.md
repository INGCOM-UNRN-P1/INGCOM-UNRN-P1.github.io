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
**maybe_unused**(C23)  
[noreturn_Noreturn](noreturn.html "c/language/attributes/noreturn")(C23)(C23)(deprecated)  
[unsequenced](reproducible.html "c/language/attributes/unsequenced")(C23)  
[reproducible](reproducible.html "c/language/attributes/reproducible")(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/navbar_content&action=edit)

Suppresses warnings on unused entities. 

## Contents

  * [1 Syntax](maybe_unused.html#Syntax)
  * [2 Explanation](maybe_unused.html#Explanation)
  * [3 Example](maybe_unused.html#Example)
  * [4 See also](maybe_unused.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/maybe_unused&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**[[**` `**maybe_unused**` `**]]**`  
`**[[**` `**__maybe_unused__**` `**]]**` |  |   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/maybe_unused&action=edit&section=2 "Edit section: Explanation")] Explanation

This attribute can appear in the declaration of the following entities: 

  * [struct](../struct.html "c/language/struct")/[union](../union.html "c/language/union"): struct [[maybe_unused]] S;, 
  * [typedef name](../typedef.html "c/language/typedef"): [[maybe_unused]] typedef S* PS;, 
  * object: [[maybe_unused]] int x;, 
  * struct/union member: union U { [[maybe_unused]] int n; };, 
  * [function](../function_definition.html "c/language/function definition"): [[maybe_unused]] void f(void);, 
  * [enumeration](../enum.html "c/language/enum"): enum [[maybe_unused]] E {};, 
  * enumerator: enum { A [[maybe_unused]], B [[maybe_unused]] = 42 };. 



If the compiler issues warnings on unused entities, that warning is suppressed for any entity declared `maybe_unused`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/maybe_unused&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <assert.h>
     
    [[maybe_unused]] void f([[maybe_unused]] _Bool cond1, [[maybe_unused]] _Bool cond2)
    {
       [[maybe_unused]] _Bool b = cond1 && cond2;
       [assert](../../error/assert.html)(b); // in release mode, assert is compiled out, and b is unused
                  // no warning because it is declared [[maybe_unused]]
    } // parameters cond1 and cond2 are not used, no warning
     
    int main(void)
    {
        f(1, 1);
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/maybe_unused&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../../cpp/language/attributes/maybe_unused.html "cpp/language/attributes/maybe unused") for maybe_unused  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/maybe_unused&oldid=124539](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/maybe_unused&oldid=124539)" 

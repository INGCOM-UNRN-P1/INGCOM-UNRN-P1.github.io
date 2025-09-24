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
**fallthrough**(C23)  
[nodiscard](nodiscard.html "c/language/attributes/nodiscard")(C23)  
[maybe_unused](maybe_unused.html "c/language/attributes/maybe unused")(C23)  
[noreturn_Noreturn](noreturn.html "c/language/attributes/noreturn")(C23)(C23)(deprecated)  
[unsequenced](reproducible.html "c/language/attributes/unsequenced")(C23)  
[reproducible](reproducible.html "c/language/attributes/reproducible")(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/navbar_content&action=edit)

Indicates that the fall through from the previous case label is intentional and should not be diagnosed by a compiler that warns on fallthrough. 

## Contents

  * [1 Syntax](fallthrough.html#Syntax)
  * [2 Explanation](fallthrough.html#Explanation)
  * [3 Example](fallthrough.html#Example)
  * [4 See also](fallthrough.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/fallthrough&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**[[**` `**fallthrough**` `**]]**`  
`**[[**` `**__fallthrough__**` `**]]**` |  |   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/fallthrough&action=edit&section=2 "Edit section: Explanation")] Explanation

May only be used in an [attribute declaration](../declarations.html "c/language/declarations") to create a _fallthrough declaration_ ([[fallthrough]];). 

A fallthrough declaration may only be used in a [`switch`](../switch.html "c/language/switch") statement, where the next block item (statement, declaration, or label) to be encounted is a statement with a `case` or `default` label for that switch statement. 

Indicates that the fall through from the previous case label is intentional and should not be diagnosed by a compiler that warns on fallthrough. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/fallthrough&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdbool.h>
     
    void g(void) {}
    void h(void) {}
    void i(void) {}
     
    void f(int n) {
      switch (n) {
        case 1:
        case 2:
          g();
         [[fallthrough]];
        case 3: // no warning on fallthrough
          h();
        case 4: // compiler may warn on fallthrough
          if(n < 3) {
              i();
              [[fallthrough]]; // OK
          }
          else {
              return;
          }
        case 5:
          while (false) {
            [[fallthrough]]; // ill-formed: no subsequent case or default label
          }
        case 6:
          [[fallthrough]]; // ill-formed: no subsequent case or default label
      }
    }
     
    int main(void) {}

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/fallthrough&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../../cpp/language/attributes/fallthrough.html "cpp/language/attributes/fallthrough") for fallthrough  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/fallthrough&oldid=124533](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/fallthrough&oldid=124533)" 

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
**nodiscard**(C23)  
[maybe_unused](maybe_unused.html "c/language/attributes/maybe unused")(C23)  
[noreturn_Noreturn](noreturn.html "c/language/attributes/noreturn")(C23)(C23)(deprecated)  
[unsequenced](reproducible.html "c/language/attributes/unsequenced")(C23)  
[reproducible](reproducible.html "c/language/attributes/reproducible")(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/navbar_content&action=edit)

If a function declared `nodiscard` or a function returning a struct/union/enum declared `nodiscard` by value is called from a [discarded-value expression](../operators.html "c/language/expressions") other than a cast to void, the compiler is encouraged to issue a warning. 

## Contents

  * [1 Syntax](nodiscard.html#Syntax)
  * [2 Explanation](nodiscard.html#Explanation)
  * [3 Example](nodiscard.html#Example)
  * [4 See also](nodiscard.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/nodiscard&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**[[**` `**nodiscard**` `**]]**`  
`**[[**` `**__nodiscard__**` `**]]**` |  (1)  |   
`**[[**` `**nodiscard**` `**(**` string-literal `**)**` `**]]**`  
`**[[**` `**__nodiscard__**` `**(**` string-literal `**)**` `**]]**` |  (2)  |   
string-literal |  \-  |  text that could be used to explain the rationale for why the result should not be discarded   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/nodiscard&action=edit&section=2 "Edit section: Explanation")] Explanation

Appears in a function declaration, enumeration declaration, or struct/union declaration. 

If, from a [discarded-value expression](../operators.html "c/language/expressions") other than a cast to void, 

  * a function declared `nodiscard` is called, or 
  * a function returning a struct/union/enum declared `nodiscard` is called, 



the compiler is encouraged to issue a warning. 

The string-literal, if specified, is usually included in the warnings. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/nodiscard&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    struct [[nodiscard]] error_info { int status; /*...*/ };
    struct error_info enable_missile_safety_mode() { /*...*/ return (struct error_info){0}; }
    void launch_missiles() { /*...*/ }
    void test_missiles() {
       enable_missile_safety_mode(); // compiler may warn on discarding a nodiscard value
       launch_missiles();
    }
    struct error_info* foo() { static struct error_info e; /*...*/ return &e; }
    void f1() {
        foo(); // nodiscard type itself is not returned, no warning
    }
    // nodiscard( string-literal ):
    [[nodiscard("PURE FUN")]] int strategic_value(int x, int y) { return x ^ y; }
     
    int main()
    {
        strategic_value(4,2); // compiler may warn on discarding a nodiscard value
        int z = strategic_value(0,0); // OK: return value is not discarded
        return z;
    }

Possible output: 
    
    
    game.cpp:5:4: warning: ignoring return value of function declared with 'nodiscard' attribute
    game.cpp:17:5: warning: ignoring return value of function declared with 'nodiscard' attribute: PURE FUN

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/nodiscard&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../../cpp/language/attributes/nodiscard.html "cpp/language/attributes/nodiscard") for nodiscard  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/nodiscard&oldid=124537](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/nodiscard&oldid=124537)" 

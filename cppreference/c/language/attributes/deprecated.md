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

**deprecated**(C23)  
---  
[fallthrough](fallthrough.html "c/language/attributes/fallthrough")(C23)  
[nodiscard](nodiscard.html "c/language/attributes/nodiscard")(C23)  
[maybe_unused](maybe_unused.html "c/language/attributes/maybe unused")(C23)  
[noreturn_Noreturn](noreturn.html "c/language/attributes/noreturn")(C23)(C23)(deprecated)  
[unsequenced](reproducible.html "c/language/attributes/unsequenced")(C23)  
[reproducible](reproducible.html "c/language/attributes/reproducible")(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/navbar_content&action=edit)

Indicates that the name or entity declared with this attribute is [deprecated](https://en.wikipedia.org/wiki/Deprecation "enwiki:Deprecation"), that is, the use is allowed, but discouraged for some reason. 

## Contents

  * [1 Syntax](deprecated.html#Syntax)
  * [2 Explanation](deprecated.html#Explanation)
  * [3 Example](deprecated.html#Example)
  * [4 See also](deprecated.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/deprecated&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**[[**` `**deprecated**` `**]]**`  
`**[[**` `**__deprecated__**` `**]]**` |  (1)  |   
`**[[**` `**deprecated**` `**(**` string-literal `**)**` `**]]**`  
`**[[**` `**__deprecated__**` `**(**` string-literal `**)**` `**]]**` |  (2)  |   
string-literal |  \-  |  text that could be used to explain the rationale for deprecation and/or to suggest a replacing entity   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/deprecated&action=edit&section=2 "Edit section: Explanation")] Explanation

Indicates that the use of the name or entity declared with this attribute is allowed, but discouraged for some reason. Compilers typically issue warnings on such uses. The string-literal, if specified, is usually included in the warnings. 

This attribute is allowed in declarations of the following names or entities: 

  * [struct](../struct.html "c/language/struct")/[union](../union.html "c/language/union"): struct [[deprecated]] S;, 
  * [typedef-name](../typedef.html "c/language/typedef"): [[deprecated]] typedef S* PS;, 
  * objects: [[deprecated]] int x;, 
  * struct/union member: union U { [[deprecated]] int n; };, 
  * [function](../function_definition.html "c/language/function definition"): [[deprecated]] void f(void);, 
  * [enumeration](../enum.html "c/language/enum"): enum [[deprecated]] E {};, 
  * enumerator: enum { A [[deprecated]], B [[deprecated]] = 42 };. 



A name declared non-deprecated may be redeclared deprecated. A name declared deprecated cannot be un-deprecated by redeclaring it without this attribute. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/deprecated&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
     
    [[deprecated]]
    void TriassicPeriod(void)
    {
        [puts](../../io/puts.html)("Triassic Period: [251.9 - 208.5] million years ago.");
    }
     
    [[deprecated("Use NeogenePeriod() instead.")]]
    void JurassicPeriod(void)
    {
        [puts](../../io/puts.html)("Jurassic Period: [201.3 - 152.1] million years ago.");
    }
     
    [[deprecated("Use calcSomethingDifferently(int).")]]
    int calcSomething(int x)
    {
        return x * 2;
    }
     
    int main(void)
    {
        TriassicPeriod();
        JurassicPeriod();
    }

Possible output: 
    
    
    Triassic Period: [251.9 - 208.5] million years ago.
    Jurassic Period: [201.3 - 152.1] million years ago.
     
    prog.c:23:5: warning: 'TriassicPeriod' is deprecated [-Wdeprecated-declarations]
        TriassicPeriod();
        ^
    prog.c:3:3: note: 'TriassicPeriod' has been explicitly marked deprecated here
    [[deprecated]]
      ^
    prog.c:24:5: warning: 'JurassicPeriod' is deprecated: Use NeogenePeriod() instead. [-Wdeprecated-declarations]
        JurassicPeriod();
        ^
    prog.c:9:3: note: 'JurassicPeriod' has been explicitly marked deprecated here
    [[deprecated("Use NeogenePeriod() instead.")]]
      ^
    2 warnings generated.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/deprecated&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../../cpp/language/attributes/deprecated.html "cpp/language/attributes/deprecated") for deprecated  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/deprecated&oldid=155182](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes/deprecated&oldid=155182)" 

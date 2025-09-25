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
[Static assertions](static_assert.html "c/language/ Static assert")  
**Attributes** (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/declarations/navbar_content&action=edit)

**Attributes**

[deprecated](attributes/deprecated.html "c/language/attributes/deprecated")(C23)  
---  
[fallthrough](attributes/fallthrough.html "c/language/attributes/fallthrough")(C23)  
[nodiscard](attributes/nodiscard.html "c/language/attributes/nodiscard")(C23)  
[maybe_unused](attributes/maybe_unused.html "c/language/attributes/maybe unused")(C23)  
[noreturn_Noreturn](attributes/noreturn.html "c/language/attributes/noreturn")(C23)(C23)(deprecated)  
[unsequenced](attributes/reproducible.html "c/language/attributes/unsequenced")(C23)  
[reproducible](attributes/reproducible.html "c/language/attributes/reproducible")(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/navbar_content&action=edit)

Introduces implementation-defined attributes for types, objects, expressions, etc. 

## Contents

  * [1 Syntax](attributes.html#Syntax)
  * [2 Explanation](attributes.html#Explanation)
  * [3 Standard attributes](attributes.html#Standard_attributes)
  * [4 Attribute testing](attributes.html#Attribute_testing)
  * [5 Example](attributes.html#Example)
  * [6 References](attributes.html#References)
  * [7 See also](attributes.html#See_also)
  * [8 External links](attributes.html#External_links)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes&action=edit&section=1 "Edit section: Syntax")] Syntax

    `**[[**` attr ﻿`**]]**` `**[[**` attr1, attr2, attr3`**(**` args`**)**``**]]**` `**[[**` attribute-prefix`**::**` attr ﻿`**(**` args`**)**``**]]**`

Formally, the syntax is   
  
---  
`**[[**` attribute-list `**]]**` |  |  (since C23)  
  
where attribute-list is a comma-separated sequence of zero or more attribute-token ﻿s   
  
---  
standard-attribute |  (1)  |   
attribute-prefix `**::**` identifier |  (2)  |   
standard-attribute `**(**` argument-list ﻿(optional) `**)**` |  (3)  |   
attribute-prefix `**::**` identifier `**(**` argument-list ﻿(optional) `**)**` |  (4)  |   
  
where attribute-prefix is an identifier and argument-list is a sequence of tokens where parentheses, brackets and braces are balanced (balanced-token-sequence). 

1) standard attribute, such as [[fallthrough]]

2) attribute with a namespace, such as [[gnu::unused]]

3) standard attribute with arguments, such as [[deprecated("reason")]]

4) attribute with both a namespace and an argument list, such as [[gnu::nonnull(1)]]

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes&action=edit&section=2 "Edit section: Explanation")] Explanation

Attributes provide the unified standard syntax for implementation-defined language extensions, such as the GNU and IBM language extensions `__attribute__((...))`, Microsoft extension `__declspec()`, etc. 

An attribute can be used almost everywhere in the C program, and can be applied to almost everything: to types, to variables, to functions, to names, to code blocks, to entire translation units, although each particular attribute is only valid where it is permitted by the implementation: `[[expect_true]]` could be an attribute that can only be used with an if, and not with a class declaration. `[[omp::parallel()]]` could be an attribute that applies to a code block or to a for loop, but not to the type `int`, etc. (note these two attributes are fictional examples, see below for the standard and some non-standard attributes) 

In declarations, attributes may appear both before the whole declaration and directly after the name of the entity that is declared, in which case they are combined. In most other situations, attributes apply to the directly preceding entity. 

Two consecutive left square bracket tokens (`[[`) may only appear when introducing an attribute-specifier or inside an attribute argument. 

Besides the standard attributes listed below, implementations may support arbitrary non-standard attributes with implementation-defined behavior. All attributes unknown to an implementation are ignored without causing an error. 

Every standard-attribute is reserved for standardization. That is, every non-standard attribute is prefixed by a attribute-prefix provided by the implementation, e.g. `[[gnu::may_alias]]` and `[[clang::no_sanitize]]`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes&action=edit&section=3 "Edit section: Standard attributes")] Standard attributes

Only the following attributes are defined by the C standard. Every standard attribute whose name is of form `attr` can be also spelled as `__attr__` and its meaning is not changed. 

`[[[deprecated](attributes/deprecated.html "c/language/attributes/deprecated")]]`(C23)`[[[deprecated](attributes/deprecated.html "c/language/attributes/deprecated")("_reason_ ")]]`(C23) |  indicates that the use of the name or entity declared with this attribute is allowed, but discouraged for some reason  
(attribute specifier)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/dsc_deprecated&action=edit)  
---|---  
`[[[fallthrough](attributes/fallthrough.html "c/language/attributes/fallthrough")]]`(C23) |  indicates that the fall through from the previous case label is intentional and should not be diagnosed by a compiler that warns on fall-through  
(attribute specifier)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/dsc_fallthrough&action=edit)  
`[[[nodiscard](attributes/nodiscard.html "c/language/attributes/nodiscard")]]`(C23)`[[[nodiscard](attributes/nodiscard.html "c/language/attributes/nodiscard")("_reason_ ")]]`(C23) |  encourages the compiler to issue a warning if the return value is discarded  
(attribute specifier)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/dsc_nodiscard&action=edit)  
`[[[maybe_unused](attributes/maybe_unused.html "c/language/attributes/maybe unused")]]`(C23) |  suppresses compiler warnings on unused entities, if any  
(attribute specifier)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/dsc_maybe_unused&action=edit)  
`[[[noreturn](attributes/noreturn.html "c/language/attributes/noreturn")]]`(C23)`[[[_Noreturn](attributes/noreturn.html "c/language/attributes/noreturn")]]`(C23)(deprecated) |  indicates that the function does not return  
(attribute specifier)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/dsc_noreturn&action=edit)  
`[[[unsequenced](attributes/reproducible.html "c/language/attributes/unsequenced")]]`(C23) |  indicates that a function is stateless, effectless, idempotent and independent  
(attribute specifier)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/dsc_unsequenced&action=edit)  
`[[[reproducible](attributes/reproducible.html "c/language/attributes/reproducible")]]`(C23) |  indicates that a function is effectless and idempotent  
(attribute specifier)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/attributes/dsc_reproducible&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes&action=edit&section=4 "Edit section: Attribute testing")] Attribute testing  
  
---  
`**__has_c_attribute(**` attribute-token `**)**` |  |   
  
Checks for the presence of an attribute token named by attribute-token. 

For standard attributes, it will expand to the year and month in which the attribute was added to the working draft (see table below), the presence of vendor-specific attributes is determined by a non-zero integer constant. 

`__has_c_attribute` can be expanded in the expression of [` #if`](../preprocessor/conditional.html "c/preprocessor/conditional") and [` #elif`](../preprocessor/conditional.html "c/preprocessor/conditional"). It is treated as a defined macro by [` #ifdef`](../preprocessor/conditional.html "c/preprocessor/conditional"), [` #ifndef`](../preprocessor/conditional.html "c/preprocessor/conditional") and [`defined`](../preprocessor/conditional.html "c/preprocessor/conditional") but cannot be used anywhere else. 

attribute-token |  Attribute  |  Value  |  Standard  
---|---|---|---  
`deprecated` | `[[[deprecated](attributes/deprecated.html "c/language/attributes/deprecated")]]` | 201904L | (C23)  
`fallthrough` | `[[[fallthrough](attributes/fallthrough.html "c/language/attributes/fallthrough")]]` | 201904L | (C23)  
`maybe_unused` | `[[[maybe_unused](attributes/maybe_unused.html "c/language/attributes/maybe unused")]]` | 201904L | (C23)  
`nodiscard` | `[[[nodiscard](attributes/nodiscard.html "c/language/attributes/nodiscard")]]` | 202003L | (C23)  
`noreturn`  
`_Noreturn` | `[[[noreturn](attributes/noreturn.html "c/language/attributes/noreturn")]]`  
`[[[_Noreturn](attributes/noreturn.html "c/language/attributes/noreturn")]]` | 202202L | (C23)  
`unsequenced` | `[[[unsequenced](attributes/reproducible.html "c/language/attributes/unsequenced")]]` | 202207L | (C23)  
`reproducible` | `[[[reproducible](attributes/reproducible.html "c/language/attributes/reproducible")]]` | 202207L | (C23)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    [[gnu::hot]] [[gnu::const]] [[nodiscard]]
    int f(void); // declare f with three attributes
     
    [[gnu::const, gnu::hot, nodiscard]]
    int f(void); // the same as above, but uses a single attr
                 // specifier that contains three attributes
     
    int f(void) { return 0; }
     
    int main(void)
    {
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes&action=edit&section=6 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.12 Attributes (p: TBD) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes&action=edit&section=7 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/attributes.html "cpp/language/attributes") for Attribute specifier sequence  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes&action=edit&section=8 "Edit section: External links")] External links

1\.  | [Attributes in GCC](https://gcc.gnu.org/onlinedocs/gcc/Attribute-Syntax.html#Attribute-Syntax)  
---|---  
2\.  | [Attributes in Clang](https://clang.llvm.org/docs/AttributeReference.html)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/attributes&oldid=178605](https://en.cppreference.com/mwiki/index.php?title=c/language/attributes&oldid=178605)" 

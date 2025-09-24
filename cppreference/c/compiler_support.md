From cppreference.com

< [c](../c.html "c")

[ C](../c.html "c")

**Compiler support**  
---  
[Language](language.html "c/language")  
[Headers](header.html "c/header")  
[Type support](types.html "c/types")  
[Program utilities](program.html "c/program")  
[Variadic function support](variadic.html "c/variadic")  
[Error handling](error.html "c/error")  
[Dynamic memory management](memory.html "c/memory")  
[Strings library](string.html "c/string")  
[Algorithms](algorithm.html "c/algorithm")  
[Numerics](numeric.html "c/numeric")  
[Date and time utilities](chrono.html "c/chrono")  
[Input/output support](io.html "c/io")  
[Localization support](locale.html "c/locale")  
[Concurrency support](thread.html "c/thread") (C11)  
[Technical Specifications](experimental.html "c/experimental")  
[Symbol index](index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

**Compiler support**

[ C99](compiler_support/99.html "c/compiler support/99")  
---  
[ C23](compiler_support/23.html "c/compiler support/23")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/compiler_support/navbar_content&action=edit)

![](https://upload.cppreference.com/mwiki/images/3/31/Imbox_notice.png) |  This page is maintained as best-effort and may lag behind most recent compiler releases. If you see something is out-of-date, please help us by updating it!   
---|---  
  
## Contents

  * [1 C23 features](compiler_support.html#C23_features)
    * [1.1 C23 core language features](compiler_support.html#C23_core_language_features)
    * [1.2 C23 library features](compiler_support.html#C23_library_features)
  * [2 C99 features](compiler_support.html#C99_features)
    * [2.1 C99 core language features](compiler_support.html#C99_core_language_features)
    * [2.2 See also](compiler_support.html#See_also)

  
---  
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/compiler_support&action=edit&section=1 "Edit section: C23 features")] C23 features 

Note that this list may change, as the draft C23/2x standard evolves. 

[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/compiler_support/23&action=edit)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=Template:c/compiler_support/23&action=edit&section=T-1 "Template:c/compiler support/23")] C23 core language features

| This section is incomplete  
Reason: status for Apple Clang and other compilers supporting C2x   
---|---  
C23 feature  
  
| Paper(s)  
  
| GCC | Clang | MSVC | Apple Clang | EDG eccp | Intel C++ | Nvidia HPC C++ (ex PGI)* | Nvidia nvcc | Cray |   
---|---|---|---|---|---|---|---|---|---|---|---  
[`static_assert`](language/static_assert.html "c/language/ Static assert") with no message  | [N2265](https://open-std.org/JTC1/SC22/WG14/www/docs/n2265.pdf) | 9  | 9  | Yes  | Yes  | 6.5  | 2021.1.2 (clang based)  |  |  |   
`[[[nodiscard](language/attributes/nodiscard.html "c/language/attributes/nodiscard")]]` | [N2267](https://open-std.org/JTC1/SC22/WG14/www/docs/n2267.pdf) | 10  | 9  |  | Yes  | 6.4  | 2021.1.2 (clang based)  |  |  |   
`[[[maybe_unused](language/attributes/maybe_unused.html "c/language/attributes/maybe unused")]]` | [N2270](https://open-std.org/JTC1/SC22/WG14/www/docs/n2270.pdf) | 10  | 9  |  | Yes  | 6.4  | 2021.1.2 (clang based)  |  |  |   
`[[[deprecated](language/attributes/deprecated.html "c/language/attributes/deprecated")]]` | [N2334](https://open-std.org/JTC1/SC22/WG14/www/docs/n2334.pdf) | 10  | 9  |  | Yes  | 6.4  | 2021.1.2 (clang based)  |  |  |   
[Attributes](language/attributes.html "c/language/attributes") | [N2335](https://open-std.org/JTC1/SC22/WG14/www/docs/n2335.pdf)  
[N2554](https://open-std.org/JTC1/SC22/WG14/www/docs/n2554.pdf) | 10  | 9  |  | Yes  | 6.4  | 2021.1.2 (clang based)  |  |  |   
IEEE 754 decimal floating-point types  | [N2341](https://open-std.org/JTC1/SC22/WG14/www/docs/n2341.pdf) | 4.2 (partial)*  
12  |  |  |  |  | 13.0 (partial)* |  |  |   
`[[[fallthrough](language/attributes/fallthrough.html "c/language/attributes/fallthrough")]]` | [N2408](https://open-std.org/JTC1/SC22/WG14/www/docs/n2408.pdf) | 10  | 9  |  | Yes  | 6.4  | 2021.1.2 (clang based)  |  |  |   
[`u8` character constants](language/character_constant.html "c/language/character constant") | [N2418](https://open-std.org/JTC1/SC22/WG14/www/docs/n2418.pdf) | 10  | 15  |  |  | 6.5  | 2022.2  |  |  |   
Removal of [function definitions](language/function_definition.html "c/language/function definition") without prototype  | [N2432](https://open-std.org/JTC1/SC22/WG14/www/docs/n2432.pdf) | 10  | 15  |  |  |  | 2022.2  |  |  |   
`[[[nodiscard](language/attributes/nodiscard.html "c/language/attributes/nodiscard")]]` with message  | [N2448](https://open-std.org/JTC1/SC22/WG14/www/docs/n2448.pdf) | 11  | 10  |  | Yes  | 6.4  | 2021.1.2 (clang based)  |  |  |   
Unnamed parameters in function definitions  | [N2480](https://open-std.org/JTC1/SC22/WG14/www/docs/n2480.pdf) | 11  | 11  |  | Yes  | 6.4  | 2021.1.2 (clang based)  |  |  |   
[Labels](language/statements.html#Labels "c/language/statements") before declarations and end of blocks  | [N2508](https://open-std.org/JTC1/SC22/WG14/www/docs/n2508.pdf) | 11  | 16  | Partial* |  | 6.5  | 17.0* |  |  |   
[Binary integer constants](language/integer_constant.html "c/language/integer constant") | [N2549](https://open-std.org/JTC1/SC22/WG14/www/docs/n2549.pdf) | 4.3*  
11  | 2.9*  
9  | 19.0 (2015)** | Yes  | 6.5  | 11.0* |  |  |   
[`__has_c_attribute`](language/attributes.html#Attribute_testing "c/language/attributes") in preprocessor conditionals  | [N2553](https://open-std.org/JTC1/SC22/WG14/www/docs/n2553.pdf) | 11  | 9  |  | Yes  | 6.5  | 2021.1.2 (clang based)  |  |  |   
Allow duplicate attributes  | [N2557](https://open-std.org/JTC1/SC22/WG14/www/docs/n2557.pdf) | 11  | 13  |  | Yes  | 6.5  | 2021.4 (clang-based  |  |  |   
IEEE 754 interchange and extended types  | [N2601](https://open-std.org/JTC1/SC22/WG14/www/docs/n2601.pdf) | 7 (partial)*  
14  | 6 (partial)* |  | Partial* |  |  |  |  |   
Digit separators  | [N2626](https://open-std.org/JTC1/SC22/WG14/www/docs/n2626.pdf) | 12  | 13  | 19.0 (2015)** | Yes  | 6.5  | 18.0* |  |  |   
[`#elifdef` and `#elifndef`](preprocessor/conditional.html "c/preprocessor/conditional") | [N2645](https://open-std.org/JTC1/SC22/WG14/www/docs/n2645.pdf) | 12  | 13  | 19.40* | 13.1.6* | 6.5  | 2021.4  |  |  |   
Type change of [`u8` string literals](language/string_literal.html "c/language/string literal") | [N2653](https://open-std.org/JTC1/SC22/WG14/www/docs/n2653.htm) | 13  |  |  |  |  |  |  |  |   
`[[[maybe_unused](language/attributes/maybe_unused.html "c/language/attributes/maybe unused")]]` for labels  | [N2662](https://open-std.org/JTC1/SC22/WG14/www/docs/n2662.pdf) | 11  | 16  |  |  | 6.5  | 2022.2  |  |  |   
[` #warning`](preprocessor/warning.html "c/preprocessor/error") | [N2686](https://open-std.org/JTC1/SC22/WG14/www/docs/n2686.pdf) | Yes  | Yes  |  | Yes  | 6.5  | Yes  |  |  |   
Bit-precise integer types (_BitInt)  | [N2763](https://open-std.org/JTC1/SC22/WG14/www/docs/n2763.pdf) | 14 (partial)* | 15  |  |  | 6.5  | 2022.2  |  |  |   
`[[[noreturn](language/attributes/noreturn.html "c/language/attributes/noreturn")]]` | [N2764](https://open-std.org/JTC1/SC22/WG14/www/docs/n2764.pdf) | 13  | 15  |  |  | 6.5  | 2022.2  |  |  |   
Suffixes for bit-precise integer constants  | [N2775](https://open-std.org/JTC1/SC22/WG14/www/docs/n2775.pdf) | 14  | 15  |  |  |  | 2022.2  |  |  |   
[`__has_include`](preprocessor/include.html "c/preprocessor/include") in preprocessor conditionals  | [N2799](https://open-std.org/JTC1/SC22/WG14/www/docs/n2799.pdf) | 5  | Yes  | 19.11* | Yes  | 6.5  | 18.0  |  |  |   
Identifier Syntax using Unicode Standard Annex 31  | [N2836](https://open-std.org/JTC1/SC22/WG14/www/docs/n2836.pdf) | 13  | 15  |  |  | 6.5  | 2022.2  |  |  |   
Removal of [function declarations](language/function_declaration.html "c/language/function declaration") without prototype  | [N2841](https://open-std.org/JTC1/SC22/WG14/www/docs/n2841.htm) | 13  | 15  |  |  |  | 2022.2  |  |  |   
[Empty initializers](language/initialization.html#Empty_initialization "c/language/initialization") | [N2900](https://open-std.org/JTC1/SC22/WG14/www/docs/n2900.htm) | Partial*  
13  | Partial* |  | Partial* | Partial* | Partial* |  |  |   
[`typeof`](language/typeof_unqual.html "c/language/typeof") and [`typeof_unqual`](language/typeof_unqual.html "c/language/typeof") | [N2927](https://open-std.org/JTC1/SC22/WG14/www/docs/n2927.htm)  
[N2930](https://open-std.org/JTC1/SC22/WG14/www/docs/n2930.pdf) | Partial*  
13  | Partial*  
16  | 19.39* | Partial* | Partial* | Partial* |  |  | Partial*  
New spelling of keywords  | [N2934](https://open-std.org/JTC1/SC22/WG14/www/docs/n2934.pdf) | 13  | 16  |  |  | 6.5  |  |  |  |   
Predefined [true and false](language/bool_constant.html "c/language/bool constant") | [N2935](https://open-std.org/JTC1/SC22/WG14/www/docs/n2935.pdf) | 13  | 15  |  |  |  | 2022.2  |  |  |   
`[[[unsequenced](language/attributes/reproducible.html "c/language/attributes/unsequenced")]]` and `[[[reproducible](language/attributes/reproducible.html "c/language/attributes/reproducible")]]` | [N2956](https://open-std.org/JTC1/SC22/WG14/www/docs/n2956.htm) | 15  |  |  |  |  |  |  |  |   
Relax requirements for [variadic parameter list](language/variadic.html "c/language/variadic") | [N2975](https://open-std.org/JTC1/SC22/WG14/www/docs/n2975.pdf) | 13  | 16  |  |  | 6.5  | 2023.1  |  |  |   
Type inference in object definitions  | [N3007](https://open-std.org/JTC1/SC22/WG14/www/docs/n3007.htm) | 13  | 18  |  |  |  |  |  |  |   
[` #embed`](preprocessor/embed.html "c/preprocessor/embed") | [N3017](https://open-std.org/JTC1/SC22/WG14/www/docs/n3017.htm) | 15  | 19  |  |  |  |  |  |  |   
[`constexpr`](language/constexpr.html "c/language/constexpr") objects  | [N3018](https://open-std.org/JTC1/SC22/WG14/www/docs/n3018.htm) | 13  | 19  |  |  |  |  |  |  |   
Improved Normal Enumerations  | [N3029](https://open-std.org/JTC1/SC22/WG14/www/docs/n3029.htm) | 13  | 20* |  |  |  |  |  |  |   
Enumerations with fixed underlying types  | [N3030](https://open-std.org/JTC1/SC22/WG14/www/docs/n3030.htm) | 13  | 20* |  |  |  |  |  |  |   
[`__VA_OPT__`](preprocessor/replace.html#Function-like_macros "c/preprocessor/replace") | [N3033](https://open-std.org/JTC1/SC22/WG14/www/docs/n3033.htm) | 8  
13  | 12  | 19.39* |  | 6.5  |  |  |  |   
Storage-class specifiers for compound literals  | [N3038](https://open-std.org/JTC1/SC22/WG14/www/docs/n3038.htm) | 13  |  |  |  |  |  |  |  |   
[`nullptr`](language/nullptr.html "c/language/nullptr") | [N3042](https://open-std.org/JTC1/SC22/WG14/www/docs/n3042.htm) | 13  | 16  |  |  |  |  |  |  |   
  
  
C23 feature  |    
  
Paper(s)  | GCC | Clang | MSVC | Apple Clang | EDG eccp | Intel C++ | Nvidia HPC C++ (ex PGI)* | Nvidia nvcc | Cray  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=Template:c/compiler_support/23&action=edit&section=T-2 "Template:c/compiler support/23")] C23 library features

| This section is incomplete  
Reason: a different list for C standard libraries   
---|---  
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/compiler_support&action=edit&section=2 "Edit section: C99 features")] C99 features 

[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/compiler_support/99&action=edit)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=Template:c/compiler_support/99&action=edit&section=T-1 "Template:c/compiler support/99")] C99 core language features

| This section is incomplete  
Reason: needs to list C compilers, verification   
---|---  
C99 feature  
  
| Paper(s)  
  
| GCC | Clang | MSVC | Apple Clang | EDG eccp | Intel C++ | Nvidia HPC C++ (ex PGI)* | Nvidia nvcc | Cray |   
---|---|---|---|---|---|---|---|---|---|---|---  
Universal-character-names in [identifiers](language/identifiers.html "c/language/identifier") |  | 3.1  | Yes  | Yes  |  |  |  |  |  |   
Increased [translation limits](language/identifiers.html#Translation_limits "c/language/identifier") | [N590](https://open-std.org/JTC1/SC22/WG14/www/docs/n590.pdf) | 0.9  |  N/A |  |  |  |  |  |  |   
// [comments](comment.html "c/comment") | [N644](https://open-std.org/JTC1/SC22/WG14/www/docs/n644.htm) | 2.7  | Yes  | Yes  |  |  |  |  |  |   
[`restrict`](language/restrict.html "c/language/restrict") pointers  | [N448](https://open-std.org/JTC1/SC22/WG14/www/docs/n448.pdf) | 2.95  | Yes  | partial* |  |  |  |  |  |   
Enhanced [arithmetic types](language/arithmetic_types.html "c/language/arithmetic types") | [N815](https://open-std.org/JTC1/SC22/WG14/www/docs/n815.htm)  
[N601](https://open-std.org/JTC1/SC22/WG14/www/docs/n601.ps)  
[N620](https://open-std.org/JTC1/SC22/WG14/www/docs/n620.ps)  
[N638](https://open-std.org/JTC1/SC22/WG14/www/docs/n638.ps)  
[N657](https://open-std.org/JTC1/SC22/WG14/www/docs/n657.ps)  
[N694](https://open-std.org/JTC1/SC22/WG14/www/docs/n694.ps)  
[N809](https://open-std.org/JTC1/SC22/WG14/www/docs/n809.ps) | Yes  | partial  | Maybe  |  |  |  |  |  |   
Flexible array members  |  | 3.0  | Yes  | Yes  |  |  |  |  |  |   
[Variable-length array](language/array.html#Variable-length_arrays "c/language/array") (VLA) types  | [N683](https://open-std.org/JTC1/SC22/WG14/www/docs/n683.htm) | 0.9  | Yes  |  |  |  |  |  |  |   
Variably-modified (VM) types  | [N2778](https://open-std.org/JTC1/SC22/WG14/www/docs/n2778.pdf) |  N/A | Yes  |  |  |  |  |  |  |   
Designated initializers  | [N494](https://open-std.org/JTC1/SC22/WG14/www/docs/n494.pdf) | 3.0  | Yes  | Yes  |  |  |  |  |  |   
Non-constant initializers  |  | 1.21  |  N/A |  |  |  |  |  |  |   
Idempotent cvr-qualifiers  | [N505](https://open-std.org/JTC1/SC22/WG14/www/docs/n505.pdf) | 3.0  |  N/A |  |  |  |  |  |  |   
Trailing comma in [enumerator-list](language/enum.html "c/language/enum") |  | 0.9  | Yes  | Yes  |  |  |  |  |  |   
Hexadecimal [floating constants](language/floating_constant.html "c/language/floating constant") | [N308](https://open-std.org/JTC1/SC22/WG14/www/docs/n308.pdf) | 2.8  | Yes  | Yes  |  |  |  |  |  |   
[Compound literals](language/compound_literal.html "c/language/compound literal") | [N716](https://open-std.org/JTC1/SC22/WG14/www/docs/n716.htm) | 3.1  | Yes  | Yes  |  |  |  |  |  |   
Floating-point environment  |  | partial  | partial  |  |  |  |  |  |  |   
Requiring truncation for divisions of signed integer types  | [N617](https://open-std.org/JTC1/SC22/WG14/www/docs/n617.htm) | 0.9  |  N/A |  |  |  |  |  |  |   
Implicit return 0; in the [`main()` function](language/main_function.html "c/language/main function") |  | Yes  | Yes  | Yes  |  |  |  |  |  |   
Declarations and statements in mixed order  | [N740](https://open-std.org/JTC1/SC22/WG14/www/docs/n740.htm) | 3.0  | Yes  | Yes  |  |  |  |  |  |   
init-statement in [`for`](language/for.html "c/language/for") loops  |  | Yes  | Yes  | Yes  |  |  |  |  |  |   
[`inline`](language/inline.html "c/language/inline") functions  | [N741](https://open-std.org/JTC1/SC22/WG14/www/docs/n741.htm) | 4.3  | Yes  | Yes  |  |  |  |  |  |   
Predefined variable [`__func__`](language/function_definition.html "c/language/function definition") | [N611](https://open-std.org/JTC1/SC22/WG14/www/docs/n611.ps) | 2.95  | Yes  | Yes  |  |  |  |  |  |   
Cvr-qualifiers and static in [] within function declarations  |  | 3.1  | Yes  |  |  |  |  |  |  |   
[Variadic macros](preprocessor/replace.html "c/preprocessor/replace") | [N707](https://open-std.org/JTC1/SC22/WG14/www/docs/n707.htm) | 2.95  | Yes  | Yes  |  |  |  |  |  |   
[`_Pragma`](preprocessor/impl.html "c/preprocessor/impl") preprocessor operator  | [N634](https://open-std.org/JTC1/SC22/WG14/www/docs/n634.ps) | 3.0  | Yes  | partial* |  |  |  |  |  |   
Standard pragmas for floating-point evaluation  | [N631](https://open-std.org/JTC1/SC22/WG14/www/docs/n631.htm)  
[N696](https://open-std.org/JTC1/SC22/WG14/www/docs/n696.ps) |  No  |  No  |  |  |  |  |  |  |   
  
  
C99 feature  |    
  
Paper(s)  | GCC | Clang | MSVC | Apple Clang | EDG eccp | Intel C++ | Nvidia HPC C++ (ex PGI)* | Nvidia nvcc | Cray  
  
  


### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/compiler_support&action=edit&section=3 "Edit section: See also")] See also

[C++ documentation](../cpp/compiler_support.html "cpp/compiler support") for compiler support  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/compiler_support&oldid=145580](https://en.cppreference.com/mwiki/index.php?title=c/compiler_support&oldid=145580)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../Category%253ATodo_with_reason.html "Category:Todo with reason")



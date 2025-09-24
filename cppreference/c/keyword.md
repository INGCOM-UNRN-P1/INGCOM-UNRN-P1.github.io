From cppreference.com

< [c](../c.html "c")

[ C](../c.html "c")

[Compiler support](compiler_support.html "c/compiler support")  
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

[ C language](language.html "c/language")

[Basic concepts](language/basic_concepts.html "c/language/basic concepts")  
---  
**Keywords**  
[ Preprocessor](preprocessor.html "c/preprocessor")  
[ Statements](language/statements.html "c/language/statements")  
[ Expressions](language/operators.html "c/language/expressions")  
[ Initialization](language/initialization.html "c/language/initialization")  
[ Declarations](language/declarations.html "c/language/declarations")  
[ Functions](language/functions.html "c/language/functions")  
Miscellaneous  
[ History of C](language/history.html "c/language/history")  
[Technical Specifications](experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

**Keywords**

| [alignas](keyword/alignas.html "c/keyword/alignas")(C23)  
---  
[alignof](keyword/alignof.html "c/keyword/alignof")(C23)  
[auto](keyword/auto.html "c/keyword/auto")  
[bool](keyword/bool.html "c/keyword/bool")(C23)  
[break](keyword/break.html "c/keyword/break")  
[case](keyword/case.html "c/keyword/case")  
[char](keyword/char.html "c/keyword/char")  
[const](keyword/const.html "c/keyword/const")  
[constexpr](keyword/constexpr.html "c/keyword/constexpr")(C23)` `  
[continue](keyword/continue.html "c/keyword/continue")  
[default](keyword/default.html "c/keyword/default")  
[do](keyword/do.html "c/keyword/do")  
[double](keyword/double.html "c/keyword/double")  
[else](keyword/else.html "c/keyword/else")  
[enum](keyword/enum.html "c/keyword/enum")  
  
| [extern](keyword/extern.html "c/keyword/extern")  
---  
[false](keyword/false.html "c/keyword/false")(C23)  
[float](keyword/float.html "c/keyword/float")  
[for](keyword/for.html "c/keyword/for")  
[goto](keyword/goto.html "c/keyword/goto")  
[if](keyword/if.html "c/keyword/if")  
[inline](keyword/inline.html "c/keyword/inline")(C99)  
[int](keyword/int.html "c/keyword/int")  
[long](keyword/long.html "c/keyword/long")  
[nullptr](keyword/nullptr.html "c/keyword/nullptr")(C23)  
[register](keyword/register.html "c/keyword/register")  
[restrict](keyword/restrict.html "c/keyword/restrict")(C99)` `  
[return](keyword/return.html "c/keyword/return")  
[short](keyword/short.html "c/keyword/short")  
[signed](keyword/signed.html "c/keyword/signed")  
  
| [sizeof](keyword/sizeof.html "c/keyword/sizeof")  
---  
[static](keyword/static.html "c/keyword/static")  
[static_assert](keyword/static_assert.html "c/keyword/static assert")(C23)  
[struct](keyword/struct.html "c/keyword/struct")  
[switch](keyword/switch.html "c/keyword/switch")  
[thread_local](keyword/thread_local.html "c/keyword/thread local")(C23)  
[true](keyword/true.html "c/keyword/true")(C23)  
[typedef](keyword/typedef.html "c/keyword/typedef")  
[typeof](keyword/typeof.html "c/keyword/typeof")(C23)  
[typeof_unqual](keyword/typeof_unqual.html "c/keyword/typeof unqual")(C23)` `  
[union](keyword/union.html "c/keyword/union")  
[unsigned](keyword/unsigned.html "c/keyword/unsigned")  
[void](keyword/void.html "c/keyword/void")  
[volatile](keyword/volatile.html "c/keyword/volatile")  
[while](keyword/while.html "c/keyword/while")  
  
| [_Alignas](keyword/_Alignas.html "c/keyword/ Alignas")(C11*)  
---  
[_Alignof](keyword/_Alignof.html "c/keyword/ Alignof")(C11*)  
[_Atomic](keyword/_Atomic.html "c/keyword/ Atomic")(C11)  
[_BigInt](https://en.cppreference.com/mwiki/index.php?title=c/keyword/_BigInt&action=edit&redlink=1 "c/keyword/ BigInt \(page does not exist\)")(C23)  
[_Bool](keyword/_Bool.html "c/keyword/ Bool")(C99*)  
[_Complex](keyword/_Complex.html "c/keyword/ Complex")(C99)  
[_Decimal128](keyword/_Decimal128.html "c/keyword/ Decimal128")(C23)  
[_Decimal32](keyword/_Decimal32.html "c/keyword/ Decimal32")(C23)  
[_Decimal64](keyword/_Decimal64.html "c/keyword/ Decimal64")(C23)  
[_Generic](keyword/_Generic.html "c/keyword/ Generic")(C11)  
[_Imaginary](keyword/_Imaginary.html "c/keyword/ Imaginary")(C99)  
[_Noreturn](keyword/_Noreturn.html "c/keyword/ Noreturn")(C11*)  
[_Static_assert](keyword/_Static_assert.html "c/keyword/ Static assert")(C11*)  
[_Thread_local](keyword/_Thread_local.html "c/keyword/ Thread local")(C11*)  
  
conditionally-supported  
| [asm](language/asm.html "c/language/asm")  
---  
  
| [fortran](keyword/fortran.html "c/keyword/fortran")  
---  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/keyword/navbar_content&action=edit)

This is a list of reserved keywords in C. Since they are used by the language, these keywords are not available for re-definition. As an exception, they are not considered reserved in [attribute-tokens](language/attributes.html "c/language/attributes").(since C23)

[`alignas`](keyword/alignas.html "c/keyword/alignas") (C23)  
[`alignof`](keyword/alignof.html "c/keyword/alignof") (C23)  
[`auto`](keyword/auto.html "c/keyword/auto")  
[`bool`](keyword/bool.html "c/keyword/bool") (C23)  
[`break`](keyword/break.html "c/keyword/break")  
[`case`](keyword/case.html "c/keyword/case")  
[`char`](keyword/char.html "c/keyword/char")  
[`const`](keyword/const.html "c/keyword/const")  
[`constexpr`](keyword/constexpr.html "c/keyword/constexpr") (C23)  
[`continue`](keyword/continue.html "c/keyword/continue")  
[`default`](keyword/default.html "c/keyword/default")  
[`do`](keyword/do.html "c/keyword/do")  
[`double`](keyword/double.html "c/keyword/double")  
[`else`](keyword/else.html "c/keyword/else")  
[`enum`](keyword/enum.html "c/keyword/enum")  
|  [`extern`](keyword/extern.html "c/keyword/extern")  
[`false`](keyword/false.html "c/keyword/false") (C23)  
[`float`](keyword/float.html "c/keyword/float")  
[`for`](keyword/for.html "c/keyword/for")  
[`goto`](keyword/goto.html "c/keyword/goto")  
[`if`](keyword/if.html "c/keyword/if")  
[`inline`](keyword/inline.html "c/keyword/inline") (C99)  
[`int`](keyword/int.html "c/keyword/int")  
[`long`](keyword/long.html "c/keyword/long")  
[`nullptr`](keyword/nullptr.html "c/keyword/nullptr") (C23)  
[`register`](keyword/register.html "c/keyword/register")  
[`restrict`](keyword/restrict.html "c/keyword/restrict") (C99)  
[`return`](keyword/return.html "c/keyword/return")  
[`short`](keyword/short.html "c/keyword/short")  
[`signed`](keyword/signed.html "c/keyword/signed")  
|  [`sizeof`](keyword/sizeof.html "c/keyword/sizeof")  
[`static`](keyword/static.html "c/keyword/static")  
[`static_assert`](keyword/static_assert.html "c/keyword/static assert") (C23)  
[`struct`](keyword/struct.html "c/keyword/struct")  
[`switch`](keyword/switch.html "c/keyword/switch")  
[`thread_local`](keyword/thread_local.html "c/keyword/thread local") (C23)  
[`true`](keyword/true.html "c/keyword/true") (C23)  
[`typedef`](keyword/typedef.html "c/keyword/typedef")  
[`typeof`](keyword/typeof.html "c/keyword/typeof") (C23)  
[`typeof_unqual`](keyword/typeof_unqual.html "c/keyword/typeof unqual") (C23)  
[`union`](keyword/union.html "c/keyword/union")  
[`unsigned`](keyword/unsigned.html "c/keyword/unsigned")  
[`void`](keyword/void.html "c/keyword/void")  
[`volatile`](keyword/volatile.html "c/keyword/volatile")  
[`while`](keyword/while.html "c/keyword/while")  
|  [`_Alignas`](keyword/_Alignas.html "c/keyword/ Alignas") (C11)(deprecated in C23)  
[`_Alignof`](keyword/_Alignof.html "c/keyword/ Alignof") (C11)(deprecated in C23)  
[`_Atomic`](keyword/_Atomic.html "c/keyword/ Atomic") (C11)  
[`_BitInt`](https://en.cppreference.com/mwiki/index.php?title=c/keyword/_BitInt&action=edit&redlink=1 "c/keyword/ BitInt \(page does not exist\)") (C23)  
[`_Bool`](keyword/_Bool.html "c/keyword/ Bool") (C99)(deprecated in C23)  
[`_Complex`](keyword/_Complex.html "c/keyword/ Complex") (C99)  
[`_Decimal128`](keyword/_Decimal128.html "c/keyword/ Decimal128") (C23)  
[`_Decimal32`](keyword/_Decimal32.html "c/keyword/ Decimal32") (C23)  
[`_Decimal64`](keyword/_Decimal64.html "c/keyword/ Decimal64") (C23)  
[`_Generic`](keyword/_Generic.html "c/keyword/ Generic") (C11)  
[`_Imaginary`](keyword/_Imaginary.html "c/keyword/ Imaginary") (C99)  
[`_Noreturn`](keyword/_Noreturn.html "c/keyword/ Noreturn") (C11)(deprecated in C23)  
[`_Static_assert`](keyword/_Static_assert.html "c/keyword/ Static assert") (C11)(deprecated in C23)  
[`_Thread_local`](keyword/_Thread_local.html "c/keyword/ Thread local") (C11)(deprecated in C23)  
  
---|---|---|---  
  
The most common keywords that begin with an underscore are generally used through their convenience macros: 

Keyword  | Used as  | Defined in   
---|---|---  
[`_Alignas`](keyword/_Alignas.html "c/keyword/ Alignas") (C11)(deprecated in C23) | [`alignas`](types.html "c/types") (removed in C23) | `stdalign.h`  
[`_Alignof`](keyword/_Alignof.html "c/keyword/ Alignof") (C11)(deprecated in C23) | [`alignof`](types.html "c/types") (removed in C23) | `stdalign.h`  
[`_Atomic`](keyword/_Atomic.html "c/keyword/ Atomic") (C11) | [`atomic_bool, atomic_int, ...`](thread.html "c/thread") | `stdatomic.h`  
[`_BitInt`](https://en.cppreference.com/mwiki/index.php?title=c/keyword/_BitInt&action=edit&redlink=1 "c/keyword/ BitInt \(page does not exist\)") (C23) | (no macro)  |   
[`_Bool`](keyword/_Bool.html "c/keyword/ Bool") (C99)(deprecated in C23) | [`bool`](types.html "c/types") (removed in C23) | `stdbool.h`  
[`_Complex`](keyword/_Complex.html "c/keyword/ Complex") (C99) | [`complex`](numeric/complex/complex.html "c/numeric/complex/complex") | `complex.h`  
[`_Decimal128`](keyword/_Decimal128.html "c/keyword/ Decimal128") (C23) | (no macro)  |   
[`_Decimal32`](keyword/_Decimal32.html "c/keyword/ Decimal32") (C23) | (no macro)  |   
[`_Decimal64`](keyword/_Decimal64.html "c/keyword/ Decimal64") (C23) | (no macro)  |   
[`_Generic`](keyword/_Generic.html "c/keyword/ Generic") (C11) | (no macro)  |   
[`_Imaginary`](keyword/_Imaginary.html "c/keyword/ Imaginary") (C99) | [`imaginary`](numeric/complex/imaginary.html "c/numeric/complex/imaginary") | `complex.h`  
[`_Noreturn`](keyword/_Noreturn.html "c/keyword/ Noreturn") (C11)(deprecated in C23) | [`noreturn`](types.html "c/types") | `stdnoreturn.h`  
[`_Static_assert`](keyword/_Static_assert.html "c/keyword/ Static assert") (C11)(deprecated in C23) | [`static_assert`](error/static_assert.html "c/error/static assert") (removed in C23) | `assert.h`  
[`_Thread_local`](keyword/_Thread_local.html "c/keyword/ Thread local") (C11)(deprecated in C23) | [`thread_local`](thread/thread_local.html "c/thread/thread local") (removed in C23) | `threads.h`  
  
Some keywords are deprecated and retained as alternative spellings for compatibility purposes. These can be used wherever the keyword can. 

Keyword  | Alternative spelling   
---|---  
`alignas` (C23) | `_Alignas` (C11)(deprecated in C23)  
`alignof` (C23) | `_Alignof` (C11)(deprecated in C23)  
`bool` (C23) | `_Bool` (C99)(deprecated in C23)  
`static_assert` (C23) | `_Static_assert` (C11)(deprecated in C23)  
`thread_local` (C23) | `_Thread_local` (C11)(deprecated in C23)  
  
It is unspecified whether any of the spellings of these keywords, their alternate forms, or `true` and `false` is implemented as a predefined macro. 

Each name that begins with a double underscore `**__**` or an underscore `**_**` followed by an uppercase letter is reserved: see [identifier](language/identifiers.html#Reserved_identifiers "c/language/identifier") for details. 

Note that digraphs `<%`, `%>`, `<:`, `:>`, `%:`, and `%:%:` provide an [alternative way to represent standard tokens](language/operator_alternative.html "c/language/operator alternative"). 

The following tokens are recognized by the [preprocessor](preprocessor.html "c/preprocessor") when they are used _within_ the context of a preprocessor directive: 

[`if`](preprocessor/conditional.html "c/preprocessor/conditional")  
[`elif`](preprocessor/conditional.html "c/preprocessor/conditional")  
[`else`](preprocessor/conditional.html "c/preprocessor/conditional")  
[`endif`](preprocessor/conditional.html "c/preprocessor/conditional")  
|  [`ifdef`](preprocessor/conditional.html "c/preprocessor/conditional")  
[`ifndef`](preprocessor/conditional.html "c/preprocessor/conditional")  
[`elifdef`](preprocessor/conditional.html "c/preprocessor/conditional") (C23)  
[`elifndef`](preprocessor/conditional.html "c/preprocessor/conditional") (C23)  
[`define`](preprocessor/replace.html "c/preprocessor/replace")  
[`undef`](preprocessor/replace.html "c/preprocessor/replace")  
|  [`include`](preprocessor/include.html "c/preprocessor/include")  
[`embed`](preprocessor/embed.html "c/preprocessor/embed") (C23)  
[`line`](preprocessor/line.html "c/preprocessor/line")  
[`error`](preprocessor/warning.html "c/preprocessor/error")  
[`warning`](preprocessor/warning.html "c/preprocessor/error") (C23)  
[`pragma`](preprocessor/impl.html "c/preprocessor/impl")  
|  [`defined`](preprocessor/conditional.html "c/preprocessor/conditional")  
[`__has_include`](preprocessor/include.html "c/preprocessor/include") (C23)  
[`__has_embed`](preprocessor/embed.html "c/preprocessor/embed") (C23)  
[`__has_c_attribute`](language/attributes.html#Attribute_testing "c/language/attributes") (C23)  
---|---|---|---  
  
The following tokens are recognized by the preprocessor when they are used _outside_ the context of a preprocessor directive: 

[`_Pragma`](preprocessor/impl.html "c/preprocessor/impl") (C99)  
---  
  
The following additional keywords are classified as extensions and conditionally-supported: 

[`asm`](language/asm.html "c/language/asm")  
[`fortran`](keyword/fortran.html "c/keyword/fortran")  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/keyword&action=edit&section=1 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.4.1 Keywords (p: 53) 



    

  * J.5.9 The fortran keyword (p: 601) 



    

  * J.5.10 The asm keyword (p: 601) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.4.1 Keywords (p: 42-43) 



    

  * J.5.9 The fortran keyword (p: 422) 



    

  * J.5.10 The asm keyword (p: 422) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.4.1 Keywords (p: 58-59) 



    

  * J.5.9 The fortran keyword (p: 580) 



    

  * J.5.10 The asm keyword (p: 580) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.4.1 Keywords (p: 50) 



    

  * J.5.9 The fortran keyword (p: 514) 



    

  * J.5.10 The asm keyword (p: 514) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.1.1 Keywords 



    

  * G.5.9 The fortran keyword 



    

  * G.5.10 The asm keyword 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/keyword&action=edit&section=2 "Edit section: See also")] See also

[C++ documentation](../cpp/keywords.html "cpp/keyword") for keywords  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/keyword&oldid=182855](https://en.cppreference.com/mwiki/index.php?title=c/keyword&oldid=182855)" 

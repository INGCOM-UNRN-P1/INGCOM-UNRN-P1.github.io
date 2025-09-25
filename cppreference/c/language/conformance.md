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

_Conformance_ has a three-fold definition: 

  * _strictly conforming program_ \- uses only well-defined language constructs, that is constructs with a single behavior. It excludes unspecified, undefined, or implementation-defined behavior, and does not exceed any minimum implementation limit. 
  * _conforming program_ \- acceptable to a conforming implementation. 
  * _conforming implementation_ \- 
    * A conforming hosted implementation shall accept any strictly conforming program. 
    * A conforming freestanding implementation shall accept any strictly conforming program in which the use of the features specified in the library clause (clause 7) is confined to the contents of the freestanding standard library headers (see below). 
    * A conforming implementation may have extensions (including additional library functions), provided they do not alter the behavior of any strictly conforming program. 



## Contents

  * [1 Explanation](conformance.html#Explanation)
    * [1.1 Freestanding standard library headers](conformance.html#Freestanding_standard_library_headers)
      * [1.1.1 Fully freestanding standard library headers](conformance.html#Fully_freestanding_standard_library_headers)
      * [1.1.2 Conditionally fully freestanding standard library headers](conformance.html#Conditionally_fully_freestanding_standard_library_headers)
      * [1.1.3 Partially freestanding standard library headers](conformance.html#Partially_freestanding_standard_library_headers)
  * [2 References](conformance.html#References)
  * [3 See also](conformance.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conformance&action=edit&section=1 "Edit section: Explanation")] Explanation

The standard does not define any minimum implementation limit on translation units. A hosted environment has an operating system; a freestanding environment does not. A program running in a hosted environment may use all features described in the library clause (clause 7); a program running in a freestanding environment may use a subset of library features required by clause 4. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conformance&action=edit&section=2 "Edit section: Freestanding standard library headers")] Freestanding standard library headers

All standard library features in every fully freestanding header are required to be provided by a freestanding implementation. 

Some standard library headers are conditionally freestanding. 

  * If the implementation predefines the macro `__STDC_IEC_60559_BFP__` or `__STDC_IEC_60559_DFP__`, then [`<math.h>`](../header/math.html "c/header/math") and [`<fenv.h>`](../header/fenv.html "c/header/fenv") are fully freestanding headers. However, the behavior of functions in these headers is required to be well-defined in a freestanding environment only if a program does not set the state of the [`FENV_ACCESS`](../preprocessor/impl.html#Standard_pragmas "c/preprocessor/impl") pragma to `ON`. 

Some standard library headers are partially freestanding. 

  * In [`<stdlib.h>`](../header/stdlib.html "c/header/stdlib"), [`memalignment`](../program/memalignment.html "c/program/memalignment") is freestanding. Additionally, when `__STDC_IEC_60559_BFP__` or `__STDC_IEC_60559_DFP__` are predefined, numeric conversion functions (`ato _X_`, `strto _X_`, and `strfrom _X_`) are also freestanding, while their behavior is required to be well-defined in a freestanding environment only if a program does not set the state of the [`FENV_ACCESS`](../preprocessor/impl.html#Standard_pragmas "c/preprocessor/impl") pragma to `ON`. No other component in [`<stdlib.h>`](../header/stdlib.html "c/header/stdlib") is required to be to be provided by a freestanding implementation. 
  * In [`<string.h>`](../header/string.html "c/header/string"), [`strdup`](../string/byte/strdup.html "c/string/byte/strdup"), [`strndup`](../string/byte/strndup.html "c/string/byte/strndup"), [strcoll](../string/byte/strcoll.html "c/string/byte/strcoll"), [strxfrm](../string/byte/strxfrm.html "c/string/byte/strxfrm"), [strtok](../string/byte/strtok.html "c/string/byte/strtok"), and [strerror](../string/byte/strerror.html "c/string/byte/strerror") are not required to be provided by a freestanding implementation. 

| (since C23)  
---|---  
  
#####  Fully freestanding standard library headers   
  
---  
[`<float.h>`](../header/float.html "c/header/float") |  [Limits of floating-point types](../types/limits.html#Limits_of_floating-point_types "c/types/limits")  
[`<iso646.h>`](../header/iso646.html "c/header/iso646") (since C95) |  [Alternative operator spellings](operator_alternative.html "c/language/operator alternative")  
[`<limits.h>`](../header/limits.html "c/header/limits") |  [Ranges of integer types](../types/limits.html "c/types/limits")  
[`<stdalign.h>`](../header/stdalign.html "c/header/stdalign") (since C11) |  [`alignas` and `alignof`](../types.html "c/types") convenience macros   
[`<stdarg.h>`](../header/stdarg.html "c/header/stdarg") |  [Variable arguments](../variadic.html "c/variadic")  
[`<stdbool.h>`](../header/stdbool.html "c/header/stdbool") (since C99) |  [Macros for boolean type](../types.html "c/types")  
[`<stddef.h>`](../header/stddef.html "c/header/stddef") |  [Common macro definitions](../types.html "c/types")  
[`<stdint.h>`](../header/stdint.html "c/header/stdint") (since C99) |  [Fixed-width integer types](../types/integer.html "c/types/integer")  
[`<stdnoreturn.h>`](../header/stdnoreturn.html "c/header/stdnoreturn") (since C11) |  [`noreturn`](../types.html "c/types") convenience macro   
[`<stdbit.h>`](../header/stdbit.html "c/header/stdbit") (since C23) |  Macros to work with the byte and bit representations of types   
  
#####  Conditionally fully freestanding standard library headers   
  
[`<fenv.h>`](../header/fenv.html "c/header/fenv") (since C23) |  [Floating-point environment](../numeric/fenv.html "c/numeric/fenv")  
[`<math.h>`](../header/math.html "c/header/math") (since C23) |  [Common mathematics functions](../numeric/math.html "c/numeric/math")  
  
#####  Partially freestanding standard library headers   
  
[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib") (since C23) |  General utilities: [memory management](../memory.html "c/memory"), [program utilities](../program.html "c/program"), [string conversions](../string.html "c/string"), [random numbers](../numeric/random.html "c/numeric/random"), [algorithms](../algorithm.html "c/algorithm")  
[`<string.h>`](../header/string.html "c/header/string") (since C23) |  [String handling](../string/byte.html "c/string/byte")  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conformance&action=edit&section=3 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 4 Conformance (p: 9-10) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 4 Conformance (p: 4) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 4 Conformance (p: 8-9) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 4 Conformance (p: 7-8) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 1.7 Compliance 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/conformance&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../cpp/freestanding.html "cpp/freestanding") for Freestanding and hosted implementation  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/conformance&oldid=177001](https://en.cppreference.com/mwiki/index.php?title=c/language/conformance&oldid=177001)" 

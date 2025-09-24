From cppreference.com

< [c](../c.html "c")

[ C](../c.html "c")

[Compiler support](compiler_support.html "c/compiler support")  
---  
[Language](language.html "c/language")  
**Headers**  
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

**Standard Library headers**

| [`<assert.h>`](header/assert.html "c/header/assert")  
---  
[`<complex.h>`](header/complex.html "c/header/complex") (C99)  
[`<ctype.h>`](header/ctype.html "c/header/ctype")  
[`<errno.h>`](header/errno.html "c/header/errno")  
[`<fenv.h>`](header/fenv.html "c/header/fenv") (C99)  
[`<float.h>`](header/float.html "c/header/float")  
[`<inttypes.h>`](header/inttypes.html "c/header/inttypes") (C99)` `  
[`<iso646.h>`](header/iso646.html "c/header/iso646") (C95)  
[`<limits.h>`](header/limits.html "c/header/limits")  
[`<locale.h>`](header/locale.html "c/header/locale")  
[`<math.h>`](header/math.html "c/header/math")  
  
| [`<setjmp.h>`](header/setjmp.html "c/header/setjmp")  
---  
[`<signal.h>`](header/signal.html "c/header/signal")  
[`<stdalign.h>`](header/stdalign.html "c/header/stdalign") (C11*)  
[`<stdarg.h>`](header/stdarg.html "c/header/stdarg")  
[`<stdatomic.h>`](header/stdatomic.html "c/header/stdatomic") (C11)` `  
[`<stdbit.h>`](header/stdbit.html "c/header/stdbit") (C23)  
[`<stdbool.h>`](header/stdbool.html "c/header/stdbool") (C99*)  
[`<stdckdint.h>`](header/stdckdint.html "c/header/stdckdint") (C23)  
[`<stddef.h>`](header/stddef.html "c/header/stddef")  
[`<stdint.h>`](header/stdint.html "c/header/stdint") (C99)  
[`<stdio.h>`](header/stdio.html "c/header/stdio")  
  
| [`<stdlib.h>`](header/stdlib.html "c/header/stdlib")  
---  
[`<stdmchar.h>`](header/stdmchar.html "c/header/stdmchar") (C29)  
[`<stdnoreturn.h>`](header/stdnoreturn.html "c/header/stdnoreturn") (C11*)  
[`<string.h>`](header/string.html "c/header/string")  
[`<tgmath.h>`](header/tgmath.html "c/header/tgmath") (C99)  
[`<threads.h>`](header/threads.html "c/header/threads") (C11)  
[`<time.h>`](header/time.html "c/header/time")  
[`<uchar.h>`](header/uchar.html "c/header/uchar") (C11)  
[`<wchar.h>`](header/wchar.html "c/header/wchar") (C95)  
[`<wctype.h>`](header/wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

The interface of C standard library is defined by the following collection of headers. 

[ <assert.h>](header/assert.html "c/header/assert") |  [Conditionally compiled macro that compares its argument to zero](error.html "c/error")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_assert&action=edit)  
---|---  
[ <complex.h>](header/complex.html "c/header/complex")(C99) |  [Complex number arithmetic](numeric/complex.html "c/numeric/complex")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_complex&action=edit)  
[ <ctype.h>](header/ctype.html "c/header/ctype") |  [Functions to determine the type contained in character data](string/byte.html "c/string/byte")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_ctype&action=edit)  
[ <errno.h>](header/errno.html "c/header/errno") |  [Macros reporting error conditions](error.html "c/error")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_errno&action=edit)  
[ <fenv.h>](header/fenv.html "c/header/fenv")(C99) |  [Floating-point environment](numeric/fenv.html "c/numeric/fenv")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_fenv&action=edit)  
[ <float.h>](header/float.html "c/header/float") |  [Limits of floating-point types](types/limits.html#Limits_of_floating-point_types "c/types/limits")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_float&action=edit)  
[ <inttypes.h>](header/inttypes.html "c/header/inttypes")(C99) |  [Format conversion of integer types](types/integer.html "c/types/integer")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_inttypes&action=edit)  
[ <iso646.h>](header/iso646.html "c/header/iso646")(C95) |  [Alternative operator spellings](language/operator_alternative.html "c/language/operator alternative")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_iso646&action=edit)  
[ <limits.h>](header/limits.html "c/header/limits") |  [Ranges of integer types](types/limits.html "c/types/limits")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_limits&action=edit)  
[ <locale.h>](header/locale.html "c/header/locale") |  [Localization utilities](locale.html "c/locale")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_locale&action=edit)  
[ <math.h>](header/math.html "c/header/math") |  [Common mathematics functions](numeric/math.html "c/numeric/math")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_math&action=edit)  
[ <setjmp.h>](header/setjmp.html "c/header/setjmp") |  [Nonlocal jumps](program.html "c/program")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_setjmp&action=edit)  
[ <signal.h>](header/signal.html "c/header/signal") |  [Signal handling](program.html "c/program")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_signal&action=edit)  
[ <stdalign.h>](header/stdalign.html "c/header/stdalign")(since C11)(deprecated in C23) |  [`alignas` and `alignof`](types.html "c/types") convenience macros[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_stdalign&action=edit)  
[ <stdarg.h>](header/stdarg.html "c/header/stdarg") |  [Variable arguments](variadic.html "c/variadic")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_stdarg&action=edit)  
[ <stdatomic.h>](header/stdatomic.html "c/header/stdatomic")(C11) |  [Atomic operations](thread.html#Atomic_operations "c/thread")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_stdatomic&action=edit)  
[ <stdbit.h>](header/stdbit.html "c/header/stdbit")(C23) |  [Macros to work with the byte and bit representations of types](numeric.html#Bit_manipulation "c/numeric")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_stdbit&action=edit)  
[ <stdbool.h>](header/stdbool.html "c/header/stdbool")(since C99)(deprecated in C23) |  [Macros for boolean type](types.html "c/types")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_stdbool&action=edit)  
[ <stdckdint.h>](header/stdckdint.html "c/header/stdckdint")(C23) |  [Macros for performing checked integer arithmetic](numeric.html#Checked_integer_arithmetic "c/numeric")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_stdckdint&action=edit)  
[ <stddef.h>](header/stddef.html "c/header/stddef") |  [Common macro definitions](types.html "c/types")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_stddef&action=edit)  
[ <stdint.h>](header/stdint.html "c/header/stdint")(C99) |  [Fixed-width integer types](types/integer.html "c/types/integer")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_stdint&action=edit)  
[ <stdio.h>](header/stdio.html "c/header/stdio") |  [Input/output](io.html "c/io")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_stdio&action=edit)  
[ <stdlib.h>](header/stdlib.html "c/header/stdlib") |  General utilities: [memory management](memory.html "c/memory"), [program utilities](program.html "c/program"), [string conversions](string.html "c/string"), [random numbers](numeric/random.html "c/numeric/random"), [algorithms](algorithm.html "c/algorithm")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_stdlib&action=edit)  
[ <stdmchar.h>](header/stdmchar.html "c/header/stdmchar")(since C29) |  Text transcode[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_stdmchar&action=edit)  
[ <stdnoreturn.h>](header/stdnoreturn.html "c/header/stdnoreturn")(since C11)(deprecated in C23) |  [`noreturn`](language/noreturn.html "c/language/ Noreturn") convenience macro[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_stdnoreturn&action=edit)  
[ <string.h>](header/string.html "c/header/string") |  [String handling](string/byte.html "c/string/byte")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_string&action=edit)  
[ <tgmath.h>](header/tgmath.html "c/header/tgmath")(C99) |  [Type-generic math](numeric/tgmath.html "c/numeric/tgmath") (macros wrapping [`<math.h>`](header/math.html "c/header/math") and [`<complex.h>`](header/complex.html "c/header/complex"))[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_tgmath&action=edit)  
[ <threads.h>](header/threads.html "c/header/threads")(C11) |  [Thread library](thread.html "c/thread")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_threads&action=edit)  
[ <time.h>](header/time.html "c/header/time") |  [Time/date utilities](chrono.html "c/chrono")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_time&action=edit)  
[ <uchar.h>](header/uchar.html "c/header/uchar")(C11) |  [UTF-16 and UTF-32 character utilities](string/multibyte.html "c/string/multibyte")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_uchar&action=edit)  
[ <wchar.h>](header/wchar.html "c/header/wchar")(C95) |  [Extended multibyte and wide character utilities](string/wide.html "c/string/wide")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_wchar&action=edit)  
[ <wctype.h>](header/wctype.html "c/header/wctype")(C95) |  [Functions to determine the type contained in wide character data](string/wide.html "c/string/wide")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_wctype&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header&action=edit&section=1 "Edit section: Feature test macros \(since C23\)")] Feature test macros (since C23)

Feature test macros are defined in corresponding headers respectively since C23. Note that not all headers contain such a macro. 

#  | Header  | Macro name  | Value   
---|---|---|---  
1  | [`<assert.h>`](header/assert.html "c/header/assert") | __STDC_VERSION_ASSERT_H__ | 202311L  
2  | [`<complex.h>`](header/complex.html "c/header/complex") | __STDC_VERSION_COMPLEX_H__ | 202311L  
3  | [`<ctype.h>`](header/ctype.html "c/header/ctype") |  N/A  
4  | [`<errno.h>`](header/errno.html "c/header/errno") |  N/A  
5  | [`<fenv.h>`](header/fenv.html "c/header/fenv") | __STDC_VERSION_FENV_H__ | 202311L  
6  | [`<float.h>`](header/float.html "c/header/float") | __STDC_VERSION_FLOAT_H__ | 202311L  
7  | [`<inttypes.h>`](header/inttypes.html "c/header/inttypes") | __STDC_VERSION_INTTYPES_H__ | 202311L  
8  | [`<iso646.h>`](header/iso646.html "c/header/iso646") |  N/A  
9  | [`<limits.h>`](header/limits.html "c/header/limits") | __STDC_VERSION_LIMITS_H__ | 202311L  
10  | [`<locale.h>`](header/locale.html "c/header/locale") |  N/A  
11  | [`<math.h>`](header/math.html "c/header/math") | __STDC_VERSION_MATH_H__ | 202311L  
12  | [`<setjmp.h>`](header/setjmp.html "c/header/setjmp") | __STDC_VERSION_SETJMP_H__ | 202311L  
13  | [`<signal.h>`](header/signal.html "c/header/signal") |  N/A  
14  | [`<stdalign.h>`](header/stdalign.html "c/header/stdalign") |  N/A  
15  | [`<stdarg.h>`](header/stdarg.html "c/header/stdarg") | __STDC_VERSION_STDARG_H__ | 202311L  
16  | [`<stdatomic.h>`](header/stdatomic.html "c/header/stdatomic") | __STDC_VERSION_STDATOMIC_H__ | 202311L  
17  | [`<stdbit.h>`](header/stdbit.html "c/header/stdbit") | __STDC_VERSION_STDBIT_H__ | 202311L  
18  | [`<stdbool.h>`](header/stdbool.html "c/header/stdbool") |  N/A  
19  | [`<stdckdint.h>`](header/stdckdint.html "c/header/stdckdint") | __STDC_VERSION_STDCKDINT_H__ | 202311L  
20  | [`<stddef.h>`](header/stddef.html "c/header/stddef") | __STDC_VERSION_STDDEF_H__ | 202311L  
21  | [`<stdint.h>`](header/stdint.html "c/header/stdint") | __STDC_VERSION_STDINT_H__ | 202311L  
22  | [`<stdio.h>`](header/stdio.html "c/header/stdio") | __STDC_VERSION_STDIO_H__ | 202311L  
23  | [`<stdlib.h>`](header/stdlib.html "c/header/stdlib") | __STDC_VERSION_STDLIB_H__ | 202311L  
24  | [`<stdmchar.h>`](header/stdmchar.html "c/header/stdmchar") | __STDC_VERSION_STDMCHAR_H__ | 2029??L  
25  | [`<stdnoreturn.h>`](header/stdnoreturn.html "c/header/stdnoreturn") |  N/A  
26  | [`<string.h>`](header/string.html "c/header/string") | __STDC_VERSION_STRING_H__ | 202311L  
27  | [`<tgmath.h>`](header/tgmath.html "c/header/tgmath") | __STDC_VERSION_TGMATH_H__ | 202311L  
28  | [`<threads.h>`](header/threads.html "c/header/threads") |  N/A  
29  | [`<time.h>`](header/time.html "c/header/time") | __STDC_VERSION_TIME_H__ | 202311L  
30  | [`<uchar.h>`](header/uchar.html "c/header/uchar") | __STDC_VERSION_UCHAR_H__ | 202311L  
31  | [`<wchar.h>`](header/wchar.html "c/header/wchar") | __STDC_VERSION_WCHAR_H__ | 202311L  
32  | [`<wctype.h>`](header/wctype.html "c/header/wctype") |  N/A  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header&action=edit&section=2 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.1.2 Standard headers (p: 191-192) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.1.2 Standard headers (p: 131-132) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.1.2 Standard headers (p: 181-182) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.1.2 Standard headers (p: 165) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.1.2 Standard headers 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header&action=edit&section=3 "Edit section: See also")] See also

[C++ documentation](../cpp/headers.html "cpp/header") for Standard Library headers  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header&oldid=183293](https://en.cppreference.com/mwiki/index.php?title=c/header&oldid=183293)" 

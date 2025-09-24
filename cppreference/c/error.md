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
**Error handling**  
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

**Error handling**

Error codes  
---  
[ Error codes](error/errno_macros.html "c/error/errno macros")  
[errno](error/errno.html "c/error/errno")  
Assertions  
[assert](error/assert.html "c/error/assert")  
[static_assert](error/static_assert.html "c/error/static assert")(C11)(removed in C23)  
Bounds checking  
[set_constraint_handler_s](error/set_constraint_handler_s.html "c/error/set constraint handler s")(C11)  
[abort_handler_s](error/abort_handler_s.html "c/error/abort handler s")(C11)  
[ignore_handler_s](error/ignore_handler_s.html "c/error/ignore handler s")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/navbar_content&action=edit)

## Contents

  * [1 Error numbers](error.html#Error_numbers)
  * [2 Assertions](error.html#Assertions)
  * [3 Bounds checking](error.html#Bounds_checking)
  * [4 Notes](error.html#Notes)
  * [5 References](error.html#References)
  * [6 See also](error.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error&action=edit&section=1 "Edit section: Error numbers")] Error numbers

Defined in header `[`<errno.h>`](header/errno.html "c/header/errno")`  
---  
[ errno](error/errno.html "c/error/errno") |  macro which expands to POSIX-compatible thread-local error number variable  
(macro variable) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/dsc_errno&action=edit)  
[ E2BIG, EACCES, ..., EXDEV](error/errno_macros.html "c/error/errno macros") |  macros for standard POSIX-compatible error conditions   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/dsc_errno_macros&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error&action=edit&section=2 "Edit section: Assertions")] Assertions

Defined in header `[`<assert.h>`](header/assert.html "c/header/assert")`  
---  
[ assert](error/assert.html "c/error/assert") |  aborts the program if the user-specified condition is not true. May be disabled for release builds   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/dsc_assert&action=edit)  
[ static_assert](error/static_assert.html "c/error/static assert")(C11)(removed in C23) |  issues a compile-time diagnostic if the value of a constant expression is false   
(keyword macro)  
  
###  Bounds checking

The standard library provides bounds-checked versions of some existing functions ([gets_s](io/gets.html "c/io/gets"), [fopen_s](io/fopen.html "c/io/fopen"), [printf_s](io/fprintf.html "c/io/fprintf"), [strcpy_s](string/byte/strcpy.html "c/string/byte/strcpy"), [wcscpy_s](string/wide/wcscpy.html "c/string/wide/wcscpy"), [mbstowcs_s](string/multibyte/mbstowcs.html "c/string/multibyte/mbstowcs"), [qsort_s](algorithm/qsort.html "c/algorithm/qsort"), [getenv_s](program/getenv.html "c/program/getenv"), etc). This functionality is _optional_ and is only available if __STDC_LIB_EXT1__ is defined. The following macros and functions support this functionality.  |   
---  
Defined in header `[`<errno.h>`](header/errno.html "c/header/errno")`  
Defined in header `[`<stdio.h>`](header/stdio.html "c/header/stdio")`  
errno_t(C11) |  a typedef for the type int, used to self-document functions that return [errno](error/errno.html "c/error/errno") values   
(typedef)  
Defined in header `[`<stddef.h>`](header/stddef.html "c/header/stddef")`  
Defined in header `[`<stdio.h>`](header/stdio.html "c/header/stdio")`  
Defined in header `[`<stdlib.h>`](header/stdlib.html "c/header/stdlib")`  
Defined in header `[`<string.h>`](header/string.html "c/header/string")`  
Defined in header `[`<time.h>`](header/time.html "c/header/time")`  
Defined in header `[`<wchar.h>`](header/wchar.html "c/header/wchar")`  
rsize_t(C11) |  a typedef for the same type as [size_t](types/size_t.html "c/types/size t"), used to self-document functions that range-check their parameters at runtime   
(typedef)  
Defined in header `[`<stdint.h>`](header/stdint.html "c/header/stdint")`  
RSIZE_MAX(C11) |  largest acceptable size for bounds-checked functions, expands to either constant or variable which may change at runtime (e.g. as the currently allocated memory size changes)  
(macro variable)  
Defined in header `[`<stdlib.h>`](header/stdlib.html "c/header/stdlib")`  
[ set_constraint_handler_s](error/set_constraint_handler_s.html "c/error/set constraint handler s")(C11) |  set the error callback for bounds-checked functions   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/set_constraint_handler_s&action=edit)  
[ abort_handler_s](error/abort_handler_s.html "c/error/abort handler s")(C11) |  abort callback for the bounds-checked functions   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/abort_handler_s&action=edit)  
[ ignore_handler_s](error/ignore_handler_s.html "c/error/ignore handler s")(C11) |  ignore callback for the bounds-checked functions   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/ignore_handler_s&action=edit)  
  
Note: implementations of bounds-checked functions are available as open-source libraries [Safe C](https://github.com/rurban/safeclib/) and [Slibc](https://code.google.com/archive/p/slibc/), and as part of Watcom C. There is also an incompatible set of bounds-checked functions available in Visual Studio. 

(since C11)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error&action=edit&section=4 "Edit section: Notes")] Notes

Since C23, [`static_assert`](language/static_assert.html "c/language/ Static assert") is itself a keyword, which may also be a predefined macro, so `<assert.h>` no longer provides it. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error&action=edit&section=5 "Edit section: References")] References

Extended content  
---  
  
  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.2 Diagnostics <assert.h> (p: TBD) 



    

  * 7.5 Errors <errno.h> (p: TBD) 



    

  * 7.19 Common definitions <stddef.h> (p: TBD) 



    

  * 7.20 Integer types <stdint.h> (p: TBD) 



    

  * 7.21 Input/output <stdio.h> (p: TBD) 



    

  * 7.22 General utilities <stdlib.h> (p: TBD) 



    

  * K.3.1.3 Use of errno (p: TBD) 



    

  * K.3.2/2 errno_t (p: TBD) 



    

  * K.3.3/2 rsize_t (p: TBD) 



    

  * K.3.4/2 RSIZE_MAX (p: TBD) 



    

  * 7.31.3 Errors <errno.h> (p: TBD) 



    

  * 7.31.10 Integer types <stdint.h> (p: TBD) 



    

  * 7.31.11 Input/output <stdio.h> (p: TBD) 



    

  * 7.31.12 General utilities <stdlib.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.2 Diagnostics <assert.h> (p: TBD) 



    

  * 7.5 Errors <errno.h> (p: TBD) 



    

  * 7.19 Common definitions <stddef.h> (p: TBD) 



    

  * 7.20 Integer types <stdint.h> (p: TBD) 



    

  * 7.21 Input/output <stdio.h> (p: TBD) 



    

  * 7.22 General utilities <stdlib.h> (p: TBD) 



    

  * K.3.1.3 Use of errno (p: TBD) 



    

  * K.3.2/2 errno_t (p: TBD) 



    

  * K.3.3/2 rsize_t (p: TBD) 



    

  * K.3.4/2 RSIZE_MAX (p: TBD) 



    

  * 7.31.3 Errors <errno.h> (p: TBD) 



    

  * 7.31.10 Integer types <stdint.h> (p: TBD) 



    

  * 7.31.11 Input/output <stdio.h> (p: TBD) 



    

  * 7.31.12 General utilities <stdlib.h> (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.2 Diagnostics <assert.h> (p: 186-187) 



    

  * 7.5 Errors <errno.h> (p: 205) 



    

  * 7.19 Common definitions <stddef.h> (p: 288) 



    

  * 7.20 Integer types <stdint.h> (p: 289-295) 



    

  * 7.21 Input/output <stdio.h> (p: 296-339) 



    

  * 7.22 General utilities <stdlib.h> (p: 340-360) 



    

  * K.3.1.3 Use of errno (p: 584) 



    

  * K.3.2/2 errno_t (p: 585) 



    

  * K.3.3/2 rsize_t (p: 585) 



    

  * K.3.4/2 RSIZE_MAX (p: 585) 



    

  * 7.31.3 Errors <errno.h> (p: 455) 



    

  * 7.31.10 Integer types <stdint.h> (p: 456) 



    

  * 7.31.11 Input/output <stdio.h> (p: 456) 



    

  * 7.31.12 General utilities <stdlib.h> (p: 456) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.2 Diagnostics <assert.h> (p: 169) 



    

  * 7.5 Errors <errno.h> (p: 186) 



    

  * 7.26.3 Errors <errno.h> (p: 401) 



    

  * 7.26.8 Integer types <stdint.h> (p: 401) 



    

  * 7.26.9 Input/output <stdio.h> (p: 402) 



    

  * 7.26.10 General utilities <stdlib.h> (p: 402) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.2 DIAGNOSTICS <assert.h>



    

  * 4.1.3 Errors <errno.h>



    

  * 4.13.1 Errors <errno.h>



    

  * 4.13.6 Input/output <stdio.h>



    

  * 4.13.7 General utilities <stdlib.h>

  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error&action=edit&section=6 "Edit section: See also")] See also

[ math_errhandlingMATH_ERRNOMATH_ERREXCEPT](numeric/math/math_errhandling.html "c/numeric/math/math errhandling")(C99)(C99)(C99) |  defines the error handling mechanism used by the common mathematical functions   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_math_errhandling&action=edit)  
---|---  
[C++ documentation](../cpp/error.html "cpp/error") for Error handling  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/error&oldid=180038](https://en.cppreference.com/mwiki/index.php?title=c/error&oldid=180038)" 

From cppreference.com

< [c](../../c.html "c")‎ | [header](../header.html "c/header")

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

[ Standard Library headers ](../header.html "c/header")

| [`<assert.h>`](assert.html "c/header/assert")  
---  
[`<complex.h>`](complex.html "c/header/complex") (C99)  
[`<ctype.h>`](ctype.html "c/header/ctype")  
**`< errno.h>`**  
[`<fenv.h>`](fenv.html "c/header/fenv") (C99)  
[`<float.h>`](float.html "c/header/float")  
[`<inttypes.h>`](inttypes.html "c/header/inttypes") (C99)` `  
[`<iso646.h>`](iso646.html "c/header/iso646") (C95)  
[`<limits.h>`](limits.html "c/header/limits")  
[`<locale.h>`](locale.html "c/header/locale")  
[`<math.h>`](math.html "c/header/math")  
  
| [`<setjmp.h>`](setjmp.html "c/header/setjmp")  
---  
[`<signal.h>`](signal.html "c/header/signal")  
[`<stdalign.h>`](stdalign.html "c/header/stdalign") (C11*)  
[`<stdarg.h>`](stdarg.html "c/header/stdarg")  
[`<stdatomic.h>`](stdatomic.html "c/header/stdatomic") (C11)` `  
[`<stdbit.h>`](stdbit.html "c/header/stdbit") (C23)  
[`<stdbool.h>`](stdbool.html "c/header/stdbool") (C99*)  
[`<stdckdint.h>`](stdckdint.html "c/header/stdckdint") (C23)  
[`<stddef.h>`](stddef.html "c/header/stddef")  
[`<stdint.h>`](stdint.html "c/header/stdint") (C99)  
[`<stdio.h>`](stdio.html "c/header/stdio")  
  
| [`<stdlib.h>`](stdlib.html "c/header/stdlib")  
---  
[`<stdmchar.h>`](stdmchar.html "c/header/stdmchar") (C29)  
[`<stdnoreturn.h>`](stdnoreturn.html "c/header/stdnoreturn") (C11*)  
[`<string.h>`](string.html "c/header/string")  
[`<tgmath.h>`](tgmath.html "c/header/tgmath") (C99)  
[`<threads.h>`](threads.html "c/header/threads") (C11)  
[`<time.h>`](time.html "c/header/time")  
[`<uchar.h>`](uchar.html "c/header/uchar") (C11)  
[`<wchar.h>`](wchar.html "c/header/wchar") (C95)  
[`<wctype.h>`](wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header is part of the [error handling](../error.html "c/error") library. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/errno&action=edit&section=1 "Edit section: Error numbers")] Error numbers

[ errno](../error/errno.html "c/error/errno") |  macro which expands to POSIX-compatible thread-local error number variable  
(macro variable) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/dsc_errno&action=edit)  
---|---  
[ E2BIG, EACCES, ..., EXDEV](../error/errno_macros.html "c/error/errno macros") |  macros for standard POSIX-compatible error conditions   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/dsc_errno_macros&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/errno&action=edit&section=2 "Edit section: Synopsis")] Synopsis
    
    
    #define EDOM   /* implementation-defined */
    #define EILSEQ /* implementation-defined */
    #define ERANGE /* implementation-defined */
     
    #define errno  /* implementation-defined */
     
    // Only if the implementation defines __STDC_LIB_EXT1__ and additionally the user code
    // defines __STDC_WANT_LIB_EXT1__ before any inclusion of <errno.h>:
    #ifdef __STDC_WANT_LIB_EXT1__
    #define __STDC_LIB_EXT1__  /* implementation-defined */
    #define errno_t            /* implementation-defined */
    #endif

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/errno&oldid=180047](https://en.cppreference.com/mwiki/index.php?title=c/header/errno&oldid=180047)" 

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
[`<errno.h>`](errno.html "c/header/errno")  
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
**`< stddef.h>`**  
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

This header is part of [types support](../types.html "c/types") library, in particular, it provides additional basic types and convenience macros. 

| 

## Contents

  * [1 Types](stddef.html#Types)
  * [2 Constants](stddef.html#Constants)
  * [3 Macros](stddef.html#Macros)
  * [4 Synopsis](stddef.html#Synopsis)

  
---  
  
###  Types  
  
[ ptrdiff_t](../types/ptrdiff_t.html "c/types/ptrdiff t") |  signed integer type returned when subtracting two pointers   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_ptrdiff_t&action=edit)  
[ nullptr_t](../types/nullptr_t.html "c/types/nullptr t")(C23) |  the type of the predefined null pointer constant [`nullptr`](../language/nullptr.html "c/language/nullptr")   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_nullptr_t&action=edit)  
[ max_align_t](../types/max_align_t.html "c/types/max align t")(C11) |  a type with alignment requirement as great as any other scalar type   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_max_align_t&action=edit)  
[ size_t](../types/size_t.html "c/types/size t") |  unsigned integer type returned by the [`sizeof`](../language/sizeof.html "c/language/sizeof") operator   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_size_t&action=edit)  
  
###  Constants  
  
[ NULL](../types/NULL.html "c/types/NULL") |  implementation-defined null pointer constant   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_NULL&action=edit)  
  
###  Macros  
  
[ offsetof](../types/offsetof.html "c/types/offsetof") |  byte offset from the beginning of a struct type to specified member   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_offsetof&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/stddef&action=edit&section=1 "Edit section: Synopsis")] Synopsis
    
    
    #define __STDC_VERSION_STDDEF_H__ 202311L
     
    typedef /* see description */ [ptrdiff_t](../types/ptrdiff_t.html);
    typedef /* see description */ [nullptr_t](../types/nullptr_t.html);
    typedef /* see description */ [max_align_t](../types/max_align_t.html);
    typedef /* see description */ wchar_t;
    typedef /* see description */ [size_t](../types/size_t.html);
     
    #define NULL /* see description */
    #define unreachable() /* see description */
    #define offsetof(P, D) /* see description */

Only if the implementation defines __STDC_LIB_EXT1__ and additionally the user code defines __STDC_WANT_LIB_EXT1__ before any inclusion of `<stddef.h>`: 
    
    
    #if defined(__STDC_WANT_LIB_EXT1__)
    typedef /* see description */ rsize_t;
    #endif

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/stddef&oldid=180206](https://en.cppreference.com/mwiki/index.php?title=c/header/stddef&oldid=180206)" 

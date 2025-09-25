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
  
| **`< setjmp.h>`**  
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

This header is part of the [program support utilities](../program.html#Non-local_jumps "c/program") library. 

| 

## Contents

  * [1 Types](setjmp.html#Types)
  * [2 Macros](setjmp.html#Macros)
  * [3 Functions](setjmp.html#Functions)
  * [4 Synopsis](setjmp.html#Synopsis)

  
---  
  
###  Types  
  
[ jmp_buf](../program/jmp_buf.html "c/program/jmp buf") |  execution context type   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_jmp_buf&action=edit)  
  
###  Macros  
  
[ setjmp](../program/setjmp.html "c/program/setjmp") |  saves the context   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_setjmp&action=edit)  
  
###  Functions  
  
[ longjmp](../program/longjmp.html "c/program/longjmp") |  jumps to specified location   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_longjmp&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/setjmp&action=edit&section=1 "Edit section: Synopsis")] Synopsis
    
    
    #define __STDC_VERSION_SETJMP_H__ 202311L
     
    typedef /* unspecified */ [jmp_buf](../program/jmp_buf.html);
     
    int [setjmp](../program/setjmp.html)([jmp_buf](../program/jmp_buf.html) env);
    [[noreturn]] void [longjmp](../program/longjmp.html)([jmp_buf](../program/jmp_buf.html) env, int val);

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/setjmp&oldid=180739](https://en.cppreference.com/mwiki/index.php?title=c/header/setjmp&oldid=180739)" 

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
**`< signal.h>`**  
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

This header is part of the [program support](../program.html "c/program") library. 

| 

## Contents

  * [1 Types](signal.html#Types)
  * [2 Macros](signal.html#Macros)
  * [3 Functions](signal.html#Functions)
  * [4 Synopsis](signal.html#Synopsis)

  
---  
  
###  Types  
  
[ sig_atomic_t](../program/sig_atomic_t.html "c/program/sig atomic t") |  the integer type that can be accessed as an atomic entity from an asynchronous signal handler   
(typedef)  
  
###  Macros  
  
[ SIGABRTSIGFPESIGILLSIGINTSIGSEGVSIGTERM](../program/SIG_types.html "c/program/SIG types") |  defines signal types   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_SIG_types&action=edit)  
[ SIG_DFLSIG_IGN](../program/SIG_strategies.html "c/program/SIG strategies") |  defines signal handling strategies   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_SIG_strategies&action=edit)  
[ SIG_ERR](../program/SIG_ERR.html "c/program/SIG ERR") |  error was encountered   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_SIG_ERR&action=edit)  
  
###  Functions  
  
[ signal](../program/signal.html "c/program/signal") |  sets a signal handler for particular signal   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_signal&action=edit)  
[ raise](../program/raise.html "c/program/raise") |  runs the signal handler for particular signal   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_raise&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/signal&action=edit&section=1 "Edit section: Synopsis")] Synopsis
    
    
    typedef [sig_atomic_t](../program/sig_atomic_t.html) /* see description */;
     
    void (*[signal](../program/signal.html)(int sig, void (*func)(int)))(int);
    int [raise](../program/raise.html)(int sig);
     
    #define SIG_DFL  /* see description */
    #define SIG_ERR  /* see description */
    #define SIG_IGN  /* see description */
    #define SIGABRT  /* see description */
    #define SIGFPE   /* see description */
    #define SIGILL   /* see description */
    #define SIGINT   /* see description */
    #define SIGSEGV  /* see description */
    #define SIGTERM  /* see description */

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/signal&oldid=180112](https://en.cppreference.com/mwiki/index.php?title=c/header/signal&oldid=180112)" 

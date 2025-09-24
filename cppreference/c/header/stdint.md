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
[`<stddef.h>`](stddef.html "c/header/stddef")  
**`< stdint.h>`** (C99)  
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

This header is part of [types support](../types.html "c/types") library, providing [fixed width integer types](../types/integer.html#Types "c/types/integer") and a part of [numeric limits](../types/limits.html#Limits_of_library_type_aliases "c/types/limits") interface. 

| This section is incomplete  
Reason: 7.22 Integer types <stdint.h>, copy/share parts of [c/types/integer](../types/integer.html "c/types/integer") and [c/types/limits](../types/limits.html "c/types/limits")  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/stdint&action=edit&section=1 "Edit section: Synopsis")] Synopsis

| This section is incomplete  
Reason: B.21 Integer types <stdint.h>  
---|---  
      
    
    typedef /*signed-integer-type*/     [int8_t](../types/integer.html)         ; // optional
    typedef /*signed-integer-type*/     [int16_t](../types/integer.html)        ; // optional
    typedef /*signed-integer-type*/     [int32_t](../types/integer.html)        ; // optional
    typedef /*signed-integer-type*/     [int64_t](../types/integer.html)        ; // optional
    typedef /* see description */       intN_t         ; // optional, see description
     
    typedef /*signed-integer-type*/     [int_fast8_t](../types/integer.html)    ;
    typedef /*signed-integer-type*/     [int_fast16_t](../types/integer.html)   ;
    typedef /*signed-integer-type*/     [int_fast32_t](../types/integer.html)   ;
    typedef /*signed-integer-type*/     [int_fast64_t](../types/integer.html)   ;
    typedef /* see description */       int_fastN_t    ; // optional, see description
     
    typedef /*signed-integer-type*/     [int_least8_t](../types/integer.html)   ;
    typedef /*signed-integer-type*/     [int_least16_t](../types/integer.html)  ;
    typedef /*signed-integer-type*/     [int_least32_t](../types/integer.html)  ;
    typedef /*signed-integer-type*/     [int_least64_t](../types/integer.html)  ;
    typedef /* see description */       int_leastN_t   ; // optional, see description
     
    typedef /*signed-integer-type*/     [intmax_t](../types/integer.html)       ;
    typedef /*signed-integer-type*/     [intptr_t](../types/integer.html)       ; // optional
     
    typedef /*unsigned-integer-type*/   [uint8_t](../types/integer.html)        ; // optional
    typedef /*unsigned-integer-type*/   [uint16_t](../types/integer.html)       ; // optional
    typedef /*unsigned-integer-type*/   [uint32_t](../types/integer.html)       ; // optional
    typedef /*unsigned-integer-type*/   [uint64_t](../types/integer.html)       ; // optional
    typedef /* see description */       uintN_t        ; // optional, see description
     
    typedef /*unsigned-integer-type*/   [uint_fast8_t](../types/integer.html)   ;
    typedef /*unsigned-integer-type*/   [uint_fast16_t](../types/integer.html)  ;
    typedef /*unsigned-integer-type*/   [uint_fast32_t](../types/integer.html)  ;
    typedef /*unsigned-integer-type*/   [uint_fast64_t](../types/integer.html)  ;
    typedef /* see description */       uint_fastN_t   ; // optional, see description
     
    typedef /*unsigned-integer-type*/   [uint_least8_t](../types/integer.html)  ;
    typedef /*unsigned-integer-type*/   [uint_least16_t](../types/integer.html) ;
    typedef /*unsigned-integer-type*/   [uint_least32_t](../types/integer.html) ;
    typedef /*unsigned-integer-type*/   [uint_least64_t](../types/integer.html) ;
    typedef /* see description */       uint_leastN_t  ; // optional, see description
     
    typedef /*unsigned-integer-type*/   [uintmax_t](../types/integer.html)      ;
    typedef /*unsigned-integer-type*/   [uintptr_t](../types/integer.html)      ; // optional
     
    #define INTN_MIN         /* see description */
    #define INTN_MAX         /* see description */
    #define UINTN_MAX        /* see description */
     
    #define INT_FASTN_MIN    /* see description */
    #define INT_FASTN_MAX    /* see description */
    #define UINT_FASTN_MAX   /* see description */
     
    #define INT_LEASTN_MIN   /* see description */
    #define INT_LEASTN_MAX   /* see description */
    #define UINT_LEASTN_MAX  /* see description */
     
    #define INTMAX_MIN       /* see description */
    #define INTMAX_MAX       /* see description */
    #define UINTMAX_MAX      /* see description */
     
    #define INTPTR_MIN       /* see description */        // optional
    #define INTPTR_MAX       /* see description */        // optional
    #define UINTPTR_MAX      /* see description */        // optional
     
    #define PTRDIFF_MIN      /* see description */
    #define PTRDIFF_MAX      /* see description */
    #define SIZE_MAX         /* see description */
     
    #define SIG_ATOMIC_MIN   /* see description */
    #define SIG_ATOMIC_MAX   /* see description */
     
    #define WCHAR_MIN        /* see description */
    #define WCHAR_MAX        /* see description */
     
    #define WINT_MIN         /* see description */
    #define WINT_MAX         /* see description */
     
    #define INTN_C(value)    /* see description */
    #define UINTN_C(value)   /* see description */
    #define INTMAX_C(value)  /* see description */
    #define UINTMAX_C(value) /* see description */

Only if the implementation defines __STDC_LIB_EXT1__ and additionally the user code defines __STDC_WANT_LIB_EXT1__ before any inclusion of `stdint.h`: 
    
    
    #if defined(__STDC_WANT_LIB_EXT1__)
    #define RSIZE_MAX /* see description */
    #endif

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/stdint&oldid=180202](https://en.cppreference.com/mwiki/index.php?title=c/header/stdint&oldid=180202)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



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
[`<stdint.h>`](stdint.html "c/header/stdint") (C99)  
[`<stdio.h>`](stdio.html "c/header/stdio")  
  
| [`<stdlib.h>`](stdlib.html "c/header/stdlib")  
---  
**`< stdmchar.h>`** (C29)  
[`<stdnoreturn.h>`](stdnoreturn.html "c/header/stdnoreturn") (C11*)  
[`<string.h>`](string.html "c/header/string")  
[`<tgmath.h>`](tgmath.html "c/header/tgmath") (C99)  
[`<threads.h>`](threads.html "c/header/threads") (C11)  
[`<time.h>`](time.html "c/header/time")  
[`<uchar.h>`](uchar.html "c/header/uchar") (C11)  
[`<wchar.h>`](wchar.html "c/header/wchar") (C95)  
[`<wctype.h>`](wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header is part of [text transcoding utilities](../string.html "c/string") library. 

| This section is incomplete  
Reason: 7.25 Text transcoding utilities <stdmchar.h>  
---|---  
  
## Contents

  * [1 Functions](stdmchar.html#Functions)
  * [2 Types](stdmchar.html#Types)
  * [3 Macros](stdmchar.html#Macros)
  * [4 Synopsis](stdmchar.html#Synopsis)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/stdmchar&action=edit&section=1 "Edit section: Functions")] Functions  
  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/stdmchar&action=edit&section=2 "Edit section: Types")] Types  
  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/stdmchar&action=edit&section=3 "Edit section: Macros")] Macros  
  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/stdmchar&action=edit&section=4 "Edit section: Synopsis")] Synopsis
    
    
    #define __STDC_VERSION_STDMCHAR_H__ 202900L // 202ymmL
     
    typedef /* see description */ char16_t;
    typedef /* see description */ char32_t;
    typedef /* see description */ char8_t;
    typedef /* see description */ [mbstate_t](../string/multibyte/mbstate_t.html);
    typedef /* see description */ [size_t](../types/size_t.html);
    typedef /* see description */ stdc_mcerr;
    typedef /* see description */ wchar_t;
     
    #define MB_UTF16     /* see description */
    #define MB_UTF32     /* see description */
    #define MB_UTF8      /* see description */
    #define STDC_C16_MAX /* see description */
    #define STDC_C32_MAX /* see description */
    #define STDC_C8_MAX  /* see description */
    #define STDC_MC_MAX  /* see description */
    #define STDC_MWC_MAX /* see description */
    #define WCHAR_MAX    /* see description */
    #define WCHAR_MIN    /* see description */
    #define WCHAR_UTF16  /* see description */
    #define WCHAR_UTF32  /* see description */
    #define WCHAR_UTF8   /* see description */
    #define WCHAR_WIDTH  /* see description */
     
    enum stdc_mcerr
    {
        stdc_mcerr_ok = 0
        stdc_mcerr_invalid = -1,
        stdc_mcerr_incomplete_input = -2,
        stdc_mcerr_insufficient_output = -3
    };
     
    stdc_mcerr stdc_mcnrtomcn([size_t](../types/size_t.html)* restrict output_size,
                              char* restrict* restrict output,
                              [size_t](../types/size_t.html)* restrict input_size,
                              const char* restrict* restrict input,
                              [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mcnrtomwcn([size_t](../types/size_t.html)* restrict output_size,
                               wchar_t* restrict* restrict output,
                               [size_t](../types/size_t.html)* restrict input_size,
                               const char* restrict* restrict input,
                               [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mcnrtoc8n([size_t](../types/size_t.html)* restrict output_size,
                              char8_t* restrict* restrict output,
                              [size_t](../types/size_t.html)* restrict input_size,
                              const char* restrict* restrict input,
                              [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mcnrtoc16n([size_t](../types/size_t.html)* restrict output_size,
                               char16_t* restrict* restrict output,
                               [size_t](../types/size_t.html)* restrict input_size,
                               const char* restrict* restrict input,
                               [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mcnrtoc32n([size_t](../types/size_t.html)* restrict output_size,
                               char32_t* restrict* restrict output,
                               [size_t](../types/size_t.html)* restrict input_size,
                               const char* restrict* restrict input,
                               [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mwcnrtomcn([size_t](../types/size_t.html)* restrict output_size,
                               char* restrict* restrict output,
                               [size_t](../types/size_t.html)* restrict input_size,
                               wchar_t* restrict* restrict input,
                               [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mwcnrtomwcn([size_t](../types/size_t.html)* restrict output_size,
                                wchar_t* restrict* restrict output,
                                [size_t](../types/size_t.html)* restrict input_size,
                                wchar_t* restrict* restrict input,
                                [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mwcnrtoc8n([size_t](../types/size_t.html)* restrict output_size,
                               char8_t* restrict* restrict output,
                               [size_t](../types/size_t.html)* restrict input_size,
                               wchar_t* restrict* restrict input,
                               [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mwcnrtoc16n([size_t](../types/size_t.html)* restrict output_size,
                                char16_t* restrict* restrict output,
                                [size_t](../types/size_t.html)* restrict input_size,
                                wchar_t* restrict* restrict input,
                                [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mwcnrtoc32n([size_t](../types/size_t.html)* restrict output_size,
                                char32_t* restrict* restrict output,
                                [size_t](../types/size_t.html)* restrict input_size,
                                wchar_t* restrict* restrict input,
                                [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c8nrtomcn([size_t](../types/size_t.html)* restrict output_size,
                              char* restrict* restrict output,
                              [size_t](../types/size_t.html)* restrict input_size,
                              const char8_t* restrict* restrict input,
                              [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c8nrtomwcn([size_t](../types/size_t.html)* restrict output_size,
                               wchar_t* restrict* restrict output,
                               [size_t](../types/size_t.html)* restrict input_size,
                               const char8_t* restrict* restrict input,
                               [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c8nrtoc8n([size_t](../types/size_t.html)* restrict output_size,
                              char8_t* restrict* restrict output,
                              [size_t](../types/size_t.html)* restrict input_size,
                              const char8_t* restrict* restrict input,
                              [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c8nrtoc16n([size_t](../types/size_t.html)* restrict output_size,
                               char16_t* restrict* restrict output,
                               [size_t](../types/size_t.html)* restrict input_size,
                               const char8_t* restrict* restrict input,
                               [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c8nrtoc32n([size_t](../types/size_t.html)* restrict output_size,
                               char32_t* restrict* restrict output,
                               [size_t](../types/size_t.html)* restrict input_size,
                               const char8_t* restrict* restrict input,
                               [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c16nrtomcn([size_t](../types/size_t.html)* restrict output_size,
                               char* restrict* restrict output,
                               [size_t](../types/size_t.html)* restrict input_size,
                               const char16_t* restrict* restrict input,
                               [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c16nrtomwcn([size_t](../types/size_t.html)* restrict output_size,
                                wchar_t* restrict* restrict output,
                                [size_t](../types/size_t.html)* restrict input_size,
                                const char16_t* restrict* restrict input,
                                [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c16nrtoc8n([size_t](../types/size_t.html)* restrict output_size,
                               char8_t* restrict* restrict output,
                               [size_t](../types/size_t.html)* restrict input_size,
                               const char16_t* restrict* restrict input,
                               [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c16nrtoc16n([size_t](../types/size_t.html)* restrict output_size,
                                char16_t* restrict* restrict output,
                                [size_t](../types/size_t.html)* restrict input_size,
                                const char16_t* restrict* restrict input,
                                [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c16nrtoc32n([size_t](../types/size_t.html)* restrict output_size,
                                char32_t* restrict* restrict output,
                                [size_t](../types/size_t.html)* restrict input_size,
                                const char16_t* restrict* restrict input,
                                [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c32nrtomcn([size_t](../types/size_t.html)* restrict output_size,
                               char* restrict* restrict output,
                               [size_t](../types/size_t.html)* restrict input_size,
                               const char32_t* restrict* restrict input,
                               [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c32nrtomwcn([size_t](../types/size_t.html)* restrict output_size,
                                wchar_t* restrict* restrict output,
                                [size_t](../types/size_t.html)* restrict input_size,
                                const char32_t* restrict* restrict input,
                                [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c32nrtoc8n([size_t](../types/size_t.html)* restrict output_size,
                               char8_t* restrict* restrict output,
                               [size_t](../types/size_t.html)* restrict input_size,
                               const char32_t* restrict* restrict input,
                               [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c32nrtoc16n([size_t](../types/size_t.html)* restrict output_size,
                                char16_t* restrict* restrict output,
                                [size_t](../types/size_t.html)* restrict input_size,
                                const char32_t* restrict* restrict input,
                                [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c32nrtoc32n([size_t](../types/size_t.html)* restrict output_size,
                                char32_t* restrict* restrict output,
                                [size_t](../types/size_t.html)* restrict input_size,
                                const char32_t* restrict* restrict input,
                                [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mcsnrtomcsn([size_t](../types/size_t.html)* restrict output_size,
                                char* restrict* restrict output,
                                [size_t](../types/size_t.html)* restrict input_size,
                                const char* restrict* restrict input,
                                [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mcsnrtomwcsn([size_t](../types/size_t.html)* restrict output_size,
                                 wchar_t* restrict* restrict output,
                                 [size_t](../types/size_t.html)* restrict input_size,
                                 const char* restrict* restrict input,
                                 [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mcsnrtoc8sn([size_t](../types/size_t.html)* restrict output_size,
                                char8_t* restrict* restrict output,
                                [size_t](../types/size_t.html)* restrict input_size,
                                const char* restrict* restrict input,
                                [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mcsnrtoc16sn([size_t](../types/size_t.html)* restrict output_size,
                                 char16_t* restrict* restrict output,
                                 [size_t](../types/size_t.html)* restrict input_size,
                                 const char* restrict* restrict input,
                                 [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mcsnrtoc32sn([size_t](../types/size_t.html)* restrict output_size,
                                 char32_t* restrict* restrict output,
                                 [size_t](../types/size_t.html)* restrict input_size,
                                 const char* restrict* restrict input,
                                 [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mwcsnrtomcsn([size_t](../types/size_t.html)* restrict output_size,
                                 char* restrict* restrict output,
                                 [size_t](../types/size_t.html)* restrict input_size,
                                 wchar_t* restrict* restrict input,
                                 [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mwcsnrtomwcsn([size_t](../types/size_t.html)* restrict output_size,
                                  char* restrict* restrict output,
                                  [size_t](../types/size_t.html)* restrict input_size,
                                  wchar_t* restrict* restrict input,
                                  [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mwcsnrtoc8sn([size_t](../types/size_t.html)* restrict output_size,
                                 char8_t* restrict* restrict output,
                                 [size_t](../types/size_t.html)* restrict input_size,
                                 wchar_t* restrict* restrict input,
                                 [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mwcsnrtoc16sn([size_t](../types/size_t.html)* restrict output_size,
                                  char16_t* restrict* restrict output,
                                  [size_t](../types/size_t.html)* restrict input_size,
                                  wchar_t* restrict* restrict input,
                                  [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_mwcsnrtoc32sn([size_t](../types/size_t.html)* restrict output_size,
                                  char32_t* restrict* restrict output,
                                  [size_t](../types/size_t.html)* restrict input_size,
                                  wchar_t* restrict* restrict input,
                                  [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c8snrtomwcsn([size_t](../types/size_t.html)* restrict output_size,
                                 wchar_t* restrict* restrict output,
                                 [size_t](../types/size_t.html)* restrict input_size,
                                 const char8_t* restrict* restrict input,
                                 [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c8snrtomcsn([size_t](../types/size_t.html)* restrict output_size,
                                char* restrict* restrict output,
                                [size_t](../types/size_t.html)* restrict input_size,
                                const char8_t* restrict* restrict input,
                                [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c8snrtoc8sn([size_t](../types/size_t.html)* restrict output_size,
                                char8_t* restrict* restrict output,
                                [size_t](../types/size_t.html)* restrict input_size,
                                const char8_t* restrict* restrict input,
                                [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c8snrtoc16sn([size_t](../types/size_t.html)* restrict output_size,
                                 char16_t* restrict* restrict output,
                                 [size_t](../types/size_t.html)* restrict input_size,
                                 const char8_t* restrict* restrict input,
                                 [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c8snrtoc32sn([size_t](../types/size_t.html)* restrict output_size,
                                 char32_t* restrict* restrict output,
                                 [size_t](../types/size_t.html)* restrict input_size,
                                 const char8_t* restrict* restrict input,
                                 [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c16snrtomwcsn([size_t](../types/size_t.html)* restrict output_size,
                                  wchar_t* restrict* restrict output,
                                  [size_t](../types/size_t.html)* restrict input_size,
                                  const char16_t* restrict* restrict input,
                                  [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c16snrtomcsn([size_t](../types/size_t.html)* restrict output_size,
                                 char* restrict* restrict output,
                                 [size_t](../types/size_t.html)* restrict input_size,
                                 const char16_t* restrict* restrict input,
                                 [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c16snrtoc8sn([size_t](../types/size_t.html)* restrict output_size,
                                 char8_t* restrict* restrict output,
                                 [size_t](../types/size_t.html)* restrict input_size,
                                 const char16_t* restrict* restrict input,
                                 [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c16snrtoc16sn([size_t](../types/size_t.html)* restrict output_size,
                                  char16_t* restrict* restrict output,
                                  [size_t](../types/size_t.html)* restrict input_size,
                                  const char16_t* restrict* restrict input,
                                  [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c16snrtoc32sn([size_t](../types/size_t.html)* restrict output_size,
                                  char32_t* restrict* restrict output,
                                  [size_t](../types/size_t.html)* restrict input_size,
                                  const char16_t* restrict* restrict input,
                                  [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c32snrtomcsn([size_t](../types/size_t.html)* restrict output_size,
                                 char* restrict* restrict output,
                                 [size_t](../types/size_t.html)* restrict input_size,
                                 const char32_t* restrict* restrict input,
                                 [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c32snrtomwcsn([size_t](../types/size_t.html)* restrict output_size,
                                  wchar_t* restrict* restrict output,
                                  [size_t](../types/size_t.html)* restrict input_size,
                                  const char32_t* restrict* restrict input,
                                  [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c32snrtoc8sn([size_t](../types/size_t.html)* restrict output_size,
                                 char8_t* restrict* restrict output,
                                 [size_t](../types/size_t.html)* restrict input_size,
                                 const char32_t* restrict* restrict input,
                                 [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c32snrtoc16sn([size_t](../types/size_t.html)* restrict output_size,
                                  char16_t* restrict* restrict output,
                                  [size_t](../types/size_t.html)* restrict input_size,
                                  const char32_t* restrict* restrict input,
                                  [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);
    stdc_mcerr stdc_c32snrtoc32sn([size_t](../types/size_t.html)* restrict output_size,
                                  char32_t* restrict* restrict output,
                                  [size_t](../types/size_t.html)* restrict input_size,
                                  const char32_t* restrict* restrict input,
                                  [mbstate_t](../string/multibyte/mbstate_t.html)* restrict state);

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/stdmchar&oldid=180741](https://en.cppreference.com/mwiki/index.php?title=c/header/stdmchar&oldid=180741)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



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
[`<stdmchar.h>`](stdmchar.html "c/header/stdmchar") (C29)  
[`<stdnoreturn.h>`](stdnoreturn.html "c/header/stdnoreturn") (C11*)  
[`<string.h>`](string.html "c/header/string")  
[`<tgmath.h>`](tgmath.html "c/header/tgmath") (C99)  
[`<threads.h>`](threads.html "c/header/threads") (C11)  
[`<time.h>`](time.html "c/header/time")  
**`< uchar.h>`** (C11)  
[`<wchar.h>`](wchar.html "c/header/wchar") (C95)  
[`<wctype.h>`](wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header is part of [null-terminated multibyte strings](../string/multibyte.html "c/string/multibyte") library. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/uchar&action=edit&section=1 "Edit section: Functions")] Functions

[ mbrtoc8](../string/multibyte/mbrtoc8.html "c/string/multibyte/mbrtoc8")(C23) |  converts a narrow multibyte character to UTF-8 encoding   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbrtoc8&action=edit)  
---|---  
[ c8rtomb](../string/multibyte/c8rtomb.html "c/string/multibyte/c8rtomb")(C23) |  converts UTF-8 string to narrow multibyte encoding   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_c8rtomb&action=edit)  
[ mbrtoc16](../string/multibyte/mbrtoc16.html "c/string/multibyte/mbrtoc16")(C11) |  converts a narrow multibyte character to UTF-16 encoding   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbrtoc16&action=edit)  
[ c16rtomb](../string/multibyte/c16rtomb.html "c/string/multibyte/c16rtomb")(C11) |  converts a UTF-16 character to narrow multibyte encoding   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_c16rtomb&action=edit)  
[ mbrtoc32](../string/multibyte/mbrtoc32.html "c/string/multibyte/mbrtoc32")(C11) |  converts a narrow multibyte character to UTF-32 encoding   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbrtoc32&action=edit)  
[ c32rtomb](../string/multibyte/c32rtomb.html "c/string/multibyte/c32rtomb")(C11) |  converts a UTF-32 character to narrow multibyte encoding   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_c32rtomb&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/uchar&action=edit&section=2 "Edit section: Types")] Types

[ mbstate_t](../string/multibyte/mbstate_t.html "c/string/multibyte/mbstate t")(C95) |  conversion state information necessary to iterate multibyte character strings   
(class) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbstate_t&action=edit)  
---|---  
[ char8_t](../string/multibyte/char8_t.html "c/string/multibyte/char8 t")(C23) |  8-bit character type   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_char8_t&action=edit)  
[ char16_t](../string/multibyte/char16_t.html "c/string/multibyte/char16 t")(C11) |  16-bit character type   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_char16_t&action=edit)  
[ char32_t](../string/multibyte/char32_t.html "c/string/multibyte/char32 t")(C11) |  32-bit character type   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_char32_t&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/uchar&action=edit&section=3 "Edit section: Synopsis")] Synopsis
    
    
    #define __STDC_VERSION_UCHAR_H__ 202311L
     
    typedef /* see description */ [mbstate_t](../string/multibyte/mbstate_t.html);
    typedef /* see description */ [size_t](../types/size_t.html);
    typedef /* see description */ char8_t;
    typedef /* see description */ char16_t;
    typedef /* see description */ char32_t;
     
    [size_t](../types/size_t.html) mbrtoc8(char8_t* restrict pc8, const char* restrict s, [size_t](../types/size_t.html) n,
                   [mbstate_t](../string/multibyte/mbstate_t.html)* restrict ps);
    [size_t](../types/size_t.html) c8rtomb(char* restrict s, char8_t c8, [mbstate_t](../string/multibyte/mbstate_t.html)* restrict ps);
    [size_t](../types/size_t.html) [mbrtoc16](../string/multibyte/mbrtoc16.html)(char16_t* restrict pc16, const char* restrict s, [size_t](../types/size_t.html) n,
                    [mbstate_t](../string/multibyte/mbstate_t.html)* restrict ps);
    [size_t](../types/size_t.html) [c16rtomb](../string/multibyte/c16rtomb.html)(char* restrict s, char16_t c16, [mbstate_t](../string/multibyte/mbstate_t.html)* restrict ps);
    [size_t](../types/size_t.html) [mbrtoc32](../string/multibyte/mbrtoc32.html)(char32_t* restrict pc32, const char* restrict s, [size_t](../types/size_t.html) n,
                    [mbstate_t](../string/multibyte/mbstate_t.html)* restrict ps);
    [size_t](../types/size_t.html) [c32rtomb](../string/multibyte/c32rtomb.html)(char* restrict s, char32_t c32, [mbstate_t](../string/multibyte/mbstate_t.html)* restrict ps);

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/uchar&oldid=180745](https://en.cppreference.com/mwiki/index.php?title=c/header/uchar&oldid=180745)" 

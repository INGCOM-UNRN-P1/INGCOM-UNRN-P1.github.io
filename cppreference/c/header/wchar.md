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
[`<uchar.h>`](uchar.html "c/header/uchar") (C11)  
**`< wchar.h>`** (C95)  
[`<wctype.h>`](wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header is part of [null-terminated wide strings](../string/wide.html "c/string/wide") library. 

## Contents

  * [1 Functions](wchar.html#Functions)
    * [1.1 Conversions to numeric formats](wchar.html#Conversions_to_numeric_formats)
    * [1.2 String manipulation](wchar.html#String_manipulation)
    * [1.3 String examination](wchar.html#String_examination)
    * [1.4 Wide character array manipulation](wchar.html#Wide_character_array_manipulation)
  * [2 Types](wchar.html#Types)
  * [3 Macros](wchar.html#Macros)
  * [4 Synopsis](wchar.html#Synopsis)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/wchar&action=edit&section=1 "Edit section: Functions")] Functions

#####  Conversions to numeric formats   
  
---  
[ wcstolwcstoll](../string/wide/wcstol.html "c/string/wide/wcstol")(C95)(C99) |  converts a wide string to an integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstol&action=edit)  
[ wcstoulwcstoull](../string/wide/wcstoul.html "c/string/wide/wcstoul")(C95)(C99) |  converts a wide string to an unsigned integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstoul&action=edit)  
[ wcstofwcstodwcstold](../string/wide/wcstof.html "c/string/wide/wcstof")(C99)(C95)(C99) |  converts a wide string to a floating-point value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstof&action=edit)  
  
#####  String manipulation   
  
[ wcscpywcscpy_s](../string/wide/wcscpy.html "c/string/wide/wcscpy")(C95)(C11) |  copies one wide string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcscpy&action=edit)  
[ wcsncpywcsncpy_s](../string/wide/wcsncpy.html "c/string/wide/wcsncpy")(C95)(C11) |  copies a certain amount of wide characters from one string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsncpy&action=edit)  
[ wcscatwcscat_s](../string/wide/wcscat.html "c/string/wide/wcscat")(C95)(C11) |  appends a copy of one wide string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcscat&action=edit)  
[ wcsncatwcsncat_s](../string/wide/wcsncat.html "c/string/wide/wcsncat")(C95)(C11) |  appends a certain amount of wide characters from one wide string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsncat&action=edit)  
[ wcsxfrm](../string/wide/wcsxfrm.html "c/string/wide/wcsxfrm")(C95) |  transform a wide string so that [wcscmp](../string/wide/wcscmp.html "c/string/wide/wcscmp") would produce the same result as [wcscoll](../string/wide/wcscoll.html "c/string/wide/wcscoll")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsxfrm&action=edit)  
  
#####  String examination   
  
[ wcslenwcsnlen_s](../string/wide/wcslen.html "c/string/wide/wcslen")(C95)(C11) |  returns the length of a wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcslen&action=edit)  
[ wcscmp](../string/wide/wcscmp.html "c/string/wide/wcscmp")(C95) |  compares two wide strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcscmp&action=edit)  
[ wcsncmp](../string/wide/wcsncmp.html "c/string/wide/wcsncmp")(C95) |  compares a certain amount of characters from two wide strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsncmp&action=edit)  
[ wcscoll](../string/wide/wcscoll.html "c/string/wide/wcscoll")(C95) |  compares two wide strings in accordance to the current locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcscoll&action=edit)  
[ wcschr](../string/wide/wcschr.html "c/string/wide/wcschr")(C95) |  finds the first occurrence of a wide character in a wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcschr&action=edit)  
[ wcsrchr](../string/wide/wcsrchr.html "c/string/wide/wcsrchr")(C95) |  finds the last occurrence of a wide character in a wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsrchr&action=edit)  
[ wcsspn](../string/wide/wcsspn.html "c/string/wide/wcsspn")(C95) |  returns the length of the maximum initial segment that consists   
of only the wide characters found in another wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsspn&action=edit)  
[ wcscspn](../string/wide/wcscspn.html "c/string/wide/wcscspn")(C95) |  returns the length of the maximum initial segment that consists   
of only the wide chars _not_ found in another wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcscspn&action=edit)  
[ wcspbrk](../string/wide/wcspbrk.html "c/string/wide/wcspbrk")(C95) |  finds the first location of any wide character in one wide string, in another wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcspbrk&action=edit)  
[ wcsstr](../string/wide/wcsstr.html "c/string/wide/wcsstr")(C95) |  finds the first occurrence of a wide string within another wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsstr&action=edit)  
[ wcstokwcstok_s](../string/wide/wcstok.html "c/string/wide/wcstok")(C95)(C11) |  finds the next token in a wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstok&action=edit)  
  
#####  Wide character array manipulation   
  
[ wmemcpywmemcpy_s](../string/wide/wmemcpy.html "c/string/wide/wmemcpy")(C95)(C11) |  copies a certain amount of wide characters between two non-overlapping arrays   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wmemcpy&action=edit)  
[ wmemmovewmemmove_s](../string/wide/wmemmove.html "c/string/wide/wmemmove")(C95)(C11) |  copies a certain amount of wide characters between two, possibly overlapping, arrays   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wmemmove&action=edit)  
[ wmemcmp](../string/wide/wmemcmp.html "c/string/wide/wmemcmp")(C95) |  compares a certain amount of wide characters from two arrays   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wmemcmp&action=edit)  
[ wmemchr](../string/wide/wmemchr.html "c/string/wide/wmemchr")(C95) |  finds the first occurrence of a wide character in a wide character array   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wmemchr&action=edit)  
[ wmemset](../string/wide/wmemset.html "c/string/wide/wmemset")(C95) |  copies the given wide character to every position in a wide character array   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wmemset&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/wchar&action=edit&section=2 "Edit section: Types")] Types

wchar_t |  integer type that can hold any valid wide character   
(typedef)  
---|---  
wint_t(C95) |  integer type that can hold any valid wide character and at least one more value   
(typedef)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/wchar&action=edit&section=3 "Edit section: Macros")] Macros

WEOF(C95) |  a non-character value of type wint_t used to indicate errors   
(macro constant)  
---|---  
WCHAR_MIN(C95) |  the smallest valid value of wchar_t   
(macro constant)  
WCHAR_MAX(C95) |  the largest valid value of wchar_t   
(macro constant)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/wchar&action=edit&section=4 "Edit section: Synopsis")] Synopsis
    
    
    #define __STDC_VERSION_WCHAR_H__ 202311L
     
    typedef /* see description */ wchar_t;
    typedef /* see description */ [size_t](../types/size_t.html);
    typedef /* see description */ [mbstate_t](../string/multibyte/mbstate_t.html);
    typedef /* see description */ wint_t;
     
    struct [tm](../chrono/tm.html) { /* see description */ };
     
    #define MB_UTF16    /* see description */
    #define MB_UTF32    /* see description */
    #define MB_UTF8     /* see description */
    #define NULL        /* see description */
    #define WCHAR_MAX   /* see description */
    #define WCHAR_MIN   /* see description */
    #define WCHAR_UTF16 /* see description */
    #define WCHAR_UTF32 /* see description */
    #define WCHAR_UTF8  /* see description */
    #define WCHAR_WIDTH /* see description */
    #define WEOF        /* see description */
     
    int [fwprintf](../io/fwprintf.html)([FILE](../io/FILE.html)* restrict stream, const wchar_t* restrict format, ...);
    int [fwscanf](../io/fwscanf.html)([FILE](../io/FILE.html)* restrict stream, const wchar_t* restrict format, ...);
    int [swprintf](../io/fwprintf.html)(wchar_t* restrict s, [size_t](../types/size_t.html) n, const wchar_t* restrict format, ...);
    int [swscanf](../io/fwscanf.html)(const wchar_t* restrict s, const wchar_t* restrict format, ...);
    int [vfwprintf](../io/vfwprintf.html)([FILE](../io/FILE.html)* restrict stream, const wchar_t* restrict format, va_list arg);
    int [vfwscanf](../io/vfwscanf.html)([FILE](../io/FILE.html)* restrict stream, const wchar_t* restrict format, va_list arg);
    int [vswprintf](../io/vfwprintf.html)(wchar_t* restrict s, [size_t](../types/size_t.html) n, const wchar_t* restrict format,
                  va_list arg);
    int [vswscanf](../io/vfwscanf.html)(const wchar_t* restrict s, const wchar_t* restrict format, va_list arg);
    int [vwprintf](../io/vfwprintf.html)(const wchar_t* restrict format, va_list arg);
    int [vwscanf](../io/vfwscanf.html)(const wchar_t* restrict format, va_list arg);
    int [wprintf](../io/fwprintf.html)(const wchar_t* restrict format, ...);
    int [wscanf](../io/fwscanf.html)(const wchar_t* restrict format, ...);
    wint_t [fgetwc](../io/fgetwc.html)([FILE](../io/FILE.html)* stream);
    wchar_t* fgetws(wchar_t* restrict s, int n, [FILE](../io/FILE.html)* restrict stream);
    wint_t [fputwc](../io/fputwc.html)(wchar_t c, [FILE](../io/FILE.html)* stream);
    int [fputws](../io/fputws.html)(const wchar_t* restrict s, [FILE](../io/FILE.html)* restrict stream);
    int fwide([FILE](../io/FILE.html)* stream, int mode);
    wint_t getwc([FILE](../io/FILE.html)* stream);
    wint_t [getwchar](../io/getwchar.html)(void);
    wint_t putwc(wchar_t c, [FILE](../io/FILE.html)* stream);
    wint_t [putwchar](../io/putwchar.html)(wchar_t c);
    wint_t [ungetwc](../io/ungetwc.html)(wint_t c, [FILE](../io/FILE.html)* stream);
    double [wcstod](../string/wide/wcstof.html)(const wchar_t* restrict nptr, wchar_t** restrict endptr);
    float [wcstof](../string/wide/wcstof.html)(const wchar_t* restrict nptr, wchar_t** restrict endptr);
    long double [wcstold](../string/wide/wcstof.html)(const wchar_t* restrict nptr, wchar_t** restrict endptr);
    long int [wcstol](../string/wide/wcstol.html)(const wchar_t* restrict nptr, wchar_t** restrict endptr, int base);
    long long int [wcstoll](../string/wide/wcstol.html)(const wchar_t* restrict nptr, wchar_t** restrict endptr, int base);
    unsigned long int [wcstoul](../string/wide/wcstoul.html)(const wchar_t* restrict nptr, wchar_t** restrict endptr,
                              int base);
    unsigned long long int [wcstoull](../string/wide/wcstoul.html)(const wchar_t* restrict nptr, wchar_t** restrict endptr,
                                    int base);
    wchar_t* [wcscpy](../string/wide/wcscpy.html)(wchar_t* restrict s1, const wchar_t* restrict s2);
    wchar_t* [wcsncpy](../string/wide/wcsncpy.html)(wchar_t* restrict s1, const wchar_t* restrict s2, [size_t](../types/size_t.html) n);
    wchar_t* [wmemcpy](../string/wide/wmemcpy.html)(wchar_t* restrict s1, const wchar_t* restrict s2, [size_t](../types/size_t.html) n);
    wchar_t* [wmemmove](../string/wide/wmemmove.html)(wchar_t* s1, const wchar_t* s2, [size_t](../types/size_t.html) n);
    wchar_t* [wcscat](../string/wide/wcscat.html)(wchar_t* restrict s1, const wchar_t* restrict s2);
    wchar_t* [wcsncat](../string/wide/wcsncat.html)(wchar_t* restrict s1, const wchar_t* restrict s2, [size_t](../types/size_t.html) n);
    int [wcscmp](../string/wide/wcscmp.html)(const wchar_t* s1, const wchar_t* s2);
    int [wcscoll](../string/wide/wcscoll.html)(const wchar_t* s1, const wchar_t* s2);
    int [wcsncmp](../string/wide/wcsncmp.html)(const wchar_t* s1, const wchar_t* s2, [size_t](../types/size_t.html) n);
    [size_t](../types/size_t.html) [wcsxfrm](../string/wide/wcsxfrm.html)(wchar_t* restrict s1, const wchar_t* restrict s2, [size_t](../types/size_t.html) n);
    int [wmemcmp](../string/wide/wmemcmp.html)(const wchar_t* s1, const wchar_t* s2, [size_t](../types/size_t.html) n);
    /*QWchar_t*/* [wcschr](../string/wide/wcschr.html)(/*QWchar_t*/* s, wchar_t c);
    [size_t](../types/size_t.html) [wcscspn](../string/wide/wcscspn.html)(const wchar_t* s1, const wchar_t* s2);
    /*QWchar_t*/* [wcspbrk](../string/wide/wcspbrk.html)(/*QWchar_t*/* s1, const wchar_t* s2);
    /*QWchar_t*/* [wcsrchr](../string/wide/wcsrchr.html)(/*QWchar_t*/* s, wchar_t c);
    [size_t](../types/size_t.html) [wcsspn](../string/wide/wcsspn.html)(const wchar_t* s1, const wchar_t* s2);
    /*QWchar_t*/* [wcsstr](../string/wide/wcsstr.html)(/*QWchar_t*/* s1, const wchar_t* s2);
    wchar_t* [wcstok](../string/wide/wcstok.html)(wchar_t* restrict s1, const wchar_t* restrict s2,
                    wchar_t** restrict ptr);
    /*QWchar_t*/* [wmemchr](../string/wide/wmemchr.html)(/*QWchar_t*/* s, wchar_t c, [size_t](../types/size_t.html) n);
    [size_t](../types/size_t.html) [wcslen](../string/wide/wcslen.html)(const wchar_t* s);
    [size_t](../types/size_t.html) wcsnlen(const wchar_t* s, [size_t](../types/size_t.html) n);
    wchar_t* [wmemset](../string/wide/wmemset.html)(wchar_t* s, wchar_t c, [size_t](../types/size_t.html) n);
    [size_t](../types/size_t.html) [wcsftime](../chrono/wcsftime.html)(wchar_t* restrict s, [size_t](../types/size_t.html) maxsize, const wchar_t* restrict format,
                    const struct [tm](../chrono/tm.html)* restrict timeptr);
    wint_t [btowc](../string/multibyte/btowc.html)(int c);
    int [wctob](../string/multibyte/wctob.html)(wint_t c);
    int [mbsinit](../string/multibyte/mbsinit.html)(const [mbstate_t](../string/multibyte/mbstate_t.html)* ps);
    [size_t](../types/size_t.html) [mbrlen](../string/multibyte/mbrlen.html)(const char* restrict s, [size_t](../types/size_t.html) n, [mbstate_t](../string/multibyte/mbstate_t.html)* restrict ps);
    [size_t](../types/size_t.html) [mbrtowc](../string/multibyte/mbrtowc.html)(wchar_t* restrict pwc, const char* restrict s, [size_t](../types/size_t.html) n,
                   [mbstate_t](../string/multibyte/mbstate_t.html)* restrict ps);
    [size_t](../types/size_t.html) [wcrtomb](../string/multibyte/wcrtomb.html)(char* restrict s, wchar_t wc, [mbstate_t](../string/multibyte/mbstate_t.html)* restrict ps);
    [size_t](../types/size_t.html) [mbsrtowcs](../string/multibyte/mbsrtowcs.html)(wchar_t* restrict dst, const char** restrict src, [size_t](../types/size_t.html) len,
                     [mbstate_t](../string/multibyte/mbstate_t.html)* restrict ps);
    [size_t](../types/size_t.html) [wcsrtombs](../string/multibyte/wcsrtombs.html)(char* restrict dst, const wchar_t** restrict src, [size_t](../types/size_t.html) len,
                     [mbstate_t](../string/multibyte/mbstate_t.html)* restrict ps);

Only if the implementation defines __STDC_IEC_60559_DFP__: 
    
    
    _Decimal32 wcstod32(const wchar_t* restrict nptr, wchar_t** restrict endptr);
    _Decimal64 wcstod64(const wchar_t* restrict nptr, wchar_t** restrict endptr);
    _Decimal128 wcstod128(const wchar_t* restrict nptr, wchar_t** restrict endptr);

Only if the implementation defines __STDC_IEC_60559_TYPES__ and additionally the user code defines __STDC_WANT_IEC_60559_TYPES_EXT__ before any inclusion of **`< wchar.h>`**: 
    
    
    #ifdef __STDC_WANT_IEC_60559_TYPES_EXT__
    /*_FloatN*/ /*wcstofN*/(const wchar_t* restrict nptr, wchar_t** restrict endptr);
    /*_FloatNx*/ /*wcstofNx*/(const wchar_t* restrict nptr, wchar_t** restrict endptr);
    /*_DecimalN*/ /*wcstodN*/(const wchar_t* restrict nptr, wchar_t** restrict endptr);
    /*_DecimalNx*/ /*wcstodNx*/(const wchar_t* restrict nptr, wchar_t** restrict endptr);
    void /*wcstoencfN*/(unsigned char encptr[restrict static N/8],
                        const wchar_t* restrict nptr, wchar_t** restrict endptr);
    void /*wcstoencdecdN*/(unsigned char encptr[restrict static N/8],
                           const wchar_t* restrict nptr, wchar_t** restrict endptr);
    void /*wcstoencbindN*/(unsigned char encptr[restrict static N/8],
                           const wchar_t* restrict nptr, wchar_t** restrict endptr);
    #endif

Only if the implementation defines __STDC_LIB_EXT1__ and additionally the user code defines __STDC_WANT_LIB_EXT1__ before any inclusion of **`< wchar.h>`**: 
    
    
    #ifdef __STDC_WANT_LIB_EXT1__
    typedef /* see description */ errno_t;
    typedef /* see description */ rsize_t;
     
    int fwprintf_s([FILE](../io/FILE.html)* restrict stream, const wchar_t* restrict format, ...);
    int fwscanf_s([FILE](../io/FILE.html)* restrict stream, const wchar_t* restrict format, ...);
    int snwprintf_s(wchar_t* restrict s, rsize_t n, const wchar_t* restrict format, ...);
    int swprintf_s(wchar_t* restrict s, rsize_t n, const wchar_t* restrict format, ...);
    int swscanf_s(const wchar_t* restrict s, const wchar_t* restrict format, ...);
    int vfwprintf_s([FILE](../io/FILE.html)* restrict stream, const wchar_t* restrict format, va_list arg);
    int vfwscanf_s([FILE](../io/FILE.html)* restrict stream, const wchar_t* restrict format, va_list arg);
    int vsnwprintf_s(wchar_t* restrict s, rsize_t n, const wchar_t* restrict format,
                     va_list arg);
    int vswprintf_s(wchar_t* restrict s, rsize_t n, const wchar_t* restrict format,
                    va_list arg);
    int vswscanf_s(const wchar_t* restrict s, const wchar_t* restrict format, va_list arg);
    int vwprintf_s(const wchar_t* restrict format, va_list arg);
    int vwscanf_s(const wchar_t* restrict format, va_list arg);
    int wprintf_s(const wchar_t* restrict format, ...);
    int wscanf_s(const wchar_t* restrict format, ...);
    errno_t wcscpy_s(wchar_t* restrict s1, rsize_t s1max, const wchar_t* restrict s2);
    errno_t wcsncpy_s(wchar_t* restrict s1, rsize_t s1max, const wchar_t* restrict s2,
                      rsize_t n);
    errno_t wmemcpy_s(wchar_t* restrict s1, rsize_t s1max, const wchar_t* restrict s2,
                      rsize_t n);
    errno_t wmemmove_s(wchar_t* s1, rsize_t s1max, const wchar_t* s2, rsize_t n);
    errno_t wcscat_s(wchar_t* restrict s1, rsize_t s1max, const wchar_t* restrict s2);
    errno_t wcsncat_s(wchar_t* restrict s1, rsize_t s1max, const wchar_t* restrict s2,
                      rsize_t n);
    wchar_t* wcstok_s(wchar_t* restrict s1, rsize_t* restrict s1max,
                      const wchar_t* restrict s2, wchar_t** restrict ptr);
    [size_t](../types/size_t.html) wcsnlen_s(const wchar_t* s, [size_t](../types/size_t.html) maxsize);
    errno_t wcrtomb_s([size_t](../types/size_t.html)* restrict retval, char* restrict s, rsize_t smax, wchar_t wc,
                      [mbstate_t](../string/multibyte/mbstate_t.html)* restrict ps);
    errno_t mbsrtowcs_s([size_t](../types/size_t.html)* restrict retval, wchar_t* restrict dst, rsize_t dstmax,
                        const char** restrict src, rsize_t len, [mbstate_t](../string/multibyte/mbstate_t.html)* restrict ps);
    errno_t wcsrtombs_s([size_t](../types/size_t.html)* restrict retval, char* restrict dst, rsize_t dstmax,
                        const wchar_t** restrict src, rsize_t len, [mbstate_t](../string/multibyte/mbstate_t.html)* restrict ps);
    #endif

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/wchar&oldid=180747](https://en.cppreference.com/mwiki/index.php?title=c/header/wchar&oldid=180747)" 

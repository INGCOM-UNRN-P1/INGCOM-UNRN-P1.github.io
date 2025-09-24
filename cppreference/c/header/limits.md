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
**`< limits.h>`**  
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

This header is part of the [type support](../types.html "c/types") library, in particular it's part of the C [numeric limits](../types/limits.html#Limits_of_core_language_integer_types "c/types/limits") interface. 

#####  Limits of core language integer types   
  
---  
BOOL_WIDTH(C23) |  bit width of _Bool   
(macro constant)  
BOOL_MAX(C29) |  maximum value of _Bool   
(macro constant)  
CHAR_BIT |  bit width of byte   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_CHAR_BIT&action=edit)  
MB_LEN_MAX |  maximum number of bytes in a multibyte character   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_MB_LEN_MAX&action=edit)  
CHAR_WIDTH(C23) |  bit width of char, same as `CHAR_BIT`   
(macro constant)  
CHAR_MIN |  minimum value of char   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_CHAR_MIN&action=edit)  
CHAR_MAX |  maximum value of char   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_CHAR_MAX&action=edit)  
SCHAR_WIDTHSHRT_WIDTHINT_WIDTHLONG_WIDTHLLONG_WIDTH(C23)(C23)(C23)(C23)(C23) |  bit width of signed char, short, int, long, and long long respectively   
(macro constant)  
SCHAR_MINSHRT_MININT_MINLONG_MINLLONG_MIN(C99) |  minimum value of signed char, short, int, long and long long respectively   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_signed_MIN&action=edit)  
SCHAR_MAXSHRT_MAXINT_MAXLONG_MAXLLONG_MAX(C99) |  maximum value of signed char, short, int, long and long long respectively   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_signed_MAX&action=edit)  
UCHAR_WIDTHUSHRT_WIDTHUINT_WIDTHULONG_WIDTHULLONG_WIDTH(C23)(C23)(C23)(C23)(C23) |  bit width of unsigned char, unsigned short, unsigned int, unsigned long, and unsigned long long respectively   
(macro constant)  
UCHAR_MAXUSHRT_MAXUINT_MAXULONG_MAXULLONG_MAX(C99) |  maximum value of unsigned char, unsigned short, unsigned int,  
unsigned long and unsigned long long respectively   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:cpp/types/dsc_unsigned_MAX&action=edit)  
BITINT_MAXWIDTH(C23) |  maximum width N supported by the declaration of a bit-precise integer in the type specifier _BitInt(N), greater than or equal to `ULLONG_WIDTH`   
(macro constant)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/limits&action=edit&section=1 "Edit section: Synopsis")] Synopsis
    
    
    #define __STDC_VERSION_LIMITS_H__ 202311L
     
    #define BITINT_MAXWIDTH  /* see description */
    #define BOOL_MAX         /* see description */
    #define BOOL_WIDTH       /* see description */
    #define CHAR_BIT         /* see description */
    #define CHAR_MAX         /* see description */
    #define CHAR_MIN         /* see description */
    #define CHAR_WIDTH       /* see description */
    #define INT_MAX          /* see description */
    #define INT_MIN          /* see description */
    #define INT_WIDTH        /* see description */
    #define LLONG_MAX        /* see description */
    #define LLONG_MIN        /* see description */
    #define LLONG_WIDTH      /* see description */
    #define LONG_MAX         /* see description */
    #define LONG_MIN         /* see description */
    #define LONG_WIDTH       /* see description */
    #define MB_LEN_MAX       /* see description */
    #define SCHAR_MAX        /* see description */
    #define SCHAR_MIN        /* see description */
    #define SCHAR_WIDTH      /* see description */
    #define SHRT_MAX         /* see description */
    #define SHRT_MIN         /* see description */
    #define SHRT_WIDTH       /* see description */
    #define UCHAR_MAX        /* see description */
    #define UCHAR_WIDTH      /* see description */
    #define UINT_MAX         /* see description */
    #define UINT_WIDTH       /* see description */
    #define ULLONG_MAX       /* see description */
    #define ULLONG_WIDTH     /* see description */
    #define ULONG_MAX        /* see description */
    #define ULONG_WIDTH      /* see description */
    #define USHRT_MAX        /* see description */
    #define USHRT_WIDTH      /* see description */

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/limits&oldid=180063](https://en.cppreference.com/mwiki/index.php?title=c/header/limits&oldid=180063)" 

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
**`< string.h>`**  
[`<tgmath.h>`](tgmath.html "c/header/tgmath") (C99)  
[`<threads.h>`](threads.html "c/header/threads") (C11)  
[`<time.h>`](time.html "c/header/time")  
[`<uchar.h>`](uchar.html "c/header/uchar") (C11)  
[`<wchar.h>`](wchar.html "c/header/wchar") (C95)  
[`<wctype.h>`](wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header provides functions for handling [null-terminated byte strings](../string/byte.html "c/string/byte"). 

| 

## Contents

  * [1 Macros](string.html#Macros)
  * [2 Types](string.html#Types)
  * [3 Functions](string.html#Functions)
    * [3.1 String manipulation](string.html#String_manipulation)
    * [3.2 String examination](string.html#String_examination)
    * [3.3 Character array manipulation](string.html#Character_array_manipulation)
    * [3.4 Miscellaneous](string.html#Miscellaneous)
  * [4 Synopsis](string.html#Synopsis)

  
---  
  
###  Macros  
  
[ NULL](../types/NULL.html "c/types/NULL") |  implementation-defined null pointer constant   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_NULL&action=edit)  
  
###  Types  
  
[ size_t](../types/size_t.html "c/types/size t") |  unsigned integer type returned by the [`sizeof`](../language/sizeof.html "c/language/sizeof") operator   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_size_t&action=edit)  
  
###  Functions  
  
#####  String manipulation   
  
[ strcpystrcpy_s](../string/byte/strcpy.html "c/string/byte/strcpy")(C11) |  copies one string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcpy&action=edit)  
[ strncpystrncpy_s](../string/byte/strncpy.html "c/string/byte/strncpy")(C11) |  copies a certain amount of characters from one string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strncpy&action=edit)  
[ strcatstrcat_s](../string/byte/strcat.html "c/string/byte/strcat")(C11) |  concatenates two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcat&action=edit)  
[ strncatstrncat_s](../string/byte/strncat.html "c/string/byte/strncat")(C11) |  concatenates a certain amount of characters of two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strncat&action=edit)  
[ strxfrm](../string/byte/strxfrm.html "c/string/byte/strxfrm") |  transform a string so that strcmp would produce the same result as strcoll   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strxfrm&action=edit)  
[ strdup](../string/byte/strdup.html "c/string/byte/strdup")(C23) |  allocates a copy of a string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strdup&action=edit)  
[ strndup](../string/byte/strndup.html "c/string/byte/strndup")(C23) |  allocates a copy of a string of specified size   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strndup&action=edit)  
  
#####  String examination   
  
[ strlenstrnlen_s](../string/byte/strlen.html "c/string/byte/strlen")(C11) |  returns the length of a given string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strlen&action=edit)  
[ strcmp](../string/byte/strcmp.html "c/string/byte/strcmp") |  compares two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcmp&action=edit)  
[ strncmp](../string/byte/strncmp.html "c/string/byte/strncmp") |  compares a certain amount of characters of two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strncmp&action=edit)  
[ strcoll](../string/byte/strcoll.html "c/string/byte/strcoll") |  compares two strings in accordance to the current locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcoll&action=edit)  
[ strchr](../string/byte/strchr.html "c/string/byte/strchr") |  finds the first occurrence of a character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strchr&action=edit)  
[ strrchr](../string/byte/strrchr.html "c/string/byte/strrchr") |  finds the last occurrence of a character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strrchr&action=edit)  
[ strspn](../string/byte/strspn.html "c/string/byte/strspn") |  returns the length of the maximum initial segment that consists   
of only the characters found in another byte string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strspn&action=edit)  
[ strcspn](../string/byte/strcspn.html "c/string/byte/strcspn") |  returns the length of the maximum initial segment that consists   
of only the characters not found in another byte string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcspn&action=edit)  
[ strpbrk](../string/byte/strpbrk.html "c/string/byte/strpbrk") |  finds the first location of any character in one string, in another string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strpbrk&action=edit)  
[ strstr](../string/byte/strstr.html "c/string/byte/strstr") |  finds the first occurrence of a substring of characters   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strstr&action=edit)  
[ strtokstrtok_s](../string/byte/strtok.html "c/string/byte/strtok")(C11) |  finds the next token in a byte string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtok&action=edit)  
  
#####  Character array manipulation   
  
[ memchr](../string/byte/memchr.html "c/string/byte/memchr") |  searches an array for the first occurrence of a character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memchr&action=edit)  
[ memcmp](../string/byte/memcmp.html "c/string/byte/memcmp") |  compares two buffers   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memcmp&action=edit)  
[ memsetmemset_explicitmemset_s](../string/byte/memset.html "c/string/byte/memset")(C23)(C11) |  fills a buffer with a character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memset&action=edit)  
[ memcpymemcpy_s](../string/byte/memcpy.html "c/string/byte/memcpy")(C11) |  copies one buffer to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memcpy&action=edit)  
[ memmovememmove_s](../string/byte/memmove.html "c/string/byte/memmove")(C11) |  moves one buffer to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memmove&action=edit)  
[ memccpy](../string/byte/memccpy.html "c/string/byte/memccpy")(C23) |  copies one buffer to another, stopping after the specified delimiter   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memccpy&action=edit)  
  
#####  Miscellaneous   
  
[ strerrorstrerror_sstrerrorlen_s](../string/byte/strerror.html "c/string/byte/strerror")(C11)(C11) |  returns a text version of a given error code   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strerror&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/string&action=edit&section=1 "Edit section: Synopsis")] Synopsis
    
    
    #define __STDC_VERSION_STRING_H__ 202311L
     
    #define NULL /* see description */
     
    typedef /* see description */ [size_t](../types/size_t.html);
     
    void* [memcpy](../string/byte/memcpy.html)(void* restrict s1, const void* restrict s2, [size_t](../types/size_t.html) n);
    void* memccpy(void* restrict s1, const void* restrict s2, int c, [size_t](../types/size_t.html) n);
    void* [memmove](../string/byte/memmove.html)(void* s1, const void* s2, [size_t](../types/size_t.html) n);
    char* [strcpy](../string/byte/strcpy.html)(char* restrict s1, const char* restrict s2);
    char* [strncpy](../string/byte/strncpy.html)(char* restrict s1, const char* restrict s2, [size_t](../types/size_t.html) n);
    char* strdup(const char* s);
    char* strndup(const char* s, [size_t](../types/size_t.html) n);
    char* [strcat](../string/byte/strcat.html)(char* restrict s1, const char* restrict s2);
    char* [strncat](../string/byte/strncat.html)(char* restrict s1, const char* restrict s2, [size_t](../types/size_t.html) n);
    int [memcmp](../string/byte/memcmp.html)(const void* s1, const void* s2, [size_t](../types/size_t.html) n);
    int [strcmp](../string/byte/strcmp.html)(const char* s1, const char* s2);
    int [strcoll](../string/byte/strcoll.html)(const char* s1, const char* s2);
    int [strncmp](../string/byte/strncmp.html)(const char* s1, const char* s2, [size_t](../types/size_t.html) n);
    [size_t](../types/size_t.html) [strxfrm](../string/byte/strxfrm.html)(char* restrict s1, const char* restrict s2, [size_t](../types/size_t.html) n);
    /*QVoid*/* [memchr](../string/byte/memchr.html)(/*QVoid*/* s, int c, [size_t](../types/size_t.html) n);
    /*QChar*/* [strchr](../string/byte/strchr.html)(/*QChar*/* s, int c);
    [size_t](../types/size_t.html) [strcspn](../string/byte/strcspn.html)(const char* s1, const char* s2);
    /*QChar*/* [strpbrk](../string/byte/strpbrk.html)(/*QChar*/* s1, const char* s2);
    /*QChar*/* [strrchr](../string/byte/strrchr.html)(/*QChar*/* s, int c);
    [size_t](../types/size_t.html) [strspn](../string/byte/strspn.html)(const char* s1, const char* s2);
    /*QChar*/* [strstr](../string/byte/strstr.html)(/*QChar*/* s1, const char* s2);
    char* [strtok](../string/byte/strtok.html)(char* restrict s1, const char* restrict s2);
    void* [memset](../string/byte/memset.html)(void* s, int c, [size_t](../types/size_t.html) n);
    void* memset_explicit(void* s, int c, [size_t](../types/size_t.html) n);
    char* [strerror](../string/byte/strerror.html)(int errnum);
    [size_t](../types/size_t.html) [strlen](../string/byte/strlen.html)(const char* s);
    [size_t](../types/size_t.html) strnlen(const char* s, [size_t](../types/size_t.html) n);

Only if the implementation defines __STDC_LIB_EXT1__ and additionally the user code defines __STDC_WANT_LIB_EXT1__ before any inclusion of `<string.h>`: 
    
    
    #ifdef __STDC_WANT_LIB_EXT1__
     
    tyepdef /* see description */ errno_t;
    tyepdef /* see description */ rsize_t;
     
    errno_t memcpy_s(void* restrict s1, rsize_t s1max, const void* restrict s2, rsize_t n);
    errno_t memmove_s(void* s1, rsize_t s1max, const void* s2, rsize_t n);
    errno_t strcpy_s(char* restrict s1, rsize_t s1max, const char* restrict s2);
    errno_t strncpy_s(char* restrict s1, rsize_t s1max, const char* restrict s2, rsize_t n);
    errno_t strcat_s(char* restrict s1, rsize_t s1max, const char* restrict s2);
    errno_t strncat_s(char* restrict s1, rsize_t s1max, const char* restrict s2, rsize_t n);
    char* strtok_s(char* restrict s1, rsize_t* restrict s1max,
                   const char* restrict s2, char** restrict ptr);
    errno_t memset_s(void* s, rsize_t smax, int c, rsize_t n)
    errno_t strerror_s(char* s, rsize_t maxsize, errno_t errnum);
    [size_t](../types/size_t.html) strerrorlen_s(errno_t errnum);
    [size_t](../types/size_t.html) strnlen_s(const char* s, [size_t](../types/size_t.html) maxsize);
     
    #endif

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/string&oldid=181830](https://en.cppreference.com/mwiki/index.php?title=c/header/string&oldid=181830)" 

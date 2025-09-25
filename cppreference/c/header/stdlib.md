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
  
| **`< stdlib.h>`**  
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

This header is a part of [program support utilities](../program.html "c/program") library, in particular, it provides functions for program termination, [memory management](../memory.html "c/memory"), [string conversions](../string.html "c/string"), [random numbers](../numeric/random.html "c/numeric/random") generation. The header also provides some [algorithms](../algorithm.html "c/algorithm"). 

###  Functions  
  
---  
[ abort](../program/abort.html "c/program/abort") |  causes abnormal program termination (without cleaning up)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_abort&action=edit)  
[ exit](../program/exit.html "c/program/exit") |  causes normal program termination with cleaning up   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_exit&action=edit)  
[ quick_exit](../program/quick_exit.html "c/program/quick exit")(C11) |  causes normal program termination without completely cleaning up   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_quick_exit&action=edit)  
[ _Exit](../program/_Exit.html "c/program/ Exit")(C99) |  causes normal program termination without cleaning up   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_Exit&action=edit)  
[ atexit](../program/atexit.html "c/program/atexit") |  registers a function to be called on [exit()](../program/exit.html "c/program/exit") invocation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_atexit&action=edit)  
[ at_quick_exit](../program/at_quick_exit.html "c/program/at quick exit")(C11) |  registers a function to be called on [`quick_exit`](../program/quick_exit.html "c/program/quick exit") invocation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_at_quick_exit&action=edit)  
[ EXIT_SUCCESSEXIT_FAILURE](../program/EXIT_status.html "c/program/EXIT status") |  indicates program execution execution status   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_EXIT_status&action=edit)  
| This section is incomplete  
Reason: Add more from 7.24 General utilities <stdlib.h>  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/stdlib&action=edit&section=1 "Edit section: Synopsis")] Synopsis

| This section is incomplete  
Reason: Add more from B.23 General utilities <stdlib.h>  
---|---  
      
    
    #define __STDC_VERSION_STDLIB_H__ 202311L
     
    // TODO: types and macros
     
    void [call_once](../thread/call_once.html)([once_flag](../thread.html)* flag, void (*func)(void));
    double [atof](../string/byte/atof.html)(const char* nptr);
    int [atoi](../string/byte/atoi.html)(const char* nptr);
    long int [atol](../string/byte/atoi.html)(const char* nptr);
    long long int [atoll](../string/byte/atoi.html)(const char* nptr);
    int strfromd(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format, double fp);
    int strfromf(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format, float fp);
    int strfroml(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format, long double fp);
    double [strtod](../string/byte/strtof.html)(const char* restrict nptr, char** restrict endptr);
    float [strtof](../string/byte/strtof.html)(const char* restrict nptr, char** restrict endptr);
    long double [strtold](../string/byte/strtof.html)(const char* restrict nptr, char** restrict endptr);
    long int [strtol](../string/byte/strtol.html)(const char* restrict nptr, char** restrict endptr, int base);
    long long int [strtoll](../string/byte/strtol.html)(const char* restrict nptr, char** restrict endptr, int base);
    unsigned long int [strtoul](../string/byte/strtoul.html)(const char* restrict nptr, char** restrict endptr, int base);
    unsigned long long int [strtoull](../string/byte/strtoul.html)(const char* restrict nptr,
                                    char** restrict endptr, int base);
    int [rand](../numeric/random/rand.html)(void);
    void [srand](../numeric/random/srand.html)(unsigned int seed);
    void* aligned_alloc([size_t](../types/size_t.html) alignment, [size_t](../types/size_t.html) size);
    void* [calloc](../memory/calloc.html)([size_t](../types/size_t.html) nmemb, [size_t](../types/size_t.html) size);
    void [free](../memory/free.html)(void* ptr);
    void free_sized(void* ptr, [size_t](../types/size_t.html) size);
    void free_aligned_sized(void* ptr, [size_t](../types/size_t.html) alignment, [size_t](../types/size_t.html) size);
    void* [malloc](../memory/malloc.html)([size_t](../types/size_t.html) size);
    void* [realloc](../memory/realloc.html)(void* ptr, [size_t](../types/size_t.html) size);
    [[noreturn]] void [abort](../program/abort.html)(void);
    int [atexit](../program/atexit.html)(void (*func)(void));
    int [at_quick_exit](../program/at_quick_exit.html)(void (*func)(void));
    [[noreturn]] void [exit](../program/exit.html)(int status);
    [[noreturn]] void [_Exit](../program/_Exit.html)(int status);
    char* [getenv](../program/getenv.html)(const char* name);
    [[noreturn]] void [quick_exit](../program/quick_exit.html)(int status);
    int [system](../program/system.html)(const char* string);
    QVoid* [bsearch](../algorithm/bsearch.html)(const void* key, QVoid* base, [size_t](../types/size_t.html) nmemb, [size_t](../types/size_t.html) size,
                   int (*compar)(const void* , const void* ));
    void [qsort](../algorithm/qsort.html)(void* base, [size_t](../types/size_t.html) nmemb, [size_t](../types/size_t.html) size,
               int (*compar)(const void* , const void* ));
    int [abs](../numeric/math/abs.html)(int j);
    long int [labs](../numeric/math/abs.html)(long int j);
    long long int [llabs](../numeric/math/abs.html)(long long int j);
    div_t [div](../numeric/math/div.html)(int numer, int denom);
    ldiv_t [ldiv](../numeric/math/div.html)(long int numer, long int denom);
    lldiv_t lldiv(long long int numer, long long int denom);
    int [mblen](../string/multibyte/mblen.html)(const char* s, [size_t](../types/size_t.html) n);
    int [mbtowc](../string/multibyte/mbtowc.html)(wchar_t* restrict pwc, const char* restrict s, [size_t](../types/size_t.html) n);
    int [wctomb](../string/multibyte/wctomb.html)(char* s, wchar_t wc);
    [size_t](../types/size_t.html) [mbstowcs](../string/multibyte/mbstowcs.html)(wchar_t* restrict pwcs, const char* restrict s, [size_t](../types/size_t.html) n);
    [size_t](../types/size_t.html) [wcstombs](../string/multibyte/wcstombs.html)(char* restrict s, const wchar_t* restrict pwcs, [size_t](../types/size_t.html) n);
    [size_t](../types/size_t.html) memalignment(const void* p);

Only if the implementation defines __STDC_IEC_60559_DFP__: 
    
    
    int strfromd32(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format, _Decimal32 fp);
    int strfromd64(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format, _Decimal64 fp);
    int strfromd128(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format, _Decimal128 fp);
    _Decimal32 strtod32(const char* restrict nptr, char** restrict endptr);
    _Decimal64 strtod64(const char* restrict nptr, char** restrict endptr);
    _Decimal128 strtod128(const char* restrict nptr, char** restrict endptr);

Only if the implementation defines __STDC_IEC_60559_TYPES__ and additionally the user code defines __STDC_WANT_IEC_60559_TYPES_EXT__ before any inclusion of `<stdlib.h>`: 
    
    
    #ifdef __STDC_WANT_IEC_60559_TYPES_EXT__
    int strfromfN(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format, _FloatN fp);
    int strfromfNx(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format, _FloatNx fp);
    int strfromdN(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format, _DecimalN fp);
    int strfromdNx(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format, _DecimalNx fp);
    _FloatN strtofN(const char* restrict nptr, char** restrict endptr);
    _FloatNx strtofNx(const char* restrict nptr, char** restrict endptr);
    _DecimalN strtodN(const char* restrict nptr, char** restrict endptr);
    _DecimalNx strtodNx(const char* restrict nptr, char** restrict endptr);
    int strfromencfN(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format,
                     const unsigned char encptr[restrict static N/8]);
    int strfromencdecdN(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format,
                        const unsigned char encptr[restrict static N/8]);
    int strfromencbindN(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format,
                        const unsigned char encptr[restrict static N/8]);
    void strtoencfN(unsigned char encptr[restrict static N/8],
                    const char* restrict nptr, char** restrict endptr);
    void strtoencdecdN(unsigned char encptr[restrict static N/8],
                       const char* restrict nptr, char** restrict endptr);
    void strtoencbindN(unsigned char encptr[restrict static N/8],
                       const char* restrict nptr, char** restrict endptr);
    #endif

Only if the implementation defines __STDC_LIB_EXT1__ and additionally the user code defines __STDC_WANT_LIB_EXT1__ before any inclusion of `stdio.h`: 
    
    
    #if defined(__STDC_WANT_LIB_EXT1__)
    constraint_handler_t set_constraint_handler_s(constraint_handler_t handler);
    void abort_handler_s(const char* restrict msg, void* restrict ptr, errno_t error);
    void ignore_handler_s(const char* restrict msg, void* restrict ptr, errno_t error);
    errno_t getenv_s([size_t](../types/size_t.html)* restrict len, char* restrict value, rsize_t maxsize,
                     const char* restrict name);
    QVoid* bsearch_s(const void* key, QVoid* base, rsize_t nmemb, rsize_t size,
                     int (*compar)(const void* k, const void* y, void* context),
                                   void* context);
    errno_t qsort_s(void* base, rsize_t nmemb, rsize_t size,
                    int (*compar)(const void* x, const void* y, void* context),
                                  void* context);
    errno_t wctomb_s(int* restrict status, char* restrict s, rsize_t smax,
                     wchar_t wc);
    errno_t mbstowcs_s([size_t](../types/size_t.html)* restrict retval, wchar_t* restrict dst, rsize_t dstmax,
                       const char* restrict src, rsize_t len);
    errno_t wcstombs_s([size_t](../types/size_t.html)* restrict retval, char* restrict dst, rsize_t dstmax,
                       const wchar_t* restrict src, rsize_t len);
    #endif

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/stdlib&oldid=180220](https://en.cppreference.com/mwiki/index.php?title=c/header/stdlib&oldid=180220)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



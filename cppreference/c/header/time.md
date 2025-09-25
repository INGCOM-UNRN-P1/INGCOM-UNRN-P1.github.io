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
**`< time.h>`**  
[`<uchar.h>`](uchar.html "c/header/uchar") (C11)  
[`<wchar.h>`](wchar.html "c/header/wchar") (C95)  
[`<wctype.h>`](wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header is part of [date and time utilities](../chrono.html "c/chrono") library. 

## Contents

  * [1 Functions](time.html#Functions)
    * [1.1 Time manipulation](time.html#Time_manipulation)
    * [1.2 Format conversions](time.html#Format_conversions)
  * [2 Constants](time.html#Constants)
  * [3 Types](time.html#Types)
  * [4 Synopsis](time.html#Synopsis)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/time&action=edit&section=1 "Edit section: Functions")] Functions

#####  Time manipulation   
  
---  
[ difftime](../chrono/difftime.html "c/chrono/difftime") |  computes the difference between times   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_difftime&action=edit)  
[ time](../chrono/time.html "c/chrono/time") |  returns the current calendar time of the system as time since epoch   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_time&action=edit)  
[ clock](../chrono/clock.html "c/chrono/clock") |  returns raw processor clock time since the program is started   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_clock&action=edit)  
[ timespec_get](../chrono/timespec_get.html "c/chrono/timespec get")(C11) |  returns the calendar time in seconds and nanoseconds based on a given time base   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_timespec_get&action=edit)  
[ timespec_getres](../chrono/timespec_getres.html "c/chrono/timespec getres")(C23) |  returns the resolution of calendar time based on a given time base   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_timespec_getres&action=edit)  
  
#####  Format conversions   
  
[ asctimeasctime_s](../chrono/asctime.html "c/chrono/asctime")(deprecated in C23)(C11) |  converts a [tm](../chrono/tm.html "c/chrono/tm") object to a textual representation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_asctime&action=edit)  
[ ctimectime_s](../chrono/ctime.html "c/chrono/ctime")(deprecated in C23)(C11) |  converts a [time_t](../chrono/time_t.html "c/chrono/time t") object to a textual representation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_ctime&action=edit)  
[ strftime](../chrono/strftime.html "c/chrono/strftime") |  converts a [tm](../chrono/tm.html "c/chrono/tm") object to custom textual representation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_strftime&action=edit)  
[ gmtimegmtime_rgmtime_s](../chrono/gmtime.html "c/chrono/gmtime")(C23)(C11) |  converts time since epoch to calendar time expressed as Coordinated Universal Time (UTC)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_gmtime&action=edit)  
[ localtimelocaltime_rlocaltime_s](../chrono/localtime.html "c/chrono/localtime")(C23)(C11) |  converts time since epoch to calendar time expressed as local time   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_localtime&action=edit)  
[ mktime](../chrono/mktime.html "c/chrono/mktime") |  converts calendar time to time since epoch   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_mktime&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/time&action=edit&section=2 "Edit section: Constants")] Constants

[ CLOCKS_PER_SEC](../chrono/CLOCKS_PER_SEC.html "c/chrono/CLOCKS PER SEC") |  number of processor clock ticks per second   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_CLOCKS_PER_SEC&action=edit)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/time&action=edit&section=3 "Edit section: Types")] Types

[ tm](../chrono/tm.html "c/chrono/tm") |  calendar time type  
(struct)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_tm&action=edit)  
---|---  
[ time_t](../chrono/time_t.html "c/chrono/time t") |  calendar time since epoch type   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_time_t&action=edit)  
[ clock_t](../chrono/clock_t.html "c/chrono/clock t") |  processor time since era type   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_clock_t&action=edit)  
[ timespec](../chrono/timespec.html "c/chrono/timespec")(C11) |  time in seconds and nanoseconds   
(struct)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_timespec&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/time&action=edit&section=4 "Edit section: Synopsis")] Synopsis
    
    
    #define __STDC_VERSION_TIME_H__ 202311L
     
    #define NULL           /* see description */
    #define CLOCKS_PER_SEC /* see description */
    #define TIME_UTC       /* see description */
     
    typedef /* see description */ [clock_t](../chrono/clock_t.html);
    typedef /* see description */ [size_t](../types/size_t.html);
    typedef /* see description */ [time_t](../chrono/time_t.html);
     
    struct timespec { /* see description */ };
    struct [tm](../chrono/tm.html) { /* see description */ };
     
    [clock_t](../chrono/clock_t.html) [clock](../chrono/clock.html)(void);
    double [difftime](../chrono/difftime.html)([time_t](../chrono/time_t.html) time1, [time_t](../chrono/time_t.html) time0);
    [time_t](../chrono/time_t.html) [mktime](../chrono/mktime.html)(struct [tm](../chrono/tm.html)* timeptr);
    [time_t](../chrono/time_t.html) timegm(struct [tm](../chrono/tm.html)* timeptr);
    [time_t](../chrono/time_t.html) [time](../chrono/time.html)([time_t](../chrono/time_t.html)* timer);
    int timespec_get(struct timespec* ts, int base);
    int timespec_getres(struct timespec* ts, int base);
    [[deprecated]] char* [asctime](../chrono/asctime.html)(const struct [tm](../chrono/tm.html)* timeptr);
    [[deprecated]] char* [ctime](../chrono/ctime.html)(const [time_t](../chrono/time_t.html)* timer);
    struct [tm](../chrono/tm.html)* [gmtime](../chrono/gmtime.html)(const [time_t](../chrono/time_t.html)* timer);
    struct [tm](../chrono/tm.html)* gmtime_r(const [time_t](../chrono/time_t.html)* timer, struct [tm](../chrono/tm.html)* buf);
    struct [tm](../chrono/tm.html)* [localtime](../chrono/localtime.html)(const [time_t](../chrono/time_t.html)* timer);
    struct [tm](../chrono/tm.html)* localtime_r(const [time_t](../chrono/time_t.html)* timer, struct [tm](../chrono/tm.html)* buf);
    [size_t](../types/size_t.html) [strftime](../chrono/strftime.html)(char* restrict s, [size_t](../types/size_t.html) maxsize, const char* restrict format,
    const struct [tm](../chrono/tm.html)* restrict timeptr);

Only if supported by the implementation: 
    
    
    #define TIME_MONOTONIC /* see description */
    #define TIME_ACTIVE    /* see description */

Only if threads are supported and it is supported by the implementation: 
    
    
    #define TIME_THREAD_ACTIVE /* see description */

Only if the implementation defines __STDC_LIB_EXT1__ and additionally the user code defines __STDC_WANT_LIB_EXT1__ before any inclusion of **`< time.h>`**: 
    
    
    #ifdef __STDC_WANT_LIB_EXT1__
    typedef /* see description */ errno_t;
    typedef /* see description */ rsize_t;
     
    errno_t asctime_s(char* s, rsize_t maxsize, const struct [tm](../chrono/tm.html)* timeptr);
    errno_t ctime_s(char* s, rsize_t maxsize, const [time_t](../chrono/time_t.html)* timer);
    struct [tm](../chrono/tm.html)* gmtime_s(const [time_t](../chrono/time_t.html)* restrict timer, struct [tm](../chrono/tm.html)* restrict result);
    struct [tm](../chrono/tm.html)* localtime_s(const [time_t](../chrono/time_t.html)* restrict timer, struct [tm](../chrono/tm.html)* restrict result);
    #endif

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/time&oldid=180743](https://en.cppreference.com/mwiki/index.php?title=c/header/time&oldid=180743)" 

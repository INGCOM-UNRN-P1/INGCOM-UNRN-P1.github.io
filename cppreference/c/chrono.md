From cppreference.com

< [c](../c.html "c")

[ C](../c.html "c")

[Compiler support](compiler_support.html "c/compiler support")  
---  
[Language](language.html "c/language")  
[Headers](header.html "c/header")  
[Type support](types.html "c/types")  
[Program utilities](program.html "c/program")  
[Variadic function support](variadic.html "c/variadic")  
[Error handling](error.html "c/error")  
[Dynamic memory management](memory.html "c/memory")  
[Strings library](string.html "c/string")  
[Algorithms](algorithm.html "c/algorithm")  
[Numerics](numeric.html "c/numeric")  
**Date and time utilities**  
[Input/output support](io.html "c/io")  
[Localization support](locale.html "c/locale")  
[Concurrency support](thread.html "c/thread") (C11)  
[Technical Specifications](experimental.html "c/experimental")  
[Symbol index](index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

**Date and time utilities**

Functions  
---  
Time manipulation  
[difftime](chrono/difftime.html "c/chrono/difftime")  
[time](chrono/time.html "c/chrono/time")  
[clock](chrono/clock.html "c/chrono/clock")  
[timespec_get](chrono/timespec_get.html "c/chrono/timespec get")(C11)  
[timespec_getres](chrono/timespec_getres.html "c/chrono/timespec getres")(C23)  
Format conversions  
[asctimeasctime_s](chrono/asctime.html "c/chrono/asctime")(deprecated in C23)(C11)  
[ctimectime_s](chrono/ctime.html "c/chrono/ctime")(deprecated in C23)(C11)  
[strftime](chrono/strftime.html "c/chrono/strftime")  
[wcsftime](chrono/wcsftime.html "c/chrono/wcsftime")(C95)  
[gmtimegmtime_rgmtime_s](chrono/gmtime.html "c/chrono/gmtime")(C23)(C11)  
[localtimelocaltime_rlocaltime_s](chrono/localtime.html "c/chrono/localtime")(C23)(C11)  
[mktime](chrono/mktime.html "c/chrono/mktime")  
Constants  
[CLOCKS_PER_SEC](chrono/CLOCKS_PER_SEC.html "c/chrono/CLOCKS PER SEC")  
Types  
[tm](chrono/tm.html "c/chrono/tm")  
[time_t](chrono/time_t.html "c/chrono/time t")  
[clock_t](chrono/clock_t.html "c/chrono/clock t")  
[timespec](chrono/timespec.html "c/chrono/timespec")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/navbar_content&action=edit)

## Contents

  * [1 Functions](chrono.html#Functions)
    * [1.1 Time manipulation](chrono.html#Time_manipulation)
    * [1.2 Format conversions](chrono.html#Format_conversions)
  * [2 Constants](chrono.html#Constants)
  * [3 Types](chrono.html#Types)
  * [4 References](chrono.html#References)
  * [5 See also](chrono.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono&action=edit&section=1 "Edit section: Functions")] Functions

#####  Time manipulation   
  
---  
Defined in header `[`<time.h>`](header/time.html "c/header/time")`  
[ difftime](chrono/difftime.html "c/chrono/difftime") |  computes the difference between times   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_difftime&action=edit)  
[ time](chrono/time.html "c/chrono/time") |  returns the current calendar time of the system as time since epoch   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_time&action=edit)  
[ clock](chrono/clock.html "c/chrono/clock") |  returns raw processor clock time since the program is started   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_clock&action=edit)  
[ timespec_get](chrono/timespec_get.html "c/chrono/timespec get")(C11) |  returns the calendar time in seconds and nanoseconds based on a given time base   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_timespec_get&action=edit)  
[ timespec_getres](chrono/timespec_getres.html "c/chrono/timespec getres")(C23) |  returns the resolution of calendar time based on a given time base   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_timespec_getres&action=edit)  
  
#####  Format conversions   
  
Defined in header `[`<time.h>`](header/time.html "c/header/time")`  
[ asctimeasctime_s](chrono/asctime.html "c/chrono/asctime")(deprecated in C23)(C11) |  converts a [tm](chrono/tm.html "c/chrono/tm") object to a textual representation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_asctime&action=edit)  
[ ctimectime_s](chrono/ctime.html "c/chrono/ctime")(deprecated in C23)(C11) |  converts a [time_t](chrono/time_t.html "c/chrono/time t") object to a textual representation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_ctime&action=edit)  
[ strftime](chrono/strftime.html "c/chrono/strftime") |  converts a [tm](chrono/tm.html "c/chrono/tm") object to custom textual representation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_strftime&action=edit)  
Defined in header `[`<wchar.h>`](header/wchar.html "c/header/wchar")`  
[ wcsftime](chrono/wcsftime.html "c/chrono/wcsftime")(C95) |  converts a [tm](chrono/tm.html "c/chrono/tm") object to custom wide string textual representation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_wcsftime&action=edit)  
Defined in header `[`<time.h>`](header/time.html "c/header/time")`  
[ gmtimegmtime_rgmtime_s](chrono/gmtime.html "c/chrono/gmtime")(C23)(C11) |  converts time since epoch to calendar time expressed as Coordinated Universal Time (UTC)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_gmtime&action=edit)  
[ localtimelocaltime_rlocaltime_s](chrono/localtime.html "c/chrono/localtime")(C23)(C11) |  converts time since epoch to calendar time expressed as local time   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_localtime&action=edit)  
[ mktime](chrono/mktime.html "c/chrono/mktime") |  converts calendar time to time since epoch   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_mktime&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono&action=edit&section=2 "Edit section: Constants")] Constants

Defined in header `[`<time.h>`](header/time.html "c/header/time")`  
---  
[ CLOCKS_PER_SEC](chrono/CLOCKS_PER_SEC.html "c/chrono/CLOCKS PER SEC") |  number of processor clock ticks per second   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_CLOCKS_PER_SEC&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono&action=edit&section=3 "Edit section: Types")] Types

Defined in header `[`<time.h>`](header/time.html "c/header/time")`  
---  
[ tm](chrono/tm.html "c/chrono/tm") |  calendar time type  
(struct)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_tm&action=edit)  
[ time_t](chrono/time_t.html "c/chrono/time t") |  calendar time since epoch type   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_time_t&action=edit)  
[ clock_t](chrono/clock_t.html "c/chrono/clock t") |  processor time since era type   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_clock_t&action=edit)  
[ timespec](chrono/timespec.html "c/chrono/timespec")(C11) |  time in seconds and nanoseconds   
(struct)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_timespec&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.27 Date and time <time.h> (p: TBD) 



    

  * 7.29.5.1 The wcsftime function (p: TBD) 



    

  * 7.31.14 Date and time <time.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.27 Date and time <time.h> (p: 284-291) 



    

  * 7.29.5.1 The wcsftime function (p: 320-321) 



    

  * 7.31.14 Date and time <time.h> (p: 333) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.27 Date and time <time.h> (p: 388-397) 



    

  * 7.29.5.1 The wcsftime function (p: 439-440) 



    

  * 7.31.14 Date and time <time.h> (p: 456) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.23 Date and time <time.h> (p: 338-347) 



    

  * 7.24.5.1 The wcsftime function (p: 385-386) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.12 DATE AND TIME <time.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono&action=edit&section=5 "Edit section: See also")] See also

[C++ documentation](../cpp/chrono/c.html "cpp/chrono/c") for C Date and time utilities  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono&oldid=180683](https://en.cppreference.com/mwiki/index.php?title=c/chrono&oldid=180683)" 

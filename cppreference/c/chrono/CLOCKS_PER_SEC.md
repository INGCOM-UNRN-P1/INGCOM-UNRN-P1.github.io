From cppreference.com

< [c](../../c.html "c")‎ | [chrono](../chrono.html "c/chrono")

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

[ Date and time utilities](../chrono.html "c/chrono")

Functions  
---  
Time manipulation  
[difftime](difftime.html "c/chrono/difftime")  
[time](time.html "c/chrono/time")  
[clock](clock.html "c/chrono/clock")  
[timespec_get](timespec_get.html "c/chrono/timespec get")(C11)  
[timespec_getres](timespec_getres.html "c/chrono/timespec getres")(C23)  
Format conversions  
[asctimeasctime_s](asctime.html "c/chrono/asctime")(deprecated in C23)(C11)  
[ctimectime_s](ctime.html "c/chrono/ctime")(deprecated in C23)(C11)  
[strftime](strftime.html "c/chrono/strftime")  
[wcsftime](wcsftime.html "c/chrono/wcsftime")(C95)  
[gmtimegmtime_rgmtime_s](gmtime.html "c/chrono/gmtime")(C23)(C11)  
[localtimelocaltime_rlocaltime_s](localtime.html "c/chrono/localtime")(C23)(C11)  
[mktime](mktime.html "c/chrono/mktime")  
Constants  
**CLOCKS_PER_SEC**  
Types  
[tm](tm.html "c/chrono/tm")  
[time_t](time_t.html "c/chrono/time t")  
[clock_t](clock_t.html "c/chrono/clock t")  
[timespec](timespec.html "c/chrono/timespec")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/navbar_content&action=edit)

Defined in header `[`<time.h>`](../header/time.html "c/header/time")` |  |   
---|---|---  
#define CLOCKS_PER_SEC /* implementation-defined */ |  |   
| |   
  
Expands to an expression (not necessarily a compile-time constant) of type [clock_t](clock_t.html "c/chrono/clock t") equal to the number of clock ticks per second, as returned by [clock()](clock.html "c/chrono/clock"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/CLOCKS_PER_SEC&action=edit&section=1 "Edit section: Notes")] Notes

POSIX defines [CLOCKS_PER_SEC](https://pubs.opengroup.org/onlinepubs/9799919799/basedefs/time.h.html) as 1'000'000, regardless of the actual precision of [clock](clock.html "c/chrono/clock"). 

Until standardized as CLOCKS_PER_SEC in C89, this macro was sometimes known by its IEEE std 1003.1-1988 name CLK_TCK: that name was not included in C89 and was removed from POSIX itself in 1996 over ambiguity with _SC_CLK_TCK, which gives number of clocks per second for the function [`times`](https://pubs.opengroup.org/onlinepubs/9799919799/functions/times.html)). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/CLOCKS_PER_SEC&action=edit&section=2 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.27.1/2 Components of time (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.27.1/2 Components of time (p: 284) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.27.1/2 Components of time (p: 388) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.23.1/2 Components of time (p: 338) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.12.1 Components of time 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/CLOCKS_PER_SEC&action=edit&section=3 "Edit section: See also")] See also

[ clock](clock.html "c/chrono/clock") |  returns raw processor clock time since the program is started   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_clock&action=edit)  
---|---  
[ clock_t](clock_t.html "c/chrono/clock t") |  processor time since era type   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_clock_t&action=edit)  
[C++ documentation](../../cpp/chrono/c/CLOCKS_PER_SEC.html "cpp/chrono/c/CLOCKS PER SEC") for CLOCKS_PER_SEC  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono/CLOCKS_PER_SEC&oldid=180491](https://en.cppreference.com/mwiki/index.php?title=c/chrono/CLOCKS_PER_SEC&oldid=180491)" 

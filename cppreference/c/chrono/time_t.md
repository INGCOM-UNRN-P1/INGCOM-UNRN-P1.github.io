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
[CLOCKS_PER_SEC](CLOCKS_PER_SEC.html "c/chrono/CLOCKS PER SEC")  
Types  
[tm](tm.html "c/chrono/tm")  
**time_t**  
[clock_t](clock_t.html "c/chrono/clock t")  
[timespec](timespec.html "c/chrono/timespec")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/navbar_content&action=edit)

Defined in header `[`<time.h>`](../header/time.html "c/header/time")` |  |   
---|---|---  
typedef /* unspecified */ time_t; |  |   
| |   
  
Real arithmetic type capable of representing times. 

Although not defined by the C standard, this is almost always an integral value holding the number of seconds (not counting leap seconds) since 00:00, Jan 1 1970 UTC, corresponding to [ POSIX time](https://en.wikipedia.org/wiki/Unix_time "enwiki:Unix time"). 

## Contents

  * [1 Notes](time_t.html#Notes)
  * [2 Example](time_t.html#Example)
  * [3 References](time_t.html#References)
  * [4 See also](time_t.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/time_t&action=edit&section=1 "Edit section: Notes")] Notes

The standard uses the term _calendar time_ when referring to a value of type **time_t**. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/time_t&action=edit&section=2 "Edit section: Example")] Example

Show the start of the epoch.

Run this code
    
    
    #include <stdio.h>
    #include <time.h>
    #include <stdint.h>
     
    int main(void)
    {
        time_t epoch = 0;
        [printf](../io/fprintf.html)("%jd seconds since the epoch began\n", ([intmax_t](../types/integer.html))epoch);
        [printf](../io/fprintf.html)("%s", [asctime](asctime.html)([gmtime](gmtime.html)(&epoch)));
    }

Possible output: 
    
    
    0 seconds since the epoch began
    Thu Jan  1 00:00:00 1970

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/time_t&action=edit&section=3 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.27.1/3 Components of time (p: 284) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.27.1/3 Components of time (p: 388) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.23.1/3 Components of time (p: 338) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.12.1 Components of time 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/time_t&action=edit&section=4 "Edit section: See also")] See also

[ time](time.html "c/chrono/time") |  returns the current calendar time of the system as time since epoch   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_time&action=edit)  
---|---  
[ localtimelocaltime_rlocaltime_s](localtime.html "c/chrono/localtime")(C23)(C11) |  converts time since epoch to calendar time expressed as local time   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_localtime&action=edit)  
[ gmtimegmtime_rgmtime_s](gmtime.html "c/chrono/gmtime")(C23)(C11) |  converts time since epoch to calendar time expressed as Coordinated Universal Time (UTC)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_gmtime&action=edit)  
[C++ documentation](../../cpp/chrono/c/time_t.html "cpp/chrono/c/time t") for time_t  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono/time_t&oldid=144874](https://en.cppreference.com/mwiki/index.php?title=c/chrono/time_t&oldid=144874)" 

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
**tm**  
[time_t](time_t.html "c/chrono/time t")  
[clock_t](clock_t.html "c/chrono/clock t")  
[timespec](timespec.html "c/chrono/timespec")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/navbar_content&action=edit)

Defined in header `[`<time.h>`](../header/time.html "c/header/time")` |  |   
---|---|---  
struct tm; |  |   
| |   
  
Structure holding a calendar date and time broken down into its components. 

## Contents

  * [1 Member objects](tm.html#Member_objects)
    * [1.1 Notes](tm.html#Notes)
  * [2 Example](tm.html#Example)
  * [3 References](tm.html#References)
  * [4 See also](tm.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/tm&action=edit&section=1 "Edit section: Member objects")] Member objects

int tm_sec |  seconds after the minute – `[`​0​`, `61`]`(until C99)`[`​0​`, `60`]`(since C99)[[note 1]](tm.html#cite_note-leapsecond-1)   
(public member object)  
---|---  
int tm_min |  minutes after the hour – `[`​0​`, `59`]`   
(public member object)  
int tm_hour |  hours since midnight – `[`​0​`, `23`]`   
(public member object)  
int tm_mday |  day of the month – `[`1`, `31`]`   
(public member object)  
int tm_mon |  months since January – `[`​0​`, `11`]`   
(public member object)  
int tm_year |  years since 1900   
(public member object)  
int tm_wday |  days since Sunday – `[`​0​`, `6`]`   
(public member object)  
int tm_yday |  days since January 1 – `[`​0​`, `365`]`   
(public member object)  
int tm_isdst |  Daylight Saving Time flag. The value is positive if DST is in effect, zero if not and negative if no information is available   
(public member object)  
  
###### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/tm&action=edit&section=2 "Edit section: Notes")] Notes

The Standard mandates only the presence of the aforementioned members in either order. The implementations usually add more data-members to this structure. 

  1. [↑](tm.html#cite_ref-leapsecond_1-0) Range allows for a positive leap second. Two leap seconds in the same minute are not allowed (the C89 range 0..61 was a defect)



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/tm&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <time.h>
     
    int main(void)
    {
        struct tm start = {.tm_year = 2022 - 1900, .tm_mday = 1};
        [mktime](mktime.html)(&start);
        [printf](../io/fprintf.html)("%s", [asctime](asctime.html)(&start)); // note implicit trailing '\n'
    }

Output: 
    
    
    Sat Jan  1 00:00:00 2022

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/tm&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.27.1/3 Components of time (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.27.1/3 Components of time (p: 284) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.27.1/3 Components of time (p: 388) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.23.1/3 Components of time (p: 338) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.12.1 Components of time 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/tm&action=edit&section=5 "Edit section: See also")] See also

[ localtimelocaltime_rlocaltime_s](localtime.html "c/chrono/localtime")(C23)(C11) |  converts time since epoch to calendar time expressed as local time   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_localtime&action=edit)  
---|---  
[ gmtimegmtime_rgmtime_s](gmtime.html "c/chrono/gmtime")(C23)(C11) |  converts time since epoch to calendar time expressed as Coordinated Universal Time (UTC)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_gmtime&action=edit)  
[C++ documentation](../../cpp/chrono/c/tm.html "cpp/chrono/c/tm") for tm  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono/tm&oldid=172469](https://en.cppreference.com/mwiki/index.php?title=c/chrono/tm&oldid=172469)" 

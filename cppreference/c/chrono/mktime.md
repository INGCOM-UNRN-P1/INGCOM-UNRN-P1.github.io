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
**mktime**  
Constants  
[CLOCKS_PER_SEC](CLOCKS_PER_SEC.html "c/chrono/CLOCKS PER SEC")  
Types  
[tm](tm.html "c/chrono/tm")  
[time_t](time_t.html "c/chrono/time t")  
[clock_t](clock_t.html "c/chrono/clock t")  
[timespec](timespec.html "c/chrono/timespec")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/navbar_content&action=edit)

Defined in header `[`<time.h>`](../header/time.html "c/header/time")` |  |   
---|---|---  
[time_t](time_t.html) mktime( struct [tm](tm.html)* arg ); |  |   
| |   
  
Renormalizes local calendar time expressed as a [struct tm](tm.html "c/chrono/tm") object and also converts it to time since epoch as a [time_t](time_t.html "c/chrono/time t") object. arg->tm_wday and arg->tm_yday are ignored. The values in arg are not checked for being out of range. 

A negative value of arg->tm_isdst causes `mktime` to attempt to determine if Daylight Saving Time was in effect in the specified time. 

If the conversion to `time_t` is successful, the arg object is modified. All fields of arg are updated to fit their proper ranges. arg->tm_wday and arg->tm_yday are recalculated using information available in other fields. 

## Contents

  * [1 Parameters](mktime.html#Parameters)
  * [2 Return value](mktime.html#Return_value)
  * [3 Notes](mktime.html#Notes)
  * [4 Example](mktime.html#Example)
  * [5 References](mktime.html#References)
  * [6 See also](mktime.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/mktime&action=edit&section=1 "Edit section: Parameters")] Parameters

arg  |  \-  |  pointer to a [tm](tm.html "c/chrono/tm") object specifying local calendar time to convert   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/mktime&action=edit&section=2 "Edit section: Return value")] Return value

The time since epoch as a [time_t](time_t.html "c/chrono/time t") object on success, or -1 if arg cannot be represented as a [time_t](time_t.html "c/chrono/time t") object (POSIX also requires [EOVERFLOW](../error/errno_macros.html) to be stored in [errno](../error/errno.html "c/error/errno") in this case). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/mktime&action=edit&section=3 "Edit section: Notes")] Notes

If the struct [tm](tm.html) object was obtained from POSIX [`strptime`](https://pubs.opengroup.org/onlinepubs/9799919799/functions/strptime.html) or equivalent function, the value of `tm_isdst` is indeterminate, and needs to be set explicitly before calling `mktime`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/mktime&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #define _POSIX_C_SOURCE 200112L // for setenv on gcc
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
     
    int main(void)
    {
        setenv("TZ", "/usr/share/zoneinfo/America/New_York", 1); // POSIX-specific
     
        struct [tm](tm.html) [tm](tm.html) = *[localtime](localtime.html)(&([time_t](time_t.html)){[time](time.html)([NULL](../types/NULL.html))});
        [printf](../io/fprintf.html)("Today is           %s", [asctime](asctime.html)(&[tm](tm.html)));
        [printf](../io/fprintf.html)("(DST is %s)\n", [tm](tm.html).tm_isdst ? "in effect" : "not in effect");
        [tm](tm.html).tm_mon -= 100;  // tm_mon is now outside its normal range
        mktime(&[tm](tm.html));       // tm_isdst is not set to -1; today's DST status is used
        [printf](../io/fprintf.html)("100 months ago was %s", [asctime](asctime.html)(&[tm](tm.html)));
        [printf](../io/fprintf.html)("(DST was %s)\n", [tm](tm.html).tm_isdst ? "in effect" : "not in effect");
    }

Possible output: 
    
    
    Today is           Fri Apr 22 11:53:36 2016
    (DST is in effect)
    100 months ago was Sat Dec 22 10:53:36 2007
    (DST was not in effect)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/mktime&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.27.2.3 The mktime function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.27.2.3 The mktime function (p: 285-286) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.27.2.3 The mktime function (p: 390-391) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.23.2.3 The mktime function (p: 340-341) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.12.2.3 The mktime function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/mktime&action=edit&section=6 "Edit section: See also")] See also

[ localtimelocaltime_rlocaltime_s](localtime.html "c/chrono/localtime")(C23)(C11) |  converts time since epoch to calendar time expressed as local time   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_localtime&action=edit)  
---|---  
[C++ documentation](../../cpp/chrono/c/mktime.html "cpp/chrono/c/mktime") for mktime  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono/mktime&oldid=183117](https://en.cppreference.com/mwiki/index.php?title=c/chrono/mktime&oldid=183117)" 

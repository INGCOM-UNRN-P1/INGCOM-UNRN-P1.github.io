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
**time**  
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
[time_t](time_t.html "c/chrono/time t")  
[clock_t](clock_t.html "c/chrono/clock t")  
[timespec](timespec.html "c/chrono/timespec")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/navbar_content&action=edit)

Defined in header `[`<time.h>`](../header/time.html "c/header/time")` |  |   
---|---|---  
[time_t](time_t.html) time( [time_t](time_t.html)* arg ); |  |   
| |   
  
Returns the current calendar time encoded as a [time_t](time_t.html "c/chrono/time t") object, and also stores it in the [time_t](time_t.html "c/chrono/time t") object pointed to by arg (unless arg is a null pointer) 

## Contents

  * [1 Parameters](time.html#Parameters)
  * [2 Return value](time.html#Return_value)
  * [3 Notes](time.html#Notes)
  * [4 Example](time.html#Example)
  * [5 References](time.html#References)
  * [6 See also](time.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/time&action=edit&section=1 "Edit section: Parameters")] Parameters

arg  |  \-  |  pointer to a [time_t](time_t.html "c/chrono/time t") object where the time will be stored, or a null pointer   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/time&action=edit&section=2 "Edit section: Return value")] Return value

Current calendar time encoded as [time_t](time_t.html "c/chrono/time t") object on success, ([time_t](time_t.html))(-1) on error. If arg is not a null pointer, the return value is also stored in the object pointed to by arg. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/time&action=edit&section=3 "Edit section: Notes")] Notes

The encoding of calendar time in [time_t](time_t.html "c/chrono/time t") is unspecified, but most systems conform to [POSIX specification](https://pubs.opengroup.org/onlinepubs/9799919799/functions/time.html) and return a value of integral type holding the number of seconds since [the Epoch](https://pubs.opengroup.org/onlinepubs/9799919799/basedefs/V1_chap04.html#tag_04_15). Implementations in which [time_t](time_t.html "c/chrono/time t") is a 32-bit signed integer (many historical implementations) fail in the year [2038](https://en.wikipedia.org/wiki/Year_2038_problem "enwiki:Year 2038 problem"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/time&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdint.h>
    #include <stdio.h>
    #include <time.h>
     
    int main(void)
    {
        [time_t](time_t.html) result = time([NULL](../types/NULL.html));
        if (result != ([time_t](time_t.html))(-1))
            [printf](../io/fprintf.html)("The current time is %s(%jd seconds since the Epoch)\n",
                   [asctime](asctime.html)([gmtime](gmtime.html)(&result)), ([intmax_t](../types/integer.html))result);
    }

Possible output: 
    
    
    The current time is Fri Apr 24 15:05:25 2015
    (1429887925 seconds since the Epoch)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/time&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.27.2.4 The time function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.27.2.4 The time function (p: 286) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.27.2.4 The time function (p: 391) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.23.2.4 The time function (p: 341) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.12.2.4 The time function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/time&action=edit&section=6 "Edit section: See also")] See also

[ localtimelocaltime_rlocaltime_s](localtime.html "c/chrono/localtime")(C23)(C11) |  converts time since epoch to calendar time expressed as local time   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_localtime&action=edit)  
---|---  
[ gmtimegmtime_rgmtime_s](gmtime.html "c/chrono/gmtime")(C23)(C11) |  converts time since epoch to calendar time expressed as Coordinated Universal Time (UTC)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_gmtime&action=edit)  
[ timespec_get](timespec_get.html "c/chrono/timespec get")(C11) |  returns the calendar time in seconds and nanoseconds based on a given time base   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_timespec_get&action=edit)  
[C++ documentation](../../cpp/chrono/c/time.html "cpp/chrono/c/time") for time  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono/time&oldid=180264](https://en.cppreference.com/mwiki/index.php?title=c/chrono/time&oldid=180264)" 

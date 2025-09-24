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
**timespec_get**(C11)  
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
int timespec_get( struct timespec *ts, int base ); |  (1)  |  (since C11)  
#define TIME_UTC /* implementation-defined */ |  (2)  |  (since C11)  
| |   
  
1) Modifies the timespec object pointed to by ts to hold the current calendar time in the time base base.

2) Expands to a value suitable for use as the base argument of `timespec_get`

Other macro constants beginning with `TIME_` may be provided by the implementation to indicate additional time bases 

If base is `TIME_UTC`, then 

  * ts->tv_sec is set to the number of seconds since an implementation defined epoch, truncated to a whole value 
  * ts->tv_nsec member is set to the integral number of nanoseconds, rounded to the resolution of the system clock 



## Contents

  * [1 Parameters](timespec_get.html#Parameters)
  * [2 Return value](timespec_get.html#Return_value)
  * [3 Notes](timespec_get.html#Notes)
  * [4 Example](timespec_get.html#Example)
  * [5 References](timespec_get.html#References)
  * [6 See also](timespec_get.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_get&action=edit&section=1 "Edit section: Parameters")] Parameters

ts  |  \-  |  pointer to an object of type struct timespec  
---|---|---  
base  |  \-  |  `TIME_UTC` or another nonzero integer value indicating the time base   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_get&action=edit&section=2 "Edit section: Return value")] Return value

The value of base if successful, zero otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_get&action=edit&section=3 "Edit section: Notes")] Notes

The POSIX function [`clock_gettime(CLOCK_REALTIME, ts)`](https://pubs.opengroup.org/onlinepubs/9799919799/functions/clock_getres.html) may also be used to populate a `timespec` with the time since the Epoch. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_get&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <time.h>
     
    int main(void)
    {
        struct timespec ts;
        timespec_get(&ts, TIME_UTC);
        char buff[100];
        [strftime](strftime.html)(buff, sizeof buff, "%D %T", [gmtime](gmtime.html)(&ts.tv_sec));
        [printf](../io/fprintf.html)("Current time: %s.%09ld UTC\n", buff, ts.tv_nsec);
    }

Possible output: 
    
    
    Current time: 02/18/15 14:34:03.048508855 UTC

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_get&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.27.2.5 The timespec_get function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.27.2.5 The timespec_get function (p: 286) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.27.2.5 The timespec_get function (p: 390) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_get&action=edit&section=6 "Edit section: See also")] See also

[ timespec](timespec.html "c/chrono/timespec")(C11) |  time in seconds and nanoseconds   
(struct)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_timespec&action=edit)  
---|---  
[ timespec_getres](timespec_getres.html "c/chrono/timespec getres")(C23) |  returns the resolution of calendar time based on a given time base   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_timespec_getres&action=edit)  
[ time](time.html "c/chrono/time") |  returns the current calendar time of the system as time since epoch   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_time&action=edit)  
[C++ documentation](../../cpp/chrono/c/timespec_get.html "cpp/chrono/c/timespec get") for timespec_get  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_get&oldid=180263](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_get&oldid=180263)" 

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
**timespec_getres**(C23)  
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
int timespec_getres( struct timespec *ts, int base ); |  |  (since C23)  
| |   
  
If `ts` is non-null and `base` is supported by timespec_get, modifies *ts to hold the resolution of time provided by timespec_get for `base`. For each supported `base`, multiple calls to `timespec_getres` during the same program execution have identical results. 

## Contents

  * [1 Parameters](timespec_getres.html#Parameters)
  * [2 Return value](timespec_getres.html#Return_value)
  * [3 Notes](timespec_getres.html#Notes)
  * [4 Example](timespec_getres.html#Example)
  * [5 See also](timespec_getres.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_getres&action=edit&section=1 "Edit section: Parameters")] Parameters

ts  |  \-  |  pointer to an object of type struct timespec  
---|---|---  
base  |  \-  |  TIME_UTC or another nonzero integer value indicating the time base   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_getres&action=edit&section=2 "Edit section: Return value")] Return value

The value of `base` if `base` is supported, zero otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_getres&action=edit&section=3 "Edit section: Notes")] Notes

The POSIX function [`clock_getres(clock_id, ts)`](http://pubs.opengroup.org/onlinepubs/9699919799/functions/clock_getres.html) may also be used to populate a timespec with the resolution of time identified by `clock_id`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_getres&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <time.h>
     
    int main(void)
    {
        char buff[128];
        struct timespec ts;
        const int res = timespec_getres(&ts, TIME_UTC);
        if (res == TIME_UTC) {
            struct [tm](tm.html) timer;
            [strftime](strftime.html)(buff, sizeof buff, "%D %T", gmtime_r(&ts.tv_sec, &timer));
            [printf](../io/fprintf.html)("Time resolution info: %s.%09ld UTC\n", buff, ts.tv_nsec);
        } else {
            [printf](../io/fprintf.html)("TIME_UTC base is not supported.");
        }
    }

Possible output: 
    
    
    Time resolution info: 01/01/70 00:00:00.000000001 UTC

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_getres&action=edit&section=5 "Edit section: See also")] See also

[ timespec](timespec.html "c/chrono/timespec")(C11) |  time in seconds and nanoseconds   
(struct)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_timespec&action=edit)  
---|---  
[ timespec_get](timespec_get.html "c/chrono/timespec get")(C11) |  returns the calendar time in seconds and nanoseconds based on a given time base   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_timespec_get&action=edit)  
[ time](time.html "c/chrono/time") |  returns the current calendar time of the system as time since epoch   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_time&action=edit)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_getres&oldid=125006](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec_getres&oldid=125006)" 

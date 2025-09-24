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
[time_t](time_t.html "c/chrono/time t")  
[clock_t](clock_t.html "c/chrono/clock t")  
**timespec**(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/navbar_content&action=edit)

Defined in header `[`<time.h>`](../header/time.html "c/header/time")` |  |   
---|---|---  
struct timespec; |  |  (since C11)  
| |   
  
Structure holding an interval broken down into seconds and nanoseconds. 

## Contents

  * [1 Member objects](timespec.html#Member_objects)
  * [2 Notes](timespec.html#Notes)
  * [3 Example](timespec.html#Example)
  * [4 References](timespec.html#References)
  * [5 See also](timespec.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec&action=edit&section=1 "Edit section: Member objects")] Member objects

Member  |  Description   
---|---  
[time_t](time_t.html "c/chrono/time t") `tv_sec` |  whole seconds (valid values are >= ​0​)   
/* see below */ `tv_nsec` |  nanoseconds (valid values are `[`​0​`, `999999999`]`)   
The type of `tv_nsec` is long.  | (until C23)  
---|---  
The type of `tv_nsec` is an implementation-defined signed integer type that can represent integers in `[`​0​`, `999999999`]`.  | (since C23)  
  
The declaration order of `tv_sec` and `tv_nsec` is unspecified. Implementation may add other members to struct timespec. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec&action=edit&section=2 "Edit section: Notes")] Notes

The type of `tv_nsec` is long long on some platforms, which is conforming only since C23. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdint.h>
    #include <stdio.h>
    #include <time.h>
     
    int main(void)
    {
        struct timespec ts;
        timespec_get(&ts, TIME_UTC);
        char buff[100];
        [strftime](strftime.html)(buff, sizeof buff, "%D %T", [gmtime](gmtime.html)(&ts.tv_sec));
        [printf](../io/fprintf.html)("Current time: %s.%09ld UTC\n", buff, ts.tv_nsec);
        [printf](../io/fprintf.html)("Raw timespec.tv_sec: %jd\n", ([intmax_t](../types/integer.html))ts.tv_sec);
        [printf](../io/fprintf.html)("Raw timespec.tv_nsec: %09ld\n", ts.tv_nsec);
    }

Possible output: 
    
    
    Current time: 04/04/24 14:45:17.885909786 UTC
    Raw timespec.tv_sec: 1712241917
    Raw timespec.tv_nsec: 885909786

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.27.1/3 Components of time (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.27.1/3 Components of time (p: 284) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.27.1/3 Components of time (p: 388) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec&action=edit&section=5 "Edit section: See also")] See also

[ timespec_get](timespec_get.html "c/chrono/timespec get")(C11) |  returns the calendar time in seconds and nanoseconds based on a given time base   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_timespec_get&action=edit)  
---|---  
[ tm](tm.html "c/chrono/tm") |  calendar time type  
(struct)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_tm&action=edit)  
[C++ documentation](../../cpp/chrono/c/timespec.html "cpp/chrono/c/timespec") for timespec  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec&oldid=180251](https://en.cppreference.com/mwiki/index.php?title=c/chrono/timespec&oldid=180251)" 

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
**gmtime gmtime_rgmtime_s**(C23)(C11)  
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
struct [tm](tm.html)* gmtime ( const [time_t](time_t.html)* timer ); |  (1)  |   
struct [tm](tm.html)* gmtime_r( const [time_t](time_t.html)* timer, struct [tm](tm.html)* buf ); |  (2)  |  (since C23)  
struct [tm](tm.html)* gmtime_s( const [time_t](time_t.html)* restrict timer, struct [tm](tm.html)* restrict buf ); |  (3)  |  (since C11)  
| |   
  
1) Converts given time since epoch (a [time_t](time_t.html "c/chrono/time t") value pointed to by timer) into calendar time, expressed in Coordinated Universal Time (UTC) in the [`struct tm`](tm.html "c/chrono/tm") format. The result is stored in static storage and a pointer to that static storage is returned.

2) Same as (1), except that the function uses user-provided storage buf for the result.

3) Same as (1), except that the function uses user-provided storage buf for the result and that the following errors are detected at runtime and call the currently installed [constraint handler](../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * timer or buf is a null pointer 


    As with all bounds-checked functions, `gmtime_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<time.h>`](../header/time.html "c/header/time").

## Contents

  * [1 Parameters](gmtime.html#Parameters)
  * [2 Return value](gmtime.html#Return_value)
  * [3 Notes](gmtime.html#Notes)
  * [4 Example](gmtime.html#Example)
  * [5 References](gmtime.html#References)
  * [6 See also](gmtime.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/gmtime&action=edit&section=1 "Edit section: Parameters")] Parameters

timer  |  \-  |  pointer to a [time_t](time_t.html "c/chrono/time t") object to convert   
---|---|---  
buf  |  \-  |  pointer to a struct [tm](tm.html) object to store the result   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/gmtime&action=edit&section=2 "Edit section: Return value")] Return value

1) pointer to a static internal [tm](tm.html "c/chrono/tm") object on success, or null pointer otherwise. The structure may be shared between `gmtime`, [localtime](localtime.html "c/chrono/localtime"), and [ctime](ctime.html "c/chrono/ctime") and may be overwritten on each invocation.

2,3) copy of the buf pointer, or null pointer on error (which may be a runtime constraint violation or a failure to convert the specified time to UTC).

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/gmtime&action=edit&section=3 "Edit section: Notes")] Notes

`gmtime` may not be thread-safe. 

POSIX requires that [`gmtime`](https://pubs.opengroup.org/onlinepubs/9799919799/functions/gmtime.html) and [`gmtime_r`](https://pubs.opengroup.org/onlinepubs/9799919799/functions/gmtime_r.html) set [errno](../error/errno.html "c/error/errno") to [EOVERFLOW](../error/errno_macros.html) if they fail because the argument is too large. 

The implementation of `gmtime_s` in [Microsoft CRT](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/gmtime-s-gmtime32-s-gmtime64-s?view=vs-2019) is incompatible with the C standard since it has reversed parameter order. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/gmtime&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #define __STDC_WANT_LIB_EXT1__ 1
    #define _XOPEN_SOURCE // for putenv
    #include <stdio.h>
    #include <stdlib.h>   // for putenv
    #include <time.h>
     
    int main(void)
    {
        [time_t](time_t.html) t = [time](time.html)([NULL](../types/NULL.html));
        [printf](../io/fprintf.html)("UTC:       %s", [asctime](asctime.html)(gmtime(&t)));
        [printf](../io/fprintf.html)("local:     %s", [asctime](asctime.html)([localtime](localtime.html)(&t)));
        // POSIX-specific
        putenv("TZ=Asia/Singapore");
        [printf](../io/fprintf.html)("Singapore: %s", [asctime](asctime.html)([localtime](localtime.html)(&t)));
     
    #ifdef __STDC_LIB_EXT1__
        struct [tm](tm.html) buf;
        char str[26];
        asctime_s(str, sizeof str, gmtime_s(&t, &buf));
        [printf](../io/fprintf.html)("UTC:       %s", str);
        asctime_s(str, sizeof str, localtime_s(&t, &buf));
        [printf](../io/fprintf.html)("local:     %s", str);
    #endif
    }

Possible output: 
    
    
    UTC:       Fri Sep 15 14:22:05 2017
    local:     Fri Sep 15 14:22:05 2017
    Singapore: Fri Sep 15 22:22:05 2017
    UTC:       Fri Sep 15 14:22:05 2017
    local:     Fri Sep 15 14:22:05 2017

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/gmtime&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.27.3.3 The gmtime function (p: TBD) 



    

  * K.3.8.2.3 The gmtime_s function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.27.3.3 The gmtime function (p: 288) 



    

  * K.3.8.2.3 The gmtime_s function (p: 454-455) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.27.3.3 The gmtime function (p: 393-394) 



    

  * K.3.8.2.3 The gmtime_s function (p: 626-627) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.23.3.3 The gmtime function (p: 343) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.12.3.3 The gmtime function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/gmtime&action=edit&section=6 "Edit section: See also")] See also

[ localtimelocaltime_rlocaltime_s](localtime.html "c/chrono/localtime")(C23)(C11) |  converts time since epoch to calendar time expressed as local time   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_localtime&action=edit)  
---|---  
[C++ documentation](../../cpp/chrono/c/gmtime.html "cpp/chrono/c/gmtime") for gmtime  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono/gmtime&oldid=183128](https://en.cppreference.com/mwiki/index.php?title=c/chrono/gmtime&oldid=183128)" 

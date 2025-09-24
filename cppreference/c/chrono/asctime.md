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
**asctime asctime_s**(deprecated in C23)(C11)  
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
| (1) |   
char* asctime( const struct [tm](tm.html)* time_ptr ); |  | (until C23)  
[[deprecated]] char* asctime( const struct [tm](tm.html)* time_ptr ); |  |  (since C23)  
errno_t asctime_s( char* buf, rsize_t bufsz, const struct [tm](tm.html)* time_ptr ); |  (2)  |  (since C11)  
| |   
  
1) Converts given calendar time [tm](tm.html "c/chrono/tm") to a textual representation of the following fixed 25-character form: Www Mmm dd hh:mm:ss yyyy\n

  * `Www` \- three-letter English abbreviated day of the week from time_ptr->tm_wday, one of `Mon`, `Tue`, `Wed`, `Thu`, `Fri`, `Sat`, `Sun`. 
  * `Mmm` \- three-letter English abbreviated month name from time_ptr->tm_mon, one of `Jan`, `Feb`, `Mar`, `Apr`, `May`, `Jun`, `Jul`, `Aug`, `Sep`, `Oct`, `Nov`, `Dec`. 
  * `dd` \- 2-digit day of the month from timeptr->tm_mday as if printed by [sprintf](../io/fprintf.html "c/io/fprintf") using %2d. 
  * `hh` \- 2-digit hour from timeptr->tm_hour as if printed by [sprintf](../io/fprintf.html "c/io/fprintf") using %.2d. 
  * `mm` \- 2-digit minute from timeptr->tm_min as if printed by [sprintf](../io/fprintf.html "c/io/fprintf") using %.2d. 
  * `ss` \- 2-digit second from timeptr->tm_sec as if printed by [sprintf](../io/fprintf.html "c/io/fprintf") using %.2d. 
  * `yyyy` \- 4-digit year from timeptr->tm_year + 1900 as if printed by [sprintf](../io/fprintf.html "c/io/fprintf") using %4d.



The behavior is undefined if any member of *time_ptr is outside its normal range.

The behavior is undefined if the calendar year indicated by time_ptr->tm_year has more than 4 digits or is less than the year 1000.

The function does not support localization, and the newline character cannot be removed.

The function modifies static storage and is not thread-safe.

This function is deprecated and should not be used in new code. | (since C23)  
---|---  
  
2) Same as (1), except that the message is written into user-provided storage buf, which is guaranteed to be null-terminated, and the following errors are detected at runtime and call the currently installed [constraint handler](../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * buf or time_ptr is a null pointer 
  * bufsz is less than 26 or greater than RSIZE_MAX
  * not all members of *time_ptr are within their normal ranges 
  * the year indicated by time_ptr->tm_year is less than 0 or greater than 9999. 


    As with all bounds-checked functions, `asctime_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<time.h>`](../header/time.html "c/header/time").

## Contents

  * [1 Parameters](asctime.html#Parameters)
  * [2 Return value](asctime.html#Return_value)
  * [3 Notes](asctime.html#Notes)
  * [4 Example](asctime.html#Example)
  * [5 References](asctime.html#References)
  * [6 See also](asctime.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/asctime&action=edit&section=1 "Edit section: Parameters")] Parameters

time_ptr  |  \-  |  pointer to a [tm](tm.html "c/chrono/tm") object specifying the time to print   
---|---|---  
buf  |  \-  |  pointer to a user-supplied buffer at least 26 bytes in length   
bufsz  |  \-  |  size of the user-supplied buffer   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/asctime&action=edit&section=2 "Edit section: Return value")] Return value

1) pointer to a static null-terminated character string holding the textual representation of date and time as described above. The string may be shared between `asctime` and [ctime](ctime.html "c/chrono/ctime"), and may be overwritten on each invocation of any of those functions.

2) zero on success, non-zero on failure, in which case buf[0] is set to zero (unless buf is a null pointer or bufsz is zero or greater than RSIZE_MAX).

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/asctime&action=edit&section=3 "Edit section: Notes")] Notes

`asctime` returns a pointer to static data and is not thread-safe. POSIX marks this function obsolete and recommends [strftime](strftime.html "c/chrono/strftime") instead. The C standard also recommends [strftime](strftime.html "c/chrono/strftime") instead of `asctime` and `asctime_s` because `strftime` is more flexible and locale-sensitive. 

POSIX limits undefined behaviors only to when the output string would be longer than 25 characters, when timeptr->tm_wday or timeptr->tm_mon are not within the expected ranges, or when timeptr->tm_year exceeds [INT_MAX](../types/limits.html) - 1990. 

Some implementations handle timeptr->tm_mday == 0 as meaning the last day of the preceding month. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/asctime&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #define __STDC_WANT_LIB_EXT1__ 1
    #include <stdio.h>
    #include <time.h>
     
    int main(void)
    {
        struct [tm](tm.html) [tm](tm.html) = *[localtime](localtime.html)(&([time_t](time_t.html)){[time](time.html)([NULL](../types/NULL.html))});
        [printf](../io/fprintf.html)("%s", asctime(&[tm](tm.html))); // note implicit trailing '\n'
     
    #ifdef __STDC_LIB_EXT1__
        char str[26];
        asctime_s(str, sizeof str, &[tm](tm.html));
        [printf](../io/fprintf.html)("%s", str);
    #endif
    }

Possible output: 
    
    
    Tue May 26 21:51:50 2015
    Tue May 26 21:51:50 2015

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/asctime&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.27.2.1 The asctime function (p: 287) 



    

  * K.3.8.2.1 The asctime_s function (p: 453-454) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.27.2.1 The asctime function (p: 392-393) 



    

  * K.3.8.2.1 The asctime_s function (p: 624-625) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.23.3.1 The asctime function (p: 341-342) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.12.3.1 The asctime function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/asctime&action=edit&section=6 "Edit section: See also")] See also

[ ctimectime_s](ctime.html "c/chrono/ctime")(deprecated in C23)(C11) |  converts a [time_t](time_t.html "c/chrono/time t") object to a textual representation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_ctime&action=edit)  
---|---  
[ strftime](strftime.html "c/chrono/strftime") |  converts a [tm](tm.html "c/chrono/tm") object to custom textual representation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_strftime&action=edit)  
[C++ documentation](../../cpp/chrono/c/asctime.html "cpp/chrono/c/asctime") for asctime  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono/asctime&oldid=172468](https://en.cppreference.com/mwiki/index.php?title=c/chrono/asctime&oldid=172468)" 

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
**ctime ctime_s**(deprecated in C23)(C11)  
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
char* ctime( const [time_t](time_t.html)* timer ); |  | (until C23)  
[[deprecated]] char* ctime( const [time_t](time_t.html)* timer ); |  |  (since C23)  
errno_t ctime_s( char *buf, rsize_t bufsz, const [time_t](time_t.html)* timer ); |  (2)  |  (since C11)  
| |   
  
1) Converts given time since epoch to a calendar local time and then to a textual representation, as if by calling [asctime](asctime.html)([localtime](localtime.html)(timer)) or [asctime](asctime.html)(localtime_r(timer, &(struct [tm](tm.html)){0}))(since C23). This function is deprecated and should not be used in new code.(since C23)

2) Same as (1), except that the function is equivalent to asctime_s(buf, bufsz, localtime_s(timer, &(struct [tm](tm.html)){0})), and the following errors are detected at runtime and call the currently installed [constraint handler](../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * `buf` or `timer` is a null pointer 
  * `bufsz` is less than 26 or greater than RSIZE_MAX


    As with all bounds-checked functions, `ctime_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<time.h>`](../header/time.html "c/header/time").

The resulting string has the following format: 
    
    
    Www Mmm dd hh:mm:ss yyyy\n

  * `Www` \- the day of the week (one of `Mon`, `Tue`, `Wed`, `Thu`, `Fri`, `Sat`, `Sun`). 
  * `Mmm` \- the month (one of `Jan`, `Feb`, `Mar`, `Apr`, `May`, `Jun`, `Jul`, `Aug`, `Sep`, `Oct`, `Nov`, `Dec`). 
  * `dd` \- the day of the month 
  * `hh` \- hours 
  * `mm` \- minutes 
  * `ss` \- seconds 
  * `yyyy` \- years 



The function does not support localization. 

## Contents

  * [1 Parameters](ctime.html#Parameters)
  * [2 Return value](ctime.html#Return_value)
  * [3 Notes](ctime.html#Notes)
  * [4 Example](ctime.html#Example)
  * [5 References](ctime.html#References)
  * [6 See also](ctime.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/ctime&action=edit&section=1 "Edit section: Parameters")] Parameters

timer  |  \-  |  pointer to a [time_t](time_t.html "c/chrono/time t") object specifying the time to print   
---|---|---  
buf  |  \-  |  pointer to the first element of a char array of size at least `bufsz`  
bufsz  |  \-  |  max number of bytes to output, typically the size of the buffer pointed to by `buf`  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/ctime&action=edit&section=2 "Edit section: Return value")] Return value

1) pointer to a static null-terminated character string holding the textual representation of date and time. The string may be shared between [asctime](asctime.html "c/chrono/asctime") and `ctime`, and may be overwritten on each invocation of any of those functions.

2) zero on success (in which case the string representation of time has been written out to the array pointed to by `buf`), or non-zero on failure (in which case, the terminating null character is always written to buf[0] unless `buf` is a null pointer or `bufsz` is zero or greater than RSIZE_MAX.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/ctime&action=edit&section=3 "Edit section: Notes")] Notes

`ctime` returns a pointer to static data and is not thread-safe. In addition, it modifies the static [tm](tm.html "c/chrono/tm") object which may be shared with [gmtime](gmtime.html "c/chrono/gmtime") and [localtime](localtime.html "c/chrono/localtime"). POSIX marks this function obsolete and recommends [strftime](strftime.html "c/chrono/strftime") instead. The C standard also recommends [strftime](strftime.html "c/chrono/strftime") instead of `ctime` and `ctime_s` because `strftime` is more flexible and locale-sensitive. 

The behavior of `ctime` is undefined for the values of [time_t](time_t.html "c/chrono/time t") that result in the string longer than 25 characters (e.g. year 10000). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/ctime&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #define __STDC_WANT_LIB_EXT1__ 1
    #include <time.h>
    #include <stdio.h>
     
    int main(void)
    {
        [time_t](time_t.html) result = [time](time.html)([NULL](../types/NULL.html));
        [printf](../io/fprintf.html)("%s", ctime(&result));
     
    #ifdef __STDC_LIB_EXT1__
        char str[26];
        ctime_s(str,sizeof str,&result);
        [printf](../io/fprintf.html)("%s", str);
    #endif
    }

Possible output: 
    
    
    Tue May 26 21:51:03 2015
    Tue May 26 21:51:03 2015

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/ctime&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.27.3.2 The ctime function (p: 287-288) 



    

  * K.3.8.2.2 The ctime_s function (p: 454) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.27.3.2 The ctime function (p: 393) 



    

  * K.3.8.2.2 The ctime_s function (p: 626) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.23.3.2 The ctime function (p: 342) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.12.3.2 The ctime function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/ctime&action=edit&section=6 "Edit section: See also")] See also

[ asctimeasctime_s](asctime.html "c/chrono/asctime")(deprecated in C23)(C11) |  converts a [tm](tm.html "c/chrono/tm") object to a textual representation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_asctime&action=edit)  
---|---  
[ strftime](strftime.html "c/chrono/strftime") |  converts a [tm](tm.html "c/chrono/tm") object to custom textual representation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_strftime&action=edit)  
[C++ documentation](../../cpp/chrono/c/ctime.html "cpp/chrono/c/ctime") for ctime  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono/ctime&oldid=142715](https://en.cppreference.com/mwiki/index.php?title=c/chrono/ctime&oldid=142715)" 

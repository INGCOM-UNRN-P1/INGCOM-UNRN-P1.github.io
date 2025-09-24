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
**difftime**  
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
[timespec](timespec.html "c/chrono/timespec")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/navbar_content&action=edit)

Defined in header `[`<time.h>`](../header/time.html "c/header/time")` |  |   
---|---|---  
double difftime( [time_t](time_t.html) time_end, [time_t](time_t.html) time_beg ); |  |   
| |   
  
Computes difference between two calendar times as [time_t](time_t.html "c/chrono/time t") objects (time_end - time_beg) in seconds. If `time_end` refers to time point before `time_beg` then the result is negative. 

## Contents

  * [1 Parameters](difftime.html#Parameters)
  * [2 Return value](difftime.html#Return_value)
  * [3 Notes](difftime.html#Notes)
  * [4 Example](difftime.html#Example)
  * [5 References](difftime.html#References)
  * [6 See also](difftime.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/difftime&action=edit&section=1 "Edit section: Parameters")] Parameters

time_beg, time_end  |  \-  |  times to compare   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/difftime&action=edit&section=2 "Edit section: Return value")] Return value

Difference between two times in seconds. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/difftime&action=edit&section=3 "Edit section: Notes")] Notes

On POSIX systems, [time_t](time_t.html "c/chrono/time t") is measured in seconds, and `difftime` is equivalent to arithmetic subtraction, but C and C++ allow fractional units for [time_t](time_t.html "c/chrono/time t"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/difftime&action=edit&section=4 "Edit section: Example")] Example

The following program computes the number of seconds that have passed since the beginning of the month.

Run this code
    
    
    #include <stdio.h>
    #include <time.h>
     
    int main(void)
    {
        [time_t](time_t.html) now = [time](time.html)(0);
     
        struct [tm](tm.html) beg = *[localtime](localtime.html)(&now);
     
        // set beg to the beginning of the month
        beg.tm_hour = 0,
        beg.tm_min = 0,
        beg.tm_sec = 0,
        beg.tm_mday = 1;
     
        double seconds = difftime(now, [mktime](mktime.html)(&beg));
     
        [printf](../io/fprintf.html)("%.f seconds have passed since the beginning of the month.\n", seconds);
     
        return 0;
    }

Output: 
    
    
    1937968 seconds have passed since the beginning of the month.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/difftime&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.27.2.2 The difftime function (p: 285) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.27.2.2 The difftime function (p: 390) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.23.2.2 The difftime function (p: 338) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 7.12.2.2 The difftime function (p: 171) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/difftime&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/chrono/c/difftime.html "cpp/chrono/c/difftime") for difftime  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono/difftime&oldid=144873](https://en.cppreference.com/mwiki/index.php?title=c/chrono/difftime&oldid=144873)" 

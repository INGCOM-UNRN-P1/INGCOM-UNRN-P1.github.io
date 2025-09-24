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
**clock_t**  
[timespec](timespec.html "c/chrono/timespec")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/navbar_content&action=edit)

Defined in header `[`<time.h>`](../header/time.html "c/header/time")` |  |   
---|---|---  
typedef /* unspecified */ clock_t; |  |   
| |   
  
Arithmetic(until C11)Real(since C11) type capable of representing the processor time used by a process. It has implementation-defined range and precision. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/clock_t&action=edit&section=1 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <time.h>
    #include <math.h>
     
    volatile double sink;
    int main (void)
    {
      clock_t start = [clock](clock.html)();
     
      for([size_t](../types/size_t.html) i=0; i<3141592; ++i)
          sink+=[sin](../numeric/math/sin.html)(i);
     
      clock_t end = [clock](clock.html)();
      double cpu_time_used = ((double) (end - start)) / [CLOCKS_PER_SEC](CLOCKS_PER_SEC.html);
     
      [printf](../io/fprintf.html)("for loop took %f seconds to execute \n", cpu_time_used);
    }

Possible output: 
    
    
    for loop took 0.271828 seconds to execute

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/clock_t&action=edit&section=2 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.27.1/3 Components of time (p: 284) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.27.1/3 Components of time (p: 388) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.23.1/3 Components of time (p: 338) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.12.1 Components of time 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/clock_t&action=edit&section=3 "Edit section: See also")] See also

[ clock](clock.html "c/chrono/clock") |  returns raw processor clock time since the program is started   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_clock&action=edit)  
---|---  
[ CLOCKS_PER_SEC](CLOCKS_PER_SEC.html "c/chrono/CLOCKS PER SEC") |  number of processor clock ticks per second   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_CLOCKS_PER_SEC&action=edit)  
[C++ documentation](../../cpp/chrono/c/clock_t.html "cpp/chrono/c/clock t") for clock_t  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono/clock_t&oldid=135526](https://en.cppreference.com/mwiki/index.php?title=c/chrono/clock_t&oldid=135526)" 

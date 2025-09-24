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
**clock**  
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
[clock_t](clock_t.html) clock(void); |  |   
| |   
  
Returns the approximate processor time used by the process since the beginning of an implementation-defined era related to the program's execution. To convert result value to seconds, divide it by [CLOCKS_PER_SEC](CLOCKS_PER_SEC.html "c/chrono/CLOCKS PER SEC"). 

Only the difference between two values returned by different calls to `clock` is meaningful, as the beginning of the `clock` era does not have to coincide with the start of the program. 

`clock` time may advance faster or slower than the wall clock, depending on the execution resources given to the program by the operating system. For example, if the CPU is shared by other processes, `clock` time may advance slower than wall clock. On the other hand, if the current process is multithreaded and more than one execution core is available, `clock` time may advance faster than wall clock. 

## Contents

  * [1 Return value](clock.html#Return_value)
  * [2 Notes](clock.html#Notes)
  * [3 Example](clock.html#Example)
  * [4 References](clock.html#References)
  * [5 See also](clock.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/clock&action=edit&section=1 "Edit section: Return value")] Return value

Processor time used by the program so far. 

  * If the processor time used is not available, returns ([clock_t](clock_t.html))(-1). 
  * If the value of the processor time used cannot be represented by [clock_t](clock_t.html "c/chrono/clock t"), returns an unspecified value. 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/clock&action=edit&section=2 "Edit section: Notes")] Notes

On POSIX-compatible systems, [`clock_gettime`](http://pubs.opengroup.org/onlinepubs/9699919799/functions/clock_getres.html) with clock id CLOCK_PROCESS_CPUTIME_ID offers better resolution. 

The value returned by `clock()` may wrap around on some implementations. For example, on such an implementation, if [clock_t](clock_t.html "c/chrono/clock t") is a signed 32-bit integer and [CLOCKS_PER_SEC](CLOCKS_PER_SEC.html "c/chrono/CLOCKS PER SEC") is 1000000, it will wrap after about 2147 seconds (about 36 minutes). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/clock&action=edit&section=3 "Edit section: Example")] Example

This example demonstrates the difference between `clock()` time and real time.

Run this code
    
    
    #ifndef __STDC_NO_THREADS__
        #include <threads.h>
    #else
        // POSIX alternative
        #define _POSIX_C_SOURCE 199309L
        #include <pthread.h>
    #endif
     
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
     
    // the function f() does some time-consuming work
    int f(void* thr_data) // return void* in POSIX
    {
        (void) thr_data;
        volatile double d = 0;
        for (int n = 0; n < 10000; ++n)
           for (int m = 0; m < 10000; ++m)
               d += d * n * m;
        return 0;
    }
     
    int main(void)
    {
        struct timespec ts1, tw1; // both C11 and POSIX
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts1); // POSIX
        clock_gettime(CLOCK_MONOTONIC, &tw1); // POSIX; use timespec_get in C11
        [clock_t](clock_t.html) t1 = clock();
     
    #ifndef __STDC_NO_THREADS__
        [thrd_t](../thread.html) thr1, thr2;  // C11; use pthread_t in POSIX
        [thrd_create](../thread/thrd_create.html)(&thr1, f, [NULL](../types/NULL.html)); // C11; use pthread_create in POSIX
        [thrd_create](../thread/thrd_create.html)(&thr2, f, [NULL](../types/NULL.html));
        [thrd_join](../thread/thrd_join.html)(thr1, [NULL](../types/NULL.html)); // C11; use pthread_join in POSIX
        [thrd_join](../thread/thrd_join.html)(thr2, [NULL](../types/NULL.html));
    #endif
     
        struct timespec ts2, tw2;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts2);
        clock_gettime(CLOCK_MONOTONIC, &tw2);
        [clock_t](clock_t.html) t2 = clock();
     
        double dur = 1000.0 * (t2 - t1) / [CLOCKS_PER_SEC](CLOCKS_PER_SEC.html);
        double posix_dur = 1000.0 * ts2.tv_sec + 1e-6 * ts2.tv_nsec
                               - (1000.0 * ts1.tv_sec + 1e-6 * ts1.tv_nsec);
        double posix_wall = 1000.0 * tw2.tv_sec + 1e-6 * tw2.tv_nsec
                                - (1000.0 * tw1.tv_sec + 1e-6 * tw1.tv_nsec);
     
        [printf](../io/fprintf.html)("CPU time used (per clock()): %.2f ms\n", dur);
        [printf](../io/fprintf.html)("CPU time used (per clock_gettime()): %.2f ms\n", posix_dur);
        [printf](../io/fprintf.html)("Wall time passed: %.2f ms\n", posix_wall);
    }

Possible output: 
    
    
    CPU time used (per clock()): 1580.00 ms
    CPU time used (per clock_gettime()): 1582.76 ms
    Wall time passed: 792.13 ms

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/clock&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.27.2.1 The clock function (p: 285) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.27.2.1 The clock function (p: 389) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.23.2.1 The clock function (p: 339) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.12.2.1 The clock function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/chrono/clock&action=edit&section=5 "Edit section: See also")] See also

[ ctimectime_s](ctime.html "c/chrono/ctime")(deprecated in C23)(C11) |  converts a [time_t](time_t.html "c/chrono/time t") object to a textual representation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_ctime&action=edit)  
---|---  
[ time](time.html "c/chrono/time") |  returns the current calendar time of the system as time since epoch   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/chrono/dsc_time&action=edit)  
[C++ documentation](../../cpp/chrono/c/clock.html "cpp/chrono/c/clock") for clock  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/chrono/clock&oldid=180116](https://en.cppreference.com/mwiki/index.php?title=c/chrono/clock&oldid=180116)" 

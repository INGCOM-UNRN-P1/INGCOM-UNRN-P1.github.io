From cppreference.com

< [c](../../c.html "c")‎ | [program](../program.html "c/program")

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

[ Program support utilities](../program.html "c/program")

Program termination  
---  
| [abort](abort.html "c/program/abort")  
---  
[exit](exit.html "c/program/exit")  
[quick_exit](quick_exit.html "c/program/quick exit")(C11)  
[_Exit](_Exit.html "c/program/ Exit")(C99)  
  
| [atexit](atexit.html "c/program/atexit")  
---  
[at_quick_exit](at_quick_exit.html "c/program/at quick exit")(C11)  
[EXIT_SUCCESSEXIT_FAILURE](EXIT_status.html "c/program/EXIT status")  
  
Unreachable control flow  
[unreachable](unreachable.html "c/program/unreachable")(C23)  
Communicating with the environment  
| [getenvgetenv_s](getenv.html "c/program/getenv")(C11)  
---  
  
| [system](system.html "c/program/system")  
---  
  
  
  
Memory alignment query  
[memalignment](memalignment.html "c/program/memalignment")(C23)  
Signals  
| **signal**  
---  
[raise](raise.html "c/program/raise")  
[sig_atomic_t](sig_atomic_t.html "c/program/sig atomic t")  
  
| [SIG_DFLSIG_IGN](SIG_strategies.html "c/program/SIG strategies")  
---  
[SIG_ERR](SIG_ERR.html "c/program/SIG ERR")  
  
Signal types  
| [SIGABRTSIGFPESIGILL](SIG_types.html "c/program/SIG types")  
---  
  
| [SIGINTSIGSEGVSIGTERM](SIG_types.html "c/program/SIG types")  
---  
  
Non-local jumps  
| [setjmp](setjmp.html "c/program/setjmp")  
---  
  
| [longjmp](longjmp.html "c/program/longjmp")  
---  
  
Types  
[jmp_buf](jmp_buf.html "c/program/jmp buf")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/navbar_content&action=edit)

Defined in header `[`<signal.h>`](../header/signal.html "c/header/signal")` |  |   
---|---|---  
void (*signal( int sig, void (*handler) (int))) (int); |  |   
| |   
  
Sets the error handler for signal `sig`. The signal handler can be set so that default handling will occur, signal is ignored, or a user-defined function is called. 

When signal handler is set to a function and a signal occurs, it is implementation defined whether signal(sig, [SIG_DFL](SIG_strategies.html)) will be executed immediately before the start of signal handler. Also, the implementation can prevent some implementation-defined set of signals from occurring while the signal handler runs. 

## Contents

  * [1 Parameters](signal.html#Parameters)
  * [2 Return value](signal.html#Return_value)
  * [3 Signal handler](signal.html#Signal_handler)
  * [4 Notes](signal.html#Notes)
  * [5 Example](signal.html#Example)
  * [6 References](signal.html#References)
  * [7 See also](signal.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/signal&action=edit&section=1 "Edit section: Parameters")] Parameters

sig  |  \-  |  the signal to set the signal handler to. It can be an implementation-defined value or one of the following values:  |  [ SIGABRTSIGFPESIGILLSIGINTSIGSEGVSIGTERM](SIG_types.html "c/program/SIG types") |  defines signal types   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_SIG_types&action=edit)  
---|---  
handler  |  \-  |  the signal handler. This must be one of the following: 

  * [SIG_DFL](SIG_strategies.html "c/program/SIG strategies") macro. The signal handler is set to default signal handler. 
  * [SIG_IGN](SIG_strategies.html "c/program/SIG strategies") macro. The signal is ignored. 
  * pointer to a function. The signature of the function must be equivalent to the following: 

|  void fun(int sig); |  |   
---|---|---  
| |   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/signal&action=edit&section=2 "Edit section: Return value")] Return value

Previous signal handler on success or [SIG_ERR](SIG_ERR.html "c/program/SIG ERR") on failure (setting a signal handler can be disabled on some implementations). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/signal&action=edit&section=3 "Edit section: Signal handler")] Signal handler

The following limitations are imposed on the user-defined function that is installed as a signal handler. 

If the user defined function returns when handling [SIGFPE](SIG_types.html "c/program/SIG types"), [SIGILL](SIG_types.html "c/program/SIG types") or [SIGSEGV](SIG_types.html "c/program/SIG types"), the behavior is undefined. 

If the signal handler is called as a result of [abort](abort.html "c/program/abort") or [raise](raise.html "c/program/raise"), the behavior is undefined if the signal handler calls [raise](raise.html "c/program/raise"). 

If the signal handler is called NOT as a result of [abort](abort.html "c/program/abort") or [raise](raise.html "c/program/raise") (in other words, the signal handler is _asynchronous_), the behavior is undefined if 

  * the signal handler calls any function within the standard library, except 



    

  * [abort](abort.html "c/program/abort")
  * [_Exit](_Exit.html "c/program/ Exit")
  * [quick_exit](quick_exit.html "c/program/quick exit")
  * `signal` with the first argument being the number of the signal currently handled (async handler can re-register itself, but not other signals). 
  * atomic functions from [`<stdatomic.h>`](../thread.html#Atomic_operations "c/thread") if the atomic arguments are lock-free 
  * [atomic_is_lock_free](../atomic/atomic_is_lock_free.html "c/atomic/atomic is lock free") (with any kind of atomic arguments) 



  * the signal handler refers to any object with static or thread-local(since C11) [storage duration](../language/storage_class_specifiers.html "c/language/storage duration") that is not a lock-free [atomic](../language/atomic.html "c/language/atomic")(since C11) other than by assigning to a static volatile [sig_atomic_t](sig_atomic_t.html). 



On entry to the signal handler, the state of the floating-point environment and the values of all objects is unspecified, except for 

  * objects of type volatile [sig_atomic_t](sig_atomic_t.html)
  * objects of lock-free atomic types (since C11)
  * side effects made visible through [atomic_signal_fence](../atomic/atomic_signal_fence.html "c/atomic/atomic signal fence") (since C11)



On return from a signal handler, the value of any object modified by the signal handler that is not volatile [sig_atomic_t](sig_atomic_t.html) or lock-free atomic(since C11) is undefined. 

The behavior is undefined if signal is used in a multithreaded program. It is not required to be thread-safe. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/signal&action=edit&section=4 "Edit section: Notes")] Notes

POSIX requires that `signal` is thread-safe, and [specifies a list of async-signal-safe library functions](http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_04) that may be called from any signal handler. 

Besides `abort` and `raise`, POSIX specifies that `kill`, `pthread_kill`, and `sigqueue` generate synchronous signals. 

POSIX recommends [`sigaction`](http://pubs.opengroup.org/onlinepubs/9699919799/functions/sigaction.html) instead of `signal`, due to its underspecified behavior and significant implementation variations, regarding signal delivery while a signal handler is executed. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/signal&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <signal.h>
    #include <stdio.h>
     
    volatile [sig_atomic_t](sig_atomic_t.html) gSignalStatus;
     
    void signal_handler(int signal)
    {
      gSignalStatus = signal;
    }
     
    int main(void)
    {
      signal([SIGINT](SIG_types.html), signal_handler);
     
      [printf](../io/fprintf.html)("SignalValue: %d\n", gSignalStatus);
      [printf](../io/fprintf.html)("Sending signal: %d\n", [SIGINT](SIG_types.html));
      [raise](raise.html)([SIGINT](SIG_types.html));
      [printf](../io/fprintf.html)("SignalValue: %d\n", gSignalStatus);
    }

Output: 
    
    
    SignalValue: 0
    Sending signal: 2
    SignalValue: 2

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/signal&action=edit&section=6 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.14.1.1 The signal function (p: 193-194) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.14.1.1 The signal function (p: 266-267) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.14.1.1 The signal function (p: 247-248) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.7.1.1 The signal function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/signal&action=edit&section=7 "Edit section: See also")] See also

[ raise](raise.html "c/program/raise") |  runs the signal handler for particular signal   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_raise&action=edit)  
---|---  
[C++ documentation](../../cpp/utility/program/signal.html "cpp/utility/program/signal") for signal  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/signal&oldid=140330](https://en.cppreference.com/mwiki/index.php?title=c/program/signal&oldid=140330)" 

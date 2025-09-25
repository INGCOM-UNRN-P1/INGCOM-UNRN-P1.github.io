From cppreference.com

< [c](../../c.html "c")‎ | [thread](../thread.html "c/thread")

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

[ Concurrency support library](../thread.html "c/thread")

|  Threads  
---  
| [thrd_create](thrd_create.html "c/thread/thrd create")  
---  
[thrd_equal](thrd_equal.html "c/thread/thrd equal")  
[thrd_current](thrd_current.html "c/thread/thrd current")  
[thrd_sleep](thrd_sleep.html "c/thread/thrd sleep")  
[thrd_yield](thrd_yield.html "c/thread/thrd yield")  
[thrd_exit](thrd_exit.html "c/thread/thrd exit")  
  
| [thrd_detach](thrd_detach.html "c/thread/thrd detach")  
---  
[thrd_join](thrd_join.html "c/thread/thrd join")  
[thrd_successthrd_timedoutthrd_busythrd_nomemthrd_error](thrd_errors.html "c/thread/thrd errors")  
  
Atomic operations  
[atomic_init](../atomic/atomic_init.html "c/atomic/atomic init")  
[ATOMIC_VAR_INIT](../atomic/ATOMIC_VAR_INIT.html "c/atomic/ATOMIC VAR INIT")(until C23)  
[ATOMIC_***_LOCK_FREE](../atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts")  
[atomic_is_lock_free](../atomic/atomic_is_lock_free.html "c/atomic/atomic is lock free")  
[atomic_store](../atomic/atomic_store.html "c/atomic/atomic store")  
[atomic_load](../atomic/atomic_load.html "c/atomic/atomic load")  
[atomic_exchange](../atomic/atomic_exchange.html "c/atomic/atomic exchange")  
[atomic_compare_exchange](../atomic/atomic_compare_exchange.html "c/atomic/atomic compare exchange")  
[atomic_fetch_add](../atomic/atomic_fetch_add.html "c/atomic/atomic fetch add")  
[atomic_fetch_sub](../atomic/atomic_fetch_sub.html "c/atomic/atomic fetch sub")  
[atomic_fetch_or](../atomic/atomic_fetch_or.html "c/atomic/atomic fetch or")  
[atomic_fetch_xor](../atomic/atomic_fetch_xor.html "c/atomic/atomic fetch xor")  
[atomic_fetch_and](../atomic/atomic_fetch_and.html "c/atomic/atomic fetch and")  
  
|  Atomic flags  
---  
[atomic_flag](../atomic/atomic_flag.html "c/atomic/atomic flag")  
[ATOMIC_FLAG_INIT](../atomic/ATOMIC_FLAG_INIT.html "c/atomic/ATOMIC FLAG INIT")  
[atomic_flag_test_and_set](../atomic/atomic_flag_test_and_set.html "c/atomic/atomic flag test and set")  
[atomic_flag_clear](../atomic/atomic_flag_clear.html "c/atomic/atomic flag clear")  
Memory ordering  
| [memory_order](../atomic/memory_order.html "c/atomic/memory order")  
---  
[kill_dependency](../atomic/kill_dependency.html "c/atomic/kill dependency")  
  
| [atomic_thread_fence](../atomic/atomic_thread_fence.html "c/atomic/atomic thread fence")  
---  
[atomic_signal_fence](../atomic/atomic_signal_fence.html "c/atomic/atomic signal fence")  
  
Mutual exclusion  
| [mtx_init](mtx_init.html "c/thread/mtx init")  
---  
[mtx_lock](mtx_lock.html "c/thread/mtx lock")  
[mtx_timedlock](mtx_timedlock.html "c/thread/mtx timedlock")  
[mtx_trylock](mtx_trylock.html "c/thread/mtx trylock")  
[call_once](ONCE_FLAG_INIT.html "c/thread/call once")  
  
| **mtx_unlock**  
---  
[mtx_destroy](mtx_destroy.html "c/thread/mtx destroy")  
[mtx_plainmtx_recursivemtx_timed](mtx_types.html "c/thread/mtx types")  
  
Condition variables  
| [cnd_init](cnd_init.html "c/thread/cnd init")  
---  
[cnd_signal](cnd_signal.html "c/thread/cnd signal")  
[cnd_broadcast](cnd_broadcast.html "c/thread/cnd broadcast")  
  
| [cnd_wait](cnd_wait.html "c/thread/cnd wait")  
---  
[cnd_timedwait](cnd_timedwait.html "c/thread/cnd timedwait")  
[cnd_destroy](cnd_destroy.html "c/thread/cnd destroy")  
  
Thread-local storage  
| [thread_local](thread_local.html "c/thread/thread local")  
---  
[TSS_DTOR_ITERATIONS](TSS_DTOR_ITERATIONS.html "c/thread/TSS DTOR ITERATIONS")  
[tss_create](tss_create.html "c/thread/tss create")  
  
| [tss_get](tss_get.html "c/thread/tss get")  
---  
[tss_set](tss_set.html "c/thread/tss set")  
[tss_delete](tss_delete.html "c/thread/tss delete")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/navbar_content&action=edit)

Defined in header `[`<threads.h>`](../header/threads.html "c/header/threads")` |  |   
---|---|---  
int mtx_unlock( [mtx_t](../thread.html) *mutex ); |  |  (since C11)  
| |   
  
Unlocks the mutex pointed to by `mutex`. 

The behavior is undefined if the mutex is not locked by the calling thread. 

This function _synchronizes-with_ subsequent [mtx_lock](mtx_lock.html "c/thread/mtx lock"), [mtx_trylock](mtx_trylock.html "c/thread/mtx trylock"), or [mtx_timedlock](mtx_timedlock.html "c/thread/mtx timedlock") on the same mutex. All lock/unlock operations on any given mutex form a single total order (similar to the modification order of an atomic). 

## Contents

  * [1 Parameters](mtx_unlock.html#Parameters)
  * [2 Return value](mtx_unlock.html#Return_value)
  * [3 References](mtx_unlock.html#References)
  * [4 See also](mtx_unlock.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread/mtx_unlock&action=edit&section=1 "Edit section: Parameters")] Parameters

mutex  |  \-  |  pointer to the mutex to unlock   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread/mtx_unlock&action=edit&section=2 "Edit section: Return value")] Return value

[thrd_success](thrd_errors.html "c/thread/thrd errors") if successful, [thrd_error](thrd_errors.html "c/thread/thrd errors") otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread/mtx_unlock&action=edit&section=3 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.26.4.6 The mtx_unlock function (p: 279) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.26.4.6 The mtx_unlock function (p: 382) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread/mtx_unlock&action=edit&section=4 "Edit section: See also")] See also

[ mtx_lock](mtx_lock.html "c/thread/mtx lock")(C11) |  blocks until locks a mutex   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_lock&action=edit)  
---|---  
[ mtx_timedlock](mtx_timedlock.html "c/thread/mtx timedlock")(C11) |  blocks until locks a mutex or times out   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_timedlock&action=edit)  
[ mtx_trylock](mtx_trylock.html "c/thread/mtx trylock")(C11) |  locks a mutex or returns without blocking if already locked   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_trylock&action=edit)  
[C++ documentation](../../cpp/thread/mutex/unlock.html "cpp/thread/mutex/unlock") for mutex::unlock  
[C++ documentation](../../cpp/thread/timed_mutex/unlock.html "cpp/thread/timed mutex/unlock") for timed_mutex::unlock  
[C++ documentation](../../cpp/thread/recursive_mutex/unlock.html "cpp/thread/recursive mutex/unlock") for recursive_mutex::unlock  
[C++ documentation](../../cpp/thread/recursive_timed_mutex/unlock.html "cpp/thread/recursive timed mutex/unlock") for recursive_timed_mutex::unlock  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/thread/mtx_unlock&oldid=138855](https://en.cppreference.com/mwiki/index.php?title=c/thread/mtx_unlock&oldid=138855)" 

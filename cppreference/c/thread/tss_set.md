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
  
| [mtx_unlock](mtx_unlock.html "c/thread/mtx unlock")  
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
**tss_set**  
[tss_delete](tss_delete.html "c/thread/tss delete")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/navbar_content&action=edit)

Defined in header `[`<threads.h>`](../header/threads.html "c/header/threads")` |  |   
---|---|---  
int tss_set( [tss_t](../thread.html) tss_id, void *val ); |  |  (since C11)  
| |   
  
Sets the value of the thread-specific storage identified by `tss_id` for the current thread to `val`. Different threads may set different values to the same key. 

The destructor, if available, is not invoked. 

## Contents

  * [1 Parameters](tss_set.html#Parameters)
  * [2 Return value](tss_set.html#Return_value)
  * [3 Notes](tss_set.html#Notes)
  * [4 Example](tss_set.html#Example)
  * [5 References](tss_set.html#References)
  * [6 See also](tss_set.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread/tss_set&action=edit&section=1 "Edit section: Parameters")] Parameters

tss_id  |  \-  |  thread-specific storage key, obtained from [tss_create](tss_create.html "c/thread/tss create") and not deleted by [tss_delete](tss_delete.html "c/thread/tss delete")  
---|---|---  
val  |  \-  |  value to set thread-specific storage to   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread/tss_set&action=edit&section=2 "Edit section: Return value")] Return value

[thrd_success](thrd_errors.html "c/thread/thrd errors") if successful, [thrd_error](thrd_errors.html "c/thread/thrd errors") otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread/tss_set&action=edit&section=3 "Edit section: Notes")] Notes

The POSIX equivalent of this function is [`pthread_setspecific`](http://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_setspecific.html). 

Typically TSS is used to store pointers to blocks of dynamically allocated memory that have been reserved for use by the calling thread. 

`tss_set` may be called in the TSS destructor. If the destructor exits with non-NULL value in the TSS storage, it will be retried by [thrd_exit](thrd_exit.html "c/thread/thrd exit") up to [TSS_DTOR_ITERATIONS](TSS_DTOR_ITERATIONS.html "c/thread/TSS DTOR ITERATIONS") times, after which the storage will be lost. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread/tss_set&action=edit&section=4 "Edit section: Example")] Example

| This section is incomplete  
Reason: improve, perhaps look for POSIX examples for inspiration   
---|---  
      
    
    int thread_func(void *arg) {
        [tss_t](../thread.html) key;
        if ([thrd_success](thrd_errors.html) == [tss_create](tss_create.html)(&key, [free](../memory/free.html))) {
            tss_set(key, [malloc](../memory/malloc.html)(4)); // stores a pointer on TSS
            // ...
        }
    } // calls free() for the pointer stored on TSS

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread/tss_set&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.26.6.4 The tss_set function (p: 282-283) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.26.6.4 The tss_set function (p: 387) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread/tss_set&action=edit&section=6 "Edit section: See also")] See also

[ tss_get](tss_get.html "c/thread/tss get")(C11) |  reads from thread-specific storage   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_tss_get&action=edit)  
---|---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/thread/tss_set&oldid=138762](https://en.cppreference.com/mwiki/index.php?title=c/thread/tss_set&oldid=138762)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



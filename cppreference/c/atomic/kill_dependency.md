From cppreference.com

< [c](../../c.html "c")‎ | [atomic](../atomic.html "c/atomic")

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
| [thrd_create](../thread/thrd_create.html "c/thread/thrd create")  
---  
[thrd_equal](../thread/thrd_equal.html "c/thread/thrd equal")  
[thrd_current](../thread/thrd_current.html "c/thread/thrd current")  
[thrd_sleep](../thread/thrd_sleep.html "c/thread/thrd sleep")  
[thrd_yield](../thread/thrd_yield.html "c/thread/thrd yield")  
[thrd_exit](../thread/thrd_exit.html "c/thread/thrd exit")  
  
| [thrd_detach](../thread/thrd_detach.html "c/thread/thrd detach")  
---  
[thrd_join](../thread/thrd_join.html "c/thread/thrd join")  
[thrd_successthrd_timedoutthrd_busythrd_nomemthrd_error](../thread/thrd_errors.html "c/thread/thrd errors")  
  
Atomic operations  
[atomic_init](atomic_init.html "c/atomic/atomic init")  
[ATOMIC_VAR_INIT](ATOMIC_VAR_INIT.html "c/atomic/ATOMIC VAR INIT")(until C23)  
[ATOMIC_***_LOCK_FREE](ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts")  
[atomic_is_lock_free](atomic_is_lock_free.html "c/atomic/atomic is lock free")  
[atomic_store](atomic_store.html "c/atomic/atomic store")  
[atomic_load](atomic_load.html "c/atomic/atomic load")  
[atomic_exchange](atomic_exchange.html "c/atomic/atomic exchange")  
[atomic_compare_exchange](atomic_compare_exchange.html "c/atomic/atomic compare exchange")  
[atomic_fetch_add](atomic_fetch_add.html "c/atomic/atomic fetch add")  
[atomic_fetch_sub](atomic_fetch_sub.html "c/atomic/atomic fetch sub")  
[atomic_fetch_or](atomic_fetch_or.html "c/atomic/atomic fetch or")  
[atomic_fetch_xor](atomic_fetch_xor.html "c/atomic/atomic fetch xor")  
[atomic_fetch_and](atomic_fetch_and.html "c/atomic/atomic fetch and")  
  
|  Atomic flags  
---  
[atomic_flag](atomic_flag.html "c/atomic/atomic flag")  
[ATOMIC_FLAG_INIT](ATOMIC_FLAG_INIT.html "c/atomic/ATOMIC FLAG INIT")  
[atomic_flag_test_and_set](atomic_flag_test_and_set.html "c/atomic/atomic flag test and set")  
[atomic_flag_clear](atomic_flag_clear.html "c/atomic/atomic flag clear")  
Memory ordering  
| [memory_order](memory_order.html "c/atomic/memory order")  
---  
**kill_dependency**  
  
| [atomic_thread_fence](atomic_thread_fence.html "c/atomic/atomic thread fence")  
---  
[atomic_signal_fence](atomic_signal_fence.html "c/atomic/atomic signal fence")  
  
Mutual exclusion  
| [mtx_init](../thread/mtx_init.html "c/thread/mtx init")  
---  
[mtx_lock](../thread/mtx_lock.html "c/thread/mtx lock")  
[mtx_timedlock](../thread/mtx_timedlock.html "c/thread/mtx timedlock")  
[mtx_trylock](../thread/mtx_trylock.html "c/thread/mtx trylock")  
[call_once](../thread/ONCE_FLAG_INIT.html "c/thread/call once")  
  
| [mtx_unlock](../thread/mtx_unlock.html "c/thread/mtx unlock")  
---  
[mtx_destroy](../thread/mtx_destroy.html "c/thread/mtx destroy")  
[mtx_plainmtx_recursivemtx_timed](../thread/mtx_types.html "c/thread/mtx types")  
  
Condition variables  
| [cnd_init](../thread/cnd_init.html "c/thread/cnd init")  
---  
[cnd_signal](../thread/cnd_signal.html "c/thread/cnd signal")  
[cnd_broadcast](../thread/cnd_broadcast.html "c/thread/cnd broadcast")  
  
| [cnd_wait](../thread/cnd_wait.html "c/thread/cnd wait")  
---  
[cnd_timedwait](../thread/cnd_timedwait.html "c/thread/cnd timedwait")  
[cnd_destroy](../thread/cnd_destroy.html "c/thread/cnd destroy")  
  
Thread-local storage  
| [thread_local](../thread/thread_local.html "c/thread/thread local")  
---  
[TSS_DTOR_ITERATIONS](../thread/TSS_DTOR_ITERATIONS.html "c/thread/TSS DTOR ITERATIONS")  
[tss_create](../thread/tss_create.html "c/thread/tss create")  
  
| [tss_get](../thread/tss_get.html "c/thread/tss get")  
---  
[tss_set](../thread/tss_set.html "c/thread/tss set")  
[tss_delete](../thread/tss_delete.html "c/thread/tss delete")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/navbar_content&action=edit)

Defined in header `[`<stdatomic.h>`](../header/stdatomic.html "c/header/stdatomic")` |  |   
---|---|---  
A kill_dependency( A y ); |  |  (since C11)  
| |   
  
Informs the compiler that the dependency tree started by an [memory_order_consume](memory_order.html "c/atomic/memory order") atomic load operation does not extend past the return value of `kill_dependency`; that is, the argument does not carry a dependency into the return value. 

The function is implemented as a macro. `A` is the type of y. 

## Contents

  * [1 Parameters](kill_dependency.html#Parameters)
  * [2 Return value](kill_dependency.html#Return_value)
  * [3 References](kill_dependency.html#References)
  * [4 See also](kill_dependency.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/kill_dependency&action=edit&section=1 "Edit section: Parameters")] Parameters

y  |  \-  |  the expression whose return value is to be removed from a dependency tree   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/kill_dependency&action=edit&section=2 "Edit section: Return value")] Return value

Returns y, no longer a part of a dependency tree. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/kill_dependency&action=edit&section=3 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.17.3.1 The kill_dependency macro (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.17.3.1 The kill_dependency macro (p: 203-204) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.17.3.1 The kill_dependency macro (p: 278) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/kill_dependency&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../cpp/atomic/kill_dependency.html "cpp/atomic/kill dependency") for kill_dependency  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/atomic/kill_dependency&oldid=155478](https://en.cppreference.com/mwiki/index.php?title=c/atomic/kill_dependency&oldid=155478)" 

From cppreference.com

< [c](../c.html "c")

[ C](../c.html "c")

[Compiler support](compiler_support.html "c/compiler support")  
---  
[Language](language.html "c/language")  
[Headers](header.html "c/header")  
[Type support](types.html "c/types")  
[Program utilities](program.html "c/program")  
[Variadic function support](variadic.html "c/variadic")  
[Error handling](error.html "c/error")  
[Dynamic memory management](memory.html "c/memory")  
[Strings library](string.html "c/string")  
[Algorithms](algorithm.html "c/algorithm")  
[Numerics](numeric.html "c/numeric")  
[Date and time utilities](chrono.html "c/chrono")  
[Input/output support](io.html "c/io")  
[Localization support](locale.html "c/locale")  
**Concurrency support** (C11)  
[Technical Specifications](experimental.html "c/experimental")  
[Symbol index](index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

**Concurrency support library**

|  Threads  
---  
| [thrd_create](thread/thrd_create.html "c/thread/thrd create")  
---  
[thrd_equal](thread/thrd_equal.html "c/thread/thrd equal")  
[thrd_current](thread/thrd_current.html "c/thread/thrd current")  
[thrd_sleep](thread/thrd_sleep.html "c/thread/thrd sleep")  
[thrd_yield](thread/thrd_yield.html "c/thread/thrd yield")  
[thrd_exit](thread/thrd_exit.html "c/thread/thrd exit")  
  
| [thrd_detach](thread/thrd_detach.html "c/thread/thrd detach")  
---  
[thrd_join](thread/thrd_join.html "c/thread/thrd join")  
[thrd_successthrd_timedoutthrd_busythrd_nomemthrd_error](thread/thrd_errors.html "c/thread/thrd errors")  
  
Atomic operations  
[atomic_init](atomic/atomic_init.html "c/atomic/atomic init")  
[ATOMIC_VAR_INIT](atomic/ATOMIC_VAR_INIT.html "c/atomic/ATOMIC VAR INIT")(until C23)  
[ATOMIC_***_LOCK_FREE](atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts")  
[atomic_is_lock_free](atomic/atomic_is_lock_free.html "c/atomic/atomic is lock free")  
[atomic_store](atomic/atomic_store.html "c/atomic/atomic store")  
[atomic_load](atomic/atomic_load.html "c/atomic/atomic load")  
[atomic_exchange](atomic/atomic_exchange.html "c/atomic/atomic exchange")  
[atomic_compare_exchange](atomic/atomic_compare_exchange.html "c/atomic/atomic compare exchange")  
[atomic_fetch_add](atomic/atomic_fetch_add.html "c/atomic/atomic fetch add")  
[atomic_fetch_sub](atomic/atomic_fetch_sub.html "c/atomic/atomic fetch sub")  
[atomic_fetch_or](atomic/atomic_fetch_or.html "c/atomic/atomic fetch or")  
[atomic_fetch_xor](atomic/atomic_fetch_xor.html "c/atomic/atomic fetch xor")  
[atomic_fetch_and](atomic/atomic_fetch_and.html "c/atomic/atomic fetch and")  
  
|  Atomic flags  
---  
[atomic_flag](atomic/atomic_flag.html "c/atomic/atomic flag")  
[ATOMIC_FLAG_INIT](atomic/ATOMIC_FLAG_INIT.html "c/atomic/ATOMIC FLAG INIT")  
[atomic_flag_test_and_set](atomic/atomic_flag_test_and_set.html "c/atomic/atomic flag test and set")  
[atomic_flag_clear](atomic/atomic_flag_clear.html "c/atomic/atomic flag clear")  
Memory ordering  
| [memory_order](atomic/memory_order.html "c/atomic/memory order")  
---  
[kill_dependency](atomic/kill_dependency.html "c/atomic/kill dependency")  
  
| [atomic_thread_fence](atomic/atomic_thread_fence.html "c/atomic/atomic thread fence")  
---  
[atomic_signal_fence](atomic/atomic_signal_fence.html "c/atomic/atomic signal fence")  
  
Mutual exclusion  
| [mtx_init](thread/mtx_init.html "c/thread/mtx init")  
---  
[mtx_lock](thread/mtx_lock.html "c/thread/mtx lock")  
[mtx_timedlock](thread/mtx_timedlock.html "c/thread/mtx timedlock")  
[mtx_trylock](thread/mtx_trylock.html "c/thread/mtx trylock")  
[call_once](thread/ONCE_FLAG_INIT.html "c/thread/call once")  
  
| [mtx_unlock](thread/mtx_unlock.html "c/thread/mtx unlock")  
---  
[mtx_destroy](thread/mtx_destroy.html "c/thread/mtx destroy")  
[mtx_plainmtx_recursivemtx_timed](thread/mtx_types.html "c/thread/mtx types")  
  
Condition variables  
| [cnd_init](thread/cnd_init.html "c/thread/cnd init")  
---  
[cnd_signal](thread/cnd_signal.html "c/thread/cnd signal")  
[cnd_broadcast](thread/cnd_broadcast.html "c/thread/cnd broadcast")  
  
| [cnd_wait](thread/cnd_wait.html "c/thread/cnd wait")  
---  
[cnd_timedwait](thread/cnd_timedwait.html "c/thread/cnd timedwait")  
[cnd_destroy](thread/cnd_destroy.html "c/thread/cnd destroy")  
  
Thread-local storage  
| [thread_local](thread/thread_local.html "c/thread/thread local")  
---  
[TSS_DTOR_ITERATIONS](thread/TSS_DTOR_ITERATIONS.html "c/thread/TSS DTOR ITERATIONS")  
[tss_create](thread/tss_create.html "c/thread/tss create")  
  
| [tss_get](thread/tss_get.html "c/thread/tss get")  
---  
[tss_set](thread/tss_set.html "c/thread/tss set")  
[tss_delete](thread/tss_delete.html "c/thread/tss delete")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/navbar_content&action=edit)

C includes built-in support for threads, atomic operations, mutual exclusion, condition variables, and thread-specific storages. 

These features are optionally provided: 

  * if the macro constant `__STDC_NO_THREADS__` is defined by the compiler, the header [`<threads.h>`](header/threads.html "c/header/threads") and all of the names provided in it are not provided; 
  * if the macro constant `__STDC_NO_ATOMICS__` is defined by the compiler, the header [`<stdatomic.h>`](header/stdatomic.html "c/header/stdatomic") and all of the names provided in it are not provided. 



See also [`**_Atomic**` type specifier and qualifier](language/atomic.html "c/language/atomic"). 

## Contents

  * [1 Threads](thread.html#Threads)
  * [2 Atomic operations](thread.html#Atomic_operations)
    * [2.1 Operations on atomic types](thread.html#Operations_on_atomic_types)
    * [2.2 Flag type and operations](thread.html#Flag_type_and_operations)
    * [2.3 Initialization](thread.html#Initialization)
    * [2.4 Memory synchronization ordering](thread.html#Memory_synchronization_ordering)
    * [2.5 Convenience type aliases](thread.html#Convenience_type_aliases)
  * [3 Mutual exclusion](thread.html#Mutual_exclusion)
    * [3.1 Call once](thread.html#Call_once)
  * [4 Condition variables](thread.html#Condition_variables)
  * [5 Thread-local storage](thread.html#Thread-local_storage)
  * [6 Reserved identifiers](thread.html#Reserved_identifiers)
  * [7 References](thread.html#References)
  * [8 See also](thread.html#See_also)
  * [9 External links](thread.html#External_links)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread&action=edit&section=1 "Edit section: Threads")] Threads

Defined in header `[`<threads.h>`](header/threads.html "c/header/threads")`  
---  
`**thrd_t**` |  implementation-defined complete object type identifying a thread [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_t&action=edit)  
[ thrd_create](thread/thrd_create.html "c/thread/thrd create")(C11) |  creates a thread   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_create&action=edit)  
[ thrd_equal](thread/thrd_equal.html "c/thread/thrd equal")(C11) |  checks if two identifiers refer to the same thread   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_equal&action=edit)  
[ thrd_current](thread/thrd_current.html "c/thread/thrd current")(C11) |  obtains the current thread identifier   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_current&action=edit)  
[ thrd_sleep](thread/thrd_sleep.html "c/thread/thrd sleep")(C11) |  suspends execution of the calling thread for the given period of time   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_sleep&action=edit)  
[ thrd_yield](thread/thrd_yield.html "c/thread/thrd yield")(C11) |  yields the current time slice   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_yield&action=edit)  
[ thrd_exit](thread/thrd_exit.html "c/thread/thrd exit")(C11) |  terminates the calling thread   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_exit&action=edit)  
[ thrd_detach](thread/thrd_detach.html "c/thread/thrd detach")(C11) |  detaches a thread   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_detach&action=edit)  
[ thrd_join](thread/thrd_join.html "c/thread/thrd join")(C11) |  blocks until a thread terminates   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_join&action=edit)  
[ thrd_successthrd_timedoutthrd_busythrd_nomemthrd_error](thread/thrd_errors.html "c/thread/thrd errors")(C11) |  indicates a thread error status   
(constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_errors&action=edit)  
thrd_start_t(C11) |  a typedef of the function pointer type int(*)(void*), used by [thrd_create](thread/thrd_create.html)   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_start_t&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread&action=edit&section=2 "Edit section: Atomic operations")] Atomic operations

Defined in header `[`<stdatomic.h>`](header/stdatomic.html "c/header/stdatomic")`  
---  
  
#####  Operations on atomic types   
  
[ ATOMIC_BOOL_LOCK_FREEATOMIC_CHAR_LOCK_FREEATOMIC_CHAR16_T_LOCK_FREEATOMIC_CHAR32_T_LOCK_FREEATOMIC_WCHAR_T_LOCK_FREEATOMIC_SHORT_LOCK_FREEATOMIC_INT_LOCK_FREEATOMIC_LONG_LOCK_FREEATOMIC_LLONG_LOCK_FREEATOMIC_POINTER_LOCK_FREE](atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts")(C11) |  indicates that the given atomic type is lock-free   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_ATOMIC_LOCK_FREE_consts&action=edit)  
[ atomic_is_lock_free](atomic/atomic_is_lock_free.html "c/atomic/atomic is lock free")(C11) |  indicates whether the atomic object is lock-free   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_is_lock_free&action=edit)  
[ atomic_storeatomic_store_explicit](atomic/atomic_store.html "c/atomic/atomic store")(C11) |  stores a value in an atomic object   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_store&action=edit)  
[ atomic_loadatomic_load_explicit](atomic/atomic_load.html "c/atomic/atomic load")(C11) |  reads a value from an atomic object   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_load&action=edit)  
[ atomic_exchangeatomic_exchange_explicit](atomic/atomic_exchange.html "c/atomic/atomic exchange")(C11) |  swaps a value with the value of an atomic object   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_exchange&action=edit)  
[ atomic_compare_exchange_strongatomic_compare_exchange_strong_explicitatomic_compare_exchange_weakatomic_compare_exchange_weak_explicit](atomic/atomic_compare_exchange.html "c/atomic/atomic compare exchange")(C11) |  swaps a value with an atomic object if the old value is what is expected, otherwise reads the old value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_compare_exchange&action=edit)  
[ atomic_fetch_addatomic_fetch_add_explicit](atomic/atomic_fetch_add.html "c/atomic/atomic fetch add")(C11) |  atomic addition   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_fetch_add&action=edit)  
[ atomic_fetch_subatomic_fetch_sub_explicit](atomic/atomic_fetch_sub.html "c/atomic/atomic fetch sub")(C11) |  atomic subtraction   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_fetch_sub&action=edit)  
[ atomic_fetch_oratomic_fetch_or_explicit](atomic/atomic_fetch_or.html "c/atomic/atomic fetch or")(C11) |  atomic bitwise OR   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_fetch_or&action=edit)  
[ atomic_fetch_xoratomic_fetch_xor_explicit](atomic/atomic_fetch_xor.html "c/atomic/atomic fetch xor")(C11) |  atomic bitwise exclusive OR   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_fetch_xor&action=edit)  
[ atomic_fetch_andatomic_fetch_and_explicit](atomic/atomic_fetch_and.html "c/atomic/atomic fetch and")(C11) |  atomic bitwise AND   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_fetch_and&action=edit)  
  
#####  Flag type and operations   
  
[ atomic_flag](atomic/atomic_flag.html "c/atomic/atomic flag")(C11) |  lock-free atomic boolean flag   
(struct)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_flag&action=edit)  
[ atomic_flag_test_and_setatomic_flag_test_and_set_explicit](atomic/atomic_flag_test_and_set.html "c/atomic/atomic flag test and set")(C11) |  sets an atomic_flag to true and returns the old value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_flag_test_and_set&action=edit)  
[ atomic_flag_clearatomic_flag_clear_explicit](atomic/atomic_flag_clear.html "c/atomic/atomic flag clear")(C11) |  sets an atomic_flag to false   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_flag_clear&action=edit)  
  
#####  Initialization   
  
[ atomic_init](atomic/atomic_init.html "c/atomic/atomic init")(C11) |  initializes an existing atomic object   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_init&action=edit)  
[ ATOMIC_VAR_INIT](atomic/ATOMIC_VAR_INIT.html "c/atomic/ATOMIC VAR INIT")(C11)(deprecated in C17)(removed in C23) |  initializes a new atomic object   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_ATOMIC_VAR_INIT&action=edit)  
[ ATOMIC_FLAG_INIT](atomic/ATOMIC_FLAG_INIT.html "c/atomic/ATOMIC FLAG INIT")(C11) |  initializes a new [atomic_flag](atomic/atomic_flag.html)   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_ATOMIC_FLAG_INIT&action=edit)  
  
#####  Memory synchronization ordering   
  
[ memory_order](atomic/memory_order.html "c/atomic/memory order")(C11) |  defines memory ordering constraints   
(enum) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_memory_order&action=edit)  
[ kill_dependency](atomic/kill_dependency.html "c/atomic/kill dependency")(C11) |  breaks a dependency chain for [memory_order_consume](atomic/memory_order.html)   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_kill_dependency&action=edit)  
[ atomic_thread_fence](atomic/atomic_thread_fence.html "c/atomic/atomic thread fence")(C11) |  generic memory order-dependent fence synchronization primitive   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_thread_fence&action=edit)  
[ atomic_signal_fence](atomic/atomic_signal_fence.html "c/atomic/atomic signal fence")(C11) |  fence between a thread and a signal handler executed in the same thread   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_signal_fence&action=edit)  
  
#####  Convenience type aliases   
  
---  
Typedef name  |  Full type name   
`atomic_bool` (C11) |  _Atomic _Bool(until C23)_Atomic bool(since C23)  
`atomic_char` (C11) |  _Atomic char  
`atomic_schar` (C11) |  _Atomic signed char  
`atomic_uchar` (C11) |  _Atomic unsigned char  
`atomic_short` (C11) |  _Atomic short  
`atomic_ushort` (C11) |  _Atomic unsigned short  
`atomic_int` (C11) |  _Atomic int  
`atomic_uint` (C11) |  _Atomic unsigned int  
`atomic_long` (C11) |  _Atomic long  
`atomic_ulong` (C11) |  _Atomic unsigned long  
`atomic_llong` (C11) |  _Atomic long long  
`atomic_ullong` (C11) |  _Atomic unsigned long long  
`atomic_char8_t` (C23) |  _Atomic char8_t  
`atomic_char16_t` (C11) |  _Atomic char16_t  
`atomic_char32_t` (C11) |  _Atomic char32_t  
`atomic_wchar_t` (C11) |  _Atomic wchar_t  
`atomic_int_least8_t` (C11) |  _Atomic [int_least8_t](types/integer.html)  
`atomic_uint_least8_t` (C11) |  _Atomic [uint_least8_t](types/integer.html)  
`atomic_int_least16_t` (C11) |  _Atomic [int_least16_t](types/integer.html)  
`atomic_uint_least16_t` (C11) |  _Atomic [uint_least16_t](types/integer.html)  
`atomic_int_least32_t` (C11) |  _Atomic [int_least32_t](types/integer.html)  
`atomic_uint_least32_t` (C11) |  _Atomic [uint_least32_t](types/integer.html)  
`atomic_int_least64_t` (C11) |  _Atomic [int_least64_t](types/integer.html)  
`atomic_uint_least64_t` (C11) |  _Atomic [uint_least64_t](types/integer.html)  
`atomic_int_fast8_t` (C11) |  _Atomic [int_fast8_t](types/integer.html)  
`atomic_uint_fast8_t` (C11) |  _Atomic [uint_fast8_t](types/integer.html)  
`atomic_int_fast16_t` (C11) |  _Atomic [int_fast16_t](types/integer.html)  
`atomic_uint_fast16_t` (C11) |  _Atomic [uint_fast16_t](types/integer.html)  
`atomic_int_fast32_t` (C11) |  _Atomic [int_fast32_t](types/integer.html)  
`atomic_uint_fast32_t` (C11) |  _Atomic [uint_fast32_t](types/integer.html)  
`atomic_int_fast64_t` (C11) |  _Atomic [int_fast64_t](types/integer.html)  
`atomic_uint_fast64_t` (C11) |  _Atomic [uint_fast64_t](types/integer.html)  
`atomic_intptr_t` (C11) |  _Atomic [intptr_t](types/integer.html)  
`atomic_uintptr_t` (C11) |  _Atomic [uintptr_t](types/integer.html)  
`atomic_size_t` (C11) |  _Atomic [size_t](types/size_t.html)  
`atomic_ptrdiff_t` (C11) |  _Atomic [ptrdiff_t](types/ptrdiff_t.html)  
`atomic_intmax_t` (C11) |  _Atomic [intmax_t](types/integer.html)  
`atomic_uintmax_t` (C11) |  _Atomic [uintmax_t](types/integer.html)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread&action=edit&section=3 "Edit section: Mutual exclusion")] Mutual exclusion

Defined in header `[`<threads.h>`](header/threads.html "c/header/threads")`  
---  
`**mtx_t**` |  mutex identifier [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_t&action=edit)  
[ mtx_init](thread/mtx_init.html "c/thread/mtx init")(C11) |  creates a mutex   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_init&action=edit)  
[ mtx_lock](thread/mtx_lock.html "c/thread/mtx lock")(C11) |  blocks until locks a mutex   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_lock&action=edit)  
[ mtx_timedlock](thread/mtx_timedlock.html "c/thread/mtx timedlock")(C11) |  blocks until locks a mutex or times out   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_timedlock&action=edit)  
[ mtx_trylock](thread/mtx_trylock.html "c/thread/mtx trylock")(C11) |  locks a mutex or returns without blocking if already locked   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_trylock&action=edit)  
[ mtx_unlock](thread/mtx_unlock.html "c/thread/mtx unlock")(C11) |  unlocks a mutex   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_unlock&action=edit)  
[ mtx_destroy](thread/mtx_destroy.html "c/thread/mtx destroy")(C11) |  destroys a mutex   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_destroy&action=edit)  
[ mtx_plainmtx_recursivemtx_timed](thread/mtx_types.html "c/thread/mtx types")(C11)(C11)(C11) |  defines the type of a mutex   
(enum) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_types&action=edit)  
  
#####  Call once   
  
[ call_once](thread/ONCE_FLAG_INIT.html "c/thread/call once")(C11) |  calls a function exactly once   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_call_once&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread&action=edit&section=4 "Edit section: Condition variables")] Condition variables

Defined in header `[`<threads.h>`](header/threads.html "c/header/threads")`  
---  
`**cnd_t**` |  condition variable identifier   
[ cnd_init](thread/cnd_init.html "c/thread/cnd init")(C11) |  creates a condition variable   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_cnd_init&action=edit)  
[ cnd_signal](thread/cnd_signal.html "c/thread/cnd signal")(C11) |  unblocks one thread blocked on a condition variable   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_cnd_signal&action=edit)  
[ cnd_broadcast](thread/cnd_broadcast.html "c/thread/cnd broadcast")(C11) |  unblocks all threads blocked on a condition variable   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_cnd_broadcast&action=edit)  
[ cnd_wait](thread/cnd_wait.html "c/thread/cnd wait")(C11) |  blocks on a condition variable   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_cnd_wait&action=edit)  
[ cnd_timedwait](thread/cnd_timedwait.html "c/thread/cnd timedwait")(C11) |  blocks on a condition variable, with a timeout   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_cnd_timedwait&action=edit)  
[ cnd_destroy](thread/cnd_destroy.html "c/thread/cnd destroy")(C11) |  destroys a condition variable   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_cnd_destroy&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread&action=edit&section=5 "Edit section: Thread-local storage")] Thread-local storage

Defined in header `[`<threads.h>`](header/threads.html "c/header/threads")`  
---  
[ thread_local](thread/thread_local.html "c/thread/thread local")(C11)(removed in C23) |  convenience macro for storage-class specifier _Thread_local   
(keyword macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thread_local&action=edit)  
`**tss_t**` |  thread-specific storage pointer [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_tss_t&action=edit)  
[ TSS_DTOR_ITERATIONS](thread/TSS_DTOR_ITERATIONS.html "c/thread/TSS DTOR ITERATIONS")(C11) |  maximum number of times destructors are called   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_TSS_DTOR_ITERATIONS&action=edit)  
`**tss_dtor_t**`(C11) |  function pointer type void(*)(void*), used for TSS destructor   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_tss_dtor_t&action=edit)  
[ tss_create](thread/tss_create.html "c/thread/tss create")(C11) |  creates thread-specific storage pointer with a given destructor   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_tss_create&action=edit)  
[ tss_get](thread/tss_get.html "c/thread/tss get")(C11) |  reads from thread-specific storage   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_tss_get&action=edit)  
[ tss_set](thread/tss_set.html "c/thread/tss set")(C11) |  write to thread-specific storage   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_tss_set&action=edit)  
[ tss_delete](thread/tss_delete.html "c/thread/tss delete")(C11) |  releases the resources held by a given thread-specific pointer   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_tss_delete&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread&action=edit&section=6 "Edit section: Reserved identifiers")] Reserved identifiers

In future revisions of the C standard: 

  * function names, type names, and enumeration constants that begin with either `cnd_`, `mtx_`, `thrd_`, or `tss_`, and a lowercase letter may be added to the declarations in the `<threads.h>` header; 
  * macros that begin with `ATOMIC_` and an uppercase letter may be added to the macros defined in the [`<stdatomic.h>`](header/stdatomic.html "c/header/stdatomic") header; 
  * typedef names that begin with either `atomic_` or `memory_`, and a lowercase letter may be added to the declarations in the [`<stdatomic.h>`](header/stdatomic.html "c/header/stdatomic") header; 
  * enumeration constants that begin with `memory_order_` and a lowercase letter may be added to the definition of the [memory_order](atomic/memory_order.html "c/atomic/memory order") type in the [`<stdatomic.h>`](header/stdatomic.html "c/header/stdatomic") header; 
  * function names that begin with `atomic_` and a lowercase letter may be added to the declarations in the [`<stdatomic.h>`](header/stdatomic.html "c/header/stdatomic") header. 



Identifiers reserved for functions names are always potentially(since C23) reserved for use as identifiers with external linkage, while other identifiers list here are potentially(since C23) reserved when [`<stdatomic.h>`](header/stdatomic.html "c/header/stdatomic") is included. 

Declaring, defining, or #undefing such an identifier results in undefined behavior if it is provided by the standard or implementation(since C23). Portable programs should not use those identifiers. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread&action=edit&section=7 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.17 Atomics <stdatomic.h> (p: TBD) 



    

  * 7.26 Threads <threads.h> (p: TBD) 



    

  * 7.31.8 Atomics <stdatomic.h> (p: TBD) 



    

  * 7.31.15 Threads <threads.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.17 Atomics <stdatomic.h> (p: 200-209) 



    

  * 7.26 Threads <threads.h> (p: 274-283) 



    

  * 7.31.8 Atomics <stdatomic.h> (p: 332) 



    

  * 7.31.15 Threads <threads.h> (p: 333) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.17 Atomics <stdatomic.h> (p: 273-286) 



    

  * 7.26 Threads <threads.h> (p: 376-387) 



    

  * 7.31.8 Atomics <stdatomic.h> (p: 455-456) 



    

  * 7.31.15 Threads <threads.h> (p: 456) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread&action=edit&section=8 "Edit section: See also")] See also

[C++ documentation](../cpp/atomic.html "cpp/thread") for Concurrency support library  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/thread&action=edit&section=9 "Edit section: External links")] External links

[GNU GCC Libc Manual: ISO C Mutexes](https://www.gnu.org/software/libc/manual/html_node/ISO-C-Mutexes.html)  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/thread&oldid=180203](https://en.cppreference.com/mwiki/index.php?title=c/thread&oldid=180203)" 

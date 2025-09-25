From cppreference.com

< [c](../../c.html "c")‎ | [header](../header.html "c/header")

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

[ Standard Library headers ](../header.html "c/header")

| [`<assert.h>`](assert.html "c/header/assert")  
---  
[`<complex.h>`](complex.html "c/header/complex") (C99)  
[`<ctype.h>`](ctype.html "c/header/ctype")  
[`<errno.h>`](errno.html "c/header/errno")  
[`<fenv.h>`](fenv.html "c/header/fenv") (C99)  
[`<float.h>`](float.html "c/header/float")  
[`<inttypes.h>`](inttypes.html "c/header/inttypes") (C99)` `  
[`<iso646.h>`](iso646.html "c/header/iso646") (C95)  
[`<limits.h>`](limits.html "c/header/limits")  
[`<locale.h>`](locale.html "c/header/locale")  
[`<math.h>`](math.html "c/header/math")  
  
| [`<setjmp.h>`](setjmp.html "c/header/setjmp")  
---  
[`<signal.h>`](signal.html "c/header/signal")  
[`<stdalign.h>`](stdalign.html "c/header/stdalign") (C11*)  
[`<stdarg.h>`](stdarg.html "c/header/stdarg")  
[`<stdatomic.h>`](stdatomic.html "c/header/stdatomic") (C11)` `  
[`<stdbit.h>`](stdbit.html "c/header/stdbit") (C23)  
[`<stdbool.h>`](stdbool.html "c/header/stdbool") (C99*)  
[`<stdckdint.h>`](stdckdint.html "c/header/stdckdint") (C23)  
[`<stddef.h>`](stddef.html "c/header/stddef")  
[`<stdint.h>`](stdint.html "c/header/stdint") (C99)  
[`<stdio.h>`](stdio.html "c/header/stdio")  
  
| [`<stdlib.h>`](stdlib.html "c/header/stdlib")  
---  
[`<stdmchar.h>`](stdmchar.html "c/header/stdmchar") (C29)  
[`<stdnoreturn.h>`](stdnoreturn.html "c/header/stdnoreturn") (C11*)  
[`<string.h>`](string.html "c/header/string")  
[`<tgmath.h>`](tgmath.html "c/header/tgmath") (C99)  
**`< threads.h>`** (C11)  
[`<time.h>`](time.html "c/header/time")  
[`<uchar.h>`](uchar.html "c/header/uchar") (C11)  
[`<wchar.h>`](wchar.html "c/header/wchar") (C95)  
[`<wctype.h>`](wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header is part of [concurrency support library](../thread.html "c/thread") and provides support for threads, mutual exclusion, condition variables, and thread-specific storages. 

## Contents

  * [1 Threads](threads.html#Threads)
  * [2 Mutual exclusion](threads.html#Mutual_exclusion)
    * [2.1 Call once](threads.html#Call_once)
  * [3 Condition variables](threads.html#Condition_variables)
  * [4 Thread-local storage](threads.html#Thread-local_storage)
  * [5 Synopsis](threads.html#Synopsis)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/threads&action=edit&section=1 "Edit section: Threads")] Threads

`**thrd_t**` |  implementation-defined complete object type identifying a thread [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_t&action=edit)  
---|---  
[ thrd_create](../thread/thrd_create.html "c/thread/thrd create")(C11) |  creates a thread   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_create&action=edit)  
[ thrd_equal](../thread/thrd_equal.html "c/thread/thrd equal")(C11) |  checks if two identifiers refer to the same thread   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_equal&action=edit)  
[ thrd_current](../thread/thrd_current.html "c/thread/thrd current")(C11) |  obtains the current thread identifier   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_current&action=edit)  
[ thrd_sleep](../thread/thrd_sleep.html "c/thread/thrd sleep")(C11) |  suspends execution of the calling thread for the given period of time   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_sleep&action=edit)  
[ thrd_yield](../thread/thrd_yield.html "c/thread/thrd yield")(C11) |  yields the current time slice   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_yield&action=edit)  
[ thrd_exit](../thread/thrd_exit.html "c/thread/thrd exit")(C11) |  terminates the calling thread   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_exit&action=edit)  
[ thrd_detach](../thread/thrd_detach.html "c/thread/thrd detach")(C11) |  detaches a thread   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_detach&action=edit)  
[ thrd_join](../thread/thrd_join.html "c/thread/thrd join")(C11) |  blocks until a thread terminates   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_join&action=edit)  
[ thrd_successthrd_timedoutthrd_busythrd_nomemthrd_error](../thread/thrd_errors.html "c/thread/thrd errors")(C11) |  indicates a thread error status   
(constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_errors&action=edit)  
thrd_start_t(C11) |  a typedef of the function pointer type int(*)(void*), used by [thrd_create](../thread/thrd_create.html)   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thrd_start_t&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/threads&action=edit&section=2 "Edit section: Mutual exclusion")] Mutual exclusion

`**mtx_t**` |  mutex identifier [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_t&action=edit)  
---|---  
[ mtx_init](../thread/mtx_init.html "c/thread/mtx init")(C11) |  creates a mutex   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_init&action=edit)  
[ mtx_lock](../thread/mtx_lock.html "c/thread/mtx lock")(C11) |  blocks until locks a mutex   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_lock&action=edit)  
[ mtx_timedlock](../thread/mtx_timedlock.html "c/thread/mtx timedlock")(C11) |  blocks until locks a mutex or times out   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_timedlock&action=edit)  
[ mtx_trylock](../thread/mtx_trylock.html "c/thread/mtx trylock")(C11) |  locks a mutex or returns without blocking if already locked   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_trylock&action=edit)  
[ mtx_unlock](../thread/mtx_unlock.html "c/thread/mtx unlock")(C11) |  unlocks a mutex   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_unlock&action=edit)  
[ mtx_destroy](../thread/mtx_destroy.html "c/thread/mtx destroy")(C11) |  destroys a mutex   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_destroy&action=edit)  
[ mtx_plainmtx_recursivemtx_timed](../thread/mtx_types.html "c/thread/mtx types")(C11)(C11)(C11) |  defines the type of a mutex   
(enum) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_mtx_types&action=edit)  
  
#####  Call once   
  
[ call_once](../thread/ONCE_FLAG_INIT.html "c/thread/call once")(C11) |  calls a function exactly once   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_call_once&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/threads&action=edit&section=3 "Edit section: Condition variables")] Condition variables

`**cnd_t**` |  condition variable identifier   
---|---  
[ cnd_init](../thread/cnd_init.html "c/thread/cnd init")(C11) |  creates a condition variable   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_cnd_init&action=edit)  
[ cnd_signal](../thread/cnd_signal.html "c/thread/cnd signal")(C11) |  unblocks one thread blocked on a condition variable   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_cnd_signal&action=edit)  
[ cnd_broadcast](../thread/cnd_broadcast.html "c/thread/cnd broadcast")(C11) |  unblocks all threads blocked on a condition variable   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_cnd_broadcast&action=edit)  
[ cnd_wait](../thread/cnd_wait.html "c/thread/cnd wait")(C11) |  blocks on a condition variable   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_cnd_wait&action=edit)  
[ cnd_timedwait](../thread/cnd_timedwait.html "c/thread/cnd timedwait")(C11) |  blocks on a condition variable, with a timeout   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_cnd_timedwait&action=edit)  
[ cnd_destroy](../thread/cnd_destroy.html "c/thread/cnd destroy")(C11) |  destroys a condition variable   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_cnd_destroy&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/threads&action=edit&section=4 "Edit section: Thread-local storage")] Thread-local storage

[ thread_local](../thread/thread_local.html "c/thread/thread local")(C11)(removed in C23) |  convenience macro for storage-class specifier _Thread_local   
(keyword macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_thread_local&action=edit)  
---|---  
`**tss_t**` |  thread-specific storage pointer [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_tss_t&action=edit)  
[ TSS_DTOR_ITERATIONS](../thread/TSS_DTOR_ITERATIONS.html "c/thread/TSS DTOR ITERATIONS")(C11) |  maximum number of times destructors are called   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_TSS_DTOR_ITERATIONS&action=edit)  
`**tss_dtor_t**`(C11) |  function pointer type void(*)(void*), used for TSS destructor   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_tss_dtor_t&action=edit)  
[ tss_create](../thread/tss_create.html "c/thread/tss create")(C11) |  creates thread-specific storage pointer with a given destructor   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_tss_create&action=edit)  
[ tss_get](../thread/tss_get.html "c/thread/tss get")(C11) |  reads from thread-specific storage   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_tss_get&action=edit)  
[ tss_set](../thread/tss_set.html "c/thread/tss set")(C11) |  write to thread-specific storage   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_tss_set&action=edit)  
[ tss_delete](../thread/tss_delete.html "c/thread/tss delete")(C11) |  releases the resources held by a given thread-specific pointer   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/thread/dsc_tss_delete&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/threads&action=edit&section=5 "Edit section: Synopsis")] Synopsis
    
    
    #define __STDC_NO_THREADS__ 202311L
     
    #define ONCE_FLAG_INIT      /* see description */
    #define TSS_DTOR_ITERATIONS /* see description */
     
    typedef /* see description */ [cnd_t](../thread.html);
    typedef /* see description */ [thrd_t](../thread.html);
    typedef /* see description */ [tss_t](../thread.html);
    typedef /* see description */ [mtx_t](../thread.html);
    typedef /* see description */ [tss_dtor_t](../thread.html);
    typedef /* see description */ [thrd_start_t](../thread.html);
     
    #define mtx_plain     /* see description */
    #define mtx_recursive /* see description */
    #define mtx_timed     /* see description */
    #define once_flag     /* see description */
    #define thrd_busy     /* see description */
    #define thrd_error    /* see description */
    #define thrd_nomem    /* see description */
    #define thrd_success  /* see description */
    #define thrd_timedout /* see description */
     
    void [call_once](../thread/call_once.html)([once_flag](../thread.html)* flag, void (*func)(void));
    int [cnd_broadcast](../thread/cnd_broadcast.html)([cnd_t](../thread.html)* cond);
    void [cnd_destroy](../thread/cnd_destroy.html)([cnd_t](../thread.html)* cond);
    int [cnd_init](../thread/cnd_init.html)([cnd_t](../thread.html)* cond);
    int [cnd_signal](../thread/cnd_signal.html)([cnd_t](../thread.html)* cond);
    int [cnd_timedwait](../thread/cnd_timedwait.html)([cnd_t](../thread.html)* restrict cond, [mtx_t](../thread.html)* restrict mtx,
    const struct timespec* restrict ts);
    int [cnd_wait](../thread/cnd_wait.html)([cnd_t](../thread.html)* cond, [mtx_t](../thread.html)* mtx);
    void [mtx_destroy](../thread/mtx_destroy.html)([mtx_t](../thread.html)* mtx);
    int [mtx_init](../thread/mtx_init.html)([mtx_t](../thread.html)* mtx, int type);
    int [mtx_lock](../thread/mtx_lock.html)([mtx_t](../thread.html)* mtx);
    int [mtx_timedlock](../thread/mtx_timedlock.html)([mtx_t](../thread.html)* restrict mtx, const struct timespec* restrict ts);
    int [mtx_trylock](../thread/mtx_trylock.html)([mtx_t](../thread.html)* mtx);
    int [mtx_unlock](../thread/mtx_unlock.html)([mtx_t](../thread.html)* mtx);
    int [thrd_create](../thread/thrd_create.html)([thrd_t](../thread.html)* thr, [thrd_start_t](../thread.html) func, void* arg);
    [thrd_t](../thread.html) [thrd_current](../thread/thrd_current.html)(void);
    int [thrd_detach](../thread/thrd_detach.html)([thrd_t](../thread.html) thr);
    int [thrd_equal](../thread/thrd_equal.html)([thrd_t](../thread.html) thr0, [thrd_t](../thread.html) thr1);
    [[noreturn]] void [thrd_exit](../thread/thrd_exit.html)(int res);
    int [thrd_join](../thread/thrd_join.html)([thrd_t](../thread.html) thr, int* res);
    int [thrd_sleep](../thread/thrd_sleep.html)(const struct timespec* duration, struct timespec* remaining);
    void [thrd_yield](../thread/thrd_yield.html)(void);
    int [tss_create](../thread/tss_create.html)([tss_t](../thread.html)* key, [tss_dtor_t](../thread.html) dtor);
    void [tss_delete](../thread/tss_delete.html)([tss_t](../thread.html) key);
    void* [tss_get](../thread/tss_get.html)([tss_t](../thread.html) key);
    int [tss_set](../thread/tss_set.html)([tss_t](../thread.html) key, void* val);

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/threads&oldid=180751](https://en.cppreference.com/mwiki/index.php?title=c/header/threads&oldid=180751)" 

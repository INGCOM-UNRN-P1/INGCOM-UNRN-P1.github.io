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
**atomic_fetch_add**  
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
[kill_dependency](kill_dependency.html "c/atomic/kill dependency")  
  
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
C atomic_fetch_add( volatile A* obj, M arg ); |  (1)  |  (since C11)  
C atomic_fetch_add_explicit( volatile A* obj, M arg, [memory_order](memory_order.html) order ); |  (2)  |  (since C11)  
| |   
  
Atomically replaces the value pointed by `obj` with the result of addition of `arg` to the old value of `obj`, and returns the value `obj` held previously. The operation is read-modify-write operation. The first version orders memory accesses according to [memory_order_seq_cst](memory_order.html "c/atomic/memory order"), the second version orders memory accesses according to `order`. 

This is a [generic function](../language/generic.html "c/language/generic") defined for all [atomic object types](../language/atomic.html "c/language/atomic") `A`. The argument is pointer to a volatile atomic type to accept addresses of both non-volatile and [volatile](../language/volatile.html "c/language/volatile") (e.g. memory-mapped I/O) atomic objects, and volatile semantic is preserved when applying this operation to volatile atomic objects. `M` is either the non-atomic type corresponding to `A` if `A` is atomic integer type, or [ptrdiff_t](../types/ptrdiff_t.html "c/types/ptrdiff t") if `A` is atomic pointer type. 

It is unspecified whether the name of a generic function is a macro or an identifier declared with external linkage. If a macro definition is suppressed in order to access an actual function (e.g. parenthesized like (atomic_fetch_add)(...)), or a program defines an external identifier with the name of a generic function, the behavior is undefined. 

For signed integer types, arithmetic is defined to use two’s complement representation. There are no undefined results. For pointer types, the result may be an undefined address, but the operations otherwise have no undefined behavior. 

## Contents

  * [1 Parameters](atomic_fetch_add.html#Parameters)
  * [2 Return value](atomic_fetch_add.html#Return_value)
  * [3 Example](atomic_fetch_add.html#Example)
  * [4 References](atomic_fetch_add.html#References)
  * [5 See also](atomic_fetch_add.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_fetch_add&action=edit&section=1 "Edit section: Parameters")] Parameters

obj  |  \-  |  pointer to the atomic object to modify   
---|---|---  
arg  |  \-  |  the value to add to the value stored in the atomic object   
order  |  \-  |  the memory synchronization ordering for this operation: all values are permitted   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_fetch_add&action=edit&section=2 "Edit section: Return value")] Return value

The value held previously by the atomic object pointed to by `obj`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_fetch_add&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <threads.h>
    #include <stdatomic.h>
     
    [atomic_int](../atomic.html) acnt;
    int cnt;
     
    int f(void* thr_data)
    {
        for(int n = 0; n < 1000; ++n) {
            atomic_fetch_add_explicit(&acnt, 1, [memory_order_relaxed](memory_order.html)); // atomic
            ++cnt; // undefined behavior, in practice some updates missed
        }
        return 0;
    }
     
    int main(void)
    {
        [thrd_t](../thread.html) thr[10];
        for(int n = 0; n < 10; ++n)
            [thrd_create](../thread/thrd_create.html)(&thr[n], f, [NULL](../types/NULL.html));
        for(int n = 0; n < 10; ++n)
            [thrd_join](../thread/thrd_join.html)(thr[n], [NULL](../types/NULL.html));
     
        [printf](../io/fprintf.html)("The atomic counter is %u\n", acnt);
        [printf](../io/fprintf.html)("The non-atomic counter is %u\n", cnt);
    }

Possible output: 
    
    
    The atomic counter is 10000
    The non-atomic counter is 9511

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_fetch_add&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.17.7.5 The atomic_fetch and modify generic functions (p: 208) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.17.7.5 The atomic_fetch and modify generic functions (p: 284-285) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_fetch_add&action=edit&section=5 "Edit section: See also")] See also

[ atomic_fetch_subatomic_fetch_sub_explicit](atomic_fetch_sub.html "c/atomic/atomic fetch sub")(C11) |  atomic subtraction   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_fetch_sub&action=edit)  
---|---  
[C++ documentation](../../cpp/atomic/atomic_fetch_add.html "cpp/atomic/atomic fetch add") for atomic_fetch_add, atomic_fetch_add_explicit  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_fetch_add&oldid=138692](https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_fetch_add&oldid=138692)" 

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
**atomic_is_lock_free**  
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
_Bool atomic_is_lock_free( const volatile A* obj ); |  |  (since C11)  
| |   
  
Determines if the atomic operations on all objects of the type `A` (the type of the object pointed to by `obj`) are lock-free. In any given program execution, the result of calling `atomic_is_lock_free` is the same for all pointers of the same type. 

This is a [generic function](../language/generic.html "c/language/generic") defined for all [atomic object types](../language/atomic.html "c/language/atomic") `A`. The argument is pointer to a volatile atomic type to accept addresses of both non-volatile and [volatile](../language/volatile.html "c/language/volatile") (e.g. memory-mapped I/O) atomic objects, and volatile semantic is preserved when applying this operation to volatile atomic objects. 

It is unspecified whether the name of a generic function is a macro or an identifier declared with external linkage. If a macro definition is suppressed in order to access an actual function (e.g. parenthesized like (atomic_is_lock_free)(...)), or a program defines an external identifier with the name of a generic function, the behavior is undefined. 

## Contents

  * [1 Parameters](atomic_is_lock_free.html#Parameters)
  * [2 Return value](atomic_is_lock_free.html#Return_value)
  * [3 Example](atomic_is_lock_free.html#Example)
  * [4 Defect reports](atomic_is_lock_free.html#Defect_reports)
  * [5 References](atomic_is_lock_free.html#References)
  * [6 See also](atomic_is_lock_free.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_is_lock_free&action=edit&section=1 "Edit section: Parameters")] Parameters

obj  |  \-  |  pointer to the atomic object to inspect   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_is_lock_free&action=edit&section=2 "Edit section: Return value")] Return value

true if the operations on all objects of the type `A` are lock-free, false otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_is_lock_free&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdatomic.h>
     
    _Atomic struct A { int a[100]; } a;
    _Atomic struct B { int x, y; } b;
    int main(void)
    {
        [printf](../io/fprintf.html)("_Atomic struct A is lock free? %s\n", 
                atomic_is_lock_free(&a) ? "true" : "false");
        [printf](../io/fprintf.html)("_Atomic struct B is lock free? %s\n", 
                atomic_is_lock_free(&b) ? "true" : "false");
    }

Possible output: 
    
    
    _Atomic struct A is lock free? false
    _Atomic struct B is lock free? true

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_is_lock_free&action=edit&section=4 "Edit section: Defect reports")] Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards. 

DR  | Applied to  | Behavior as published  | Correct behavior   
---|---|---|---  
[DR 465](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_465) | C11  | this function was per-object  | this functions is per-type   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_is_lock_free&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.17.5.1 The atomic_is_lock_free generic function (p: 205) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.17.5.1 The atomic_is_lock_free generic function (p: 280) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_is_lock_free&action=edit&section=6 "Edit section: See also")] See also

[ ATOMIC_BOOL_LOCK_FREEATOMIC_CHAR_LOCK_FREEATOMIC_CHAR16_T_LOCK_FREEATOMIC_CHAR32_T_LOCK_FREEATOMIC_WCHAR_T_LOCK_FREEATOMIC_SHORT_LOCK_FREEATOMIC_INT_LOCK_FREEATOMIC_LONG_LOCK_FREEATOMIC_LLONG_LOCK_FREEATOMIC_POINTER_LOCK_FREE](ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts")(C11) |  indicates that the given atomic type is lock-free   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_ATOMIC_LOCK_FREE_consts&action=edit)  
---|---  
[C++ documentation](../../cpp/atomic/atomic_is_lock_free.html "cpp/atomic/atomic is lock free") for atomic_is_lock_free  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_is_lock_free&oldid=138687](https://en.cppreference.com/mwiki/index.php?title=c/atomic/atomic_is_lock_free&oldid=138687)" 

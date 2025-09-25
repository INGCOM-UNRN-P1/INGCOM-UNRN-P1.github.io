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
| **memory_order**  
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
enum memory_order  
{  
memory_order_relaxed,  
memory_order_consume,  
memory_order_acquire,  
memory_order_release,  
memory_order_acq_rel,  
memory_order_seq_cst  
}; |  |  (since C11)  
| |   
  
`memory_order` specifies how memory accesses, including regular, non-atomic memory accesses, are to be ordered around an atomic operation. Absent any constraints on a multi-core system, when multiple threads simultaneously read and write to several variables, one thread can observe the values change in an order different from the order another thread wrote them. Indeed, the apparent order of changes can even differ among multiple reader threads. Some similar effects can occur even on uniprocessor systems due to compiler transformations allowed by the memory model. 

The default behavior of all atomic operations in the [language](../language/atomic.html "c/language/atomic") and the library provides for _sequentially consistent ordering_ (see discussion below). That default can hurt performance, but the library's atomic operations can be given an additional `memory_order` argument to specify the exact constraints, beyond atomicity, that the compiler and processor must enforce for that operation. 

## Contents

  * [1 Constants](memory_order.html#Constants)
    * [1.1 Relaxed ordering](memory_order.html#Relaxed_ordering)
    * [1.2 Release-Consume ordering](memory_order.html#Release-Consume_ordering)
    * [1.3 Release sequence](memory_order.html#Release_sequence)
    * [1.4 Release-Acquire ordering](memory_order.html#Release-Acquire_ordering)
    * [1.5 Sequentially-consistent ordering](memory_order.html#Sequentially-consistent_ordering)
  * [2 Relationship with volatile](memory_order.html#Relationship_with_volatile)
  * [3 Examples](memory_order.html#Examples)
  * [4 References](memory_order.html#References)
  * [5 See also](memory_order.html#See_also)
  * [6 External links](memory_order.html#External_links)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/memory_order&action=edit&section=1 "Edit section: Constants")] Constants

Defined in header `[`<stdatomic.h>`](../header/stdatomic.html "c/header/stdatomic")`  
---  
Value  |  Explanation   
`memory_order_relaxed` |  Relaxed operation: there are no synchronization or ordering constraints imposed on other reads or writes, only this operation's atomicity is guaranteed (see [Relaxed ordering](memory_order.html#Relaxed_ordering) below).   
`memory_order_consume`  
(deprecated in C++26) |  A load operation with this memory order performs a _consume operation_ on the affected memory location: no reads or writes in the current thread dependent on the value currently loaded can be reordered before this load. Writes to data-dependent variables in other threads that release the same atomic variable are visible in the current thread. On most platforms, this affects compiler optimizations only (see [Release-Consume ordering](memory_order.html#Release-Consume_ordering) below).   
`memory_order_acquire` |  A load operation with this memory order performs the _acquire operation_ on the affected memory location: no reads or writes in the current thread can be reordered before this load. All writes in other threads that release the same atomic variable are visible in the current thread (see [Release-Acquire ordering](memory_order.html#Release-Acquire_ordering) below).   
`memory_order_release` |  A store operation with this memory order performs the _release operation_ : no reads or writes in the current thread can be reordered after this store. All writes in the current thread are visible in other threads that acquire the same atomic variable (see [Release-Acquire ordering](memory_order.html#Release-Acquire_ordering) below) and writes that carry a dependency into the atomic variable become visible in other threads that consume the same atomic (see [Release-Consume ordering](memory_order.html#Release-Consume_ordering) below).   
`memory_order_acq_rel` |  A read-modify-write operation with this memory order is both an _acquire operation_ and a _release operation_. No memory reads or writes in the current thread can be reordered before the load, nor after the store. All writes in other threads that release the same atomic variable are visible before the modification and the modification is visible in other threads that acquire the same atomic variable.   
`memory_order_seq_cst` |  A load operation with this memory order performs an _acquire operation_ , a store performs a _release operation_ , and read-modify-write performs both an _acquire operation_ and a _release operation_ , plus a single total order exists in which all threads observe all modifications in the same order (see [Sequentially-consistent ordering](memory_order.html#Sequentially-consistent_ordering) below).   
| This section is incomplete  
Reason: happens-before and other concepts, as in C++, but keep modification orders and the four consistencies in [c/language/atomic](../language/atomic.html "c/language/atomic")  
---|---  
| This section is incomplete  
Reason: when doing above, don't forget that although happens-before wasn't acyclic in C11 as published, this was updated to match C++11 via DR 401   
---|---  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/memory_order&action=edit&section=2 "Edit section: Relaxed ordering")] Relaxed ordering

Atomic operations tagged memory_order_relaxed are not synchronization operations; they do not impose an order among concurrent memory accesses. They only guarantee atomicity and modification order consistency. 

For example, with x and y initially zero, 

// Thread 1:  
r1 = [atomic_load_explicit](atomic_load.html)(y, memory_order_relaxed); // A  
[atomic_store_explicit](atomic_store.html)(x, r1, memory_order_relaxed); // B  
// Thread 2:  
r2 = [atomic_load_explicit](atomic_load.html)(x, memory_order_relaxed); // C  
[atomic_store_explicit](atomic_store.html)(y, 42, memory_order_relaxed); // D is allowed to produce r1 == r2 == 42 because, although A is _sequenced-before_ B within thread 1 and C is _sequenced before_ D within thread 2, nothing prevents D from appearing before A in the modification order of y, and B from appearing before C in the modification order of x. The side-effect of D on y could be visible to the load A in thread 1 while the side effect of B on x could be visible to the load C in thread 2. In particular, this may occur if D is completed before C in thread 2, either due to compiler reordering or at runtime. 

Typical use for relaxed memory ordering is incrementing counters, such as the reference counters , since this only requires atomicity, but not ordering or synchronization . 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/memory_order&action=edit&section=3 "Edit section: Release-Consume ordering")] Release-Consume ordering

If an atomic store in thread A is tagged memory_order_release, an atomic load in thread B from the same variable is tagged memory_order_consume, and the load in thread B reads a value written by the store in thread A, then the store in thread A is _dependency-ordered before_ the load in thread B. 

All memory writes (non-atomic and relaxed atomic) that _happened-before_ the atomic store from the point of view of thread A, become _visible side-effects_ within those operations in thread B into which the load operation _carries dependency_ , that is, once the atomic load is completed, those operators and functions in thread B that use the value obtained from the load are guaranteed to see what thread A wrote to memory. 

The synchronization is established only between the threads _releasing_ and _consuming_ the same atomic variable. Other threads can see different order of memory accesses than either or both of the synchronized threads. 

On all mainstream CPUs other than DEC Alpha, dependency ordering is automatic, no additional CPU instructions are issued for this synchronization mode, only certain compiler optimizations are affected (e.g. the compiler is prohibited from performing speculative loads on the objects that are involved in the dependency chain). 

Typical use cases for this ordering involve read access to rarely written concurrent data structures (routing tables, configuration, security policies, firewall rules, etc) and publisher-subscriber situations with pointer-mediated publication, that is, when the producer publishes a pointer through which the consumer can access information: there is no need to make everything else the producer wrote to memory visible to the consumer (which may be an expensive operation on weakly-ordered architectures). An example of such scenario is [`rcu_dereference`](https://en.wikipedia.org/wiki/Read-copy-update "enwiki:Read-copy-update"). 

Note that currently (2/2015) no known production compilers track dependency chains: consume operations are lifted to acquire operations. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/memory_order&action=edit&section=4 "Edit section: Release sequence")] Release sequence

If some atomic is store-released and several other threads perform read-modify-write operations on that atomic, a "release sequence" is formed: all threads that perform the read-modify-writes to the same atomic synchronize with the first thread and each other even if they have no `memory_order_release` semantics. This makes single producer - multiple consumers situations possible without imposing unnecessary synchronization between individual consumer threads. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/memory_order&action=edit&section=5 "Edit section: Release-Acquire ordering")] Release-Acquire ordering

If an atomic store in thread A is tagged memory_order_release, an atomic load in thread B from the same variable is tagged memory_order_acquire, and the load in thread B reads a value written by the store in thread A, then the store in thread A _synchronizes-with_ the load in thread B. 

All memory writes (including non-atomic and relaxed atomic) that _happened-before_ the atomic store from the point of view of thread A, become _visible side-effects_ in thread B. That is, once the atomic load is completed, thread B is guaranteed to see everything thread A wrote to memory. This promise only holds if B actually returns the value that A stored, or a value from later in the release sequence. 

The synchronization is established only between the threads _releasing_ and _acquiring_ the same atomic variable. Other threads can see different order of memory accesses than either or both of the synchronized threads. 

On strongly-ordered systems — x86, SPARC TSO, IBM mainframe, etc. — release-acquire ordering is automatic for the majority of operations. No additional CPU instructions are issued for this synchronization mode; only certain compiler optimizations are affected (e.g., the compiler is prohibited from moving non-atomic stores past the atomic store-release or performing non-atomic loads earlier than the atomic load-acquire). On weakly-ordered systems (ARM, Itanium, PowerPC), special CPU load or memory fence instructions are used. 

Mutual exclusion locks, such as [mutexes](../thread.html#Mutual_exclusion "c/thread") or [atomic spinlocks](atomic_flag_test_and_set.html "c/atomic/atomic flag test and set"), are an example of release-acquire synchronization: when the lock is released by thread A and acquired by thread B, everything that took place in the critical section (before the release) in the context of thread A has to be visible to thread B (after the acquire) which is executing the same critical section. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/memory_order&action=edit&section=6 "Edit section: Sequentially-consistent ordering")] Sequentially-consistent ordering

Atomic operations tagged memory_order_seq_cst not only order memory the same way as release/acquire ordering (everything that _happened-before_ a store in one thread becomes a _visible side effect_ in the thread that did a load), but also establish a _single total modification order_ of all atomic operations that are so tagged. 

Formally, 

each `memory_order_seq_cst` operation B that loads from atomic variable M, observes one of the following: 

  * the result of the last operation A that modified M, which appears before B in the single total order, 
  * OR, if there was such an A, B may observe the result of some modification on M that is not `memory_order_seq_cst` and does not _happen-before_ A, 
  * OR, if there wasn't such an A, B may observe the result of some unrelated modification of M that is not `memory_order_seq_cst`. 



If there was a `memory_order_seq_cst` [atomic_thread_fence](atomic_thread_fence.html "c/atomic/atomic thread fence") operation X _sequenced-before_ B, then B observes one of the following: 

  * the last `memory_order_seq_cst` modification of M that appears before X in the single total order, 
  * some unrelated modification of M that appears later in M's modification order. 



For a pair of atomic operations on M called A and B, where A writes and B reads M's value, if there are two `memory_order_seq_cst` [atomic_thread_fence](atomic_thread_fence.html "c/atomic/atomic thread fence")s X and Y, and if A is _sequenced-before_ X, Y is _sequenced-before_ B, and X appears before Y in the Single Total Order, then B observes either: 

  * the effect of A, 
  * some unrelated modification of M that appears after A in M's modification order. 



For a pair of atomic modifications of M called A and B, B occurs after A in M's modification order if 

  * there is a `memory_order_seq_cst` [atomic_thread_fence](atomic_thread_fence.html "c/atomic/atomic thread fence") X such that A is _sequenced-before_ X and X appears before B in the Single Total Order, 
  * or, there is a `memory_order_seq_cst` [atomic_thread_fence](atomic_thread_fence.html "c/atomic/atomic thread fence") Y such that Y is _sequenced-before_ B and A appears before Y in the Single Total Order, 
  * or, there are `memory_order_seq_cst` [atomic_thread_fence](atomic_thread_fence.html "c/atomic/atomic thread fence")s X and Y such that A is _sequenced-before_ X, Y is _sequenced-before_ B, and X appears before Y in the Single Total Order. 



Note that this means that: 

1) as soon as atomic operations that are not tagged `memory_order_seq_cst` enter the picture, the sequential consistency is lost,

2) the sequentially-consistent fences are only establishing total ordering for the fences themselves, not for the atomic operations in the general case (_sequenced-before_ is not a cross-thread relationship, unlike _happens-before_).

Sequential ordering may be necessary for multiple producer-multiple consumer situations where all consumers must observe the actions of all producers occurring in the same order. 

Total sequential ordering requires a full memory fence CPU instruction on all multi-core systems. This may become a performance bottleneck since it forces the affected memory accesses to propagate to every core. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/memory_order&action=edit&section=7 "Edit section: Relationship with volatile")] Relationship with volatile

Within a thread of execution, accesses (reads and writes) through [volatile lvalues](../language/volatile.html "c/language/volatile") cannot be reordered past observable side-effects (including other volatile accesses) that are separated by a sequence point within the same thread, but this order is not guaranteed to be observed by another thread, since volatile access does not establish inter-thread synchronization. 

In addition, volatile accesses are not atomic (concurrent read and write is a [data race](../language/memory_model.html "c/language/memory model")) and do not order memory (non-volatile memory accesses may be freely reordered around the volatile access). 

One notable exception is Visual Studio, where, with default settings, every volatile write has release semantics and every volatile read has acquire semantics ([Microsoft Docs](https://learn.microsoft.com/en-us/cpp/cpp/volatile-cpp)), and thus volatiles may be used for inter-thread synchronization. Standard volatile semantics are not applicable to multi-threaded programming, although they are sufficient for e.g. communication with a [signal](../program/signal.html "c/program/signal") handler that runs in the same thread when applied to [sig_atomic_t](../program/sig_atomic_t.html) variables. The compiler option `/volatile:iso` can be used to restore behavior consistent with the standard, which is the default setting when the target platform is ARM. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/memory_order&action=edit&section=8 "Edit section: Examples")] Examples

| This section is incomplete  
Reason: no example   
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/memory_order&action=edit&section=9 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.17.1/4 memory_order (p: TBD) 



    

  * 7.17.3 Order and consistency (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.17.1/4 memory_order (p: 200) 



    

  * 7.17.3 Order and consistency (p: 201-203) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.17.1/4 memory_order (p: 273) 



    

  * 7.17.3 Order and consistency (p: 275-277) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/memory_order&action=edit&section=10 "Edit section: See also")] See also

[C++ documentation](../../cpp/atomic/memory_order.html "cpp/atomic/memory order") for memory order  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic/memory_order&action=edit&section=11 "Edit section: External links")] External links

1\.  | [MOESI protocol](https://en.wikipedia.org/wiki/MOESI_protocol "enwiki:MOESI protocol")  
---|---  
2\.  | [x86-TSO: A Rigorous and Usable Programmer’s Model for x86 Multiprocessors](https://www.cl.cam.ac.uk/~pes20/weakmemory/cacm.pdf) P. Sewell et. al., 2010   
3\.  | [A Tutorial Introduction to the ARM and POWER Relaxed Memory Models](https://www.cl.cam.ac.uk/~pes20/ppc-supplemental/test7.pdf) P. Sewell et al, 2012   
4\.  | [MESIF: A Two-Hop Cache Coherency Protocol for Point-to-Point Interconnects](https://researchspace.auckland.ac.nz/bitstream/handle/2292/11594/MESIF-2009.pdf?sequence=6) J.R. Goodman, H.H.J. Hum, 2009   
5\.  | [Memory Models](https://research.swtch.com/mm) Russ Cox, 2021   
| This section is incomplete  
Reason: Let's find good refs on QPI, MOESI, and maybe Dragon.   
---|---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/atomic/memory_order&oldid=175729](https://en.cppreference.com/mwiki/index.php?title=c/atomic/memory_order&oldid=175729)" 

[Categories](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")
  * [Todo no example](../../Category%253ATodo_no_example.html "Category:Todo no example")



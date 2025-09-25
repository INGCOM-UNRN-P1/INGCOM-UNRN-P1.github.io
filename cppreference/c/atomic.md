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
[Concurrency support](thread.html "c/thread") (C11)  
[Technical Specifications](experimental.html "c/experimental")  
[Symbol index](index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

**Atomic operations library**

Types   
---  
[memory_order](atomic/memory_order.html "c/atomic/memory order")  
[atomic_flag](atomic/atomic_flag.html "c/atomic/atomic flag")  
Macros   
[ATOMIC_***_LOCK_FREE](atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts")  
[ATOMIC_FLAG_INIT](atomic/ATOMIC_FLAG_INIT.html "c/atomic/ATOMIC FLAG INIT")  
[ATOMIC_VAR_INIT](atomic/ATOMIC_VAR_INIT.html "c/atomic/ATOMIC VAR INIT")  
[kill_dependency](atomic/kill_dependency.html "c/atomic/kill dependency")  
Functions   
[atomic_flag_test_and_set](atomic/atomic_flag_test_and_set.html "c/atomic/atomic flag test and set")  
[atomic_flag_clear](atomic/atomic_flag_clear.html "c/atomic/atomic flag clear")  
[atomic_init](atomic/atomic_init.html "c/atomic/atomic init")  
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
[atomic_thread_fence](atomic/atomic_thread_fence.html "c/atomic/atomic thread fence")  
[atomic_signal_fence](atomic/atomic_signal_fence.html "c/atomic/atomic signal fence")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/navbar_content&action=edit)

If the macro constant `__STDC_NO_ATOMICS__`(C11) is defined by the compiler, the header `<stdatomic.h>`, the keyword _Atomic, and all of the names listed here are not provided. 

## Contents

  * [1 Types](atomic.html#Types)
  * [2 Macros](atomic.html#Macros)
  * [3 Functions](atomic.html#Functions)
  * [4 Types](atomic.html#Types_2)
  * [5 References](atomic.html#References)
  * [6 See also](atomic.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic&action=edit&section=1 "Edit section: Types")] Types

Defined in header `[`<stdatomic.h>`](header/stdatomic.html "c/header/stdatomic")`  
---  
[ memory_order](atomic/memory_order.html "c/atomic/memory order")(C11) |  defines memory ordering constraints   
(enum) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_memory_order&action=edit)  
[ atomic_flag](atomic/atomic_flag.html "c/atomic/atomic flag")(C11) |  lock-free atomic boolean flag   
(struct)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_flag&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic&action=edit&section=2 "Edit section: Macros")] Macros

Defined in header `[`<stdatomic.h>`](header/stdatomic.html "c/header/stdatomic")`  
---  
[ ATOMIC_BOOL_LOCK_FREEATOMIC_CHAR_LOCK_FREEATOMIC_CHAR16_T_LOCK_FREEATOMIC_CHAR32_T_LOCK_FREEATOMIC_WCHAR_T_LOCK_FREEATOMIC_SHORT_LOCK_FREEATOMIC_INT_LOCK_FREEATOMIC_LONG_LOCK_FREEATOMIC_LLONG_LOCK_FREEATOMIC_POINTER_LOCK_FREE](atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts")(C11) |  indicates that the given atomic type is lock-free   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_ATOMIC_LOCK_FREE_consts&action=edit)  
[ ATOMIC_FLAG_INIT](atomic/ATOMIC_FLAG_INIT.html "c/atomic/ATOMIC FLAG INIT")(C11) |  initializes a new [atomic_flag](atomic/atomic_flag.html)   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_ATOMIC_FLAG_INIT&action=edit)  
[ ATOMIC_VAR_INIT](atomic/ATOMIC_VAR_INIT.html "c/atomic/ATOMIC VAR INIT")(C11)(deprecated in C17)(removed in C23) |  initializes a new atomic object   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_ATOMIC_VAR_INIT&action=edit)  
[ kill_dependency](atomic/kill_dependency.html "c/atomic/kill dependency")(C11) |  breaks a dependency chain for [memory_order_consume](atomic/memory_order.html)   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_kill_dependency&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic&action=edit&section=3 "Edit section: Functions")] Functions

Defined in header `[`<stdatomic.h>`](header/stdatomic.html "c/header/stdatomic")`  
---  
[ atomic_flag_test_and_setatomic_flag_test_and_set_explicit](atomic/atomic_flag_test_and_set.html "c/atomic/atomic flag test and set")(C11) |  sets an atomic_flag to true and returns the old value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_flag_test_and_set&action=edit)  
[ atomic_flag_clearatomic_flag_clear_explicit](atomic/atomic_flag_clear.html "c/atomic/atomic flag clear")(C11) |  sets an atomic_flag to false   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_flag_clear&action=edit)  
[ atomic_init](atomic/atomic_init.html "c/atomic/atomic init")(C11) |  initializes an existing atomic object   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_init&action=edit)  
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
[ atomic_thread_fence](atomic/atomic_thread_fence.html "c/atomic/atomic thread fence")(C11) |  generic memory order-dependent fence synchronization primitive   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_thread_fence&action=edit)  
[ atomic_signal_fence](atomic/atomic_signal_fence.html "c/atomic/atomic signal fence")(C11) |  fence between a thread and a signal handler executed in the same thread   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_signal_fence&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic&action=edit&section=4 "Edit section: Types")] Types

The standard library offers convenience typedefs for the [core language atomic types](language/atomic.html "c/language/atomic"). 

Typedef name  |  Full type name   
---|---  
`atomic_bool` |  _Atomic _Bool  
`atomic_char` |  _Atomic char  
`atomic_schar` |  _Atomic signed char  
`atomic_uchar` |  _Atomic unsigned char  
`atomic_short` |  _Atomic short  
`atomic_ushort` |  _Atomic unsigned short  
`atomic_int` |  _Atomic int  
`atomic_uint` |  _Atomic unsigned int  
`atomic_long` |  _Atomic long  
`atomic_ulong` |  _Atomic unsigned long  
`atomic_llong` |  _Atomic long long  
`atomic_ullong` |  _Atomic unsigned long long  
`atomic_char8_t` (C23) |  _Atomic char8_t  
`atomic_char16_t` |  _Atomic char16_t  
`atomic_char32_t` |  _Atomic char32_t  
`atomic_wchar_t` |  _Atomic wchar_t  
`atomic_int_least8_t` |  _Atomic [int_least8_t](types/integer.html)  
`atomic_uint_least8_t` |  _Atomic [uint_least8_t](types/integer.html)  
`atomic_int_least16_t` |  _Atomic [int_least16_t](types/integer.html)  
`atomic_uint_least16_t` |  _Atomic [uint_least16_t](types/integer.html)  
`atomic_int_least32_t` |  _Atomic [int_least32_t](types/integer.html)  
`atomic_uint_least32_t` |  _Atomic [uint_least32_t](types/integer.html)  
`atomic_int_least64_t` |  _Atomic [int_least64_t](types/integer.html)  
`atomic_uint_least64_t` |  _Atomic [uint_least64_t](types/integer.html)  
`atomic_int_fast8_t` |  _Atomic [int_fast8_t](types/integer.html)  
`atomic_uint_fast8_t` |  _Atomic [uint_fast8_t](types/integer.html)  
`atomic_int_fast16_t` |  _Atomic [int_fast16_t](types/integer.html)  
`atomic_uint_fast16_t` |  _Atomic [uint_fast16_t](types/integer.html)  
`atomic_int_fast32_t` |  _Atomic [int_fast32_t](types/integer.html)  
`atomic_uint_fast32_t` |  _Atomic [uint_fast32_t](types/integer.html)  
`atomic_int_fast64_t` |  _Atomic [int_fast64_t](types/integer.html)  
`atomic_uint_fast64_t` |  _Atomic [uint_fast64_t](types/integer.html)  
`atomic_intptr_t` |  _Atomic [intptr_t](types/integer.html)  
`atomic_uintptr_t` |  _Atomic [uintptr_t](types/integer.html)  
`atomic_size_t` |  _Atomic [size_t](types/size_t.html)  
`atomic_ptrdiff_t` |  _Atomic [ptrdiff_t](types/ptrdiff_t.html)  
`atomic_intmax_t` |  _Atomic [intmax_t](types/integer.html)  
`atomic_uintmax_t` |  _Atomic [uintmax_t](types/integer.html)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.17 Atomics <stdatomic.h> (p: TBD) 



    

  * 7.31.8 Atomics <stdatomic.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.17 Atomics <stdatomic.h> (p: TBD) 



    

  * 7.31.8 Atomics <stdatomic.h> (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.17 Atomics <stdatomic.h> (p: 273-286) 



    

  * 7.31.8 Atomics <stdatomic.h> (p: 455-456) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/atomic&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../cpp/atomic.html "cpp/atomic") for Atomic operations library  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/atomic&oldid=156654](https://en.cppreference.com/mwiki/index.php?title=c/atomic&oldid=156654)" 

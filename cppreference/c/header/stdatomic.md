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
**`< stdatomic.h>`** (C11)` `  
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
[`<threads.h>`](threads.html "c/header/threads") (C11)  
[`<time.h>`](time.html "c/header/time")  
[`<uchar.h>`](uchar.html "c/header/uchar") (C11)  
[`<wchar.h>`](wchar.html "c/header/wchar") (C95)  
[`<wctype.h>`](wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header provides [atomic operations](../thread.html#Atomic_operations "c/thread"), in particular, it's a part of the [concurrency support](../thread.html "c/thread") library. 

## Contents

  * [1 Atomic operations](stdatomic.html#Atomic_operations)
    * [1.1 Operations on atomic types](stdatomic.html#Operations_on_atomic_types)
    * [1.2 Flag type and operations](stdatomic.html#Flag_type_and_operations)
    * [1.3 Initialization](stdatomic.html#Initialization)
    * [1.4 Memory synchronization ordering](stdatomic.html#Memory_synchronization_ordering)
    * [1.5 Convenience type aliases](stdatomic.html#Convenience_type_aliases)
  * [2 Synopsis](stdatomic.html#Synopsis)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/stdatomic&action=edit&section=1 "Edit section: Atomic operations")] Atomic operations

#####  Operations on atomic types   
  
---  
[ ATOMIC_BOOL_LOCK_FREEATOMIC_CHAR_LOCK_FREEATOMIC_CHAR16_T_LOCK_FREEATOMIC_CHAR32_T_LOCK_FREEATOMIC_WCHAR_T_LOCK_FREEATOMIC_SHORT_LOCK_FREEATOMIC_INT_LOCK_FREEATOMIC_LONG_LOCK_FREEATOMIC_LLONG_LOCK_FREEATOMIC_POINTER_LOCK_FREE](../atomic/ATOMIC_LOCK_FREE_consts.html "c/atomic/ATOMIC LOCK FREE consts")(C11) |  indicates that the given atomic type is lock-free   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_ATOMIC_LOCK_FREE_consts&action=edit)  
[ atomic_is_lock_free](../atomic/atomic_is_lock_free.html "c/atomic/atomic is lock free")(C11) |  indicates whether the atomic object is lock-free   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_is_lock_free&action=edit)  
[ atomic_storeatomic_store_explicit](../atomic/atomic_store.html "c/atomic/atomic store")(C11) |  stores a value in an atomic object   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_store&action=edit)  
[ atomic_loadatomic_load_explicit](../atomic/atomic_load.html "c/atomic/atomic load")(C11) |  reads a value from an atomic object   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_load&action=edit)  
[ atomic_exchangeatomic_exchange_explicit](../atomic/atomic_exchange.html "c/atomic/atomic exchange")(C11) |  swaps a value with the value of an atomic object   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_exchange&action=edit)  
[ atomic_compare_exchange_strongatomic_compare_exchange_strong_explicitatomic_compare_exchange_weakatomic_compare_exchange_weak_explicit](../atomic/atomic_compare_exchange.html "c/atomic/atomic compare exchange")(C11) |  swaps a value with an atomic object if the old value is what is expected, otherwise reads the old value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_compare_exchange&action=edit)  
[ atomic_fetch_addatomic_fetch_add_explicit](../atomic/atomic_fetch_add.html "c/atomic/atomic fetch add")(C11) |  atomic addition   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_fetch_add&action=edit)  
[ atomic_fetch_subatomic_fetch_sub_explicit](../atomic/atomic_fetch_sub.html "c/atomic/atomic fetch sub")(C11) |  atomic subtraction   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_fetch_sub&action=edit)  
[ atomic_fetch_oratomic_fetch_or_explicit](../atomic/atomic_fetch_or.html "c/atomic/atomic fetch or")(C11) |  atomic bitwise OR   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_fetch_or&action=edit)  
[ atomic_fetch_xoratomic_fetch_xor_explicit](../atomic/atomic_fetch_xor.html "c/atomic/atomic fetch xor")(C11) |  atomic bitwise exclusive OR   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_fetch_xor&action=edit)  
[ atomic_fetch_andatomic_fetch_and_explicit](../atomic/atomic_fetch_and.html "c/atomic/atomic fetch and")(C11) |  atomic bitwise AND   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_fetch_and&action=edit)  
  
#####  Flag type and operations   
  
[ atomic_flag](../atomic/atomic_flag.html "c/atomic/atomic flag")(C11) |  lock-free atomic boolean flag   
(struct)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_flag&action=edit)  
[ atomic_flag_test_and_setatomic_flag_test_and_set_explicit](../atomic/atomic_flag_test_and_set.html "c/atomic/atomic flag test and set")(C11) |  sets an atomic_flag to true and returns the old value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_flag_test_and_set&action=edit)  
[ atomic_flag_clearatomic_flag_clear_explicit](../atomic/atomic_flag_clear.html "c/atomic/atomic flag clear")(C11) |  sets an atomic_flag to false   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_flag_clear&action=edit)  
  
#####  Initialization   
  
[ atomic_init](../atomic/atomic_init.html "c/atomic/atomic init")(C11) |  initializes an existing atomic object   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_init&action=edit)  
[ ATOMIC_VAR_INIT](../atomic/ATOMIC_VAR_INIT.html "c/atomic/ATOMIC VAR INIT")(C11)(deprecated in C17)(removed in C23) |  initializes a new atomic object   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_ATOMIC_VAR_INIT&action=edit)  
[ ATOMIC_FLAG_INIT](../atomic/ATOMIC_FLAG_INIT.html "c/atomic/ATOMIC FLAG INIT")(C11) |  initializes a new [atomic_flag](../atomic/atomic_flag.html)   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_ATOMIC_FLAG_INIT&action=edit)  
  
#####  Memory synchronization ordering   
  
[ memory_order](../atomic/memory_order.html "c/atomic/memory order")(C11) |  defines memory ordering constraints   
(enum) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_memory_order&action=edit)  
[ kill_dependency](../atomic/kill_dependency.html "c/atomic/kill dependency")(C11) |  breaks a dependency chain for [memory_order_consume](../atomic/memory_order.html)   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_kill_dependency&action=edit)  
[ atomic_thread_fence](../atomic/atomic_thread_fence.html "c/atomic/atomic thread fence")(C11) |  generic memory order-dependent fence synchronization primitive   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_thread_fence&action=edit)  
[ atomic_signal_fence](../atomic/atomic_signal_fence.html "c/atomic/atomic signal fence")(C11) |  fence between a thread and a signal handler executed in the same thread   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/atomic/dsc_atomic_signal_fence&action=edit)  
  
#####  Convenience type aliases   
  
---  
Typedef name  |  Full type name   
`atomic_bool` (C11) |  _Atomic _Bool  
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
`atomic_int_least8_t` (C11) |  _Atomic [int_least8_t](../types/integer.html)  
`atomic_uint_least8_t` (C11) |  _Atomic [uint_least8_t](../types/integer.html)  
`atomic_int_least16_t` (C11) |  _Atomic [int_least16_t](../types/integer.html)  
`atomic_uint_least16_t` (C11) |  _Atomic [uint_least16_t](../types/integer.html)  
`atomic_int_least32_t` (C11) |  _Atomic [int_least32_t](../types/integer.html)  
`atomic_uint_least32_t` (C11) |  _Atomic [uint_least32_t](../types/integer.html)  
`atomic_int_least64_t` (C11) |  _Atomic [int_least64_t](../types/integer.html)  
`atomic_uint_least64_t` (C11) |  _Atomic [uint_least64_t](../types/integer.html)  
`atomic_int_fast8_t` (C11) |  _Atomic [int_fast8_t](../types/integer.html)  
`atomic_uint_fast8_t` (C11) |  _Atomic [uint_fast8_t](../types/integer.html)  
`atomic_int_fast16_t` (C11) |  _Atomic [int_fast16_t](../types/integer.html)  
`atomic_uint_fast16_t` (C11) |  _Atomic [uint_fast16_t](../types/integer.html)  
`atomic_int_fast32_t` (C11) |  _Atomic [int_fast32_t](../types/integer.html)  
`atomic_uint_fast32_t` (C11) |  _Atomic [uint_fast32_t](../types/integer.html)  
`atomic_int_fast64_t` (C11) |  _Atomic [int_fast64_t](../types/integer.html)  
`atomic_uint_fast64_t` (C11) |  _Atomic [uint_fast64_t](../types/integer.html)  
`atomic_intptr_t` (C11) |  _Atomic [intptr_t](../types/integer.html)  
`atomic_uintptr_t` (C11) |  _Atomic [uintptr_t](../types/integer.html)  
`atomic_size_t` (C11) |  _Atomic [size_t](../types/size_t.html)  
`atomic_ptrdiff_t` (C11) |  _Atomic [ptrdiff_t](../types/ptrdiff_t.html)  
`atomic_intmax_t` (C11) |  _Atomic [intmax_t](../types/integer.html)  
`atomic_uintmax_t` (C11) |  _Atomic [uintmax_t](../types/integer.html)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/stdatomic&action=edit&section=2 "Edit section: Synopsis")] Synopsis

| This section is incomplete  
Reason: add more from 7.17 Atomics <stdatomic.h> and B.16 Atomics <stdatomic.h>  
---|---  
      
    
    #define __STDC_VERSION_STDATOMIC_H__ 202311L
     
    void [atomic_init](../atomic/atomic_init.html)(volatile A* obj, /*C*/ value);
    /*type*/ [kill_dependency](../atomic/kill_dependency.html)(/*type*/ y);
    void [atomic_thread_fence](../atomic/atomic_thread_fence.html)([memory_order](../atomic/memory_order.html) order);
    void [atomic_signal_fence](../atomic/atomic_signal_fence.html)([memory_order](../atomic/memory_order.html) order);
    bool [atomic_is_lock_free](../atomic/atomic_is_lock_free.html)(const volatile A* obj);
    void [atomic_store](../atomic/atomic_store.html)(volatile A* object, /*C*/ desired);
    void [atomic_store_explicit](../atomic/atomic_store.html)(volatile A* object, /*C*/ desired, [memory_order](../atomic/memory_order.html) order);
    /*C*/ [atomic_load](../atomic/atomic_load.html)(const volatile A* object);
    /*C*/ [atomic_load_explicit](../atomic/atomic_load.html)(const volatile A* object, [memory_order](../atomic/memory_order.html) order);
    /*C*/ [atomic_exchange](../atomic/atomic_exchange.html)(volatile A* object, /*C*/ desired);
    /*C*/ [atomic_exchange_explicit](../atomic/atomic_exchange.html)(volatile A* object, /*C*/ desired, [memory_order](../atomic/memory_order.html) order);
    bool [atomic_compare_exchange_strong](../atomic/atomic_compare_exchange.html)(volatile A* object, /*C*/* expected, /*C*/ desired);
    bool [atomic_compare_exchange_strong_explicit](../atomic/atomic_compare_exchange.html)(volatile A* object, /*C*/* expected,
    /*C*/ desired, [memory_order](../atomic/memory_order.html) success, [memory_order](../atomic/memory_order.html) failure);
    bool [atomic_compare_exchange_weak](../atomic/atomic_compare_exchange.html)(volatile A* object, /*C*/* expected, /*C*/ desired);
    bool [atomic_compare_exchange_weak_explicit](../atomic/atomic_compare_exchange.html)(volatile A* object, /*C*/* expected,
    /*C*/ desired, [memory_order](../atomic/memory_order.html) success, [memory_order](../atomic/memory_order.html) failure);
    /*C*/ /*atomic_fetch_key*/(volatile A* object, M operand);
    /*C*/ /*atomic_fetch_key_explicit*/(volatile A* object, M operand, [memory_order](../atomic/memory_order.html) order);
    bool [atomic_flag_test_and_set](../atomic/atomic_flag_test_and_set.html)(volatile [atomic_flag](../atomic/atomic_flag.html)* object);
    bool [atomic_flag_test_and_set_explicit](../atomic/atomic_flag_test_and_set.html)(volatile [atomic_flag](../atomic/atomic_flag.html)* object,
    [memory_order](../atomic/memory_order.html) order);
    void [atomic_flag_clear](../atomic/atomic_flag_clear.html)(volatile [atomic_flag](../atomic/atomic_flag.html)* object);
    void [atomic_flag_clear_explicit](../atomic/atomic_flag_clear.html)(volatile [atomic_flag](../atomic/atomic_flag.html)* object,
                                    [memory_order](../atomic/memory_order.html) order);

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/stdatomic&oldid=180140](https://en.cppreference.com/mwiki/index.php?title=c/header/stdatomic&oldid=180140)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



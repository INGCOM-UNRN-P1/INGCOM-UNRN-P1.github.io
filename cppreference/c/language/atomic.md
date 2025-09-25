From cppreference.com

< [c](../../c.html "c")‎ | [language](../language.html "c/language")

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

[ C language](../language.html "c/language")

[Basic concepts](basic_concepts.html "c/language/basic concepts")  
---  
[ Keywords](../keyword.html "c/keyword")  
[ Preprocessor](../preprocessor.html "c/preprocessor")  
[ Statements](statements.html "c/language/statements")  
[ Expressions](operators.html "c/language/expressions")  
[ Initialization](initialization.html "c/language/initialization")  
[ Declarations](declarations.html "c/language/declarations")  
[ Functions](functions.html "c/language/functions")  
Miscellaneous  
[ History of C](history.html "c/language/history")  
[Technical Specifications](../experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

[ Declarations](declarations.html "c/language/declarations")

[Pointer](pointer.html "c/language/pointer")  
---  
[Array](array.html "c/language/array")  
[enum](enum.html "c/language/enum")  
[struct](struct.html "c/language/struct")  
[union](union.html "c/language/union")  
[Bit-field](bit_field.html "c/language/bit field")  
**Atomic types** (C11)  
[const](const.html "c/language/const")  
[constexpr](constexpr.html "c/language/constexpr")(C23)  
[volatile](volatile.html "c/language/volatile")  
[restrict](restrict.html "c/language/restrict")(C99)  
[Alignment specifiers](alignas.html "c/language/ Alignas")  
[Storage duration and linkage](storage_class_specifiers.html "c/language/storage duration")  
[External and tentative definitions](extern.html "c/language/extern")  
[typedef](typedef.html "c/language/typedef")  
[Static assertions](static_assert.html "c/language/ Static assert")  
[Attributes](attributes.html "c/language/attributes") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/declarations/navbar_content&action=edit)

## Contents

  * [1 Syntax](atomic.html#Syntax)
  * [2 Explanation](atomic.html#Explanation)
  * [3 Notes](atomic.html#Notes)
  * [4 Keywords](atomic.html#Keywords)
  * [5 Example](atomic.html#Example)
  * [6 References](atomic.html#References)
  * [7 See also](atomic.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/atomic&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**_Atomic**` `**(**` type-name `**)**` |  (1)  |  (since C11)  
`**_Atomic**` type-name |  (2)  |  (since C11)  
  
1) Use as a type specifier; this designates a new atomic type

2) Use as a type qualifier; this designates the atomic version of type-name. In this role, it may be mixed with [`const`](const.html "c/language/const"), [`volatile`](volatile.html "c/language/volatile"), and [`restrict`](restrict.html "c/language/restrict"), although unlike other qualifiers, the atomic version of type-name may have a different size, alignment, and object representation.

type-name |  \-  |  any type other than array or function. For (1), type-name also cannot be atomic or cvr-qualified   
---|---|---  
  
The header [`<stdatomic.h>`](../header/stdatomic.html "c/header/stdatomic") defines [many convenience type aliases](../thread.html#Atomic_operations "c/thread"), from [`atomic_bool`](../thread.html#Atomic_operations "c/thread") to [`atomic_uintmax_t`](../thread.html#Atomic_operations "c/thread"), which simplify the use of this keyword with built-in and library types. 
    
    
    _Atomic const int* p1;  // p is a pointer to an atomic const int
    const [atomic_int](../atomic.html)* p2;   // same
    const _Atomic(int)* p3; // same

If the macro constant __STDC_NO_ATOMICS__ is defined by the compiler, the keyword _Atomic is not provided. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/atomic&action=edit&section=2 "Edit section: Explanation")] Explanation

Objects of atomic types are the only objects that are free from [data races](memory_model.html "c/language/memory model"); that is, they may be modified by two threads concurrently or modified by one and read by another. 

Each atomic object has its own associated _modification order_ , which is a total order of modifications made to that object. If, from some thread's point of view, modification `A` of some atomic `M` [happens-before](../atomic/memory_order.html "c/atomic/memory order") modification `B` of the same atomic `M`, then in the modification order of `M`, `A` occurs before `B`. 

Note that although each atomic object has its own modification order, there is no single total order; different threads may observe modifications to different atomic objects in different orders. 

There are four coherence kinds that are guaranteed for all atomic operations: 

  1. **write-write coherence** : If an operation `A` that modifies an atomic object `M` _happens-before_ an operation `B` that modifies `M`, then `A` appears earlier than `B` in the modification order of `M`. 
  2. **read-read coherence** : If a value computation `A` of an atomic object `M` happens before a value computation `B` of `M`, and `A` takes its value from a side effect `X` on `M`, then the value computed by `B` is either the value stored by `X` or is the value stored by a side effect `Y` on `M`, where `Y` appears later than `X` in the modification order of `M`. 
  3. **read-write coherence** : If a value computation `A` of an atomic object `M` _happens-before_ an operation `B` on `M`, then `A` takes its value from a side effect `X` on `M`, where `X` appears before `B` in the modification order of `M`. 
  4. **write-read coherence** : If a side effect `X` on an atomic object `M` _happens-before_ a value computation `B` of `M`, then the evaluation `B` takes its value from `X` or from a side effect `Y` that appears after `X` in the modification order of `M`. 



Some atomic operations are also synchronization operations; they may have additional release semantics, acquire semantics, or sequentially-consistent semantics. See [memory_order](../atomic/memory_order.html "c/atomic/memory order"). 

Built-in [increment and decrement operators](operator_incdec.html "c/language/operator incdec") and [compound assignment](operator_assignment.html "c/language/operator assignment") are read-modify-write atomic operations with total sequentially consistent ordering (as if using [memory_order_seq_cst](../atomic/memory_order.html "c/atomic/memory order")). If less strict synchronization semantics are desired, the [standard library functions](../thread.html#Atomic_operations "c/thread") may be used instead. 

Atomic properties are only meaningful for [lvalue expressions](value_category.html "c/language/value category"). Lvalue-to-rvalue conversion (which models a memory read from an atomic location to a CPU register) strips atomicity along with other qualifiers. 

| This section is incomplete  
Reason: more, review interaction with memory_order and atomic library pages   
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/atomic&action=edit&section=3 "Edit section: Notes")] Notes

Accessing a member of an atomic struct/union is undefined behavior. 

The library type [sig_atomic_t](../program/sig_atomic_t.html) does not provide inter-thread synchronization or memory ordering, only atomicity. 

The [`volatile`](volatile.html "c/language/volatile") types do not provide inter-thread synchronization, memory ordering, or atomicity. 

Implementations are recommended to ensure that the representation of _Atomic(T) in C is same as that of std::atomic<T> in C++ for every possible type `T`. The mechanisms used to ensure atomicity and memory ordering should be compatible. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/atomic&action=edit&section=4 "Edit section: Keywords")] Keywords

[`_Atomic`](../keyword/_Atomic.html "c/keyword/ Atomic")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/atomic&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdatomic.h>
    #include <stdio.h>
    #include <threads.h>
     
    [atomic_int](../atomic.html) acnt;
    int cnt;
     
    int f(void* thr_data)
    {
        for (int n = 0; n < 1000; ++n)
        {
            ++cnt;
            ++acnt;
            // for this example, relaxed memory order is sufficient, e.g.
            // atomic_fetch_add_explicit(&acnt, 1, memory_order_relaxed);
        }
        return 0;
    }
     
    int main(void)
    {
        [thrd_t](../thread.html) thr[10];
        for (int n = 0; n < 10; ++n)
            [thrd_create](../thread/thrd_create.html)(&thr[n], f, [NULL](../types/NULL.html));
        for (int n = 0; n < 10; ++n)
            [thrd_join](../thread/thrd_join.html)(thr[n], [NULL](../types/NULL.html));
     
        [printf](../io/fprintf.html)("The atomic counter is %u\n", acnt);
        [printf](../io/fprintf.html)("The non-atomic counter is %u\n", cnt);
    }

Possible output: 
    
    
    The atomic counter is 10000
    The non-atomic counter is 8644

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/atomic&action=edit&section=6 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.2.4 Atomic type specifiers (p: TBD) 



    

  * 7.17 Atomics <stdatomic.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.2.4 Atomic type specifiers (p: 87) 



    

  * 7.17 Atomics <stdatomic.h> (p: 200-209) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.2.4 Atomic type specifiers (p: 121) 



    

  * 7.17 Atomics <stdatomic.h> (p: 273-286) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/atomic&action=edit&section=7 "Edit section: See also")] See also

**[Concurrency support library](../thread.html "c/thread")**  
---  
[C++ documentation](../../cpp/atomic/atomic.html "cpp/atomic/atomic") for atomic  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/atomic&oldid=180497](https://en.cppreference.com/mwiki/index.php?title=c/language/atomic&oldid=180497)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



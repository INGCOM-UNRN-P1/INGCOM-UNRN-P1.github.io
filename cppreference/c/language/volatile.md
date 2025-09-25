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
[Atomic types](atomic.html "c/language/atomic") (C11)  
[const](const.html "c/language/const")  
[constexpr](constexpr.html "c/language/constexpr")(C23)  
**volatile**  
[restrict](restrict.html "c/language/restrict")(C99)  
[Alignment specifiers](alignas.html "c/language/ Alignas")  
[Storage duration and linkage](storage_class_specifiers.html "c/language/storage duration")  
[External and tentative definitions](extern.html "c/language/extern")  
[typedef](typedef.html "c/language/typedef")  
[Static assertions](static_assert.html "c/language/ Static assert")  
[Attributes](attributes.html "c/language/attributes") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/declarations/navbar_content&action=edit)

Each individual type in the C [type system](compatible_type.html "c/language/type") has several _qualified_ versions of that type, corresponding to one, two, or all three of the [`const`](const.html "c/language/const"), `volatile`, and, for pointers to object types, [`restrict`](restrict.html "c/language/restrict") qualifiers. This page describes the effects of the `volatile` qualifier. 

Every access (both read and write) made through an lvalue expression of volatile-qualified type is considered an observable side effect for the purpose of optimization and is evaluated strictly according to the rules of the abstract machine (that is, all writes are completed at some time before the next sequence point). This means that within a single thread of execution, a volatile access cannot be optimized out or reordered relative to another visible side effect that is separated by a [sequence point](eval_order.html "c/language/eval order") from the volatile access. 

A cast of a non-volatile value to a volatile type has no effect. To access a non-volatile object using volatile semantics, its address must be cast to a pointer-to-volatile and then the access must be made through that pointer. 

Any attempt to read or write to an object whose type is volatile-qualified through a non-volatile lvalue results in undefined behavior: 
    
    
    volatile int n = 1; // object of volatile-qualified type
    int* p = (int*)&n;
    int val = *p; // undefined behavior

A member of a volatile-qualified structure or union type acquires the qualification of the type it belongs to (both when accessed using the `**.**` operator or the `**- >**` operator): 
    
    
    struct s { int i; const int ci; } s;
    // the type of s.i is int, the type of s.ci is const int
    volatile struct s vs;
    // the types of vs.i and vs.ci are volatile int and const volatile int

If an array type is declared with the volatile type qualifier (through the use of [`typedef`](typedef.html "c/language/typedef")), the array type is not volatile-qualified, but its element type is.  | (until C23)  
---|---  
An array type and its element type are always considered to be identically volatile-qualified.  | (since C23)  
      
    
    typedef int A[2][3];
    volatile A a = {{4, 5, 6}, {7, 8, 9}}; // array of array of volatile int
    int* pi = a[0]; // Error: a[0] has type volatile int*
    void *unqual_ptr = a; // OK until C23; error since C23
    // Notes: clang applies the rule in C++/C23 even in C89-C17 modes

If a function type is declared with the volatile type qualified (through the use of [`typedef`](typedef.html "c/language/typedef")), the behavior is undefined. 

In a function declaration, the keyword `volatile` may appear inside the square brackets that are used to declare an array type of a function parameter. It qualifies the pointer type to which the array type is transformed. The following two declarations declare the same function: 
    
    
    void f(double x[volatile], const double y[volatile]);
    void f(double * volatile x, const double * volatile y);

| (since C99)  
---|---  
  
A pointer to a non-volatile type can be implicitly converted to a pointer to the volatile-qualified version of the same or [compatible](compatible_type.html "c/language/compatible type") type. The reverse conversion requires a cast expression. 
    
    
    int* p = 0;
    volatile int* vp = p; // OK: adds qualifiers (int to volatile int)
    p = vp; // Error: discards qualifiers (volatile int to int)
    p = (int*)vp; // OK: cast

Note that pointer to pointer to `T` is not convertible to pointer to pointer to `volatile T`; for two types to be compatible, their qualifications must be identical: 
    
    
    char *p = 0;
    volatile char **vpp = &p; // Error: char* and volatile char* are not compatible types
    char * volatile *pvp = &p; // OK, adds qualifiers (char* to char*volatile)

## Contents

  * [1 Uses of volatile](volatile.html#Uses_of_volatile)
  * [2 Keywords](volatile.html#Keywords)
  * [3 Example](volatile.html#Example)
  * [4 References](volatile.html#References)
  * [5 See also](volatile.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/volatile&action=edit&section=1 "Edit section: Uses of volatile")] Uses of volatile

1) [`static`](static_storage_duration.html "c/language/static storage duration") `volatile` objects model memory-mapped I/O ports, and `static` `const` `volatile` objects model memory-mapped input ports, such as a real-time clock: 
    
    
    volatile short *ttyport = (volatile short*)TTYPORT_ADDR;
    for(int i = 0; i < N; ++i)
        *ttyport = a[i]; // *ttyport is an lvalue of type volatile short

2) `static` `volatile` objects of type [sig_atomic_t](../program/sig_atomic_t.html "c/program/sig atomic t") are used for communication with [signal](../program/signal.html "c/program/signal") handlers.

3) `volatile` variables that are local to a function that contains an invocation of the [setjmp](../program/setjmp.html "c/program/setjmp") macro are the only local variables guaranteed to retain their values after [longjmp](../program/longjmp.html "c/program/longjmp") returns.

4) In addition, volatile variables can be used to disable certain forms of optimization, e.g. to disable dead store elimination or constant folding for micro-benchmarks.

Note that volatile variables are not suitable for communication between threads; they do not offer atomicity, synchronization, or memory ordering. A read from a volatile variable that is modified by another thread without synchronization or concurrent modification from two unsynchronized threads is undefined behavior due to a data race. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/volatile&action=edit&section=2 "Edit section: Keywords")] Keywords

[`volatile`](../../cpp/keyword/volatile.html "cpp/keyword/volatile")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/volatile&action=edit&section=3 "Edit section: Example")] Example

demonstrates the use of volatile to disable optimizations

Run this code
    
    
    #include <stdio.h>
    #include <time.h>
     
    int main(void)
    {
        [clock_t](../chrono/clock_t.html) t = [clock](../chrono/clock.html)();
        double d = 0.0;
        for (int n = 0; n < 10000; ++n)
            for (int m = 0; m < 10000; ++m)
                d += d * n * m; // reads from and writes to a non-volatile 
        [printf](../io/fprintf.html)("Modified a non-volatile variable 100m times. "
               "Time used: %.2f seconds\n",
               (double)([clock](../chrono/clock.html)() - t)/[CLOCKS_PER_SEC](../chrono/CLOCKS_PER_SEC.html));
     
        t = [clock](../chrono/clock.html)();
        volatile double vd = 0.0;
        for (int n = 0; n < 10000; ++n)
            for (int m = 0; m < 10000; ++m) {
                double prod = vd * n * m; // reads from a volatile
                vd += prod; // reads from and writes to a volatile
            } 
        [printf](../io/fprintf.html)("Modified a volatile variable 100m times. "
               "Time used: %.2f seconds\n",
               (double)([clock](../chrono/clock.html)() - t)/[CLOCKS_PER_SEC](../chrono/CLOCKS_PER_SEC.html));
    }

Possible output: 
    
    
    Modified a non-volatile variable 100m times. Time used: 0.00 seconds
    Modified a volatile variable 100m times. Time used: 0.79 seconds

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/volatile&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.3 Type qualifiers (p: 87-90) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.3 Type qualifiers (p: 121-123) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.7.3 Type qualifiers (p: 108-110) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 6.5.3 Type qualifiers 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/volatile&action=edit&section=5 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/cv.html "cpp/language/cv") for cv (`const` and `volatile`) type qualifiers  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/volatile&oldid=154455](https://en.cppreference.com/mwiki/index.php?title=c/language/volatile&oldid=154455)" 

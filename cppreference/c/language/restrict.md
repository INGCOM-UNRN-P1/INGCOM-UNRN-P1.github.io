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
[volatile](volatile.html "c/language/volatile")  
**restrict**(C99)  
[Alignment specifiers](alignas.html "c/language/ Alignas")  
[Storage duration and linkage](storage_class_specifiers.html "c/language/storage duration")  
[External and tentative definitions](extern.html "c/language/extern")  
[typedef](typedef.html "c/language/typedef")  
[Static assertions](static_assert.html "c/language/ Static assert")  
[Attributes](attributes.html "c/language/attributes") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/declarations/navbar_content&action=edit)

Each individual type in the C [type system](compatible_type.html "c/language/type") has several _qualified_ versions of that type, corresponding to one, two, or all three of the [`const`](const.html "c/language/const"), [`volatile`](volatile.html "c/language/volatile"), and, for pointers to object types, `restrict` qualifiers. This page describes the effects of the `restrict` qualifier. 

Only a pointer to an [object type](compatible_type.html "c/language/type") or a (possibly multi-dimensional) array thereof(since C23) may be restrict-qualified; in particular, the following are _erroneous_ : 

  * int restrict *p
  * float (* restrict f9)(void)



Restrict semantics apply to lvalue expressions only; for example, a cast to restrict-qualified pointer or a function call returning a restrict-qualified pointer are not lvalues and the qualifier has no effect. 

During each execution of a block in which a restricted pointer `P` is declared (typically each execution of a function body in which `P` is a function parameter), if some object that is accessible through `P` (directly or indirectly) is modified, by any means, then all accesses to that object (both reads and writes) in that block must occur through `P` (directly or indirectly), otherwise the behavior is undefined: 
    
    
    void f(int n, int * restrict p, int * restrict q)
    {
        while (n-- > 0)
            *p++ = *q++; // none of the objects modified through *p is the same
                         // as any of the objects read through *q
                         // compiler free to optimize, vectorize, page map, etc.
    }
     
    void g(void)
    {
        extern int d[100];
        f(50, d + 50, d); // OK
        f(50, d + 1, d);  // Undefined behavior: d[1] is accessed through both p and q in f
    }

If the object is never modified, it may be aliased and accessed through different restrict-qualified pointers (note that if the objects pointed to by aliased restrict-qualified pointers are, in turn, pointers, this aliasing can inhibit optimization). 

Assignment from one restricted pointer to another is undefined behavior, except when assigning from a pointer to an object in some outer block to a pointer in some inner block (including using a restricted pointer argument when calling a function with a restricted pointer parameter) or when returning from a function (and otherwise when the block of the from-pointer ended): 
    
    
    int* restrict p1 = &a;
    int* restrict p2 = &b;
    p1 = p2; // undefined behavior

Restricted pointers can be assigned to unrestricted pointers freely, the optimization opportunities remain in place as long as the compiler is able to analyze the code: 
    
    
    void f(int n, float * restrict r, float * restrict s)
    {
        float *p = r, *q = s; // OK
        while (n-- > 0)
            *p++ = *q++; // almost certainly optimized just like *r++ = *s++
    }

If an array type is declared with the restrict type qualifier (through the use of [typedef](typedef.html "c/language/typedef")), the array type is not restrict-qualified, but its element type is:  | (until C23)  
---|---  
An array type and its element type are always considered to be identically restrict-qualified:  | (since C23)  
      
    
    typedef int *array_t[10];
     
    restrict array_t a; // the type of a is int *restrict[10]
    // Notes: clang and icc reject this on the grounds that array_t is not a pointer type
     
    void *unqual_ptr = &a; // OK until C23; error since C23
    // Notes: clang applies the rule in C++/C23 even in C89-C17 modes

In a function declaration, the keyword `restrict` may appear inside the square brackets that are used to declare an array type of a function parameter. It qualifies the pointer type to which the array type is transformed: 
    
    
    void f(int m, int n, float a[restrict m][n], float b[restrict m][n]);
     
    void g12(int n, float (*p)[n])
    {
       f(10, n, p, p+10); // OK
       f(20, n, p, p+10); // possibly undefined behavior (depending on what f does)
    }

## Contents

  * [1 Notes](restrict.html#Notes)
  * [2 Usage patterns](restrict.html#Usage_patterns)
    * [2.1 File scope](restrict.html#File_scope)
    * [2.2 Function parameter](restrict.html#Function_parameter)
    * [2.3 Block scope](restrict.html#Block_scope)
    * [2.4 Struct members](restrict.html#Struct_members)
  * [3 Keywords](restrict.html#Keywords)
  * [4 Example](restrict.html#Example)
  * [5 References](restrict.html#References)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/restrict&action=edit&section=1 "Edit section: Notes")] Notes

The intended use of the restrict qualifier (like the register storage class) is to promote optimization, and deleting all instances of the qualifier from all preprocessing translation units composing a conforming program does not change its meaning (i.e., observable behavior). 

The compiler is free to ignore any or all aliasing implications of uses of `restrict`. 

To avoid undefined behavior, the programmer must ensure that the aliasing assertions made by the restrict-qualified pointers are not violated. 

Many compilers provide, as a language extension, the opposite of `restrict`: an attribute indicating that pointers may alias even if their types differ: [`may_alias`](https://gcc.gnu.org/onlinedocs/gcc/Common-Type-Attributes.html#index-g_t_0040code_007bmay_005falias_007d-type-attribute-3667) (gcc), 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/restrict&action=edit&section=2 "Edit section: Usage patterns")] Usage patterns

There are several common usage patterns for restrict-qualified pointers: 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/restrict&action=edit&section=3 "Edit section: File scope")] File scope

A file-scope restrict-qualified pointer has to point into a single array object for the duration of the program. That array object may not be referenced both through the restricted pointer and through either its declared name (if it has one) or another restricted pointer. 

File scope restricted pointers are useful in providing access to dynamically allocated global arrays; the restrict semantics make it possible to optimize references through this pointer as effectively as references to a static array through its declared name: 
    
    
    float *restrict a, *restrict b;
    float c[100];
     
    int init(int n)
    {
       float * t = [malloc](../memory/malloc.html)(2*n*sizeof(float));
       a = t;      // a refers to 1st half
       b = t + n;  // b refers to 2nd half
    }
    // compiler can deduce from the restrict qualifiers that
    // there is no potential aliasing among the names a, b, and c

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/restrict&action=edit&section=4 "Edit section: Function parameter")] Function parameter

The most popular use case for restrict-qualified pointers is the use as function parameters. 

In the following example, the compiler may infer that there is no aliasing of modified objects, and so optimize the loop aggressively. Upon entry to `f`, the restricted pointer a must provide exclusive access to its associated array. In particular, within `f` neither `b` nor `c` may point into the array associated with `a`, because neither is assigned a pointer value based on `a`. For `b`, this is evident from the const-qualifier in its declaration, but for `c`, an inspection of the body of `f` is required: 
    
    
    float x[100];
    float *c;
     
    void f(int n, float * restrict a, float * const b)
    {
        int i;
        for ( i=0; i<n; i++ )
           a[i] = b[i] + c[i];
    }
     
    void g3(void)
    {
        float d[100], e[100];
        c = x; f(100,   d,    e); // OK
               f( 50,   d, d+50); // OK
               f( 99, d+1,    d); // undefined behavior
        c = d; f( 99, d+1,    e); // undefined behavior
               f( 99,   e,  d+1); // OK
    }

Note that it is permitted for c to point into the array associated with b. Note also that, for these purposes, the "array" associated with a particular pointer means only that portion of an array object which is actually referenced through that pointer. 

Note that in the example above, the compiler can infer that a and b do not alias because b's constness guarantees that it cannot become dependent on a in the body of the function. Equivalently, the programmer could write void f(int n, float * a, float const * restrict b), in which case the compiler can reason that objects referenced through b cannot be modified, and so no modified object can be referenced using both b and a. If the programmer were to write void f(int n, float * restrict a, float * b), the compiler would be unable to infer non-aliasing of a and b without examining the body of the function. 

In general, it is best to explicitly annotate all non-aliasing pointers in a function's prototype with restrict. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/restrict&action=edit&section=5 "Edit section: Block scope")] Block scope

A block scope restrict-qualified pointer makes an aliasing assertion that is limited to its block. It allows local assertions that apply only to important blocks, such as tight loops. It also makes it possible to convert a function that takes restrict-qualified pointers into a macro: 
    
    
    float x[100];
    float *c;
     
    #define f3(N, A, B)                                    \
    do                                                     \
    {   int n = (N);                                       \
        float * restrict a = (A);                          \
        float * const    b = (B);                          \
        int i;                                             \
        for ( i=0; i<n; i++ )                              \
            a[i] = b[i] + c[i];                            \
    } while(0)

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/restrict&action=edit&section=6 "Edit section: Struct members")] Struct members

The scope of the aliasing assertion made by a restrict-qualified pointer that is a member of a struct is the scope of the identifier used to access the struct. 

Even if the struct is declared at file scope, when the identifier used to access the struct has block scope, the aliasing assertions in the struct also have block scope; the aliasing assertions are only in effect within a block execution or a function call, depending on how the object of this struct type was created: 
    
    
    struct t      // Restricted pointers assert that
    {
       int n;     // members point to disjoint storage.
       float * restrict p;
       float * restrict q;
    };
     
    void ff(struct t r, struct t s)
    {
       struct t u;
       // r,s,u have block scope
       // r.p, r.q, s.p, s.q, u.p, u.q should all point to
       // disjoint storage during each execution of ff.
       // ...
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/restrict&action=edit&section=7 "Edit section: Keywords")] Keywords

[`restrict`](../keyword/restrict.html "c/keyword/restrict")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/restrict&action=edit&section=8 "Edit section: Example")] Example

code generation example; compile with -S (gcc, clang, etc) or /FA (visual studio) 
    
    
    int foo(int *a, int *b)
    {
        *a = 5;
        *b = 6;
        return *a + *b;
    }
     
    int rfoo(int *restrict a, int *restrict b)
    {
        *a = 5;
        *b = 6;
        return *a + *b;
    }

Possible output: 
    
    
    ; generated code on 64bit Intel platform:
    foo:
        movl    $5, (%rdi)    ; store 5 in *a
        movl    $6, (%rsi)    ; store 6 in *b
        movl    (%rdi), %eax  ; read back from *a in case previous store modified it
        addl    $6, %eax      ; add 6 to the value read from *a
        ret
     
    rfoo:
        movl      $11, %eax   ; the result is 11, a compile-time constant
        movl      $5, (%rdi)  ; store 5 in *a
        movl      $6, (%rsi)  ; store 6 in *b
        ret

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/restrict&action=edit&section=9 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.3.1 Formal definition of restrict (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.3.1 Formal definition of restrict (p: 89-90) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.3.1 Formal definition of restrict (p: 123-125) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.7.3.1 Formal definition of restrict (p: 110-112) 



Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/restrict&oldid=154457](https://en.cppreference.com/mwiki/index.php?title=c/language/restrict&oldid=154457)" 

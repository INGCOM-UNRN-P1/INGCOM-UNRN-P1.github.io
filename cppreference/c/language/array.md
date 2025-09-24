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
**Array**  
[enum](enum.html "c/language/enum")  
[struct](struct.html "c/language/struct")  
[union](union.html "c/language/union")  
[Bit-field](bit_field.html "c/language/bit field")  
[Atomic types](atomic.html "c/language/atomic") (C11)  
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

Array is a type consisting of a contiguously allocated nonempty sequence of objects with a particular _element type_. The number of those objects (the array size) never changes during the array lifetime. 

## Contents

  * [1 Syntax](array.html#Syntax)
  * [2 Explanation](array.html#Explanation)
    * [2.1 Arrays of constant known size](array.html#Arrays_of_constant_known_size)
    * [2.2 Variable-length arrays](array.html#Variable-length_arrays)
    * [2.3 Arrays of unknown size](array.html#Arrays_of_unknown_size)
    * [2.4 Qualifiers](array.html#Qualifiers)
    * [2.5 Assignment](array.html#Assignment)
    * [2.6 Array to pointer conversion](array.html#Array_to_pointer_conversion)
    * [2.7 Multidimensional arrays](array.html#Multidimensional_arrays)
  * [3 Notes](array.html#Notes)
  * [4 References](array.html#References)
  * [5 See also](array.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/array&action=edit&section=1 "Edit section: Syntax")] Syntax

In the [declaration grammar](declarations.html "c/language/declarations") of an array declaration, the _type-specifier_ sequence designates the _element type_ (which must be a complete object type), and the _declarator_ has the form:   
  
---  
`**[**` `**static**`(optional) qualifiers ﻿(optional) expression ﻿(optional) `**]**` attr-spec-seq ﻿(optional) |  (1)  |   
`**[**` qualifiers ﻿(optional) `**static**`(optional) expression ﻿(optional) `**]**` attr-spec-seq ﻿(optional) |  (2)  |   
`**[**` qualifiers ﻿(optional) `*****` `**]**` attr-spec-seq ﻿(optional) |  (3)  |   
  
1,2) General array declarator syntax

3) Declarator for VLA of unspecified size (can appear in function prototype scope only) where

expression |  \-  |  any expression other than [comma operator](operator_other.html#Comma_operator "c/language/operator other"), designates the number of elements in the array   
---|---|---  
qualifiers |  \-  |  any combination of [`const`](const.html "c/language/const"), [`restrict`](restrict.html "c/language/restrict"), or [`volatile`](volatile.html "c/language/volatile") qualifiers, only allowed in function parameter lists; this qualifies the pointer type to which this array parameter is transformed   
attr-spec-seq |  \-  |  (C23)optional list of [attributes](attributes.html "c/language/attributes"), applied to the declared array   
      
    
    float fa[11], *afp[17]; // fa is an array of 11 floats
                            // afp is an array of 17 pointers to floats

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/array&action=edit&section=2 "Edit section: Explanation")] Explanation

There are several variations of array types: arrays of known constant size, variable-length arrays, and arrays of unknown size. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/array&action=edit&section=3 "Edit section: Arrays of constant known size")] Arrays of constant known size

If expression in an array declarator is an [integer constant expression](constant_expression.html#Integer_constant_expression "c/language/constant expression") with a value greater than zero and the element type is a type with a known constant size (that is, elements are not VLA)(since C99), then the declarator declares an array of constant known size: 
    
    
    int n[10]; // integer constants are constant expressions
    char o[sizeof(double)]; // sizeof is a constant expression
    enum { MAX_SZ=100 };
    int n[MAX_SZ]; // enum constants are constant expressions

Arrays of constant known size can use [array initializers](array_initialization.html "c/language/array initialization") to provide their initial values: 
    
    
    int a[5] = {1,2,3}; // declares int[5] initialized to 1,2,3,0,0
    char str[] = "abc"; // declares char[4] initialized to 'a','b','c','\0'

In function parameter lists, additional syntax elements are allowed within the array declarators: the keyword `**static**` and qualifiers, which may appear in any order before the size expression (they may also appear even when the size expression is omitted). In each [function call](operator_other.html#Function_call "c/language/operator other") to a function where an array parameter uses the keyword `**static**` between `**[**` and `**]**`, the value of the actual parameter must be a valid pointer to the first element of an array with at least as many elements as specified by expression: 
    
    
    void fadd(double a[static 10], const double b[static 10])
    {
        for (int i = 0; i < 10; i++)
        {
            if (a[i] < 0.0) return;
            a[i] += b[i];
        }
    }
    // a call to fadd may perform compile-time bounds checking
    // and also permits optimizations such as prefetching 10 doubles
    int main(void)
    {
        double a[10] = {0}, b[20] = {0};
        fadd(a, b); // OK
        double x[5] = {0};
        fadd(x, b); // undefined behavior: array argument is too small
    }

If qualifiers are present, they qualify the pointer type to which the array parameter type is transformed: 
    
    
    int f(const int a[20])
    {
        // in this function, a has type const int* (pointer to const int)
    }
    int g(const int a[const 20])
    {
        // in this function, a has type const int* const (const pointer to const int)
    }

This is commonly used with the [`restrict`](restrict.html "c/language/restrict") type qualifier: 
    
    
    void fadd(double a[static restrict 10],
              const double b[static restrict 10])
    {
        for (int i = 0; i < 10; i++) // loop can be unrolled and reordered
        {
            if (a[i] < 0.0)
                break;
            a[i] += b[i];
        }
    }

####  Variable-length arrays

If expression is not an [integer constant expression](constant_expression.html#Integer_constant_expression "c/language/constant expression"), the declarator is for an array of variable size. Each time the flow of control passes over the declaration, expression is evaluated (and it must always evaluate to a value greater than zero), and the array is allocated (correspondingly, [lifetime](lifetime.html "c/language/lifetime") of a VLA ends when the declaration goes out of scope). The size of each VLA instance does not change during its lifetime, but on another pass over the same code, it may be allocated with a different size.  Run this code
    
    
    #include <stdio.h>
     
    int main(void)
    {
       int n = 1;
    label:;
       int a[n]; // re-allocated 10 times, each with a different size
       [printf](../io/fprintf.html)("The array has %zu elements\n", sizeof a / sizeof *a);
       if (n++ < 10)
           goto label; // leaving the scope of a VLA ends its lifetime
    }

If the size is `*****`, the declaration is for a VLA of unspecified size. Such declaration may only appear in a function prototype scope, and declares an array of a complete type. In fact, all VLA declarators in function prototype scope are treated as if expression were replaced by `*****`. 
    
    
    void foo([size_t](../types/size_t.html) x, int a[*]);
    void foo([size_t](../types/size_t.html) x, int a[x])
    {
        [printf](../io/fprintf.html)("%zu\n", sizeof a); // same as sizeof(int*)
    }

Variable-length arrays and the types derived from them (pointers to them, etc) are commonly known as "variably-modified types" (VM). Objects of any variably-modified type may only be declared at block scope or function prototype scope. 
    
    
    extern int n;
    int A[n];            // Error: file scope VLA
    extern int (*p2)[n]; // Error: file scope VM
    int B[100];          // OK: file-scope array of constant known size
    void fvla(int m, int C[m][m]); // OK: prototype-scope VLA

VLA must have automatic or allocated storage duration. Pointers to VLA, but not VLA themselves may also have static storage duration. No VM type may have linkage. 
    
    
    void fvla(int m, int C[m][m]) // OK: block scope/auto duration pointer to VLA
    {
        typedef int VLA[m][m]; // OK: block scope VLA
        int D[m];              // OK: block scope/auto duration VLA
    //  static int E[m]; // Error: static duration VLA
    //  extern int F[m]; // Error: VLA with linkage
        int (*s)[m];     // OK: block scope/auto duration VM
        s = [malloc](../memory/malloc.html)(m * sizeof(int)); // OK: s points to VLA in allocated storage
    //  extern int (*r)[m]; // Error: VM with linkage
        static int (*q)[m] = &B; // OK: block scope/static duration VM}
    }

Variably-modified types cannot be members of structs or unions. 
    
    
    struct tag
    {
        int z[n]; // Error: VLA struct member
        int (*y)[n]; // Error: VM struct member
    };

| (since C99)  
---|---  
If the compiler defines the macro constant __STDC_NO_VLA__ to integer constant 1, then VLA and VM types are not supported.  | (since C11)  
(until C23)  
If the compiler defines the macro constant __STDC_NO_VLA__ to integer constant 1, then VLA objects with automatic storage duration are not supported. The support for VM types and VLAs with allocated storage durations is mandated.  | (since C23)  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/array&action=edit&section=5 "Edit section: Arrays of unknown size")] Arrays of unknown size

If expression in an array declarator is omitted, it declares an array of unknown size. Except in function parameter lists (where such arrays are transformed to pointers) and when an [initializer](array_initialization.html "c/language/array initialization") is available, such type is an [incomplete type](compatible_type.html#Incomplete_types "c/language/type") (note that VLA of unspecified size, declared with `*****` as the size, is a complete type)(since C99): 
    
    
    extern int x[]; // the type of x is "array of unknown bound of int"
    int a[] = {1,2,3}; // the type of a is "array of 3 int"

Within a [struct](struct.html "c/language/struct") definition, an array of unknown size may appear as the last member (as long as there is at least one other named member), in which case it is a special case known as _flexible array member_. See [struct](struct.html "c/language/struct") for details: 
    
    
    struct s { int n; double d[]; }; // s.d is a flexible array member
    struct s *s1 = [malloc](../memory/malloc.html)(sizeof (struct s) + (sizeof (double) * 8)); // as if d was double d[8]

  
| (since C99)  
---|---  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/array&action=edit&section=6 "Edit section: Qualifiers")] Qualifiers

If an array type is declared with a [`const`](const.html "c/language/const"), [`volatile`](volatile.html "c/language/volatile"), or [`restrict`](restrict.html "c/language/restrict")(since C99) qualifier (which is possible through the use of [typedef](typedef.html "c/language/typedef")), the array type is not qualified, but its element type is:  | (until C23)  
---|---  
An array type and its element type are always considered to be identically qualified, except that an array type is never considered to be [`_Atomic`](atomic.html "c/language/atomic")-qualified.  | (since C23)  
      
    
    typedef int A[2][3];
    const A a = {{4, 5, 6}, {7, 8, 9}}; // array of array of const int
    int* pi = a[0]; // Error: a[0] has type const int*
    void* unqual_ptr = a; // OK until C23; error since C23
    // Notes: clang applies the rule in C++/C23 even in C89-C17 modes

[`_Atomic`](atomic.html "c/language/atomic") is not allowed to be applied to an array type, although an array of atomic type is allowed. 
    
    
    typedef int A[2];
    // _Atomic A a0 = {0};    // Error
    // _Atomic(A) a1 = {0};   // Error
    _Atomic int a2[2] = {0};  // OK
    _Atomic(int) a3[2] = {0}; // OK

| (since C11)  
---|---  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/array&action=edit&section=7 "Edit section: Assignment")] Assignment

Objects of array type are not [modifiable lvalues](value_category.html "c/language/value category"), and although their address may be taken, they cannot appear on the left hand side of an assignment operator. However, structs with array members are modifiable lvalues and can be assigned: 
    
    
    int a[3] = {1,2,3}, b[3] = {4,5,6};
    int (*p)[3] = &a; // okay, address of a can be taken
    // a = b;            // error, a is an array
    struct { int c[3]; } s1, s2 = {3,4,5};
    s1 = s2; // okay: can assign structs holding array members

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/array&action=edit&section=8 "Edit section: Array to pointer conversion")] Array to pointer conversion

Any [lvalue expression](value_category.html "c/language/value category") of array type, when used in any context other than 

  * as the operand of the [address-of operator](operator_member_access.html "c/language/operator member access")
  * as the operand of [`sizeof`](sizeof.html "c/language/sizeof")
  * as the operand of [`typeof`](typeof_unqual.html "c/language/typeof") and [`typeof_unqual`](typeof_unqual.html "c/language/typeof unqual") (since C23)
  * as the string literal used for [array initialization](array_initialization.html "c/language/array initialization")



  * as the operand of [`_Alignof`](alignof.html "c/language/ Alignof")(since C11)(until C23)[`alignof`](alignof.html "c/language/alignof")(since C23)

| (since C11)  
---|---  
  
undergoes an [implicit conversion](conversion.html "c/language/conversion") to the pointer to its first element. The result is not an lvalue. 

If the array was declared [`register`](storage_class_specifiers.html "c/language/storage duration"), the behavior of the program that attempts such conversion is undefined. 
    
    
    int a[3] = {1,2,3};
    int* p = a;
    [printf](../io/fprintf.html)("%zu\n", sizeof a); // prints size of array
    [printf](../io/fprintf.html)("%zu\n", sizeof p); // prints size of a pointer

When an array type is used in a function parameter list, it is transformed to the corresponding pointer type: int f(int a[2]) and int f(int* a) declare the same function. Since the function's actual parameter type is pointer type, a function call with an array argument performs array-to-pointer conversion; the size of the argument array is not available to the called function and must be passed explicitly: 

Run this code
    
    
    #include <stdio.h>
     
    void f(int a[], int sz) // actually declares void f(int* a, int sz)
    {
        for (int i = 0; i < sz; ++i)
            [printf](../io/fprintf.html)("%d\n", a[i]);
    }
     
    void g(int (*a)[10]) // pointer to array parameter is not transformed
    {
        for (int i = 0; i < 10; ++i)
            [printf](../io/fprintf.html)("%d\n", (*a)[i]);
    }
     
    int main(void)
    {
        int a[10] = {0};
        f(a, 10); // converts a to int*, passes the pointer
        g(&a);    // passes a pointer to the array (no need to pass the size)
    }

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/array&action=edit&section=9 "Edit section: Multidimensional arrays")] Multidimensional arrays

When the element type of an array is another array, it is said that the array is multidimensional: 
    
    
    // array of 2 arrays of 3 ints each
    int a[2][3] = {{1,2,3},  // can be viewed as a 2x3 matrix
                   {4,5,6}}; // with row-major layout

Note that when array-to-pointer conversion is applied, a multidimensional array is converted to a pointer to its first element, e.g., pointer to the first row: 
    
    
    int a[2][3]; // 2x3 matrix
    int (*p1)[3] = a; // pointer to the first 3-element row
    int b[3][3][3]; // 3x3x3 cube
    int (*p2)[3][3] = b; // pointer to the first 3x3 plane

Multidimensional arrays may be variably modified in every dimension if VLAs are supported(since C11): 
    
    
    int n = 10;
    int a[n][2*n];

| (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/array&action=edit&section=10 "Edit section: Notes")] Notes

Zero-length array declarations are not allowed, even though some compilers offer them as extensions (typically as a pre-C99 implementation of [flexible array members](struct.html "c/language/struct")). 

If the size expression of a VLA has side effects, they are guaranteed to be produced except when it is a part of a sizeof expression whose result doesn't depend on it: 
    
    
    int n = 5, m = 5;
    [size_t](../types/size_t.html) sz = sizeof(int (*[n++])[m++]); // n is incremented, m may or may not be incremented

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/array&action=edit&section=11 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.6.2 Array declarators (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.6.2 Array declarators (p: 94-96) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.6.2 Array declarators (p: 130-132) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.7.5.2 Array declarators (p: 116-118) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.5.4.2 Array declarators 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/array&action=edit&section=12 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/array.html "cpp/language/array") for Array declaration  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/array&oldid=179987](https://en.cppreference.com/mwiki/index.php?title=c/language/array&oldid=179987)" 

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

[ Basic Concepts](basic_concepts.html "c/language/basic concepts")

[ Comments](../comment.html "c/comment")  
---  
[ ASCII](ascii.html "c/language/ascii")  
[ Character sets](charset.html "c/language/charset")  
[ Translation phases](translation_phases.html "c/language/translation phases")  
[Punctuation](punctuators.html "c/language/punctuators")  
[Identifier](identifiers.html "c/language/identifier")  
[Scope](scope.html "c/language/scope")  
[Lifetime](lifetime.html "c/language/lifetime")  
[Lookup and name spaces](name_space.html "c/language/name space")  
[Type](compatible_type.html "c/language/type")  
[Arithmetic types](arithmetic_types.html "c/language/arithmetic types")  
[Objects and alignment](object.html "c/language/object")  
[The main() function](main_function.html "c/language/main function")  
[The as-if rule](as_if.html "c/language/as if")  
**Undefined behavior**  
[Memory model and data races](memory_model.html "c/language/memory model")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/basics/navbar_content&action=edit)

The C language standard precisely specifies the [observable behavior](as_if.html "c/language/as if") of C language programs, except for the ones in the following categories: 

  * _undefined behavior_ \- there are no restrictions on the behavior of the program. Examples of undefined behavior are memory accesses outside of array bounds, signed integer overflow, null pointer dereference, modification of the same scalar [more than once](eval_order.html "c/language/eval order") in an expression without sequence points, access to an object through a pointer of a different type, etc. Compilers are not required to diagnose undefined behavior (although many simple situations are diagnosed), and the compiled program is not required to do anything meaningful. 


  * _unspecified behavior_ \- two or more behaviors are permitted and the implementation is not required to document the effects of each behavior. For example, [order of evaluation](eval_order.html "c/language/eval order"), whether identical [string literals](string_literal.html "c/language/string literal") are distinct, etc. Each unspecified behavior results in one of a set of valid results and may produce a different result when repeated in the same program. 


  * _implementation-defined behavior_ \- unspecified behavior where each implementation documents how the choice is made. For example, number of bits in a byte, or whether signed integer right shift is arithmetic or logical. 


  * _locale-specific behavior_ \- implementation-defined behavior that depends on the [currently chosen locale](../locale/setlocale.html "c/locale/setlocale"). For example, whether [islower](../string/byte/islower.html "c/string/byte/islower") returns true for any character other than the 26 lowercase Latin letters. 



(Note: [Strictly conforming](conformance.html "c/language/conformance") programs do not depend on any unspecified, undefined, or implementation-defined behavior) 

The compilers are required to issue diagnostic messages (either errors or warnings) for any programs that violates any C syntax rule or semantic constraint, even if its behavior is specified as undefined or implementation-defined or if the compiler provides a language extension that allows it to accept such program. Diagnostics for undefined behavior are not otherwise required. 

## Contents

  * [1 UB and optimization](behavior.html#UB_and_optimization)
    * [1.1 Signed overflow](behavior.html#Signed_overflow)
    * [1.2 Access out of bounds](behavior.html#Access_out_of_bounds)
    * [1.3 Uninitialized scalar](behavior.html#Uninitialized_scalar)
    * [1.4 Invalid scalar](behavior.html#Invalid_scalar)
    * [1.5 Null pointer dereference](behavior.html#Null_pointer_dereference)
    * [1.6 Access to pointer passed to realloc](behavior.html#Access_to_pointer_passed_to_realloc)
    * [1.7 Infinite loop without side-effects](behavior.html#Infinite_loop_without_side-effects)
  * [2 References](behavior.html#References)
  * [3 See also](behavior.html#See_also)
  * [4 External links](behavior.html#External_links)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/behavior&action=edit&section=1 "Edit section: UB and optimization")] UB and optimization

Because correct C programs are free of undefined behavior, compilers may produce unexpected results when a program that actually has UB is compiled with optimization enabled: 

For example, 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/behavior&action=edit&section=2 "Edit section: Signed overflow")] Signed overflow
    
    
    int foo(int x)
    {
        return x + 1 > x; // either true or UB due to signed overflow
    }

may be compiled as ([demo](https://godbolt.org/z/9dh7b71TK)) 
    
    
    foo:
            mov     eax, 1
            ret

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/behavior&action=edit&section=3 "Edit section: Access out of bounds")] Access out of bounds
    
    
    int table[4] = {0};
    int exists_in_table(int v)
    {
        // return 1 in one of the first 4 iterations or UB due to out-of-bounds access
        for (int i = 0; i <= 4; i++)
            if (table[i] == v)
                return 1;
        return 0;
    }

May be compiled as ([demo](https://godbolt.org/z/48bn19Tsb)) 
    
    
    exists_in_table:
            mov     eax, 1
            ret

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/behavior&action=edit&section=4 "Edit section: Uninitialized scalar")] Uninitialized scalar
    
    
    _Bool p; // uninitialized local variable
    if (p) // UB access to uninitialized scalar
        [puts](../io/puts.html)("p is true");
    if (!p) // UB access to uninitialized scalar
        [puts](../io/puts.html)("p is false");

May produce the following output (observed with an older version of gcc): 
    
    
    p is true
    p is false
    
    
    [size_t](../types/size_t.html) f(int x)
    {
        [size_t](../types/size_t.html) a;
        if (x) // either x nonzero or UB
            a = 42;
        return a;
    }

May be compiled as ([demo](https://godbolt.org/z/9nz6EMPTG)) 
    
    
    f:
            mov     eax, 42
            ret

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/behavior&action=edit&section=5 "Edit section: Invalid scalar")] Invalid scalar
    
    
    int f(void)
    {
        _Bool b = 0;
        unsigned char* p = (unsigned char*)&b;
        *p = 10;
        // reading from b is now UB
        return b == 0;
    }

May be compiled as ([demo](https://godbolt.org/z/rjx77bjoh)) 
    
    
    f:
            mov     eax, 11
            ret

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/behavior&action=edit&section=6 "Edit section: Null pointer dereference")] Null pointer dereference
    
    
    int foo(int* p)
    {
        int x = *p;
        if (!p)
            return x; // Either UB above or this branch is never taken
        else
            return 0;
    }
     
    int bar()
    {
        int* p = [NULL](../types/NULL.html);
        return *p;    // Unconditional UB
    }

may be compiled as ([demo](https://godbolt.org/z/8jnjMjcPz)) 
    
    
    foo:
            xor     eax, eax
            ret
    bar:
            ret

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/behavior&action=edit&section=7 "Edit section: Access to pointer passed to realloc")] Access to pointer passed to [realloc](../memory/realloc.html "c/memory/realloc")

Choose clang to observe the output shown

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        int *p = (int*)[malloc](../memory/malloc.html)(sizeof(int));
        int *q = (int*)[realloc](../memory/realloc.html)(p, sizeof(int));
        *p = 1; // UB access to a pointer that was passed to realloc
        *q = 2;
        if (p == q) // UB access to a pointer that was passed to realloc
            [printf](../io/fprintf.html)("%d%d\n", *p, *q);
    }

Possible output: 
    
    
    12

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/behavior&action=edit&section=8 "Edit section: Infinite loop without side-effects")] Infinite loop without side-effects

Choose clang to observe the output shown

Run this code
    
    
    #include <stdio.h>
     
    int fermat()
    {
        const int MAX = 1000;
        // Endless loop with no side effects is UB
        for (int a = 1, b = 1, c = 1; 1;)
        {
            if (((a * a * a) == ((b * b * b) + (c * c * c))))
                return 1;
            ++a;
            if (a > MAX)
            {
                a = 1;
                ++b;
            }
            if (b > MAX)
            {
                b = 1;
                ++c;
            }
            if (c > MAX)
                c = 1;
        }
        return 0;
    }
     
    int main(void)
    {
        if (fermat())
            [puts](../io/puts.html)("Fermat's Last Theorem has been disproved.");
        else
            [puts](../io/puts.html)("Fermat's Last Theorem has not been disproved.");
    }

Possible output: 
    
    
    Fermat's Last Theorem has been disproved.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/behavior&action=edit&section=9 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 3.4 Behavior (p: TBD) 



    

  * 4 Conformance (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 3.4 Behavior (p: 3-4) 



    

  * 4 Conformance (p: 8) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 3.4 Behavior (p: 3-4) 



    

  * 4/2 Undefined behavior (p: 8) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 3.4 Behavior (p: 3-4) 



    

  * 4/2 Undefined behavior (p: 7) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 1.6 DEFINITIONS OF TERMS 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/behavior&action=edit&section=10 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/ub.html "cpp/language/ub") for Undefined behavior  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/behavior&action=edit&section=11 "Edit section: External links")] External links

1\.  | [What Every C Programmer Should Know About Undefined Behavior #1/3](https://blog.llvm.org/2011/05/what-every-c-programmer-should-know.html)  
---|---  
2\.  | [What Every C Programmer Should Know About Undefined Behavior #2/3](https://blog.llvm.org/2011/05/what-every-c-programmer-should-know_14.html)  
3\.  | [What Every C Programmer Should Know About Undefined Behavior #3/3](https://blog.llvm.org/2011/05/what-every-c-programmer-should-know_21.html)  
4\.  | [Undefined behavior can result in time travel (among other things, but time travel is the funkiest)](https://devblogs.microsoft.com/oldnewthing/20140627-00/?p=633)  
5\.  | [Understanding Integer Overflow in C/C++](https://www.cs.utah.edu/~regehr/papers/overflow12.pdf)  
6\.  | [Undefined Behavior and Fermat’s Last Theorem](https://web.archive.org/web/20201108094235/https://kukuruku.co/post/undefined-behavior-and-fermats-last-theorem/)  
7\.  | [Fun with NULL pointers, part 1](https://lwn.net/Articles/342330/) (local exploit in Linux 2.6.30 caused by UB due to null pointer dereference)   
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/behavior&oldid=178597](https://en.cppreference.com/mwiki/index.php?title=c/language/behavior&oldid=178597)" 

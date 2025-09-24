From cppreference.com

< [c](../../c.html "c")‎ | [types](../types.html "c/types")

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

[ Type support](../types.html "c/types")

[size_t](size_t.html "c/types/size t")  
---  
[ptrdiff_t](ptrdiff_t.html "c/types/ptrdiff t")  
**nullptr_t**(C23)  
[NULL](NULL.html "c/types/NULL")  
[max_align_t](max_align_t.html "c/types/max align t")(C11)  
[offsetof](offsetof.html "c/types/offsetof")  
[ Numeric limits](limits.html "c/types/limits")  
[ Fixed width integer types](integer.html "c/types/integer") (C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/navbar_content&action=edit)

Defined in header `[`<stddef.h>`](../header/stddef.html "c/header/stddef")` |  |   
---|---|---  
typedef typeof(nullptr) nullptr_t; |  |  (since C23)  
| |   
  
`nullptr_t` is the type of the predefined null pointer constant, [`nullptr`](../language/nullptr.html "c/language/nullptr"). It is a distinct type that is not itself a pointer type. It can be [implicitly converted](../language/conversion.html "c/language/conversion") to any pointer type or bool, and the result is the null pointer value of that type or false respectively. No type other than `nullptr_t` itself can be converted or explicitly cast to `nullptr_t`. 

sizeof(nullptr_t) and alignof(nullptr_t) are equal to sizeof(void*) and alignof(void*) respectively. 

`nullptr_t` has only one valid value, i.e., nullptr. The object representation of nullptr is same as that of (void*)0. If an [lvalue conversion](../language/conversion.html#Lvalue_conversion "c/language/conversion") produces a `nullptr_t` value with a different object representation, the behavior is undefined. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/nullptr_t&action=edit&section=1 "Edit section: Example")] Example

Demonstrate that `nullptr_t` is a distinct type.

Run this code
    
    
    #include <stddef.h>
    #include <stdio.h>
     
    #define DETECT_NULL_POINTER_CONSTANT(e) \
        _Generic(e,                         \
            void* : puts("void*"),          \
            nullptr_t : puts("nullptr_t"),  \
            default : puts("other")         \
        )
     
    int main()
    {
        DETECT_NULL_POINTER_CONSTANT(((void*)0));
        DETECT_NULL_POINTER_CONSTANT(0);
        DETECT_NULL_POINTER_CONSTANT(nullptr);
    }

Output: 
    
    
    void*
    other
    nullptr_t

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/nullptr_t&action=edit&section=2 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.2 The nullptr_t type (p: 315-316) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/nullptr_t&action=edit&section=3 "Edit section: See also")] See also

[ NULL](NULL.html "c/types/NULL") |  implementation-defined null pointer constant   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_NULL&action=edit)  
---|---  
[C++ documentation](../../cpp/types/nullptr_t.html "cpp/types/nullptr t") for nullptr_t  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/types/nullptr_t&oldid=172487](https://en.cppreference.com/mwiki/index.php?title=c/types/nullptr_t&oldid=172487)" 

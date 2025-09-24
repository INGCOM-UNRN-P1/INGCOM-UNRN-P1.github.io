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
[nullptr_t](nullptr_t.html "c/types/nullptr t")(C23)  
**NULL**  
[max_align_t](max_align_t.html "c/types/max align t")(C11)  
[offsetof](offsetof.html "c/types/offsetof")  
[ Numeric limits](limits.html "c/types/limits")  
[ Fixed width integer types](integer.html "c/types/integer") (C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/navbar_content&action=edit)

Defined in header `[`<locale.h>`](../header/locale.html "c/header/locale")` |  |   
---|---|---  
Defined in header `[`<stddef.h>`](../header/stddef.html "c/header/stddef")` |  |   
Defined in header `[`<stdio.h>`](../header/stdio.html "c/header/stdio")` |  |   
Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")` |  |   
Defined in header `[`<string.h>`](../header/string.html "c/header/string")` |  |   
Defined in header `[`<time.h>`](../header/time.html "c/header/time")` |  |   
Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")` |  |   
#define NULL /*implementation-defined*/ |  |   
| |   
  
The macro `NULL` is an implementation-defined null pointer constant, which may be 

  * an integer [constant expression](../language/constant_expression.html#Integer_constant_expression "c/language/constant expression") with the value ​0​
  * an integer constant expression with the value ​0​ [cast to the type](../language/conversion.html#Pointer_conversions "c/language/conversion") void*



  * predefined constant [`nullptr`](../language/nullptr.html "c/language/nullptr")

| (since C23)  
---|---  
  
A null pointer constant may be [converted](../language/conversion.html#Pointer_conversions "c/language/conversion") to any pointer type; such conversion results in the null pointer value of that type. 

## Contents

  * [1 Notes](NULL.html#Notes)
  * [2 Possible implementation](NULL.html#Possible_implementation)
  * [3 Example](NULL.html#Example)
  * [4 See also](NULL.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/NULL&action=edit&section=1 "Edit section: Notes")] Notes

[POSIX requires](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stddef.h.html) `NULL` to be defined as an integer constant expression with the value ​0​ cast to void*. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/NULL&action=edit&section=2 "Edit section: Possible implementation")] Possible implementation
    
    
    // C++ compatible:
    #define NULL 0
    // C++ incompatible:
    #define NULL (10*2 - 20)
    #define NULL ((void*)0)
    // since C23 (compatible with C++11 and later)
    #define NULL nullptr  
  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/NULL&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <inttypes.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        // any kind of pointer can be set to NULL
        int* p = NULL;
        struct S *s = NULL;
        void(*f)(int, double) = NULL;
        [printf](../io/fprintf.html)("%p %p %p\n", (void*)p, (void*)s, (void*)(long)f);
     
        // many pointer-returning functions use null pointers to indicate error
        char *ptr = [malloc](../memory/malloc.html)(0xFULL);
        if (ptr == NULL)
            [printf](../io/fprintf.html)("Out of memory");
        else
            [printf](../io/fprintf.html)("ptr = %#" [PRIxPTR](integer.html)"\n", ([uintptr_t](integer.html))ptr);
        [free](../memory/free.html)(ptr);
    }

Possible output: 
    
    
    (nil) (nil) (nil)
    ptr = 0xc001cafe

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/NULL&action=edit&section=4 "Edit section: See also")] See also

[ nullptr_t](nullptr_t.html "c/types/nullptr t")(C23) |  the type of the predefined null pointer constant [`nullptr`](../language/nullptr.html "c/language/nullptr")   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_nullptr_t&action=edit)  
---|---  
[C++ documentation](../../cpp/types/NULL.html "cpp/types/NULL") for NULL  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/types/NULL&oldid=168678](https://en.cppreference.com/mwiki/index.php?title=c/types/NULL&oldid=168678)" 

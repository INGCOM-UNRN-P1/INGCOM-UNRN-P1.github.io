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
[NULL](NULL.html "c/types/NULL")  
**max_align_t**(C11)  
[offsetof](offsetof.html "c/types/offsetof")  
[ Numeric limits](limits.html "c/types/limits")  
[ Fixed width integer types](integer.html "c/types/integer") (C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/navbar_content&action=edit)

Defined in header `[`<stddef.h>`](../header/stddef.html "c/header/stddef")` |  |   
---|---|---  
typedef /*implementation-defined*/ max_align_t; |  |  (since C11)  
| |   
  
`max_align_t` is a type whose alignment requirement is at least as strict (as large) as that of every scalar type. 

## Contents

  * [1 Notes](max_align_t.html#Notes)
  * [2 Example](max_align_t.html#Example)
  * [3 References](max_align_t.html#References)
  * [4 See also](max_align_t.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/max_align_t&action=edit&section=1 "Edit section: Notes")] Notes

Pointers returned by allocation functions such as [malloc](../memory/malloc.html "c/memory/malloc") are suitably aligned for any object, which means they are aligned at least as strictly as `max_align_t`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/max_align_t&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <inttypes.h>
    #include <stdalign.h>
    #include <stddef.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        [size_t](size_t.html) a = alignof(max_align_t);
        [printf](../io/fprintf.html)("Alignment of max_align_t is %zu (%#zx)\n", a, a);
     
        void *p = [malloc](../memory/malloc.html)(123);
        [printf](../io/fprintf.html)("The address obtained from malloc(123) is %#" [PRIxPTR](integer.html)"\n",
                ([uintptr_t](integer.html))p);
        [free](../memory/free.html)(p);
    }

Possible output: 
    
    
    Alignment of max_align_t is 16 (0x10)
    The address obtained from malloc(123) is 0x1fa67010

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/max_align_t&action=edit&section=3 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.19 Common definitions <stddef.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.19 Common definitions <stddef.h> (p: 211) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.19 Common definitions <stddef.h> (p: 288) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/max_align_t&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../cpp/types/max_align_t.html "cpp/types/max align t") for max_align_t  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/types/max_align_t&oldid=171582](https://en.cppreference.com/mwiki/index.php?title=c/types/max_align_t&oldid=171582)" 

From cppreference.com

< [c](../../c.html "c")‎ | [error](../error.html "c/error")

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

[ Error handling](../error.html "c/error")

Error codes  
---  
[ Error codes](errno_macros.html "c/error/errno macros")  
[errno](errno.html "c/error/errno")  
Assertions  
[assert](assert.html "c/error/assert")  
**static_assert**(C11)(removed in C23)  
Bounds checking  
[set_constraint_handler_s](set_constraint_handler_s.html "c/error/set constraint handler s")(C11)  
[abort_handler_s](abort_handler_s.html "c/error/abort handler s")(C11)  
[ignore_handler_s](ignore_handler_s.html "c/error/ignore handler s")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/navbar_content&action=edit)

Defined in header `[`<assert.h>`](../header/assert.html "c/header/assert")` |  |   
---|---|---  
#define static_assert _Static_assert |  |  (since C11)   
(removed in C23)  
| |   
  
This convenience macro expands to the keyword [`_Static_assert`](../keyword/_Static_assert.html "c/keyword/ Static assert"). 

## Contents

  * [1 Example](static_assert.html#Example)
  * [2 Notes](static_assert.html#Notes)
  * [3 References](static_assert.html#References)
  * [4 See also](static_assert.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/static_assert&action=edit&section=1 "Edit section: Example")] Example

Run this code
    
    
    #include <assert.h>
     
    int main(void)
    {
        static_assert(2 + 2 == 4, "2+2 isn't 4");   // well-formed
     
        static_assert(sizeof(int) < sizeof(char),   // compile-time error
                      "this program requires that int is less than char");
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/static_assert&action=edit&section=2 "Edit section: Notes")] Notes

Since C23, [`static_assert`](../language/static_assert.html "c/language/ Static assert") is itself a keyword, which may also be a predefined macro, so [`<assert.h>`](../header/assert.html "c/header/assert") no longer provides it. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/static_assert&action=edit&section=3 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.2/3 Diagnostics <assert.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.2/3 Diagnostics <assert.h> (p: 135) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.2/3 Diagnostics <assert.h> (p: 186) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/static_assert&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/static_assert.html "cpp/language/static assert") for Static Assertion  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/error/static_assert&oldid=180039](https://en.cppreference.com/mwiki/index.php?title=c/error/static_assert&oldid=180039)" 

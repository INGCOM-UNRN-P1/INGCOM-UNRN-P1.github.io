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
[static_assert](static_assert.html "c/error/static assert")(C11)(removed in C23)  
Bounds checking  
[set_constraint_handler_s](set_constraint_handler_s.html "c/error/set constraint handler s")(C11)  
[abort_handler_s](abort_handler_s.html "c/error/abort handler s")(C11)  
**ignore_handler_s**(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/navbar_content&action=edit)

Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
void ignore_handler_s( const char * restrict msg,  
void * restrict ptr,  
errno_t error  
); |  |  (since C11)  
| |   
  
The function simply returns to the caller without performing any other action. 

A pointer to this function can be passed to [set_constraint_handler_s](set_constraint_handler_s.html "c/error/set constraint handler s") to establish a runtime constraints violation handler that does nothing. 

    As with all bounds-checked functions, `ignore_handler_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including `<stdlib.h>`. 

## Contents

  * [1 Parameters](ignore_handler_s.html#Parameters)
  * [2 Return value](ignore_handler_s.html#Return_value)
  * [3 Notes](ignore_handler_s.html#Notes)
  * [4 Example](ignore_handler_s.html#Example)
  * [5 References](ignore_handler_s.html#References)
  * [6 See also](ignore_handler_s.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/ignore_handler_s&action=edit&section=1 "Edit section: Parameters")] Parameters

msg  |  \-  |  pointer to character string that describes the error   
---|---|---  
ptr  |  \-  |  pointer to an implementation-defined object or a null pointer. Examples of implementation-defined objects are objects that give the name of the function that detected the violation and the line number when the violation was detected   
error  |  \-  |  the error about to be returned by the calling function, if it happens to be one of the functions that return errno_t   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/ignore_handler_s&action=edit&section=2 "Edit section: Return value")] Return value

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/ignore_handler_s&action=edit&section=3 "Edit section: Notes")] Notes

If `ignore_handler_s` is used as a the runtime constraints handler, the violations may be detected by examining the results of the bounds-checked function calls, which may be different for different functions (non-zero errno_t, null character written to the first byte of the output string, etc) 

If `set_constraint_handler_s` is never called, the default handler is implementation-defined: it may be abort_handler_s, ignore_handler_s, or some other implementation-defined handler. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/ignore_handler_s&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #define __STDC_WANT_LIB_EXT1__ 1
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
    #ifdef __STDC_LIB_EXT1__
        char dst[2];
        set_constraint_handler_s(ignore_handler_s);
        int r = strcpy_s(dst, sizeof dst, "Too long!");
        [printf](../io/fprintf.html)("dst = \"%s\", r = %d\n", dst, r);
        set_constraint_handler_s(abort_handler_s);
        r = strcpy_s(dst, sizeof dst, "Too long!");
        [printf](../io/fprintf.html)("dst = \"%s\", r = %d\n", dst, r);
    #endif
    }

Possible output: 
    
    
    dst = "", r = 22
    abort_handler_s was called in response to a runtime-constraint violation.
     
    The runtime-constraint violation was caused by the following expression in strcpy_s:
    (s1max <= (s2_len=strnlen_s(s2, s1max)) ) (in string_s.c:62)
     
    Note to end users: This program was terminated as a result
    of a bug present in the software. Please reach out to your
    software's vendor to get more help.
    Aborted

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/ignore_handler_s&action=edit&section=5 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * K.3.6.1.3 The ignore_handler_s function (p: 606) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/ignore_handler_s&action=edit&section=6 "Edit section: See also")] See also

[ abort_handler_s](abort_handler_s.html "c/error/abort handler s")(C11) |  abort callback for the bounds-checked functions   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/abort_handler_s&action=edit)  
---|---  
[ set_constraint_handler_s](set_constraint_handler_s.html "c/error/set constraint handler s")(C11) |  set the error callback for bounds-checked functions   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/set_constraint_handler_s&action=edit)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/error/ignore_handler_s&oldid=78580](https://en.cppreference.com/mwiki/index.php?title=c/error/ignore_handler_s&oldid=78580)" 

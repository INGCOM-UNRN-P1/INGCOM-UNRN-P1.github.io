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
**Error codes**  
[errno](errno.html "c/error/errno")  
Assertions  
[assert](assert.html "c/error/assert")  
[static_assert](static_assert.html "c/error/static assert")(C11)(removed in C23)  
Bounds checking  
[set_constraint_handler_s](set_constraint_handler_s.html "c/error/set constraint handler s")(C11)  
[abort_handler_s](abort_handler_s.html "c/error/abort handler s")(C11)  
[ignore_handler_s](ignore_handler_s.html "c/error/ignore handler s")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/navbar_content&action=edit)

Each of the macros defined in [`<errno.h>`](../header/errno.html "c/header/errno") expands to an integer constant expression with type int and with a unique positive value. The following constants are defined by ISO C. The implementation may define more, as long as they begin with 'E' followed by digits or uppercase letters. 

Defined in header `[`<errno.h>`](../header/errno.html "c/header/errno")`  
---  
EDOM |  Mathematics argument out of domain of function   
(macro constant)  
EILSEQ(C95) |  Illegal byte sequence   
(macro constant)  
ERANGE |  Result too large   
(macro constant)  
  
## Contents

  * [1 Notes](errno_macros.html#Notes)
  * [2 Example](errno_macros.html#Example)
  * [3 References](errno_macros.html#References)
  * [4 See also](errno_macros.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/errno_macros&action=edit&section=1 "Edit section: Notes")] Notes

Many additional errno constants are [defined by POSIX](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/errno.h.html) and by the [C++ standard library](../../cpp/error/errno_macros.html "cpp/error/errno macros"), and individual implementations may define even more, e.g. errno(3) on Linux or intro(2) on BSD and OS X. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/errno_macros&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <errno.h>
    #include <math.h>
    #include <stdio.h>
    #include <string.h>
     
    int main(void)
    {
        errno = 0;
        [printf](../io/fprintf.html)("log(-1.0) = %f\n", [log](../numeric/math/log.html)(-1.0));
        [printf](../io/fprintf.html)("%s\n\n", [strerror](../string/byte/strerror.html)(errno));
     
        errno = 0;
        [printf](../io/fprintf.html)("log(0.0)  = %f\n", [log](../numeric/math/log.html)(0.0));
        [printf](../io/fprintf.html)("%s\n", [strerror](../string/byte/strerror.html)(errno));
    }

Possible output: 
    
    
    log(-1.0) = nan
    Numerical argument out of domain
     
    log(0.0)  = -inf
    Numerical result out of range

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/errno_macros&action=edit&section=3 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.5/2 Errors <errno.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.5/2 Errors <errno.h> (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.5/2 Errors <errno.h> (p: 205) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.5/2 Errors <errno.h> (p: 186) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.1.3 Errors <errno.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/errno_macros&action=edit&section=4 "Edit section: See also")] See also

[ errno](errno.html "c/error/errno") |  macro which expands to POSIX-compatible thread-local error number variable  
(macro variable) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/dsc_errno&action=edit)  
---|---  
[ perror](../io/perror.html "c/io/perror") |  displays a character string corresponding of the current error to [stderr](../io/std_streams.html "c/io/std streams")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_perror&action=edit)  
[ strerrorstrerror_sstrerrorlen_s](../string/byte/strerror.html "c/string/byte/strerror")(C11)(C11) |  returns a text version of a given error code   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strerror&action=edit)  
[C++ documentation](../../cpp/error/errno_macros.html "cpp/error/errno macros") for Error numbers  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/error/errno_macros&oldid=180046](https://en.cppreference.com/mwiki/index.php?title=c/error/errno_macros&oldid=180046)" 

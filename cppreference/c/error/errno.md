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
**errno**  
Assertions  
[assert](assert.html "c/error/assert")  
[static_assert](static_assert.html "c/error/static assert")(C11)(removed in C23)  
Bounds checking  
[set_constraint_handler_s](set_constraint_handler_s.html "c/error/set constraint handler s")(C11)  
[abort_handler_s](abort_handler_s.html "c/error/abort handler s")(C11)  
[ignore_handler_s](ignore_handler_s.html "c/error/ignore handler s")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/navbar_content&action=edit)

Defined in header `[`<errno.h>`](../header/errno.html "c/header/errno")` |  |   
---|---|---  
#define errno /* implementation-defined */ |  |   
| |   
  
`errno` is a preprocessor macro (but see note below) that expands to a thread-local(since C11) modifiable lvalue of type int. Several standard library functions indicate errors by writing positive integers to `errno`. Typically, the value of `errno` is set to one of the error codes listed in [`<errno.h>`](../header/errno.html "c/header/errno") as macro constants beginning with the letter `E` followed by uppercase letters or digits. 

The value of `errno` is ​0​ at program startup, and although library functions are allowed to write positive integers to `errno` whether or not an error occurred, library functions never store ​0​ in `errno`. 

Library functions [perror](../io/perror.html "c/io/perror") and [strerror](../string/byte/strerror.html "c/string/byte/strerror") can be used to obtain textual descriptions of the error conditions that correspond to the current `errno` value. 

Note: Until C11, the C standards had contradictory requirements, in that they said that `errno` is a macro but _also_ that "it is unspecified whether `errno` is a macro or an identifier declared with external linkage". C11 fixes this, requiring that it be defined as a macro (see also WG14 [N1338](https://open-std.org/JTC1/SC22/WG14/www/docs/n1338.htm)). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/errno&action=edit&section=1 "Edit section: Example")] Example

Run this code
    
    
    #include <errno.h>
    #include <math.h>
    #include <stdio.h>
     
    void show_errno(void)
    {
        const char *err_info = "unknown error";
        switch (errno)
        {
            case [EDOM](errno_macros.html):
                err_info = "domain error";
                break;
            case [EILSEQ](errno_macros.html):
                err_info = "illegal sequence";
                break;
            case [ERANGE](errno_macros.html):
                err_info = "pole or range error";
                break;
            case 0:
                err_info = "no error";
        }
        [fputs](../io/fputs.html)(err_info, [stdout](../io/std_streams.html));
        [puts](../io/puts.html)(" occurred");
    }
     
    int main(void)
    {
        [fputs](../io/fputs.html)("MATH_ERRNO is ", [stdout](../io/std_streams.html));
        [puts](../io/puts.html)(math_errhandling & MATH_ERRNO ? "set" : "not set");
     
        errno = 0;
        (void)(1.0 / 0.0);
        show_errno();
     
        errno = 0;
        (void)[acos](../numeric/math/acos.html)(+1.1);
        show_errno();
     
        errno = 0;
        (void)[log](../numeric/math/log.html)(0.0);
        show_errno();
     
        errno = 0;
        (void)[sin](../numeric/math/sin.html)(0.0);
        show_errno();
    }

Possible output: 
    
    
    MATH_ERRNO is set
    no error occurred
    domain error occurred
    pole or range error occurred
    no error occurred

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/errno&action=edit&section=2 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.5 Errors <errno.h> (p: TBD) 



    

  * K.3.1.3 Use of errno (p: TBD) 



    

  * K.3.2 Errors <errno.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.5 Errors <errno.h> (p: TBD) 



    

  * K.3.1.3 Use of errno (p: TBD) 



    

  * K.3.2 Errors <errno.h> (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.5 Errors <errno.h> (p: 205) 



    

  * K.3.1.3 Use of errno (p: 584) 



    

  * K.3.2 Errors <errno.h> (p: 585) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.5 Errors <errno.h> (p: 186) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.1.3 Errors <errno.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/errno&action=edit&section=3 "Edit section: See also")] See also

[ E2BIG, EACCES, ..., EXDEV](errno_macros.html "c/error/errno macros") |  macros for standard POSIX-compatible error conditions   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/dsc_errno_macros&action=edit)  
---|---  
[ perror](../io/perror.html "c/io/perror") |  displays a character string corresponding of the current error to [stderr](../io/std_streams.html "c/io/std streams")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_perror&action=edit)  
[ strerrorstrerror_sstrerrorlen_s](../string/byte/strerror.html "c/string/byte/strerror")(C11)(C11) |  returns a text version of a given error code   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strerror&action=edit)  
[ math_errhandlingMATH_ERRNOMATH_ERREXCEPT](../numeric/math/math_errhandling.html "c/numeric/math/math errhandling")(C99)(C99)(C99) |  defines the error handling mechanism used by the common mathematical functions   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_math_errhandling&action=edit)  
[C++ documentation](../../cpp/error/errno.html "cpp/error/errno") for errno  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/error/errno&oldid=180045](https://en.cppreference.com/mwiki/index.php?title=c/error/errno&oldid=180045)" 

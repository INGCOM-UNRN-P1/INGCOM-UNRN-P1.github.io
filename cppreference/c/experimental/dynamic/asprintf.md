From cppreference.com

< [c](../../../c.html "c")‎ | [experimental](../../experimental.html "c/experimental")‎ | [dynamic](../dynamic.html "c/experimental/dynamic")

[ C](../../../c.html "c")

[Compiler support](../../compiler_support.html "c/compiler support")  
---  
[Language](../../language.html "c/language")  
[Headers](../../header.html "c/header")  
[Type support](../../types.html "c/types")  
[Program utilities](../../program.html "c/program")  
[Variadic function support](../../variadic.html "c/variadic")  
[Error handling](../../error.html "c/error")  
[Dynamic memory management](../../memory.html "c/memory")  
[Strings library](../../string.html "c/string")  
[Algorithms](../../algorithm.html "c/algorithm")  
[Numerics](../../numeric.html "c/numeric")  
[Date and time utilities](../../chrono.html "c/chrono")  
[Input/output support](../../io.html "c/io")  
[Localization support](../../locale.html "c/locale")  
[Concurrency support](../../thread.html "c/thread") (C11)  
[Technical Specifications](../../experimental.html "c/experimental")  
[Symbol index](../../index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

[ Technical Specifications](../../experimental.html "c/experimental")

[ Extensions for embedded processors](https://en.cppreference.com/mwiki/index.php?title=c/experimental/embedded&action=edit&redlink=1 "c/experimental/embedded \(page does not exist\)")  
---  
[ Dynamic memory extensions](../dynamic.html "c/experimental/dynamic")  
[ Floating-point extensions part 1: Binary floating-point](../fpext1.html "c/experimental/fpext1")  
[ Floating-point extensions part 4: Supplementary functions](../fpext4.html "c/experimental/fpext4")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/navbar_content&action=edit)

[ Dynamic memory extensions](../dynamic.html "c/experimental/dynamic")

[fmemopen](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/fmemopen&action=edit&redlink=1 "c/experimental/dynamic/fmemopen \(page does not exist\)")  
---  
[open_memstreamopen_wmemstream](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/open_memstream&action=edit&redlink=1 "c/experimental/dynamic/open memstream \(page does not exist\)")  
**asprintf aswprintfvasprintfvaswprintf**  
[getlinegetwlinegetdelimgetwdelim](getline.html "c/experimental/dynamic/getline")  
[strdup](strdup.html "c/experimental/dynamic/strdup")  
[strndup](strndup.html "c/experimental/dynamic/strndup")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/navbar_content&action=edit)

Defined in header `[`<stdio.h>`](../../header/stdio.html "c/header/stdio")` |  |   
---|---|---  
int asprintf( char **restrict strp, const char *restrict fmt, ... ); |  (1)  |  (dynamic memory TR)  
int aswprintf( wchar_t **restrict strp, const wchar_t *restrict fmt, ... ); |  (2)  |  (dynamic memory TR)  
int vasprintf( char **restrict strp, const char *restrict fmt,  
va_list arg ); |  (3)  |  (dynamic memory TR)  
int vaswprintf( wchar_t **restrict strp, const wchar_t *restrict fmt,  
va_list arg ); |  (4)  |  (dynamic memory TR)  
| |   
  
1) Analog of [sprintf](../../io/fprintf.html "c/io/fprintf"), except that it allocates a storage large enough to hold the output including the terminating null character, as if by a call to [malloc](../../memory/malloc.html "c/memory/malloc"), and returns a pointer to that storage via the first argument. This pointer should be passed to [free](../../memory/free.html "c/memory/free") to release the allocated storage when it is no longer needed.

2) Same as (1), except that it works with wide characters wchar_t (by analogy with [swprintf](../../io/fwprintf.html "c/io/fwprintf")). 

3) Same as (1), with the variable argument list replaced by `arg`, which shall be initialized by the va_start macro (and possibly subsequent va_arg calls).

4) Same as (3), except that it works with wide characters wchar_t.

## Contents

  * [1 Parameters](asprintf.html#Parameters)
  * [2 Return value](asprintf.html#Return_value)
  * [3 Notes](asprintf.html#Notes)
  * [4 Example](asprintf.html#Example)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/asprintf&action=edit&section=1 "Edit section: Parameters")] Parameters

strp  |  \-  |  A pointer to a char* or wchar_t* which will contain the formatted output   
---|---|---  
fmt  |  \-  |  A format string as with [printf](../../io/fprintf.html "c/io/fprintf")/[wprintf](../../io/fwprintf.html "c/io/fwprintf") and related functions   
arg  |  \-  |  Any extra arguments are used as with [vsprintf](../../io/vfprintf.html "c/io/vfprintf") and [vswprintf](../../io/vfwprintf.html "c/io/vfwprintf")  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/asprintf&action=edit&section=2 "Edit section: Return value")] Return value

The number of characters written, just like [sprintf](../../io/fprintf.html "c/io/fprintf") (1), [swprintf](../../io/fwprintf.html "c/io/fwprintf") (2), [vsprintf](../../io/vfprintf.html "c/io/vfprintf") (3), or [vswprintf](../../io/vfwprintf.html "c/io/vfwprintf") (4), respectively. If memory allocation wasn't possible, or some other error occurs, these functions will return -1, and the contents of `strp` is undefined. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/asprintf&action=edit&section=3 "Edit section: Notes")] Notes

These functions are GNU extensions, not in C or POSIX. They are also available under *BSD. The FreeBSD implementation sets `strp` to `NULL` on error. 

The `vasprintf` and `vaswprintf` functions do not invoke the va_end macro. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/asprintf&action=edit&section=4 "Edit section: Example")] Example

Can be tested with clang (C11)

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
     
    void test(const char *fmt, ...)
    {
        char* dyn_buf;
     
        [printf](../../io/fprintf.html)("Demo asprintf:\n");
        const int written_1 = asprintf(&dyn_buf, "%s", fmt);
        [printf](../../io/fprintf.html)("dyn_buf: \"%s\"; %i chars were written\n", dyn_buf, written_1);
        [free](../../memory/free.html)(dyn_buf);
     
        [printf](../../io/fprintf.html)("Demo vasprintf:\n");
        va_list args;
        va_start(args, fmt);
        const int written_2 = vasprintf(&dyn_buf, fmt, args);
        va_end(args);
        [printf](../../io/fprintf.html)("dyn_buf: \"%s\"; %i chars were written\n", dyn_buf, written_2);
        [free](../../memory/free.html)(dyn_buf);
    }
     
    int main(void)
    {
        test("Testing... %d, %d, %d", 1, 2, 3);
    }

Output: 
    
    
    Demo asprintf:
    dyn_buf: "Testing... %d, %d, %d"; 21 chars were written
    Demo vasprintf:
    dyn_buf: "Testing... 1, 2, 3"; 18 chars were written

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/asprintf&oldid=161853](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/asprintf&oldid=161853)" 

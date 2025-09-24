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
[asprintfaswprintfvasprintfvaswprintf](asprintf.html "c/experimental/dynamic/asprintf")  
**getline getwlinegetdelimgetwdelim**  
[strdup](strdup.html "c/experimental/dynamic/strdup")  
[strndup](strndup.html "c/experimental/dynamic/strndup")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/navbar_content&action=edit)

Defined in header `[`<stdio.h>`](../../header/stdio.html "c/header/stdio")` |  |   
---|---|---  
ssize_t getline(char **lineptr, [size_t](../../types/size_t.html) *n, [FILE](../../io/FILE.html) *stream); |  (1)  |  (dynamic memory TR)  
ssize_t getwline(wchar_t **lineptr, [size_t](../../types/size_t.html) *n, [FILE](../../io/FILE.html) *stream); |  (2)  |  (dynamic memory TR)  
ssize_t getdelim(char ** restrict lineptr, [size_t](../../types/size_t.html) * restrict n,  
int delimiter, [FILE](../../io/FILE.html) *stream); |  (3)  |  (dynamic memory TR)  
ssize_t getwdelim(wchar_t ** restrict lineptr, [size_t](../../types/size_t.html) * restrict n,  
wint_t delimiter, [FILE](../../io/FILE.html) * stream); |  (4)  |  (dynamic memory TR)  
| |   
  
1) Behaves like getdelim(lineptr, n, '\n', stream)

2) Behaves like getwdelim(lineptr, n, L'\n', stream)

3) Reads from the stream `stream` as if by [fgetc](../../io/fgetc.html "c/io/fgetc"), until `delimiter` is encountered, storing the characters in the buffer of size `*n` pointed to by `*lineptr`, automatically increasing its size as if by [realloc](../../memory/realloc.html "c/memory/realloc") to fit the entire input, including the delimiter, and adding a null terminator. The pointer returned by [realloc](../../memory/realloc.html "c/memory/realloc") is written back into `*lineptr`. `*lineptr` may be null, in which case previous value of `*n` is ignored and `getline` allocates a new buffer as if by [malloc](../../memory/malloc.html "c/memory/malloc"). In any case the final length of the allocated buffer is written to `*n`. The behavior is undefined if `delimiter` has a value that is outside the range of `unsigned char` or [EOF](../../io.html "c/io").

4) Same as (3), except the characters are read as if by [fgetwc](../../io/fgetwc.html "c/io/fgetwc") and that `delimiter` must be a valid `wchar_t` or WEOF.

If `*lineptr` is not null, the behavior is undefined if `*lineptr` is not a pointer that can be passed to [free](../../memory/free.html "c/memory/free") or if `*n` is greater than the size of the allocated memory pointed to by `*lineptr`. The behavior is also undefined if `n` is not a valid pointer suitable for writing a value of type [size_t](../../types/size_t.html). 

As all functions from Dynamic Memory TR, `getline` is only guaranteed to be available if __STDC_ALLOC_LIB__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT2__ to the integer constant 1 before including `stdio.h`. 

## Contents

  * [1 Parameters](getline.html#Parameters)
  * [2 Return value](getline.html#Return_value)
  * [3 Notes](getline.html#Notes)
  * [4 Example](getline.html#Example)
  * [5 See also](getline.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/getline&action=edit&section=1 "Edit section: Parameters")] Parameters

lineptr  |  \-  |  pointer to a pointer to the initial buffer or to a null pointer   
---|---|---  
n  |  \-  |  pointer to the size of the initial buffer   
delimiter  |  \-  |  the delimiter character   
stream  |  \-  |  valid input stream, opened by [fopen](../../io/fopen.html "c/io/fopen")  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/getline&action=edit&section=2 "Edit section: Return value")] Return value

The number of characters stored in the buffer, including the delimiter, but excluding the null terminator. 

On error, returns -1 and sets [feof](../../io/feof.html "c/io/feof") or [ferror](../../io/ferror.html "c/io/ferror") on `stream`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/getline&action=edit&section=3 "Edit section: Notes")] Notes

These functions are identical to their [POSIX versions](http://pubs.opengroup.org/onlinepubs/9699919799/functions/getdelim.html) except that it is allowed, but not required to set [errno](../../error/errno.html "c/error/errno") on error. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/getline&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #ifdef __STDC_ALLOC_LIB__
    #define __STDC_WANT_LIB_EXT2__ 1
    #else
    #define _POSIX_C_SOURCE 200809L
    #endif
     
    #include <stdio.h>
    #include <stdlib.h>
    void get_y_or_n(void)
    {
        char *response = [NULL](../../types/NULL.html);
        [size_t](../../types/size_t.html) len;
        [printf](../../io/fprintf.html)("Continue? [y] n: ");
        if((getline(&response, &len, [stdin](../../io/std_streams.html)) < 0) || (len && response[0] == 'n')) {
            [free](../../memory/free.html)(response);
            [exit](../../program/exit.html)(0);
        }
        [free](../../memory/free.html)(response);
        return;
    }
    int main(void) 
    {
        get_y_or_n();
    }

Output: 
    
    
    Continue? [y] n:

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/getline&action=edit&section=5 "Edit section: See also")] See also

[ fgets](../../io/fgets.html "c/io/fgets") |  gets a character string from a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fgets&action=edit)  
---|---  
[ getsgets_s](../../io/gets.html "c/io/gets")(removed in C11)(C11) |  reads a character string from [stdin](../../io/std_streams.html "c/io/std streams")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_gets&action=edit)  
[ fgetws](../../io/fgetws.html "c/io/fgetws")(C95) |  gets a wide string from a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fgetws&action=edit)  
[ malloc](../../memory/malloc.html "c/memory/malloc") |  allocates memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_malloc&action=edit)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/getline&oldid=183188](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/getline&oldid=183188)" 

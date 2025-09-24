From cppreference.com

< [c](../../c.html "c")‎ | [io](../io.html "c/io")

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

[ File input/output](../io.html "c/io")

Types and objects  
---  
|  | [stdinstdoutstderr](std_streams.html "c/io/std streams")` `  
---  
  
| [FILE](FILE.html "c/io/FILE")  
---  
[fpos_t](fpos_t.html "c/io/fpos t")  
  
  
  
| Functions  
---  
File access  
| [fopenfopen_s](fopen.html "c/io/fopen")(C11)  
---  
**freopen freopen_s**(C11)` `  
[fwide](fwide.html "c/io/fwide")(C95)  
  
| [setbuf](setbuf.html "c/io/setbuf")  
---  
[setvbuf](setvbuf.html "c/io/setvbuf")  
[fclose](fclose.html "c/io/fclose")  
[fflush](fflush.html "c/io/fflush")  
  
  
  
Unformatted input/output  
| [fgetc](fgetc.html "c/io/fgetc")  
---  
[fgets](fgets.html "c/io/fgets")  
[fputc](putc.html "c/io/fputc")  
[fputs](fputs.html "c/io/fputs")  
[getchar](getchar.html "c/io/getchar")  
[getsgets_s](gets.html "c/io/gets")(until C11)(C11)  
[putchar](putchar.html "c/io/putchar")  
[puts](puts.html "c/io/puts")  
[ungetc](ungetc.html "c/io/ungetc")  
  
| [fgetwcgetwc](fgetwc.html "c/io/fgetwc")(C95)(C95)  
---  
[fgetws](fgetws.html "c/io/fgetws")(C95)  
[fputwcputwc](fputwc.html "c/io/fputwc")(C95)(C95)  
[fputws](fputws.html "c/io/fputws")(C95)  
[getwchar](getwchar.html "c/io/getwchar")(C95)  
[putwchar](putwchar.html "c/io/putwchar")(C95)  
[ungetwc](ungetwc.html "c/io/ungetwc")(C95)  
  
  
  
Formatted input  
| [scanffscanfsscanfscanf_sfscanf_ssscanf_s](fscanf.html "c/io/fscanf")(C11)(C11)(C11)  
---  
[wscanffwscanfswscanfwscanf_sfwscanf_sswscanf_s](fwscanf.html "c/io/fwscanf")(C95)(C95)(C95)(C11)(C11)(C11)  
  
| [vscanfvfscanfvsscanfvscanf_svfscanf_svsscanf_s](vfscanf.html "c/io/vfscanf")(C99)(C99)(C99)(C11)(C11)(C11)  
---  
[vwscanfvfwscanfvswscanfvwscanf_svfwscanf_svswscanf_s](vfwscanf.html "c/io/vfwscanf")(C99)(C99)(C99)(C11)(C11)(C11)` `  
  
| Direct input/output  
---  
| [fread](fread.html "c/io/fread")  
---  
  
| [fwrite](fwrite.html "c/io/fwrite")  
---  
  
Formatted output  
| [printffprintfsprintfsnprintfprintf_sfprintf_ssprintf_ssnprintf_s](fprintf.html "c/io/fprintf")(C99)(C11)(C11)(C11)(C11)  
---  
[wprintffwprintfswprintfwprintf_sfwprintf_sswprintf_ssnwprintf_s](fwprintf.html "c/io/fwprintf")(C95)(C95)(C95)(C11)(C11)(C11)(C11)` `  
  
| [vprintfvfprintfvsprintfvsnprintfvprintf_svfprintf_svsprintf_svsnprintf_s](vfprintf.html "c/io/vfprintf")(C99)(C11)(C11)(C11)(C11)  
---  
[vwprintfvfwprintfvswprintfvwprintf_svfwprintf_svswprintf_svsnwprintf_s](vfwprintf.html "c/io/vfwprintf")(C95)(C95)(C95)(C11)(C11)(C11)(C11)  
  
File positioning  
| [ftell](ftell.html "c/io/ftell")  
---  
[fgetpos](fgetpos.html "c/io/fgetpos")  
[fseek](fseek.html "c/io/fseek")  
  
| [fsetpos](fsetpos.html "c/io/fsetpos")  
---  
[rewind](rewind.html "c/io/rewind")  
  
  
  
Error handling  
| [clearerr](clearerr.html "c/io/clearerr")  
---  
[feof](feof.html "c/io/feof")  
  
| [ferror](ferror.html "c/io/ferror")  
---  
[perror](perror.html "c/io/perror")  
  
Operations on files  
| [remove](remove.html "c/io/remove")  
---  
[tmpfiletmpfile_s](tmpfile.html "c/io/tmpfile")(C11)  
  
| [rename](rename.html "c/io/rename")  
---  
[tmpnamtmpnam_s](tmpnam.html "c/io/tmpnam")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/navbar_content&action=edit)

Defined in header `[`<stdio.h>`](../header/stdio.html "c/header/stdio")` |  |   
---|---|---  
| (1) |   
[FILE](FILE.html) *freopen( const char *filename, const char *mode,  
[FILE](FILE.html) *stream ); |  |  (until C99)  
[FILE](FILE.html) *freopen( const char *restrict filename, const char *restrict mode,   
[FILE](FILE.html) *restrict stream ); |  |  (since C99)  
errno_t freopen_s( [FILE](FILE.html) *restrict *restrict newstreamptr,  
const char *restrict filename, const char *restrict mode,  
[FILE](FILE.html) *restrict stream ); |  (2)  |  (since C11)  
| |   
  
1) First, attempts to close the file associated with `stream`, ignoring any errors. Then, if `filename` is not null, attempts to open the file specified by `filename` using `mode` as if by [fopen](fopen.html "c/io/fopen"), and associates that file with the file stream pointed to by `stream`. If `filename` is a null pointer, then the function attempts to reopen the file that is already associated with `stream` (it is implementation defined which mode changes are allowed in this case).

2) Same as (1), except that `mode` is treated as in fopen_s and that the pointer to the file stream is written to `newstreamptr` and the following errors are detected at runtime and call the currently installed [constraint handler](../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * `newstreamptr` is a null pointer 
  * `stream` is a null pointer 
  * `mode` is a null pointer 


    As with all bounds-checked functions, `freopen_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<stdio.h>`](../header/stdio.html "c/header/stdio").

## Contents

  * [1 Parameters](freopen.html#Parameters)
  * [2 File access flags](freopen.html#File_access_flags)
  * [3 Return value](freopen.html#Return_value)
  * [4 Notes](freopen.html#Notes)
  * [5 Example](freopen.html#Example)
  * [6 References](freopen.html#References)
  * [7 See also](freopen.html#See_also)

  
---  
  
###  Parameters

filename  |  \-  |  file name to associate the file stream to   
---|---|---  
mode  |  \-  |  null-terminated character string determining new [file access mode](freopen.html#File_access_flags)  
stream  |  \-  |  the file stream to modify   
newstreamptr  |  \-  |  pointer to a pointer where the function stores the result (an out-parameter)   
  
###  File access flags

File access   
mode string  |  Meaning  |  Explanation  |  Action if file   
already exists  |  Action if file   
does not exist   
---|---|---|---|---  
"r" |  read  |  Open a file for reading  |  read from start  |  failure to open   
"w" |  write  |  Create a file for writing  |  destroy contents  |  create new   
"a" |  append  |  Append to a file  |  write to end  |  create new   
"r+" |  read extended  |  Open a file for read/write  |  read from start  |  error   
"w+" |  write extended  |  Create a file for read/write  |  destroy contents  |  create new   
"a+" |  append extended  |  Open a file for read/write  |  write to end  |  create new   
File access mode flag "b" can optionally be specified to open a file in binary mode. This flag has no effect on POSIX systems, but on Windows it disables special handling of '\n' and '\x1A'.   
On the append file access modes, data is written to the end of the file regardless of the current position of the file position indicator.   
The behavior is undefined if the mode is not one of the strings listed above. Some implementations define additional supported modes (e.g. [Windows](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-wfopen)).   
In update mode ('+'), both input and output may be performed, but output cannot be followed by input without an intervening call to [fflush](fflush.html "c/io/fflush"), [fseek](fseek.html "c/io/fseek"), [fsetpos](fsetpos.html "c/io/fsetpos") or [rewind](rewind.html "c/io/rewind"), and input cannot be followed by output without an intervening call to [fseek](fseek.html "c/io/fseek"), [fsetpos](fsetpos.html "c/io/fsetpos") or [rewind](rewind.html "c/io/rewind"), unless the input operation encountered end of file. In update mode, implementations are permitted to use binary mode even when text mode is specified.   
File access mode flag "x" can optionally be appended to "w" or "w+" specifiers. This flag forces the function to fail if the file exists, instead of overwriting it. (C11)  
When using fopen_s or freopen_s, file access permissions for any file created with "w" or "a" prevents other users from accessing it. File access mode flag "u" can optionally be prepended to any specifier that begins with "w" or "a", to enable the default [fopen](fopen.html "c/io/fopen") permissions. (C11)  
  
###  Return value

1) A copy of the value of `stream` on success, null pointer on failure.

2) zero on success (and a copy of the value of `stream` is written to *newstreamptr, non-zero on error (and null pointer is written to *newstreamptr unless `newstreamptr` is itself a null pointer).

###  Notes

`freopen` is the only way to change the narrow/wide orientation of a stream once it has been established by an I/O operation or by fwide. 

Microsoft CRT version of `freopen` does not support any mode changes when `filename` is a null pointer and treats this as an error (see [documentation](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/freopen-wfreopen)). A possible workaround is the non-standard function [`_setmode()`](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/setmode). 

###  Example

The following code redirects `stdout` to a file.

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        [puts](puts.html)("stdout is printed to console");
        if (freopen("redir.txt", "w", [stdout](std_streams.html)) == [NULL](../types/NULL.html))
        {
           [perror](perror.html)("freopen() failed");
           return [EXIT_FAILURE](../program/EXIT_status.html);
        }
        [puts](puts.html)("stdout is redirected to a file"); // this is written to redir.txt
        [fclose](fclose.html)([stdout](std_streams.html));
        return [EXIT_SUCCESS](../program/EXIT_status.html);
    }

Output: 
    
    
    stdout is printed to console

###  References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.5.4 The freopen function (p: 224-225) 



    

  * K.3.5.2.2 The freopen_s function (p: 429-430) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.5.4 The freopen function (p: 307) 



    

  * K.3.5.2.2 The freopen_s function (p: 590) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.5.4 The freopen function (p: 272-273) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.5.4 The freopen function 



###  See also

[ fopenfopen_s](fopen.html "c/io/fopen")(C11) |  opens a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fopen&action=edit)  
---|---  
[ fclose](fclose.html "c/io/fclose") |  closes a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fclose&action=edit)  
[C++ documentation](../../cpp/io/c/freopen.html "cpp/io/c/freopen") for freopen  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/freopen&oldid=133723](https://en.cppreference.com/mwiki/index.php?title=c/io/freopen&oldid=133723)" 

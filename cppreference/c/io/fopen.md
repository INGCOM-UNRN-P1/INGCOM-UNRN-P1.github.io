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
| **fopen fopen_s**(C11)  
---  
[freopenfreopen_s](freopen.html "c/io/freopen")(C11)` `  
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
[FILE](FILE.html) *fopen( const char *filename, const char *mode ); |  |  (until C99)  
[FILE](FILE.html) *fopen( const char *restrict filename, const char *restrict mode ); |  |  (since C99)  
errno_t fopen_s( [FILE](FILE.html) *restrict *restrict streamptr,  
const char *restrict filename,  
const char *restrict mode ); |  (2)  |  (since C11)  
| |   
  
1) Opens a file indicated by `filename` and returns a pointer to the file stream associated with that file. `mode` is used to determine the file access mode. 

2) Same as (1), except that the pointer to the file stream is written to `streamptr` and the following errors are detected at runtime and call the currently installed [constraint handler](../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * `streamptr` is a null pointer 
  * `filename` is a null pointer 
  * `mode` is a null pointer 


As with all bounds-checked functions, `fopen_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<stdio.h>`](../header/stdio.html "c/header/stdio").

## Contents

  * [1 Parameters](fopen.html#Parameters)
  * [2 File access flags](fopen.html#File_access_flags)
  * [3 Return value](fopen.html#Return_value)
  * [4 Notes](fopen.html#Notes)
  * [5 Example](fopen.html#Example)
  * [6 References](fopen.html#References)
  * [7 See also](fopen.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fopen&action=edit&section=1 "Edit section: Parameters")] Parameters

filename  |  \-  |  file name to associate the file stream to   
---|---|---  
mode  |  \-  |  null-terminated character string determining [file access mode](fopen.html#File_access_flags)  
streamptr  |  \-  |  pointer to a pointer where the function stores the result (an out-parameter)   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fopen&action=edit&section=2 "Edit section: File access flags")] File access flags

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
When using fopen_s or freopen_s, file access permissions for any file created with "w" or "a" prevents other users from accessing it. File access mode flag "u" can optionally be prepended to any specifier that begins with "w" or "a", to enable the default **fopen** permissions. (C11)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fopen&action=edit&section=3 "Edit section: Return value")] Return value

1) If successful, returns a pointer to the new file stream. The stream is fully buffered unless `filename` refers to an interactive device. On error, returns a null pointer. [POSIX requires](https://pubs.opengroup.org/onlinepubs/9699919799/functions/fopen.html) that [errno](../error/errno.html "c/error/errno") be set in this case.

2) If successful, returns zero and a pointer to the new file stream is written to *streamptr. On error, returns a non-zero error code and writes the null pointer to *streamptr (unless `streamptr` is a null pointer itself).

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fopen&action=edit&section=4 "Edit section: Notes")] Notes

The format of `filename` is implementation-defined, and does not necessarily refer to a file (e.g. it may be the console or another device accessible though filesystem API). On platforms that support them, `filename` may include absolute or relative filesystem path. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fopen&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        const char* fname = "/tmp/unique_name.txt"; // or tmpnam(NULL);
        int is_ok = [EXIT_FAILURE](../program/EXIT_status.html);
     
        [FILE](FILE.html)* fp = fopen(fname, "w+");
        if (!fp)
        {
            [perror](perror.html)("File opening failed");
            return is_ok;
        }
        [fputs](fputs.html)("Hello, world!\n", fp);
        [rewind](rewind.html)(fp);
     
        int c; // note: int, not char, required to handle EOF
        while ((c = [fgetc](fgetc.html)(fp)) != [EOF](../io.html)) // standard C I/O file reading loop
            [putchar](putchar.html)(c);
     
        if ([ferror](ferror.html)(fp))
            [puts](puts.html)("I/O error when reading");
        else if ([feof](feof.html)(fp))
        {
            [puts](puts.html)("End of file is reached successfully");
            is_ok = [EXIT_SUCCESS](../program/EXIT_status.html);
        }
     
        [fclose](fclose.html)(fp);
        [remove](remove.html)(fname);
        return is_ok;
    }

Possible output: 
    
    
    Hello, world!
    End of file is reached successfully

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fopen&action=edit&section=6 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.5.3 The fopen function (p: 223-224) 



    

  * K.3.5.2.1 The fopen_s function (p: 428-429) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.5.3 The fopen function (p: 305-306) 



    

  * K.3.5.2.1 The fopen_s function (p: 588-590) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.5.3 The fopen function (p: 271-272) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.5.3 The fopen function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fopen&action=edit&section=7 "Edit section: See also")] See also

[ fclose](fclose.html "c/io/fclose") |  closes a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fclose&action=edit)  
---|---  
[ fflush](fflush.html "c/io/fflush") |  synchronizes an output stream with the actual file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fflush&action=edit)  
[ freopenfreopen_s](freopen.html "c/io/freopen")(C11) |  open an existing stream with a different name   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_freopen&action=edit)  
[C++ documentation](../../cpp/io/c/fopen.html "cpp/io/c/fopen") for fopen  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/fopen&oldid=149657](https://en.cppreference.com/mwiki/index.php?title=c/io/fopen&oldid=149657)" 

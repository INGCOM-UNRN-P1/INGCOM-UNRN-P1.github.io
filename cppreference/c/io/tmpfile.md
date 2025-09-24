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
**tmpfile tmpfile_s**(C11)  
  
| [rename](rename.html "c/io/rename")  
---  
[tmpnamtmpnam_s](tmpnam.html "c/io/tmpnam")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/navbar_content&action=edit)

Defined in header `[`<stdio.h>`](../header/stdio.html "c/header/stdio")` |  |   
---|---|---  
[FILE](FILE.html)* tmpfile( void ); |  (1)  |   
errno_t tmpfile_s( [FILE](FILE.html)* restrict* restrict streamptr ); |  (2)  |  (since C11)  
| |   
  
1) Creates and opens a temporary file. The file is opened as binary file for update (as if by [fopen](fopen.html "c/io/fopen") with "wb+" mode). The filename of the file is guaranteed to be unique within the filesystem. At least [TMP_MAX](../io.html "c/io") files may be opened during the lifetime of a program (this limit may be shared with [tmpnam](tmpnam.html "c/io/tmpnam") and may be further limited by [FOPEN_MAX](../io.html "c/io")).

2) Same as (1), except that at least TMP_MAX_S files may be opened (the limit may be shared with tmpnam_s), and if streamptr is a null pointer, the currently installed [constraint handler](../error/set_constraint_handler_s.html "c/error/set constraint handler s") function is called. 

    As with all bounds-checked functions, `tmpfile_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<stdio.h>`](../header/stdio.html "c/header/stdio").

The temporary file created by this function is closed and deleted when the program exits normally. Whether it's deleted on abnormal termination is implementation-defined. 

## Contents

  * [1 Parameters](tmpfile.html#Parameters)
  * [2 Return value](tmpfile.html#Return_value)
  * [3 Notes](tmpfile.html#Notes)
  * [4 Example](tmpfile.html#Example)
  * [5 References](tmpfile.html#References)
  * [6 See also](tmpfile.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/tmpfile&action=edit&section=1 "Edit section: Parameters")] Parameters

1) (none)

2) pointer to a pointer that will be updated by this function call

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/tmpfile&action=edit&section=2 "Edit section: Return value")] Return value

1) Pointer to the file stream associated with the file or null pointer if an error has occurred.

2) Zero if the file was created and open successfully, non-zero if the file was not created or open or if streamptr was a null pointer. In addition, pointer to the associated file stream is stored in *streamptr on success, and a null pointer value is stored in *streamptr on error.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/tmpfile&action=edit&section=3 "Edit section: Notes")] Notes

On some implementations (e.g. older Linux), this function actually creates, opens, and immediately deletes the file from the file system: as long as an open file descriptor to a deleted file is held by a program, the file exists, but since it was deleted, its name does not appear in any directory, so that no other process can open it. Once the file descriptor is closed, or once the program terminates (normally or abnormally), the space occupied by the file is reclaimed by the filesystem. Newer Linux (since 3.11 or later, depending on filesystem) creates such invisible temporary files in one step, via special flag in the [`open()`](https://man7.org/linux/man-pages/man2/open.2.html) syscall. 

On some implementations (e.g. Windows), elevated privileges are required as the function may create the temporary file in a system directory. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/tmpfile&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #define _POSIX_C_SOURCE 200112L
    #include <stdio.h>
    #include <unistd.h>
     
    int main(void)
    {
        [printf](fprintf.html)("TMP_MAX = %d, FOPEN_MAX = %d\n", [TMP_MAX](../io.html), [FOPEN_MAX](../io.html));
        [FILE](FILE.html)* tmpf = tmpfile();
        [fputs](fputs.html)("Hello, world", tmpf);
        [rewind](rewind.html)(tmpf);
        char buf[6];
        [fgets](fgets.html)(buf, sizeof buf, tmpf);
        [printf](fprintf.html)("got back from the file: '%s'\n", buf);
     
        // Linux-specific method to display the tmpfile name
        char fname[[FILENAME_MAX](../io.html)], link[[FILENAME_MAX](../io.html)] = {0};
        [sprintf](fprintf.html)(fname, "/proc/self/fd/%d", fileno(tmpf));
        if (readlink(fname, link, sizeof link - 1) > 0)
            [printf](fprintf.html)("File name: %s\n", link);
    }

Possible output: 
    
    
    TMP_MAX = 238328, FOPEN_MAX = 16
    got back from the file: 'Hello'
    File name: /tmp/tmpfjptPe5 (deleted)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/tmpfile&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.4.3 The tmpfile function (p: TBD) 



    

  * K.3.5.1.1 The tmpfile_s function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.4.3 The tmpfile function (p: 222) 



    

  * K.3.5.1.1 The tmpfile_s function (p: 427) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.4.3 The tmpfile function (p: 303) 



    

  * K.3.5.1.1 The tmpfile_s function (p: 586-587) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.4.3 The tmpfile function (p: 269) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.4.3 The tmpfile function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/tmpfile&action=edit&section=6 "Edit section: See also")] See also

[ tmpnamtmpnam_s](tmpnam.html "c/io/tmpnam")(C11) |  returns a unique filename   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_tmpnam&action=edit)  
---|---  
[C++ documentation](../../cpp/io/c/tmpfile.html "cpp/io/c/tmpfile") for tmpfile  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/tmpfile&oldid=158992](https://en.cppreference.com/mwiki/index.php?title=c/io/tmpfile&oldid=158992)" 

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
**setvbuf**  
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
int setvbuf( [FILE](FILE.html) * stream, char * buffer,   
int mode, [size_t](../types/size_t.html) size ); |  |  (until C99)  
int setvbuf( [FILE](FILE.html) *restrict stream, char *restrict buffer,   
int mode, [size_t](../types/size_t.html) size ); |  |  (since C99)  
#define _IOFBF /*unspecified*/  
#define _IOLBF /*unspecified*/  
#define _IONBF /*unspecified*/ |  |   
| |   
  
Changes the buffering mode of the given file stream `stream` as indicated by the argument `mode`. In addition, 

  * If `buffer` is a null pointer, resizes the internal buffer to `size`. 
  * If `buffer` is not a null pointer, instructs the stream to use the user-provided buffer of size `size` beginning at `buffer`. The stream must be closed (with [fclose](fclose.html "c/io/fclose")) before the [lifetime](../language/lifetime.html "c/language/lifetime") of the array pointed to by `buffer` ends. The contents of the array after a successful call to `setvbuf` are indeterminate and any attempt to use it is undefined behavior. 



## Contents

  * [1 Parameters](setvbuf.html#Parameters)
  * [2 Return value](setvbuf.html#Return_value)
  * [3 Notes](setvbuf.html#Notes)
  * [4 Example](setvbuf.html#Example)
  * [5 References](setvbuf.html#References)
  * [6 See also](setvbuf.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/setvbuf&action=edit&section=1 "Edit section: Parameters")] Parameters

stream  |  \-  |  the file stream to set the buffer to   
---|---|---  
buffer  |  \-  |  pointer to a buffer for the stream to use or null pointer to change size and mode only   
mode  |  \-  |  buffering mode to use. It can be one of the following values:  |  [_IOFBF](../io.html) |  full buffering   
---|---  
[_IOLBF](../io.html) |  line buffering   
[_IONBF](../io.html) |  no buffering   
size  |  \-  |  size of the buffer   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/setvbuf&action=edit&section=2 "Edit section: Return value")] Return value

​0​ on success or nonzero on failure. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/setvbuf&action=edit&section=3 "Edit section: Notes")] Notes

This function may only be used after `stream` has been associated with an open file, but before any other operation (other than a failed call to [setbuf](setbuf.html "c/io/setbuf")/`setvbuf`). 

Not all `size` bytes will necessarily be used for buffering: the actual buffer size is usually rounded down to a multiple of 2, a multiple of page size, etc. 

On many implementations, line buffering is only available for terminal input streams. 

A common error is setting the buffer of stdin or stdout to an array whose lifetime ends before the program terminates: 
    
    
    int main(void) {
        char buf[[BUFSIZ](../io.html)];
        [setbuf](setbuf.html)([stdin](std_streams.html), buf);
    } // lifetime of buf ends, undefined behavior

The default buffer size [BUFSIZ](../io.html "c/io") is expected to be the most efficient buffer size for file I/O on the implementation, but POSIX [fstat](http://pubs.opengroup.org/onlinepubs/9699919799/functions/fstat.html) often provides a better estimate. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/setvbuf&action=edit&section=4 "Edit section: Example")] Example

One use case for changing buffer size is when a better size is known. (This example uses some POSIX function, e.g. [`fileno`](https://pubs.opengroup.org/onlinepubs/7908799/xsh/fileno.html). See also SO: [#1](https://stackoverflow.com/questions/15749184/fileno-not-available) and [#2](https://stackoverflow.com/questions/44622827/why-am-i-getting-error-implicit-declaration-of-function-fileno-when-i-try-t)).

Run this code
    
    
    // Make some POSIX functions, such as `int fileno(FILE*)`, visible:
    #define _POSIX_SOURCE
     
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
     
    int main(void)
    {
        [FILE](FILE.html)* fp = [fopen](fopen.html)("/tmp/test.txt", "w+");
        if (fp == [NULL](../types/NULL.html))
        {
            [perror](perror.html)("fopen");
            return [EXIT_FAILURE](../program/EXIT_status.html);
        }
     
        struct stat stats;
        if (fstat(fileno(fp), &stats) == -1) // POSIX only
        {
            [perror](perror.html)("fstat");
            return [EXIT_FAILURE](../program/EXIT_status.html);
        }
     
        [printf](fprintf.html)("BUFSIZ is %d, but optimal block size is %ld\n", [BUFSIZ](../io.html), stats.st_blksize);
        if (setvbuf(fp, [NULL](../types/NULL.html), [_IOFBF](../io.html), stats.st_blksize) != 0)
        {
            [perror](perror.html)("setvbuf failed"); // POSIX version sets errno
            return [EXIT_FAILURE](../program/EXIT_status.html);
        }
     
        int ch;
        while((ch=[fgetc](fgetc.html)(fp)) != [EOF](../io.html)); // read entire file: use truss/strace to
                                      // observe the read(2) syscalls used
     
        [fclose](fclose.html)(fp);
        return [EXIT_SUCCESS](../program/EXIT_status.html);
    }

Possible output: 
    
    
    BUFSIZ is 8192, but optimal block size is 65536

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/setvbuf&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.5.6 The setvbuf function (p: 225) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.5.6 The setvbuf function (p: 308) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.5.6 The setvbuf function (p: 273-274) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.5.6 The setvbuf function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/setvbuf&action=edit&section=6 "Edit section: See also")] See also

[ setbuf](setbuf.html "c/io/setbuf") |  sets the buffer for a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_setbuf&action=edit)  
---|---  
[C++ documentation](../../cpp/io/c/setvbuf.html "cpp/io/c/setvbuf") for setvbuf  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/setvbuf&oldid=145360](https://en.cppreference.com/mwiki/index.php?title=c/io/setvbuf&oldid=145360)" 

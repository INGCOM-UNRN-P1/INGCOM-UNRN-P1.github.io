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
  
| **setbuf**  
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
void setbuf( [FILE](FILE.html) *stream, char *buffer ); |  |  (until C99)  
void setbuf( [FILE](FILE.html) *restrict stream, char *restrict buffer ); |  |  (since C99)  
#define BUFSIZ /*unspecified*/ |  |   
| |   
  
Sets the internal buffer to use for stream operations. It should be at least `BUFSIZ` characters long. 

If `buffer` is not null, equivalent to [setvbuf](setvbuf.html)(stream, buffer, [_IOFBF](../io.html), [BUFSIZ](../io.html)). 

If `buffer` is null, equivalent to [setvbuf](setvbuf.html)(stream, [NULL](../types/NULL.html), [_IONBF](../io.html), 0), which turns off buffering. 

## Contents

  * [1 Parameters](setbuf.html#Parameters)
  * [2 Return value](setbuf.html#Return_value)
  * [3 Notes](setbuf.html#Notes)
  * [4 Example](setbuf.html#Example)
  * [5 References](setbuf.html#References)
  * [6 See also](setbuf.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/setbuf&action=edit&section=1 "Edit section: Parameters")] Parameters

stream  |  \-  |  the file stream to set the buffer to   
---|---|---  
buffer  |  \-  |  pointer to a buffer for the stream to use. If a null pointer is supplied, the buffering is turned off   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/setbuf&action=edit&section=2 "Edit section: Return value")] Return value

None. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/setbuf&action=edit&section=3 "Edit section: Notes")] Notes

If [BUFSIZ](../io.html "c/io") is not the appropriate buffer size, [setvbuf](setvbuf.html "c/io/setvbuf") can be used to change it. 

[setvbuf](setvbuf.html "c/io/setvbuf") should also be used to detect errors, since `setbuf` does not indicate success or failure. 

This function may only be used after `stream` has been associated with an open file, but before any other operation (other than a failed call to **setbuf** /`setvbuf`). 

A common error is setting the buffer of stdin or stdout to an array whose lifetime ends before the program terminates: 
    
    
    int main(void) {
        char buf[[BUFSIZ](../io.html)];
        setbuf([stdin](std_streams.html), buf);
    } // lifetime of buf ends, undefined behavior

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/setbuf&action=edit&section=4 "Edit section: Example")] Example

`setbuf` may be used to disable buffering on streams that require immediate output.

Run this code
    
    
    #include <stdio.h>
    #include <threads.h>
     
    int main(void)
    {
        setbuf([stdout](std_streams.html), [NULL](../types/NULL.html)); // unbuffered stdout
        [putchar](putchar.html)('a'); // 'a' appears immediately if stdout is unbuffered
        [thrd_sleep](../thread/thrd_sleep.html)(&(struct timespec){.tv_sec=1}, [NULL](../types/NULL.html)); // sleep 1 sec
        [putchar](putchar.html)('b'); 
    }

Output: 
    
    
    ab

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/setbuf&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.5.5 The setbuf function (p: 225) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.5.5 The setbuf function (p: 307-308) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.5.5 The setbuf function (p: 273) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.5.5 The setbuf function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/setbuf&action=edit&section=6 "Edit section: See also")] See also

[ setvbuf](setvbuf.html "c/io/setvbuf") |  sets the buffer and its size for a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_setvbuf&action=edit)  
---|---  
[C++ documentation](../../cpp/io/c/setbuf.html "cpp/io/c/setbuf") for setbuf  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/setbuf&oldid=135090](https://en.cppreference.com/mwiki/index.php?title=c/io/setbuf&oldid=135090)" 

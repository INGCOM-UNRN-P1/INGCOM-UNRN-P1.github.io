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
**fflush**  
  
  
  
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
int fflush( [FILE](FILE.html)* stream ); |  |   
| |   
  
For output streams (and for update streams on which the last operation was output), writes any unwritten data from the stream's buffer to the associated output device. 

For input streams (and for update streams on which the last operation was input), the behavior is undefined. 

If stream is a null pointer, all open output streams are flushed, including the ones manipulated within library packages or otherwise not directly accessible to the program. 

## Contents

  * [1 Parameters](fflush.html#Parameters)
  * [2 Return value](fflush.html#Return_value)
  * [3 Notes](fflush.html#Notes)
  * [4 References](fflush.html#References)
  * [5 See also](fflush.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fflush&action=edit&section=1 "Edit section: Parameters")] Parameters

stream  |  \-  |  the file stream to write out   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fflush&action=edit&section=2 "Edit section: Return value")] Return value

Returns zero on success. Otherwise [EOF](../io.html "c/io") is returned and the error indicator of the file stream is set. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fflush&action=edit&section=3 "Edit section: Notes")] Notes

POSIX [extends the specification of fflush](https://pubs.opengroup.org/onlinepubs/9699919799/functions/fflush.html) by defining its effects on an input stream, as long as that stream represents a file or another seekable device: in that case the POSIX file pointer is repositioned to match the C stream pointer (which effectively undoes any read buffering) and the effects of any [ungetc](ungetc.html "c/io/ungetc") or [ungetwc](ungetwc.html "c/io/ungetwc") that weren't yet read back from the stream are discarded. 

Microsoft also extends the specification of fflush by defining its effects on an input stream: in Visual Studio 2013 and prior, it [discarded the input buffer](https://docs.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-2013/9yky46tz\(v=vs.120\)), in Visual Studio 2015 and newer, it [has no effect, buffers are retained](https://msdn.microsoft.com/en-us/library/9yky46tz.aspx). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fflush&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.5.2 The fflush function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.5.2 The fflush function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.5.2 The fflush function (p: 305) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.5.2 The fflush function (p: 270-271) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.5.2 The fflush function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fflush&action=edit&section=5 "Edit section: See also")] See also

[ fopenfopen_s](fopen.html "c/io/fopen")(C11) |  opens a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fopen&action=edit)  
---|---  
[ fclose](fclose.html "c/io/fclose") |  closes a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fclose&action=edit)  
[C++ documentation](../../cpp/io/c/fflush.html "cpp/io/c/fflush") for fflush  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/fflush&oldid=179126](https://en.cppreference.com/mwiki/index.php?title=c/io/fflush&oldid=179126)" 

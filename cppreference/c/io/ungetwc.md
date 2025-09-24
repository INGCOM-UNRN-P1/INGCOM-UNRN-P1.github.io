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
**ungetwc**(C95)  
  
  
  
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

Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")` |  |   
---|---|---  
wint_t ungetwc( wint_t ch, [FILE](FILE.html) *stream ); |  |  (since C95)  
| |   
  
If `ch` does not equal WEOF, pushes the wide character `ch` into the input buffer associated with the stream `stream` in such a manner that subsequent read operation from `stream` will retrieve that wide character. The external device associated with the stream is not modified. 

Stream repositioning operations [fseek](fseek.html "c/io/fseek"), [fsetpos](fsetpos.html "c/io/fsetpos"), and [rewind](rewind.html "c/io/rewind") discard the effects of `ungetwc`. 

If `ungetwc` is called more than once without an intervening read or repositioning, it may fail (in other words, a pushback buffer of size 1 is guaranteed, but any larger buffer is implementation-defined). If multiple successful `ungetwc` were performed, read operations retrieve the pushed-back wide characters in reverse order of `ungetwc`

If `ch` equals WEOF, the operation fails and the stream is not affected. 

A successful call to `ungetwc` clears the end of file status flag [feof](feof.html "c/io/feof"). 

A successful call to `ungetwc` on a stream (whether text or binary) modifies the stream position indicator in unspecified manner but guarantees that after all pushed-back wide characters are retrieved with a read operation, the stream position indicator is equal to its value before `ungetwc`. 

## Contents

  * [1 Parameters](ungetwc.html#Parameters)
  * [2 Return value](ungetwc.html#Return_value)
  * [3 References](ungetwc.html#References)
  * [4 See also](ungetwc.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/ungetwc&action=edit&section=1 "Edit section: Parameters")] Parameters

ch  |  \-  |  wide character to be put back   
---|---|---  
stream  |  \-  |  file stream to put the wide character back to   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/ungetwc&action=edit&section=2 "Edit section: Return value")] Return value

On success `ch` is returned. 

On failure WEOF is returned and the given stream remains unchanged. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/ungetwc&action=edit&section=3 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.29.3.10 The ungetwc function (p: 425-426) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.24.3.10 The ungetwc function (p: 370-371) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/ungetwc&action=edit&section=4 "Edit section: See also")] See also

[ ungetc](ungetc.html "c/io/ungetc") |  puts a character back into a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_ungetc&action=edit)  
---|---  
[ fgetwcgetwc](fgetwc.html "c/io/fgetwc")(C95) |  gets a wide character from a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fgetwc&action=edit)  
[C++ documentation](../../cpp/io/c/ungetwc.html "cpp/io/c/ungetwc") for ungetwc  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/ungetwc&oldid=86961](https://en.cppreference.com/mwiki/index.php?title=c/io/ungetwc&oldid=86961)" 

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
  
| **FILE**  
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
[tmpfiletmpfile_s](tmpfile.html "c/io/tmpfile")(C11)  
  
| [rename](rename.html "c/io/rename")  
---  
[tmpnamtmpnam_s](tmpnam.html "c/io/tmpnam")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/navbar_content&action=edit)

Defined in header `[`<stdio.h>`](../header/stdio.html "c/header/stdio")` |  |   
---|---|---  
typedef /* unspecified */ FILE; |  |   
| |   
  
Each `FILE` object denotes a C stream. 

C standard does not specify whether `FILE` is a complete object type. While it may be possible to copy a valid `FILE`, using a pointer to such a copy as an argument for an I/O function invokes unspecified behavior. In other words, `FILE` may be semantically non-copyable. 

I/O streams can be used for both unformatted and formatted input and output. Furthermore, the functions that handle input and output can also be locale-sensitive, such that wide/multibyte conversions are performed as necessary. 

## Contents

  * [1 Stream state](FILE.html#Stream_state)
    * [1.1 Narrow and wide orientation](FILE.html#Narrow_and_wide_orientation)
    * [1.2 Binary and text modes](FILE.html#Binary_and_text_modes)
  * [2 Notes](FILE.html#Notes)
  * [3 References](FILE.html#References)
  * [4 See also](FILE.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/FILE&action=edit&section=1 "Edit section: Stream state")] Stream state

Besides the system-specific information necessary to access the device (_e.g.,_ a POSIX file descriptor), each `FILE` object directly or indirectly holds the following: 

  1. (C95) Character width: unset, narrow, or wide. 
  2. (C95) Parse state for conversions between multibyte and wide characters (an object of type [mbstate_t](../string/multibyte/mbstate_t.html "c/string/multibyte/mbstate t")) 
  3. Buffering state: unbuffered, line-buffered, fully buffered. 
  4. The buffer, which may be replaced by an external, user-provided buffer. 
  5. I/O mode: input, output, or update (both input and output). 
  6. Binary/text mode indicator. 
  7. End-of-file status indicator. 
  8. Error status indicator. 
  9. File position indicator, accessible as an object of type [fpos_t](fpos_t.html "c/io/fpos t"), which, for wide streams, includes parse state. 
  10. (C11) Reentrant lock used to prevent data races when multiple threads read, write, position, or query the position of a stream. 



#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/FILE&action=edit&section=2 "Edit section: Narrow and wide orientation")] Narrow and wide orientation

A newly opened stream has no orientation. The first call to fwide or to any I/O function establishes the orientation: a wide I/O function makes the stream wide-oriented; a narrow I/O function makes the stream narrow-oriented. Once set, the orientation can be changed with only [freopen](freopen.html "c/io/freopen"). Narrow I/O functions cannot be called on a wide-oriented stream; wide I/O functions cannot be called on a narrow-oriented stream. Wide I/O functions convert between wide and multibyte characters as if by calling [mbrtowc](../string/multibyte/mbrtowc.html "c/string/multibyte/mbrtowc") or [wcrtomb](../string/multibyte/wcrtomb.html "c/string/multibyte/wcrtomb") with the conversion state as described by the stream. Unlike the multibyte character strings that are valid in a program, multibyte character sequences in the file may contain embedded nulls and do not have to begin or end in the initial shift state. 

The conversion state of a stream with wide orientation is established by the C locale that is installed at the time the stream's orientation is set. 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/FILE&action=edit&section=3 "Edit section: Binary and text modes")] Binary and text modes

A _text stream_ is an ordered sequence of characters that can be composed into lines; a line can be decomposed into zero or more characters plus a terminating '\n' (“newline”) character. Whether the last line requires a terminating '\n' is implementation-defined. Furthermore, characters may have to be added, altered, or deleted on input and output to conform to the conventions for representing text in the OS (in particular, C streams on Windows OS convert '\n' to '\r\n' on output, and convert '\r\n' to '\n' on input). 

Data read in from a text stream is guaranteed to compare equal to the data that were earlier written out to that stream only if each of the following is true: 

  * The data consist of only printing characters and/or the control characters '\t' and '\n' (in particular, on Windows OS, the character '\0x1A' terminates input). 
  * No '\n' character is immediately preceded by space characters (such space characters may disappear when such output is later read as input). 
  * The last character is '\n'. 



A _binary stream_ is an ordered sequence of characters that can transparently record internal data. Data read in from a binary stream always equal the data that were earlier written out to that stream, except that an implementation is allowed to append an indeterminate number of null characters to the end of the stream. A wide binary stream doesn't need to end in the initial shift state. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/FILE&action=edit&section=4 "Edit section: Notes")] Notes

POSIX explicitly requires that the `LC_CTYPE` facet of the currently installed C locale be stored within the `FILE` object the moment the stream's orientation becomes wide; POSIX requires that this `LC_CTYPE` facet be used for all future I/O on this stream until the orientation is changed, regardless of any subsequent call to [setlocale](../locale/setlocale.html "c/locale/setlocale"). 

It is intended that each line of text be composed of data that are essentially human-readable. POSIX implementations do not distinguish between text and binary streams (there is no special mapping for '\n' or any other characters). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/FILE&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21 Input/output <stdio.h> (p: 217-247) 



    

  * 7.29 Extended multibyte and wide character utilities <wchar.h> (p: 295-325) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21 Input/output <stdio.h> (p: 296-339) 



    

  * 7.29 Extended multibyte and wide character utilities <wchar.h> (p: 402-446) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19 Input/output <stdio.h> (p: 262-305) 



    

  * 7.24 Extended multibyte and wide character utilities <wchar.h> (p: 348-392) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9 INPUT/OUTPUT <stdio.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/FILE&action=edit&section=6 "Edit section: See also")] See also

[ stdinstdoutstderr](std_streams.html "c/io/std streams") |  expression of type FILE* associated with the input stream  
expression of type FILE* associated with the output stream  
expression of type FILE* associated with the error output stream   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_std_streams&action=edit)  
---|---  
[C++ documentation](../../cpp/io/c/FILE.html "cpp/io/c/FILE") for FILE  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/FILE&oldid=151194](https://en.cppreference.com/mwiki/index.php?title=c/io/FILE&oldid=151194)" 

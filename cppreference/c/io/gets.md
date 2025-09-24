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
**gets gets_s**(until C11)(C11)  
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
char* gets( char* str ); |  (1)  |  (removed in C11)  
char* gets_s( char* str, rsize_t n ); |  (2)  |  (since C11)  
| |   
  
1) Reads [stdin](std_streams.html "c/io/std streams") into the character array pointed to by str until a newline character is found or end-of-file occurs. A null character is written immediately after the last character read into the array. The newline character is discarded but not stored in the buffer.

2) Reads characters from [stdin](std_streams.html "c/io/std streams") until a newline is found or end-of-file occurs. Writes only at most n - 1 characters into the array pointed to by str, and always writes the terminating null character (unless str is a null pointer). The newline character, if found, is discarded and does not count toward the number of characters written to the buffer.

The following errors are detected at runtime and call the currently installed [constraint handler](../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

  * n is zero; 
  * n is greater than RSIZE_MAX; 
  * str is a null pointer; 
  * _endline_ or _eof_ not encountered after storing n - 1 characters to the buffer.



In any case, `gets_s` first finishes reading and discarding the characters from [stdin](std_streams.html "c/io/std streams") until new-line character, end-of-file condition, or read error before calling the constraint handler.

As with all bounds-checked functions, `gets_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<stdio.h>`](../header/stdio.html "c/header/stdio").

## Contents

  * [1 Parameters](gets.html#Parameters)
  * [2 Return value](gets.html#Return_value)
  * [3 Notes](gets.html#Notes)
  * [4 References](gets.html#References)
  * [5 See also](gets.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/gets&action=edit&section=1 "Edit section: Parameters")] Parameters

str  |  \-  |  a character array the characters from [stdin](std_streams.html "c/io/std streams") to be written to   
---|---|---  
n  |  \-  |  maximum number of characters that can be written to the array pointed to by str  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/gets&action=edit&section=2 "Edit section: Return value")] Return value

str on success, a null pointer on failure. 

If the failure has been caused by end of file condition, additionally sets the _eof_ indicator (see [feof()](feof.html "c/io/feof")) on [stdin](std_streams.html "c/io/std streams"). If the failure has been caused by some other error, sets the _error_ indicator (see [ferror()](ferror.html "c/io/ferror")) on [stdin](std_streams.html "c/io/std streams"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/gets&action=edit&section=3 "Edit section: Notes")] Notes

The `gets()` function does not perform bounds checking, therefore this function is extremely vulnerable to buffer-overflow attacks. It cannot be used safely (unless the program runs in an environment which restricts what can appear on `stdin`). For this reason, the function has been deprecated in the third corrigendum to the C99 standard and removed altogether in the C11 standard. [fgets()](fgets.html "c/io/fgets") and `gets_s()` are the recommended replacements. 

**WARNING: Never use`gets()`**. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/gets&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * K.3.5.4.1 The gets_s function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * K.3.5.4.1 The gets_s function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * K.3.5.4.1 The gets_s function (p: 602-603) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.7.7 The gets function (p: 298) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.7.7 The gets function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/gets&action=edit&section=5 "Edit section: See also")] See also

[ scanffscanfsscanfscanf_sfscanf_ssscanf_s](fscanf.html "c/io/fscanf")(C11)(C11)(C11) |  reads formatted input from [stdin](std_streams.html "c/io/std streams"), a file stream or a buffer   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fscanf&action=edit)  
---|---  
[ fgets](fgets.html "c/io/fgets") |  gets a character string from a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fgets&action=edit)  
[ fputs](fputs.html "c/io/fputs") |  writes a character string to a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fputs&action=edit)  
[ getlinegetwlinegetdelimgetwdelim](../experimental/dynamic/getline.html "c/experimental/dynamic/getline")(dynamic memory TR) |  read from a stream into an automatically resized buffer until delimiter/end of line   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/dsc_getline&action=edit)  
[C++ documentation](../../cpp/io/c/gets.html "cpp/io/c/gets") for gets  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/gets&oldid=172391](https://en.cppreference.com/mwiki/index.php?title=c/io/gets&oldid=172391)" 

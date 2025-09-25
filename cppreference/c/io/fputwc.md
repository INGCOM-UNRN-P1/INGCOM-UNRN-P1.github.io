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
**fputwc putwc**(C95)(C95)  
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

Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")` |  |   
---|---|---  
wint_t fputwc( wchar_t ch, [FILE](FILE.html)* stream ); |  (1)  |  (since C95)  
wint_t putwc( wchar_t ch, [FILE](FILE.html)* stream ); |  (2)  |  (since C95)  
| |   
  
Writes a wide character ch to the given output stream stream. 

2) May be implemented as a macro and may evaluate stream more than once.

## Contents

  * [1 Parameters](fputwc.html#Parameters)
  * [2 Return value](fputwc.html#Return_value)
  * [3 Example](fputwc.html#Example)
  * [4 References](fputwc.html#References)
  * [5 See also](fputwc.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fputwc&action=edit&section=1 "Edit section: Parameters")] Parameters

ch  |  \-  |  wide character to be written   
---|---|---  
stream  |  \-  |  the output stream   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fputwc&action=edit&section=2 "Edit section: Return value")] Return value

Returns a copy of ch on success. 

On failure, returns WEOF and sets the _error_ indicator (see [ferror()](ferror.html "c/io/ferror")) on stream. 

If an encoding error occurred, additionally sets [errno](../error/errno.html "c/error/errno") to [EILSEQ](../error/errno_macros.html "c/error/errno macros"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fputwc&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <errno.h>
    #include <locale.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <wchar.h>
     
    int main(void)
    {
        [setlocale](../locale/setlocale.html)([LC_ALL](../locale/LC_categories.html), "en_US.utf8");
     
        errno = 0;
        if (fputwc(L'🍌', [stdout](std_streams.html)) == WEOF)
        {
            if (errno == [EILSEQ](../error/errno_macros.html))
                [puts](puts.html)("Encoding error in fputwc.");
            else
                [puts](puts.html)("I/O error in fputwc.");
            return [EXIT_FAILURE](../program/EXIT_status.html);
        }
    }

Possible output: 
    
    
    🍌

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fputwc&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.31.3.3 The fputwc function (p: 430) 



    

  * 7.31.3.8 The putwc function (p: 431-432) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.29.3.3 The fputwc function (p: 308) 



    

  * 7.29.3.8 The putwc function (p: 310) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.29.3.3 The fputwc function (p: 422-423) 



    

  * 7.29.3.8 The putwc function (p: 424) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.24.3.3 The fputwc function (p: 368) 



    

  * 7.24.3.8 The putwc function (p: 370) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fputwc&action=edit&section=5 "Edit section: See also")] See also

[ fputcputc](putc.html "c/io/fputc") |  writes a character to a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fputc&action=edit)  
---|---  
[ fputws](fputws.html "c/io/fputws")(C95) |  writes a wide string to a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fputws&action=edit)  
[ fgetwcgetwc](fgetwc.html "c/io/fgetwc")(C95) |  gets a wide character from a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fgetwc&action=edit)  
[C++ documentation](../../cpp/io/c/fputwc.html "cpp/io/c/fputwc") for fputwc  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/fputwc&oldid=158956](https://en.cppreference.com/mwiki/index.php?title=c/io/fputwc&oldid=158956)" 

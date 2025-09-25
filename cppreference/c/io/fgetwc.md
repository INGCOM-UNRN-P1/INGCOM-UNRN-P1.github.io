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
  
| **fgetwc getwc**(C95)(C95)  
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

Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")` |  |   
---|---|---  
wint_t fgetwc( [FILE](FILE.html) *stream ); |  |  (since C95)  
wint_t getwc( [FILE](FILE.html) *stream ); |  |  (since C95)  
| |   
  
Reads the next wide character from the given input stream. getwc() may be implemented as a macro and may evaluate `stream` more than once. 

## Contents

  * [1 Parameters](fgetwc.html#Parameters)
  * [2 Return value](fgetwc.html#Return_value)
  * [3 Example](fgetwc.html#Example)
  * [4 References](fgetwc.html#References)
  * [5 See also](fgetwc.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetwc&action=edit&section=1 "Edit section: Parameters")] Parameters

stream  |  \-  |  to read the wide character from   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetwc&action=edit&section=2 "Edit section: Return value")] Return value

The next wide character from the stream or WEOF on failure. 

If the failure has been caused by end-of-file condition, additionally sets the _eof_ indicator (see [feof()](feof.html "c/io/feof")) on `stream`. If the failure has been caused by some other error, sets the _error_ indicator (see [ferror()](ferror.html "c/io/ferror")) on `stream`. 

If an encoding error occurred, additionally sets [errno](../error/errno.html "c/error/errno") to `EILSEQ`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetwc&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <wchar.h>
    #include <errno.h>
    #include <locale.h>
     
    int main(void)
    {
        [setlocale](../locale/setlocale.html)([LC_ALL](../locale/LC_categories.html), "en_US.utf8");
        [FILE](FILE.html) *fp = [fopen](fopen.html)("fgetwc.dat", "w");
        if(!fp) {
            [perror](perror.html)("Can't open file for writing");
            return [EXIT_FAILURE](../program/EXIT_status.html);
        }
        [fputs](fputs.html)("кошка\n", fp);
        [fclose](fclose.html)(fp);
     
        fp = [fopen](fopen.html)("fgetwc.dat", "r");
        if(!fp) {
            [perror](perror.html)("Can't open file for reading");
            return [EXIT_FAILURE](../program/EXIT_status.html);
        }
        wint_t wc;
        errno = 0;
        while ((wc = fgetwc(fp)) != WEOF)
            [putwchar](putwchar.html)(wc);
     
        if ([ferror](ferror.html)(fp)) {
            if (errno == [EILSEQ](../error/errno_macros.html))
                [puts](puts.html)("Character encoding error while reading.");
            else
                [puts](puts.html)("I/O error when reading");
        } else if ([feof](feof.html)(fp))
            [puts](puts.html)("End of file reached successfully");
     
        [fclose](fclose.html)(fp);
    }

Output: 
    
    
    кошка

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetwc&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.29.3.1 The fgetwc function (p: 307-308) 



    

  * 7.29.3.6 The getwc function (p: 309) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.29.3.1 The fgetwc function (p: 421-422) 



    

  * 7.29.3.6 The getwc function (p: 424) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.24.3.1 The fgetwc function (p: 367) 



    

  * 7.24.3.6 The getwc function (p: 369) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetwc&action=edit&section=5 "Edit section: See also")] See also

[ fgetcgetc](fgetc.html "c/io/fgetc") |  gets a character from a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fgetc&action=edit)  
---|---  
[ fgetws](fgetws.html "c/io/fgetws")(C95) |  gets a wide string from a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fgetws&action=edit)  
[ fputwcputwc](fputwc.html "c/io/fputwc")(C95) |  writes a wide character to a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fputwc&action=edit)  
[ ungetwc](ungetwc.html "c/io/ungetwc")(C95) |  puts a wide character back into a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_ungetwc&action=edit)  
[C++ documentation](../../cpp/io/c/fgetwc.html "cpp/io/c/fgetwc") for fgetwc  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/fgetwc&oldid=133650](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetwc&oldid=133650)" 

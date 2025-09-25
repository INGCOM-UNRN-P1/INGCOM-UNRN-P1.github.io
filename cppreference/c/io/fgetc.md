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
| **fgetc**  
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
int fgetc( [FILE](FILE.html)* stream ); |  (1)  |   
int getc( [FILE](FILE.html)* stream ); |  (2)  |   
| |   
  
1) Reads the next character from the given input stream.

2) Same as `fgetc`, except that if `getc` is implemented as a macro, it may evaluate stream more than once, so the corresponding argument should never be an expression with side effects.

## Contents

  * [1 Parameters](fgetc.html#Parameters)
  * [2 Return value](fgetc.html#Return_value)
  * [3 Example](fgetc.html#Example)
  * [4 References](fgetc.html#References)
  * [5 See also](fgetc.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetc&action=edit&section=1 "Edit section: Parameters")] Parameters

stream  |  \-  |  to read the character from   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetc&action=edit&section=2 "Edit section: Return value")] Return value

On success, returns the obtained character as an unsigned char converted to an int. On failure, returns [EOF](../io.html "c/io"). 

If the failure has been caused by end-of-file condition, additionally sets the _eof_ indicator (see [feof()](feof.html "c/io/feof")) on stream. If the failure has been caused by some other error, sets the _error_ indicator (see [ferror()](ferror.html "c/io/ferror")) on stream. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetc&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        const char* fname = "/tmp/unique_name.txt"; // or tmpnam(NULL);
        int is_ok = [EXIT_FAILURE](../program/EXIT_status.html);
     
        [FILE](FILE.html)* fp = [fopen](fopen.html)(fname, "w+");
        if (!fp)
        {
            [perror](perror.html)("File opening failed");
            return is_ok;
        }
        [fputs](fputs.html)("Hello, world!\n", fp);
        [rewind](rewind.html)(fp);
     
        int c; // note: int, not char, required to handle EOF
        while ((c = fgetc(fp)) != [EOF](../io.html)) // standard C I/O file reading loop
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

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetc&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.7.1 The fgetc function (p: TBD) 



    

  * 7.21.7.5 The getc function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.7.1 The fgetc function (p: 240-241) 



    

  * 7.21.7.5 The getc function (p: 242) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.7.1 The fgetc function (p: 330) 



    

  * 7.21.7.5 The getc function (p: 332) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.7.1 The fgetc function (p: 296) 



    

  * 7.19.7.5 The getc function (p: 297-298) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.7.1 The fgetc function 



    

  * 4.9.7.5 The getc function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetc&action=edit&section=5 "Edit section: See also")] See also

[ getchar](getchar.html "c/io/getchar") |  reads a character from [stdin](std_streams.html "c/io/std streams")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_getchar&action=edit)  
---|---  
[ getsgets_s](gets.html "c/io/gets")(removed in C11)(C11) |  reads a character string from [stdin](std_streams.html "c/io/std streams")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_gets&action=edit)  
[ fputcputc](putc.html "c/io/fputc") |  writes a character to a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fputc&action=edit)  
[ ungetc](ungetc.html "c/io/ungetc") |  puts a character back into a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_ungetc&action=edit)  
[C++ documentation](../../cpp/io/c/fgetc.html "cpp/io/c/fgetc") for fgetc, getc  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/fgetc&oldid=172389](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetc&oldid=172389)" 

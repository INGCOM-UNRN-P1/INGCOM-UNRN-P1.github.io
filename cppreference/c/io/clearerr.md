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
| **clearerr**  
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
void clearerr( [FILE](FILE.html) *stream ); |  |   
| |   
  
Resets the error flags and the [`EOF`](../io.html#Macro_constants "c/io") indicator for the given file stream. 

## Contents

  * [1 Parameters](clearerr.html#Parameters)
  * [2 Return value](clearerr.html#Return_value)
  * [3 Example](clearerr.html#Example)
  * [4 References](clearerr.html#References)
  * [5 See also](clearerr.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/clearerr&action=edit&section=1 "Edit section: Parameters")] Parameters

stream  |  \-  |  the file to reset the error flags for   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/clearerr&action=edit&section=2 "Edit section: Return value")] Return value

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/clearerr&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <assert.h>
     
    int main(void)
    {
        [FILE](FILE.html)* tmpf = [tmpfile](tmpfile.html)();
        [fputs](fputs.html)("cppreference.com\n", tmpf);
        [rewind](rewind.html)(tmpf);
     
        for (int ch; (ch = [fgetc](fgetc.html)(tmpf)) != [EOF](../io.html); [putchar](putchar.html)(ch)) { }
     
        [assert](../error/assert.html)([feof](feof.html)(tmpf)); // the loop is expected to terminate by EOF
        [puts](puts.html)("End of file reached");
     
        clearerr(tmpf); // clear EOF
     
        [puts](puts.html)([feof](feof.html)(tmpf) ? "EOF indicator set" 
                        : "EOF indicator cleared");
    }

Output: 
    
    
    cppreference.com
    End of file reached
    EOF indicator cleared

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/clearerr&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.10.1 The clearerr function (p: 246) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.10.1 The clearerr function (p: 338) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.10.1 The clearerr function (p: 304) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.10.1 The clearerr function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/clearerr&action=edit&section=5 "Edit section: See also")] See also

[ feof](feof.html "c/io/feof") |  checks for the end-of-file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_feof&action=edit)  
---|---  
[ perror](perror.html "c/io/perror") |  displays a character string corresponding of the current error to [stderr](std_streams.html "c/io/std streams")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_perror&action=edit)  
[ ferror](ferror.html "c/io/ferror") |  checks for a file error   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_ferror&action=edit)  
[C++ documentation](../../cpp/io/c/clearerr.html "cpp/io/c/clearerr") for clearerr  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/clearerr&oldid=142553](https://en.cppreference.com/mwiki/index.php?title=c/io/clearerr&oldid=142553)" 

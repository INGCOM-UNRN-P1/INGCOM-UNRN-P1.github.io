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
| [clearerr](clearerr.html "c/io/clearerr")  
---  
**feof**  
  
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
int feof( [FILE](FILE.html) *stream ); |  |   
| |   
  
Checks if the end of the given file stream has been reached. 

## Contents

  * [1 Parameters](feof.html#Parameters)
  * [2 Return value](feof.html#Return_value)
  * [3 Notes](feof.html#Notes)
  * [4 Example](feof.html#Example)
  * [5 References](feof.html#References)
  * [6 See also](feof.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/feof&action=edit&section=1 "Edit section: Parameters")] Parameters

stream  |  \-  |  the file stream to check   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/feof&action=edit&section=2 "Edit section: Return value")] Return value

nonzero value if the end of the stream has been reached, otherwise ​0​

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/feof&action=edit&section=3 "Edit section: Notes")] Notes

This function only reports the stream state as reported by the most recent I/O operation, it does not examine the associated data source. For example, if the most recent I/O was a [fgetc](fgetc.html "c/io/fgetc"), which returned the last byte of a file, `feof` returns zero. The next [fgetc](fgetc.html "c/io/fgetc") fails and changes the stream state to _end-of-file_. Only then `feof` returns non-zero. 

In typical usage, input stream processing stops on any error; `feof` and [ferror](ferror.html "c/io/ferror") are then used to distinguish between different error conditions. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/feof&action=edit&section=4 "Edit section: Example")] Example

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
        while ((c = [fgetc](fgetc.html)(fp)) != [EOF](../io.html)) // standard C I/O file reading loop
            [putchar](putchar.html)(c);
     
        if ([ferror](ferror.html)(fp))
            [puts](puts.html)("I/O error when reading");
        else if (feof(fp))
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

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/feof&action=edit&section=5 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.10.2 The feof function (p: 339) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.10.2 The feof function (p: 305) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.10.2 The feof function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/feof&action=edit&section=6 "Edit section: See also")] See also

[ clearerr](clearerr.html "c/io/clearerr") |  clears errors   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_clearerr&action=edit)  
---|---  
[ perror](perror.html "c/io/perror") |  displays a character string corresponding of the current error to [stderr](std_streams.html "c/io/std streams")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_perror&action=edit)  
[ ferror](ferror.html "c/io/ferror") |  checks for a file error   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_ferror&action=edit)  
[C++ documentation](../../cpp/io/c/feof.html "cpp/io/c/feof") for feof  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/feof&oldid=78948](https://en.cppreference.com/mwiki/index.php?title=c/io/feof&oldid=78948)" 

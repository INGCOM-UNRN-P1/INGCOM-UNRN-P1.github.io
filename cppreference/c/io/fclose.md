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
**fclose**  
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
int fclose( [FILE](FILE.html)* stream ); |  |   
| |   
  
Closes the given file stream. Any unwritten buffered data are flushed to the OS. Any unread buffered data are discarded. 

Whether or not the operation succeeds, the stream is no longer associated with a file, and the buffer allocated by [setbuf](setbuf.html "c/io/setbuf") or [setvbuf](setvbuf.html "c/io/setvbuf"), if any, is also disassociated and deallocated if automatic allocation was used. 

The behavior is undefined if the value of the pointer stream is used after `fclose` returns. 

## Contents

  * [1 Parameters](fclose.html#Parameters)
  * [2 Return value](fclose.html#Return_value)
  * [3 Example](fclose.html#Example)
  * [4 References](fclose.html#References)
  * [5 See also](fclose.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fclose&action=edit&section=1 "Edit section: Parameters")] Parameters

stream  |  \-  |  the file stream to close   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fclose&action=edit&section=2 "Edit section: Return value")] Return value

​0​ on success, [EOF](../io.html "c/io") otherwise 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fclose&action=edit&section=3 "Edit section: Example")] Example

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
        else if ([feof](feof.html)(fp))
        {
            [puts](puts.html)("End of file is reached successfully");
            is_ok = [EXIT_SUCCESS](../program/EXIT_status.html);
        }
     
        fclose(fp);
        [remove](remove.html)(fname);
        return is_ok;
    }

Possible output: 
    
    
    Hello, world!
    End of file is reached successfully

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fclose&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.5.1 The fclose function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.5.1 The fclose function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.5.1 The fclose function (p: 304) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.5.1 The fclose function (p: 270) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.5.1 The fclose function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fclose&action=edit&section=5 "Edit section: See also")] See also

[ fopenfopen_s](fopen.html "c/io/fopen")(C11) |  opens a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fopen&action=edit)  
---|---  
[ freopenfreopen_s](freopen.html "c/io/freopen")(C11) |  open an existing stream with a different name   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_freopen&action=edit)  
[C++ documentation](../../cpp/io/c/fclose.html "cpp/io/c/fclose") for fclose  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/fclose&oldid=179127](https://en.cppreference.com/mwiki/index.php?title=c/io/fclose&oldid=179127)" 

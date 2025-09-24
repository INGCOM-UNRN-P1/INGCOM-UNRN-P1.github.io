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
**fwide**(C95)  
  
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

Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")` |  |   
---|---|---  
int fwide( [FILE](FILE.html)* stream, int mode ); |  |  (since C95)  
| |   
  
If mode > 0, attempts to make stream wide-oriented. If mode < 0, attempts to make stream byte-oriented. If mode == 0, only queries the current orientation of the stream. 

If the orientation of the stream has already been decided (by executing output or by an earlier call to `fwide`), this function does nothing. 

## Contents

  * [1 Parameters](fwide.html#Parameters)
  * [2 Return value](fwide.html#Return_value)
  * [3 Example](fwide.html#Example)
  * [4 References](fwide.html#References)
  * [5 See also](fwide.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fwide&action=edit&section=1 "Edit section: Parameters")] Parameters

stream  |  \-  |  pointer to the C I/O stream to modify or query   
---|---|---  
mode  |  \-  |  integer value greater than zero to set the stream wide, less than zero to set the stream narrow, or zero to query only   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fwide&action=edit&section=2 "Edit section: Return value")] Return value

An integer greater than zero if the stream is wide-oriented after this call, less than zero if the stream is byte-oriented after this call, and zero if the stream has no orientation. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fwide&action=edit&section=3 "Edit section: Example")] Example

The following code sets and resets the stream orientation.

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <wchar.h>
     
    void show_orientation(int n)
    {
        n < 0 ? [puts](puts.html)("\tnarrow orientation"):
        n > 0 ? [puts](puts.html)("\twide orientation"):
                [puts](puts.html)("\tno orientation");
    }
     
    void try_read([FILE](FILE.html)* fp)
    {
        int c = [fgetc](fgetc.html)(fp);
        c == [EOF](../io.html)
            ? [printf](fprintf.html)("\tnarrow character read failed\n")
            : [printf](fprintf.html)("\tnarrow character read '%c'\n", c);
     
        wint_t wc = [fgetwc](fgetwc.html)(fp);
        wc == WEOF
            ? [printf](fprintf.html)("\twide character read failed\n")
            : [printf](fprintf.html)("\twide character read '%lc'\n", wc);
    }
     
    int main(void)
    {
        enum fwide_orientation { narrow = -1, query, wide };
     
        [FILE](FILE.html)* fp = [fopen](fopen.html)("main.cpp", "r");
        if (!fp)
        {
            [perror](perror.html)("fopen() failed");
            return [EXIT_FAILURE](../program/EXIT_status.html);
        }
     
        [puts](puts.html)("1) A newly opened stream has no orientation.");
        show_orientation(fwide(fp, query));
     
        [puts](puts.html)("2) Establish byte orientation.");
        show_orientation(fwide(fp, narrow));
        try_read(fp);
     
        [puts](puts.html)("3) Only freopen() can reset stream orientation.");
        if ([freopen](freopen.html)("main.cpp", "r", fp) == [NULL](../types/NULL.html))
        {
           [perror](perror.html)("freopen() failed");
           return [EXIT_FAILURE](../program/EXIT_status.html);
        }
     
        [puts](puts.html)("4) A reopened stream has no orientation.");
        show_orientation(fwide(fp, query));
     
        [puts](puts.html)("5) Establish wide orientation.");
        show_orientation(fwide(fp, wide));
        try_read(fp);
     
        [fclose](fclose.html)(fp);
    }

Possible output: 
    
    
    1) A newly opened stream has no orientation.
            no orientation
    2) Establish byte orientation.
            narrow orientation
            narrow character read '#'
            wide character read failed
    3) Only freopen() can reset stream orientation.
    4) A reopened stream has no orientation.
            no orientation
    5) Establish wide orientation.
            wide orientation
            narrow character read failed
            wide character read '#'

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fwide&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.29.3.5 The fwide function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.29.3.5 The fwide function (p: 309) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.29.3.5 The fwide function (p: 423) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.24.3.5 The fwide function (p: 369) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fwide&action=edit&section=5 "Edit section: See also")] See also

[ fopenfopen_s](fopen.html "c/io/fopen")(C11) |  opens a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fopen&action=edit)  
---|---  
[C++ documentation](../../cpp/io/c/fwide.html "cpp/io/c/fwide") for fwide  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/fwide&oldid=179125](https://en.cppreference.com/mwiki/index.php?title=c/io/fwide&oldid=179125)" 

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
**putchar**  
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
int putchar( int ch ); |  |   
| |   
  
Writes a character ch to [stdout](std_streams.html "c/io/std streams"). Internally, the character is converted to unsigned char just before being written. 

Equivalent to [putc](putc.html)(ch, [stdout](std_streams.html)). 

## Contents

  * [1 Parameters](putchar.html#Parameters)
  * [2 Return value](putchar.html#Return_value)
  * [3 Example](putchar.html#Example)
  * [4 References](putchar.html#References)
  * [5 See also](putchar.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/putchar&action=edit&section=1 "Edit section: Parameters")] Parameters

ch  |  \-  |  character to be written   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/putchar&action=edit&section=2 "Edit section: Return value")] Return value

On success, returns the written character. 

On failure, returns [EOF](../io.html "c/io") and sets the _error_ indicator (see [ferror()](ferror.html "c/io/ferror")) on [stdout](std_streams.html "c/io/std streams"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/putchar&action=edit&section=3 "Edit section: Example")] Example

Shows `putchar` with error checking

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        int ret_code = 0;
        for (char c = 'a'; (ret_code != [EOF](../io.html)) && (c != 'z'); c++)
            ret_code = putchar(c);
     
        // Test whether EOF was reached.
        if (ret_code == [EOF](../io.html) && [ferror](ferror.html)([stdout](std_streams.html)))
        {
            [fprintf](fprintf.html)([stderr](std_streams.html), "putchar() failed in file %s at line # %d\n",
                    __FILE__, __LINE__ - 6);
            [perror](perror.html)("putchar()");
            [exit](../program/exit.html)([EXIT_FAILURE](../program/EXIT_status.html));
        }
        putchar('\n');
     
        // putchar return value is not equal to the argument
        int r = 0x1070;
        [printf](fprintf.html)("\n0x%x\n", r);
        r = putchar(r);
        [printf](fprintf.html)("\n0x%x\n", r);
    }

Output: 
    
    
    abcdefghijklmnopqrstuvwxy
     
    0x1070
    p
    0x70

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/putchar&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.7.8 The putchar function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.7.8 The putchar function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.7.8 The putchar function (p: 333) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.7.9 The putchar function (p: 299) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.7.9 The putchar function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/putchar&action=edit&section=5 "Edit section: See also")] See also

[ fputcputc](putc.html "c/io/fputc") |  writes a character to a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fputc&action=edit)  
---|---  
[C++ documentation](../../cpp/io/c/putchar.html "cpp/io/c/putchar") for putchar  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/putchar&oldid=172392](https://en.cppreference.com/mwiki/index.php?title=c/io/putchar&oldid=172392)" 

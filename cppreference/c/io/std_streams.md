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
|  | **stdin stdoutstderr**` `  
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
#define stdin /* implementation-defined */ |  (1)  |   
#define stdout /* implementation-defined */ |  (2)  |   
#define stderr /* implementation-defined */ |  (3)  |   
| |   
  
Three text streams are predefined. These streams are implicitly opened and unoriented at program startup. 

1) Associated with the _standard input_ stream, used for reading conventional input. At program startup, the stream is fully buffered if and only if the stream can be determined to not refer to an interactive device.

2) Associated with the _standard output_ stream, used for writing conventional output. At program startup, the stream is fully buffered if and only if the stream can be determined to not refer to an interactive device.

3) Associated with the _standard error_ stream, used for writing diagnostic output. At program startup, the stream is not fully buffered.

What constitutes an interactive device is implementation-defined. 

These macros are expanded to expressions of type [FILE](FILE.html)*. 

## Contents

  * [1 Notes](std_streams.html#Notes)
  * [2 Example](std_streams.html#Example)
  * [3 References](std_streams.html#References)
  * [4 See also](std_streams.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/std_streams&action=edit&section=1 "Edit section: Notes")] Notes

Although not mandated by POSIX, the UNIX convention is that `stdin` and `stdout` are line-buffered if associated with a terminal and `stderr` is unbuffered. 

These macros may be expanded to modifiable lvalues. If any of these [FILE](FILE.html)* lvalue is modified, subsequent operations on the corresponding stream result in unspecified or undefined behavior. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/std_streams&action=edit&section=2 "Edit section: Example")] Example

This example shows a function equivalent to [printf](fprintf.html "c/io/fprintf").

Run this code
    
    
    #include <stdarg.h>
    #include <stdio.h>
     
    int my_printf(const char* restrict fmt, ...)
    {
        va_list vl;
        va_start(vl, fmt);
        int ret = [vfprintf](vfprintf.html)(stdout, fmt, vl);
        va_end(vl);
        return ret;
    }
     
    int main(void)
    {
        my_printf("Rounding:\t%f %.0f %.32f\n", 1.5, 1.5, 1.3);
        my_printf("Padding:\t%05.2f %.2f %5.2f\n", 1.5, 1.5, 1.5);
        my_printf("Scientific:\t%E %e\n", 1.5, 1.5);
        my_printf("Hexadecimal:\t%a %A\n", 1.5, 1.5);
    }

Possible output: 
    
    
    Rounding:       1.500000 2 1.30000000000000004440892098500626
    Padding:        01.50 1.50  1.50
    Scientific:     1.500000E+00 1.500000e+00
    Hexadecimal:    0x1.8p+0 0X1.8P+0

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/std_streams&action=edit&section=3 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.1 Introduction (p: TBD) 



    

  * 7.21.2 Streams (p: TBD) 



    

  * 7.21.2 Files (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.1 Introduction (p: 217-218) 



    

  * 7.21.2 Streams (p: 217-219) 



    

  * 7.21.2 Files (p: 219-221) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.1 Introduction (p: 296-298) 



    

  * 7.21.2 Streams (p: 298-299) 



    

  * 7.21.2 Files (p: 300-302) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.1 Introduction (p: 262-264) 



    

  * 7.19.2 Streams (p: 264-265) 



    

  * 7.19.2 Files (p: 266-268) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 7.9.1 Introduction 



    

  * 7.9.2 Streams 



    

  * 7.9.3 Files 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/std_streams&action=edit&section=4 "Edit section: See also")] See also

[ FILE](FILE.html "c/io/FILE") |  object type, capable of holding all information needed to control a C I/O stream   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_FILE&action=edit)  
---|---  
[C++ documentation](../../cpp/io/c/std_streams.html "cpp/io/c/std streams") for stdin, stdout, stderr  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/std_streams&oldid=180287](https://en.cppreference.com/mwiki/index.php?title=c/io/std_streams&oldid=180287)" 

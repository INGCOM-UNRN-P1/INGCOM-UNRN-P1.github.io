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
  
| **fwrite**  
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
[size_t](../types/size_t.html) fwrite( const void* buffer, [size_t](../types/size_t.html) size, [size_t](../types/size_t.html) count,  
[FILE](FILE.html)* stream ); |  |  (until C99)  
[size_t](../types/size_t.html) fwrite( const void* restrict buffer, [size_t](../types/size_t.html) size, [size_t](../types/size_t.html) count,  
[FILE](FILE.html)* restrict stream ); |  |  (since C99)  
| |   
  
Writes count of objects from the given array buffer to the output stream stream. The objects are written as if by reinterpreting each object as an array of unsigned char and calling [fputc](putc.html "c/io/fputc") size times for each object to write those unsigned chars into stream, in order. The file position indicator for the stream is advanced by the number of characters written. 

If an error occurs, the resulting value of the file position indicator for the stream is indeterminate. 

## Contents

  * [1 Parameters](fwrite.html#Parameters)
  * [2 Return value](fwrite.html#Return_value)
  * [3 Example](fwrite.html#Example)
  * [4 References](fwrite.html#References)
  * [5 See also](fwrite.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fwrite&action=edit&section=1 "Edit section: Parameters")] Parameters

buffer  |  \-  |  pointer to the first object in the array to be written   
---|---|---  
size  |  \-  |  size of each object   
count  |  \-  |  the number of the objects to be written   
stream  |  \-  |  pointer to the output stream   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fwrite&action=edit&section=2 "Edit section: Return value")] Return value

The number of objects written successfully, which may be less than count if an error occurs. 

If size or count is zero, `fwrite` returns zero and performs no other action. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fwrite&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <assert.h>
    #include <stdio.h>
    #include <stdlib.h>
     
    enum { SIZE = 5 };
     
    int main(void)
    {
        double a[SIZE] = {1, 2, 3, 4, 5};
        [FILE](FILE.html)* f1 = [fopen](fopen.html)("file.bin", "wb");
        [assert](../error/assert.html)(f1);
        [size_t](../types/size_t.html) r1 = fwrite(a, sizeof a[0], SIZE, f1);
        [printf](fprintf.html)("wrote %zu elements out of %d requested\n", r1, SIZE);
        [fclose](fclose.html)(f1);
     
        double b[SIZE];
        [FILE](FILE.html)* f2 = [fopen](fopen.html)("file.bin", "rb");
        [size_t](../types/size_t.html) r2 = [fread](fread.html)(b, sizeof b[0], SIZE, f2);
        [fclose](fclose.html)(f2);
        [printf](fprintf.html)("read back: ");
        for ([size_t](../types/size_t.html) i = 0; i < r2; ++i)
            [printf](fprintf.html)("%0.2f ", b[i]);
    }

Output: 
    
    
    wrote 5 elements out of 5 requested
    read back: 1.00 2.00 3.00 4.00 5.00

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fwrite&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.8.2 The fwrite function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.8.2 The fwrite function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.8.2 The fwrite function (p: 335-336) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.8.2 The fwrite function (p: 301-302) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.8.2 The fwrite function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fwrite&action=edit&section=5 "Edit section: See also")] See also

[ printffprintfsprintfsnprintfprintf_sfprintf_ssprintf_ssnprintf_s](fprintf.html "c/io/fprintf")(C99)(C11)(C11)(C11)(C11) |  prints formatted output to [stdout](std_streams.html "c/io/std streams"), a file stream or a buffer   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fprintf&action=edit)  
---|---  
[ fputs](fputs.html "c/io/fputs") |  writes a character string to a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fputs&action=edit)  
[ fread](fread.html "c/io/fread") |  reads from a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fread&action=edit)  
[C++ documentation](../../cpp/io/c/fwrite.html "cpp/io/c/fwrite") for fwrite  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/fwrite&oldid=160133](https://en.cppreference.com/mwiki/index.php?title=c/io/fwrite&oldid=160133)" 

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
**fgetpos**  
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
int fgetpos( [FILE](FILE.html)* stream, [fpos_t](fpos_t.html)* pos ); |  |  (until C99)  
int fgetpos( [FILE](FILE.html)* restrict stream, [fpos_t](fpos_t.html)* restrict pos ); |  |  (since C99)  
| |   
  
Obtains the file position indicator and the current parse state (if any) for the file stream stream and stores them in the object pointed to by pos. The value stored is only meaningful as the input to [fsetpos](fsetpos.html "c/io/fsetpos"). 

## Contents

  * [1 Parameters](fgetpos.html#Parameters)
  * [2 Return value](fgetpos.html#Return_value)
  * [3 Example](fgetpos.html#Example)
  * [4 References](fgetpos.html#References)
  * [5 See also](fgetpos.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetpos&action=edit&section=1 "Edit section: Parameters")] Parameters

stream  |  \-  |  file stream to examine   
---|---|---  
pos  |  \-  |  pointer to a [fpos_t](fpos_t.html "c/io/fpos t") object to store the file position indicator to   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetpos&action=edit&section=2 "Edit section: Return value")] Return value

​0​ upon success, nonzero value otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetpos&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <assert.h>
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        // prepare a file holding 4 values of type double
        enum {SIZE = 4};
        [FILE](FILE.html)* fp = [fopen](fopen.html)("test.bin", "wb");
        [assert](../error/assert.html)(fp);
        int rc = [fwrite](fwrite.html)((double[SIZE]){1.1, 2.2, 3.3, 4.4}, sizeof(double), SIZE, fp);
        [assert](../error/assert.html)(rc == SIZE);
        [fclose](fclose.html)(fp);
     
        // demo using fsetpos to return to the beginning of a file
        fp = [fopen](fopen.html)("test.bin", "rb");
        [fpos_t](fpos_t.html) pos;
        fgetpos(fp, &pos);               // store start of file in pos
        double d;
        rc = [fread](fread.html)(&d, sizeof d, 1, fp); // read the first double
        [assert](../error/assert.html)(rc == 1);
        [printf](fprintf.html)("First value in the file: %.1f\n", d);
        [fsetpos](fsetpos.html)(fp,&pos);                // move file position back to the start of the file
        rc = [fread](fread.html)(&d, sizeof d, 1, fp); // read the first double again
        [assert](../error/assert.html)(rc == 1);
        [printf](fprintf.html)("First value in the file again: %.1f\n", d);
        [fclose](fclose.html)(fp);
     
        // demo error handling
        rc = [fsetpos](fsetpos.html)([stdin](std_streams.html), &pos);
        if (rc)
            [perror](perror.html)("could not fsetpos stdin");
    }

Output: 
    
    
    First value in the file: 1.1
    First value in the file again: 1.1
    could not fsetpos stdin: Illegal seek

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetpos&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.9.1 The fgetpos function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.9.1 The fgetpos function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.9.1 The fgetpos function (p: 336) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.9.1 The fgetpos function (p: 302) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.9.1 The fgetpos function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetpos&action=edit&section=5 "Edit section: See also")] See also

[ ftell](ftell.html "c/io/ftell") |  returns the current file position indicator   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_ftell&action=edit)  
---|---  
[ fseek](fseek.html "c/io/fseek") |  moves the file position indicator to a specific location in a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fseek&action=edit)  
[ fsetpos](fsetpos.html "c/io/fsetpos") |  moves the file position indicator to a specific location in a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fsetpos&action=edit)  
[C++ documentation](../../cpp/io/c/fgetpos.html "cpp/io/c/fgetpos") for fgetpos  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/fgetpos&oldid=178252](https://en.cppreference.com/mwiki/index.php?title=c/io/fgetpos&oldid=178252)" 

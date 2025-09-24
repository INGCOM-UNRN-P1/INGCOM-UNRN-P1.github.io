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
  
| **fsetpos**  
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
int fsetpos( [FILE](FILE.html)* stream, const [fpos_t](fpos_t.html)* pos ); |  |   
| |   
  
Sets the file position indicator and the multibyte parsing state (if any) for the file stream stream according to the value pointed to by pos. 

Besides establishing new parse state and position, a call to this function undoes the effects of [ungetc](ungetc.html "c/io/ungetc") and clears the end-of-file state, if it is set. 

If a read or write error occurs, the error indicator ([ferror](ferror.html "c/io/ferror")) for the stream is set. 

## Contents

  * [1 Parameters](fsetpos.html#Parameters)
  * [2 Return value](fsetpos.html#Return_value)
  * [3 Notes](fsetpos.html#Notes)
  * [4 Example](fsetpos.html#Example)
  * [5 References](fsetpos.html#References)
  * [6 See also](fsetpos.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fsetpos&action=edit&section=1 "Edit section: Parameters")] Parameters

stream  |  \-  |  file stream to modify   
---|---|---  
pos  |  \-  |  pointer to a [fpos_t](fpos_t.html "c/io/fpos t") object to use as new value of file position indicator   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fsetpos&action=edit&section=2 "Edit section: Return value")] Return value

​0​ upon success, nonzero value otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fsetpos&action=edit&section=3 "Edit section: Notes")] Notes

After seeking to a non-end position in a wide stream, the next call to any output function may render the remainder of the file undefined, e.g. by outputting a multibyte sequence of a different length. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fsetpos&action=edit&section=4 "Edit section: Example")] Example

`fsetpos` with error checking

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        // Prepare an array of FP (floating-point) values.
        #define SIZE 5
        double A[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
        // Write array to a file.
        [FILE](FILE.html) * fp = [fopen](fopen.html)("test.bin", "wb");
        [fwrite](fwrite.html)(A,sizeof(double),SIZE,fp);
        [fclose](fclose.html) (fp);
     
        // Read the FP values into array B.
        double B[SIZE];
        fp = [fopen](fopen.html)("test.bin","rb");
        [fpos_t](fpos_t.html) pos;
        if ([fgetpos](fgetpos.html)(fp, &pos)) // current position: start of file
        {
            [perror](perror.html)("fgetpos()");
            [fprintf](fprintf.html)([stderr](std_streams.html), "fgetpos() failed in file %s at line # %d\n",
                    __FILE__, __LINE__ - 3);
            [exit](../program/exit.html)([EXIT_FAILURE](../program/EXIT_status.html));
        }
     
        int ret_code = [fread](fread.html)(B,sizeof(double),1,fp); // read one FP value
        // current position: after reading one f-p value
        [printf](fprintf.html)("%.1f; read count = %d\n", B[0], ret_code); // print one FP value and ret_code
     
        if (fsetpos(fp, &pos)) // reset current position to start of file
        {
            if ([ferror](ferror.html)(fp))
            {
                [perror](perror.html)("fsetpos()");
                [fprintf](fprintf.html)([stderr](std_streams.html), "fsetpos() failed in file %s at line # %d\n", __FILE__,
                        __LINE__ - 5);
                [exit](../program/exit.html)([EXIT_FAILURE](../program/EXIT_status.html));
            }
        }
     
        ret_code = [fread](fread.html)(B, sizeof(double), 1, fp); // reread first FP value
        [printf](fprintf.html)("%.1f; read count = %d\n", B[0], ret_code); // print one FP value and ret_code
        [fclose](fclose.html)(fp);
     
        return [EXIT_SUCCESS](../program/EXIT_status.html);
    }

Possible output: 
    
    
    1.0; read count = 1
    1.0; read count = 1

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fsetpos&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.9.3 The fsetpos function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.9.3 The fsetpos function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.9.3 The fsetpos function (p: 337) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.9.3 The fsetpos function (p: 303) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.9.3 The fsetpos function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fsetpos&action=edit&section=6 "Edit section: See also")] See also

[ fgetpos](fgetpos.html "c/io/fgetpos") |  gets the file position indicator   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fgetpos&action=edit)  
---|---  
[ ftell](ftell.html "c/io/ftell") |  returns the current file position indicator   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_ftell&action=edit)  
[ fseek](fseek.html "c/io/fseek") |  moves the file position indicator to a specific location in a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fseek&action=edit)  
[C++ documentation](../../cpp/io/c/fsetpos.html "cpp/io/c/fsetpos") for fsetpos  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/fsetpos&oldid=178687](https://en.cppreference.com/mwiki/index.php?title=c/io/fsetpos&oldid=178687)" 

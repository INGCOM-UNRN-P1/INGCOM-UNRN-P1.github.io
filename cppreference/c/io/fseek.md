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
**fseek**  
  
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
int fseek( [FILE](FILE.html)* stream, long offset, int origin ); |  |   
#define SEEK_SET /* unspecified */  
#define SEEK_CUR /* unspecified */  
#define SEEK_END /* unspecified */ |  |   
| |   
  
Sets the file position indicator for the file stream stream to the value pointed to by offset. 

If the stream is open in binary mode, the new position is exactly offset bytes measured from the beginning of the file if origin is [SEEK_SET](../io.html "c/io"), from the current file position if origin is [SEEK_CUR](../io.html "c/io"), and from the end of the file if origin is [SEEK_END](../io.html "c/io"). Binary streams are not required to support [SEEK_END](../io.html "c/io"), in particular if additional null bytes are output. 

If the stream is open in text mode, the only supported values for offset are zero (which works with any origin) and a value returned by an earlier call to [ftell](ftell.html "c/io/ftell") on a stream associated with the same file (which only works with origin of [SEEK_SET](../io.html "c/io")). 

If the stream is wide-oriented, the restrictions of both text and binary streams apply (result of [ftell](ftell.html "c/io/ftell") is allowed with [SEEK_SET](../io.html "c/io") and zero offset is allowed from [SEEK_SET](../io.html "c/io") and [SEEK_CUR](../io.html "c/io"), but not [SEEK_END](../io.html "c/io")). 

In addition to changing the file position indicator, `fseek` undoes the effects of [ungetc](ungetc.html "c/io/ungetc") and clears the end-of-file status, if applicable. 

If a read or write error occurs, the error indicator for the stream ([ferror](ferror.html "c/io/ferror")) is set and the file position is unaffected. 

## Contents

  * [1 Parameters](fseek.html#Parameters)
  * [2 Return value](fseek.html#Return_value)
  * [3 Notes](fseek.html#Notes)
  * [4 Example](fseek.html#Example)
  * [5 References](fseek.html#References)
  * [6 See also](fseek.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fseek&action=edit&section=1 "Edit section: Parameters")] Parameters

stream  |  \-  |  file stream to modify   
---|---|---  
offset  |  \-  |  number of characters to shift the position relative to origin   
origin  |  \-  |  position to which offset is added. It can have one of the following values: [SEEK_SET](../io.html "c/io"), [SEEK_CUR](../io.html "c/io"), [SEEK_END](../io.html "c/io")  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fseek&action=edit&section=2 "Edit section: Return value")] Return value

​0​ upon success, nonzero value otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fseek&action=edit&section=3 "Edit section: Notes")] Notes

After seeking to a non-end position in a wide stream, the next call to any output function may render the remainder of the file undefined, e.g. by outputting a multibyte sequence of a different length. 

For text streams, the only valid values of offset are ​0​ (applicable to any origin) and a value returned by an earlier call to [ftell](ftell.html "c/io/ftell") (only applicable to [SEEK_SET](../io.html "c/io")). 

POSIX allows seeking beyond the existing end of file. If an output is performed after this seek, any read from the gap will return zero bytes. Where supported by the filesystem, this creates a _sparse file_. 

POSIX also requires that `fseek` first performs [fflush](fflush.html "c/io/fflush") if there are any unwritten data (but whether the shift state is restored is implementation-defined). 

POSIX specifies, that [`fseek`](https://pubs.opengroup.org/onlinepubs/9699919799/functions/fseek.html) should return -1 on error, and set [errno](../error/errno.html "c/error/errno") to indicate the error. 

On Windows, [`_fseeki64`](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fseek-fseeki64) can be used to work with files larger than 2 GiB. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fseek&action=edit&section=4 "Edit section: Example")] Example

`fseek` with error checking:

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        // Prepare an array of double values.
        #define SIZE 5
        double A[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
     
        // Write array to a file.
        [FILE](FILE.html) * fp = [fopen](fopen.html)("test.bin", "wb");
        [fwrite](fwrite.html)(A, sizeof(double), SIZE, fp);
        [fclose](fclose.html) (fp);
     
        // Read the double values into array B.
        double B[SIZE];
        fp = [fopen](fopen.html)("test.bin", "rb");
     
        // Set the file position indicator in front of third double value.
        if (fseek(fp, sizeof(double) * 2L, [SEEK_SET](../io.html)) != 0)
        {
            [fprintf](fprintf.html)([stderr](std_streams.html), "fseek() failed in file %s at line # %d\n",
                    __FILE__, __LINE__ - 2);
            [fclose](fclose.html)(fp);
            return [EXIT_FAILURE](../program/EXIT_status.html);
        }
     
        int ret_code = [fread](fread.html)(B, sizeof(double), 1, fp); // reads one double value
        [printf](fprintf.html)("ret_code == %d\n", ret_code);           // prints the number of values read
        [printf](fprintf.html)("B[0] == %.1f\n", B[0]);                 // prints one value
     
        [fclose](fclose.html)(fp);
        return [EXIT_SUCCESS](../program/EXIT_status.html);
    }

Possible output: 
    
    
    ret_code == 1
    B[0] == 3.0

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fseek&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.23.9.2 The fseek function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.9.2 The fseek function (p: 245) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.9.2 The fseek function (p: 336-337) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.9.2 The fseek function (p: 302-303) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.9.2 The fseek function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fseek&action=edit&section=6 "Edit section: See also")] See also

[ fsetpos](fsetpos.html "c/io/fsetpos") |  moves the file position indicator to a specific location in a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fsetpos&action=edit)  
---|---  
[ fgetpos](fgetpos.html "c/io/fgetpos") |  gets the file position indicator   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fgetpos&action=edit)  
[ ftell](ftell.html "c/io/ftell") |  returns the current file position indicator   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_ftell&action=edit)  
[ rewind](rewind.html "c/io/rewind") |  moves the file position indicator to the beginning in a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_rewind&action=edit)  
[C++ documentation](../../cpp/io/c/fseek.html "cpp/io/c/fseek") for fseek  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/fseek&oldid=178171](https://en.cppreference.com/mwiki/index.php?title=c/io/fseek&oldid=178171)" 

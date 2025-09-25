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
| **fread**  
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
[size_t](../types/size_t.html) fread( void *buffer, [size_t](../types/size_t.html) size, [size_t](../types/size_t.html) count,  
[FILE](FILE.html) *stream ); |  |  (until C99)  
[size_t](../types/size_t.html) fread( void *restrict buffer, [size_t](../types/size_t.html) size, [size_t](../types/size_t.html) count,  
[FILE](FILE.html) *restrict stream ); |  |  (since C99)  
| |   
  
Reads up to count objects into the array buffer from the given input stream stream as if by calling [fgetc](fgetc.html "c/io/fgetc") size times for each object, and storing the results, in the order obtained, into the successive positions of buffer, which is reinterpreted as an array of unsigned char. The file position indicator for the stream is advanced by the number of characters read. 

If an error occurs, the resulting value of the file position indicator for the stream is indeterminate. If a partial element is read, its value is indeterminate. 

## Contents

  * [1 Parameters](fread.html#Parameters)
  * [2 Return value](fread.html#Return_value)
  * [3 Example](fread.html#Example)
  * [4 References](fread.html#References)
  * [5 See also](fread.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fread&action=edit&section=1 "Edit section: Parameters")] Parameters

buffer  |  \-  |  pointer to the array where the read objects are stored   
---|---|---  
size  |  \-  |  size of each object in bytes   
count  |  \-  |  the number of the objects to be read   
stream  |  \-  |  the stream to read   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fread&action=edit&section=2 "Edit section: Return value")] Return value

Number of objects read successfully, which may be less than count if an error or end-of-file condition occurs. 

If size or count is zero, `fread` returns zero and performs no other action. 

`fread` does not distinguish between end-of-file and error, and callers must use [feof](feof.html "c/io/feof") and [ferror](ferror.html "c/io/ferror") to determine which occurred. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fread&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
     
    enum { SIZE = 5 };
     
    int main(void)
    {
        const double a[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
        [printf](fprintf.html)("Array has size %ld bytes, element size: %ld\n", sizeof a, sizeof *a);
        [FILE](FILE.html) *fp = [fopen](fopen.html)("test.bin", "wb"); // must use binary mode
        [fwrite](fwrite.html)(a, sizeof *a, SIZE, fp); // writes an array of doubles
        [fclose](fclose.html)(fp);
     
        double b[SIZE];
        fp = [fopen](fopen.html)("test.bin","rb");
        const [size_t](../types/size_t.html) ret_code = fread(b, sizeof b[0], SIZE, fp); // reads an array of doubles
        if (ret_code == SIZE)
        {
            [printf](fprintf.html)("Array at %p read successfully, contents:\n", (void*)&a);
            for (int n = 0; n != SIZE; ++n)
                [printf](fprintf.html)("%f ", b[n]);
            [putchar](putchar.html)('\n');
        }
        else // error handling
        {
            if ([feof](feof.html)(fp))
                [printf](fprintf.html)("Error reading test.bin: unexpected end of file\n");
            else if ([ferror](ferror.html)(fp))
                [perror](perror.html)("Error reading test.bin");
        }
     
        [fclose](fclose.html)(fp);
    }

Possible output: 
    
    
    Array has size 40 bytes, element size: 8
    Array at 0x1337f00d6960 read successfully, contents:
    1.000000 2.000000 3.000000 4.000000 5.000000

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fread&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.8.1 The fread function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.8.1 The fread function (p: 243-244) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.8.1 The fread function (p: 335) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.8.1 The fread function (p: 301) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.8.1 The fread function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fread&action=edit&section=5 "Edit section: See also")] See also

[ scanffscanfsscanfscanf_sfscanf_ssscanf_s](fscanf.html "c/io/fscanf")(C11)(C11)(C11) |  reads formatted input from [stdin](std_streams.html "c/io/std streams"), a file stream or a buffer   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fscanf&action=edit)  
---|---  
[ fgets](fgets.html "c/io/fgets") |  gets a character string from a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fgets&action=edit)  
[ fwrite](fwrite.html "c/io/fwrite") |  writes to a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fwrite&action=edit)  
[C++ documentation](../../cpp/io/c/fread.html "cpp/io/c/fread") for fread  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/fread&oldid=151522](https://en.cppreference.com/mwiki/index.php?title=c/io/fread&oldid=151522)" 

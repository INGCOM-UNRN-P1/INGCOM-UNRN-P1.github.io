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
**fgets**  
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
char* fgets( char* str, int count, [FILE](FILE.html)* stream ); |  |  (until C99)  
char* fgets( char* restrict str, int count, [FILE](FILE.html)* restrict stream ); |  |  (since C99)  
| |   
  
Reads at most count - 1 characters from the given file stream and stores them in the character array pointed to by str. Parsing stops if a newline character is found (in which case str will contain that newline character) or if end-of-file occurs. If bytes are read and no errors occur, writes a null character at the position immediately after the last character written to str. 

## Contents

  * [1 Parameters](fgets.html#Parameters)
  * [2 Return value](fgets.html#Return_value)
  * [3 Notes](fgets.html#Notes)
  * [4 Example](fgets.html#Example)
  * [5 References](fgets.html#References)
  * [6 See also](fgets.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgets&action=edit&section=1 "Edit section: Parameters")] Parameters

str  |  \-  |  pointer to an element of a char array   
---|---|---  
count  |  \-  |  maximum number of characters to write (typically the length of str)   
stream  |  \-  |  file stream to read the data from   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgets&action=edit&section=2 "Edit section: Return value")] Return value

str on success, null pointer on failure. 

If the end-of-file condition is encountered, sets the _eof_ indicator on stream (see [feof()](feof.html "c/io/feof")). This is only a failure if it causes no bytes to be read, in which case a null pointer is returned and the contents of the array pointed to by str are not altered (i.e. the first byte is not overwritten with a null character). 

If the failure has been caused by some other error, sets the _error_ indicator (see [ferror()](ferror.html "c/io/ferror")) on stream. The contents of the array pointed to by str are indeterminate (it may not even be null-terminated). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgets&action=edit&section=3 "Edit section: Notes")] Notes

[POSIX additionally requires](https://pubs.opengroup.org/onlinepubs/9699919799/functions/fgets.html) that fgets sets [errno](../error/errno.html "c/error/errno") if a read error occurs. 

Although the standard specification is [unclear](https://stackoverflow.com/questions/23388620) in the cases where count <= 1, common implementations do 

  * if count < 1, do nothing, report error, 
  * if count == 1, 



    

  * some implementations do nothing, report error, 
  * others read nothing, store zero in str[0], report success. 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgets&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        [FILE](FILE.html)* tmpf = [tmpfile](tmpfile.html)();
        [fputs](fputs.html)("Alan Turing\n", tmpf);
        [fputs](fputs.html)("John von Neumann\n", tmpf);
        [fputs](fputs.html)("Alonzo Church\n", tmpf);
     
        [rewind](rewind.html)(tmpf);
     
        char buf[8];
        while (fgets(buf, sizeof buf, tmpf) != [NULL](../types/NULL.html))
              [printf](fprintf.html)("\"%s\"\n", buf);
     
        if ([feof](feof.html)(tmpf))
           [puts](puts.html)("End of file reached");
    }

Output: 
    
    
    "Alan Tu"
    "ring
    "
    "John vo"
    "n Neuma"
    "nn
    "
    "Alonzo "
    "Church
    "
    End of file reached

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgets&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.7.2 The fgets function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.7.2 The fgets function (p: 241) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.7.2 The fgets function (p: 331) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.7.2 The fgets function (p: 296) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.7.2 The fgets function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/fgets&action=edit&section=6 "Edit section: See also")] See also

[ scanffscanfsscanfscanf_sfscanf_ssscanf_s](fscanf.html "c/io/fscanf")(C11)(C11)(C11) |  reads formatted input from [stdin](std_streams.html "c/io/std streams"), a file stream or a buffer   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fscanf&action=edit)  
---|---  
[ getsgets_s](gets.html "c/io/gets")(removed in C11)(C11) |  reads a character string from [stdin](std_streams.html "c/io/std streams")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_gets&action=edit)  
[ fputs](fputs.html "c/io/fputs") |  writes a character string to a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fputs&action=edit)  
[ getlinegetwlinegetdelimgetwdelim](../experimental/dynamic/getline.html "c/experimental/dynamic/getline")(dynamic memory TR) |  read from a stream into an automatically resized buffer until delimiter/end of line   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/dsc_getline&action=edit)  
[C++ documentation](../../cpp/io/c/fgets.html "cpp/io/c/fgets") for fgets  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/fgets&oldid=172125](https://en.cppreference.com/mwiki/index.php?title=c/io/fgets&oldid=172125)" 

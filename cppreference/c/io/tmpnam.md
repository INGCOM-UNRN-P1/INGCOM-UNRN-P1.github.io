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
**tmpnam tmpnam_s**(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/navbar_content&action=edit)

Defined in header `[`<stdio.h>`](../header/stdio.html "c/header/stdio")` |  |   
---|---|---  
char *tmpnam( char *filename ); |  (1)  |   
errno_t tmpnam_s(char *filename_s, rsize_t maxsize); |  (2)  |  (since C11)  
#define TMP_MAX /*unspecified*/ |  |   
#define TMP_MAX_S /*unspecified*/ |  |  (since C11)  
#define L_tmpnam /*unspecified*/ |  |   
#define L_tmpnam_s /*unspecified*/ |  |  (since C11)  
| |   
  
1) Creates a unique valid file name (no longer than [L_tmpnam](../io.html "c/io") in length) and stores it in character string pointed to by filename. The function is capable of generating up to [TMP_MAX](../io.html "c/io") of unique filenames, but some or all of them may be in use in the filesystem and thus not suitable return values.

2) Same as (1), except that up to TMP_MAX_S names may be generated, no longer than L_tmpnam_s in length, and the following errors are detected at runtime and call the currently installed [constraint handler](../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * filename_s is a null pointer 
  * maxsize is greater than RSIZE_MAX
  * maxsize is less than the generated file name string 


     As with all bounds-checked functions, `tmpnam_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<stdio.h>`](../header/stdio.html "c/header/stdio").

tmpnam and tmpnam_s modify static state (which may be shared between these functions) and are not required to be thread-safe. 

## Contents

  * [1 Parameters](tmpnam.html#Parameters)
  * [2 Return value](tmpnam.html#Return_value)
  * [3 Notes](tmpnam.html#Notes)
  * [4 Example](tmpnam.html#Example)
  * [5 References](tmpnam.html#References)
  * [6 See also](tmpnam.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/tmpnam&action=edit&section=1 "Edit section: Parameters")] Parameters

filename  |  \-  |  pointer to the character array capable of holding at least [L_tmpnam](../io.html "c/io") bytes, to be used as a result buffer. If null pointer is passed, a pointer to an internal static buffer is returned.   
---|---|---  
filename_s  |  \-  |  pointer to the character array capable of holding at least L_tmpnam_s bytes, to be used as a result buffer.   
maxsize  |  \-  |  maximum number of characters the function is allowed to write (typically the size of the `filename_s` array).   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/tmpnam&action=edit&section=2 "Edit section: Return value")] Return value

1) filename if filename was not a null pointer. Otherwise a pointer to an internal static buffer is returned. If no suitable filename can be generated, null pointer is returned.

2) Returns zero and writes the file name to filename_s on success. On error, returns non-zero and writes the null character to filename_s[0] (only if filename_s is not null and maxsize is not zero and is not greater than RSIZE_MAX).

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/tmpnam&action=edit&section=3 "Edit section: Notes")] Notes

Although the names generated by `tmpnam` are difficult to guess, it is possible that a file with that name is created by another process between the moment `tmpnam` returns and the moment this program attempts to use the returned name to create a file. The standard function [tmpfile](tmpfile.html "c/io/tmpfile") and the POSIX function [`mkstemp`](https://pubs.opengroup.org/onlinepubs/9699919799/functions/mkdtemp.html) do not have this problem (creating a unique directory using only the standard C library still requires the use of `tmpnam`). 

POSIX systems additionally define the similarly named function [`tempnam`](https://pubs.opengroup.org/onlinepubs/9699919799/functions/tempnam.html), which offers the choice of a directory (which defaults to the optionally defined macro [`P_tmpdir`](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdio.h.html)). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/tmpnam&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
     
    int main(void)
    {
        // Note, the compiler/linker may issue a security warning, e.g. GCC:
        // "warning: the use of `tmpnam' is dangerous, better use `mkstemp'"
        char* name1 = tmpnam([NULL](../types/NULL.html));
        [printf](fprintf.html)("temporary file name: %s\n", name1);
     
        char name2[[L_tmpnam](../io.html)];
        if (tmpnam(name2))
            [printf](fprintf.html)("temporary file name: %s\n", name2);
     
        // POSIX offers mkstemp. The following declaration might be
        // necessary as mkstemp is absent in the standard C <stdlib.h>.
        int mkstemp(char*);
     
        char name3[] = "/tmp/fileXXXXXX"; // at least six 'X' required ^_^
        int file_descriptor = mkstemp(name3);
        if (file_descriptor != -1)
            [printf](fprintf.html)("temporary file name: %s\n", name3);
        else
            [perror](perror.html)("mkstemp");
    }

Possible output: 
    
    
    temporary file name: /tmp/file90dLlR
    temporary file name: /tmp/fileY9LWAg
    temporary file name: /tmp/filexgv8PF

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/tmpnam&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.4.4 The tmpnam function (p: TBD) 



    

  * K.3.5.1.2 The tmpnam_s function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.4.4 The tmpnam function (p: 222) 



    

  * K.3.5.1.2 The tmpnam_s function (p: 427-428) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.4.4 The tmpnam function (p: 303-304) 



    

  * K.3.5.1.2 The tmpnam_s function (p: 587-588) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.4.4 The tmpnam function (p: 269-270) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.4.4 The tmpnam function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/tmpnam&action=edit&section=6 "Edit section: See also")] See also

[ tmpfiletmpfile_s](tmpfile.html "c/io/tmpfile")(C11) |  returns a pointer to a temporary file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_tmpfile&action=edit)  
---|---  
[C++ documentation](../../cpp/io/c/tmpnam.html "cpp/io/c/tmpnam") for tmpnam  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/tmpnam&oldid=150073](https://en.cppreference.com/mwiki/index.php?title=c/io/tmpnam&oldid=150073)" 

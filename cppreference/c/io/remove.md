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
| **remove**  
---  
[tmpfiletmpfile_s](tmpfile.html "c/io/tmpfile")(C11)  
  
| [rename](rename.html "c/io/rename")  
---  
[tmpnamtmpnam_s](tmpnam.html "c/io/tmpnam")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/navbar_content&action=edit)

Defined in header `[`<stdio.h>`](../header/stdio.html "c/header/stdio")` |  |   
---|---|---  
int remove( const char* pathname ); |  |   
| |   
  
Deletes the file identified by the character string pointed to by pathname. 

If the file is currently open by any process, the behavior of this function is implementation-defined. POSIX systems unlink the file name (directory entry), but the filesystem space used by the file is not reclaimed while it is open in any process and while other hard links to the file exist. Windows does not allow the file to be deleted in such cases. 

## Contents

  * [1 Parameters](remove.html#Parameters)
  * [2 Return value](remove.html#Return_value)
  * [3 Notes](remove.html#Notes)
  * [4 Example](remove.html#Example)
  * [5 References](remove.html#References)
  * [6 See also](remove.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/remove&action=edit&section=1 "Edit section: Parameters")] Parameters

pathname  |  \-  |  pointer to a null-terminated string containing the path identifying the file to delete   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/remove&action=edit&section=2 "Edit section: Return value")] Return value

​0​ upon success or non-zero value on error. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/remove&action=edit&section=3 "Edit section: Notes")] Notes

[POSIX specifies](https://pubs.opengroup.org/onlinepubs/9699919799/functions/remove.html) many additional details for the behavior of this function. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/remove&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        [FILE](FILE.html)* fp = [fopen](fopen.html)("file1.txt", "w"); // create file
        if (!fp)
        {
            [perror](perror.html)("file1.txt");
            return [EXIT_FAILURE](../program/EXIT_status.html);
        }
        [puts](puts.html)("Created file1.txt");
        [fclose](fclose.html)(fp);
     
        int rc = remove("file1.txt");
        if (rc)
        {
            [perror](perror.html)("remove");
            return [EXIT_FAILURE](../program/EXIT_status.html);
        }
        [puts](puts.html)("Removed file1.txt");
     
        fp = [fopen](fopen.html)("file1.txt", "r"); // Failure: file does not exist
        if (!fp)
            [perror](perror.html)("Opening removed file failed");
     
        rc = remove("file1.txt"); // Failure: file does not exist
        if (rc)
            [perror](perror.html)("Double-remove failed");
     
        return [EXIT_SUCCESS](../program/EXIT_status.html);
    }

Possible output: 
    
    
    Created file1.txt
    Removed file1.txt
    Opening removed file failed: No such file or directory
    Double-remove failed: No such file or directory

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/remove&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.4.1 The remove function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.4.1 The remove function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.4.1 The remove function (p: 302) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.4.1 The remove function (p: 268) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.4.1 The remove function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/remove&action=edit&section=6 "Edit section: See also")] See also

[ rename](rename.html "c/io/rename") |  renames a file   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_rename&action=edit)  
---|---  
[C++ documentation](../../cpp/io/c/remove.html "cpp/io/c/remove") for remove  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/remove&oldid=168454](https://en.cppreference.com/mwiki/index.php?title=c/io/remove&oldid=168454)" 

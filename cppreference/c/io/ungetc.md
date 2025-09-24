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
**ungetc**  
  
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
int ungetc( int ch, [FILE](FILE.html)* stream ); |  |   
| |   
  
If ch does not equal [EOF](../io.html "c/io"), pushes the character ch (reinterpreted as unsigned char) into the input buffer associated with the stream stream in such a manner that subsequent read operation from stream will retrieve that character. The external device associated with the stream is not modified. 

Stream repositioning operations [fseek](fseek.html "c/io/fseek"), [fsetpos](fsetpos.html "c/io/fsetpos"), and [rewind](rewind.html "c/io/rewind") discard the effects of `ungetc`. 

If `ungetc` is called more than once without an intervening read or repositioning, it may fail (in other words, a pushback buffer of size 1 is guaranteed, but any larger buffer is implementation-defined). If multiple successful `ungetc` were performed, read operations retrieve the pushed-back characters in reverse order of `ungetc`. 

If ch equals [EOF](../io.html "c/io"), the operation fails and the stream is not affected. 

A successful call to `ungetc` clears the end of file status flag [feof](feof.html "c/io/feof"). 

A successful call to `ungetc` on a binary stream decrements the stream position indicator by one (the behavior is indeterminate if the stream position indicator was zero). 

A successful call to `ungetc` on a text stream modifies the stream position indicator in unspecified manner but guarantees that after all pushed-back characters are retrieved with a read operation, the stream position indicator is equal to its value before `ungetc`. 

## Contents

  * [1 Parameters](ungetc.html#Parameters)
  * [2 Return value](ungetc.html#Return_value)
  * [3 Notes](ungetc.html#Notes)
  * [4 Example](ungetc.html#Example)
  * [5 References](ungetc.html#References)
  * [6 See also](ungetc.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/ungetc&action=edit&section=1 "Edit section: Parameters")] Parameters

ch  |  \-  |  character to be pushed into the input stream buffer   
---|---|---  
stream  |  \-  |  file stream to put the character back to   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/ungetc&action=edit&section=2 "Edit section: Return value")] Return value

On success ch is returned. 

On failure [EOF](../io.html "c/io") is returned and the given stream remains unchanged. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/ungetc&action=edit&section=3 "Edit section: Notes")] Notes

The size of the pushback buffer varies in practice from 4k (Linux, MacOS) to as little as 4 (Solaris) or the guaranteed minimum 1 (HPUX, AIX). 

The apparent size of the pushback buffer may be larger if the character that is pushed back equals the character existing at that location in the external character sequence (the implementation may simply decrement the read file position indicator and avoid maintaining a pushback buffer). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/ungetc&action=edit&section=4 "Edit section: Example")] Example

Demonstrates the original purpose of `ungetc`: implementation of [scanf](fscanf.html "c/io/fscanf")

Run this code
    
    
    #include <ctype.h>
    #include <stdio.h>
     
    void demo_scanf(const char* fmt, [FILE](FILE.html)* s)
    {
        while (*fmt != '\0')
        {
            if (*fmt == '%')
            {
                int c;
                switch (*++fmt)
                {
                    case 'u':
                        while ([isspace](../string/byte/isspace.html)(c=[getc](fgetc.html)(s))) {}
                        unsigned int num = 0;
                        while ([isdigit](../string/byte/isdigit.html)(c))
                        {
                            num = num*10 + c-'0';
                            c = [getc](fgetc.html)(s);
                        }
                        [printf](fprintf.html)("%%u scanned %u\n", num);
                        ungetc(c, s);
                        break;
                    case 'c':
                        c = [getc](fgetc.html)(s);
                        [printf](fprintf.html)("%%c scanned '%c'\n", c);
                        break;
                }
            }
            else
                ++fmt;
        }
    }
     
    int main(void)
    {
        [FILE](FILE.html)* f = [fopen](fopen.html)("input.txt", "w+");
        if (f != [NULL](../types/NULL.html))
        {
            [fputs](fputs.html)("123x", f);
            [rewind](rewind.html)(f);
            demo_scanf("%u%c", f);
            [fclose](fclose.html)(f);
        }
        return 0;
    }

Output: 
    
    
    %u scanned 123
    %c scanned 'x'

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/ungetc&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.21.7.10 The ungetc function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.21.7.10 The ungetc function (p: 243) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.7.10 The ungetc function (p: 334) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.7.11 The ungetc function (p: 300) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.9.7.11 The ungetc function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/ungetc&action=edit&section=6 "Edit section: See also")] See also

[ fgetcgetc](fgetc.html "c/io/fgetc") |  gets a character from a file stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fgetc&action=edit)  
---|---  
[C++ documentation](../../cpp/io/c/ungetc.html "cpp/io/c/ungetc") for ungetc  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/ungetc&oldid=172393](https://en.cppreference.com/mwiki/index.php?title=c/io/ungetc&oldid=172393)" 

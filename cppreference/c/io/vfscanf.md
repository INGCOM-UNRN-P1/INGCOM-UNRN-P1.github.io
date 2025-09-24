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
  
| **vscanf vfscanfvsscanfvscanf_svfscanf_svsscanf_s**(C99)(C99)(C99)(C11)(C11)(C11)  
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
int vscanf( const char *restrict format, va_list vlist ); |  (1)  |  (since C99)  
int vfscanf( [FILE](FILE.html) *restrict stream, const char *restrict format,   
va_list vlist ); |  (2)  |  (since C99)  
int vsscanf( const char *restrict buffer, const char *restrict format,   
va_list vlist ); |  (3)  |  (since C99)  
int vscanf_s(const char *restrict format, va_list vlist); |  (4)  |  (since C11)  
int vfscanf_s( [FILE](FILE.html) *restrict stream, const char *restrict format,  
va_list vlist); |  (5)  |  (since C11)  
int vsscanf_s( const char *restrict buffer, const char *restrict format,  
va_list vlist); |  (6)  |  (since C11)  
| |   
  
Reads data from the a variety of sources, interprets it according to `format` and stores the results into locations defined by `vlist`. 

1) Reads the data from [stdin](std_streams.html "c/io/std streams")

2) Reads the data from file stream `stream`

3) Reads the data from null-terminated character string `buffer`. Reaching the end of the string is equivalent to reaching the end-of-file condition for `fscanf`

4-6) Same as (1-3), except that %c, %s, and %[ conversion specifiers each expect two arguments (the usual pointer and a value of type rsize_t indicating the size of the receiving array, which may be 1 when reading with a %c into a single char) and except that the following errors are detected at runtime and call the currently installed [constraint handler](../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * any of the arguments of pointer type is a null pointer 
  * `format`, `stream`, or `buffer` is a null pointer 
  * the number of characters that would be written by %c, %s, or %[, plus the terminating null character, would exceed the second (rsize_t) argument provided for each of those conversion specifiers 
  * optionally, any other detectable error, such as unknown conversion specifier 


    As with all bounds-checked functions, `vscanf_s`, `vfscanf_s`, and `vsscanf_s` are only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<stdio.h>`](../header/stdio.html "c/header/stdio").

## Contents

  * [1 Parameters](vfscanf.html#Parameters)
  * [2 Return value](vfscanf.html#Return_value)
  * [3 Notes](vfscanf.html#Notes)
  * [4 Example](vfscanf.html#Example)
  * [5 References](vfscanf.html#References)
  * [6 See also](vfscanf.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/vfscanf&action=edit&section=1 "Edit section: Parameters")] Parameters

stream  |  \-  |  input file stream to read from   
---|---|---  
buffer  |  \-  |  pointer to a null-terminated character string to read from   
format  |  \-  |  pointer to a null-terminated character string specifying how to read the input   
vlist  |  \-  |  variable argument list containing the receiving arguments.   
  
  
The **format** string consists of 

  * non-whitespace multibyte characters except %: each such character in the format string consumes exactly one identical character from the input stream, or causes the function to fail if the next character on the stream does not compare equal. 
  * whitespace characters: any single whitespace character in the format string consumes all available consecutive whitespace characters from the input (determined as if by calling [isspace](../string/byte/isspace.html "c/string/byte/isspace") in a loop). Note that there is no difference between "\n", " ", "\t\t", or other whitespace in the format string. 
  * conversion specifications. Each conversion specification has the following format: 



    

  * introductory % character. 



    

  * (optional) assignment-suppressing character *. If this option is present, the function does not assign the result of the conversion to any receiving argument. 



    

  * (optional) integer number (greater than zero) that specifies _maximum field width_ , that is, the maximum number of characters that the function is allowed to consume when doing the conversion specified by the current conversion specification. Note that %s and %[ may lead to buffer overflow if the width is not provided. 



    

  * (optional) _length modifier_ that specifies the size of the receiving argument, that is, the actual destination type. This affects the conversion accuracy and overflow rules. The default destination type is different for each conversion type (see table below). 



    

  * conversion format specifier. 



The following format specifiers are available: 

Conversion  
specifier  | Explanation  | Expected  
Argument type   
---|---|---  
Length Modifier→  | `hh` | `h` | none  | `**l**` | `**ll**` | `**j**` | `**z**` | `**t**` | `**L**`  
Only available since C99→  | Yes |  |  |  | Yes | Yes | Yes | Yes |   
`%` |  Matches literal `**%**`. |  N/A |  N/A |  N/A |  N/A |  N/A |  N/A |  N/A |  N/A |  N/A  
`c` |  Matches a **character** or a sequence of **characters**. 

  * If a width specifier is used, matches exactly _width_ characters (the argument must be a pointer to an array with sufficient room). 
  * Unlike %s and %[, does not append the null character to the array. 

|  N/A |  N/A | char* | wchar_t* |  N/A |  N/A |  N/A |  N/A |  N/A  
`s` |  Matches a sequence of non-whitespace characters (a **string**). 

  * If width specifier is used, matches up to _width_ or until the first whitespace character, whichever appears first. 
  * Always stores a null character in addition to the characters matched (so the argument array must have room for at least _width+1_ characters). 

  
`[`set ﻿`]` |  Matches a non-empty sequence of character from set of characters. 

  * If the first character of the set is `**^**`, then all characters not in the set are matched. 
  * If the set begins with `**]**` or `**^]**` then the `**]**` character is also included into the set. 
  * It is implementation-defined whether the character `**-**` in the non-initial position in the scanset may be indicating a range, as in `**[0-9]**`. 
  * If width specifier is used, matches only up to _width_. 
  * Always stores a null character in addition to the characters matched (so the argument array must have room for at least _width+1_ characters). 

  
`d` |  Matches a **decimal integer**. 

  * The format of the number is the same as expected by [strtol](../string/byte/strtol.html "c/string/byte/strtol") with the value 10 for the base argument. 

| signed char* or unsigned char* | signed short* or unsigned short* | signed int* or unsigned int* | signed long* or unsigned long* | signed long long* or unsigned long long* | [intmax_t](../types/integer.html)* or [uintmax_t](../types/integer.html)* | [size_t](../types/size_t.html)* | [ptrdiff_t](../types/ptrdiff_t.html)* |  N/A  
`i` |  Matches an **integer**. 

  * The format of the number is the same as expected by [strtol](../string/byte/strtol.html "c/string/byte/strtol") with the value ​0​ for the base argument (base is determined by the first characters parsed). 

  
`u` |  Matches an unsigned **decimal integer**. 

  * The format of the number is the same as expected by [strtoul](../string/byte/strtoul.html "c/string/byte/strtoul") with the value 10 for the base argument. 

  
`o` |  Matches an unsigned **octal integer**. 

  * The format of the number is the same as expected by [strtoul](../string/byte/strtoul.html "c/string/byte/strtoul") with the value 8 for the base argument. 

  
`x`  
`X` |  Matches an unsigned **hexadecimal integer**. 

  * The format of the number is the same as expected by [strtoul](../string/byte/strtoul.html "c/string/byte/strtoul") with the value 16 for the base argument. 

  
`n` |  Returns the **number of characters read so far**. 

  * No input is consumed. Does not increment the assignment count. 
  * If the specifier has assignment-suppressing operator defined, the behavior is undefined. 

  
`a` (C99)  
`A` (C99)  
`e`  
`E`  
`f`  
`F` (C99)  
`g`  
`G` |  Matches a **floating-point number**. 

  * The format of the number is the same as expected by [strtof](../string/byte/strtof.html "c/string/byte/strtof"). 

|  N/A |  N/A | float* | double* |  N/A |  N/A |  N/A |  N/A | long double*  
`p` |  Matches implementation defined character sequence defining a **pointer**. 

  * `printf` family of functions should produce the same sequence using `**%p**` format specifier. 

|  N/A |  N/A | void** |  N/A |  N/A |  N/A |  N/A |  N/A |  N/A  
Notes   
For every conversion specifier other than n, the longest sequence of input characters which does not exceed any specified ﬁeld width and which either is exactly what the conversion specifier expects or is a prefix of a sequence it would expect, is what's consumed from the stream. The ﬁrst character, if any, after this consumed sequence remains unread. If the consumed sequence has length zero or if the consumed sequence cannot be converted as specified above, the matching failure occurs unless end-of-ﬁle, an encoding error, or a read error prevented input from the stream, in which case it is an input failure. All conversion specifiers other than [, c, and n consume and discard all leading whitespace characters (determined as if by calling [isspace](../string/byte/isspace.html "c/string/byte/isspace")) before attempting to parse the input. These consumed characters do not count towards the specified maximum field width. The conversion specifiers lc, ls, and l[ perform multibyte-to-wide character conversion as if by calling [mbrtowc](../string/multibyte/mbrtowc.html "c/string/multibyte/mbrtowc") with an [mbstate_t](../string/multibyte/mbstate_t.html "c/string/multibyte/mbstate t") object initialized to zero before the first character is converted. The conversion specifiers s and [ always store the null terminator in addition to the matched characters. The size of the destination array must be at least one greater than the specified field width. The use of %s or %[, without specifying the destination array size, is as unsafe as [gets](gets.html "c/io/gets"). The correct conversion specifications for the [fixed-width integer types](../types/integer.html "c/types/integer") ([int8_t](../types/integer.html "c/types/integer"), etc) are defined in the header [`<inttypes.h>`](../types/integer.html "c/types/integer") (although [`SCNdMAX`](../types/integer.html "c/types/integer"), [`SCNuMAX`](../types/integer.html "c/types/integer"), etc is synonymous with %jd, %ju, etc). There is a [sequence point](../language/eval_order.html "c/language/eval order") after the action of each conversion specifier; this permits storing multiple fields in the same “sink” variable. When parsing an incomplete floating-point value that ends in the exponent with no digits, such as parsing "100er" with the conversion specifier %f, the sequence "100e" (the longest prefix of a possibly valid floating-point number) is consumed, resulting in a matching error (the consumed sequence cannot be converted to a floating-point number), with "r" remaining. Some existing implementations do not follow this rule and roll back to consume only "100", leaving "er", e.g., [glibc bug 1765](https://sourceware.org/bugzilla/show_bug.cgi?id=1765). If a conversion specification is invalid, the behavior is undefined.   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/vfscanf&action=edit&section=2 "Edit section: Return value")] Return value

1-3) Number of receiving arguments successfully assigned, or [EOF](../io.html "c/io") if read failure occurs before the first receiving argument was assigned.

4-6) Same as (1-3), except that [EOF](../io.html "c/io") is also returned if there is a runtime constraint violation.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/vfscanf&action=edit&section=3 "Edit section: Notes")] Notes

All these functions invoke va_arg at least once, the value of `arg` is indeterminate after the return. These functions to not invoke va_end, and it must be done by the caller. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/vfscanf&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdarg.h>
     
    bool checked_sscanf(int count, const char* buf, const char *fmt, ...)
    {
        va_list ap;
        va_start(ap, fmt);
        int rc = vsscanf(buf, fmt, ap);
        va_end(ap);
        return rc == count;
    }
     
    int main(void)
    {
        int n, m;
     
        [printf](fprintf.html)("Parsing '1 2'...");
        if(checked_sscanf(2, "1 2", "%d %d", &n, &m))
            [puts](puts.html)("success");
        else
            [puts](puts.html)("failure");
     
        [printf](fprintf.html)("Parsing '1 a'...");
        if(checked_sscanf(2, "1 a", "%d %d", &n, &m))
            [puts](puts.html)("success");
        else
            [puts](puts.html)("failure");
    }

Output: 
    
    
    Parsing '1 2'...success
    Parsing '1 a'...failure

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/vfscanf&action=edit&section=5 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.21.6.9 The vfscanf function (p: 327) 



    

  * 7.21.6.11 The vscanf function (p: 328) 



    

  * 7.21.6.14 The vsscanf function (p: 330) 



    

  * K.3.5.3.9 The vfscanf_s function (p: 597-598) 



    

  * K.3.5.3.11 The vscanf_s function (p: 599) 



    

  * K.3.5.3.14 The vsscanf_s function (p: 602) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.19.6.9 The vfscanf function (p: 293) 



    

  * 7.19.6.11 The vscanf function (p: 294) 



    

  * 7.19.6.14 The vsscanf function (p: 295) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/vfscanf&action=edit&section=6 "Edit section: See also")] See also

[ scanffscanfsscanfscanf_sfscanf_ssscanf_s](fscanf.html "c/io/fscanf")(C11)(C11)(C11) |  reads formatted input from [stdin](std_streams.html "c/io/std streams"), a file stream or a buffer   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fscanf&action=edit)  
---|---  
[ vprintfvfprintfvsprintfvsnprintfvprintf_svfprintf_svsprintf_svsnprintf_s](vfprintf.html "c/io/vfprintf")(C99)(C11)(C11)(C11)(C11) |  prints formatted output to [stdout](std_streams.html "c/io/std streams"), a file stream or a buffer  
using variable argument list   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_vfprintf&action=edit)  
[C++ documentation](../../cpp/io/c/vfscanf.html "cpp/io/c/vfscanf") for vscanf, vfscanf, vsscanf  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/vfscanf&oldid=125689](https://en.cppreference.com/mwiki/index.php?title=c/io/vfscanf&oldid=125689)" 

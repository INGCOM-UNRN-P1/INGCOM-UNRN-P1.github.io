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
**vwprintf vfwprintfvswprintfvwprintf_svfwprintf_svswprintf_svsnwprintf_s**(C95)(C95)(C95)(C11)(C11)(C11)(C11)  
  
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

Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")` |  |   
---|---|---  
| (1) |   
int vwprintf( const wchar_t* format, va_list vlist ); |  |  (since C95)   
(until C99)  
int vwprintf( const wchar_t* restrict format, va_list vlist ); |  |  (since C99)  
| (2) |   
int vfwprintf( [FILE](FILE.html)* stream, const wchar_t* format, va_list vlist ); |  |  (since C95)   
(until C99)  
int vfwprintf( [FILE](FILE.html)* restrict stream,  
const wchar_t* restrict format, va_list vlist ); |  |  (since C99)  
| (3) |   
int vswprintf( wchar_t* buffer, [size_t](../types/size_t.html) bufsz,  
const wchar_t* format, va_list vlist ); |  |  (since C95)   
(until C99)  
int vswprintf( wchar_t* restrict buffer, [size_t](../types/size_t.html) bufsz,  
const wchar_t* restrict format, va_list vlist ); |  |  (since C99)  
int vwprintf_s( const wchar_t* restrict format, va_list vlist); |  (4)  |  (since C11)  
int vfwprintf_s( [FILE](FILE.html)* restrict stream,  
const wchar_t* restrict format, va_list vlist); |  (5)  |  (since C11)  
int vswprintf_s( wchar_t* restrict buffer, rsize_t bufsz,  
const wchar_t* restrict format, va_list vlist); |  (6)  |  (since C11)  
int vsnwprintf_s( wchar_t* restrict buffer, rsize_t bufsz,  
const wchar_t* restrict format, va_list vlist); |  (7)  |  (since C11)  
| |   
  
Loads the data from locations, defined by vlist, converts them to wide string equivalents and writes the results to a variety of sinks. 

1) Writes the results to [stdout](std_streams.html "c/io/std streams").

2) Writes the results to a file stream stream.

3) Writes the results to a wide string buffer. At most bufsz - 1 wide characters are written followed by null wide character. The resulting wide character string will be terminated with a null wide character, unless bufsz is zero.

4-6) Same as (1-3), except that the following errors are detected at runtime and call the currently installed [constraint handler](../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * the conversion specifier `%n` is present in format
  * any of the arguments corresponding to `%s` is a null pointer 
  * format or buffer is a null pointer 
  * bufsz is zero or greater than RSIZE_MAX / sizeof(wchar_t)
  * encoding errors occur in any of string and character conversion specifiers 
  * (for `vswprintf_s` only), the string to be stored in buffer (including the trailing wide null) would be exceed bufsz.



7) Same as (6), except it will truncate the result to fit within the array pointed to by buffer. 

    As with all bounds-checked functions, `vwprintf_s`, `vfwprintf_s`, `vswprintf_s`, and `vsnwprintf_s` are only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<stdio.h>`](../header/stdio.html "c/header/stdio").

## Contents

  * [1 Parameters](vfwprintf.html#Parameters)
  * [2 Return value](vfwprintf.html#Return_value)
  * [3 Notes](vfwprintf.html#Notes)
  * [4 Example](vfwprintf.html#Example)
  * [5 References](vfwprintf.html#References)
  * [6 See also](vfwprintf.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/vfwprintf&action=edit&section=1 "Edit section: Parameters")] Parameters

stream  |  \-  |  output wide stream to write to   
---|---|---  
buffer  |  \-  |  pointer to a wide string to write to   
bufsz  |  \-  |  maximum number of wide characters to write   
format  |  \-  |  pointer to a null-terminated wide string specifying how to interpret the data   
vlist  |  \-  |  [variable argument list](../language/variadic.html "c/language/variadic") containing the data to print.   
  
  
The **format** string consists of ordinary wide characters (except `**%**`), which are copied unchanged into the output stream, and conversion specifications. Each conversion specification has the following format: 

    

  * introductory `**%**` character. 



    

  * (optional) one or more flags that modify the behavior of the conversion: 



    

  * `**-**`: the result of the conversion is left-justified within the field (by default it is right-justified). 
  * `**+**`: the sign of signed conversions is always prepended to the result of the conversion (by default the result is preceded by minus only when it is negative). 
  * _space_ : if the result of a signed conversion does not start with a sign character, or is empty, space is prepended to the result. It is ignored if `+` flag is present. 
  * `**#**`: _alternative form_ of the conversion is performed. See the table below for exact effects otherwise the behavior is undefined. 
  * `**0**`: for integer and floating-point number conversions, leading zeros are used to pad the field instead of _space_ characters. For integer numbers it is ignored if the precision is explicitly specified. For other conversions using this flag results in undefined behavior. It is ignored if `-` flag is present. 



    

  * (optional) integer value or `*` that specifies minimum field width. The result is padded with _space_ characters (by default), if required, on the left when right-justified, or on the right if left-justified. In the case when `*` is used, the width is specified by an additional argument of type int, which appears before the argument to be converted and the argument supplying precision if one is supplied. If the value of the argument is negative, it results with the `-` flag specified and positive field width (Note: This is the minimum width: The value is never truncated.). 



    

  * (optional) `**.**` followed by integer number or `*****`, or neither that specifies _precision_ of the conversion. In the case when `*` is used, the _precision_ is specified by an additional argument of type int, which appears before the argument to be converted, but after the argument supplying minimum field width if one is supplied. If the value of this argument is negative, it is ignored. If neither a number nor `*****` is used, the precision is taken as zero. See the table below for exact effects of _precision_. 



    

  * (optional) _length modifier_ that specifies the size of the argument (in combination with the conversion format specifier, it specifies the type of the corresponding argument). 



    

  * conversion format specifier. 



The following format specifiers are available: 

Conversion  
Specifier  | Explanation  | Expected  
Argument Type   
---|---|---  
Length Modifier→  | hh  | h  | none  | l  | ll  | j  | z  | t  | L   
Only available since C99→  | Yes |  |  |  | Yes | Yes | Yes | Yes |   
`%` | Writes literal `**%**`. The full conversion specification must be `**%%**`.  |  N/A |  N/A |  N/A |  N/A |  N/A |  N/A |  N/A |  N/A |  N/A  
`c` |  Writes a **single character**. 

  * The argument is first converted to wchar_t as if by calling [btowc](../string/multibyte/btowc.html "c/string/multibyte/btowc"). 
  * If the **l** modifier is used, the wint_t argument is first converted to wchar_t. 

|  N/A |  N/A | int | wint_t |  N/A |  N/A |  N/A |  N/A |  N/A  
`s` |  Writes a **character string**. 

  * The argument must be a pointer to the initial element of a character array containing a multibyte character sequence beginning in the initial shift state, which is converted to wide character array as if by a call to [mbrtowc](../string/multibyte/mbrtowc.html "c/string/multibyte/mbrtowc") with zero-initialized conversion state. 
  * _Precision_ specifies the maximum number of wide characters to be written. If _Precision_ is not specified, writes every wide characters up to and not including the first null terminator. 
  * If the **l** specifier is used, the argument must be a pointer to the initial element of an array of wchar_t. 

|  N/A |  N/A | char* | wchar_t* |  N/A |  N/A |  N/A |  N/A |  N/A  
`d`  
`i` |  Converts a **signed integer** into decimal representation _[-]dddd_. 

  * _Precision_ specifies the minimum number of digits to appear. The default precision is 1. 
  * If both the converted value and the precision are ​0​ the conversion results in no characters. 
  * For the `**z**` modifier, the expected argument type is the signed version of [size_t](../types/size_t.html "c/types/size t"). 

| signed char | short | int | long | long long | [intmax_t](../types/integer.html "c/types/integer") | ※ | [ptrdiff_t](../types/ptrdiff_t.html "c/types/ptrdiff t") |  N/A  
`o` |  Converts an **unsigned integer** into octal representation _oooo_. 

  * _Precision_ specifies the minimum number of digits to appear. The default precision is 1. 
  * If both the converted value and the precision are ​0​ the conversion results in no characters. 
  * In the _alternative implementation_ precision is increased if necessary, to write one leading zero. In that case if both the converted value and the precision are ​0​, single ​0​ is written. 

| unsigned char | unsigned short | unsigned int | unsigned long | unsigned long long | [uintmax_t](../types/integer.html "c/types/integer") | [size_t](../types/size_t.html "c/types/size t") | unsigned version of [ptrdiff_t](../types/ptrdiff_t.html "c/types/ptrdiff t") |  N/A  
`x`  
`X` |  Converts an **unsigned integer** into hexadecimal representation _hhhh_. 

  * For the `**x**` conversion letters `abcdef` are used. 
  * For the `**X**` conversion letters `ABCDEF` are used. 
  * _Precision_ specifies the minimum number of digits to appear. The default precision is 1. 
  * If both the converted value and the precision are ​0​ the conversion results in no characters. 
  * In the _alternative implementation_ `**0x**` or `**0X**` is prefixed to results if the converted value is nonzero. 

|  N/A  
`u` |  Converts an **unsigned integer** into decimal representation _dddd_. 

  * _Precision_ specifies the minimum number of digits to appear. 
  * The default precision is 1. 
  * If both the converted value and the precision are ​0​ the conversion results in no characters. 

|  N/A  
`f`  
`F` (C99) |  Converts **floating-point number** to the decimal notation in the style _[-]ddd.ddd_. 

  * _Precision_ specifies the exact number of digits to appear after the decimal point character. 
  * The default precision is 6. 
  * In the _alternative implementation_ decimal point character is written even if no digits follow it. 
  * For infinity and not-a-number conversion style see [notes](vfwprintf.html#Notes). 

|  N/A |  N/A | double | double (C99) |  N/A |  N/A |  N/A |  N/A | long double  
`e`  
`E` |  Converts **floating-point number** to the decimal exponent notation. 

  * For the `**e**` conversion style _[-]d.ddd_ ﻿`**e**` _±dd_ is used. 
  * For the `**E**` conversion style _[-]d.ddd_ ﻿`**E**` _±dd_ is used. 
  * The exponent contains at least two digits, more digits are used only if necessary. 
  * If the value is ​0​, the exponent is also ​0​. 
  * _Precision_ specifies the exact number of digits to appear after the decimal point character. 
  * The default precision is 6. 
  * In the _alternative implementation_ decimal point character is written even if no digits follow it. 
  * For infinity and not-a-number conversion style see [notes](vfwprintf.html#Notes). 

|  N/A |  N/A |  N/A |  N/A |  N/A |  N/A  
`a`  
`A` (C99) |  Converts **floating-point number** to the hexadecimal exponent notation. 

  * For the `**a**` conversion style _[-]_ ﻿`**0x**` _h.hhh_ ﻿`**p**` _±d_ is used. 
  * For the `**A**` conversion style _[-]_ ﻿`**0X**` _h.hhh_ ﻿`**P**` _±d_ is used. 
  * The first hexadecimal digit is not `0` if the argument is a normalized floating-point value. 
  * If the value is ​0​, the exponent is also ​0​. 
  * _Precision_ specifies the exact number of digits to appear after the hexadecimal point character. 
  * The default precision is sufficient for exact representation of the value. 
  * In the _alternative implementation_ decimal point character is written even if no digits follow it. 
  * For infinity and not-a-number conversion style see [notes](vfwprintf.html#Notes). 

|  N/A |  N/A |  N/A |  N/A |  N/A |  N/A  
`g`  
`G` |  Converts **floating-point number** to decimal or decimal exponent notation depending on the value and the _precision_. 

  * For the `**g**` conversion style conversion with style `**e**` or `**f**` will be performed. 
  * For the `**G**` conversion style conversion with style `**E**` or `**f**`(until C99)`**F**`(since C99) will be performed. 
  * Let `P` equal the precision if nonzero, 6 if the precision is not specified, or 1 if the precision is ​0​. Then, if a conversion with style `E` would have an exponent of `X`: 
    * If _P > X ≥ −4_, the conversion is with style `**f**` or `**F**`(since C99) and precision _P − 1 − X_. 
    * Otherwise, the conversion is with style `**e**` or `**E**` and precision _P − 1_. 
  * Unless _alternative representation_ is requested the trailing zeros are removed, also the decimal point character is removed if no fractional part is left. 
  * For infinity and not-a-number conversion style see [notes](vfwprintf.html#Notes). 

|  N/A |  N/A |  N/A |  N/A |  N/A |  N/A  
`n` |  Returns the **number of characters written** so far by this call to the function. 

  * The result is _written_ to the value pointed to by the argument. 
  * The specification may not contain any _flag_ , _field width_ , or _precision_. 
  * For the `**z**` modifier, the expected argument type is S*, where `S` is the signed version of [size_t](../types/size_t.html). 

| signed char* | short* | int* | long* | long long* | [intmax_t](../types/integer.html "c/types/integer")* | ※ |  [ptrdiff_t](../types/ptrdiff_t.html "c/types/ptrdiff t")* |  N/A  
`p` |  Writes an implementation defined character sequence defining a **pointer**.  |  N/A |  N/A | void* |  N/A |  N/A |  N/A |  N/A |  N/A |  N/A  
Notes  
The floating-point conversion functions convert infinity to `inf` or `infinity`. Which one is used is implementation defined. Not-a-number is converted to `nan` or `nan(_char_sequence_)`. Which one is used is implementation defined. The conversions `**F**`, `**E**`, `**G**`, `**A**` output `INF`, `INFINITY`, `NAN` instead. The conversion specifier used to print char, unsigned char, signed char, short, and unsigned short expects promoted types of [default argument promotions](../language/conversion.html#Default_argument_promotions "c/language/conversion"), but before printing its value will be converted to char, unsigned char, signed char, short, and unsigned short. It is safe to pass values of these types because of the promotion that takes place when a variadic function is called. The correct conversion specifications for the fixed-width character types ([int8_t](../types/integer.html "c/types/integer"), etc) are defined in the header [`<inttypes.h>`](../header/inttypes.html "c/header/inttypes") (although [PRIdMAX](../types/integer.html "c/types/integer"), [PRIuMAX](../types/integer.html "c/types/integer"), etc is synonymous with `%jd`, `%ju`, etc). The memory-writing conversion specifier `%n` is a common target of security exploits where format strings depend on user input and is not supported by the bounds-checked `printf_s` family of functions(since C11). There is a [sequence point](../language/eval_order.html "c/language/eval order") after the action of each conversion specifier; this permits storing multiple `%n` results in the same variable or, as an edge case, printing a string modified by an earlier `%n` within the same call. If a conversion specification is invalid, the behavior is undefined.   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/vfwprintf&action=edit&section=2 "Edit section: Return value")] Return value

1,4) The number of wide characters written if successful or negative value if an error occurred.

3) The number of wide characters written if successful or negative value if an error occurred. If the resulting string gets truncated due to bufsz limit, function returns the total number of characters (not including the terminating null wide character) which would have been written, if the limit were not imposed.

2,5) number of wide characters transmitted to the output stream or negative value if an output error, a runtime constraints violation error, or an encoding error occurred.

6) number of wide characters written to buffer, not counting the null wide character (which is always written as long as buffer is not a null pointer and bufsz is not zero and not greater than `RSIZE_MAX/sizeof(wchar_t)`), or zero on runtime constraint violations, and negative value on encoding errors.

7) number of wide characters not including the terminating null character (which is always written as long as buffer is not a null pointer and bufsz is not zero and not greater than `RSIZE_MAX/sizeof(wchar_t)`), which would have been written to buffer if bufsz was ignored, or a negative value if a runtime constraints violation or an encoding error occurred.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/vfwprintf&action=edit&section=3 "Edit section: Notes")] Notes

All these functions invoke va_arg at least once, the value of arg is indeterminate after the return. These functions to not invoke va_end, and it must be done by the caller. 

While narrow strings provide [vsnprintf](vfprintf.html "c/io/vfprintf"), which makes it possible to determine the required output buffer size, there is no equivalent for wide strings (until C11's vsnwprintf_s), and in order to determine the buffer size, the program may need to call `vswprintf`, check the result value, and reallocate a larger buffer, trying again until successful. 

`vsnwprintf_s`, unlike `vswprintf_s`, will truncate the result to fit within the array pointed to by buffer, even though truncation is treated as an error by most bounds-checked functions. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/vfwprintf&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <locale.h>
    #include <stdarg.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <time.h>
    #include <wchar.h>
     
    void debug_wlog(const wchar_t* fmt, ...)
    {
        struct timespec ts;
        timespec_get(&ts, TIME_UTC);
        char time_buf[100];
        [size_t](../types/size_t.html) rc = [strftime](../chrono/strftime.html)(time_buf, sizeof time_buf, "%D %T", [gmtime](../chrono/gmtime.html)(&ts.tv_sec));
        [snprintf](fprintf.html)(time_buf + rc, sizeof time_buf - rc, ".%06ld UTC", ts.tv_nsec / 1000);
     
        va_list args;
        va_start(args, fmt);
        wchar_t buf[1024];
        int rc2 = vswprintf(buf, sizeof buf / sizeof *buf, fmt, args);
        va_end(args);
     
        if(rc2 > 0)
           [wprintf](fwprintf.html)(L"%s [debug]: %ls\n", time_buf, buf);
        else
           [wprintf](fwprintf.html)(L"%s [debug]: (string too long)\n", time_buf);
    }
     
    int main(void)
    {
        [setlocale](../locale/setlocale.html)([LC_ALL](../locale/LC_categories.html), "");
        debug_wlog(L"Logging, %d, %d, %d", 1, 2, 3);
    }

Possible output: 
    
    
    02/20/15 22:12:38.476575 UTC [debug]: Logging, 1, 2, 3

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/vfwprintf&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.29.2.5 The vfwprintf function (p: TBD) 



    

  * 7.29.2.7 The vswprintf function (p: TBD) 



    

  * 7.29.2.9 The vwprintf function (p: TBD) 



    

  * K.3.9.1.6 The vfwprintf_s function (p: TBD) 



    

  * K.3.9.1.8 The vsnwprintf_s function (p: TBD) 



    

  * K.3.9.1.9 The vswprintf_s function (p: TBD) 



    

  * K.3.9.1.11 The vwprintf_s function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.29.2.5 The vfwprintf function (p: TBD) 



    

  * 7.29.2.7 The vswprintf function (p: TBD) 



    

  * 7.29.2.9 The vwprintf function (p: TBD) 



    

  * K.3.9.1.6 The vfwprintf_s function (p: TBD) 



    

  * K.3.9.1.8 The vsnwprintf_s function (p: TBD) 



    

  * K.3.9.1.9 The vswprintf_s function (p: TBD) 



    

  * K.3.9.1.11 The vwprintf_s function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.29.2.5 The vfwprintf function (p: 417-418) 



    

  * 7.29.2.7 The vswprintf function (p: 419) 



    

  * 7.29.2.9 The vwprintf function (p: 420) 



    

  * K.3.9.1.6 The vfwprintf_s function (p: 632) 



    

  * K.3.9.1.8 The vsnwprintf_s function (p: 633-634) 



    

  * K.3.9.1.9 The vswprintf_s function (p: 634-635) 



    

  * K.3.9.1.11 The vwprintf_s function (p: 636) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.24.2.5 The vfwprintf function (p: 363) 



    

  * 7.24.2.7 The vswprintf function (p: 364) 



    

  * 7.24.2.9 The vwprintf function (p: 365) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/io/vfwprintf&action=edit&section=6 "Edit section: See also")] See also

[ vprintfvfprintfvsprintfvsnprintfvprintf_svfprintf_svsprintf_svsnprintf_s](vfprintf.html "c/io/vfprintf")(C99)(C11)(C11)(C11)(C11) |  prints formatted output to [stdout](std_streams.html "c/io/std streams"), a file stream or a buffer  
using variable argument list   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_vfprintf&action=edit)  
---|---  
[ wprintffwprintfswprintfwprintf_sfwprintf_sswprintf_ssnwprintf_s](fwprintf.html "c/io/fwprintf")(C95)(C95)(C95)(C11)(C11)(C11)(C11) |  prints formatted wide character output to [stdout](std_streams.html "c/io/std streams"), a file stream or a buffer   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fwprintf&action=edit)  
[C++ documentation](../../cpp/io/c/vfwprintf.html "cpp/io/c/vfwprintf") for vwprintf, vfwprintf, vswprintf  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/io/vfwprintf&oldid=172069](https://en.cppreference.com/mwiki/index.php?title=c/io/vfwprintf&oldid=172069)" 

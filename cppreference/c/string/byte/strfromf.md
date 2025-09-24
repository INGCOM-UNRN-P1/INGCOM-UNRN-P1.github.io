From cppreference.com

< [c](../../../c.html "c")‎ | [string](../../string.html "c/string")‎ | [byte](../byte.html "c/string/byte")

[ C](../../../c.html "c")

[Compiler support](../../compiler_support.html "c/compiler support")  
---  
[Language](../../language.html "c/language")  
[Headers](../../header.html "c/header")  
[Type support](../../types.html "c/types")  
[Program utilities](../../program.html "c/program")  
[Variadic function support](../../variadic.html "c/variadic")  
[Error handling](../../error.html "c/error")  
[Dynamic memory management](../../memory.html "c/memory")  
[Strings library](../../string.html "c/string")  
[Algorithms](../../algorithm.html "c/algorithm")  
[Numerics](../../numeric.html "c/numeric")  
[Date and time utilities](../../chrono.html "c/chrono")  
[Input/output support](../../io.html "c/io")  
[Localization support](../../locale.html "c/locale")  
[Concurrency support](../../thread.html "c/thread") (C11)  
[Technical Specifications](../../experimental.html "c/experimental")  
[Symbol index](../../index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

[ Strings library](../../string.html "c/string")

[Null-terminated byte strings](../byte.html "c/string/byte")  
---  
[Null-terminated multibyte strings](../multibyte.html "c/string/multibyte")  
[Null-terminated wide strings](../wide.html "c/string/wide")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/navbar_content&action=edit)

[ Null-terminated byte strings](../byte.html "c/string/byte")

Functions  
---  
Character manipulation  
| [isalnum](isalnum.html "c/string/byte/isalnum")  
---  
[isalpha](isalpha.html "c/string/byte/isalpha")  
[islower](islower.html "c/string/byte/islower")  
[isupper](isupper.html "c/string/byte/isupper")  
[isdigit](isdigit.html "c/string/byte/isdigit")  
[isxdigit](isxdigit.html "c/string/byte/isxdigit")  
[isblank](isblank.html "c/string/byte/isblank")(C99)  
  
| [iscntrl](iscntrl.html "c/string/byte/iscntrl")  
---  
[isgraph](isgraph.html "c/string/byte/isgraph")  
[isspace](isspace.html "c/string/byte/isspace")  
[isprint](isprint.html "c/string/byte/isprint")  
[ispunct](ispunct.html "c/string/byte/ispunct")  
[tolower](tolower.html "c/string/byte/tolower")  
[toupper](toupper.html "c/string/byte/toupper")  
  
Conversions to and from numeric formats  
| [atoiatolatoll](atoi.html "c/string/byte/atoi")(C99)  
---  
[atof](atof.html "c/string/byte/atof")  
[strtolstrtoll](strtol.html "c/string/byte/strtol")(C99)  
[strtoulstrtoull](strtoul.html "c/string/byte/strtoul")(C99)  
  
| [strtoimaxstrtoumax](strtoimax.html "c/string/byte/strtoimax")(C99)(C99)  
---  
[strtofstrtodstrtold](strtof.html "c/string/byte/strtof")(C99)(C99)  
**strfromf strfromdstrfroml**(C23)(C23)(C23)  
  
String manipulation  
| [strcpystrcpy_s](strcpy.html "c/string/byte/strcpy")(C11)  
---  
[strncpystrncpy_s](strncpy.html "c/string/byte/strncpy")(C11)  
[strcatstrcat_s](strcat.html "c/string/byte/strcat")(C11)  
  
| [strncatstrncat_s](strncat.html "c/string/byte/strncat")(C11)  
---  
[strxfrm](strxfrm.html "c/string/byte/strxfrm")  
[strdup](strdup.html "c/string/byte/strdup")(C23)  
[strndup](strndup.html "c/string/byte/strndup")(C23)  
  
  
  
String examination  
| [strlenstrnlen_s](strlen.html "c/string/byte/strlen")(C11)  
---  
[strcmp](strcmp.html "c/string/byte/strcmp")  
[strncmp](strncmp.html "c/string/byte/strncmp")  
[strcoll](strcoll.html "c/string/byte/strcoll")  
[strchr](strchr.html "c/string/byte/strchr")  
[strrchr](strrchr.html "c/string/byte/strrchr")  
  
| [strspn](strspn.html "c/string/byte/strspn")  
---  
[strcspn](strcspn.html "c/string/byte/strcspn")  
[strpbrk](strpbrk.html "c/string/byte/strpbrk")  
[strstr](strstr.html "c/string/byte/strstr")  
[strtokstrtok_s](strtok.html "c/string/byte/strtok")(C11)  
  
  
  
Memory manipulation  
| [memchr](memchr.html "c/string/byte/memchr")  
---  
[memcmp](memcmp.html "c/string/byte/memcmp")  
[memsetmemset_explicitmemset_s](memset.html "c/string/byte/memset")(C23)(C11)  
  
| [memcpymemcpy_s](memcpy.html "c/string/byte/memcpy")(C11)  
---  
[memmovememmove_s](memmove.html "c/string/byte/memmove")(C11)  
[memccpy](memccpy.html "c/string/byte/memccpy")(C23)  
  
Miscellaneous  
[strerrorstrerror_sstrerrorlen_s](strerror.html "c/string/byte/strerror")(C11)(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/navbar_content&action=edit)

Defined in header `[`<stdlib.h>`](../../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
int strfromf( char* restrict s, [size_t](../../types/size_t.html) n, const char* restrict format, float fp ); |  |  (since C23)  
int strfromd( char* restrict s, [size_t](../../types/size_t.html) n, const char* restrict format, double fp ); |  |  (since C23)  
int strfroml( char* restrict s, [size_t](../../types/size_t.html) n, const char* restrict format, long double fp ); |  |  (since C23)  
| |   
  
Converts a floating-point value to a byte string. 

The functions are equivalent to [snprintf](../../io/fprintf.html)(s, n, format, fp), except that the format string shall only contain the character %, an optional precision that does not contain an asterisk *, and one of the conversion specifiers `a`, `A`, `e`, `E`, `f`, `F`, `g`, or `G`, which applies to the type double, float, or long double) indicated by the function suffix (rather than by a length modifier). Use of these functions with any other format string results in undefined behavior. 

## Contents

  * [1 Parameters](strfromf.html#Parameters)
  * [2 Return value](strfromf.html#Return_value)
  * [3 Example](strfromf.html#Example)
  * [4 Reference](strfromf.html#Reference)
  * [5 See also](strfromf.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strfromf&action=edit&section=1 "Edit section: Parameters")] Parameters

s  |  \-  |  pointer to a character string to write to   
---|---|---  
n  |  \-  |  up to n - 1 characters may be written, plus the null terminator   
format  |  \-  |  pointer to a null-terminated byte string specifying how to interpret the data   
fp  |  \-  |  floating-point value to convert   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strfromf&action=edit&section=2 "Edit section: Return value")] Return value

The number of characters that would have been written had n been sufficiently large, not counting the terminating null character. Thus, the null-terminated output has been completely written if and only if the returned value is both nonnegative and less than n. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strfromf&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main()
    {
        char buffer[32];
        int written;
        const char* format[] = {"%a", "%A", "%e", "%E", "%f", "%F", "%g", "%G"};
     
        for ([size_t](../../types/size_t.html) fmt = 0; fmt != sizeof format / sizeof format[0]; ++fmt)
        {
            written = strfromf(buffer, sizeof buffer, format[fmt], 3.1415f);
            [printf](../../io/fprintf.html)("strfromf(... %s ...) = %2i, buffer: \"%s\"\n",
                   format[fmt], written, buffer);
        }
        [puts](../../io/puts.html)("");
     
        for ([size_t](../../types/size_t.html) fmt = 0; fmt != sizeof format / sizeof format[0]; ++fmt)
        {
            written = strfromd(buffer, sizeof buffer, format[fmt], 3.1415);
            [printf](../../io/fprintf.html)("strfromd(... %s ...) = %2i, buffer: \"%s\"\n",
                   format[fmt], written, buffer);
        }
        [puts](../../io/puts.html)("");
     
        for ([size_t](../../types/size_t.html) fmt = 0; fmt != sizeof format / sizeof format[0]; ++fmt)
        {
            written = strfroml(buffer, sizeof buffer, format[fmt], 3.1415);
            [printf](../../io/fprintf.html)("strfroml(... %s ...) = %2i, buffer: \"%s\"\n",
                   format[fmt], written, buffer);
        }
    }

Output: 
    
    
    strfromf(... %a ...) = 13, buffer: "0x1.921cacp+1"
    strfromf(... %A ...) = 13, buffer: "0X1.921CACP+1"
    strfromf(... %e ...) = 12, buffer: "3.141500e+00"
    strfromf(... %E ...) = 12, buffer: "3.141500E+00"
    strfromf(... %f ...) =  8, buffer: "3.141500"
    strfromf(... %F ...) =  8, buffer: "3.141500"
    strfromf(... %g ...) =  6, buffer: "3.1415"
    strfromf(... %G ...) =  6, buffer: "3.1415"
     
    strfromd(... %a ...) = 20, buffer: "0x1.921cac083126fp+1"
    strfromd(... %A ...) = 20, buffer: "0X1.921CAC083126FP+1"
    strfromd(... %e ...) = 12, buffer: "3.141500e+00"
    strfromd(... %E ...) = 12, buffer: "3.141500E+00"
    strfromd(... %f ...) =  8, buffer: "3.141500"
    strfromd(... %F ...) =  8, buffer: "3.141500"
    strfromd(... %g ...) =  6, buffer: "3.1415"
    strfromd(... %G ...) =  6, buffer: "3.1415"
     
    strfroml(... %a ...) = 20, buffer: "0xc.90e5604189378p-2"
    strfroml(... %A ...) = 20, buffer: "0XC.90E5604189378P-2"
    strfroml(... %e ...) = 12, buffer: "3.141500e+00"
    strfroml(... %E ...) = 12, buffer: "3.141500E+00"
    strfroml(... %f ...) =  8, buffer: "3.141500"
    strfroml(... %F ...) =  8, buffer: "3.141500"
    strfroml(... %g ...) =  6, buffer: "3.1415"
    strfroml(... %G ...) =  6, buffer: "3.1415"

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strfromf&action=edit&section=4 "Edit section: Reference")] Reference

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.24.1.3 The strfromd, strfromf, and strfroml functions 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strfromf&action=edit&section=5 "Edit section: See also")] See also

[ printffprintfsprintfsnprintfprintf_sfprintf_ssprintf_ssnprintf_s](../../io/fprintf.html "c/io/fprintf")(C99)(C11)(C11)(C11)(C11) |  prints formatted output to [stdout](../../io/std_streams.html "c/io/std streams"), a file stream or a buffer   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_fprintf&action=edit)  
---|---  
[ strtofstrtodstrtold](strtof.html "c/string/byte/strtof")(C99)(C99) |  converts a byte string to a floating-point value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtof&action=edit)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strfromf&oldid=178809](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strfromf&oldid=178809)" 

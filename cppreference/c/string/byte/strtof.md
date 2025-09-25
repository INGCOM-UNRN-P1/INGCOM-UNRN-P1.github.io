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
**strtof strtodstrtold**(C99)(C99)  
[strfromfstrfromdstrfroml](strfromf.html "c/string/byte/strfromf")(C23)(C23)(C23)  
  
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
float strtof ( const char* restrict str, char** restrict str_end ); |  (1)  |  (since C99)  
| (2) |   
double strtod ( const char* str, char** str_end ); |  | (until C99)  
double strtod ( const char* restrict str, char** restrict str_end ); |  |  (since C99)  
long double strtold( const char* restrict str, char** restrict str_end ); |  (3)  |  (since C99)  
| |   
  
Interprets a floating-point value in a byte string pointed to by str. 

Function discards any whitespace characters (as determined by [isspace](isspace.html "c/string/byte/isspace")) until first non-whitespace character is found. Then it takes as many characters as possible to form a valid floating-point representation and converts them to a floating-point value. The valid floating-point value can be one of the following: 

  * decimal floating-point expression. It consists of the following parts: 



    

  * (optional) plus or minus sign 
  * nonempty sequence of decimal digits optionally containing decimal-point character (as determined by the current C [locale](../../locale/setlocale.html "c/locale/setlocale")) (defines significand) 
  * (optional) `**e**` or `**E**` followed with optional minus or plus sign and nonempty sequence of decimal digits (defines exponent to base 10) 



  * hexadecimal floating-point expression. It consists of the following parts: 



    

  * (optional) plus or minus sign 
  * `**0x**` or `**0X**`
  * nonempty sequence of hexadecimal digits optionally containing a decimal-point character (as determined by the current C [locale](../../locale/setlocale.html "c/locale/setlocale")) (defines significand) 
  * (optional) `**p**` or `**P**` followed with optional minus or plus sign and nonempty sequence of decimal digits (defines exponent to base 2) 



  * infinity expression. It consists of the following parts: 



    

  * (optional) plus or minus sign 
  * `**INF**` or `**INFINITY**` ignoring case 



  * not-a-number expression. It consists of the following parts: 



    

  * (optional) plus or minus sign 
  * `**NAN**` or `**NAN(**`_char_sequence ﻿_`**)**` ignoring case of the `**NAN**` part. _char_sequence_ can only contain digits, Latin letters, and underscores. The result is a quiet NaN floating-point value. 


| (since C99)  
---|---  
  
  * any other expression that may be accepted by the currently installed C [locale](../../locale/setlocale.html "c/locale/setlocale"). 



The functions sets the pointer pointed to by str_end to point to the character past the last character interpreted. If str_end is a null pointer, it is ignored. 

## Contents

  * [1 Parameters](strtof.html#Parameters)
  * [2 Return value](strtof.html#Return_value)
  * [3 Example](strtof.html#Example)
  * [4 References](strtof.html#References)
  * [5 See also](strtof.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtof&action=edit&section=1 "Edit section: Parameters")] Parameters

str  |  \-  |  pointer to the null-terminated byte string to be interpreted   
---|---|---  
str_end  |  \-  |  pointer to a pointer to character   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtof&action=edit&section=2 "Edit section: Return value")] Return value

Floating-point value corresponding to the contents of str on success. If the converted value falls out of range of corresponding return type, range error occurs ([errno](../../error/errno.html "c/error/errno") is set to [ERANGE](../../error/errno_macros.html "c/error/errno macros")) and [HUGE_VAL](../../numeric/math/HUGE_VALL.html "c/numeric/math/HUGE VAL"), [HUGE_VALF](../../numeric/math/HUGE_VALL.html "c/numeric/math/HUGE VAL") or [HUGE_VALL](../../numeric/math/HUGE_VALL.html "c/numeric/math/HUGE VAL") is returned. If no conversion can be performed, ​0​ is returned. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtof&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <errno.h>
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        // parsing with error handling
        const char* p = "111.11 -2.22 Nan nan(2) inF 0X1.BC70A3D70A3D7P+6  1.18973e+4932zzz";
        [printf](../../io/fprintf.html)("Parsing '%s':\n", p);
        char* end = [NULL](../../types/NULL.html);
        for (double f = strtod(p, &end); p != end; f = strtod(p, &end))
        {
            [printf](../../io/fprintf.html)("'%.*s' -> ", (int)(end - p), p);
            p = end;
            if (errno == [ERANGE](../../error/errno_macros.html))
            {
                [printf](../../io/fprintf.html)("range error, got ");
                errno = 0;
            }
            [printf](../../io/fprintf.html)("%f\n", f);
        }
     
        // parsing without error handling
        [printf](../../io/fprintf.html)("\"  -0.0000000123junk\"  -->  %g\n", strtod("  -0.0000000123junk", [NULL](../../types/NULL.html)));
        [printf](../../io/fprintf.html)("\"junk\"                 -->  %g\n", strtod("junk", [NULL](../../types/NULL.html)));
    }

Possible output: 
    
    
    Parsing '111.11 -2.22 Nan nan(2) inF 0X1.BC70A3D70A3D7P+6  1.18973e+4932zzz':
    '111.11' -> 111.110000
    ' -2.22' -> -2.220000
    ' Nan' -> nan
    ' nan(2)' -> nan
    ' inF' -> inf
    ' 0X1.BC70A3D70A3D7P+6' -> 111.110000
    '  1.18973e+4932' -> range error, got inf
    "  -0.0000000123junk"  -->  -1.23e-08
    "junk"                 -->  0

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtof&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.22.1.3 The strtod, strtof, and strtold functions (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.1.3 The strtod, strtof, and strtold functions (p: 249-251) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.1.3 The strtod, strtof, and strtold functions (p: 342-344) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.1.3 The strtod, strtof, and strtold functions (p: 308-310) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.1.4 The strtod function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtof&action=edit&section=5 "Edit section: See also")] See also

[ atof](atof.html "c/string/byte/atof") |  converts a byte string to a floating-point value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_atof&action=edit)  
---|---  
[ wcstofwcstodwcstold](../wide/wcstof.html "c/string/wide/wcstof")(C99)(C95)(C99) |  converts a wide string to a floating-point value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstof&action=edit)  
[C++ documentation](../../../cpp/string/byte/strtof.html "cpp/string/byte/strtof") for strtof, strtod, strtold  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtof&oldid=178833](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtof&oldid=178833)" 

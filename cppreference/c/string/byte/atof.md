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
**atof**  
[strtolstrtoll](strtol.html "c/string/byte/strtol")(C99)  
[strtoulstrtoull](strtoul.html "c/string/byte/strtoul")(C99)  
  
| [strtoimaxstrtoumax](strtoimax.html "c/string/byte/strtoimax")(C99)(C99)  
---  
[strtofstrtodstrtold](strtof.html "c/string/byte/strtof")(C99)(C99)  
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
double atof( const char* str ); |  |   
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



## Contents

  * [1 Parameters](atof.html#Parameters)
  * [2 Return value](atof.html#Return_value)
  * [3 Notes](atof.html#Notes)
  * [4 Example](atof.html#Example)
  * [5 References](atof.html#References)
  * [6 See also](atof.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atof&action=edit&section=1 "Edit section: Parameters")] Parameters

str  |  \-  |  pointer to the null-terminated byte string to be interpreted   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atof&action=edit&section=2 "Edit section: Return value")] Return value

double value corresponding to the contents of str on success. If the converted value falls out of range of the return type, the return value is undefined. If no conversion can be performed, 0.0 is returned. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atof&action=edit&section=3 "Edit section: Notes")] Notes

The name stands for “ASCII to float”. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atof&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        [printf](../../io/fprintf.html)("%g\n", atof("  -0.0000000123junk"));
        [printf](../../io/fprintf.html)("%g\n", atof("0.012"));
        [printf](../../io/fprintf.html)("%g\n", atof("15e16"));
        [printf](../../io/fprintf.html)("%g\n", atof("-0x1afp-2"));
        [printf](../../io/fprintf.html)("%g\n", atof("inF"));
        [printf](../../io/fprintf.html)("%g\n", atof("Nan"));
        [printf](../../io/fprintf.html)("%g\n", atof("1.0e+309"));   // UB: out of range of double
        [printf](../../io/fprintf.html)("%g\n", atof("0.0"));
        [printf](../../io/fprintf.html)("%g\n", atof("junk"));       // no conversion can be performed
    }

Possible output: 
    
    
    -1.23e-08
    0.012
    1.5e+17
    -107.75
    inf
    nan
    inf
    0
    0

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atof&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.22.1.1 The atof function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.1.1 The atof function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.1.1 The atof function (p: 341) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.1.1 The atof function (p: 307) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.1.1 The atof function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atof&action=edit&section=6 "Edit section: See also")] See also

[ strtofstrtodstrtold](strtof.html "c/string/byte/strtof")(C99)(C99) |  converts a byte string to a floating-point value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtof&action=edit)  
---|---  
[C++ documentation](../../../cpp/string/byte/atof.html "cpp/string/byte/atof") for atof  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atof&oldid=181410](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atof&oldid=181410)" 

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
**strtoul strtoull**(C99)  
  
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
unsigned long strtoul( const char* str, char** str_end,  
int base ); |  | (until C99)  
unsigned long strtoul( const char* restrict str, char** restrict str_end,  
int base ); |  |  (since C99)  
unsigned long long strtoull( const char* restrict str, char** restrict str_end,  
int base ); |  |  (since C99)  
| |   
  
Interprets an unsigned integer value in a byte string pointed to by str. 

Discards any whitespace characters (as identified by calling [`isspace`](isspace.html "c/string/byte/isspace")) until the first non-whitespace character is found, then takes as many characters as possible to form a valid _base-n_ (where n=`base`) unsigned integer number representation and converts them to an integer value. The valid unsigned integer value consists of the following parts: 

  * (optional) plus or minus sign 
  * (optional) prefix (`**0**`) indicating octal base (applies only when the base is 8 or ​0​) 
  * (optional) prefix (`**0x**` or `**0X**`) indicating hexadecimal base (applies only when the base is 16 or ​0​) 
  * a sequence of digits 



The set of valid values for base is `{0, 2, 3, ..., 36}`. The set of valid digits for base-`2` integers is `{0, 1}`, for base-`3` integers is `{0, 1, 2}`, and so on. For bases larger than `10`, valid digits include alphabetic characters, starting from `Aa` for base-`11` integer, to `Zz` for base-`36` integer. The case of the characters is ignored. 

Additional numeric formats may be accepted by the currently installed C [locale](../../locale/setlocale.html "c/locale/setlocale"). 

If the value of `base` is ​0​, the numeric base is auto-detected: if the prefix is `**0**`, the base is octal, if the prefix is `**0x**` or `**0X**`, the base is hexadecimal, otherwise the base is decimal. 

If the minus sign was part of the input sequence, the numeric value calculated from the sequence of digits is negated as if by [unary minus](../../language/operator_arithmetic.html#Unary_arithmetic "c/language/operator arithmetic") in the result type, which applies unsigned integer wraparound rules. 

The functions sets the pointer pointed to by str_end to point to the character past the last character interpreted. If str_end is a null pointer, it is ignored. 

## Contents

  * [1 Parameters](strtoul.html#Parameters)
  * [2 Return value](strtoul.html#Return_value)
  * [3 Example](strtoul.html#Example)
  * [4 References](strtoul.html#References)
  * [5 See also](strtoul.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtoul&action=edit&section=1 "Edit section: Parameters")] Parameters

str  |  \-  |  pointer to the null-terminated byte string to be interpreted   
---|---|---  
str_end  |  \-  |  pointer to a pointer to character, might be set to a position past the last character interpreted   
base  |  \-  |  _base_ of the interpreted integer value   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtoul&action=edit&section=2 "Edit section: Return value")] Return value

Integer value corresponding to the contents of str on success. If the converted value falls out of range of corresponding return type, range error occurs ([errno](../../error/errno.html "c/error/errno") is set to `ERANGE`) and [ULONG_MAX](../../types/limits.html "c/types/limits") or [ULLONG_MAX](../../types/limits.html "c/types/limits") is returned. If no conversion can be performed, ​0​ is returned. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtoul&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <errno.h>
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        const char* p = "10 200000000000000000000000000000 30 -40 - 42";
        [printf](../../io/fprintf.html)("Parsing '%s':\n", p);
        char* end = [NULL](../../types/NULL.html);
        for (unsigned long i = strtoul(p, &end, 10);
             p != end;
             i = strtoul(p, &end, 10))
        {
            [printf](../../io/fprintf.html)("'%.*s' -> ", (int)(end - p), p);
            p = end;
            if (errno == [ERANGE](../../error/errno_macros.html))
            {
                errno = 0;
                [printf](../../io/fprintf.html)("range error, got ");
            }
            [printf](../../io/fprintf.html)("%lu\n", i);
        }
        [printf](../../io/fprintf.html)("After the loop p points to '%s'\n", p);
    }

Output: 
    
    
    Parsing '10 200000000000000000000000000000 30 -40 - 42':
    '10' -> 10
    ' 200000000000000000000000000000' -> range error, got 18446744073709551615
    ' 30' -> 30
    ' -40' -> 18446744073709551576
    After the loop p points to ' - 42'

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtoul&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.24.1.7 The strtol, strtoll, strtoul, and strtoull functions (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.1.4 The strtol, strtoll, strtoul, and strtoull functions (p: 251-252) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.1.4 The strtol, strtoll, strtoul, and strtoull functions (p: 344-345) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.1.4 The strtol, strtoll, strtoul, and strtoull functions (p: 310-311) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.1.6 The strtoul function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtoul&action=edit&section=5 "Edit section: See also")] See also

[ wcstoulwcstoull](../wide/wcstoul.html "c/string/wide/wcstoul")(C95)(C99) |  converts a wide string to an unsigned integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstoul&action=edit)  
---|---  
[ atoiatolatoll](atoi.html "c/string/byte/atoi")(C99) |  converts a byte string to an integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_atoi&action=edit)  
[ strtolstrtoll](strtol.html "c/string/byte/strtol")(C99) |  converts a byte string to an integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtol&action=edit)  
[C++ documentation](../../../cpp/string/byte/strtoul.html "cpp/string/byte/strtoul") for strtoul  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtoul&oldid=181408](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtoul&oldid=181408)" 

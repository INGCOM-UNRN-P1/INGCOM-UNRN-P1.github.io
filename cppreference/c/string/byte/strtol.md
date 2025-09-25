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
**strtol strtoll**(C99)  
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
long strtol( const char* str, char** str_end, int base ); |  | (until C99)  
long strtol( const char* restrict str, char** restrict str_end, int base ); |  |  (since C99)  
long long strtoll( const char* restrict str, char** restrict str_end, int base ); |  |  (since C99)  
| |   
  
Interprets an integer value in a byte string pointed to by str. 

Discards any whitespace characters (as identified by calling [`isspace`](isspace.html "c/string/byte/isspace")) until the first non-whitespace character is found, then takes as many characters as possible to form a valid _base-n_ (where n=`base`) integer number representation and converts them to an integer value. The valid integer value consists of the following parts: 

  * (optional) plus or minus sign 
  * (optional) prefix (`**0**`) indicating octal base (applies only when the base is 8 or ​0​) 
  * (optional) prefix (`**0x**` or `**0X**`) indicating hexadecimal base (applies only when the base is 16 or ​0​) 
  * a sequence of digits 



The set of valid values for base is `{0, 2, 3, ..., 36}`. The set of valid digits for base-`2` integers is `{0, 1}`, for base-`3` integers is `{0, 1, 2}`, and so on. For bases larger than `10`, valid digits include alphabetic characters, starting from `Aa` for base-`11` integer, to `Zz` for base-`36` integer. The case of the characters is ignored. 

Additional numeric formats may be accepted by the currently installed C [locale](../../locale/setlocale.html "c/locale/setlocale"). 

If the value of `base` is ​0​, the numeric base is auto-detected: if the prefix is `**0**`, the base is octal, if the prefix is `**0x**` or `**0X**`, the base is hexadecimal, otherwise the base is decimal. 

If the minus sign was part of the input sequence, the numeric value calculated from the sequence of digits is negated as if by [unary minus](../../language/operator_arithmetic.html#Unary_arithmetic "c/language/operator arithmetic") in the result type. 

The functions set the pointer pointed to by str_end to point to the character past the last numeric character interpreted. If str_end is a null pointer, it is ignored. 

If the str is empty or does not have the expected form, no conversion is performed, and (if str_end is not a null pointer) the value of str is stored in the object pointed to by str_end. 

## Contents

  * [1 Parameters](strtol.html#Parameters)
  * [2 Return value](strtol.html#Return_value)
  * [3 Example](strtol.html#Example)
  * [4 References](strtol.html#References)
  * [5 See also](strtol.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtol&action=edit&section=1 "Edit section: Parameters")] Parameters

str  |  \-  |  pointer to the null-terminated byte string to be interpreted   
---|---|---  
str_end  |  \-  |  pointer to a pointer to character   
base  |  \-  |  _base_ of the interpreted integer value   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtol&action=edit&section=2 "Edit section: Return value")] Return value

  * If successful, an integer value corresponding to the contents of str is returned. 
  * If the converted value falls out of range of corresponding return type, a range error occurs (setting [errno](../../error/errno.html "c/error/errno") to [ERANGE](../../error/errno_macros.html "c/error/errno macros")) and [LONG_MAX](../../types/limits.html "c/types/limits"), [LONG_MIN](../../types/limits.html "c/types/limits"), [LLONG_MAX](../../types/limits.html "c/types/limits") or [LLONG_MIN](../../types/limits.html "c/types/limits") is returned. 
  * If no conversion can be performed, ​0​ is returned. 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtol&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <errno.h>
    #include <limits.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        // parsing with error handling
        const char* p = "10 200000000000000000000000000000 30 -40 junk";
        [printf](../../io/fprintf.html)("Parsing '%s':\n", p);
     
        for (;;)
        {
            // errno can be set to any non-zero value by a library function call
            // regardless of whether there was an error, so it needs to be cleared
            // in order to check the error set by strtol
            errno = 0;
            char* end;
            const long i = strtol(p, &end, 10);
            if (p == end)
                break;
     
            const bool range_error = errno == [ERANGE](../../error/errno_macros.html);
            [printf](../../io/fprintf.html)("Extracted '%.*s', strtol returned %ld.", (int)(end-p), p, i);
            p = end;
     
            if (range_error)
                [printf](../../io/fprintf.html)("\n --> Range error occurred.");
     
            [putchar](../../io/putchar.html)('\n');
        }
     
        [printf](../../io/fprintf.html)("Unextracted leftover: '%s'\n\n", p);
     
        // parsing without error handling
        [printf](../../io/fprintf.html)("\"1010\" in binary  --> %ld\n", strtol("1010", [NULL](../../types/NULL.html), 2));
        [printf](../../io/fprintf.html)("\"12\"   in octal   --> %ld\n", strtol("12",   [NULL](../../types/NULL.html), 8));
        [printf](../../io/fprintf.html)("\"A\"    in hex     --> %ld\n", strtol("A",    [NULL](../../types/NULL.html), 16));
        [printf](../../io/fprintf.html)("\"junk\" in base-36 --> %ld\n", strtol("junk", [NULL](../../types/NULL.html), 36));
        [printf](../../io/fprintf.html)("\"012\"  in auto-detected base --> %ld\n", strtol("012",  [NULL](../../types/NULL.html), 0));
        [printf](../../io/fprintf.html)("\"0xA\"  in auto-detected base --> %ld\n", strtol("0xA",  [NULL](../../types/NULL.html), 0));
        [printf](../../io/fprintf.html)("\"junk\" in auto-detected base --> %ld\n", strtol("junk", [NULL](../../types/NULL.html), 0));
    }

Possible output: 
    
    
    Parsing '10 200000000000000000000000000000 30 -40 junk':
    Extracted '10', strtol returned 10.
    Extracted ' 200000000000000000000000000000', strtol returned 9223372036854775807.
     --> Range error occurred.
    Extracted ' 30', strtol returned 30.
    Extracted ' -40', strtol returned -40.
    Unextracted leftover: ' junk'
     
    "1010" in binary  --> 10
    "12"   in octal   --> 10
    "A"    in hex     --> 10
    "junk" in base-36 --> 926192
    "012"  in auto-detected base --> 10
    "0xA"  in auto-detected base --> 10
    "junk" in auto-detected base --> 0

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtol&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.22.1.4 The strtol, strtoll, strtoul, and strtoull functions (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.1.4 The strtol, strtoll, strtoul, and strtoull functions (p: 251-252) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.1.4 The strtol, strtoll, strtoul, and strtoull functions (p: 344-345) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.1.4 The strtol, strtoll, strtoul, and strtoull functions (p: 310-311) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.1.5 The strtol function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtol&action=edit&section=5 "Edit section: See also")] See also

[ atoiatolatoll](atoi.html "c/string/byte/atoi")(C99) |  converts a byte string to an integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_atoi&action=edit)  
---|---  
[ strtoul strtoull](strtoul.html "c/string/byte/strtoul")(C99) |  converts a byte string to an unsigned integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtoul&action=edit)  
[ wcstolwcstoll](../wide/wcstol.html "c/string/wide/wcstol")(C95)(C99) |  converts a wide string to an integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstol&action=edit)  
[ wcstoulwcstoull](../wide/wcstoul.html "c/string/wide/wcstoul")(C95)(C99) |  converts a wide string to an unsigned integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstoul&action=edit)  
[C++ documentation](../../../cpp/string/byte/strtol.html "cpp/string/byte/strtol") for strtol, strtoll  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtol&oldid=178821](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtol&oldid=178821)" 

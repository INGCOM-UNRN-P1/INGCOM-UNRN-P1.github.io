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
  
| **strtoimax strtoumax**(C99)(C99)  
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

Defined in header `[`<inttypes.h>`](../../header/inttypes.html "c/header/inttypes")` |  |   
---|---|---  
[intmax_t](../../types/integer.html) strtoimax( const char* restrict nptr,  
char** restrict endptr, int base ); |  (1)  |  (since C99)  
[uintmax_t](../../types/integer.html) strtoumax( const char* restrict nptr,  
char** restrict endptr, int base ); |  (2)  |  (since C99)  
| |   
  
Interprets an integer value in a byte string pointed to by nptr. 

Discards any whitespace characters (as identified by calling [`isspace`](isspace.html "c/string/byte/isspace")) until the first non-whitespace character is found, then takes as many characters as possible to form a valid _base-n_ (where n=`base`) integer number representation and converts them to an integer value. The valid integer value consists of the following parts: 

  * (optional) plus or minus sign 
  * (optional) prefix (`**0**`) indicating octal base (applies only when the base is 8 or ​0​) 
  * (optional) prefix (`**0x**` or `**0X**`) indicating hexadecimal base (applies only when the base is 16 or ​0​) 
  * a sequence of digits 



The set of valid values for base is `{0, 2, 3, ..., 36}`. The set of valid digits for base-`2` integers is `{0, 1}`, for base-`3` integers is `{0, 1, 2}`, and so on. For bases larger than `10`, valid digits include alphabetic characters, starting from `Aa` for base-`11` integer, to `Zz` for base-`36` integer. The case of the characters is ignored. 

Additional numeric formats may be accepted by the currently installed C [locale](../../locale/setlocale.html "c/locale/setlocale"). 

If the value of `base` is ​0​, the numeric base is auto-detected: if the prefix is `**0**`, the base is octal, if the prefix is `**0x**` or `**0X**`, the base is hexadecimal, otherwise the base is decimal. 

If the minus sign was part of the input sequence, the numeric value calculated from the sequence of digits is negated as if by [unary minus](../../language/operator_arithmetic.html#Unary_arithmetic "c/language/operator arithmetic") in the result type. 

The functions sets the pointer pointed to by endptr to point to the character past the last character interpreted. If endptr is a null pointer, it is ignored. 

If the nptr is empty or does not have the expected form, no conversion is performed, and (if endptr is not a null pointer) the value of nptr is stored in the object pointed to by endptr. 

## Contents

  * [1 Parameters](strtoimax.html#Parameters)
  * [2 Return value](strtoimax.html#Return_value)
  * [3 Example](strtoimax.html#Example)
  * [4 References](strtoimax.html#References)
  * [5 See also](strtoimax.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtoimax&action=edit&section=1 "Edit section: Parameters")] Parameters

nptr  |  \-  |  pointer to the null-terminated byte string to be interpreted   
---|---|---  
endptr  |  \-  |  pointer to a pointer to character   
base  |  \-  |  _base_ of the interpreted integer value   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtoimax&action=edit&section=2 "Edit section: Return value")] Return value

  * If successful, an integer value corresponding to the contents of `str` is returned. 
  * If the converted value falls out of range of corresponding return type, a range error occurs (setting [errno](../../error/errno.html "c/error/errno") to [ERANGE](../../error/errno_macros.html "c/error/errno macros")) and [INTMAX_MAX](../../types/integer.html "c/types/integer"), [INTMAX_MIN](../../types/integer.html "c/types/integer"), [UINTMAX_MAX](../../types/integer.html "c/types/integer") or ​0​ is returned, as appropriate. 
  * If no conversion can be performed, ​0​ is returned. 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtoimax&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <errno.h>
    #include <inttypes.h>
    #include <stdio.h>
    #include <string.h>
     
    int main(void)
    {
        char* endptr = [NULL](../../types/NULL.html);
     
        [printf](../../io/fprintf.html)("%ld\n", strtoimax(" -123junk", &endptr, 10)); // base 10
        [printf](../../io/fprintf.html)("%ld\n", strtoimax("11111111", &endptr, 2));   // base 2
        [printf](../../io/fprintf.html)("%ld\n", strtoimax("XyZ", &endptr, 36));       // base 36
        [printf](../../io/fprintf.html)("%ld\n", strtoimax("010", &endptr, 0));        // octal auto-detection
        [printf](../../io/fprintf.html)("%ld\n", strtoimax("10", &endptr, 0));         // decimal auto-detection
        [printf](../../io/fprintf.html)("%ld\n", strtoimax("0x10", &endptr, 0));       // hexadecimal auto-detection
     
        // range error: LONG_MAX+1 --> LONG_MAX
        errno = 0;
        [printf](../../io/fprintf.html)("%ld\n", strtoimax("9223372036854775808", &endptr, 10));
        [printf](../../io/fprintf.html)("%s\n", [strerror](strerror.html)(errno));
    }

Output: 
    
    
    -123
    255
    44027
    8
    10
    16
    9223372036854775807
    Numerical result out of range

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtoimax&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.8.2.3 The strtoimax and strtoumax functions (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.8.2.3 The strtoimax and strtoumax functions (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.8.2.3 The strtoimax and strtoumax functions (p: 219) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.8.2.3 The strtoimax and strtoumax functions (p: 200) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtoimax&action=edit&section=5 "Edit section: See also")] See also

[ wcstoimaxwcstoumax](../wide/wcstoimax.html "c/string/wide/wcstoimax")(C99)(C99) |  converts a wide string to [intmax_t](../../types/integer.html "c/types/integer") or [uintmax_t](../../types/integer.html "c/types/integer")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstoimax&action=edit)  
---|---  
[ strtolstrtoll](strtol.html "c/string/byte/strtol")(C99) |  converts a byte string to an integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtol&action=edit)  
[ strtoul strtoull](strtoul.html "c/string/byte/strtoul")(C99) |  converts a byte string to an unsigned integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtoul&action=edit)  
[C++ documentation](../../../cpp/string/byte/strtoimax.html "cpp/string/byte/strtoimax") for strtoimax, strtoumax  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtoimax&oldid=178835](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtoimax&oldid=178835)" 

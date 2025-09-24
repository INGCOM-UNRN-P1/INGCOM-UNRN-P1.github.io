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
| **atoi atolatoll**(C99)  
---  
[atof](atof.html "c/string/byte/atof")  
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
int atoi ( const char* str ); |  (1)  |   
long atol ( const char* str ); |  (2)  |   
long long atoll( const char* str ); |  (3)  |  (since C99)  
| |   
  
Interprets an integer value in a byte string pointed to by str. The implied radix is always 10. 

Discards any whitespace characters until the first non-whitespace character is found, then takes as many characters as possible to form a valid integer number representation and converts them to an integer value. The valid integer value consists of the following parts: 

  * (optional) plus or minus sign 
  * numeric digits 



If the value of the result cannot be represented, i.e. the converted value falls out of range of the corresponding return type, the behavior is undefined. 

## Contents

  * [1 Parameters](atoi.html#Parameters)
  * [2 Return value](atoi.html#Return_value)
  * [3 Notes](atoi.html#Notes)
  * [4 Example](atoi.html#Example)
  * [5 References](atoi.html#References)
  * [6 See also](atoi.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atoi&action=edit&section=1 "Edit section: Parameters")] Parameters

str  |  \-  |  pointer to the null-terminated byte string to be interpreted   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atoi&action=edit&section=2 "Edit section: Return value")] Return value

Integer value corresponding to the contents of str on success. 

If no conversion can be performed, ​0​ is returned. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atoi&action=edit&section=3 "Edit section: Notes")] Notes

The name stands for “ASCII to integer”. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atoi&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        [printf](../../io/fprintf.html)("%i\n", atoi(" -123junk"));
        [printf](../../io/fprintf.html)("%i\n", atoi(" +321dust"));
        [printf](../../io/fprintf.html)("%i\n", atoi("0"));
        [printf](../../io/fprintf.html)("%i\n", atoi("0042")); // treated as a decimal number with leading zeros
        [printf](../../io/fprintf.html)("%i\n", atoi("0x2A")); // only leading zero is converted discarding "x2A"
        [printf](../../io/fprintf.html)("%i\n", atoi("junk")); // no conversion can be performed
        [printf](../../io/fprintf.html)("%i\n", atoi("2147483648")); // UB: out of range of int
    }

Possible output: 
    
    
    -123
    321
    0
    42
    0
    0
    -2147483648

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atoi&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.22.1.2 The atoi, atol, and atoll functions (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.1.2 The atoi, atol, and atoll functions (p: 249) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.1.2 The atoi, atol, and atoll functions (p: 341) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.1.2 The atoi, atol, and atoll functions (p: 307) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.1.2 The atoi function 



    

  * 4.10.1.3 The atol function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atoi&action=edit&section=6 "Edit section: See also")] See also

[ strtolstrtoll](strtol.html "c/string/byte/strtol")(C99) |  converts a byte string to an integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtol&action=edit)  
---|---  
[ strtoul strtoull](strtoul.html "c/string/byte/strtoul")(C99) |  converts a byte string to an unsigned integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtoul&action=edit)  
[ wcstolwcstoll](../wide/wcstol.html "c/string/wide/wcstol")(C95)(C99) |  converts a wide string to an integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstol&action=edit)  
[ wcstoulwcstoull](../wide/wcstoul.html "c/string/wide/wcstoul")(C95)(C99) |  converts a wide string to an unsigned integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstoul&action=edit)  
[C++ documentation](../../../cpp/string/byte/atoi.html "cpp/string/byte/atoi") for atoi, atol, atoll  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atoi&oldid=181411](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/atoi&oldid=181411)" 

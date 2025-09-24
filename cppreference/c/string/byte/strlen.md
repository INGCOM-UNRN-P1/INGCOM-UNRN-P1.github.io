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
| **strlen strnlen_s**(C11)  
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

Defined in header `[`<string.h>`](../../header/string.html "c/header/string")` |  |   
---|---|---  
[size_t](../../types/size_t.html) strlen( const char* str ); |  (1)  |   
[size_t](../../types/size_t.html) strnlen_s( const char* str, [size_t](../../types/size_t.html) strsz ); |  (2)  |  (since C11)  
| |   
  
1) Returns the length of the given null-terminated byte string, that is, the number of characters in a character array whose first element is pointed to by str up to and not including the first null character.

The behavior is undefined if str is not a pointer to a null-terminated byte string.

2) Same as (1), except that the function returns zero if str is a null pointer and returns strsz if the null character was not found in the first strsz bytes of str.

The behavior is undefined if str is not a pointer to a null-terminated byte string and strsz is greater than the size of that character array. 

    As with all bounds-checked functions, `strnlen_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<string.h>`](../../header/string.html "c/header/string").

## Contents

  * [1 Parameters](strlen.html#Parameters)
  * [2 Return value](strlen.html#Return_value)
  * [3 Notes](strlen.html#Notes)
  * [4 Example](strlen.html#Example)
  * [5 References](strlen.html#References)
  * [6 See also](strlen.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strlen&action=edit&section=1 "Edit section: Parameters")] Parameters

str  |  \-  |  pointer to the null-terminated byte string to be examined   
---|---|---  
strsz  |  \-  |  maximum number of characters to examine   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strlen&action=edit&section=2 "Edit section: Return value")] Return value

1) The length of the null-terminated byte string str.

2) The length of the null-terminated byte string str on success, zero if str is a null pointer, strsz if the null character was not found.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strlen&action=edit&section=3 "Edit section: Notes")] Notes

`strnlen_s` and `wcsnlen_s` are the only [bounds-checked functions](../../error.html "c/error") that do not invoke the runtime constraints handler. They are pure utility functions used to provide limited support for non-null terminated strings. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strlen&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #define __STDC_WANT_LIB_EXT1__ 1
    #include <stdio.h>
    #include <string.h>
     
    int main(void)
    {
        const char str[] = "How many characters does this string contain?";
     
        [printf](../../io/fprintf.html)("without null character: %zu\n", strlen(str));
        [printf](../../io/fprintf.html)("with null character:    %zu\n", sizeof str);
     
    #ifdef __STDC_LIB_EXT1__
        [printf](../../io/fprintf.html)("without null character: %zu\n", strnlen_s(str, sizeof str));
    #endif
    }

Possible output: 
    
    
    without null character: 45
    with null character:    46
    without null character: 45

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strlen&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.24.6.3 The strlen function (p: TBD) 



    

  * K.3.7.4.4 The strnlen_s function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.24.6.3 The strlen function (p: TBD) 



    

  * K.3.7.4.4 The strnlen_s function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.24.6.3 The strlen function (p: 372) 



    

  * K.3.7.4.4 The strnlen_s function (p: 623) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.21.6.3 The strlen function (p: 334) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.11.6.3 The strlen function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strlen&action=edit&section=6 "Edit section: See also")] See also

[ wcslenwcsnlen_s](../wide/wcslen.html "c/string/wide/wcslen")(C95)(C11) |  returns the length of a wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcslen&action=edit)  
---|---  
[ mblen](../multibyte/mblen.html "c/string/multibyte/mblen") |  returns the number of bytes in the next multibyte character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mblen&action=edit)  
[C++ documentation](../../../cpp/string/byte/strlen.html "cpp/string/byte/strlen") for strlen  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strlen&oldid=172378](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strlen&oldid=172378)" 

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
| [strlenstrnlen_s](strlen.html "c/string/byte/strlen")(C11)  
---  
[strcmp](strcmp.html "c/string/byte/strcmp")  
[strncmp](strncmp.html "c/string/byte/strncmp")  
[strcoll](strcoll.html "c/string/byte/strcoll")  
**strchr**  
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
char* strchr( const char* str, int ch ); |  (1)  |   
/*QChar*/ *strchr( /*QChar*/ *str, int ch ); |  (2)  |  (since C23)  
| |   
  
1) Finds the first occurrence of ch (after conversion to char as if by (char)ch) in the null-terminated byte string pointed to by str (each character interpreted as unsigned char). The terminating null character is considered to be a part of the string and can be found when searching for '\0'.

2) Type-generic function equivalent to (1). Let `T` be an unqualified character object type. 

    

  * If `str` is of type const T*, the return type is const char*. 
  * Otherwise, if `str` is of type T*, the return type is char*. 
  * Otherwise, the behavior is undefined. 


If a macro definition of each of these generic functions is suppressed to access an actual function (e.g. if (strchr) or a function pointer is used), the actual function declaration (1) becomes visible.

The behavior is undefined if str is not a pointer to a null-terminated byte string. 

## Contents

  * [1 Parameters](strchr.html#Parameters)
  * [2 Return value](strchr.html#Return_value)
  * [3 Example](strchr.html#Example)
  * [4 References](strchr.html#References)
  * [5 See also](strchr.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strchr&action=edit&section=1 "Edit section: Parameters")] Parameters

str  |  \-  |  pointer to the null-terminated byte string to be analyzed   
---|---|---  
ch  |  \-  |  character to search for   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strchr&action=edit&section=2 "Edit section: Return value")] Return value

Pointer to the found character in str, or null pointer if no such character is found. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strchr&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <string.h>
     
    int main(void)
    {
        const char *str = "Try not. Do, or do not. There is no try.";
        char target = 'T';
        const char* result = str;
     
        while((result = strchr(result, target)) != [NULL](../../types/NULL.html))
        {
            [printf](../../io/fprintf.html)("Found '%c' starting at '%s'\n", target, result);
            ++result; // Increment result, otherwise we'll find target at the same location
        }
    }

Output: 
    
    
    Found 'T' starting at 'Try not. Do, or do not. There is no try.'
    Found 'T' starting at 'There is no try.'

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strchr&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.24.5.2 The strchr function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.24.5.2 The strchr function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.24.5.2 The strchr function (p: 367-368) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.21.5.2 The strchr function (p: 330) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.11.5.2 The strchr function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strchr&action=edit&section=5 "Edit section: See also")] See also

[ memchr](memchr.html "c/string/byte/memchr") |  searches an array for the first occurrence of a character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memchr&action=edit)  
---|---  
[ strrchr](strrchr.html "c/string/byte/strrchr") |  finds the last occurrence of a character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strrchr&action=edit)  
[ strpbrk](strpbrk.html "c/string/byte/strpbrk") |  finds the first location of any character in one string, in another string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strpbrk&action=edit)  
[C++ documentation](../../../cpp/string/byte/strchr.html "cpp/string/byte/strchr") for strchr  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strchr&oldid=172154](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strchr&oldid=172154)" 

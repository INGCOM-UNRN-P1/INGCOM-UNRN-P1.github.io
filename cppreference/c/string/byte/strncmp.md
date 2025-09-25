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
**strncmp**  
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
int strncmp( const char* lhs, const char* rhs, [size_t](../../types/size_t.html) count ); |  |   
| |   
  
Compares at most count characters of two possibly null-terminated arrays. The comparison is done lexicographically. Characters following the null character are not compared. 

The sign of the result is the sign of the difference between the values of the first pair of characters (both interpreted as unsigned char) that differ in the arrays being compared. 

The behavior is undefined when access occurs past the end of either array lhs or rhs. The behavior is undefined when either lhs or rhs is the null pointer. 

## Contents

  * [1 Parameters](strncmp.html#Parameters)
  * [2 Return value](strncmp.html#Return_value)
  * [3 Notes](strncmp.html#Notes)
  * [4 Example](strncmp.html#Example)
  * [5 References](strncmp.html#References)
  * [6 See also](strncmp.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncmp&action=edit&section=1 "Edit section: Parameters")] Parameters

lhs, rhs  |  \-  |  pointers to the possibly null-terminated arrays to compare   
---|---|---  
count  |  \-  |  maximum number of characters to compare   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncmp&action=edit&section=2 "Edit section: Return value")] Return value

Negative value if lhs appears before rhs in lexicographical order. 

Zero if lhs and rhs compare equal, or if count is zero. 

Positive value if lhs appears after rhs in lexicographical order. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncmp&action=edit&section=3 "Edit section: Notes")] Notes

This function is not locale-sensitive, unlike [strcoll](strcoll.html "c/string/byte/strcoll") and [strxfrm](strxfrm.html "c/string/byte/strxfrm"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncmp&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <string.h>
     
    void demo(const char* lhs, const char* rhs, int sz)
    {
        const int rc = strncmp(lhs, rhs, sz);
        if (rc < 0)
            [printf](../../io/fprintf.html)("First %d chars of [%s] precede [%s]\n", sz, lhs, rhs);
        else if (rc > 0)
            [printf](../../io/fprintf.html)("First %d chars of [%s] follow [%s]\n", sz, lhs, rhs);
        else
            [printf](../../io/fprintf.html)("First %d chars of [%s] equal [%s]\n", sz, lhs, rhs);
    }
    int main(void)
    {
        const char* string = "Hello World!";
        demo(string, "Hello!", 5);
        demo(string, "Hello", 10);
        demo(string, "Hello there", 10);
        demo("Hello, everybody!" + 12, "Hello, somebody!" + 11, 5);
    }

Output: 
    
    
    First 5 chars of [Hello World!] equal [Hello!]
    First 10 chars of [Hello World!] follow [Hello]
    First 10 chars of [Hello World!] precede [Hello there]
    First 5 chars of [body!] equal [body!]

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncmp&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.24.4.4 The strncmp function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.24.4.4 The strncmp function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.24.4.4 The strncmp function (p: 366) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.21.4.4 The strncmp function (p: 329) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.11.4.4 The strncmp function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncmp&action=edit&section=6 "Edit section: See also")] See also

[ strcmp](strcmp.html "c/string/byte/strcmp") |  compares two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcmp&action=edit)  
---|---  
[ wcsncmp](../wide/wcsncmp.html "c/string/wide/wcsncmp")(C95) |  compares a certain amount of characters from two wide strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsncmp&action=edit)  
[ memcmp](memcmp.html "c/string/byte/memcmp") |  compares two buffers   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memcmp&action=edit)  
[ strcoll](strcoll.html "c/string/byte/strcoll") |  compares two strings in accordance to the current locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcoll&action=edit)  
[C++ documentation](../../../cpp/string/byte/strncmp.html "cpp/string/byte/strncmp") for strncmp  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncmp&oldid=153460](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncmp&oldid=153460)" 

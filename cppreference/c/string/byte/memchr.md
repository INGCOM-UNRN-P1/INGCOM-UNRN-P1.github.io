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
[strchr](strchr.html "c/string/byte/strchr")  
[strrchr](strrchr.html "c/string/byte/strrchr")  
  
| [strspn](strspn.html "c/string/byte/strspn")  
---  
[strcspn](strcspn.html "c/string/byte/strcspn")  
[strpbrk](strpbrk.html "c/string/byte/strpbrk")  
[strstr](strstr.html "c/string/byte/strstr")  
[strtokstrtok_s](strtok.html "c/string/byte/strtok")(C11)  
  
  
  
Memory manipulation  
| **memchr**  
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
void* memchr( const void* ptr, int ch, [size_t](../../types/size_t.html) count ); |  (1)  |   
/*QVoid*/ *memchr( /*QVoid*/ *ptr, int ch, [size_t](../../types/size_t.html) count ); |  (2)  |  (since C23)  
| |   
  
1) Finds the first occurrence of (unsigned char)ch in the initial count bytes (each interpreted as unsigned char) of the object pointed to by ptr.

2) Type-generic function equivalent to (1). Let `T` be an unqualified object type (including void). 

    

  * If `ptr` is of type const T*, the return type is const void*. 
  * Otherwise, if `ptr` is of type T*, the return type is void*. 
  * Otherwise, the behavior is undefined. 


If a macro definition of each of these generic functions is suppressed to access an actual function (e.g. if (memchr) or a function pointer is used), the actual function declaration (1) becomes visible.

The behavior is undefined if access occurs beyond the end of the array searched. The behavior is undefined if ptr is a null pointer. 

This function behaves as if it reads the bytes sequentially and stops as soon as a matching bytes is found: if the array pointed to by ptr is smaller than count, but the match is found within the array, the behavior is well-defined.  | (since C11)  
---|---  
  
## Contents

  * [1 Parameters](memchr.html#Parameters)
  * [2 Return value](memchr.html#Return_value)
  * [3 Example](memchr.html#Example)
  * [4 References](memchr.html#References)
  * [5 See also](memchr.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memchr&action=edit&section=1 "Edit section: Parameters")] Parameters

ptr  |  \-  |  pointer to the object to be examined   
---|---|---  
ch  |  \-  |  bytes to search for   
count  |  \-  |  max number of bytes to examine   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memchr&action=edit&section=2 "Edit section: Return value")] Return value

Pointer to the location of the byte, or a null pointer if no such byte is found. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memchr&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <string.h>
     
    int main(void)
    {
        const char str[] = "ABCDEFG";
        const int chars[] = {'D', 'd'};
        for ([size_t](../../types/size_t.html) i = 0; i < sizeof chars / (sizeof chars[0]); ++i)
        {
            const int c = chars[i];
            const char *ps = memchr(str, c, [strlen](strlen.html)(str));
            ps ? [printf](../../io/fprintf.html) ("character '%c'(%i) found: %s\n", c, c, ps)
               : [printf](../../io/fprintf.html) ("character '%c'(%i) not found\n", c, c);
        }
        return 0;
    }

Possible output: 
    
    
    character 'D'(68) found: DEFG
    character 'd'(100) not found

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memchr&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.24.5.1 The memchr function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.24.5.1 The memchr function (p: 267-268) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.24.5.1 The memchr function (p: 367) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.21.5.1 The memchr function (p: 330) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.11.5.1 The memchr function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memchr&action=edit&section=5 "Edit section: See also")] See also

[ strchr](strchr.html "c/string/byte/strchr") |  finds the first occurrence of a character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strchr&action=edit)  
---|---  
[C++ documentation](../../../cpp/string/byte/memchr.html "cpp/string/byte/memchr") for memchr  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memchr&oldid=172141](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memchr&oldid=172141)" 

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
| [memchr](memchr.html "c/string/byte/memchr")  
---  
**memcmp**  
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
int memcmp( const void* lhs, const void* rhs, [size_t](../../types/size_t.html) count ); |  |   
| |   
  
Compares the first count bytes of the objects pointed to by lhs and rhs. The comparison is done lexicographically. 

The sign of the result is the sign of the difference between the values of the first pair of bytes (both interpreted as unsigned char) that differ in the objects being compared. 

The behavior is undefined if access occurs beyond the end of either object pointed to by lhs and rhs. The behavior is undefined if either lhs or rhs is a null pointer. 

## Contents

  * [1 Parameters](memcmp.html#Parameters)
  * [2 Return value](memcmp.html#Return_value)
  * [3 Notes](memcmp.html#Notes)
  * [4 Example](memcmp.html#Example)
  * [5 References](memcmp.html#References)
  * [6 See also](memcmp.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcmp&action=edit&section=1 "Edit section: Parameters")] Parameters

lhs, rhs  |  \-  |  pointers to the objects to compare   
---|---|---  
count  |  \-  |  number of bytes to examine   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcmp&action=edit&section=2 "Edit section: Return value")] Return value

Negative value if lhs appears before rhs in lexicographical order. 

Zero if lhs and rhs compare equal, or if count is zero. 

Positive value if lhs appears after rhs in lexicographical order. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcmp&action=edit&section=3 "Edit section: Notes")] Notes

This function reads [object representations](../../language/object.html "c/language/object"), not the object values, and is typically meaningful for byte arrays only: structs may have padding bytes whose values are indeterminate, the values of any bytes beyond the last stored member in a union are indeterminate, and a type may have two or more representations for the same value (different encodings for +0 and -0 or for +0.0 and –0.0, indeterminate padding bits within the type). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcmp&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <string.h>
     
    void demo(const char* lhs, const char* rhs, [size_t](../../types/size_t.html) sz)
    {
        for([size_t](../../types/size_t.html) n = 0; n < sz; ++n)
            [putchar](../../io/putchar.html)(lhs[n]);
     
        int rc = memcmp(lhs, rhs, sz);
        const char *rel = rc < 0 ? " precedes " : rc > 0 ? " follows " : " compares equal ";
        [fputs](../../io/fputs.html)(rel, [stdout](../../io/std_streams.html));
     
        for([size_t](../../types/size_t.html) n = 0; n < sz; ++n)
            [putchar](../../io/putchar.html)(rhs[n]);
        [puts](../../io/puts.html)(" in lexicographical order");
    }
     
    int main(void)
    {
        char a1[] = {'a','b','c'};
        char a2[sizeof a1] = {'a','b','d'};
     
        demo(a1, a2, sizeof a1);
        demo(a2, a1, sizeof a1);
        demo(a1, a1, sizeof a1);
    }

Output: 
    
    
    abc precedes abd in lexicographical order
    abd follows abc in lexicographical order
    abc compares equal to abc in lexicographical order

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcmp&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.24.4.1 The memcmp function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.24.4.1 The memcmp function (p: 266) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.24.4.1 The memcmp function (p: 365) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.21.4.1 The memcmp function (p: 328) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.11.4.1 The memcmp function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcmp&action=edit&section=6 "Edit section: See also")] See also

[ strcmp](strcmp.html "c/string/byte/strcmp") |  compares two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcmp&action=edit)  
---|---  
[ strncmp](strncmp.html "c/string/byte/strncmp") |  compares a certain amount of characters of two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strncmp&action=edit)  
[C++ documentation](../../../cpp/string/byte/memcmp.html "cpp/string/byte/memcmp") for memcmp  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcmp&oldid=172142](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcmp&oldid=172142)" 

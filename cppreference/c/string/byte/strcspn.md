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
**strcspn**  
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
[size_t](../../types/size_t.html) strcspn( const char *dest, const char *src ); |  |   
| |   
  
Returns the length of the maximum initial segment of the null-terminated byte string pointed to by `dest`, that consists of only the characters _not_ found in the null-terminated byte string pointed to by `src`. 

The behavior is undefined if either `dest` or `src` is not a pointer to a null-terminated byte string. 

## Contents

  * [1 Parameters](strcspn.html#Parameters)
  * [2 Return value](strcspn.html#Return_value)
  * [3 Notes](strcspn.html#Notes)
  * [4 Example](strcspn.html#Example)
  * [5 References](strcspn.html#References)
  * [6 See also](strcspn.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcspn&action=edit&section=1 "Edit section: Parameters")] Parameters

dest  |  \-  |  pointer to the null-terminated byte string to be analyzed   
---|---|---  
src  |  \-  |  pointer to the null-terminated byte string that contains the characters to search for   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcspn&action=edit&section=2 "Edit section: Return value")] Return value

The length of the maximum initial segment that contains only characters not found in the null-terminated byte string pointed to by `src`

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcspn&action=edit&section=3 "Edit section: Notes")] Notes

The function name stands for "complementary span" because the function searches for characters not found in `src`, that is the complement of `src`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcspn&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <string.h>
    #include <stdio.h>
     
    int main(void)
    {
        const char *string = "abcde312$#@";
        const char *invalid = "*$#";
     
        [size_t](../../types/size_t.html) valid_len = strcspn(string, invalid);
        if(valid_len != [strlen](strlen.html)(string))
           [printf](../../io/fprintf.html)("'%s' contains invalid chars starting at position %zu\n",
                   string, valid_len);
    }

Output: 
    
    
    'abcde312$#@' contains invalid chars starting at position 8

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcspn&action=edit&section=5 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.24.5.3 The strcspn function (p: 368) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.21.5.3 The strcspn function (p: 331) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.11.5.3 The strcspn function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcspn&action=edit&section=6 "Edit section: See also")] See also

[ strspn](strspn.html "c/string/byte/strspn") |  returns the length of the maximum initial segment that consists   
of only the characters found in another byte string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strspn&action=edit)  
---|---  
[ wcscspn](../wide/wcscspn.html "c/string/wide/wcscspn")(C95) |  returns the length of the maximum initial segment that consists   
of only the wide chars _not_ found in another wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcscspn&action=edit)  
[ strpbrk](strpbrk.html "c/string/byte/strpbrk") |  finds the first location of any character in one string, in another string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strpbrk&action=edit)  
[C++ documentation](../../../cpp/string/byte/strcspn.html "cpp/string/byte/strcspn") for strcspn  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcspn&oldid=89169](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcspn&oldid=89169)" 

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
**strxfrm**  
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

Defined in header `[`<string.h>`](../../header/string.html "c/header/string")` |  |   
---|---|---  
[size_t](../../types/size_t.html) strxfrm( char *dest, const char *src, [size_t](../../types/size_t.html) count ); |  |  (until C99)  
[size_t](../../types/size_t.html) strxfrm( char *restrict dest, const char *restrict src, [size_t](../../types/size_t.html) count ); |  |  (since C99)  
| |   
  
Transforms the null-terminated byte string pointed to by `src` into the implementation-defined form such that comparing two transformed strings with [strcmp](strcmp.html "c/string/byte/strcmp") gives the same result as comparing the original strings with [strcoll](strcoll.html "c/string/byte/strcoll"), in the current C locale. 

The first `count` characters of the transformed string are written to destination, including the terminating null character, and the length of the full transformed string is returned, excluding the terminating null character. 

The behavior is undefined if the `dest` array is not large enough. The behavior is undefined if `dest` and `src` overlap. 

If `count` is ​0​, then `dest` is allowed to be a null pointer. 

## Contents

  * [1 Notes](strxfrm.html#Notes)
  * [2 Parameters](strxfrm.html#Parameters)
  * [3 Return value](strxfrm.html#Return_value)
  * [4 Example](strxfrm.html#Example)
  * [5 References](strxfrm.html#References)
  * [6 See also](strxfrm.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strxfrm&action=edit&section=1 "Edit section: Notes")] Notes

The correct length of the buffer that can receive the entire transformed string is 1+strxfrm([NULL](../../types/NULL.html), src, 0)

This function is used when making multiple locale-dependent comparisons using the same string or set of strings, because it is more efficient to use `strxfrm` to transform all the strings just once, and subsequently compare the transformed strings with [strcmp](strcmp.html "c/string/byte/strcmp"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strxfrm&action=edit&section=2 "Edit section: Parameters")] Parameters

dest  |  \-  |  pointer to the first element of the array where the transformed string will be written   
---|---|---  
src  |  \-  |  pointer to the first character of a null-terminated byte string to transform   
count  |  \-  |  maximum number of characters to be written   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strxfrm&action=edit&section=3 "Edit section: Return value")] Return value

The length of the transformed string, not including the terminating null-character. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strxfrm&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <string.h>
    #include <locale.h>
     
    int main(void)
    {
        [setlocale](../../locale/setlocale.html)([LC_COLLATE](../../locale/LC_categories.html), "cs_CZ.iso88592");
     
        const char *in1 = "hrnec";
        char out1[1+strxfrm([NULL](../../types/NULL.html), in1, 0)];
        strxfrm(out1, in1, sizeof out1);
     
        const char *in2 = "chrt";
        char out2[1+strxfrm([NULL](../../types/NULL.html), in2, 0)];
        strxfrm(out2, in2, sizeof out2);
     
        [printf](../../io/fprintf.html)("In the Czech locale: ");
        if([strcmp](strcmp.html)(out1, out2) < 0)
             [printf](../../io/fprintf.html)("%s before %s\n",in1, in2);
        else
             [printf](../../io/fprintf.html)("%s before %s\n",in2, in1);
     
        [printf](../../io/fprintf.html)("In lexicographical comparison: ");
        if([strcmp](strcmp.html)(in1, in2)<0)
             [printf](../../io/fprintf.html)("%s before %s\n",in1, in2);
        else
             [printf](../../io/fprintf.html)("%s before %s\n",in2, in1);
     
    }

Possible output: 
    
    
    In the Czech locale: hrnec before chrt
    In lexicographical comparison: chrt before hrnec

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strxfrm&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.24.4.5 The strxfrm function (p: 267) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.24.4.5 The strxfrm function (p: 366-367) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.21.4.5 The strxfrm function (p: 329-330) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.11.4.5 The strxfrm function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strxfrm&action=edit&section=6 "Edit section: See also")] See also

[ strcoll](strcoll.html "c/string/byte/strcoll") |  compares two strings in accordance to the current locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcoll&action=edit)  
---|---  
[ wcscoll](../wide/wcscoll.html "c/string/wide/wcscoll")(C95) |  compares two wide strings in accordance to the current locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcscoll&action=edit)  
[ strcmp](strcmp.html "c/string/byte/strcmp") |  compares two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcmp&action=edit)  
[ wcsxfrm](../wide/wcsxfrm.html "c/string/wide/wcsxfrm")(C95) |  transform a wide string so that [wcscmp](../wide/wcscmp.html "c/string/wide/wcscmp") would produce the same result as [wcscoll](../wide/wcscoll.html "c/string/wide/wcscoll")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsxfrm&action=edit)  
[C++ documentation](../../../cpp/string/byte/strxfrm.html "cpp/string/byte/strxfrm") for strxfrm  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strxfrm&oldid=134743](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strxfrm&oldid=134743)" 

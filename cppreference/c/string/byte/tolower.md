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
**tolower**  
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
[memcmp](memcmp.html "c/string/byte/memcmp")  
[memsetmemset_explicitmemset_s](memset.html "c/string/byte/memset")(C23)(C11)  
  
| [memcpymemcpy_s](memcpy.html "c/string/byte/memcpy")(C11)  
---  
[memmovememmove_s](memmove.html "c/string/byte/memmove")(C11)  
[memccpy](memccpy.html "c/string/byte/memccpy")(C23)  
  
Miscellaneous  
[strerrorstrerror_sstrerrorlen_s](strerror.html "c/string/byte/strerror")(C11)(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/navbar_content&action=edit)

Defined in header `[`<ctype.h>`](../../header/ctype.html "c/header/ctype")` |  |   
---|---|---  
int tolower( int ch ); |  |   
| |   
  
Converts the given character to lowercase according to the character conversion rules defined by the currently installed C locale. 

In the default "C" locale, the following uppercase letters `ABCDEFGHIJKLMNOPQRSTUVWXYZ` are replaced with respective lowercase letters `abcdefghijklmnopqrstuvwxyz`. 

## Contents

  * [1 Parameters](tolower.html#Parameters)
  * [2 Return value](tolower.html#Return_value)
  * [3 Example](tolower.html#Example)
  * [4 References](tolower.html#References)
  * [5 See also](tolower.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/tolower&action=edit&section=1 "Edit section: Parameters")] Parameters

ch  |  \-  |  character to be converted. If the value of ch is not representable as unsigned char and does not equal [EOF](../../io.html), the behavior is undefined.   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/tolower&action=edit&section=2 "Edit section: Return value")] Return value

Lowercase version of ch or unmodified ch if no lowercase version is listed in the current C locale. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/tolower&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <ctype.h>
    #include <limits.h>
    #include <locale.h>
    #include <stdio.h>
     
    int main(void)
    {
        // In the default locale
        for (unsigned char u = 0; u < [UCHAR_MAX](../../types/limits.html); u++)
        {
            unsigned char l = tolower(u);
            if (l != u)
                [printf](../../io/fprintf.html)("%c%c ", u, l);
        }
        [printf](../../io/fprintf.html)("\n\n");
     
        unsigned char c = '\xb4'; // the character Ž in ISO-8859-15
                                  // but ´ (acute accent) in ISO-8859-1
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.iso88591");
        [printf](../../io/fprintf.html)("in iso8859-1, tolower('0x%x') gives 0x%x\n", c, tolower(c));
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.iso885915");
        [printf](../../io/fprintf.html)("in iso8859-15, tolower('0x%x') gives 0x%x\n", c, tolower(c));
    }

Possible output: 
    
    
    Aa Bb Cc Dd Ee Ff Gg Hh Ii Jj Kk Ll Mm Nn Oo Pp Qq Rr Ss Tt Uu Vv Ww Xx Yy Zz
     
    in iso8859-1, tolower('0xb4') gives 0xb4
    in iso8859-15, tolower('0xb4') gives 0xb8

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/tolower&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.4.2.1 The tolower function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.4.2.1 The tolower function (p: 147) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.4.2.1 The tolower function (p: 203) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.4.2.1 The tolower function (p: 184) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.3.2.1 The tolower function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/tolower&action=edit&section=5 "Edit section: See also")] See also

[ toupper](toupper.html "c/string/byte/toupper") |  converts a character to uppercase   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_toupper&action=edit)  
---|---  
[ towlower](../wide/towlower.html "c/string/wide/towlower")(C95) |  converts a wide character to lowercase   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_towlower&action=edit)  
[C++ documentation](../../../cpp/string/byte/tolower.html "cpp/string/byte/tolower") for tolower  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/tolower&oldid=181286](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/tolower&oldid=181286)" 

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
**ispunct**  
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
int ispunct( int ch ); |  |   
| |   
  
Checks if the given character is a punctuation character in the current C locale. The default C locale classifies the characters `!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~` as punctuation. 

The behavior is undefined if the value of ch is not representable as unsigned char and is not equal to [EOF](../../io.html). 

## Contents

  * [1 Parameters](ispunct.html#Parameters)
  * [2 Return value](ispunct.html#Return_value)
  * [3 Example](ispunct.html#Example)
  * [4 References](ispunct.html#References)
  * [5 See also](ispunct.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/ispunct&action=edit&section=1 "Edit section: Parameters")] Parameters

ch  |  \-  |  character to classify   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/ispunct&action=edit&section=2 "Edit section: Return value")] Return value

Non-zero value if the character is a punctuation character, zero otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/ispunct&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <ctype.h>
    #include <locale.h>
    #include <stdio.h>
     
    int main(void)
    {
        unsigned char c = '\xd7'; // the character × (multiplication sign) in ISO-8859-1
        [printf](../../io/fprintf.html)("In the default C locale, \\xd7 is %spunctuation\n",
               ispunct(c) ? "" : "not " );
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_GB.iso88591");
        [printf](../../io/fprintf.html)("In ISO-8859-1 locale, \\xd7 is %spunctuation\n",
               ispunct(c) ? "" : "not " );
    }

Possible output: 
    
    
    In the default C locale, \xd7 is not punctuation
    In ISO-8859-1 locale, \xd7 is punctuation

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/ispunct&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.4.1.9 The ispunct function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.4.1.9 The ispunct function (p: 146) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.4.1.9 The ispunct function (p: 202) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.4.1.9 The ispunct function (p: 183) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.3.1.8 The ispunct function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/ispunct&action=edit&section=5 "Edit section: See also")] See also

[ iswpunct](../wide/iswpunct.html "c/string/wide/iswpunct")(C95) |  checks if a wide character is a punctuation character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswpunct&action=edit)  
---|---  
[C++ documentation](../../../cpp/string/byte/ispunct.html "cpp/string/byte/ispunct") for ispunct  
ASCII values  | characters  |  [`iscntrl`](iscntrl.html "c/string/byte/iscntrl")  
[`iswcntrl`](../wide/iswcntrl.html "c/string/wide/iswcntrl") |  [`isprint`](isprint.html "c/string/byte/isprint")  
[`iswprint`](../wide/iswprint.html "c/string/wide/iswprint") |  [`isspace`](isspace.html "c/string/byte/isspace")  
[`iswspace`](../wide/iswspace.html "c/string/wide/iswspace") |  [`isblank`](isblank.html "c/string/byte/isblank")  
[`iswblank`](../wide/iswblank.html "c/string/wide/iswblank") |  [`isgraph`](isgraph.html "c/string/byte/isgraph")  
[`iswgraph`](../wide/iswgraph.html "c/string/wide/iswgraph") |  **`ispunct`**   
[`iswpunct`](../wide/iswpunct.html "c/string/wide/iswpunct") |  [`isalnum`](isalnum.html "c/string/byte/isalnum")   
[`iswalnum`](../wide/iswalnum.html "c/string/wide/iswalnum") |  [`isalpha`](isalpha.html "c/string/byte/isalpha")   
[`iswalpha`](../wide/iswalpha.html "c/string/wide/iswalpha") |  [`isupper`](isupper.html "c/string/byte/isupper")  
[`iswupper`](../wide/iswupper.html "c/string/wide/iswupper") |  [`islower`](islower.html "c/string/byte/islower")  
[`iswlower`](../wide/iswlower.html "c/string/wide/iswlower") |  [`isdigit`](isdigit.html "c/string/byte/isdigit")  
[`iswdigit`](../wide/iswdigit.html "c/string/wide/iswdigit") |  [`isxdigit`](isxdigit.html "c/string/byte/isxdigit")  
[`iswxdigit`](../wide/iswxdigit.html "c/string/wide/iswxdigit")  
---|---|---|---|---|---|---|---|---|---|---|---|---|---  
decimal  |  hexadecimal  |  octal   
0–8  | `\x0`–`\x8` | `\0`–`\10` | control codes (`NUL`, etc.)  | **`≠0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`**  
9  | `\x9` | `\11` | tab (`\t`)  | **`≠0`** |  **`0`** | **`≠0`** | **`≠0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`**  
10–13  | `\xA`–`\xD` | `\12`–`\15` | whitespaces (`\n`, `\v`, `\f`, `\r`)  | **`≠0`** |  **`0`** | **`≠0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`**  
14–31  | `\xE`–`\x1F` | `\16`–`\37` | control codes  | **`≠0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`**  
32  | `\x20` | `\40` | space  |  **`0`** | **`≠0`** | **`≠0`** | **`≠0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`**  
33–47  | `\x21`–`\x2F` | `\41`–`\57` | `!"#$%&'()*+,-./` |  **`0`** | **`≠0`** |  **`0`** |  **`0`** | **`≠0`** | **`≠0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`**  
48–57  | `\x30`–`\x39` | `\60`–`\71` | `0123456789` |  **`0`** | **`≠0`** |  **`0`** |  **`0`** | **`≠0`** |  **`0`** | **`≠0`** |  **`0`** |  **`0`** |  **`0`** | **`≠0`** | **`≠0`**  
58–64  | `\x3A`–`\x40` | `\72`–`\100` | `:;<=>?@` |  **`0`** | **`≠0`** |  **`0`** |  **`0`** | **`≠0`** | **`≠0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`**  
65–70  | `\x41`–`\x46` | `\101`–`\106` | `ABCDEF` |  **`0`** | **`≠0`** |  **`0`** |  **`0`** | **`≠0`** |  **`0`** | **`≠0`** | **`≠0`** | **`≠0`** |  **`0`** |  **`0`** | **`≠0`**  
71–90  | `\x47`–`\x5A` | `\107`–`\132` | `GHIJKLMNOP`  
`QRSTUVWXYZ` |  **`0`** | **`≠0`** |  **`0`** |  **`0`** | **`≠0`** |  **`0`** | **`≠0`** | **`≠0`** | **`≠0`** |  **`0`** |  **`0`** |  **`0`**  
91–96  | `\x5B`–`\x60` | `\133`–`\140` | `[\]^_`` |  **`0`** | **`≠0`** |  **`0`** |  **`0`** | **`≠0`** | **`≠0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`**  
97–102  | `\x61`–`\x66` | `\141`–`\146` | `abcdef` |  **`0`** | **`≠0`** |  **`0`** |  **`0`** | **`≠0`** |  **`0`** | **`≠0`** | **`≠0`** |  **`0`** | **`≠0`** |  **`0`** | **`≠0`**  
103–122  | `\x67`–`\x7A` | `\147`–`\172` | `ghijklmnop`  
`qrstuvwxyz` |  **`0`** | **`≠0`** |  **`0`** |  **`0`** | **`≠0`** |  **`0`** | **`≠0`** | **`≠0`** |  **`0`** | **`≠0`** |  **`0`** |  **`0`**  
123–126  | `\x7B`–`\x7E` | `\173`–`\176` | `{|}~` |  **`0`** | **`≠0`** |  **`0`** |  **`0`** | **`≠0`** | **`≠0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`**  
127  | `\x7F` | `\177` | backspace character (`DEL`)  | **`≠0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`** |  **`0`**  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/ispunct&oldid=181285](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/ispunct&oldid=181285)" 

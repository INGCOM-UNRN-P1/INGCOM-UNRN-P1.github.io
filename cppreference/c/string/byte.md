From cppreference.com

< [c](../../c.html "c")‎ | [string](../string.html "c/string")

[ C](../../c.html "c")

[Compiler support](../compiler_support.html "c/compiler support")  
---  
[Language](../language.html "c/language")  
[Headers](../header.html "c/header")  
[Type support](../types.html "c/types")  
[Program utilities](../program.html "c/program")  
[Variadic function support](../variadic.html "c/variadic")  
[Error handling](../error.html "c/error")  
[Dynamic memory management](../memory.html "c/memory")  
[Strings library](../string.html "c/string")  
[Algorithms](../algorithm.html "c/algorithm")  
[Numerics](../numeric.html "c/numeric")  
[Date and time utilities](../chrono.html "c/chrono")  
[Input/output support](../io.html "c/io")  
[Localization support](../locale.html "c/locale")  
[Concurrency support](../thread.html "c/thread") (C11)  
[Technical Specifications](../experimental.html "c/experimental")  
[Symbol index](../index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

[ Strings library](../string.html "c/string")

**Null-terminated byte strings**  
---  
[Null-terminated multibyte strings](multibyte.html "c/string/multibyte")  
[Null-terminated wide strings](wide.html "c/string/wide")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/navbar_content&action=edit)

**Null-terminated byte strings**

Functions  
---  
Character manipulation  
| [isalnum](byte/isalnum.html "c/string/byte/isalnum")  
---  
[isalpha](byte/isalpha.html "c/string/byte/isalpha")  
[islower](byte/islower.html "c/string/byte/islower")  
[isupper](byte/isupper.html "c/string/byte/isupper")  
[isdigit](byte/isdigit.html "c/string/byte/isdigit")  
[isxdigit](byte/isxdigit.html "c/string/byte/isxdigit")  
[isblank](byte/isblank.html "c/string/byte/isblank")(C99)  
  
| [iscntrl](byte/iscntrl.html "c/string/byte/iscntrl")  
---  
[isgraph](byte/isgraph.html "c/string/byte/isgraph")  
[isspace](byte/isspace.html "c/string/byte/isspace")  
[isprint](byte/isprint.html "c/string/byte/isprint")  
[ispunct](byte/ispunct.html "c/string/byte/ispunct")  
[tolower](byte/tolower.html "c/string/byte/tolower")  
[toupper](byte/toupper.html "c/string/byte/toupper")  
  
Conversions to and from numeric formats  
| [atoiatolatoll](byte/atoi.html "c/string/byte/atoi")(C99)  
---  
[atof](byte/atof.html "c/string/byte/atof")  
[strtolstrtoll](byte/strtol.html "c/string/byte/strtol")(C99)  
[strtoulstrtoull](byte/strtoul.html "c/string/byte/strtoul")(C99)  
  
| [strtoimaxstrtoumax](byte/strtoimax.html "c/string/byte/strtoimax")(C99)(C99)  
---  
[strtofstrtodstrtold](byte/strtof.html "c/string/byte/strtof")(C99)(C99)  
[strfromfstrfromdstrfroml](byte/strfromf.html "c/string/byte/strfromf")(C23)(C23)(C23)  
  
String manipulation  
| [strcpystrcpy_s](byte/strcpy.html "c/string/byte/strcpy")(C11)  
---  
[strncpystrncpy_s](byte/strncpy.html "c/string/byte/strncpy")(C11)  
[strcatstrcat_s](byte/strcat.html "c/string/byte/strcat")(C11)  
  
| [strncatstrncat_s](byte/strncat.html "c/string/byte/strncat")(C11)  
---  
[strxfrm](byte/strxfrm.html "c/string/byte/strxfrm")  
[strdup](byte/strdup.html "c/string/byte/strdup")(C23)  
[strndup](byte/strndup.html "c/string/byte/strndup")(C23)  
  
  
  
String examination  
| [strlenstrnlen_s](byte/strlen.html "c/string/byte/strlen")(C11)  
---  
[strcmp](byte/strcmp.html "c/string/byte/strcmp")  
[strncmp](byte/strncmp.html "c/string/byte/strncmp")  
[strcoll](byte/strcoll.html "c/string/byte/strcoll")  
[strchr](byte/strchr.html "c/string/byte/strchr")  
[strrchr](byte/strrchr.html "c/string/byte/strrchr")  
  
| [strspn](byte/strspn.html "c/string/byte/strspn")  
---  
[strcspn](byte/strcspn.html "c/string/byte/strcspn")  
[strpbrk](byte/strpbrk.html "c/string/byte/strpbrk")  
[strstr](byte/strstr.html "c/string/byte/strstr")  
[strtokstrtok_s](byte/strtok.html "c/string/byte/strtok")(C11)  
  
  
  
Memory manipulation  
| [memchr](byte/memchr.html "c/string/byte/memchr")  
---  
[memcmp](byte/memcmp.html "c/string/byte/memcmp")  
[memsetmemset_explicitmemset_s](byte/memset.html "c/string/byte/memset")(C23)(C11)  
  
| [memcpymemcpy_s](byte/memcpy.html "c/string/byte/memcpy")(C11)  
---  
[memmovememmove_s](byte/memmove.html "c/string/byte/memmove")(C11)  
[memccpy](byte/memccpy.html "c/string/byte/memccpy")(C23)  
  
Miscellaneous  
[strerrorstrerror_sstrerrorlen_s](byte/strerror.html "c/string/byte/strerror")(C11)(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/navbar_content&action=edit)

A null-terminated byte string (NTBS) is a sequence of nonzero bytes followed by a byte with value zero (the terminating null character). Each byte in a byte string encodes one character of some character set. For example, the character array {'\x63','\x61','\x74','\0'} is an NTBS holding the string "cat" in [ASCII](../language/ascii.html "c/language/ascii") encoding. 

## Contents

  * [1 Functions](byte.html#Functions)
    * [1.1 Character classification](byte.html#Character_classification)
    * [1.2 Character manipulation](byte.html#Character_manipulation)
    * [1.3 Conversions to and from numeric formats](byte.html#Conversions_to_and_from_numeric_formats)
    * [1.4 String manipulation](byte.html#String_manipulation)
    * [1.5 String examination](byte.html#String_examination)
    * [1.6 Character array manipulation](byte.html#Character_array_manipulation)
    * [1.7 Miscellaneous](byte.html#Miscellaneous)
  * [2 References](byte.html#References)
  * [3 See also](byte.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte&action=edit&section=1 "Edit section: Functions")] Functions

#####  Character classification   
  
---  
Defined in header `[`<ctype.h>`](../header/ctype.html "c/header/ctype")`  
[ isalnum](byte/isalnum.html "c/string/byte/isalnum") |  checks if a character is alphanumeric   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_isalnum&action=edit)  
[ isalpha](byte/isalpha.html "c/string/byte/isalpha") |  checks if a character is alphabetic   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_isalpha&action=edit)  
[ islower](byte/islower.html "c/string/byte/islower") |  checks if a character is lowercase   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_islower&action=edit)  
[ isupper](byte/isupper.html "c/string/byte/isupper") |  checks if a character is an uppercase character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_isupper&action=edit)  
[ isdigit](byte/isdigit.html "c/string/byte/isdigit") |  checks if a character is a digit   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_isdigit&action=edit)  
[ isxdigit](byte/isxdigit.html "c/string/byte/isxdigit") |  checks if a character is a hexadecimal character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_isxdigit&action=edit)  
[ iscntrl](byte/iscntrl.html "c/string/byte/iscntrl") |  checks if a character is a control character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_iscntrl&action=edit)  
[ isgraph](byte/isgraph.html "c/string/byte/isgraph") |  checks if a character is a graphical character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_isgraph&action=edit)  
[ isspace](byte/isspace.html "c/string/byte/isspace") |  checks if a character is a space character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_isspace&action=edit)  
[ isblank](byte/isblank.html "c/string/byte/isblank")(C99) |  checks if a character is a blank character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_isblank&action=edit)  
[ isprint](byte/isprint.html "c/string/byte/isprint") |  checks if a character is a printing character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_isprint&action=edit)  
[ ispunct](byte/ispunct.html "c/string/byte/ispunct") |  checks if a character is a punctuation character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_ispunct&action=edit)  
  
#####  Character manipulation   
  
[ tolower](byte/tolower.html "c/string/byte/tolower") |  converts a character to lowercase   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_tolower&action=edit)  
[ toupper](byte/toupper.html "c/string/byte/toupper") |  converts a character to uppercase   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_toupper&action=edit)  
  
Note: additional functions whose names begin with either `**to**` or `**is**`, followed by a lowercase letter, may be added to the header [`<ctype.h>`](../header/ctype.html "c/header/ctype") in future and should not be defined by programs that include that header. 

ASCII values  | characters  |  [`iscntrl`](byte/iscntrl.html "c/string/byte/iscntrl")  
[`iswcntrl`](wide/iswcntrl.html "c/string/wide/iswcntrl") |  [`isprint`](byte/isprint.html "c/string/byte/isprint")  
[`iswprint`](wide/iswprint.html "c/string/wide/iswprint") |  [`isspace`](byte/isspace.html "c/string/byte/isspace")  
[`iswspace`](wide/iswspace.html "c/string/wide/iswspace") |  [`isblank`](byte/isblank.html "c/string/byte/isblank")  
[`iswblank`](wide/iswblank.html "c/string/wide/iswblank") |  [`isgraph`](byte/isgraph.html "c/string/byte/isgraph")  
[`iswgraph`](wide/iswgraph.html "c/string/wide/iswgraph") |  [`ispunct`](byte/ispunct.html "c/string/byte/ispunct")   
[`iswpunct`](wide/iswpunct.html "c/string/wide/iswpunct") |  [`isalnum`](byte/isalnum.html "c/string/byte/isalnum")   
[`iswalnum`](wide/iswalnum.html "c/string/wide/iswalnum") |  [`isalpha`](byte/isalpha.html "c/string/byte/isalpha")   
[`iswalpha`](wide/iswalpha.html "c/string/wide/iswalpha") |  [`isupper`](byte/isupper.html "c/string/byte/isupper")  
[`iswupper`](wide/iswupper.html "c/string/wide/iswupper") |  [`islower`](byte/islower.html "c/string/byte/islower")  
[`iswlower`](wide/iswlower.html "c/string/wide/iswlower") |  [`isdigit`](byte/isdigit.html "c/string/byte/isdigit")  
[`iswdigit`](wide/iswdigit.html "c/string/wide/iswdigit") |  [`isxdigit`](byte/isxdigit.html "c/string/byte/isxdigit")  
[`iswxdigit`](wide/iswxdigit.html "c/string/wide/iswxdigit")  
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
  
#####  Conversions to and from numeric formats   
  
---  
Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")`  
[ atof](byte/atof.html "c/string/byte/atof") |  converts a byte string to a floating-point value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_atof&action=edit)  
[ atoiatolatoll](byte/atoi.html "c/string/byte/atoi")(C99) |  converts a byte string to an integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_atoi&action=edit)  
[ strtolstrtoll](byte/strtol.html "c/string/byte/strtol")(C99) |  converts a byte string to an integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtol&action=edit)  
[ strtoul strtoull](byte/strtoul.html "c/string/byte/strtoul")(C99) |  converts a byte string to an unsigned integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtoul&action=edit)  
[ strtofstrtodstrtold](byte/strtof.html "c/string/byte/strtof")(C99)(C99) |  converts a byte string to a floating-point value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtof&action=edit)  
[ strfromfstrfromdstrfroml](byte/strfromf.html "c/string/byte/strfromf")(C23)(C23)(C23) |  converts a floating-point value to a byte string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strfromf&action=edit)  
Defined in header `[`<inttypes.h>`](../header/inttypes.html "c/header/inttypes")`  
[ strtoimaxstrtoumax](byte/strtoimax.html "c/string/byte/strtoimax")(C99)(C99) |  converts a byte string to [intmax_t](../types/integer.html "c/types/integer") or [uintmax_t](../types/integer.html "c/types/integer")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtoimax&action=edit)  
  
#####  String manipulation   
  
Defined in header `[`<string.h>`](../header/string.html "c/header/string")`  
[ strcpystrcpy_s](byte/strcpy.html "c/string/byte/strcpy")(C11) |  copies one string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcpy&action=edit)  
[ strncpystrncpy_s](byte/strncpy.html "c/string/byte/strncpy")(C11) |  copies a certain amount of characters from one string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strncpy&action=edit)  
[ strcatstrcat_s](byte/strcat.html "c/string/byte/strcat")(C11) |  concatenates two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcat&action=edit)  
[ strncatstrncat_s](byte/strncat.html "c/string/byte/strncat")(C11) |  concatenates a certain amount of characters of two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strncat&action=edit)  
[ strxfrm](byte/strxfrm.html "c/string/byte/strxfrm") |  transform a string so that strcmp would produce the same result as strcoll   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strxfrm&action=edit)  
[ strdup](byte/strdup.html "c/string/byte/strdup")(C23) |  allocates a copy of a string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strdup&action=edit)  
[ strndup](byte/strndup.html "c/string/byte/strndup")(C23) |  allocates a copy of a string of specified size   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strndup&action=edit)  
  
#####  String examination   
  
Defined in header `[`<string.h>`](../header/string.html "c/header/string")`  
[ strlenstrnlen_s](byte/strlen.html "c/string/byte/strlen")(C11) |  returns the length of a given string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strlen&action=edit)  
[ strcmp](byte/strcmp.html "c/string/byte/strcmp") |  compares two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcmp&action=edit)  
[ strncmp](byte/strncmp.html "c/string/byte/strncmp") |  compares a certain amount of characters of two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strncmp&action=edit)  
[ strcoll](byte/strcoll.html "c/string/byte/strcoll") |  compares two strings in accordance to the current locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcoll&action=edit)  
[ strchr](byte/strchr.html "c/string/byte/strchr") |  finds the first occurrence of a character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strchr&action=edit)  
[ strrchr](byte/strrchr.html "c/string/byte/strrchr") |  finds the last occurrence of a character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strrchr&action=edit)  
[ strspn](byte/strspn.html "c/string/byte/strspn") |  returns the length of the maximum initial segment that consists   
of only the characters found in another byte string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strspn&action=edit)  
[ strcspn](byte/strcspn.html "c/string/byte/strcspn") |  returns the length of the maximum initial segment that consists   
of only the characters not found in another byte string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcspn&action=edit)  
[ strpbrk](byte/strpbrk.html "c/string/byte/strpbrk") |  finds the first location of any character in one string, in another string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strpbrk&action=edit)  
[ strstr](byte/strstr.html "c/string/byte/strstr") |  finds the first occurrence of a substring of characters   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strstr&action=edit)  
[ strtokstrtok_s](byte/strtok.html "c/string/byte/strtok")(C11) |  finds the next token in a byte string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtok&action=edit)  
  
#####  Character array manipulation   
  
Defined in header `[`<string.h>`](../header/string.html "c/header/string")`  
[ memchr](byte/memchr.html "c/string/byte/memchr") |  searches an array for the first occurrence of a character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memchr&action=edit)  
[ memcmp](byte/memcmp.html "c/string/byte/memcmp") |  compares two buffers   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memcmp&action=edit)  
[ memsetmemset_explicitmemset_s](byte/memset.html "c/string/byte/memset")(C23)(C11) |  fills a buffer with a character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memset&action=edit)  
[ memcpymemcpy_s](byte/memcpy.html "c/string/byte/memcpy")(C11) |  copies one buffer to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memcpy&action=edit)  
[ memmovememmove_s](byte/memmove.html "c/string/byte/memmove")(C11) |  moves one buffer to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memmove&action=edit)  
[ memccpy](byte/memccpy.html "c/string/byte/memccpy")(C23) |  copies one buffer to another, stopping after the specified delimiter   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memccpy&action=edit)  
  
#####  Miscellaneous   
  
Defined in header `[`<string.h>`](../header/string.html "c/header/string")`  
[ strerrorstrerror_sstrerrorlen_s](byte/strerror.html "c/string/byte/strerror")(C11)(C11) |  returns a text version of a given error code   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strerror&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte&action=edit&section=2 "Edit section: References")] References

Extended content  
---  
  
  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.4 Character handling <ctype.h> (p: TBD) 



    

  * 7.8 Format conversion of integer types <inttypes.h> (p: TBD) 



    

  * 7.22 General utilities <stdlib.h> (p: TBD) 



    

  * 7.24 String handling <string.h> (p: TBD) 



    

  * 7.31.2 Character handling <ctype.h> (p: TBD) 



    

  * 7.31.5 Format conversion of integer types <inttypes.h> (p: TBD) 



    

  * 7.31.12 General utilities <stdlib.h> (p: TBD) 



    

  * 7.31.13 String handling <string.h> (p: TBD) 



    

  * K.3.6 General utilities <stdlib.h> (p: TBD) 



    

  * K.3.7 String handling <string.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.4 Character handling <ctype.h> (p: TBD) 



    

  * 7.8 Format conversion of integer types <inttypes.h> (p: TBD) 



    

  * 7.22 General utilities <stdlib.h> (p: TBD) 



    

  * 7.24 String handling <string.h> (p: TBD) 



    

  * 7.31.2 Character handling <ctype.h> (p: TBD) 



    

  * 7.31.5 Format conversion of integer types <inttypes.h> (p: TBD) 



    

  * 7.31.12 General utilities <stdlib.h> (p: TBD) 



    

  * 7.31.13 String handling <string.h> (p: TBD) 



    

  * K.3.6 General utilities <stdlib.h> (p: TBD) 



    

  * K.3.7 String handling <string.h> (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.4 Character handling <ctype.h> (p: 200-204) 



    

  * 7.8 Format conversion of integer types <inttypes.h> (p: 217-220) 



    

  * 7.22 General utilities <stdlib.h> (p: 340-360) 



    

  * 7.24 String handling <string.h> (p: 362-372) 



    

  * 7.31.2 Character handling <ctype.h> (p: 455) 



    

  * 7.31.5 Format conversion of integer types <inttypes.h> (p: 455) 



    

  * 7.31.12 General utilities <stdlib.h> (p: 456) 



    

  * 7.31.13 String handling <string.h> (p: 456) 



    

  * K.3.6 General utilities <stdlib.h> (p: 604-613) 



    

  * K.3.7 String handling <string.h> (p: 614-623) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.4 Character handling <ctype.h> (p: 181-185) 



    

  * 7.8 Format conversion of integer types <inttypes.h> (p: 198-201) 



    

  * 7.20 General utilities <stdlib.h> (p: 306-324) 



    

  * 7.21 String handling <string.h> (p: 325-334) 



    

  * 7.26.2 Character handling <ctype.h> (p: 401) 



    

  * 7.26.4 Format conversion of integer types <inttypes.h> (p: 401) 



    

  * 7.26.10 General utilities <stdlib.h> (p: 402) 



    

  * 7.26.11 String handling <string.h> (p: 402) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.3 CHARACTER HANDLING <ctype.h>



    

  * 4.10 GENERAL UTILITIES <stdlib.h>



    

  * 4.11 STRING HANDLING <string.h>



    

  * 4.13.2 Character handling <ctype.h>



    

  * 4.13.7 General utilities <stdlib.h>



    

  * 4.13.8 String handling <string.h>

  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte&action=edit&section=3 "Edit section: See also")] See also

[C++ documentation](../../cpp/string/byte.html "cpp/string/byte") for `Null`-terminated byte strings  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte&oldid=180299](https://en.cppreference.com/mwiki/index.php?title=c/string/byte&oldid=180299)" 

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

[Null-terminated byte strings](byte.html "c/string/byte")  
---  
[Null-terminated multibyte strings](multibyte.html "c/string/multibyte")  
**Null-terminated wide strings**  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/navbar_content&action=edit)

**Null-terminated wide strings**

| [Functions](wide.html#Functions "c/string/wide")  
---  
[Character classification](wide.html#Character_classification "c/string/wide")  
| [iswalnum](wide/iswalnum.html "c/string/wide/iswalnum")(C95)  
---  
[iswalpha](wide/iswalpha.html "c/string/wide/iswalpha")(C95)  
[iswlower](wide/iswlower.html "c/string/wide/iswlower")(C95)  
[iswupper](wide/iswupper.html "c/string/wide/iswupper")(C95)  
[iswdigit](wide/iswdigit.html "c/string/wide/iswdigit")(C95)  
[iswxdigit](wide/iswxdigit.html "c/string/wide/iswxdigit")(C95)` `  
[iswblank](wide/iswblank.html "c/string/wide/iswblank")(C99)  
  
| [iswctype](wide/iswctype.html "c/string/wide/iswctype")(C95)  
---  
[iswcntrl](wide/iswcntrl.html "c/string/wide/iswcntrl")(C95)  
[iswgraph](wide/iswgraph.html "c/string/wide/iswgraph")(C95)  
[iswspace](wide/iswspace.html "c/string/wide/iswspace")(C95)  
[iswprint](wide/iswprint.html "c/string/wide/iswprint")(C95)  
[iswpunct](wide/iswpunct.html "c/string/wide/iswpunct")(C95)  
[wctype](wide/wctype.html "c/string/wide/wctype")(C95)  
  
[Character manipulation](wide.html#Character_manipulation "c/string/wide")  
| [towlower](wide/towlower.html "c/string/wide/towlower")(C95)  
---  
[towupper](wide/towupper.html "c/string/wide/towupper")(C95)  
  
| [wctrans](wide/wctrans.html "c/string/wide/wctrans")(C95)  
---  
[towctrans](wide/towctrans.html "c/string/wide/towctrans")(C95)  
  
[Conversions to numeric formats](wide.html#Conversions_to_numeric_formats "c/string/wide")  
| [wcstolwcstoll](wide/wcstol.html "c/string/wide/wcstol")(C95)(C99)  
---  
[wcstofwcstodwcstold](wide/wcstof.html "c/string/wide/wcstof")(C99)(C95)(C99)  
  
| [wcstoulwcstoull](wide/wcstoul.html "c/string/wide/wcstoul")(C95)(C99)  
---  
[wcstoimaxwcstoumax](wide/wcstoimax.html "c/string/wide/wcstoimax")(C99)(C99)` `  
  
  
  
[String manipulation](wide.html#String_manipulation "c/string/wide")  
| [wcscpywcscpy_s](wide/wcscpy.html "c/string/wide/wcscpy")(C95)(C11)  
---  
[wcsncpywcsncpy_s](wide/wcsncpy.html "c/string/wide/wcsncpy")(C95)(C11)  
[wcsxfrm](wide/wcsxfrm.html "c/string/wide/wcsxfrm")(C95)  
  
| [wcscatwcscat_s](wide/wcscat.html "c/string/wide/wcscat")(C95)(C11)  
---  
[wcsncatwcsncat_s](wide/wcsncat.html "c/string/wide/wcsncat")(C95)(C11)  
  
  
  
| [String examination](wide.html#String_examination "c/string/wide")  
---  
| [wcslenwcsnlen_s](wide/wcslen.html "c/string/wide/wcslen")(C95)(C11)  
---  
[wcsstr](wide/wcsstr.html "c/string/wide/wcsstr")(C95)  
[wcscmp](wide/wcscmp.html "c/string/wide/wcscmp")(C95)  
[wcsncmp](wide/wcsncmp.html "c/string/wide/wcsncmp")(C95)  
[wcscoll](wide/wcscoll.html "c/string/wide/wcscoll")(C95)  
[wcschr](wide/wcschr.html "c/string/wide/wcschr")(C95)  
  
| [wcsrchr](wide/wcsrchr.html "c/string/wide/wcsrchr")(C95)  
---  
[wcspbrk](wide/wcspbrk.html "c/string/wide/wcspbrk")(C95)  
[wcsspn](wide/wcsspn.html "c/string/wide/wcsspn")(C95)  
[wcscspn](wide/wcscspn.html "c/string/wide/wcscspn")(C95)  
[wcstokwcstok_s](wide/wcstok.html "c/string/wide/wcstok")(C95)(C11)  
  
  
  
[Array manipulation](wide.html#Wide_character_array_manipulation "c/string/wide")  
| [wmemcpywmemcpy_s](wide/wmemcpy.html "c/string/wide/wmemcpy")(C95)(C11)  
---  
[wmemmovewmemmove_s](wide/wmemmove.html "c/string/wide/wmemmove")(C95)(C11)` `  
  
| [wmemcmp](wide/wmemcmp.html "c/string/wide/wmemcmp")(C95)  
---  
[wmemchr](wide/wmemchr.html "c/string/wide/wmemchr")(C95)  
[wmemset](wide/wmemset.html "c/string/wide/wmemset")(C95)  
  
  
  
[Types](wide.html#Types "c/string/wide")  
[wchar_t  
wint_t](wide.html#Types "c/string/wide")(C95)  
[wctrans_t  
wctype_t](wide.html#Types "c/string/wide")(C95)(C95)  
[Macros](wide.html#Macros "c/string/wide")  
[WCHAR_MIN  
WCHAR_MAX](wide.html#Macros "c/string/wide")(C95)(C95)  
[WEOF](wide.html#Macros "c/string/wide")(C95)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/navbar_content&action=edit)

A null-terminated wide string is a sequence of valid wide characters, ending with a null-character. 

## Contents

  * [1 Functions](wide.html#Functions)
    * [1.1 Character classification](wide.html#Character_classification)
    * [1.2 Character manipulation](wide.html#Character_manipulation)
    * [1.3 Conversions to numeric formats](wide.html#Conversions_to_numeric_formats)
    * [1.4 String manipulation](wide.html#String_manipulation)
    * [1.5 String examination](wide.html#String_examination)
    * [1.6 Wide character array manipulation](wide.html#Wide_character_array_manipulation)
  * [2 Types](wide.html#Types)
  * [3 Macros](wide.html#Macros)
  * [4 References](wide.html#References)
  * [5 See also](wide.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/wide&action=edit&section=1 "Edit section: Functions")] Functions

#####  Character classification   
  
---  
Defined in header `[`<wctype.h>`](../header/wctype.html "c/header/wctype")`  
[ iswalnum](wide/iswalnum.html "c/string/wide/iswalnum")(C95) |  checks if a wide character is alphanumeric   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswalnum&action=edit)  
[ iswalpha](wide/iswalpha.html "c/string/wide/iswalpha")(C95) |  checks if a wide character is alphabetic   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswalpha&action=edit)  
[ iswlower](wide/iswlower.html "c/string/wide/iswlower")(C95) |  checks if a wide character is an lowercase character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswlower&action=edit)  
[ iswupper](wide/iswupper.html "c/string/wide/iswupper")(C95) |  checks if a wide character is an uppercase character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswupper&action=edit)  
[ iswdigit](wide/iswdigit.html "c/string/wide/iswdigit")(C95) |  checks if a wide character is a digit   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswdigit&action=edit)  
[ iswxdigit](wide/iswxdigit.html "c/string/wide/iswxdigit")(C95) |  checks if a wide character is a hexadecimal character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswxdigit&action=edit)  
[ iswcntrl](wide/iswcntrl.html "c/string/wide/iswcntrl")(C95) |  checks if a wide character is a control character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswcntrl&action=edit)  
[ iswgraph](wide/iswgraph.html "c/string/wide/iswgraph")(C95) |  checks if a wide character is a graphical character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswgraph&action=edit)  
[ iswspace](wide/iswspace.html "c/string/wide/iswspace")(C95) |  checks if a wide character is a space character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswspace&action=edit)  
[ iswblank](wide/iswblank.html "c/string/wide/iswblank")(C99) |  checks if a wide character is a blank character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswblank&action=edit)  
[ iswprint](wide/iswprint.html "c/string/wide/iswprint")(C95) |  checks if a wide character is a printing character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswprint&action=edit)  
[ iswpunct](wide/iswpunct.html "c/string/wide/iswpunct")(C95) |  checks if a wide character is a punctuation character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswpunct&action=edit)  
[ iswctype](wide/iswctype.html "c/string/wide/iswctype")(C95) |  classifies a wide character according to the specified [LC_CTYPE](../locale/LC_categories.html "c/locale/LC categories") category   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswctype&action=edit)  
[ wctype](wide/wctype.html "c/string/wide/wctype")(C95) |  looks up a character classification category in the current C locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wctype&action=edit)  
  
#####  Character manipulation   
  
Defined in header `[`<wctype.h>`](../header/wctype.html "c/header/wctype")`  
[ towlower](wide/towlower.html "c/string/wide/towlower")(C95) |  converts a wide character to lowercase   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_towlower&action=edit)  
[ towupper](wide/towupper.html "c/string/wide/towupper")(C95) |  converts a wide character to uppercase   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_towupper&action=edit)  
[ towctrans](wide/towctrans.html "c/string/wide/towctrans")(C95) |  performs character mapping according to the specified [LC_CTYPE](../locale/LC_categories.html "c/locale/LC categories") mapping category   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_towctrans&action=edit)  
[ wctrans](wide/wctrans.html "c/string/wide/wctrans")(C95) |  looks up a character mapping category in the current C locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wctrans&action=edit)  
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
  
#####  Conversions to numeric formats   
  
---  
Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")`  
[ wcstolwcstoll](wide/wcstol.html "c/string/wide/wcstol")(C95)(C99) |  converts a wide string to an integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstol&action=edit)  
[ wcstoulwcstoull](wide/wcstoul.html "c/string/wide/wcstoul")(C95)(C99) |  converts a wide string to an unsigned integer value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstoul&action=edit)  
[ wcstofwcstodwcstold](wide/wcstof.html "c/string/wide/wcstof")(C99)(C95)(C99) |  converts a wide string to a floating-point value   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstof&action=edit)  
Defined in header `[`<inttypes.h>`](../header/inttypes.html "c/header/inttypes")`  
[ wcstoimaxwcstoumax](wide/wcstoimax.html "c/string/wide/wcstoimax")(C99)(C99) |  converts a wide string to [intmax_t](../types/integer.html "c/types/integer") or [uintmax_t](../types/integer.html "c/types/integer")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstoimax&action=edit)  
  
#####  String manipulation   
  
---  
Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")`  
[ wcscpywcscpy_s](wide/wcscpy.html "c/string/wide/wcscpy")(C95)(C11) |  copies one wide string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcscpy&action=edit)  
[ wcsncpywcsncpy_s](wide/wcsncpy.html "c/string/wide/wcsncpy")(C95)(C11) |  copies a certain amount of wide characters from one string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsncpy&action=edit)  
[ wcscatwcscat_s](wide/wcscat.html "c/string/wide/wcscat")(C95)(C11) |  appends a copy of one wide string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcscat&action=edit)  
[ wcsncatwcsncat_s](wide/wcsncat.html "c/string/wide/wcsncat")(C95)(C11) |  appends a certain amount of wide characters from one wide string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsncat&action=edit)  
[ wcsxfrm](wide/wcsxfrm.html "c/string/wide/wcsxfrm")(C95) |  transform a wide string so that [wcscmp](wide/wcscmp.html "c/string/wide/wcscmp") would produce the same result as [wcscoll](wide/wcscoll.html "c/string/wide/wcscoll")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsxfrm&action=edit)  
  
#####  String examination   
  
Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")`  
[ wcslenwcsnlen_s](wide/wcslen.html "c/string/wide/wcslen")(C95)(C11) |  returns the length of a wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcslen&action=edit)  
[ wcscmp](wide/wcscmp.html "c/string/wide/wcscmp")(C95) |  compares two wide strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcscmp&action=edit)  
[ wcsncmp](wide/wcsncmp.html "c/string/wide/wcsncmp")(C95) |  compares a certain amount of characters from two wide strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsncmp&action=edit)  
[ wcscoll](wide/wcscoll.html "c/string/wide/wcscoll")(C95) |  compares two wide strings in accordance to the current locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcscoll&action=edit)  
[ wcschr](wide/wcschr.html "c/string/wide/wcschr")(C95) |  finds the first occurrence of a wide character in a wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcschr&action=edit)  
[ wcsrchr](wide/wcsrchr.html "c/string/wide/wcsrchr")(C95) |  finds the last occurrence of a wide character in a wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsrchr&action=edit)  
[ wcsspn](wide/wcsspn.html "c/string/wide/wcsspn")(C95) |  returns the length of the maximum initial segment that consists   
of only the wide characters found in another wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsspn&action=edit)  
[ wcscspn](wide/wcscspn.html "c/string/wide/wcscspn")(C95) |  returns the length of the maximum initial segment that consists   
of only the wide chars _not_ found in another wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcscspn&action=edit)  
[ wcspbrk](wide/wcspbrk.html "c/string/wide/wcspbrk")(C95) |  finds the first location of any wide character in one wide string, in another wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcspbrk&action=edit)  
[ wcsstr](wide/wcsstr.html "c/string/wide/wcsstr")(C95) |  finds the first occurrence of a wide string within another wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcsstr&action=edit)  
[ wcstokwcstok_s](wide/wcstok.html "c/string/wide/wcstok")(C95)(C11) |  finds the next token in a wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstok&action=edit)  
  
#####  Wide character array manipulation   
  
---  
Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")`  
[ wmemcpywmemcpy_s](wide/wmemcpy.html "c/string/wide/wmemcpy")(C95)(C11) |  copies a certain amount of wide characters between two non-overlapping arrays   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wmemcpy&action=edit)  
[ wmemmovewmemmove_s](wide/wmemmove.html "c/string/wide/wmemmove")(C95)(C11) |  copies a certain amount of wide characters between two, possibly overlapping, arrays   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wmemmove&action=edit)  
[ wmemcmp](wide/wmemcmp.html "c/string/wide/wmemcmp")(C95) |  compares a certain amount of wide characters from two arrays   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wmemcmp&action=edit)  
[ wmemchr](wide/wmemchr.html "c/string/wide/wmemchr")(C95) |  finds the first occurrence of a wide character in a wide character array   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wmemchr&action=edit)  
[ wmemset](wide/wmemset.html "c/string/wide/wmemset")(C95) |  copies the given wide character to every position in a wide character array   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wmemset&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/wide&action=edit&section=2 "Edit section: Types")] Types

Defined in header `[`<stddef.h>`](../header/stddef.html "c/header/stddef")`  
---  
Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")`  
Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")`  
wchar_t |  integer type that can hold any valid wide character   
(typedef)  
Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")`  
Defined in header `[`<wctype.h>`](../header/wctype.html "c/header/wctype")`  
wint_t(C95) |  integer type that can hold any valid wide character and at least one more value   
(typedef)  
Defined in header `[`<wctype.h>`](../header/wctype.html "c/header/wctype")`  
wctrans_t(C95) |  scalar type that holds locale-specific character mapping   
(typedef)  
wctype_t(C95) |  scalar type that holds locale-specific character classification   
(typedef)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/wide&action=edit&section=3 "Edit section: Macros")] Macros

Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")`  
---  
Defined in header `[`<wctype.h>`](../header/wctype.html "c/header/wctype")`  
WEOF(C95) |  a non-character value of type wint_t used to indicate errors   
(macro constant)  
Defined in header `[`<wchar.h>`](../header/wchar.html "c/header/wchar")`  
Defined in header `[`<stdint.h>`](../header/stdint.html "c/header/stdint")`  
WCHAR_MIN(C95) |  the smallest valid value of wchar_t   
(macro constant)  
WCHAR_MAX(C95) |  the largest valid value of wchar_t   
(macro constant)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/wide&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.19 Common definitions <stddef.h> (p: TBD) 



    

  * 7.29 Extended multibyte and wide character utilities <wchar.h> (p: TBD) 



    

  * 7.30 Wide character classification and mapping utilities <wctype.h> (p: TBD) 



    

  * 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: TBD) 



    

  * 7.31.17 Wide character classification and mapping utilities <wctype.h> (p: TBD) 



    

  * K.3.3 Common definitions <stddef.h> (p: TBD) 



    

  * K.3.9 Extended multibyte and wide character utilities <wchar.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.19 Common definitions <stddef.h> (p: TBD) 



    

  * 7.29 Extended multibyte and wide character utilities <wchar.h> (p: TBD) 



    

  * 7.30 Wide character classification and mapping utilities <wctype.h> (p: TBD) 



    

  * 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: TBD) 



    

  * 7.31.17 Wide character classification and mapping utilities <wctype.h> (p: TBD) 



    

  * K.3.3 Common definitions <stddef.h> (p: TBD) 



    

  * K.3.9 Extended multibyte and wide character utilities <wchar.h> (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.19 Common definitions <stddef.h> (p: 288) 



    

  * 7.29 Extended multibyte and wide character utilities <wchar.h> (p: 402-446) 



    

  * 7.30 Wide character classification and mapping utilities <wctype.h> (p: 447-454) 



    

  * 7.31.16 Extended multibyte and wide character utilities <wchar.h> (p: 456) 



    

  * 7.31.17 Wide character classification and mapping utilities <wctype.h> (p: 457) 



    

  * K.3.3 Common definitions <stddef.h> (p: 585) 



    

  * K.3.9 Extended multibyte and wide character utilities <wchar.h> (p: 627-651) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.17 Common definitions <stddef.h> (p: 254) 



    

  * 7.24 Extended multibyte and wide character utilities <wchar.h> (p: 348-392) 



    

  * 7.25 Wide character classification and mapping utilities <wctype.h> (p: 393-400) 



    

  * 7.26.12 Extended multibyte and wide character utilities <wchar.h> (p: 402) 



    

  * 7.26.13 Wide character classification and mapping utilities <wctype.h> (p: 402) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.1.5 Common definitions <stddef.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/wide&action=edit&section=5 "Edit section: See also")] See also

[C++ documentation](../../cpp/string/wide.html "cpp/string/wide") for `Null`-terminated wide strings  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/wide&oldid=180714](https://en.cppreference.com/mwiki/index.php?title=c/string/wide&oldid=180714)" 

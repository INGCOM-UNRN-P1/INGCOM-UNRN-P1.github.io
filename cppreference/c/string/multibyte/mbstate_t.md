From cppreference.com

< [c](../../../c.html "c")‎ | [string](../../string.html "c/string")‎ | [multibyte](../multibyte.html "c/string/multibyte")

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

[ Null-terminated multibyte strings](../multibyte.html "c/string/multibyte")

[Functions](../multibyte.html#Functions "c/string/multibyte")  
---  
[Wide/multibyte conversions](../multibyte.html#Multibyte.2Fwide_character_conversions "c/string/multibyte")  
[mbsinit](mbsinit.html "c/string/multibyte/mbsinit")(C95)  
| [mbstowcsmbstowcs_s](mbstowcs.html "c/string/multibyte/mbstowcs")(C11)  
---  
[btowc](btowc.html "c/string/multibyte/btowc")(C95)  
[mbrtowc](mbrtowc.html "c/string/multibyte/mbrtowc")(C95)  
[mbsrtowcsmbsrtowcs_s](mbsrtowcs.html "c/string/multibyte/mbsrtowcs")(C95)(C11)` `  
[mbrtoc8](mbrtoc8.html "c/string/multibyte/mbrtoc8")(C23)  
[c8rtomb](c8rtomb.html "c/string/multibyte/c8rtomb")(C23)  
[mbrtoc16](mbrtoc16.html "c/string/multibyte/mbrtoc16")(C11)  
[c16rtomb](c16rtomb.html "c/string/multibyte/c16rtomb")(C11)  
[c32rtomb](c32rtomb.html "c/string/multibyte/c32rtomb")(C11)  
[mbrtoc32](mbrtoc32.html "c/string/multibyte/mbrtoc32")(C11)  
  
| [mblen](mblen.html "c/string/multibyte/mblen")  
---  
[mbtowc](mbtowc.html "c/string/multibyte/mbtowc")  
[wctombwctomb_s](wctomb.html "c/string/multibyte/wctomb")(C11)  
[wcstombswcstombs_s](wcstombs.html "c/string/multibyte/wcstombs")(C11)  
[wctob](wctob.html "c/string/multibyte/wctob")(C95)  
[wcrtombwcrtomb_s](wcrtomb.html "c/string/multibyte/wcrtomb")(C95)(C11)  
[wcsrtombswcsrtombs_s](wcsrtombs.html "c/string/multibyte/wcsrtombs")(C95)(C11)  
[mbrlen](mbrlen.html "c/string/multibyte/mbrlen")(C95)  
  
[Types](../multibyte.html#Types "c/string/multibyte")  
| **mbstate_t**(C95)  
---  
[char8_t](char8_t.html "c/string/multibyte/char8 t")(C23)  
  
| [char16_t](char16_t.html "c/string/multibyte/char16 t")(C11)  
---  
[char32_t](char32_t.html "c/string/multibyte/char32 t")(C11)  
  
[Macros](../multibyte.html#Macros "c/string/multibyte")  
| [MB_LEN_MAX](../multibyte.html#Macros "c/string/multibyte")  
---  
  
| [MB_CUR_MAX](../multibyte.html#Macros "c/string/multibyte")  
---  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/navbar_content&action=edit)

Defined in header `[`<uchar.h>`](../../header/uchar.html "c/header/uchar")` |  | (since C11)  
---|---|---  
Defined in header `[`<wchar.h>`](../../header/wchar.html "c/header/wchar")` |  |   
struct mbstate_t; |  |  (since C95)  
| |   
  
The type `mbstate_t` is a trivial non-array type that can represent any of the conversion states that can occur in an implementation-defined set of supported multibyte character encoding rules. Zero-initialized value of `mbstate_t` represents the initial conversion state, although other values of `mbstate_t` may exist that also represent the initial conversion state. 

Possible implementation of `mbstate_t` is a struct type holding an array representing the incomplete multibyte character, an integer counter indicating the number of bytes in the array that have been processed, and a representation of the current shift state. 

The following functions should not be called from multiple threads without synchronization with the mbstate_t* argument of a null pointer due to possible data races: [mbrlen](mbrlen.html "c/string/multibyte/mbrlen"), [mbrtowc](mbrtowc.html "c/string/multibyte/mbrtowc"), [mbsrtowcs](mbsrtowcs.html "c/string/multibyte/mbsrtowcs"), [mbtowc](mbtowc.html "c/string/multibyte/mbtowc"), [wcrtomb](wcrtomb.html "c/string/multibyte/wcrtomb"), [wcsrtombs](wcsrtombs.html "c/string/multibyte/wcsrtombs"), [wctomb](wctomb.html "c/string/multibyte/wctomb"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbstate_t&action=edit&section=1 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.29.1/2 Introduction (p: 402) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.24.1/2 Introduction (p: 348) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbstate_t&action=edit&section=2 "Edit section: See also")] See also

[ mbsinit](mbsinit.html "c/string/multibyte/mbsinit")(C95) |  checks if the mbstate_t object represents initial shift state   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbsinit&action=edit)  
---|---  
[C++ documentation](../../../cpp/string/multibyte/mbstate_t.html "cpp/string/multibyte/mbstate t") for mbstate_t  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbstate_t&oldid=119771](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbstate_t&oldid=119771)" 

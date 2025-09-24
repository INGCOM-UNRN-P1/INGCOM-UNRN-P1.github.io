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
**c8rtomb**(C23)  
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
| [mbstate_t](mbstate_t.html "c/string/multibyte/mbstate t")(C95)  
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

Defined in header `[`<uchar.h>`](../../header/uchar.html "c/header/uchar")` |  |   
---|---|---  
[size_t](../../types/size_t.html) c8rtomb( char* restrict s, char8_t c8, [mbstate_t](mbstate_t.html)* restrict ps ); |  |  (since C23)  
| |   
  
Converts a single code point from UTF-8 to a narrow multibyte character representation. 

If s is not a null pointer and c8 is the last code unit in a valid UTF-8 encoding of a code point, the function determines the number of bytes necessary to store the multibyte character representation of that code point (including any shift sequences, and taking into account the current multibyte conversion state *ps), and stores the multibyte character representation in the character array whose first element is pointed to by s, updating *ps as necessary. At most MB_CUR_MAX bytes can be written by this function. 

If c8 is not the final UTF-8 code unit in a representation of a code point, the function does not write to the array pointed to by s, only *ps is updated. 

If s is a null pointer, the call is equivalent to c8rtomb(buf, u8'\0', ps) for some internal buffer buf. 

If c8 is the null character u8'\0', a null byte is stored, preceded by any shift sequence necessary to restore the initial shift state and the conversion state parameter *ps is updated to represent the initial shift state. 

The multibyte encoding used by this function is specified by the currently active C locale. 

## Contents

  * [1 Parameters](c8rtomb.html#Parameters)
  * [2 Return value](c8rtomb.html#Return_value)
  * [3 Notes](c8rtomb.html#Notes)
  * [4 Example](c8rtomb.html#Example)
  * [5 References](c8rtomb.html#References)
  * [6 See also](c8rtomb.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c8rtomb&action=edit&section=1 "Edit section: Parameters")] Parameters

s  |  \-  |  pointer to narrow character array where the multibyte character will be stored   
---|---|---  
c8  |  \-  |  the UTF-8 code unit to convert   
ps  |  \-  |  pointer to the conversion state object used when interpreting the multibyte string   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c8rtomb&action=edit&section=2 "Edit section: Return value")] Return value

The number of bytes stored in the array object (including any shift sequences). This may be zero when c8 is not the final code unit in the UTF-8 representation of a code point. 

If c8 is invalid (does not contribute to a sequence of char8_t corresponding to a valid multibyte character), the value of the macro [EILSEQ](../../error/errno_macros.html "c/error/errno macros") is stored in [errno](../../error/errno.html "c/error/errno"), ([size_t](../../types/size_t.html))-1 is returned, and the conversion state is unspecified. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c8rtomb&action=edit&section=3 "Edit section: Notes")] Notes

Calls to `c8rtomb` with a null pointer argument for s may introduce a data race with other calls to `c8rtomb` with a null pointer argument for s. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c8rtomb&action=edit&section=4 "Edit section: Example")] Example

| This section is incomplete  
Reason: no example   
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c8rtomb&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.30.1.2 The c8rtomb function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c8rtomb&action=edit&section=6 "Edit section: See also")] See also

[ mbrtoc8](mbrtoc8.html "c/string/multibyte/mbrtoc8")(C23) |  converts a narrow multibyte character to UTF-8 encoding   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbrtoc8&action=edit)  
---|---  
[C++ documentation](../../../cpp/string/multibyte/c8rtomb.html "cpp/string/multibyte/c8rtomb") for c8rtomb  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c8rtomb&oldid=181067](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c8rtomb&oldid=181067)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo no example](../../../Category%253ATodo_no_example.html "Category:Todo no example")



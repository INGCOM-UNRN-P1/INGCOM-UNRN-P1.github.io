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
**mbrtoc8**(C23)  
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
[size_t](../../types/size_t.html) mbrtoc8( char8_t* restrict pc8, const char* restrict s, [size_t](../../types/size_t.html) n,  
[mbstate_t](mbstate_t.html)* restrict ps ); |  |  (since C23)  
| |   
  
Converts a narrow multibyte character to UTF-8 encoding. 

If s is not a null pointer, inspects at most n bytes of the multibyte character string, beginning with the byte pointed to by s to determine the number of bytes necessary to complete the next multibyte character (including any shift sequences). If the function determines that the next multibyte character in s is complete and valid, converts it to UTF-8 and stores the first UTF-8 code unit in *pc8 (if pc8 is not null). 

If UTF-8 encoding of the multibyte character in *s consists of more than one UTF-8 code unit, then after the first call to this function, *ps is updated in such a way that the next call to `mbrtoc8` will write out the additional UTF-8 code units, without considering *s. 

If s is a null pointer, the values of n and pc8 are ignored and the call is equivalent to mbrtoc8(nullptr, "", 1, ps). 

If UTF-8 code unit produced is u8'\0', the conversion state *ps represents the initial shift state. 

The multibyte encoding used by this function is specified by the currently active C locale. 

## Contents

  * [1 Parameters](mbrtoc8.html#Parameters)
  * [2 Return value](mbrtoc8.html#Return_value)
  * [3 Example](mbrtoc8.html#Example)
  * [4 References](mbrtoc8.html#References)
  * [5 See also](mbrtoc8.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc8&action=edit&section=1 "Edit section: Parameters")] Parameters

pc8  |  \-  |  pointer to the location where the resulting UTF-8 code units will be written   
---|---|---  
s  |  \-  |  pointer to the multibyte character string used as input   
n  |  \-  |  limit on the number of bytes in s that can be examined   
ps  |  \-  |  pointer to the conversion state object used when interpreting the multibyte string   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc8&action=edit&section=2 "Edit section: Return value")] Return value

The first of the following that applies: 

  * ​0​ if the character converted from s (and stored in *pc8 if non-null) was the null character. 
  * The number of bytes `[`1`, `n`]` of the multibyte character successfully converted from s. 
  * ([size_t](../../types/size_t.html))-3 if the next UTF-8 code unit from a character whose encoding consists of multiple code units has now been written to *pc8. No bytes are processed from the input in this case. 
  * ([size_t](../../types/size_t.html))-2 if the next n bytes constitute an incomplete, but so far valid, multibyte character. Nothing is written to *pc8. 
  * ([size_t](../../types/size_t.html))-1 if encoding error occurs. Nothing is written to *pc8, the value [EILSEQ](../../error/errno_macros.html "c/error/errno macros") is stored in [errno](../../error/errno.html "c/error/errno") and the value of *ps is unspecified. 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc8&action=edit&section=3 "Edit section: Example")] Example

| This section is incomplete  
Reason: no example   
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc8&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.30.1.1 The mbrtoc8 function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc8&action=edit&section=5 "Edit section: See also")] See also

[ c8rtomb](c8rtomb.html "c/string/multibyte/c8rtomb")(C23) |  converts UTF-8 string to narrow multibyte encoding   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_c8rtomb&action=edit)  
---|---  
[C++ documentation](../../../cpp/string/multibyte/mbrtoc8.html "cpp/string/multibyte/mbrtoc8") for mbrtoc8  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc8&oldid=181065](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc8&oldid=181065)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo no example](../../../Category%253ATodo_no_example.html "Category:Todo no example")



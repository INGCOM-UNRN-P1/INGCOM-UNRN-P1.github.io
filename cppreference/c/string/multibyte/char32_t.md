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
| [mbstate_t](mbstate_t.html "c/string/multibyte/mbstate t")(C95)  
---  
[char8_t](char8_t.html "c/string/multibyte/char8 t")(C23)  
  
| [char16_t](char16_t.html "c/string/multibyte/char16 t")(C11)  
---  
**char32_t**(C11)  
  
[Macros](../multibyte.html#Macros "c/string/multibyte")  
| [MB_LEN_MAX](../multibyte.html#Macros "c/string/multibyte")  
---  
  
| [MB_CUR_MAX](../multibyte.html#Macros "c/string/multibyte")  
---  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/navbar_content&action=edit)

Defined in header `[`<uchar.h>`](../../header/uchar.html "c/header/uchar")` |  |   
---|---|---  
typedef [uint_least32_t](../../types/integer.html) char32_t; |  |  (since C11)  
| |   
  
char32_t is an unsigned integer type used for 32-bit wide characters and is the same type as [uint_least32_t](../../types/integer.html). 

## Contents

  * [1 Notes](char32_t.html#Notes)
  * [2 Example](char32_t.html#Example)
  * [3 References](char32_t.html#References)
  * [4 See also](char32_t.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/char32_t&action=edit&section=1 "Edit section: Notes")] Notes

On any given platform, by the definition of [uint_least32_t](../../types/integer.html), the width of type char32_t can be greater than 32 bits, but the actual values stored in an object of type char32_t will always have a width of 32 bits. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/char32_t&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <uchar.h>
     
    int main(void)
    {
        const char32_t wc[] = U"zß水🍌"; // or "z\u00df\u6c34\U0001f34c"
        const [size_t](../../types/size_t.html) wc_sz = sizeof wc / sizeof *wc;
        [printf](../../io/fprintf.html)("%zu UTF-32 code units: [ ", wc_sz);
        for ([size_t](../../types/size_t.html) n = 0; n < wc_sz; ++n)
            [printf](../../io/fprintf.html)("%#x ", wc[n]);
        [printf](../../io/fprintf.html)("]\n");
    }

Possible output: 
    
    
    5 UTF-32 code units: [ 0x7a 0xdf 0x6c34 0x1f34c 0 ]

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/char32_t&action=edit&section=3 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.28 Unicode utilities <uchar.h> (p: 292) 



    

  * 7.20.1.2 Minimum-width integer types (p: 212-213) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.28 Unicode utilities <uchar.h> (p: 398) 



    

  * 7.20.1.2 Minimum-width integer types (p: 290) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.18.1.2 Minimum-width integer types (p: 256) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/char32_t&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../../cpp/language/types.html "cpp/language/types") for Fundamental types  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/char32_t&oldid=149703](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/char32_t&oldid=149703)" 

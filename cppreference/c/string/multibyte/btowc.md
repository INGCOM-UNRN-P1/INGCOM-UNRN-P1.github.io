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
**btowc**(C95)  
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
[char32_t](char32_t.html "c/string/multibyte/char32 t")(C11)  
  
[Macros](../multibyte.html#Macros "c/string/multibyte")  
| [MB_LEN_MAX](../multibyte.html#Macros "c/string/multibyte")  
---  
  
| [MB_CUR_MAX](../multibyte.html#Macros "c/string/multibyte")  
---  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/navbar_content&action=edit)

Defined in header `[`<wchar.h>`](../../header/wchar.html "c/header/wchar")` |  |   
---|---|---  
wint_t btowc( int c ); |  |  (since C95)  
| |   
  
Widens a single-byte character `c` (reinterpreted as unsigned char) to its wide character equivalent. 

Most multibyte character encodings use single-byte codes to represent the characters from the ASCII character set. This function may be used to convert such characters to wchar_t. 

## Contents

  * [1 Parameters](btowc.html#Parameters)
  * [2 Return value](btowc.html#Return_value)
  * [3 Example](btowc.html#Example)
  * [4 References](btowc.html#References)
  * [5 See also](btowc.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/btowc&action=edit&section=1 "Edit section: Parameters")] Parameters

c  |  \-  |  single-byte character to widen   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/btowc&action=edit&section=2 "Edit section: Return value")] Return value

WEOF if `c` is [EOF](../../io.html "c/io")

wide character representation of `c` if (unsigned char)c is a valid single-byte character in the initial shift state, WEOF otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/btowc&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <wchar.h>
    #include <locale.h>
    #include <assert.h>
     
    void try_widen(unsigned char c)
    {
        wint_t w = btowc(c);
        if(w != WEOF)
            [printf](../../io/fprintf.html)("The single-byte character %#x widens to %#x\n", c, w);
        else
            [printf](../../io/fprintf.html)("The single-byte character %#x failed to widen\n", c);
    }
     
    int main(void)
    {
        char *loc = [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "lt_LT.iso88594");
        [assert](../../error/assert.html)(loc);
        [printf](../../io/fprintf.html)("In Lithuanian ISO-8859-4 locale:\n");
        try_widen('A');
        try_widen('\xdf'); // German letter ß (U+00df) in ISO-8859-4
        try_widen('\xf9'); // Lithuanian letter ų (U+0173) in ISO-8859-4
     
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "lt_LT.utf8");
        [printf](../../io/fprintf.html)("In Lithuanian UTF-8 locale:\n");
        try_widen('A');
        try_widen('\xdf');
        try_widen('\xf9');
    }

Possible output: 
    
    
    In Lithuanian ISO-8859-4 locale:
    The single-byte character 0x41 widens to 0x41
    The single-byte character 0xdf widens to 0xdf
    The single-byte character 0xf9 widens to 0x173
    In Lithuanian UTF-8 locale:
    The single-byte character 0x41 widens to 0x41
    The single-byte character 0xdf failed to widen
    The single-byte character 0xf9 failed to widen

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/btowc&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.29.6.1.1 The btowc function (p: 441) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.24.6.1.1 The btowc function (p: 387) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/btowc&action=edit&section=5 "Edit section: See also")] See also

[ wctob](wctob.html "c/string/multibyte/wctob")(C95) |  narrows a wide character to a single-byte narrow character, if possible   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_wctob&action=edit)  
---|---  
[C++ documentation](../../../cpp/string/multibyte/btowc.html "cpp/string/multibyte/btowc") for btowc  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/btowc&oldid=76790](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/btowc&oldid=76790)" 

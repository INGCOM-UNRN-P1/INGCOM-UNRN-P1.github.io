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
**wctob**(C95)  
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
int wctob( wint_t c ); |  |  (since C95)  
| |   
  
Narrows a wide character `c` if its multibyte character equivalent in the initial shift state is a single byte. 

This is typically possible for the characters from the ASCII character set, since most multibyte encodings (such as UTF-8) use single bytes to encode those characters. 

## Contents

  * [1 Parameters](wctob.html#Parameters)
  * [2 Return value](wctob.html#Return_value)
  * [3 Example](wctob.html#Example)
  * [4 References](wctob.html#References)
  * [5 See also](wctob.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctob&action=edit&section=1 "Edit section: Parameters")] Parameters

c  |  \-  |  wide character to narrow   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctob&action=edit&section=2 "Edit section: Return value")] Return value

[EOF](../../io.html "c/io") if `c` does not represent a multibyte character with length 1 in initial shift state. 

otherwise, the single-byte representation of `c` as unsigned char converted to int

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctob&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <locale.h>
    #include <wchar.h>
    #include <stdio.h>
    #include <assert.h>
     
    void try_narrowing(wchar_t c)
    {
        int cn = wctob(c);
        if(cn != [EOF](../../io.html))
            [printf](../../io/fprintf.html)("%#x narrowed to %#x\n", c, cn);
        else
            [printf](../../io/fprintf.html)("%#x could not be narrowed\n", c);
    }
     
    int main(void)
    {
        char* utf_locale_present = [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "th_TH.utf8");
        [assert](../../error/assert.html)(utf_locale_present);
        [puts](../../io/puts.html)("In Thai UTF-8 locale:");
        try_narrowing(L'a');
        try_narrowing(L'๛');
     
        char* tis_locale_present = [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "th_TH.tis620");
        [assert](../../error/assert.html)(tis_locale_present);
        [puts](../../io/puts.html)("In Thai TIS-620 locale:");
        try_narrowing(L'a');
        try_narrowing(L'๛');
    }

Possible output: 
    
    
    In Thai UTF-8 locale:
    0x61 narrowed to 0x61
    0xe5b could not be narrowed
    In Thai TIS-620 locale:
    0x61 narrowed to 0x61
    0xe5b narrowed to 0xfb

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctob&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.29.6.1.2 The wctob function (p: 441) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.24.6.1.2 The wctob function (p: 387) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctob&action=edit&section=5 "Edit section: See also")] See also

[ btowc](btowc.html "c/string/multibyte/btowc")(C95) |  widens a single-byte narrow character to wide character, if possible   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_btowc&action=edit)  
---|---  
[C++ documentation](../../../cpp/string/multibyte/wctob.html "cpp/string/multibyte/wctob") for wctob  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctob&oldid=76791](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctob&oldid=76791)" 

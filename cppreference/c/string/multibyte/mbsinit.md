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
**mbsinit**(C95)  
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
[char32_t](char32_t.html "c/string/multibyte/char32 t")(C11)  
  
[Macros](../multibyte.html#Macros "c/string/multibyte")  
| [MB_LEN_MAX](../multibyte.html#Macros "c/string/multibyte")  
---  
  
| [MB_CUR_MAX](../multibyte.html#Macros "c/string/multibyte")  
---  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/navbar_content&action=edit)

Defined in header `[`<wchar.h>`](../../header/wchar.html "c/header/wchar")` |  |   
---|---|---  
int mbsinit( const [mbstate_t](mbstate_t.html)* ps); |  |  (since C95)  
| |   
  
If `ps` is not a null pointer, the `mbsinit` function determines whether the pointed-to [mbstate_t](mbstate_t.html "c/string/multibyte/mbstate t") object describes the initial conversion state. 

## Contents

  * [1 Notes](mbsinit.html#Notes)
  * [2 Parameters](mbsinit.html#Parameters)
  * [3 Return value](mbsinit.html#Return_value)
  * [4 Example](mbsinit.html#Example)
  * [5 References](mbsinit.html#References)
  * [6 See also](mbsinit.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsinit&action=edit&section=1 "Edit section: Notes")] Notes

Although a zero-initialized [mbstate_t](mbstate_t.html "c/string/multibyte/mbstate t") always represents the initial conversion state, there may be other values of [mbstate_t](mbstate_t.html "c/string/multibyte/mbstate t") that also represent the initial conversion state. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsinit&action=edit&section=2 "Edit section: Parameters")] Parameters

ps  |  \-  |  pointer to the mbstate_t object to examine   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsinit&action=edit&section=3 "Edit section: Return value")] Return value

​0​ if `ps` is not a null pointer and does not represent the initial conversion state, nonzero value otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsinit&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <locale.h>
    #include <string.h>
    #include <stdio.h>
    #include <wchar.h>
     
    int main(void)
    {
        // allow mbrlen() to work with UTF-8 multibyte encoding
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.utf8");
        // UTF-8 narrow multibyte encoding
        const char* str = u8"水"; // or u8"\u6c34" or "\xe6\xb0\xb4"
        static [mbstate_t](mbstate_t.html) mb; // zero-initialize
        (void)[mbrlen](mbrlen.html)(&str[0], 1, &mb);
        if (!mbsinit(&mb)) {
            [printf](../../io/fprintf.html)("After processing the first 1 byte of %s,\n"
                   "the conversion state is not initial\n\n", str);
        }
     
        (void)[mbrlen](mbrlen.html)(&str[1], [strlen](../byte/strlen.html)(str), &mb);
        if (mbsinit(&mb)) {
            [printf](../../io/fprintf.html)("After processing the remaining 2 bytes of %s,\n"
                   "the conversion state is initial conversion state\n", str);
        }
    }

Output: 
    
    
    After processing the first 1 byte of 水,
    the conversion state is not initial
     
    After processing the remaining 2 bytes of 水,
    the conversion state is initial conversion state

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsinit&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.29.6.2.1 The mbsinit function (p: 322) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.29.6.2.1 The mbsinit function (p: 441-442) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.24.6.2.1 The mbsinit function (p: 387-388) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsinit&action=edit&section=6 "Edit section: See also")] See also

[ mbstate_t](mbstate_t.html "c/string/multibyte/mbstate t")(C95) |  conversion state information necessary to iterate multibyte character strings   
(class) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbstate_t&action=edit)  
---|---  
[C++ documentation](../../../cpp/string/multibyte/mbsinit.html "cpp/string/multibyte/mbsinit") for mbsinit  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsinit&oldid=133920](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsinit&oldid=133920)" 

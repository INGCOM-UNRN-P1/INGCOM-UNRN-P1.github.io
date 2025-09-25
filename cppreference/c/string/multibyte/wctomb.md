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
**wctomb wctomb_s**(C11)  
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

Defined in header `[`<stdlib.h>`](../../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
int wctomb( char *s, wchar_t wc ); |  (1)  |   
errno_t wctomb_s( int *restrict status, char *restrict s, rsize_t ssz, wchar_t wc ); |  (2)  |  (since C11)  
| |   
  
1) Converts a wide character `wc` to multibyte encoding and stores it (including any shift sequences) in the char array whose first element is pointed to by `s`. No more than MB_CUR_MAX characters are stored. The conversion is affected by the current locale's LC_CTYPE category. 

If `wc` is the null character, the null byte is written to `s`, preceded by any shift sequences necessary to restore the initial shift state.

If `s` is a null pointer, this function resets the global conversion state and determines whether shift sequences are used.

2) Same as (1), except that the result is returned in the out-parameter `status` and the following errors are detected at runtime and call the currently installed [constraint handler](../../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * `ssz` is less than the number of bytes that would be written (unless `s` is null) 
  * `ssz` is greater than RSIZE_MAX (unless `s` is null) 
  * `s` is a null pointer but `ssz` is not zero 


    As with all bounds-checked functions, `wctomb_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<stdlib.h>`](../../header/stdlib.html "c/header/stdlib").

## Contents

  * [1 Notes](wctomb.html#Notes)
  * [2 Parameters](wctomb.html#Parameters)
  * [3 Return value](wctomb.html#Return_value)
  * [4 Example](wctomb.html#Example)
  * [5 References](wctomb.html#References)
  * [6 See also](wctomb.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctomb&action=edit&section=1 "Edit section: Notes")] Notes

Each call to `wctomb` updates the internal global conversion state (a static object of type [mbstate_t](mbstate_t.html "c/string/multibyte/mbstate t"), known only to this function). If the multibyte encoding uses shift states, this function is not reentrant. In any case, multiple threads should not call `wctomb` without synchronization: [wcrtomb](wcrtomb.html "c/string/multibyte/wcrtomb") or `wctomb_s` may be used instead. 

Unlike most bounds-checked functions, `wctomb_s` does not null-terminate its output, because it is designed to be used in loops that process strings character-by-character. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctomb&action=edit&section=2 "Edit section: Parameters")] Parameters

s  |  \-  |  pointer to the character array for output   
---|---|---  
wc  |  \-  |  wide character to convert   
ssz  |  \-  |  maximum number of bytes to write to `s` (size of the array `s`)   
status  |  \-  |  pointer to an out-parameter where the result (length of the multibyte sequence or the shift sequence status) will be stored   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctomb&action=edit&section=3 "Edit section: Return value")] Return value

1) If `s` is not a null pointer, returns the number of bytes that are contained in the multibyte representation of `wc` or -1 if `wc` is not a valid character.

If `s` is a null pointer, resets its internal conversion state to represent the initial shift state and returns ​0​ if the current multibyte encoding is not state-dependent (does not use shift sequences) or a non-zero value if the current multibyte encoding is state-dependent (uses shift sequences).

2) zero on success, in which case the multibyte representation of `wc` is stored in `s` and its length is stored in *status, or, if `s` is null, the shift sequence status is stored in `status`). Non-zero on encoding error or runtime constraint violation, in which case ([size_t](../../types/size_t.html))-1 is stored in *status. The value stored in *status never exceeds MB_CUR_MAX

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctomb&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>
     
    void demo(wchar_t wc)
    {
        const char* dep = wctomb([NULL](../../types/NULL.html), wc) ? "Yes" : "No";
        [printf](../../io/fprintf.html)("State-dependent encoding? %s.\n", dep);
     
        char mb[MB_CUR_MAX];
        int len = wctomb(mb, wc);
        [printf](../../io/fprintf.html)("wide char '%lc' -> multibyte char [", wc);
        for (int idx = 0; idx < len; ++idx)
            [printf](../../io/fprintf.html)("%s%#2x", idx ? " " : "", (unsigned char)mb[idx]);
        [printf](../../io/fprintf.html)("]\n");
    }
     
    int main(void)
    {
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.utf8");
        [printf](../../io/fprintf.html)("MB_CUR_MAX = %zu\n", MB_CUR_MAX);
        demo(L'A');
        demo(L'\u00df');
        demo(L'\U0001d10b');
    }

Possible output: 
    
    
    MB_CUR_MAX = 6
    State-dependent encoding? No.
    wide char 'A' -> multibyte char [0x41]
    State-dependent encoding? No.
    wide char 'ß' -> multibyte char [0xc3 0x9f]
    State-dependent encoding? No.
    wide char '𝄋' -> multibyte char [0xf0 0x9d 0x84 0x8b]

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctomb&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.7.3 The wctomb function (p: 261) 



    

  * K.3.6.4.1 The wctomb_s function (p: 443) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.7.3 The wctomb function (p: 358-359) 



    

  * K.3.6.4.1 The wctomb_s function (p: 610-611) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.7.3 The wctomb function (p: 322-323) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.7.3 The wctomb function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctomb&action=edit&section=6 "Edit section: See also")] See also

[ mbtowc](mbtowc.html "c/string/multibyte/mbtowc") |  converts the next multibyte character to wide character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbtowc&action=edit)  
---|---  
[ wcrtombwcrtomb_s](wcrtomb.html "c/string/multibyte/wcrtomb")(C95)(C11) |  converts a wide character to its multibyte representation, given state   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_wcrtomb&action=edit)  
[C++ documentation](../../../cpp/string/multibyte/wctomb.html "cpp/string/multibyte/wctomb") for wctomb  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctomb&oldid=133917](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wctomb&oldid=133917)" 

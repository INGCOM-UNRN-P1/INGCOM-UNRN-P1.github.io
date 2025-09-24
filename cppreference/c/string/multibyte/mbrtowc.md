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
**mbrtowc**(C95)  
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
[size_t](../../types/size_t.html) mbrtowc( wchar_t* pwc, const char* s, [size_t](../../types/size_t.html) n, [mbstate_t](mbstate_t.html)* ps ); |  |  (since C95)  
[size_t](../../types/size_t.html) mbrtowc( wchar_t *restrict pwc, const char *restrict s, [size_t](../../types/size_t.html) n,  
[mbstate_t](mbstate_t.html) *restrict ps ); |  |  (since C99)  
| |   
  
Converts a narrow multibyte character to its wide character representation. 

If `s` is not a null pointer, inspects at most `n` bytes of the multibyte character string, beginning with the byte pointed to by `s` to determine the number of bytes necessary to complete the next multibyte character (including any shift sequences, and taking into account the current multibyte conversion state *ps). If the function determines that the next multibyte character in `s` is complete and valid, converts it to the corresponding wide character and stores it in *pwc (if `pwc` is not null). 

If `s` is a null pointer, the values of `n` and `pwc` are ignored and call is equivalent to mbrtowc([NULL](../../types/NULL.html), "", 1, ps). 

If the wide character produced is the null character, the conversion state stored in *ps is the initial shift state. 

If the environment macro __STDC_ISO_10646__ is defined, the values of type wchar_t are the same as the short identifiers of the characters in the Unicode required set (typically UTF-32 encoding); otherwise, it is implementation-defined. In any case, the multibyte character encoding used by this function is specified by the currently active C locale. 

## Contents

  * [1 Parameters](mbrtowc.html#Parameters)
  * [2 Return value](mbrtowc.html#Return_value)
  * [3 Example](mbrtowc.html#Example)
  * [4 References](mbrtowc.html#References)
  * [5 See also](mbrtowc.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtowc&action=edit&section=1 "Edit section: Parameters")] Parameters

pwc  |  \-  |  pointer to the location where the resulting wide character will be written   
---|---|---  
s  |  \-  |  pointer to the multibyte character string used as input   
n  |  \-  |  limit on the number of bytes in s that can be examined   
ps  |  \-  |  pointer to the conversion state used when interpreting the multibyte character string   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtowc&action=edit&section=2 "Edit section: Return value")] Return value

The first of the following that applies: 

  * ​0​ if the character converted from `s` (and stored in pwc if non-null) was the null character 
  * the number of bytes [1...n] of the multibyte character successfully converted from `s`
  * ([size_t](../../types/size_t.html))-2 if the next `n` bytes constitute an incomplete, but so far valid, multibyte character. Nothing is written to *pwc. 
  * ([size_t](../../types/size_t.html))-1 if encoding error occurs. Nothing is written to `*pwc`, the value [EILSEQ](../../error/errno_macros.html "c/error/errno macros") is stored in [errno](../../error/errno.html "c/error/errno") and the value of *ps is left unspecified. 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtowc&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <locale.h>
    #include <string.h>
    #include <wchar.h>
     
    int main(void)
    {
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.utf8");
        [mbstate_t](mbstate_t.html) state;
        [memset](../byte/memset.html)(&state, 0, sizeof state);
        char in[] = u8"z\u00df\u6c34\U0001F34C"; // or u8"zß水🍌"
        [size_t](../../types/size_t.html) in_sz = sizeof in / sizeof *in;
     
        [printf](../../io/fprintf.html)("Processing %zu UTF-8 code units: [ ", in_sz);
        for([size_t](../../types/size_t.html) n = 0; n < in_sz; ++n) [printf](../../io/fprintf.html)("%#x ", (unsigned char)in[n]);
        [puts](../../io/puts.html)("]");
     
        wchar_t out[in_sz];
        char *p_in = in, *end = in + in_sz;
        wchar_t *p_out = out;
        int rc;
        while((rc = mbrtowc(p_out, p_in, end - p_in, &state)) > 0)
        {
            p_in += rc;
            p_out += 1;
        }
     
        [size_t](../../types/size_t.html) out_sz = p_out - out + 1;
        [printf](../../io/fprintf.html)("into %zu wchar_t units: [ ", out_sz);
        for([size_t](../../types/size_t.html) x = 0; x < out_sz; ++x) [printf](../../io/fprintf.html)("%#x ", out[x]);
        [puts](../../io/puts.html)("]");
    }

Output: 
    
    
    Processing 11 UTF-8 code units: [ 0x7a 0xc3 0x9f 0xe6 0xb0 0xb4 0xf0 0x9f 0x8d 0x8c 0 ]
    into 5 wchar_t units: [ 0x7a 0xdf 0x6c34 0x1f34c 0 ]

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtowc&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.29.6.3.2 The mbrtowc function (p: 443) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.24.6.3.2 The mbrtowc function (p: 389) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtowc&action=edit&section=5 "Edit section: See also")] See also

[ mbtowc](mbtowc.html "c/string/multibyte/mbtowc") |  converts the next multibyte character to wide character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbtowc&action=edit)  
---|---  
[ wcrtombwcrtomb_s](wcrtomb.html "c/string/multibyte/wcrtomb")(C95)(C11) |  converts a wide character to its multibyte representation, given state   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_wcrtomb&action=edit)  
[C++ documentation](../../../cpp/string/multibyte/mbrtowc.html "cpp/string/multibyte/mbrtowc") for mbrtowc  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtowc&oldid=95803](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtowc&oldid=95803)" 

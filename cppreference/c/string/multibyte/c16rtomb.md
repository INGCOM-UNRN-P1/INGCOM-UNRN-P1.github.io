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
**c16rtomb**(C11)  
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
[size_t](../../types/size_t.html) c16rtomb( char* restrict s, char16_t c16, [mbstate_t](mbstate_t.html)* restrict ps ); |  |  (since C11)  
| |   
  
Converts a single code point from its variable-length 16-bit wide character representation (typically, UTF-16) to its narrow multibyte character representation. 

If s is not a null pointer and c16 is the last 16-bit code unit in a valid variable-length encoding of a code point, the function determines the number of bytes necessary to store the multibyte character representation of that code point (including any shift sequences, and taking into account the current multibyte conversion state *ps), and stores the multibyte character representation in the character array whose first element is pointed to by s, updating *ps as necessary. At most MB_CUR_MAX bytes can be written by this function. 

If s is a null pointer, the call is equivalent to c16rtomb(buf, u'\0', ps) for some internal buffer buf. 

If c16 is the null wide character u'\0', a null byte is stored, preceded by any shift sequence necessary to restore the initial shift state and the conversion state parameter *ps is updated to represent the initial shift state. 

If c16 is not the final code unit in a 16-bit representation of a wide character, it does not write to the array pointed to by s, only *ps is updated. 

If the macro __STDC_UTF_16__ is defined, the 16-bit encoding used by this function is UTF-16; otherwise, it is implementation-defined. The macro is always defined and the encoding is always UTF-16.(since C23) In any case, the multibyte character encoding used by this function is specified by the currently active C locale. 

## Contents

  * [1 Parameters](c16rtomb.html#Parameters)
  * [2 Return value](c16rtomb.html#Return_value)
  * [3 Notes](c16rtomb.html#Notes)
  * [4 Example](c16rtomb.html#Example)
  * [5 References](c16rtomb.html#References)
  * [6 See also](c16rtomb.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c16rtomb&action=edit&section=1 "Edit section: Parameters")] Parameters

s  |  \-  |  pointer to narrow character array where the multibyte character will be stored   
---|---|---  
c16  |  \-  |  the 16-bit wide character to convert   
ps  |  \-  |  pointer to the conversion state object used when interpreting the multibyte string   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c16rtomb&action=edit&section=2 "Edit section: Return value")] Return value

On success, returns the number of bytes (including any shift sequences) written to the character array whose first element is pointed to by s. This value may be ​0​, e.g. when processing the leading char16_t units in a multi-char16_t-unit sequence (occurs when processing the leading surrogate in a surrogate pair of UTF-16). 

On failure (if c16 is not a valid 16-bit code unit), returns -1, stores [EILSEQ](../../error/errno_macros.html "c/error/errno macros") in [errno](../../error/errno.html "c/error/errno"), and leaves *ps in unspecified state. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c16rtomb&action=edit&section=3 "Edit section: Notes")] Notes

In C11 as published, unlike [mbrtoc16](mbrtoc16.html "c/string/multibyte/mbrtoc16"), which converts variable-width multibyte (such as UTF-8) to variable-width 16-bit (such as UTF-16) encoding, this function can only convert single-unit 16-bit encoding, meaning it cannot convert UTF-16 to UTF-8 despite that being the original intent of this function. This was corrected by the post-C11 defect report [DR488](https://open-std.org/JTC1/SC22/WG14/www/docs/n2059.htm#dr_488). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c16rtomb&action=edit&section=4 "Edit section: Example")] Example

Note: this example assumes the fix for the defect report [DR488](https://open-std.org/JTC1/SC22/WG14/www/docs/n2059.htm#dr_488) is applied.  
On MSVC you may need the `/utf-8` compiler flag for UTF_8 to work properly.

Run this code
    
    
    #include <locale.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <uchar.h>
     
    int main(void)
    {
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.utf8");
        const char16_t in[] = u"zß水🍌"; // or "z\u00df\u6c34\U0001F34C"
        const [size_t](../../types/size_t.html) in_sz = sizeof in / sizeof *in;
     
        [printf](../../io/fprintf.html)("Processing %zu UTF-16 code units: [", in_sz);
        for ([size_t](../../types/size_t.html) n = 0; n < in_sz; ++n)
            [printf](../../io/fprintf.html)("%s%04X", n ? " " : "", in[n]);
        [puts](../../io/puts.html)("]");
     
        char* out = [malloc](../../memory/malloc.html)(MB_CUR_MAX * in_sz);
        char* p = out;
        [mbstate_t](mbstate_t.html) state = {0};
     
        for ([size_t](../../types/size_t.html) n = 0; n < in_sz; ++n)
        {
            [size_t](../../types/size_t.html) rc = c16rtomb(p, in[n], &state);
            if (rc == ([size_t](../../types/size_t.html))-1)
                break;
            p += rc;
        }
     
        [size_t](../../types/size_t.html) out_sz = p - out;
        [printf](../../io/fprintf.html)("into %zu UTF-8 code units: [", out_sz);
        for ([size_t](../../types/size_t.html) x = 0; x < out_sz; ++x)
            [printf](../../io/fprintf.html)("%s%02X", x ? " " : "", +(unsigned char)out[x]);
        [puts](../../io/puts.html)("]");
        [free](../../memory/free.html)(out);
    }

Output: 
    
    
    Processing 6 UTF-16 code units: [007A 00DF 6C34 D83C DF4C 0000]
    into 13 UTF-8 code units: [7A C3 9F E6 B0 B4 ED A0 BC ED BD 8C 00]

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c16rtomb&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.28.1.2 The c16rtomb function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.28.1.2 The c16rtomb function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.28.1.2 The c16rtomb function (p: 399-400) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c16rtomb&action=edit&section=6 "Edit section: See also")] See also

[ mbrtoc16](mbrtoc16.html "c/string/multibyte/mbrtoc16")(C11) |  converts a narrow multibyte character to UTF-16 encoding   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbrtoc16&action=edit)  
---|---  
[C++ documentation](../../../cpp/string/multibyte/c16rtomb.html "cpp/string/multibyte/c16rtomb") for c16rtomb  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c16rtomb&oldid=181006](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c16rtomb&oldid=181006)" 

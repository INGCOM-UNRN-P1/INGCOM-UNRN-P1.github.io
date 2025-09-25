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
**mbrtoc16**(C11)  
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
[size_t](../../types/size_t.html) mbrtoc16( char16_t* restrict pc16, const char* restrict s,  
[size_t](../../types/size_t.html) n, [mbstate_t](mbstate_t.html)* restrict ps ); |  |  (since C11)  
| |   
  
Converts a single code point from its narrow multibyte character representation to its variable-length 16-bit wide character representation (typically, UTF-16). 

If s is not a null pointer, inspects at most n bytes of the multibyte character string, beginning with the byte pointed to by s to determine the number of bytes necessary to complete the next multibyte character (including any shift sequences, and taking into account the current multibyte conversion state *ps). If the function determines that the next multibyte character in s is complete and valid, converts it to the corresponding 16-bit wide character and stores it in *pc16 (if pc16 is not null). 

If the multibyte character in *s corresponds to a multi-char16_t sequence (e.g. a surrogate pair in UTF-16), then after the first call to this function, *ps is updated in such a way that the next call to `mbrtoc16` will write out the additional char16_t, without considering *s. 

If s is a null pointer, the values of n and pc16 are ignored and the call is equivalent to mbrtoc16([NULL](../../types/NULL.html), "", 1, ps). 

If the wide character produced is the null character, the conversion state *ps represents the initial shift state. 

If the macro __STDC_UTF_16__ is defined, the 16-bit encoding used by this function is UTF-16; otherwise, it is implementation-defined. The macro is always defined and the encoding is always UTF-16.(since C23) In any case, the multibyte character encoding used by this function is specified by the currently active C locale. 

## Contents

  * [1 Parameters](mbrtoc16.html#Parameters)
  * [2 Return value](mbrtoc16.html#Return_value)
  * [3 Example](mbrtoc16.html#Example)
  * [4 References](mbrtoc16.html#References)
  * [5 See also](mbrtoc16.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc16&action=edit&section=1 "Edit section: Parameters")] Parameters

pc16  |  \-  |  pointer to the location where the resulting 16-bit wide character will be written   
---|---|---  
s  |  \-  |  pointer to the multibyte character string used as input   
n  |  \-  |  limit on the number of bytes in s that can be examined   
ps  |  \-  |  pointer to the conversion state object used when interpreting the multibyte string   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc16&action=edit&section=2 "Edit section: Return value")] Return value

The first of the following that applies: 

  * ​0​ if the character converted from s (and stored in *pc16 if non-null) was the null character. 
  * The number of bytes `[`1`, `n`]` of the multibyte character successfully converted from s. 
  * ([size_t](../../types/size_t.html))-3 if the next char16_t from a multi-char16_t character (e.g. a surrogate pair) has now been written to *pc16. No bytes are processed from the input in this case. 
  * ([size_t](../../types/size_t.html))-2 if the next n bytes constitute an incomplete, but so far valid, multibyte character. Nothing is written to *pc16. 
  * ([size_t](../../types/size_t.html))-1 if encoding error occurs. Nothing is written to *pc16, the value [EILSEQ](../../error/errno_macros.html "c/error/errno macros") is stored in [errno](../../error/errno.html "c/error/errno") and the value of *ps is unspecified. 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc16&action=edit&section=3 "Edit section: Example")] Example

On MSVC you may need the `/utf-8` compiler flag for UTF_8 to work properly.

Run this code
    
    
    #include <locale.h>
    #include <stdio.h>
    #include <uchar.h>
     
    int main(void)
    {
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.utf8");
        const char in[] = u8"zß水🍌"; // or "z\u00df\u6c34\U0001F34C"
        enum { in_sz = sizeof in / sizeof *in };
     
        [printf](../../io/fprintf.html)("Processing %d UTF-8 code units: [", in_sz);
        for (int n = 0; n < in_sz; ++n)
            [printf](../../io/fprintf.html)("%s%02X", n ? " " : "", (unsigned char)in[n]);
        [puts](../../io/puts.html)("]");
     
        char16_t out[in_sz];
        const char* p_in = in;
        const char* end = in + in_sz;
        char16_t* p_out = out;
        [mbstate_t](mbstate_t.html) state = {0};
     
        for ([size_t](../../types/size_t.html) rc; (rc = mbrtoc16(p_out, p_in, end - p_in, &state));)
        {
            if (rc == ([size_t](../../types/size_t.html))-1)     // invalid input
                break;
            else if(rc == ([size_t](../../types/size_t.html))-2) // truncated input
                break;
            else if(rc == ([size_t](../../types/size_t.html))-3) // UTF-16 high surrogate
                p_out += 1;
            else
            {
                p_in += rc;
                p_out += 1;
            };
        }
     
        const [size_t](../../types/size_t.html) out_sz = p_out - out + 1;
        [printf](../../io/fprintf.html)("into %zu UTF-16 code units: [", out_sz);
        for ([size_t](../../types/size_t.html) x = 0; x < out_sz; ++x)
            [printf](../../io/fprintf.html)("%s%04X", x ? " " : "", out[x]);
        [puts](../../io/puts.html)("]");
    }

Output: 
    
    
    Processing 11 UTF-8 code units: [7A C3 9F E6 B0 B4 F0 9F 8D 8C 00]
    into 6 UTF-16 code units: [007A 00DF 6C34 D83C DF4C 0000]

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc16&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.30.1.3 The mbrtoc16 function (p: 408-409) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.28.1.1 The mbrtoc16 function (p: 398-399) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc16&action=edit&section=5 "Edit section: See also")] See also

[ c16rtomb](c16rtomb.html "c/string/multibyte/c16rtomb")(C11) |  converts a UTF-16 character to narrow multibyte encoding   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_c16rtomb&action=edit)  
---|---  
[C++ documentation](../../../cpp/string/multibyte/mbrtoc16.html "cpp/string/multibyte/mbrtoc16") for mbrtoc16  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc16&oldid=181013](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc16&oldid=181013)" 

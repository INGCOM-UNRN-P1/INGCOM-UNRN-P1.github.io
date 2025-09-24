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
**mbrtoc32**(C11)  
  
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
[size_t](../../types/size_t.html) mbrtoc32( char32_t restrict* pc32, const char* restrict s,  
[size_t](../../types/size_t.html) n, [mbstate_t](mbstate_t.html)* restrict ps ); |  |  (since C11)  
| |   
  
Converts a single code point from its narrow multibyte character representation to its variable-length 32-bit wide character representation (but typically, UTF-32). 

If s is not a null pointer, inspects at most n bytes of the multibyte character string, beginning with the byte pointed to by s to determine the number of bytes necessary to complete the next multibyte character (including any shift sequences, and taking into account the current multibyte conversion state *ps). If the function determines that the next multibyte character in s is complete and valid, converts it to the corresponding 32-bit wide character and stores it in *pc32 (if pc32 is not null). 

If the multibyte character in *s corresponds to a multi-char32_t sequence (not possible with UTF-32), then after the first call to this function, *ps is updated in such a way that the next calls to `mbrtoc32` will write out the additional char32_t, without considering *s. 

If s is a null pointer, the values of n and pc32 are ignored and the call is equivalent to mbrtoc32([NULL](../../types/NULL.html), "", 1, ps). 

If the wide character produced is the null character, the conversion state *ps represents the initial shift state. 

If the macro __STDC_UTF_32__ is defined, the 32-bit encoding used by this function is UTF-32; otherwise, it is implementation-defined. The macro is always defined and the encoding is always UTF-32.(since C23) In any case, the multibyte character encoding used by this function is specified by the currently active C locale. 

## Contents

  * [1 Parameters](mbrtoc32.html#Parameters)
  * [2 Return value](mbrtoc32.html#Return_value)
  * [3 Example](mbrtoc32.html#Example)
  * [4 References](mbrtoc32.html#References)
  * [5 See also](mbrtoc32.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc32&action=edit&section=1 "Edit section: Parameters")] Parameters

pc32  |  \-  |  pointer to the location where the resulting 32-bit wide character will be written   
---|---|---  
s  |  \-  |  pointer to the multibyte character string used as input   
n  |  \-  |  limit on the number of bytes in s that can be examined   
ps  |  \-  |  pointer to the conversion state object used when interpreting the multibyte string   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc32&action=edit&section=2 "Edit section: Return value")] Return value

The first of the following that applies: 

  * ​0​ if the character converted from s (and stored in *pc32 if non-null) was the null character. 
  * The number of bytes `[`1`, `n`]` of the multibyte character successfully converted from s. 
  * ([size_t](../../types/size_t.html))-3 if the next char32_t from a multi-char32_t character has now been written to *pc32. No bytes are processed from the input in this case. 
  * ([size_t](../../types/size_t.html))-2 if the next n bytes constitute an incomplete, but so far valid, multibyte character. Nothing is written to *pc32. 
  * ([size_t](../../types/size_t.html))-1 if encoding error occurs. Nothing is written to *pc32, the value [EILSEQ](../../error/errno_macros.html "c/error/errno macros") is stored in [errno](../../error/errno.html "c/error/errno") and the value of *ps is unspecified. 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc32&action=edit&section=3 "Edit section: Example")] Example

On MSVC you will need the `/utf-8` compiler flag for UTF_8 to work properly.

Run this code
    
    
    #include <assert.h>
    #include <locale.h>
    #include <stdio.h>
    #include <uchar.h>
     
    int main(void)
    {
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.utf8");
        char in[] = u8"zß水🍌"; // or "z\u00df\u6c34\U0001F34C"
        enum { in_size = sizeof in / sizeof *in };
     
        [printf](../../io/fprintf.html)("Processing %d UTF-8 code units: [", in_size);
        for (int i = 0; i < in_size; ++i)
            [printf](../../io/fprintf.html)("%s%02X", i ? " " : "", (unsigned char)in[i]);
        [puts](../../io/puts.html)("]");
     
        char32_t out[in_size];
        char32_t* p_out = out;
        char* p_in = in;
        char* end = in + in_size;
        [mbstate_t](mbstate_t.html) state = {0};
        [size_t](../../types/size_t.html) rc;
        while ((rc = mbrtoc32(p_out, p_in, end - p_in, &state)))
        {
            [assert](../../error/assert.html)(rc != ([size_t](../../types/size_t.html))-3); // no surrogate pairs in UTF-32
            if (rc == ([size_t](../../types/size_t.html))-1) break; // invalid input
            if (rc == ([size_t](../../types/size_t.html))-2) break; // truncated input
            p_in += rc;
            ++p_out;
        }
     
        [size_t](../../types/size_t.html) out_size = p_out+1 - out;
        [printf](../../io/fprintf.html)("into %zu UTF-32 code units: [", out_size);
        for ([size_t](../../types/size_t.html) i = 0; i < out_size; ++i)
            [printf](../../io/fprintf.html)("%s%08X", i ? " " : "", out[i]);
        [puts](../../io/puts.html)("]");
    }

Output: 
    
    
    Processing 11 UTF-8 code units: [7A C3 9F E6 B0 B4 F0 9F 8D 8C 00]
    into 5 UTF-32 code units: [0000007A 000000DF 00006C34 0001F34C 00000000]

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc32&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.30.1.5 The mbrtoc32 function (p: 410) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.28.1.3 The mbrtoc32 function (p: 293-294) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.28.1.3 The mbrtoc32 function (p: 400-401) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc32&action=edit&section=5 "Edit section: See also")] See also

[ c32rtomb](c32rtomb.html "c/string/multibyte/c32rtomb")(C11) |  converts a UTF-32 character to narrow multibyte encoding   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_c32rtomb&action=edit)  
---|---  
[C++ documentation](../../../cpp/string/multibyte/mbrtoc32.html "cpp/string/multibyte/mbrtoc32") for mbrtoc32  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc32&oldid=181022](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrtoc32&oldid=181022)" 

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
**c32rtomb**(C11)  
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
[size_t](../../types/size_t.html) c32rtomb( char* restrict s, char32_t c32, [mbstate_t](mbstate_t.html)* restrict ps ); |  |  (since C11)  
| |   
  
Converts a single code point from its variable-length 32-bit wide character representation (but typically, UTF-32) to its narrow multibyte character representation. 

If s is not a null pointer, the function determines the number of bytes necessary to store the multibyte character representation of c32 (including any shift sequences, and taking into account the current multibyte conversion state *ps), and stores the multibyte character representation in the character array whose first element is pointed to by s, updating *ps as necessary. At most MB_CUR_MAX bytes can be written by this function. 

If s is a null pointer, the call is equivalent to c32rtomb(buf, U'\0', ps) for some internal buffer buf. 

If c32 is the null wide character U'\0', a null byte is stored, preceded by any shift sequence necessary to restore the initial shift state and the conversion state parameter *ps is updated to represent the initial shift state. 

If the macro __STDC_UTF_32__ is defined, the 32-bit encoding used by this function is UTF-32; otherwise, it is implementation-defined. The macro is always defined and the encoding is always UTF-32.(since C23) In any case, the multibyte character encoding used by this function is specified by the currently active C locale. 

## Contents

  * [1 Parameters](c32rtomb.html#Parameters)
  * [2 Return value](c32rtomb.html#Return_value)
  * [3 Example](c32rtomb.html#Example)
  * [4 References](c32rtomb.html#References)
  * [5 See also](c32rtomb.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c32rtomb&action=edit&section=1 "Edit section: Parameters")] Parameters

s  |  \-  |  pointer to narrow character array where the multibyte character will be stored   
---|---|---  
c32  |  \-  |  the 32-bit wide character to convert   
ps  |  \-  |  pointer to the conversion state object used when interpreting the multibyte string   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c32rtomb&action=edit&section=2 "Edit section: Return value")] Return value

On success, returns the number of bytes (including any shift sequences) written to the character array whose first element is pointed to by s. This value may be ​0​, e.g. when processing the leading char32_t units in a multi-char32_t-unit sequence (does not occur in UTF-32). 

On failure (if c32 is not a valid 32-bit wide character), returns -1, stores [EILSEQ](../../error/errno_macros.html "c/error/errno macros") in [errno](../../error/errno.html "c/error/errno"), and leaves *ps in unspecified state. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c32rtomb&action=edit&section=3 "Edit section: Example")] Example

On MSVC you will need the `/utf-8` compiler flag for UTF_8 to work properly.

Run this code
    
    
    #include <locale.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <uchar.h>
     
    int main(void)
    {
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.utf8");
        const char32_t in[] = U"zß水🍌"; // or "z\u00df\u6c34\U0001F34C"
        [size_t](../../types/size_t.html) in_sz = sizeof in / sizeof *in;
     
        [printf](../../io/fprintf.html)("Processing %zu UTF-32 code units: [", in_sz);
        for ([size_t](../../types/size_t.html) n = 0; n < in_sz; ++n)
            [printf](../../io/fprintf.html)("%s%08X", n ? " " : "", in[n]);
        [puts](../../io/puts.html)("]");
     
        char* out = [malloc](../../memory/malloc.html)(MB_CUR_MAX * in_sz);
        char* p = out;
        [mbstate_t](mbstate_t.html) state = {0};
     
        for ([size_t](../../types/size_t.html) n = 0; n < in_sz; ++n)
        {
            [size_t](../../types/size_t.html) rc = c32rtomb(p, in[n], &state);
            if(rc == ([size_t](../../types/size_t.html))-1) break;
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
    
    
    Processing 5 UTF-32 code units: [0000007A 000000DF 00006C34 0001F34C 00000000]
    into 11 UTF-8 code units: [7A C3 9F E6 B0 B4 F0 9F 8D 8C 00]

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c32rtomb&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.30.1.6 The c32rtomb function (p: 411) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.28.1.4 The c32rtomb function (p: 401) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c32rtomb&action=edit&section=5 "Edit section: See also")] See also

[ mbrtoc32](mbrtoc32.html "c/string/multibyte/mbrtoc32")(C11) |  converts a narrow multibyte character to UTF-32 encoding   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbrtoc32&action=edit)  
---|---  
[C++ documentation](../../../cpp/string/multibyte/c32rtomb.html "cpp/string/multibyte/c32rtomb") for c32rtomb  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c32rtomb&oldid=181020](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/c32rtomb&oldid=181020)" 

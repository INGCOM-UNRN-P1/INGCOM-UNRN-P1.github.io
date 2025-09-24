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
**wcrtomb wcrtomb_s**(C95)(C11)  
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
| (1) |   
[size_t](../../types/size_t.html) wcrtomb( char *s, wchar_t wc, [mbstate_t](mbstate_t.html) *ps); |  |  (since C95)  
[size_t](../../types/size_t.html) wcrtomb( char *restrict s, wchar_t wc, [mbstate_t](mbstate_t.html) *restrict ps); |  |  (since C99)  
errno_t wcrtomb_s([size_t](../../types/size_t.html) *restrict retval, char *restrict s, rsize_t ssz,  
wchar_t wc, [mbstate_t](mbstate_t.html) *restrict ps); |  (2)  |  (since C11)  
| |   
  
Converts a wide character to its narrow multibyte representation. 

1) If `s` is not a null pointer, the function determines the number of bytes necessary to store the multibyte character representation of `wc` (including any shift sequences, and taking into account the current multibyte conversion state *ps), and stores the multibyte character representation in the character array whose first element is pointed to by `s`, updating *ps as necessary. At most MB_CUR_MAX bytes can be written by this function.

If `s` is a null pointer, the call is equivalent to wcrtomb(buf, L'\0', ps) for some internal buffer `buf`.

If wc is the null wide character L'\0', a null byte is stored, preceded by any shift sequence necessary to restore the initial shift state and the conversion state parameter *ps is updated to represent the initial shift state.

If the environment macro __STDC_ISO_10646__ is defined, the values of type wchar_t are the same as the short identifiers of the characters in the Unicode required set (typically UTF-32 encoding); otherwise, it is implementation-defined. In any case, the multibyte character encoding used by this function is specified by the currently active C locale.

2) Same as (1), except that

if `s` is a null pointer, the call is equivalent to wcrtomb_s(&retval, buf, sizeof buf, L'\0', ps) with internal variables `retval` and `buf` (whose size is greater than MB_CUR_MAX)

the result is returned in the out-parameter `retval`

the following errors are detected at runtime and call the currently installed [constraint handler](../../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * `retval` or `ps` is a null pointer. 
  * `ssz` is zero or greater than RSIZE_MAX (unless `s` is null) 
  * `ssz` is less than the number of bytes that would be written (unless `s` is null) 
  * `s` is a null pointer but `ssz` is not zero 


    As with all bounds-checked functions, `wcrtomb_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<wchar.h>`](../../header/wchar.html "c/header/wchar").

## Contents

  * [1 Parameters](wcrtomb.html#Parameters)
  * [2 Return value](wcrtomb.html#Return_value)
  * [3 Example](wcrtomb.html#Example)
  * [4 References](wcrtomb.html#References)
  * [5 See also](wcrtomb.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcrtomb&action=edit&section=1 "Edit section: Parameters")] Parameters

s  |  \-  |  pointer to narrow character array where the multibyte character will be stored   
---|---|---  
wc  |  \-  |  the wide character to convert   
ps  |  \-  |  pointer to the conversion state object used when interpreting the multibyte string   
ssz  |  \-  |  max number of bytes to write (the size of the buffer `s`)   
retval  |  \-  |  pointer to an out-parameter where the result (number of bytes in the multibyte string including any shift sequences) will be stored   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcrtomb&action=edit&section=2 "Edit section: Return value")] Return value

1) On success, returns the number of bytes (including any shift sequences) written to the character array whose first element is pointed to by `s`. 

On failure (if wc is not a valid wide character), returns ([size_t](../../types/size_t.html))-1, stores [EILSEQ](../../error/errno_macros.html "c/error/errno macros") in [errno](../../error/errno.html "c/error/errno"), and leaves *ps in unspecified state.

2) Returns zero on success and non-zero on failure, in which case, s[0] is set to '\0' (unless `s` is null or `ssz` is zero or greater than RSIZE_MAX) and *retval is set to ([size_t](../../types/size_t.html))-1 (unless `retval` is null)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcrtomb&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <locale.h>
    #include <string.h>
    #include <wchar.h>
    #include <stdlib.h>
     
    int main(void)
    {
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.utf8");
        [mbstate_t](mbstate_t.html) state;
        [memset](../byte/memset.html)(&state, 0, sizeof state);
        wchar_t in[] = L"zß水🍌"; // or "z\u00df\u6c34\U0001F34C"
        [size_t](../../types/size_t.html) in_sz = sizeof in / sizeof *in;
     
        [printf](../../io/fprintf.html)("Processing %zu wchar_t units: [ ", in_sz);
        for([size_t](../../types/size_t.html) n = 0; n < in_sz; ++n) [printf](../../io/fprintf.html)("%#x ", (unsigned int)in[n]);
        [puts](../../io/puts.html)("]");
     
        char out[MB_CUR_MAX * in_sz];
        char *p = out;
        for([size_t](../../types/size_t.html) n = 0; n < in_sz; ++n) {
            int rc = wcrtomb(p, in[n], &state); 
            if(rc == -1) break;
            p += rc;
        }
     
        [size_t](../../types/size_t.html) out_sz = p - out;
        [printf](../../io/fprintf.html)("into %zu UTF-8 code units: [ ", out_sz);
        for([size_t](../../types/size_t.html) x = 0; x < out_sz; ++x) [printf](../../io/fprintf.html)("%#x ", +(unsigned char)out[x]);
        [puts](../../io/puts.html)("]");
    }

Output: 
    
    
    Processing 5 wchar_t units: [ 0x7a 0xdf 0x6c34 0x1f34c 0 ]
    into 11 UTF-8 code units: [ 0x7a 0xc3 0x9f 0xe6 0xb0 0xb4 0xf0 0x9f 0x8d 0x8c 0 ]

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcrtomb&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.29.6.3.3 The wcrtomb function (p: 444) 



    

  * K.3.9.3.1.1 The wcrtomb_s function (p: 647-648) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.24.6.3.3 The wcrtomb function (p: 390) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcrtomb&action=edit&section=5 "Edit section: See also")] See also

[ wctombwctomb_s](wctomb.html "c/string/multibyte/wctomb")(C11) |  converts a wide character to its multibyte representation   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_wctomb&action=edit)  
---|---  
[ mbrtowc](mbrtowc.html "c/string/multibyte/mbrtowc")(C95) |  converts the next multibyte character to wide character, given state   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbrtowc&action=edit)  
[C++ documentation](../../../cpp/string/multibyte/wcrtomb.html "cpp/string/multibyte/wcrtomb") for wcrtomb  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcrtomb&oldid=101816](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcrtomb&oldid=101816)" 

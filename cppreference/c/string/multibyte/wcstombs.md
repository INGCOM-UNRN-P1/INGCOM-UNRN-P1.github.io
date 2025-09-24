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
**wcstombs wcstombs_s**(C11)  
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
| (1) |   
[size_t](../../types/size_t.html) wcstombs( char *dst, const wchar_t *src, [size_t](../../types/size_t.html) len ); |  |  (until C99)  
[size_t](../../types/size_t.html) wcstombs( char *restrict dst, const wchar_t *restrict src, [size_t](../../types/size_t.html) len ); |  |  (since C99)  
errno_t wcstombs_s( [size_t](../../types/size_t.html) *restrict retval, char *restrict dst, rsize_t dstsz,  
const wchar_t *restrict src, rsize_t len ); |  (2)  |  (since C11)  
| |   
  
1) Converts a sequence of wide characters from the array whose first element is pointed to by `src` to its narrow multibyte representation that begins in the initial shift state. Converted characters are stored in the successive elements of the char array pointed to by `dst`. No more than `len` bytes are written to the destination array.

Each character is converted as if by a call to [wctomb](wctomb.html "c/string/multibyte/wctomb"), except that the wctomb's conversion state is unaffected. The conversion stops if:

* The null character L'\0' was converted and stored. The bytes stored in this case are the unshift sequence (if necessary) followed by '\0',

* A wchar_t was found that does not correspond to a valid character in the current C locale.

* The next multibyte character to be stored would exceed `len`.

If `src` and `dst` overlap, the behavior is unspecified.

2) Same as (1), except that

* conversion is as-if by [wcrtomb](wcrtomb.html "c/string/multibyte/wcrtomb"), not [wctomb](wctomb.html "c/string/multibyte/wctomb")

* the function returns its result as an out-parameter `retval`

* if the conversion stops without writing a null character, the function will store '\0' in the next byte in `dst`, which may be `dst[len]` or `dst[dstsz]`, whichever comes first (meaning up to len+1/dstsz+1 total bytes may be written). In this case, there may be no unshift sequence written before the terminating null.

* if `dst` is a null pointer, the number of bytes that would be produced is stored in *retval

* the function clobbers the destination array from the terminating null and until `dstsz`

* If `src` and `dst` overlap, the behavior is unspecified.

* the following errors are detected at runtime and call the currently installed [constraint handler](../../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * `retval` or `src` is a null pointer 
  * `dstsz` or `len` is greater than RSIZE_MAX (unless `dst` is null) 
  * `dstsz` is not zero (unless `dst` is null) 
  * `len` is greater than `dstsz` and the conversion does not encounter null or encoding error in the `src` array by the time `dstsz` is reached (unless `dst` is null) 


    As with all bounds-checked functions, `wcstombs_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<stdlib.h>`](../../header/stdlib.html "c/header/stdlib").

## Contents

  * [1 Notes](wcstombs.html#Notes)
  * [2 Parameters](wcstombs.html#Parameters)
  * [3 Return value](wcstombs.html#Return_value)
  * [4 Example](wcstombs.html#Example)
  * [5 References](wcstombs.html#References)
  * [6 See also](wcstombs.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcstombs&action=edit&section=1 "Edit section: Notes")] Notes

In most implementations, `wcstombs` updates a global static object of type [mbstate_t](mbstate_t.html "c/string/multibyte/mbstate t") as it processes through the string, and cannot be called simultaneously by two threads, [wcsrtombs](wcsrtombs.html "c/string/multibyte/wcsrtombs") or `wcstombs_s` should be used in such cases. 

POSIX specifies a common extension: if `dst` is a null pointer, this function returns the number of bytes that would be written to `dst`, if converted. Similar behavior is standard for [wcsrtombs](wcsrtombs.html "c/string/multibyte/wcsrtombs") and `wcstombs_s`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcstombs&action=edit&section=2 "Edit section: Parameters")] Parameters

dst  |  \-  |  pointer to narrow character array where the multibyte character will be stored   
---|---|---  
src  |  \-  |  pointer to the first element of a null-terminated wide string to convert   
len  |  \-  |  number of bytes available in the array pointed to by dst   
dstsz  |  \-  |  max number of bytes that will be written (size of the `dst` array)   
retval  |  \-  |  pointer to a size_t object where the result will be stored   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcstombs&action=edit&section=3 "Edit section: Return value")] Return value

1) On success, returns the number of bytes (including any shift sequences, but excluding the terminating '\0') written to the character array whose first element is pointed to by `dst`. On conversion error (if invalid wide character was encountered), returns ([size_t](../../types/size_t.html))-1.

2) Returns zero on success (in which case the number of bytes excluding terminating zero that were, or would be written to `dst`, is stored in *retval), non-zero on error. In case of a runtime constraint violation, stores ([size_t](../../types/size_t.html))-1 in *retval (unless `retval` is null) and sets dst[0] to '\0' (unless `dst` is null or `dstmax` is zero or greater than RSIZE_MAX)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcstombs&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>
     
    int main(void)
    {
        // 4 wide characters
        const wchar_t src[] = L"z\u00df\u6c34\U0001f34c";
        // they occupy 10 bytes in UTF-8
        char dst[11];
     
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.utf8");
        [printf](../../io/fprintf.html)("wide-character string: '%ls'\n",src);
        for ([size_t](../../types/size_t.html) ndx=0; ndx < sizeof src/sizeof src[0]; ++ndx)
            [printf](../../io/fprintf.html)("   src[%2zu] = %#8x\n", ndx, src[ndx]);
     
        int rtn_val = wcstombs(dst, src, sizeof dst);
        [printf](../../io/fprintf.html)("rtn_val = %d\n", rtn_val);
        if (rtn_val > 0)
            [printf](../../io/fprintf.html)("multibyte string:  '%s'\n",dst);
        for ([size_t](../../types/size_t.html) ndx=0; ndx<sizeof dst; ++ndx)
            [printf](../../io/fprintf.html)("   dst[%2zu] = %#2x\n", ndx, (unsigned char)dst[ndx]);
    }

Output: 
    
    
    wide-character string: 'zß水🍌'
       src[ 0] =     0x7a
       src[ 1] =     0xdf
       src[ 2] =   0x6c34
       src[ 3] =  0x1f34c
       src[ 4] =        0
    rtn_val = 10
    multibyte string:  'zß水🍌'
       dst[ 0] = 0x7a
       dst[ 1] = 0xc3
       dst[ 2] = 0x9f
       dst[ 3] = 0xe6
       dst[ 4] = 0xb0
       dst[ 5] = 0xb4
       dst[ 6] = 0xf0
       dst[ 7] = 0x9f
       dst[ 8] = 0x8d
       dst[ 9] = 0x8c
       dst[10] =  0

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcstombs&action=edit&section=5 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.8.2 The wcstombs function (p: 360) 



    

  * K.3.6.5.2 The wcstombs_s function (p: 612-614) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.8.2 The wcstombs function (p: 324) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.8.2 The wcstombs function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcstombs&action=edit&section=6 "Edit section: See also")] See also

[ wcsrtombswcsrtombs_s](wcsrtombs.html "c/string/multibyte/wcsrtombs")(C95)(C11) |  converts a wide string to narrow multibyte character string, given state   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_wcsrtombs&action=edit)  
---|---  
[ mbstowcsmbstowcs_s](mbstowcs.html "c/string/multibyte/mbstowcs")(C11) |  converts a narrow multibyte character string to wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbstowcs&action=edit)  
[C++ documentation](../../../cpp/string/multibyte/wcstombs.html "cpp/string/multibyte/wcstombs") for wcstombs  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcstombs&oldid=101815](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcstombs&oldid=101815)" 

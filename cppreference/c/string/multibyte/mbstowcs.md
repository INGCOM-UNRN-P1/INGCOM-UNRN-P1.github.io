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
| **mbstowcs mbstowcs_s**(C11)  
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

Defined in header `[`<stdlib.h>`](../../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
| (1) |   
[size_t](../../types/size_t.html) mbstowcs( wchar_t *dst, const char *src, [size_t](../../types/size_t.html) len) |  |  (until C99)  
[size_t](../../types/size_t.html) mbstowcs( wchar_t *restrict dst, const char *restrict src, [size_t](../../types/size_t.html) len) |  |  (since C99)  
errno_t mbstowcs_s([size_t](../../types/size_t.html) *restrict retval, wchar_t *restrict dst,  
rsize_t dstsz, const char *restrict src, rsize_t len); |  (2)  |  (since C11)  
| |   
  
1) Converts a multibyte character string from the array whose first element is pointed to by `src` to its wide character representation. Converted characters are stored in the successive elements of the array pointed to by `dst`. No more than `len` wide characters are written to the destination array.

Each character is converted as if by a call to [mbtowc](mbtowc.html "c/string/multibyte/mbtowc"), except that the mbtowc conversion state is unaffected. The conversion stops if:

* The multibyte null character was converted and stored.

* An invalid (in the current C locale) multibyte character was encountered.

* The next wide character to be stored would exceed `len`.

If `src` and `dst` overlap, the behavior is undefined

2) Same as (1), except that

* conversion is as-if by [mbrtowc](mbrtowc.html "c/string/multibyte/mbrtowc"), not [mbtowc](mbtowc.html "c/string/multibyte/mbtowc")

* the function returns its result as an out-parameter `retval`

* if no null character was written to `dst` after `len` wide characters were written, then L'\0' is stored in `dst[len]`, which means len+1 total wide characters are written

* if `dst` is a null pointer, the number of wide characters that would be produced is stored in *retval

* the function clobbers the destination array from the terminating null and until `dstsz`

* If `src` and `dst` overlap, the behavior is unspecified.

* the following errors are detected at runtime and call the currently installed [constraint handler](../../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * `retval` or `src` is a null pointer 
  * `dstsz` or `len` is greater than RSIZE_MAX/sizeof(wchar_t) (unless `dst` is null) 
  * `dstsz` is not zero (unless `dst` is null) 
  * There is no null character in the first `dstsz` multibyte characters in the `src` array and `len` is greater than `dstsz` (unless `dst` is null) 


    As with all bounds-checked functions, `mbstowcs_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<stdlib.h>`](../../header/stdlib.html "c/header/stdlib").

## Contents

  * [1 Notes](mbstowcs.html#Notes)
  * [2 Parameters](mbstowcs.html#Parameters)
  * [3 Return value](mbstowcs.html#Return_value)
  * [4 Example](mbstowcs.html#Example)
  * [5 References](mbstowcs.html#References)
  * [6 See also](mbstowcs.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbstowcs&action=edit&section=1 "Edit section: Notes")] Notes

In most implementations, `mbstowcs` updates a global static object of type [mbstate_t](mbstate_t.html "c/string/multibyte/mbstate t") as it processes through the string, and cannot be called simultaneously by two threads, [mbsrtowcs](mbsrtowcs.html "c/string/multibyte/mbsrtowcs") should be used in such cases. 

POSIX specifies a common extension: if `dst` is a null pointer, this function returns the number of wide characters that would be written to `dst`, if converted. Similar behavior is standard for `mbstowcs_s` and for [mbsrtowcs](mbsrtowcs.html "c/string/multibyte/mbsrtowcs"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbstowcs&action=edit&section=2 "Edit section: Parameters")] Parameters

dst  |  \-  |  pointer to wide character array where the wide string will be stored   
---|---|---  
src  |  \-  |  pointer to the first element of a null-terminated multibyte string to convert   
len  |  \-  |  number of wide characters available in the array pointed to by dst   
dstsz  |  \-  |  max number of wide characters that will be written (size of the `dst` array)   
retval  |  \-  |  pointer to a size_t object where the result will be stored   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbstowcs&action=edit&section=3 "Edit section: Return value")] Return value

1) On success, returns the number of wide characters, excluding the terminating L'\0', written to the destination array. On conversion error (if invalid multibyte character was encountered), returns ([size_t](../../types/size_t.html))-1.

2) zero on success (in which case the number of wide characters excluding terminating zero that were, or would be written to `dst`, is stored in *retval), non-zero on error. In case of a runtime constraint violation, stores ([size_t](../../types/size_t.html))-1 in *retval (unless `retval` is null) and sets dst[0] to L'\0' (unless `dst` is null or `dstmax` is zero or greater than RSIZE_MAX)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbstowcs&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <locale.h>
    #include <stdlib.h>
    #include <wchar.h>
     
    int main(void)
    {
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.utf8");
        const char* mbstr = u8"z\u00df\u6c34\U0001F34C"; // or u8"zß水🍌"
        wchar_t wstr[5];
        mbstowcs(wstr, mbstr, 5);
        [wprintf](../../io/fwprintf.html)(L"MB string: %s\n", mbstr);
        [wprintf](../../io/fwprintf.html)(L"Wide string: %ls\n", wstr);
    }

Output: 
    
    
    MB string: zß水🍌
    Wide string: zß水🍌

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbstowcs&action=edit&section=5 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.8.1 The mbstowcs function (p: 359) 



    

  * K.3.6.5.1 The mbstowcs_s function (p: 611-612) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.8.1 The mbstowcs function (p: 323) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.8.1 The mbstowcs function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbstowcs&action=edit&section=6 "Edit section: See also")] See also

[ mbsrtowcsmbsrtowcs_s](mbsrtowcs.html "c/string/multibyte/mbsrtowcs")(C95)(C11) |  converts a narrow multibyte character string to wide string, given state   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbsrtowcs&action=edit)  
---|---  
[ wcstombswcstombs_s](wcstombs.html "c/string/multibyte/wcstombs")(C11) |  converts a wide string to narrow multibyte character string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_wcstombs&action=edit)  
[C++ documentation](../../../cpp/string/multibyte/mbstowcs.html "cpp/string/multibyte/mbstowcs") for mbstowcs  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbstowcs&oldid=102011](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbstowcs&oldid=102011)" 

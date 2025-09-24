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
**mbsrtowcs mbsrtowcs_s**(C95)(C11)` `  
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
| (1) |   
[size_t](../../types/size_t.html) mbsrtowcs( wchar_t* dst, const char** src, [size_t](../../types/size_t.html) len, [mbstate_t](mbstate_t.html)* ps ); |  | (since C95)   
(until C99)  
[size_t](../../types/size_t.html) mbsrtowcs( wchar_t *restrict dst, const char **restrict src, [size_t](../../types/size_t.html) len,  
[mbstate_t](mbstate_t.html) *restrict ps ); |  |  (since C99)  
errno_t mbsrtowcs_s( [size_t](../../types/size_t.html) *restrict retval,  
wchar_t *restrict dst, rsize_t dstsz,  
const char **restrict src, rsize_t len,  
[mbstate_t](mbstate_t.html) *restrict ps ); |  (2)  |  (since C11)  
| |   
  
1) Converts a null-terminated multibyte character sequence, which begins in the conversion state described by `*ps`, from the array whose first element is pointed to by *src to its wide character representation. If `dst` is not null, converted characters are stored in the successive elements of the wchar_t array pointed to by `dst`. No more than `len` wide characters are written to the destination array. Each multibyte character is converted as if by a call to [mbrtowc](mbrtowc.html "c/string/multibyte/mbrtowc"). The conversion stops if: 

  * The multibyte null character was converted and stored. *src is set to null pointer value and `*ps` represents the initial shift state. 
  * An invalid multibyte character (according to the current C locale) was encountered. *src is set to point at the beginning of the first unconverted multibyte character. 
  * the next wide character to be stored would exceed `len`. *src is set to point at the beginning of the first unconverted multibyte character. This condition is not checked if `dst` is a null pointer.



2) Same as (1), except that 

  * the function returns its result as an out-parameter `retval`
  * if no null character was written to `dst` after `len` wide characters were written, then L'\0' is stored in `dst[len]`, which means len+1 total wide characters are written 
  * the function clobbers the destination array from the terminating null and until `dstsz`
  * If `src` and `dst` overlap, the behavior is unspecified. 
  * the following errors are detected at runtime and call the currently installed [constraint handler](../../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 



    

  * `retval`, `ps`, `src`, or *src is a null pointer 
  * `dstsz` or `len` is greater than RSIZE_MAX/sizeof(wchar_t) (unless `dst` is null) 
  * `dstsz` is not zero (unless `dst` is null) 
  * There is no null character in the first `dstsz` multibyte characters in the *src array and `len` is greater than `dstsz` (unless `dst` is null) 


    As with all bounds-checked functions, `mbsrtowcs_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<wchar.h>`](../../header/wchar.html "c/header/wchar").

## Contents

  * [1 Parameters](mbsrtowcs.html#Parameters)
  * [2 Return value](mbsrtowcs.html#Return_value)
  * [3 Example](mbsrtowcs.html#Example)
  * [4 References](mbsrtowcs.html#References)
  * [5 See also](mbsrtowcs.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsrtowcs&action=edit&section=1 "Edit section: Parameters")] Parameters

dst  |  \-  |  pointer to wide character array where the results will be stored   
---|---|---  
src  |  \-  |  pointer to pointer to the first element of a null-terminated multibyte string   
len  |  \-  |  number of wide characters available in the array pointed to by dst   
ps  |  \-  |  pointer to the conversion state object   
dstsz  |  \-  |  max number of wide characters that will be written (size of the `dst` array)   
retval  |  \-  |  pointer to a size_t object where the result will be stored   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsrtowcs&action=edit&section=2 "Edit section: Return value")] Return value

1) On success, returns the number of wide characters, excluding the terminating L'\0', written to the character array. If `dst` is a null pointer, returns the number of wide characters that would have been written given unlimited length. On conversion error (if invalid multibyte character was encountered), returns ([size_t](../../types/size_t.html))-1, stores [EILSEQ](../../error/errno_macros.html "c/error/errno macros") in [errno](../../error/errno.html "c/error/errno"), and leaves *ps in unspecified state.

2) zero on success (in which case the number of wide characters excluding terminating zero that were, or would be written to `dst`, is stored in *retval), non-sero on error. In case of a runtime constraint violation, stores ([size_t](../../types/size_t.html))-1 in *retval (unless `retval` is null) and sets dst[0] to L'\0' (unless `dst` is null or `dstmax` is zero or greater than RSIZE_MAX)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsrtowcs&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <locale.h>
    #include <wchar.h>
    #include <string.h>
     
    void print_as_wide(const char* mbstr)
    {
        [mbstate_t](mbstate_t.html) state;
        [memset](../byte/memset.html)(&state, 0, sizeof state);
        [size_t](../../types/size_t.html) len = 1 + mbsrtowcs([NULL](../../types/NULL.html), &mbstr, 0, &state);
        wchar_t wstr[len];
        mbsrtowcs(&wstr[0], &mbstr, len, &state);
        [wprintf](../../io/fwprintf.html)(L"Wide string: %ls \n", wstr);
        [wprintf](../../io/fwprintf.html)(L"The length, including L'\\0': %zu\n", len);
    }
     
    int main(void)
    {
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.utf8");
        print_as_wide(u8"z\u00df\u6c34\U0001f34c"); // u8"zß水🍌"
    }

Output: 
    
    
    Wide string: zß水🍌
    The length, including L'\0': 5

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsrtowcs&action=edit&section=4 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.29.6.4.1 The mbsrtowcs function (p: 445) 



    

  * K.3.9.3.2.1 The mbsrtowcs_s function (p: 648-649) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.24.6.4.1 The mbsrtowcs function (p: 391) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsrtowcs&action=edit&section=5 "Edit section: See also")] See also

[ mbstowcsmbstowcs_s](mbstowcs.html "c/string/multibyte/mbstowcs")(C11) |  converts a narrow multibyte character string to wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbstowcs&action=edit)  
---|---  
[ mbrtowc](mbrtowc.html "c/string/multibyte/mbrtowc")(C95) |  converts the next multibyte character to wide character, given state   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbrtowc&action=edit)  
[ wcsrtombswcsrtombs_s](wcsrtombs.html "c/string/multibyte/wcsrtombs")(C95)(C11) |  converts a wide string to narrow multibyte character string, given state   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_wcsrtombs&action=edit)  
[C++ documentation](../../../cpp/string/multibyte/mbsrtowcs.html "cpp/string/multibyte/mbsrtowcs") for mbsrtowcs  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsrtowcs&oldid=119770](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbsrtowcs&oldid=119770)" 

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
[wcrtombwcrtomb_s](wcrtomb.html "c/string/multibyte/wcrtomb")(C95)(C11)  
**wcsrtombs wcsrtombs_s**(C95)(C11)  
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
[size_t](../../types/size_t.html) wcsrtombs( char *dst, const wchar_t **src, [size_t](../../types/size_t.html) len, [mbstate_t](mbstate_t.html)* ps ); |  | (since C95)   
(until C99)  
[size_t](../../types/size_t.html) wcsrtombs( char *restrict dst, const wchar_t **restrict src, [size_t](../../types/size_t.html) len,  
[mbstate_t](mbstate_t.html) *restrict ps ); |  |  (since C99)  
errno_t wcsrtombs_s( [size_t](../../types/size_t.html) *restrict retval, char *restrict dst, rsize_t dstsz,  
const wchar_t **restrict src, rsize_t len,  
[mbstate_t](mbstate_t.html) *restrict ps ); |  (2)  |  (since C11)  
| |   
  
1) Converts a sequence of wide characters from the array whose first element is pointed to by *src to its narrow multibyte representation that begins in the conversion state described by *ps. If `dst` is not null, converted characters are stored in the successive elements of the char array pointed to by `dst`. No more than `len` bytes are written to the destination array. Each character is converted as if by a call to [wcrtomb](wcrtomb.html "c/string/multibyte/wcrtomb"). The conversion stops if: 

  * The null character L'\0' was converted and stored. The bytes stored in this case are the unshift sequence (if necessary) followed by '\0', *src is set to null pointer value and *ps represents the initial shift state. 
  * A wchar_t was found that does not correspond to a valid character in the current C locale. *src is set to point at the first unconverted wide character. 
  * the next multibyte character to be stored would exceed `len`. *src is set to point at the first unconverted wide character. This condition is not checked if `dst` is a null pointer.



2) Same as (1), except that 

  * the function returns its result as an out-parameter `retval`
  * if the conversion stops without writing a null character, the function will store '\0' in the next byte in `dst`, which may be dst[len] or dst[dstsz], whichever comes first (meaning up to len+1/dstsz+1 total bytes may be written). In this case, there may be no unshift sequence written before the terminating null. 
  * the function clobbers the destination array from the terminating null and until `dstsz`
  * If `src` and `dst` overlap, the behavior is unspecified. 
  * the following errors are detected at runtime and call the currently installed [constraint handler](../../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 



    

  * `retval`, `ps`, `src`, or *src is a null pointer 
  * `dstsz` or `len` is greater than RSIZE_MAX (unless `dst` is null) 
  * `dstsz` is not zero (unless `dst` is null) 
  * `len` is greater than `dstsz` and the conversion does not encounter null or encoding error in the `src` array by the time `dstsz` is reached (unless `dst` is null) 


    As with all bounds-checked functions, `wcsrtombs_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<wchar.h>`](../../header/wchar.html "c/header/wchar").

## Contents

  * [1 Parameters](wcsrtombs.html#Parameters)
  * [2 Return value](wcsrtombs.html#Return_value)
  * [3 Example](wcsrtombs.html#Example)
  * [4 References](wcsrtombs.html#References)
  * [5 See also](wcsrtombs.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcsrtombs&action=edit&section=1 "Edit section: Parameters")] Parameters

dst  |  \-  |  pointer to narrow character array where the multibyte characters will be stored   
---|---|---  
src  |  \-  |  pointer to pointer to the first element of a null-terminated wide string   
len  |  \-  |  number of bytes available in the array pointed to by dst   
ps  |  \-  |  pointer to the conversion state object   
dstsz  |  \-  |  max number of bytes that will be written (size of the `dst` array)   
retval  |  \-  |  pointer to a [size_t](../../types/size_t.html "c/types/size t") object where the result will be stored   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcsrtombs&action=edit&section=2 "Edit section: Return value")] Return value

1) On success, returns the number of bytes (including any shift sequences, but excluding the terminating '\0') written to the character array whose first element is pointed to by `dst`. If `dst` is a null pointer, returns the number of bytes that would have been written. On conversion error (if invalid wide character was encountered), returns ([size_t](../../types/size_t.html))-1, stores [EILSEQ](../../error/errno_macros.html "c/error/errno macros") in [errno](../../error/errno.html "c/error/errno"), and leaves *ps in unspecified state.

2) Returns zero on success (in which case the number of bytes excluding terminating zero that were, or would be written to `dst`, is stored in *retval), non-zero on error. In case of a runtime constraint violation, stores ([size_t](../../types/size_t.html))-1 in *retval (unless `retval` is null) and sets dst[0] to '\0' (unless `dst` is null or `dstmax` is zero or greater than RSIZE_MAX)

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcsrtombs&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <locale.h>
    #include <string.h>
    #include <wchar.h>
     
    void print_wide(const wchar_t* wstr)
    {
        [mbstate_t](mbstate_t.html) state;
        [memset](../byte/memset.html)(&state, 0, sizeof state);
        [size_t](../../types/size_t.html) len = 1 + wcsrtombs([NULL](../../types/NULL.html), &wstr, 0, &state);
        char mbstr[len];
        wcsrtombs(mbstr, &wstr, len, &state);
        [printf](../../io/fprintf.html)("Multibyte string: %s\n", mbstr);
        [printf](../../io/fprintf.html)("Length, including '\\0': %zu\n", len);
    }
     
    int main(void)
    {
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.utf8");
        print_wide(L"z\u00df\u6c34\U0001f34c"); // or L"zß水🍌"
    }

Output: 
    
    
    Multibyte string: zß水🍌
    Length, including '\0': 11

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcsrtombs&action=edit&section=4 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.29.6.4.2 The wcsrtombs function (p: 324-325) 



    

  * K.3.9.3.2.2 The wcsrtombs_s function (p: 471-472) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.29.6.4.2 The wcsrtombs function (p: 446) 



    

  * K.3.9.3.2.2 The wcsrtombs_s function (p: 649-651) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.24.6.4.2 The wcsrtombs function (p: 392) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcsrtombs&action=edit&section=5 "Edit section: See also")] See also

[ wcstombswcstombs_s](wcstombs.html "c/string/multibyte/wcstombs")(C11) |  converts a wide string to narrow multibyte character string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_wcstombs&action=edit)  
---|---  
[ wcrtombwcrtomb_s](wcrtomb.html "c/string/multibyte/wcrtomb")(C95)(C11) |  converts a wide character to its multibyte representation, given state   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_wcrtomb&action=edit)  
[ mbsrtowcsmbsrtowcs_s](mbsrtowcs.html "c/string/multibyte/mbsrtowcs")(C95)(C11) |  converts a narrow multibyte character string to wide string, given state   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbsrtowcs&action=edit)  
[C++ documentation](../../../cpp/string/multibyte/wcsrtombs.html "cpp/string/multibyte/wcsrtombs") for wcsrtombs  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcsrtombs&oldid=142642](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/wcsrtombs&oldid=142642)" 

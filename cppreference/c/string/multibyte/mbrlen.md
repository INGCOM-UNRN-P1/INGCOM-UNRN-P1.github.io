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
[wcsrtombswcsrtombs_s](wcsrtombs.html "c/string/multibyte/wcsrtombs")(C95)(C11)  
**mbrlen**(C95)  
  
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
[size_t](../../types/size_t.html) mbrlen( const char* s, [size_t](../../types/size_t.html) n, [mbstate_t](mbstate_t.html)* ps ); |  |  (since C95)   
(until C99)  
[size_t](../../types/size_t.html) mbrlen( const char* restrict s, [size_t](../../types/size_t.html) n, [mbstate_t](mbstate_t.html)* restrict ps ); |  |  (since C99)  
| |   
  
Determines the size, in bytes, of the representation of a multibyte character. 

This function is equivalent to the call [mbrtowc](mbrtowc.html)([NULL](../../types/NULL.html), s, n, ps ? ps : &internal) for some hidden object internal of type [mbstate_t](mbstate_t.html "c/string/multibyte/mbstate t"), except that the expression ps is evaluated only once. 

## Contents

  * [1 Parameters](mbrlen.html#Parameters)
  * [2 Return value](mbrlen.html#Return_value)
  * [3 Example](mbrlen.html#Example)
  * [4 References](mbrlen.html#References)
  * [5 See also](mbrlen.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrlen&action=edit&section=1 "Edit section: Parameters")] Parameters

s  |  \-  |  pointer to an element of a multibyte character string   
---|---|---  
n  |  \-  |  limit on the number of bytes in s that can be examined   
ps  |  \-  |  pointer to the variable holding the conversion state   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrlen&action=edit&section=2 "Edit section: Return value")] Return value

The first of the following that applies: 

  * ​0​ if the next n or fewer bytes complete the null character or if s is a null pointer. Both cases reset the conversion state. 
  * the number of bytes [1...n] that complete a valid multibyte character 
  * ([size_t](../../types/size_t.html))-2 if the next n bytes are part of a possibly valid multibyte character, which is still incomplete after examining all n bytes 
  * ([size_t](../../types/size_t.html))-1 if encoding error occurs. The value of [errno](../../error/errno.html "c/error/errno") is [EILSEQ](../../error/errno_macros.html "c/error/errno macros"); the conversion state is unspecified. 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrlen&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <locale.h>
    #include <stdio.h>
    #include <string.h>
    #include <wchar.h>
     
    int main(void)
    {
        // allow mbrlen() to work with UTF-8 multibyte encoding
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.utf8");
     
        // UTF-8 narrow multibyte encoding
        const char* str = "水";
        [size_t](../../types/size_t.html) sz = [strlen](../byte/strlen.html)(str);
     
        [mbstate_t](mbstate_t.html) mb;
        [memset](../byte/memset.html)(&mb, 0, sizeof mb);
        int len1 = mbrlen(str, 1, &mb);
        if (len1 == -2)
            [printf](../../io/fprintf.html)("The first 1 byte of %s is an incomplete multibyte char"
                   " (mbrlen returns -2)\n", str);
     
        int len2 = mbrlen(str + 1, sz - 1, &mb);
        [printf](../../io/fprintf.html)("The remaining %zu  bytes of %s hold %d bytes of the multibyte"
               " character\n", sz - 1, str, len2);
     
        [printf](../../io/fprintf.html)("Attempting to call mbrlen() in the middle of %s while in initial"
               " shift state returns %zd\n", str, mbrlen(str + 1, sz - 1, &mb));
    }

Output: 
    
    
    The first 1 byte of 水 is an incomplete multibyte char (mbrlen returns -2)
    The remaining 2  bytes of 水 hold 2 bytes of the multibyte character
    Attempting to call mbrlen() in the middle of 水 while in initial shift state returns -1

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrlen&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.29.6.3.1 The mbrlen function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.29.6.3.1 The mbrlen function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.29.6.3.1 The mbrlen function (p: 442) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.24.6.3.1 The mbrlen function (p: 388) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrlen&action=edit&section=5 "Edit section: See also")] See also

[ mbrtowc](mbrtowc.html "c/string/multibyte/mbrtowc")(C95) |  converts the next multibyte character to wide character, given state   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbrtowc&action=edit)  
---|---  
[ mblen](mblen.html "c/string/multibyte/mblen") |  returns the number of bytes in the next multibyte character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mblen&action=edit)  
[C++ documentation](../../../cpp/string/multibyte/mbrlen.html "cpp/string/multibyte/mbrlen") for mbrlen  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrlen&oldid=176729](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mbrlen&oldid=176729)" 

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
  
| **mblen**  
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
int mblen( const char* s, [size_t](../../types/size_t.html) n ); |  |   
| |   
  
Determines the size, in bytes, of the multibyte character whose first byte is pointed to by `s`. 

If `s` is a null pointer, resets the global conversion state and(until C23) determined whether shift sequences are used. 

This function is equivalent to the call [mbtowc](mbtowc.html)((wchar_t*)0, s, n), except that conversion state of [mbtowc](mbtowc.html "c/string/multibyte/mbtowc") is unaffected. 

## Contents

  * [1 Parameters](mblen.html#Parameters)
  * [2 Return value](mblen.html#Return_value)
  * [3 Notes](mblen.html#Notes)
  * [4 Example](mblen.html#Example)
  * [5 References](mblen.html#References)
  * [6 See also](mblen.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mblen&action=edit&section=1 "Edit section: Parameters")] Parameters

s  |  \-  |  pointer to the multibyte character   
---|---|---  
n  |  \-  |  limit on the number of bytes in s that can be examined   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mblen&action=edit&section=2 "Edit section: Return value")] Return value

If `s` is not a null pointer, returns the number of bytes that are contained in the multibyte character or -1 if the first bytes pointed to by `s` do not form a valid multibyte character or ​0​ if `s` is pointing at the null charcter '\0'. 

If `s` is a null pointer, resets its internal conversion state to represent the initial shift state and(until C23) returns ​0​ if the current multibyte encoding is not state-dependent (does not use shift sequences) or a non-zero value if the current multibyte encoding is state-dependent (uses shift sequences). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mblen&action=edit&section=3 "Edit section: Notes")] Notes

Each call to `mblen` updates the internal global conversion state (a static object of type [mbstate_t](mbstate_t.html "c/string/multibyte/mbstate t"), only known to this function). If the multibyte encoding uses shift states, care must be taken to avoid backtracking or multiple scans. In any case, multiple threads should not call `mblen` without synchronization: [mbrlen](mbrlen.html "c/string/multibyte/mbrlen") may be used instead.  | (until C23)  
---|---  
`mblen` is not allowed to have an internal state.  | (since C23)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mblen&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <locale.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
     
    // the number of characters in a multibyte string is the sum of mblen()'s
    // note: the simpler approach is mbstowcs(NULL, str, sz)
    [size_t](../../types/size_t.html) strlen_mb(const char* ptr)
    {
        [size_t](../../types/size_t.html) result = 0;
        const char* end = ptr + [strlen](../byte/strlen.html)(ptr);
        mblen([NULL](../../types/NULL.html), 0); // reset the conversion state
        while(ptr < end) {
            int next = mblen(ptr, end - ptr);
            if (next == -1) {
               [perror](../../io/perror.html)("strlen_mb");
               break;
            }
            ptr += next;
            ++result;
        }
        return result;
    }
     
    void dump_bytes(const char* str)
    {
        for (const char* end = str + [strlen](../byte/strlen.html)(str); str != end; ++str)
            [printf](../../io/fprintf.html)("%02X ", (unsigned char)str[0]);
        [printf](../../io/fprintf.html)("\n");
    }
     
    int main(void)
    {
        [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "en_US.utf8");
        const char* str = "z\u00df\u6c34\U0001f34c";
        [printf](../../io/fprintf.html)("The string \"%s\" consists of %zu characters, but %zu bytes: ",
                str, strlen_mb(str), [strlen](../byte/strlen.html)(str));
        dump_bytes(str);
    }

Possible output: 
    
    
    The string "zß水🍌" consists of 4 characters, but 10 bytes: 7A C3 9F E6 B0 B4 F0 9F 8D 8C

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mblen&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.7.1 The mblen function (p: 260) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.7.1 The mblen function (p: 357) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.7.1 The mblen function (p: 321) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.7.1 The mblen function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mblen&action=edit&section=6 "Edit section: See also")] See also

[ mbtowc](mbtowc.html "c/string/multibyte/mbtowc") |  converts the next multibyte character to wide character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbtowc&action=edit)  
---|---  
[ mbrlen](mbrlen.html "c/string/multibyte/mbrlen")(C95) |  returns the number of bytes in the next multibyte character, given state   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/multibyte/dsc_mbrlen&action=edit)  
[C++ documentation](../../../cpp/string/multibyte/mblen.html "cpp/string/multibyte/mblen") for mblen  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mblen&oldid=146551](https://en.cppreference.com/mwiki/index.php?title=c/string/multibyte/mblen&oldid=146551)" 

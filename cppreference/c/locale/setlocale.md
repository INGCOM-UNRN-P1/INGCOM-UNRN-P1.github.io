From cppreference.com

< [c](../../c.html "c")‎ | [locale](../locale.html "c/locale")

[ C](../../c.html "c")

[Compiler support](../compiler_support.html "c/compiler support")  
---  
[Language](../language.html "c/language")  
[Headers](../header.html "c/header")  
[Type support](../types.html "c/types")  
[Program utilities](../program.html "c/program")  
[Variadic function support](../variadic.html "c/variadic")  
[Error handling](../error.html "c/error")  
[Dynamic memory management](../memory.html "c/memory")  
[Strings library](../string.html "c/string")  
[Algorithms](../algorithm.html "c/algorithm")  
[Numerics](../numeric.html "c/numeric")  
[Date and time utilities](../chrono.html "c/chrono")  
[Input/output support](../io.html "c/io")  
[Localization support](../locale.html "c/locale")  
[Concurrency support](../thread.html "c/thread") (C11)  
[Technical Specifications](../experimental.html "c/experimental")  
[Symbol index](../index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

[ Localization support](../locale.html "c/locale")

**setlocale**  
---  
[localeconv](localeconv.html "c/locale/localeconv")  
[lconv](lconv.html "c/locale/lconv")  
Locale categories  
[LC_ALLLC_COLLATELC_CTYPELC_MONETARYLC_NUMERICLC_TIME](LC_categories.html "c/locale/LC categories")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/locale/navbar_content&action=edit)

Defined in header `[`<locale.h>`](../header/locale.html "c/header/locale")` |  |   
---|---|---  
char* setlocale( int category, const char* locale ); |  |   
| |   
  
The `setlocale` function installs the specified system locale or its portion as the new C locale. The modifications remain in effect and influences the execution of all locale-sensitive C library functions until the next call to `setlocale`. If `locale` is a null pointer, `setlocale` queries the current C locale without modifying it. 

## Contents

  * [1 Parameters](setlocale.html#Parameters)
  * [2 Return value](setlocale.html#Return_value)
  * [3 Notes](setlocale.html#Notes)
  * [4 Example](setlocale.html#Example)
  * [5 References](setlocale.html#References)
  * [6 See also](setlocale.html#See_also)
  * [7 External links](setlocale.html#External_links)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/setlocale&action=edit&section=1 "Edit section: Parameters")] Parameters

category  |  \-  |  locale category identifier, one of the [`LC_xxx`](LC_categories.html "c/locale/LC categories") macros. May be null.   
---|---|---  
locale  |  \-  |  system-specific locale identifier. Can be "" for the user-preferred locale or "C" for the minimal locale   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/setlocale&action=edit&section=2 "Edit section: Return value")] Return value

pointer to a narrow null-terminated string identifying the C locale after applying the changes, if any, or null pointer on failure. 

A copy of the returned string along with the category used in this call to `setlocale` may be used later in the program to restore the locale back to the state at the end of this call. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/setlocale&action=edit&section=3 "Edit section: Notes")] Notes

During program startup, the equivalent of setlocale([LC_ALL](LC_categories.html), "C"); is executed before any user code is run. 

Although the return type is char*, modifying the pointed-to characters is undefined behavior. 

Because `setlocale` modifies global state which affects execution of locale-dependent functions, it is undefined behavior to call it from one thread, while another thread is executing any of the following functions: [fprintf](../io/fprintf.html "c/io/fprintf"), [isprint](../string/byte/isprint.html "c/string/byte/isprint"), [iswdigit](../string/wide/iswdigit.html "c/string/wide/iswdigit"), [localeconv](localeconv.html "c/locale/localeconv"), [tolower](../string/byte/tolower.html "c/string/byte/tolower"), [fscanf](../io/fscanf.html "c/io/fscanf"), [ispunct](../string/byte/ispunct.html "c/string/byte/ispunct"), [iswgraph](../string/wide/iswgraph.html "c/string/wide/iswgraph"), [mblen](../string/multibyte/mblen.html "c/string/multibyte/mblen"), [toupper](../string/byte/toupper.html "c/string/byte/toupper"), [isalnum](../string/byte/isalnum.html "c/string/byte/isalnum"), [isspace](../string/byte/isspace.html "c/string/byte/isspace"), [iswlower](../string/wide/iswlower.html "c/string/wide/iswlower"), [mbstowcs](../string/multibyte/mbstowcs.html "c/string/multibyte/mbstowcs"), [towlower](../string/wide/towlower.html "c/string/wide/towlower"), [isalpha](../string/byte/isalpha.html "c/string/byte/isalpha"), [isupper](../string/byte/isupper.html "c/string/byte/isupper"), [iswprint](../string/wide/iswprint.html "c/string/wide/iswprint"), [mbtowc](../string/multibyte/mbtowc.html "c/string/multibyte/mbtowc"), [towupper](../string/wide/towupper.html "c/string/wide/towupper"), [isblank](../string/byte/isblank.html "c/string/byte/isblank"), [iswalnum](../string/wide/iswalnum.html "c/string/wide/iswalnum"), [iswpunct](../string/wide/iswpunct.html "c/string/wide/iswpunct"), `setlocale`, [wcscoll](../string/wide/wcscoll.html "c/string/wide/wcscoll"), [iscntrl](../string/byte/iscntrl.html "c/string/byte/iscntrl"), [iswalpha](../string/wide/iswalpha.html "c/string/wide/iswalpha"), [iswspace](../string/wide/iswspace.html "c/string/wide/iswspace"), [strcoll](../string/byte/strcoll.html "c/string/byte/strcoll"), [wcstod](../string/wide/wcstof.html "c/string/wide/wcstof"), [isdigit](../string/byte/isdigit.html "c/string/byte/isdigit"), [iswblank](../string/wide/iswblank.html "c/string/wide/iswblank"), [iswupper](../string/wide/iswupper.html "c/string/wide/iswupper"), [strerror](../string/byte/strerror.html "c/string/byte/strerror"), [wcstombs](../string/multibyte/wcstombs.html "c/string/multibyte/wcstombs"), [isgraph](../string/byte/isgraph.html "c/string/byte/isgraph"), [iswcntrl](../string/wide/iswcntrl.html "c/string/wide/iswcntrl"), [iswxdigit](../string/wide/iswxdigit.html "c/string/wide/iswxdigit"), [strtod](../string/byte/strtof.html "c/string/byte/strtof"), [wcsxfrm](../string/wide/wcsxfrm.html "c/string/wide/wcsxfrm"), [islower](../string/byte/islower.html "c/string/byte/islower"), [iswctype](../string/wide/iswctype.html "c/string/wide/iswctype"), [isxdigit](../string/byte/isxdigit.html "c/string/byte/isxdigit"). 

POSIX also defines a locale named "POSIX", which is always accessible and is exactly equivalent to the default minimal "C" locale. 

POSIX also specifies that the returned pointer, not just the contents of the pointed-to string, may be invalidated by subsequent calls to `setlocale`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/setlocale&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <locale.h>
    #include <stdio.h>
    #include <time.h>
    #include <wchar.h>
     
    int main(void)
    {
        // the C locale will be UTF-8 enabled English;
        // decimal dot will be German
        // date and time formatting will be Japanese
        setlocale([LC_ALL](LC_categories.html), "en_US.UTF-8");
        setlocale([LC_NUMERIC](LC_categories.html), "de_DE.utf8");
        setlocale([LC_TIME](LC_categories.html), "ja_JP.utf8");
     
        wchar_t str[100];
        [time_t](../chrono/time_t.html) t = [time](../chrono/time.html)([NULL](../types/NULL.html));
        [wcsftime](../chrono/wcsftime.html)(str, 100, L"%A %c", [localtime](../chrono/localtime.html)(&t));
        [wprintf](../io/fwprintf.html)(L"Number: %.2f\nDate: %ls\n", 3.14, str);
    }

Possible output: 
    
    
    Number: 3,14
    Date: 月曜日 2017年09月25日 13時00分15秒

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/setlocale&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.11.1.1 The setlocale function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.11.1.1 The setlocale function (p: 163-164) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.11.1.1 The setlocale function (p: 224-225) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.11.1.1 The setlocale function (p: 205-206) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.4.1.1 The setlocale function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/setlocale&action=edit&section=6 "Edit section: See also")] See also

[ LC_ALLLC_COLLATELC_CTYPELC_MONETARYLC_NUMERICLC_TIME](LC_categories.html "c/locale/LC categories") |  locale categories for **setlocale**   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/locale/dsc_LC_categories&action=edit)  
---|---  
[C++ documentation](../../cpp/locale/setlocale.html "cpp/locale/setlocale") for setlocale  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/setlocale&action=edit&section=7 "Edit section: External links")] External links

1\.  | [List of Windows locale names](https://ss64.com/locale.html).   
---|---  
2\.  | [List of Linux locale names](https://lh.2xlibre.net/locales/).   
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/locale/setlocale&oldid=180065](https://en.cppreference.com/mwiki/index.php?title=c/locale/setlocale&oldid=180065)" 

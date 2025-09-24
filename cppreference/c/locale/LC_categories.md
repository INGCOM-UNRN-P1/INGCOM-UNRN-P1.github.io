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

[setlocale](setlocale.html "c/locale/setlocale")  
---  
[localeconv](localeconv.html "c/locale/localeconv")  
[lconv](lconv.html "c/locale/lconv")  
Locale categories  
**LC_ALL LC_COLLATELC_CTYPELC_MONETARYLC_NUMERICLC_TIME**  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/locale/navbar_content&action=edit)

Defined in header `[`<locale.h>`](../header/locale.html "c/header/locale")` |  |   
---|---|---  
#define LC_ALL /* implementation-defined */ |  |   
#define LC_COLLATE /* implementation-defined */ |  |   
#define LC_CTYPE /* implementation-defined */ |  |   
#define LC_MONETARY /* implementation-defined */ |  |   
#define LC_NUMERIC /* implementation-defined */ |  |   
#define LC_TIME /* implementation-defined */ |  |   
| |   
  
Each of the above macro constants expand to integer constant expressions with distinct values that are suitable for use as the first argument of [setlocale](setlocale.html "c/locale/setlocale"). 

Constant  |  Explanation   
---|---  
`LC_ALL` |  selects the entire C locale   
`LC_COLLATE` |  selects the collation category of the C locale   
`LC_CTYPE` |  selects the character classification category of the C locale   
`LC_MONETARY` |  selects the monetary formatting category of the C locale   
`LC_NUMERIC` |  selects the numeric formatting category of the C locale   
`LC_TIME` |  selects the time formatting category of the C locale   
  
Additional macro constants, with names that begin with `LC_` followed by at least one uppercase letter, may be defined in `locale.h`. For example, the POSIX specification requires `LC_MESSAGES` (which controls, among other things, [perror](../io/perror.html "c/io/perror") and [strerror](../string/byte/strerror.html "c/string/byte/strerror")), ISO/IEC 30112:2014 ([2014 draft](https://www.open-std.org/JTC1/SC35/WG5/docs/30112d10.pdf)) additionally defines `LC_IDENTIFICATION`, `LC_XLITERATE`, `LC_NAME`, `LC_ADDRESS`, `LC_TELEPHONE`, `LC_PAPER`, `LC_MEASUREMENT`, and `LC_KEYBOARD`, which are supported by the GNU C library (except for `LC_XLITERATE`). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/LC_categories&action=edit&section=1 "Edit section: Example")] Example

Run this code
    
    
    #include <locale.h>
    #include <stdio.h>
    #include <time.h>
    #include <wchar.h>
     
    int main(void)
    {
        [setlocale](setlocale.html)(LC_ALL, "en_US.UTF-8"); // the C locale will be the UTF-8 enabled English
        [setlocale](setlocale.html)(LC_NUMERIC, "de_DE.utf8"); // decimal dot will be German
        [setlocale](setlocale.html)(LC_TIME, "ja_JP.utf8");    // date/time formatting will be Japanese
        wchar_t str[100];
        [time_t](../chrono/time_t.html) t = [time](../chrono/time.html)([NULL](../types/NULL.html));
        [wcsftime](../chrono/wcsftime.html)(str, 100, L"%A %c", [localtime](../chrono/localtime.html)(&t));
        [wprintf](../io/fwprintf.html)(L"Number: %.2f\nDate: %Ls\n", 3.14, str);
    }

Possible output: 
    
    
    Number: 3,14
    Date: 金曜日 2023年09月15日 20時04分14秒

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/LC_categories&action=edit&section=2 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.11/3 Localization <locale.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.11/3 Localization <locale.h> (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.11/3 Localization <locale.h> (p: 224) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.11/3 Localization <locale.h> (p: 205) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.4 LOCALIZATION <locale.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/LC_categories&action=edit&section=3 "Edit section: See also")] See also

[ setlocale](setlocale.html "c/locale/setlocale") |  gets and sets the current C locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/locale/dsc_setlocale&action=edit)  
---|---  
[C++ documentation](../../cpp/locale/LC_categories.html "cpp/locale/LC categories") for locale categories  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/locale/LC_categories&oldid=180072](https://en.cppreference.com/mwiki/index.php?title=c/locale/LC_categories&oldid=180072)" 

From cppreference.com

< [c](../../c.html "c")‎ | [header](../header.html "c/header")

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

[ Standard Library headers ](../header.html "c/header")

| [`<assert.h>`](assert.html "c/header/assert")  
---  
[`<complex.h>`](complex.html "c/header/complex") (C99)  
[`<ctype.h>`](ctype.html "c/header/ctype")  
[`<errno.h>`](errno.html "c/header/errno")  
[`<fenv.h>`](fenv.html "c/header/fenv") (C99)  
[`<float.h>`](float.html "c/header/float")  
[`<inttypes.h>`](inttypes.html "c/header/inttypes") (C99)` `  
[`<iso646.h>`](iso646.html "c/header/iso646") (C95)  
[`<limits.h>`](limits.html "c/header/limits")  
**`< locale.h>`**  
[`<math.h>`](math.html "c/header/math")  
  
| [`<setjmp.h>`](setjmp.html "c/header/setjmp")  
---  
[`<signal.h>`](signal.html "c/header/signal")  
[`<stdalign.h>`](stdalign.html "c/header/stdalign") (C11*)  
[`<stdarg.h>`](stdarg.html "c/header/stdarg")  
[`<stdatomic.h>`](stdatomic.html "c/header/stdatomic") (C11)` `  
[`<stdbit.h>`](stdbit.html "c/header/stdbit") (C23)  
[`<stdbool.h>`](stdbool.html "c/header/stdbool") (C99*)  
[`<stdckdint.h>`](stdckdint.html "c/header/stdckdint") (C23)  
[`<stddef.h>`](stddef.html "c/header/stddef")  
[`<stdint.h>`](stdint.html "c/header/stdint") (C99)  
[`<stdio.h>`](stdio.html "c/header/stdio")  
  
| [`<stdlib.h>`](stdlib.html "c/header/stdlib")  
---  
[`<stdmchar.h>`](stdmchar.html "c/header/stdmchar") (C29)  
[`<stdnoreturn.h>`](stdnoreturn.html "c/header/stdnoreturn") (C11*)  
[`<string.h>`](string.html "c/header/string")  
[`<tgmath.h>`](tgmath.html "c/header/tgmath") (C99)  
[`<threads.h>`](threads.html "c/header/threads") (C11)  
[`<time.h>`](time.html "c/header/time")  
[`<uchar.h>`](uchar.html "c/header/uchar") (C11)  
[`<wchar.h>`](wchar.html "c/header/wchar") (C95)  
[`<wctype.h>`](wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header is part of the [localization](../locale.html "c/locale") library. 

| 

## Contents

  * [1 Types](locale.html#Types)
  * [2 Constants](locale.html#Constants)
  * [3 Functions](locale.html#Functions)
  * [4 Synopsis](locale.html#Synopsis)
  * [5 Notes](locale.html#Notes)

  
---  
  
###  Types  
  
[ lconv](../locale/lconv.html "c/locale/lconv") |  formatting details, returned by [localeconv](../locale/localeconv.html "c/locale/localeconv")  
(struct)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/locale/dsc_lconv&action=edit)  
  
###  Constants  
  
[ NULL](../types/NULL.html "c/types/NULL") |  implementation-defined null pointer constant   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_NULL&action=edit)  
[ LC_ALLLC_COLLATELC_CTYPELC_MONETARYLC_NUMERICLC_TIME](../locale/LC_categories.html "c/locale/LC categories") |  locale categories for [setlocale](../locale/setlocale.html "c/locale/setlocale")   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/locale/dsc_LC_categories&action=edit)  
  
###  Functions  
  
[ setlocale](../locale/setlocale.html "c/locale/setlocale") |  gets and sets the current C locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/locale/dsc_setlocale&action=edit)  
[ localeconv](../locale/localeconv.html "c/locale/localeconv") |  queries numeric and monetary formatting details of the current locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/locale/dsc_localeconv&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/locale&action=edit&section=1 "Edit section: Synopsis")] Synopsis
    
    
    // In the "C" locale, the members shall have the values specified in the comments:
    struct [lconv](../locale/lconv.html)
    {
        char* decimal_point;        // "."
        char* thousands_sep;        // ""
        char* grouping;             // ""
        char* mon_decimal_point;    // ""
        char* mon_thousands_sep;    // ""
        char* mon_grouping;         // ""
        char* positive_sign;        // ""
        char* negative_sign;        // ""
        char* currency_symbol;      // ""
        char  frac_digits;          // CHAR_MAX
        char  p_cs_precedes;        // CHAR_MAX
        char  n_cs_precedes;        // CHAR_MAX
        char  p_sep_by_space;       // CHAR_MAX
        char  n_sep_by_space;       // CHAR_MAX
        char  p_sign_posn;          // CHAR_MAX
        char  n_sign_posn;          // CHAR_MAX
        char* int_curr_symbol;      // ""
        char  int_frac_digits;      // CHAR_MAX
        char  int_p_cs_precedes;    // CHAR_MAX
        char  int_n_cs_precedes;    // CHAR_MAX
        char  int_p_sep_by_space;   // CHAR_MAX
        char  int_n_sep_by_space;   // CHAR_MAX
        char  int_p_sign_posn;      // CHAR_MAX
        char  int_n_sign_posn;      // CHAR_MAX
    };
     
    char* [setlocale](../locale/setlocale.html)(int category, const char* locale);
    [lconv](../locale/lconv.html)* [localeconv](../locale/localeconv.html)();
     
    #define NULL        /* see description */
    #define LC_ALL      /* see description */
    #define LC_COLLATE  /* see description */
    #define LC_CTYPE    /* see description */
    #define LC_MONETARY /* see description */
    #define LC_NUMERIC  /* see description */
    #define LC_TIME     /* see description */

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/locale&action=edit&section=2 "Edit section: Notes")] Notes

  * [NULL](../types/NULL.html "c/types/NULL") is also defined in the following headers: 
    * [`<string.h>`](string.html "c/header/string")
    * [`<time.h>`](time.html "c/header/time")
    * [`<stddef.h>`](stddef.html "c/header/stddef")
    * [`<stdio.h>`](stdio.html "c/header/stdio")
    * [`<wchar.h>`](wchar.html "c/header/wchar")



Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/locale&oldid=180073](https://en.cppreference.com/mwiki/index.php?title=c/header/locale&oldid=180073)" 

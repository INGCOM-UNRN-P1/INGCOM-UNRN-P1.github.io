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
[`<locale.h>`](locale.html "c/header/locale")  
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
**`< wctype.h>`** (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header is part of [wide character classification and mapping utilities](../string/wide.html "c/string/wide") library. 

## Contents

  * [1 Functions](wctype.html#Functions)
    * [1.1 Character classification](wctype.html#Character_classification)
    * [1.2 Character manipulation](wctype.html#Character_manipulation)
  * [2 Types](wctype.html#Types)
  * [3 Macros](wctype.html#Macros)
  * [4 Synopsis](wctype.html#Synopsis)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/wctype&action=edit&section=1 "Edit section: Functions")] Functions

#####  Character classification   
  
---  
[ iswalnum](../string/wide/iswalnum.html "c/string/wide/iswalnum")(C95) |  checks if a wide character is alphanumeric   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswalnum&action=edit)  
[ iswalpha](../string/wide/iswalpha.html "c/string/wide/iswalpha")(C95) |  checks if a wide character is alphabetic   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswalpha&action=edit)  
[ iswlower](../string/wide/iswlower.html "c/string/wide/iswlower")(C95) |  checks if a wide character is an lowercase character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswlower&action=edit)  
[ iswupper](../string/wide/iswupper.html "c/string/wide/iswupper")(C95) |  checks if a wide character is an uppercase character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswupper&action=edit)  
[ iswdigit](../string/wide/iswdigit.html "c/string/wide/iswdigit")(C95) |  checks if a wide character is a digit   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswdigit&action=edit)  
[ iswxdigit](../string/wide/iswxdigit.html "c/string/wide/iswxdigit")(C95) |  checks if a wide character is a hexadecimal character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswxdigit&action=edit)  
[ iswcntrl](../string/wide/iswcntrl.html "c/string/wide/iswcntrl")(C95) |  checks if a wide character is a control character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswcntrl&action=edit)  
[ iswgraph](../string/wide/iswgraph.html "c/string/wide/iswgraph")(C95) |  checks if a wide character is a graphical character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswgraph&action=edit)  
[ iswspace](../string/wide/iswspace.html "c/string/wide/iswspace")(C95) |  checks if a wide character is a space character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswspace&action=edit)  
[ iswblank](../string/wide/iswblank.html "c/string/wide/iswblank")(C99) |  checks if a wide character is a blank character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswblank&action=edit)  
[ iswprint](../string/wide/iswprint.html "c/string/wide/iswprint")(C95) |  checks if a wide character is a printing character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswprint&action=edit)  
[ iswpunct](../string/wide/iswpunct.html "c/string/wide/iswpunct")(C95) |  checks if a wide character is a punctuation character   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswpunct&action=edit)  
[ iswctype](../string/wide/iswctype.html "c/string/wide/iswctype")(C95) |  classifies a wide character according to the specified [LC_CTYPE](../locale/LC_categories.html "c/locale/LC categories") category   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_iswctype&action=edit)  
[ wctype](../string/wide/wctype.html "c/string/wide/wctype")(C95) |  looks up a character classification category in the current C locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wctype&action=edit)  
  
#####  Character manipulation   
  
[ towlower](../string/wide/towlower.html "c/string/wide/towlower")(C95) |  converts a wide character to lowercase   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_towlower&action=edit)  
[ towupper](../string/wide/towupper.html "c/string/wide/towupper")(C95) |  converts a wide character to uppercase   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_towupper&action=edit)  
[ towctrans](../string/wide/towctrans.html "c/string/wide/towctrans")(C95) |  performs character mapping according to the specified [LC_CTYPE](../locale/LC_categories.html "c/locale/LC categories") mapping category   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_towctrans&action=edit)  
[ wctrans](../string/wide/wctrans.html "c/string/wide/wctrans")(C95) |  looks up a character mapping category in the current C locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wctrans&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/wctype&action=edit&section=2 "Edit section: Types")] Types

wint_t(C95) |  integer type that can hold any valid wide character and at least one more value   
(typedef)  
---|---  
wctrans_t(C95) |  scalar type that holds locale-specific character mapping   
(typedef)  
wctype_t(C95) |  scalar type that holds locale-specific character classification   
(typedef)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/wctype&action=edit&section=3 "Edit section: Macros")] Macros

WEOF(C95) |  a non-character value of type wint_t used to indicate errors   
(macro constant)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/wctype&action=edit&section=4 "Edit section: Synopsis")] Synopsis
    
    
    typedef /* see description */ wctrans_t;
    typedef /* see description */ wctype_t;
    typedef /* see description */ wint_t;
     
    #define WEOF /* see description */
     
    int [iswalnum](../string/wide/iswalnum.html)(wint_t wc);
    int [iswalpha](../string/wide/iswalpha.html)(wint_t wc);
    int [iswblank](../string/wide/iswblank.html)(wint_t wc);
    int [iswcntrl](../string/wide/iswcntrl.html)(wint_t wc);
    int [iswdigit](../string/wide/iswdigit.html)(wint_t wc);
    int [iswgraph](../string/wide/iswgraph.html)(wint_t wc);
    int [iswlower](../string/wide/iswlower.html)(wint_t wc);
    int [iswprint](../string/wide/iswprint.html)(wint_t wc);
    int [iswpunct](../string/wide/iswpunct.html)(wint_t wc);
    int [iswspace](../string/wide/iswspace.html)(wint_t wc);
    int [iswupper](../string/wide/iswupper.html)(wint_t wc);
    int [iswxdigit](../string/wide/iswxdigit.html)(wint_t wc);
    int [iswctype](../string/wide/iswctype.html)(wint_t wc, wctype_t desc);
    wctype_t [wctype](../string/wide/wctype.html)(const char* property);
    wint_t [towlower](../string/wide/towlower.html)(wint_t wc);
    wint_t [towupper](../string/wide/towupper.html)(wint_t wc);
    wint_t [towctrans](../string/wide/towctrans.html)(wint_t wc, wctrans_t desc);
    wctrans_t [wctrans](../string/wide/wctrans.html)(const char* property);

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/wctype&oldid=180749](https://en.cppreference.com/mwiki/index.php?title=c/header/wctype&oldid=180749)" 

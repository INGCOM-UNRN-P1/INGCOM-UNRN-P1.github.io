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
**localeconv**  
[lconv](lconv.html "c/locale/lconv")  
Locale categories  
[LC_ALLLC_COLLATELC_CTYPELC_MONETARYLC_NUMERICLC_TIME](LC_categories.html "c/locale/LC categories")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/locale/navbar_content&action=edit)

Defined in header `[`<locale.h>`](../header/locale.html "c/header/locale")` |  |   
---|---|---  
struct [lconv](lconv.html)* localeconv(void); |  |   
| |   
  
The `localeconv` function obtains a pointer to a static object of type [lconv](lconv.html "c/locale/lconv"), which represents numeric and monetary formatting rules of the current C locale. 

## Contents

  * [1 Parameters](localeconv.html#Parameters)
  * [2 Return value](localeconv.html#Return_value)
  * [3 Notes](localeconv.html#Notes)
  * [4 Example](localeconv.html#Example)
  * [5 References](localeconv.html#References)
  * [6 See also](localeconv.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/localeconv&action=edit&section=1 "Edit section: Parameters")] Parameters

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/localeconv&action=edit&section=2 "Edit section: Return value")] Return value

pointer to the current [lconv](lconv.html "c/locale/lconv") object. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/localeconv&action=edit&section=3 "Edit section: Notes")] Notes

Modifying the object references through the returned pointer is undefined behavior. 

`localeconv` modifies a static object, calling it from different threads without synchronization is undefined behavior. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/localeconv&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <locale.h>
    #include <stdio.h>
     
    int main(void)
    {
        [setlocale](setlocale.html)([LC_MONETARY](LC_categories.html), "en_IN.utf8");
        struct [lconv](lconv.html)* lc = localeconv();
        [printf](../io/fprintf.html)("Local Currency Symbol        : %s\n", lc->currency_symbol);
        [printf](../io/fprintf.html)("International Currency Symbol: %s\n", lc->int_curr_symbol);
    }

Output: 
    
    
    Local Currency Symbol        : ₹
    International Currency Symbol: INR

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/localeconv&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.11.2.1 The localeconv function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.11.2.1 The localeconv function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.11.2.1 The localeconv function (p: 225-230) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.11.2.1 The localeconv function (p: 206-211) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.4.2.1 The localeconv function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/localeconv&action=edit&section=6 "Edit section: See also")] See also

[ setlocale](setlocale.html "c/locale/setlocale") |  gets and sets the current C locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/locale/dsc_setlocale&action=edit)  
---|---  
[ lconv](lconv.html "c/locale/lconv") |  formatting details, returned by **localeconv**  
(struct)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/locale/dsc_lconv&action=edit)  
[C++ documentation](../../cpp/locale/localeconv.html "cpp/locale/localeconv") for localeconv  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/locale/localeconv&oldid=180071](https://en.cppreference.com/mwiki/index.php?title=c/locale/localeconv&oldid=180071)" 

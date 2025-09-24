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
**lconv**  
Locale categories  
[LC_ALLLC_COLLATELC_CTYPELC_MONETARYLC_NUMERICLC_TIME](LC_categories.html "c/locale/LC categories")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/locale/navbar_content&action=edit)

Defined in header `[`<locale.h>`](../header/locale.html "c/header/locale")` |  |   
---|---|---  
struct lconv; |  |   
| |   
  
The struct `lconv` contains numeric and monetary formatting rules as defined by a C locale. Objects of this struct may be obtained with [localeconv](localeconv.html "c/locale/localeconv"). The members of `lconv` are values of type char and of type char*. Each char* member except `decimal_point` may be pointing at a null character (that is, at an empty C-string). The members of type char are all non-negative numbers, any of which may be [CHAR_MAX](../types/limits.html "c/types/limits") if the corresponding value is not available in the current C locale. 

## Contents

  * [1 Member objects](lconv.html#Member_objects)
    * [1.1 Non-monetary numeric formatting parameters](lconv.html#Non-monetary_numeric_formatting_parameters)
    * [1.2 Monetary numeric formatting parameters](lconv.html#Monetary_numeric_formatting_parameters)
    * [1.3 Local monetary numeric formatting parameters](lconv.html#Local_monetary_numeric_formatting_parameters)
    * [1.4 International monetary numeric formatting parameters](lconv.html#International_monetary_numeric_formatting_parameters)
  * [2 Example](lconv.html#Example)
  * [3 References](lconv.html#References)
  * [4 See also](lconv.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/lconv&action=edit&section=1 "Edit section: Member objects")] Member objects

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/lconv&action=edit&section=2 "Edit section: Non-monetary numeric formatting parameters")] Non-monetary numeric formatting parameters

char* decimal_point |  the character used as the decimal point   
(public member object)  
---|---  
char* thousands_sep |  the character used to separate groups of digits before the decimal point   
(public member object)  
char* grouping |  a string whose elements indicate the sizes of digit groups   
(public member object)  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/lconv&action=edit&section=3 "Edit section: Monetary numeric formatting parameters")] Monetary numeric formatting parameters

char* mon_decimal_point |  the character used as the decimal point   
(public member object)  
---|---  
char* mon_thousands_sep |  the character used to separate groups of digits before the decimal point   
(public member object)  
char* mon_grouping |  a string whose elements indicate the sizes of digit groups   
(public member object)  
char* positive_sign |  a string used to indicate non-negative monetary quantity   
(public member object)  
char* negative_sign |  a string used to indicate negative monetary quantity   
(public member object)  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/lconv&action=edit&section=4 "Edit section: Local monetary numeric formatting parameters")] Local monetary numeric formatting parameters

char* currency_symbol |  the symbol used for currency in the current C locale   
(public member object)  
---|---  
char frac_digits |  the number of digits after the decimal point to display in a monetary quantity   
(public member object)  
char p_cs_precedes |  1 if currency_symbol is placed before non-negative value, ​0​ if after   
(public member object)  
char n_cs_precedes |  1 if currency_symbol is placed before negative value, ​0​ if after   
(public member object)  
char p_sep_by_space |  indicates the separation of currency_symbol, positive_sign, and the non-negative monetary value   
(public member object)  
char n_sep_by_space |  indicates the separation of currency_symbol, negative_sign, and the negative monetary value   
(public member object)  
char p_sign_posn |  indicates the position of positive_sign in a non-negative monetary value   
(public member object)  
char n_sign_posn |  indicates the position of negative_sign in a negative monetary value   
(public member object)  
  
#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/lconv&action=edit&section=5 "Edit section: International monetary numeric formatting parameters")] International monetary numeric formatting parameters

char* int_curr_symbol |  the string used as international currency name in the current C locale   
(public member object)  
---|---  
char int_frac_digits |  the number of digits after the decimal point to display in an international monetary quantity   
(public member object)  
char int_p_cs_precedes(C99) |  1 if int_curr_symbol is placed before non-negative international monetary value, ​0​ if after   
(public member object)  
char int_n_cs_precedes(C99) |  1 if int_curr_symbol is placed before negative international monetary value, ​0​ if after   
(public member object)  
char int_p_sep_by_space(C99) |  indicates the separation of int_curr_symbol, positive_sign, and the non-negative international monetary value   
(public member object)  
char int_n_sep_by_space(C99) |  indicates the separation of int_curr_symbol, negative_sign, and the negative international monetary value   
(public member object)  
char int_p_sign_posn(C99) |  indicates the position of positive_sign in a non-negative international monetary value   
(public member object)  
char int_n_sign_posn(C99) |  indicates the position of negative_sign in a negative international monetary value   
(public member object)  
  
The characters of the C-strings pointed to by grouping and mon_grouping are interpreted according to their numeric values. When the terminating '\0' is encountered, the last value seen is assumed to repeat for the remainder of digits. If [CHAR_MAX](../types/limits.html "c/types/limits") is encountered, no further digits are grouped. The typical grouping of three digits at a time is "\003". 

The values of p_sep_by_space, n_sep_by_space, int_p_sep_by_space, int_n_sep_by_space are interpreted as follows: 

​0​ |  no space separates the currency symbol and the value   
---|---  
1 |  sign sticks to the currency symbol, value is separated by a space   
2 |  sign sticks to the value. Currency symbol is separated by a space   
  
The values of p_sign_posn, n_sign_posn, int_p_sign_posn, int_n_sign_posn are interpreted as follows: 

​0​ |  parentheses around the value and the currency symbol are used to represent the sign   
---|---  
1 |  sign before the value and the currency symbol   
2 |  sign after the value and the currency symbol   
3 |  sign before the currency symbol   
4 |  sign after the currency symbol   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/lconv&action=edit&section=6 "Edit section: Example")] Example

Run this code
    
    
    #include <locale.h>
    #include <stdio.h>
     
    int main(void)
    {
        [setlocale](setlocale.html)([LC_ALL](LC_categories.html), "ja_JP.UTF-8");
        struct lconv* lc = [localeconv](localeconv.html)();
        [printf](../io/fprintf.html)("Japanese currency symbol: %s(%s)\n", lc->currency_symbol, lc->int_curr_symbol);
    }

Possible output: 
    
    
    Japanese currency symbol: ￥(JPY )

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/lconv&action=edit&section=7 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.11/2 Localization <locale.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.11/2 Localization <locale.h> (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.11/2 Localization <locale.h> (p: 223) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.11/2 Localization <locale.h> (p: 204) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.4 LOCALIZATION <locale.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/locale/lconv&action=edit&section=8 "Edit section: See also")] See also

[ localeconv](localeconv.html "c/locale/localeconv") |  queries numeric and monetary formatting details of the current locale   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/locale/dsc_localeconv&action=edit)  
---|---  
[C++ documentation](../../cpp/locale/lconv.html "cpp/locale/lconv") for lconv  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/locale/lconv&oldid=180064](https://en.cppreference.com/mwiki/index.php?title=c/locale/lconv&oldid=180064)" 

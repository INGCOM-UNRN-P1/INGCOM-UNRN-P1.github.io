From cppreference.com

< [c](../../c.html "c")‎ | [numeric](../numeric.html "c/numeric")

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

[ Numerics](../numeric.html "c/numeric")

[Common mathematical functions](math.html "c/numeric/math")  
---  
[Floating-point environment](fenv.html "c/numeric/fenv") (C99)  
[Pseudo-random number generation](random.html "c/numeric/random")  
[Complex number arithmetic](complex.html "c/numeric/complex") (C99)  
[Type-generic math](tgmath.html "c/numeric/tgmath") (C99)  
[Bit manipulation](../numeric.html#Bit_manipulation "c/numeric") (C23)  
[Checked integer arithmetic](../numeric.html#Checked_integer_arithmetic "c/numeric") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/navbar_content&action=edit)

[Bit manipulation](../numeric.html#Bit_manipulation_.28since_C23.29 "c/numeric")

[Functions](bit_manip.html#Functions "c/numeric/bit manip")  
---  
[stdc_leading_zeros](bit/stdc_leading_zeros.html "c/numeric/bit/stdc leading zeros")(C23)  
[stdc_leading_ones](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_leading_ones&action=edit&redlink=1 "c/numeric/bit/stdc leading ones \(page does not exist\)")(C23)  
[stdc_trailing_zeros](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_trailing_zeros&action=edit&redlink=1 "c/numeric/bit/stdc trailing zeros \(page does not exist\)")(C23)  
[stdc_trailing_ones](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_trailing_ones&action=edit&redlink=1 "c/numeric/bit/stdc trailing ones \(page does not exist\)")(C23)  
[stdc_first_leading_zero](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_first_leading_zero&action=edit&redlink=1 "c/numeric/bit/stdc first leading zero \(page does not exist\)")(C23)  
[stdc_first_leading_one](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_first_leading_one&action=edit&redlink=1 "c/numeric/bit/stdc first leading one \(page does not exist\)")(C23)  
[stdc_first_trailing_zero](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_first_trailing_zero&action=edit&redlink=1 "c/numeric/bit/stdc first trailing zero \(page does not exist\)")(C23)  
[stdc_first_trailing_one](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_first_trailing_one&action=edit&redlink=1 "c/numeric/bit/stdc first trailing one \(page does not exist\)")(C23)  
[stdc_count_zeros](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_count_zeros&action=edit&redlink=1 "c/numeric/bit/stdc count zeros \(page does not exist\)")(C23)  
[stdc_count_ones](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_count_ones&action=edit&redlink=1 "c/numeric/bit/stdc count ones \(page does not exist\)")(C23)  
[stdc_has_single_bit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_has_single_bit&action=edit&redlink=1 "c/numeric/bit/stdc has single bit \(page does not exist\)")(C23)  
[stdc_bit_width](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_bit_width&action=edit&redlink=1 "c/numeric/bit/stdc bit width \(page does not exist\)")(C23)  
[stdc_bit_floor](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_bit_floor&action=edit&redlink=1 "c/numeric/bit/stdc bit floor \(page does not exist\)")(C23)  
[stdc_bit_ceil](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_bit_ceil&action=edit&redlink=1 "c/numeric/bit/stdc bit ceil \(page does not exist\)")(C23)  
[Macro constants](bit_manip.html#Macro_constants "c/numeric/bit manip")  
**__STDC_ENDIAN_LITTLE__  
__STDC_ENDIAN_BIG__  
__STDC_ENDIAN_NATIVE__**(C23)(C23)(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/bit/navbar_content&action=edit)

Defined in header `[`<stdbit.h>`](../header/stdbit.html "c/header/stdbit")` |  |   
---|---|---  
#define __STDC_ENDIAN_LITTLE__ /* implementation-defined */ |  (1)  |  (since C23)  
#define __STDC_ENDIAN_BIG__ /* implementation-defined */ |  (2)  |  (since C23)  
#define __STDC_ENDIAN_NATIVE__ /* implementation-defined */ |  (3)  |  (since C23)  
| |   
  
Indicates the [endianness](https://en.wikipedia.org/wiki/Endianness#Overview "enwiki:Endianness") of all [scalar types](../../cpp/language/type-id.html "cpp/language/type"): 

  * If all scalar types are little-endian, __STDC_ENDIAN_NATIVE__ equals __STDC_ENDIAN_LITTLE__. 
  * If all scalar types are big-endian, __STDC_ENDIAN_NATIVE__ equals __STDC_ENDIAN_BIG__. 
  * If the platform uses neither little-endian nor big-endian, __STDC_ENDIAN_NATIVE__ equals neither __STDC_ENDIAN_BIG__ nor __STDC_ENDIAN_LITTLE__. 
  * The values of the integer constant expressions for __STDC_ENDIAN_BIG__ and __STDC_ENDIAN_LITTLE__ are not equal. 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/endian&action=edit&section=1 "Edit section: Example")] Example

Run this code
    
    
    #include <stdbit.h>
    #include <stdio.h>
     
    int main()
    {
        switch(__STDC_ENDIAN_NATIVE__)
        {
            case __STDC_ENDIAN_LITTLE__:
                [printf](../io/fprintf.html)("__STDC_ENDIAN_LITTLE__\n");
                break;
            case __STDC_ENDIAN_BIG__:
                [printf](../io/fprintf.html)("__STDC_ENDIAN_BIG__\n");
                break;
            default:
                [printf](../io/fprintf.html)("mixed-endian\n");
        }
        return __STDC_ENDIAN_NATIVE__;
    }

Possible output: 
    
    
    mixed-endian

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/endian&action=edit&section=2 "Edit section: See also")] See also

[C++ documentation](../../cpp/types/endian.html "cpp/types/endian") for endian  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/endian&oldid=178957](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/endian&oldid=178957)" 

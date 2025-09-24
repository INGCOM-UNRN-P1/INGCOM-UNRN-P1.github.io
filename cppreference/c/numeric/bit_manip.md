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
[__STDC_ENDIAN_LITTLE__  
__STDC_ENDIAN_BIG__  
__STDC_ENDIAN_NATIVE__](endian.html "c/numeric/bit/endian")(C23)(C23)(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/bit/navbar_content&action=edit)

| 

## Contents

  * [1 Functions](bit_manip.html#Functions)
  * [2 Macro constants](bit_manip.html#Macro_constants)
  * [3 References](bit_manip.html#References)
  * [4 See also](bit_manip.html#See_also)

  
---  
  
###  Functions  
  
Defined in header `[`<stdbit.h>`](../header/stdbit.html "c/header/stdbit")`  
[ stdc_leading_zeros](bit/stdc_leading_zeros.html "c/numeric/bit/stdc leading zeros")(C23) |  counts the number of consecutive ​0​ bits, starting from the most significant bit  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_leading_zeros&action=edit)  
[ stdc_leading_ones](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_leading_ones&action=edit&redlink=1 "c/numeric/bit/stdc leading ones \(page does not exist\)")(C23) |  counts the number of consecutive 1 bits, starting from the most significant bit  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_leading_ones&action=edit)  
[ stdc_trailing_zeros](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_trailing_zeros&action=edit&redlink=1 "c/numeric/bit/stdc trailing zeros \(page does not exist\)")(C23) |  counts the number of consecutive ​0​ bits, starting from the least significant bit  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_trailing_zeros&action=edit)  
[ stdc_trailing_ones](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_trailing_ones&action=edit&redlink=1 "c/numeric/bit/stdc trailing ones \(page does not exist\)")(C23) |  counts the number of consecutive 1 bits, starting from the least significant bit  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_trailing_ones&action=edit)  
[ stdc_first_leading_zero](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_first_leading_zero&action=edit&redlink=1 "c/numeric/bit/stdc first leading zero \(page does not exist\)")(C23) |  finds the first position of ​0​ bit, starting from the most significant bit  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_first_leading_zero&action=edit)  
[ stdc_first_leading_one](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_first_leading_one&action=edit&redlink=1 "c/numeric/bit/stdc first leading one \(page does not exist\)")(C23) |  finds the first position of 1 bit, starting from the most significant bit  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_first_leading_one&action=edit)  
[ stdc_first_trailing_zero](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_first_trailing_zero&action=edit&redlink=1 "c/numeric/bit/stdc first trailing zero \(page does not exist\)")(C23) |  finds the first position of ​0​ bit, starting from the least significant bit  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_first_trailing_zero&action=edit)  
[ stdc_first_trailing_one](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_first_trailing_one&action=edit&redlink=1 "c/numeric/bit/stdc first trailing one \(page does not exist\)")(C23) |  finds the first position of 1 bit, starting from the least significant bit  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_first_trailing_one&action=edit)  
[ stdc_count_zeros](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_count_zeros&action=edit&redlink=1 "c/numeric/bit/stdc count zeros \(page does not exist\)")(C23) |  counts the number of ​0​ bits in an unsigned integer  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_count_zeros&action=edit)  
[ stdc_count_ones](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_count_ones&action=edit&redlink=1 "c/numeric/bit/stdc count ones \(page does not exist\)")(C23) |  counts the number of 1 bits in an unsigned integer  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_count_ones&action=edit)  
[ stdc_has_single_bit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_has_single_bit&action=edit&redlink=1 "c/numeric/bit/stdc has single bit \(page does not exist\)")(C23) |  checks if a number is an integral power of 2  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_has_single_bit&action=edit)  
[ stdc_bit_width](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_bit_width&action=edit&redlink=1 "c/numeric/bit/stdc bit width \(page does not exist\)")(C23) |  finds the smallest number of bits needed to represent the given value  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_bit_width&action=edit)  
[ stdc_bit_floor](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_bit_floor&action=edit&redlink=1 "c/numeric/bit/stdc bit floor \(page does not exist\)")(C23) |  finds the largest integral power of 2 not greater than the given value  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_bit_floor&action=edit)  
[ stdc_bit_ceil](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_bit_ceil&action=edit&redlink=1 "c/numeric/bit/stdc bit ceil \(page does not exist\)")(C23) |  finds the smallest integral power of 2 not less than the given value  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_bit_ceil&action=edit)  
  
###  Macro constants  
  
Defined in header `[`<stdbit.h>`](../header/stdbit.html "c/header/stdbit")`  
[ __STDC_ENDIAN_LITTLE____STDC_ENDIAN_BIG__ __STDC_ENDIAN_NATIVE__](endian.html "c/numeric/bit/endian")(C23) |  indicates the endianness of scalar types   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_endian&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit_manip&action=edit&section=1 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.18 Bit and byte utilities <stdbit.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit_manip&action=edit&section=2 "Edit section: See also")] See also

[C++ documentation](../../cpp/utility/bit.html "cpp/utility/bit") for Bit manipulation  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit_manip&oldid=180023](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit_manip&oldid=180023)" 

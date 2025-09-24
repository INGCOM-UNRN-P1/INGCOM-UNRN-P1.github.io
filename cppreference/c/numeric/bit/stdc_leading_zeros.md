From cppreference.com

< [c](../../../c.html "c")‎ | [numeric](../../numeric.html "c/numeric")

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

[ Numerics](../../numeric.html "c/numeric")

[Common mathematical functions](../math.html "c/numeric/math")  
---  
[Floating-point environment](../fenv.html "c/numeric/fenv") (C99)  
[Pseudo-random number generation](../random.html "c/numeric/random")  
[Complex number arithmetic](../complex.html "c/numeric/complex") (C99)  
[Type-generic math](../tgmath.html "c/numeric/tgmath") (C99)  
[Bit manipulation](../../numeric.html#Bit_manipulation "c/numeric") (C23)  
[Checked integer arithmetic](../../numeric.html#Checked_integer_arithmetic "c/numeric") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/navbar_content&action=edit)

[Bit manipulation](../../numeric.html#Bit_manipulation_.28since_C23.29 "c/numeric")

[Functions](../bit_manip.html#Functions "c/numeric/bit manip")  
---  
**stdc_leading_zeros**(C23)  
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
[Macro constants](../bit_manip.html#Macro_constants "c/numeric/bit manip")  
[__STDC_ENDIAN_LITTLE__  
__STDC_ENDIAN_BIG__  
__STDC_ENDIAN_NATIVE__](../endian.html "c/numeric/bit/endian")(C23)(C23)(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/bit/navbar_content&action=edit)

Defined in header `[`<stdbit.h>`](../../header/stdbit.html "c/header/stdbit")` |  |   
---|---|---  
unsigned int stdc_leading_zeros_uc( unsigned char value ) [[unsequenced]]; |  (1)  |  (since C23)  
unsigned int stdc_leading_zeros_us( unsigned short value ) [[unsequenced]]; |  (2)  |  (since C23)  
unsigned int stdc_leading_zeros_ui( unsigned int value ) [[unsequenced]]; |  (3)  |  (since C23)  
unsigned int stdc_leading_zeros_ul( unsigned long int value ) [[unsequenced]]; |  (4)  |  (since C23)  
unsigned int stdc_leading_zeros_ull( unsigned long long int value ) [[unsequenced]]; |  (5)  |  (since C23)  
#define stdc_leading_zeros( value )  
// exposed interface:  
generic_return_type stdc_leading_zeros( generic_value_type value ) [[unsequenced]]; |  (6)  |  (since C23)  
| |   
  
1-5) Returns the number of consecutive ​0​ bits in the value, starting from the most significant bit.

6) The type-generic function (marked by its `generic_value_type` argument) returns the appropriate value based on the type of the input value, so long as it is a: 

  * standard unsigned integer type, excluding bool; 
  * extended unsigned integer type; 
  * or, bit-precise unsigned integer type whose width matches a standard or extended integer type, excluding bool. 

The `generic_return_type` shall be a suitable large unsigned integer type capable of representing the computed result.

## Contents

  * [1 Parameters](stdc_leading_zeros.html#Parameters)
  * [2 Return value](stdc_leading_zeros.html#Return_value)
  * [3 Example](stdc_leading_zeros.html#Example)
  * [4 See also](stdc_leading_zeros.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_leading_zeros&action=edit&section=1 "Edit section: Parameters")] Parameters

value  |  \-  |  value of unsigned integer type   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_leading_zeros&action=edit&section=2 "Edit section: Return value")] Return value

The number of consecutive ​0​ bits in the value, starting from the most significant bit. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_leading_zeros&action=edit&section=3 "Edit section: Example")] Example

Run this code
    
    
    #include <limits.h>
    #include <stdbit.h>
    #include <stdint.h>
    #include <stdio.h>
     
    #define bits_num(value) (sizeof(value) * CHAR_BIT)
     
    #define bin_impl(T, suffix) \
    const char* bin_##suffix(T x) \
    { \
        static char buf[bits_num(x) * CHAR_BIT + 1]; \
        for (T i = 0, mask = ((T)1 << (bits_num(x) - 1)); mask; mask >>= 1) \
            buf[i++] = x & mask ? '1' : '0'; \
        buf[bits_num(x)] = '\0'; \
        return buf; \
    }
     
    bin_impl([uint8_t](../../types/integer.html), u8)
    bin_impl([uint16_t](../../types/integer.html), u16)
    bin_impl([uint32_t](../../types/integer.html), u32)
    bin_impl([uint64_t](../../types/integer.html), u64)
     
    #define bin(x) _Generic((x), \
        uint8_t: bin_u8, uint16_t: bin_u16, uint32_t: bin_u32, default: bin_u64)(x)
     
    int main()
    {
        [puts](../../io/puts.html)("uint8_t:");
        for ([uint8_t](../../types/integer.html) x = 0b11000000; ; x >>= 1)
        {
            [printf](../../io/fprintf.html)("x = [%s], leading zeros: %d\n", bin(x), stdc_leading_zeros(x));
            if (!x)
                break;
        }
     
        [puts](../../io/puts.html)("uint16_t:");
        for ([uint16_t](../../types/integer.html) x = 0b11000000; ; x >>= 1)
        {
            [printf](../../io/fprintf.html)("x = [%s], leading zeros: %d\n", bin(x), stdc_leading_zeros(x));
            if (!x)
                break;
        }
    }

Output: 
    
    
    uint8_t:
    x = [11000000], leading zeros: 0
    x = [01100000], leading zeros: 1
    x = [00110000], leading zeros: 2
    x = [00011000], leading zeros: 3
    x = [00001100], leading zeros: 4
    x = [00000110], leading zeros: 5
    x = [00000011], leading zeros: 6
    x = [00000001], leading zeros: 7
    x = [00000000], leading zeros: 8
    uint16_t:
    x = [0000000011000000], leading zeros: 8
    x = [0000000001100000], leading zeros: 9
    x = [0000000000110000], leading zeros: 10
    x = [0000000000011000], leading zeros: 11
    x = [0000000000001100], leading zeros: 12
    x = [0000000000000110], leading zeros: 13
    x = [0000000000000011], leading zeros: 14
    x = [0000000000000001], leading zeros: 15
    x = [0000000000000000], leading zeros: 16

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_leading_zeros&action=edit&section=4 "Edit section: See also")] See also

[ stdc_first_leading_zero](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_first_leading_zero&action=edit&redlink=1 "c/numeric/bit/stdc first leading zero \(page does not exist\)")(C23) |  finds the first position of ​0​ bit, starting from the most significant bit  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_first_leading_zero&action=edit)  
---|---  
[ stdc_count_zeros](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_count_zeros&action=edit&redlink=1 "c/numeric/bit/stdc count zeros \(page does not exist\)")(C23) |  counts the number of ​0​ bits in an unsigned integer  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_count_zeros&action=edit)  
[ stdc_leading_ones](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_leading_ones&action=edit&redlink=1 "c/numeric/bit/stdc leading ones \(page does not exist\)")(C23) |  counts the number of consecutive 1 bits, starting from the most significant bit  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_stdc_leading_ones&action=edit)  
[C++ documentation](../../../cpp/numeric/countl_zero.html "cpp/numeric/countl zero") for countl_zero  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_leading_zeros&oldid=178971](https://en.cppreference.com/mwiki/index.php?title=c/numeric/bit/stdc_leading_zeros&oldid=178971)" 

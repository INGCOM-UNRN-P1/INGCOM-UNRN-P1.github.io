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
**`< stdbit.h>`** (C23)  
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

This header is part of the [numeric](../numeric.html "c/numeric") library, in particular, it provides macros and functions to work with the [byte ordering](stdbit.html#Macro_constants) and [byte and bit representation](stdbit.html#Functions) of C objects. 

###  Functions  
  
---  
[ stdc_leading_zeros](../numeric/bit/stdc_leading_zeros.html "c/numeric/bit/stdc leading zeros")(C23) |  counts the number of consecutive ​0​ bits, starting from the most significant bit  
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
  
[ __STDC_ENDIAN_LITTLE____STDC_ENDIAN_BIG__ __STDC_ENDIAN_NATIVE__](../numeric/endian.html "c/numeric/bit/endian")(C23) |  indicates the endianness of scalar types   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_endian&action=edit)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/stdbit&action=edit&section=1 "Edit section: Synopsis")] Synopsis
    
    
    #define __STDC_VERSION_STDBIT_H__ 202311L
     
    #define __STDC_ENDIAN_LITTLE__ /* implementation-defined */
    #define __STDC_ENDIAN_BIG__    /* implementation-defined */
    #define __STDC_ENDIAN_NATIVE__ /* implementation-defined */
     
    unsigned int stdc_leading_zeros_uc(unsigned char value) [[unsequenced]];
    unsigned int stdc_leading_zeros_us(unsigned short value) [[unsequenced]];
    unsigned int stdc_leading_zeros_ui(unsigned int value) [[unsequenced]];
    unsigned int stdc_leading_zeros_ul(unsigned long int value) [[unsequenced]];
    unsigned int stdc_leading_zeros_ull(unsigned long long int value) [[unsequenced]];
    /*generic_return_type*/
    stdc_leading_zeros(/*generic_value_type*/ value) [[unsequenced]];
    unsigned int stdc_leading_ones_uc(unsigned char value) [[unsequenced]];
    unsigned int stdc_leading_ones_us(unsigned short value) [[unsequenced]];
    unsigned int stdc_leading_ones_ui(unsigned int value) [[unsequenced]];
    unsigned int stdc_leading_ones_ul(unsigned long int value) [[unsequenced]];
    unsigned int stdc_leading_ones_ull(unsigned long long int value) [[unsequenced]];
    /*generic_return_type*/
    stdc_leading_ones(/*generic_value_type*/ value) [[unsequenced]];
    unsigned int stdc_trailing_zeros_uc(unsigned char value) [[unsequenced]];
    unsigned int stdc_trailing_zeros_us(unsigned short value) [[unsequenced]];
    unsigned int stdc_trailing_zeros_ui(unsigned int value) [[unsequenced]];
    unsigned int stdc_trailing_zeros_ul(unsigned long int value) [[unsequenced]];
    unsigned int stdc_trailing_zeros_ull(unsigned long long int value) [[unsequenced]];
    /*generic_return_type*/
    stdc_trailing_zeros(/*generic_value_type*/ value) [[unsequenced]];
    unsigned int stdc_trailing_ones_uc(unsigned char value) [[unsequenced]];
    unsigned int stdc_trailing_ones_us(unsigned short value) [[unsequenced]];
    unsigned int stdc_trailing_ones_ui(unsigned int value) [[unsequenced]];
    unsigned int stdc_trailing_ones_ul(unsigned long int value) [[unsequenced]];
    unsigned int stdc_trailing_ones_ull(unsigned long long int value) [[unsequenced]];
    /*generic_return_type*/
    stdc_trailing_ones(/*generic_value_type*/ value) [[unsequenced]];
    unsigned int stdc_first_leading_zero_uc(unsigned char value) [[unsequenced]];
    unsigned int stdc_first_leading_zero_us(unsigned short value) [[unsequenced]];
    unsigned int stdc_first_leading_zero_ui(unsigned int value) [[unsequenced]];
    unsigned int stdc_first_leading_zero_ul(unsigned long int value) [[unsequenced]];
    unsigned int stdc_first_leading_zero_ull(unsigned long long int value) [[unsequenced]];
    /*generic_return_type*/
    stdc_first_leading_zero(/*generic_value_type*/ value) [[unsequenced]];
    unsigned int stdc_first_leading_one_uc(unsigned char value) [[unsequenced]];
    unsigned int stdc_first_leading_one_us(unsigned short value) [[unsequenced]];
    unsigned int stdc_first_leading_one_ui(unsigned int value) [[unsequenced]];
    unsigned int stdc_first_leading_one_ul(unsigned long int value) [[unsequenced]];
    unsigned int stdc_first_leading_one_ull(unsigned long long int value) [[unsequenced]];
    /*generic_return_type*/
    stdc_first_leading_one(/*generic_value_type*/ value) [[unsequenced]];
    unsigned int stdc_first_trailing_zero_uc(unsigned char value) [[unsequenced]];
    unsigned int stdc_first_trailing_zero_us(unsigned short value) [[unsequenced]];
    unsigned int stdc_first_trailing_zero_ui(unsigned int value) [[unsequenced]];
    unsigned int stdc_first_trailing_zero_ul(unsigned long int value) [[unsequenced]];
    unsigned int stdc_first_trailing_zero_ull(unsigned long long int value) [[unsequenced]];
    /*generic_return_type*/
    stdc_first_trailing_zero(/*generic_value_type*/ value) [[unsequenced]];
    unsigned int stdc_first_trailing_one_uc(unsigned char value) [[unsequenced]];
    unsigned int stdc_first_trailing_one_us(unsigned short value) [[unsequenced]];
    unsigned int stdc_first_trailing_one_ui(unsigned int value) [[unsequenced]];
    unsigned int stdc_first_trailing_one_ul(unsigned long int value) [[unsequenced]];
    unsigned int stdc_first_trailing_one_ull(unsigned long long int value) [[unsequenced]];
    /*generic_return_type*/
    stdc_first_trailing_one(/*generic_value_type*/ value) [[unsequenced]];
    unsigned int stdc_count_zeros_uc(unsigned char value) [[unsequenced]];
    unsigned int stdc_count_zeros_us(unsigned short value) [[unsequenced]];
    unsigned int stdc_count_zeros_ui(unsigned int value) [[unsequenced]];
    unsigned int stdc_count_zeros_ul(unsigned long int value) [[unsequenced]];
    unsigned int stdc_count_zeros_ull(unsigned long long int value) [[unsequenced]];
    /*generic_return_type*/
    stdc_count_zeros(/*generic_value_type*/ value) [[unsequenced]];
    unsigned int stdc_count_ones_uc(unsigned char value) [[unsequenced]];
    unsigned int stdc_count_ones_us(unsigned short value) [[unsequenced]];
    unsigned int stdc_count_ones_ui(unsigned int value) [[unsequenced]];
    unsigned int stdc_count_ones_ul(unsigned long int value) [[unsequenced]];
    unsigned int stdc_count_ones_ull(unsigned long long int value) [[unsequenced]];
    /*generic_return_type*/
    stdc_count_ones(/*generic_value_type*/ value) [[unsequenced]];
    bool stdc_has_single_bit_uc(unsigned char value) [[unsequenced]];
    bool stdc_has_single_bit_us(unsigned short value) [[unsequenced]];
    bool stdc_has_single_bit_ui(unsigned int value) [[unsequenced]];
    bool stdc_has_single_bit_ul(unsigned long int value) [[unsequenced]];
    bool stdc_has_single_bit_ull(unsigned long long int value) [[unsequenced]];
    bool stdc_has_single_bit(/*generic_value_type*/ value) [[unsequenced]];
    unsigned int stdc_bit_width_uc(unsigned char value) [[unsequenced]];
    unsigned int stdc_bit_width_us(unsigned short value) [[unsequenced]];
    unsigned int stdc_bit_width_ui(unsigned int value) [[unsequenced]];
    unsigned int stdc_bit_width_ul(unsigned long int value) [[unsequenced]];
    unsigned int stdc_bit_width_ull(unsigned long long int value) [[unsequenced]];
    /*generic_return_type*/
    stdc_bit_width(/*generic_value_type*/ value) [[unsequenced]];
    unsigned char stdc_bit_floor_uc(unsigned char value) [[unsequenced]];
    unsigned short stdc_bit_floor_us(unsigned short value) [[unsequenced]];
    unsigned int stdc_bit_floor_ui(unsigned int value) [[unsequenced]];
    unsigned long int stdc_bit_floor_ul(unsigned long int value) [[unsequenced]];
    unsigned long long int stdc_bit_floor_ull(unsigned long long int value) [[unsequenced]];
    /*generic_value_type*/
    stdc_bit_floor(/*generic_value_type*/ value) [[unsequenced]];
    unsigned char stdc_bit_ceil_uc(unsigned char value) [[unsequenced]];
    unsigned short stdc_bit_ceil_us(unsigned short value) [[unsequenced]];
    unsigned int stdc_bit_ceil_ui(unsigned int value) [[unsequenced]];
    unsigned long int stdc_bit_ceil_ul(unsigned long int value) [[unsequenced]];
    unsigned long long int stdc_bit_ceil_ull(unsigned long long int value) [[unsequenced]];
    /*generic_value_type*/
    stdc_bit_ceil(/*generic_value_type*/ value) [[unsequenced]];
    unsigned char stdc_rotate_left_uc(unsigned char value, unsigned int count);
    unsigned short stdc_rotate_left_us(unsigned short value, unsigned int count);
    unsigned int stdc_rotate_left_ui(unsigned int value, unsigned int count);
    unsigned long stdc_rotate_left_ul(unsigned long value, unsigned int count);
    unsigned long long stdc_rotate_left_ull(unsigned long long value, unsigned int count);
    /*generic_value_type*/
    stdc_rotate_left(/*generic_value_type*/ value, generic_count_type count);
    unsigned char stdc_rotate_right_uc(unsigned char value, unsigned int count);
    unsigned short stdc_rotate_right_us(unsigned short value, unsigned int count);
    unsigned int stdc_rotate_right_ui(unsigned int value, unsigned int count);
    unsigned long stdc_rotate_right_ul(unsigned long value, unsigned int count);
    unsigned long long stdc_rotate_right_ull(unsigned long long value, unsigned int count);
    /*generic_value_type*/
    stdc_rotate_right(/*generic_value_type*/ value, generic_count_type count);

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/stdbit&oldid=180174](https://en.cppreference.com/mwiki/index.php?title=c/header/stdbit&oldid=180174)" 

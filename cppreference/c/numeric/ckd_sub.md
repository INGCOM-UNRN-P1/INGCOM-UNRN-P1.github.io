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

[Checked integer arithmetic](../numeric.html#Checked_integer_arithmetic_.28since_C23.29 "c/numeric")

[Functions](../numeric.html#Checked_integer_arithmetic "c/numeric")  
---  
[ckd_add](ckd_add.html "c/numeric/ckd add")(C23)  
**ckd_sub**(C23)  
[ckd_mul](ckd_mul.html "c/numeric/ckd mul")(C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/chk_math/navbar_content&action=edit)

Defined in header `[`<stdckdint.h>`](../header/stdckdint.html "c/header/stdckdint")` |  |   
---|---|---  
#define ckd_sub( result, a, b ) /* implementation-defined */  
// exposed interface:  
bool ckd_sub( type1* result, type2 a, type3 b ); |  |  (since C23)  
| |   
  
Computes the subtraction x - y and stores the result into *result. The subtraction is performed as if both operands were represented in a signed integer type with infinite range, and the result was then converted from this integer type to type1. If the value assigned to *result correctly represents the mathematical result of the operation, it returns false. Otherwise, it returns true. In this case, the value assigned to *result is the mathematical result of the operation wrapped around to the width of *result. 

## Contents

  * [1 Parameters](ckd_sub.html#Parameters)
  * [2 Return value](ckd_sub.html#Return_value)
  * [3 Note](ckd_sub.html#Note)
  * [4 Example](ckd_sub.html#Example)
  * [5 References](ckd_sub.html#References)
  * [6 See also](ckd_sub.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/ckd_op&action=edit&section=T-1 "Template:c/numeric/ckd op")] Parameters

a, b  |  \-  |  integer values   
---|---|---  
result  |  \-  |  address of where result should be stored   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/ckd_op&action=edit&section=T-2 "Template:c/numeric/ckd op")] Return value

false if the value assigned to *result correctly represents the mathematical result of the subtraction, true otherwise. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/ckd_op&action=edit&section=T-3 "Template:c/numeric/ckd op")] Note

Both type2 and type3 shall be any integer type other than “plain” char, bool, a [bit-precise integer type](../language/arithmetic_types.html "c/language/arithmetic types"), or an [enumerated type](../language/enum.html "c/language/enum"), and they can be the same. *result shall be a modifiable lvalue of any integer type other than “plain” char, bool, a bit-precise integer type, or an enumerated type. 

It is recommended to produce a diagnostic message if type2 or type3 are not suitable integer types, or if *result is not a modifiable lvalue of a suitable integer type. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/ckd_op&action=edit&section=T-4 "Template:c/numeric/ckd op")] Example

| This section is incomplete  
Reason: no example   
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/ckd_op&action=edit&section=T-5 "Template:c/numeric/ckd op")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.20.1 The ckd_ checked integer operation macros (p: 311) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/ckd_op&action=edit&section=T-6 "Template:c/numeric/ckd op")] See also

[ ckd_add](ckd_add.html "c/numeric/ckd add")(C23) |  checked addition operation on two integers  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_ckd_add&action=edit)  
---|---  
[ ckd_mul](ckd_mul.html "c/numeric/ckd mul")(C23) |  checked multiplication operation on two integers  
(type-generic function macro)[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/dsc_ckd_mul&action=edit)  
[C++ documentation](../../cpp/numeric/ckd_sub.html "cpp/numeric/ckd sub") for ckd_sub  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/numeric/ckd_sub&oldid=178630](https://en.cppreference.com/mwiki/index.php?title=c/numeric/ckd_sub&oldid=178630)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo no example](../../Category%253ATodo_no_example.html "Category:Todo no example")



From cppreference.com

< [c](../../c.html "c")‎ | [language](../language.html "c/language")

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

[ C language](../language.html "c/language")

[Basic concepts](basic_concepts.html "c/language/basic concepts")  
---  
[ Keywords](../keyword.html "c/keyword")  
[ Preprocessor](../preprocessor.html "c/preprocessor")  
[ Statements](statements.html "c/language/statements")  
[ Expressions](operators.html "c/language/expressions")  
[ Initialization](initialization.html "c/language/initialization")  
[ Declarations](declarations.html "c/language/declarations")  
[ Functions](functions.html "c/language/functions")  
Miscellaneous  
[ History of C](history.html "c/language/history")  
[Technical Specifications](../experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

[ Basic Concepts](basic_concepts.html "c/language/basic concepts")

[ Comments](../comment.html "c/comment")  
---  
[ ASCII](ascii.html "c/language/ascii")  
[ Character sets](charset.html "c/language/charset")  
[ Translation phases](translation_phases.html "c/language/translation phases")  
[Punctuation](punctuators.html "c/language/punctuators")  
[Identifier](identifiers.html "c/language/identifier")  
[Scope](scope.html "c/language/scope")  
[Lifetime](lifetime.html "c/language/lifetime")  
[Lookup and name spaces](name_space.html "c/language/name space")  
[Type](compatible_type.html "c/language/type")  
**Arithmetic types**  
[Objects and alignment](object.html "c/language/object")  
[The main() function](main_function.html "c/language/main function")  
[The as-if rule](as_if.html "c/language/as if")  
[Undefined behavior](behavior.html "c/language/behavior")  
[Memory model and data races](memory_model.html "c/language/memory model")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/basics/navbar_content&action=edit)

(See also [type](compatible_type.html "c/language/type") for type system overview and [the list of type-related utilities](../types.html "c/types") that are provided by the C library.)

| 

## Contents

  * [1 Boolean type](arithmetic_types.html#Boolean_type)
  * [2 Character types](arithmetic_types.html#Character_types)
  * [3 Integer types](arithmetic_types.html#Integer_types)
    * [3.1 Data models](arithmetic_types.html#Data_models)
  * [4 Real floating types](arithmetic_types.html#Real_floating_types)
  * [5 Complex floating types](arithmetic_types.html#Complex_floating_types)
  * [6 Imaginary floating types](arithmetic_types.html#Imaginary_floating_types)
  * [7 Keywords](arithmetic_types.html#Keywords)
  * [8 Range of values](arithmetic_types.html#Range_of_values)
  * [9 See also](arithmetic_types.html#See_also)

  
---  
  
###  Boolean type

    

  * _Bool (also accessible as the macro [`bool`](../types.html "c/types"))(until C23)bool(since C23) — type, capable of holding one of the two values: 1 and ​0​ (also accessible as the macros [`true`](../types.html "c/types") and [`false`](../types.html "c/types"))(until C23)true and false(since C23). 



Note that [conversion](conversion.html "c/language/conversion") to _Bool(until C23)bool(since C23) does not work the same as conversion to other integer types: (bool)0.5 evaluates to true, whereas (int)0.5 evaluates to ​0​. 

(since C99)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/arithmetic_types&action=edit&section=2 "Edit section: Character types")] Character types

    

  * signed char — type for signed character representation. 
  * unsigned char — type for unsigned character representation. Also used to inspect [object representations](object.html "c/language/object") (raw memory). 
  * char — type for character representation. Equivalent to either signed char or unsigned char (which one is implementation-defined and may be controlled by a compiler commandline switch), but char is a distinct type, different from both signed char and unsigned char. 



Note that the standard library also defines [typedef](typedef.html "c/language/typedef") names [`wchar_t`](../string/wide.html "c/string/wide"), [`char16_t`](../string/multibyte.html "c/string/multibyte") and [`char32_t`](../string/multibyte.html "c/string/multibyte")(since C11) to represent wide characters and [`char8_t`](../string/multibyte.html "c/string/multibyte") for UTF-8 characters(since C23). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/arithmetic_types&action=edit&section=3 "Edit section: Integer types")] Integer types

    

  * short int (also accessible as short, may use the keyword signed) 
  * unsigned short int (also accessible as unsigned short) 
  * int (also accessible as signed int) 



     This is the most optimal integer type for the platform, and is guaranteed to be at least 16 bits. Most current systems use 32 bits (see Data models below). 

  * unsigned int (also accessible as unsigned), the unsigned counterpart of int, implementing modulo arithmetic. Suitable for bit manipulations. 
  * long int (also accessible as long) 
  * unsigned long int (also accessible as unsigned long) 



    

  * long long int (also accessible as long long) 
  * unsigned long long int (also accessible as unsigned long long) 


| (since C99)  
---|---  
  
    

  * _BitInt(n) (also accessible as signed _BitInt(n)), the bit-precise signed integer types (where `n` is replaced by an integer constant expression denoting the precise width (including the sign bit), that cannot be larger than BITINT_MAXWIDTH from [`<limits.h>`](../header/limits.html "c/header/limits")) 
  * unsigned _BitInt(n), the bit-precise unsigned integer types (where `n` is replaced by an integer constant expression denoting the precise width, that cannot be larger than BITINT_MAXWIDTH from [`<limits.h>`](../header/limits.html "c/header/limits")) 


| (since C23)  
  
Note: as with all type specifiers, any order is permitted: unsigned long long int and long int unsigned long name the same type. 

The following table summarizes all available integer types and their properties: 

Type specifier  | Equivalent type  | Width in bits by data model   
---|---|---  
C standard  |  LP32  |  ILP32  |  LLP64  |  LP64   
char | char | at least  
**8** | **8** | **8** | **8** | **8**  
signed char | signed char  
unsigned char | unsigned char  
short | short int | at least  
**16** | **16** | **16** | **16** | **16**  
short int  
signed short  
signed short int  
unsigned short | unsigned short int  
unsigned short int  
int | int | at least  
**16** | **16** | **32** | **32** | **32**  
signed  
signed int  
unsigned | unsigned int  
unsigned int  
long | long int | at least  
**32** | **32** | **32** | **32** | **64**  
long int  
signed long  
signed long int  
unsigned long | unsigned long int  
unsigned long int  
long long | long long int  
(C99) | at least  
**64** | **64** | **64** | **64** | **64**  
long long int  
signed long long  
signed long long int  
unsigned long long | unsigned long long int  
(C99)  
unsigned long long int  
  
Besides the minimal bit counts, the C Standard guarantees that 

    1 == sizeof(char) `≤` sizeof(short) `≤` sizeof(int) `≤` sizeof(long) `≤` sizeof(long long). 

Note: this allows the extreme case in which [byte](https://en.wikipedia.org/wiki/byte "enwiki:byte") are sized 64 bits, all types (including char) are 64 bits wide, and sizeof returns 1 for every type. 

Note: integer arithmetic is defined differently for the signed and unsigned integer types. See [arithmetic operators](operator_arithmetic.html "c/language/operator arithmetic"), in particular [integer overflows](operator_arithmetic.html#Overflows "c/language/operator arithmetic"). 

#### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/arithmetic_types&action=edit&section=4 "Edit section: Data models")] Data models

The choices made by each implementation about the sizes of the fundamental types are collectively known as _data model_. Four data models found wide acceptance: 

32 bit systems: 

    

  * **LP32** or **2/4/4** (int is 16-bit, long and pointer are 32-bit) 



    

  * Win16 API 



  * **ILP32** or **4/4/4** (int, long, and pointer are 32-bit); 



    

  * Win32 API 
  * Unix and Unix-like systems (Linux, Mac OS X) 



64 bit systems: 

    

  * **LLP64** or **4/4/8** (int and long are 32-bit, pointer is 64-bit) 



    

  * Win64 API 



  * **LP64** or **4/8/8** (int is 32-bit, long and pointer are 64-bit) 



    

  * Unix and Unix-like systems (Linux, Mac OS X) 



Other models are very rare. For example, **ILP64** (**8/8/8** : int, long, and pointer are 64-bit) only appeared in some early 64-bit Unix systems (e.g. [Unicos on Cray](https://en.wikipedia.org/wiki/UNICOS "enwiki:UNICOS")). 

Note that exact-width integer types are available in [`<stdint.h>`](../header/stdint.html "c/header/stdint") since C99. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/arithmetic_types&action=edit&section=5 "Edit section: Real floating types")] Real floating types

C has three or six(since C23) types for representing real floating-point values: 

    

  * float — single precision floating-point type. Matches [IEEE-754 binary32 format](https://en.wikipedia.org/wiki/Single-precision_floating-point_format "enwiki:Single-precision floating-point format") if supported. 
  * double — double precision floating-point type. Matches [IEEE-754 binary64 format](https://en.wikipedia.org/wiki/Double-precision_floating-point_format "enwiki:Double-precision floating-point format") if supported. 
  * long double — extended precision floating-point type. Matches [IEEE-754 binary128 format](https://en.wikipedia.org/wiki/Quadruple-precision_floating-point_format "enwiki:Quadruple-precision floating-point format") if supported, otherwise matches [IEEE-754 binary64-extended format](https://en.wikipedia.org/wiki/Extended_precision "enwiki:Extended precision") if supported, otherwise matches some non-IEEE-754 extended floating-point format as long as its precision is better than binary64 and range is at least as good as binary64, otherwise matches IEEE-754 binary64 format. 
    * binary128 format is used by some HP-UX, SPARC, MIPS, ARM64, and z/OS implementations. 
    * The most well known IEEE-754 binary64-extended format is 80-bit x87 extended precision format. It is used by many x86 and x86-64 implementations (a notable exception is MSVC, which implements long double in the same format as double, i.e. binary64). 



     If the implementation predefines the macro constant `__STDC_IEC_60559_DFP__`, the following decimal floating-point types are also supported. 

  * _Decimal32 — Represents [IEEE-754 decimal32 format](https://en.wikipedia.org/wiki/decimal32_floating-point_format "enwiki:decimal32 floating-point format"). 
  * _Decimal64 — Represents [IEEE-754 decimal64 format](https://en.wikipedia.org/wiki/decimal64_floating-point_format "enwiki:decimal64 floating-point format"). 
  * _Decimal128 — Represents [IEEE-754 decimal128 format](https://en.wikipedia.org/wiki/decimal128_floating-point_format "enwiki:decimal128 floating-point format"). 


     Otherwise, these decimal floating-point types are not supported. 
| (since C23)  
---|---  
  
Floating-point types may support special values: 

  * _infinity_ (positive and negative), see [`INFINITY`](../numeric/math/INFINITY.html "c/numeric/math/INFINITY")
  * the _negative zero_ , -0.0. It compares equal to the positive zero, but is meaningful in some arithmetic operations, e.g. 1.0 / 0.0 == INFINITY, but 1.0 / -0.0 == -INFINITY) 
  * _not-a-number_ (NaN), which does not compare equal with anything (including itself). Multiple bit patterns represent NaNs, see [nan](../numeric/math/nan.html "c/numeric/math/nan"), [`NAN`](../numeric/math/NAN.html "c/numeric/math/NAN"). Note that C takes no special notice of signaling NaNs (specified by IEEE-754), and treats all NaNs as quiet. 



Real floating-point numbers may be used with [arithmetic operators](operator_arithmetic.html "c/language/operator arithmetic") `**+**` `**-**` `**/**` `*****` and various mathematical functions from [`<math.h>`](../header/math.html "c/header/math"). Both built-in operators and library functions may raise floating-point exceptions and set [errno](../error/errno.html "c/error/errno") as described in [`math_errhandling`](../numeric/math/math_errhandling.html "c/numeric/math/math errhandling"). 

Floating-point expressions may have greater range and precision than indicated by their types, see [FLT_EVAL_METHOD](../types/limits/FLT_EVAL_METHOD.html "c/types/limits/FLT EVAL METHOD"). [Assignment](operator_assignment.html "c/language/operator assignment"), [return](return.html "c/language/return"), and [cast](cast.html "c/language/cast") force the range and precision to the one associated with the declared type. 

Floating-point expressions may also be _contracted_ , that is, calculated as if all intermediate values have infinite range and precision, see [` #pragma STDC FP_CONTRACT`](../preprocessor/impl.html#Standard_pragmas "c/preprocessor/impl"). 

Some operations on floating-point numbers are affected by and modify the state of [the floating-point environment](../numeric/fenv.html "c/numeric/fenv") (most notably, the rounding direction). 

[Implicit conversions](conversion.html "c/language/conversion") are defined between real floating types and integer, complex, and imaginary types. 

See [Limits of floating-point types](../types/limits.html#Limits_of_floating-point_types "c/types/limits") and the [`<math.h>`](../header/math.html "c/header/math") library for additional details, limits, and properties of the floating-point types. 

###  Complex floating types

Complex floating types model the mathematical [complex number](https://en.wikipedia.org/wiki/complex_number "enwiki:complex number"), that is the numbers that can be written as a sum of a real number and a real number multiplied by the imaginary unit: a + bi The three complex types are 

    

  * float _Complex (also available as float [complex](../numeric/complex/complex.html) if [`<complex.h>`](../header/complex.html "c/header/complex") is included) 
  * double _Complex (also available as double [complex](../numeric/complex/complex.html) if [`<complex.h>`](../header/complex.html "c/header/complex") is included) 
  * long double _Complex (also available as long double [complex](../numeric/complex/complex.html) if [`<complex.h>`](../header/complex.html "c/header/complex") is included) 


Note: as with all type specifiers, any order is permitted: long double [complex](../numeric/complex/complex.html), [complex](../numeric/complex/complex.html) long double, and even double [complex](../numeric/complex/complex.html) long name the same type.  Run this code
    
    
    #include <complex.h>
    #include <stdio.h>
     
    int main(void)
    {
        double [complex](../numeric/complex/complex.html) z = 1 + 2*I;
        z = 1 / z;
        [printf](../io/fprintf.html)("1/(1.0+2.0i) = %.1f%+.1fi\n", [creal](../numeric/complex/creal.html)(z), [cimag](../numeric/complex/cimag.html)(z));
    }

Output: 
    
    
    1/(1.0+2.0i) = 0.2-0.4i

|  If the macro constant `__STDC_NO_COMPLEX__` is defined by the implementation, the complex types (as well as the library header [`<complex.h>`](../header/complex.html "c/header/complex")) are not provided.  | (since C11)  
---|---  
  
Each complex type has the same [object representation](object.html "c/language/object") and [alignment requirements](object.html "c/language/object") as an [array](array.html "c/language/array") of two elements of the corresponding real type (float for float [complex](../numeric/complex/complex.html), double for double [complex](../numeric/complex/complex.html), long double for long double [complex](../numeric/complex/complex.html)). The first element of the array holds the real part, and the second element of the array holds the imaginary component. 
    
    
    float a[4] = {1, 2, 3, 4};
    float [complex](../numeric/complex/complex.html) z1, z2;
    [memcpy](../string/byte/memcpy.html)(&z1, a, sizeof z1); // z1 becomes 1.0 + 2.0i
    [memcpy](../string/byte/memcpy.html)(&z2, a+2, sizeof z2); // z2 becomes 3.0 + 4.0i

Complex numbers may be used with [arithmetic operators](operator_arithmetic.html "c/language/operator arithmetic") `**+**` `**-**` `*****` and `**/**`, possibly mixed with imaginary and real numbers. There are many mathematical functions defined for complex numbers in [`<complex.h>`](../header/complex.html "c/header/complex"). Both built-in operators and library functions may raise floating-point exceptions and set [errno](../error/errno.html "c/error/errno") as described in [`math_errhandling`](../numeric/math/math_errhandling.html "c/numeric/math/math errhandling"). 

Increment and decrement are not defined for complex types. 

Relational operators are not defined for complex types (there is no notion of "less than"). 

| This section is incomplete  
Reason: review other ops, link library   
---|---  
[Implicit conversions](conversion.html "c/language/conversion") are defined between complex types and other arithmetic types. 

In order to support the one-infinity model of complex number arithmetic, C regards any complex value with at least one infinite part as an infinity even if its other part is a NaN, guarantees that all operators and functions honor basic properties of infinities and provides [cproj](../numeric/complex/cproj.html "c/numeric/complex/cproj") to map all infinities to the canonical one (see [arithmetic operators](operator_arithmetic.html "c/language/operator arithmetic") for the exact rules). 

Run this code
    
    
    #include <complex.h>
    #include <math.h>
    #include <stdio.h>
     
    int main(void)
    {
        double [complex](../numeric/complex/complex.html) z = (1 + 0*I) * (INFINITY + I*INFINITY);
    //  textbook formula would give
    //  (1+i0)(∞+i∞) ⇒ (1×∞ – 0×∞) + i(0×∞+1×∞) ⇒ NaN + I*NaN
    //  but C gives a complex infinity
        [printf](../io/fprintf.html)("%f%+f*i\n", [creal](../numeric/complex/creal.html)(z), [cimag](../numeric/complex/cimag.html)(z));
     
    //  textbook formula would give
    //  cexp(∞+iNaN) ⇒ exp(∞)×(cis(NaN)) ⇒ NaN + I*NaN
    //  but C gives  ±∞+i*nan
        double [complex](../numeric/complex/complex.html) y = [cexp](../numeric/complex/cexp.html)(INFINITY + I*NAN);
        [printf](../io/fprintf.html)("%f%+f*i\n", [creal](../numeric/complex/creal.html)(y), [cimag](../numeric/complex/cimag.html)(y));
    }

Possible output: 
    
    
    inf+inf*i 
    inf+nan*i

C also treats multiple infinities so as to preserve directional information where possible, despite the inherent limitations of the Cartesian representation: 

multiplying the imaginary unit by real infinity gives the correctly-signed imaginary infinity: i × ∞ = i∞. Also, i × (∞ – i∞) = ∞ + i∞ indicates the reasonable quadrant. 

| This section is incomplete  
Reason: wording   
---|---  
  
###  Imaginary floating types

Imaginary floating types model the mathematical [imaginary numbers](https://en.wikipedia.org/wiki/imaginary_numbers "enwiki:imaginary numbers"), that is numbers that can be written as a real number multiplied by the imaginary unit: bi The three imaginary types are 

    

  * float _Imaginary (also available as float [imaginary](../numeric/complex/imaginary.html) if [`<complex.h>`](../header/complex.html "c/header/complex") is included) 
  * double _Imaginary (also available as double [imaginary](../numeric/complex/imaginary.html) if [`<complex.h>`](../header/complex.html "c/header/complex") is included) 
  * long double _Imaginary (also available as long double [imaginary](../numeric/complex/imaginary.html) if [`<complex.h>`](../header/complex.html "c/header/complex") is included) 



Note: as with all type specifiers, any order is permitted: long double [imaginary](../numeric/complex/imaginary.html), [imaginary](../numeric/complex/imaginary.html) long double, and even double [imaginary](../numeric/complex/imaginary.html) long name the same type. 

Run this code
    
    
    #include <complex.h>
    #include <stdio.h>
     
    int main(void)
    {
        double [imaginary](../numeric/complex/imaginary.html) z = 3*I;
        z = 1 / z;
        [printf](../io/fprintf.html)("1/(3.0i) = %+.1fi\n", [cimag](../numeric/complex/cimag.html)(z));
    }

Output: 
    
    
    1/(3.0i) = -0.3i

An implementation that defines `__STDC_IEC_559_COMPLEX__` is recommended, but not required to support imaginary numbers. POSIX recommends checking if the macro [_Imaginary_I](../numeric/complex/Imaginary_I.html "c/numeric/complex/Imaginary I") is defined to identify imaginary number support.  | (until C11)  
---|---  
Imaginary numbers are supported if `__STDC_IEC_559_COMPLEX__`(until C23)`__STDC_IEC_60559_COMPLEX__`(since C23) is defined.  | (since C11)  
  
Each of the three imaginary types has the same [object representation](object.html "c/language/object") and [alignment requirement](object.html "c/language/object") as its _corresponding real type_ (float for float [imaginary](../numeric/complex/imaginary.html), double for double [imaginary](../numeric/complex/imaginary.html), long double for long double [imaginary](../numeric/complex/imaginary.html)). 

Note: despite that, imaginary types are distinct and [not compatible](compatible_type.html#Compatible_types "c/language/type") with their corresponding real types, which prohibits aliasing. 

Imaginary numbers may be used with [arithmetic operators](operator_arithmetic.html "c/language/operator arithmetic") `**+**` `**-**` `*****` and `**/**`, possibly mixed with complex and real numbers. There are many mathematical functions defined for imaginary numbers in [`<complex.h>`](../header/complex.html "c/header/complex"). Both built-in operators and library functions may raise floating-point exceptions and set [errno](../error/errno.html "c/error/errno") as described in [`math_errhandling`](../numeric/math/math_errhandling.html "c/numeric/math/math errhandling"). 

Increment and decrement are not defined for imaginary types. 

| This section is incomplete  
Reason: review other ops, link library   
---|---  
[Implicit conversions](conversion.html "c/language/conversion") are defined between imaginary types and other arithmetic types. 

The imaginary numbers make it possible to express all complex numbers using the natural notation x + I*y (where I is defined as [_Imaginary_I](../numeric/complex/Imaginary_I.html "c/numeric/complex/Imaginary I")). Without imaginary types, certain special complex values cannot be created naturally. For example, if I is defined as [_Complex_I](../numeric/complex/Complex_I.html "c/numeric/complex/Complex I"), then writing 0.0 + I*INFINITY gives NaN as the real part, and [CMPLX](../numeric/complex/CMPLX.html)(0.0, INFINITY) must be used instead. Same goes for the numbers with the negative zero imaginary component, which are meaningful when working with the library functions with branch cuts, such as [csqrt](../numeric/complex/csqrt.html "c/numeric/complex/csqrt"): 1.0 - 0.0*I results in the positive zero imaginary component if I is defined as [_Complex_I](../numeric/complex/Complex_I.html "c/numeric/complex/Complex I") and the negative zero imaginary part requires the use of [CMPLX](../numeric/complex/CMPLX.html "c/numeric/complex/CMPLX") or [conj](../numeric/complex/conj.html "c/numeric/complex/conj"). 

Imaginary types also simplify implementations; multiplication of an imaginary by a complex can be implemented straightforwardly with two multiplications if the imaginary types are supported, instead of four multiplications and two additions. 

(since C99)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/arithmetic_types&action=edit&section=8 "Edit section: Keywords")] Keywords

  * [`bool`](../keyword/bool.html "c/keyword/bool"), [`true`](../keyword/true.html "c/keyword/true"), [`false`](../keyword/false.html "c/keyword/false"), [`char`](../keyword/char.html "c/keyword/char"), [`int`](../keyword/int.html "c/keyword/int"), [`short`](../keyword/short.html "c/keyword/short"), [`long`](../keyword/long.html "c/keyword/long"), [`signed`](../keyword/signed.html "c/keyword/signed"), [`unsigned`](../keyword/unsigned.html "c/keyword/unsigned"), [`float`](../keyword/float.html "c/keyword/float"), [`double`](../keyword/double.html "c/keyword/double"). 
  * [`_Bool`](../keyword/_Bool.html "c/keyword/ Bool"), [`_BitInt`](https://en.cppreference.com/mwiki/index.php?title=c/keyword/_BitInt&action=edit&redlink=1 "c/keyword/ BitInt \(page does not exist\)"), [`_Complex`](../keyword/_Complex.html "c/keyword/ Complex"), [`_Imaginary`](../keyword/_Imaginary.html "c/keyword/ Imaginary"), [`_Decimal32`](../keyword/_Decimal32.html "c/keyword/ Decimal32"), [`_Decimal64`](../keyword/_Decimal64.html "c/keyword/ Decimal64"), [`_Decimal128`](../keyword/_Decimal128.html "c/keyword/ Decimal128"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/arithmetic_types&action=edit&section=9 "Edit section: Range of values")] Range of values

The following table provides a reference for the limits of common numeric representations. 

Prior to C23, the C Standard allowed any signed integer representation, and the minimum guaranteed range of N-bit signed integers was from \\(\scriptsize -(2^{N-1}-1)\\)-(2N-1  
-1) to \\(\scriptsize +2^{N-1}-1\\)+2N-1  
-1 (e.g. **-127** to **127** for a signed 8-bit type), which corresponds to the limits of [one's complement](https://en.wikipedia.org/wiki/one%27s_complement "enwiki:one's complement") or [sign-and-magnitude](https://en.wikipedia.org/wiki/Signed_number_representations#Sign-and-magnitude_method "enwiki:Signed number representations"). 

However, all popular data models (including all of ILP32, LP32, LP64, LLP64) and almost all C compilers use [two's complement](https://en.wikipedia.org/wiki/two%27s_complement "enwiki:two's complement") representation (the only known exceptions are some compilers for UNISYS), and as of C23, it is the only representation allowed by the standard, with the guaranteed range from \\(\scriptsize -2^{N-1}\\)-2N-1  
to \\(\scriptsize +2^{N-1}-1\\)+2N-1  
-1 (e.g. **-128** to **127** for a signed 8-bit type). 

Type  | Size in bits  | Format  | Value range   
---|---|---|---  
Approximate  | Exact   
character  | 8  | signed  |  | **−128** to **127**  
unsigned  |  | **0** to **255**  
16  | UTF-16  |  | **0** to **65535**  
32  | UTF-32  |  | **0** to **1114111** (**0x10ffff**)   
integer  | 16  | signed  | **± 3.27 · 10 4** | **−32768** to **32767**  
unsigned  | **0** to **6.55 · 10 4** | **0** to **65535**  
32  | signed  | **± 2.14 · 10 9** | **−2,147,483,648** to **2,147,483,647**  
unsigned  | **0** to **4.29 · 10 9** | **0** to **4,294,967,295**  
64  | signed  | **± 9.22 · 10 18** | **−9,223,372,036,854,775,808** to **9,223,372,036,854,775,807**  
unsigned  | **0** to **1.84 · 10 19** | **0** to **18,446,744,073,709,551,615**  
binary  
floating-  
point  | 32  | [IEEE-754](https://en.wikipedia.org/wiki/Single-precision_floating-point_format "enwiki:Single-precision floating-point format") | 

  * min subnormal:  
**± 1.401,298,4 · 10 −45**
  * min normal:  
**± 1.175,494,3 · 10 −38**
  * max:  
**± 3.402,823,4 · 10 38**

| 

  * min subnormal:  
**±0x1p−149**
  * min normal:  
**±0x1p−126**
  * max:  
**±0x1.fffffep+127**

  
64  | [IEEE-754](https://en.wikipedia.org/wiki/Double-precision_floating-point_format "enwiki:Double-precision floating-point format") | 

  * min subnormal:  
**± 4.940,656,458,412 · 10 −324**
  * min normal:  
**± 2.225,073,858,507,201,4 · 10 −﻿308**
  * max:  
**± 1.797,693,134,862,315,7 · 10 308**

| 

  * min subnormal:  
**±0x1p−1074**
  * min normal:  
**±0x1p−1022**
  * max:  
**±0x1.fffffffffffffp+1023**

  
80[[note 1]](arithmetic_types.html#cite_note-1) | [x86](https://en.wikipedia.org/wiki/Extended_precision "enwiki:Extended precision") | 

  * min subnormal:  
**± 3.645,199,531,882,474,602,528  
· 10−4951**
  * min normal:  
**± 3.362,103,143,112,093,506,263  
· 10−4932**
  * max:  
**± 1.189,731,495,357,231,765,021  
· 104932**

| 

  * min subnormal:  
**±0x1p−16445**
  * min normal:  
**±0x1p−16382**
  * max:  
**±0x1.fffffffffffffffep+16383**

  
128  | [IEEE-754](https://en.wikipedia.org/wiki/Quadruple-precision_floating-point_format "enwiki:Quadruple-precision floating-point format") | 

  * min subnormal:  
**± 6.475,175,119,438,025,110,924,  
438,958,227,646,552,5 · 10−4966**
  * min normal:  
**± 3.362,103,143,112,093,506,262,  
677,817,321,752,602,6 · 10−4932**
  * max:  
**± 1.189,731,495,357,231,765,085,  
759,326,628,007,016,2 · 104932**

| 

  * min subnormal:  
**±0x1p−16494**
  * min normal:  
**±0x1p−16382**
  * max:  
**±0x1.ffffffffffffffffffffffffffff  
p+16383**

  
decimal  
floating-  
point  | 32  | [IEEE-754](https://en.wikipedia.org/wiki/decimal32_floating-point_format "enwiki:decimal32 floating-point format") |  | 

  * min subnormal:  
**± 1 · 10 -101**
  * min normal:  
**± 1 · 10 -95**
  * max:  
**± 9.999'999 · 10 96**

  
64  | [IEEE-754](https://en.wikipedia.org/wiki/decimal64_floating-point_format "enwiki:decimal64 floating-point format") |  | 

  * min subnormal:  
**± 1 · 10 -398**
  * min normal:  
**± 1 · 10 -383**
  * max:  
**± 9.999'999'999'999'999 · 10 384**

  
128  | [IEEE-754](https://en.wikipedia.org/wiki/decimal128_floating-point_format "enwiki:decimal128 floating-point format") |  | 

  * min subnormal:  
**± 1 · 10 -6176**
  * min normal:  
**± 1 · 10 -6143**
  * max:  
**± 9.999'999'999'999'999'999'  
999'999'999'999'999 · 106144**

  
  
  1. [↑](arithmetic_types.html#cite_ref-1) The object representation usually occupies 96/128 bits on 32/64-bit platforms respectively.



Note: actual (as opposed to guaranteed minimal) ranges are available in the library headers [`<limits.h>`](../header/limits.html "c/header/limits") and [`<float.h>`](../header/float.html "c/header/float"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/arithmetic_types&action=edit&section=10 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/types.html "cpp/language/types") for Fundamental types  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/arithmetic_types&oldid=180190](https://en.cppreference.com/mwiki/index.php?title=c/language/arithmetic_types&oldid=180190)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



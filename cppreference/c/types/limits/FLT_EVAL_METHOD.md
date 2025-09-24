From cppreference.com

< [c](../../../c.html "c")‎ | [types](../../types.html "c/types")‎ | [limits](../limits.html "c/types/limits")

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

[ Type support](../../types.html "c/types")

[size_t](../size_t.html "c/types/size t")  
---  
[ptrdiff_t](../ptrdiff_t.html "c/types/ptrdiff t")  
[nullptr_t](../nullptr_t.html "c/types/nullptr t")(C23)  
[NULL](../NULL.html "c/types/NULL")  
[max_align_t](../max_align_t.html "c/types/max align t")(C11)  
[offsetof](../offsetof.html "c/types/offsetof")  
[ Numeric limits](../limits.html "c/types/limits")  
[ Fixed width integer types](../integer.html "c/types/integer") (C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/navbar_content&action=edit)

[ Numeric limits](../limits.html "c/types/limits")

[FLT_ROUNDS](FLT_ROUNDS.html "c/types/limits/FLT ROUNDS")  
---  
**FLT_EVAL_METHOD**(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/limits/navbar_content&action=edit)

Defined in header `[`<float.h>`](../../header/float.html "c/header/float")` |  |   
---|---|---  
#define FLT_EVAL_METHOD /* implementation-defined */ |  |  (since C99)  
| |   
  
Specifies range and precision of floating-point values obtained from floating-point constants and from all operations (operators, implicit conversions of operands) except assignment, cast, and library function call. 

Value  |  Explanation   
---|---  
negative values except -1 |  implementation-defined behavior   
-1 |  the default precision is not known   
​0​ |  all operations and constants evaluate in the range and precision of the type used. Additionally, float_t and double_t are equivalent to float and double respectively   
1 |  all operations and constants evaluate in the range and precision of double. Additionally, both float_t and double_t are equivalent to double  
2 |  all operations and constants evaluate in the range and precision of long double. Additionally, both float_t and double_t are equivalent to long double  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/limits/FLT_EVAL_METHOD&action=edit&section=1 "Edit section: Notes")] Notes

Regardless of the value of FLT_EVAL_METHOD, any floating-point expression may be _contracted_ , that is, calculated as if all intermediate results have infinite range and precision (unless [` #pragma`](../../preprocessor/impl.html "c/preprocessor/impl") STDC FP_CONTRACT is off). 

Cast and assignment strip away any extraneous range and precision: this models the action of storing a value from an extended-precision FPU register into a standard-sized memory location. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/limits/FLT_EVAL_METHOD&action=edit&section=2 "Edit section: See also")] See also

[ float_t](../../numeric/math/float_t.html "c/numeric/math/float t")(C99) |  most efficient floating-point type at least as wide as float   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_float_t&action=edit)  
---|---  
[ double_t](../../numeric/math/float_t.html "c/numeric/math/float t")(C99) |  most efficient floating-point type at least as wide as double   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_double_t&action=edit)  
[C++ documentation](../../../cpp/types/climits/FLT_EVAL_METHOD.html "cpp/types/climits/FLT EVAL METHOD") for FLT_EVAL_METHOD  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/types/limits/FLT_EVAL_METHOD&oldid=180195](https://en.cppreference.com/mwiki/index.php?title=c/types/limits/FLT_EVAL_METHOD&oldid=180195)" 

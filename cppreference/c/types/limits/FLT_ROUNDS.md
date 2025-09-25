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

**FLT_ROUNDS**  
---  
[FLT_EVAL_METHOD](FLT_EVAL_METHOD.html "c/types/limits/FLT EVAL METHOD")(C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/limits/navbar_content&action=edit)

Defined in header `[`<float.h>`](../../header/float.html "c/header/float")` |  |   
---|---|---  
#define FLT_ROUNDS /* implementation defined */ |  |   
| |   
  
Returns the current rounding direction of floating-point arithmetic operations. 

Value  |  Explanation   
---|---  
`-1` |  the default rounding direction is not known   
`0` |  toward zero; same meaning as [FE_TOWARDZERO](../../numeric/fenv/FE_round.html "c/numeric/fenv/FE round")  
`1` |  to nearest; same meaning as [FE_TONEAREST](../../numeric/fenv/FE_round.html "c/numeric/fenv/FE round")  
`2` |  towards positive infinity; same meaning as [FE_UPWARD](../../numeric/fenv/FE_round.html "c/numeric/fenv/FE round")  
`3` |  towards negative infinity; same meaning as [FE_DOWNWARD](../../numeric/fenv/FE_round.html "c/numeric/fenv/FE round")  
other values  |  implementation-defined behavior   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/limits/FLT_ROUNDS&action=edit&section=1 "Edit section: Notes")] Notes

The rounding mode can be changed with [fesetround](../../numeric/fenv/feround.html "c/numeric/fenv/feround") and **FLT_ROUNDS** reflects that change. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/limits/FLT_ROUNDS&action=edit&section=2 "Edit section: See also")] See also

[ fegetroundfesetround](../../numeric/fenv/feround.html "c/numeric/fenv/feround")(C99)(C99) |  gets or sets rounding direction   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_feround&action=edit)  
---|---  
[ FE_DOWNWARDFE_TONEARESTFE_TOWARDZEROFE_UPWARD](../../numeric/fenv/FE_round.html "c/numeric/fenv/FE round")(C99) |  floating-point rounding direction   
(macro constant) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/fenv/dsc_FE_round&action=edit)  
[C++ documentation](../../../cpp/types/climits/FLT_ROUNDS.html "cpp/types/climits/FLT ROUNDS") for FLT_ROUNDS  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/types/limits/FLT_ROUNDS&oldid=108863](https://en.cppreference.com/mwiki/index.php?title=c/types/limits/FLT_ROUNDS&oldid=108863)" 

From cppreference.com

< [c](../../c.html "c")‎ | [experimental](../experimental.html "c/experimental")

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

[ Technical Specifications](../experimental.html "c/experimental")

[ Extensions for embedded processors](https://en.cppreference.com/mwiki/index.php?title=c/experimental/embedded&action=edit&redlink=1 "c/experimental/embedded \(page does not exist\)")  
---  
[ Dynamic memory extensions](dynamic.html "c/experimental/dynamic")  
**Floating-point extensions part 1: Binary floating-point**  
[ Floating-point extensions part 4: Supplementary functions](fpext4.html "c/experimental/fpext4")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/navbar_content&action=edit)

**Floating-point extensions part 1: Binary floating-point**

[Template:c/experimental/fpext1/navbar content](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/fpext1/navbar_content&action=edit&redlink=1 "Template:c/experimental/fpext1/navbar content \(page does not exist\)")

[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/fpext1/navbar_content&action=edit)

![](https://upload.cppreference.com/mwiki/images/3/31/Imbox_notice.png) |  **Merged into ISO C** The functionality described on this page was merged into the mainline ISO C standard as of 3/2019; link TBD (since C23)  
---|---  
  
Floating-point extensions for C - Part 1: Binary floating-point arithmetic, ISO/IEC TS 18661-1:2014, defines the following new components for the C standard library, as recommended by ISO/IEC/IEEE 60559:2011 (the current revision of IEEE-754) 

__STDC_IEC_60559_BFP__ |  integer constant of type long and value 201ymmL, replaces __STDC_IEC_559__   
(macro constant)  
---|---  
__STDC_IEC_60559_COMPLEX__ |  integer constant of type long and value 201ymmL, replaces __STDC_IEC_559_COMPLEX__   
(macro constant)  
Defined in header `[`<limits.h>`](../header/limits.html "c/header/limits")`  
CHAR_WIDTH SCHAR_WIDTH UCHAR_WIDTHSHRT_WIDTH USHRT_WIDTHINT_WIDTH UINT_WIDTHLONG_WIDTH ULONG_WIDTHLLONG_WIDTH ULLONG_WIDTH(FP Ext 1 TS) |  width, in bits, of the corresponding type   
(macro constant)  
Defined in header `[`<float.h>`](../header/float.html "c/header/float")`  
[ CR_DECIMAL_DIG](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/CR_DECIMAL_DIG&action=edit&redlink=1 "c/experimental/fpext1/CR DECIMAL DIG \(page does not exist\)")(FP Ext 1 TS) |  conversions between all supported binary floating-point types and character sequences with at most CR_DECIMAL_DIG significant decimal digits are correctly rounded (this is at least DECIMAL_DIG + 3)   
(macro constant)  
Defined in header `[`<fenv.h>`](../header/fenv.html "c/header/fenv")`  
femode_t(FP Ext 1 TS) |  collection of dynamic floating-point control modes supported by the implementation, including the dynamic rounding direction mode   
(typedef)  
FE_DFL_MODE(FP Ext 1 TS) |  pointer to the default femode_t   
(macro constant)  
FE_SNANS_ALWAYS_SIGNAL(FP Ext 1 TS) |  defined (as integer constant 1) if sNaN arguments cause the functions that suppress qNaNs, like [hypot](../numeric/math/hypot.html "c/numeric/math/hypot") or [fmax](../numeric/math/fmax.html "c/numeric/math/fmax"), to raise FE_INVALID and return a qNaN   
(macro constant)  
[ fesetexcept](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/fesetexcept&action=edit&redlink=1 "c/experimental/fpext1/fesetexcept \(page does not exist\)")(FP Ext 1 TS) |  sets the specified floating-point exception flags without causing any side-effects that raising them would   
(function)  
[ fetestexceptflag](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/fetestexceptflag&action=edit&redlink=1 "c/experimental/fpext1/fetestexceptflag \(page does not exist\)")(FP Ext 1 TS) |  tests if given flags are in a saved representation of the floating-point exception flags   
(function)  
[ fegetmodefesetmode](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/fegetmode_fesetmode&action=edit&redlink=1 "c/experimental/fpext1/fegetmode fesetmode \(page does not exist\)")(FP Ext 1 TS) |  gets and sets all the implementation’s dynamic floating-point control modes collectively   
(function)  
Defined in header `[`<stdint.h>`](../header/stdint.html "c/header/stdint")`  
INTn_WIDTH UINTn_WIDTHINT_LEASTn_WIDTH UINT_LEASTn_WIDTHINT_FASTn_WIDTH UINT_FASTn_WIDTHINTPTR_WIDTH UINTPTR_WIDTHINTMAX_WIDTH UINTMAX_WIDTHPTRDIFF_WIDTHSIG_ATOMIC_WIDTHSIZE_WIDTHWCHAR_WIDTH WINT_WIDTH(FP Ext 1 TS) |  width, in bits, of the corresponding type   
(macro constant)  
Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")`  
[ strfromdstrfromfstrfroml](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/strfromf&action=edit&redlink=1 "c/experimental/fpext1/strfromf \(page does not exist\)")(FP Ext 1 TS) |  convert a single foating-point number to string using the specified snprintf format   
(function)  
Defined in header `[`<math.h>`](../header/math.html "c/header/math")`  
FP_INT_UPWARDFP_INT_DOWNWARDFP_INT_TOWARDZERO FP_INT_TONEARESTFROMZEROFP_INT_TONEAREST(FP Ext 1 TS) |  rounding direction for the functions ceil, floor, trunc, round, and roundeven, suitable for use with fromfp family of functions   
(macro constant)  
FP_LLOGB0(FP Ext 1 TS) |  value returned by llogb if the argument is zero   
(macro constant)  
FP_LLOGBNAN(FP Ext 1 TS) |  value returned by llogb if the argument is NaN   
(macro constant)  
[ SNANFSNANSNANL](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/SNAN&action=edit&redlink=1 "c/experimental/fpext1/SNAN \(page does not exist\)")(FP Ext 1 TS) |  represents a signalling NaN for float, double, long double respectively   
(macro constant)  
FP_FAST_FADD FP_FAST_FADDL FP_FAST_DADDLFP_FAST_FSUB FP_FAST_FSUBL FP_FAST_DSUBLFP_FAST_FMUL FP_FAST_FMULL FP_FAST_DMULLFP_FAST_FDIV FP_FAST_FDIVL FP_FAST_DDIVLFP_FAST_FFMA FP_FAST_FFMAL FP_FAST_DFMALFP_FAST_FSQRT FP_FAST_FSQRTL FP_FAST_DSQRTL(FP Ext 1 TS) |  if defined, indicates that the corresponding function executes faster than the equivalent function in a larger type followed by a cast to target type   
(macro constant)  
iseqsig(FP Ext 1 TS) |    
(function macro)  
iscanonical(FP Ext 1 TS) |  tests if the floating-point value is canonical   
(function macro)  
issignaling(FP Ext 1 TS) |  tests if the floating-point value is a signalling NaN   
(function macro)  
issubnormal(FP Ext 1 TS) |  tests if the floating-point value is subnormal   
(function macro)  
iszero(FP Ext 1 TS) |  tests if the floating-point value is a zero (positive, negative, unsigned)   
(function macro)  
[ fromfpfromfpffromfpl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/fromfp&action=edit&redlink=1 "c/experimental/fpext1/fromfp \(page does not exist\)")(FP Ext 1 TS) |  round to signed integer using the specified rounding direction   
(function)  
[ ufromfpufromfpfufromfpl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/ufromfp&action=edit&redlink=1 "c/experimental/fpext1/ufromfp \(page does not exist\)")(FP Ext 1 TS) |  round to unsigned integer using the specified rounding direction   
(function)  
[ fromfpxfromfpxffromfpxl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/fromfpx&action=edit&redlink=1 "c/experimental/fpext1/fromfpx \(page does not exist\)")(FP Ext 1 TS) |  round to signed integer using the specified rounding direction, reporting inexactness   
(function)  
[ ufromfpxufromfpxfufromfpxl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/ufromfpx&action=edit&redlink=1 "c/experimental/fpext1/ufromfpx \(page does not exist\)")(FP Ext 1 TS) |  round to unsigned integer using the specified rounding direction, reporting inexactness   
(function)  
[ roundevenroundevenfroundevenl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/roundeven&action=edit&redlink=1 "c/experimental/fpext1/roundeven \(page does not exist\)")(FP Ext 1 TS) |  rounds to nearest, halfway cases to even   
(function)  
[ llogbllogbfllogbl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/llogb&action=edit&redlink=1 "c/experimental/fpext1/llogb \(page does not exist\)")(FP Ext 1 TS) |  equivalent to [logb](../numeric/math/logb.html "c/numeric/math/logb") except the return type is long   
(function)  
[ fmaxmagfmaxmagffmaxmagl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/fmaxmag&action=edit&redlink=1 "c/experimental/fpext1/fmaxmag \(page does not exist\)")(FP Ext 1 TS) |  returns the value of their argument of maximum magnitude   
(function)  
[ fminmagfminmagffminmagl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/fminmag&action=edit&redlink=1 "c/experimental/fpext1/fminmag \(page does not exist\)")(FP Ext 1 TS) |  returns the value of their argument of minimum magnitude   
(function)  
[ nextupnextupfnextupl](fpext1/nextup.html "c/experimental/fpext1/nextup")(FP Ext 1 TS) |  returns the next greater representable floating-point value   
(function)  
[ nextdownnextdownfnextdown l](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/nextdown&action=edit&redlink=1 "c/experimental/fpext1/nextdown \(page does not exist\)")(FP Ext 1 TS) |  returns the next smaller representable floating-point value   
(function)  
[ faddfaddldaddl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/fadd&action=edit&redlink=1 "c/experimental/fpext1/fadd \(page does not exist\)")(FP Ext 1 TS) |  calculates x+y as if in infinite precision and rounded once to target type   
(function)  
[ fsubfsubldsubl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/fsub&action=edit&redlink=1 "c/experimental/fpext1/fsub \(page does not exist\)")(FP Ext 1 TS) |  calculates x-y as if in infinite precision and rounded once to target type   
(function)  
[ fmulfmulldmull](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/fmul&action=edit&redlink=1 "c/experimental/fpext1/fmul \(page does not exist\)")(FP Ext 1 TS) |  calculates x*y as if in infinite precision and rounded once to target type   
(function)  
[ fdivfdivlddivl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/fdiv&action=edit&redlink=1 "c/experimental/fpext1/fdiv \(page does not exist\)")(FP Ext 1 TS) |  calculates x/y as if in infinite precision and rounded once to target type   
(function)  
[ ffmaffmaldfmal](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/ffma&action=edit&redlink=1 "c/experimental/fpext1/ffma \(page does not exist\)")(FP Ext 1 TS) |  calculates the same as [fma](../numeric/math/fma.html "c/numeric/math/fma") as if in infinite precision and rounded once to target type   
(function)  
[ fsqrtfsqrtldsqrtl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/fsqrt&action=edit&redlink=1 "c/experimental/fpext1/fsqrt \(page does not exist\)")(FP Ext 1 TS) |  calculates the same as [sqrt](../numeric/math/sqrt.html "c/numeric/math/sqrt") as if in infinite precision and rounded once to target type   
(function)  
[ totalordertotalorderftotalorderl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/totalorder&action=edit&redlink=1 "c/experimental/fpext1/totalorder \(page does not exist\)")(FP Ext 1 TS) |  orders two floating-point values using the ISO 60559 total order relation   
(function)  
[ totalordermagtotalordermagftotalordermagl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/totalordermag&action=edit&redlink=1 "c/experimental/fpext1/totalordermag \(page does not exist\)")(FP Ext 1 TS) |  orders the magnitudes of two floating-point values using the ISO 60559 total order relation   
(function)  
[ canonicalizecanonicalizefcanonicalizel](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/canonicalize&action=edit&redlink=1 "c/experimental/fpext1/canonicalize \(page does not exist\)")(FP Ext 1 TS) |  obtains the ISO 60559 canonical binary encoding of the given floating-point value   
(function)  
[ getpayloadgetpayloadfgetpayloadl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/getpayload&action=edit&redlink=1 "c/experimental/fpext1/getpayload \(page does not exist\)")(FP Ext 1 TS) |  extracts the payload from the given NaN value   
(function)  
[ setpayloadsetpayloadfsetpayloadl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/setpayload&action=edit&redlink=1 "c/experimental/fpext1/setpayload \(page does not exist\)")(FP Ext 1 TS) |  creates a quiet NaN with the specified payload   
(function)  
[ setpayloadsigsetpayloadsigfsetpayloadsigl](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1/setpayloadsig&action=edit&redlink=1 "c/experimental/fpext1/setpayloadsig \(page does not exist\)")(FP Ext 1 TS) |  creates a signalling NaN with the specified payload   
(function)  
Defined in header `[`<tgmath.h>`](../header/tgmath.html "c/header/tgmath")`  
roundeven(FP Ext 1 TS) |  generic overload of roundeven   
(function)  
llogb(FP Ext 1 TS) |  generic overload of llogb   
(function)  
fmaxmag(FP Ext 1 TS) |  generic overload of fmaxmag   
(function)  
fminmag(FP Ext 1 TS) |  generic overload of fminmag   
(function)  
nextup(FP Ext 1 TS) |  generic overload of nextup   
(function)  
nextdown(FP Ext 1 TS) |  generic overload of nextdown   
(function)  
fromfp(FP Ext 1 TS) |  generic overload of fromfp   
(function)  
ufromfp(FP Ext 1 TS) |  generic overload of ufromfp   
(function)  
fromfpx(FP Ext 1 TS) |  generic overload of fromfpx   
(function)  
ufromfpx(FP Ext 1 TS) |  generic overload of ufromfpx   
(function)  
nextdown(FP Ext 1 TS) |  generic overload of nextdown   
(function)  
totalorder(FP Ext 1 TS) |  generic overload of totalorder   
(function)  
totalordermag(FP Ext 1 TS) |  generic overload of totalordermag   
(function)  
fadd(FP Ext 1 TS) |  generic overload of fadd   
(function)  
dadd(FP Ext 1 TS) |  generic overload of dadd   
(function)  
fsub(FP Ext 1 TS) |  generic overload of fsub   
(function)  
dsub(FP Ext 1 TS) |  generic overload of dsub   
(function)  
fmul(FP Ext 1 TS) |  generic overload of fmul   
(function)  
dmul(FP Ext 1 TS) |  generic overload of dmul   
(function)  
fdiv(FP Ext 1 TS) |  generic overload of fdiv   
(function)  
ddiv(FP Ext 1 TS) |  generic overload of ddiv   
(function)  
ffma(FP Ext 1 TS) |  generic overload of ffma   
(function)  
dfma(FP Ext 1 TS) |  generic overload of dfma   
(function)  
fsqrt(FP Ext 1 TS) |  generic overload of fsqrt   
(function)  
dsqrt(FP Ext 1 TS) |  generic overload of dsqrt   
(function)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1&action=edit&section=1 "Edit section: Notes")] Notes

The standard C macros __STDC_IEC_559__ and __STDC_IEC_559_COMPLEX__ are made obsolete by this technical specification. 

All functions and macros added to the C library by this extension are only declared if a macro __STDC_WANT_IEC_60559_BFP_EXT__ is defined before the corresponding header is included. 

Besides additions to the standard library, ISO/IEC TS 18661-1:2014 makes a number of changes to the core language, notably splitting floating-point control between static (controlled by the new #pragma STDC FENV_ROUND), and dynamic (controlled by [fesetround](../numeric/fenv/feround.html "c/numeric/fenv/feround")). Most math.h functions respect the static rounding mode, if set, over the dynamic rounding mode. 

| This section is incomplete  
Reason: add to the pragma page or describe the pragma in full here?   
---|---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1&oldid=124001](https://en.cppreference.com/mwiki/index.php?title=c/experimental/fpext1&oldid=124001)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



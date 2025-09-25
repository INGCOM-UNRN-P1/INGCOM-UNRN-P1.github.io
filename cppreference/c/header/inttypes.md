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
**`< inttypes.h>`** (C99)` `  
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
[`<stdbit.h>`](stdbit.html "c/header/stdbit") (C23)  
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

This header is part of the [type support](../types.html "c/types") library, in particular, it is a part of [format conversion of integer types](../types/integer.html#Format_macro_constants "c/types/integer") interface. 

| 

## Contents

  * [1 Includes](inttypes.html#Includes)
  * [2 Types](inttypes.html#Types)
  * [3 Functions](inttypes.html#Functions)
  * [4 Macros](inttypes.html#Macros)
    * [4.1 Format constants for the fprintf family of functions](inttypes.html#Format_constants_for_the_fprintf_family_of_functions)
    * [4.2 Format constants for the fscanf family of functions](inttypes.html#Format_constants_for_the_fscanf_family_of_functions)
  * [5 Synopsis](inttypes.html#Synopsis)

  
---  
  
###  Includes  
  
[ <stdint.h>](stdint.html "c/header/stdint")(C99) |  [Fixed-width integer types](../types/integer.html "c/types/integer")[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/dsc_stdint&action=edit)  
  
###  Types  
  
[ imaxdiv_t](../numeric/math/div.html "c/numeric/math/div")(C99) |  structure type, return of the imaxdiv function   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_imaxdiv_t&action=edit)  
  
###  Functions  
  
[ imaxabs](../numeric/math/abs.html "c/numeric/math/abs")(C99) |  computes absolute value of an integral value (\\(\small{|x|}\\)|x|)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_imaxabs&action=edit)  
[ imaxdiv](../numeric/math/div.html "c/numeric/math/div")(C99) |  computes quotient and remainder of integer division   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/numeric/math/dsc_imaxdiv&action=edit)  
[ strtoimaxstrtoumax](../string/byte/strtoimax.html "c/string/byte/strtoimax")(C99)(C99) |  converts a byte string to [intmax_t](../types/integer.html "c/types/integer") or [uintmax_t](../types/integer.html "c/types/integer")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strtoimax&action=edit)  
[ wcstoimaxwcstoumax](../string/wide/wcstoimax.html "c/string/wide/wcstoimax")(C99)(C99) |  converts a wide string to [intmax_t](../types/integer.html "c/types/integer") or [uintmax_t](../types/integer.html "c/types/integer")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstoimax&action=edit)  
  
###  Macros  
  
#####  Format constants for the [fprintf](../io/fprintf.html "c/io/fprintf") family of functions   
  
PRId8PRId16PRId32PRId64PRIdLEAST8PRIdLEAST16PRIdLEAST32PRIdLEAST64PRIdFAST8PRIdFAST16PRIdFAST32PRIdFAST64PRIdMAXPRIdPTR(C99) |  format conversion specifier to output a signed decimal integer value of type [int8_t](../types/integer.html "c/types/integer"), [int16_t](../types/integer.html "c/types/integer"), [int32_t](../types/integer.html "c/types/integer"), [int64_t](../types/integer.html "c/types/integer"), [int_least8_t](../types/integer.html "c/types/integer"), [int_least16_t](../types/integer.html "c/types/integer"), [int_least32_t](../types/integer.html "c/types/integer"), [int_least64_t](../types/integer.html "c/types/integer"), [int_fast8_t](../types/integer.html "c/types/integer"), [int_fast16_t](../types/integer.html "c/types/integer"), [int_fast32_t](../types/integer.html "c/types/integer"), [int_fast64_t](../types/integer.html "c/types/integer"), [intmax_t](../types/integer.html "c/types/integer"), [intptr_t](../types/integer.html "c/types/integer") respectively, equivalent to `d` for int   
(macro constant)  
PRIi8PRIi16PRIi32PRIi64PRIiLEAST8PRIiLEAST16PRIiLEAST32PRIiLEAST64PRIiFAST8PRIiFAST16PRIiFAST32PRIiFAST64PRIiMAXPRIiPTR(C99) |  format conversion specifier to output a signed decimal integer value of type [int8_t](../types/integer.html "c/types/integer"), [int16_t](../types/integer.html "c/types/integer"), [int32_t](../types/integer.html "c/types/integer"), [int64_t](../types/integer.html "c/types/integer"), [int_least8_t](../types/integer.html "c/types/integer"), [int_least16_t](../types/integer.html "c/types/integer"), [int_least32_t](../types/integer.html "c/types/integer"), [int_least64_t](../types/integer.html "c/types/integer"), [int_fast8_t](../types/integer.html "c/types/integer"), [int_fast16_t](../types/integer.html "c/types/integer"), [int_fast32_t](../types/integer.html "c/types/integer"), [int_fast64_t](../types/integer.html "c/types/integer"), [intmax_t](../types/integer.html "c/types/integer"), [intptr_t](../types/integer.html "c/types/integer") respectively, equivalent to `i` for int   
(macro constant)  
PRIu8PRIu16PRIu32PRIu64PRIuLEAST8PRIuLEAST16PRIuLEAST32PRIuLEAST64PRIuFAST8PRIuFAST16PRIuFAST32PRIuFAST64PRIuMAXPRIuPTR(C99) |  format conversion specifier to output an unsigned decimal integer value of type [uint8_t](../types/integer.html "c/types/integer"), [uint16_t](../types/integer.html "c/types/integer"), [uint32_t](../types/integer.html "c/types/integer"), [uint64_t](../types/integer.html "c/types/integer"), [uint_least8_t](../types/integer.html "c/types/integer"), [uint_least16_t](../types/integer.html "c/types/integer"), [uint_least32_t](../types/integer.html "c/types/integer"), [uint_least64_t](../types/integer.html "c/types/integer"), [uint_fast8_t](../types/integer.html "c/types/integer"), [uint_fast16_t](../types/integer.html "c/types/integer"), [uint_fast32_t](../types/integer.html "c/types/integer"), [uint_fast64_t](../types/integer.html "c/types/integer"), [uintmax_t](../types/integer.html "c/types/integer"), [uintptr_t](../types/integer.html "c/types/integer") respectively, equivalent to `u` for unsigned int   
(macro constant)  
PRIo8PRIo16PRIo32PRIo64PRIoLEAST8PRIoLEAST16PRIoLEAST32PRIoLEAST64PRIoFAST8PRIoFAST16PRIoFAST32PRIoFAST64PRIoMAXPRIoPTR(C99) |  format conversion specifier to output an unsigned octal integer value of type [uint8_t](../types/integer.html "c/types/integer"), [uint16_t](../types/integer.html "c/types/integer"), [uint32_t](../types/integer.html "c/types/integer"), [uint64_t](../types/integer.html "c/types/integer"), [uint_least8_t](../types/integer.html "c/types/integer"), [uint_least16_t](../types/integer.html "c/types/integer"), [uint_least32_t](../types/integer.html "c/types/integer"), [uint_least64_t](../types/integer.html "c/types/integer"), [uint_fast8_t](../types/integer.html "c/types/integer"), [uint_fast16_t](../types/integer.html "c/types/integer"), [uint_fast32_t](../types/integer.html "c/types/integer"), [uint_fast64_t](../types/integer.html "c/types/integer"), [uintmax_t](../types/integer.html "c/types/integer"), [uintptr_t](../types/integer.html "c/types/integer") respectively, equivalent to `o` for unsigned int   
(macro constant)  
PRIx8PRIx16PRIx32PRIx64PRIxLEAST8PRIxLEAST16PRIxLEAST32PRIxLEAST64PRIxFAST8PRIxFAST16PRIxFAST32PRIxFAST64PRIxMAXPRIxPTR(C99) |  format conversion specifier to output an unsigned lowercase hexadecimal integer value of type [uint8_t](../types/integer.html "c/types/integer"), [uint16_t](../types/integer.html "c/types/integer"), [uint32_t](../types/integer.html "c/types/integer"), [uint64_t](../types/integer.html "c/types/integer"), [uint_least8_t](../types/integer.html "c/types/integer"), [uint_least16_t](../types/integer.html "c/types/integer"), [uint_least32_t](../types/integer.html "c/types/integer"), [uint_least64_t](../types/integer.html "c/types/integer"), [uint_fast8_t](../types/integer.html "c/types/integer"), [uint_fast16_t](../types/integer.html "c/types/integer"), [uint_fast32_t](../types/integer.html "c/types/integer"), [uint_fast64_t](../types/integer.html "c/types/integer"), [uintmax_t](../types/integer.html "c/types/integer"), [uintptr_t](../types/integer.html "c/types/integer") respectively, equivalent to `x` for unsigned int   
(macro constant)  
PRIX8PRIX16PRIX32PRIX64PRIXLEAST8PRIXLEAST16PRIXLEAST32PRIXLEAST64PRIXFAST8PRIXFAST16PRIXFAST32PRIXFAST64PRIXMAXPRIXPTR(C99) |  format conversion specifier to output an unsigned uppercase hexadecimal integer value of type [uint8_t](../types/integer.html "c/types/integer"), [uint16_t](../types/integer.html "c/types/integer"), [uint32_t](../types/integer.html "c/types/integer"), [uint64_t](../types/integer.html "c/types/integer"), [uint_least8_t](../types/integer.html "c/types/integer"), [uint_least16_t](../types/integer.html "c/types/integer"), [uint_least32_t](../types/integer.html "c/types/integer"), [uint_least64_t](../types/integer.html "c/types/integer"), [uint_fast8_t](../types/integer.html "c/types/integer"), [uint_fast16_t](../types/integer.html "c/types/integer"), [uint_fast32_t](../types/integer.html "c/types/integer"), [uint_fast64_t](../types/integer.html "c/types/integer"), [uintmax_t](../types/integer.html "c/types/integer"), [uintptr_t](../types/integer.html "c/types/integer") respectively, equivalent to `X` for unsigned int   
(macro constant)  
  
#####  Format constants for the [fscanf](../io/fscanf.html "c/io/fscanf") family of functions   
  
SCNd8SCNd16SCNd32SCNd64SCNdLEAST8SCNdLEAST16SCNdLEAST32SCNdLEAST64SCNdFAST8SCNdFAST16SCNdFAST32SCNdFAST64SCNdMAXSCNdPTR(C99) |  format conversion specifier to input a signed decimal integer value of type [int8_t](../types/integer.html "c/types/integer"), [int16_t](../types/integer.html "c/types/integer"), [int32_t](../types/integer.html "c/types/integer"), [int64_t](../types/integer.html "c/types/integer"), [int_least8_t](../types/integer.html "c/types/integer"), [int_least16_t](../types/integer.html "c/types/integer"), [int_least32_t](../types/integer.html "c/types/integer"), [int_least64_t](../types/integer.html "c/types/integer"), [int_fast8_t](../types/integer.html "c/types/integer"), [int_fast16_t](../types/integer.html "c/types/integer"), [int_fast32_t](../types/integer.html "c/types/integer"), [int_fast64_t](../types/integer.html "c/types/integer"), [intmax_t](../types/integer.html "c/types/integer"), [intptr_t](../types/integer.html "c/types/integer") respectively, equivalent to `d` for int   
(macro constant)  
SCNi8SCNi16SCNi32SCNi64SCNiLEAST8SCNiLEAST16SCNiLEAST32SCNiLEAST64SCNiFAST8SCNiFAST16SCNiFAST32SCNiFAST64SCNiMAXSCNiPTR(C99) |  format conversion specifier to input a signed decimal/octal/hexadecimal integer value of type [int8_t](../types/integer.html "c/types/integer"), [int16_t](../types/integer.html "c/types/integer"), [int32_t](../types/integer.html "c/types/integer"), [int64_t](../types/integer.html "c/types/integer"), [int_least8_t](../types/integer.html "c/types/integer"), [int_least16_t](../types/integer.html "c/types/integer"), [int_least32_t](../types/integer.html "c/types/integer"), [int_least64_t](../types/integer.html "c/types/integer"), [int_fast8_t](../types/integer.html "c/types/integer"), [int_fast16_t](../types/integer.html "c/types/integer"), [int_fast32_t](../types/integer.html "c/types/integer"), [int_fast64_t](../types/integer.html "c/types/integer"), [intmax_t](../types/integer.html "c/types/integer"), [intptr_t](../types/integer.html "c/types/integer") respectively, equivalent to `i` for int   
(macro constant)  
SCNu8SCNu16SCNu32SCNu64SCNuLEAST8SCNuLEAST16SCNuLEAST32SCNuLEAST64SCNuFAST8SCNuFAST16SCNuFAST32SCNuFAST64SCNuMAXSCNuPTR(C99) |  format conversion specifier to input an unsigned decimal integer value of type [uint8_t](../types/integer.html "c/types/integer"), [uint16_t](../types/integer.html "c/types/integer"), [uint32_t](../types/integer.html "c/types/integer"), [uint64_t](../types/integer.html "c/types/integer"), [uint_least8_t](../types/integer.html "c/types/integer"), [uint_least16_t](../types/integer.html "c/types/integer"), [uint_least32_t](../types/integer.html "c/types/integer"), [uint_least64_t](../types/integer.html "c/types/integer"), [uint_fast8_t](../types/integer.html "c/types/integer"), [uint_fast16_t](../types/integer.html "c/types/integer"), [uint_fast32_t](../types/integer.html "c/types/integer"), [uint_fast64_t](../types/integer.html "c/types/integer"), [uintmax_t](../types/integer.html "c/types/integer"), [uintptr_t](../types/integer.html "c/types/integer") respectively, equivalent to `u` for unsigned int   
(macro constant)  
SCNo8SCNo16SCNo32SCNo64SCNoLEAST8SCNoLEAST16SCNoLEAST32SCNoLEAST64SCNoFAST8SCNoFAST16SCNoFAST32SCNoFAST64SCNoMAXSCNoPTR(C99) |  format conversion specifier to input an unsigned octal integer value of type [uint8_t](../types/integer.html "c/types/integer"), [uint16_t](../types/integer.html "c/types/integer"), [uint32_t](../types/integer.html "c/types/integer"), [uint64_t](../types/integer.html "c/types/integer"), [uint_least8_t](../types/integer.html "c/types/integer"), [uint_least16_t](../types/integer.html "c/types/integer"), [uint_least32_t](../types/integer.html "c/types/integer"), [uint_least64_t](../types/integer.html "c/types/integer"), [uint_fast8_t](../types/integer.html "c/types/integer"), [uint_fast16_t](../types/integer.html "c/types/integer"), [uint_fast32_t](../types/integer.html "c/types/integer"), [uint_fast64_t](../types/integer.html "c/types/integer"), [uintmax_t](../types/integer.html "c/types/integer"), [uintptr_t](../types/integer.html "c/types/integer") respectively, equivalent to `o` for unsigned int   
(macro constant)  
SCNx8SCNx16SCNx32SCNx64SCNxLEAST8SCNxLEAST16SCNxLEAST32SCNxLEAST64SCNxFAST8SCNxFAST16SCNxFAST32SCNxFAST64SCNxMAXSCNxPTR(C99) |  format conversion specifier to input an unsigned hexadecimal integer value of type [uint8_t](../types/integer.html "c/types/integer"), [uint16_t](../types/integer.html "c/types/integer"), [uint32_t](../types/integer.html "c/types/integer"), [uint64_t](../types/integer.html "c/types/integer"), [uint_least8_t](../types/integer.html "c/types/integer"), [uint_least16_t](../types/integer.html "c/types/integer"), [uint_least32_t](../types/integer.html "c/types/integer"), [uint_least64_t](../types/integer.html "c/types/integer"), [uint_fast8_t](../types/integer.html "c/types/integer"), [uint_fast16_t](../types/integer.html "c/types/integer"), [uint_fast32_t](../types/integer.html "c/types/integer"), [uint_fast64_t](../types/integer.html "c/types/integer"), [uintmax_t](../types/integer.html "c/types/integer"), [uintptr_t](../types/integer.html "c/types/integer") respectively, equivalent to `x` for unsigned int   
(macro constant)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/inttypes&action=edit&section=1 "Edit section: Synopsis")] Synopsis
    
    
    using imaxdiv_t = /* see description */;
     
    [intmax_t](../types/integer.html) imaxabs([intmax_t](../types/integer.html) j);
    imaxdiv_t imaxdiv([intmax_t](../types/integer.html) numer, [intmax_t](../types/integer.html) denom);
    [intmax_t](../types/integer.html) [strtoimax](../string/byte/strtoimax.html)(const char* restrict nptr, char** restrict endptr, int base);
    [uintmax_t](../types/integer.html) [strtoumax](../string/byte/strtoimax.html)(const char* restrict nptr, char** restrict endptr, int base);
    [intmax_t](../types/integer.html) [wcstoimax](../string/wide/wcstoimax.html)(const wchar_t* restrict nptr, wchar_t** restrict endptr, int base);
    [uintmax_t](../types/integer.html) [wcstoumax](../string/wide/wcstoimax.html)(const wchar_t* restrict nptr, wchar_t** restrict endptr, int base);
     
    #define PRIdN /* see description */
    #define PRIiN /* see description */
    #define PRIoN /* see description */
    #define PRIuN /* see description */
    #define PRIxN /* see description */
    #define PRIXN /* see description */
    #define SCNdN /* see description */
    #define SCNiN /* see description */
    #define SCNoN /* see description */
    #define SCNuN /* see description */
    #define SCNxN /* see description */
    #define PRIdLEASTN /* see description */
    #define PRIiLEASTN /* see description */
    #define PRIoLEASTN /* see description */
    #define PRIuLEASTN /* see description */
    #define PRIxLEASTN /* see description */
    #define PRIXLEASTN /* see description */
    #define SCNdLEASTN /* see description */
    #define SCNiLEASTN /* see description */
    #define SCNoLEASTN /* see description */
    #define SCNuLEASTN /* see description */
    #define SCNxLEASTN /* see description */
    #define PRIdFASTN /* see description */
    #define PRIiFASTN /* see description */
    #define PRIoFASTN /* see description */
    #define PRIuFASTN /* see description */
    #define PRIxFASTN /* see description */
    #define PRIXFASTN /* see description */
    #define SCNdFASTN /* see description */
    #define SCNiFASTN /* see description */
    #define SCNoFASTN /* see description */
    #define SCNuFASTN /* see description */
    #define SCNxFASTN /* see description */
    #define PRIdMAX /* see description */
    #define PRIiMAX /* see description */
    #define PRIoMAX /* see description */
    #define PRIuMAX /* see description */
    #define PRIxMAX /* see description */
    #define PRIXMAX /* see description */
    #define SCNdMAX /* see description */
    #define SCNiMAX /* see description */
    #define SCNoMAX /* see description */
    #define SCNuMAX /* see description */
    #define SCNxMAX /* see description */
    #define PRIdPTR /* see description */
    #define PRIiPTR /* see description */
    #define PRIoPTR /* see description */
    #define PRIuPTR /* see description */
    #define PRIxPTR /* see description */
    #define PRIXPTR /* see description */
    #define SCNdPTR /* see description */
    #define SCNiPTR /* see description */
    #define SCNoPTR /* see description */
    #define SCNuPTR /* see description */
    #define SCNxPTR /* see description */

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/inttypes&oldid=183254](https://en.cppreference.com/mwiki/index.php?title=c/header/inttypes&oldid=183254)" 

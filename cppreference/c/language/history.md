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
**History of C**  
[Technical Specifications](../experimental.html "c/experimental")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/navbar_content&action=edit)

## Contents

  * [1 Early C](history.html#Early_C)
  * [2 Standard C](history.html#Standard_C)
    * [2.1 Future development](history.html#Future_development)
    * [2.2 See also](history.html#See_also)
    * [2.3 External links](history.html#External_links)

  
---  
  
## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/history&action=edit&section=1 "Edit section: Early C")] Early C

  * 1969: B created, based on BCPL, to replace PDP-7 assembler as the system programming language for Unix 



    

  * added operators ++, \--, compound assignment, remained a typeless language like BCPL 



  * 1971: NB ("new B") created when porting B to PDP-11 



    

  * types (int, char, arrays and pointers), array-to-pointer conversion, compilation to machine code 



  * 1972: Language renamed to C 



    

  * struct, operators && and ||, preprocessor, portable I/O 



  * 1973: Unix re-written in C 



    

  * unsigned, long, union, enumerations, increased type safety 



  * 1978: The C Programming Language, 1st edition 



## [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/history&action=edit&section=2 "Edit section: Standard C")] Standard C

  * 1983: ANSI established X3J11 committee 
  * 1988: The C Programming Language, 2nd edition 
  * 1989: **C89** , the ANSI C standard published 


  1. codified existing practices 
  2. new features: volatile, enum, signed, void, locales 
  3. From C++: const, function prototypes 


  * 1990: **C90** , the ANSI C standard accepted as ISO/IEC 9899:1990 
  * 1994: Technical corrigendum 1 (ISO/IEC 9899:1990/Cor.1:1994) 



    

  * [44 small changes](https://open-std.org/JTC1/SC22/WG14/www/docs/tc1.htm)



  * 1995: **C95** (ISO/IEC 9899:1990/Amd.1:1995) ([online store](https://infostore.saiglobal.com/store/Details.aspx?DocN=isoc000767513)) 


  1. greatly expanded wide and multibyte character support ([`<wctype.h>`](../header/wctype.html "c/header/wctype"), [`<wchar.h>`](../header/wchar.html "c/header/wchar"), additions and changes to stream I/O, etc) 
  2. digraphs, [`<iso646.h>`](../header/iso646.html "c/header/iso646"), 


  * 1996: Technical corrigendum 2 (ISO/IEC 9899:1990/Cor.2:1996) 



    

  * [24 small changes](https://open-std.org/JTC1/SC22/WG14/www/docs/tc2.htm)



  * 1999: **C99** (ISO/IEC 9899:1999) 


  1. new features: bool, long long, [`<stdint.h>`](../header/stdint.html "c/header/stdint"), [`<inttypes.h>`](../header/inttypes.html "c/header/inttypes"), restrict, compound literals, variable length arrays, flexible array members, designated initializers, [`<fenv.h>`](../header/fenv.html "c/header/fenv"), variadic macros, complex numbers, __func__, hexadecimal floating-point format (%a), monetary formatting in [lconv](../locale/lconv.html "c/locale/lconv"), [isblank](../string/byte/isblank.html "c/string/byte/isblank"), concatenation of narrow and wide string literals, trailing comma in enumerations, empty arguments in function-like macros, STDC_* pragmas, va_copy, null return of [tmpnam](../io/tmpnam.html "c/io/tmpnam"), null pointer in [setvbuf](../io/setvbuf.html "c/io/setvbuf"), `hh` and `ll` length-specifiers in [printf](../io/fprintf.html "c/io/fprintf"), [snprintf](../io/fprintf.html "c/io/fprintf"), [_Exit](../program/_Exit.html "c/program/ Exit"), [`<tgmath.h>`](../header/tgmath.html "c/header/tgmath"), POSIX-like [strftime](../chrono/strftime.html "c/chrono/strftime") specifiers 
  2. from C++: inline, mix declarations and code, declarations in the init-clause of the for loop, // comments, universal character names in source code 
  3. removed implicit functions and implicit int


  * 2001: Technical corrigendum 1 (ISO/IEC 9899:1999/Cor.1:2001) 



    

  * [11 defects fixed](https://open-std.org/JTC1/SC22/WG14/www/docs/9899tc1/.)



  * 2004: Technical corrigendum 2 (ISO/IEC 9899:1999/Cor.2:2004) 
  * 2004: Unicode TR (ISO/IEC TR 19769:2004) ([ISO store](https://www.iso.org/iso/iso_catalogue/catalogue_tc/catalogue_detail.htm?csnumber=33907)) ([N1040](https://open-std.org/JTC1/SC22/WG14/www/docs/n1040.pdf) November 7, 2003 draft) 
  * 2007: Technical corrigendum 3 (ISO/IEC 9899:1999/Cor.3:2007) ([N1256](https://open-std.org/JTC1/SC22/WG14/www/docs/n1256.pdf) September 7, 2007 draft) 



    

  * deprecated [gets](../io/gets.html "c/io/gets")



  * 2007: Bounds-checking interfaces TR (ISO/IEC TR 24731-1:2007) ([ISO store](https://www.iso.org/iso/catalogue_detail.htm?csnumber=38841)) ([N1225](https://open-std.org/JTC1/SC22/WG14/www/docs/n1225.pdf) March 28, 2007 draft) 
  * 2008: Embedded TR (ISO/IEC TR 18037:2008) ([ISO store](https://www.iso.org/iso/catalogue_detail.htm?csnumber=51126)) ([N1021](https://open-std.org/JTC1/SC22/WG14/www/docs/n1021.pdf) September 24, 2003 draft) 
  * 2009: Decimal floating-point TR (ISO/IEC TR 24732:2009) ([ISO store](https://www.iso.org/iso/catalogue_detail.htm?csnumber=38842)) ([N1241](https://open-std.org/JTC1/SC22/WG14/www/docs/n1241.pdf) July 5, 2007 draft) 
  * 2009: Mathematical special functions TR (ISO/IEC TR 24747:2009) ([ISO store](https://www.iso.org/iso/catalogue_detail.htm?csnumber=38857)) ([N1182](https://open-std.org/JTC1/SC22/WG14/www/docs/n1182.pdf) August 2, 2006 draft) 
  * 2010: Dynamic allocations functions TR (ISO/IEC TR 24731-2:2010) ([ISO store](https://www.iso.org/iso/catalogue_detail.htm?csnumber=51678)) ([N1388](https://open-std.org/JTC1/SC22/WG14/www/docs/n1388.pdf) June 1, 2009 draft) 
  * 2011: **C11** (ISO/IEC 9899:2011) ([ISO store](https://www.iso.org/iso/home/store/catalogue_tc/catalogue_detail.htm?csnumber=57853)) ([ANSI store](https://webstore.ansi.org/RecordDetail.aspx?sku=INCITS%2fISO%2fIEC+9899-2012#.UGCvLIHyaHM)) ([N1570](https://open-std.org/JTC1/SC22/WG14/www/docs/n1570.pdf) April 12, 2011 draft) 


  1. thread-aware memory model, [`<stdatomic.h>`](../header/stdatomic.html "c/header/stdatomic"), [`<threads.h>`](../header/threads.html "c/header/threads"), type-generic functions, alignas/alignof, noreturn, static_assert, analyzability extensions, extensions to complex and imaginary types, anonymous structures and unions, exclusive file open mode, [quick_exit](../program/quick_exit.html "c/program/quick exit")
  2. removed [gets](../io/gets.html "c/io/gets")
  3. from Bounds-checking interfaces TR: bounds-checking interfaces, 
  4. from Unicode TR: char16_t, char32_t, and [`<uchar.h>`](../header/uchar.html "c/header/uchar")


  * 2012: Technical corrigendum 1 (ISO/IEC 9899:2011/Cor 1:2012) ([ISO store](https://www.iso.org/iso/home/store/catalogue_tc/catalogue_detail.htm?csnumber=61717)) 



    

  * Fixes [DR 411](https://open-std.org/JTC1/SC22/WG14/www/docs/n2244.htm#dr_411)



  * 2013: Secure Coding Rules TS (ISO/IEC TS 17961:2013) ([ISO store](https://www.iso.org/iso/catalogue_detail.htm?csnumber=61134)) ([N1718](https://open-std.org/JTC1/SC22/WG14/www/docs/n1718.pdf) May 30, 2013) 
  * 2014: FP TS part 1: Binary floating-point arithmetic (ISO/IEC TS 18661-1:2014) ([ISO store](https://www.iso.org/iso/catalogue_detail.htm?csnumber=63146)) ([N1778](https://open-std.org/JTC1/SC22/WG14/www/docs/n1778.pdf) 2013 draft) 


  1. provides changes to C11 (mostly to Annex F) that cover all basic requirements and some recommendations of IEC 60559:2011 (C11 was built on IEC 60559:1989) 


  * 2015: FP TS part 2: Decimal floating-point arithmetic (ISO/IEC TS 18661-2:2015) ([ISO store](https://www.iso.org/iso/home/store/catalogue_ics/catalogue_detail_ics.htm?csnumber=68882)) ([N1912](https://open-std.org/JTC1/SC22/WG14/www/docs/n1912.pdf) 2015 draft) 


  1. provides changes to C11 to support all the requirements, plus some basic recommendations, of IEC 60559:2011 for decimal floating-point arithmetic. This supersedes ISO/IEC TR 24732:2009. 


  * 2015: FP TS part 3: Interchange and extended types (ISO/IEC TS 18661-3:2015) ([ISO store](https://www.iso.org/iso/home/store/catalogue_tc/catalogue_detail.htm?csnumber=65615)) ([N1945](https://open-std.org/JTC1/SC22/WG14/www/docs/n1945.pdf) 2015 draft) 


  1. provides changes to C11 to support the recommendations of IEC 60559:2011 for extended floating‐point formats and the interchange formats, both arithmetic and non-arithmetic. 


  * 2015: FP TS part 4: Supplementary functions (ISO/IEC TS 18661-4:2015) ([ISO store](https://www.iso.org/iso/home/store/catalogue_tc/catalogue_detail.htm?csnumber=65616)) ([N1950](https://open-std.org/JTC1/SC22/WG14/www/docs/n1950.pdf) 2015 draft) 


  1. provides changes to C11 to support all mathematical operations recommended by IEC 60559:2011, including trigonometry in π units, inverse square root, compounded interest, etc. 


  * 2016: FP TS part 5: Supplementary attributes (ISO/IEC TS 18661-5:2016) ([ISO store](https://www.iso.org/iso/home/store/catalogue_tc/catalogue_detail.htm?csnumber=65617)) ([N2004](https://open-std.org/JTC1/SC22/WG14/www/docs/n2004.pdf) 2016 draft) 


  1. provides changes to C11 to support all supplementary attributes (evaluation model, exception handling, reproducibility, etc) recommended by IEC 60559:2011 


  * 2018: **C17** (ISO/IEC 9899:2018) ([ISO Store](https://www.iso.org/standard/74528.html)) ([Final draft](https://files.lhmouse.com/standards/ISO%20C%20N2176.pdf)) 



    [Main Article: C17](../17.html "c/17")

Defect Reports fixed in C17 (54 defects)  
---  
  
  * [DR 400](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_400)
  * [DR 401](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_401)
  * [DR 402](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_402)
  * [DR 403](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_403)
  * [DR 404](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_404)
  * [DR 405](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_405)
  * [DR 406](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_406)
  * [DR 407](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_407)
  * [DR 410](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_410)
  * [DR 412](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_412)
  * [DR 414](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_414)
  * [DR 415](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_415)
  * [DR 416](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_416)
  * [DR 417](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_417)
  * [DR 419](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_419)
  * [DR 423](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_423)
  * [DR 426](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_426)
  * [DR 428](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_428)
  * [DR 429](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_429)
  * [DR 430](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_430)
  * [DR 431](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_431)
  * [DR 433](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_433)
  * [DR 434](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_434)
  * [DR 436](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_436)
  * [DR 437](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_437)
  * [DR 438](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_438)
  * [DR 439](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_439)
  * [DR 441](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_441)
  * [DR 444](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_444)
  * [DR 445](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_445)
  * [DR 447](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_447)
  * [DR 448](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_448)
  * [DR 450](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_450)
  * [DR 452](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_452)
  * [DR 453](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_453)
  * [DR 457](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_457)
  * [DR 458](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_458)
  * [DR 459](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_459)
  * [DR 460](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_460)
  * [DR 462](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_462)
  * [DR 464](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_464)
  * [DR 465](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_465)
  * [DR 468](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_468)
  * [DR 470](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_470)
  * [DR 471](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_471)
  * [DR 472](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_472)
  * [DR 473](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_473)
  * [DR 475](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_475)
  * [DR 477](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_477)
  * [DR 480](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_480)
  * [DR 481](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_481)
  * [DR 485](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_485)
  * [DR 487](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_487)
  * [DR 491](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2244.htm#dr_491)

  
  
  * 2023 **C23** (ISO/IEC 9899:2024). C23 is the current revision of the C standard. 



    [Main Article: C23](../23.html "c/23")

Defect Reports fixed in C23 (? defects)  
---  
  
  * [DR 440](https://open-std.org/JTC1/SC22/WG14/www/docs/n2379.htm)
  * [DR 432](https://open-std.org/JTC1/SC22/WG14/www/docs/n2326.htm)
  * [DR 467](https://open-std.org/JTC1/SC22/WG14/www/docs/n2326.htm)
  * [DR 476](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_476)
  * [DR 482](https://open-std.org/JTC1/SC22/WG14/www/docs/n2324.htm)
  * [DR 488](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_488)
  * [DR 489](https://open-std.org/JTC1/SC22/WG14/www/docs/n2713.htm)
  * [DR 494](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_494)
  * [DR 496](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_496)
  * [DR 497](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_497)
  * [DR 499](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_499)
  * [DR 500](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_500)
  * [DR 501](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_501)

  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/history&action=edit&section=3 "Edit section: Future development")] Future development

  * Parallelism TS (Draft [N2017](https://open-std.org/JTC1/SC22/WG14/www/docs/n2017.pdf) 2016-03-10) 
  * Transactional Memory TS (Draft [N1961](https://open-std.org/JTC1/SC22/WG14/www/docs/n1961.pdf) 2015-09-23) 
  * **C** (Latest draft [n3550](https://open-std.org/JTC1/SC22/WG14/www/docs/n3550.pdf) 2025-05-04) 


  1. List of issues that were not granted DR status: ([N2556](https://open-std.org/JTC1/SC22/WG14/www/docs/n2556.pdf) 2020-08-02) 



    [Main Article: C29](https://en.cppreference.com/mwiki/index.php?title=c/29&action=edit&redlink=1 "c/29 \(page does not exist\)") ? 
    Next major C language standard revision 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/history&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/history.html "cpp/language/history") for History of C++  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/history&action=edit&section=5 "Edit section: External links")] External links

1\.  | [The Development of the C Language](https://www.bell-labs.com/usr/dmr/www/chist.html) by Dennis M. Ritchie   
---|---  
2\.  | [Rationale for the C99 standard](https://www.open-std.org/jtc1/sc22/wg14/www/C99RationaleV5.10.pdf)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/history&oldid=178579](https://en.cppreference.com/mwiki/index.php?title=c/language/history&oldid=178579)" 

From cppreference.com

< [c](../../c.html "c")‎ | [variadic](../variadic.html "c/variadic")

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

[ Variadic functions](../variadic.html "c/variadic")

[va_start](va_start.html "c/variadic/va start")  
---  
[va_arg](va_arg.html "c/variadic/va arg")  
[va_copy](va_copy.html "c/variadic/va copy")(C99)  
**va_end**  
[va_list](va_list.html "c/variadic/va list")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/navbar_content&action=edit)

Defined in header `[`<stdarg.h>`](../header/stdarg.html "c/header/stdarg")` |  |   
---|---|---  
void va_end( va_list ap ); |  |   
| |   
  
The `va_end` macro performs cleanup for an `ap` object initialized by a call to va_start or va_copy. `va_end` may modify `ap` so that it is no longer usable. 

If there is no corresponding call to va_start or va_copy, or if `va_end` is not called before a function that calls va_start or va_copy returns, the behavior is undefined. 

## Contents

  * [1 Parameters](va_end.html#Parameters)
  * [2 Expanded value](va_end.html#Expanded_value)
  * [3 References](va_end.html#References)
  * [4 See also](va_end.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_end&action=edit&section=1 "Edit section: Parameters")] Parameters

ap  |  \-  |  an instance of the va_list type to clean up   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_end&action=edit&section=2 "Edit section: Expanded value")] Expanded value

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_end&action=edit&section=3 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.16.1.3 The va_end macro (p: 270-271) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.15.1.3 The va_end macro (p: 250-251) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.8.1.3 The va_end macro 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_end&action=edit&section=4 "Edit section: See also")] See also

[ va_arg](va_arg.html "c/variadic/va arg") |  accesses the next variadic function argument   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_arg&action=edit)  
---|---  
[ va_copy](va_copy.html "c/variadic/va copy")(C99) |  makes a copy of the variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_copy&action=edit)  
[ va_list](va_list.html "c/variadic/va list") |  holds the information needed by va_start, va_arg, va_end, and va_copy   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_list&action=edit)  
[ va_start](va_start.html "c/variadic/va start") |  enables access to variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_start&action=edit)  
[C++ documentation](../../cpp/utility/variadic/va_end.html "cpp/utility/variadic/va end") for va_end  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_end&oldid=117389](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_end&oldid=117389)" 

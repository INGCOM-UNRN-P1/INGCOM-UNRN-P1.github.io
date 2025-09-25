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
[va_end](va_end.html "c/variadic/va end")  
**va_list**  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/navbar_content&action=edit)

Defined in header `[`<stdarg.h>`](../header/stdarg.html "c/header/stdarg")` |  |   
---|---|---  
/* unspecified */ va_list; |  |   
| |   
  
`va_list` is a complete object type suitable for holding the information needed by the macros va_start, va_copy, va_arg, and va_end. 

If a `va_list` instance is created, passed to another function, and used via va_arg in that function, then any subsequent use in the calling function should be preceded by a call to va_end. 

It is legal to pass a pointer to a `va_list` object to another function and then use that object after the function returns. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_list&action=edit&section=1 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.16/3 Variable arguments <stdarg.h> (p: 269) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.15/3 Variable arguments <stdarg.h> (p: 249) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.8 VARIABLE ARGUMENTS <stdarg.h>



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_list&action=edit&section=2 "Edit section: See also")] See also

[ va_arg](va_arg.html "c/variadic/va arg") |  accesses the next variadic function argument   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_arg&action=edit)  
---|---  
[ va_copy](va_copy.html "c/variadic/va copy")(C99) |  makes a copy of the variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_copy&action=edit)  
[ va_end](va_end.html "c/variadic/va end") |  ends traversal of the variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_end&action=edit)  
[ va_start](va_start.html "c/variadic/va start") |  enables access to variadic function arguments   
(function macro) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/variadic/dsc_va_start&action=edit)  
[C++ documentation](../../cpp/utility/variadic/va_list.html "cpp/utility/variadic/va list") for va_list  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_list&oldid=117386](https://en.cppreference.com/mwiki/index.php?title=c/variadic/va_list&oldid=117386)" 

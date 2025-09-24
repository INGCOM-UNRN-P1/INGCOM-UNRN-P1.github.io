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

This optional extension to the C language limits the potential results of executing some forms of undefined behavior, which improves the effectiveness of static analysis of such programs. Analyzability is only guaranteed to be enabled if the [predefined macro constant](../preprocessor/replace.html "c/preprocessor/replace") __STDC_ANALYZABLE__ is defined by the compiler. 

If the compiler supports analyzability, any language or library construct whose behavior is undefined is further classified between _critical_ and _bounded_ undefined behavior, and the behavior of all bounded UB cases is limited as specified below. 

## Contents

  * [1 Critical undefined behavior](analyzability.html#Critical_undefined_behavior)
  * [2 Bounded undefined behavior](analyzability.html#Bounded_undefined_behavior)
  * [3 Notes](analyzability.html#Notes)
  * [4 References](analyzability.html#References)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/analyzability&action=edit&section=1 "Edit section: Critical undefined behavior")] Critical undefined behavior

Critical UB is undefined behavior that might perform a memory write or a volatile memory read out of bounds of any object. A program that has critical undefined behavior may be susceptible to security exploits. 

Only the following undefined behaviors are critical: 

  * access to an object outside of its [lifetime](lifetime.html "c/language/lifetime") (e.g. through a dangling pointer) 
  * write to an object whose declarations are not [compatible](compatible_type.html#Compatible_types "c/language/type")
  * function call through a function pointer whose type is not [compatible](compatible_type.html#Compatible_types "c/language/type") with the type of the function it points to 
  * [lvalue expression](value_category.html "c/language/value category") is evaluated, but does not designate an object 
  * attempted modification of a [string literal](string_literal.html "c/language/string literal")
  * [dereferencing](operator_member_access.html "c/language/operator member access") an invalid (null, indeterminate, etc) or [past-the-end](operator_arithmetic.html "c/language/operator arithmetic") pointer 
  * modification of a [const object](const.html "c/language/const") through a non-const pointer 
  * call to a standard library function or macro with an invalid argument 
  * call to a variadic standard library function with unexpected argument type (e.g. call to [printf](../io/fprintf.html "c/io/fprintf") with an argument of the type that doesn't match its conversion specifier) 
  * [longjmp](../program/longjmp.html "c/program/longjmp") where there is no [setjmp](../program/setjmp.html "c/program/setjmp") up the calling scope, across threads, or from within the scope of a VM type. 
  * any use of the pointer that was deallocated by [free](../memory/free.html "c/memory/free") or [realloc](../memory/realloc.html "c/memory/realloc")
  * any [string](../string/byte.html "c/string/byte") or [wide string](../string/wide.html "c/string/wide") library function accesses an array out of bounds 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/analyzability&action=edit&section=2 "Edit section: Bounded undefined behavior")] Bounded undefined behavior

Bounded UB is undefined behavior that cannot perform an illegal memory write, although it may trap and may produce or store indeterminate values. 

  * All undefined behavior not listed as critical is bounded, including 



    

  * multithreaded data races 
  * use of a [indeterminate values](initialization.html "c/language/initialization") with automatic storage duration 
  * [strict aliasing](object.html#Strict_aliasing "c/language/object") violations 
  * [misaligned](object.html#alignment "c/language/object") object access 
  * signed integer overflow 
  * [unsequenced side-effects](eval_order.html "c/language/eval order") modify the same scalar or modify and read the same scalar 
  * floating-to-integer or pointer-to-integer [conversion](conversion.html "c/language/conversion") overflow 
  * [bitwise shift](operator_arithmetic.html "c/language/operator arithmetic") by a negative or too large bit count 
  * [integer division](operator_arithmetic.html "c/language/operator arithmetic") by zero 
  * use of a void expression 
  * direct [assignment](operator_assignment.html "c/language/operator assignment") or [memcpy](../string/byte/memcpy.html "c/string/byte/memcpy") of inexactly-overlapped objects 
  * [restrict](restrict.html "c/language/restrict") violations 
  * etc.. ALL undefined behavior that's not in the critical list. 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/analyzability&action=edit&section=3 "Edit section: Notes")] Notes

Bounded undefined behavior disables certain optimizations: compilation with analyzability enabled preserves source-code causality, which [may be violated](as_if.html "c/language/as if") by undefined behavior otherwise. 

Analyzability extension permits, as a form of implementation-defined behavior, for the [runtime constraint handler](../error/set_constraint_handler_s.html "c/error/set constraint handler s") to be invoked when a trap occurs. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/analyzability&action=edit&section=4 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.10.10.4/1 Conditional feature macros (p: 188-189) 



    

  * Annex L Analyzability (p: 672-673) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.10.8.3/1 Conditional feature macros (p: 128-129) 



    

  * Annex L Analyzability (p: 473-474) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.10.8.3/1 Conditional feature macros (p: 177) 



    

  * Annex L Analyzability (p: 652-653) 



Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/analyzability&oldid=183252](https://en.cppreference.com/mwiki/index.php?title=c/language/analyzability&oldid=183252)" 

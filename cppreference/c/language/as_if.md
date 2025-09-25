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
[Arithmetic types](arithmetic_types.html "c/language/arithmetic types")  
[Objects and alignment](object.html "c/language/object")  
[The main() function](main_function.html "c/language/main function")  
**The as-if rule**  
[Undefined behavior](behavior.html "c/language/behavior")  
[Memory model and data races](memory_model.html "c/language/memory model")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/basics/navbar_content&action=edit)

Allows any and all code transformations that do not change the observable behavior of the program. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/as_if&action=edit&section=1 "Edit section: Explanation")] Explanation

The C compiler is permitted to perform any changes to the program as long as the following remains true: 

1) At every [sequence point](eval_order.html "c/language/eval order"), the values of all [volatile](volatile.html "c/language/volatile") objects are stable (previous evaluations are complete, new evaluations not started).  | (until C11)  
---|---  
1) Accesses (reads and writes) to [volatile](volatile.html "c/language/volatile") objects occur strictly according to the semantics of the expressions in which they occur. In particular, they are [not reordered](../atomic/memory_order.html "c/atomic/memory order") with respect to other volatile accesses on the same thread.  | (since C11)  
  
2) At program termination, data written to files is exactly as if the program was executed as written.

3) Prompting text which is sent to interactive devices will be shown before the program waits for input.

4) If the pragma [` #pragma STDC FENV_ACCESS`](../preprocessor/impl.html#Standard_pragmas "c/preprocessor/impl") is supported and is set to `ON`, the changes to the [floating-point environment](../numeric/fenv.html "c/numeric/fenv") (floating-point exceptions and rounding modes) are guaranteed to be observed by the floating-point arithmetic operators and function calls as if executed as written, except that 

    

  * the result of any floating-point expression other than cast and assignment may have range and precision of a floating-point type different from the type of the expression (see [FLT_EVAL_METHOD](../types/limits/FLT_EVAL_METHOD.html "c/types/limits/FLT EVAL METHOD")), 
  * notwithstanding the above, intermediate results of any floating-point expression may be calculated as if to infinite range and precision (unless [` #pragma STDC FP_CONTRACT`](../preprocessor/impl.html#Standard_pragmas "c/preprocessor/impl") is `OFF`).


| (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/as_if&action=edit&section=2 "Edit section: Notes")] Notes

| This section is incomplete  
Reason: fill out similar to [cpp/language/as_if](../../cpp/language/as_if.html "cpp/language/as if")  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/as_if&action=edit&section=3 "Edit section: See also")] See also

  * [Order of evaluation](eval_order.html "c/language/eval order")

[C++ documentation](../../cpp/language/as_if.html "cpp/language/as if") for as-if rule  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/as_if&oldid=154654](https://en.cppreference.com/mwiki/index.php?title=c/language/as_if&oldid=154654)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



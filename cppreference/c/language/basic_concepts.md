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

**Basic concepts**  
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

**Basic Concepts**

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
[The as-if rule](as_if.html "c/language/as if")  
[Undefined behavior](behavior.html "c/language/behavior")  
[Memory model and data races](memory_model.html "c/language/memory model")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/basics/navbar_content&action=edit)

This section provides definitions for the specific terminology and the concepts used when describing the C programming language. 

A C program is a sequence of text files (typically header and source files) that contain [declarations](declarations.html "c/language/declarations"). They undergo [translation](translation_phases.html "c/language/translation phases") to become an executable program, which is executed when the OS calls its [main function](main_function.html "c/language/main function") (unless it is itself the OS or another _freestanding_ program, in which case the entry point is implementation-defined). 

Certain words in a C program have special meaning, they are [keywords](../keyword.html "c/keyword"). Others can be used as [identifiers](identifiers.html "c/language/identifier"), which may be used to identify [objects](object.html "c/language/object"), [functions](functions.html "c/language/functions"), [struct](struct.html "c/language/struct"), [union](union.html "c/language/union"), or [enumeration](enum.html "c/language/enum") tags, their members, [typedef](typedef.html "c/language/typedef") names, [labels](statements.html#Labels "c/language/statements"), or [macros](../preprocessor/replace.html "c/preprocessor/replace"). 

Each identifier (other than macro) is only valid within a part of the program called its [scope](scope.html "c/language/scope") and belongs to one of four kinds of [name spaces](name_space.html "c/language/name space"). Some identifiers have [linkage](storage_class_specifiers.html "c/language/storage duration") which makes them refer to the same entities when they appear in different scopes or translation units. 

Definitions of functions include sequences of [statements](statements.html "c/language/statements") and [declarations](declarations.html "c/language/declarations"), some of which include [expressions](operators.html "c/language/expressions"), which specify the computations to be performed by the program. 

[Declarations](declarations.html "c/language/declarations") and [expressions](operators.html "c/language/expressions") create, destroy, access, and manipulate [objects](object.html "c/language/object"). Each [object](object.html "c/language/object"), [function](functions.html "c/language/functions"), and [expression](operators.html "c/language/expressions") in C is associated with a [type](compatible_type.html "c/language/type"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/basic_concepts&action=edit&section=1 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/basics.html "cpp/language/basic concepts") for Basic concepts  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/basic_concepts&oldid=133988](https://en.cppreference.com/mwiki/index.php?title=c/language/basic_concepts&oldid=133988)" 

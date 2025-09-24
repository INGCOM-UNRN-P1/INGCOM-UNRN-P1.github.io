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
**Punctuation**  
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

These are the punctuation symbols in C. The meaning of each symbol is detailed in the linked pages. 

## Contents

  * [1 { }](punctuators.html#.7B_.7D)
  * [2 [ ]](punctuators.html#.5B_.5D)
  * [3 #](punctuators.html#.23)
  * [4 ##](punctuators.html#.23.23)
  * [5 ( )](punctuators.html#.28_.29)
  * [6 ;](punctuators.html#.3B)
  * [7 :](punctuators.html#:)
  * [8 ...](punctuators.html#...)
  * [9 ?](punctuators.html#.3F)
  * [10 ::](punctuators.html#::)
  * [11 .](punctuators.html#.)
  * [12 ->](punctuators.html#-.3E)
  * [13 ~](punctuators.html#.7E)
  * [14 !](punctuators.html#.21)
  * [15 +](punctuators.html#.2B)
  * [16 -](punctuators.html#-)
  * [17 *](punctuators.html#.2A)
  * [18 /](punctuators.html#.2F)
  * [19 %](punctuators.html#.25)
  * [20 ^](punctuators.html#.5E)
  * [21 &](punctuators.html#.26)
  * [22 |](punctuators.html#.7C)
  * [23 =](punctuators.html#.3D)
  * [24 +=](punctuators.html#.2B.3D)
  * [25 -=](punctuators.html#-.3D)
  * [26 *=](punctuators.html#.2A.3D)
  * [27 /=](punctuators.html#.2F.3D)
  * [28 %=](punctuators.html#.25.3D)
  * [29 ^=](punctuators.html#.5E.3D)
  * [30 &=](punctuators.html#.26.3D)
  * [31 |=](punctuators.html#.7C.3D)
  * [32 ==](punctuators.html#.3D.3D)
  * [33 !=](punctuators.html#.21.3D)
  * [34 <](punctuators.html#.3C)
  * [35 >](punctuators.html#.3E)
  * [36 <=](punctuators.html#.3C.3D)
  * [37 >=](punctuators.html#.3E.3D)
  * [38 &&](punctuators.html#.26.26)
  * [39 ||](punctuators.html#.7C.7C)
  * [40 <<](punctuators.html#.3C.3C)
  * [41 >>](punctuators.html#.3E.3E)
  * [42 <<=](punctuators.html#.3C.3C.3D)
  * [43 >>=](punctuators.html#.3E.3E.3D)
  * [44 ++](punctuators.html#.2B.2B)
  * [45 \--](punctuators.html#--)
  * [46 ,](punctuators.html#.2C)
  * [47 References](punctuators.html#References)
  * [48 See also](punctuators.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=1 "Edit section: { }")] `{` `}`

  * In a [struct](struct.html "c/language/struct") or [union](union.html "c/language/union") definition, delimit the struct-declaration-list. 
  * In an [enum](enum.html "c/language/enum") definition, delimit the enumerator list. 
  * Delimit a [compound statement](statements.html#Compound_statements "c/language/statements"). The compound statement may be part of a [function definition](function_definition.html "c/language/function definition"). 
  * In [initialization](initialization.html "c/language/initialization"), delimit the initializers. 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=2 "Edit section: \[ \]")] `[` `]`

  * [Subscript operator](operator_member_access.html#Subscript "c/language/operator member access"). 
  * Part of [array declarator](declarations.html#Declarators "c/language/declarations") in a [declaration](declarations.html "c/language/declarations") or a [type-id](compatible_type.html#Type_names "c/language/type"). 
  * In [initialization](initialization.html "c/language/initialization"), introduce a designator for an array element. (since C99)
  * In an [attribute specifier](attributes.html "c/language/attributes"), delimit the attributes. (since C23)



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=3 "Edit section: #")] `#`

  * Introduce a [preprocessing directive](../preprocessor.html "c/preprocessor"). 
  * The [preprocessing operator for stringification](../preprocessor/replace.html#.23_and_.23.23_operators "c/preprocessor/replace"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=4 "Edit section: ##")] `##`

  * The [preprocessing operator for token pasting](../preprocessor/replace.html#.23_and_.23.23_operators "c/preprocessor/replace"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=5 "Edit section: \( \)")] `(` `)`

  * In an expression, [indicate grouping](operators.html#Primary_expressions "c/language/expressions"). 
  * [Function call operator](operator_other.html#Function_call "c/language/operator other"). 
  * In a [`sizeof`](sizeof.html "c/language/sizeof"), [`_Alignof`](alignof.html "c/language/ Alignof")(since C11) , [`typeof`](typeof_unqual.html "c/language/typeof") or [`typeof_unqual`](typeof_unqual.html "c/language/typeof unqual")(since C23) expression, delimit the operand. 
  * In an [explicit cast](cast.html "c/language/cast"), delimit the type-id. 
  * In a [compound literal](compound_literal.html "c/language/compound literal"), delimit the type-id. (since C99)
  * In a [declaration](declarations.html "c/language/declarations") or a [type-id](compatible_type.html#Type_names "c/language/type"), indicate grouping. 
  * In a [function declarator](function_declaration.html "c/language/function declaration") (in a [declaration](declarations.html "c/language/declarations") or a [type-id](compatible_type.html#Type_names "c/language/type")), delimit the parameter list. 
  * In an [`if`](if.html "c/language/if"), [`switch`](switch.html "c/language/switch"), [`while`](while.html "c/language/while"), [`do-while`](do.html "c/language/do"), or [`for`](for.html "c/language/for") statement, delimit the controlling clause. 
  * In a [function-like macro definition](../preprocessor/replace.html#Function-like_macros "c/preprocessor/replace"), delimit the macro parameters. 
  * In a [function-like macro invocation](../preprocessor/replace.html#Function-like_macros "c/preprocessor/replace"), delimit the macro arguments or prevent commas from being interpreted as argument separators. 
  * Part of a `defined`, `__has_include`, `__has_embed` or `__has_c_attribute`(since C23) preprocessing operator. 
  * Part of a [generic selection expression](generic.html "c/language/generic"). (since C11)
  * In an [`_Atomic`](atomic.html "c/language/atomic") type specifier, delimit the type-id. (since C11)
  * In a [static assertion declaration](static_assert.html "c/language/ Static assert"), delimit the operands. (since C11)
  * In an [`_Alignas`](alignas.html "c/language/ Alignas") specifier, delimit the operand. (since C11)
  * In an [attribute](attributes.html "c/language/attributes"), delimit the attribute arguments. (since C23)
  * In a bit-precise integer type name (_BitInt(N)), delimit the size. (since C23)
  * Part of [`__VA_OPT__`](../preprocessor/replace.html "c/preprocessor/replace") replacement in a variadic macro definition. (since C23)
  * In a preprocessor parameter used in [#embed directives](../preprocessor/embed.html "c/preprocessor/embed") and __has_embed preprocessing expressions, delimit the preprocessor parameter clause. (since C23)



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=6 "Edit section: ;")] `;`

  * Indicate the end of 



    

  * a [statement](statements.html "c/language/statements") (including the init-statement of a for statement) 
  * a [declaration](declarations.html "c/language/declarations") or struct-declaration-list



  * Separate the second and third clauses of a [for statement](for.html "c/language/for"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=7 "Edit section: :")] `:`

  * Part of [conditional operator](operator_other.html#Conditional_operator "c/language/operator other"). 
  * Part of [label declaration](statements.html#Labels "c/language/statements"). 
  * In a [bit-field member declaration](bit_field.html "c/language/bit field"), introduce the width. 
  * Introduce an [enum base](enum.html "c/language/enum"), which specifies the underlying type of the enum. (since C23)
  * In a [generic association](generic.html "c/language/generic"), delimit the type-id or default and the selected expression. (since C11)



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=8 "Edit section: ...")] `...`

  * In the [parameter list](function_declaration.html#Parameter_list "c/language/function declaration") of a function declarator, signify a [variadic function](variadic.html "c/language/variadic"). 
  * In a [macro definition](../preprocessor/replace.html "c/preprocessor/replace"), signify a variadic macro. (since C99)



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=9 "Edit section: ?")] `?`

  * Part of [conditional operator](operator_other.html#Conditional_operator "c/language/operator other"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=10 "Edit section: ::")] `::`

  * In an [attribute](attributes.html "c/language/attributes"), indicate attribute scope. (since C23)
  * In a preprocessor prefixed parameter (used by [#embed](../preprocessor/embed.html "c/preprocessor/embed") and __has_embed), indicate scope. (since C23)



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=11 "Edit section: .")] `.`

  * [Member access operator](operator_member_access.html#Member_access "c/language/operator member access"). 
  * In [initialization](initialization.html "c/language/initialization"), introduce a designator for a struct/union member. (since C99)



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=12 "Edit section: ->")] `->`

  * [Member access operator](operator_member_access.html#Member_access_through_pointer "c/language/operator member access"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=13 "Edit section: ~")] `~`

  * [Unary complement operator (a.k.a. bitwise not operator)](operator_arithmetic.html#Bitwise_logic "c/language/operator arithmetic"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=14 "Edit section: !")] `!`

  * [Logical not operator](operator_logical.html#Logical_NOT "c/language/operator logical"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=15 "Edit section: +")] `+`

  * [Unary plus operator](operator_arithmetic.html#Unary_arithmetic "c/language/operator arithmetic"). 
  * [Binary plus operator](operator_arithmetic.html#Additive_operators "c/language/operator arithmetic"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=16 "Edit section: -")] `-`

  * [Unary minus operator](operator_arithmetic.html#Unary_arithmetic "c/language/operator arithmetic"). 
  * [Binary minus operator](operator_arithmetic.html#Additive_operators "c/language/operator arithmetic"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=17 "Edit section: *")] `*`

  * [Indirection operator](operator_member_access.html#Dereference "c/language/operator member access"). 
  * [Multiplication operator](operator_arithmetic.html#Multiplicative_operators "c/language/operator arithmetic"). 
  * Pointer operator operator in a [declarator](declarations.html#Declarators "c/language/declarations") or in a [type-id](compatible_type.html#Type_names "c/language/type"). 
  * Placeholder for the length of a variable-length array declarator in a [function declaration](function_declaration.html "c/language/function declaration"). (since C99)



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=18 "Edit section: /")] `/`

  * [Division operator](operator_arithmetic.html#Multiplicative_operators "c/language/operator arithmetic"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=19 "Edit section: %")] `%`

  * [Modulo operator](operator_arithmetic.html#Multiplicative_operators "c/language/operator arithmetic"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=20 "Edit section: ^")] `^`

  * [Bitwise xor operator](operator_arithmetic.html#Bitwise_logic "c/language/operator arithmetic"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=21 "Edit section: &")] `&`

  * [Address-of operator](operator_member_access.html#Address_of "c/language/operator member access"). 
  * [Bitwise and operator](operator_arithmetic.html#Bitwise_logic "c/language/operator arithmetic"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=22 "Edit section: |")] `|`

  * [Bitwise or operator](operator_arithmetic.html#Bitwise_logic "c/language/operator arithmetic"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=23 "Edit section: =")] `=`

  * [Simple assignment operator](operator_assignment.html#Simple_assignment "c/language/operator assignment"). 
  * In [initialization](initialization.html "c/language/initialization"), delimit the object and the initializer list. 
  * In an [enum definition](enum.html "c/language/enum"), introduce the value of enumeration constant. 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=24 "Edit section: +=")] `+=`

  * [Compound assignment operator](operator_assignment.html#Compound_assignment "c/language/operator assignment"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=25 "Edit section: -=")] `-=`

  * [Compound assignment operator](operator_assignment.html#Compound_assignment "c/language/operator assignment"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=26 "Edit section: *=")] `*=`

  * [Compound assignment operator](operator_assignment.html#Compound_assignment "c/language/operator assignment"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=27 "Edit section: /=")] `/=`

  * [Compound assignment operator](operator_assignment.html#Compound_assignment "c/language/operator assignment"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=28 "Edit section: %=")] `%=`

  * [Compound assignment operator](operator_assignment.html#Compound_assignment "c/language/operator assignment"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=29 "Edit section: ^=")] `^=`

  * [Compound assignment operator](operator_assignment.html#Compound_assignment "c/language/operator assignment"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=30 "Edit section: &=")] `&=`

  * [Compound assignment operator](operator_assignment.html#Compound_assignment "c/language/operator assignment"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=31 "Edit section: |=")] `|=`

  * [Compound assignment operator](operator_assignment.html#Compound_assignment "c/language/operator assignment"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=32 "Edit section: ==")] `==`

  * [Equality operator](operator_comparison.html#Equality_operators "c/language/operator comparison"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=33 "Edit section: !=")] `!=`

  * [Inequality operator](operator_comparison.html#Equality_operators "c/language/operator comparison"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=34 "Edit section: <")] `<`

  * [Less-than operator](operator_comparison.html#Relational_operators "c/language/operator comparison"). 
  * Introduce a header name in 



    

  * a [#include directive](../preprocessor/include.html "c/preprocessor/include")
  * a [__has_include preprocessing expression](../preprocessor/include.html "c/preprocessor/include") (since C23)
  * a [#embed directive](../preprocessor/embed.html "c/preprocessor/embed") (since C23)
  * a [__has_embed preprocessing expression](../preprocessor/embed.html "c/preprocessor/embed") (since C23)
  * implementation-defined locations within a [`#pragma` directive](../preprocessor/impl.html "c/preprocessor/impl")



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=35 "Edit section: >")] `>`

  * [Greater-than operator](operator_comparison.html#Relational_operators "c/language/operator comparison"). 
  * Indicate the end of a header name in 



    

  * a [#include directive](../preprocessor/include.html "c/preprocessor/include")
  * a [__has_include preprocessing expression](../preprocessor/include.html "c/preprocessor/include") (since C23)
  * a [#embed directive](../preprocessor/embed.html "c/preprocessor/embed") (since C23)
  * a [__has_embed preprocessing expression](../preprocessor/embed.html "c/preprocessor/embed") (since C23)
  * implementation-defined locations within a [`#pragma` directive](../preprocessor/impl.html "c/preprocessor/impl")



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=36 "Edit section: <=")] `<=`

  * [Less-than-or-equal-to operator](operator_comparison.html#Relational_operators "c/language/operator comparison"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=37 "Edit section: >=")] `>=`

  * [Greater-than-or-equal-to operator](operator_comparison.html#Relational_operators "c/language/operator comparison"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=38 "Edit section: &&")] `&&`

  * [Logical and operator](operator_logical.html#Logical_AND "c/language/operator logical"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=39 "Edit section: ||")] `||`

  * [Logical or operator](operator_logical.html#Logical_OR "c/language/operator logical"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=40 "Edit section: <<")] `<<`

  * [Bitwise shift operator](operator_arithmetic.html#Shift_operators "c/language/operator arithmetic"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=41 "Edit section: >>")] `>>`

  * [Bitwise shift operator](operator_arithmetic.html#Shift_operators "c/language/operator arithmetic"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=42 "Edit section: <<=")] `<<=`

  * [Compound assignment operator](operator_assignment.html#Compound_assignment "c/language/operator assignment"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=43 "Edit section: >>=")] `>>=`

  * [Compound assignment operator](operator_assignment.html#Compound_assignment "c/language/operator assignment"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=44 "Edit section: ++")] `++`

  * [Increment operator](operator_incdec.html "c/language/operator incdec"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=45 "Edit section: --")] `--`

  * [Decrement operator](operator_incdec.html "c/language/operator incdec"). 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=46 "Edit section: ,")] `,`

  * [Comma operator](operator_other.html#Comma_operator "c/language/operator other"). 
  * List separator in 



    

  * the declarator list in a [declaration](declarations.html "c/language/declarations")
  * initializer list in [initialization](initialization.html "c/language/initialization"), including [compound literals](compound_literal.html "c/language/compound literal")(since C99)
  * the argument list in a [function call expression](operator_other.html#Function_call "c/language/operator other")
  * the enumerator list in an [enum](enum.html "c/language/enum") declaration 
  * a function parameter list 
  * the macro parameter list in a [function-like macro definition](../preprocessor/replace.html#Function-like_macros "c/preprocessor/replace")
  * the macro argument list in a [function-like macro invocation](../preprocessor/replace.html#Function-like_macros "c/preprocessor/replace"), unless found between an inner set of parentheses 
  * the generic association list in a [generic selection expression](generic.html "c/language/generic") (since C11)
  * an [attribute](attributes.html "c/language/attributes") list (since C23)



  * In a [static assertion declaration](static_assert.html "c/language/ Static assert"), separate the arguments. (since C11)
  * In a [generic selection expression](generic.html "c/language/generic"), separate the controlling expression and the generic association list. (since C11)



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=47 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.4.6 Punctuators (p: 68-69) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.4.6 Punctuators (p: 52-53) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.4.6 Punctuators (p: 72-73) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.4.6 Punctuators (p: 63-64) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.1.6 Punctuators 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&action=edit&section=48 "Edit section: See also")] See also

[ Alternative representations](operator_alternative.html "c/language/operator alternative") (C95) |  alternative spellings for certain operators[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/dsc_operator_alternative&action=edit)  
---|---  
[C++ documentation](../../cpp/language/punctuators.html "cpp/language/punctuators") for Punctuation  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&oldid=159676](https://en.cppreference.com/mwiki/index.php?title=c/language/punctuators&oldid=159676)" 

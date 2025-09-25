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

[ Declarations](declarations.html "c/language/declarations")

[Pointer](pointer.html "c/language/pointer")  
---  
[Array](array.html "c/language/array")  
[enum](enum.html "c/language/enum")  
[struct](struct.html "c/language/struct")  
[union](union.html "c/language/union")  
[Bit-field](bit_field.html "c/language/bit field")  
[Atomic types](atomic.html "c/language/atomic") (C11)  
[const](const.html "c/language/const")  
[constexpr](constexpr.html "c/language/constexpr")(C23)  
[volatile](volatile.html "c/language/volatile")  
[restrict](restrict.html "c/language/restrict")(C99)  
**Alignment specifiers**  
[Storage duration and linkage](storage_class_specifiers.html "c/language/storage duration")  
[External and tentative definitions](extern.html "c/language/extern")  
[typedef](typedef.html "c/language/typedef")  
[Static assertions](static_assert.html "c/language/ Static assert")  
[Attributes](attributes.html "c/language/attributes") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/declarations/navbar_content&action=edit)

Appears in the [declaration](declarations.html "c/language/declarations") syntax as one of the type specifiers to modify the [alignment requirement](object.html#Alignment "c/language/object") of the object being declared. 

## Contents

  * [1 Syntax](alignas.html#Syntax)
  * [2 Explanation](alignas.html#Explanation)
  * [3 Notes](alignas.html#Notes)
  * [4 Keywords](alignas.html#Keywords)
  * [5 Example](alignas.html#Example)
  * [6 Defect reports](alignas.html#Defect_reports)
  * [7 References](alignas.html#References)
  * [8 See also](alignas.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignas&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**_Alignas**` `**(**` expression `**)**` |  (1)  |  (since C11)  
`**alignas**` `**(**` expression `**)**` |  (2)  |  (since C23)  
`**_Alignas**` `**(**` type `**)**` |  (3)  |  (since C11)  
`**alignas**` `**(**` type `**)**` |  (4)  |  (since C23)  
expression |  \-  |  any [integer constant expression](constant_expression.html "c/language/constant expression") whose value is a valid [alignment](object.html#Alignment "c/language/object") or zero   
---|---|---  
type |  \-  |  any [type name](compatible_type.html#Type_names "c/language/type")  
The keyword `_Alignas` is also available as convenience macro [`alignas`](../types.html "c/types"), available in the header [`<stdalign.h>`](../header/stdalign.html "c/header/stdalign").  | (until C23)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignas&action=edit&section=2 "Edit section: Explanation")] Explanation

The `_Alignas`(until C23)`alignas`(since C23) specifier can only be used when declaring objects that are not [bit-fields](bit_field.html "c/language/bit field"), and don't have the [register](storage_class_specifiers.html "c/language/storage duration") storage class. It cannot be used in function parameter declarations, and cannot be used in a typedef. 

When used in a declaration, the declared object will have its [alignment requirement](object.html#Alignment "c/language/object") set to 

1,2) the result of the expression, unless it is zero

3,4) the alignment requirement of type, that is, to _Alignof(type)(until C23)alignof(type)(since C23)

except when this would weaken the alignment the type would have had naturally. 

If expression evaluates to zero, this specifier has no effect. 

When multiple `_Alignas`(until C23)`alignas`(since C23) specifiers appear in the same declaration, the strictest one is used. 

`_Alignas`(until C23)`alignas`(since C23) specifier only needs to appear on the [definition](declarations.html#Definitions "c/language/declarations") of an object, but if any declaration uses `_Alignas`(until C23)`alignas`(since C23), it must specify the same alignment as the `_Alignas`(until C23)`alignas`(since C23) on the definition. The behavior is undefined if different translation units specify different alignments for the same object. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignas&action=edit&section=3 "Edit section: Notes")] Notes

In C++, the `alignas` specifier may also be applied to the declarations of class/struct/union types and enumerations. This is not supported in C, but the alignment of a struct type can be controlled by using `_Alignas`(until C23)`alignas`(since C23) in a member declaration. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignas&action=edit&section=4 "Edit section: Keywords")] Keywords

[`alignas`](../keyword/alignas.html "c/keyword/alignas"), [`_Alignas`](../keyword/_Alignas.html "c/keyword/ Alignas")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignas&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <stdalign.h>
    #include <stdio.h>
     
    // every object of type struct sse_t will be aligned to 16-byte boundary
    // (note: needs support for DR 444)
    struct sse_t
    {
        alignas(16) float sse_data[4];
    };
     
    // every object of type struct data will be aligned to 128-byte boundary
    struct data
    {
        char x;
        alignas(128) char cacheline[128]; // over-aligned array of char,
                                          // not array of over-aligned chars
    };
     
    int main(void)
    {
        [printf](../io/fprintf.html)("sizeof(data) = %zu (1 byte + 127 bytes padding + 128-byte array)\n",
               sizeof(struct data));
     
        [printf](../io/fprintf.html)("alignment of sse_t is %zu\n", alignof(struct sse_t));
     
        alignas(2048) struct data d; // this instance of data is aligned even stricter
        (void)d; // suppresses "maybe unused" warning
    }

Output: 
    
    
    sizeof(data) = 256 (1 byte + 127 bytes padding + 128-byte array)
    alignment of sse_t is 16

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignas&action=edit&section=6 "Edit section: Defect reports")] Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards. 

DR  | Applied to  | Behavior as published  | Correct behavior   
---|---|---|---  
[DR 444](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_444) | C11  | `_Alignas` was not allowed in struct and union members  | allowed   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignas&action=edit&section=7 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.5 Alignment specifier (p: TBD) 



    

  * 6.2.8 Alignment of objects (p: TBD) 



    

  * 7.15 Alignment <stdalign.h> (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.5 Alignment specifier (p: 92) 



    

  * 6.2.8 Alignment of objects (p: 36-37) 



    

  * 7.15 Alignment <stdalign.h> (p: 196) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.5 Alignment specifier (p: 127-128) 



    

  * 6.2.8 Alignment of objects (p: 48-49) 



    

  * 7.15 Alignment <stdalign.h> (p: 268) 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignas&action=edit&section=8 "Edit section: See also")] See also

[ max_align_t](../types/max_align_t.html "c/types/max align t")(C11) |  a type with alignment requirement as great as any other scalar type   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_max_align_t&action=edit)  
---|---  
[`_Alignof`](alignof.html "c/language/ Alignof")(until C23)[`alignof`](alignof.html "c/language/ Alignof")(since C23) |  queries alignment requirements of an object  
(operator)  
[C++ documentation](../../cpp/language/alignas.html "cpp/language/alignas") for `alignas` specifier  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignas&oldid=180144](https://en.cppreference.com/mwiki/index.php?title=c/language/_Alignas&oldid=180144)" 

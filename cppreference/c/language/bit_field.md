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
**Bit-field**  
[Atomic types](atomic.html "c/language/atomic") (C11)  
[const](const.html "c/language/const")  
[constexpr](constexpr.html "c/language/constexpr")(C23)  
[volatile](volatile.html "c/language/volatile")  
[restrict](restrict.html "c/language/restrict")(C99)  
[Alignment specifiers](alignas.html "c/language/ Alignas")  
[Storage duration and linkage](storage_class_specifiers.html "c/language/storage duration")  
[External and tentative definitions](extern.html "c/language/extern")  
[typedef](typedef.html "c/language/typedef")  
[Static assertions](static_assert.html "c/language/ Static assert")  
[Attributes](attributes.html "c/language/attributes") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/declarations/navbar_content&action=edit)

Declares a member with explicit width, in bits. Adjacent bit-field members may be packed to share and straddle the individual bytes. 

A bit-field declaration is a [struct](struct.html "c/language/struct") or [union](union.html "c/language/union") member declaration which uses the following [declarator](declarations.html "c/language/declarations"):   
  
---  
identifier ﻿(optional) `**:**` width |  |   
identifier |  \-  |  a name of the bit-field that is being declared. The name is optional: nameless bit-fields introduce the specified number of bits of padding   
---|---|---  
width |  \-  |  an integer [constant expression](constant_expression.html "c/language/constant expression") with a value greater or equal to zero and less or equal the number of bits in the underlying type. When greater than zero, this is the number of bits that this bit-field will occupy. The value zero is only allowed for nameless bit-fields and has special meaning: it specifies that the next bit-field in the class definition will begin at an allocation unit's boundary.   
  
## Contents

  * [1 Explanation](bit_field.html#Explanation)
  * [2 Notes](bit_field.html#Notes)
  * [3 References](bit_field.html#References)
  * [4 See also](bit_field.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/bit_field&action=edit&section=1 "Edit section: Explanation")] Explanation

Bit-fields can have only one of the following (possibly [const](const.html "c/language/const") or [volatile](volatile.html "c/language/volatile") qualified) types: 

  * unsigned int, for unsigned bit-fields (e.g. unsigned int b : 3; has the range `[`​0​`, `7`]`) 
  * signed int, for signed bit-fields (signed int b : 3; has the range `[`-4`, `3`]`) 
  * int, for bit-fields with implementation-defined signedness (note that this differs from the meaning of the keyword int everywhere else, where it means "signed int"). For example, int b : 3; may have the range of values `[`​0​`, `7`]` or `[`-4`, `3`]`. 



  * _Bool, for single-bit bit-fields (e.g. bool x : 1;) has the range `[`​0​`, `1`]` and [implicit conversions](conversion.html "c/language/conversion") to and from it follow the boolean conversion rules. 

| (since C99)  
---|---  
  
  * bit-precise integer types (e.g. _BitInt(5) : 4; has the range `[`-8`, `7`]` and unsigned _BitInt(5) : 4; has the range `[`​0​`, `15`]`). 

| (since C23)  
  
Additional implementation-defined types may be acceptable. It is also implementation-defined whether a bit-field may have [atomic](atomic.html "c/language/atomic") type.(since C11) The number of bits in a bit-field (width) sets the limit to the range of values it can hold: 

Run this code
    
    
    #include <stdio.h>
     
    struct S
    {
        // three-bit unsigned field,
        // allowed values are 0...7
        unsigned int b : 3;
    };
     
    int main(void)
    {
        struct S s = {7};
        ++s.b; // unsigned overflow
        [printf](../io/fprintf.html)("%d\n", s.b); // output: 0
    }

Multiple adjacent bit-fields are permitted to be (and usually are) packed together: 

Run this code
    
    
    #include <stdio.h>
     
    struct S
    {
        // will usually occupy 4 bytes:
        // 5 bits: value of b1
        // 11 bits: unused
        // 6 bits: value of b2
        // 2 bits: value of b3
        // 8 bits: unused
        unsigned b1 : 5, : 11, b2 : 6, b3 : 2;
    };
     
    int main(void)
    {
        [printf](../io/fprintf.html)("%zu\n", sizeof(struct S)); // usually prints 4
    }

The special _unnamed bit-field_ of width zero breaks up padding: it specifies that the next bit-field begins at the beginning of the next allocation unit: 

Run this code
    
    
    #include <stdio.h>
     
    struct S
    {
        // will usually occupy 8 bytes:
        // 5 bits: value of b1
        // 27 bits: unused
        // 6 bits: value of b2
        // 15 bits: value of b3
        // 11 bits: unused
        unsigned b1 : 5;
        unsigned    : 0; // starts a new unsigned int
        unsigned b2 : 6;
        unsigned b3 : 15;
    };
     
    int main(void)
    {
        [printf](../io/fprintf.html)("%zu\n", sizeof(struct S)); // usually prints 8
    }

Because bit-fields do not necessarily begin at the beginning of a byte, address of a bit-field cannot be taken. Pointers to bit-fields are not possible. Bit-fields cannot be used with [`sizeof`](sizeof.html "c/language/sizeof") and [`_Alignas`](alignas.html "c/language/ Alignas")(since C11)(until C23)[`alignas`](alignas.html "c/language/alignas")(since C23)(since C11). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/bit_field&action=edit&section=2 "Edit section: Notes")] Notes

The following usages of bit-fields causes _undefined behavior_ : 

  * Calling [offsetof](../types/offsetof.html "c/types/offsetof") on a bit-field. 



The following properties of bit-fields are _unspecified_ : 

  * Alignment of the allocation unit that holds a bit-field. 



The following properties of bit-fields are _implementation-defined_ : 

  * Whether bit-fields of type int are treated as signed or unsigned. 
  * Whether types other than int, signed int, unsigned int, _Bool(since C99), and (possibly unsigned) _BitInt(N)(since C23) are permitted. 



  * Whether atomic types are permitted. 

| (since C11)  
---|---  
  
  * Whether a bit-field can straddle an allocation unit boundary. 
  * The order of bit-fields within an allocation unit (on some platforms, bit-fields are packed left-to-right, on others right-to-left). 

Even though the number of bits in the object representation of _Bool is at least [CHAR_BIT](../types/limits.html "c/types/limits"), the width of the bit-field of type _Bool cannot be greater than 1.  | (since C99)  
---|---  
  
In the C++ programming language, the width of a bit-field can exceed the width of the underlying type (but the extra bits are padding bits), and bit-fields of type int are always signed. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/bit_field&action=edit&section=3 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.2.1 Structure and union specifiers 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.2.1 Structure and union specifiers 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.2.1 Structure and union specifiers 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.7.2.1 Structure and union specifiers 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.5.2.1 Structure and union specifiers 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/bit_field&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/bit_field.html "cpp/language/bit field") for Bit-field  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/bit_field&oldid=180012](https://en.cppreference.com/mwiki/index.php?title=c/language/bit_field&oldid=180012)" 

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
**union**  
[Bit-field](bit_field.html "c/language/bit field")  
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

A union is a type consisting of a sequence of members whose storage overlaps (as opposed to struct, which is a type consisting of a sequence of members whose storage is allocated in an ordered sequence). The value of at most one of the members can be stored in a union at any one time. 

The [type specifier](declarations.html "c/language/declarations") for a union is identical to the [`struct`](struct.html "c/language/struct") type specifier except for the keyword used: 

## Contents

  * [1 Syntax](union.html#Syntax)
  * [2 Explanation](union.html#Explanation)
  * [3 Keywords](union.html#Keywords)
  * [4 Notes](union.html#Notes)
  * [5 Example](union.html#Example)
  * [6 Defect reports](union.html#Defect_reports)
  * [7 References](union.html#References)
  * [8 See also](union.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/union&action=edit&section=1 "Edit section: Syntax")] Syntax  
  
---  
`**union**` attr-spec-seq ﻿(optional) name ﻿(optional) `**{**` struct-declaration-list `**}**` |  (1)  |   
`**union**` attr-spec-seq ﻿(optional) name |  (2)  |   
name |  \-  |  the name of the union that's being defined   
---|---|---  
struct-declaration-list |  \-  |  any number of variable declarations, [bit-field](bit_field.html "c/language/bit field") declarations, and static assert declarations. Members of incomplete type and members of function type are not allowed.   
attr-spec-seq |  \-  |  (C23)optional list of [attributes](attributes.html "c/language/attributes"), applied to the union type, not allowed for (2) if such form is not followed by a `**;**` (i.e. not a forward declaration).   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/union&action=edit&section=2 "Edit section: Explanation")] Explanation

The union is only as big as necessary to hold its largest member (additional unnamed trailing padding may also be added). The other members are allocated in the same bytes as part of that largest member. 

A pointer to a union can be cast to a pointer to each of its members (if a union has bit-field members, the pointer to a union can be cast to the pointer to the bit-field's underlying type). Likewise, a pointer to any member of a union can be cast to a pointer to the enclosing union. 

If the member used to access the contents of a union is not the same as the member last used to store a value, the object representation of the value that was stored is reinterpreted as an object representation of the new type (this is known as _type punning_). If the size of the new type is larger than the size of the last-written type, the contents of the excess bytes are unspecified (and may be a trap representation). Before C99 TC3 (DR 283) this behavior was undefined, but commonly implemented this way.  | (since C99)  
---|---  
Similar to struct, an unnamed member of a union whose type is a union without name is known as _anonymous union_. Every member of an anonymous union is considered to be a member of the enclosing struct or union keeping their union layout. This applies recursively if the enclosing struct or union is also anonymous. 
    
    
    struct v
    {
       union // anonymous union
       {
           struct { int i, j; }; // anonymous structure
           struct { long k, l; } w;
       };
       int m;
    } v1;
     
    v1.i = 2;   // valid
    v1.k = 3;   // invalid: inner structure is not anonymous
    v1.w.k = 5; // valid

Similar to struct, the behavior of the program is undefined if union is defined without any named members (including those obtained via anonymous nested structs or unions).  | (since C11)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/union&action=edit&section=3 "Edit section: Keywords")] Keywords

[`union`](../keyword/union.html "c/keyword/union")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/union&action=edit&section=4 "Edit section: Notes")] Notes

See [struct initialization](struct_initialization.html "c/language/struct initialization") for the rules about initialization of structs and unions. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/union&action=edit&section=5 "Edit section: Example")] Example

Run this code
    
    
    #include <assert.h>
    #include <stdint.h>
    #include <stdio.h>
     
    int main(void)
    {
        union S
        {
            [uint32_t](../types/integer.html) u32;
            [uint16_t](../types/integer.html) u16[2];
            [uint8_t](../types/integer.html)  u8;
        } s = {0x12345678}; // s.u32 is now the active member
        [printf](../io/fprintf.html)("Union S has size %zu and holds %x\n", sizeof s, s.u32);
        s.u16[0] = 0x0011;  // s.u16 is now the active member
        // reading from s.u32 or from s.u8 reinterprets the object representation
    //  printf("s.u8 is now %x\n", s.u8); // unspecified, typically 11 or 00
    //  printf("s.u32 is now %x\n", s.u32); // unspecified, typically 12340011 or 00115678
     
        // pointers to all members of a union compare equal to themselves and the union
        [assert](../error/assert.html)(([uint8_t](../types/integer.html)*)&s == &s.u8);
     
        // this union has 3 bytes of trailing padding
        union pad
        {
            char  c[5]; // occupies 5 bytes
            float f;    // occupies 4 bytes, imposes alignment 4
        } p = { .f = 1.23 }; // the size is 8 to satisfy float's alignment
        [printf](../io/fprintf.html)("size of union of char[5] and float is %zu\n", sizeof p);
    }

Possible output: 
    
    
    Union S has size 4 and holds 12345678
    size of union of char[5] and float is 8

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/union&action=edit&section=6 "Edit section: Defect reports")] Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards. 

DR  | Applied to  | Behavior as published  | Correct behavior   
---|---|---|---  
[DR 499](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_499) | C11  | members of anonymous structs/unions were considered members of the enclosing struct/union  | they retain their memory layout   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/union&action=edit&section=7 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.2.1 Structure and union specifiers (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.2.1 Structure and union specifiers (p: 81-84) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.2.1 Structure and union specifiers (p: 112-117) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.7.2.1 Structure and union specifiers (p: 101-104) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.5.2.1 Structure and union specifiers 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/union&action=edit&section=8 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/union.html "cpp/language/union") for Union declaration  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/union&oldid=168508](https://en.cppreference.com/mwiki/index.php?title=c/language/union&oldid=168508)" 

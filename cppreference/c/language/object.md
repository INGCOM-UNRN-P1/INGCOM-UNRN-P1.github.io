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
**Objects and alignment**  
[The main() function](main_function.html "c/language/main function")  
[The as-if rule](as_if.html "c/language/as if")  
[Undefined behavior](behavior.html "c/language/behavior")  
[Memory model and data races](memory_model.html "c/language/memory model")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/basics/navbar_content&action=edit)

C programs create, destroy, access, and manipulate objects. 

An object in C is a region of [data storage](memory_model.html "c/language/memory model") in the execution environment, the contents of which can represent _values_ (a value is the meaning of the contents of an object, when interpreted as having a specific [type](compatible_type.html "c/language/type")). 

Every object has 

  * size (can be determined with [`sizeof`](sizeof.html "c/language/sizeof")) 
  * alignment requirement(can be determined by [`_Alignof`](alignof.html "c/language/ Alignof")(until C23)[`alignof`](alignof.html "c/language/alignof")(since C23))(since C11)
  * [storage duration](storage_class_specifiers.html "c/language/storage duration") (automatic, static, allocated, thread-local) 
  * [lifetime](lifetime.html "c/language/lifetime") (equal to storage duration or temporary) 
  * effective type (see below) 
  * value (which may be indeterminate) 
  * optionally, an [identifier](identifiers.html "c/language/identifier") that denotes this object. 



Objects are created by [declarations](declarations.html "c/language/declarations"), [allocation functions](../memory.html "c/memory"), [string literals](string_literal.html "c/language/string literal"), [compound literals](compound_literal.html "c/language/compound literal"), and by non-lvalue expressions that return [structures or unions with array members](lifetime.html "c/language/lifetime"). 

## Contents

  * [1 Object representation](object.html#Object_representation)
  * [2 Effective type](object.html#Effective_type)
  * [3 Strict aliasing](object.html#Strict_aliasing)
  * [4 Alignment](object.html#Alignment)
  * [5 Defect reports](object.html#Defect_reports)
  * [6 References](object.html#References)
  * [7 See also](object.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/object&action=edit&section=1 "Edit section: Object representation")] Object representation

Except for [bit-fields](bit_field.html "c/language/bit field"), objects are composed of contiguous sequences of one or more bytes, each consisting of [CHAR_BIT](../types/limits.html "c/types/limits") bits, and can be copied with [memcpy](../string/byte/memcpy.html "c/string/byte/memcpy") into an object of type unsigned char[n], where `n` is the size of the object. The contents of the resulting array are known as _object representation_. 

If two objects have the same object representation, they compare equal (except if they are floating-point NaNs). The reverse is not true: two objects that compare equal may have different object representations because not every bit of the object representation needs to participate in the value. Such bits may be used for padding to satisfy alignment requirement, for parity checks, to indicate trap representations, etc. 

If an object representation does not represent any value of the object type, it is known as _trap representation_. Accessing a trap representation in any way other than reading it through an lvalue expression of character type is undefined behavior. The value of a structure or union is never a trap representation even if any particular member is one. 

For the objects of type char, signed char, and unsigned char, every bit of the object representation is required to participate in the value representation and each possible bit pattern represents a distinct value (no padding, trap bits, or multiple representations allowed). 

When objects of [integer types](arithmetic_types.html#Integer_types "c/language/arithmetic types") (short, int, long, long long) occupy multiple bytes, the use of those bytes is implementation-defined, but the two dominant implementations are _big-endian_ (POWER, Sparc, Itanium) and _little-endian_ (x86, x86_64): a big-endian platform stores the most significant byte at the lowest address of the region of storage occupied by the integer, a little-endian platform stores the least significant byte at the lowest address. See [Endianness](https://en.wikipedia.org/wiki/Endianness "enwiki:Endianness") for detail. See also example below. 

Although most implementations do not allow trap representations, padding bits, or multiple representations for integer types, there are exceptions; for example a value of an integer type on Itanium [may be a trap representation](https://web.archive.org/web/20170830125905/https://blogs.msdn.microsoft.com/oldnewthing/20040119-00/?p=41003). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/object&action=edit&section=2 "Edit section: Effective type")] Effective type

Every object has an _effective type_ , which determines which [lvalue](value_category.html "c/language/value category") accesses are valid and which violate the strict aliasing rules. 

If the object was created by a [declaration](declarations.html "c/language/declarations"), the declared type of that object is the object's _effective type_. 

If the object was created by an [allocation function](../memory.html "c/memory") (including [realloc](../memory/realloc.html "c/memory/realloc")), it has no declared type. Such object acquires an effective type as follows: 

  * The first write to that object through an lvalue that has a type other than character type, at which time the type of that lvalue becomes this object's _effective type_ for that write and all subsequent reads. 
  * [memcpy](../string/byte/memcpy.html "c/string/byte/memcpy") or [memmove](../string/byte/memmove.html "c/string/byte/memmove") copy another object into that object, or copy another object into that object as an array of character type, at which time the effective type of the source object (if it had one) becomes the effective type of this object for that write and all subsequent reads. 
  * Any other access to the object with no declared type, the effective type is the type of the lvalue used for the access. 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/object&action=edit&section=3 "Edit section: Strict aliasing")] Strict aliasing

Given an object with _effective type_ T1, using an lvalue expression (typically, dereferencing a pointer) of a different type T2 is undefined behavior, unless: 

  * T2 and T1 are [compatible types](compatible_type.html#Compatible_types "c/language/type"). 
  * T2 is cvr-qualified version of a type that is [compatible](compatible_type.html#Compatible_types "c/language/type") with T1. 
  * T2 is a signed or unsigned version of a type that is [compatible](compatible_type.html#Compatible_types "c/language/type") with T1. 
  * T2 is an aggregate type or union type type that includes one of the aforementioned types among its members (including, recursively, a member of a subaggregate or contained union). 
  * T2 is a character type (char, signed char, or unsigned char). 


    
    
    int i = 7;
    char* pc = (char*)(&i);
     
    if (pc[0] == '\x7') // aliasing through char is OK
        [puts](../io/puts.html)("This system is little-endian");
    else
        [puts](../io/puts.html)("This system is big-endian");
     
    float* pf = (float*)(&i);
    float d = *pf; // UB: float lvalue *p cannot be used to access int

These rules control whether when compiling a function that receives two pointers, the compiler must emit code that re-reads one after writing through another: 
    
    
    // int* and double* cannot alias
    void f1(int* pi, double* pd, double d)
    {
        // the read from *pi can be done only once, before the loop
        for (int i = 0; i < *pi; i++)
            *pd++ = d;
    }
    
    
    struct S { int a, b; };
     
    // int* and struct S* may alias because S is an aggregate type with a member of type int
    void f2(int* pi, struct S* ps, struct S s)
    {
        // read from *pi must take place after every write through *ps
        for (int i = 0; i < *pi; i++)
            *ps++ = s;
    }

Note that [restrict qualifier](restrict.html "c/language/restrict") can be used to indicate that two pointers do not alias even if the rules above permit them to be. 

Note that type-punning may also be performed through the inactive member of a [union](union.html "c/language/union"). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/object&action=edit&section=4 "Edit section: Alignment")] Alignment

Every complete [object type](types.html#Type_groups "c/language/types") has a property called _alignment requirement_ , which is an integer value of type [size_t](../types/size_t.html "c/types/size t") representing the number of bytes between successive addresses at which objects of this type can be allocated. The valid alignment values are non-negative integral powers of two. 

The alignment requirement of a type can be queried with [`_Alignof`](alignof.html "c/language/ Alignof")(until C23)[`alignof`](alignof.html "c/language/alignof")(since C23).  | (since C11)  
---|---  
  
In order to satisfy alignment requirements of all members of a struct, padding may be inserted after some of its members. 

Run this code
    
    
    #include <stdalign.h>
    #include <stdio.h>
     
    // objects of struct S can be allocated at any address
    // because both S.a and S.b can be allocated at any address
    struct S
    {
        char a; // size: 1, alignment: 1
        char b; // size: 1, alignment: 1
    }; // size: 2, alignment: 1
     
    // objects of struct X must be allocated at 4-byte boundaries
    // because X.n must be allocated at 4-byte boundaries
    // because int's alignment requirement is (usually) 4
    struct X
    {
        int n;  // size: 4, alignment: 4
        char c; // size: 1, alignment: 1
        // three bytes padding
    }; // size: 8, alignment: 4
     
    int main(void)
    {
        [printf](../io/fprintf.html)("sizeof(struct S) = %zu\n", sizeof(struct S));
        [printf](../io/fprintf.html)("alignof(struct S) = %zu\n", alignof(struct S));
        [printf](../io/fprintf.html)("sizeof(struct X) = %zu\n", sizeof(struct X));
        [printf](../io/fprintf.html)("alignof(struct X) = %zu\n", alignof(struct X));
    }

Possible output: 
    
    
    sizeof(struct S) = 2
    alignof(struct S) = 1
    sizeof(struct X) = 8
    alignof(struct X) = 4

Each object type imposes its alignment requirement on every object of that type. The weakest (smallest) alignment is the alignment of the types char, signed char, and unsigned char, and equals 1. The strictest (largest) _fundamental alignment_ of any type is implementation-definedand equal to the alignment of [max_align_t](../types/max_align_t.html "c/types/max align t")(since C11). 

Fundamental alignments are supported for objects of all kinds of storage durations. 

If an object's alignment is made stricter (larger) than [max_align_t](../types/max_align_t.html "c/types/max align t") using [`_Alignof`](alignof.html "c/language/ Alignof")(until C23)[`alignof`](alignof.html "c/language/alignof")(since C23), it has _extended alignment requirement_. A struct or union type whose member has extended alignment is an _over-aligned type_. It is implementation-defined if over-aligned types are supported, and their support may be different in each kind of [storage duration](storage_class_specifiers.html "c/language/storage duration"). If a struct or union type `S` does not have any member of an over-aligned type or declared with an alignment specifier that specifies an extended alignment, `S` has a fundamental alignment. The [atomic](atomic.html "c/language/atomic") version of every [arithmetic](arithmetic_types.html "c/language/arithmetic types") or [pointer](pointer.html "c/language/pointer") type has a fundamental alignment.  | (since C11)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/object&action=edit&section=5 "Edit section: Defect reports")] Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards. 

DR  | Applied to  | Behavior as published  | Correct behavior   
---|---|---|---  
[DR 445](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_445) | C11  | a type might have extended alignment without _Alignas involved  | it must have fundamental alignment   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/object&action=edit&section=6 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 3.15 object (p: 5) 



    

  * 6.2.6 Representations of types (p: 33-35) 



    

  * 6.2.8 Alignment of objects (p: 36-37) 



    

  * 6.5/6-7 Expressions (p: 55-56) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 3.15 object (p: 6) 



    

  * 6.2.6 Representations of types (p: 44-46) 



    

  * 6.2.8 Alignment of objects (p: 48-49) 



    

  * 6.5/6-7 Expressions (p: 77) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 3.2 alignment (p: 3) 



    

  * 3.14 object (p: 5) 



    

  * 6.2.6 Representations of types (p: 37-39) 



    

  * 6.5/6-7 Expressions (p: 67-68) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 1.6 Definitions of terms 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/object&action=edit&section=7 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/objects.html "cpp/language/object") for Object  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/object&oldid=179995](https://en.cppreference.com/mwiki/index.php?title=c/language/object&oldid=179995)" 

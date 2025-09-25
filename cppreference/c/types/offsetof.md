From cppreference.com

< [c](../../c.html "c")‎ | [types](../types.html "c/types")

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

[ Type support](../types.html "c/types")

[size_t](size_t.html "c/types/size t")  
---  
[ptrdiff_t](ptrdiff_t.html "c/types/ptrdiff t")  
[nullptr_t](nullptr_t.html "c/types/nullptr t")(C23)  
[NULL](NULL.html "c/types/NULL")  
[max_align_t](max_align_t.html "c/types/max align t")(C11)  
**offsetof**  
[ Numeric limits](limits.html "c/types/limits")  
[ Fixed width integer types](integer.html "c/types/integer") (C99)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/navbar_content&action=edit)

Defined in header `[`<stddef.h>`](../header/stddef.html "c/header/stddef")` |  |   
---|---|---  
#define offsetof(type, member) /*implementation-defined*/ |  |   
| |   
  
The macro **offsetof** expands to an [integer constant expression](../language/constant_expression.html#Integer_constant_expression "c/language/constant expression") of type [size_t](size_t.html "c/types/size t"), the value of which is the offset, in bytes, from the beginning of an object of specified type to its specified subobject, including padding if any. 

Given an object `o` of type `type` with static storage duration, &(o.member) shall be an address constant expression and point to a subobject of `o`. Otherwise, the behavior is undefined. 

If the type name specified in `type` contains a comma not between matching parentheses, the behavior is undefined.  | (since C23)  
---|---  
  
## Contents

  * [1 Notes](offsetof.html#Notes)
  * [2 Example](offsetof.html#Example)
  * [3 Defect reports](offsetof.html#Defect_reports)
  * [4 See also](offsetof.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/offsetof&action=edit&section=1 "Edit section: Notes")] Notes

If `offsetof` is applied to a bit-field member, the behavior is undefined, because the address of a bit-field cannot be taken. 

`member` is not restricted to a direct member. It can denote a subobject of a given member, such as an element of an array member. 

Even though it is specified in C23 that specifying a new type containing an unparenthesized comma in `offsetof` is undefined behavior, such usage is generally not supported even in earlier modes: offsetof(struct Foo { int a, b; }, a) generally fails to compile. 

[`typeof`](../language/typeof_unqual.html "c/language/typeof") can be used to avoid the bad effect of commas in the definition of a new type, e.g. offsetof(typeof(struct { int i, j; }), i) is well-defined.  | (since C23)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/offsetof&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stddef.h>
     
    struct S {
        char c;
        double d;
    };
     
    int main(void)
    {
        [printf](../io/fprintf.html)("the first element is at offset %zu\n", offsetof(struct S, c));
        [printf](../io/fprintf.html)("the double is at offset %zu\n", offsetof(struct S, d));
    }

Possible output: 
    
    
    the first element is at offset 0
    the double is at offset 8

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/offsetof&action=edit&section=3 "Edit section: Defect reports")] Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards. 

DR  | Applied to  | Behavior as published  | Correct behavior   
---|---|---|---  
[DR 496](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2396.htm#dr_496) | C89  | only structs and struct members were mentioned  | unions and other subobjects are also supported   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/types/offsetof&action=edit&section=4 "Edit section: See also")] See also

[ size_t](size_t.html "c/types/size t") |  unsigned integer type returned by the [`sizeof`](../language/sizeof.html "c/language/sizeof") operator   
(typedef) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/types/dsc_size_t&action=edit)  
---|---  
[C++ documentation](../../cpp/types/offsetof.html "cpp/types/offsetof") for offsetof  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/types/offsetof&oldid=170432](https://en.cppreference.com/mwiki/index.php?title=c/types/offsetof&oldid=170432)" 

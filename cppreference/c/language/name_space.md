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
**Lookup and name spaces**  
[Type](compatible_type.html "c/language/type")  
[Arithmetic types](arithmetic_types.html "c/language/arithmetic types")  
[Objects and alignment](object.html "c/language/object")  
[The main() function](main_function.html "c/language/main function")  
[The as-if rule](as_if.html "c/language/as if")  
[Undefined behavior](behavior.html "c/language/behavior")  
[Memory model and data races](memory_model.html "c/language/memory model")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/basics/navbar_content&action=edit)

When an [identifier](identifiers.html "c/language/identifier") is encountered in a C program, a lookup is performed to locate the [declaration](declarations.html "c/language/declarations") that introduced that identifier and that is currently [in scope](scope.html "c/language/scope"). C allows more than one declaration for the same identifier to be in scope simultaneously if these identifiers belong to different categories, called _name spaces_ : 

1) Label name space: all identifiers declared as [labels](statements.html#Labels "c/language/statements").

2) Tag names: all identifiers declared as names of [structs](struct.html "c/language/struct"), [unions](union.html "c/language/union") and [enumerated types](enum.html "c/language/enum"). Note that all three kinds of tags share one name space.

3) Member names: all identifiers declared as members of any one [struct](struct.html "c/language/struct") or [union](union.html "c/language/union"). Every struct and union introduces its own name space of this kind.

4) Global attribute name space: [attribute tokens](attributes.html "c/language/attributes") defined by the standard or implementation-defined attribute prefixes. 5) Non-standard attribute names: attribute names following attribute prefixes. Each attribute prefix has a separate name space for the implementation-defined attributes it introduces. | (since C23)  
---|---  
  
6) All other identifiers, called _ordinary identifiers_ to distinguish from (1-5) (function names, object names, typedef names, enumeration constants).

At the point of lookup, the name space of an identifier is determined by the manner in which it is used: 

1) identifier appearing as the operand of a [goto statement](goto.html "c/language/goto") is looked up in the label name space.

2) identifier that follows the keyword struct, union, or enum is looked up in the tag name space.

3) identifier that follows the [member access](operator_member_access.html "c/language/operator member access") or member access through pointer operator is looked up in the name space of members of the type determined by the left-hand operand of the member access operator.

4) identifier that directly appears in an attribute specifier ([[...]]) is looked up in the global attribute name space. 5) identifier that follows the :: token following an attribute prefix is looked in the name space introduced by the attribute prefix. | (since C23)  
---|---  
  
6) all other identifiers are looked up in the name space of ordinary identifiers.

## Contents

  * [1 Notes](name_space.html#Notes)
  * [2 Example](name_space.html#Example)
  * [3 References](name_space.html#References)
  * [4 See also](name_space.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/name_space&action=edit&section=1 "Edit section: Notes")] Notes

The names of [macros](../preprocessor/replace.html "c/preprocessor/replace") are not part of any name space because they are replaced by the preprocessor prior to semantic analysis. 

It is common practice to inject struct/union/enum names into the name space of the ordinary identifiers using a [typedef](typedef.html "c/language/typedef") declaration: 
    
    
    struct A { };       // introduces the name A in tag name space
    typedef struct A A; // first, lookup for A after "struct" finds one in tag name space
                        // then introduces the name A in the ordinary name space
    struct A* p;        // OK, this A is looked up in the tag name space
    A* q;               // OK, this A is looked up in the ordinary name space

A well-known example of the same identifier being used across two name spaces is the identifier stat from the POSIX header `sys/stat.h`. It [names a function](http://pubs.opengroup.org/onlinepubs/9699919799/) when used as an ordinary identifier and [indicates a struct](http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_stat.h.html) when used as a tag. 

Unlike in C++, enumeration constants are not struct members, and their name space is the name space of ordinary identifiers, and since there is no struct scope in C, their scope is the scope in which the struct declaration appears: 
    
    
    struct tagged_union {
       enum {INT, FLOAT, STRING} type;
       union {
          int integer;
          float floating_point;
          char *string;
       };
    } tu;
     
    tu.type = INT; // OK in C, error in C++

If a standard attribute, an attribute prefix, or a non-standard attribute name is not supported, the invalid attribute itself is ignored without causing an error.  | (since C23)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/name_space&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    void foo (void) { return; } // ordinary name space, file scope
    struct foo {      // tag name space, file scope
        int foo;      // member name space for this struct foo, file scope
        enum bar {    // tag name space, file scope
            RED       // ordinary name space, file scope
        } bar;        // member name space for this struct foo, file scope
        struct foo* p; // OK: uses tag/file scope name "foo"
    };
    enum bar x; // OK: uses tag/file-scope bar
    // int foo; // Error: ordinary name space foo already in scope 
    //union foo { int a, b; }; // Error: tag name space foo in scope
     
    int main(void)
    {
        goto foo; // OK uses "foo" from label name space/function scope
     
        struct foo { // tag name space, block scope (hides file scope)
           enum bar x; // OK, uses "bar" from tag name space/file scope
        };
        typedef struct foo foo; // OK: uses foo from tag name space/block scope
                                // defines block-scope ordinary foo (hides file scope)
        (foo){.x=RED}; // uses ordinary/block-scope foo and ordinary/file-scope RED
     
    foo:; // label name space, function scope
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/name_space&action=edit&section=3 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.2.3 Name spaces of identifiers (p: 29-30) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.2.3 Name spaces of identifiers (p: 37) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.2.3 Name spaces of identifiers (p: 31) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.1.2.3 Name spaces of identifiers 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/name_space&action=edit&section=4 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/lookup.html "cpp/language/lookup") for Name lookup  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/name_space&oldid=136120](https://en.cppreference.com/mwiki/index.php?title=c/language/name_space&oldid=136120)" 

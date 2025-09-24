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
**Lifetime**  
[Lookup and name spaces](name_space.html "c/language/name space")  
[Type](compatible_type.html "c/language/type")  
[Arithmetic types](arithmetic_types.html "c/language/arithmetic types")  
[Objects and alignment](object.html "c/language/object")  
[The main() function](main_function.html "c/language/main function")  
[The as-if rule](as_if.html "c/language/as if")  
[Undefined behavior](behavior.html "c/language/behavior")  
[Memory model and data races](memory_model.html "c/language/memory model")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/basics/navbar_content&action=edit)

Every [object](object.html "c/language/object") in C exists, has a constant address, retains its last-stored value (except when the value is indeterminate), and, for VLA, retains its size(since C99) over a portion of program execution known as this object's _lifetime_. 

For the objects that are declared with automatic, static, and thread storage duration, lifetime equals their [storage duration](storage_class_specifiers.html "c/language/storage duration") (note the difference between non-VLA and VLA automatic storage duration). 

For the objects with allocated storage duration, the lifetime begins when the allocation function returns (including the return from [realloc](../memory/realloc.html "c/memory/realloc")) and ends when the [realloc](../memory/realloc.html "c/memory/realloc") or deallocation function is called. Note that since allocated objects have no [declared type](object.html "c/language/object"), the type of the lvalue expression first used to access this object becomes its [effective type](object.html "c/language/object"). 

Accessing an object outside of its lifetime is undefined behavior. 
    
    
    int* foo(void) {
        int a = 17; // a has automatic storage duration
        return &a;
    }  // lifetime of a ends
    int main(void) {
        int* p = foo(); // p points to an object past lifetime ("dangling pointer")
        int n = *p; // undefined behavior
    }

A pointer to an object (or one past the object) whose lifetime ended has indeterminate value. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/lifetime&action=edit&section=1 "Edit section: Temporary lifetime")] Temporary lifetime

Struct and union objects with array members (either direct or members of nested struct/union members) that are designated by [non-lvalue expressions](value_category.html "c/language/value category"), have _temporary lifetime_. Temporary lifetime begins when the expression that refers to such object is evaluated and ends at the next [sequence point](eval_order.html "c/language/eval order")(until C11)when the containing full expression or full declarator ends(since C11). 

Any attempt to modify an object with temporary lifetime results in undefined behavior. 
    
    
    struct T { double a[4]; };
    struct T f(void) { return (struct T){3.15}; }
    double g1(double* x) { return *x; }
    void g2(double* x) { *x = 1.0; }
    int main(void)
    {
        double d = g1(f().a); // C99: UB access to a[0] in g1 whose lifetime ended
                              //      at the sequence point at the start of g1
                              // C11: OK, d is 3.15
        g2(f().a); // C99: UB modification of a[0] whose lifetime ended at the sequence point
                   // C11: UB attempt to modify a temporary object
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/lifetime&action=edit&section=2 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.2.4 Storage durations of objects (p: 30) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.2.4 Storage durations of objects (p: 38-39) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.2.4 Storage durations of objects (p: 32) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.1.2.4 Storage durations of objects 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/lifetime&action=edit&section=3 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/lifetime.html "cpp/language/lifetime") for Object lifetime  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/lifetime&oldid=138081](https://en.cppreference.com/mwiki/index.php?title=c/language/lifetime&oldid=138081)" 

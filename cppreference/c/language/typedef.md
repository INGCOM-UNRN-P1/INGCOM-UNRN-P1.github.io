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
[Alignment specifiers](alignas.html "c/language/ Alignas")  
[Storage duration and linkage](storage_class_specifiers.html "c/language/storage duration")  
[External and tentative definitions](extern.html "c/language/extern")  
**typedef**  
[Static assertions](static_assert.html "c/language/ Static assert")  
[Attributes](attributes.html "c/language/attributes") (C23)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/declarations/navbar_content&action=edit)

The _typedef declaration_ provides a way to declare an identifier as a type alias, to be used to replace a possibly complex [type name](compatible_type.html#Type_names "c/language/type")

The keyword typedef is used in a [declaration](declarations.html "c/language/declarations"), in the grammatical position of a [storage-class specifier](storage_class_specifiers.html "c/language/storage duration"), except that it does not affect storage or linkage: 
    
    
    typedef int int_t; // declares int_t to be an alias for the type int
    typedef char char_t, *char_p, (*fp)(void); // declares char_t to be an alias for char
                                               // char_p to be an alias for char*
                                               // fp to be an alias for char(*)(void)

## Contents

  * [1 Explanation](typedef.html#Explanation)
  * [2 Notes](typedef.html#Notes)
  * [3 References](typedef.html#References)
  * [4 Keywords](typedef.html#Keywords)
  * [5 See also](typedef.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/typedef&action=edit&section=1 "Edit section: Explanation")] Explanation

If a [declaration](declarations.html "c/language/declarations") uses typedef as storage-class specifier, every declarator in it defines an identifier as an alias to the type specified. Since only one storage-class specifier is permitted in a declaration, typedef declaration cannot be [static or extern](storage_class_specifiers.html "c/language/storage duration"). 

typedef declaration does not introduce a distinct type, it only establishes a synonym for an existing type, thus typedef names are [compatible](compatible_type.html#Compatible_types "c/language/type") with the types they alias. Typedef names share the [name space](name_space.html "c/language/name space") with ordinary identifiers such as enumerators, variables and function. 

A typedef for a VLA can only appear at block scope. The length of the array is evaluated each time the flow of control passes over the typedef declaration, as opposed to the declaration of the array itself: 
    
    
    void copyt(int n)
    {
        typedef int B[n]; // B is a VLA, its size is n, evaluated now
        n += 1;
        B a; // size of a is n from before +=1
        int b[n]; // a and b are different sizes
        for (int i = 1; i < n; i++)
            a[i-1] = b[i];
    }

| (since C99)  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/typedef&action=edit&section=2 "Edit section: Notes")] Notes

typedef name may be an [incomplete type](compatible_type.html#Incomplete_types "c/language/type"), which may be completed as usual: 
    
    
    typedef int A[]; // A is int[]
    A a = {1, 2}, b = {3,4,5}; // type of a is int[2], type of b is int[3]

typedef declarations are often used to inject names from the tag [name space](name_space.html "c/language/name space") into the ordinary name space: 
    
    
    typedef struct tnode tnode; // tnode in ordinary name space
                                // is an alias to tnode in tag name space
    struct tnode {
        int count;
        tnode *left, *right; // same as struct tnode *left, *right;
    }; // now tnode is also a complete type
    tnode s, *sp; // same as struct tnode s, *sp;

They can even avoid using the tag name space at all: 
    
    
    typedef struct { double hi, lo; } range;
    range z, *zp;

Typedef names are also commonly used to simplify the syntax of complex declarations: 
    
    
    // array of 5 pointers to functions returning pointers to arrays of 3 ints
    int (*(*callbacks[5])(void))[3];
     
    // same with typedefs
    typedef int arr_t[3]; // arr_t is array of 3 int
    typedef arr_t* (*fp)(void); // pointer to function returning arr_t*
    fp callbacks[5];

Libraries often expose system-dependent or configuration-dependent types as typedef names, to present a consistent interface to the users or to other library components: 
    
    
    #if defined(_LP64)
    typedef int     wchar_t;
    #else
    typedef long    wchar_t;
    #endif

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/typedef&action=edit&section=3 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 6.7.8 Type definitions (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 6.7.8 Type definitions (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 6.7.8 Type definitions (p: 137-138) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 6.7.7 Type definitions (p: 123-124) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 3.5.6 Type definitions 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/typedef&action=edit&section=4 "Edit section: Keywords")] Keywords

[`typedef`](../keyword/typedef.html "c/keyword/typedef")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/typedef&action=edit&section=5 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/typedef.html "cpp/language/typedef") for `typedef` declaration  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/typedef&oldid=169928](https://en.cppreference.com/mwiki/index.php?title=c/language/typedef&oldid=169928)" 

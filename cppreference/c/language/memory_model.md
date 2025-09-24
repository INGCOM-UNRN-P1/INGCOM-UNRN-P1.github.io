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
[Objects and alignment](object.html "c/language/object")  
[The main() function](main_function.html "c/language/main function")  
[The as-if rule](as_if.html "c/language/as if")  
[Undefined behavior](behavior.html "c/language/behavior")  
**Memory model and data races**  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/language/basics/navbar_content&action=edit)

Defines the semantics of computer memory storage for the purpose of the C abstract machine. 

The data storage (memory) available to a C program is one or more contiguous sequences of _bytes_. Each byte in memory has a unique _address_. 

## Contents

  * [1 Byte](memory_model.html#Byte)
  * [2 Memory location](memory_model.html#Memory_location)
  * [3 Threads and data races](memory_model.html#Threads_and_data_races)
  * [4 Memory order](memory_model.html#Memory_order)
  * [5 References](memory_model.html#References)
  * [6 See also](memory_model.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/memory_model&action=edit&section=1 "Edit section: Byte")] Byte

A _byte_ is the smallest addressable unit of memory. It is defined as a contiguous sequence of bits, large enough to hold any member of the _basic execution character set_ ([the 96 characters](translation_phases.html "c/language/translation phases") that are required to be single-byte). C supports bytes of sizes 8 bits and greater. 

The [types](types.html "c/language/types") char, unsigned char, and signed char use one byte for both storage and [value representation](object.html "c/language/object"). The number of bits in a byte is accessible as [CHAR_BIT](../types/limits.html "c/types/limits"). 

For use of bytes to representation values of other fundamental types (including big-endian and little-endian memory layouts), see [object representation](object.html#Object_representation "c/language/object")

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/memory_model&action=edit&section=2 "Edit section: Memory location")] Memory location

A _memory location_ is 

  * an object of [scalar type](compatible_type.html#Type_groups "c/language/type") (arithmetic type, pointer type, enumeration type) 
  * or the largest contiguous sequence of [bit-fields](bit_field.html "c/language/bit field") of non-zero length 


    
    
    struct S
    {
        char a;     // memory location #1
        int b : 5;  // memory location #2
        int c : 11, // memory location #2 (continued)
              : 0,
            d : 8;  // memory location #3
        struct
        {
            int ee : 8; // memory location #4
        } e;
    } obj; // The object 'obj' consists of 4 separate memory locations

###  Threads and data races

A thread of execution is a flow of control within a program that begins with the invocation of a top-level function by [thrd_create](../thread/thrd_create.html "c/thread/thrd create") or other means. Any thread can potentially access any object in the program (objects with automatic and thread-local [storage duration](storage_class_specifiers.html "c/language/storage duration") may still be accessed by another thread through a pointer). Different threads of execution are always allowed to access (read and modify) different _memory locations_ concurrently, with no interference and no synchronization requirements. (note that it is not safe to concurrently update two non-atomic bit-fields in the same structure if all members declared between them are also (non-zero-length) bit-fields, no matter what the sizes of those intervening bit-fields happen to be) When an [evaluation](eval_order.html "c/language/eval order") of an expression writes to a memory location and another evaluation reads or modifies the same memory location, the expressions are said to _conflict_. A program that has two conflicting evaluations has a _data race_ unless either 

  * both conflicting evaluations are [atomic operations](atomic.html "c/language/atomic")
  * one of the conflicting evaluations _happens-before_ another (see [memory_order](../atomic/memory_order.html "c/atomic/memory order")) 

If a data race occurs, the behavior of the program is undefined.  (in particular, [mtx_unlock](../thread/mtx_unlock.html "c/thread/mtx unlock") is _synchronized-with_ , and therefore, _happens-before_ [mtx_lock](../thread/mtx_lock.html "c/thread/mtx lock") of the same mutex by another thread, which makes it possible to use mutex locks to guard against data races) | | This section is incomplete  
Reason: small example or two   
---|---  
  
###  Memory order

When a thread reads a value from a memory location, it may see the initial value, the value written in the same thread, or the value written in another thread. See [memory_order](../atomic/memory_order.html "c/atomic/memory order") for details on the order in which writes made from threads become visible to other threads. 

(since C11)  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/memory_model&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 3.6 byte (p: TBD) 



    

  * 3.14 memory location (p: TBD) 



    

  * 5.1.2.4 Multi-threaded executions and data races (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 3.6 byte (p: TBD) 



    

  * 3.14 memory location (p: TBD) 



    

  * 5.1.2.4 Multi-threaded executions and data races (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 3.6 byte (p: 4) 



    

  * 3.14 memory location (p: 5) 



    

  * 5.1.2.4 Multi-threaded executions and data races (p: 17-21) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 3.6 byte (p: 4) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 1.6 DEFINITIONS OF TERMS 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/language/memory_model&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/language/memory_model.html "cpp/language/memory model") for Memory model  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/language/memory_model&oldid=175727](https://en.cppreference.com/mwiki/index.php?title=c/language/memory_model&oldid=175727)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



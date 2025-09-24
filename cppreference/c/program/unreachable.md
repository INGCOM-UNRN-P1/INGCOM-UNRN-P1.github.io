From cppreference.com

< [c](../../c.html "c")‎ | [program](../program.html "c/program")

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

[ Program support utilities](../program.html "c/program")

Program termination  
---  
| [abort](abort.html "c/program/abort")  
---  
[exit](exit.html "c/program/exit")  
[quick_exit](quick_exit.html "c/program/quick exit")(C11)  
[_Exit](_Exit.html "c/program/ Exit")(C99)  
  
| [atexit](atexit.html "c/program/atexit")  
---  
[at_quick_exit](at_quick_exit.html "c/program/at quick exit")(C11)  
[EXIT_SUCCESSEXIT_FAILURE](EXIT_status.html "c/program/EXIT status")  
  
Unreachable control flow  
**unreachable**(C23)  
Communicating with the environment  
| [getenvgetenv_s](getenv.html "c/program/getenv")(C11)  
---  
  
| [system](system.html "c/program/system")  
---  
  
  
  
Memory alignment query  
[memalignment](memalignment.html "c/program/memalignment")(C23)  
Signals  
| [signal](signal.html "c/program/signal")  
---  
[raise](raise.html "c/program/raise")  
[sig_atomic_t](sig_atomic_t.html "c/program/sig atomic t")  
  
| [SIG_DFLSIG_IGN](SIG_strategies.html "c/program/SIG strategies")  
---  
[SIG_ERR](SIG_ERR.html "c/program/SIG ERR")  
  
Signal types  
| [SIGABRTSIGFPESIGILL](SIG_types.html "c/program/SIG types")  
---  
  
| [SIGINTSIGSEGVSIGTERM](SIG_types.html "c/program/SIG types")  
---  
  
Non-local jumps  
| [setjmp](setjmp.html "c/program/setjmp")  
---  
  
| [longjmp](longjmp.html "c/program/longjmp")  
---  
  
Types  
[jmp_buf](jmp_buf.html "c/program/jmp buf")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/navbar_content&action=edit)

Defined in header `[`<stddef.h>`](../header/stddef.html "c/header/stddef")` |  |   
---|---|---  
#define unreachable() /* see below */ |  |  (since C23)  
| |   
  
The function-like macro `unreachable` expands to a void expression. Executing unreachable() results in [undefined behavior](../language/behavior.html "c/language/behavior"). 

An implementation may use this to optimize impossible code branches away (typically, in optimized builds) or to trap them to prevent further execution (typically, in debug builds). 

## Contents

  * [1 Possible implementation](unreachable.html#Possible_implementation)
  * [2 Example](unreachable.html#Example)
  * [3 See also](unreachable.html#See_also)
  * [4 External Links](unreachable.html#External_Links)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/unreachable&action=edit&section=1 "Edit section: Possible implementation")] Possible implementation
    
    
    // Uses compiler specific extensions if possible.
    #ifdef __GNUC__ // GCC, Clang, ICC
     
    #define unreachable() (__builtin_unreachable())
     
    #elifdef _MSC_VER // MSVC
     
    #define unreachable() (__assume(false))
     
    #else
    // Even if no extension is used, undefined behavior is still raised by
    // the empty function body and the noreturn attribute.
     
    // The external definition of unreachable_impl must be emitted in a separated TU
    // due to the rule for inline functions in C.
     
    [[noreturn]] inline void unreachable_impl() {}
    #define unreachable() (unreachable_impl())
     
    #endif  
  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/unreachable&action=edit&section=2 "Edit section: Example")] Example

Run this code
    
    
    #include <assert.h>
    #include <stddef.h>
    #include <stdint.h>
    #include <stdlib.h>
     
    struct Color { [uint8_t](../types/integer.html) r, g, b, a; };
    struct ColorSpan { struct Color* data; [size_t](../types/size_t.html) size; };
     
    // Assume that only restricted set of texture caps is supported.
    struct ColorSpan allocate_texture([size_t](../types/size_t.html) xy)
    {
        switch (xy)
        {
        case 128: [[fallthrough]];
        case 256: [[fallthrough]];
        case 512:
        {
            /* ... */
            struct ColorSpan result = {
                .data = [malloc](../memory/malloc.html)(xy * xy * sizeof(struct Color)),
                .size = xy * xy
            };
     
            if (!result.data)
                result.size = 0;
     
            return result;
        }
        default:
            unreachable();
        }
    }
     
    int main(void)
    {
        struct ColorSpan tex = allocate_texture(128); // OK
        [assert](../error/assert.html)(tex.size == 128 * 128);
     
        struct ColorSpan badtex = allocate_texture(32);  // Undefined behavior
     
        [free](../memory/free.html)(badtex.data);
        [free](../memory/free.html)(tex.data);
    }

Possible output: 
    
    
    Segmentation fault

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/unreachable&action=edit&section=3 "Edit section: See also")] See also

[C++ documentation](../../cpp/utility/unreachable.html "cpp/utility/unreachable") for unreachable  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/unreachable&action=edit&section=4 "Edit section: External Links")] External Links

1\.  | [GCC docs: `__builtin_unreachable`](https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html#index-_005f_005fbuiltin_005funreachable)  
---|---  
2\.  | [Clang docs: `__builtin_unreachable`](https://clang.llvm.org/docs/LanguageExtensions.html#builtin-unreachable)  
3\.  | [MSVC docs: `__assume`](https://docs.microsoft.com/en-us/cpp/intrinsics/assume)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/unreachable&oldid=178607](https://en.cppreference.com/mwiki/index.php?title=c/program/unreachable&oldid=178607)" 

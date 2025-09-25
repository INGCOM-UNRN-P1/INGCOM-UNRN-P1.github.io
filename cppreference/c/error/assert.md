From cppreference.com

< [c](../../c.html "c")‎ | [error](../error.html "c/error")

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

[ Error handling](../error.html "c/error")

Error codes  
---  
[ Error codes](errno_macros.html "c/error/errno macros")  
[errno](errno.html "c/error/errno")  
Assertions  
**assert**  
[static_assert](static_assert.html "c/error/static assert")(C11)(removed in C23)  
Bounds checking  
[set_constraint_handler_s](set_constraint_handler_s.html "c/error/set constraint handler s")(C11)  
[abort_handler_s](abort_handler_s.html "c/error/abort handler s")(C11)  
[ignore_handler_s](ignore_handler_s.html "c/error/ignore handler s")(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/navbar_content&action=edit)

Defined in header `[`<assert.h>`](../header/assert.html "c/header/assert")` |  |   
---|---|---  
#ifdef NDEBUG  
#define assert(condition) ((void)0)  
#else  
#define assert(condition) /*implementation defined*/  
#endif |  | (until C23)  
#ifdef NDEBUG  
#define assert(...) ((void)0)  
#else  
#define assert(...) /*implementation defined*/  
#endif |  |  (since C23)  
| |   
  
The definition of the macro `assert` depends on another macro, NDEBUG, which is not defined by the standard library. 

If NDEBUG is defined as a macro name at the point in the source code where [`<assert.h>`](../header/assert.html "c/header/assert") is included, then `assert` does nothing. 

If NDEBUG is not defined, then `assert` checks if its argument(until C23)the expression synthesized from __VA_ARGS__(since C23) (which must have scalar type, otherwise, the behavior is undefined) compares equal to zero. If it does, `assert` outputs implementation-specific diagnostic information on the standard error output and calls [abort](../program/abort.html)(). The diagnostic information is required to include the text of `expression`, as well as the values of  the [predefined variable](../language/function_definition.html "c/language/function definition") __func__ and of(since C99) the [predefined macros](../preprocessor/replace.html "c/preprocessor/replace") __FILE__ and __LINE__. 

## Contents

  * [1 Parameters](assert.html#Parameters)
  * [2 Return value](assert.html#Return_value)
  * [3 Notes](assert.html#Notes)
  * [4 Example](assert.html#Example)
  * [5 References](assert.html#References)
  * [6 See also](assert.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/assert&action=edit&section=1 "Edit section: Parameters")] Parameters

condition  |  \-  |  expression of scalar type   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/assert&action=edit&section=2 "Edit section: Return value")] Return value

(none) 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/assert&action=edit&section=3 "Edit section: Notes")] Notes

There is no standardized interface to add an additional message to `assert` errors. A portable way to include one is to use a [comma operator](../language/operator_other.html#Comma_operator "c/language/operator other"), or use && with a string literal: 
    
    
    assert(("There are five lights", 2 + 2 == 5));
    assert(2 + 2 == 5 && "There are five lights");

The implementation of `assert` in [Microsoft CRT](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/assert-macro-assert-wassert) does not conform to C99 and later revisions, because its underlying function (`_wassert`) takes neither __func__ nor an equivalent replacement. 

Even though the change of `assert` in C23 ([N2829](https://open-std.org/JTC1/SC22/WG14/www/docs/n2829.htm)) is not a formal defect report, the C committee [recommends](https://www.open-std.org/jtc1/sc22/wg14/www/previous.html) implementations to backport the change to old modes. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/assert&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    // uncomment to disable assert()
    // #define NDEBUG
    #include <assert.h>
    #include <math.h>
     
    #define TEST(...) __VA_ARGS__
     
    int main(void)
    {
        double x = -1.0;
        assert(x >= 0.0);
        [printf](../io/fprintf.html)("sqrt(x) = %f\n", [sqrt](../numeric/math/sqrt.html)(x));
     
        assert(TEST(x >= 0.0));
     
        return 0;
    }

Possible output: 
    
    
    --- Output with NDEBUG not defined: ---
    a.out: main.cpp:10: main: Assertion `x >= 0.0' failed.
     
    --- Output with NDEBUG defined: ---
    sqrt(x) = -nan

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/assert&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.2.2.1 The assert macro (p: 196) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.2.1.1 The assert macro (p: 135) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.2.1.1 The assert macro (p: 186-187) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.2.1.1 The assert macro (p: 169) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.2.1.1 The assert macro 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/error/assert&action=edit&section=6 "Edit section: See also")] See also

[ abort](../program/abort.html "c/program/abort") |  causes abnormal program termination (without cleaning up)   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/program/dsc_abort&action=edit)  
---|---  
[C++ documentation](../../cpp/error/assert.html "cpp/error/assert") for assert  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/error/assert&oldid=173989](https://en.cppreference.com/mwiki/index.php?title=c/error/assert&oldid=173989)" 

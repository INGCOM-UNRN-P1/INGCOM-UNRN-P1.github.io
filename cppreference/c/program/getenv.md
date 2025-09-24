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
[unreachable](unreachable.html "c/program/unreachable")(C23)  
Communicating with the environment  
| **getenv getenv_s**(C11)  
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

Defined in header `[`<stdlib.h>`](../header/stdlib.html "c/header/stdlib")` |  |   
---|---|---  
char *getenv( const char *name ); |  (1)  |   
errno_t getenv_s( [size_t](../types/size_t.html) *restrict len, char *restrict value,  
rsize_t valuesz, const char *restrict name ); |  (2)  |  (since C11)  
| |   
  
1) Searches for an environmental variable with name name in the host-specified environment list and returns a pointer to the string that is associated with the matched environment variable. The set of environmental variables and methods of altering it are implementation-defined.

This function is not required to be thread-safe. Another call to `getenv`, as well as a call to the POSIX functions [`setenv()`](https://pubs.opengroup.org/onlinepubs/9699919799/functions/setenv.html), [`unsetenv()`](https://pubs.opengroup.org/onlinepubs/9699919799/functions/unsetenv.html), and [`putenv()`](https://pubs.opengroup.org/onlinepubs/9699919799/functions/putenv.html) may invalidate the pointer returned by a previous call or modify the string obtained from a previous call.

Modifying the string returned by `getenv` invokes undefined behavior.

2) Same as (1), except that the values of the environment variable is written to the user-provided buffer value (unless null) and the number of bytes written is stored in the user-provided location *len (unless null). If the environment variable is not set in the environment, zero is written to *len (unless null) and '\0' is written to value[0] (unless null). In addition, the following errors are detected at runtime and call the currently installed [constraint handler](../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * name is a null pointer 
  * valuesz is greater than RSIZE_MAX
  * value is a null pointer and valuesz is not zero 


    As with all bounds-checked functions, `getenv_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<stdlib.h>`](../header/stdlib.html "c/header/stdlib").

## Contents

  * [1 Parameters](getenv.html#Parameters)
  * [2 Return value](getenv.html#Return_value)
  * [3 Notes](getenv.html#Notes)
  * [4 Example](getenv.html#Example)
  * [5 References](getenv.html#References)
  * [6 See also](getenv.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/getenv&action=edit&section=1 "Edit section: Parameters")] Parameters

name  |  \-  |  null-terminated character string identifying the name of the environmental variable to look for   
---|---|---  
len  |  \-  |  pointer to a user-provided location where `getenv_s` will store the length of the environment variable   
value  |  \-  |  pointer to a user-provided character array where `getenv_s` will store the contents of the environment variable   
valuesz  |  \-  |  maximum number of characters that `getenv_s` is allowed to write to `dest` (size of the buffer)   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/getenv&action=edit&section=2 "Edit section: Return value")] Return value

1) character string identifying the value of the environmental variable or null pointer if such variable is not found.

2) zero if the environment variable was found, non-zero if it was not found or if a runtime constraint violation occurred. On any error, writes zero to *len (unless len is a null pointer).

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/getenv&action=edit&section=3 "Edit section: Notes")] Notes

On POSIX systems, the [environment variables](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap08.html#tag_08) are also accessible through the global variable `environ`, declared as extern char **environ; in [`<unistd.h>`](https://en.cppreference.com/mwiki/index.php?title=c/header/unistd&action=edit&redlink=1 "c/header/unistd \(page does not exist\)"), and through the optional third argument, `envp`, of [the main function](../language/main_function.html "c/language/main function"). 

The call to `getenv_s` with a null pointer for value and zero for valuesz is used to determine the size of the buffer required to hold the entire result. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/getenv&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        const char *name = "PATH";
        const char *env_p = getenv(name);
        if (env_p)
            [printf](../io/fprintf.html)("Your %s is %s\n", name, env_p);
    }

Possible output: 
    
    
    Your PATH is /home/gamer/.local/bin:/usr/local/bin:/usr/bin:/bin:/usr/share/games

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/getenv&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.22.4.6 The getenv function (p: TBD) 



    

  * K.3.6.2.1 The getenv_s function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.22.4.6 The getenv function (p: 256-257) 



    

  * K.3.6.2.1 The getenv_s function (p: 440-441) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.22.4.6 The getenv function (p: 352-353) 



    

  * K.3.6.2.1 The getenv_s function (p: 606-607) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.20.4.5 The getenv function (p: 317) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.10.4.4 The getenv function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/program/getenv&action=edit&section=6 "Edit section: See also")] See also

[C++ documentation](../../cpp/utility/program/getenv.html "cpp/utility/program/getenv") for getenv  
---  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/program/getenv&oldid=160652](https://en.cppreference.com/mwiki/index.php?title=c/program/getenv&oldid=160652)" 

From cppreference.com

< [c](../../../c.html "c")‎ | [string](../../string.html "c/string")‎ | [byte](../byte.html "c/string/byte")

[ C](../../../c.html "c")

[Compiler support](../../compiler_support.html "c/compiler support")  
---  
[Language](../../language.html "c/language")  
[Headers](../../header.html "c/header")  
[Type support](../../types.html "c/types")  
[Program utilities](../../program.html "c/program")  
[Variadic function support](../../variadic.html "c/variadic")  
[Error handling](../../error.html "c/error")  
[Dynamic memory management](../../memory.html "c/memory")  
[Strings library](../../string.html "c/string")  
[Algorithms](../../algorithm.html "c/algorithm")  
[Numerics](../../numeric.html "c/numeric")  
[Date and time utilities](../../chrono.html "c/chrono")  
[Input/output support](../../io.html "c/io")  
[Localization support](../../locale.html "c/locale")  
[Concurrency support](../../thread.html "c/thread") (C11)  
[Technical Specifications](../../experimental.html "c/experimental")  
[Symbol index](../../index.html "c/symbol index")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/navbar_content&action=edit)

[ Strings library](../../string.html "c/string")

[Null-terminated byte strings](../byte.html "c/string/byte")  
---  
[Null-terminated multibyte strings](../multibyte.html "c/string/multibyte")  
[Null-terminated wide strings](../wide.html "c/string/wide")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/navbar_content&action=edit)

[ Null-terminated byte strings](../byte.html "c/string/byte")

Functions  
---  
Character manipulation  
| [isalnum](isalnum.html "c/string/byte/isalnum")  
---  
[isalpha](isalpha.html "c/string/byte/isalpha")  
[islower](islower.html "c/string/byte/islower")  
[isupper](isupper.html "c/string/byte/isupper")  
[isdigit](isdigit.html "c/string/byte/isdigit")  
[isxdigit](isxdigit.html "c/string/byte/isxdigit")  
[isblank](isblank.html "c/string/byte/isblank")(C99)  
  
| [iscntrl](iscntrl.html "c/string/byte/iscntrl")  
---  
[isgraph](isgraph.html "c/string/byte/isgraph")  
[isspace](isspace.html "c/string/byte/isspace")  
[isprint](isprint.html "c/string/byte/isprint")  
[ispunct](ispunct.html "c/string/byte/ispunct")  
[tolower](tolower.html "c/string/byte/tolower")  
[toupper](toupper.html "c/string/byte/toupper")  
  
Conversions to and from numeric formats  
| [atoiatolatoll](atoi.html "c/string/byte/atoi")(C99)  
---  
[atof](atof.html "c/string/byte/atof")  
[strtolstrtoll](strtol.html "c/string/byte/strtol")(C99)  
[strtoulstrtoull](strtoul.html "c/string/byte/strtoul")(C99)  
  
| [strtoimaxstrtoumax](strtoimax.html "c/string/byte/strtoimax")(C99)(C99)  
---  
[strtofstrtodstrtold](strtof.html "c/string/byte/strtof")(C99)(C99)  
[strfromfstrfromdstrfroml](strfromf.html "c/string/byte/strfromf")(C23)(C23)(C23)  
  
String manipulation  
| [strcpystrcpy_s](strcpy.html "c/string/byte/strcpy")(C11)  
---  
[strncpystrncpy_s](strncpy.html "c/string/byte/strncpy")(C11)  
[strcatstrcat_s](strcat.html "c/string/byte/strcat")(C11)  
  
| [strncatstrncat_s](strncat.html "c/string/byte/strncat")(C11)  
---  
[strxfrm](strxfrm.html "c/string/byte/strxfrm")  
[strdup](strdup.html "c/string/byte/strdup")(C23)  
[strndup](strndup.html "c/string/byte/strndup")(C23)  
  
  
  
String examination  
| [strlenstrnlen_s](strlen.html "c/string/byte/strlen")(C11)  
---  
[strcmp](strcmp.html "c/string/byte/strcmp")  
[strncmp](strncmp.html "c/string/byte/strncmp")  
[strcoll](strcoll.html "c/string/byte/strcoll")  
[strchr](strchr.html "c/string/byte/strchr")  
[strrchr](strrchr.html "c/string/byte/strrchr")  
  
| [strspn](strspn.html "c/string/byte/strspn")  
---  
[strcspn](strcspn.html "c/string/byte/strcspn")  
[strpbrk](strpbrk.html "c/string/byte/strpbrk")  
[strstr](strstr.html "c/string/byte/strstr")  
[strtokstrtok_s](strtok.html "c/string/byte/strtok")(C11)  
  
  
  
Memory manipulation  
| [memchr](memchr.html "c/string/byte/memchr")  
---  
[memcmp](memcmp.html "c/string/byte/memcmp")  
[memsetmemset_explicitmemset_s](memset.html "c/string/byte/memset")(C23)(C11)  
  
| [memcpymemcpy_s](memcpy.html "c/string/byte/memcpy")(C11)  
---  
[memmovememmove_s](memmove.html "c/string/byte/memmove")(C11)  
[memccpy](memccpy.html "c/string/byte/memccpy")(C23)  
  
Miscellaneous  
**strerror strerror_sstrerrorlen_s**(C11)(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/navbar_content&action=edit)

Defined in header `[`<string.h>`](../../header/string.html "c/header/string")` |  |   
---|---|---  
char* strerror( int errnum ); |  (1)  |   
errno_t strerror_s( char *buf, rsize_t bufsz, errno_t errnum ); |  (2)  |  (since C11)  
[size_t](../../types/size_t.html) strerrorlen_s( errno_t errnum ); |  (3)  |  (since C11)  
| |   
  
1) Returns a pointer to the textual description of the system error code `errnum`, identical to the description that would be printed by [perror()](../../io/perror.html "c/io/perror").

`errnum` is usually acquired from the `errno` variable, however the function accepts any value of type int. The contents of the string are locale-specific.

The returned string must not be modified by the program, but may be overwritten by a subsequent call to the `strerror` function. `strerror` is not required to be thread-safe. Implementations may be returning different pointers to static read-only string literals or may be returning the same pointer over and over, pointing at a static buffer in which strerror places the string.

2) Same as (1), except that the message is copied into user-provided storage `buf`. No more than `bufsz-1` bytes are written, the buffer is always null-terminated. If the message had to be truncated to fit the buffer and `bufsz` is greater than 3, then only `bufsz-4` bytes are written, and the characters "..." are appended before the null terminator. In addition, the following errors are detected at runtime and call the currently installed [constraint handler](../../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * `buf` is a null pointer 
  * `bufsz` is zero or greater than RSIZE_MAX



The behavior is undefined if writing to `buf` occurs past the end of the array, which can happen when the size of the buffer pointed to by `buf` is less than the number of characters in the error message which in turn is less than `bufsz`.

3) Computes the length of the untruncated locale-specific error message that `strerror_s` would write if it were called with `errnum`. The length does not include the null terminator. 

    As with all bounds-checked functions, `strerror_s` and `strerrorlen_s` are only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<string.h>`](../../header/string.html "c/header/string").

## Contents

  * [1 Parameters](strerror.html#Parameters)
  * [2 Return value](strerror.html#Return_value)
  * [3 Notes](strerror.html#Notes)
  * [4 Example](strerror.html#Example)
  * [5 References](strerror.html#References)
  * [6 See also](strerror.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strerror&action=edit&section=1 "Edit section: Parameters")] Parameters

errnum  |  \-  |  integral value referring to an error code   
---|---|---  
buf  |  \-  |  pointer to a user-provided buffer   
bufsz  |  \-  |  size of the user-provided buffer   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strerror&action=edit&section=2 "Edit section: Return value")] Return value

1) Pointer to a null-terminated byte string corresponding to the [errno](../../error/errno.html "c/error/errno") error code `errnum`.

2) Zero if the entire message was successfully stored in `buf`, non-zero otherwise.

3) Length (not including the null terminator) of the message that `strerror_s` would return

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strerror&action=edit&section=3 "Edit section: Notes")] Notes

[POSIX](http://pubs.opengroup.org/onlinepubs/9699919799/functions/strerror.html) allows subsequent calls to `strerror` to invalidate the pointer value returned by an earlier call. It also specifies that it is the [`LC_MESSAGES`](../../locale/LC_categories.html "c/locale/LC categories") locale facet that controls the contents of these messages. 

`strerror_s` is the only bounds-checked function that allows truncation, because providing as much information as possible about a failure was deemed to be more desirable. POSIX also defines [`strerror_r`](http://pubs.opengroup.org/onlinepubs/9699919799/functions/strerror.html) for similar purposes. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strerror&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #define __STDC_WANT_LIB_EXT1__ 1
    #include <stdio.h>
    #include <errno.h>
    #include <string.h>
    #include <locale.h>
     
    int main(void)
    {
        [FILE](../../io/FILE.html) *fp = [fopen](../../io/fopen.html)([tmpnam](../../io/tmpnam.html)((char[[L_tmpnam](../../io.html)]){0}), "r");
        if(fp==[NULL](../../types/NULL.html)) {
            [printf](../../io/fprintf.html)("File opening error: %s\n", strerror(errno));
            [setlocale](../../locale/setlocale.html)(LC_MESSAGES, "de_DE.utf8");
            [printf](../../io/fprintf.html)("Now in German: %s\n", strerror(errno));
    #ifdef __STDC_LIB_EXT1__
            [setlocale](../../locale/setlocale.html)([LC_ALL](../../locale/LC_categories.html), "ja_JP.utf8"); // printf needs CTYPE for multibyte output
            [size_t](../../types/size_t.html) errmsglen = strerrorlen_s(errno) + 1;
            char errmsg[errmsglen]; 
            strerror_s(errmsg, errmsglen, errno);
            [printf](../../io/fprintf.html)("Now in Japanese: %s\n", errmsg);
    #endif
        }
    }

Possible output: 
    
    
    File opening error: No such file or directory
    Now in German: Datei oder Verzeichnis nicht gefunden
    Now in Japanese: そのようなファイル、又はディレクトリはありません

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strerror&action=edit&section=5 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.24.6.2 The strerror function (p: 371) 



    

  * K.3.7.4.2 The strerror_s function (p: 622) 



    

  * K.3.7.4.3 The strerrorlen_s function (p: 623) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.21.6.2 The strerror function (p: 334) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.11.6.2 The strerror function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strerror&action=edit&section=6 "Edit section: See also")] See also

[ perror](../../io/perror.html "c/io/perror") |  displays a character string corresponding of the current error to [stderr](../../io/std_streams.html "c/io/std streams")   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/io/dsc_perror&action=edit)  
---|---  
[ errno](../../error/errno.html "c/error/errno") |  macro which expands to POSIX-compatible thread-local error number variable  
(macro variable) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/error/dsc_errno&action=edit)  
[C++ documentation](../../../cpp/string/byte/strerror.html "cpp/string/byte/strerror") for strerror  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strerror&oldid=132557](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strerror&oldid=132557)" 

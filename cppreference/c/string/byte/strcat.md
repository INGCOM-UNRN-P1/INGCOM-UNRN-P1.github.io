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
**strcat strcat_s**(C11)  
  
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
[strerrorstrerror_sstrerrorlen_s](strerror.html "c/string/byte/strerror")(C11)(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/navbar_content&action=edit)

Defined in header `[`<string.h>`](../../header/string.html "c/header/string")` |  |   
---|---|---  
| (1) |   
char *strcat( char *dest, const char *src ); |  |  (until C99)  
char *strcat( char *restrict dest, const char *restrict src ); |  |  (since C99)  
errno_t strcat_s(char *restrict dest, rsize_t destsz, const char *restrict src); |  (2)  |  (since C11)  
| |   
  
1) Appends a copy of the null-terminated byte string pointed to by `src` to the end of the null-terminated byte string pointed to by `dest`. The character `src[0]` replaces the null terminator at the end of `dest`. The resulting byte string is null-terminated.

The behavior is undefined if the destination array is not large enough for the contents of both `src` and `dest` and the terminating null character. The behavior is undefined if the strings overlap. The behavior is undefined if either `dest` or `src` is not a pointer to a null-terminated byte string.

2) Same as (1), except that it may clobber the rest of the destination array (from the last character written to `destsz`) with unspecified values and that the following errors are detected at runtime and call the currently installed [constraint handler](../../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * `src` or `dest` is a null pointer 
  * `destsz` is zero or greater than RSIZE_MAX
  * there is no null terminator in the first `destsz` bytes of `dest`
  * truncation would occur (the available space at the end of `dest` would not fit every character, including the null terminator, of `src`) 
  * overlap would occur between the source and the destination strings



The behavior is undefined if the size of the character array pointed to by `dest` < [strlen](strlen.html)(dest)+[strlen](strlen.html)(src)+1 <= `destsz`; in other words, an erroneous value of `destsz` does not expose the impending buffer overflow. 

    As with all bounds-checked functions, `strcat_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<string.h>`](../../header/string.html "c/header/string").

## Contents

  * [1 Parameters](strcat.html#Parameters)
  * [2 Return value](strcat.html#Return_value)
  * [3 Notes](strcat.html#Notes)
  * [4 Example](strcat.html#Example)
  * [5 References](strcat.html#References)
  * [6 See also](strcat.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcat&action=edit&section=1 "Edit section: Parameters")] Parameters

dest  |  \-  |  pointer to the null-terminated byte string to append to   
---|---|---  
src  |  \-  |  pointer to the null-terminated byte string to copy from   
destsz  |  \-  |  maximum number of characters to write, typically the size of the destination buffer   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcat&action=edit&section=2 "Edit section: Return value")] Return value

1) returns a copy of `dest`

2) returns zero on success, returns non-zero on error. Also, on error, writes zero to dest[0] (unless `dest` is a null pointer or `destsz` is zero or greater than RSIZE_MAX).

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcat&action=edit&section=3 "Edit section: Notes")] Notes

Because `strcat` needs to seek to the end of `dest` on each call, it is inefficient to concatenate many strings into one using `strcat`. 

`strcat_s` is allowed to clobber the destination array from the last character written up to `destsz` in order to improve efficiency: it may copy in multibyte blocks and then check for null bytes. 

The function `strcat_s` is similar to the [BSD function `strlcat`](https://www.freebsd.org/cgi/man.cgi?query=strlcat&sektion=3), except that 

  * `strlcat` truncates the source string to fit in the destination 
  * `strlcat` does not perform all the runtime checks that `strcat_s` does 
  * `strlcat` does not make failures obvious by setting the destination to a null string or calling a handler if the call fails. 



Although `strcat_s` prohibits truncation due to potential security risks, it's possible to truncate a string using bounds-checked [strncat_s](strncat.html "c/string/byte/strncat") instead. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcat&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #define __STDC_WANT_LIB_EXT1__ 1
    #include <string.h> 
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void) 
    {
        char str[50] = "Hello ";
        char str2[50] = "World!";
        strcat(str, str2);
        strcat(str, " ...");
        strcat(str, " Goodbye World!");
        [puts](../../io/puts.html)(str);
     
    #ifdef __STDC_LIB_EXT1__
        set_constraint_handler_s(ignore_handler_s);
        int r = strcat_s(str, sizeof str, " ... ");
        [printf](../../io/fprintf.html)("str = \"%s\", r = %d\n", str, r);
        r = strcat_s(str, sizeof str, " and this is too much");
        [printf](../../io/fprintf.html)("str = \"%s\", r = %d\n", str, r);
    #endif
    }

Possible output: 
    
    
    Hello World! ... Goodbye World!
    str = "Hello World! ... Goodbye World! ... ", r = 0
    str = "", r = 22

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcat&action=edit&section=5 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.24.3.1 The strcat function (p: 364) 



    

  * K.3.7.2.1 The strcat_s function (p: 617-618) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.21.3.1 The strcat function (p: 327) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.11.3.1 The strcat function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcat&action=edit&section=6 "Edit section: See also")] See also

[ strncatstrncat_s](strncat.html "c/string/byte/strncat")(C11) |  concatenates a certain amount of characters of two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strncat&action=edit)  
---|---  
[ strcpystrcpy_s](strcpy.html "c/string/byte/strcpy")(C11) |  copies one string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcpy&action=edit)  
[ memccpy](memccpy.html "c/string/byte/memccpy")(C23) |  copies one buffer to another, stopping after the specified delimiter   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memccpy&action=edit)  
[C++ documentation](../../../cpp/string/byte/strcat.html "cpp/string/byte/strcat") for strcat  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcat&oldid=124078](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strcat&oldid=124078)" 

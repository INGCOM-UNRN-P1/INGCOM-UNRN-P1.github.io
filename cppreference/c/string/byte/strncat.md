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
  
| **strncat strncat_s**(C11)  
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
char *strncat( char *dest, const char *src, [size_t](../../types/size_t.html) count ); |  |  (until C99)  
char *strncat( char *restrict dest, const char *restrict src, [size_t](../../types/size_t.html) count ); |  |  (since C99)  
errno_t strncat_s( char *restrict dest, rsize_t destsz,  
const char *restrict src, rsize_t count ); |  (2)  |  (since C11)  
| |   
  
1) Appends at most `count` characters from the character array pointed to by `src`, stopping if the null character is found, to the end of the null-terminated byte string pointed to by `dest`. The character src[0] replaces the null terminator at the end of `dest`. The terminating null character is always appended in the end (so the maximum number of bytes the function may write is count+1).

The behavior is undefined if the destination array does not have enough space for the contents of both `dest` and the first `count` characters of `src`, plus the terminating null character. The behavior is undefined if the source and destination objects overlap. The behavior is undefined if either `dest` is not a pointer to a null-terminated byte string or `src` is not a pointer to a character array,

2) Same as (1), except that this function may clobber the remainder of the destination array (from the last byte written to `destsz`) and that the following errors are detected at runtime and call the currently installed [constraint handler](../../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * `src` or `dest` is a null pointer 
  * `destsz` or `count` is zero or greater than RSIZE_MAX
  * there is no null character in the first `destsz` bytes of `dest`
  * truncation would occur: `count` or the length of `src`, whichever is less, exceeds the space available between the null terminator of `dest` and `destsz`. 
  * overlap would occur between the source and the destination strings



The behavior is undefined if the size of the character array pointed to by `dest` < strnlen(dest,destsz)+strnlen(src,count)+1 < `destsz`; in other words, an erroneous value of `destsz` does not expose the impending buffer overflow. The behavior is undefined if the size of the character array pointed to by `src` < strnlen(src,count) < `destsz`; in other words, an erroneous value of `count` does not expose the impending buffer overflow. 

    As with all bounds-checked functions, `strncat_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<string.h>`](../../header/string.html "c/header/string").

## Contents

  * [1 Parameters](strncat.html#Parameters)
  * [2 Return value](strncat.html#Return_value)
  * [3 Notes](strncat.html#Notes)
  * [4 Example](strncat.html#Example)
  * [5 References](strncat.html#References)
  * [6 See also](strncat.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncat&action=edit&section=1 "Edit section: Parameters")] Parameters

dest  |  \-  |  pointer to the null-terminated byte string to append to   
---|---|---  
src  |  \-  |  pointer to the character array to copy from   
count  |  \-  |  maximum number of characters to copy   
destsz  |  \-  |  the size of the destination buffer   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncat&action=edit&section=2 "Edit section: Return value")] Return value

1) returns a copy of `dest`

2) returns zero on success, returns non-zero on error. Also, on error, writes zero to dest[0] (unless `dest` is a null pointer or `destsz` is zero or greater than RSIZE_MAX).

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncat&action=edit&section=3 "Edit section: Notes")] Notes

Because `strncat` needs to seek to the end of `dest` on each call, it is inefficient to concatenate many strings into one using `strncat`. 

Although truncation to fit the destination buffer is a security risk and therefore a runtime constraints violation for `strncat_s`, it is possible to get the truncating behavior by specifying `count` equal to the size of the destination array minus one: it will copy the first `count` bytes and append the null terminator as always: strncat_s(dst, sizeof dst, src, (sizeof dst)-strnlen_s(dst, sizeof dst)-1);

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncat&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #define __STDC_WANT_LIB_EXT1__ 1
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        char str[50] = "Hello ";
        char str2[50] = "World!";
        [strcat](strcat.html)(str, str2);
        strncat(str, " Goodbye World!", 3);
        [puts](../../io/puts.html)(str);
     
    #ifdef __STDC_LIB_EXT1__
        set_constraint_handler_s(ignore_handler_s);
        char s1[100] = "good";
        char s5[1000] = "bye";
        int r1 = strncat_s(s1, 100, s5, 1000); // r1 is 0, s1 holds "goodbye\0"
        [printf](../../io/fprintf.html)("s1 = %s, r1 = %d\n", s1, r1);
        char s2[6] = "hello";
        int r2 = strncat_s(s2, 6, "", 1); // r2 is 0, s2 holds "hello\0"
        [printf](../../io/fprintf.html)("s2 = %s, r2 = %d\n", s2, r2);
        char s3[6] = "hello";
        int r3 = strncat_s(s3, 6, "X", 2); // r3 is non-zero, s3 holds "\0"
        [printf](../../io/fprintf.html)("s3 = %s, r3 = %d\n", s3, r3);
        // the strncat_s truncation idiom:
        char s4[7] = "abc";
        int r4 = strncat_s(s4, 7, "defghijklmn", 3); // r4 is 0, s4 holds "abcdef\0"
        [printf](../../io/fprintf.html)("s4 = %s, r4 = %d\n", s4, r4);
    #endif
    }

Possible output: 
    
    
    Hello World! Go
    s1 = goodbye, r1 = 0
    s2 = hello, r2 = 0
    s3 = , r3 = 22
    s4 = abcdef, r4 = 0

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncat&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.26.3.2 The strncat function (p: 379) 



    

  * K.3.7.2.2 The strncat_s function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.24.3.2 The strncat function (p: 265-266) 



    

  * K.3.7.2.2 The strncat_s function (p: 449-450) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.24.3.2 The strncat function (p: 364-365) 



    

  * K.3.7.2.2 The strncat_s function (p: 618-620) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.21.3.2 The strncat function (p: 327-328) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.11.3.2 The strncat function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncat&action=edit&section=6 "Edit section: See also")] See also

[ strcatstrcat_s](strcat.html "c/string/byte/strcat")(C11) |  concatenates two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcat&action=edit)  
---|---  
[ strcpystrcpy_s](strcpy.html "c/string/byte/strcpy")(C11) |  copies one string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcpy&action=edit)  
[ memccpy](memccpy.html "c/string/byte/memccpy")(C23) |  copies one buffer to another, stopping after the specified delimiter   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memccpy&action=edit)  
[C++ documentation](../../../cpp/string/byte/strncat.html "cpp/string/byte/strncat") for strncat  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncat&oldid=145743](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncat&oldid=145743)" 

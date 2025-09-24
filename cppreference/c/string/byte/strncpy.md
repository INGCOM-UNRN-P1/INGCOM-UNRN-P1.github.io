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
**strncpy strncpy_s**(C11)  
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
[strerrorstrerror_sstrerrorlen_s](strerror.html "c/string/byte/strerror")(C11)(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/navbar_content&action=edit)

Defined in header `[`<string.h>`](../../header/string.html "c/header/string")` |  |   
---|---|---  
| (1) |   
char *strncpy( char *dest, const char *src, [size_t](../../types/size_t.html) count ); |  |  (until C99)  
char *strncpy( char *restrict dest, const char *restrict src, [size_t](../../types/size_t.html) count ); |  |  (since C99)  
errno_t strncpy_s( char *restrict dest, rsize_t destsz,  
const char *restrict src, rsize_t count ); |  (2)  |  (since C11)  
| |   
  
1) Copies at most `count` characters of the character array pointed to by `src` (including the terminating null character, but not any of the characters that follow the null character) to character array pointed to by `dest`. 

If `count` is reached before the entire array `src` was copied, the resulting character array is not null-terminated.

If, after copying the terminating null character from `src`, `count` is not reached, additional null characters are written to `dest` until the total of `count` characters have been written.

The behavior is undefined if the character arrays overlap, if either `dest` or `src` is not a pointer to a character array (including if `dest` or `src` is a null pointer), if the size of the array pointed to by `dest` is less than `count`, or if the size of the array pointed to by `src` is less than `count` and it does not contain a null character.

2) Same as (1), except that the function does not continue writing zeroes into the destination array to pad up to `count`, it stops after writing the terminating null character (if there was no null in the source, it writes one at dest[count] and then stops). Also, the following errors are detected at runtime and call the currently installed [constraint handler](../../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * `src` or `dest` is a null pointer 
  * `destsz` is zero or greater than RSIZE_MAX
  * `count` is greater than RSIZE_MAX
  * `count` is greater or equal `destsz`, but `destsz` is less or equal strnlen_s(src, count), in other words, truncation would occur 
  * overlap would occur between the source and the destination strings



The behavior is undefined if the size of the character array pointed to by `dest` < strnlen_s(src, destsz) <= `destsz`; in other words, an erroneous value of `destsz` does not expose the impending buffer overflow. The behavior is undefined if the size of the character array pointed to by `src` < strnlen_s(src, count) < `destsz`; in other words, an erroneous value of count may permit buffer overflow. 

    As with all bounds-checked functions, `strncpy_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<string.h>`](../../header/string.html "c/header/string").

## Contents

  * [1 Parameters](strncpy.html#Parameters)
  * [2 Return value](strncpy.html#Return_value)
  * [3 Notes](strncpy.html#Notes)
  * [4 Example](strncpy.html#Example)
  * [5 References](strncpy.html#References)
  * [6 See also](strncpy.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncpy&action=edit&section=1 "Edit section: Parameters")] Parameters

dest  |  \-  |  pointer to the character array to copy to   
---|---|---  
src  |  \-  |  pointer to the character array to copy from   
count  |  \-  |  maximum number of characters to copy   
destsz  |  \-  |  the size of the destination buffer   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncpy&action=edit&section=2 "Edit section: Return value")] Return value

1) returns a copy of `dest`

2) returns zero on success, returns non-zero on error. Also, on error, writes zero to dest[0] (unless `dest` is a null pointer or `destsz` is zero or greater than RSIZE_MAX) and may clobber the rest of the destination array with unspecified values.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncpy&action=edit&section=3 "Edit section: Notes")] Notes

As corrected by the post-C11 DR 468, `strncpy_s`, unlike [strcpy_s](strcpy.html "c/string/byte/strcpy"), is only allowed to clobber the remainder of the destination array if an error occurs. 

Unlike `strncpy`, `strncpy_s` does not pad the destination array with zeroes, This is a common source of errors when converting existing code to the bounds-checked version. 

Although truncation to fit the destination buffer is a security risk and therefore a runtime constraints violation for `strncpy_s`, it is possible to get the truncating behavior by specifying `count` equal to the size of the destination array minus one: it will copy the first `count` bytes and append the null terminator as always: strncpy_s(dst, sizeof dst, src, (sizeof dst)-1);

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncpy&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #define __STDC_WANT_LIB_EXT1__ 1
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <errno.h>
     
    int main(void)
    {
        char src[] = "hi";
        char dest[6] = "abcdef"; // no null terminator
        strncpy(dest, src, 5); // writes five characters 'h', 'i', '\0', '\0', '\0' to dest
        [printf](../../io/fprintf.html)("strncpy(dest, src, 5) to a 6-byte dest gives : ");
        for ([size_t](../../types/size_t.html) n = 0; n < sizeof dest; ++n) {
            char c = dest[n];
            c ? [printf](../../io/fprintf.html)("'%c' ", c) : [printf](../../io/fprintf.html)("'\\0' ");
        }
     
        [printf](../../io/fprintf.html)("\nstrncpy(dest2, src, 2) to a 2-byte dst gives : ");
        char dest2[2];
        strncpy(dest2, src, 2); // truncation: writes two characters 'h', 'i', to dest2
        for ([size_t](../../types/size_t.html) n = 0; n < sizeof dest2; ++n) {
            char c = dest2[n];
            c ? [printf](../../io/fprintf.html)("'%c' ", c) : [printf](../../io/fprintf.html)("'\\0' ");
        }
        [printf](../../io/fprintf.html)("\n");
     
    #ifdef __STDC_LIB_EXT1__
        set_constraint_handler_s(ignore_handler_s);
        char dst1[6], src1[100] = "hello";
        errno_t r1 = strncpy_s(dst1, 6, src1, 100);  // writes 0 to r1, 6 characters to dst1
        [printf](../../io/fprintf.html)("dst1 = \"%s\", r1 = %d\n", dst1,r1); // 'h','e','l','l','o','\0' to dst1
     
        char dst2[5], src2[7] = {'g','o','o','d','b','y','e'};
        errno_t r2 = strncpy_s(dst2, 5, src2, 7);    // copy overflows the destination array
        [printf](../../io/fprintf.html)("dst2 = \"%s\", r2 = %d\n", dst2,r2); // writes nonzero to r2,'\0' to dst2[0]
     
        char dst3[5];
        errno_t r3 = strncpy_s(dst3, 5, src2, 4);    // writes 0 to r3, 5 characters to dst3
        [printf](../../io/fprintf.html)("dst3 = \"%s\", r3 = %d\n", dst3,r3); // 'g', 'o', 'o', 'd', '\0' to dst3
    #endif
    }

Possible output: 
    
    
    strncpy(dest, src, 5) to a 6-byte dst gives : 'h' 'i' '\0' '\0' '\0' 'f'
    strncpy(dest2, src, 2) to a 2-byte dst gives : 'h' 'i'
    dst1 = "hello", r1 = 0
    dst2 = "", r2 = 22
    dst3 = "good", r3 = 0

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncpy&action=edit&section=5 "Edit section: References")] References

  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.24.2.4 The strncpy function (p: 265) 



    

  * K.3.7.1.4 The strncpy_s function (p: 447-448) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.24.2.4 The strncpy function (p: 363-364) 



    

  * K.3.7.1.4 The strncpy_s function (p: 616-617) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.21.2.4 The strncpy function (p: 326-327) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.11.2.4 The strncpy function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncpy&action=edit&section=6 "Edit section: See also")] See also

[ strcpystrcpy_s](strcpy.html "c/string/byte/strcpy")(C11) |  copies one string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcpy&action=edit)  
---|---  
[ memcpymemcpy_s](memcpy.html "c/string/byte/memcpy")(C11) |  copies one buffer to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memcpy&action=edit)  
[ strndup](../../experimental/dynamic/strndup.html "c/experimental/dynamic/strndup")(dynamic memory TR) |  allocate a copy of a string up to specified size   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/dsc_strndup&action=edit)  
[C++ documentation](../../../cpp/string/byte/strncpy.html "cpp/string/byte/strncpy") for strncpy  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncpy&oldid=183211](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strncpy&oldid=183211)" 

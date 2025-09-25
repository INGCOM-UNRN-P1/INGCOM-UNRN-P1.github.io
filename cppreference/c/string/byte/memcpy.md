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
  
| **memcpy memcpy_s**(C11)  
---  
[memmovememmove_s](memmove.html "c/string/byte/memmove")(C11)  
[memccpy](memccpy.html "c/string/byte/memccpy")(C23)  
  
Miscellaneous  
[strerrorstrerror_sstrerrorlen_s](strerror.html "c/string/byte/strerror")(C11)(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/navbar_content&action=edit)

Defined in header `[`<string.h>`](../../header/string.html "c/header/string")` |  |   
---|---|---  
| (1) |   
void* memcpy( void *dest, const void *src, [size_t](../../types/size_t.html) count ); |  |  (until C99)  
void* memcpy( void *restrict dest, const void *restrict src, [size_t](../../types/size_t.html) count ); |  |  (since C99)  
errno_t memcpy_s( void *restrict dest, rsize_t destsz,  
const void *restrict src, rsize_t count ); |  (2)  |  (since C11)  
| |   
  
1) Copies `count` characters from the object pointed to by `src` to the object pointed to by `dest`. Both objects are interpreted as arrays of unsigned char.

The behavior is undefined if access occurs beyond the end of the `dest` array. If the objects overlap (which is a violation of the [`restrict`](../../language/restrict.html "c/language/restrict") contract)(since C99), the behavior is undefined. The behavior is undefined if either `dest` or `src` is an invalid or null pointer.

2) Same as (1), except that the following errors are detected at runtime and cause the entire destination range [dest, dest+destsz) to be zeroed out (if both `dest` and `destsz` are valid), as well as call the currently installed [constraint handler](../../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * `dest` or `src` is a null pointer 
  * `destsz` or `count` is greater than RSIZE_MAX
  * `count` is greater than `destsz` (buffer overflow would occur) 
  * the source and the destination objects overlap



The behavior is undefined if the size of the character array pointed to by `dest` < `count` <= `destsz`; in other words, an erroneous value of `destsz` does not expose the impending buffer overflow. 

    As with all bounds-checked functions, `memcpy_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<string.h>`](../../header/string.html "c/header/string").

## Contents

  * [1 Parameters](memcpy.html#Parameters)
  * [2 Return value](memcpy.html#Return_value)
  * [3 Notes](memcpy.html#Notes)
  * [4 Example](memcpy.html#Example)
  * [5 References](memcpy.html#References)
  * [6 See also](memcpy.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcpy&action=edit&section=1 "Edit section: Parameters")] Parameters

dest  |  \-  |  pointer to the object to copy to   
---|---|---  
destsz  |  \-  |  max number of bytes to modify in the destination (typically the size of the destination object)   
src  |  \-  |  pointer to the object to copy from   
count  |  \-  |  number of bytes to copy   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcpy&action=edit&section=2 "Edit section: Return value")] Return value

1) Returns a copy of `dest`

2) Returns zero on success and non-zero value on error. Also on error, if `dest` is not a null pointer and `destsz` is valid, writes `destsz` zero bytes in to the destination array.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcpy&action=edit&section=3 "Edit section: Notes")] Notes

`memcpy` may be used to set the [effective type](../../language/object.html#Effective_type "c/language/object") of an object obtained by an allocation function. 

`memcpy` is the fastest library routine for memory-to-memory copy. It is usually more efficient than [strcpy](strcpy.html "c/string/byte/strcpy"), which must scan the data it copies or [memmove](memmove.html "c/string/byte/memmove"), which must take precautions to handle overlapping inputs. 

Several C compilers transform suitable memory-copying loops to `memcpy` calls. 

Where [strict aliasing](../../language/object.html#Strict_aliasing "c/language/object") prohibits examining the same memory as values of two different types, `memcpy` may be used to convert the values. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcpy&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #define __STDC_WANT_LIB_EXT1__ 1
    #include <stdio.h>
    #include <stdint.h>
    #include <inttypes.h>
    #include <string.h>
    #include <stdlib.h>
     
    int main(void)
    {
        // simple usage
        char source[] = "once upon a midnight dreary...", dest[4];
        memcpy(dest, source, sizeof dest);
        for([size_t](../../types/size_t.html) n = 0; n < sizeof dest; ++n)
            [putchar](../../io/putchar.html)(dest[n]);
     
        // setting effective type of allocated memory to be int
        int *p = [malloc](../../memory/malloc.html)(3*sizeof(int));   // allocated memory has no effective type
        int arr[3] = {1,2,3};
        memcpy(p,arr,3*sizeof(int));      // allocated memory now has an effective type
     
        // reinterpreting data
        double d = 0.1;
    //    int64_t n = *(int64_t*)(&d); // strict aliasing violation
        [int64_t](../../types/integer.html) n;
        memcpy(&n, &d, sizeof d); // OK
        [printf](../../io/fprintf.html)("\n%a is %" [PRIx64](../../types/integer.html) " as an int64_t\n", d, n);
     
    #ifdef __STDC_LIB_EXT1__
        set_constraint_handler_s(ignore_handler_s);
        char src[] = "aaaaaaaaaa";
        char dst[] = "xyxyxyxyxy";
        int r = memcpy_s(dst,sizeof dst,src,5);
        [printf](../../io/fprintf.html)("dst = \"%s\", r = %d\n", dst,r);
        r = memcpy_s(dst,5,src,10);            //  count is greater than destsz  
        [printf](../../io/fprintf.html)("dst = \"");
        for([size_t](../../types/size_t.html) ndx=0; ndx<sizeof dst; ++ndx) {
            char c = dst[ndx];
            c ? [printf](../../io/fprintf.html)("%c", c) : [printf](../../io/fprintf.html)("\\0");
        }
        [printf](../../io/fprintf.html)("\", r = %d\n", r);
    #endif
    }

Possible output: 
    
    
    once
    0x1.999999999999ap-4 is 3fb999999999999a as an int64_t
    dst = "aaaaayxyxy", r = 0
    dst = "\0\0\0\0\0yxyxy", r = 22

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcpy&action=edit&section=5 "Edit section: References")] References

  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.24.2.1 The memcpy function (p: 362) 



    

  * K.3.7.1.1 The memcpy_s function (p: 614) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.21.2.1 The memcpy function (p: 325) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.11.2.1 The memcpy function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcpy&action=edit&section=6 "Edit section: See also")] See also

[ memccpy](memccpy.html "c/string/byte/memccpy")(C23) |  copies one buffer to another, stopping after the specified delimiter   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memccpy&action=edit)  
---|---  
[ memmovememmove_s](memmove.html "c/string/byte/memmove")(C11) |  moves one buffer to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memmove&action=edit)  
[ wmemcpywmemcpy_s](../wide/wmemcpy.html "c/string/wide/wmemcpy")(C95)(C11) |  copies a certain amount of wide characters between two non-overlapping arrays   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wmemcpy&action=edit)  
[C++ documentation](../../../cpp/string/byte/memcpy.html "cpp/string/byte/memcpy") for memcpy  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcpy&oldid=123807](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memcpy&oldid=123807)" 

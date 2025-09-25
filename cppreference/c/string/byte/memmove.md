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
**memmove memmove_s**(C11)  
[memccpy](memccpy.html "c/string/byte/memccpy")(C23)  
  
Miscellaneous  
[strerrorstrerror_sstrerrorlen_s](strerror.html "c/string/byte/strerror")(C11)(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/navbar_content&action=edit)

Defined in header `[`<string.h>`](../../header/string.html "c/header/string")` |  |   
---|---|---  
void* memmove( void* dest, const void* src, [size_t](../../types/size_t.html) count ); |  (1)  |   
errno_t memmove_s(void* dest, rsize_t destsz, const void* src, rsize_t count); |  (2)  |  (since C11)  
| |   
  
1) Copies count characters from the object pointed to by src to the object pointed to by dest. Both objects are interpreted as arrays of unsigned char. The objects may overlap: copying takes place as if the characters were copied to a temporary character array and then the characters were copied from the array to dest.

The behavior is undefined if access occurs beyond the end of the dest array. The behavior is undefined if either dest or src is an invalid or null pointer.

2) Same as (1), except when detecting the following errors at runtime, it zeroes out the entire destination range [dest, dest + destsz) (if both dest and destsz are valid) and calls the currently installed [constraint handler](../../error/set_constraint_handler_s.html "c/error/set constraint handler s") function: 

    

  * dest or src is a null pointer 
  * destsz or count is greater than RSIZE_MAX
  * count is greater than destsz (buffer overflow would occur)



The behavior is undefined if the size of the character array pointed to by dest < count <= destsz; in other words, an erroneous value of destsz does not expose the impending buffer overflow. 

    As with all bounds-checked functions, `memmove_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<string.h>`](../../header/string.html "c/header/string").

## Contents

  * [1 Parameters](memmove.html#Parameters)
  * [2 Return value](memmove.html#Return_value)
  * [3 Notes](memmove.html#Notes)
  * [4 Example](memmove.html#Example)
  * [5 References](memmove.html#References)
  * [6 See also](memmove.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memmove&action=edit&section=1 "Edit section: Parameters")] Parameters

dest  |  \-  |  pointer to the object to copy to   
---|---|---  
destsz  |  \-  |  max number of bytes to modify in the destination (typically the size of the destination object)   
src  |  \-  |  pointer to the object to copy from   
count  |  \-  |  number of bytes to copy   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memmove&action=edit&section=2 "Edit section: Return value")] Return value

1) Returns a copy of dest

2) Returns zero on success and non-zero value on error. Also on error, if dest is not a null pointer and destsz is valid, writes destsz zero bytes in to the destination array.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memmove&action=edit&section=3 "Edit section: Notes")] Notes

`memmove` may be used to set the [effective type](../../language/object.html#Effective_type "c/language/object") of an object obtained by an allocation function. 

Despite being specified "as if" a temporary buffer is used, actual implementations of this function do not incur the overhead or double copying or extra memory. A common approach (glibc and bsd libc) is to copy bytes forwards from the beginning of the buffer if the destination starts before the source, and backwards from the end otherwise, with a fall back to the more efficient [memcpy](memcpy.html "c/string/byte/memcpy") when there is no overlap at all. 

Where [strict aliasing](../../language/object.html#Strict_aliasing "c/language/object") prohibits examining the same memory as values of two different types, `memmove` may be used to convert the values. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memmove&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #define __STDC_WANT_LIB_EXT1__ 1
    #include <inttypes.h>
    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
     
    int main(void)
    {
        char str[] = "1234567890";
        [puts](../../io/puts.html)(str);
        memmove(str + 4, str + 3, 3); // copy from [4,5,6] to [5,6,7]
        [puts](../../io/puts.html)(str);
     
        // setting effective type of allocated memory to be int
        int* p = [malloc](../../memory/malloc.html)(3 * sizeof(int)); // allocated memory has no effective type
        int arr[3] = {1, 2, 3};
        memmove(p, arr, 3 * sizeof(int)); // allocated memory now has an effective type
     
        // reinterpreting data
        double d = 0.1;
        // int64_t n = *(int64_t*)(&d); // strict aliasing violation
        [int64_t](../../types/integer.html) n;
        memmove(&n, &d, sizeof d); // OK
        [printf](../../io/fprintf.html)("%a is %" [PRIx64](../../types/integer.html) " as an int64_t\n", d, n);
     
    #ifdef __STDC_LIB_EXT1__
        set_constraint_handler_s(ignore_handler_s);
        char src[] = "aaaaaaaaaa";
        char dst[] = "xyxyxyxyxy";
        int r = memmove_s(dst, sizeof dst, src, 5);
        [printf](../../io/fprintf.html)("dst = \"%s\", r = %d\n", dst, r);
        r = memmove_s(dst, 5, src, 10); // count is greater than destsz
        [printf](../../io/fprintf.html)("dst = \"");
        for ([size_t](../../types/size_t.html) ndx = 0; ndx < sizeof dst; ++ndx)
        {
            char c = dst[ndx];
            c ? [printf](../../io/fprintf.html)("%c", c) : [printf](../../io/fprintf.html)("\\0");
        }
        [printf](../../io/fprintf.html)("\", r = %d\n", r);
    #endif
    }

Possible output: 
    
    
    1234567890
    1234456890
    0x1.999999999999ap-4 is 3fb999999999999a as an int64_t
    dst = "aaaaayxyxy", r = 0
    dst = "\0\0\0\0\0yxyxy", r = 22

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memmove&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.24.2.2 The memmove function (p: TBD) 



    

  * K.3.7.1.2 The memmove_s function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.24.2.2 The memmove function (p: 264) 



    

  * K.3.7.1.2 The memmove_s function (p: 446) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.24.2.2 The memmove function (p: 363) 



    

  * K.3.7.1.2 The memmove_s function (p: 615) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.21.2.2 The memmove function (p: 326) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.11.2.2 The memmove function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memmove&action=edit&section=6 "Edit section: See also")] See also

[ memcpymemcpy_s](memcpy.html "c/string/byte/memcpy")(C11) |  copies one buffer to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memcpy&action=edit)  
---|---  
[ wmemmovewmemmove_s](../wide/wmemmove.html "c/string/wide/wmemmove")(C95)(C11) |  copies a certain amount of wide characters between two, possibly overlapping, arrays   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wmemmove&action=edit)  
[C++ documentation](../../../cpp/string/byte/memmove.html "cpp/string/byte/memmove") for memmove  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memmove&oldid=178699](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memmove&oldid=178699)" 

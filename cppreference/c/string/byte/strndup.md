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
**strndup**(C23)  
  
  
  
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
char *strndup( const char *src, [size_t](../../types/size_t.html) size ); |  |  (since C23)  
| |   
  
Returns a pointer to a null-terminated byte string, which contains copies of at most `size` bytes from the string pointed to by `src`. The space for the new string is obtained as if [malloc](../../memory/malloc.html "c/memory/malloc") was called. If the null terminator is not encountered in the first `size` bytes, it is appended to the duplicated string. 

The returned pointer must be passed to [free](../../memory/free.html "c/memory/free") to avoid a memory leak. 

If an error occurs, a null pointer is returned and [errno](../../error/errno.html "c/error/errno") might be set. 

## Contents

  * [1 Parameters](strndup.html#Parameters)
  * [2 Return value](strndup.html#Return_value)
  * [3 Notes](strndup.html#Notes)
  * [4 Example](strndup.html#Example)
  * [5 See also](strndup.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strndup&action=edit&section=1 "Edit section: Parameters")] Parameters

src  |  \-  |  pointer to the null-terminated byte string to duplicate   
---|---|---  
size  |  \-  |  max number of bytes to copy from `src`  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strndup&action=edit&section=2 "Edit section: Return value")] Return value

A pointer to the newly allocated string, or a null pointer if an error occurred. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strndup&action=edit&section=3 "Edit section: Notes")] Notes

The function is identical to the [POSIX strndup](http://pubs.opengroup.org/onlinepubs/9699919799/functions/strdup.html) except that it is allowed, but not required to set [errno](../../error/errno.html "c/error/errno") on error. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strndup&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        const [size_t](../../types/size_t.html) n = 3;
     
        const char *src = "Replica";
        char *dup = strndup(src, n);
        [printf](../../io/fprintf.html)("strndup(\"%s\", %lu) == \"%s\"\n", src, n, dup);
        [free](../../memory/free.html)(dup);
     
        src = "Hi";
        dup = strndup(src, n);
        [printf](../../io/fprintf.html)("strndup(\"%s\", %lu) == \"%s\"\n", src, n, dup);
        [free](../../memory/free.html)(dup);
     
        const char arr[] = {'A','B','C','D'}; // NB: no trailing '\0'
        dup = strndup(arr, n);
        [printf](../../io/fprintf.html)("strndup({'A','B','C','D'}, %lu) == \"%s\"\n", n, dup);
        [free](../../memory/free.html)(dup);
    }

Output: 
    
    
    strndup("Replica", 3) == "Rep"
    strndup("Hi", 3) == "Hi"
    strndup({'A','B','C','D'}, 3) == "ABC"

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strndup&action=edit&section=5 "Edit section: See also")] See also

[ strdup](strdup.html "c/string/byte/strdup")(C23) |  allocates a copy of a string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strdup&action=edit)  
---|---  
[ strcpystrcpy_s](strcpy.html "c/string/byte/strcpy")(C11) |  copies one string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcpy&action=edit)  
[ malloc](../../memory/malloc.html "c/memory/malloc") |  allocates memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_malloc&action=edit)  
[ free](../../memory/free.html "c/memory/free") |  deallocates previously allocated memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_free&action=edit)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strndup&oldid=136178](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strndup&oldid=136178)" 

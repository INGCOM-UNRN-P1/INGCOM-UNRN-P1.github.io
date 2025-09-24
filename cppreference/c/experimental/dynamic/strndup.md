From cppreference.com

< [c](../../../c.html "c")‎ | [experimental](../../experimental.html "c/experimental")‎ | [dynamic](../dynamic.html "c/experimental/dynamic")

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

[ Technical Specifications](../../experimental.html "c/experimental")

[ Extensions for embedded processors](https://en.cppreference.com/mwiki/index.php?title=c/experimental/embedded&action=edit&redlink=1 "c/experimental/embedded \(page does not exist\)")  
---  
[ Dynamic memory extensions](../dynamic.html "c/experimental/dynamic")  
[ Floating-point extensions part 1: Binary floating-point](../fpext1.html "c/experimental/fpext1")  
[ Floating-point extensions part 4: Supplementary functions](../fpext4.html "c/experimental/fpext4")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/navbar_content&action=edit)

[ Dynamic memory extensions](../dynamic.html "c/experimental/dynamic")

[fmemopen](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/fmemopen&action=edit&redlink=1 "c/experimental/dynamic/fmemopen \(page does not exist\)")  
---  
[open_memstreamopen_wmemstream](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/open_memstream&action=edit&redlink=1 "c/experimental/dynamic/open memstream \(page does not exist\)")  
[asprintfaswprintfvasprintfvaswprintf](asprintf.html "c/experimental/dynamic/asprintf")  
[getlinegetwlinegetdelimgetwdelim](getline.html "c/experimental/dynamic/getline")  
[strdup](strdup.html "c/experimental/dynamic/strdup")  
**strndup**  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/navbar_content&action=edit)

![](https://upload.cppreference.com/mwiki/images/3/31/Imbox_notice.png) |  **Merged into ISO C** The functionality described on this page was merged into the mainline ISO C standard as of 6/2019, see [`strndup`](../../string/byte/strndup.html "c/string/byte/strndup") (since C23)  
---|---  
Defined in header `[`<string.h>`](../../header/string.html "c/header/string")` |  |   
---|---|---  
char *strndup( const char *str, [size_t](../../types/size_t.html) size ); |  |  (dynamic memory TR)  
| |   
  
Returns a pointer to a null-terminated byte string, which contains copies of at most `size` bytes from the string pointed to by `str`. If the null terminator is not encountered in the first `size` bytes, it is added to the duplicated string. 

The returned pointer must be passed to [free](../../memory/free.html "c/memory/free") to avoid a memory leak. 

If an error occurs, a null pointer is returned and [errno](../../error/errno.html "c/error/errno") may be set. 

As all functions from Dynamic Memory TR, `strndup` is only guaranteed to be available if __STDC_ALLOC_LIB__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT2__ to the integer constant 1 before including `string.h`. 

## Contents

  * [1 Parameters](strndup.html#Parameters)
  * [2 Return value](strndup.html#Return_value)
  * [3 Notes](strndup.html#Notes)
  * [4 Example](strndup.html#Example)
  * [5 See also](strndup.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/strndup&action=edit&section=1 "Edit section: Parameters")] Parameters

str  |  \-  |  pointer to the null-terminated byte string to duplicate   
---|---|---  
size  |  \-  |  max number of bytes to copy from `str`  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/strndup&action=edit&section=2 "Edit section: Return value")] Return value

A pointer to the newly allocated string, or a null pointer if an error occurred. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/strndup&action=edit&section=3 "Edit section: Notes")] Notes

The function is identical to the [POSIX strndup](http://pubs.opengroup.org/onlinepubs/9699919799/functions/strdup.html) except that it is allowed, but not required to set [errno](../../error/errno.html "c/error/errno") on error. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/strndup&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #ifdef __STDC_ALLOC_LIB__
    #define __STDC_WANT_LIB_EXT2__ 1
    #else
    #define _POSIX_C_SOURCE 200809L
    #endif
     
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
     
    int main(void)
    {
        const char *s1 = "String";
        char *s2 = strndup(s1, 2);
        [printf](../../io/fprintf.html)("strndup(\"String\", 2) == %s\n", s2);
        [free](../../memory/free.html)(s2);
    }

Output: 
    
    
    strndup("String", 2) == St

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/strndup&action=edit&section=5 "Edit section: See also")] See also

[ strdup](strdup.html "c/experimental/dynamic/strdup")(dynamic memory TR) |  allocate a copy of a string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/dsc_strdup&action=edit)  
---|---  
[ strncpystrncpy_s](../../string/byte/strncpy.html "c/string/byte/strncpy")(C11) |  copies a certain amount of characters from one string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strncpy&action=edit)  
[ malloc](../../memory/malloc.html "c/memory/malloc") |  allocates memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_malloc&action=edit)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/strndup&oldid=123997](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/strndup&oldid=123997)" 

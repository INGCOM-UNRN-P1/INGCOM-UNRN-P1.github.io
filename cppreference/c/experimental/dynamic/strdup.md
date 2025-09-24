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
**strdup**  
[strndup](strndup.html "c/experimental/dynamic/strndup")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/navbar_content&action=edit)

![](https://upload.cppreference.com/mwiki/images/3/31/Imbox_notice.png) |  **Merged into ISO C** The functionality described on this page was merged into the mainline ISO C standard as of 6/2019, see [`strdup`](../../string/byte/strdup.html "c/string/byte/strdup") (since C23)  
---|---  
Defined in header `[`<string.h>`](../../header/string.html "c/header/string")` |  |   
---|---|---  
char * strdup( const char *str1 ); |  |  (dynamic memory TR)  
| |   
  
Returns a pointer to a null-terminated byte string, which is a duplicate of the string pointed to by `str1`. The returned pointer must be passed to [free](../../memory/free.html "c/memory/free") to avoid a memory leak. 

If an error occurs, a null pointer is returned and [errno](../../error/errno.html "c/error/errno") may be set. 

As all functions from Dynamic Memory TR, `strdup` is only guaranteed to be available if __STDC_ALLOC_LIB__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT2__ to the integer constant 1 before including `string.h`. 

## Contents

  * [1 Parameters](strdup.html#Parameters)
  * [2 Return value](strdup.html#Return_value)
  * [3 Notes](strdup.html#Notes)
  * [4 Example](strdup.html#Example)
  * [5 See also](strdup.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/strdup&action=edit&section=1 "Edit section: Parameters")] Parameters

str1  |  \-  |  pointer to the null-terminated byte string to duplicate   
---|---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/strdup&action=edit&section=2 "Edit section: Return value")] Return value

A pointer to the newly allocated string, or a null pointer if an error occurred. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/strdup&action=edit&section=3 "Edit section: Notes")] Notes

The function is identical to the [POSIX strdup](http://pubs.opengroup.org/onlinepubs/9699919799/functions/strdup.html). 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/strdup&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #ifdef __STDC_ALLOC_LIB__
    #define __STDC_WANT_LIB_EXT2__ 1
    #else
    #define _POSIX_C_SOURCE 200809L
    #endif
     
    #include <string.h>
    #include <assert.h>
    #include <stdlib.h>
     
    int main(void)
    {
        const char *s1 = "String";
        char *s2 = strdup(s1);
        [assert](../../error/assert.html)([strcmp](../../string/byte/strcmp.html)(s1, s2) == 0);
        [free](../../memory/free.html)(s2);
    }

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/strdup&action=edit&section=5 "Edit section: See also")] See also

[ strndup](strndup.html "c/experimental/dynamic/strndup")(dynamic memory TR) |  allocate a copy of a string up to specified size   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/dsc_strndup&action=edit)  
---|---  
[ strcpystrcpy_s](../../string/byte/strcpy.html "c/string/byte/strcpy")(C11) |  copies one string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcpy&action=edit)  
[ malloc](../../memory/malloc.html "c/memory/malloc") |  allocates memory   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/memory/dsc_malloc&action=edit)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/strdup&oldid=123996](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/strdup&oldid=123996)" 

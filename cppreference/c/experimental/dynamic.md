From cppreference.com

< [c](../../c.html "c")‎ | [experimental](../experimental.html "c/experimental")

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

[ Technical Specifications](../experimental.html "c/experimental")

[ Extensions for embedded processors](https://en.cppreference.com/mwiki/index.php?title=c/experimental/embedded&action=edit&redlink=1 "c/experimental/embedded \(page does not exist\)")  
---  
**Dynamic memory extensions**  
[ Floating-point extensions part 1: Binary floating-point](fpext1.html "c/experimental/fpext1")  
[ Floating-point extensions part 4: Supplementary functions](fpext4.html "c/experimental/fpext4")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/navbar_content&action=edit)

**Dynamic memory extensions**

[fmemopen](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/fmemopen&action=edit&redlink=1 "c/experimental/dynamic/fmemopen \(page does not exist\)")  
---  
[open_memstreamopen_wmemstream](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/open_memstream&action=edit&redlink=1 "c/experimental/dynamic/open memstream \(page does not exist\)")  
[asprintfaswprintfvasprintfvaswprintf](dynamic/asprintf.html "c/experimental/dynamic/asprintf")  
[getlinegetwlinegetdelimgetwdelim](dynamic/getline.html "c/experimental/dynamic/getline")  
[strdup](dynamic/strdup.html "c/experimental/dynamic/strdup")  
[strndup](dynamic/strndup.html "c/experimental/dynamic/strndup")  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/navbar_content&action=edit)

Extensions to the C Library Part II: Dynamic Allocation Functions, ISO/IEC TR 24731-2:2010, defines the following new components for the C standard library: 

__STDC_ALLOC_LIB__ |  integer constant of type long indicating conformance level   
(macro constant)  
---|---  
Defined in header `[`<stdio.h>`](../header/stdio.html "c/header/stdio")`  
[ fmemopen](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/fmemopen&action=edit&redlink=1 "c/experimental/dynamic/fmemopen \(page does not exist\)")(dynamic memory TR) |  opens a fixed-size memory buffer as an I/O stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/dsc_fmemopen&action=edit)  
[ open_memstreamopen_wmemstream](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic/open_memstream&action=edit&redlink=1 "c/experimental/dynamic/open memstream \(page does not exist\)")(dynamic memory TR) |  opens a dynamically resized memory buffer as an I/O stream   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/dsc_open_memstream&action=edit)  
[ asprintfaswprintfvasprintfvaswprintf](dynamic/asprintf.html "c/experimental/dynamic/asprintf")(dynamic memory TR) |  variants of [sprintf](../io/fprintf.html "c/io/fprintf") etc that write to automatically-allocated buffer and return a pointer to it   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/dsc_asprintf&action=edit)  
[ getlinegetwlinegetdelimgetwdelim](dynamic/getline.html "c/experimental/dynamic/getline")(dynamic memory TR) |  read from a stream into an automatically resized buffer until delimiter/end of line   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/dsc_getline&action=edit)  
Defined in header `[`<string.h>`](../header/string.html "c/header/string")`  
[ strdup](dynamic/strdup.html "c/experimental/dynamic/strdup")(dynamic memory TR) |  allocate a copy of a string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/dsc_strdup&action=edit)  
[ strndup](dynamic/strndup.html "c/experimental/dynamic/strndup")(dynamic memory TR) |  allocate a copy of a string up to specified size   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/experimental/dynamic/dsc_strndup&action=edit)  
  
This library extension also introduces assignment-allocation character `**m**` for use with `**%s**`, `**%[**`, and `**%c**` conversion specifiers in [fscanf](../io/fscanf.html "c/io/fscanf") and [fwscanf](../io/fwscanf.html "c/io/fwscanf") family of functions. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic&action=edit&section=1 "Edit section: Notes")] Notes

The functions `fmemopen`, `open_memstream`, `open_wmemstream`, `getdelim`, `getline`, `strdup`, `strndup`, and the extensions to `fscanf` are available in [POSIX (ISO/IEC 9945:2003)](http://pubs.opengroup.org/onlinepubs/9699919799/). 

The functions `asprintf` and `vasprintf` are available in Linux Standard Base (ISO/IEC IS 23360:2006) 

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic&oldid=104628](https://en.cppreference.com/mwiki/index.php?title=c/experimental/dynamic&oldid=104628)" 

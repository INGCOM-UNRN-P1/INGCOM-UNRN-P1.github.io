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
**memccpy**(C23)  
  
Miscellaneous  
[strerrorstrerror_sstrerrorlen_s](strerror.html "c/string/byte/strerror")(C11)(C11)  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/navbar_content&action=edit)

Defined in header `[`<string.h>`](../../header/string.html "c/header/string")` |  |   
---|---|---  
void* memccpy( void* restrict dest, const void* restrict src, int c, [size_t](../../types/size_t.html) count ); |  |  (since C23)  
| |   
  
Copies bytes from the object pointed to by src to the object pointed to by dest, stopping after _any_ of the next two conditions are satisfied: 

    

  * count bytes are copied 
  * the byte (unsigned char)c is found (and copied). 



The src and dest objects are interpreted as arrays of unsigned char. 

The behavior is undefined if _any_ condition is met: 

    

  * access occurs beyond the end of the dest array; 
  * the objects overlap (which is a violation of the [`restrict`](../../language/restrict.html "c/language/restrict") contract) 
  * either dest or src is an invalid or null pointer 



## Contents

  * [1 Parameters](memccpy.html#Parameters)
  * [2 Return value](memccpy.html#Return_value)
  * [3 Notes](memccpy.html#Notes)
  * [4 Example](memccpy.html#Example)
  * [5 See also](memccpy.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memccpy&action=edit&section=1 "Edit section: Parameters")] Parameters

dest  |  \-  |  pointer to the object to copy to   
---|---|---  
src  |  \-  |  pointer to the object to copy from   
c  |  \-  |  terminating byte, converted to unsigned char at first   
count  |  \-  |  number of bytes to copy   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memccpy&action=edit&section=2 "Edit section: Return value")] Return value

If the byte (unsigned char)c was found, `memccpy` returns a pointer to the next byte in dest after (unsigned char)c. Otherwise it returns a null pointer. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memccpy&action=edit&section=3 "Edit section: Notes")] Notes

The function is identical to the [POSIX `memccpy`](https://pubs.opengroup.org/onlinepubs/9699919799/functions/memccpy.html). 

memccpy(dest, src, 0, count) behaves similar to [strncpy](strncpy.html)(dest, src, count), except that the former returns a pointer to the _end_ of the buffer written, and does not zero-pad the destination array. Thus, `memccpy` is useful for efficiently concatenating multiple strings. 
    
    
    char bigString[1000];
    char* end = bigString + sizeof bigString;
     
    char* p = memccpy(bigString, "John, ", '\0', sizeof bigString - 1);
    if (p)
        p = memccpy(p - 1, "Paul, ", '\0', end - p);
    if (p)
        p = memccpy(p - 1, "George, ", '\0', end - p);
    if (p)
        p = memccpy(p - 1, "Joel ", '\0', end - p);
    if (!p)
        end[-1] = '\0';
     
    [puts](../../io/puts.html)(bigString); // John, Paul, George, Joel

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memccpy&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #include <ctype.h>
    #include <stdio.h>
    #include <string.h>
     
    int main(void)
    {
        const char src[] = "Stars: Altair, Sun, Vega.";
        const char terminal[] = {':', ' ', ',', '.', '!'};
        char dest[sizeof src];
        const char alt = '@';
     
        for ([size_t](../../types/size_t.html) i = 0; i != sizeof terminal; ++i)
        {
            void* to = memccpy(dest, src, terminal[i], sizeof dest);
     
            [printf](../../io/fprintf.html)("Terminal '%c' (%s):\t\"", terminal[i], to ? "found" : "absent");
     
            // if `terminal` character was not found - print the whole `dest`
            to = to ? to : dest + sizeof dest;
     
            for (char* from = dest; from != to; ++from)
                [putchar](../../io/putchar.html)([isprint](isprint.html)(*from) ? *from : alt);
     
            [puts](../../io/puts.html)("\"");
        }
     
     
        [puts](../../io/puts.html)("\n" "Separate star names from distances (ly):");
        const char *star_distance[] = {
            "Arcturus : 37", "Vega : 25", "Capella : 43", "Rigel : 860", "Procyon : 11"
        };
        char names_only[64];
        char *first = names_only;
        char *last = names_only + sizeof names_only;
     
        for ([size_t](../../types/size_t.html) t = 0; t != (sizeof star_distance) / (sizeof star_distance[0]); ++t)
        {
            if (first)
                first = memccpy(first, star_distance[t], ' ', last - first);
            else
                break;
        }
     
        if (first)
        {
            *first = '\0';
            [puts](../../io/puts.html)(names_only);
        }
        else
            [puts](../../io/puts.html)("Buffer is too small.");
    }

Output: 
    
    
    Terminal ':' (found):   "Stars:"
    Terminal ' ' (found):   "Stars: "
    Terminal ',' (found):   "Stars: Altair,"
    Terminal '.' (found):   "Stars: Altair, Sun, Vega."
    Terminal '!' (absent):  "Stars: Altair, Sun, Vega.@"
     
    Separate star names from distances (ly):
    Arcturus Vega Capella Rigel Procyon

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memccpy&action=edit&section=5 "Edit section: See also")] See also

[ memcpymemcpy_s](memcpy.html "c/string/byte/memcpy")(C11) |  copies one buffer to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memcpy&action=edit)  
---|---  
[ wmemcpywmemcpy_s](../wide/wmemcpy.html "c/string/wide/wmemcpy")(C95)(C11) |  copies a certain amount of wide characters between two non-overlapping arrays   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wmemcpy&action=edit)  
[ memmovememmove_s](memmove.html "c/string/byte/memmove")(C11) |  moves one buffer to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_memmove&action=edit)  
[ strcpystrcpy_s](strcpy.html "c/string/byte/strcpy")(C11) |  copies one string to another   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcpy&action=edit)  
[ strcatstrcat_s](strcat.html "c/string/byte/strcat")(C11) |  concatenates two strings   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcat&action=edit)  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memccpy&oldid=159915](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/memccpy&oldid=159915)" 

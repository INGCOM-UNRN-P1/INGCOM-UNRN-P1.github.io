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
**strtok strtok_s**(C11)  
  
  
  
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
char* strtok( char* str, const char* delim ); |  | (until C99)  
char* strtok( char* restrict str, const char* restrict delim ); |  |  (since C99)  
char* strtok_s( char* restrict str, rsize_t* restrict strmax,  
const char* restrict delim, char** restrict ptr ); |  (2)  |  (since C11)  
| |   
  
Tokenizes a null-terminated byte string. 

1) A sequence of calls to `strtok` breaks the string pointed to by str into a sequence of tokens, each of which is delimited by a character from the string pointed to by delim. Each call in the sequence has a _search target ﻿_ : 

  * If str is non-null, the call is the _first call_ in the sequence. The search target is null-terminated byte string pointed to by str. 
  * If str is null, the call is one of the _subsequent calls_ in the sequence. The search target is determined by the previous call in the sequence.



Each call in the sequence searches the search target for the first character that is **not** contained in the _separator string_ pointed to by delim, the separator string can be different from call to call. 

  * If no such character is found, then there are no tokens in the search target. The search target for the next call in the sequence is unchanged.[[1]](strtok.html#cite_note-1)
  * If such a character is found, it is the start of the current token. `strtok` then searches from there for the first character that is contained in the separator string. 
    * If no such character is found, the current token extends to the end of search target. The search target for the next call in the sequence is an empty string.[[2]](strtok.html#cite_note-2)
    * If such a character is found, it is overwritten by a null character, which terminates the current token. The search target for the next call in the sequence starts from the following character.



If str or delim is not a pointer to a null-terminated byte string, the behavior is undefined.

2) Same as (1), except for the following differences: 

  * In each call, writes the number of characters left to see in str into *strmax and writes the tokenizer's internal state into *ptr. 
  * Subsequent calls in the sequence must pass strmax and ptr with the values stored by the previous call. 
  * The following errors are detected at runtime and call the currently installed [constraint handler](../../error/set_constraint_handler_s.html "c/error/set constraint handler s") function, without storing anything in the object pointed to by ptr: 
    * strmax, delim, or ptr is a null pointer. 
    * *ptr is a null pointer for a subsequent call in the sequence. 
    * *strmax is greater than RSIZE_MAX. 
    * The end of the token found does not occur within the first *s1max characters of the search target.



If both str points to a character array which lacks the null character and strmax points to a value which is greater than the size of that character array, the behavior is undefined.

As with all bounds-checked functions, `strtok_s` is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation and if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 before including [`<string.h>`](../../header/string.html "c/header/string").

  1. [↑](strtok.html#cite_ref-1) A token may still be formed in a subsequent call with a different separator string.
  2. [↑](strtok.html#cite_ref-2) No more tokens can be formed in subsequent calls.



## Contents

  * [1 Parameters](strtok.html#Parameters)
  * [2 Return value](strtok.html#Return_value)
  * [3 Note](strtok.html#Note)
  * [4 Example](strtok.html#Example)
  * [5 References](strtok.html#References)
  * [6 See also](strtok.html#See_also)

  
---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtok&action=edit&section=1 "Edit section: Parameters")] Parameters

str  |  \-  |  pointer to the null-terminated byte string to tokenize   
---|---|---  
delim  |  \-  |  pointer to the null-terminated byte string identifying delimiters   
strmax  |  \-  |  pointer to an object which initially holds the size of str: `strtok_s` stores the number of characters that remain to be examined   
ptr  |  \-  |  pointer to an object of type char*, which is used by `strtok_s` to store its internal state   
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtok&action=edit&section=2 "Edit section: Return value")] Return value

1) Returns a pointer to the first character of the next token, or a null pointer if there is no token.

2) Returns a pointer to the first character of the next token, or a null pointer if there is no token or there is a runtime-constraint violation.

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtok&action=edit&section=3 "Edit section: Note")] Note

This function is destructive: it writes the '\0' characters in the elements of the string str. In particular, a string literal cannot be used as the first argument of `strtok`. 

Each call to `strtok` modifies a static variable: is not thread safe. 

Unlike most other tokenizers, the delimiters in `strtok` can be different for each subsequent token, and can even depend on the contents of the previous tokens. 

The `strtok_s` function differs from the POSIX [`strtok_r`](https://pubs.opengroup.org/onlinepubs/9799919799/functions/strtok.html) function by guarding against storing outside of the string being tokenized, and by checking runtime constraints. The Microsoft CRT [`strtok_s`](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtok-s-strtok-s-l-wcstok-s-wcstok-s-l-mbstok-s-mbstok-s-l) signature matches this POSIX `strtok_r` definition, not the C11 `strtok_s`. 

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtok&action=edit&section=4 "Edit section: Example")] Example

Run this code
    
    
    #define __STDC_WANT_LIB_EXT1__ 1
    #include <stdio.h>
    #include <string.h>
     
    int main(void)
    {
        char input[] = "A bird came down the walk";
        [printf](../../io/fprintf.html)("Parsing the input string '%s'\n", input);
        char* token = strtok(input, " ");
        while (token)
        {
            [puts](../../io/puts.html)(token);
            token = strtok([NULL](../../types/NULL.html), " ");
        }
     
        [printf](../../io/fprintf.html)("Contents of the input string now: '");
        for ([size_t](../../types/size_t.html) n = 0; n < sizeof input; ++n)
            input[n] ? [putchar](../../io/putchar.html)(input[n]) : [fputs](../../io/fputs.html)("\\0", [stdout](../../io/std_streams.html));
        [puts](../../io/puts.html)("'");
     
    #ifdef __STDC_LIB_EXT1__
        char str[] = "A bird came down the walk";
        rsize_t strmax = sizeof str;
        const char* delim = " ";
        char* next_token;
        [printf](../../io/fprintf.html)("Parsing the input string '%s'\n", str);
        token = strtok_s(str, &strmax, delim, &next_token);
        while (token)
        {
            [puts](../../io/puts.html)(token);
            token = strtok_s([NULL](../../types/NULL.html), &strmax, delim, &next_token);
        }
     
        [printf](../../io/fprintf.html)("Contents of the input string now: '");
        for ([size_t](../../types/size_t.html) n = 0; n < sizeof str; ++n)
            str[n] ? [putchar](../../io/putchar.html)(str[n]) : [fputs](../../io/fputs.html)("\\0", [stdout](../../io/std_streams.html));
        [puts](../../io/puts.html)("'");
    #endif
    }

Possible output: 
    
    
    Parsing the input string 'A bird came down the walk'
    A
    bird
    came
    down
    the
    walk
    Contents of the input string now: 'A\0bird\0came\0down\0the\0walk\0'
    Parsing the input string 'A bird came down the walk'
    A
    bird
    came
    down
    the
    walk
    Contents of the input string now: 'A\0bird\0came\0down\0the\0walk\0'

### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtok&action=edit&section=5 "Edit section: References")] References

  * C23 standard (ISO/IEC 9899:2024): 



    

  * 7.24.5.8 The strtok function (p: TBD) 



    

  * K.3.7.3.1 The strtok_s function (p: TBD) 



  * C17 standard (ISO/IEC 9899:2018): 



    

  * 7.24.5.8 The strtok function (p: TBD) 



    

  * K.3.7.3.1 The strtok_s function (p: TBD) 



  * C11 standard (ISO/IEC 9899:2011): 



    

  * 7.24.5.8 The strtok function (p: 369-370) 



    

  * K.3.7.3.1 The strtok_s function (p: 620-621) 



  * C99 standard (ISO/IEC 9899:1999): 



    

  * 7.21.5.8 The strtok function (p: 332-333) 



  * C89/C90 standard (ISO/IEC 9899:1990): 



    

  * 4.11.5.8 The strtok function 



### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtok&action=edit&section=6 "Edit section: See also")] See also

[ strpbrk](strpbrk.html "c/string/byte/strpbrk") |  finds the first location of any character in one string, in another string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strpbrk&action=edit)  
---|---  
[ strcspn](strcspn.html "c/string/byte/strcspn") |  returns the length of the maximum initial segment that consists   
of only the characters not found in another byte string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strcspn&action=edit)  
[ strspn](strspn.html "c/string/byte/strspn") |  returns the length of the maximum initial segment that consists   
of only the characters found in another byte string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/byte/dsc_strspn&action=edit)  
[ wcstokwcstok_s](../wide/wcstok.html "c/string/wide/wcstok")(C95)(C11) |  finds the next token in a wide string   
(function) [[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/string/wide/dsc_wcstok&action=edit)  
[C++ documentation](../../../cpp/string/byte/strtok.html "cpp/string/byte/strtok") for strtok  
  
Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtok&oldid=180884](https://en.cppreference.com/mwiki/index.php?title=c/string/byte/strtok&oldid=180884)" 

From cppreference.com

< [c](../../c.html "c")‎ | [header](../header.html "c/header")

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

[ Standard Library headers ](../header.html "c/header")

| [`<assert.h>`](assert.html "c/header/assert")  
---  
[`<complex.h>`](complex.html "c/header/complex") (C99)  
[`<ctype.h>`](ctype.html "c/header/ctype")  
[`<errno.h>`](errno.html "c/header/errno")  
[`<fenv.h>`](fenv.html "c/header/fenv") (C99)  
[`<float.h>`](float.html "c/header/float")  
[`<inttypes.h>`](inttypes.html "c/header/inttypes") (C99)` `  
[`<iso646.h>`](iso646.html "c/header/iso646") (C95)  
[`<limits.h>`](limits.html "c/header/limits")  
[`<locale.h>`](locale.html "c/header/locale")  
[`<math.h>`](math.html "c/header/math")  
  
| [`<setjmp.h>`](setjmp.html "c/header/setjmp")  
---  
[`<signal.h>`](signal.html "c/header/signal")  
[`<stdalign.h>`](stdalign.html "c/header/stdalign") (C11*)  
[`<stdarg.h>`](stdarg.html "c/header/stdarg")  
[`<stdatomic.h>`](stdatomic.html "c/header/stdatomic") (C11)` `  
[`<stdbit.h>`](stdbit.html "c/header/stdbit") (C23)  
[`<stdbool.h>`](stdbool.html "c/header/stdbool") (C99*)  
[`<stdckdint.h>`](stdckdint.html "c/header/stdckdint") (C23)  
[`<stddef.h>`](stddef.html "c/header/stddef")  
[`<stdint.h>`](stdint.html "c/header/stdint") (C99)  
**`< stdio.h>`**  
  
| [`<stdlib.h>`](stdlib.html "c/header/stdlib")  
---  
[`<stdmchar.h>`](stdmchar.html "c/header/stdmchar") (C29)  
[`<stdnoreturn.h>`](stdnoreturn.html "c/header/stdnoreturn") (C11*)  
[`<string.h>`](string.html "c/header/string")  
[`<tgmath.h>`](tgmath.html "c/header/tgmath") (C99)  
[`<threads.h>`](threads.html "c/header/threads") (C11)  
[`<time.h>`](time.html "c/header/time")  
[`<uchar.h>`](uchar.html "c/header/uchar") (C11)  
[`<wchar.h>`](wchar.html "c/header/wchar") (C95)  
[`<wctype.h>`](wctype.html "c/header/wctype") (C95)  
  
  
  
[[edit]](https://en.cppreference.com/mwiki/index.php?title=Template:c/header/navbar_content&action=edit)

This header is part of [input/output](../io.html "c/io") library, providing generic file operation support and supplies I/O functions that work with narrow characters. 

| This section is incomplete  
Reason: 7.23 Input/output <stdio.h>; copy/share subset of [c/io](../io.html "c/io")  
---|---  
  
### [[edit](https://en.cppreference.com/mwiki/index.php?title=c/header/stdio&action=edit&section=1 "Edit section: Synopsis")] Synopsis
    
    
    #define __STDC_VERSION_STDIO_H__ 202311L
     
    typedef /* see description */ [FILE](../io/FILE.html);
    typedef /* see description */ [size_t](../types/size_t.html);
    typedef /* see description */ [FILE](../io/FILE.html);
    typedef /* see description */ [fpos_t](../io/fpos_t.html);
     
    #define NULL         /* see description */
    #define _IOFBF       /* see description */
    #define _IOLBF       /* see description */
    #define _IONBF       /* see description */
    #define BUFSIZ       /* see description */
    #define EOF          /* see description */
    #define FOPEN_MAX    /* see description */
    #define FILENAME_MAX /* see description */
    #define L_tmpnam     /* see description */
    #define SEEK_CUR     /* see description */
    #define SEEK_END     /* see description */
    #define SEEK_SET     /* see description */
    #define TMP_MAX      /* see description */
     
    #define stdin        /* see description */
    #define stdout       /* see description */
    #define stderr       /* see description */
     
    #define _PRINTF_NAN_LEN_MAX /* see description */
     
    int [remove](../io/remove.html)(const char* filename);
    int [rename](../io/rename.html)(const char* old, const char* new);
    [FILE](../io/FILE.html)* [tmpfile](../io/tmpfile.html)(void);
    char* [tmpnam](../io/tmpnam.html)(char* s);
    int [fclose](../io/fclose.html)([FILE](../io/FILE.html)* stream);
    int [fflush](../io/fflush.html)([FILE](../io/FILE.html)* stream);
    [FILE](../io/FILE.html)* [fopen](../io/fopen.html)(const char* restrict filename, const char* restrict mode);
    [FILE](../io/FILE.html)* [freopen](../io/freopen.html)(const char* restrict filename, const char* restrict mode,
    [FILE](../io/FILE.html)* restrict stream);
    void [setbuf](../io/setbuf.html)([FILE](../io/FILE.html)* restrict stream, char* restrict buf);
    int [setvbuf](../io/setvbuf.html)([FILE](../io/FILE.html)* restrict stream, char* restrict buf, int mode, [size_t](../types/size_t.html) size);
    int [printf](../io/fprintf.html)(const char* restrict format, ...);
    int [scanf](../io/fscanf.html)(const char* restrict format, ...);
    int [snprintf](../io/fprintf.html)(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format, ...);
    int [sprintf](../io/fprintf.html)(char* restrict s, const char* restrict format, ...);
    int [sscanf](../io/fscanf.html)(const char* restrict s, const char* restrict format, ...);
    int [vfprintf](../io/vfprintf.html)([FILE](../io/FILE.html)* restrict stream, const char* restrict format, va_list arg);
    int [vfscanf](../io/vfscanf.html)([FILE](../io/FILE.html)* restrict stream, const char* restrict format, va_list arg);
    int [vprintf](../io/vfprintf.html)(const char* restrict format, va_list arg);
    int [vscanf](../io/vfscanf.html)(const char* restrict format, va_list arg);
    int [vsnprintf](../io/vfprintf.html)(char* restrict s, [size_t](../types/size_t.html) n, const char* restrict format, va_list arg);
    int [vsprintf](../io/vfprintf.html)(char* restrict s, const char* restrict format, va_list arg);
    int [vsscanf](../io/vfscanf.html)(const char* restrict s, const char* restrict format, va_list arg);
    int [fgetc](../io/fgetc.html)([FILE](../io/FILE.html)* stream);
    char* [fgets](../io/fgets.html)(char* restrict s, int n, [FILE](../io/FILE.html)* restrict stream);
    int [fputc](../io/putc.html)(int c, [FILE](../io/FILE.html)* stream);
    int [fputs](../io/fputs.html)(const char* restrict s, [FILE](../io/FILE.html)* restrict stream);
    int [getc](../io/fgetc.html)([FILE](../io/FILE.html)* stream);
    int [getchar](../io/getchar.html)(void);
    int [putc](../io/putc.html)(int c, [FILE](../io/FILE.html)* stream);
    int [putchar](../io/putchar.html)(int c);
    int [puts](../io/puts.html)(const char* s);
    int [ungetc](../io/ungetc.html)(int c, [FILE](../io/FILE.html)* stream);
    [size_t](../types/size_t.html) [fread](../io/fread.html)(void* restrict ptr, [size_t](../types/size_t.html) size, [size_t](../types/size_t.html) nmemb,
    [FILE](../io/FILE.html)* restrict stream);
    [size_t](../types/size_t.html) [fwrite](../io/fwrite.html)(const void* restrict ptr, [size_t](../types/size_t.html) size, [size_t](../types/size_t.html) nmemb,
    [FILE](../io/FILE.html)* restrict stream);
    int [fgetpos](../io/fgetpos.html)([FILE](../io/FILE.html)* restrict stream, [fpos_t](../io/fpos_t.html)* restrict pos);
    int [fseek](../io/fseek.html)([FILE](../io/FILE.html)* stream, long int offset, int whence);
    int [fsetpos](../io/fsetpos.html)([FILE](../io/FILE.html)* stream, const [fpos_t](../io/fpos_t.html)* pos);
    long int [ftell](../io/ftell.html)([FILE](../io/FILE.html)* stream);
    void [rewind](../io/rewind.html)([FILE](../io/FILE.html)* stream);
    void [clearerr](../io/clearerr.html)([FILE](../io/FILE.html)* stream);
    int [feof](../io/feof.html)([FILE](../io/FILE.html)* stream);
    int [ferror](../io/ferror.html)([FILE](../io/FILE.html)* stream);
    void [perror](../io/perror.html)(const char* s);
    int [fprintf](../io/fprintf.html)([FILE](../io/FILE.html)* restrict stream, const char* restrict format, ...);
    int [fscanf](../io/fscanf.html)([FILE](../io/FILE.html)* restrict stream, const char* restrict format, ...);

Only if the implementation defines __STDC_LIB_EXT1__ and additionally the user code defines __STDC_WANT_LIB_EXT1__ before any inclusion of `<stdio.h>`: 
    
    
    #if defined(__STDC_WANT_LIB_EXT1__)
     
    #define L_tmpnam_s /* see description */
    #define TMP_MAX_S  /* see description */
     
    typedef /* see description */ errno_t;
    typedef /* see description */ rsize_t;
     
    errno_t tmpfile_s([FILE](../io/FILE.html)* restrict* restrict streamptr);
    errno_t tmpnam_s(char* s, rsize_t maxsize);
    errno_t fopen_s([FILE](../io/FILE.html)* restrict* restrict streamptr,
    const char* restrict filename, const char* restrict mode);
    errno_t freopen_s([FILE](../io/FILE.html)* restrict* restrict newstreamptr,
    const char* restrict filename, const char* restrict mode,
    [FILE](../io/FILE.html)* restrict stream);
    int fprintf_s([FILE](../io/FILE.html)* restrict stream, const char* restrict format, ...);
    int fscanf_s([FILE](../io/FILE.html)* restrict stream, const char* restrict format, ...);
    int printf_s(const char* restrict format, ...);
    int scanf_s(const char* restrict format, ...);
    int snprintf_s(char* restrict s, rsize_t n, const char* restrict format, ...);
    int sprintf_s(char* restrict s, rsize_t n, const char* restrict format, ...);
    int sscanf_s(const char* restrict s, const char* restrict format, ...);
    int vfprintf_s([FILE](../io/FILE.html)* restrict stream, const char* restrict format, va_list arg);
    int vfscanf_s([FILE](../io/FILE.html)* restrict stream, const char* restrict format, va_list arg);
    int vprintf_s(const char* restrict format, va_list arg);
    int vscanf_s(const char* restrict format, va_list arg);
    int vsnprintf_s(char* restrict s, rsize_t n, const char* restrict format, va_list arg);
    int vsprintf_s(char* restrict s, rsize_t n, const char* restrict format, va_list arg);
    int vsscanf_s(const char* restrict s, const char* restrict format, va_list arg);
    char* gets_s(char* s, rsize_t n);
    #endif

Retrieved from "[https://en.cppreference.com/mwiki/index.php?title=c/header/stdio&oldid=180214](https://en.cppreference.com/mwiki/index.php?title=c/header/stdio&oldid=180214)" 

[Category](https://en.cppreference.com/w/Special:Categories "Special:Categories"): 

  * [Todo with reason](../../Category%253ATodo_with_reason.html "Category:Todo with reason")



# Compilar con GCC
GNU Compiler Collection ([GCC](https://gcc.gnu.org/)) es una colección de compiladores, entre los cuales incluye al lenguaje de programación C.

Teniendo las siguientes líneas de código, en un archivo llamado `ejercicio1.c`.

```C
#include <stdio.h>

/*
 *  1. Hola Mundo
 *  Desarrollar un programa que muestre por STDOUT el mensaje "Hola Mundo C!".
 *  Indicar en un comentario la instrucción de compilación con GCC 
 *  por línea de comandos.
 */


int main()
{
    printf("Hola Mundo C!\n");
    return 0;
}
```

Para compilar el código, ejecutamos el siguiente comando:
```sh
$> gcc ejercicio1.c
```
De compilar correctamente, se genera un archivo ejecutable nombrado por defecto `a.out`.
Para dar un _nombre específico_, al archivo ejecutable, se usa la opción `-o`. Por ejemplo, si el archivo ejecutable tendrá el nombre de `ejercicio1`, el comando será:

```sh
$ gcc ejercicio1.c -o ejercicio1
```
Se recomienda, _**fuertemente**_, utilizar las verificaciones adicionales del compilador, las mismas se agregan al compilar:

```sh
$> gcc ejercicio1.c -Wall -Wextra -o ejercicio1
```
De esta manera, el compilador les avisará sobre situaciones que _potencialmente_ pueden ser problemáticas y no estrictamente un error.


Finalmente, para ejecutar el programa:
```sh
$ ./ejercicio1
"Hola Mundo C!"
```

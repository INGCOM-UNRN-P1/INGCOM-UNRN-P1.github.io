---
title: Cuestiones de estilo
short_title: 0x0000h - Estilo
subtitle: Pautas para la organización y prolijidad del código.
---

## Introducción

Este documento establece un conjunto de reglas de estilo, diseñadas para que su código en C sea más claro, legible y menos propenso a errores. La programación en C ofrece una gran flexibilidad, pero ello también facilita la adopción de malas prácticas que pueden conducir a errores de difícil detección. Por este motivo, la adhesión a un conjunto de reglas claras es fundamental para mantener el código ordenado y seguro.

La idea detrás de estas reglas es que un código de calidad no solo debe ser funcional, sino también comprensible para cualquier profesional que deba leerlo, ya sea vos mismo en el futuro o un colega que se incorpore al proyecto. Un código limpio y bien organizado facilita la colaboración, ahorra tiempo en la fase de corrección y previene complicaciones durante la depuración o actualización del software.

Estas reglas abarcan desde la nomenclatura de variables y funciones hasta la estructuración de condicionales y lazos. Su observancia no solo contribuye a la coherencia del proyecto, sino que también resulta en un código más robusto y mantenible a largo plazo.

Al comenzar, la aplicación de reglas estrictas en un lenguaje flexible como C te proporciona un marco sólido. A medida que tu comprensión del lenguaje se profundice, podés adaptar estas reglas para desarrollar un estilo propio.

## Apertura a Sugerencias y Debate

Estamos abiertos a debatir todas las reglas. Para ello, solo tenés que abrir un hilo en Discussions o un ticket en el Issue Tracker. Aceptamos propuestas de nuevas reglas, clasificaciones, explicaciones y potenciales excepciones.

## Principios Clave

- **Claridad:** El código debe ser fácil de leer.
- **Mantenibilidad:** Debe ser sencillo de modificar y extender.
- **Consistencia:** El uso de un estilo uniforme optimiza la colaboración.
- **Eficiencia:** Se debe optimizar el rendimiento sin sacrificar la legibilidad.

## Las Reglas

(En algún momento dejaremos)

(0x0000h)=
### Regla `0x0000h`: La claridad y prolijidad son de máxima importancia

El código debe ser claro y fácil de entender para cualquier lector, no solo para su autor. Un código limpio y prolijo previene errores, facilita el mantenimiento y mejora la colaboración en equipo. La claridad es siempre preferible a técnicas de programación ofuscadas que solo complican la comprensión.

```diff
- for (int i = 0, j = 10; i < j; i++, j--) { printf("%d", i+j); }
+ for (int i = 0; i < 10; i++)
+ {
+     int suma = i + (10 - i);
+     printf("%d", suma);
+ }
```

(0x0001h)=
### Regla `0x0001h`: Los identificadores deben ser descriptivos

Los nombres de variables, funciones y demás identificadores deben reflejar con precisión su propósito. Esto contribuye a que el código sea autodescriptivo, minimizando la necesidad de comentarios adicionales. El uso de nombres significativos facilita la lectura y la comprensión.

- Identificadores inadecuados:

```c
int a, b;
a = obtener_precio();
b = calcular_descuento(a);
```

- Identificadores adecuados:

```c
int precio, descuento;
precio = obtener_precio();
descuento = calcular_descuento(precio);
```

#### Sin embargo, no debés temer el uso de nombres de variables cortos

Bajo ciertas condiciones, los nombres cortos son aceptables y hasta preferibles:

1.  Si el ámbito de la variable es reducido (visible en una sola pantalla).
2.  Si la variable se utiliza con alta frecuencia en ese ámbito.
3.  Si existe un identificador de una o dos letras cuyo significado es obvio en el contexto (matemático, contadores, etc.).

Probá y observá si el nombre corto contribuye a la legibilidad. Es probable que así sea.

El ejemplo canónico es el uso de `i` y `j` como variables de control en lazos. Otras situaciones se presentan al implementar algoritmos matemáticos donde la notación es estándar.

(0x0002h)=
### Regla `0x0002h`: Una declaración de variable por línea

```diff
-int a, b, c;
+int a;
+int b;
+int c;
```

(0x0003h)=
### Regla `0x0003h`: Siempre debés inicializar las variables a un valor conocido

Es imperativo que una variable utilizada como R-Value contenga un valor conocido antes de su uso.

Aunque un sistema operativo moderno pueda inicializar la memoria en `0`, la reutilización de la misma puede introducir valores residuales. No debés confiar en una inicialización implícita.

- Incorrecto:

```c
int contador;
```

- Correcto:

```c
int contador = 0;
```

:::{note} Opciones de compilación

El compilador le advertirá sobre el uso de variables sin inicializar, pero solo si activás las verificaciones y mensajes adicionales correspondientes.

:::

#### Esto incluye evitar inicializaciones implícitas en estructuras.

- Incorrecto:

```c
struct Datos datos;
```

- Correcto:

```c
struct Datos datos = {0};
```

(0x0004h)=
### Regla `0x0004h`: Un espacio antes y después de cada operador binario

```diff
-uno=dos+tres;
+uno = dos + tres;
```

- **Incorrecto:**
  ```c
  resultado=valor1*valor2+offset;
  ```
- **Correcto:**
  ```c
  resultado = valor1 * valor2 + offset;
  ```

(0x0005h)=
### Regla `0x0005h`: Todas las estructuras de control deben utilizar llaves

Aunque las llaves son técnicamente opcionales para bloques de una sola línea, su uso es obligatorio para mantener la prolijidad y la consistencia. Además, se evita que futuras modificaciones al programa introduzcan comportamientos inesperados.

```c
if (condicion) {
    // Camino verdadero
} else {
    // Camino falso
}
```

Esto aplica incluso para bloques de una sola línea.

```diff
- if (condicion) accion;
+ if (condicion) {
+     accion;
+ }
```

- Incorrecto:
  ```c
  if (x > 0) x++;
  ```
- Correcto:
  ```c
  if (x > 0)
  {
      x++;
  }
  ```

Las llaves, a su vez, deben colocarse en una línea propia.

- Incorrecto:

```c
if (condicion) {
    accion();
}
```

- Correcto:

```c
if (condicion)
{
    accion();
}
```

(0x0006h)=
### Regla `0x0006h`: No utilizar `break` ni `continue`; en su lugar, empleá lazos con bandera

El uso de `break` y `continue` puede generar un flujo de control difícil de seguir. Es preferible utilizar una variable de control (bandera) para gestionar la terminación de los lazos de forma explícita y ordenada. Esto produce un código más predecible y mantenible.

- **Incorrecto (Uso de `break` y `continue`):**
```c
#include <stdio.h>

int main()
{
    printf("Ejemplo usando break y continue:\n");
    for (int i = 1; i <= 10; i++)
    {
        if (i == 4)
        {
            // Omite la iteración actual y salta a la siguiente
            continue;
        }
        if (i == 8)
        {
            // Sale del bucle completamente
            break;
        }
        printf("Número: %d\n", i);
    }
    return 0;
}
```

- **Correcto (Uso de bandera):**
```c
#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Ejemplo usando una bandera de control:\n");

    bool seguir_ejecutando = true; // La bandera para controlar el bucle
    int i = 1;

    while (i <= 10 && seguir_ejecutando)
    {
        if (i == 8)
        {
            // "Apagamos" la bandera para salir del bucle en
            // el inicio del siguiente lazo
            seguir_ejecutando = false;
        }
        else if (i != 4) // Y en lugar de 'continue', simplemente
                         //  no ejecutamos la acción
        {
            printf("Número: %d\n", i);
        }
        i++;
    }
    return 0;
}
```

(0x0007h)=
### Regla `0x0007h`: Preferí el uso de `while` en lugar de `for`

El lazo `while` ofrece mayor flexibilidad y es más adecuado cuando el número de iteraciones no se conoce de antemano. Generalmente, `while` resulta más legible si la condición de parada no es un simple contador. Para lazos de repetición indefinida o condicional, `while` es la estructura preferible.

- **Incorrecto (abuso de `for`):**

```c
#include <stdio.h>

int main()
{
    int numero;
    int suma = 0;

    printf("Ejemplo con 'for' (poco legible):\n");

    // Se fuerza la lectura del dato dentro de la declaración y el paso del 'for'.
    // Esto es confuso y rompe la claridad del código.
    for (printf("Ingrese un número (0 termina): "), scanf("%d", &numero); 
         numero != 0;
         printf("Ingrese un número (0 para terminar): "), scanf("%d", &numero))
    {
        suma = suma + numero;
    }

    printf("La suma total es: %d\n", suma);

    return 0;
}
```

- **Correcto (uso de `while`):**

```c
#include <stdio.h>

int main()
{
    int numero;
    int suma = 0;

    printf("Ejemplo con 'while' (preferido y claro):\n");
    printf("Ingrese un número (0 para terminar): ");
    scanf("%d", &numero);

    // La condición de parada es clara y está en un solo lugar.
    while (numero != 0)
    {
        suma = suma + numero;

        // Se pide el siguiente dato al final del bloque.
        printf("Ingrese un número (0 para terminar): ");
        scanf("%d", &numero);
    }

    printf("La suma total es: %d\n", suma);

    return 0;
}
```

(0x0008h)=
### Regla `0x0008h`: Cada función debe tener una única instrucción `return`

Limitar una función a un único punto de salida mejora la legibilidad y facilita el seguimiento del flujo de control. Adicionalmente, ayuda a prevenir errores relacionados con la liberación de recursos o la ejecución de código de limpieza.

- **Incorrecto (múltiples `return`):**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_FUNCIONO -1

// Mal ejemplo: Múltiples puntos de retorno complican la gestión de recursos.
int procesar_archivo_con_multiples_retornos(const char *nombre_archivo)
{
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL)
    {
        // Punto de salida 1: No hay recursos que liberar aún.
        return NO_FUNCIONO;
    }

    char *buffer = (char *)malloc(100);
    if (buffer == NULL)
    {
        // Punto de salida 2: Hay que recordar cerrar el archivo.
        fclose(archivo);
        return NO_FUNCIONO;
    }

    if (fread(buffer, 1, 99, archivo) < 1)
    {
        // Punto de salida 3: Hay que recordar liberar memoria Y cerrar el archivo.
        free(buffer);
        fclose(archivo);
        return NO_FUNCIONO;
    }

    printf("Archivo procesado correctamente.\n");

    // Punto de salida 4 (el caso exitoso): Limpieza completa.
    free(buffer);
    fclose(archivo);
    return 0;
}
```

- **Correcto (un solo `return`):**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_FUNCIONO -1

// Buen ejemplo: Un único punto de retorno facilita la legibilidad y la limpieza.
int procesar_archivo_con_un_retorno(const char *nombre_archivo)
{
    int valor_retorno = 0; // Asumimos éxito al principio
    FILE *archivo = NULL;
    char *buffer = NULL;

    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL)
    {
        valor_retorno = NO_FUNCIONO; // Marcamos el error
    }

    if (valor_retorno == 0)
    {
        buffer = (char *)malloc(100);
        if (buffer == NULL)
        {
            valor_retorno = NO_FUNCIONO; // Marcamos el error
        }
    }

    if (valor_retorno == 0)
    {
        if (fread(buffer, 1, 99, archivo) < 1)
        {
            valor_retorno = NO_FUNCIONO; // Marcamos el error
        }
    }

    if (valor_retorno == 0)
    {
        printf("Archivo procesado correctamente.\n");
    }

    // ---- BLOQUE DE LIMPIEZA CENTRALIZADO ----
    // Este bloque se ejecuta sin importar el resultado.
    if (buffer != NULL)
    {
        free(buffer);
    }
    if (archivo != NULL)
    {
        fclose(archivo);
    }

    return valor_retorno; // ÚNICO punto de salida de la función.
}
```

(0x0009h)=
### Regla `0x0009h`: Las funciones no deben contener `printf` o `scanf`, a menos que ese sea su propósito explícito

Las funciones deben desacoplarse de las operaciones de entrada y salida (I/O) para maximizar su reutilización y facilitar las pruebas unitarias. Si el propósito de una función no es realizar I/O, dichas llamadas deben ser delegadas a otras funciones especializadas.

- **Incorrecto:**
  ```c
  // La función mezcla la lógica de cálculo con la presentación (salida).
  // Esto la hace menos reutilizable y más difícil de probar.
  void calcular_e_imprimir_iva(float monto) {
      float iva = monto * 0.21;
      printf("El IVA es: %.2f\n", iva);
  }
  ```
- **Correcto:**
  ```c
  // La función tiene una única responsabilidad: calcular.
  float calcular_iva(float monto) {
      return monto * 0.21;
  }

  // Quien la llama decide qué hacer con el resultado (imprimirlo, guardarlo, etc.).
  int main() {
      float precio = 100.0;
      float iva = calcular_iva(precio);
      printf("El IVA de %.2f es: %.2f\n", precio, iva);
      return 0;
  }
  ```

(0x000Ah)=
### Regla `0x000Ah`: Todas las funciones deben incluir documentación completa y estructurada

El código no solo debe funcionar, sino que debe ser comprensible para otros programadores y para tu "yo" del futuro. Una documentación adecuada transforma una simple función en un componente reutilizable y fiable.

Al describir qué hace la función, qué datos necesita (`@param`) y qué resultado produce (`@returns`), se establece un "contrato" que define su comportamiento. Esto ahorra tiempo y reduce errores, ya que no es necesario descifrar la lógica interna cada vez que se utiliza la función.

El formato de documentación especificado, que utiliza etiquetas como `@param`, `@pre`, `@returns` y `@post`, sigue un estándar similar al de herramientas como Doxygen, capaces de generar manuales de referencia automáticamente. El objetivo es que estructures y pienses de manera explícita sobre las precondiciones y poscondiciones, un nivel de detalle crucial para construir software robusto.

Opcionalmente, podés especificar las invariantes con la etiqueta `@invariant`.

```c
/**
 * Descripción de la función.
 * @param parametro rol
 * @pre parametro
 * @returns caracteristicas del valor de retorno.
 * @post
 */
```

Ejemplo concreto


```c
/**
 * Calcula la suma de dos números enteros mediante incrementos o decrementos
 * sucesivos. Esta función simula la operación de suma utilizando únicamente
 * el operador de incremento (+1) o decremento (-1).
 *
 * @param sumando El primer término de la suma, que será la base para los
 *                incrementos.
 * @param sumador El segundo término, que determina la cantidad de incrementos
 *                o decrementos a realizar. Puede ser positivo, negativo o cero.
 *
 * @pre La suma resultante de 'sumando' y 'sumador' no debe causar un
 *      desbordamiento (overflow) del tipo 'int'.
 *
 * @returns Un entero que es el resultado de la suma de 'sumando' y 'sumador'.
 *
 * @post El valor retornado es matemáticamente equivalente a la operación
 *       'sumando + sumador'.
 */
int suma_lenta(int sumando, int sumador);
```

(0x000Bh)=
### Regla `0x000Bh`: No se permite el uso de variables globales

Las variables globales pueden ser modificadas desde cualquier parte del programa, lo que causa efectos secundarios impredecibles y dificulta el rastreo de errores. Su uso está prohibido.

- **Incorrecto:**
  ```c
  int contador_global = 0; // Variable global

  void incrementar_contador() {
      contador_global++; // Efecto secundario oculto y peligroso
  }

  void imprimir_valor() {
      // El comportamiento de esta función depende de un estado externo
      // y no documentado en sus parámetros.
      printf("Valor: %d\n", contador_global);
  }
  ```
- **Correcto:**
  ```c
  // La función recibe el estado que necesita como parámetro.
  int incrementar(int contador) {
      return contador + 1;
  }

  void imprimir_valor(int valor) {
      printf("Valor: %d\n", valor);
  }

  int main() {
      int contador_local = 0;
      contador_local = incrementar(contador_local);
      imprimir_valor(contador_local);
      return 0;
  }
  ```

(0x000Ch)=
### Regla `0x000Ch`: Cada función debe tener una única responsabilidad (Principio de Responsabilidad Única)

Cada función debe encargarse de una sola tarea. Esto mejora la legibilidad, la reutilización y el mantenimiento del código. Las funciones pequeñas y especializadas son más fáciles de probar y depurar.

- **Incorrecto:**
  ```c
  // Esta función tiene dos responsabilidades: encontrar el máximo y calcular la suma.
  int procesar_arreglo(const int arr[], size_t n, int *maximo) {
      int suma = 0;
      *maximo = arr[0];
      for (size_t i = 0; i < n; i++) {
          suma = suma + arr[i];
          if (arr[i] > *maximo) {
              *maximo = arr[i];
          }
      }
      return suma;
  }
  ```
- **Correcto:**
  ```c
  // Cada función tiene una única y clara responsabilidad.
  int calcular_suma(const int arr[], size_t n) {
      int suma = 0;
      for (size_t i = 0; i < n; i++) {
          suma += arr[i];
      }
      return suma;
  }

  int encontrar_maximo(const int arr[], size_t n) {
      int maximo = arr[0];
      for (size_t i = 1; i < n; i++) {
          if (arr[i] > maximo) {
              maximo = arr[i];
          }
      }
      return maximo;
  }
  ```

(0x000Dh)=
### Regla `0x000Dh`: Las condiciones complejas deben ser simplificadas o comentadas

Si una condición contiene múltiples operadores lógicos, considerá dividirla en partes más pequeñas o agregar comentarios que expliquen su lógica.

- **Incorrecto (difícil de leer):**
```c
if ((usuario_activo && tiene_permisos) || (es_admin && !modo_mantenimiento)) {
    // ...
}
```

- **Correcto (simplificado con variables booleanas):**
```c
// Explicar qué valida la condición completa
bool puede_acceder = usuario_activo && tiene_permisos;
bool es_admin_con_acceso = es_admin && !modo_mantenimiento;

if (puede_acceder || es_admin_con_acceso) {
    // ...
}
```

Sin embargo, si la expresión es excesivamente compleja, la mejor opción es refactorizarla en varias estructuras `if` anidadas o funciones auxiliares.

(0x000Eh)=
### Regla `0x000Eh`: Los arreglos estáticos deben ser creados con un tamaño fijo en tiempo de compilación

Los Arreglos de Longitud Variable (ALV) no están permitidos debido a los problemas de gestión de memoria que pueden ocasionar en la pila. Deben ser definidos con un tamaño constante.

```diff
- int n = 10;
- int numeros[n]; // ALV no permitido
+ #define TAMANO_NUMEROS 10
+ int numeros[TAMANO_NUMEROS];
```

(0x000Fh)=
### Regla `0x000Fh`: Una aserción por cada función de prueba

Podés lograr esto creando una función de prueba parametrizada que reciba los argumentos y el resultado esperado, o bien dedicando una función de prueba para cada caso específico.

- **Incorrecto (múltiples aserciones no relacionadas):**
  ```c
  void prueba_calculadora() {
      ASSERT_IGUAL(sumar(2, 2), 4); // Prueba de suma
      ASSERT_IGUAL(restar(5, 3), 2); // Prueba de resta en la misma función
  }
  ```
- **Correcto (una aserción por prueba):**
  ```c
  void prueba_suma_positivos() {
      ASSERT_IGUAL(sumar(2, 2), 4);
  }

  void prueba_resta_basica() {
      ASSERT_IGUAL(restar(5, 3), 2);
  }
  ```

(0x0010h)=
### Regla `0x0010h`: Evitá las condiciones ambiguas basadas en la "veracidad" (truthiness) del tipo de dato

Las comparaciones deben ser siempre explícitas. En C, cualquier valor numérico distinto de cero se considera **verdadero**, y el cero se considera **falso**. Depender de esta "veracidad" implícita (`truthiness`) atenta contra la legibilidad del código y, por lo tanto, no está permitido.

Una comparación explícita le indica al lector con qué tipo de dato está operando: contadores, caracteres, booleanos o punteros. Al observar una comprobación de veracidad, el primer paso es buscar la declaración de la variable para entender su tipo; una comparación explícita elimina esta ambigüedad.

Por ejemplo, si una variable numérica se usa como condición, siempre debés ser explícito:

```diff
- if (x) {
+ if (x != 0) {
```

Al evaluar una condición, esta debe ser únicamente el resultado de una operación de comparación.

```c
// Incorrecto - ¿Qué comprueban realmente estas expresiones?
if ( encendido );
return !caracter;
something( primero( xs ) );
while ( !trabajando );

// Correcto - Informativo y elimina la ambigüedad
if ( encendido > 0 );
return caracter == NULL;
something( primero( xs ) != '\0' );
while ( trabajando == false );
```

(0x0011h)=
### Regla `0x0011h`: Mantené el alcance de las variables al mínimo posible

Históricamente, C requería que todas las variables fueran declaradas al inicio de una función. Actualmente, esa limitación no existe, y podés y debés crear variables con el alcance más restringido posible.

- **Incorrecto (alcance demasiado amplio):**
  ```c
  void procesar() {
      int i; // Declarada al inicio de la función
      // ... mucho código ...
      for (i = 0; i < 10; i++) {
          // ...
      }
  }
  ```
- **Correcto (alcance mínimo):**
  ```c
  void procesar() {
      // ... mucho código ...
      for (int i = 0; i < 10; i++) { // 'i' solo existe dentro del lazo
          // ...
      }
  }
  ```

Al declarar `i` dentro de la cabecera del `for`, su alcance se limita exclusivamente a dicho lazo. Aplicá este principio siempre que sea posible.

(0x0012h)=
### Regla `0x0012h`: Los valores de retorno numéricos deben definirse como constantes de preprocesador

El uso de nombres descriptivos para los valores de retorno facilita la comprensión de su propósito.

```diff
-return -1;
+return ERROR_APERTURA_ARCHIVO;
```

```c
#define ERROR_APERTURA_ARCHIVO -1
```

(0x0013h)=
### Regla `0x0013h`: Cada bloque debe tener una indentación de cuatro espacios respecto a su contenedor

Esto permite una alineación consistente y mejora la legibilidad de la estructura del código.

- **Incorrecto (indentación inconsistente):**
  ```c
  void funcion() {
  int x = 10;
    if (x > 5) {
          printf("Mayor");
      }
  }
  ```
- **Correcto (indentación de 4 espacios):**
  ```c
  void funcion() {
      int x = 10;
      if (x > 5) {
          printf("Mayor");
      }
  }
  ```

(0x0014h)=
### Regla `0x0014h`: No utilizar la instrucción `goto`

El uso de `goto` rompe el flujo de control estructurado, dificultando la lectura y depuración del código. En su lugar, empleá las estructuras de control estándar (`if-else`, `for`, `while`, `switch`).

- **Incorrecto:**
  ```c
  void procesar_datos(int *datos, size_t n) {
      for (size_t i = 0; i < n; i++) {
          if (datos[i] < 0) {
              goto error;
          }
          // ...
      }
  error:
      printf("Error: dato negativo encontrado.\n");
  }
  ```
- **Correcto:**
  ```c
  bool procesar_datos(int *datos, size_t n) {
      bool exito = true;
      for (size_t i = 0; i < n && exito; i++) {
          if (datos[i] < 0) {
              exito = false;
          }
      }
      if (!exito) {
          printf("Error: dato negativo encontrado.\n");
      }
      return exito;
  }
  ```

(0x0015h)=
### Regla `0x0015h`: No utilizar el operador condicional (ternario) `?:`

Aunque compacto, el operador ternario puede reducir la legibilidad del código, especialmente en expresiones anidadas o complejas.

- **Incorrecto:**
  ```c
  int resultado = (a > b) ? a : b;
  ```
- **Correcto:**
  ```c
  int resultado;
  if (a > b) {
      resultado = a;
  } else {
      resultado = b;
  }
  ```

(0x0016h)=
### Regla `0x0016h`: Los ejercicios deben ser resueltos mediante funciones

Esta práctica fomenta la modularización, facilita las pruebas unitarias y promueve la reutilización del código. Dividir la lógica en funciones resulta en un código más organizado y comprensible.

- **Incorrecto (toda la lógica en `main`):**
  ```c
  int main() {
      int base = 10;
      int altura = 5;
      int area = base * altura;
      printf("El área es: %d\n", area);
      return 0;
  }
  ```
- **Correcto (lógica encapsulada en una función):**
  ```c
  int calcular_area(int base, int altura) {
      return base * altura;
  }

  int main() {
      int area = calcular_area(10, 5);
      printf("El área es: %d\n", area);
      return 0;
  }
  ```

(0x0017h)=
### Regla `0x0017h`: Los nombres de funciones y procedimientos deben usar `snake_case` en minúsculas

El uso de `snake_case` (palabras en minúsculas separadas por guiones bajos) para nombrar funciones y procedimientos es una convención que mejora la consistencia y legibilidad, permitiendo distinguir rápidamente entre los diferentes tipos de identificadores.

- **Incorrecto:**
  ```c
  void MiFuncionDeCalculo(int v); // PascalCase
  void otraFuncion(); // camelCase
  ```
- **Correcto:**
  ```c
  void mi_funcion_de_calculo(int valor);
  void otra_funcion();
  ```

(0x0018h)=
### Regla `0x0018h`: El asterisco de los punteros debe declararse junto al identificador

Esta convención facilita la identificación visual de una variable como puntero y mejora la claridad.

```diff
-int* ptr;
+int *ptr;
```

(0x0019h)=
### Regla `0x0019h`: Siempre verificá la asignación exitosa de memoria dinámica

Toda asignación con `malloc`, `calloc` o `realloc` debe ser seguida por una comprobación para asegurar que la memoria fue asignada correctamente.

```c
ptr = malloc(tamaño);
if (ptr == NULL)
{
    // Manejo de error
}
```

(0x001Ah)=
### Regla `0x001Ah`: Liberá siempre la memoria dinámica y prevení punteros colgantes

Por cada asignación de memoria dinámica, debe existir una correspondiente liberación con `free`. Después de liberar, asigná `NULL` al puntero para evitar punteros colgantes (`dangling pointers`).

```c
free(ptr);
ptr = NULL;
```

#### Simetría en la liberación de recursos

La liberación de memoria debe realizarse al mismo nivel de abstracción que su asignación. Si creaste una función `crear_recurso` para encapsular una asignación compleja, debés crear una función simétrica `liberar_recurso` para su liberación.

- **Ejemplo de simetría:**
  ```c
  recurso_t *crear_recurso() {
      recurso_t *r = malloc(sizeof(recurso_t));
      // ... inicialización ...
      return r;
  }

  void liberar_recurso(recurso_t *r) {
      // ... liberación de miembros internos ...
      free(r);
  }
  ```

(0x001Bh)=
### Regla `0x001Bh`: No mezcles operaciones de asignación y comparación en una sola línea

Mantener las asignaciones y comparaciones en líneas separadas previene errores sutiles y mejora la claridad.

```diff
- if ((ptr = malloc(tamaño)) == NULL) {
+ ptr = malloc(tamaño);
+ if (ptr == NULL) {
```

(0x001Ch)=
### Regla `0x001Ch`: Preferí `fgets` sobre `gets` y `scanf` para leer cadenas

`fgets` es más seguro, ya que previene desbordamientos de búfer al permitir especificar el tamaño máximo de lectura.

- **Incorrecto (inseguro):**
  ```c
  char buffer[50];
  scanf("%s", buffer); // Peligro de desbordamiento si la entrada > 49 chars
  ```
- **Correcto (seguro):**
  ```c
  char buffer[50];
  fgets(buffer, sizeof(buffer), stdin);
  ```

(0x001Dh)=
### Regla `0x001Dh`: Manejá correctamente la apertura y cierre de archivos

Siempre verificá que la apertura de un archivo con `fopen` haya sido exitosa y asegurate de cerrarlo con `fclose` después de su uso. Considerá el uso de `errno` para un manejo de errores más detallado.

```c

FILE *archivo = fopen("archivo.txt", "r");
if (archivo == NULL)
{
    // Manejo de error, ej: perror("Error al abrir archivo");
}
// ...
fclose(archivo);
```

(0x001Eh)=
### Regla `0x001Eh`: Utilizá `typedef` para definir tipos de estructuras

El uso de `typedef` para crear alias de tipos de estructuras facilita su manejo y mejora la legibilidad. Por convención, los nuevos tipos definidos con `typedef` deben llevar el sufijo `_t`.

- **Incorrecto:**
  ```c
  struct mi_estructura var; // Requiere 'struct' en cada declaración
  ```
- **Correcto:**
  ```c
  typedef struct {
      int campo1;
      char *campo2;
  } mi_estructura_t;

  mi_estructura_t var; // Más limpio y claro
  ```

(0x001Fh)=
### Regla `0x001Fh`: Minimizá el uso de múltiples niveles de indirección (punteros a punteros)

Los punteros a punteros (`**`) o niveles superiores de indirección complican la lectura, el razonamiento y el manejo de la memoria. Evitalos siempre que sea posible.

- **Incorrecto (innecesariamente complejo):**
  ```c
  void obtener_datos(int **ptr_datos, size_t *tamano) { /* ... */ }
  ```
- **Correcto (más simple, usando el valor de retorno):**
  ```c
  int *obtener_datos(size_t *tamano_out) { /* ... */ }
  ```

(0x0020h)=
### Regla `0x020Fh`: Documentá la propiedad de los recursos al utilizar punteros

Cuando una función recibe o devuelve un puntero a memoria dinámica, su documentación debe especificar claramente quién es el responsable de liberar dicha memoria (el "dueño" del puntero).

```c
/**
 * Crea un nuevo recurso.
 * @returns Un puntero al nuevo recurso. El llamador es responsable
 *          de liberar esta memoria con liberar_recurso().
 */
recurso_t *crear_recurso();

/**
 * Libera un recurso.
 * @param ptr Puntero al recurso a liberar. La memoria es liberada
 *            y el puntero no debe ser usado nuevamente.
 */
void liberar_recurso(recurso_t *ptr);
```

Recordá que en tiempo de ejecución no es posible diferenciar entre memoria dinámica y automática.

(0x0021h)=
### Regla `0x0021h`: Los argumentos de tipo puntero deben ser `const` siempre que la función no los modifique

Usar `const` en los parámetros de una función, especialmente con punteros, establece un **contrato** con quien la llama: "Te garantizo que no modificaré el dato al que apunta este argumento".

El compilador se encarga de hacer cumplir esta promesa. Si intentás modificar un dato a través de un puntero `const`, la compilación fallará. Esto previene **efectos secundarios** no deseados y hace que el comportamiento de la función sea más predecible.

**Ejemplo Correcto (Función de solo lectura):**

```c
#include <stdio.h>

// Correcto: La función solo necesita leer la cadena, no modificarla.
void imprimir_saludo(const char *nombre)
{
    // Si intentaras hacer esto, el compilador emitiría un error:
    // nombre[0] = 'J';
    printf("Hola, %s!\n", nombre);
}
```

**Ejemplo Válido (Función que modifica):**

En este caso, el propósito de la función es modificar el dato, por lo que **no se usa `const`**. El nombre de la función debe reflejar esta intención.

```c
#include <ctype.h>

// Correcto: El propósito es modificar la cadena, por lo que el parámetro
// NO debe ser 'const'.
void convertir_a_mayusculas(char *cadena)
{
    for (size_t i = 0; cadena[i] != '\0'; i++)
    {
        cadena[i] = toupper(cadena[i]);
    }
}
```


(0x0022h)=
### Regla `0x0022h`: Los punteros nulos deben ser inicializados como `NULL`, no `0`

Usa `NULL` para inicializar y verificar punteros, no `0`, para mayor claridad y
coherencia semántica.

```c
int *ptr = NULL;
if (ptr == NULL) {
    // ...
}
```

(0x0023h)=
### Regla `0x0023h`: Documentar explícitamente el uso de punteros nulos.

Cuando una función devuelve punteros, y estos pueden ser `NULL`, documentar en
que casos nos podemos encontrar con uno.

(0x0024h)=
### Regla `0x0024h`: Usar punteros con cast explícito al convertir tipos, evitando conversiones implícitas

Las conversiones de tipos deben ser claras y explícitas para evitar errores:

```c
void *mem = malloc(sizeof(int));
int *ptr = (int *) mem;  // Cast explícito
```

(0x0026h)=
### Regla `0x0025h`: Usar `sizeof` siempre en las asignaciones de memoria dinámica

Facilita la modificación y reduce errores al manejar estructuras y tipos
dinámicos:

```c
ptr = malloc(sizeof(*ptr));  // Asigna la cantidad correcta de memoria para el tipo de ptr
```

Ya que calculado manualmente puede ser fácilmente tener el tamaño equivocado y acarrear
problemas difíciles de detectar.

(0x0027h)=
### Regla `0x0027h`: Verificar siempre los límites de los arreglos antes de acceder a sus elementos

Evita accesos fuera de los límites del arreglo, esto es una de las fuentes más
comunes de errores en C:

```c
if (indice >= 0 && indice < tamaño_arreglo) {
    arreglo[indice] = valor;
}
```

En funciones, esto implica también, que es necesario pasar como argumento el
tamaño del arreglo.

:::{note} Strings

Esto incluye a las cadenas, y es obligatorio cuando la función modifica
posiciones de la misma.

:::

(0x0028h)=
### Regla `0x0028h`: Usar `enum` en lugar de números mágicos para estados y valores constantes

Mejora la legibilidad y reduce errores al manejar múltiples constantes:

```c
enum Estado { INACTIVO, ACTIVO, PAUSADO };
Estado estado = ACTIVO;
```

Esta regla es similar a [](#0x0012h), pero esta es más completa, ya que limita
los valores a los que están definidos en la enumeración.

(0x0029h)=
### Regla `0x0029h`: Documentar explícitamente el comportamiento de las funciones al manejar punteros nulos

Cuando una función acepta o devuelve un puntero nulo, el comportamiento debe
estar claramente documentado:

```c
/**
 * @param ptr Puntero que puede ser NULL.
 * @returns NULL si ocurre un error.
 * @returns ERROR_POR_NULO no se pudió seguir.
 */
```

Esto no implica un cambio en la estructura de la función, es una cuestión de
documentar la situación en la estructura que tenga la función.

(0x002Ah)=
### Regla `0x002Ah`: Liberar memoria en el orden inverso a su asignación

Esto es especialmente importante en programas complejos donde varias porciones
de memoria son asignadas en secuencia, como con matrices.

```c
free(ptr2);
free(ptr1);
```

(0x002Bh)=
### Regla `0x002Bh`: Nunca con más de 79 caracteres por línea

Nunca escribas líneas de más de 79 caracteres.

80 caracteres por línea es un estándar de facto para la visualización de código.
Los lectores de tu código que confían en ese estándar, y tienen su terminal o
editor dimensionado a 80 caracteres de ancho, pueden caber más en la pantalla
colocando ventanas una al lado de la otra.

Debes ceñirte a un máximo de 79 caracteres para que siempre haya un espacio en
la última columna. Esto hace más evidente que la línea no continúa en la
siguiente. También proporciona un margen derecho.

Si superas los 80 caracteres, estás haciendo que tu código sea
significativamente más difícil de leer para las personas que intentan confiar en
el estándar de 80 columnas. O bien la línea se enrolla, lo que dificulta la
lectura, o bien los lectores tienen que desplazar la ventana hacia la derecha
para leer los últimos caracteres. Cualquiera de estos dos resultados hace que el
código sea más difícil de leer que si hubieras resuelto un salto de línea tú
mismo.

Es más difícil leer líneas largas porque tus ojos tienen que desplazarse más
lejos para llegar al principio de la siguiente línea, y cuanto más lejos tengan
que ir, más probable es que tengas que reajustarte visualmente. Los estilos de
ancho 100 y 120 son más fáciles de escribir, pero más difíciles de leer.

Puede ser muy tentador dejar que una línea aquí o allá supere los 79 caracteres,
pero sus lectores pagarán el precio cada vez que tengan que leer una línea así.
Trate los 79 caracteres como un límite estricto, sin peros. Averigüe cuál es la
mejor manera de dividir las líneas largas y sus lectores se lo agradecerán.

En C, muchas instrucciones admiten estar en dos líneas, y otras necesitan del
carácter de continuación `\` para seguir en la línea siguiente.

Haga lo que hacen los demás, escriba para las 80 columnas y todos saldremos
ganando.

- [Emacs Wiki: Regla de las ochenta columnas](http://www.emacswiki.org/emacs/EightyColumnRule)
- [Programmers' Stack Exchange: ¿Sigue siendo relevante el límite de 80 caracteres?](http://programmers.stackexchange.com/questions/604/is-the-80-character-limit-still-relevant-in-times-of-widescreen-monitors)


(0x002Ch)=
### Regla `0x002Ch`: Desarrolla y compila siempre con todas las advertencias (y más) activadas.

No hay excusas. Desarrolla y compila siempre con las advertencias activadas.
Resulta, sin embargo, que `-Wall` y `-Wextra` en realidad no activan «todas» las
advertencias. Hay algunas otras que pueden ser realmente útiles:

```make
CFLAGS += -Wall -Wextra -Wpedantic \
          -Wformat=2 -Wno-unused-parameter -Wshadow \
          -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          -Wredundant-decls -Wnested-externs -Wmissing-include-dirs

# Warnings de GCC que Clang no proporciona:
ifeq ($(CC),gcc)
    CFLAGS += -Wjump-misses-init -Wlogical-op
endif
```

Compilar con las optimizaciones activadas también puede ayudar a detectar
errores:

```make
CFLAGS += -O2
```

(0x002Dh)=
### Regla `0x002Dh`: Utiliza guardas de inclusión

En todos los headers (`.h`) creados, para evitar la doble inclusión

[Include guards](https://en.wikipedia.org/wiki/Include_guard) permite incluir un
archivo header «dos veces» sin que se interrumpa la compilación.

```c
// Ejemplo de guarda
#ifndef INCLUDED_ALPHABET_H
#define INCLUDED_ALPHABET_H

...

#endif // ifndef INCLUDED_ALPHABET_H
```

El macro utilizado debe ser similar al del ejemplo, terminar con `_H` y
utilizar un nombre relacionado con el archivo que lo contiene.

[Rob Pike argumenta en contra de las protecciones de inclusión](http://www.lysator.liu.se/c/pikestyle.html),
diciendo que nunca se deben incluir archivos en archivos de inclusión. Dice que
las protecciones de inclusión «resultan en miles de líneas de código
innecesarias que pasan por el analizador léxico».

De hecho,
[GCC detectará los include guards](http://gcc.gnu.org/onlinedocs/cppinternals/Guard-Macros.html),
y no leerá tales ficheros una segunda vez. No sé si otros compiladores realizan
esta optimización.

No creo que sea una buena idea requerir a tus usuarios que incluyan las
dependencias de tus ficheros de cabecera. Las dependencias de tus archivos de
cabecera no deberían considerarse realmente «públicas». Aplicaría la regla «no
dependas de lo que incluyen tus ficheros de cabecera», pero se desmorona en
cuanto los ficheros de cabecera utilizan cosas que no necesitas, como `FILE` o
`bool`. Los usuarios no deberían preocuparse por eso si no lo necesitan.

Así que, escribe siempre «include guards», y haz la vida de tus usuarios más
fácil.

#### Comentarios al incluir un header no estandar

Los comentarios en los headers `#include`s de bibliotecas no estándar para
indicar qué símbolos usas de ellas.

Los espacios de nombres son uno de los grandes avances del desarrollo de
software. Por desgracia, C se lo perdió (los ámbitos no son espacios de
nombres). Pero, como los espacios de nombres son tan fantásticos, deberíamos
intentar simularlos con comentarios.

```c
#include <test.h> // Test, tests_run
#include "trie.h" // Trie, Trie_*
```

Esto ofrece algunas ventajas:

- los lectores no se ven obligados a consultar la documentación o utilizar
  `grep` para averiguar dónde está definido un símbolo (o, si no sigue la regla
  siguiente, de dónde procede): su código simplemente se lo dice
- los desarrolladores tienen la esperanza de poder determinar qué `#include`s se
  pueden eliminar y cuáles no
- los desarrolladores se ven forzados a considerar la contaminación del espacio
  de nombres (que de otro modo se ignora en la mayoría del código C), y les
  anima a proporcionar sólo cabeceras pequeñas y bien definidas

El inconveniente es que los comentarios `#include` no se comprueban ni se hacen
cumplir. He estado intentando escribir un comprobador para esto durante bastante
tiempo, pero por ahora, no hay nada que impida que los comentarios sean
erróneos - ya sea mencionando símbolos que ya no se usan, o no mencionando
símbolos que sí se usan. En tu proyecto, intenta cortar estos problemas de raíz,
para evitar que se extiendan. Siempre debes poder confiar en tu código. Este
mantenimiento es molesto, seguro, pero creo que los comentarios `#include`
merecen la pena en conjunto.

Encontrar de dónde vienen las cosas es siempre uno de mis principales retos
cuando aprendo una base de código. Podría ser mucho más fácil. Nunca he visto
ningún proyecto que escriba comentarios `#include` así, pero me encantaría que
se convirtiera en algo habitual.

#### `#include` la definición de todo lo que utilices.

No dependas de lo que incluyan tus cabeceras. Si tu código usa un símbolo,
incluye el fichero de cabecera donde ese símbolo está definido. Entonces, si tus
cabeceras cambian sus inclusiones, tu código no se romperá.

Además, combinado con la regla de comentario `#include` anterior, esto ahorra a
tus lectores y compañeros desarrolladores tener que seguir un rastro de
inclusiones solo para encontrar la definición de un símbolo que estás usando. Tu
código debería decirles de dónde viene.

#### Evitar las cabeceras unificadas

Las cabeceras unificadas son generalmente malas, porque liberan al desarrollador
de la biblioteca de la responsabilidad de proporcionar módulos sueltos
claramente separados por su propósito y abstracción. Incluso si el desarrollador
(piensa que) hace esto de todos modos, una cabecera unificada aumenta el tiempo
de compilación, y acopla el programa del usuario a toda la biblioteca,
independientemente de si la necesita. Hay muchas otras desventajas, mencionadas
en los puntos anteriores.

Hubo una buena exposición sobre las cabeceras unificadas en
[Programmers' Stack Exchange](http://programmers.stackexchange.com/questions/185773/library-design-provide-a-common-header-file-or-multiple-headers).
Una respuesta menciona que es razonable que algo como GTK+ sólo proporcione un
único archivo de cabecera. Estoy de acuerdo, pero creo que eso se debe al mal
diseño de GTK+, y no es intrínseco a un conjunto de herramientas gráficas.

Es más difícil para los usuarios escribir múltiples `#include`s al igual que es
más difícil para los usuarios escribir tipos. Traer dificultad a esto es
perderse el bosque por los árboles.

(0x002Eh)=
### Regla `0x002Eh`: Las variables que refieran al tamaño o posición de un arreglo deben ser `size_t`

El tipo `size_t` es el tipo de dato entero sin signo que devuelve el operador
`sizeof`. Está diseñado específicamente para representar el tamaño de cualquier
objeto en memoria, lo que lo convierte en la opción semánticamente correcta y
más segura para los índices y tamaños de los arreglos.

Usar `size_t` tiene varias ventajas:

- **Portabilidad**: Garantiza que la variable pueda contener el índice más
  grande posible para un arreglo en cualquier plataforma, algo que un `int` no
  siempre puede asegurar.
- **Claridad**: Comunica explícitamente que la variable representa un tamaño o
  un índice, que por naturaleza no pueden ser negativos.
- **Seguridad**: Evita advertencias y errores sutiles del compilador al comparar
  variables con signo (como `int`) con valores sin signo (como el resultado de
  `sizeof`).

**Ejemplo Correcto:**

```c
#include <stdio.h>
#include <stddef.h> // Necesario para size_t

// La función recibe el tamaño como 'size_t' y usa 'size_t' para el índice.
void imprimir_arreglo(const int arreglo[], size_t tamano)
{
    printf("Contenido del arreglo: ");
    for (size_t i = 0; i < tamano; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}
```

**Contraejemplo (Uso de `int`):**

```c
// Contraejemplo: Usar 'int' es menos robusto y puede generar advertencias.
void procesar_elementos(const int arreglo[], int tamano)
{
    // Si 'tamano' fuera muy grande en un sistema de 64 bits, un 'int'
    // podría no ser suficiente para almacenarlo, llevando a un desbordamiento.
    // Además, usar 'int' para 'i' puede causar advertencias de "signed/unsigned
    // mismatch" si se compara con el resultado de sizeof().
    for (int i = 0; i < tamano; i++)
    {
        // ...
    }
}
```

(0x002Fh)=
### Regla `0x002Fh`: Las variables declaradas como `const` van en `MAYUSCULAS`

Esta es una convención de estilo muy extendida que mejora drásticamente la
legibilidad. Cuando un identificador está en mayúsculas (`SNAKE_CASE`), actúa
como una señal visual inmediata para el programador, indicando que se trata de
un valor constante que no debe ser modificado durante la ejecución del programa.
Esto ayuda a diferenciar las constantes de las variables (que por convención
usan `snake_case` en minúsculas).

**Ejemplo Correcto:**

```c
// El uso de mayúsculas deja claro que son valores fijos.
const int DIAS_DE_LA_SEMANA = 7;
const float PI = 3.14159f;

float calcular_circunferencia(float radio)
{
    return 2 * PI * radio;
}
```

**Contraejemplo (Mala Práctica):**

```c
// Contraejemplo: Sintácticamente válido, pero rompe la convención de estilo.
// 'pi' y 'diasDeLaSemana' parecen variables normales, lo que puede llevar a
// confusiones o a intentos accidentales de modificarlas en otra parte del código.
const float pi = 3.14159f;
const int diasDeLaSemana = 7;
```


(0x0030h)=
### Regla `0x0030h`: Todas las cadenas en funciones deben ser seguras

(0x0031h)=
### Regla `0x0031h`: Los argumentos y variables van en `snake_case` minúscula


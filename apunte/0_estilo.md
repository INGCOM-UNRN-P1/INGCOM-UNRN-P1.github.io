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

(0x020Fh)=
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
### Regla `0x0022h`: Los punteros nulos deben ser inicializados y comparados con `NULL`, no con `0`

Utilizá la macro `NULL` para una mayor claridad y coherencia semántica al trabajar con punteros.

- **Incorrecto:**
  ```c
  int *ptr = 0;
  if (ptr == 0)
  {
    /* ... */
  }
  ```
- **Correcto:**
  ```c
  #include <stddef.h> // Para NULL
  int *ptr = NULL;
  if (ptr == NULL)
  {
    // ...
  }
  ```

(0x0023h)=
### Regla `0x0023h`: Documentá explícitamente los casos en que una función puede retornar `NULL`

Si una función que devuelve un puntero puede retornar `NULL` (por ejemplo, en caso de error), esta posibilidad debe estar claramente documentada.

```c
/**
 * Busca un usuario por ID.
 * @param id El ID del usuario a buscar.
 * @returns Un puntero al usuario si se encuentra, o NULL si no existe
 *          o si ocurre un error de memoria.
 */
usuario_t *buscar_usuario(int id);
```

(0x0024h)=
### Regla `0x0024h`: Utilizá `cast` explícito al convertir tipos de punteros

Las conversiones de tipos de punteros deben ser siempre explícitas para evitar errores y mejorar la claridad.

```c
void *mem = malloc(sizeof(int));
if (mem != NULL) {
    int *ptr = (int *)mem;  // Cast explícito
    // ...
}
```

(0x0026h)=
### Regla `0x0026h`: Usá siempre `sizeof` en las asignaciones de memoria dinámica

El uso de `sizeof` en lugar de tamaños codificados manualmente (`hardcoded`) reduce errores y facilita el mantenimiento. Es preferible usar `sizeof(*puntero)` en lugar de `sizeof(tipo)`.

- **Incorrecto:**
  ```c
  // Peligroso: si el tipo de 'ptr' cambia, este código fallará.
  int *ptr = malloc(4); 
  ```
- **Correcto:**
  ```c
  // Asigna la cantidad correcta de memoria para el tipo al que apunta ptr.
  int *ptr = malloc(sizeof(*ptr));
  ```

(0x0027h)=
### Regla `0x0027h`: Verificá siempre los límites de los arreglos antes de acceder a sus elementos

El acceso fuera de los límites de un arreglo (`out-of-bounds`) es una de las fuentes más comunes de errores y vulnerabilidades en C. Siempre debés validar los índices.

- **Incorrecto (acceso fuera de límites):**
  ```c
  int arreglo[10];
  arreglo[10] = 5; // Error: el último índice válido es 9.
  ```
- **Correcto:**
  ```c
  int arreglo[10];
  int indice = 9;
  if (indice >= 0 && indice < 10) {
      arreglo[indice] = 5;
  }
  ```

En funciones, esto implica que el tamaño del arreglo debe ser pasado como argumento.

:::{note} Cadenas de caracteres

Esta regla es especialmente crítica para las cadenas de caracteres, y su cumplimiento es obligatorio cuando una función modifica el contenido de una.

:::

(0x0028h)=
### Regla `0x0028h`: Utilizá `enum` en lugar de "números mágicos" para conjuntos de estados y valores constantes

El uso de enumeraciones (`enum`) mejora la legibilidad y previene errores al manejar conjuntos de constantes _relacionadas_.

- **Incorrecto (números mágicos):**
  ```c
  // ¿Qué significan 0, 1 y 2?
  void procesar_estado(int estado) {
      if (estado == 0) { /* ... */ }
  }
  ```
- **Correcto:**
  ```c
  typedef enum {
      ESTADO_INACTIVO,
      ESTADO_ACTIVO,
      ESTADO_PAUSADO
  } estado_t;

  void procesar_estado(estado_t estado) {
      if (estado == ESTADO_ACTIVO) { /* ... */ }
  }
  ```

(0x0029h)=
### Regla `0x0029h`: Documentá explícitamente el comportamiento de las funciones al manejar punteros nulos como argumentos

Cuando una función acepta un puntero que puede ser `NULL`, su comportamiento ante este caso debe estar claramente documentado.

```c
/**
 * Calcula la longitud de una cadena.
 * @param ptr Puntero a la cadena. Si es NULL, el comportamiento es indefinido
 *            y la función no debe ser llamada con un puntero nulo.
 * @pre ptr no debe ser NULL.
 * @returns La longitud de la cadena.
 */
size_t calcular_longitud(const char *ptr);
```

(0x002Ah)=
### Regla `0x002Ah`: Liberá la memoria en el orden inverso a su asignación

Este principio es especialmente importante en estructuras de datos complejas (como matrices 2D o listas enlazadas) para evitar dejar memoria huérfana.

```c
// Ejemplo para una matriz 2D
for (size_t i = 0; i < filas; i++) {
    free(matriz[i]); // Libera cada fila
}
free(matriz); // Libera el arreglo de punteros
```

(0x002Bh)=
### Regla `0x002Bh`: Las líneas de código no deben exceder los 79 caracteres

Nunca debés escribir líneas que excedan los 79 caracteres. El límite de 80 columnas es un estándar de facto que facilita la lectura y la visualización de código en paralelo.

Si superás este límite, dificultás la lectura para otros. La línea se cortará de forma impredecible o requerirá desplazamiento horizontal, ambos escenarios perjudiciales para la comprensión. Las líneas largas, además, fatigan la vista.

Considerá los 79 caracteres como un límite estricto. Determiná cuál es la forma óptima de dividir las líneas extensas; tus lectores lo agradecerán. En C, muchas instrucciones pueden dividirse en varias líneas de forma natural.

- **Incorrecto:**
  ```c
  printf("Este es un mensaje de registro extremadamente largo que definitivamente excede el límite de 79 caracteres y hace que el código sea mucho más difícil de leer para otros desarrolladores.\n");
  ```
- **Correcto:**
  ```c
  printf("Este es un mensaje de registro extremadamente largo que se divide "
         "en múltiples líneas para cumplir con el estándar de 80 columnas.\n");
  ```

Adoptá la práctica estándar: escribí para 80 columnas, y el beneficio será para todos.

- [Emacs Wiki: Regla de las ochenta columnas](http://www.emacswiki.org/emacs/EightyColumnRule)
- [Programmers' Stack Exchange: ¿Sigue siendo relevante el límite de 80 caracteres?](http://programmers.stackexchange.com/questions/604/is-the-80-character-limit-still-relevant-in-times-of-widescreen-monitors)

(0x002Ch)=
### Regla `0x002Ch`: Desarrollá y compilá siempre con todas las advertencias del compilador activadas

No hay excusas. Desarrollá y compilá siempre con el máximo nivel de advertencias posible. Las opciones `-Wall` y `-Wextra` no activan *todas* las advertencias útiles. Considerá el siguiente conjunto para `gcc` o `clang`:

```make
CFLAGS += -Wall -Wextra -Wpedantic \
          -Wformat=2 -Wno-unused-parameter -Wshadow \
          -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          -Wredundant-decls -Wnested-externs -Wmissing-include-dirs
```

Compilar con optimizaciones (`-O2` o superior) también puede ayudar al compilador a detectar errores adicionales mediante análisis estático.

(0x002Dh)=
### Regla `0x002Dh`: Utilizá guardas de inclusión en todos los archivos de cabecera

Todos los archivos de cabecera (`.h`) deben estar protegidos por guardas de inclusión para prevenir problemas de doble definición si son incluidos múltiples veces.

[Include guards](https://en.wikipedia.org/wiki/Include_guard) permite incluir un
archivo header «dos veces» sin que se interrumpa la compilación.

```c
// Ejemplo de guarda de inclusión
#ifndef MI_MODULO_H
#define MI_MODULO_H

// Contenido del header...

#endif // MI_MODULO_H
```

El nombre de la macro debe ser único, típicamente basado en el nombre del archivo. Aunque existen otras técnicas, las guardas de inclusión son el método más extendido y compatible. Hacen la vida de los usuarios de tu biblioteca más fácil.

#### Comentarios en inclusiones no estándar

Añadí comentarios a las directivas `#include` de bibliotecas no estándar para indicar qué símbolos estás utilizando de ellas.

```c
#include <test.h> // Test, tests_run
#include "trie.h" // Trie, Trie_*
```

Esto ofrece varias ventajas:
- Los lectores no necesitan usar `grep` o consultar documentación externa para saber de dónde proviene un símbolo.
- Facilita la identificación de inclusiones innecesarias.
- Fomenta la reflexión sobre la contaminación del espacio de nombres.

#### Incluí la definición de cada símbolo que utilices

No dependas de las inclusiones transitivas. Si tu código utiliza un símbolo, incluí explícitamente el archivo de cabecera donde se define. Esto hace tu código más robusto ante cambios en las bibliotecas que usás y más claro para los lectores.

#### Evitá las cabeceras unificadas ("umbrella headers")

Las cabeceras que incluyen una biblioteca completa (`#include <biblioteca.h>`) son, por lo general, una mala práctica. Incrementan los tiempos de compilación y acoplan fuertemente tu código a toda la biblioteca, aunque solo necesites una pequeña parte. Es preferible incluir únicamente las cabeceras específicas que contienen los símbolos que necesitás.

(0x002Eh)=
### Regla `0x002Eh`: Las variables que representan tamaños o índices de arreglos deben ser de tipo `size_t`

El tipo `size_t` es un entero sin signo devuelto por el operador `sizeof`. Está diseñado para representar el tamaño de cualquier objeto en memoria, lo que lo convierte en la opción semánticamente correcta y más segura para índices y tamaños de arreglos.

Su uso ofrece ventajas de portabilidad (puede contener el índice más grande posible en cualquier plataforma), claridad (comunica que el valor no puede ser negativo) y seguridad (evita errores de comparación entre tipos con y sin signo).

- **Incorrecto:**
  ```c
  // Usar 'int' puede causar advertencias de comparación con/sin signo
  // y podría no ser suficientemente grande en algunas plataformas.
  void procesar(const int datos[], int tamano) { /* ... */ }
  ```
- **Correcto:**
  ```c
  #include <stddef.h> // Necesario para size_t

  // La función recibe el tamaño como 'size_t' y usa 'size_t' para el índice.
  void imprimir_arreglo(const int arreglo[], size_t tamano)
  {
      for (size_t i = 0; i < tamano; i++)
      {
          printf("%d ", arreglo[i]);
      }
      printf("\n");
  }
  ```

(0x002Fh)=
### Regla `0x002Fh`: Las constantes (`const` o `#define`) deben nombrarse en `MAYUSCULAS_SNAKE_CASE`

Esta convención de estilo mejora drásticamente la legibilidad. Un identificador en mayúsculas actúa como una señal visual inmediata, indicando que se trata de un valor fijo que no debe ser modificado. Esto ayuda a diferenciar las constantes de las variables.

- **Incorrecto:**
  ```c
  const int diasDeLaSemana = 7;
  #define pi 3.14159f
  ```
- **Correcto:**
  ```c
  const int DIAS_DE_LA_SEMANA = 7;
  #define PI 3.14159f

  float calcular_circunferencia(float radio)
  {
      return 2 * PI * radio;
  }
  ```

(0x0030h)=
### Regla `0x0030h`: Todas las operaciones con cadenas deben ser seguras

Utilizá funciones que controlen los límites del búfer (ej. `strncpy`, `snprintf`, `strncat`) para prevenir desbordamientos, una de las vulnerabilidades de seguridad más comunes en C.

- **Incorrecto (inseguro):**
  ```c
  void concatenar_saludo(char *destino, const char *nombre) {
      strcpy(destino, "Hola, "); // strcpy no verifica límites
      strcat(destino, nombre); // strcat no verifica límites
  }
  ```
- **Correcto (seguro):**
  ```c
  void concatenar_saludo_seguro(char *destino, size_t tam_destino, const char *nombre) {
      snprintf(destino, tam_destino, "Hola, %s", nombre);
  }
  ```

Y si estamos implementando funciones que trabajen con cadenas, las mismas deben
incluir un `size_t` para el tamaño en memoria de la cadena.

(0x0031h)=
### Regla `0x0031h`: Los argumentos de función y las variables locales deben usar `snake_case` en minúsculas

- **Incorrecto:**
  ```c
  int miVariable;
  void miFuncion(int UnArgumento) { /* ... */ }
  ```
- **Correcto:**
  ```c
  int mi_variable;
  void mi_funcion(int un_argumento) { /* ... */ }
  ```

(0x0032h)=
### Regla `0x0032h`: Escribí comentarios que expliquen el "porqué", no el "qué"

Los comentarios deben aportar valor y aclarar la intención detrás del código, no parafrasear lo que el código ya expresa de forma evidente. Un buen comentario explica la razón de una decisión de diseño, la lógica de un algoritmo complejo o el contexto que justifica una pieza de código particular.

El código en sí mismo debe ser lo suficientemente claro para explicar *qué* hace. Si necesitás un comentario para describir una simple operación, es probable que el código deba ser refactorizado para ser más legible.

- **Incorrecto (Comentario obvio y redundante):**
```c
// Incrementa i en 1
i++;
```

- **Correcto (Comentario que explica la intención):**
```c
// Se utiliza un índice inverso para procesar los elementos desde el final,
// ya que el último elemento tiene un significado especial en el protocolo.
for (size_t i = tamano - 1; i < tamano; i--) {
    // ...
}
```

(0x0033h)=
### Regla `0x0033h`: Toda instrucción `switch` debe incluir un caso `default`

Para garantizar un comportamiento predecible y robusto, toda instrucción `switch` debe finalizar con un bloque `default`. Esto asegura que el programa maneje explícitamente cualquier valor inesperado que no coincida con los casos definidos, previniendo errores sutiles.
Si un `case` intencionalmente no contiene una instrucción `break` para "caer" (`fall-through`) al siguiente caso, esta intención debe ser documentada explícitamente con un comentario para evitar confusiones.

- **Incorrecto (sin `default` y `fall-through` ambiguo):**
```c
switch (opcion) {
    case OPCION_A:
        hacer_algo();
        break;
    case OPCION_B:
        hacer_otra_cosa(); // ¿Es intencional la caída?
    case OPCION_C:
        hacer_algo_mas();
        break;
}
```

- **Correcto:**
```c
switch (opcion) {
    case OPCION_A:
        // ... código para A ...
        break;

    case OPCION_B:
        // ... código para B ...
        // INTENCIONAL: Se cae al caso C
    case OPCION_C:
        // ... código para B y C ...
        break;

    default:
        // Manejar casos no esperados para evitar comportamiento indefinido.
        fprintf(stderr, "Error: Opción no válida.\n");
        break;
}
```

(0x0034h)=
### Regla `0x0034h`: Organizá la estructura de tus archivos `.c` de forma estándar

Una estructura de archivo consistente mejora la navegabilidad y la predictibilidad del código. Organizá tus archivos `.c` siguiendo este orden estándar:

1.  **Inclusiones de bibliotecas estándar del sistema:** (ej. `<stdio.h>`, `<stdlib.h>`)
2.  **Inclusiones de bibliotecas de terceros:** (si aplica).
3.  **Inclusiones de tus propios módulos locales:** (ej. `"mi_modulo.h"`).
4.  **Definiciones de constantes y macros:** (`#define`).
5.  **Definiciones de tipos:** (`typedef`, `struct`, `enum`).
6.  **Prototipos de funciones privadas del módulo:** (funciones estáticas).
7.  **Implementación de la función `main`:** (si es el archivo principal).
8.  **Implementación de funciones públicas.**
9.  **Implementación de funciones privadas (estáticas).**

- **Ejemplo de estructura:**
```c
// 1. Inclusiones estándar
#include <stdio.h>
#include <stdbool.h>

// 3. Inclusiones locales
#include "utilidades.h"

// 4. Macros
#define VERSION "1.0"

// 5. Tipos
typedef struct {
    int id;
} mi_tipo_t;

// 6. Prototipos de funciones privadas
static bool es_valido(int valor);

// 7. Función main (si aplica)
int main(int argc, char *argv[]) {
    // ...
    return 0;
}

// 8. Funciones públicas
int funcion_publica(int parametro) {
    if (!es_valido(parametro)) {
        return -1;
    }
    // ...
    return 0;
}

// 9. Funciones privadas
static bool es_valido(int valor) {
    return valor > 0;
}
```


(0x0035h)=
### Regla `0x0035h`: Si una función trabaja con `void*`, no se espera modificar el contenido apuntado

Cuando una función recibe un parámetro de tipo `void*`, este debe ser tratado como una referencia genérica inmutable a menos que se indique explícitamente lo contrario. Si la función necesita modificar el contenido apuntado, el parámetro debe ser documentado claramente o, preferentemente, debe usarse un tipo de puntero específico que indique su propósito.

El uso de `void*` generalmente implica polimorfismo o compatibilidad con diferentes tipos de datos, como en funciones de comparación o callbacks. La modificación del contenido a través de un puntero genérico aumenta el riesgo de errores de tipo y comportamiento indefinido.

- **Incorrecto (modificación implícita a través de `void*`):**
```c
void procesar_datos(void *datos, size_t tamano) {
    int *ptr = (int *)datos;
    *ptr = 42; // Modifica sin que sea claro desde la firma
}
```

- **Correcto (lectura solamente):**
```c
void imprimir_bytes(const void *datos, size_t tamano) {
    const unsigned char *ptr = (const unsigned char *)datos;
    for (size_t i = 0; i < tamano; i++) {
        printf("%02x ", ptr[i]);
    }
}
```

- **Correcto (modificación explícita con tipo específico):**
```c
void inicializar_buffer(int *buffer, size_t cantidad, int valor_inicial) {
    for (size_t i = 0; i < cantidad; i++) {
        buffer[i] = valor_inicial;
    }
}
```

(0x0036h)=
### Regla `0x0036h`: Luego de liberar memoria, asignar NULL al puntero

Después de liberar memoria con `free()`, el puntero debe ser inmediatamente asignado a `NULL`. Esto previene el uso accidental de un puntero colgante (*dangling pointer*), que apunta a una región de memoria que ya no es válida. Intentar acceder a memoria liberada resulta en comportamiento indefinido y puede causar errores difíciles de rastrear.

Asignar `NULL` al puntero después de liberarlo proporciona una forma segura de detectar intentos de uso posterior: cualquier desreferencia de un puntero `NULL` generará un error inmediato y predecible, en lugar de un comportamiento impredecible.

- **Incorrecto (puntero colgante):**
```c
int *datos = malloc(100 * sizeof(int));
// ... usar datos ...
free(datos);
// datos ahora es un puntero colgante
```

- **Correcto:**
```c
int *datos = malloc(100 * sizeof(int));
// ... usar datos ...
free(datos);
datos = NULL; // Previene uso accidental posterior
```

- **Ejemplo de protección adicional:**
```c
void liberar_recurso(int **puntero) {
    if (puntero != NULL && *puntero != NULL) {
        free(*puntero);
        *puntero = NULL; // Asegura que el puntero original se anule
    }
}

// Uso:
int *datos = malloc(100 * sizeof(int));
liberar_recurso(&datos);
// Ahora datos es NULL
```


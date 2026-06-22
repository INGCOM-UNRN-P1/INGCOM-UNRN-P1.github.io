---
title: Cuestiones de estilo
short_title: 0x0000h - Estilo
subtitle: Pautas para la organización y prolijidad del código.
---

## Introducción

Este documento establece un conjunto de reglas de estilo, diseñadas para que su código en C sea más claro, legible y menos propenso a errores. La programación en C ofrece una gran flexibilidad, pero ello también facilita la adopción de malas prácticas que pueden conducir a errores de difícil detección. Por este motivo, la adhesión a un conjunto de reglas claras es fundamental para mantener el código ordenado y seguro.

La idea detrás de estas reglas es que un código de calidad no solo debe ser funcional, sino también comprensible para cualquier profesional que deba leerlo, ya sea vos mismo en el futuro o un colega que se incorpore al proyecto. Un código limpio y bien organizará facilita la colaboración, ahorra tiempo en la fase de corrección y previene complicaciones durante la depuración o actualización del software.

Estas reglas abarcan desde la nomenclatura de variables y funciones hasta la estructuración de condicionales y lazos. Su observancia no solo contribuye a la coherencia del proyecto, sino que también resulta en un código más robusto y mantenible a largo plazo.

Al comenzar, la aplicación de reglas estrictas en un lenguaje flexible como C te proporciona un marco sólido. A medida que tu comprensión del lenguaje se profundice, podés adaptar estas reglas para desarrollar un estilo propio.

## Apertura a Sugerencias y Debate

Estamos abiertos a debatir todas las reglas. Para ello, solo tenés que abrir un hilo en Discussions o un ticket en el Issue Tracker. Aceptamos propuestas de nuevas reglas, clasificaciones, explicaciones y potenciales excepciones.

## Principios Clave

- **Claridad:** El código debe ser fácil de leer.
- **Mantenibilidad:** Debe ser sencillo de modificar y extender.
- **Consistencia:** El uso de un estilo uniforme optimiza la colaboración.
- **Eficiencia:** Se debe optimizar el rendimiento sin sacrificar la legibilidad.

---

## Estructura de Clasificación de Reglas (Máscara de Bits)

Para facilitar la referencia cruzada y el análisis estático de las pautas de estilo, las reglas se encuentran organizadas en secciones temáticas progresivas bajo un esquema de máscara de bits de 16 bits (`0xXXXX`):

1.  **Sintaxis Básica y Nomenclatura (`0x00XX`):** Reglas visuales, espaciado, indentación y pautas de nombrado de variables y constantes.
2.  **Estructuras de Control y Lazos (`0x10XX`):** Bloques condicionales, estructuras de iteración y flujos de ejecución de sentencias.
3.  **Funciones y Modularización (`0x20XX`):** Diseño de interfaces de funciones, documentación de contratos, alcance y responsabilidades.
4.  **Punteros y Gestión de Memoria (`0x30XX`):** Uso de indirecciones, alocación en el heap, gestión de punteros nulos y liberación segura de recursos.
5.  **Compilación y Buenas Prácticas de Ingeniería (`0x40XX`):** Configuración de alertas, guardas de cabeceras, archivos de cabeceras locales, robustez y estructuras de código estándar.

---

## 1. Sintaxis Básica y Nomenclatura (`0x00XX`)

(0x0000h)=
### Regla `0x0000h`: La claridad y prolijidad son de máxima importancia

El código debe ser claro y fácil de entender para cualquier lector, no solo para su autor. Un código limpio y prolijo previene errores, facilita el mantenimiento y mejora la colaboración en equipo. La claridad es siempre preferible a técnicas de programación ofuscadas que solo complican la comprensión.

```diff
- for (int i = 0, j = 10; i < j; i++, j--) { printf("%d", i+j); }
+ int i = 0;
+ int j = 10;
+ while (i < j)
+ {
+     printf("%d", i + j);
+     i++;
+     j--;
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

Probá y observá si el nombre corto contribuye a la legibilidad.

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
### Regla `0x0005h`: Cada bloque debe tener una indentación de cuatro espacios respecto a su contenedor y llaves

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

Esto aplica incluso para bloques de una sola línea.
```diff
- if (condicion) accion;
+ if (condicion) {
+     accion;
+ }
```

(0x0006h)=
### Regla `0x0006h`: El asterisco de los punteros debe declararse junto al identificador

Esta convención facilita la identificación visual de una variable como puntero y mejora la claridad.

```diff
-int* ptr;
+int *ptr;
```

(0x0007h)=
### Regla `0x0007h`: Los argumentos de función y las variables locales deben usar `snake_case` en minúsculas

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

(0x0008h)=
### Regla `0x0008h`: Las constantes (`const` o `#define`) deben nombrarse en `MAYUSCULAS_SNAKE_CASE`

Esta convención de estilo de nomenclatura mejora la legibilidad. Un identificador en mayúsculas actúa como una señal visual inmediata, indicando que se trata de un valor inmutable.

- **Incorrecto:**
  ```c
  const int diasDeLaSemana = 7;
  #define pi 3.14159f
  ```
- **Correcto:**
  ```c
  const int DIAS_DE_LA_SEMANA = 7;
  #define PI 3.14159f

  float calcular_circunferencia(float radio) {
      return 2 * PI * radio;
  }
  ```

(0x0009h)=
### Regla `0x0009h`: Las líneas de código no deben exceder los 79 caracteres

Nunca debés escribir líneas que excedan los 79 caracteres. El límite de 80 columnas es un estándar de facto que facilita la lectura y la visualización de código en paralelo. Las líneas largas fatigan la vista y requieren desplazamiento horizontal.

- **Incorrecto:**
  ```c
  printf("Este es un mensaje de registro extremadamente largo que definitivamente excede el límite de 79 caracteres y hace que el código sea mucho más difícil de leer para otros desarrolladores.\n");
  ```
- **Correcto:**
  ```c
  printf("Este es un mensaje de registro extremadamente largo que se divide "
         "en múltiples líneas para cumplir con el estándar de 80 columnas.\n");
  ```

(0x000Ah)=
### Regla `0x000Ah`: Escribí comentarios que expliquen el "porqué", no el "qué"

Los comentarios deben aportar valor y aclarar la intención detrás del código, no parafrasear lo que el código ya expresa de forma evidente. El código en sí mismo debe ser lo suficientemente claro para explicar *qué* hace.

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

---

## 2. Estructuras de Control y Lazos (`0x10XX`)

(0x1001h)=
### Regla `0x1001h`: Todas las estructuras de control deben utilizar llaves

Aunque las llaves son opcionales para bloques de una sola línea, su uso es obligatorio para mantener la prolijidad y consistencia, y para evitar que futuras modificaciones introduzcan comportamientos inesperados.

```c
if (condicion) {
    // Camino verdadero
} else {
    // Camino falso
}
```

Las llaves, a su vez, deben colocarse en una línea propia para mejor visibilidad del bloque.

- **Incorrecto:**
  ```c
  if (x > 0) x++;
  ```
- **Correcto:**
  ```c
  if (x > 0)
  {
      x++;
  }
  ```

(0x1002h)=
### Regla `0x1002h`: Evitá el uso descontrolado de `break` y `continue`; preferí lazos con bandera de control

La cátedra desaconseja el uso generalizado de `break` y `continue` para controlar lazos complejos. En su lugar, preferí usar variables booleanas (banderas) de control en la condición del lazo.

**Excepción:** Se admite el uso de `break` para salir anticipadamente de un lazo cuando simplifique la lógica y evite un anidamiento excesivo o banderas redundantes. El uso de `continue` sigue estando estrictamente prohibido debido a que salta partes del código y oscurece el flujo lógico del lazo. (Si tenés dudas, consultá)

- **Incorrecto (Uso descontrolado de `break` y `continue`):**
```c
for (int i = 1; i <= 10; i++){
    if (i == 4){
        continue;
    }
    if (i == 8){
        break;
    }
    printf("Número: %d\n", i);
}
```

- **Correcto (Uso de bandera lógica):**
```c
bool seguir_ejecutando = true;
int i = 1;

while (i <= 10 && seguir_ejecutando){
    if (i == 8)    {
        seguir_ejecutando = false;
    } else if (i != 4){
        printf("Número: %d\n", i);
    }
    i++;
}
```

(0x1003h)=
### Regla `0x1003h`: Utilizá el lazo `for` para iteraciones con rango o contador definido y `while` para lazos controlados por condiciones lógicas

Utilizá el lazo `for` cuando la cantidad de iteraciones esté predefinida o se controle mediante un contador o rango conocido. Reservá el uso del lazo `while` para iteraciones basadas en condiciones puramente lógicas o eventos indefinidos en tiempo de ejecución.

El lazo `for` es preferible para conteos, ya que agrupa la inicialización, la condición de parada y el incremento en un único lugar, previniendo lazos infinitos por olvido del incremento de control.

- **Incorrecto (forzado de lectura interactiva en `for`):**
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

- **Correcto (uso de `for` para conteo definido):**
```c
for (size_t i = 0; i < limite; i++)
{
    procesar_elemento(i);
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


(0x1004h)=
### Regla `0x1004h`: Las condiciones complejas deben ser simplificadas o comentadas

Si una condición contiene múltiples operadores lógicos, considerá dividirla en partes más pequeñas usando variables lógicas auxiliares explicativas o funciones de validación.

- **Incorrecto (difícil de leer):**
```c
if ((usuario_activo && tiene_permisos) || (es_admin && !modo_mantenimiento)) {
    // ...
}
```

- **Correcto (simplificado con variables booleanas):**
```c
bool puede_acceder = usuario_activo && tiene_permisos;
bool es_admin_con_acceso = es_admin && !modo_mantenimiento;

if (puede_acceder || es_admin_con_acceso) {
    // ...
}
```

(0x1005h)=
### Regla `0x1005h`: Evitá las condiciones ambiguas basadas en la "veracidad" (truthiness) del tipo de dato

Las comparaciones deben ser siempre explícitas. En C, cualquier valor numérico distinto de cero se considera verdadero, y el cero falso. Depender de esta veracidad implícita atenta contra la legibilidad.

Es fundamental diferenciar de forma inequívoca la comparación de caracteres del chequeo de punteros:
- Si la variable es un carácter (`char`), comparalo contra el carácter nulo de cadena `'\0'`.
- Si la variable es un puntero, comparalo contra `NULL`.
- Si es una variable lógica, comparala contra `true` o `false`.

```diff
- if (x) {
+ if (x != 0) {
```

- **Incorrecto (veracidad implícita y ambigua):**
```c
if (encendido);
return !caracter;               // Si 'caracter' es un char
return !ptr;                    // Si 'ptr' es un puntero a memoria
while (!trabajando);
```

- **Correcto (claridad de tipos explícita):**
```c
if (encendido == true);
return caracter == '\0';        // Comparación correcta de tipo char
return ptr == NULL;             // Comparación correcta de tipo puntero
while (trabajando == false);
```

(0x1006h)=
### Regla `0x1006h`: No utilizar la instrucción `goto`

El uso de `goto` rompe el flujo de control estructurado, dificultando la lectura y depuración del código. En su lugar, empleá las estructuras de control estándar.

- **Incorrecto:**
```c
void procesar_datos(int *datos, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (datos[i] < 0) {
            goto error;
        }
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

(0x1007h)=
### Regla `0x1007h`: No utilizar el operador condicional (ternario) `?:`

Aunque compacto, el operador ternario reduce la legibilidad del código, especialmente en expresiones anidadas o complejas.

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

(0x1008h)=
### Regla `0x1008h`: Toda instrucción `switch` debe incluir un caso `default`

Para garantizar un comportamiento predecible y robusto, toda instrucción `switch` debe finalizar con un bloque `default`. Esto asegura que el programa maneje explícitamente cualquier valor inesperado. Si un `case` intencionalmente no contiene una instrucción `break` para "caer" (`fall-through`) al siguiente caso, esta intención debe ser documentada con un comentario.

```c
switch (opcion) {
    case OPCION_A:
        hacer_algo();
        break;

    case OPCION_B:
        hacer_otra_cosa();
        // INTENCIONAL: Cae al caso C
    case OPCION_C:
        hacer_algo_mas();
        break;

    default:
        fprintf(stderr, "Error: Opción no válida.\n");
        break;
}
```

---

## 3. Funciones y Modularización (`0x20XX`)

(0x2001h)=
### Regla `0x2001h`: Las funciones deben usar cláusulas de guarda y retornos anticipados para evitar la anidación profunda

Se admite el uso de retornos anticipados (`early returns`) al inicio de la función en forma de cláusulas de guarda (`guard clauses`) para validar parámetros o comprobar condiciones de error iniciales inmediatas. Esto previene la anidación profunda de bloques `if` (código en flecha) y mejora la comprensión visual del camino feliz del algoritmo.

Sin embargo, en funciones más complejas donde se asignen recursos locales (memoria dinámica, archivos abiertos, sockets), se prefiere centralizar la limpieza al final de la función para evitar fugas de recursos por puntos de salida prematuros alternativos.

- **Incorrecto:**

Anidación profunda por único retorno estricto.

```c
int procesar_sensor(sensor_t *s)
{
    int resultado = -1;
    if (s != NULL)
    {
        if (s->activo == true)
        {
            if (s->lectura > 0)
            {
                resultado = s->lectura * 2;
            }
        }
    }
    return resultado;
}
```

- **Correcto:**

Cláusulas de guarda didácticas para salida rápida

```c
int procesar_sensor(sensor_t *s)
{
    if (s == NULL || s->activo == false)
    {
        return -1;
    }
    if (s->lectura <= 0)
    {
        return -1;
    }
    return s->lectura * 2;
}
```

- **Correcto (gestión de recursos compleja centralizada al final):**
```c
int procesar_archivo_con_un_retorno(const char *nombre_archivo)
{
    int valor_retorno = 0;
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL)
    {
        return -1;
    }

    char *buffer = (char *)malloc(100);
    if (buffer == NULL)
    {
        fclose(archivo);
        return -1;
    }

    if (fread(buffer, 1, 99, archivo) < 1)
    {
        valor_retorno = -1;
    }
    else
    {
        printf("Archivo procesado: %s\n", buffer);
    }

    // Bloque de limpieza único al final de la función
    free(buffer);
    fclose(archivo);
    return valor_retorno;
}
```

(0x2002h)=
### Regla `0x2002h`: Las funciones no deben contener `printf` o `scanf`, a menos que ese sea su propósito explícito

Las funciones deben desacoplarse de las operaciones de entrada y salida (I/O) para maximizar su reutilización y facilitar las pruebas unitarias. Si el propósito de una función no es realizar I/O, dichas llamadas deben ser delegadas a otras funciones especializadas del llamador.

- **Incorrecto:**
  ```c
  void calcular_e_imprimir_iva(float monto) {
      float iva = monto * 0.21f;
      printf("El IVA es: %.2f\n", iva);
  }
  ```
- **Correcto:**
  ```c
  float calcular_iva(float monto) {
      return monto * 0.21f;
  }
  ```

(0x2003h)=
### Regla `0x2003h`: Todas las funciones deben incluir documentación completa y estructurada

Una documentación adecuada define la especificación conceptual y formal del comportamiento de la función mediante etiquetas como `@param`, `@pre`, `@returns`, `@post`, e invariantes mediante `@invariant`.

```c
/**
 * Computa la suma de dos números enteros mediante incrementos sucesivos.
 *
 * @param sumando El primer término de la suma.
 * @param sumador El segundo término, que determina la cantidad de incrementos.
 *
 * @pre La suma de 'sumando' y 'sumador' no debe causar desbordamiento (overflow) de 'int'.
 *
 * @returns Un entero que es el resultado de la suma.
 *
 * @post El valor retornado es equivalente a 'sumando + sumador'.
 */
int suma_lenta(int sumando, int sumador);
```

(0x2004h)=
### Regla `0x2004h`: No se permite el uso de variables globales

Las variables globales pueden ser modificadas desde cualquier parte del programa, lo que causa efectos secundarios impredecibles y dificulta el rastreo de errores. **Su uso está estrictamente prohibido**.

- **Incorrecto:**
  ```c
  int contador_global = 0;
  void incrementar_contador() {
      contador_global++;
  }
  ```
- **Correcto:**
  ```c
  int incrementar(int contador) {
      return contador + 1;
  }
  ```

(0x2005h)=
### Regla `0x2005h`: Cada función debe tener una única responsabilidad (Principio de Responsabilidad Única)

Cada función debe encargarse de una sola tarea. Esto mejora la legibilidad, la reutilización y el mantenimiento del código. Las funciones pequeñas y especializadas son más fáciles de probar y depurar.

- **Incorrecto:**
  ```c
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

  

(0x2006h)=
### Regla `0x2006h`: Una aserción por cada función de prueba

Podés lograr esto creando una función de prueba parametrizada que reciba los argumentos y el resultado esperado, o bien dedicando una función de prueba para cada caso específico de aserción.

- **Incorrecto:**
  ```c
  void prueba_calculadora() {
      ASSERT_IGUAL(sumar(2, 2), 4);
      ASSERT_IGUAL(restar(5, 3), 2);
  }
  ```
- **Correcto:**
  ```c
  void prueba_suma_positivos() {
      ASSERT_IGUAL(sumar(2, 2), 4);
  }
  void prueba_resta_basica() {
      ASSERT_IGUAL(restar(5, 3), 2);
  }
  ```

(0x2007h)=
### Regla `0x2007h`: Mantené el alcance de las variables al mínimo posible

Declarar las variables con el alcance más restringido posible ayuda a reducir errores y mejora la claridad de la vida útil de cada dato.

- **Incorrecto:**
  ```c
  void procesar() {
      int i;
      // ... mucho código ...
      for (i = 0; i < 10; i++) { /* ... */ }
  }
  ```
- **Correcto:**
  ```c
  void procesar() {
      // ... mucho código ...
      for (int i = 0; i < 10; i++) { /* 'i' solo existe en el lazo */ }
  }
  ```

(0x2008h)=
### Regla `0x2008h`: Los valores de retorno numéricos deben definirse como constantes de preprocesador o `enum`s

El uso de nombres descriptivos para los valores de retorno numéricos facilita la comprensión de su significado semántico.

```diff
-return -1;
+return ERROR_APERTURA_ARCHIVO;
```

(0x2009h)=
### Regla `0x2009h`: Los ejercicios deben ser resueltos mediante funciones

Esta práctica fomenta la modularización, facilita las pruebas unitarias y promueve la reutilización de código.

- **Incorrecto:**
  ```c
  int main() {
      int base = 10;
      int altura = 5;
      int area = base * altura;
      printf("Área: %d\n", area);
      return 0;
  }
  ```
- **Correcto:**
  ```c
  int calcular_area(int base, int altura) {
      return base * altura;
  }
  int main() {
      int area = calcular_area(10, 5);
      printf("Área: %d\n", area);
      return 0;
  }
  ```

(0x200Ah)=
### Regla `0x200Ah`: Los nombres de funciones y procedimientos deben usar `snake_case` en minúsculas

Mejora la consistencia y legibilidad, distinguiendo funciones de tipos y constantes.

- **Incorrecto:**
  ```c
  void MiFuncionDeCalculo(int v);
  void otraFuncion();
  ```
- **Correcto:**
  ```c
  void mi_funcion_de_calculo(int valor);
  void otra_funcion();
  ```

---

## 4. Punteros y Gestión de Memoria (`0x30XX`)

(0x3001h)=
### Regla `0x3001h`: Siempre verificá la asignación exitosa de memoria dinámica

Toda asignación de memoria dinámica realizada con `malloc`, `calloc` o `realloc` debe ser seguida inmediatamente por una comprobación contra `NULL` antes de su uso.

```c
ptr = malloc(sizeof(*ptr));
if (ptr == NULL)
{
    // Manejo de error de memoria insuficiente
}
```

(0x3002h)=
### Regla `0x3002h`: Liberá siempre la memoria dinámica y asigná `NULL` al puntero para evitar punteros colgantes

Por cada asignación de memoria dinámica debe existir una correspondiente liberación con `free()`. Inmediatamente después de liberar la memoria, asigná `NULL` al puntero para prevenir fallos por acceso a punteros colgantes (*dangling pointers*).

```c
free(ptr);
ptr = NULL;
```

#### Simetría en la liberación de recursos

La liberación de memoria debe realizarse al mismo nivel de abstracción que su asignación. Si se encapsula la creación de una estructura con una función `crear_recurso`, se debe proveer una función `liberar_recurso` correspondiente.

```c
recurso_t *crear_recurso() {
    recurso_t *r = malloc(sizeof(*r));
    return r;
}
void liberar_recurso(recurso_t *r) {
    free(r);
}
```

(0x3003h)=
### Regla `0x3003h`: No mezcles operaciones de asignación y comparación en una sola línea

Mantener las asignaciones y comparaciones en líneas separadas previene errores lógicos sutiles y facilita el rastreo de excepciones.

```diff
- if ((ptr = malloc(tamaño)) == NULL) {
+ ptr = malloc(tamaño);
+ if (ptr == NULL) {
```

(0x3004h)=
### Regla `0x3004h`: Utilizá `typedef` para definir tipos de estructuras con el sufijo `_t`

Esto simplifica el manejo sintáctico del código en C. Los alias de tipo creados con `typedef` deben terminar obligatoriamente con el sufijo `_t`.

- **Incorrecto:**
  ```c
  struct mi_estructura var;
  ```
- **Correcto:**
  ```c
  typedef struct {
      int campo1;
  } mi_estructura_t;

  mi_estructura_t var;
  ```

(0x3005h)=
### Regla `0x3005h`: Minimizá el uso de múltiples niveles de indirección (punteros a punteros)

Los punteros a punteros (`**`) o de niveles superiores de indirección complican la lectura y el razonamiento sobre la memoria. Deben evitarse siempre que no sean estrictamente requeridos.

- **Incorrecto:**
  ```c
  void obtener_datos(int **ptr_datos, size_t *tamano) { /* ... */ }
  ```
- **Correcto:**
  ```c
  int *obtener_datos(size_t *tamano_out) { /* ... */ }
  ```

(0x3006h)=
### Regla `0x3006h`: Documentá la propiedad de los recursos al utilizar punteros

Cuando una función recibe o devuelve un puntero a memoria dinámica, la documentación de la función debe especificar explícitamente cuál es el módulo responsable de liberar dicha memoria (el dueño del recurso).

```c
/**
 * Crea un nuevo recurso.
 * @returns Un puntero al nuevo recurso. El llamador es dueño y responsable
 *          de liberar esta memoria mediante liberar_recurso().
 */
recurso_t *crear_recurso();
```

(0x3007h)=
### Regla `0x3007h`: Los argumentos de tipo puntero deben ser `const` siempre que la función no los modifique

Usar `const` en los parámetros de tipo puntero establece un contrato de solo lectura, previniendo efectos secundarios no deseados sobre los datos de origen.

```c
// Correcto: La función lee el dato apuntado pero garantiza no modificarlo.
void imprimir_saludo(const char *nombre)
{
    printf("Hola, %s!\n", nombre);
}
```

(0x3008h)=
### Regla `0x3008h`: Los punteros nulos deben ser inicializados y comparados con `NULL`, no con `0`

La macro `NULL` debe utilizarse para mantener la coherencia semántica en operaciones con punteros.

- **Incorrecto:**
  ```c
  int *ptr = 0;
  if (ptr == 0) { /* ... */ }
  ```
- **Correcto:**
  ```c
  int *ptr = NULL;
  if (ptr == NULL) { /* ... */ }
  ```

(0x3009h)=
### Regla `0x3009h`: Documentá explícitamente los casos en que una función puede retornar `NULL`

Si una función que devuelve un puntero puede fallar y retornar `NULL`, este escenario debe ser explícito en la documentación de retorno de la función.

```c
/**
 * Busca un elemento en la estructura.
 * @returns Un puntero al elemento si se encuentra, o NULL si no existe.
 */
elemento_t *buscar_elemento(int id);
```

(0x300Ah)=
### Regla `0x300Ah`: Utilizá `cast` explícito al convertir tipos de punteros

Las conversiones de tipos de punteros deben ser siempre explícitas en el código fuente para mejorar la claridad de conversión de tipos de datos.

```c
void *mem = malloc(sizeof(int));
if (mem != NULL) {
    int *ptr = (int *)mem;  // Cast explícito
}
```

(0x300Bh)=
### Regla `0x300Bh`: Usá siempre `sizeof` en las asignaciones de memoria dinámica, prefiriendo `sizeof(*ptr)`

El uso de `sizeof` dinámico en asignación reduce errores ante cambios de tipos en refactorizaciones de variables.

- **Incorrecto:**
  ```c
  int *ptr = malloc(4);
  ```
- **Correcto:**
  ```c
  int *ptr = malloc(sizeof(*ptr));
  ```

(0x300Ch)=
### Regla `0x300Ch`: Verificá siempre los límites de los arreglos antes de acceder a sus elementos

El acceso fuera de límites de un arreglo (`out-of-bounds`) es un error grave. Los índices deben ser explícitamente validados antes de acceder a un elemento.

```c
int arreglo[10];
int indice = 9;
if (indice >= 0 && indice < 10) {
    arreglo[indice] = 5;
}
```

(0x300Dh)=
### Regla `0x300Dh`: Utilizá `enum` en lugar de "números mágicos" para conjuntos de estados y valores constantes

Las enumeraciones explican la semántica de un conjunto de constantes enteras relacionadas.

- **Incorrecto (uso de enteros crudos):**
  ```c
  void procesar_estado(int estado) {
      if (estado == 0) { /* ... */ }
  }
  ```
- **Correcto:**
  ```c
  typedef enum {
      ESTADO_INACTIVO,
      ESTADO_ACTIVO
  } estado_t;

  void procesar_estado(estado_t estado) {
      if (estado == ESTADO_ACTIVO) { /* ... */ }
  }
  ```

(0x300Eh)=
### Regla `0x300Eh`: Documentá explícitamente el comportamiento de las funciones al manejar punteros nulos como argumentos

Si una función acepta que sus argumentos punteros sean `NULL`, se debe indicar el comportamiento esperado. Si no los acepta, se debe documentar como una precondición explícita.

```c
/**
 * Procesa la información.
 * @param datos Puntero a los datos. No debe ser NULL.
 * @pre datos != NULL
 */
void procesar_datos(const datos_t *datos);
```

(0x300Fh)=
### Regla `0x300Fh`: Liberá la memoria en el orden inverso a su asignación

Esto es crítico en estructuras de datos anidadas, como matrices dinámicas 2D o listas enlazadas, para evitar dejar memoria inaccesible en el heap.

```c
for (size_t i = 0; i < filas; i++) {
    free(matriz[i]); // Libera las subasignaciones primero
}
free(matriz);        // Libera el contenedor principal
matriz = NULL;
```

(0x3010h)=
### Regla `0x3010h`: Las variables que representan tamaños o índices de arreglos deben ser de tipo `size_t`

`size_t` es un tipo entero sin signo que garantiza portabilidad para contener el tamaño máximo posible de un objeto en memoria.

- **Incorrecto:**
  ```c
  void imprimir_arreglo(const int arreglo[], int tamano);
  ```
- **Correcto:**
  ```c
  void imprimir_arreglo(const int arreglo[], size_t tamano)
  {
      for (size_t i = 0; i < tamano; i++)
      {
          printf("%d ", arreglo[i]);
      }
  }
  ```

(0x3011h)=
### Regla `0x3011h`: Si una función recibe un puntero genérico para operaciones de solo lectura, la firma de la función debe utilizar `const void*`

Si una función recibe un puntero genérico `void*` y no modifica el contenido de la memoria apuntada, se **debe** declarar obligatoriamente el parámetro como `const void*`. Se prohíbe pasar `void*` sin calificador `const` si la operación es de solo lectura.

- **Incorrecto:**
```c
void imprimir_bytes(void *datos, size_t tamano) {
    unsigned char *ptr = (unsigned char *)datos; // Firma insegura
    // ...
}
```

- **Correcto:**
```c
void imprimir_bytes(const void *datos, size_t tamano) {
    const unsigned char *ptr = (const unsigned char *)datos;
    for (size_t i = 0; i < tamano; i++) {
        printf("%02x ", ptr[i]);
    }
}
```

---

## 5. Compilación y Buenas Prácticas de Ingeniería (`0x40XX`)

(0x4001h)=
### Regla `0x4001h`: Los arreglos estáticos deben ser creados con un tamaño fijo en tiempo de compilación

Los Arreglos de Longitud Variable (ALV / VLA) están prohibidos debido a los riesgos de desbordamiento incontrolado de la pila. Deben definirse con una constante en tiempo de compilación.

```diff
- int n = 10;
- int numeros[n]; // ALV prohibido
+ #define TAMANO_NUMEROS 10
+ int numeros[TAMANO_NUMEROS];
```

(0x4002h)=
### Regla `0x4002h`: Desarrollá y compilá siempre con todas las advertencias del compilador activadas

Debés activar las advertencias de compilación para la detección temprana de errores lógicos. Usá al menos las siguientes banderas con `gcc` o `clang`:

```make
CFLAGS += -Wall -Wextra -Wpedantic \
          -Wformat=2 -Wno-unused-parameter -Wshadow \
          -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          -Wredundant-decls -Wnested-externs -Wmissing-include-dirs
```

(0x4003h)=
### Regla `0x4003h`: Utilizá guardas de inclusión en todos los archivos de cabecera

Todos los archivos de cabecera (`.h`) deben incluir guardas de preprocesador para evitar problemas de redefinición múltiple.

```c
#ifndef MI_MODULO_H
#define MI_MODULO_H

// Declaraciones...

#endif // MI_MODULO_H
```

Añadí comentarios en las directivas `#include` de cabeceras de terceros o del proyecto para documentar la provisión de símbolos, y evitá cabeceras unificadas que importen todo un módulo innecesariamente.

(0x4004h)=
### Regla `0x4004h`: Todas las operaciones con cadenas deben ser seguras

Utilizá funciones que controlen los límites de tamaño máximo del buffer de destino (`strncpy`, `snprintf`, `strncat`) para prevenir desbordamientos.

- **Incorrecto (inseguro):**
  ```c
  void concatenar_saludo(char *destino, const char *nombre) {
      strcpy(destino, "Hola, ");
      strcat(destino, nombre);
  }
  ```
- **Correcto (seguro):**
  ```c
  void concatenar_saludo_seguro(char *destino, size_t tam_destino, const char *nombre) {
      snprintf(destino, tam_destino, "Hola, %s", nombre);
  }
  ```

(0x4005h)=
### Regla `0x4005h`: Organizá la estructura de tus archivos `.c` de forma estándar

Mantené la estructura de archivo ordenada en secciones progresivas para mejorar su predictibilidad:

1.  Inclusiones de bibliotecas estándar (`<stdio.h>`).
2.  Inclusiones de bibliotecas de terceros.
3.  Inclusiones de cabeceras del proyecto (`"modulo.h"`).
4.  Definición de macros y constantes (`#define`).
5.  Definiciones de tipos (`typedef`, `struct`, `enum`).
6.  Prototipos de funciones privadas (`static`).
7.  Función `main` (si aplica).
8.  Implementación de funciones públicas.
9.  Implementación de funciones privadas (`static`).

(0x4006h)=
### Regla `0x4006h`: Preferí `fgets` sobre `gets` y `scanf` para leer cadenas

`fgets` previene el desbordamiento de búfer de entrada de forma automática mediante la validación de tamaño del buffer de entrada.

- **Incorrecto:**
  ```c
  char buffer[50];
  scanf("%s", buffer);
  ```
- **Correcto:**
  ```c
  char buffer[50];
  fgets(buffer, sizeof(buffer), stdin);
  ```

(0x4007h)=
### Regla `0x4007h`: Manejá correctamente la apertura y cierre de archivos

Siempre validá que el puntero devuelto por `fopen` no sea `NULL` antes de operar sobre él, y cerrá el recurso mediante `fclose`.

```c
FILE *archivo = fopen("datos.txt", "r");
if (archivo == NULL)
{
    perror("Error al abrir archivo");
    return ERROR_ARCHIVO;
}
// ...
fclose(archivo);
```

---
title: Estructuras de Control y Lazos
short_title: Estructuras de Control
subtitle: Reglas de estilo para condicionales y estructuras de repetición en C
---

(0x10XXh)=
# Estructuras de Control y Lazos (`0x10XX`)

(0x1001h)=
## Regla `0x1001h`: Todas las estructuras de control deben utilizar llaves

Aunque las llaves son opcionales para bloques de una sola línea, su uso es
obligatorio para mantener la prolijidad y consistencia, y para evitar que
futuras modificaciones introduzcan comportamientos inesperados.

``` c
if (condicion)
{
    // Camino verdadero
}
else
{
    // Camino falso
}
```
<!-- c -->

Las llaves, a su vez, deben colocarse en una línea propia para mejor visibilidad
del bloque.

- **Incorrecto:**
  ```c
  if (x > 0)
      x++;
  ```
- **Correcto:**
  ```c
  if (x > 0)
  {
      x++;
  }
  ```

(0x1002h)=
## Regla `0x1002h`: Evitá el uso descontrolado de `break` y `continue`; preferí lazos con bandera de control

La cátedra desaconseja el uso generalizado de `break` y `continue` para
controlar lazos complejos. En su lugar, preferí usar variables booleanas
(banderas) de control en la condición del lazo.

**Excepción:** Se admite el uso de `break` para salir anticipadamente de un lazo
cuando simplifique la lógica y evite un anidamiento excesivo o banderas
redundantes. El uso de `continue` sigue estando estrictamente prohibido debido a
que salta partes del código y oscurece el flujo lógico del lazo. (Si tenés
dudas, consultá)

- **Incorrecto (Uso descontrolado de `break` y `continue`):**
```{code-block} c
:linenos:
for (int i = 1; i <= 10; i++)
{
    if (i == 4)
    {
        continue;
    }
    if (i == 8)
    {
        break;
    }
    printf("Número: %d\n", i);
}
```
<!-- {code-block} c -->

- **Correcto (Uso de bandera lógica):**
```{code-block} c
:linenos:
bool seguir_ejecutando = true;
int i = 1;
while (i <= 10 && seguir_ejecutando)
{
    if (i == 8)
    {
        seguir_ejecutando = false;
    }
    else if (i != 4)
    {
        printf("Número: %d\n", i);
    }
    i++;
}
```
<!-- {code-block} c -->

(0x1003h)=
## Regla `0x1003h`: Utilizá el lazo `for` para iteraciones con rango o contador definido y `while` para lazos controlados por condiciones lógicas

Utilizá el lazo `for` cuando la cantidad de iteraciones esté predefinida o se
controle mediante un contador o rango conocido. Reservá el uso del lazo `while`
para iteraciones basadas en condiciones puramente lógicas o eventos indefinidos
en tiempo de ejecución.

El lazo `for` es preferible para conteos, ya que agrupa la inicialización, la
condición de parada y el incremento en un único lugar, previniendo lazos
infinitos por olvido del incremento de control.

- **Incorrecto (forzado de lectura interactiva en `for`):**
```{code-block} c
:linenos:
#include <stdio.h>
int main()
{
    int numero;
    int suma = 0;
    printf("Ejemplo con 'for' (poco legible):\n");
    // Se fuerza la lectura del dato dentro de la declaración y el paso del
    // 'for'. Esto es confuso y rompe la claridad del código.
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
<!-- {code-block} c -->

- **Correcto (uso de `for` para conteo definido):**
``` c
for (size_t i = 0; i < limite; i++)
{
    procesar_elemento(i);
}
```
<!-- c -->

- **Correcto (uso de `while`):**

```{code-block} c
:linenos:
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
(0x1004h) = ##Regla `0x1004h`
    : Las condiciones complejas deben ser simplificadas o comentadas Si una
          condición contiene múltiples operadores lógicos,
    considerá dividirla en partes más pequeñas usando variables lógicas
            auxiliares explicativas o funciones de validación.-
        **Incorrecto(difícil de leer)
    : **
```` c if ((usuario_activo && tiene_permisos) ||
            (es_admin && !modo_mantenimiento))
{
    // ...
}
````
<!-- c -->

- **Correcto (simplificado con variables booleanas):**
```` c
bool puede_acceder = usuario_activo && tiene_permisos;
bool es_admin_con_acceso = es_admin && !modo_mantenimiento;
if (puede_acceder || es_admin_con_acceso)
{
    // ...
}
````
<!-- c -->

(0x1005h)=
## Regla `0x1005h`: Evitá las condiciones ambiguas basadas en la "veracidad" (truthiness) del tipo de dato

Las comparaciones deben ser siempre explícitas. En C, cualquier valor numérico distinto de cero se considera verdadero, y el cero falso. Depender de esta veracidad implícita atenta contra la legibilidad.

Es fundamental diferenciar de forma inequívoca la comparación de caracteres del chequeo de punteros:
- Si la variable es un carácter (`char`), comparalo contra el carácter nulo de cadena `'\0'`.
- Si la variable es un puntero, comparalo contra `NULL`.
- Si es una variable lógica, comparala contra `true` o `false`.

```` diff
- if (x)
- {
+ if (x != 0)
+ {
````
<!-- diff -->

- **Incorrecto (veracidad implícita y ambigua):**
```` c
if (encendido)
    ;
return !caracter; // Si 'caracter' es un char
return !ptr;      // Si 'ptr' es un puntero a memoria
while (!trabajando)
    ;
````
<!-- c -->

- **Correcto (claridad de tipos explícita):**
```` c
if (encendido == true)
    ;
return caracter == '\0'; // Comparación correcta de tipo char
return ptr == NULL;      // Comparación correcta de tipo puntero
while (trabajando == false)
    ;
````
<!-- c -->

(0x1006h)=
## Regla `0x1006h`: No utilizar la instrucción `goto`

El uso de `goto` rompe el flujo de control estructurado, dificultando la lectura y depuración del código. En su lugar, empleá las estructuras de control estándar.

- **Incorrecto:**
````{code-block} c
:linenos:
void procesar_datos(int *datos, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (datos[i] < 0)
        {
            goto error;
        }
    }
error:
    printf("Error: dato negativo encontrado.\n");
}
````
<!-- {code-block} c -->
- **Correcto:**
````{code-block} c
:linenos:
bool procesar_datos(int *datos, size_t n)
{
    bool exito = true;
    for (size_t i = 0; i < n && exito; i++)
    {
        if (datos[i] < 0)
        {
            exito = false;
        }
    }
    if (!exito)
    {
        printf("Error: dato negativo encontrado.\n");
    }
    return exito;
}
````
<!-- {code-block} c -->

(0x1007h)=
## Regla `0x1007h`: No utilizar el operador condicional (ternario) `?:`

Aunque compacto, el operador ternario reduce la legibilidad del código, especialmente en expresiones anidadas o complejas.

- **Incorrecto:**
  ```c
  int resultado = (a > b) ? a : b;
  ```
- **Correcto:**
  ```c
  int resultado;
  if (a > b)
  {
      resultado = a;
  }
  else
  {
      resultado = b;
  }
  ```

(0x1008h)=
## Regla `0x1008h`: Toda instrucción `switch` debe incluir un caso `default`

Para garantizar un comportamiento predecible y robusto, toda instrucción `switch` debe finalizar con un bloque `default`. Esto asegura que el programa maneje explícitamente cualquier valor inesperado. Si un `case` intencionalmente no contiene una instrucción `break` para "caer" (`fall-through`) al siguiente caso, esta intención debe ser documentada con un comentario.

````{code-block} c
:linenos:
switch (opcion)
{
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
````
<!-- {code-block} c -->

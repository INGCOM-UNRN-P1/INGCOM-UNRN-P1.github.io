---
title: Funciones y Modularización
short_title: Funciones
subtitle: Reglas de estilo para el diseño y documentación de funciones en C
---

(0x20XXh)=
# 3. Funciones y Modularización (`0x20XX`)

(0x2001h)=
## Regla `0x2001h`: Las funciones deben usar cláusulas de guarda y retornos anticipados para evitar la anidación profunda

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
## Regla `0x2002h`: Las funciones no deben contener `printf` o `scanf`, a menos que ese sea su propósito explícito

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
## Regla `0x2003h`: Todas las funciones deben incluir documentación completa y estructurada

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
## Regla `0x2004h`: No se permite el uso de variables globales

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
## Regla `0x2005h`: Cada función debe tener una única responsabilidad (Principio de Responsabilidad Única)

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
## Regla `0x2006h`: Una aserción por cada función de prueba

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
## Regla `0x2007h`: Mantené el alcance de las variables al mínimo posible

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
## Regla `0x2008h`: Los valores de retorno numéricos deben definirse como constantes de preprocesador o `enum`s

El uso de nombres descriptivos para los valores de retorno numéricos facilita la comprensión de su significado semántico.

```diff
-return -1;
+return ERROR_APERTURA_ARCHIVO;
```

(0x2009h)=
## Regla `0x2009h`: Los ejercicios deben ser resueltos mediante funciones

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
## Regla `0x200Ah`: Los nombres de funciones y procedimientos deben usar `snake_case` en minúsculas

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

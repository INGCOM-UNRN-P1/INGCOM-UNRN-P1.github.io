---
title: 'Ejercicios: Creación de Librerías de Funciones'
short_title: '7. Librerías de Funciones'
subtitle: 'Diseño, encapsulamiento e implementación de módulos reutilizables en C'
---

# Ejercicios: Creación de Librerías de Funciones

## Acerca de

La creación de librerías de funciones (módulos reutilizables) permite estructurar
programas de forma limpia, probable y mantenible. 

Para resolver los siguientes ejercicios se recomienda utilizar como base la [**Plantilla para Librerías de la Cátedra (UNRN)**](https://github.com/INGCOM-UNRN-P1/plantilla-libreria), organizando el proyecto con la siguiente estructura modular:

- **`include/`**: Archivos de cabecera (`.h`) públicos con los prototipos, guardas de inclusión (`#ifndef...`) y documentación.
- **`src/`**: Archivos de implementación (`.c`) con la lógica y funciones auxiliares ocultas mediante `static`.
- **`examples/`**: Programas de demostración con `main()` que consumen la librería.
- **`tests/`**: Suite de pruebas unitarias para validar las pre/postcondiciones.
- **`Makefile`**: Automatización para compilar (`make`), probar (`make test`), ejecutar (`make run`) y limpiar (`make clean`).

Asimismo, mediante el script `./manage.sh` (`rename`, `add-module`, `build`, `test`) podés administrar la librería y posteriormente integrarla en proyectos más grandes o TPs usando `./tp.sh add-lib <nombre_libreria> <url_git>`.

En este bloque de ejercicios vas a diseñar módulos temáticos independientes, definiendo interfaces claras y contratos robustos (precondiciones, postcondiciones y códigos de estado).

### Capítulos de Apunte Correspondientes
- {ref}`capitulo-funciones-descomposicion`
- [Compilación](../../apunte/bloque_2_proyectos/1_compilacion.md)

---

## 1. Librerías Matemáticas y Numéricas

(ejercicio_7_1)=
### Ejercicio 7.1 - Librería de Operaciones Geométricas 2D ⭐⭐☆☆☆

Diseñá e implementá la librería `geometria2d.h` y `geometria2d.c` para cálculos en el plano 2D:
- `double geo_distancia(double x1, double y1, double x2, double y2)`: distancia euclídea.
- `double geo_area_rectangulo(double ancho, double alto)`: área de un rectángulo.
- `double geo_perimetro_rectangulo(double ancho, double alto)`: perímetro de un rectángulo.
- `double geo_area_circulo(double radio)`: área de un círculo.
- `double geo_perimetro_circulo(double radio)`: perímetro de un círculo.

:::{hint} Lógica y Consideraciones
- **[*plus ultra*]:** Validar que dimensiones como radio, ancho y alto no sean negativas (retornar `-1.0` en caso de error).
- Usá la constante `M_PI` definida en `<math.h>`.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_2)=
### Ejercicio 7.2 - Librería de Conversión de Unidades ⭐⭐☆☆☆

Creá el módulo `conversiones.h` y `conversiones.c` para realizar transformaciones de unidades:
- `double conv_celsius_a_fahrenheit(double c)`
- `double conv_fahrenheit_a_celsius(double f)`
- `double conv_kmh_a_ms(double kmh)`
- `double conv_ms_a_kmh(double ms)`
- `double conv_grados_a_radianes(double deg)`
- `double conv_radianes_a_grados(double rad)`

:::{hint} Lógica y Consideraciones
- Mantendré firmas limpias e independientes de I/O.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_3)=
### Ejercicio 7.3 - Librería de Estadística Básica ⭐⭐⭐☆☆

Diseñá `estadistica.h` y `estadistica.c` operando sobre arreglos de `double`:
- `double est_media(const double *datos, size_t n)`
- `double est_varianza(const double *datos, size_t n)`
- `double est_desviacion_estandar(const double *datos, size_t n)`
- `double est_maximo(const double *datos, size_t n)`
- `double est_minimo(const double *datos, size_t n)`

:::{hint} Lógica y Consideraciones
- **[*plus ultra*]:** Validar puntero `NULL` o `n == 0` retornando `NAN` (`math.h`).
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_4)=
### Ejercicio 7.4 - Librería de Números Primos y Factorización ⭐⭐⭐☆☆

Implementá la librería `primos.h` y `primos.c`:
- `bool primo_es_primo(unsigned long n)`
- `unsigned long primo_siguiente(unsigned long n)`
- `size_t primo_contar_en_rango(unsigned long inicio, unsigned long fin)`
- `void primo_factores_primos(unsigned long n, unsigned long *factores, size_t *cant)`

:::{hint} Lógica y Consideraciones
- **[*plus ultra*]:** Optimizar el chequeo de primalidad probando divisores hasta `sqrt(n)`.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_5)=
### Ejercicio 7.5 - Librería de Trigonometría Compleja ⭐⭐⭐☆☆

Diseñá `trigonometria.h` y `trigonometria.c`:
- `double trigo_hipotenusa(double cateto1, double cateto2)`
- `double trigo_angulo_vector(double x, double y)`: ángulo respecto al eje X positivo en radianes.
- `bool trigo_resolver_triangulo_sss(double a, double b, double c, double *alpha, double *beta, double *gamma)`: calcula los 3 ángulos dada la longitud de los 3 lados.

:::{hint} Lógica y Consideraciones
- Usá el teorema del coseno para determinar los ángulos. Devuelve `false` si los lados no forman un triángulo válido.
:::
<!-- {hint} Lógica y Consideraciones -->

---

## 2. Librerías de Manipulación de Texto y Cadenas

(ejercicio_7_6)=
### Ejercicio 7.6 - Biblioteca de Strings seguros ⭐⭐⭐⭐⭐

Reimplementá funciones estándar de `<string.h>` en la librería `seguras.h` y `seguras.c`:
- `int mi_strlen(const char *str, size_t len_str)`
- `void mi_strcpy(char *dest, size_t len_dest, const char *src, size_t len_src)`
- `int mi_strcmp(const char *s1, size_t len_s1, const char *s2, size_t len_s2)`
- `void mi_strcat(char *dest, size_t len_dest, const char *src, size_t len_src)`
- `char *mi_strchr(const char *str, size_t len_str, char c)`

**Orientación:**
- `strlen`: contá hasta `'\0'` o hasta alcanzar `len_str`
- `strcpy`: copiá carácter por carácter respetando los límites de tamaño
- `strcmp`: retorna la diferencia numérica del primer carácter distinto dentro de los límites
- `strcat`: copiá `src` al final de `dest` sin sobrepasar `len_dest`
- `strchr`: retorna puntero a la primera aparición de `c` dentro del límite indicado
- Verificá límites de destino para evitar desbordamientos de búfer.

:::{hint} Lógica y Consideraciones
- **[*plus ultra*]:** Validar punteros `NULL` recibidos como parámetro para evitar fallos de segmentación.
- **[*plus ultra*]:** Implementar una versión utilizando aritmética de punteros en lugar de indexación directa.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_7)=
### Ejercicio 7.7 - Librería de Transformación de Cadenas Seguras ⭐⭐⭐☆☆

Diseñá `str_transform.h` y `str_transform.c`:
- `void str_a_mayusculas(char *str, size_t len_str)`
- `void str_a_minusculas(char *str, size_t len_str)`
- `void str_capitalizar(char *str, size_t len_str)` (primera letra de cada palabra en mayúscula)
- `void str_invertir(char *str, size_t len_str)`
- `void str_recortar_espacios(char *str, size_t len_str)` (elimina espacios al inicio y al final)

:::{hint} Lógica y Consideraciones
- Usá funciones de `<ctype.h>` como `toupper` y `tolower`.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_8)=
### Ejercicio 7.8 - Librería de Búsqueda y Conteo en Texto ⭐⭐⭐☆☆

Implementá la librería `text_search.h` y `text_search.c`:
- `size_t text_contar_palabras(const char *texto, size_t len_texto)`
- `size_t text_contar_caracter(const char *texto, size_t len_texto, char c)`
- `size_t text_contar_vocales(const char *texto, size_t len_texto)`
- `bool text_es_palindromo(const char *texto, size_t len_texto)`

:::{hint} Lógica y Consideraciones
- Para comprobar palíndromos podés ignorar diferencias entre mayúsculas y minúsculas y caracteres no alfabéticos.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_9)=
### Ejercicio 7.9 - Librería de Formateo y Padding de Texto ⭐⭐⭐☆☆

Diseñá `str_format.h` y `str_format.c`:
- `bool str_pad_left(const char *src, size_t len_src, char *dest, size_t dest_size, size_t total_len, char pad_char)`
- `bool str_pad_right(const char *src, size_t len_src, char *dest, size_t dest_size, size_t total_len, char pad_char)`
- `bool str_centrar(const char *src, size_t len_src, char *dest, size_t dest_size, size_t total_len, char pad_char)`

:::{hint} Lógica y Consideraciones
- Garantizá siempre la terminación de la cadena resultante con `'\0'`. Retorná `false` si `dest_size` no alcanza.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_10)=
### Ejercicio 7.10 - Librería de Sanitización e Inspección de Entradas ⭐⭐⭐☆☆

Creá `sanitizer.h` y `sanitizer.c`:
- `bool san_es_entero_valido(const char *str, size_t len_str)`
- `bool san_es_decimal_valido(const char *str, size_t len_str)`
- `bool san_es_email_basico(const char *str, size_t len_str)` (presencia de `@` y al menos un `.`)
- `void san_reemplazar_caracter(char *str, size_t len_str, char viejo, char nuevo)`

:::{hint} Lógica y Consideraciones
- Utilizá esta librería para validar la entrada ingresada por el usuario antes de convertirla a tipos numéricos.
:::
<!-- {hint} Lógica y Consideraciones -->

---

## 3. Librerías de Manejo de Arreglos y Matrices

(ejercicio_7_11)=
### Ejercicio 7.11 - Librería de Vectores de Enteros ⭐⭐⭐☆☆

Diseñá la librería `vec_int.h` y `vec_int.c` para operar sobre arreglos estáticos de enteros:
- `void vec_int_imprimir(const int *v, size_t n)`
- `int vec_int_suma(const int *v, size_t n)`
- `double vec_int_promedio(const int *v, size_t n)`
- `ssize_t vec_int_buscar_primero(const int *v, size_t n, int elem)`
- `size_t vec_int_contar_ocurrencias(const int *v, size_t n, int elem)`

:::{hint} Lógica y Consideraciones
- Usá `ssize_t` para devolver `-1` cuando el elemento buscado no se encuentre.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_12)=
### Ejercicio 7.12 - Librería de Ordenamiento y Búsqueda ⭐⭐⭐⭐☆

Creá `sort_search.h` y `sort_search.c`:
- `void sort_burbuja(int *v, size_t n)`
- `void sort_seleccion(int *v, size_t n)`
- `void sort_insercion(int *v, size_t n)`
- `ssize_t busqueda_binaria(const int *v, size_t n, int elem)`

:::{hint} Lógica y Consideraciones
- Recordá que `busqueda_binaria` requiere que el arreglo esté previamente ordenado.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_13)=
### Ejercicio 7.13 - Librería de Operaciones sobre Matrices 2D ⭐⭐⭐⭐☆

Diseñá `matriz2d.h` y `matriz2d.c` para matrices con dimensiones fijas o pasadas linealmente:
- `void mat_sumar(size_t filas, size_t cols, const double A[filas][cols], const double B[filas][cols], double C[filas][cols])`
- `void mat_multiplicar_escalar(size_t filas, size_t cols, double M[filas][cols], double escalar)`
- `void mat_transponer(size_t filas, size_t cols, const double A[filas][cols], double T[cols][filas])`
- `double mat_traza(size_t n, const double A[n][n])`

:::{hint} Lógica y Consideraciones
- Usá VLA (Variable Length Arrays) en los parámetros para permitir sintaxis limpia de matrices 2D en C99+.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_14)=
### Ejercicio 7.14 - Librería de Manipulación de Conjuntos sobre Arreglos ⭐⭐⭐⭐☆

Implementá `conjunto_arr.h` y `conjunto_arr.c`:
- `size_t conj_union(const int *A, size_t nA, const int *B, size_t nB, int *C)`
- `size_t conj_interseccion(const int *A, size_t nA, const int *B, size_t nB, int *C)`
- `size_t conj_diferencia(const int *A, size_t nA, const int *B, size_t nB, int *C)`
- `bool conj_pertenece(const int *A, size_t nA, int elem)`

:::{hint} Lógica y Consideraciones
- Las funciones retornan la cantidad efectiva de elementos colocados en el arreglo resultado `C`.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_15)=
### Ejercicio 7.15 - Librería de Filtro y Reducción (Map / Filter / Reduce) ⭐⭐⭐⭐☆

Creá `array_utils.h` y `array_utils.c` aplicando punteros a funciones:
- `size_t arr_filtrar(const int *src, size_t n, int *dest, bool (*criterio)(int))`
- `void arr_mapear(int *v, size_t n, int (*transformacion)(int))`
- `int arr_reducir(const int *v, size_t n, int valor_inicial, int (*acumulador)(int, int))`

:::{hint} Lógica y Consideraciones
- Demostrá el uso de firmas con punteros a función para hacer las utilidades genéricas a nivel algorítmico.
:::
<!-- {hint} Lógica y Consideraciones -->

---

## 4. Librerías de Utilidades del Sistema y E/S

(ejercicio_7_16)=
### Ejercicio 7.16 - Librería de Validación de Entradas de Usuario ⭐⭐☆☆☆

Diseñá `input_val.h` y `input_val.c` para simplificar la lectura segura desde `stdin`:
- `int leer_entero_rango(const char *mensaje, size_t len_msg, int min, int max)`
- `double leer_double_positivo(const char *mensaje, size_t len_msg)`
- `bool leer_confirmacion_s_n(const char *mensaje, size_t len_msg)`
- `void leer_cadena_segura(const char *mensaje, size_t len_msg, char *buffer, size_t tam)`

:::{hint} Lógica y Consideraciones
- Limpiá el búfer de entrada `stdin` ante errores de formato para evitar lazos infinitos.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_17)=
### Ejercicio 7.17 - Librería de Fechas y Calendario ⭐⭐⭐☆☆

Creá `fechas.h` y `fechas.c`:
- `bool fecha_es_bisiesto(int anio)`
- `bool fecha_es_valida(int dia, int mes, int anio)`
- `int fecha_dias_del_mes(int mes, int anio)`
- `int fecha_diferencia_dias(int d1, int m1, int a1, int d2, int m2, int a2)`

:::{hint} Lógica y Consideraciones
- Tené en cuenta años bisiestos (divisibles por 4 y no por 100, salvo divisibles por 400).
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_18)=
### Ejercicio 7.18 - Librería de Consola y Formato de Salida ⭐⭐☆☆☆

Diseñá `console_ui.h` y `console_ui.c`:
- `void ui_limpiar_pantalla(void)`
- `void ui_imprimir_titulo(const char *titulo, size_t len_titulo, char adorno)`
- `void ui_imprimir_barra_progreso(size_t actual, size_t total, int ancho)`
- `void ui_esperar_tecla(void)`

:::{hint} Lógica y Consideraciones
- Empleá secuencias de escape ANSI cuando sea posible para el control del terminal de forma portable.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_19)=
### Ejercicio 7.19 - Librería de Medición de Tiempos de Ejecución ⭐⭐⭐☆☆

Implementá `cronometro.h` y `cronometro.c`:
- `void crono_iniciar(void)`
- `double crono_detener_ms(void)`
- `double crono_lapso_ms(void)`

:::{hint} Lógica y Consideraciones
- Utilizá `clock()` de `<time.h>` o `clock_gettime()` para medir el tiempo transcurrido en milisegundos.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_20)=
### Ejercicio 7.20 - Librería de Generación Numérica Pseudoaleatoria ⭐⭐⭐☆☆

Creá `azar.h` y `azar.c`:
- `void azar_inicializar(unsigned int semilla)`
- `int azar_entero_en_rango(int min, int max)`
- `double azar_double_0_1(void)`
- `bool azar_probabilidad(double p)` (retorna `true` con probabilidad `p` entre 0.0 y 1.0)
- `void azar_desordenar_arreglo(int *v, size_t n)`

:::{hint} Lógica y Consideraciones
- Encapsulá `rand()` y `srand()` de `<stdlib.h>` asegurando una distribución uniforme mediante operaciones adecuadas.
:::
<!-- {hint} Lógica y Consideraciones -->

---

## 5. Librerías de Simulación y Dominios Específicos

(ejercicio_7_21)=
### Ejercicio 7.21 - Librería de Física: Cinemática ⭐⭐☆☆☆

Diseñá `fisica_cinematica.h` y `fisica_cinematica.c`:
- `double fis_posicion_mru(double x0, double v, double t)`
- `double fis_posicion_mruv(double x0, double v0, double a, double t)`
- `double fis_velocidad_mruv(double v0, double a, double t)`
- `double fis_tiempo_caida_libre(double altura, double g)`

:::{hint} Lógica y Consideraciones
- Definí una constante adecuada para la aceleración de la gravedad $g = 9.81$.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_22)=
### Ejercicio 7.22 - Librería de Finanzas Básicas ⭐⭐☆☆☆

Creá `finanzas.h` y `finanzas.c`:
- `double fin_interes_simple(double capital, double tasa, double tiempo)`
- `double fin_interes_compuesto(double capital, double tasa, int periodos)`
- `double fin_cuota_prestamo(double capital, double tasa_mensual, int meses)`
- `double fin_valor_futuro_anualidad(double cuota, double tasa, int periodos)`

:::{hint} Lógica y Consideraciones
- Usá `pow()` de `<math.h>` para los cálculos con exponencial.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_23)=
### Ejercicio 7.23 - Librería de Geometría 3D ⭐⭐⭐☆☆

Diseñá `geometria3d.h` y `geometria3d.c`:
- `double geo3d_volumen_esfera(double radio)`
- `double geo3d_area_esfera(double radio)`
- `double geo3d_volumen_cilindro(double radio, double altura)`
- `double geo3d_volumen_cono(double radio, double altura)`
- `double geo3d_distancia_puntos(double x1, double y1, double z1, double x2, double y2, double z2)`

:::{hint} Lógica y Consideraciones
- Verificá que el radio y la altura sean mayores a 0.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_24)=
### Ejercicio 7.24 - Librería de Conversión de Bases Numéricas ⭐⭐⭐☆☆

Implementá `bases.h` y `bases.c`:
- `bool base_dec_a_binario(unsigned int dec, char *buf, size_t buf_size)`
- `bool base_dec_a_hex(unsigned int dec, char *buf, size_t buf_size)`
- `unsigned int base_binario_a_dec(const char *bin_str, size_t len_str)`
- `unsigned int base_hex_a_dec(const char *hex_str, size_t len_str)`

:::{hint} Lógica y Consideraciones
- Asegurá la validación de los caracteres recibidos en las cadenas fuente.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_25)=
### Ejercicio 7.25 - Librería de Criptografía Clásica ⭐⭐⭐☆☆

Diseñá `cripto_simple.h` y `cripto_simple.c`:
- `void cripto_cesar_cifrar(char *texto, size_t len_texto, int desplazamiento)`
- `void cripto_cesar_descifrar(char *texto, size_t len_texto, int desplazamiento)`
- `void cripto_xor_transformar(char *texto, size_t len_texto, char clave)`

:::{hint} Lógica y Consideraciones
- El cifrado César debe mantener las letras minúsculas y mayúsculas en sus respectivos rangos alfabéticos.
:::
<!-- {hint} Lógica y Consideraciones -->

---

## 6. Librerías Avanzadas y Estructuración Compleja

(ejercicio_7_26)=
### Ejercicio 7.26 - Librería de Manejo de Colores y Espacios RGB/HSL ⭐⭐⭐☆☆

Creá `color_utils.h` y `color_utils.c`:
- `unsigned long color_rgb_a_hex(unsigned char r, unsigned char g, unsigned char b)`
- `void color_hex_a_rgb(unsigned long hex, unsigned char *r, unsigned char *g, unsigned char *b)`
- `void color_rgb_a_hsl(unsigned char r, unsigned char g, unsigned char b, double *h, double *s, double *l)`

:::{hint} Lógica y Consideraciones
- Usá operadores de desplazamiento de bits (`<<`, `>>`) y máscaras binarias (`&`).
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_27)=
### Ejercicio 7.27 - Librería de Evaluación de Expresiones lógicas ⭐⭐⭐⭐☆

Diseñá `eval_logica.h` y `eval_logica.c`:
- `bool eval_and_3(bool a, bool b, bool c)`
- `bool eval_or_3(bool a, bool b, bool c)`
- `bool eval_xor(bool a, bool b)`
- `bool eval_implicacion(bool p, bool q)`
- `bool eval_equivalencia(bool p, bool q)`

:::{hint} Lógica y Consideraciones
- Expresá las tablas de verdad en funciones puras sin efectos secundarios.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_28)=
### Ejercicio 7.28 - Librería de Gestión de Bitmask y Flags ⭐⭐⭐⭐☆

Implementá `bitmask.h` y `bitmask.c`:
- `void bit_set(unsigned int *mask, int bit)`
- `void bit_clear(unsigned int *mask, int bit)`
- `void bit_toggle(unsigned int *mask, int bit)`
- `bool bit_check(unsigned int mask, int bit)`
- `void bit_imprimir_binario(unsigned int mask)`

:::{hint} Lógica y Consideraciones
- Asegurá que `bit` esté dentro del rango válido de bits del tipo entero (`0` a `31`).
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_29)=
### Ejercicio 7.29 - Librería de Manejo de Registro de Logs ⭐⭐⭐⭐☆

Diseñá `logger.h` y `logger.c`:
- `typedef enum { LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR } log_nivel_t`
- `void log_set_nivel_minimo(log_nivel_t nivel)`
- `void log_mensaje(log_nivel_t nivel, const char *modulo, size_t len_mod, const char *mensaje, size_t len_msg)`

:::{hint} Lógica y Consideraciones
- Los mensajes con un nivel inferior al nivel mínimo configurado deben ser ignorados.
:::
<!-- {hint} Lógica y Consideraciones -->

---

(ejercicio_7_30)=
### Ejercicio 7.30 - Librería de Verificación de Integridad (Checksum) ⭐⭐⭐⭐⭐

Creá `checksum.h` y `checksum.c`:
- `unsigned char chk_luhn_calcular(const char *digitos, size_t len_digitos)`: algoritmo de Luhn para números de tarjeta/identificación.
- `bool chk_luhn_validar(const char *digitos, size_t len_digitos)`
- `unsigned char chk_suma_paridad(const unsigned char *datos, size_t len)`
- `uint16_t chk_fletcher16(const unsigned char *datos, size_t len)`

:::{hint} Lógica y Consideraciones
- **[*plus ultra*]:** Validar que `datos` no sea `NULL` y manejar adecuadamente los desbordamientos intermedios.
:::
<!-- {hint} Lógica y Consideraciones -->

---

## Notas Finales

:::{tip} Diseño de Librerías y Estructura del Proyecto
- **Estructura limpia:** Ubicá los archivos `.h` en `include/` y los `.c` en `src/`.
- **Ejemplos y Tests:** Agregá un programa de prueba en `examples/` y pruebas unitarias en `tests/`.
- **Automatización:** Proveé un `Makefile` con los objetivos `make`, `make test`, `make run` y `make clean`.
- **Guardas de inclusión:** Usá siempre `#ifndef NOMBRE_H`, `#define NOMBRE_H` y `#endif` en cada cabecera.
- **Encapsulamiento:** Ocultá funciones auxiliares usando la palabra clave `static` dentro del archivo `.c` en `src/`.
- **Prefijos de funciones:** Utilizá prefijos en los nombres de las funciones (ej. `geo_`, `str_`, `mat_`) para evitar colisiones de nombres.
:::
<!-- {tip} Diseño de Librerías y Estructura del Proyecto -->

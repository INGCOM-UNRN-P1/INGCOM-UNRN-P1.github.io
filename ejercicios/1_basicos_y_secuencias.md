---
title: Ejercicios Básicos y Secuencias
short_title: 1. Básicos
---

## Acerca de

Estos ejercicios están diseñados para afianzar los conceptos más fundamentales
de la programación en C. A través de ellos, practicarás el uso de variables, la
entrada y salida por consola, y la implementación de estructuras de control
básicas como lazos y condicionales para resolver problemas simples y generar
secuencias numéricas.

### Consideraciones Generales

1.  **Función Principal**: La lógica principal que resuelve cada enunciado debe
    estar contenida en una función, incluso si no se especifica explícitamente.
2.  **Estilo**: Todo el código debe adherirse a la
    [guía de estilo](../apunte/0_estilo.md) de la cátedra.
3.  **Entrada y Salida**: Separá la lógica de tu programa de las operaciones de
    entrada/salida. Las funciones principales no deben interactuar directamente
    con el usuario, a menos que ese sea su propósito específico.

### Cuestiones de Estilo Aplicables

Para resolver estos ejercicios, es fundamental prestar atención a las siguientes
reglas de estilo, que sientan las bases para un código limpio y mantenible:

- **Claridad y Nombrado**:

  - {ref}`0x0000h`: El código debe ser, ante todo, claro y prolijo.
  - {ref}`0x0001h`: Usá nombres de variables y funciones que describan su
    propósito (ej. `grados_celsius` en lugar de `c`).
  - {ref}`0x0017h`: Nombrá tus funciones en `snake_case` (ej.
    `calcular_area_triangulo`).

- **Estructura y Formato**:

  - {ref}`0x0002h` y {ref}`0x0003h`: Declarar e inicializar una variable por
    línea.
  - {ref}`0x0005h`: Siempre usar llaves `{}` para los bloques de `if`, `else` y
    lazos, incluso si contienen una sola línea.
  - {ref}`0x0013h`: Mantener una indentación consistente de 4 espacios.

- **Lógica de Funciones**:

  - {ref}`0x0016h`: Cada ejercicio debe resolverse dentro de una o más
    funciones.
  - {ref}`0x0009h`: Las funciones que realizan cálculos (ej.
    `convertir_temperatura`) no deben contener `printf` ni `scanf`. La
    entrada/salida se maneja en `main`.
  - {ref}`0x0008h`: Cada función debe tener un único punto de salida (`return`).
  - {ref}`0x000Ah`: Documentar cada función explicando qué hace, sus parámetros
    y lo que retorna.

- **Control de Flujo y Condiciones**:
  - {ref}`0x0006h`: No usar `break` ni `continue`. Controlar los lazos con
    variables bandera si es necesario.
  - {ref}`0x0010h`: Las condiciones deben ser explícitas (usar `contador != 0`
    en lugar de `contador`).

## 1.1: Cuenta regresiva

Este ejercicio sirve para practicar la implementación de un lazo simple con una
pausa.

Imprimir una cuenta regresiva desde un número dado. Pueden usar `sleep(1)` de
`stdlib.h` para que la cuenta no sea instantánea.

```{code-block}
:caption: Entrada de ejemplo
:name: 1-1-entrada
3
```

```{code-block}
:caption: Salida esperada
:name: 1-1-salida
3...
2...
1...
¡Lanzamiento!
```

## 0.0: Básicos

### 1.1 - ¡Hola mundo!

Porque hay que empezar por algún lado, escribir un programa que imprima \"Hola,
mundo!\" en la pantalla.

Este ejercicio nos permitirá verificar el que el entorno de programación
funciona.

```{code} text
:caption: El indispensable Hola Mundo!
:filename: salida

Hola mundo!

```

### 1.2 - Saludador

Escribir un programa que salude por nombre.

```{code} text
:filename: entrada

Martin

```

```{code} text
:caption: El mejorado Hola Mundo!
:filename: salida

Hola mundo, Martin!

```

## 1.2: Secuencias de Pares e Impares

### 1.2.1: Pares en un rango

Imprimir la secuencia de números pares dentro de un rango `[n, m]`.

- **Entrada:** `n=10`, `m=15`
- **Salida:** `10, 12, 14`

### 1.2.2: Primeros N Impares

Imprimir la secuencia de números impares desde 1 hasta `n`.

- **Entrada:** `n=9`
- **Salida:** `1, 3, 5, 7, 9`

## 1.3: Operaciones con Rangos Numéricos

### 1.3.1: Secuencia Ascendente

Mostrar los números en el rango `[n, m)` (desde `n` inclusive hasta `m` no
inclusive).

### 1.3.2: Secuencia Descendente

Mostrar los números en el rango `(m, n]` (desde `n` inclusive hasta `m` no
inclusive).

### 1.3.3: Sumatoria

Calcular la suma de los números en el rango `[n, m]`. La operación matemática
es:

$$ \sum\_{i=n}^{m} i $$

### 1.3.4: Suma de Cuadrados

Calcular la suma de los cuadrados de los números en el rango `[n, m]`. La
operación matemática es:

$$ \sum\_{i=n}^{m} i^2 $$

## 1.4: Par o Impar

Dado un número entero, determinar si es par o impar. Un número $n$ se considera
**par** si es un múltiplo de 2, lo que se verifica con la condición
$n \pmod 2 = 0$.

## 1.5: Signo de un Número

Dado un número real, clasificarlo como positivo, negativo o cero.

## 1.6: Fórmulas Geométricas

### 1.6.1: Área de Triángulo (Base y Altura)

$$ A = \frac{1}{2} b \cdot h $$
Donde $b$ es la base y $h$ es la altura.

### 1.6.2: Área de Triángulo (Fórmula de Herón)

$$ s = \frac{a+b+c}{2}, \quad A = \sqrt{s(s-a)(s-b)(s-c)} $$
Donde $a, b, c$ son
los lados y $s$ es el semiperímetro.

### 1.6.3: Círculo

- **Área**: $A = \pi r^2$
- **Circunferencia**: $C = 2\pi r$

Donde $r$ es el radio.

### 1.6.4: Trapecio

$$ A = \frac{a+b}{2} h $$
Donde $a$ y $b$ son las bases paralelas y $h$ es la
altura.

### 1.6.5: Polígono Regular

$$ A = \frac{P \cdot a}{2} $$
Donde $P$ es el perímetro y $a$ es la apotema.

### 1.6.6: Rectángulo

$$ A = l \cdot w $$
Donde $l$ es el largo y $w$ es el ancho.

## 1.7: Conversiones de Unidades

### 1.7.1: Temperaturas

- **Celsius a Fahrenheit**: $F = (C \times \frac{9}{5}) + 32$
- **Fahrenheit a Celsius**: $C = (F - 32) \times \frac{5}{9}$
- **Celsius a Kelvin**: $K = C + 273.15$

### 1.7.2: Ángulos a Segundos

Convertir una medida dada en `grados`, `minutos` y `segundos` a su equivalente
total en segundos.

$$ total_segundos = (grados \times 3600) + (minutos \times 60) + segundos $$

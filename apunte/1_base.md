---
title: Fundamentos de Computación y Algoritmos
short_title: 1 - Fundamentos
subtitle: Conceptos básicos antes de programar en C
---

## Introducción

Antes de escribir tu primera línea de código en C, es fundamental comprender
algunos conceptos básicos sobre cómo funcionan las computadoras y cómo
comunicarnos con ellas de manera efectiva. En este apunte, usaremos **Python**
para ilustrar estos conceptos de forma clara y sencilla, aprovechando que vimos
las bases en el curso de ingreso y aprovechando que el lenguaje es excelente
para aprender a pensar como un programador.

:::{important}

Este material es **prerequisito** para el apunte de introducción a C. Asegurate
de comprender estos conceptos antes de avanzar, ya que forman la base de todo lo
que veremos posteriormente.

:::

## ¿Qué es una computadora?

Una computadora es una máquina electrónica diseñada para procesar información de
manera automática, siguiendo instrucciones precisas y explícitas. A diferencia
de los seres humanos, una computadora:

- **No entiende ambigüedades**: necesita instrucciones exactas y sin
  interpretación posible.
- **No tiene intuición**: hace exactamente lo que le decimos, ni más ni menos,
  sin asumir nada.
- **Es extremadamente rápida**: puede ejecutar millones (o incluso miles de
  millones) de instrucciones por segundo.
- **Es absolutamente precisa**: no comete errores de cálculo, aunque sí puede
  ejecutar instrucciones incorrectas que nosotros le proporcionemos.
- **No se cansa**: puede repetir la misma operación millones de veces sin
  degradación en su rendimiento.

:::{note}

Esta característica de precisión absoluta es tanto una fortaleza como una
debilidad. La computadora hará **exactamente** lo que le pidamos, incluso si
está mal. De ahí la importancia de escribir algoritmos correctos.

:::

### Componentes básicos

Para entender cómo programar, es útil conocer los componentes principales de una
computadora y cómo interactúan entre sí.

#### Hardware

El **hardware** son los componentes físicos de la computadora:

- **Procesador (CPU)**: El "cerebro" que ejecuta las instrucciones. Realiza
  operaciones aritméticas, lógicas y de control. Su velocidad se mide en GHz
  (gigahertz).
  
- **Memoria RAM**: Memoria de acceso rápido donde se guardan temporalmente los
  datos y programas mientras se ejecutan. Es **volátil**: se borra cuando se
  apaga la computadora.
  
- **Almacenamiento permanente**: Disco duro (HDD) o unidad de estado sólido
  (SSD) donde se guardan archivos, programas y el sistema operativo de forma
  permanente.
  
- **Dispositivos de entrada**: Permiten introducir información (teclado, mouse,
  micrófono, cámara, sensores, etc.).
  
- **Dispositivos de salida**: Permiten obtener información (pantalla, impresora,
  altavoces, etc.).

```{mermaid}
graph TB
    subgraph "Computadora"
        CPU[CPU/Procesador]
        RAM[Memoria RAM]
        DISK[Almacenamiento]
        
        INPUT[Dispositivos de Entrada]
        OUTPUT[Dispositivos de Salida]
        
        INPUT -->|Datos| CPU
        CPU <-->|Lectura/Escritura Rápida| RAM
        CPU <-->|Lectura/Escritura Lenta| DISK
        CPU -->|Resultados| OUTPUT
    end
    
    style CPU fill:#ff9999
    style RAM fill:#99ccff
    style DISK fill:#99ff99
```

:::{admonition} ¿Por qué necesitamos RAM y disco?
:class: tip

La RAM es muy rápida pero volátil y costosa. El disco es más lento pero
persistente y económico. Esta combinación nos da lo mejor de ambos mundos:
velocidad para ejecutar programas y persistencia para guardar datos.
:::

#### Software

El **software** son los programas e instrucciones que controlan el hardware:

- **Sistema operativo**: Windows, Linux, macOS - el programa fundamental que
  controla el hardware y proporciona servicios básicos a otros programas. Actúa
  como intermediario entre el hardware y las aplicaciones.

- **Programas o aplicaciones**: Word, navegadores web, juegos, etc. Son
  software diseñado para realizar tareas específicas para el usuario.

- **Código fuente**: Las instrucciones que los programadores escriben en
  lenguajes de programación como Python o C. Este código debe ser traducido (compilado o
  interpretado) para que la computadora pueda ejecutarlo.

```{mermaid}
graph TB
    subgraph "Capas de Software"
        APP[Aplicaciones<br/>Word, Chrome, etc.]
        OS[Sistema Operativo<br/>Windows, Linux, macOS]
        HW[Hardware<br/>CPU, RAM, Disco]
        
        APP -->|usa servicios de| OS
        OS -->|controla| HW
    end
    
    style APP fill:#ffcc99
    style OS fill:#99ccff
    style HW fill:#99ff99
```

## ¿Qué es programar?

Programar es el arte y la ciencia de dar instrucciones precisas y detalladas a
una computadora para que realice una tarea específica. Es un proceso creativo
que requiere pensamiento lógico, atención al detalle y práctica constante.

:::{epigraph}
"Programar es pensar, no escribir código."

-- Anónimo
:::

Cuando programamos, debemos considerar:

1. **¿Qué problema queremos resolver?** - Entender claramente el objetivo
2. **¿Qué datos necesitamos?** - Identificar entradas y salidas
3. **¿Qué pasos seguir?** - Diseñar el algoritmo
4. **¿Cómo traducirlo a código?** - Escribir en un lenguaje de programación
5. **¿Funciona correctamente?** - Probar y depurar

### Analogía: La receta de cocina

Imagina que querés hacer un pastel y le das las instrucciones a alguien que
**nunca cocinó** y que seguirá **literalmente** cada palabra que digás:

::::{grid} 1 1 2 2
:gutter: 3

:::{grid-item-card} ❌ Instrucciones vagas (no funcionan)
"Poné un poco de harina, algo de azúcar, mezclá los ingredientes y horneá hasta
que esté listo."

**Problemas:**
- ¿Cuánto es "un poco"?
- ¿Qué otros ingredientes?
- ¿En qué orden?
- ¿A qué temperatura?
- ¿Cuándo está "listo"?
:::

:::{grid-item-card} ✅ Instrucciones precisas (como un programa)
1. Precalentar el horno a 180°C
2. En un bowl, colocar exactamente 200g de harina
3. Agregar exactamente 150g de azúcar
4. Agregar 3 huevos
5. Batir con batidora durante 2 minutos a velocidad media
6. Verter la mezcla en un molde de 20cm de diámetro
7. Hornear durante exactamente 30 minutos
8. Retirar del horno usando guantes

**Características:**
- Cantidades exactas
- Orden específico
- Tiempos definidos
- Sin ambigüedades
:::
::::

La computadora necesita el **segundo tipo de instrucciones**: específicas,
ordenadas, sin ambigüedades y completamente detalladas.

### Ejercicio inicial

:::{exercise} Instrucciones precisas
:label: ex-instrucciones-precisas
:nonumber:

Escribí instrucciones detalladas (como para alguien que nunca lo hizo) para:

1. Hacer un sándwich de jamón y queso
2. Atarse los cordones de las zapatillas
3. Calcular el promedio de tres números

Intentá ser lo más específico posible, sin asumir que la otra persona sabe algo.
:::

:::{solution} ex-instrucciones-precisas
:class: dropdown

**Hacer un sándwich de jamón y queso:**

1. Tomar 2 rebanadas de pan del paquete
2. Colocar ambas rebanadas sobre una tabla o plato
3. Tomar una rebanada de jamón del paquete
4. Colocar el jamón sobre una de las rebanadas de pan
5. Tomar una rebanada de queso del paquete
6. Colocar el queso sobre el jamón
7. Tomar la segunda rebanada de pan
8. Colocarla sobre el queso, con el lado que estaba hacia arriba ahora hacia abajo
9. Presionar suavemente las rebanadas juntas
10. Servir en un plato

**Calcular el promedio de tres números:**

1. Obtener el primer número (llamémoslo A)
2. Obtener el segundo número (llamémoslo B)
3. Obtener el tercer número (llamémoslo C)
4. Sumar los tres números: suma = A + B + C
5. Dividir la suma entre 3: promedio = suma / 3
6. Mostrar el resultado (promedio)
:::

## ¿Qué es un algoritmo?

Un **algoritmo** es una secuencia finita, ordenada y no ambigua de pasos bien
definidos que resuelve un problema o realiza una tarea específica. Los
algoritmos son la base fundamental de la programación.

```{mermaid}
graph LR
    A[Problema] --> B[Algoritmo]
    B --> C[Solución]
    
    style A fill:#ffcccc
    style B fill:#ccccff
    style C fill:#ccffcc
```

:::{important}
Un algoritmo es **independiente** del lenguaje de programación. El mismo
algoritmo puede implementarse en C, Python, Java o cualquier otro lenguaje.
:::

### Características de un buen algoritmo

Un algoritmo efectivo debe cumplir con las siguientes características:

::::{grid} 1 1 2 2
:gutter: 2

:::{grid-item-card} 1. Finito
Debe terminar en algún momento, después de un número finito de pasos.

**Ejemplo:** Un algoritmo que busca un nombre en una lista debe terminar después
de revisar todos los elementos, no puede buscar infinitamente.
:::

:::{grid-item-card} 2. Bien definido
Cada paso debe ser claro, preciso y sin ambigüedades.

**Ejemplo:** En lugar de "agregar algunos huevos", debe decir "agregar 3 huevos".
:::

:::{grid-item-card} 3. Con entrada (opcional)
Puede recibir cero o más datos iniciales.

**Ejemplo:** Un algoritmo para sumar dos números recibe dos números como entrada.
:::

:::{grid-item-card} 4. Con salida
Debe producir al menos un resultado.

**Ejemplo:** El resultado de sumar dos números, o un mensaje indicando si un
número es par.
:::

:::{grid-item-card} 5. Efectivo
Cada paso debe ser realizable en un tiempo finito usando recursos finitos.

**Ejemplo:** "multiplicar dos números" es efectivo; "encontrar el número más
grande que existe" no lo es.
:::

:::{grid-item-card} 6. Determinista
Dado el mismo conjunto de entradas, debe producir siempre el mismo resultado.

**Ejemplo:** El algoritmo para sumar 2 + 3 debe dar siempre 5, no a veces 5 y a
veces 6.
:::
::::

### Ejemplo detallado: Algoritmo para hacer café

Veamos un ejemplo cotidiano expresado como algoritmo formal:

```
┌─────────────────────────────────────────┐
│ Algoritmo: Hacer café                   │
├─────────────────────────────────────────┤
│ Entrada: ninguna                        │
│ Salida: una taza de café listo          │
├─────────────────────────────────────────┤
│ Pasos:                                  │
│                                         │
│ 1. Inicio                               │
│ 2. Verificar que haya agua en el        │
│    depósito de la cafetera              │
│ 3. Si NO hay agua:                      │
│    a. Llenar el depósito con 500ml      │
│       de agua                           │
│ 4. Verificar que haya un filtro limpio  │
│ 5. Si NO hay filtro:                    │
│    a. Colocar un filtro nuevo           │
│ 6. Agregar exactamente 2 cucharadas     │
│    (20g) de café molido en el filtro    │
│ 7. Colocar el filtro en la cafetera     │
│ 8. Encender la cafetera                 │
│ 9. Esperar 5 minutos                    │
│ 10. Verificar que la cafetera haya      │
│     terminado (luz apagada)             │
│ 11. Tomar una taza limpia               │
│ 12. Servir el café en la taza           │
│ 13. Fin                                 │
└─────────────────────────────────────────┘
```

```{mermaid}
flowchart TD
    Start([Inicio]) --> CheckWater{¿Hay agua?}
    CheckWater -->|No| AddWater[Llenar con 500ml]
    CheckWater -->|Sí| CheckFilter{¿Hay filtro?}
    AddWater --> CheckFilter
    CheckFilter -->|No| AddFilter[Colocar filtro nuevo]
    CheckFilter -->|Sí| AddCoffee[Agregar 20g de café]
    AddFilter --> AddCoffee
    AddCoffee --> TurnOn[Encender cafetera]
    TurnOn --> Wait[Esperar 5 minutos]
    Wait --> CheckReady{¿Terminó?}
    CheckReady -->|No| Wait
    CheckReady -->|Sí| Serve[Servir en taza]
    Serve --> End([Fin])
    
    style Start fill:#90EE90
    style End fill:#FFB6C1
    style CheckWater fill:#FFE4B5
    style CheckFilter fill:#FFE4B5
    style CheckReady fill:#FFE4B5
```

### Ejemplo matemático: Algoritmo para determinar si un número es par


```
┌─────────────────────────────────────────┐
│ Algoritmo: Verificar si N es par        │
├─────────────────────────────────────────┤
│ Entrada: un número entero N             │
│ Salida: mensaje indicando si es par     │
│         o impar                         │
├─────────────────────────────────────────┤
│ Pasos:                                  │
│                                         │
│ 1. Inicio                               │
│ 2. Pedir al usuario un número N         │
│ 3. Calcular el resto de dividir N / 2   │
│    (llamemos a este resto R)            │
│ 4. Si R es igual a 0:                   │
│    a. Mostrar "N es par"                │
│ 5. Si no (R no es 0):                   │
│    a. Mostrar "N es impar"              │
│ 6. Fin                                  │
└─────────────────────────────────────────┘
```

Este es el algoritmo traducido a código Python.

```python
# 1. Pedir al usuario un número N
# Usamos int() para convertir el texto ingresado a un número entero
n = int(input("Ingrese un número: "))

# 2. Calcular el resto de dividir N / 2
# El operador '%' (módulo) nos da el resto de una división
resto = n % 2

# 3. Si el resto es igual a 0, el número es par
if resto == 0:
    # 3a. Mostrar "N es par"
    print(f"El número {n} es par.")
# 4. Si no, el número es impar
else:
    # 4a. Mostrar "N es impar"
    print(f"El número {n} es impar.")
```

```{mermaid}
flowchart TD
    Start([Inicio]) --> Input[Pedir número N]
    Input --> Calc[Calcular R = N % 2]
    Calc --> Check{R == 0?}
    Check -->|Sí| Even[Mostrar: N es par]
    Check -->|No| Odd[Mostrar: N es impar]
    Even --> End([Fin])
    Odd --> End
    
    style Start fill:#90EE90
    style End fill:#FFB6C1
    style Check fill:#FFE4B5
```

:::{exercise} Escribir algoritmos en Python
:label: ex-algoritmos-1
:nonumber:

Escribí algoritmos en Python para:

1. Encontrar el mayor de tres números
2. Verificar si un año es bisiesto (divisible por 4, pero no por 100, excepto
   si es divisible por 400)
3. Calcular el factorial de un número (n! = n × (n-1) × (n-2) × ... × 1)
:::

:::{solution} ex-algoritmos-1
:class: dropdown

**1. Encontrar el mayor de tres números:**

```python
# Leemos tres números
a = float(input("Ingrese el primer número: "))
b = float(input("Ingrese el segundo número: "))
c = float(input("Ingrese el tercer número: "))

# Opción 1: Usando condicionales
mayor = a
if b > mayor:
    mayor = b
if c > mayor:
    mayor = c

print(f"El mayor número es: {mayor}")

# Opción 2: Usando la función incorporada max()
# mayor = max(a, b, c)
# print(f"El mayor número es: {mayor}")
```

**2. Verificar año bisiesto:**

```python
año = int(input("Ingrese un año: "))

# Un año es bisiesto si es divisible por 4,
# excepto los que son divisibles por 100,
# a menos que también sean divisibles por 400.
if (año % 400 == 0) or (año % 4 == 0 and año % 100 != 0):
    print(f"{año} es un año bisiesto.")
else:
    print(f"{año} no es un año bisiesto.")
```

**3. Calcular factorial:**

```python
n = int(input("Ingrese un número entero positivo: "))

if n < 0:
    print("Error: el factorial no está definido para números negativos.")
elif n == 0:
    print("El factorial de 0 es 1.")
else:
    factorial = 1
    # Usamos un bucle para multiplicar desde 1 hasta n
    for i in range(1, n + 1):
        factorial = factorial * i
    print(f"El factorial de {n} es: {factorial}")
```
:::

## Pensamiento lógico

El pensamiento lógico es la capacidad de razonar de manera coherente y
estructurada. En programación, esto se traduce en tres estructuras fundamentales
que aparecen en todos los algoritmos.

### 1. Secuencia

Las instrucciones se ejecutan **una después de otra**, en el orden exacto en que
están escritas. El orden importa.

```{mermaid}
flowchart TD
    A[Paso 1: Levantarse] --> B[Paso 2: Ir al baño]
    B --> C[Paso 3: Lavarse la cara]
    C --> D[Paso 4: Vestirse]
    D --> E[Paso 5: Desayunar]
    
    style A fill:#e1f5ff
    style B fill:#e1f5ff
    style C fill:#e1f5ff
    style D fill:#e1f5ff
    style E fill:#e1f5ff
```

**Ejemplo de la importancia del orden:**

::::{grid} 1 1 2 2

:::{grid-item-card} ✅ Orden correcto
```python
# 1. Poner agua en la olla
olla = ["agua"]
# 2. Poner la olla en el fuego
fuego_encendido = True
# 3. Esperar que hierva
agua_hirviendo = True
# 4. Agregar fideos
olla.append("fideos")
# 5. Cocinar 10 minutos
# 6. Escurrir
fideos_cocidos = True
```
:::

:::{grid-item-card} ❌ Orden incorrecto
```python
# 1. Poner la olla vacía en el fuego
olla = []
fuego_encendido = True
# 2. Agregar fideos (a la olla vacía)
olla.append("fideos")
# 3. Poner agua
olla.append("agua")
# ... ¡Desastre!
```
:::
::::

:::{warning}

En programación, cambiar el orden de las instrucciones puede cambiar
completamente el resultado o hacer que el programa falle.

:::

### 2. Decisiones (Condicionales)

A veces necesitamos que el programa tome diferentes caminos dependiendo de una
condición. Esto se representa con estructuras `if...elif...else`.

```{mermaid}
flowchart TD
    Start([Inicio]) --> Cond{Condición}
    Cond -->|Verdadero| ActionTrue[Acción si es verdadero]
    Cond -->|Falso| ActionFalse[Acción si es falso]
    ActionTrue --> End([Fin])
    ActionFalse --> End
    
    style Start fill:#90EE90
    style End fill:#FFB6C1
    style Cond fill:#FFE4B5
```

**Ejemplo simple:**

```python
hace_frio = temperatura < 5

if hace_frio:
    print("Ponerme un abrigo")
else:
    print("Usar solo remera")
```

**Ejemplo con condiciones anidadas:**

```python
tengo_hambre = True
hay_comida_en_casa = False

if tengo_hambre:
    if hay_comida_en_casa:
        print("Cocinar")
    else:
        print("Pedir delivery")
else:
    print("Continuar con mis actividades")
```

```{mermaid}
flowchart TD
    Start([Inicio]) --> Hungry{¿Tengo hambre?}
    Hungry -->|Sí| Food{¿Hay comida?}
    Hungry -->|No| Continue[Continuar actividades]
    Food -->|Sí| Cook[Cocinar]
    Food -->|No| Order[Pedir delivery]
    Cook --> End([Fin])
    Order --> End
    Continue --> End
    
    style Start fill:#90EE90
    style End fill:#FFB6C1
    style Hungry fill:#FFE4B5
    style Food fill:#FFE4B5
```

### 3. Repetición (Lazos o Bucles)

Cuando necesitamos hacer algo varias veces, usamos estructuras de repetición. Hay dos tipos principales:

#### Repetición con contador fijo (`for`)

Se usa cuando sabemos cuántas veces queremos repetir una acción.

```python
# Repetir 10 veces
# range(10) genera números del 0 al 9
for i in range(10):
    print(f"Haciendo flexión de brazos número {i + 1}")
```

```{mermaid}
flowchart TD
    Start([Inicio]) --> Init[contador = 1]
    Init --> Check{contador <= 10?}
    Check -->|Sí| Action[Hacer flexión]
    Action --> Inc[contador = contador + 1]
    Inc --> Check
    Check -->|No| End([Fin])
    
    style Start fill:#90EE90
    style End fill:#FFB6C1
    style Check fill:#FFE4B5
```

#### Repetición con condición (`while`)

Se usa cuando la repetición depende de que una condición sea verdadera.

```python
platos_sucios = 3

while platos_sucios > 0:
    print(f"Lavando un plato... Quedan {platos_sucios - 1}")
    platos_sucios = platos_sucios - 1 # ¡Crucial no olvidar esto!

print("¡Todos los platos están limpios!")
```

```{mermaid}
flowchart TD
    Start([Inicio]) --> Check[¿Hay platos<br/>sucios?]
    Check -->|Sí| Action[Lavar un plato]
    Action --> Check
    Check -->|No| End([Fin])

    style Start fill:#90EE90
    style End fill:#FFB6C1
    style Check fill:#FFE4B5
```

:::{exercise} Estructuras de control
:label: ex-estructuras
:nonumber:

Identificá qué estructura de control usarías en cada caso:

1. Verificar si un estudiante aprobó (nota ≥ 4)
2. Sumar todos los números del 1 al 100
3. Preguntar contraseña hasta que sea correcta (máximo 3 intentos)
4. Calcular el precio final con descuento si la compra supera $1000
5. Mostrar los primeros 20 números pares
:::

:::{solution} ex-estructuras
:class: dropdown

1. **Decisión simple (`if`)**: Una condición que verifica la nota.
2. **Repetición con contador (`for`)**: Un bucle que va de 1 a 100.
3. **Repetición con condición Y contador (`while`)**: Un bucle `while` con un contador de intentos.
4. **Decisión simple (`if`)**: Verifica el monto y aplica descuento si corresponde.
5. **Repetición con contador (`for`)**: Un bucle que genera 20 números pares.
:::

## Representación de datos

Las computadoras trabajan con información, y esa información puede ser de
diferentes tipos. Es fundamental entender qué tipos de datos existen y cuándo
usar cada uno.

### Tipos de información fundamentales

#### 1. Números enteros (`int`)

Números sin parte decimal, pueden ser positivos, negativos o cero.

**Ejemplos:**
- `5`, `-3`, `0`, `1000`, `-999`

**Usos comunes:**
- Contar elementos (cantidad de estudiantes, productos, etc.)
- Índices y posiciones en listas
- Edades, años
- Cantidades exactas

**Operaciones:**
- Suma, resta, multiplicación
- División entera: `17 // 5` da como resultado `3`
- Módulo (resto): `17 % 5` da como resultado `2`

::::{grid} 1 1 2 2

:::{grid-item-card} Ejemplos en Python
```python
contador = 10
edad = 25
año = 2024
temperatura = -5
```
:::

:::{grid-item-card} ❌ NO son enteros
```python
# Estos son de tipo float (decimal)
altura = 1.75
precio = 99.99
```
:::
::::

#### 2. Números decimales (`float`)

Números que pueden tener parte decimal (reales o de punto flotante).

**Ejemplos:**
- `3.14`, `-0.5`, `2.718`, `1.0`

**Usos comunes:**
- Mediciones (altura, peso, distancia)
- Cálculos con precisión (física, ingeniería)
- Precios con centavos
- Porcentajes

**Operaciones:**
- Todas las operaciones aritméticas normales
- División siempre da resultado decimal: `17.0 / 5.0` da `3.4`

:::{warning}
Los números decimales en computadora tienen **precisión limitada**. No son
exactos para todos los valores. Por ejemplo, `0.1 + 0.2` puede no dar exactamente
`0.3` debido a la representación binaria interna.
:::

#### 3. Cadenas de texto (`str`)

Secuencia de caracteres (letras, números, símbolos).

**Ejemplos:**
- Se escriben entre comillas simples o dobles: `'Hola'`, `"Mundo"`, `'@'`, `"123"`

**Usos comunes:**
- Nombres, apellidos, direcciones
- Mensajes al usuario
- Datos textuales en general

::::{grid} 1 1 2 2

:::{grid-item-card} Caracteres individuales (son `str` de longitud 1)
```python
inicial = 'M'
signo = '+'
digito = '7'
espacio = ' '
```
:::

:::{grid-item-card} Cadenas de texto
```python
nombre = "María"
mensaje = "Bienvenido"
direccion = "Calle 123"
frase = "Hola mundo"
```
:::
::::

:::{note}
Observá la diferencia entre `'7'` (texto) y `7` (número). El primero es un
símbolo, el segundo es un valor numérico con el que se pueden hacer cálculos.
:::

#### 4. Valores lógicos (`bool`)

Solo pueden tener dos valores: `True` (verdadero) o `False` (falso).

**Usos comunes:**
- Banderas (flags): indicar estados
- Resultados de comparaciones
- Condiciones en estructuras de control

**Ejemplos en Python:**
```python
est_lloviendo = True
tiene_permiso = False
es_mayor_de_edad = True
archivo_existe = False
```

```{mermaid}
graph TD
    subgraph "Valores Booleanos"
        V[True]
        F[False]
    end
    
    C1[5 > 3] --> V
    C2[10 == 10] --> V
    C3[2 > 7] --> F
    C4[nombre == "Juan"] -.-> V
    C4 -.-> F
    
    style V fill:#90EE90
    style F fill:#FFB6C1
```

### Variables: Las cajas de memoria

Una **variable** es un espacio en la memoria de la computadora donde guardamos
información. Podemos pensar en ella como una caja etiquetada.

```
┌─────────────────────┐
│  edad               │  ← nombre de la variable (etiqueta)
│  tipo: int          │  ← tipo de dato que contiene
│                     │
│     25              │  ← valor actual guardado
└─────────────────────┘
```

**Características fundamentales:**

1. **Nombre (identificador)**: Una palabra que usamos para referirnos a la
   variable
   - Debe ser descriptivo: `edad` es mejor que `x`
   - No puede empezar con número
   - No puede tener espacios ni símbolos especiales (excepto `_`)
   - Distingue mayúsculas: `edad` ≠ `Edad` ≠ `EDAD`

2. **Tipo**: Define qué clase de datos puede almacenar
   - En Python, el tipo es dinámico (se infiere del valor)
   - Determina qué operaciones se pueden hacer

3. **Valor**: El dato actual guardado
   - Puede cambiar durante la ejecución del programa
   - Debe ser compatible con el tipo

```{mermaid}
graph TD
    subgraph "Variable: edad"
        N[Nombre: edad]
        T[Tipo: int]
        V[Valor: 25]
    end
    
    N -.-> |identifica| LOC[Ubicación en Memoria]
    T -.-> |determina| OPS[Operaciones permitidas]
    V -.-> |almacenado en| LOC
    
    style LOC fill:#ffcccc
    style OPS fill:#ccffcc
```

**Ejemplos de variables en Python:**

```python
# Python infiere el tipo de dato automáticamente

# Variable de tipo entero (int)
edad = 20

# Variable de tipo decimal (float)
altura = 1.75

# Variable de tipo texto (str)
nombre = "Ana"

# Variable de tipo booleano (bool)
aprobado = True
```

### El ciclo de vida de una variable

```{mermaid}
sequenceDiagram
    participant P as Programa
    participant M as Memoria
    
    P->>M: 1. Declarar e inicializar (edad = 20)
    Note over M: Se reserva espacio y se guarda 20
    
    P->>M: 2. Usar/Modificar (edad = 21)
    Note over M: El valor en memoria cambia a 21
    
    P->>M: 3. Leer valor (print(edad))
    M->>P: Devolver 21
    
    Note over P,M: Al finalizar el programa...
    P->>M: 4. Liberar memoria
    Note over M: Espacio disponible nuevamente
```

:::{exercise} Identificar tipos de variables
:label: ex-tipos-vars
:nonumber:

Para cada uno de los siguientes datos, indicá qué tipo de variable (`int`, `float`, `str`, `bool`) usarías en Python:

1. Cantidad de estudiantes en una clase
2. Precio de un producto (ej: $19.99)
3. Nombre completo de una persona
4. Si un archivo existe o no
5. Temperatura en grados Celsius (puede ser negativa y con decimales)
6. Día de la semana (ej: "Lunes")
7. Número de identificación (DNI)
8. Calificación con decimales (ej: 7.5)
:::

:::{solution} ex-tipos-vars
:class: dropdown

1. **`int`** - las personas se cuentan en números enteros
2. **`float`** - tiene centavos
3. **`str`** - secuencia de caracteres
4. **`bool`** - solo puede ser `True` o `False`
5. **`float`** - puede tener valores como -3.5, 20.8, etc.
6. **`str`** - nombre del día
7. **`int`** o **`str`** - si no se van a hacer cálculos, `str` es más seguro para no perder ceros a la izquierda. Si es solo numérico, `int`.
8. **`float`** - tiene parte fraccionaria
:::

## Operaciones básicas

Las operaciones son acciones que podemos realizar sobre los datos. Existen
diferentes tipos según el tipo de dato.

### Operaciones aritméticas

Operaciones matemáticas básicas sobre números:

| Operación      | Símbolo | Ejemplo     | Resultado |
| -------------- | ------- | ----------- | --------- |
| Suma           | `+`     | `5 + 3`     | `8`       |
| Resta          | `-`     | `10 - 4`    | `6`       |
| Multiplicación | `*`     | `7 * 2`     | `14`      |
| División       | `/`     | `15 / 3`    | `5.0`     |
| División entera| `//`    | `17 // 5`   | `3`       |
| Módulo (resto) | `%`     | `17 % 5`    | `2`       |
| Potencia       | `**`    | `2 ** 3`    | `8`       |

:::{important}
El **módulo** (`%`) da el resto de la división. Es muy útil para:
- Determinar si un número es par: `n % 2 == 0`
- Obtener el último dígito: `1234 % 10` da `4`
- Ciclos que se repiten cada N elementos
:::

**Orden de operaciones (precedencia):**

Al igual que en matemática, las operaciones tienen un orden de evaluación:

1. Paréntesis `()`
2. Potencias `**`
3. Multiplicación, División, Módulo `*`, `/`, `//`, `%`
4. Suma, Resta `+`, `-`

```python
# Ejemplo: 2 + 3 * 4
#          2 + 12        (primero multiplicación)
#          14            (luego suma)
print(2 + 3 * 4)  # Salida: 14

# Ejemplo: (2 + 3) * 4
#          5 * 4         (primero paréntesis)
#          20            (luego multiplicación)
print((2 + 3) * 4) # Salida: 20
```

:::{exercise} Operaciones aritméticas
:label: ex-aritmeticas
:nonumber:

Calculá el resultado de las siguientes expresiones en Python:

1. `15 + 3 * 2`
2. `(15 + 3) * 2`
3. `20 / 4 - 2`
4. `20 / (4 - 2)`
5. `17 % 3`
6. `100 % 10`
7. `2 * 3 + 4 * 5`
8. `(2 * 3 + 4) * 5`
:::

:::{solution} ex-aritmeticas
:class: dropdown

1. `15 + 3 * 2 = 15 + 6 = 21`
2. `(15 + 3) * 2 = 18 * 2 = 36`
3. `20 / 4 - 2 = 5.0 - 2 = 3.0`
4. `20 / (4 - 2) = 20 / 2 = 10.0`
5. `17 % 3 = 2` (resto de 17 ÷ 3)
6. `100 % 10 = 0` (100 es divisible por 10)
7. `2 * 3 + 4 * 5 = 6 + 20 = 26`
8. `(2 * 3 + 4) * 5 = (6 + 4) * 5 = 10 * 5 = 50`
:::

### Operaciones de comparación

Comparan dos valores y devuelven `True` o `False`:

| Operación       | Símbolo | Ejemplo   | Resultado |
| --------------- | ------- | --------- | --------- |
| Igual a         | `==`    | `5 == 5`  | `True`    |
| Diferente de    | `!=`    | `3 != 7`  | `True`    |
| Mayor que       | `>`     | `8 > 3`   | `True`    |
| Menor que       | `<`     | `2 < 9`   | `True`    |
| Mayor o igual   | `>=`    | `5 >= 5`  | `True`    |
| Menor o igual   | `<=`    | `4 <= 6`  | `True`    |

:::{warning}
Notá que para comparar igualdad se usa `==` (doble igual), no `=` (que es
asignación).

- `x = 5` → **asigna** el valor 5 a x
- `x == 5` → **compara** si x es igual a 5
:::

**Ejemplos:**

```python
edad = 20

print(edad > 18)     # True  (20 es mayor que 18)
print(edad == 20)    # True  (20 es igual a 20)
print(edad < 15)     # False (20 no es menor que 15)
print(edad >= 20)    # True  (20 es mayor o igual a 20)
print(edad != 25)    # True  (20 es diferente de 25)
```

### Operaciones lógicas

Combinan condiciones booleanas:

| Operación        | Símbolo | Significado                             |
| ---------------- | ------- | --------------------------------------- |
| AND (Y lógico)   | `and`   | `True` si AMBAS condiciones lo son      |
| OR (O lógico)    | `or`    | `True` si AL MENOS UNA lo es            |
| NOT (NO lógico)  | `not`   | Invierte el valor (`True` a `False` y viceversa) |

**Tablas de verdad:**

::::{grid} 1 1 3 3

:::{grid-item-card} `and` (Y)
| A     | B     | A `and` B |
| ----- | ----- | --------- |
| True  | True  | True      |
| True  | False | False     |
| False | True  | False     |
| False | False | False     |
:::

:::{grid-item-card} `or` (O)
| A     | B     | A `or` B |
| ----- | ----- | -------- |
| True  | True  | True     |
| True  | False | True     |
| False | True  | True     |
| False | False | False    |
:::

:::{grid-item-card} `not` (NO)
| A     | `not` A |
| ----- | ------- |
| True  | False   |
| False | True    |
:::
::::

**Ejemplos prácticos:**

```python
edad = 20
tiene_dni = True

# ¿Puede votar?
if (edad >= 18) and (tiene_dni == True):
    print("Puede votar")

es_fin_de_semana = False
es_feriado = True

# ¿Hay clases?
if not (es_fin_de_semana or es_feriado):
    print("Hay clases")
else:
    print("No hay clases")

esta_lloviendo = True

# ¿Llevo paraguas?
if not esta_lloviendo:
    print("No es necesario llevar paraguas")
else:
    print("Mejor llevar paraguas")
```

```{mermaid}
graph TD
    subgraph "Ejemplo: ¿Puedo votar?"
        E[edad >= 18] --> Y{and}
        D[tiene_dni] --> Y
        Y --> R[Resultado]
    end
    
    subgraph "Ejemplo: ¿Hay clases?"
        F[es_fin_de_semana] --> O{or}
        H[es_feriado] --> O
        O --> R2[Resultado]
    end
    
    style Y fill:#ffe4b5
    style O fill:#ffe4b5
```

:::{exercise} Operaciones lógicas
:label: ex-logicas
:nonumber:

Evaluá las siguientes expresiones en Python:

1. `(5 > 3) and (10 < 20)`
2. `(7 == 7) or (4 > 8)`
3. `not (3 < 2)`
4. `(10 / 2 == 5) and (10 % 3 == 1)`
5. `(20 > 15) and (8 < 5)`
6. `(5 != 3) or (10 == 11)`
7. `not ((5 > 3) and (2 > 4))`
:::

:::{solution} ex-logicas
:class: dropdown

1. `(5 > 3) and (10 < 20)` -> `True and True` -> **`True`**
2. `(7 == 7) or (4 > 8)` -> `True or False` -> **`True`**
3. `not (3 < 2)` -> `not False` -> **`True`**
4. `(10 / 2 == 5) and (10 % 3 == 1)` -> `(5.0 == 5) and (1 == 1)` -> `True and True` -> **`True`**
5. `(20 > 15) and (8 < 5)` -> `True and False` -> **`False`**
6. `(5 != 3) or (10 == 11)` -> `True or False` -> **`True`**
7. `not ((5 > 3) and (2 > 4))` -> `not (True and False)` -> `not False` -> **`True`**
:::

## Diagramas de flujo

Los **diagramas de flujo** son representaciones gráficas de algoritmos que nos
ayudan a visualizar la lógica del programa de manera clara y estructurada. Siguen
siendo una herramienta universal, independientemente del lenguaje de programación.

### Símbolos estándar

```{mermaid}
graph TD
    subgraph "Símbolos de Diagramas de Flujo"
        A([Inicio/Fin<br/>Terminal])
        B[Proceso<br/>Acción o instrucción]
        C{Decisión<br/>Pregunta Si/No}
        D[/Entrada o Salida<br/>Input/Output/]
        E[Proceso predefinido<br/>Función/Subrutina]
    end
    
    style A fill:#90EE90
    style B fill:#87CEEB
    style C fill:#FFE4B5
    style D fill:#DDA0DD
    style E fill:#F0E68C
```

(La descripción de los símbolos y los diagramas de ejemplo siguen siendo válidos, ya que representan la lógica del algoritmo, no el código).

## De Algoritmos a Código con Python

El **pseudocódigo** es una forma de escribir algoritmos usando lenguaje natural
estructurado. Es un paso intermedio útil. Ahora, veremos cómo traducir esos
algoritmos directamente a **código Python**, que es un lenguaje de programación real
y ejecutable.

### Ejemplo completo 1: Calculadora simple

```python
# Algoritmo: Calculadora Simple
# Descripción: Realiza operaciones básicas entre dos números

print("=== CALCULADORA SIMPLE ===")

# Leer los números y convertirlos a float (decimal)
numero1 = float(input("Ingrese el primer número: "))
numero2 = float(input("Ingrese el segundo número: "))

# Leer la operación
operacion = input("Ingrese la operación (+, -, *, /): ")

# Realizar el cálculo basado en la operación
if operacion == '+':
    resultado = numero1 + numero2
    print(f"Resultado: {numero1} + {numero2} = {resultado}")
elif operacion == '-':
    resultado = numero1 - numero2
    print(f"Resultado: {numero1} - {numero2} = {resultado}")
elif operacion == '*':
    resultado = numero1 * numero2
    print(f"Resultado: {numero1} × {numero2} = {resultado}")
elif operacion == '/':
    # Verificar la división por cero
    if numero2 != 0:
        resultado = numero1 / numero2
        print(f"Resultado: {numero1} ÷ {numero2} = {resultado}")
    else:
        print("Error: No se puede dividir por cero")
else:
    print("Error: Operación no válida")

```

### Ejemplo completo 2: Tabla de multiplicar

```python
# Algoritmo: Tabla de Multiplicar
# Descripción: Muestra la tabla de multiplicar de un número del 1 al 10

print("=== TABLA DE MULTIPLICAR ===")
numero = int(input("Ingrese un número: "))

print(f"Tabla del {numero}:")
print("─────────────────")

# Usamos un bucle 'for' que cuenta desde 1 hasta 10
for contador in range(1, 11):
    resultado = numero * contador
    # f-string para formatear la salida de manera prolija
    print(f"{numero} × {contador} = {resultado}")

```

### Ejemplo completo 3: Adivinar número

```python
# Algoritmo: Adivinar Número
# Descripción: El usuario intenta adivinar un número secreto

import random # Importamos la librería para generar números aleatorios

numero_secreto = random.randint(1, 100) # Número aleatorio entre 1 y 100
intentos_maximos = 5
intentos_realizados = 0
adivinado = False

print("=== ADIVINA EL NÚMERO ===")
print(f"Tenés {intentos_maximos} intentos para adivinar un número entre 1 y 100")

while intentos_realizados < intentos_maximos and not adivinado:
    intentos_realizados += 1
    print(f"\nIntento {intentos_realizados} de {intentos_maximos}:")
    
    intento = int(input("Ingresá tu número: "))
    
    if intento == numero_secreto:
        adivinado = True
        print("¡¡¡FELICITACIONES!!! ¡Adivinaste el número!")
        print(f"Lo lograste en {intentos_realizados} intentos")
    elif intento < numero_secreto:
        print("El número secreto es MAYOR")
    else:
        print("El número secreto es MENOR")

if not adivinado:
    print("\nGame Over. Te quedaste sin intentos.")
    print(f"El número secreto era: {numero_secreto}")
```

:::{exercise} Python
:label: ex-python-2
:nonumber:

Escribí en Python algoritmos para:

1. Convertir temperatura de Celsius a Fahrenheit (F = C × 9/5 + 32)
2. Determinar si tres números pueden formar un triángulo (la suma de dos lados
   debe ser mayor que el tercero)
3. Calcular el Máximo Común Divisor (MCD) de dos números usando el algoritmo de
   Euclides
4. Determinar si una palabra es palíndromo (se lee igual de izquierda a derecha
   que de derecha a izquierda)
:::

:::{solution} ex-python-2
:class: dropdown

**1. Conversión de temperatura:**

```python
def celsius_a_fahrenheit(celsius):
    """Convierte temperatura de Celsius a Fahrenheit."""
    return celsius * 9/5 + 32

# --- Programa principal ---
c = float(input("Ingrese temperatura en Celsius: "))
f = celsius_a_fahrenheit(c)
print(f"{c}°C = {f}°F")
```

**2. Verificar triángulo:**

```python
def es_triangulo(lado1, lado2, lado3):
    """Verifica si tres lados pueden formar un triángulo."""
    return (lado1 + lado2 > lado3) and \
           (lado1 + lado3 > lado2) and \
           (lado2 + lado3 > lado1)

# --- Programa principal ---
l1 = float(input("Lado 1: "))
l2 = float(input("Lado 2: "))
l3 = float(input("Lado 3: "))

if es_triangulo(l1, l2, l3):
    print("Los lados pueden formar un triángulo.")
else:
    print("Los lados NO pueden formar un triángulo.")
```

**3. MCD (Algoritmo de Euclides):**

```python
def mcd(a, b):
    """Calcula el Máximo Común Divisor usando el algoritmo de Euclides."""
    while b != 0:
        a, b = b, a % b
    return a

# --- Programa principal ---
num1 = int(input("Número 1: "))
num2 = int(input("Número 2: "))
print(f"El MCD es: {mcd(num1, num2)}")
```

**4. Palíndromo:**
```python
def es_palindromo(palabra):
    """Verifica si una palabra es un palíndromo."""
    # Preparamos la palabra: minúsculas y sin espacios
    palabra = palabra.lower().replace(" ", "")
    # Comparamos la palabra con su inversa
    return palabra == palabra[::-1]

# --- Programa principal ---
texto = input("Ingrese una palabra o frase: ")
if es_palindromo(texto):
    print(f'"{texto}" es un palíndromo.')
else:
    print(f'"{texto}" no es un palíndromo.')
```
:::

## Ejercicios integradores

:::{exercise} Análisis de algoritmo
:label: ex-integrador-1
:nonumber:

Analizá el siguiente código Python y respondé:

```python
n = int(input("Ingrese un número: "))
suma = 0
i = 1
while i <= n:
    if i % 2 == 0:
        suma = suma + i
    i = i + 1
print(suma)
```

1. ¿Qué hace este algoritmo?
2. Si `n` es 10, ¿cuál es el resultado?
3. Dibujá el diagrama de flujo correspondiente.
4. Modificalo para que sume los números impares en lugar de los pares.
:::

:::{solution} ex-integrador-1
:class: dropdown
1.  **¿Qué hace?** Suma todos los números pares desde 1 hasta `n` inclusive.
2.  **Resultado para n=10:** Suma 2 + 4 + 6 + 8 + 10 = **30**.
3.  **Diagrama de flujo:**
    ```mermaid
    flowchart TD
        Start([Inicio]) --> Input[/Leer n/]
        Input --> Init[suma = 0<br/>i = 1]
        Init --> Loop{i <= n?}
        Loop -->|No| Output[/Escribir suma/]
        Output --> End([Fin])
        Loop -->|Sí| Check{i % 2 == 0?}
        Check -->|Sí| Add[suma = suma + i]
        Check -->|No| Inc[i = i + 1]
        Add --> Inc
        Inc --> Loop
    ```
4.  **Modificación para impares:** Cambiar `if i % 2 == 0:` por `if i % 2 != 0:`.
    ```python
    n = int(input("Ingrese un número: "))
    suma = 0
    i = 1
    while i <= n:
        if i % 2 != 0: # <-- Cambio aquí
            suma = suma + i
        i = i + 1
    print(suma)
    ```
:::


## Errores comunes y cómo evitarlos

### 1. Secuencia incorrecta de instrucciones

El orden de las instrucciones es crucial. Un error común es no considerar el
flujo lógico.

::::{grid} 1 1 2 2

:::{grid-item-card} ❌ Incorrecto
```python
# Usa las variables antes de leerlas
resultado = a + b
a = int(input("a: "))
b = int(input("b: "))
print(resultado)
```
**Problema:** `a` y `b` no tienen valor cuando se intenta calcular `resultado`.
:::

:::{grid-item-card} ✅ Correcto
```python
# Lee primero, calcula después
a = int(input("a: "))
b = int(input("b: "))
resultado = a + b
print(resultado)
```
**Solución:** Asegurarse de que las variables tengan un valor antes de usarlas.
:::
::::

### 2. Condiciones mal formuladas

::::{grid} 1 1 2 2

:::{grid-item-card} ❌ Incorrecto
```python
# Más complejo de lo necesario
if edad > 18 or edad == 18:
    print("Mayor de edad")
```
**Problema:** Funciona, pero es redundante.
:::

:::{grid-item-card} ✅ Correcto
```python
# Simplificar condiciones
if edad >= 18:
    print("Mayor de edad")
else:
    print("Menor de edad")
```
**Solución:** Usar los operadores de comparación adecuados para simplificar la lógica.
:::
::::

### 3. Ciclos infinitos

Un ciclo infinito ocurre cuando la condición de salida nunca se cumple.

::::{grid} 1 1 2 2

:::{grid-item-card} ❌ Incorrecto
```python
contador = 1
while contador <= 10:
    print(contador)
    # ¡Olvidamos incrementar contador!
```
Este ciclo nunca termina porque `contador` siempre vale 1.
:::

:::{grid-item-card} ✅ Correcto
```python
contador = 1
while contador <= 10:
    print(contador)
    contador = contador + 1 # o contador += 1
```
**Solución:** Asegurarse de que la variable de control del bucle se modifique para que eventualmente la condición sea falsa.
:::
::::

### 4. Usar variables sin inicializarlas

::::{grid} 1 1 2 2

:::{grid-item-card} ❌ Incorrecto
```python
# ¿Cuánto vale 'suma' al principio?
# Esto dará un error en Python.
suma = suma + 5
```
**Problema:** No se puede modificar una variable que no ha sido creada (inicializada) primero.
:::

:::{grid-item-card} ✅ Correcto
```python
suma = 0 # Inicializamos la variable
suma = suma + 5
print(suma) # Ahora suma vale 5
```
**Solución:** Siempre asignar un valor inicial a las variables antes de usarlas en cálculos.
:::
::::

## La importancia de la práctica

Aprender a programar es como aprender a tocar un instrumento o un deporte:

- **La teoría es importante**, pero no suficiente
- **Necesitás practicar** para desarrollar la habilidad
- **Vas a cometer errores** - y está perfecto, es parte del aprendizaje
- **La constancia** es más importante que la intensidad

:::{tip} Consejo para principiantes

No intentes memorizar todo. Enfocate en **entender la lógica**. Con la práctica,
la sintaxis y los detalles se vuelven naturales.

:::

## Próximos Pasos: El Lenguaje C

Ahora que comprendés estos conceptos fundamentales usando Python, estás mucho mejor preparado para abordar el lenguaje C. En el próximo apunte veremos:

- Cómo escribir estos mismos algoritmos en el lenguaje C
- La sintaxis más estricta y detallada de C
- El proceso de compilación y ejecución de programas
- Variables y tipos de datos estáticos en C
- Estructuras de control (`if`, `while`, `for`) en C

Recordá que toda la lógica que vimos aquí se aplica directamente a C. La principal diferencia será la sintaxis y la necesidad de gestionar la memoria de forma más explícita.

## Glosario básico

:::{glossary}

Algoritmo
: Secuencia finita de pasos precisos que resuelve un problema.

Variable
: Espacio en memoria con un nombre, donde se almacena un valor que puede cambiar.

Tipo de dato
: Categoría que determina qué clase de información puede almacenar una variable
(`int`, `float`, `str`, `bool`, etc.).

Operador
: Símbolo que indica una operación a realizar (`+`, `-`, `*`, `/`, `==`, `>`, `and`, etc.).

Condición
: Expresión que se evalúa como `True` o `False`, usada para tomar decisiones.

Ciclo o Bucle
: Estructura que repite un conjunto de instrucciones (`for`, `while`).

Pseudocódigo
: Forma de escribir algoritmos usando lenguaje natural estructurado, como paso previo a escribir código real.

Diagrama de flujo
: Representación gráfica de un algoritmo usando símbolos estandarizados.

:::

## Recursos adicionales

- Practicá resolviendo problemas simples en Python.
- Dibujá diagramas de flujo antes de empezar a codificar.
- Intentá "ejecutar" tus algoritmos mentalmente o en papel para seguir la lógica.
- Discutí tus soluciones con compañeros - hay muchas formas de resolver un
  problema.

:::{figure}
xkcd-algorithms.png
:alt: XKCD Algorithms
:align: center

Fuente: [xkcd.com](https://xkcd.com/1667/)
:::

---

En el próximo apunte, [](2_gradual.md), comenzaremos a traducir estos conceptos
al lenguaje C y escribiremos nuestros primeros programas.

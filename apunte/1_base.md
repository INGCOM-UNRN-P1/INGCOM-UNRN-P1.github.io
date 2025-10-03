---
title: Fundamentos de Computación y Algoritmos
short_title: 1 - Fundamentos
subtitle: Conceptos básicos antes de programar en C
---

## Introducción

Antes de escribir tu primera línea de código en C, es fundamental comprender
algunos conceptos básicos sobre cómo funcionan las computadoras y cómo
comunicarnos con ellas de manera efectiva. Este apunte te proporcionará las
bases necesarias para comenzar a programar con confianza.

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
  lenguajes de programación como C. Este código debe ser traducido (compilado o
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
│ Algoritmo: Verificar si N es par       │
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

:::{exercise} Escribir algoritmos
:label: ex-algoritmos-1
:nonumber:

Escribí algoritmos detallados (paso a paso) para:

1. Encontrar el mayor de tres números
2. Verificar si un año es bisiesto (divisible por 4, pero no por 100, excepto
   si es divisible por 400)
3. Calcular el factorial de un número (n! = n × (n-1) × (n-2) × ... × 1)
:::

:::{solution} ex-algoritmos-1
:class: dropdown

**1. Encontrar el mayor de tres números:**

```
Algoritmo: Mayor de tres números
Entrada: tres números A, B, C
Salida: el número mayor

1. Inicio
2. Leer A
3. Leer B
4. Leer C
5. Asumir inicialmente que mayor = A
6. Si B > mayor:
   a. mayor = B
7. Si C > mayor:
   a. mayor = C
8. Mostrar "El mayor es:", mayor
9. Fin
```

**2. Verificar año bisiesto:**

```
Algoritmo: Año bisiesto
Entrada: un año (número entero)
Salida: "Es bisiesto" o "No es bisiesto"

1. Inicio
2. Leer año
3. Si (año % 400 == 0):
   a. Mostrar "Es bisiesto"
   b. Ir al paso 8
4. Si (año % 100 == 0):
   a. Mostrar "No es bisiesto"
   b. Ir al paso 8
5. Si (año % 4 == 0):
   a. Mostrar "Es bisiesto"
6. Si no:
   a. Mostrar "No es bisiesto"
7. Fin
```

**3. Calcular factorial:**

```
Algoritmo: Factorial
Entrada: un número entero positivo N
Salida: N! (factorial de N)

1. Inicio
2. Leer N
3. Si N < 0:
   a. Mostrar "Error: número negativo"
   b. Ir al paso 11
4. factorial = 1
5. contador = N
6. Mientras contador > 1:
   a. factorial = factorial × contador
   b. contador = contador - 1
7. Mostrar "El factorial de", N, "es:", factorial
8. Fin
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
1. Poner agua en la olla
2. Poner la olla en el fuego
3. Esperar que hierva
4. Agregar fideos
5. Cocinar 10 minutos
6. Escurrir
:::

:::{grid-item-card} ❌ Orden incorrecto
1. Poner la olla vacía en el fuego
2. Agregar fideos (a la olla vacía)
3. Poner agua
4. Esperar que hierva
5. ...

**¡Desastre!**
:::
::::

:::{warning}
En programación, cambiar el orden de las instrucciones puede cambiar
completamente el resultado o hacer que el programa falle.
:::

### 2. Decisiones (Condicionales)

A veces necesitamos que el programa tome diferentes caminos dependiendo de una
condición. Esto se representa con estructuras **Si...Entonces...Sino**.

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

```
Si hace frío:
    Ponerme un abrigo
Si no:
    Usar solo remera
```

**Ejemplo con condiciones anidadas:**

```
Si tengo hambre:
    Si hay comida en casa:
        Cocinar
    Si no:
        Pedir delivery
Si no:
    Continuar con mis actividades
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

Cuando necesitamos hacer algo varias veces, usamos estructuras de repetición.
Hay dos tipos principales:

#### Repetición con contador fijo

```
Repetir 10 veces:
    Hacer una flexión de brazos
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

#### Repetición con condición

```
Mientras haya platos sucios:
    Lavar un plato
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

1. **Decisión simple (if)**: Una condición que verifica la nota
2. **Repetición con contador**: Bucle que va de 1 a 100
3. **Repetición con condición Y contador**: Bucle while con contador de intentos
4. **Decisión simple**: Verifica el monto y aplica descuento si corresponde
5. **Repetición con contador**: Bucle que genera 20 números pares
:::

## Representación de datos

Las computadoras trabajan con información, y esa información puede ser de
diferentes tipos. Es fundamental entender qué tipos de datos existen y cuándo
usar cada uno.

### Tipos de información fundamentales

#### 1. Números enteros

Números sin parte decimal, pueden ser positivos, negativos o cero.

**Ejemplos:**
- `5`, `-3`, `0`, `1000`, `-999`

**Usos comunes:**
- Contar elementos (cantidad de estudiantes, productos, etc.)
- Índices y posiciones en listas
- Edades, años
- Cantidades exactas

**Operaciones:**
- Suma, resta, multiplicación, división
- División entera: `17 / 5 = 3` (descarta decimales)
- Módulo (resto): `17 % 5 = 2`

::::{grid} 1 1 2 2

:::{grid-item-card} Ejemplos válidos
```
contador = 10
edad = 25
año = 2024
temperatura = -5
```
:::

:::{grid-item-card} ❌ NO son enteros
```
altura = 1.75  (tiene decimales)
precio = 99.99 (tiene decimales)
```
:::
::::

#### 2. Números decimales (reales o de punto flotante)

Números que pueden tener parte decimal.

**Ejemplos:**
- `3.14`, `-0.5`, `2.718`, `1.0`

**Usos comunes:**
- Mediciones (altura, peso, distancia)
- Cálculos con precisión (física, ingeniería)
- Precios con centavos
- Porcentajes

**Operaciones:**
- Todas las operaciones aritméticas normales
- División siempre da resultado decimal: `17.0 / 5.0 = 3.4`

:::{warning}
Los números decimales en computadora tienen **precisión limitada**. No son
exactos para todos los valores. Por ejemplo, 0.1 + 0.2 puede no dar exactamente
0.3 debido a la representación binaria interna.
:::

#### 3. Caracteres y texto

**Carácter individual:**
- Un solo símbolo: letra, número, signo de puntuación
- Se escribe entre comillas simples: `'A'`, `'z'`, `'3'`, `'@'`, `' '` (espacio)

**Cadena de texto (string):**
- Secuencia de caracteres
- Se escribe entre comillas dobles: `"Hola mundo"`, `"Programación en C"`

**Usos comunes:**
- Nombres, apellidos, direcciones
- Mensajes al usuario
- Datos textuales en general

::::{grid} 1 1 2 2

:::{grid-item-card} Caracteres individuales
```
inicial = 'M'
signo = '+'
digito = '7'
espacio = ' '
```
:::

:::{grid-item-card} Cadenas de texto
```
nombre = "María"
mensaje = "Bienvenido"
dirección = "Calle 123"
frase = "Hola mundo"
```
:::
::::

:::{note}
Observá la diferencia entre `'7'` (carácter) y `7` (número). El primero es un
símbolo que representa el dígito, el segundo es el valor numérico.
:::

#### 4. Valores lógicos (booleanos)

Solo pueden tener dos valores: **verdadero** o **falso**.

**Usos comunes:**
- Banderas (flags): indicar estados
- Resultados de comparaciones
- Condiciones en estructuras de control

**Ejemplos:**
```
está_lloviendo = verdadero
tiene_permiso = falso
es_mayor_de_edad = verdadero
archivo_existe = falso
```

```{mermaid}
graph TD
    subgraph "Valores Booleanos"
        V[Verdadero/True]
        F[Falso/False]
    end
    
    C1[5 > 3] --> V
    C2[10 == 10] --> V
    C3[2 > 7] --> F
    C4[nombre == Juan] -.-> V
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
│  tipo: entero       │  ← tipo de dato que contiene
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
   - Una vez definido, no cambia
   - Determina qué operaciones se pueden hacer

3. **Valor**: El dato actual guardado
   - Puede cambiar durante la ejecución del programa
   - Debe ser compatible con el tipo

```{mermaid}
graph TD
    subgraph "Variable: edad"
        N[Nombre: edad]
        T[Tipo: entero]
        V[Valor: 25]
    end
    
    N -.-> |identifica| LOC[Ubicación en Memoria]
    T -.-> |determina| OPS[Operaciones permitidas]
    V -.-> |almacenado en| LOC
    
    style LOC fill:#ffcccc
    style OPS fill:#ccffcc
```

**Ejemplos de variables:**

```
┌─────────────────────┐
│ Variable: edad      │
│ Tipo: entero        │
│ Valor actual: 20    │
└─────────────────────┘

┌─────────────────────┐
│ Variable: altura    │
│ Tipo: decimal       │
│ Valor actual: 1.75  │
└─────────────────────┘

┌─────────────────────┐
│ Variable: nombre    │
│ Tipo: texto         │
│ Valor actual: "Ana" │
└─────────────────────┘

┌──────────────────────┐
│ Variable: aprobado   │
│ Tipo: booleano       │
│ Valor actual: verdad │
└──────────────────────┘
```

### El ciclo de vida de una variable

```{mermaid}
sequenceDiagram
    participant P as Programa
    participant M as Memoria
    
    P->>M: 1. Declarar variable (reservar espacio)
    Note over M: Se reserva espacio en memoria
    
    P->>M: 2. Inicializar (asignar valor inicial)
    Note over M: edad = 0
    
    P->>M: 3. Usar/Modificar
    Note over M: edad = 25
    
    P->>M: 4. Leer valor
    M->>P: Devolver 25
    
    P->>M: 5. Modificar de nuevo
    Note over M: edad = 26
    
    Note over P,M: Al finalizar el programa...
    P->>M: 6. Liberar memoria
    Note over M: Espacio disponible nuevamente
```

:::{exercise} Identificar tipos de variables
:label: ex-tipos-vars
:nonumber:

Para cada uno de los siguientes datos, indicá qué tipo de variable usarías:

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

1. **Entero** - las personas se cuentan en números enteros
2. **Decimal** - tiene centavos
3. **Texto (string)** - secuencia de caracteres
4. **Booleano** - solo puede ser verdadero o falso
5. **Decimal** - puede tener valores como -3.5, 20.8, etc.
6. **Texto (string)** - nombre del día
7. **Entero** - aunque tiene dígitos, es un número entero sin decimales
8. **Decimal** - tiene parte fraccionaria
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
| División       | `/`     | `15 / 3`    | `5`       |
| División entera| `/`     | `17 / 5`    | `3`       |
| Módulo (resto) | `%`     | `17 % 5`    | `2`       |
| Potencia       | `**`    | `2 ** 3`    | `8`       |

:::{important}
El **módulo** (`%`) da el resto de la división. Es muy útil para:
- Determinar si un número es par: `n % 2 == 0`
- Obtener el último dígito: `1234 % 10 = 4`
- Ciclos que se repiten cada N elementos
:::

**Orden de operaciones (precedencia):**

Al igual que en matemática, las operaciones tienen un orden de evaluación:

1. Paréntesis `()`
2. Potencias `**`
3. Multiplicación, División, Módulo `*`, `/`, `%`
4. Suma, Resta `+`, `-`

```
Ejemplo: 2 + 3 * 4
         2 + 12        (primero multiplicación)
         14            (luego suma)

Ejemplo: (2 + 3) * 4
         5 * 4         (primero paréntesis)
         20            (luego multiplicación)
```

:::{exercise} Operaciones aritméticas
:label: ex-aritmeticas
:nonumber:

Calculá el resultado de las siguientes expresiones:

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
3. `20 / 4 - 2 = 5 - 2 = 3`
4. `20 / (4 - 2) = 20 / 2 = 10`
5. `17 % 3 = 2` (resto de 17 ÷ 3)
6. `100 % 10 = 0` (100 es divisible por 10)
7. `2 * 3 + 4 * 5 = 6 + 20 = 26`
8. `(2 * 3 + 4) * 5 = (6 + 4) * 5 = 10 * 5 = 50`
:::

### Operaciones de comparación

Comparan dos valores y devuelven **verdadero** o **falso**:

| Operación       | Símbolo | Ejemplo   | Resultado    |
| --------------- | ------- | --------- | ------------ |
| Igual a         | `==`    | `5 == 5`  | `verdadero`  |
| Diferente de    | `!=`    | `3 != 7`  | `verdadero`  |
| Mayor que       | `>`     | `8 > 3`   | `verdadero`  |
| Menor que       | `<`     | `2 < 9`   | `verdadero`  |
| Mayor o igual   | `>=`    | `5 >= 5`  | `verdadero`  |
| Menor o igual   | `<=`    | `4 <= 6`  | `verdadero`  |

:::{warning}
Notá que para comparar igualdad se usa `==` (doble igual), no `=` (que es
asignación).

- `x = 5` → asigna el valor 5 a x
- `x == 5` → compara si x es igual a 5
:::

**Ejemplos:**

```
edad = 20

edad > 18     → verdadero  (20 es mayor que 18)
edad == 20    → verdadero  (20 es igual a 20)
edad < 15     → falso      (20 no es menor que 15)
edad >= 20    → verdadero  (20 es mayor o igual a 20)
edad != 25    → verdadero  (20 es diferente de 25)
```

### Operaciones lógicas

Combinan condiciones booleanas:

| Operación        | Símbolo | Significado                             |
| ---------------- | ------- | --------------------------------------- |
| AND (Y lógico)   | `&&` o Y | Verdadero si AMBAS condiciones lo son  |
| OR (O lógico)    | `\|\|` o O | Verdadero si AL MENOS UNA lo es      |
| NOT (NO lógico)  | `!` o NO | Invierte el valor                      |

**Tablas de verdad:**

::::{grid} 1 1 3 3

:::{grid-item-card} AND (Y)
| A     | B     | A Y B |
| ----- | ----- | ----- |
| V     | V     | V     |
| V     | F     | F     |
| F     | V     | F     |
| F     | F     | F     |
:::

:::{grid-item-card} OR (O)
| A     | B     | A O B |
| ----- | ----- | ----- |
| V     | V     | V     |
| V     | F     | V     |
| F     | V     | V     |
| F     | F     | F     |
:::

:::{grid-item-card} NOT (NO)
| A     | NO A  |
| ----- | ----- |
| V     | F     |
| F     | V     |
:::
::::

**Ejemplos prácticos:**

```
edad = 20
tiene_dni = verdadero

(edad >= 18) Y (tiene_dni == verdadero)
→ verdadero Y verdadero
→ verdadero
(puede votar)

es_fin_de_semana = falso
es_feriado = verdadero

(es_fin_de_semana) O (es_feriado)
→ falso O verdadero
→ verdadero
(no hay clases)

está_lloviendo = verdadero

NO (está_lloviendo)
→ NO verdadero
→ falso
(no llevar paraguas)
```

```{mermaid}
graph TD
    subgraph "Ejemplo: ¿Puedo votar?"
        E[edad >= 18] --> Y{Y}
        D[tiene_dni] --> Y
        Y --> R[Resultado]
    end
    
    subgraph "Ejemplo: ¿Hay clases?"
        F[es_fin_de_semana] --> O{O}
        H[es_feriado] --> O
        O --> R2[Resultado]
    end
    
    style Y fill:#ffe4b5
    style O fill:#ffe4b5
```

:::{exercise} Operaciones lógicas
:label: ex-logicas
:nonumber:

Evaluá las siguientes expresiones (V = verdadero, F = falso):

1. `(5 > 3) Y (10 < 20)`
2. `(7 == 7) O (4 > 8)`
3. `NO (3 < 2)`
4. `(10 / 2 == 5) Y (10 % 3 == 1)`
5. `(20 > 15) Y (8 < 5)`
6. `(5 != 3) O (10 == 11)`
7. `NO ((5 > 3) Y (2 > 4))`
:::

:::{solution} ex-logicas
:class: dropdown

1. `(5 > 3) Y (10 < 20)` = `V Y V` = **V**
2. `(7 == 7) O (4 > 8)` = `V O F` = **V**
3. `NO (3 < 2)` = `NO F` = **V**
4. `(10 / 2 == 5) Y (10 % 3 == 1)` = `(5 == 5) Y (1 == 1)` = `V Y V` = **V**
5. `(20 > 15) Y (8 < 5)` = `V Y F` = **F**
6. `(5 != 3) O (10 == 11)` = `V O F` = **V**
7. `NO ((5 > 3) Y (2 > 4))` = `NO (V Y F)` = `NO F` = **V**
:::

## Diagramas de flujo

Los **diagramas de flujo** son representaciones gráficas de algoritmos que nos
ayudan a visualizar la lógica del programa de manera clara y estructurada.

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

**Descripción de cada símbolo:**

::::{grid} 1 1 2 2
:gutter: 3

:::{grid-item-card} Terminal (Óvalo)
Indica el inicio o fin del algoritmo.

**Ejemplo:**
- Inicio
- Fin
:::

:::{grid-item-card} Proceso (Rectángulo)
Representa una acción o instrucción a ejecutar.

**Ejemplo:**
- `suma = a + b`
- `contador = contador + 1`
- `área = base * altura`
:::

:::{grid-item-card} Decisión (Rombo)
Representa una pregunta cuya respuesta es sí o no.

**Ejemplo:**
- `¿edad >= 18?`
- `¿número == 0?`
- `¿llueve?`
:::

:::{grid-item-card} Entrada/Salida (Paralelogramo)
Representa lectura de datos o mostrar resultados.

**Ejemplo:**
- `Leer nombre`
- `Mostrar resultado`
- `Pedir edad`
:::
::::

### Ejemplos detallados

#### Ejemplo 1: Determinar si un número es positivo, negativo o cero

```{mermaid}
flowchart TD
    Start([Inicio]) --> Input[/Leer número N/]
    Input --> Check1{N > 0?}
    Check1 -->|Sí| Pos[/Mostrar: N es positivo/]
    Check1 -->|No| Check2{N < 0?}
    Check2 -->|Sí| Neg[/Mostrar: N es negativo/]
    Check2 -->|No| Zero[/Mostrar: N es cero/]
    Pos --> End([Fin])
    Neg --> End
    Zero --> End
    
    style Start fill:#90EE90
    style End fill:#FFB6C1
    style Check1 fill:#FFE4B5
    style Check2 fill:#FFE4B5
    style Input fill:#DDA0DD
    style Pos fill:#DDA0DD
    style Neg fill:#DDA0DD
    style Zero fill:#DDA0DD
```

#### Ejemplo 2: Calcular el promedio de tres números

```{mermaid}
flowchart TD
    Start([Inicio]) --> In1[/Leer A/]
    In1 --> In2[/Leer B/]
    In2 --> In3[/Leer C/]
    In3 --> Sum[suma = A + B + C]
    Sum --> Avg[promedio = suma / 3]
    Avg --> Out[/Mostrar promedio/]
    Out --> End([Fin])
    
    style Start fill:#90EE90
    style End fill:#FFB6C1
    style In1 fill:#DDA0DD
    style In2 fill:#DDA0DD
    style In3 fill:#DDA0DD
    style Out fill:#DDA0DD
```

#### Ejemplo 3: Sumar números del 1 al N

```{mermaid}
flowchart TD
    Start([Inicio]) --> InN[/Leer N/]
    InN --> Init1[suma = 0]
    Init1 --> Init2[contador = 1]
    Init2 --> Check{contador <= N?}
    Check -->|Sí| Add[suma = suma + contador]
    Add --> Inc[contador = contador + 1]
    Inc --> Check
    Check -->|No| Out[/Mostrar suma/]
    Out --> End([Fin])
    
    style Start fill:#90EE90
    style End fill:#FFB6C1
    style Check fill:#FFE4B5
    style InN fill:#DDA0DD
    style Out fill:#DDA0DD
```

#### Ejemplo 4: Verificar si un número es primo

```{mermaid}
flowchart TD
    Start([Inicio]) --> Input[/Leer N/]
    Input --> Check1{N <= 1?}
    Check1 -->|Sí| NoPrime[/N no es primo/]
    Check1 -->|No| Init[divisor = 2<br/>es_primo = verdadero]
    Init --> Loop{divisor < N Y<br/>es_primo?}
    Loop -->|No| CheckPrime{es_primo?}
    Loop -->|Sí| CheckDiv{N % divisor == 0?}
    CheckDiv -->|Sí| SetFalse[es_primo = falso]
    CheckDiv -->|No| NextDiv[divisor = divisor + 1]
    SetFalse --> Loop
    NextDiv --> Loop
    CheckPrime -->|Sí| IsPrime[/N es primo/]
    CheckPrime -->|No| NoPrime
    IsPrime --> End([Fin])
    NoPrime --> End
    
    style Start fill:#90EE90
    style End fill:#FFB6C1
    style Check1 fill:#FFE4B5
    style Loop fill:#FFE4B5
    style CheckDiv fill:#FFE4B5
    style CheckPrime fill:#FFE4B5
```

:::{exercise} Diagramas de flujo
:label: ex-diagramas
:nonumber:

Dibujá diagramas de flujo para:

1. Determinar cuál de dos números es mayor
2. Calcular el área de un triángulo (área = base × altura / 2)
3. Determinar si un año es bisiesto
4. Encontrar el factorial de un número
5. Contar cuántos números pares hay entre 1 y N
:::

## Pseudocódigo

El **pseudocódigo** es una forma de escribir algoritmos usando lenguaje natural
estructurado, pero más formal que el lenguaje cotidiano. Es un punto medio entre
el lenguaje humano y el código de programación real.

### Convenciones del pseudocódigo

**Palabras clave:**
- `Algoritmo`: nombre del algoritmo
- `Variables`: declaración de variables
- `Inicio` / `Fin`: delimitadores del algoritmo
- `Leer` / `Escribir`: entrada/salida
- `Si...Entonces...Sino...FinSi`: condicionales
- `Mientras...Hacer...FinMientras`: bucle con condición
- `Para...Hasta...Hacer...FinPara`: bucle con contador
- `←`: símbolo de asignación

**Estructura básica:**

```
Algoritmo NombreDelAlgoritmo
Variables:
    variable1: tipo
    variable2: tipo

Inicio
    [instrucciones]
Fin
```

### Ejemplo completo 1: Calculadora simple

```
┌─────────────────────────────────────────────────────┐
│ Algoritmo: Calculadora Simple                       │
├─────────────────────────────────────────────────────┤
│ Descripción: Realiza operaciones básicas entre     │
│              dos números                            │
├─────────────────────────────────────────────────────┤
Variables:
    numero1: decimal
    numero2: decimal
    operacion: caracter
    resultado: decimal

Inicio
    Escribir "=== CALCULADORA SIMPLE ==="
    
    Escribir "Ingrese el primer número:"
    Leer numero1
    
    Escribir "Ingrese el segundo número:"
    Leer numero2
    
    Escribir "Ingrese la operación (+, -, *, /):"
    Leer operacion
    
    Si operacion == '+' Entonces
        resultado ← numero1 + numero2
        Escribir "Resultado:", numero1, "+", numero2, "=", resultado
    Sino Si operacion == '-' Entonces
        resultado ← numero1 - numero2
        Escribir "Resultado:", numero1, "-", numero2, "=", resultado
    Sino Si operacion == '*' Entonces
        resultado ← numero1 * numero2
        Escribir "Resultado:", numero1, "×", numero2, "=", resultado
    Sino Si operacion == '/' Entonces
        Si numero2 != 0 Entonces
            resultado ← numero1 / numero2
            Escribir "Resultado:", numero1, "÷", numero2, "=", resultado
        Sino
            Escribir "Error: No se puede dividir por cero"
        FinSi
    Sino
        Escribir "Error: Operación no válida"
    FinSi
Fin
└─────────────────────────────────────────────────────┘
```

### Ejemplo completo 2: Tabla de multiplicar

```
┌─────────────────────────────────────────────────────┐
│ Algoritmo: Tabla de Multiplicar                     │
├─────────────────────────────────────────────────────┤
│ Descripción: Muestra la tabla de multiplicar de    │
│              un número del 1 al 10                  │
├─────────────────────────────────────────────────────┤
Variables:
    numero: entero
    contador: entero
    resultado: entero

Inicio
    Escribir "=== TABLA DE MULTIPLICAR ==="
    Escribir "Ingrese un número del 1 al 10:"
    Leer numero
    
    Si numero < 1 O numero > 10 Entonces
        Escribir "Error: El número debe estar entre 1 y 10"
    Sino
        Escribir "Tabla del", numero, ":"
        Escribir "─────────────────"
        
        contador ← 1
        Mientras contador <= 10 Hacer
            resultado ← numero * contador
            Escribir numero, "×", contador, "=", resultado
            contador ← contador + 1
        FinMientras
    FinSi
Fin
└─────────────────────────────────────────────────────┘
```

#### Ejemplo completo 3: Adivinar número

```
┌─────────────────────────────────────────────────────┐
│ Algoritmo: Adivinar Número                          │
├─────────────────────────────────────────────────────┤
│ Descripción: El usuario intenta adivinar un número │
│              secreto (máximo 5 intentos)            │
├─────────────────────────────────────────────────────┤
Variables:
    numero_secreto: entero
    intento: entero
    contador_intentos: entero
    adivinado: booleano

Inicio
    numero_secreto ← 42  // En un programa real sería aleatorio
    contador_intentos ← 0
    adivinado ← falso
    
    Escribir "=== ADIVINA EL NÚMERO ==="
    Escribir "Tenés 5 intentos para adivinar un número entre 1 y 100"
    
    Mientras contador_intentos < 5 Y NO adivinado Hacer
        contador_intentos ← contador_intentos + 1
        Escribir ""
        Escribir "Intento", contador_intentos, "de 5:"
        Leer intento
        
        Si intento == numero_secreto Entonces
            adivinado ← verdadero
            Escribir "¡¡¡FELICITACIONES!!! ¡Adivinaste el número!"
            Escribir "Lo lograste en", contador_intentos, "intentos"
        Sino Si intento < numero_secreto Entonces
            Escribir "El número es MAYOR"
        Sino
            Escribir "El número es MENOR"
        FinSi
    FinMientras
    
    Si NO adivinado Entonces
        Escribir ""
        Escribir "Game Over. El número era:", numero_secreto
    FinSi
Fin
└─────────────────────────────────────────────────────┘
```

:::{exercise} Pseudocódigo
:label: ex-pseudo-2
:nonumber:

Escribí en pseudocódigo algoritmos para:

1. Convertir temperatura de Celsius a Fahrenheit (F = C × 9/5 + 32)
2. Determinar si tres números pueden formar un triángulo (la suma de dos lados
   debe ser mayor que el tercero)
3. Calcular el Máximo Común Divisor (MCD) de dos números usando el algoritmo de
   Euclides
4. Determinar si una palabra es palíndromo (se lee igual de izquierda a derecha
   que de derecha a izquierda)
:::

:::{solution} ex-pseudo-2
:class: dropdown

**1. Conversión de temperatura:**

```
Algoritmo ConversionTemperatura
Variables:
    celsius: decimal
    fahrenheit: decimal

Inicio
    Escribir "Ingrese temperatura en Celsius:"
    Leer celsius
    
    fahrenheit ← celsius * 9 / 5 + 32
    
    Escribir celsius, "°C =", fahrenheit, "°F"
Fin
```

**2. Verificar triángulo:**

```
Algoritmo VerificarTriangulo
Variables:
    lado1, lado2, lado3: decimal
    es_triangulo: booleano

Inicio
    Escribir "Ingrese los tres lados:"
    Leer lado1, lado2, lado3
    
    Si (lado1 + lado2 > lado3) Y 
       (lado1 + lado3 > lado2) Y 
       (lado2 + lado3 > lado1) Entonces
        Escribir "Los números pueden formar un triángulo"
    Sino
        Escribir "Los números NO pueden formar un triángulo"
    FinSi
Fin
```

**3. MCD (Algoritmo de Euclides):**

```
Algoritmo CalcularMCD
Variables:
    a, b, temp: entero

Inicio
    Escribir "Ingrese dos números:"
    Leer a, b
    
    Mientras b != 0 Hacer
        temp ← b
        b ← a % b
        a ← temp
    FinMientras
    
    Escribir "El MCD es:", a
Fin
```
:::

## Ejercicios integradores

:::{exercise} Análisis de algoritmo
:label: ex-integrador-1
:nonumber:

Analizá el siguiente algoritmo y respondé:

```
Algoritmo Misterioso
Variables:
    n, suma, i: entero

Inicio
    Leer n
    suma ← 0
    i ← 1
    Mientras i <= n Hacer
        Si i % 2 == 0 Entonces
            suma ← suma + i
        FinSi
        i ← i + 1
    FinMientras
    Escribir suma
Fin
```

1. ¿Qué hace este algoritmo?
2. Si n = 10, ¿cuál es el resultado?
3. Dibujá el diagrama de flujo correspondiente
4. Modificalo para que sume los números impares en lugar de los pares
:::

:::{exercise} Diseño de algoritmo completo
:label: ex-integrador-2
:nonumber:

Diseñá un algoritmo completo (pseudocódigo Y diagrama de flujo) que:

1. Pida al usuario N números
2. Calcule y muestre:
   - El promedio de todos los números
   - El número mayor ingresado
   - El número menor ingresado
   - Cuántos números son positivos
   - Cuántos números son negativos
:::

:::{exercise} Problema del cambio
:label: ex-integrador-3
:nonumber:

Una máquina expendedora debe devolver cambio usando la menor cantidad posible de
billetes y monedas. Las denominaciones disponibles son: $100, $50, $20, $10,
$5, $2, $1.

Escribí un algoritmo que:
1. Reciba el monto a devolver
2. Calcule cuántos billetes/monedas de cada denominación usar
3. Muestre el desglose completo

Ejemplo: Para $287 debería mostrar:
- 2 billetes de $100
- 1 billete de $50
- 1 billete de $20
- 1 billete de $10
- 1 billete de $5
- 1 moneda de $2
:::

## Errores comunes y cómo evitarlos

### 1. Secuencia incorrecta de instrucciones

El orden de las instrucciones es crucial. Un error común es no considerar el
flujo lógico.

::::{grid} 1 1 2 2

:::{grid-item-card} ❌ Incorrecto
```
Algoritmo Incorrecto
    resultado ← a + b
    Leer a
    Leer b
    Escribir resultado
Fin
```
**Problema:** Usa variables antes de leerlas.
:::

:::{grid-item-card} ✅ Correcto
```
Algoritmo Correcto
    Leer a
    Leer b
    resultado ← a + b
    Escribir resultado
Fin
```
**Solución:** Lee primero, calcula después.
:::
::::

### 2. Condiciones mal formuladas

::::{grid} 1 1 2 2

:::{grid-item-card} ❌ Incorrecto
```
Si edad > 18 O edad == 18 Entonces
    Escribir "Mayor de edad"
FinSi
```
**Problema:** Más complejo de lo necesario.
:::

:::{grid-item-card} ✅ Correcto
```
Si edad >= 18 Entonces
    Escribir "Mayor de edad"
Sino
    Escribir "Menor de edad"
FinSi
```
**Solución:** Simplificar condiciones.
:::
::::

### 3. Ciclos infinitos

Un ciclo infinito ocurre cuando la condición de salida nunca se cumple.

::::{grid} 1 1 2 2

:::{grid-item-card} ❌ Incorrecto
```
contador ← 1
Mientras contador <= 10:
    Escribir contador
    # ¡Olvidamos incrementar contador!
```
Este ciclo nunca termina porque `contador` siempre vale 1.

✅ **Correcto:**
```
contador ← 1
Mientras contador <= 10:
    Escribir contador
    contador ← contador + 1
```
:::

:::{grid-item-card} ❌ Incorrecto
```
Mientras verdadero:
    Escribir "Hola"
```
Este ciclo nunca termina porque la condición siempre es verdadera.

✅ **Correcto:**
```
contador ← 1
Mientras contador <= 10 Hacer
    Escribir contador
    contador ← contador + 1
FinMientras
```
:::
::::

### 4. Usar variables sin inicializarlas

::::{grid} 1 1 2 2

:::{grid-item-card} ❌ Incorrecto
```
suma ← suma + 5  # ¿Cuánto vale suma al principio?
```

✅ **Correcto:**
```
suma ← 0
suma ← suma + 5  # Ahora suma vale 5
```
:::

:::{grid-item-card} ❌ Incorrecto
```
nombre_usuario ← nombre_usuario + "Smith"
```
¿Pero cuánto valía `nombre_usuario` antes?

✅ **Correcto:**
```
nombre_usuario ← "Juan"
nombre_usuario ← nombre_usuario + "Smith"  # Ahora es "JuanSmith"
```
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
las sintaxis y detalles se vuelven naturales.

:::

## Preparándose para C

Ahora que comprendés estos conceptos fundamentales, estás listo para comenzar
con el lenguaje C. En el próximo apunte veremos:

- Cómo escribir estos algoritmos en el lenguaje C
- La sintaxis específica del lenguaje
- Cómo compilar y ejecutar programas
- Variables y tipos de datos en C
- Estructuras de control (if, while, for)

Recordá que todo lo que vimos aquí se aplica directamente a C. La diferencia
principal es que en C necesitamos seguir reglas de sintaxis más estrictas.

## Glosario básico

:::{glossary}

Algoritmo
: Secuencia finita de pasos precisos que resuelve un problema.

Variable
: Espacio en memoria con un nombre, donde se almacena un valor que puede cambiar.

Tipo de dato
: Categoría que determina qué clase de información puede almacenar una variable
(entero, decimal, texto, etc.).

Operador
: Símbolo que indica una operación a realizar (+, -, *, /, ==, >, <, etc.).

Condición
: Expresión que se evalúa como verdadera o falsa, usada para tomar decisiones.

Ciclo o Bucle
: Estructura que repite un conjunto de instrucciones mientras se cumpla una
condición.

Pseudocódigo
: Forma de escribir algoritmos usando lenguaje natural estructurado.

Diagrama de flujo
: Representación gráfica de un algoritmo usando símbolos estandarizados.

:::

## Recursos adicionales

- Practicá escribiendo algoritmos cotidianos en pseudocódigo
- Dibujá diagramas de flujo para problemas simples
- Intentá "ejecutar" tus algoritmos mentalmente o en papel
- Discutí tus soluciones con compañeros - hay muchas formas de resolver un
  problema

:::{figure} xkcd-algorithms.png
:alt: XKCD Algorithms
:align: center

Fuente: [xkcd.com](https://xkcd.com/1667/)
:::

---

En el próximo apunte, [](2_gradual.md), comenzaremos a traducir estos conceptos
al lenguaje C y escribiremos nuestros primeros programas.
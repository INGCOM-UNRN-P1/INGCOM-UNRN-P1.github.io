---
title: Diseño por Contratos y Lógica de Primer Orden
subtitle: Fundamentos formales de la especificación y verificación de software
---

## Introducción

El **Diseño por Contratos** (Design by Contract, DbC) es una metodología formal de desarrollo de software introducida por Bertrand Meyer en el lenguaje Eiffel. Se fundamenta en la metáfora de un contrato legal entre partes: cada componente de software tiene **obligaciones** (precondiciones que debe garantizar el cliente) y **beneficios** (postcondiciones que garantiza el proveedor). Este enfoque transforma el desarrollo de software de una actividad artesanal a una disciplina ingenieril rigurosa.

```{figure} contratos/contract_metaphor.svg
:label: fig-metaphor
:align: center
:width: 90%

Metáfora del contrato: cliente y proveedor tienen obligaciones y derechos mutuos, formalizados mediante precondiciones y postcondiciones.
```

:::{important} Beneficios del Diseño por Contratos

1. **Documentación ejecutable**: Los contratos son especificaciones precisas y verificables
2. **Detección temprana de errores**: Violaciones se detectan en el punto exacto de falla
3. **Facilita testing**: Los contratos definen casos de prueba automáticamente
4. **Mejora mantenibilidad**: El comportamiento esperado está explícito
5. **Razonamiento formal**: Permite demostraciones matemáticas de corrección
:::

La formalización mediante Lógica de Primer Orden (LPO) proporciona el rigor matemático necesario para especificar, verificar y razonar sobre la corrección de programas.

## Fundamentos de Lógica de Primer Orden

### Sintaxis de la Lógica de Primer Orden

La **Lógica de Primer Orden** (First-Order Logic, FOL) extiende la lógica proposicional con cuantificadores sobre individuos.

#### Alfabeto

**Símbolos lógicos**:
- Variables: $x, y, z, x_1, x_2, \ldots$
- Conectivos lógicos: $\neg$ (negación), $\land$ (conjunción), $\lor$ (disyunción), $\rightarrow$ (implicación), $\leftrightarrow$ (equivalencia)
- Cuantificadores: $\forall$ (universal), $\exists$ (existencial)
- Símbolo de igualdad: $=$
- Paréntesis: $(, )$

**Símbolos no lógicos** (específicos del dominio):
- Constantes: $a, b, c, \ldots$
- Funciones: $f, g, h, \ldots$ con aridad $n \geq 1$
- Predicados: $P, Q, R, \ldots$ con aridad $n \geq 0$

#### Términos

Los **términos** denotan objetos del dominio:

$$
t ::= x \mid c \mid f(t_1, \ldots, t_n)
$$

donde $x$ es una variable, $c$ una constante, y $f$ una función de aridad $n$.

**Ejemplos**:
- $x$ (variable)
- $0$ (constante)
- $\text{succ}(x)$ (función sucesor)
- $x + y$ (función suma, notación infija)
- $\text{length}(\text{arr})$ (función longitud)

#### Fórmulas

Las **fórmulas** expresan propiedades y relaciones:

$$
\phi ::= P(t_1, \ldots, t_n) \mid t_1 = t_2 \mid \neg \phi \mid \phi_1 \land \phi_2 \mid \phi_1 \lor \phi_2 \mid \phi_1 \rightarrow \phi_2 \mid \forall x.\phi \mid \exists x.\phi
$$

**Ejemplos**:
- $x < y$ (predicado de orden)
- $\text{sorted}(\text{arr})$ (predicado de ordenamiento)
- $\forall i.\ (0 \leq i < n) \rightarrow (\text{arr}[i] \geq 0)$ (todos los elementos son no negativos)

### Semántica

La **interpretación** $\mathcal{I}$ asigna significado a símbolos no lógicos:
- **Dominio** $D$: conjunto no vacío de individuos
- **Interpretación de constantes**: $\mathcal{I}(c) \in D$
- **Interpretación de funciones**: $\mathcal{I}(f): D^n \rightarrow D$
- **Interpretación de predicados**: $\mathcal{I}(P) \subseteq D^n$

Una **asignación** $\sigma$ mapea variables a elementos del dominio: $\sigma: \text{Var} \rightarrow D$.

#### Satisfacción

La relación de satisfacción $\mathcal{I}, \sigma \models \phi$ se define inductivamente:

$$
\begin{align}
\mathcal{I}, \sigma &\models P(t_1, \ldots, t_n) &&\text{si } (\llbracket t_1 \rrbracket_{\mathcal{I},\sigma}, \ldots, \llbracket t_n \rrbracket_{\mathcal{I},\sigma}) \in \mathcal{I}(P) \\
\mathcal{I}, \sigma &\models t_1 = t_2 &&\text{si } \llbracket t_1 \rrbracket_{\mathcal{I},\sigma} = \llbracket t_2 \rrbracket_{\mathcal{I},\sigma} \\
\mathcal{I}, \sigma &\models \neg \phi &&\text{si } \mathcal{I}, \sigma \not\models \phi \\
\mathcal{I}, \sigma &\models \phi_1 \land \phi_2 &&\text{si } \mathcal{I}, \sigma \models \phi_1 \text{ y } \mathcal{I}, \sigma \models \phi_2 \\
\mathcal{I}, \sigma &\models \phi_1 \lor \phi_2 &&\text{si } \mathcal{I}, \sigma \models \phi_1 \text{ o } \mathcal{I}, \sigma \models \phi_2 \\
\mathcal{I}, \sigma &\models \phi_1 \rightarrow \phi_2 &&\text{si } \mathcal{I}, \sigma \not\models \phi_1 \text{ o } \mathcal{I}, \sigma \models \phi_2 \\
\mathcal{I}, \sigma &\models \forall x.\phi &&\text{si para todo } d \in D: \mathcal{I}, \sigma[x \mapsto d] \models \phi \\
\mathcal{I}, \sigma &\models \exists x.\phi &&\text{si existe } d \in D: \mathcal{I}, \sigma[x \mapsto d] \models \phi
\end{align}
$$

**Validez**: $\phi$ es válida ($\models \phi$) si $\mathcal{I}, \sigma \models \phi$ para toda interpretación $\mathcal{I}$ y asignación $\sigma$.

### Variables Libres y Ligadas

En $\forall x.\phi$ y $\exists x.\phi$, las ocurrencias de $x$ en $\phi$ están **ligadas**.

Una variable es **libre** si no está bajo el alcance de un cuantificador.

**Ejemplo**: En $\forall x.(x < y)$, $x$ está ligada y $y$ es libre.

Una fórmula sin variables libres es una **sentencia**.

### Sustitución

La sustitución $\phi[t/x]$ reemplaza todas las ocurrencias libres de $x$ en $\phi$ por el término $t$, evitando captura de variables.

**Ejemplo**:
$$
(\forall y.(x < y))[z+1/x] = \forall y.(z+1 < y)
$$

### Teorías de Primer Orden

Una **teoría** $T$ es un conjunto de axiomas (fórmulas) en LPO.

**Ejemplos**:
- **Aritmética de Peano**: axiomatiza números naturales
- **Teoría de conjuntos**: ZFC (Zermelo-Fraenkel con Axioma de Elección)
- **Teoría de arreglos**: axiomas para estructuras indexadas

## Diseño por Contratos: Formalización

```{figure} contratos/contract_components.svg
:label: fig-components
:align: center

Componentes de un contrato: precondición, postcondición e invariante, con sus roles en la verificación.
```

### Precondiciones

Una **precondición** $\text{Pre}(x_1, \ldots, x_n)$ es una fórmula LPO sobre los parámetros de entrada que debe ser verdadera antes de ejecutar la función.

**Definición formal**:

$$
\text{Pre}: \text{Estado}_{\text{in}} \rightarrow \{\text{true}, \text{false}\}
$$

donde $\text{Estado}_{\text{in}}$ representa el estado del programa antes de la llamada.

**Interpretación**:
- **Obligación del cliente**: Garantizar que Pre es verdadera
- **Derecho del proveedor**: Asumir que Pre es verdadera
- **Consecuencia**: Si Pre es falsa, el comportamiento es indefinido

**Ejemplo**: Búsqueda binaria
```c
// Pre: arr != NULL ∧ n > 0 ∧ sorted(arr, 0, n-1)
int busqueda_binaria(int arr[], int n, int clave);
```

Formalización:
$$
\text{Pre} \equiv (\text{arr} \neq \text{NULL}) \land (n > 0) \land \left(\forall i, j.\ 0 \leq i < j < n \rightarrow \text{arr}[i] \leq \text{arr}[j]\right)
$$

### Postcondiciones

Una **postcondición** $\text{Post}(x_1, \ldots, x_n, r)$ es una fórmula LPO que debe ser verdadera después de ejecutar la función, relacionando entradas, salidas y estado.

**Definición formal**:

$$
\text{Post}: \text{Estado}_{\text{in}} \times \text{Estado}_{\text{out}} \rightarrow \{\text{true}, \text{false}\}
$$

**Interpretación**:
- **Obligación del proveedor**: Garantizar que Post es verdadera (si Pre era verdadera)
- **Derecho del cliente**: Asumir que Post es verdadera
- **Frame condition**: Especifica qué puede cambiar

**Ejemplo**: Búsqueda binaria
```c
// Post: (r = -1 ∧ ∀i. 0 ≤ i < n → arr[i] ≠ clave) ∨
//       (0 ≤ r < n ∧ arr[r] = clave)
int busqueda_binaria(int arr[], int n, int clave);
```

Formalización:
$$
\begin{align}
\text{Post} \equiv\ &(r = -1 \land \forall i.\ 0 \leq i < n \rightarrow \text{arr}[i] \neq \text{clave}) \\
&\lor (0 \leq r < n \land \text{arr}[r] = \text{clave})
\end{align}
$$

### Invariantes

Un **invariante de lazo** $I$ es una fórmula que es verdadera antes y después de cada iteración.

**Definición formal**:

$$
I: \text{Estado} \rightarrow \{\text{true}, \text{false}\}
$$

**Regla de inferencia para lazos**:

$$
\frac{\{I \land B\}\ S\ \{I\}}{\{I\}\ \textbf{while}\ B\ \textbf{do}\ S\ \{I \land \neg B\}}
$$

donde $B$ es la guarda del lazo y $S$ el cuerpo.

```{figure} contratos/loop_invariant.svg
:label: fig-loop-invariant
:align: center

Comportamiento del invariante de lazo a través de las iteraciones, mostrando su preservación.
```

**Ejemplo**: Suma de arreglo
```c
// Pre: arr != NULL ∧ n ≥ 0
// Post: result = Σ(arr[i]) para i ∈ [0, n)
int sumar_arreglo(int arr[], int n) {
    int suma = 0;
    int i = 0;
    
    // Invariante: suma = Σ(arr[j]) para j ∈ [0, i) ∧ 0 ≤ i ≤ n
    while (i < n) {
        suma += arr[i];
        i++;
    }
    
    return suma;
}
```

Formalización del invariante:
$$
I \equiv \left(\text{suma} = \sum_{j=0}^{i-1} \text{arr}[j]\right) \land (0 \leq i \leq n)
$$

**Demostración de corrección**:

1. **Inicialización**: Antes del lazo, $i = 0$ y $\text{suma} = 0$
   $$
   I[0/i, 0/\text{suma}] = \left(0 = \sum_{j=0}^{-1} \text{arr}[j]\right) \land (0 \leq 0 \leq n) = \text{true}
   $$

2. **Preservación**: Si $I \land (i < n)$ antes de la iteración, entonces $I[i+1/i, \text{suma}+\text{arr}[i]/\text{suma}]$ después:
   $$
   \begin{align}
   \text{suma} + \text{arr}[i] &= \sum_{j=0}^{i-1} \text{arr}[j] + \text{arr}[i] \\
   &= \sum_{j=0}^{i} \text{arr}[j]
   \end{align}
   $$
   Y $(i+1) \leq n$ porque $i < n$.

3. **Terminación**: Al salir del lazo, $I \land \neg(i < n) = I \land (i \geq n)$. Por el invariante, $i \leq n$, entonces $i = n$.
   $$
   \text{suma} = \sum_{j=0}^{n-1} \text{arr}[j]
   $$
   que es la postcondición deseada.

### Invariantes de Clase

Un **invariante de clase** es una propiedad que debe ser verdadera para todos los objetos en todos los estados observables.

**Definición formal**:

$$
\text{ClassInv}: \text{Estado}_{\text{objeto}} \rightarrow \{\text{true}, \text{false}\}
$$

**Propiedades**:
1. Debe ser verdadero después del constructor
2. Debe preservarse por todos los métodos públicos
3. Puede violarse temporalmente en métodos privados

**Ejemplo**: Cola circular con arreglo
```c
typedef struct {
    int *elementos;
    int capacidad;
    int frente;
    int final;
    int tamanio;
} cola_t;

// Invariante de clase:
// 1. elementos != NULL
// 2. capacidad > 0
// 3. 0 ≤ frente < capacidad
// 4. 0 ≤ final < capacidad
// 5. 0 ≤ tamanio ≤ capacidad
// 6. Si tamanio > 0: elementos[(frente + i) % capacidad] está definido para 0 ≤ i < tamanio
```

Formalización:
$$
\begin{align}
\text{Inv}_{\text{cola}} \equiv\ &(\text{elementos} \neq \text{NULL}) \\
&\land (\text{capacidad} > 0) \\
&\land (0 \leq \text{frente} < \text{capacidad}) \\
&\land (0 \leq \text{final} < \text{capacidad}) \\
&\land (0 \leq \text{tamanio} \leq \text{capacidad}) \\
&\land (\text{tamanio} > 0 \rightarrow \forall i.\ 0 \leq i < \text{tamanio} \rightarrow \text{elementos}[(\text{frente} + i) \bmod \text{capacidad}] \in \mathbb{Z})
\end{align}
$$

## Lógica de Hoare

La **Lógica de Hoare** proporciona un sistema formal para razonar sobre la corrección de programas.

### Tripletas de Hoare

Una **tripleta de Hoare** tiene la forma:

$$
\{P\}\ S\ \{Q\}
$$

donde:
- $P$ es la **precondición** (aserción sobre el estado antes de $S$)
- $S$ es el **programa** (secuencia de instrucciones)
- $Q$ es la **postcondición** (aserción sobre el estado después de $S$)

**Interpretación** (corrección parcial):
> Si $P$ es verdadera antes de ejecutar $S$, y $S$ termina, entonces $Q$ es verdadera después.

**Corrección total**: $[P]\ S\ [Q]$ garantiza además que $S$ termina.

```{figure} contratos/hoare_triple.svg
:label: fig-hoare
:align: center

Representación de una tripleta de Hoare mostrando la transformación de estados.
```

### Reglas de Inferencia

#### Regla de Asignación

$$
\frac{}{\{Q[E/x]\}\ x := E\ \{Q\}}
$$

**Ejemplo**:
$$
\{y + 1 > 0\}\ x := y + 1\ \{x > 0\}
$$

#### Regla de Composición Secuencial

$$
\frac{\{P\}\ S_1\ \{R\} \quad \{R\}\ S_2\ \{Q\}}{\{P\}\ S_1; S_2\ \{Q\}}
$$

#### Regla de Condicional

$$
\frac{\{P \land B\}\ S_1\ \{Q\} \quad \{P \land \neg B\}\ S_2\ \{Q\}}{\{P\}\ \textbf{if}\ B\ \textbf{then}\ S_1\ \textbf{else}\ S_2\ \{Q\}}
$$

#### Regla de Lazo (While)

$$
\frac{\{I \land B\}\ S\ \{I\}}{\{I\}\ \textbf{while}\ B\ \textbf{do}\ S\ \{I \land \neg B\}}
$$

donde $I$ es el invariante de lazo.

#### Regla de Consecuencia

$$
\frac{P' \rightarrow P \quad \{P\}\ S\ \{Q\} \quad Q \rightarrow Q'}{\{P'\}\ S\ \{Q'\}}
$$

Esta regla permite **debilitar** la precondición y **fortalecer** la postcondición.

### Debilidad de Precondiciones

Una precondición $P_1$ es **más débil** que $P_2$ si:

$$
P_2 \rightarrow P_1
$$

Es decir, $P_1$ es verdadera en más estados que $P_2$.

**Precondición más débil** (weakest precondition, $wp$):

$$
wp(S, Q) = \text{la precondición más débil tal que } \{wp(S, Q)\}\ S\ \{Q\}
$$

**Ejemplo**: Para $S = \texttt{x := x + 1}$ y $Q = (x > 5)$:
$$
wp(\texttt{x := x + 1}, x > 5) = (x + 1 > 5) = (x > 4)
$$

### Ejemplo Completo: Máximo de Dos Números

```c
// Pre: true
// Post: r = max(a, b)
int maximo(int a, int b) {
    int r;
    if (a >= b) {
        r = a;
    } else {
        r = b;
    }
    return r;
}
```

**Demostración**:

1. **Rama then**: $\{a \geq b\}\ r := a\ \{r = \max(a, b)\}$
   - Por la regla de asignación: debemos probar $a \geq b \rightarrow (a = \max(a, b))$
   - Esto es verdadero porque $a \geq b \rightarrow \max(a, b) = a$

2. **Rama else**: $\{a < b\}\ r := b\ \{r = \max(a, b)\}$
   - Similarmente: $a < b \rightarrow (b = \max(a, b))$ es verdadero

3. **Condicional completo**: Por la regla de condicional:
   $$
   \{\text{true}\}\ \textbf{if}\ (a \geq b)\ \cdots\ \{r = \max(a, b)\}
   $$

## Verificación Automática y Herramientas

### Aserciones en C

En C, las aserciones se implementan con `assert.h`:

```c
#include <assert.h>

// Pre: arr != NULL ∧ n > 0
void procesar(int arr[], int n) {
    assert(arr != NULL);
    assert(n > 0);
    
    // ... código ...
}
```

**Limitaciones**:
- Solo verificación en runtime
- No hay distinción entre Pre/Post
- No soporta cuantificadores directamente

### Anotaciones Avanzadas: ACSL

**ACSL** (ANSI/ISO C Specification Language) extiende C con contratos formales para Frama-C:

```c
/*@ requires n > 0;
    requires \valid(arr + (0..n-1));
    ensures \result >= 0;
    ensures \result < n;
    ensures \forall integer i; 0 <= i < n ==> arr[\result] >= arr[i];
  */
int buscar_maximo(int arr[], int n);
```

**Cuantificadores en ACSL**:
- `\forall`: cuantificador universal
- `\exists`: cuantificador existencial
- `\valid(p)`: el puntero `p` es válido
- `\old(x)`: valor de `x` en el estado previo
- `\result`: valor de retorno

### Verificadores de Modelos

**Frama-C**: Framework para análisis estático de C
- **WP plugin**: Genera Verificación Conditions (VCs)
- **SMT solvers**: Z3, CVC4, Alt-Ergo resuelven VCs
- Puede probar corrección funcional automáticamente

```{figure} contratos/verification_flow.svg
:label: fig-verification
:align: center

Flujo de verificación automática: desde código anotado hasta prueba formal.
```

**Ejemplo completo verificable**:

```c
/*@ requires n >= 0;
    requires \valid(arr + (0..n-1));
    ensures \result == \sum(0, n-1, \lambda integer i; arr[i]);
  */
int sumar_arreglo(int arr[], int n) {
    int suma = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant suma == \sum(0, i-1, \lambda integer j; arr[j]);
        loop assigns i, suma;
        loop variant n - i;
      */
    for (int i = 0; i < n; i++) {
        suma += arr[i];
    }
    
    return suma;
}
```

## Contratos en Estructuras de Datos

### Ejemplo 1: Pila

```c
typedef struct {
    int *elementos;
    int tope;
    int capacidad;
} pila_t;

// Invariante de clase:
// 1. elementos != NULL
// 2. capacidad > 0
// 3. 0 ≤ tope ≤ capacidad
// 4. ∀i. 0 ≤ i < tope → elementos[i] está definido

/*@ predicate pila_valida(pila_t *p) =
        \valid(p) &&
        p->elementos != NULL &&
        p->capacidad > 0 &&
        0 <= p->tope <= p->capacidad &&
        \valid(p->elementos + (0..p->capacidad-1));
  */

/*@ requires pila_valida(p);
    requires p->tope < p->capacidad;
    assigns p->tope, p->elementos[p->tope];
    ensures pila_valida(p);
    ensures p->tope == \old(p->tope) + 1;
    ensures p->elementos[p->tope - 1] == dato;
  */
void push(pila_t *p, int dato) {
    p->elementos[p->tope] = dato;
    p->tope++;
}

/*@ requires pila_valida(p);
    requires p->tope > 0;
    assigns p->tope;
    ensures pila_valida(p);
    ensures p->tope == \old(p->tope) - 1;
    ensures \result == \old(p->elementos[p->tope - 1]);
  */
int pop(pila_t *p) {
    p->tope--;
    return p->elementos[p->tope];
}
```

### Ejemplo 2: Lista Enlazada

```c
typedef struct nodo {
    int dato;
    struct nodo *siguiente;
} nodo_t;

typedef struct {
    nodo_t *cabeza;
    int longitud;
} lista_t;

/*@ predicate lista_acíclica(nodo_t *n) =
        n == NULL ||
        (\valid(n) && lista_acíclica(n->siguiente) && !alcanzable(n->siguiente, n));
  */

/*@ predicate longitud_correcta(lista_t *l) =
        l->longitud == contar_nodos(l->cabeza);
  */

/*@ predicate lista_valida(lista_t *l) =
        \valid(l) &&
        lista_acíclica(l->cabeza) &&
        l->longitud >= 0 &&
        longitud_correcta(l);
  */

/*@ requires lista_valida(l);
    assigns l->cabeza, l->longitud, \allocable;
    ensures lista_valida(l);
    ensures l->longitud == \old(l->longitud) + 1;
    ensures l->cabeza->dato == dato;
    ensures l->cabeza->siguiente == \old(l->cabeza);
  */
void insertar_inicio(lista_t *l, int dato) {
    nodo_t *nuevo = malloc(sizeof(nodo_t));
    //@ assert nuevo != NULL; // Asumiendo éxito de malloc
    
    nuevo->dato = dato;
    nuevo->siguiente = l->cabeza;
    l->cabeza = nuevo;
    l->longitud++;
}
```

## Subtipos y Contratos

### Principio de Sustitución de Liskov

El **Principio de Sustitución de Liskov** (LSP) establece que un subtipo debe poder usarse donde se espera el supertipo sin alterar la corrección.

**Formalización mediante contratos**:

Si $S$ es un subtipo de $T$, entonces para todo método $m$:

$$
\begin{align}
\text{Pre}_T(m) &\rightarrow \text{Pre}_S(m) \quad \text{(precondición más débil)} \\
\text{Post}_S(m) &\rightarrow \text{Post}_T(m) \quad \text{(postcondición más fuerte)} \\
\text{Inv}_T &\rightarrow \text{Inv}_S \quad \text{(invariante más fuerte)}
\end{align}
$$

```{figure} contratos/liskov_substitution.svg
:label: fig-liskov
:align: center

Diagrama del Principio de Sustitución de Liskov mostrando la relación entre contratos de super y subtipos.
```

**Interpretación**:
- El subtipo puede **relajar** las precondiciones (aceptar más casos)
- El subtipo debe **fortalecer** las postcondiciones (garantizar más)
- El subtipo puede **añadir** invariantes

**Ejemplo**: Rectángulo vs Cuadrado

```c
// Rectángulo (supertipo)
typedef struct {
    int ancho;
    int alto;
} rectangulo_t;

/*@ requires \valid(r);
    requires ancho > 0 && alto > 0;
    assigns r->ancho, r->alto;
    ensures r->ancho == ancho && r->alto == alto;
  */
void set_dimensiones_rect(rectangulo_t *r, int ancho, int alto);

// Cuadrado (subtipo problemático)
typedef struct {
    int lado;
} cuadrado_t;

// ¡Viola LSP! Precondición más fuerte: ancho debe ser igual a alto
void set_dimensiones_cuad(cuadrado_t *c, int ancho, int alto) {
    assert(ancho == alto); // Precondición adicional
    c->lado = ancho;
}
```

Este es el **problema clásico del cuadrado-rectángulo**: un cuadrado matemáticamente es un rectángulo, pero como tipo mutable viola LSP porque tiene restricciones adicionales.

## Frame Problem y Especificación de Cambios

El **Frame Problem** consiste en especificar qué **no cambia** en una operación. Es fundamental para contratos precisos.

### Cláusulas de Frame

**Sintaxis**:
```c
//@ assigns x, y, z;
```

**Semántica**: Solo las variables listadas pueden cambiar; todo lo demás permanece igual.

**Ejemplo**:

```c
/*@ requires \valid(arr + (0..n-1));
    requires 0 <= i < n;
    assigns arr[i];
    ensures arr[i] == valor;
    ensures \forall integer j; 0 <= j < n && j != i ==> arr[j] == \old(arr[j]);
  */
void actualizar(int arr[], int n, int i, int valor) {
    arr[i] = valor;
}
```

La cláusula `assigns arr[i]` especifica que solo `arr[i]` puede cambiar. El resto del arreglo permanece igual, lo cual se hace explícito en la postcondición.

### Separación Lógica

La **Lógica de Separación** (Separation Logic) extiende Lógica de Hoare con conectivos espaciales para razonar sobre heap:

- $P * Q$: "separating conjunction" - $P$ y $Q$ se satisfacen en regiones disjuntas de heap
- $P \mathbin{-\!\!*} Q$: "magic wand" - si se agrega un heap que satisface $P$, el resultado satisface $Q$
- $\textit{emp}$: heap vacío
- $x \mapsto y$: heap con una celda en dirección $x$ conteniendo $y$

**Ejemplo**:

$$
\{x \mapsto a * y \mapsto b\}\ \texttt{swap}(x, y)\ \{x \mapsto b * y \mapsto a\}
$$

Esto especifica que $x$ e $y$ apuntan a celdas distintas (separación) y que `swap` intercambia sus contenidos.

## Casos de Estudio

### Caso 1: Ordenamiento por Inserción

```c
/*@ predicate sorted{L}(int *arr, integer i, integer j) =
        \forall integer k, l; i <= k < l <= j ==> arr[k] <= arr[l];
  */

/*@ predicate permutation{L1,L2}(int *arr, integer n) =
        \forall integer i; 0 <= i < n ==>
            cuenta{L1}(arr, n, arr[i]) == cuenta{L2}(arr, n, arr[i]);
  */

/*@ requires n >= 0;
    requires \valid(arr + (0..n-1));
    assigns arr[0..n-1];
    ensures sorted(arr, 0, n-1);
    ensures permutation{Pre,Post}(arr, n);
  */
void insertion_sort(int arr[], int n) {
    /*@ loop invariant 1 <= i <= n;
        loop invariant sorted(arr, 0, i-1);
        loop invariant permutation{Pre,Here}(arr, n);
        loop assigns i, arr[0..n-1];
        loop variant n - i;
      */
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        
        /*@ loop invariant -1 <= j < i;
            loop invariant sorted(arr, 0, j) && sorted(arr, j+2, i);
            loop invariant \forall integer k; j+2 <= k <= i ==> arr[k] >= clave;
            loop assigns j, arr[0..i];
            loop variant j + 1;
          */
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = clave;
    }
}
```

**Invariantes clave**:
1. **Lazo externo**: Los primeros $i$ elementos están ordenados
2. **Lazo interno**: Se mantiene espacio para insertar `clave`
3. **Permutación**: Los elementos del arreglo son los mismos (orden distinto)

### Caso 2: Búsqueda Binaria con Demostración

```c
/*@ requires n > 0;
    requires \valid_read(arr + (0..n-1));
    requires sorted(arr, 0, n-1);
    assigns \nothing;
    behavior found:
        assumes \exists integer i; 0 <= i < n && arr[i] == clave;
        ensures 0 <= \result < n;
        ensures arr[\result] == clave;
    behavior not_found:
        assumes \forall integer i; 0 <= i < n ==> arr[i] != clave;
        ensures \result == -1;
    complete behaviors;
    disjoint behaviors;
  */
int busqueda_binaria(const int arr[], int n, int clave) {
    int izq = 0;
    int der = n - 1;
    
    /*@ loop invariant 0 <= izq <= der + 1 <= n;
        loop invariant \forall integer i; 0 <= i < izq ==> arr[i] < clave;
        loop invariant \forall integer i; der < i < n ==> arr[i] > clave;
        loop assigns izq, der;
        loop variant der - izq;
      */
    while (izq <= der) {
        // Previene overflow: medio = (izq + der) / 2
        int medio = izq + (der - izq) / 2;
        
        if (arr[medio] == clave) {
            return medio;
        }
        
        if (arr[medio] < clave) {
            izq = medio + 1;
        } else {
            der = medio - 1;
        }
    }
    
    return -1;
}
```

**Demostración de corrección**:

**Invariante**: 
$$
I \equiv (0 \leq \text{izq} \leq \text{der} + 1 \leq n) \land I_1 \land I_2
$$
donde:
$$
\begin{align}
I_1 &\equiv \forall i.\ 0 \leq i < \text{izq} \rightarrow \text{arr}[i] < \text{clave} \\
I_2 &\equiv \forall i.\ \text{der} < i < n \rightarrow \text{arr}[i] > \text{clave}
\end{align}
$$

**Inicialización**: Con $\text{izq} = 0$ y $\text{der} = n-1$:
- $I_1$ es vacuamente verdadero (no hay $i < 0$)
- $I_2$ es vacuamente verdadero (no hay $i > n-1$)

**Preservación**:
- Si $\text{arr}[\text{medio}] < \text{clave}$: actualizamos $\text{izq} = \text{medio} + 1$
  - Por estar ordenado, $\forall i \leq \text{medio}.\ \text{arr}[i] \leq \text{arr}[\text{medio}] < \text{clave}$
  - Entonces $I_1$ sigue siendo verdadero con el nuevo $\text{izq}$
  
- Si $\text{arr}[\text{medio}] > \text{clave}$: análogo para $I_2$

**Terminación**: $(\text{der} - \text{izq})$ decrece en cada iteración y es no negativo.

**Corrección**: Al salir, $\text{izq} > \text{der}$, entonces:
- Por $I_1$: todos los elementos $< \text{clave}$ están antes de $\text{izq}$
- Por $I_2$: todos los elementos $> \text{clave}$ están después de $\text{der}$
- Por estar ordenado y ser $\text{izq} = \text{der} + 1$: no existe elemento igual a $\text{clave}$

## Limitaciones y Desafíos

### Indecidibilidad

**Teorema**: La corrección de programas con respecto a especificaciones en LPO es **indecidible** (consecuencia del Teorema de Rice).

**Implicaciones**:
- No existe algoritmo que determine automáticamente si un programa satisface su especificación
- Herramientas de verificación pueden:
  - **Probar corrección** en muchos casos
  - **Encontrar errores** con contraejemplos
  - **No terminar** en casos complejos

### Complejidad de las Especificaciones

Escribir especificaciones completas puede ser más difícil que escribir el código:

**Ejemplo**: Especificar "ordenamiento estable" requiere razonar sobre permutaciones preservando orden relativo:

$$
\begin{align}
&\text{sorted}(\text{arr}, 0, n-1) \\
\land\ &\text{permutation}(\text{arr}_{\text{in}}, \text{arr}_{\text{out}}) \\
\land\ &\forall i, j.\ (0 \leq i < j < n \land \text{arr}_{\text{in}}[i] = \text{arr}_{\text{in}}[j]) \\
&\quad\quad \rightarrow (\pi(i) < \pi(j))
\end{align}
$$

donde $\pi$ es la permutación aplicada.

### Límites de la Verificación Automática

**SMT Solvers** tienen dificultades con:
- **Cuantificadores anidados**: explosión combinatoria
- **Aritmética no lineal**: decidible pero costosa
- **Estructuras recursivas**: listas, árboles requieren inducción manual
- **Funciones no especificadas**: bibliotecas externas sin contratos

## Mejores Prácticas

```{figure} contratos/best_practices.svg
:label: fig-best-practices
:align: center

Diagrama de flujo para aplicar diseño por contratos efectivamente en proyectos.
```

### Granularidad de Contratos

1. **Contratos públicos completos**: APIs públicas deben tener Pre/Post completas
2. **Contratos privados opcionales**: Funciones auxiliares pueden tener contratos más relajados
3. **Invariantes de clase siempre**: Estructuras de datos deben tener invariantes claros

### Orden de Desarrollo

**Test-Driven Design by Contract**:

1. **Especificar contratos**: Pre/Post/Invariantes primero
2. **Escribir tests**: Basados en los contratos
3. **Implementar**: Código que satisface contratos
4. **Verificar**: Con herramientas automáticas cuando sea posible

### Contratos como Documentación

Los contratos son la **mejor documentación**:
- **Precisos**: Sin ambigüedad
- **Verificables**: Pueden probarse automáticamente
- **Ejecutables**: Se convierten en checks en runtime
- **Mantenibles**: Evolucionan con el código

### Balance Costo-Beneficio

| Tipo de Proyecto | Nivel de Contratos Recomendado |
|------------------|--------------------------------|
| Prototipos rápidos | Aserciones básicas en código crítico |
| Software comercial | Pre/Post en APIs públicas, invariantes de clase |
| Sistemas críticos | Especificación formal completa, verificación automática |
| Software certificado | Pruebas formales de corrección con asistentes de prueba (Coq, Isabelle) |

## Herramientas y Ecosistema

### Lenguajes con Soporte Nativo

- **Eiffel**: Diseño por Contratos desde su creación
- **Ada/SPARK**: Contratos formales para sistemas críticos
- **Spec#**: Extensión de C# con contratos
- **Dafny**: Lenguaje verificado con SMT solvers integrados

### Herramientas para C

- **Frama-C**: Framework completo de análisis
  - **WP**: Generador de condiciones de verificación
  - **E-ACSL**: Runtime assertion checking
  - **RTE**: Detección de errores en runtime

- **CBMC**: Bounded Model Checker para C
- **VCC**: Verificador para código concurrente en C
- **VeriFast**: Verificador con Separation Logic

### Frameworks de Testing

- **QuickCheck para C**: Generación de tests basada en propiedades
- **American Fuzzy Lop (AFL)**: Fuzzing guiado por cobertura
- **Valgrind/Memcheck**: Detección de errores de memoria en runtime

## Ejercicios

```{exercise}
:label: ejer-contratos-1

Especificá precondiciones, postcondiciones e invariantes de lazo para el siguiente código que calcula el factorial:

```c
int factorial(int n) {
    int resultado = 1;
    int i = 1;
    
    while (i <= n) {
        resultado *= i;
        i++;
    }
    
    return resultado;
}
```

Demostrá que el invariante se preserva en cada iteración.
```

````{solution} ejer-contratos-1
:class: dropdown

**Especificación**:

```c
/*@ requires n >= 0;
    requires n <= 12;  // Para evitar overflow en int de 32 bits
    assigns \nothing;
    ensures \result == factorial_matematico(n);
  */
int factorial(int n);
```

**Invariante de lazo**:
$$
I \equiv (1 \leq i \leq n+1) \land (\text{resultado} = i-1!)
$$

**Demostración**:

1. **Inicialización**: Antes del lazo, $i = 1$ y $\text{resultado} = 1$
   $$
   I[1/i, 1/\text{resultado}] = (1 \leq 1 \leq n+1) \land (1 = 0!) = \text{true}
   $$

2. **Preservación**: Asumiendo $I \land (i \leq n)$ antes de la iteración:
   - Tenemos: $\text{resultado} = (i-1)!$
   - Después de `resultado *= i`: $\text{resultado}' = (i-1)! \times i = i!$
   - Después de `i++`: $i' = i + 1$
   - Nuevo invariante: $\text{resultado}' = (i'-1)! = i!$ ✓

3. **Terminación**: Al salir, $I \land (i > n)$, entonces $i = n+1$ y $\text{resultado} = n!$

**Postcondición satisfecha**: $\text{resultado} = n!$ ✓
````

```{exercise}
:label: ejer-contratos-2

Encontrá el error en la siguiente especificación e implementación:

```c
/*@ requires n > 0;
    requires \valid(arr + (0..n-1));
    ensures \forall integer i; 0 <= i < n-1 ==> arr[i] <= arr[i+1];
  */
void ordenar_ascendente(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        arr[i] = i;
    }
}
```

¿La implementación satisface la especificación? ¿Es esto lo que se quería especificar?
```

````{solution} ejer-contratos-2
:class: dropdown

**Problema 1**: La implementación **sí satisface** la especificación técnicamente:
- Postcondición: $\forall i.\ 0 \leq i < n-1 \rightarrow \text{arr}[i] \leq \text{arr}[i+1]$
- Después del código: `arr = [0, 1, 2, ..., n-2, ???]`
- La postcondición es verdadera

**Problema 2**: La especificación es **demasiado débil**. Falta:
1. **Permutación**: Los elementos finales deben ser los mismos que los iniciales
2. **Frame**: No especifica qué no debe cambiar

**Especificación corregida**:

```c
/*@ requires n > 0;
    requires \valid(arr + (0..n-1));
    assigns arr[0..n-1];
    ensures sorted(arr, 0, n-1);
    ensures permutation{Pre,Post}(arr, n);
  */
void ordenar_ascendente(int arr[], int n);
```

donde:
```c
/*@ predicate sorted(int *arr, integer i, integer j) =
        \forall integer k; i <= k < j ==> arr[k] <= arr[k+1];
  */

/*@ predicate permutation{L1,L2}(int *arr, integer n) =
        multiset_same{L1,L2}(arr, 0, n-1);
  */
```

**Lección**: Especificaciones incompletas permiten implementaciones "correctas" pero inútiles.
````

```{exercise}
:label: ejer-contratos-3

Escribí la especificación formal completa (Pre/Post/Invariantes) para una función que invierte un arreglo in-place. Demostrá que tu invariante es correcto.
```

````{solution} ejer-contratos-3
:class: dropdown

**Especificación**:

```c
/*@ requires n >= 0;
    requires \valid(arr + (0..n-1));
    assigns arr[0..n-1];
    ensures \forall integer i; 0 <= i < n ==> arr[i] == \old(arr[n-1-i]);
  */
void invertir(int arr[], int n) {
    int i = 0;
    int j = n - 1;
    
    /*@ loop invariant 0 <= i <= j+1 <= n;
        loop invariant \forall integer k; 0 <= k < i ==>
            arr[k] == \old(arr[n-1-k]);
        loop invariant \forall integer k; j < k < n ==>
            arr[k] == \old(arr[n-1-k]);
        loop invariant \forall integer k; i <= k <= j ==>
            arr[k] == \old(arr[k]);
        loop assigns i, j, arr[0..n-1];
        loop variant j - i + 1;
      */
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}
```

**Invariante**:
$$
\begin{align}
I \equiv\ &(0 \leq i \leq j+1 \leq n) \\
\land\ &\forall k.\ 0 \leq k < i \rightarrow \text{arr}[k] = \text{arr}_{\text{old}}[n-1-k] \\
\land\ &\forall k.\ j < k < n \rightarrow \text{arr}[k] = \text{arr}_{\text{old}}[n-1-k] \\
\land\ &\forall k.\ i \leq k \leq j \rightarrow \text{arr}[k] = \text{arr}_{\text{old}}[k]
\end{align}
$$

**Interpretación**:
- Los elementos antes de $i$ ya están invertidos
- Los elementos después de $j$ ya están invertidos
- Los elementos entre $i$ y $j$ aún no se han tocado

**Demostración de preservación**: En cada iteración:
1. Intercambiamos `arr[i]` y `arr[j]`
2. Incrementamos $i$ y decrementamos $j$
3. Los elementos recién intercambiados ahora satisfacen la propiedad de inversión
4. Los elementos previamente intercambiados no se modifican

Al terminar ($i \geq j$), todos los elementos han sido procesados y están invertidos.
````

## Referencias y Lecturas Complementarias

### Textos Fundamentales

- Meyer, B. (1997). *Object-Oriented Software Construction* (2nd ed.). Prentice Hall. El texto definitivo sobre Diseño por Contratos.

- Hoare, C. A. R. (1969). "An Axiomatic Basis for Computer Programming". *Communications of the ACM*, 12(10), 576-580. El artículo seminal de Lógica de Hoare.

- Dijkstra, E. W. (1975). "Guarded Commands, Nondeterminacy and Formal Derivation of Programs". *Communications of the ACM*, 18(8), 453-457. Introduce precondiciones más débiles.

### Lógica de Primer Orden

- Enderton, H. B. (2001). *A Mathematical Introduction to Logic* (2nd ed.). Academic Press. Tratamiento riguroso de lógica matemática.

- Fitting, M. (1996). *First-Order Logic and Automated Theorem Proving* (2nd ed.). Springer. Enfoque computacional de LPO.

### Verificación Formal

- Nipkow, T., Wenzel, M., & Paulson, L. C. (2002). *Isabelle/HOL: A Proof Assistant for Higher-Order Logic*. Springer. Asistente de pruebas interactivo.

- Leino, K. R. M. (2010). "Dafny: An Automatic Program Verifier for Functional Correctness". *LPAR*, 348-370. Lenguaje con verificación integrada.

- Baudin, P., et al. (2020). *ACSL: ANSI/ISO C Specification Language*. CEA LIST. Manual completo de ACSL para Frama-C.

### Separation Logic

- Reynolds, J. C. (2002). "Separation Logic: A Logic for Shared Mutable Data Structures". *LICS*, 55-74. Introduce Separation Logic.

- O'Hearn, P. W., Reynolds, J. C., & Yang, H. (2001). "Local Reasoning about Programs that Alter Data Structures". *CSL*, 1-19. Aplicaciones prácticas.

### Recursos en Línea

- Frama-C Tutorial: https://frama-c.com/tutorial.html
- ACSL by Example: Colección de especificaciones ACSL para algoritmos estándar
- Software Foundations (Coq): https://softwarefoundations.cis.upenn.edu/

## Resumen

El Diseño por Contratos es una metodología que transforma el desarrollo de software en una disciplina ingenieril rigurosa mediante especificaciones formales basadas en Lógica de Primer Orden.

### Conceptos Clave

:::{important} Ideas Fundamentales

1. **Contrato = Pre + Post + Invariantes**: Especificación completa del comportamiento
2. **Lógica de Hoare**: Sistema formal para demostrar corrección de programas
3. **Cuantificadores**: $\forall$ y $\exists$ para expresar propiedades sobre colecciones
4. **Invariantes de lazo**: Propiedades que se preservan en cada iteración
5. **Frame problem**: Especificar qué no cambia es tan importante como qué sí cambia
6. **Principio de Liskov**: Guía la herencia mediante contratos
7. **Verificación automática**: Herramientas pueden probar corrección matemáticamente
:::

### Beneficios Prácticos

1. **Documentación precisa**: Sin ambigüedades
2. **Detección temprana de errores**: En el punto exacto de violación
3. **Testing dirigido**: Los contratos generan casos de prueba
4. **Mantenibilidad**: El comportamiento esperado es explícito
5. **Confianza**: Pruebas matemáticas de corrección

### Desafíos

1. **Curva de aprendizaje**: Requiere familiaridad con lógica formal
2. **Costo inicial**: Escribir especificaciones toma tiempo
3. **Límites de automatización**: No todo es decidible
4. **Especificaciones complejas**: A veces más difíciles que el código

### Cuándo Usar DbC

- **Siempre**: Aserciones básicas en código crítico
- **APIs públicas**: Contratos completos en interfaces
- **Estructuras de datos**: Invariantes de clase
- **Sistemas críticos**: Especificación formal completa con verificación

El Diseño por Contratos no es solo una técnica, es una **filosofía de desarrollo** que eleva el software de artesanía a ingeniería, proporcionando las bases matemáticas para razonar rigurosamente sobre la corrección de programas.

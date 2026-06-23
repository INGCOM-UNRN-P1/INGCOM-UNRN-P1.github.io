# CSS Compartido para Diagramas SVG

Este documento explica cómo usar el archivo `svg.css` para crear diagramas técnicos consistentes con la identidad visual de la UNRN.

## 📋 Tabla de Contenidos

- [Instalación](#instalación)
- [Uso Básico](#uso-básico)
- [Paleta de Colores](#paleta-de-colores)
- [Clases Disponibles](#clases-disponibles)
- [Ejemplos](#ejemplos)
- [Tipografías](#tipografías)

## 🚀 Instalación

El archivo `svg.css` ya está ubicado en `resources/svg.css`. No requiere instalación adicional.

## 📖 Uso Básico

### Incluir el CSS en tu SVG

Agregá esta línea después de la declaración XML:

```xml
<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<?xml-stylesheet href="../resources/svg.css" type="text/css"?>
<svg width="600" height="450" viewBox="0 0 600 450" xmlns="http://www.w3.org/2000/svg">
  <!-- Tu contenido aquí -->
</svg>
```

**Nota:** Ajustá la ruta `../resources/svg.css` según la ubicación de tu SVG:
- Desde `apunte/13/diagrama.svg` → `../../resources/svg.css`
- Desde `apunte/diagrama.svg` → `../resources/svg.css`

### Definir Marcadores de Flechas

```xml
<defs>
  <marker id="arrowhead" markerWidth="10" markerHeight="10" refX="9" refY="3" orient="auto">
    <polygon points="0 0, 10 3, 0 6" fill="var(--unrn-red)"/>
  </marker>
</defs>
```

##  Paleta de Colores

### Colores Institucionales UNRN

| Color | Variable CSS | Hex | Uso |
|-------|-------------|-----|-----|
| Rojo UNRN | `--unrn-red` | `#eb2141` | Principal, acentos |
| Azul Oscuro UNRN | `--unrn-dark-blue` | `#192437` | Secundario, texto |

### Colores por Tipo de Estructura

| Estructura | Colores Primarios | Variables CSS |
|------------|------------------|---------------|
| **Pilas** | Rojos/Cálidos | `--stack-primary`, `--stack-data` |
| **Colas** | Verdes | `--queue-primary`, `--queue-data` |
| **Deques** | Morados | `--deque-primary`, `--deque-data` |
| **Listas** | Azules | `--list-primary`, `--list-data` |
| **Árboles** | Verde Natural | `--tree-primary`, `--tree-data` |
| **Grafos** | Naranjas | `--graph-primary`, `--graph-data` |
| **Hash/Mapas** | Índigos | `--hash-primary`, `--hash-data` |

##  Clases Disponibles

### Texto y Etiquetas

```xml
<text class="title">Título Principal</text>
<text class="subtitle">Subtítulo</text>
<text class="label">Etiqueta normal</text>
<text class="label-bold">Etiqueta en negrita</text>
<text class="label-small">Etiqueta pequeña</text>
<text class="index">Índice numérico</text>
```

### Código

```xml
<text class="code">int x = 42;</text>
<text class="code-comment">// comentario</text>
<text class="code-keyword">return</text>
```

### Nodos (Genéricos)

```xml
<rect class="node"/>              <!-- Nodo básico -->
<rect class="node-data"/>         <!-- Campo de datos -->
<rect class="node-pointer"/>      <!-- Campo de puntero -->
<rect class="node-null"/>         <!-- Puntero NULL -->
<rect class="node-highlight"/>    <!-- Nodo resaltado -->
```

### Nodos por Estructura

#### Pilas
```xml
<rect class="stack-node"/>
<rect class="stack-data"/>
<rect class="stack-pointer"/>
<path class="stack-arrow" marker-end="url(#arrowhead)"/>
<text class="stack-label">TOPE</text>
```

#### Colas
```xml
<rect class="queue-node"/>
<rect class="queue-data"/>
<rect class="queue-pointer"/>
<path class="queue-arrow" marker-end="url(#arrowhead)"/>
<text class="queue-label">FRENTE</text>
```

#### Deques
```xml
<rect class="deque-node"/>
<rect class="deque-data"/>
<path class="deque-arrow" marker-end="url(#arrowhead)"/>
<path class="deque-arrow-secondary"/>
```

#### Listas
```xml
<rect class="list-node"/>
<rect class="list-data"/>
<rect class="list-pointer"/>
<path class="list-arrow" marker-end="url(#arrowhead)"/>
```

#### Árboles
```xml
<rect class="tree-node"/>
<rect class="tree-data"/>
<path class="tree-arrow" marker-end="url(#arrowhead)"/>
```

### Flechas

```xml
<path class="arrow"/>                    <!-- Flecha genérica -->
<path class="arrow-primary"/>            <!-- Flecha rojo UNRN -->
<path class="arrow-secondary"/>          <!-- Flecha azul UNRN -->
<path class="arrow-dashed"/>             <!-- Flecha punteada -->
<path class="arrow-bidirectional"/>      <!-- Flecha doble -->
```

### Contenedores

```xml
<rect class="code-block"/>       <!-- Fondo para código -->
<rect class="highlight-box"/>    <!-- Caja resaltada -->
<rect class="info-box"/>         <!-- Caja informativa -->
<rect class="memory-cell"/>      <!-- Celda de memoria -->
```

### Estados

```xml
<rect class="valid"/>            <!-- Estado válido (verde) -->
<rect class="invalid"/>          <!-- Estado inválido (rojo) -->
<rect class="warning"/>          <!-- Advertencia (naranja) -->
```

### Líneas

```xml
<line class="divider"/>          <!-- Línea divisoria fina -->
<line class="divider-bold"/>     <!-- Línea divisoria gruesa -->
```

## 💡 Ejemplos

### Ejemplo 1: Pila Simple

```xml
<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<?xml-stylesheet href="../../resources/svg.css" type="text/css"?>
<svg width="400" height="300" viewBox="0 0 400 300" xmlns="http://www.w3.org/2000/svg">
  <defs>
    <marker id="arrowhead" markerWidth="10" markerHeight="10" refX="9" refY="3" orient="auto">
      <polygon points="0 0, 10 3, 0 6" fill="#eb2141"/>
    </marker>
  </defs>
  
  <text x="200" y="30" class="title">Pila - Operación Push</text>
  
  <!-- Estructura -->
  <rect x="50" y="60" width="100" height="60" class="stack-node"/>
  <text x="100" y="85" class="label-bold">pila_t</text>
  <line x1="50" y1="95" x2="150" y2="95" class="divider"/>
  <text x="65" y="110" class="label-small">tope:</text>
  <rect x="105" y="103" width="35" height="12" class="stack-pointer"/>
  
  <!-- Flecha -->
  <path d="M 130,109 L 180,109" class="stack-arrow" marker-end="url(#arrowhead)"/>
  
  <!-- Nodo tope -->
  <rect x="190" y="60" width="80" height="50" class="stack-node"/>
  <text x="230" y="75" class="label-bold">Nodo</text>
  <line x1="190" y1="85" x2="270" y2="85" class="divider"/>
  <rect x="200" y="90" width="60" height="15" class="stack-data"/>
  <text x="230" y="100" class="label">42</text>
  
  <text x="290" y="87" class="stack-label">← TOPE</text>
</svg>
```

### Ejemplo 2: Cola con Código

```xml
<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<?xml-stylesheet href="../../resources/svg.css" type="text/css"?>
<svg width="500" height="400" viewBox="0 0 500 400" xmlns="http://www.w3.org/2000/svg">
  <defs>
    <marker id="arrowhead" markerWidth="10" markerHeight="10" refX="9" refY="3" orient="auto">
      <polygon points="0 0, 10 3, 0 6" fill="#2e7d32"/>
    </marker>
  </defs>
  
  <text x="250" y="30" class="title">Cola - Operación Enqueue</text>
  
  <!-- Diagrama de la cola -->
  <!-- ... elementos de la cola ... -->
  
  <!-- Bloque de código -->
  <rect x="30" y="250" width="440" height="120" class="code-block"/>
  <text x="40" y="275" class="code">// Agregar elemento al final</text>
  <text x="40" y="295" class="code-keyword">void</text>
  <text x="70" y="295" class="code"> enqueue(cola_t *cola, int dato) {</text>
  <text x="40" y="315" class="code">    nodo_t *nuevo = crear_nodo(dato);</text>
  <text x="40" y="335" class="code">    cola->final->siguiente = nuevo;</text>
  <text x="40" y="355" class="code">}</text>
</svg>
```

## 🔤 Tipografías

El CSS incluye tres familias tipográficas:

### Fabrikat (Institucional UNRN)
- **Uso:** Títulos principales y subtítulos
- **Pesos disponibles:** Regular (400), Medium (500), Bold (700)
- **Clase:** `.title`, `.subtitle`

### Lato
- **Uso:** Texto general, etiquetas, descripciones
- **Pesos disponibles:** Regular (400), Bold (700)
- **Clase:** `.label`, `.label-bold`, `.label-small`

### Share Tech Mono
- **Uso:** Código, elementos técnicos
- **Peso:** Regular (400)
- **Clase:** `.code`, `.code-comment`, `.code-keyword`

## Mejores Prácticas

1. **Consistencia:** Usá siempre las clases CSS en lugar de estilos inline
2. **Colores semánticos:** Elegí el esquema de color apropiado para cada estructura
3. **Tipografía:** Respetá la jerarquía tipográfica (title → subtitle → label)
4. **Dimensiones:** Mantené proporciones consistentes (viewBox recomendado: 600-800px ancho)
5. **Accesibilidad:** Incluí títulos descriptivos y etiquetas claras

## 📝 Notas Adicionales

- Las variables CSS (`:root`) permiten personalización sin modificar todo el archivo
- Los marcadores de flechas deben definirse en `<defs>` de cada SVG
- Para más ejemplos, consultá `svg_example.svg`

## 🤝 Contribuciones

Para proponer nuevas clases o modificaciones a la paleta de colores:
1. Abrí un issue en el repositorio
2. Asegurate de mantener coherencia con la identidad UNRN
3. Probá tus cambios con múltiples diagramas

---

**Universidad Nacional de Río Negro - Ingeniería en Computación**  
*Programación 1 - Material Didáctico*

---
title: "Manual de Referencia: librerias-c"
subtitle: "Bibliotecas Canónicas de Cátedra de Tipos Abstractos de Datos"
author: "Cátedra de Algoritmos y Programación"
date: "2026-09-14"
---

(manual-librerias-c)=
# librerias-c — Bibliotecas Canónicas de Cátedra de TDAs

```{abstract}
**Rol en el ecosistema:** Colección de implementaciones de referencia de Tipos de Datos Abstractos (TAD) en C11 con contratos formales, encapsulamiento estricto y pruebas unitarias.
```

---

## 1. Propósito y Alcance

`librerias-c` contiene el código canónico de estructuras de datos fundamentales:
* **Vector Dinámico (`vector_t`)**: Redimensionamiento amortizado.
* **Lista Simplemente y Doblemente Enlazada (`lista_t`)**: Nodos con punteros opacos.
* **Pila (`pila_t`) y Cola (`cola_t`)**: Semántica LIFO y FIFO.
* **Tabla Hash (`hash_t`)**: Direccionamiento abierto y cerrado.
* **Árbol Binario de Búsqueda (`abb_t`)**: Recorridos ordenados e iteradores.

---

## 2. Compilación y Uso

```bash
cd /home/mrtin/dev/tools/librerias
make test
```
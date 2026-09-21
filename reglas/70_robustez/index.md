---
title: "Robustez y manejo de errores (0x70XX)"
short_title: "Robustez y errores"
subtitle: "Reglas de robustez, validacion e inicializacion defensiva."
---

# Robustez y manejo de errores (0x70XX)

Reglas de robustez, validación e inicialización defensiva.

## Tabla de reglas

| Regla | Título | Antipatrones integrados |
| :--- | :--- | :--- |
| [0x7001h](0x7001h.md) | Siempre debés inicializar las variables a un valor conocido | `AP-0x0003b`, `AP-0x0004b` |
| [0x7002h](0x7002h.md) | Validá los datos en la frontera del programa | — |
| [0x7003h](0x7003h.md) | No ignores valores de retorno que pueden indicar fallo | `AP-0x2013h` |
| [0x7004h](0x7004h.md) | No llamés `exit()` en funciones de biblioteca: propagá el error | — |
| [0x7005h](0x7005h.md) | Inicializá todos los campos de estructuras y arreglos | — |
| [0x7006h](0x7006h.md) | Probá explícitamente los casos borde | — |
| [0x7007h](0x7007h.md) | Evitá los parámetros bandera de tipo bool | — |

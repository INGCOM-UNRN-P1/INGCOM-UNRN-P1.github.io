---
title: "Manual de Referencia: cyberdeck"
subtitle: "Panel Docente y Companion Hardware de Control de Aula"
author: "Cátedra de Algoritmos y Programación"
date: "2026-09-14"
---

(manual-cyberdeck)=
# cyberdeck — Panel Docente y Companion Hardware de Control de Aula

:::{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Interfaz unificada de telemetría y control
táctil/físico para docentes en aula presencial o remota, integrando
diapositivas, videollamadas y disparadores de autoevaluación.

:::
<!-- {admonition} Resumen Técnico del Satélite -->

---

## 1. Propósito y Alcance

`cyberdeck` conecta la estación de trabajo docente con dispositivos periféricos
(teclados macro, microcontroladores ESP32/RP2040, interfaces táctiles) para
controlar en tiempo real herramientas como `slide-tools` y `meet-tools`.

---

## 2. Invocación y Operación

``` bash
# Iniciar daemon concentrador
cyberdeck start --port 8888

# Monitorear eventos de dispositivos
cyberdeck monitor
```
<!-- bash -->

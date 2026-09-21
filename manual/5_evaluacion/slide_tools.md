---
title: "Manual de Referencia: slide-tools"
subtitle: "Control Remoto y Sincronización de Diapositivas para Google Slides"
author: "Cátedra de Algoritmos y Programación"
date: "2026-09-14"
---

(manual-slide-tools)=
# slide-tools — Control Remoto y Sincronización para Google Slides

:::{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Transmisión remota de notas de orador, cronómetro
sincronizado y pase de diapositivas mediante protocolo WebSocket y extensión de
navegador.

:::
<!-- {admonition} Resumen Técnico del Satélite -->

---

## 1. Propósito y Alcance

Brinda a los docentes la capacidad de avanzar diapositivas y leer notas desde
dispositivos móviles o hardware dedicado con display OLED.

---

## 2. Uso Básico

``` bash
slide-tools serve --bind 0.0.0.0 --port 8766
```
<!-- bash -->

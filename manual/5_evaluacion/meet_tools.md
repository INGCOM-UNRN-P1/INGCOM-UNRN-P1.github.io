---
title: "Manual de Referencia: meet-tools"
subtitle: "Sistema de Control y Telemetría para Google Meet"
author: "Cátedra de Algoritmos y Programación"
date: "2026-09-14"
---

(manual-meet-tools)=
# meet-tools — Sistema de Control y Telemetría para Google Meet

```{admonition} Resumen Técnico del Satélite
:class: note
**Rol en el ecosistema:** Control bidireccional de sesiones de Google Meet desde clientes externos (Android/ESP32) mediante WebExtensions y daemon local vía WebSocket.
```

---

## 1. Propósito y Alcance

Permite silenciar micrófono, conmutar cámara, consultar lista de asistentes y recibir notificaciones de mano levantada sin alternar ventanas durante la clase.

---

## 2. Uso Básico

```bash
# Iniciar servidor WebSocket local
meet-tools server --port 8765
```
---
title: "Manual de Referencia: entorno"
subtitle: "Estación de Trabajo Portátil y Toolchain Unificado de C"
author: "Cátedra de Algoritmos y Programación"
date: "2026-09-14"
---

(manual-entorno)=
# entorno — Estación de Trabajo Portátil y Toolchain Unificado de C

```{note} Resumen Técnico del Satélite
**Rol en el ecosistema:** Aprovisionamiento unificado de la suite de desarrollo C (GCC, Clang, Make, GDB, Valgrind, Python/uv) y configuración multiplataforma idéntica en Linux, macOS y Windows/WSL.
```

---

## 1. Propósito y Alcance

`entorno` centraliza los scripts de bootstrap, configuración de terminales, perfiles de shell y dependencias nativas del sistema requeridas por todos los satélites de la materia.

---

## 2. Instalación y Puesta a Punto

### En sistemas Linux/macOS
```bash
./setup-personal.sh
```

### Verificación de Salud (Smoke Test)
```bash
entorno smoke
```

---

## 3. Comandos CLI Principales

```bash
# Ejecutar verificación diagnóstica de herramientas instaladas
smoke.sh

# Actualizar dependencias nativas y satélites
entorno update

# Limpiar artefactos temporales y cachés
entorno clean
```
---
title: "Manual de Referencia: gestion"
subtitle: "Automatización de Calificaciones y Sincronización de Cátedra"
author: "Cátedra de Algoritmos y Programación"
date: "2026-09-14"
---

(manual-gestion)=
# gestion — Automatización de Calificaciones y Sincronización

```{abstract}
**Rol en el ecosistema:** Sincronización bidireccional entre la base de datos de notas SQLite de Dredd, planillas de cálculo institucionales y registros académicos.
```

---

## 1. Propósito y Alcance

Automatiza la consolidación de notas, seguimiento de entregas y generación de reportes de cursada sin intervención manual.

---

## 2. Uso Básico

```bash
# Sincronizar calificaciones locales con planilla docente
gestion sync --db notas.db --sheet "P1-2026"
```
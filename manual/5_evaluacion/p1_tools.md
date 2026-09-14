---
title: "Manual de Referencia: p1-tools"
subtitle: "Meta-Repositorio y Orquestación Global del Ecosistema"
author: "Cátedra de Algoritmos y Programación"
date: "2026-09-14"
---

(manual-p1-tools)=
# p1-tools — Meta-Repositorio y Orquestación Global del Ecosistema

```{abstract}
**Rol en el ecosistema:** Repositorio central de gobernanza arquitectónica, sincronización de submódulos git, directivas de desarrollo, skills pedagógicas y auditoría de salud.
```

---

## 1. Propósito y Alcance

Coordina las 46 herramientas del ecosistema, provee scripts de clonación masiva (`scripts/sync.sh`), linters de coherencia documental y lineamientos normativos de cátedra.

---

## 2. Uso Básico

```bash
# Auditar salud y versiones de todos los repositorios satélites
./scripts/healthcheck.sh

# Desplegar actualizaciones a los entornos de desarrollo
./scripts/sync.sh
```
---
title: "Manual de Referencia: scorm-tools"
subtitle: "Empaquetador y Validador SCORM 1.2 / 2004 para Moodle"
author: "Cátedra de Algoritmos y Programación"
date: "2026-09-14"
---

(manual-scorm-tools)=
# scorm-tools — Empaquetador y Validador SCORM 1.2 / 2004 para Moodle

```{note} Resumen Técnico del Satélite
**Rol en el ecosistema:** Generación, validación formal y empaquetado de módulos interactivos compatibles con el estándar SCORM (1.2 y 2004 4th Edition) listos para su despliegue en plataformas LMS como Moodle.
```

---

## 1. Propósito y Alcance

`scorm-tools` provee una interfaz de línea de comandos para estructurar contenidos web educativos bajo la norma SCORM sin requerir herramientas propietarias. Valida esquemas XML de manifiesto (`imsmanifest.xml`) y empaqueta los artefactos finales en archivos comprimidos `.zip`.

---

## 2. Instalación y Requisitos

La herramienta se ejecuta en entornos Linux/POSIX y requiere Python 3.10+ gestionado mediante `uv`:

```bash
uv tool install --editable /home/mrtin/dev/tools/scorm-tools
```

---

## 3. Comandos CLI y Opciones

```bash
# Inicializar un proyecto SCORM con plantilla declarativa
scorm-tools init mi_modulo --version 2004

# Validar la estructura y manifiesto XML contra esquemas XSD
scorm-tools validate mi_modulo/

# Empaquetar el recurso para Moodle
scorm-tools build mi_modulo/ --output paquete_scorm.zip
```

### Opciones Principales
* `--version [1.2|2004]`: Selecciona el estándar SCORM de destino.
* `--output, -o`: Ruta del archivo zip generado.
* `--strict`: Activa validación estricta de rutas de recursos locales.
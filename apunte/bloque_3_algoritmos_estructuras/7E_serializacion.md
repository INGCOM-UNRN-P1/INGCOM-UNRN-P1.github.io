---
title: 'Serialización y endianness'
short_title: 'Serialización'
---

> **Prerrequisitos**: estructuras, bytes y archivos.

# Serialización

No copies una estructura directamente a una red o archivo esperando un formato
portable: puede contener padding, punteros, endianness y tamaños dependientes de
la plataforma. Definí un formato byte a byte y serializá cada campo.

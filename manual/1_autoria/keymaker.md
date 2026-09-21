---
title: "Manual de Referencia: keymaker"
subtitle: "Keymaker — Gestor de Cifrado, Integridad y Desbloqueo Temporal para Paquetes de Examen"
author: "Cátedra de Algoritmos y Programación"
date: "2026-08-31"
---

(manual-keymaker)=
# Keymaker — Gestor de Cifrado, Integridad y Desbloqueo Temporal para Paquetes de Examen

:::{note} Resumen Técnico del Satélite

**Rol en el ecosistema:** Cifrado simétrico autenticado (AES-256-GCM /
ChaCha20-Poly1305), firmas digitales Ed25519, Time-Lock para exámenes y división
de secretos de Shamir para la cátedra.

:::
<!-- {note} Resumen Técnico del Satélite -->

---

(manual-keymaker-proposito)=
## 1. Propósito y Filosofía Pedagógica

La herramienta **`keymaker`** provee la confidencialidad, autenticidad e
integridad de los enunciados de examen, pautas de corrección docente y bancos de
preguntas distribuidos en el campus virtual o repositorios de GitHub Classroom:

1. **Anti-Filtraciones con Time-Lock**: Los paquetes `.ripkg.enc` se distribuyen
   con anticipación pero permanecen inaccesibles hasta el segundo exacto del
   inicio del examen.
2. **Autenticidad comprobada por Firma Digital**: Las firmas Ed25519 certifican
   que los enunciados y starter kits provienen de la cátedra y no fueron
   alterados en tránsito.
3. **Control Colegiado con Shamir ($k$ de $n$)**: La pauta oficial de corrección
   solo puede ser abierta con el consenso de al menos $k$ docentes del equipo.
4. **Individualización por Legajo**: Derivación HKDF para paquetes de examen
   personalizados por alumno.

---

(manual-keymaker-instalacion)=
## 2. Instalación y Verificación del Entorno

::::{important}

verificá contar con OpenSSL y Python >= 3.11 antes de instalar `keymaker`.

::::
<!-- {important} -->

### 2.1 Requisitos Previos del Sistema

::::{tab-set}

:::{tab-item} Ubuntu / Debian

sudo apt update && sudo apt install -y build-essential libssl-dev python3-pip uv

:::
<!-- {tab-item} Ubuntu / Debian -->

:::{tab-item} Arch Linux / Manjaro

sudo pacman -S --needed base-devel openssl python-pip uv

:::
<!-- {tab-item} Arch Linux / Manjaro -->

:::{tab-item} Fedora / RHEL

sudo dnf install -y gcc openssl-devel python3-pip uv

:::
<!-- {tab-item} Fedora / RHEL -->

:::{tab-item} macOS (Homebrew)

brew install openssl uv

:::
<!-- {tab-item} macOS (Homebrew) -->

::::
<!-- {tab-set} -->

---

### 2.2 Métodos de Instalación

::::{tab-set}

:::{tab-item} uv tool (Recomendado)

uv tool install . --editable

:::
<!-- {tab-item} uv tool (Recomendado) -->

:::{tab-item} pip / venv

python3 -m venv .venv
source .venv/bin/activate
pip install -e .

:::
<!-- {tab-item} pip / venv -->

::::
<!-- {tab-set} -->

---

### 2.3 Verificación con `doctor`

````{code-block} bash
keymaker doctor

````
<!-- {code-block} bash -->

---

(manual-keymaker-comandos)=
## 3. Referencia Completa de Comandos CLI

| Comando / Sintaxis | Descripción y Efecto |
| :--- | :--- |
| `keymaker pack <origen> -o <out.ripkg.enc> -p <pass>` | Empaqueta y cifra un examen en formato `.ripkg.enc`. |
| `keymaker unpack <bundle.enc> -o <dir> -p <pass>` | Descifra y extrae el contenido verificando integridad y Time-Lock. |
| `keymaker gen-keys [-p catedra] [-o ./keys]` | Genera un nuevo par de claves asimétricas Ed25519 (`.key` y `.pub`). |
| `keymaker sign <archivo> -k <priv.key>` | Firma digitalmente un archivo con la clave privada de cátedra. |
| `keymaker verify <archivo> -s <sig> -p <pub.key>` | Valida la firma digital Ed25519 de un paquete o enunciado. |
| `keymaker split-secret <texto> -k 3 -n 5` | Divide un secreto en $n$ partes de Shamir requiriendo $k$ para abrir. |
| `keymaker combine-shares <s1> <s2> ...` | Reconstruye un secreto a partir de $k$ partes de Shamir. |
| `keymaker audit-passphrase "<frase>"` | Audita la entropía y robustez criptográfica de una contraseña. |
| `keymaker checksum <archivo>` | Calcula el digest SHA-256 de un archivo para control de integridad. |
| `keymaker doctor` | Diagnóstico del subsistema criptográfico y OpenSSL. |

---

(manual-keymaker-tutorial)=
## 4. Tutorial Paso a Paso con Ejemplos Reales

### Generación de Claves de Cátedra y Firma del Examen

````{code-block} bash
:linenos:
# 1. Generar par de claves Ed25519 de cátedra
keymaker gen-keys -p parcial1 -o ./claves

# 2. Empaquetar y cifrar el examen con Time-Lock para las 09:00 UTC
keymaker pack ./starter_tp1 -o parcial1.ripkg.enc -p "PassphraseSegura2026!" -t "2026-09-15T09:00:00Z" -s ./claves/parcial1.key

# 3. Desempaquetar y verificar la firma digital
keymaker unpack parcial1.ripkg.enc -o ./examen_listo -p "PassphraseSegura2026!" -v ./claves/parcial1.pub --force

````
<!-- {code-block} bash -->

---

(manual-keymaker-ejercicios)=
## 5. Ejercicios Prácticos y Desafíos

::::{exercise} Desafío 1: Auditoría de Entropía
:label: keymaker-desafio-1
Auditar una contraseña docente y verificar que supere los 80 bits de entropía
teórica.

**Paso a seguir:**
``` bash
keymaker audit-passphrase "C@tedra_P1_Segura_2026!#$"
```
<!-- bash -->

::::
<!-- {exercise} Desafío 1: Auditoría de Entropía -->

::::{solution} keymaker-desafio-1

``` bash
keymaker audit-passphrase "C@tedra_P1_Segura_2026!#$" --json
```
<!-- bash -->

::::
<!-- {solution} keymaker-desafio-1 -->

::::{exercise} Desafío 2: División de la Clave de Corrección con Shamir
:label: keymaker-desafio-2
Dividir la clave de corrección del examen entre 5 docentes exigiendo al menos 3
presentes para abrirla.

**Paso a seguir:**
``` bash
keymaker split-secret "ClaveMaestraCorreccion2026" -k 3 -n 5
```
<!-- bash -->

::::
<!-- {exercise} Desafío 2: División de la Clave de Corrección con Shamir -->

::::{solution} keymaker-desafio-2

``` bash
# Tomar 3 partes generadas y recombinarlas:
keymaker combine-shares "1:<share1_b64>" "3:<share3_b64>" "5:<share5_b64>"
```
<!-- bash -->

::::
<!-- {solution} keymaker-desafio-2 -->

::::{exercise} Desafío 3: Cifrado con Derivación por Legajo
:label: keymaker-desafio-3
Empaquetar un recuperatorio individualizado para el legajo `1238305`.

**Paso a seguir:**
``` bash
keymaker pack ./recuperatorio -o recup_1238305.ripkg.enc -p "MasterKey" -l "1238305"
```
<!-- bash -->

::::
<!-- {exercise} Desafío 3: Cifrado con Derivación por Legajo -->

::::{solution} keymaker-desafio-3

``` bash
keymaker unpack recup_1238305.ripkg.enc -o ./recup_abierto -p "MasterKey" -l "1238305"
```
<!-- bash -->

::::
<!-- {solution} keymaker-desafio-3 -->

---

(manual-keymaker-arquitectura)=
## 6. Arquitectura Interna y Mecanismo Técnico

- **Cifrado Simétrico Autenticado**: AES-256-GCM con nonces de 96 bits generados
  vía CSPRNG del kernel (`os.urandom`) y tags Poly1305/GCM de 128 bits.
- **KDF Robusto**: PBKDF2-HMAC-SHA256 con 600,000 iteraciones y HKDF-SHA256 para
  derivaciones secundarias.
- **Firmas Asimétricas**: Curva Ed25519 (RFC 8032) con verificación en tiempo
  constante.
- **Shamir Secret Sharing**: Aritmética de polinomios sobre el cuerpo finito
  Galois $GF(256)$ con generador $g=3$ y polinomio irreducible $0x11B$.

---

(manual-keymaker-ecosistema)=
## 7. Integración y Conexión con el Ecosistema

::::{mermaid}

graph TD
    DK[Deckard: Banco de Ejercicios] -->|Enunciados y resolvé| KM[Keymaker:
    Cifrado e Integridad]
    KM -->|Bundle Cifrado .ripkg.enc| CAMPUS[Campus Virtual / GitHub Classroom]
    KM -->|Pautas Docentes Cifradas| DR[Dredd: Autograding Masivo]
    KM -->|Firmas Ed25519| ALU[Alucard: Generador de Parciales]
    KM -->|Desbloqueo por Legajo HKDF| EST[Estudiante: Desempaquetado]

::::
<!-- {mermaid} -->

### Matriz de Intercambio de Datos

| Canal | Herramientas Conectadas | Tipo de Datos Transferidos |
| :--- | :--- | :--- |
| **Entradas (Inputs)** | `deckard`, `alucarD`, `dredd` | Enunciados YAML, resolvé canónicas, pautas de evaluación |
| **Salidas (Outputs)** | `dredd`, `nostromo`, Estudiantes | Bundles `.ripkg.enc`, firmas `.sig`, claves públicas `.pub` |
| **Sincronización** | `dredd`, `alucarD` | Ingesta segura y desbloqueo temporal sincronizado |

---

(manual-keymaker-seccion-plugins)=
## 8. Extensión, Desarrollo de Plugins y API Python

Para integrar `keymaker` en autograders personalizados o scripts de CI/CD:

- 👉 **Consultá la guía completa:** [Guía de Extensión y Creación de
  Plugins](plugins.md)

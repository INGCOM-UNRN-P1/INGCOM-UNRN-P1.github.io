---
title: "Manual del Ecosistema de Herramientas Pedagógicas"
short_title: "Ecosistema"
subtitle: "Documentación integral de las herramientas de compilación, análisis, diagnóstico y evaluación en C"
---

(manual-ecosistema-indice)=
# Manual del Ecosistema de Herramientas

El ecosistema de herramientas pedagógicas de la cátedra está compuesto por
aplicaciones modulares diseñadas bajo el principio de responsabilidad única.
Cada herramienta atiende una fase específica del ciclo pedagógico: desde la
autoría de consignas y el desarrollo asistido del alumno, hasta el análisis
forense de memoria y la evaluación docente masiva.

## Capas Arquitectónicas del Ecosistema

### 1. Autoría y Curaduría Pedagógica
Herramientas destinadas al cuerpo docente para el diseño curricular, la
redacción de guías de trabajos prácticos y la síntesis anti-copia de
cuestionarios y exámenes.
* **[Deckard](1_autoria/deckard.md)**: Curaduría de ejercicios, composición
  taxonómica Bloom y carga horaria.
* **[Alucard](1_autoria/alucard.md)**: Síntesis de exámenes impresos en Typst y
  lectura óptica OMR.
* **[Idkfa](1_autoria/idkfa.md)**: Generación procedural de variantes de tracing
  con compilación GCC.
* **[Moodle-Toolbox](1_autoria/moodle_toolbox.md)**: Validación e higiene de
  bancos GIFT y Moodle XML.
* **[MyST-Tools](1_autoria/myst_tools.md)**: Mantenimiento y compilación de
  apuntes teóricos.
* **[Keymaker](1_autoria/keymaker.md)**: Criptografía asimétrica y sellos de
  tiempo para exámenes.
* **[SCORM-Tools](1_autoria/scorm_tools.md)**: Empaquetado e interoperabilidad
  SCORM 1.2 / 2004.
* **[Tyrell](1_autoria/tyrell.md)**: Generación de datasets sintéticos y
  plantillas.
* **[Corbel](1_autoria/corbel.md)**: Formateador arquitectónico y documentación
  de TDAs.

### 2. Desarrollo y Verificación del Alumno
El entorno cotidiano del estudiante. Diagnóstico en tiempo real y asistencia
técnica sin conjeturas.
* **[Ripley](2_desarrollo/ripley.md)**: Microkernel orquestador de análisis y
  linter de cátedra.
* **[Daedalus](2_desarrollo/daedalus.md)**: Compilación pedagógica y traducción
  de advertencias GCC/Clang.
* **[Gaff](2_desarrollo/gaff.md)**: Linter de estilo y convenciones
  arquitectónicas 0xXXXXh.
* **[Spunkmeyer](2_desarrollo/spunkmeyer.md)**: Detector de antipatrones
  didácticos C.
* **[Kaneda](2_desarrollo/kaneda.md)**: Auditor estático de seguridad y
  funciones prohibidas.
* **[Nostromo](2_desarrollo/nostromo.md)**: Sandbox de ejecución aislada con
  Bubblewrap.
* **[Bishop](2_desarrollo/bishop.md)**: Trazador visual de memoria Stack y Heap.
* **[Entorno](2_desarrollo/entorno.md)**: Suite portátil y configuración de
  shell.
* **[Librerías C](2_desarrollo/librerias_c.md)**: Implementaciones canónicas de
  TDAs.

### 3. Diagnóstico Forense y Runtime
Inspección profunda de memoria, inyección de fallos y análisis de robustez.
* **[Hal](3_diagnostico/hal.md)**: Decodificador forense de core dumps y
  segfaults.
* **[Vasquez](3_diagnostico/vasquez.md)**: Inyección dinámica de fallos vía
  `LD_PRELOAD`.
* **[Tetsuo](3_diagnostico/tetsuo.md)**: Intérprete didáctico de
  AddressSanitizer y UndefinedBehaviorSanitizer.
* **[Vassili](3_diagnostico/vassili.md)**: Análisis de cobertura y Mutation
  Testing.
* **[Dietrich](3_diagnostico/dietrich.md)**: Verificación de cobertura lógica
  MC/DC.
* **[Callahan](3_diagnostico/callahan.md)**: Verificación formal deductiva con
  contratos ACSL y Frama-C.

### 4. Análisis Estático Especializado
Inspección algorítmica y de bajo nivel de código fuente C.
* **[Brett](4_analisis/brett.md)**: Auditoría de padding y optimización de
  memoria en structs.
* **[Crowe](4_analisis/crowe.md)**: Linter de portabilidad multi-arquitectura y
  endianness.
* **[Drake](4_analisis/drake.md)**: Fuzzer guiado por límites y valores de
  frontera.
* **[Ferro](4_analisis/ferro.md)**: Perfilado de rendimiento y contadores de
  ciclos de hardware.
* **[Giger](4_analisis/giger.md)**: Grafo de llamadas (Call Graphs) y código
  muerto.
* **[Kane](4_analisis/kane.md)**: Inspección de archivos binarios y mapeo de
  structs.
* **[Motoko](4_analisis/motoko.md)**: Verificación de encapsulamiento estricto
  en TDAs.
* **[Parker](4_analisis/parker.md)**: Auditor de ABI y visibilidad de símbolos
  en bibliotecas.
* **[Rachel](4_analisis/rachel.md)**: Desensamblador y análisis de complejidad
  en jump tables.
* **[Sebastian](4_analisis/sebastian.md)**: Análisis de recursión profunda y
  consumo de stack frames.
* **[Wierzbowski](4_analisis/wierzbowski.md)**: Auditor de grafos de inclusión
  de headers y Makefiles.
* **[Zhora](4_analisis/zhora.md)**: Auditor de seguridad y robustez en macros de
  preprocesador.

### 5. Evaluación y Gestión Docente Masiva
Infraestructura de corrección automática y seguimiento de cursada.
* **[Dredd](5_evaluacion/dredd.md)**: Calificador masivo, ingesta de Moodle y
  GitHub Classroom.
* **[Weyl](5_evaluacion/weyl.md)**: Comparación estructural semántica de ASTs y
  similitud de entregas.
* **[Cyberdeck](5_evaluacion/cyberdeck.md)**: Panel de control de aula y
  companion físico.
* **[Meet-Tools](5_evaluacion/meet_tools.md)**: Telemetría y control de Google
  Meet.
* **[Slide-Tools](5_evaluacion/slide_tools.md)**: Control remoto y
  sincronización de Google Slides.
* **[Gestion](5_evaluacion/gestion.md)**: Sincronización de notas con sistemas
  académicos.
* **[P1-Tools](5_evaluacion/p1_tools.md)**: Meta-repositorio y orquestación del
  ecosistema.

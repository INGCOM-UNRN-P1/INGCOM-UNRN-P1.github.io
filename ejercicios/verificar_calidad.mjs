#!/usr/bin/env node
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const EJERCICIOS_ROOT = __dirname;

const CANONICAL_FILES = [
  'bloque_2_memoria/1_punteros.md',
  'bloque_2_memoria/1b_punteros_ejercicios.md',
  'bloque_2_memoria/6_structs.md',
  'bloque_2_memoria/7_alias_tipos_ejercicios.md',
  'bloque_4_avanzados/3_archivos_binarios.md'
];

function findMarkdownFiles(dir) {
  let files = [];
  const entries = fs.readdirSync(dir, { withFileTypes: true });
  for (const entry of entries) {
    const fullPath = path.join(dir, entry.name);
    if (entry.isDirectory()) {
      if (entry.name.startsWith('.') || entry.name === 'node_modules') continue;
      files = files.concat(findMarkdownFiles(fullPath));
    } else if (entry.isFile() && entry.name.endsWith('.md')) {
      if (entry.name === 'MARCO_EDITORIAL.md' || entry.name === 'REPORTE_HALLAZGOS.md' || entry.name === 'readme.md') {
        continue;
      }
      files.push(fullPath);
    }
  }
  return files;
}

function auditFile(filePath) {
  const content = fs.readFileSync(filePath, 'utf8');
  const lines = content.split('\n');
  const relPath = path.relative(EJERCICIOS_ROOT, filePath);
  const issues = [];

  let plusUltraCount = 0;
  let misplacedAnchors = 0;
  let hasTestVectors = content.includes('Tabla de Vectores de Prueba') || content.includes('Vectores de Prueba');

  for (let i = 0; i < lines.length; i++) {
    const line = lines[i];

    // Chequeo 1: Boilerplate Plus Ultra
    if (line.includes('[*plus ultra*]')) {
      plusUltraCount++;
      issues.push(`Línea ${i + 1}: Detección de boilerplate residual '[*plus ultra*]'`);
    }

    // Chequeo 2: Ancla MyST desfasada (debe estar inmediatamente antes de un encabezado ### Ejercicio)
    if (line.match(/^\(ej_b\d+_c\w+_\d+\)=/)) {
      const nextNonEmpty = lines.slice(i + 1).find(l => l.trim().length > 0);
      if (nextNonEmpty && !nextNonEmpty.startsWith('#')) {
        misplacedAnchors++;
        issues.push(`Línea ${i + 1}: Ancla desfasada. La siguiente línea no vacía no es un encabezado ('${nextNonEmpty.substring(0, 30)}...')`);
      }
    }
  }

  // Chequeo 3: Requisitos canónicos estrictos para archivos certificados
  const isCanonical = CANONICAL_FILES.some(cf => relPath.endsWith(cf));
  if (isCanonical && !hasTestVectors) {
    issues.push(`Archivo canónico no contiene sección obligatoria 'Tabla de Vectores de Prueba'`);
  }

  return {
    file: relPath,
    isCanonical,
    issues,
    plusUltraCount,
    misplacedAnchors
  };
}

function main() {
  console.log('='.repeat(70));
  console.log('COMPUERTA DE CALIDAD EDITORIAL Y SINTACTICA - APUNTE P1');
  console.log('='.repeat(70));

  const files = findMarkdownFiles(EJERCICIOS_ROOT);
  let totalIssues = 0;
  const reportsWithIssues = [];

  for (const file of files) {
    const report = auditFile(file);
    if (report.issues.length > 0) {
      totalIssues += report.issues.length;
      reportsWithIssues.push(report);
    }
  }

  if (reportsWithIssues.length > 0) {
    console.error(`\nSe detectaron ${totalIssues} anomalías de calidad en ${reportsWithIssues.length} archivo(s):\n`);
    for (const r of reportsWithIssues) {
      console.error(`Archivo: ${r.file}`);
      for (const iss of r.issues) {
        console.error(`  - ${iss}`);
      }
    }
    console.log('\n' + '-'.repeat(70));
    console.log('ESTADO: FALLA (Regresiones detectadas)');
    console.log('-'.repeat(70));
    process.exit(1);
  }

  console.log(`\nArchivos auditados: ${files.length}`);
  console.log(`Archivos canónicos certificados: ${CANONICAL_FILES.length}`);
  console.log('Boilerplate residual: 0');
  console.log('Anclas desfasadas: 0');
  console.log('\n' + '-'.repeat(70));
  console.log('ESTADO: APROBADO (100% libre de regresiones)');
  console.log('-'.repeat(70));
  process.exit(0);
}

main();

#!/usr/bin/env node
import fs from 'node:fs';
import path from 'node:path';
import os from 'node:os';
import { execFileSync, spawnSync } from 'node:child_process';
import { fileURLToPath } from 'node:url';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const EJERCICIOS_ROOT = __dirname;

const ARGS = process.argv.slice(2);
const IS_HELP = ARGS.includes('--help') || ARGS.includes('-h');
const IS_VERBOSE = ARGS.includes('--verbose') || ARGS.includes('-v');
const IS_SUMMARY = ARGS.includes('--summary');
const IS_JSON = ARGS.includes('--json');
const NO_SANITIZE = ARGS.includes('--no-sanitize');
const TARGET_PATH_ARG = ARGS.find(arg => !arg.startsWith('--') && !arg.startsWith('-'));

if (IS_HELP) {
  console.log(`
Uso: node ejercicios/verificar_ejercicios.mjs [ruta] [opciones]

Argumentos:
  ruta               Archivo .md o directorio a verificar (por defecto: ejercicios/)

Opciones:
  --help, -h         Muestra esta ayuda.
  --summary          Muestra únicamente el resumen cuantitativo final.
  --verbose, -v      Muestra diagnósticos detallados y trazas de error.
  --json             Salida en formato JSON estructurado.
  --no-sanitize      Deshabilita AddressSanitizer y UndefinedBehaviorSanitizer.
`);
  process.exit(0);
}

const BASE_GCC_FLAGS = [
  '-Wall',
  '-Wextra',
  '-Werror',
  '-pedantic',
  '-std=c11'
];

function checkSanitizerSupport() {
  const probeCode = 'int main(void) { return 0; }';
  const probeFile = path.join(os.tmpdir(), `probe_${process.pid}.c`);
  const probeBin = path.join(os.tmpdir(), `probe_${process.pid}.bin`);
  fs.writeFileSync(probeFile, probeCode, 'utf8');
  try {
    const res = spawnSync('gcc', [...BASE_GCC_FLAGS, '-fsanitize=address,undefined', '-o', probeBin, probeFile]);
    return res.status === 0;
  } catch {
    return false;
  } finally {
    try { fs.unlinkSync(probeFile); } catch {}
    try { fs.unlinkSync(probeBin); } catch {}
  }
}

const HAS_SANITIZER = !NO_SANITIZE && checkSanitizerSupport();
const GCC_FLAGS = [
  ...BASE_GCC_FLAGS,
  ...(HAS_SANITIZER ? ['-fsanitize=address,undefined'] : [])
];

/**
 * Recorre recursivamente un directorio buscando archivos .md
 */
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

/**
 * Extrae bloques de código C dentro de :::: {solution} o identificados con main()
 */
function extractSolutions(filePath) {
  const content = fs.readFileSync(filePath, 'utf8');
  const lines = content.split('\n');
  const solutions = [];

  let currentAnchor = null;
  let currentTitle = null;
  let inSolution = false;
  let inCodeBlock = false;
  let codeBuffer = [];
  let codeLang = null;

  let codeFenceChar = null;
  let codeFenceLength = 0;

  for (let i = 0; i < lines.length; i++) {
    const line = lines[i];

    // Detectar ancla MyST: (ej_b2_c01_01)=
    const anchorMatch = line.match(/^\((ej_b\d+_c\w+_\d+)\)=/);
    if (anchorMatch) {
      currentAnchor = anchorMatch[1];
    }

    // Detectar encabezado de ejercicio: ### Ejercicio 2.01.01: ...
    const headerMatch = line.match(/^###\s+(Ejercicio\s+[^\n]+)/);
    if (headerMatch) {
      currentTitle = headerMatch[1];
      if (!currentAnchor) {
        currentAnchor = `line_${i + 1}`;
      }
    }

    // Delimitador de solución
    if (line.match(/^:{3,}\s*\{\s*solution\s*\}/)) {
      inSolution = true;
      continue;
    }

    // Bloques de código: ``` o ::: {code-block}
    const isBacktickFence = line.match(/^`{3,}([a-zA-Z0-9_-]+)?/);
    const isColonFence = line.match(/^:{3,}\s*\{code-block\}\s*([a-zA-Z0-9_-]+)?/);

    if ((isBacktickFence || isColonFence) && !inCodeBlock) {
      inCodeBlock = true;
      if (isBacktickFence) {
        codeFenceChar = '`';
        codeFenceLength = line.match(/^`+/)[0].length;
        codeLang = isBacktickFence[1] ? isBacktickFence[1].toLowerCase() : '';
      } else {
        codeFenceChar = ':';
        codeFenceLength = line.match(/^:+/)[0].length;
        codeLang = isColonFence[1] ? isColonFence[1].toLowerCase() : '';
      }
      codeBuffer = [];
      continue;
    }

    // Cierre de bloque de código
    if (inCodeBlock) {
      const isFenceClose = line.trim().startsWith(codeFenceChar.repeat(codeFenceLength)) &&
                           line.trim().length <= codeFenceLength + 1;
      const isHtmlCommentClose = line.trim().startsWith('<!-- {code-block');

      if (isFenceClose || isHtmlCommentClose) {
        inCodeBlock = false;
        codeFenceChar = null;
        codeFenceLength = 0;
        const code = codeBuffer.join('\n');
        
        const isC = codeLang === 'c' || codeLang === 'cpp' || code.includes('#include <');
        const hasMain = code.includes('int main(') || code.includes('int main (');

        if (inSolution && isC && hasMain) {
          solutions.push({
            anchor: currentAnchor || `unknown_${solutions.length + 1}`,
            title: currentTitle || 'Sin título',
            code,
            lineStart: i - codeBuffer.length
          });
        }
        codeBuffer = [];
        codeLang = null;
        continue;
      }
    }

    // Cierre de solución
    if (!inCodeBlock && inSolution && line.match(/^:{3,}\s*$/)) {
      inSolution = false;
      continue;
    }

    if (inCodeBlock) {
      // Ignorar opciones de directivas MyST como :linenos:, :caption:, etc.
      if (line.trim().startsWith(':') && codeBuffer.length === 0) {
        continue;
      }
      codeBuffer.push(line);
    }
  }

  return solutions;
}

/**
 * Compila y ejecuta una solución en C
 */
function verifySolution(solution, tempDir) {
  const cFile = path.join(tempDir, `${solution.anchor}.c`);
  const binFile = path.join(tempDir, `${solution.anchor}.bin`);

  fs.writeFileSync(cFile, solution.code, 'utf8');

  // Compilación
  const compileResult = spawnSync('gcc', [...GCC_FLAGS, '-o', binFile, cFile, '-lm'], {
    encoding: 'utf8',
    timeout: 10000
  });

  if (compileResult.status !== 0) {
    return {
      success: false,
      stage: 'compilation',
      error: (compileResult.stderr || compileResult.stdout || 'Fallo de compilación sin salida').trim()
    };
  }

  // Ejecución aislada en directorio temporal
  const runResult = spawnSync(binFile, [], {
    cwd: tempDir,
    encoding: 'utf8',
    timeout: 5000
  });

  if (runResult.error && runResult.error.code === 'ETIMEDOUT') {
    return {
      success: false,
      stage: 'execution_timeout',
      error: 'Ejecución excedió el tiempo límite de 5000ms (posible bucle infinito)'
    };
  }

  if (runResult.status !== 0) {
    return {
      success: false,
      stage: 'execution_runtime',
      error: (runResult.stderr || runResult.stdout || `Proceso terminó con código ${runResult.status}`).trim()
    };
  }

  return {
    success: true,
    stdout: runResult.stdout.trim()
  };
}

function main() {
  let targetFiles = [];

  if (TARGET_PATH_ARG) {
    const resolved = path.resolve(process.cwd(), TARGET_PATH_ARG);
    if (!fs.existsSync(resolved)) {
      console.error(`Error: La ruta '${TARGET_PATH_ARG}' no existe.`);
      process.exit(1);
    }
    const stat = fs.statSync(resolved);
    if (stat.isDirectory()) {
      targetFiles = findMarkdownFiles(resolved);
    } else {
      targetFiles = [resolved];
    }
  } else {
    targetFiles = findMarkdownFiles(EJERCICIOS_ROOT);
  }

  if (targetFiles.length === 0) {
    console.error('No se encontraron archivos markdown para analizar.');
    process.exit(1);
  }

  const tempDir = fs.mkdtempSync(path.join(os.tmpdir(), 'c11_harness_'));

  const overallResults = {
    totalFiles: targetFiles.length,
    filesWithSolutions: 0,
    totalSolutions: 0,
    passed: 0,
    compilationFailed: 0,
    executionFailed: 0,
    details: []
  };

  try {
    for (const file of targetFiles) {
      const relPath = path.relative(EJERCICIOS_ROOT, file);
      const solutions = extractSolutions(file);

      if (solutions.length === 0) {
        continue;
      }

      overallResults.filesWithSolutions++;
      const fileReport = {
        file: relPath,
        solutionsCount: solutions.length,
        results: []
      };

      for (const sol of solutions) {
        overallResults.totalSolutions++;
        const testResult = verifySolution(sol, tempDir);

        if (testResult.success) {
          overallResults.passed++;
          fileReport.results.push({
            anchor: sol.anchor,
            title: sol.title,
            status: 'PASS'
          });
        } else {
          if (testResult.stage === 'compilation') {
            overallResults.compilationFailed++;
          } else {
            overallResults.executionFailed++;
          }
          fileReport.results.push({
            anchor: sol.anchor,
            title: sol.title,
            status: 'FAIL',
            stage: testResult.stage,
            error: testResult.error
          });
        }
      }

      overallResults.details.push(fileReport);
    }
  } finally {
    fs.rmSync(tempDir, { recursive: true, force: true });
  }

  if (IS_JSON) {
    console.log(JSON.stringify(overallResults, null, 2));
    return;
  }

  // Reporte en texto plano directo
  console.log('='.repeat(70));
  console.log('ARNES DE VERIFICACION C11 - EJERCICIOS DE PROGRAMACION 1');
  console.log('Flags:', GCC_FLAGS.join(' '));
  console.log('='.repeat(70));

  for (const report of overallResults.details) {
    console.log(`\nArchivo: ${report.file} (${report.solutionsCount} soluciones encontradas)`);
    for (const r of report.results) {
      if (r.status === 'PASS') {
        console.log(`  [PASS] ${r.anchor} - ${r.title}`);
      } else {
        console.log(`  [FAIL] ${r.anchor} - ${r.title} (${r.stage})`);
        if (IS_VERBOSE || true) {
          const indentedError = r.error.split('\n').map(l => `         ${l}`).join('\n');
          console.log(indentedError);
        }
      }
    }
  }

  console.log('\n' + '-'.repeat(70));
  console.log(`Archivos analizados : ${overallResults.totalFiles}`);
  console.log(`Con soluciones C    : ${overallResults.filesWithSolutions}`);
  console.log(`Soluciones totales  : ${overallResults.totalSolutions}`);
  console.log(`Aprobadas (PASS)    : ${overallResults.passed}`);
  console.log(`Error compilación   : ${overallResults.compilationFailed}`);
  console.log(`Error ejecución     : ${overallResults.executionFailed}`);
  console.log('-'.repeat(70));

  if (overallResults.compilationFailed > 0 || overallResults.executionFailed > 0) {
    process.exit(1);
  }
}

main();

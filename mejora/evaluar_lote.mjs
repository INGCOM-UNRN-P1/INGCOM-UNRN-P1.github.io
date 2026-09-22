#!/usr/bin/env node
import { readdirSync, statSync, writeFileSync, existsSync, mkdirSync } from 'node:fs';
import { resolve, join, relative } from 'node:path';
import { execFileSync } from 'node:child_process';

const SCRIPT_PATH = resolve('/home/mrtin/.gemini/config/skills/jev-accelerator/scripts/jev-doc-quality.mjs');
const OUTPUT_DIR = resolve(process.cwd(), 'mejora');

// Usage: node evaluar_lote.mjs [directorio] [--out nombre.json] [--max-chars N]
// Sin argumentos, evalua la totalidad de apunte/ (comportamiento historico) y
// escribe mejora/evaluacion_inicial.json. Con un directorio, evalua solo ese
// subarbol (ej. "apunte/bloque_2_memoria") y por defecto escribe un archivo
// separado para no pisar la linea de base.
const args = process.argv.slice(2);
const positional = args.filter((a) => !a.startsWith('--'));
const targetDir = positional[0] ? resolve(process.cwd(), positional[0]) : resolve(process.cwd(), 'apunte');

const outFlagIndex = args.indexOf('--out');
const defaultOutName = positional[0] ? `evaluacion_${positional[0].replace(/[\\/]/g, '_')}.json` : 'evaluacion_inicial.json';
const outName = outFlagIndex !== -1 ? args[outFlagIndex + 1] : defaultOutName;

const maxCharsIndex = args.indexOf('--max-chars');
const extraDocQualityArgs = maxCharsIndex !== -1 ? ['--max-chars', args[maxCharsIndex + 1]] : [];

function getMarkdownFiles(dir) {
  let results = [];
  const list = readdirSync(dir);
  for (const file of list) {
    const filePath = join(dir, file);
    const stat = statSync(filePath);
    if (stat && stat.isDirectory()) {
      results = results.concat(getMarkdownFiles(filePath));
    } else if (file.endsWith('.md')) {
      results.push(filePath);
    }
  }
  return results;
}

async function main() {
  if (!existsSync(targetDir)) {
    console.error(`Directorio no encontrado: ${targetDir}`);
    process.exit(1);
  }

  const mdFiles = getMarkdownFiles(targetDir).sort();
  console.log(`Evaluando ${mdFiles.length} archivos de "${relative(process.cwd(), targetDir) || '.'}" con jev-doc-quality (evaluacion de la totalidad de cada documento, no solo su apertura)...`);

  if (!existsSync(OUTPUT_DIR)) {
    mkdirSync(OUTPUT_DIR, { recursive: true });
  }
  const outJsonPath = join(OUTPUT_DIR, outName);

  const results = [];
  let index = 0;

  for (const filePath of mdFiles) {
    index++;
    const relPath = relative(process.cwd(), filePath);
    process.stdout.write(`[${index}/${mdFiles.length}] Evaluando ${relPath}... `);
    try {
      const output = execFileSync('node', [SCRIPT_PATH, relPath, ...extraDocQualityArgs], {
        encoding: 'utf-8',
        env: process.env
      });
      const parsed = JSON.parse(output.trim());
      results.push(parsed);
      const mode = parsed.analysis?.mode ?? 'full';
      console.log(`OK (Indice: ${parsed.overallQualityIndex}/100, Nivel: ${parsed.qualityLevel}, analisis: ${mode})`);
    } catch (err) {
      console.error(`ERROR: ${err.message}`);
      results.push({
        file: relPath,
        error: err.message
      });
    }
    // Escritura incremental: si el lote se corta a mitad de camino (limite de
    // API, corte de red, etc.) no se pierde el progreso ya evaluado.
    writeFileSync(outJsonPath, JSON.stringify(results, null, 2), 'utf-8');
  }

  const ok = results.filter((r) => !r.error);
  if (ok.length > 0) {
    const avg = ok.reduce((sum, r) => sum + r.overallQualityIndex, 0) / ok.length;
    const byLevel = ok.reduce((acc, r) => {
      acc[r.qualityLevel] = (acc[r.qualityLevel] ?? 0) + 1;
      return acc;
    }, {});
    console.log(`\nResumen: ${ok.length}/${mdFiles.length} evaluados sin error. Indice promedio: ${avg.toFixed(1)}/100.`);
    console.log('Distribucion:', JSON.stringify(byLevel));
  }
  const errored = results.filter((r) => r.error);
  if (errored.length > 0) {
    console.log(`\n${errored.length} archivo(s) con error, ver detalle en ${outJsonPath}.`);
  }

  console.log(`\nResultados guardados en ${outJsonPath}`);
}

main().catch(err => {
  console.error('Fallo en evaluación global:', err);
  process.exit(1);
});

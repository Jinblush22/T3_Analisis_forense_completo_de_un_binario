# Análisis Estático - team_sample.exe
**Grupo 1**

## 1. Extracción de Cadenas (Strings)
Ejecutando rabin2 -z team_sample.exe, se identificaron las siguientes cadenas significativas:

* --- INICIANDO SIMULACION EDUCATIVA: edu-malware-sim ---
* C:\Windows\Temp\simulacion_educativa.txt
* calc.exe
* [*] Durmiendo 2 segundos...

## 2. Extracción de Imports (Análisis de APIs)
Llamadas críticas detectadas:

| Import | Librería | Propósito |
| :--- | :--- | :--- |
| CreateFileA | KERNEL32.dll | Creación de archivos. |
| WriteFile | KERNEL32.dll | Escritura de contenido. |
| Sleep | KERNEL32.dll | Retraso de ejecución. |
| WinExec | KERNEL32.dll | Ejecución de payload. |

## 3. Revisión de Secciones PE
* **.text**: Código ejecutable.
* **.data**: Variables globales.
* **.rdata**: Datos de solo lectura e imports.

## 4. Estructuras en .data / .rdata
Las cadenas están en .rdata. El binario no está empaquetado (no tiene packing).

## 5. Hipótesis Inicial
El binario es un simulador de malware que:
1. Muestra una firma en consola.
2. Evade sandboxes con un Sleep.
3. Crea un archivo en Temp para persistencia.
4. Ejecuta calc.exe como payload.
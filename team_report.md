# Reporte Final: Análisis Forense y Relevamiento de Binario
**Materia:** Programación Avanzada para Ciberseguridad / Análisis forense
**Grupo:** Grupo 1
**Repositorio:** Jinblush22/T3_Analisis_forense_completo_de_un_binario

---

## 1. Resumen Ejecutivo
Este reporte documenta el análisis integral del binario `team_sample.exe` realizado por el Grupo 1. El objetivo principal fue identificar y documentar comportamientos sospechosos mediante técnicas de análisis estático y dinámico. Se logró determinar que el binario realiza acciones de evasión (anti-sandbox), persistencia local y ejecución de un proceso hijo (payload), permitiendo al equipo comprender el flujo de trabajo técnico de un analista de malware.

## 2. Descripción del Binario
El binario analizado es un ejecutable de 32 bits diseñado para sistemas Windows, desarrollado en C++ para fines estrictamente educativos y de entrenamiento forense.

* **Nombre del archivo:** `team_sample.exe`
* **Arquitectura:** x86 (32 bits)
* **Funcionalidad:** Simulador de dropper educativo.

## 3. Técnicas de Análisis Aplicadas

### Análisis Estático (Ghidra & Rabin2)
Se utilizaron herramientas de desensamblado para inspeccionar el binario sin ejecutarlo:
* **Strings:** Localización de rutas críticas (`C:\Windows\Temp\`) y nombres de procesos externos (`calc.exe`).
* **Imports:** Identificación de llamadas a la API de Windows en `KERNEL32.dll` (`CreateFileA`, `Sleep`, `WinExec`).
* **Estructura PE:** Verificación de secciones estándar (`.text`, `.rdata`, `.data`) confirmando que el archivo no está empaquetado.

### Análisis Dinámico (x32dbg)
Se ejecutó el binario en un entorno controlado (VM) para monitorear su actividad:
* **Puntos de Control:** Uso de breakpoints en el `EntryPoint` (`007C6815`) para interceptar la ejecución.
* **Depuración Paso a Paso:** Observación de la manipulación de registros (EAX, EIP) durante las llamadas al sistema.
* **Validación de Evasión:** Confirmación del tiempo de espera programado para evadir análisis automatizados.

## 4. Hallazgos Clave
1. **Identificador de Campaña:** El binario contiene la firma `edu-malware-sim`, permitiendo su detección por indicadores de compromiso (IoC).
2. **Modificación del Sistema:** El programa genera un archivo de texto en una ruta temporal para simular la persistencia de un agente malicioso.
3. **Ejecución de Carga Útil:** Se validó que el binario lanza la calculadora de Windows como una prueba de concepto de ejecución de código.

## 5. Limitaciones del Análisis
* **Aislamiento:** El análisis se limitó a un entorno sin red, por lo que no se evaluaron posibles conexiones a servidores de Comando y Control (C2).
* **Ausencia de Ofuscación:** El binario es legible y no utiliza técnicas de "packing" o cifrado, lo que facilita excesivamente su detección en comparación con amenazas reales.

## 6. Conclusiones
Se concluyó que el binario `team_sample.exe` es una herramienta efectiva para demostrar las etapas iniciales de una infección. La integración de análisis estático y dinámico es vital para la respuesta ante incidentes. El uso de reportes estructurados en Markdown asegura que la evidencia técnica sea clara y reproducible para auditorías forenses.

---
**Elaborado por:** Andrea Abundiz, Angel Arcos, Johan Garay.  
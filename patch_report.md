# Reporte de Ingeniería Inversa y Patching - Grupo 1

## 1. Información del Binario
- **Nombre:** simulacion.exe
- **Plataforma:** Windows x86_64
- **Descripción:** Binario educativo que simula comportamientos de malware (evasión, persistencia y ejecución de procesos externos).

## 2. Metodología de Análisis
Se utilizó **Cutter** (motor Radare2) para el análisis estático y dinámico:
- `aaa`: Análisis automático del sistema.
- `afl`: Localización de la función `main`.
- **Gráfico de flujo**: Identificación del bloque de ejecución del payload.

## 3. Localización de la Instrucción
Se identificó que en el bloque de código final, el programa realizaba una llamada a la función `WinExec` para ejecutar `calc.exe`.
- **Dirección original:** `0x004011da`
- **Instrucción original:** `call dword [WinExec]`

## 4. Aplicación del Parche (Patching)
Para neutralizar el comportamiento del binario sin romper su estructura, se procedió a:
1. Abrir el archivo en modo escritura (`-w`).
2. Sustituir la instrucción de llamada en `0x004011da` por instrucciones `nop` (No Operation).
3. Confirmar los cambios en el binario mediante el comando `wc` en la consola.

## 5. Resultados
- **Binario Original:** Ejecutaba la calculadora de Windows automáticamente tras 2 segundos.
- **Binario Parcheado:** El programa completa su flujo informativo y muestra el mensaje final, pero la ejecución de la calculadora ha sido desactivada con éxito.
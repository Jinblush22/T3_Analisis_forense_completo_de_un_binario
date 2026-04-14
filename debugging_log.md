Informe de Debugging - Grupo 1
Programa: simulacion.exe

Herramienta: x32dbg

1. Punto de Interrupción Inicial (Breakpoint)
Se estableció un breakpoint de software en el EntryPoint del binario para iniciar el análisis dinámico.

Dirección: 007C6815

Instrucción: call simulacion.7C6F0B

Evidencia:

![Punto de interrupción](img/78eef125-2b65-4ed2-bcfd-31002c79cd1f.jpg)

2. Análisis de Registros (Paso a Paso)
Al ejecutar el programa de forma controlada utilizando la función Step Over (F8), se observó el comportamiento de los registros del CPU.

Observación: Se nota el cambio en el registro EIP (Instruction Pointer) y las variaciones en EAX y ECX al procesar las instrucciones de carga del sistema.

Evidencia:

![Registros en rojo](img/ea793639-d70e-4326-9d86-4753d96c8642.jpg)

3. Configuración de Hardware Breakpoint (Watchpoint)
Como requisito de la práctica, se configuró un watchpoint para monitorear el acceso a direcciones específicas de memoria durante la ejecución.

Estado: Se confirma la activación de múltiples puntos de control, incluyendo el punto de entrada opcional y llamadas internas del módulo.

Evidencia:

![Watchpoint](img/b561a1ea-24b2-4747-a043-2850d93eab5d.jpg)

4. Conclusión del Análisis
El binario simulacion.exe fue interceptado exitosamente. Se validó que el flujo de ejecución pasa por las librerías de sistema (ntdll.dll, gdi32full.dll) antes de ejecutar la lógica principal de la simulación.
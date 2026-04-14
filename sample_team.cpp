#include <windows.h>
#include <iostream>
#include <fstream>

int main() {
    // 1. Firma en memoria / Identificador
    std::cout << "--- INICIANDO SIMULACION EDUCATIVA: edu-malware-sim ---" << std::endl;

    // 2. EvasiÃ³n simple (Anti-Sandbox)
    // Muchos malwares "duermen" al inicio para que los sistemas de anÃ¡lisis automÃ¡tico
    std::cout << "[*] Durmiendo 2 segundos para simular evasion de sandbox..." << std::endl;
    Sleep(2000);

    // 3. Persistencia / Artefactos en el sistema
    std::cout << "[*] Creando archivo temporal de prueba..." << std::endl;
    HANDLE hFile = CreateFileA(
        "C:\\Windows\\Temp\\simulacion_educativa.txt", 
        GENERIC_WRITE, 
        0, 
        NULL, 
        CREATE_ALWAYS, 
        FILE_ATTRIBUTE_NORMAL, 
        NULL
    );

    if (hFile != INVALID_HANDLE_VALUE) {
        const char* msg = "Este es un archivo generado por un binario educativo.";
        DWORD bytesWritten;
        WriteFile(hFile, msg, strlen(msg), &bytesWritten, NULL);
        CloseHandle(hFile);
    } else {
        std::cout << "[!] No se pudo escribir en Temp (quizas falta de privilegios)." << std::endl;
    }

    // 4. EjecuciÃ³n de procesos externos
    std::cout << "[*] Ejecutando proceso externo (calc.exe)..." << std::endl;
    WinExec("calc.exe", SW_SHOW);

    // 5. Mensaje de interacciÃ³n
    MessageBoxA(NULL, "Simulacion completada con exito.\nEste binario es benigno.", "Edu-Malware-Sim", MB_OK | MB_ICONINFORMATION);

    std::cout << "[+] Tarea finalizada. Revisa tu visor de eventos o antivirus." << std::endl;

    return 0;
}
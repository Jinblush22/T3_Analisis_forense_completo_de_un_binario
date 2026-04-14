# Resumen de Detección: YARA y CAPA
**Grupo: Grupo 1**
**Materia:** Seguridad en Redes / Ingeniería Inversa

---

## 1. Identificación del Binario (Hashes)
A continuación se detallan los identificadores únicos del binario `team_sample.exe` obtenidos mediante el análisis forense inicial:

| Atributo | Valor |
| :--- | :--- |
| **MD5** | 5ab8268ac02946e8492c745b8656c850 |
| **SHA1** | e1d4e28281c648d37c3e59f99dd4a99e5710909a |
| **SHA256** | 90d7db9362184affa7412f6494c9d0489564241b7dac4fb1500655ca2557d35c |
| **Formato** | PE (Portable Executable) |
| **Arquitectura** | amd64 (64 bits) |

---

## 2. Detección por Reglas YARA
Se desarrolló una regla personalizada para detectar la firma del binario basada en los strings identificados durante el desensamblado.

**Regla: `IdentificarSimulacionEdu`**
```yara
rule IdentificarSimulacionEdu {
    strings:
        $s1 = "edu-malware-sim"
        $s2 = "simulacion_educativa.txt"
        $s3 = "calc.exe"
    condition:
        2 of them
}

## 3. Análisis de Capacidades (CAPA)
Se mapearon las funcionalidades del binario con el framework **MITRE ATT&CK**:

| Categoría | Detalle |
| :--- | :--- |
| **EXECUTION** | Shared Modules [T1129] |
| **MAEC Category** | Launcher (Lanzador de procesos) |

### Comportamientos Detectados (MBC)
* **DISCOVERY:** Detección de herramientas de análisis y enumeración de secciones PE.
* **FILE SYSTEM:** Capacidad de lectura y escritura de archivos (Persistencia).
* **PROCESS:** Creación y terminación de procesos (Ejecución de payload).
* **MEMORY:** Reserva de memoria y manipulación de permisos RWX.

---

## 4. Conclusión
El análisis mediante **YARA** y **CAPA** confirma que `team_sample.exe` se comporta como un **dropper/launcher**. Las capacidades detectadas, tales como técnicas de *anti-analysis* y manipulación directa de procesos, coinciden con los objetivos de diseño planteados, validando así la efectividad de las herramientas de detección estática para este caso de estudio.
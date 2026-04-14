rule IdentificarSimulacionEdu {
    strings:
        $s1 = "edu-malware-sim"
        $s2 = "simulacion_educativa.txt"
        $s3 = "calc.exe"
    condition:
        2 of them
}
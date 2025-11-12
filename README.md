# Tutoring

Este repositorio contiene los ejercicios y proyectos usados en las sesiones de tutoría. Los proyectos están organizados por carpetas tipo "Tutoring #N" (por ejemplo `Tutoring #1`, `Tutoring #2`, ...). Dentro de cada carpeta suele haber una solución de Visual Studio (`.sln`) y el código fuente correspondiente.

## Estructura general

- `Tutoring #1/`, `Tutoring #2/`, ... – carpetas por sesión con subcarpetas de proyecto y archivos `.sln`.
- Cada proyecto suele incluir una carpeta con el código fuente y una carpeta `x64/` generada al compilar.

Explora las carpetas para ver proyectos concretos. Por ejemplo:

- `Tutoring #1/1. Contar_Elementos_Mayores/Contar_Elementos_Mayores.sln` – solución de ejemplo.

## Requisitos

- Windows
- Visual Studio con carga de trabajo de C++ (o al menos MSBuild y las herramientas de C++).

## Cómo compilar y ejecutar

1) Abrir la solución en Visual Studio

- Abre Visual Studio > File > Open > Project/Solution > selecciona el `.sln` que quieras y compílalo.

2) (Alternativa) Usar MSBuild desde PowerShell / Developer Command Prompt

- Abre el Developer Command Prompt for Visual Studio (recomendado) o una PowerShell con las herramientas de compilación en PATH.
- Ejecuta, por ejemplo:

```powershell
msbuild "Tutoring #1\1. Contar_Elementos_Mayores\Contar_Elementos_Mayores.sln" /p:Configuration=Debug /p:Platform=x64
```

- El ejecutable compilado suele quedar en la carpeta del proyecto bajo `Debug\` o `Release\` según la configuración.

3) Ejecutar el binario

- Navega a la carpeta de salida (por ejemplo `..\Contar_Elementos_Mayores\Debug\`) y ejecuta el `.exe` desde PowerShell:

```powershell
cd 'Tutoring #1\1. Contar_Elementos_Mayores\Contar_Elementos_Mayores\Debug'
.\Contar_Elementos_Mayores.exe
```

Nota: si el nombre de la carpeta o archivo contiene espacios, mantén las rutas entre comillas.

## Sugerencias y próximos pasos

- Si quieres, puedo:
  - Añadir instrucciones específicas por proyecto (entrada, ejemplos de ejecución). 
  - Añadir un `LICENSE` (por ejemplo MIT) si quieres publicar este repositorio.
  - Añadir scripts de build para compilar múltiples soluciones en lote.

Dime qué prefieres y lo actualizo.

---
_Generado automáticamente: README inicial en español._

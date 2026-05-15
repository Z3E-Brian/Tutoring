# Tutorias de Programacion en C++

Coleccion de ejercicios progresivos de C++ desarrollados como material de tutoria universitaria. Cada sesion aborda temas fundamentales de programacion estructurada y orientada a objetos, desde vectores y matrices hasta POO, listas enlazadas y archivos.

## Requisitos de Build

- **IDE:** Visual Studio 2022 (v143)
- **Plataforma:** x64
- **Configuracion:** Debug
- **Librerias:** Solo STL de C++ (sin dependencias externas)
- **Estandar:** C++14 / C++17

Cada proyecto es autocontenido con su propio `.sln` y `.vcxproj`. Abrir el `.sln` correspondiente y compilar (F5).

## Contenido

| Sesion | Temas | Proyectos |
|--------|-------|-----------|
| **Vectores y Matrices** | Vectores, matrices, suma, transpuesta, ordenamiento, promedio, min/max, diagonal, extraccion de filas | 9 |
| **Punteros y Matrices** | Matrices (producto, suma bajo diagonal, busqueda), introduccion a punteros | 2 |
| **Punteros y Memoria Dinamica** | Memoria dinamica (new/delete), matrices dinamicas, puntero a puntero, arreglo de punteros | 3 |
| **POO Herencia y Polimorfismo** | Clases, objetos, herencia, polimorfismo, metodos virtuales, clases abstractas | 4 |
| **POO UML y Clases Abstractas** | UML a codigo, patron Composite, clases abstractas, arreglos dinamicos | 2 + 2 UML |
| **Listas Enlazadas** | Nodos, listas enlazadas simples, insercion inicio/final/ordenada | 1 |
| **Listas Enlazadas Avanzado** | Invertir, duplicados, intercalar, deteccion de ciclos, versiones recursivas | 1 |
| **Listas Enlazadas Ejercicios** | 7 ejercicios practicos, lista circular doble, algoritmo de Floyd | 1 |
| **Archivos File IO** | Lectura/escritura de archivos, concatenacion, conteo de palabras, fstream + POO | 2 |
| **POO Sistema de Productos** | Sistema de inventario con clases, arreglos dinamicos y busqueda por codigo | 1 |

## Estructura del Repositorio

```
Tutoria - Vectores y Matrices/
  ContarElementosMayores/     -- Contar elementos mayores a un limite
  ContarCeros/                -- Contar ceros en una matriz
  MinMax/                     -- Encontrar minimo y maximo
  PromedioVector/             -- Calcular promedio de un vector
  OrdenarVector/              -- Ordenamiento burbuja
  SumaMatrices/               -- Suma de dos matrices
  TransponerMatriz/           -- Transposicion de una matriz
  DiagonalPrincipal/          -- Imprimir diagonal principal
  FilaDeMatriz/               -- Extraer una fila de una matriz

Tutoria - Punteros y Matrices/
  DemostracionPunteros/       -- Demostracion de punteros y referencias
  PracticaMatrices/           -- Suma bajo diagonal, producto, busqueda en matriz

Tutoria - Punteros y Memoria Dinamica/
  DemostracionPunteros/       -- Memoria dinamica, arreglos dinamicos
  MatrizDinamica/             -- Matrices dinamicas con new
  EjerciciosPunteros/         -- Ejercicios de punteros

Tutoria - POO Herencia y Polimorfismo/
  POOEstudiante/              -- Clase Estudiante, arreglo de objetos
  POOProducto/                -- Clase Producto, inventario dinamico
  HerenciaYPolimorfismo/      -- Clase Transporte, Auto, Moto, Camion
  PolimorfismoEmpleados/      -- Clase abstracta Empleado, nomina polimorfica

Tutoria - POO UML y Clases Abstractas/
  first_uml_code.cpp          -- UML: Product, Sale, DiscountPolicy
  second_uml_code.cpp         -- Patron Composite: FileSystem
  ClasesAbstractas/           -- Shape, Circle, Rectangle
  ArreglosDinamicos/          -- 5 ejercicios de arreglos dinamicos

Tutoria - Listas Enlazadas/
  ListaEnlazada/              -- Implementacion basica de lista enlazada

Tutoria - Listas Enlazadas Avanzado/
  ListasAvanzado/             -- 20+ operaciones, metodos recursivos

Tutoria - Listas Enlazadas Ejercicios/
  EjerciciosListas/           -- 7 ejercicios + lista circular doble

Tutoria - Archivos File IO/
  LeerArchivos/               -- FileManager, PersonManager (multi-archivo)
  ArchivosPractica/           -- Concatenar, contar, buscar, eliminar lineas

Tutoria - POO Sistema de Productos/
  GestionProductos/           -- Inventario con Producto e Inventario
  Enunciados.txt              -- Enunciados de ejercicios adicionales
```

## Temas Cubiertos

### Programacion Estructurada
- Vectores y arreglos unidimensionales
- Matrices y arreglos bidimensionales
- Algoritmos de busqueda y ordenamiento
- Memoria dinamica con new/delete
- Punteros y arreglos de punteros
- Puntero a puntero
- Paso por referencia vs paso por valor

### Programacion Orientada a Objetos
- Clases, constructores y destructores
- Arreglos estaticos y dinamicos de objetos
- Herencia (clases base y derivadas)
- Polimorfismo (metodos virtuales)
- Clases abstractas y metodos virtuales puros
- Composicion y patron Composite
- Implementacion de UML a codigo

### Estructuras de Datos
- Listas enlazadas simples
- Operaciones avanzadas (invertir, intercalar, detectar ciclos)
- Lista circular doblemente enlazada
- Algoritmo de Floyd (deteccion de ciclos)

### Archivos
- Lectura y escritura de archivos de texto (fstream)
- Concatenacion de archivos
- Conteo de palabras y busqueda
- Integracion de archivos con POO

## Uso del Material

### Visual Studio 2022 (recomendado)

1. Clonar el repositorio:
   ```bash
   git clone https://github.com/Z3E-Brian/Tutoring.git
   ```
2. Abrir Visual Studio 2022
3. Navegar a la sesion de interes y abrir el `.sln` del proyecto deseado
4. Compilar con F5 (Debug, x64)

### VS Code + GCC (Multi-plataforma)

Tambien puedes compilar y ejecutar los proyectos desde VS Code usando GCC en cualquier sistema.

#### 1. Instalar GCC

**Windows (MinGW via MSYS2):**
- Descargar e instalar [MSYS2](https://www.msys2.org/)
- Desde la terminal MSYS2:
  ```bash
  pacman -S mingw-w64-ucrt-x86_64-gcc
  ```
- Agregar `C:\msys64\ucrt64\bin` al PATH del sistema

**Linux (apt):**
```bash
sudo apt install g++
```

**Mac (Homebrew):**
```bash
brew install gcc
```

Verificar la instalacion:
```bash
g++ --version
```

#### 2. Compilar un proyecto

La mayoria de los proyectos son un solo archivo `.cpp`. Compilar desde la terminal:

```bash
cd "Tutoria - Vectores y Matrices/ContarElementosMayores/Contar_Elementos_Mayores"
g++ Contar_Elementos_Mayores.cpp -o Contar_Elementos_Mayores.exe
./Contar_Elementos_Mayores.exe
```

Para proyectos multi-archivo (ej. `LeerArchivos`):
```bash
cd "Tutoria - Archivos File IO/LeerArchivos/leerArchivos"
g++ FileManager.cpp Person.cpp PersonManager.cpp RandomMatrixManager.cpp leerArchivos.cpp -o leerArchivos.exe
./leerArchivos.exe
```

#### 3. Compilar desde VS Code (opcional)

Crear un archivo `.vscode/tasks.json` en la raiz del proyecto:

```json
{
    "version": "2.0.0",
    "tasks": [{
        "label": "g++ build",
        "type": "shell",
        "command": "g++",
        "args": ["-g", "${file}", "-o", "${fileDirname}/${fileBasenameNoExtension}.exe"],
        "group": "build"
    }]
}
```

Luego abrir cualquier `.cpp` y presionar `Ctrl+Shift+B` para compilar.

**Nota:** Los proyectos multi-archivo como `LeerArchivos` requieren compilar todos los `.cpp` juntos (ver paso 2).

## Licencia

Material educativo de uso libre para fines academicos.

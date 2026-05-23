# Parte 1: Instalacion y verificacion del ambiente

## Sistema operativo utilizado

Ubuntu 26.04 LTS


## Version de g++

```bash
 g++ --version
```

Resultado:
g++ (Ubuntu 15.2.0-16ubuntu1) 15.2.0


## Version de gdb

```bash
gdb --version
```

Resultado:

GNU gdb (Ubuntu 17.1-2ubuntu1) 17.1


## Version de valgrind

```bash
valgrind --version
```

Resultado:

valgrind-3.26.0


## Programa de prueba

### Codigo original

```cpp
#include <iostream>

int main() {
    std::cout << "Ambiente listo para depuracion" << std::endl;
    return 0;
}
```

### Comando de compilacion

```bash
g++ -g -o prueba codigo/prueba.cpp
```

### Comando de ejecucion

```bash
./prueba
```

### Resultado observado

Ambiente listo para depuracion


## Explicacion de herramientas

### g++

Compilador de C++ que genera un ejecutable con el nombre que uno desee.

### gdb

Depurador que permite ejecutar programas paso a paso, inspeccionar variables y ver errores.

### valgrind

Herramienta que detecta problemas de memoria como fugas (memory leaks), accesos invalidos y uso incorrecto de memoria.


# Preguntas de reflexion

## 1. Para que sirve g++?

Sirve para compilar programas escritos en C++ y generar archivos ejecutables.

## 2. Para que sirve gdb?

Sirve para depurar programas, permitiendo analizar su ejecucion y encontrar errores.

## 3. Para que sirve valgrind?

Sirve para detectar errores relacionados con el uso de memoria, como fugas o accesos invalidos.

## 4. Por que se recomienda compilar con -g al depurar?

Porque agrega informacion de depuracion al ejecutable, permitiendo a herramientas como gdb mostrar lineas de codigo, variables y detalles internos.

## 5. Que diferencia hay entre compilar un programa y depurarlo?

Compilar convierte el codigo fuente en un ejecutable. Depurar consiste en analizar el programa durante su ejecucion para encontrar y corregir errores.
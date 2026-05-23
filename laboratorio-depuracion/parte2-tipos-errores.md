# Parte 2: Tipos de errores

# Ejercicio 1: Error de sintaxis

## Cdigo original

```cpp
#include <iostream>

int main() {
    std::cout << "Hola mundo" << std::endl
    return 0;
}
```

## Comando de compilacin

```bash
g++ -g -o error_sintaxis codigo/01_error_sintaxis.cpp
```

## Comando de ejecucin

No fue posible ejecutar inicialmente porque el programa no compilo.

## Error observado


error: expected ';' before 'return' esto sale en la linea 4


## Herramienta usada para depurar

Compilador g++

## Explicacin del problema

El programa tenia un error de sintaxis. Faltaba un punto y coma (`;`) al final de la linea:


std::cout << "Hola mundo" << std::endl


El compilador detecta que antes de `return` debia existir un `;`.

## Correccin realizada

Se agrega el punto y coma faltante.

## Cdigo corregido

```cpp
#include <iostream>

int main() {
    std::cout << "Hola mundo" << std::endl;
    return 0;
}
```

## Evidencia

Compilacion:

```bash
g++ -g -o error_sintaxis codigo/01_error_sintaxis.cpp
```

Ejecucion:


./error_sintaxis


Salida:

Hola mundo


## Reflexin

Los errores de sintaxis suelen ser faciles de encontrar porque el compilador indica dnde ocurri el problema y proporciona un mensaje descriptivo.

---

## Preguntas de reflexin

### 1. Este error fue detectado antes o durante la ejecucin?

Fue detectado antes de la ejecucin, durante la compilacin.

### 2. Que herramienta detect el error?

El compilador g++.

### 3. Por que este tipo de error suele ser mas facil de corregir que un error lgico?

Porque el compilador normalmente indica la linea y la causa aproximada del problema.

---

# Ejercicio 2: Error lgico

## Cdigo original

```cpp
#include <iostream>
#include <vector>

double calcular_promedio(const std::vector<int>& notas) {
    int suma = 0;

    for (int nota : notas) {
        suma += nota;
    }

    return suma;
}

int main() {
    std::vector<int> notas = {80,90,100};

    double promedio = calcular_promedio(notas);

    std::cout << "Promedio: " << promedio << std::endl;

    return 0;
}


## Comando de compilacin

```bash
g++ -g -o error_logico codigo/02_error_logico.cpp
```

## Comando de ejecucin


./error_logico

## Resultado obtenido originalmente

```bash
Promedio: 270
```

## Resultado esperado

Promedio esperado:

(80 + 90 + 100)/3

=270/3

=90

## Explicacin del error

La funcion sumaba correctamente las notas, pero retornaba solamente la suma total y no divide entre la cantidad de elementos del vector (en este caso 3).

## Correccin realizada

Se divide la suma entre la cantidad de notas:

```cpp
return (double)suma / notas.size();
```

## Cdigo corregido

```cpp
#include <iostream>
#include <vector>

double calcular_promedio(const std::vector<int>& notas) {
    int suma = 0;

    for (int nota : notas) {
        suma += nota;
    }

    return (double)suma / notas.size();
}

int main() {
    std::vector<int> notas = {80,90,100};

    double promedio = calcular_promedio(notas);

    std::cout << "Promedio: " << promedio << std::endl;

    return 0;
}
```

## Evidencia

Compilacin:

```bash
g++ -g -o error_logico codigo/02_error_logico.cpp
```

Ejecucin:

```bash
./error_logico
```

Salida:

```bash
Promedio: 90
```

## Reflexin

Los errores lgicos son mas dificiles de detectar porque el programa compila y se ejecuta normalmente, pero produce resultados incorrectos.

---

## Preguntas de reflexin

### 1. Por que el compilador no detect este error?

Porque la sintaxis era correcta y el programa no tenia errores de compilacin.

### 2. Por que este error se considera lgico?

Porque el algoritmo implementado no realizaba correctamente el calculo del promedio.

### 3. Que estrategia uso para encontrarlo?

Comparar el resultado esperado calculado manualmente con el resultado obtenido por el programa.

### 4. Que pruebas adicionales podria hacer?

Probar diferentes conjuntos de notas:

```cpp
{100,100,100}
{50,70,90}
{60,60,60}
```

para verificar que el promedio siempre se calcule correctamente.
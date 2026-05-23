# Parte 2: Tipos de errores

# Ejercicio 1: Error de sintaxis

## Codigo original

```cpp
#include <iostream>

int main() {
    std::cout << "Hola mundo" << std::endl
    return 0;
}
```

## Comando de compilacion

```bash
g++ -g -o error_sintaxis codigo/01_error_sintaxis.cpp
```

## Comando de ejecucin

No fue posible ejecutar inicialmente porque el programa no compilo.

## Error observado


error: expected ';' before 'return' esto sale en la linea 4


## Herramienta usada para depurar

Compilador g++

## Explicacion del problema

El programa tenia un error de sintaxis. Faltaba un punto y coma (`;`) al final de la linea:


std::cout << "Hola mundo" << std::endl


El compilador detecta que antes de `return` debia existir un `;`.

## Correccion realizada

Se agrega el punto y coma faltante.

## Codigo corregido

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


## Reflexion

Los errores de sintaxis suelen ser faciles de encontrar porque el compilador indica dnde ocurri el problema y proporciona un mensaje descriptivo.

---

## Preguntas de reflexion

### 1. Este error fue detectado antes o durante la ejecucion?

Fue detectado antes de la ejecucin, durante la compilacin.

### 2. Que herramienta detecta el error?

El compilador g++.

### 3. Por que este tipo de error suele ser mas facil de corregir que un error logico?

Porque el compilador normalmente indica la linea y la causa aproximada del problema.

---

# Ejercicio 2: Error logico

## Codigo original

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


## Comando de compilacion

```bash
g++ -g -o error_logico codigo/02_error_logico.cpp
```

## Comando de ejecucion


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

## Explicacion del error

La funcion sumaba correctamente las notas, pero retornaba solamente la suma total y no divide entre la cantidad de elementos del vector (en este caso 3).

## Correccion realizada

Se divide la suma entre la cantidad de notas:

```cpp
return (double)suma / notas.size();
```

## Codigo corregido

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

Ejecucion:

```bash
./error_logico
```

Salida:

```bash
Promedio: 90
```

## Reflexion

Los errores lgicos son mas dificiles de detectar porque el programa compila y se ejecuta normalmente, pero produce resultados incorrectos.

---

## Preguntas de reflexion

### 1. Por que el compilador no detecta este error?

Porque la sintaxis era correcta y el programa no tenia errores de compilacin.

### 2. Por que este error se considera logico?

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
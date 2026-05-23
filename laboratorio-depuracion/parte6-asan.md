# Parte 6: AddressSanitizer

## Codigo original

```cpp
#include <iostream>

int main() {
    int* numero = new int;
    *numero = 42;

    delete numero;

    std::cout << "Numero: " << *numero << std::endl;

    return 0;
}
```

## Comando de compilacion

Compilacion normal:

```bash
g++ -g -o use_after_free codigo/07_use_after_free.cpp
```

Compilacion con AddressSanitizer:

```bash
g++ -g -fsanitize=address -o use_after_free_asan codigo/07_use_after_free.cpp
```

## Comando de ejecucion

Programa normal:

```bash
./use_after_free
```

Programa con AddressSanitizer:

```bash
./use_after_free_asan
```

## Resultado observado

Al ejecutar normalmente, el programa podria mostrar un valor inesperado o incluso parecer funcionar correctamente.

Ejemplo:

```bash
Número: -580607706
```


## Herramienta usada para depurar

AddressSanitizer

## Analisis del problema

El programa crea memoria dinamica utilizando:

```cpp
new int
```

Luego libera esa memoria usando:

```cpp
delete numero;
```

Sin embargo, despues intenta acceder nuevamente a:

```cpp
*numero
```

Esto genera un acceso a memoria ya liberada.

## Resultado con AddressSanitizer

Ejemplo:

```bash
==9116==ERROR: AddressSanitizer: heap-use-after-free on address 0x7345f43e0010 at pc 0x6339b12d734e bp 0x7ffe2ef76c80 sp 0x7ffe2ef76c70
```

## Que significa heap-use-after-free?

Significa que el programa intenta usar memoria del heap despues de haber sido liberada.

## Linea donde ocurre el error

El error ocurre en:

```cpp
std::cout << "Numero: " << *numero << std::endl;
```

porque intenta acceder a un puntero que ya fue liberado.

## Correccion realizada

Se movio el `delete` para ejecutarlo despues del ultimo uso del puntero y se asigno `nullptr`.

## Codigo corregido

```cpp
#include <iostream>

int main() {
    int* numero = new int;

    *numero = 42;

    std::cout << "Numero: " << *numero << std::endl;

    delete numero;
    numero = nullptr;

    return 0;
}
```

## Evidencia

Compilacion:

```bash
g++ -g -fsanitize=address -o use_after_free_asan codigo/07_use_after_free.cpp
```

Ejecucion:

```bash
./use_after_free_asan
```

Resultado:

```bash
Numero: 42
```

No aparecen errores reportados por AddressSanitizer.

---

## Reflexion

AddressSanitizer permite detectar errores relacionados con memoria de forma inmediata y con mensajes ordenados. Sin esta herramienta algunos errores podrian pasar desapercibidos porque el programa podria parecer funcionar correctamente, pero no funciona de una manera correcta.

---

# Preguntas de reflexion

## 1. Que significa usar memoria despues de liberarla?

Significa acceder a memoria que ya fue devuelta al sistema y que ya no pertenece al programa.

## 2. Por que este error puede ser dificil de detectar sin herramientas?

Porque el programa podria continuar funcionando aparentemente normal y producir errores solo en ciertos casos.

## 3. Que ventaja tiene AddressSanitizer sobre ejecutar el programa normalmente?

Permite detectar errores de memoria automaticamente y mostrar informacion detallada sobre donde ocurren.

## 4. Que diferencia observo entre el reporte de valgrind y el reporte de AddressSanitizer?

Valgrind analiza la ejecucion detectando problemas de memoria, mientras que AddressSanitizer muestra errores inmediatamente durante la ejecucion y suele indicar con mas detalle la ubicacion del problema.

## 5. Por que es buena practica asignar nullptr despues de liberar un puntero?

Porque evita que el puntero siga apuntando a una direccion invalida y reduce la posibilidad de usar memoria liberada accidentalmente.
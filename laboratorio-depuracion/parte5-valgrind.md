# Parte 5: Analisis de memoria con valgrind

# Ejercicio 1: Perdida de memoria

## Codigo original

```cpp
#include <iostream>

void crear_arreglo() {
    int* datos = new int[10];

    for (int i = 0; i < 10; i++) {
        datos[i] = i * 2;
    }

    std::cout << "Primer elemento: " << datos[0] << std::endl;
}

int main() {
    crear_arreglo();
    return 0;
}
```

## Comando de compilacion

```bash
g++ -g -o memory_leak codigo/05_memory_leak.cpp
```

## Comando de ejecucion

```bash
./memory_leak
```

## Resultado observado

```bash
Primer elemento: 0
```

## Herramienta usada para depurar

Valgrind

## Analisis del problema

El programa crea un arreglo dinamico usando `new`, pero nunca libera la memoria reservada.

Esto genera una perdida de memoria.

## Resultado con valgrind

```bash
definitely lost: 40 bytes in 1 blocks
```

## Que significa definitely lost?

Significa que existe memoria reservada que ya no puede recuperarse porque se perdio la referencia a ella.

## Correccion realizada

Se agrego:

```cpp
delete[] datos;
```

## Codigo corregido

```cpp
#include <iostream>

void crear_arreglo() {
    int* datos = new int[10];

    for (int i = 0; i < 10; i++) {
        datos[i] = i * 2;
    }

    std::cout << "Primer elemento: " << datos[0] << std::endl;

    delete[] datos;
}

int main() {
    crear_arreglo();
    return 0;
}
```

## Evidencia

Comando:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./memory_leak
```

Resultado:

```bash
All heap blocks were freed -- no leaks are possible
```

---

## Reflexion

Aunque el programa parecia funcionar correctamente, existia una perdida de memoria. Valgrind permite encontrar problemas que normalmente no son visibles.

---

# Preguntas de reflexion

## 1. Que es una perdida de memoria?

Es memoria reservada dinamicamente que nunca fue liberada.

## 2. Por que el programa puede terminar aparentemente bien aunque tenga una perdida de memoria?

Porque el sistema operativo recupera la memoria cuando el programa finaliza.

## 3. Que significa liberar memoria dinamica?

Significa devolver memoria reservada al sistema para evitar desperdicio de recursos.

## 4. Por que se usa delete[] y no solo delete?

Porque la memoria fue reservada como un arreglo usando `new[]`.

## 5. Que tipo de problemas podrian aparecer en programas grandes si no se libera memoria?

Consumo excesivo de memoria, disminucion del rendimiento y fallos del programa.

---

# Ejercicio 2: Acceso fuera de limites

## Codigo original

```cpp
#include <iostream>

int main() {
    int* arreglo = new int[5];

    for (int i = 0; i <= 5; i++) {
        arreglo[i] = i * 10;
    }

    std::cout << "Programa finalizado" << std::endl;

    delete[] arreglo;

    return 0;
}
```

## Comando de compilacion

```bash
g++ -g -o invalid_access codigo/06_invalid_access.cpp
```

## Comando de ejecucion

```bash
./invalid_access
```

## Resultado observado

El programa puede ejecutarse y mostrar:

```bash
Programa finalizado
```

aunque internamente existe un error.

## Herramienta usada para depurar

Valgrind

## Resultado con valgrind

Ejemplo:

```bash
Invalid write of size 4
```

## Analisis del problema

El arreglo tiene posiciones desde:

```cpp
arreglo[0]
```

hasta:

```cpp
arreglo[4]
```

Sin embargo el ciclo usa:

```cpp
for(int i=0;i<=5;i++)
```

lo que intenta acceder a:

```cpp
arreglo[5]
```

que esta fuera de los limites permitidos.

## Correccion realizada

Se modifico la condicion del ciclo.

## Codigo corregido

```cpp
#include <iostream>

int main() {

    int* arreglo = new int[5];

    for (int i = 0; i < 5; i++) {
        arreglo[i] = i * 10;
    }

    std::cout << "Programa finalizado" << std::endl;

    delete[] arreglo;

    return 0;
}
```

## Evidencia

Comando:

```bash
valgrind --leak-check=full ./invalid_access
```

Resultado:

```bash
ERROR SUMMARY: 0 errors
```

---

## Reflexion

Los accesos fuera de limites pueden ser dificiles de detectar porque el programa podria continuar ejecutandose aparentemente normal.

---

# Preguntas de reflexion

## 1. Por que el programa podria no fallar aunque acceda fuera del arreglo?

Porque puede escribir en una zona de memoria que no genera un error inmediato.

## 2. Que significa escribir fuera de los limites de un arreglo?

Significa acceder a posiciones de memoria que no pertenecen al arreglo.

## 3. Por que este tipo de error es peligroso?

Porque puede modificar datos inesperados y generar errores dificiles de encontrar.

## 4. Que diferencia hay entre un error visible y un comportamiento indefinido?

Un error visible produce un fallo claro, mientras que un comportamiento indefinido puede generar resultados distintos o inesperados.
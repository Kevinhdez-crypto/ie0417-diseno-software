# Parte 7: Analisis de hilos y condiciones de carrera

## Codigo original

```cpp
#include <iostream>
#include <thread>

int contador = 0;

void incrementar() {
    for (int i = 0; i < 100000; i++) {
        contador++;
    }
}

int main() {
    std::thread hilo1(incrementar);
    std::thread hilo2(incrementar);

    hilo1.join();
    hilo2.join();

    std::cout << "Contador final: " << contador << std::endl;

    return 0;
}
```

## Comando de compilacion

Compilacion normal:

```bash
g++ -g -pthread -o race_condition codigo/08_race_condition.cpp
```

Compilacion con ThreadSanitizer:

```bash
g++ -g -fsanitize=thread -pthread -o race_condition_tsan codigo/08_race_condition.cpp
```

## Comando de ejecucion

Programa normal:

```bash
./race_condition
./race_condition
./race_condition
```

Programa con ThreadSanitizer:

```bash
./race_condition_tsan
```

Programa con Helgrind:

```bash
valgrind --tool=helgrind ./race_condition
```

## Resultado esperado

Como cada hilo incrementa el contador 100000 veces y existen dos hilos:

```text
100000 + 100000 = 200000
```

El resultado esperado es:

```bash
Contador final: 200000
```

## Resultados observados


```bash
Contador final: 200000
Contador final: 122744
Contador final: 200000
```

## Herramientas usadas para depurar

- ThreadSanitizer
- Helgrind

## Analisis del problema

Dos hilos intentan modificar simultaneamente la variable compartida:

```cpp
contador
```

La operacion:

```cpp
contador++
```

no ocurre en un solo paso.

Internamente realiza:

```cpp
leer valor
sumar 1
guardar valor
```

Los hilos pueden interferir entre si y perder incrementos.

## Resultado con ThreadSanitizer

Ejemplo:

```bash
WARNING: ThreadSanitizer: data race
```

ThreadSanitizer detecto accesos simultaneos a una variable compartida.

## Resultado con Helgrind

Ejemplo:

```bash
Possible data race during write
```

Helgrind reporto una posible condicion de carrera entre los hilos.

## Que es una condicion de carrera?

Es una situacion donde varios hilos acceden a una misma variable compartida y el resultado depende del orden en que ocurran las operaciones.

## Correccion realizada

Se utilizo `std::mutex` para permitir que solo un hilo acceda al contador a la vez.

## Codigo corregido

```cpp
#include <iostream>
#include <thread>
#include <mutex>

int contador = 0;
std::mutex mtx;

void incrementar() {

    for (int i = 0; i < 100000; i++) {
        std::lock_guard<std::mutex> lock(mtx);
        contador++;
    }

}

int main() {

    std::thread hilo1(incrementar);
    std::thread hilo2(incrementar);

    hilo1.join();
    hilo2.join();

    std::cout << "Contador final: " << contador << std::endl;

    return 0;
}
```

## Evidencia

Compilacion:

```bash
g++ -g -pthread -o race_condition_corregido codigo/09_race_condition_corregido.cpp
```

Ejecucion:

```bash
./race_condition_corregido
```

Resultado:

```bash
Contador final: 200000
```

Con Helgrind:

```bash
ERROR SUMMARY: 0 errors
```

Con ThreadSanitizer:

```bash
No warnings reported
```

---

## Reflexion

Los errores de concurrencia pueden ser dificiles de detectar porque no siempre producen el mismo resultado. Herramientas como ThreadSanitizer y Helgrind ayudan a identificar estos problemas rapidamente.

---

# Preguntas de reflexion

## 1. Por que contador++ no es una operacion segura entre varios hilos?

Porque internamente realiza varias operaciones y dos hilos pueden modificar el valor al mismo tiempo.

## 2. Que significa que dos hilos accedan a la misma variable compartida?

Significa que ambos pueden leer o modificar el mismo espacio de memoria simultaneamente.

## 3. Que problema resuelve std::mutex?

Evita que varios hilos accedan simultaneamente a una seccion critica.

## 4. Que hace std::lock_guard?

Bloquea automaticamente el mutex y lo libera al salir del bloque de codigo.

## 5. Por que los errores de concurrencia pueden ser dificiles de reproducir?

Porque dependen del orden y tiempo en que los hilos son ejecutados.

## 6. Cual herramienta le parecio mas clara para analizar este caso: ThreadSanitizer o Helgrind?

ThreadSanitizer resulto mas claro porque muestra informacion mas directa sobre la condicion de carrera y la linea donde ocurre.
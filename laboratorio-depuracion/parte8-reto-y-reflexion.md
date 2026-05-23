# Parte 8: Mini reto de depuracion

## Mini reto de depuracion

### Codigo original

```cpp
#include <iostream>

int obtener_mayor(int* datos, int tamano) {
    int mayor = 0;

    for (int i = 0; i <= tamano; i++) {
        if (datos[i] > mayor) {
            mayor = datos[i];
        }
    }

    return mayor;
}

double calcular_promedio(int* datos, int tamano) {
    int suma = 0;

    for (int i = 0; i < tamano; i++) {
        suma += datos[i];
    }

    return suma;
}

int main() {
    int tamano = 5;
    int* datos = new int[tamano];

    datos[0] = -10;
    datos[1] = -20;
    datos[2] = -5;
    datos[3] = -30;
    datos[4] = -15;

    int mayor = obtener_mayor(datos, tamano);
    double promedio = calcular_promedio(datos, tamano);

    std::cout << "Mayor: " << mayor << std::endl;
    std::cout << "Promedio: " << promedio << std::endl;

    return 0;
}
```

## Comando de compilacion

Compilacion normal:

```bash
g++ -g -o reto codigo/10_reto.cpp
```

Compilacion con AddressSanitizer:

```bash
g++ -g -fsanitize=address -o reto_asan codigo/10_reto.cpp
```

## Comando de ejecucion

Programa normal:

```bash
./reto
```

Con Valgrind:

```bash
valgrind --leak-check=full ./reto
```

Con AddressSanitizer:

```bash
./reto_asan
```

## Resultado inicial del programa

Ejemplo:

```bash
Mayor: 0
Promedio: -80
```

## Herramientas usadas

- Ejecucion normal
- Valgrind
- AddressSanitizer
- GDB

## Errores encontrados

### Error logico en el calculo del mayor

La variable:

```cpp
int mayor = 0;
```

genera un problema porque todos los valores del arreglo son negativos.

El programa devuelve:

```bash
Mayor: 0
```

aunque el mayor valor real es:

```bash
-5
```

---

### Acceso fuera de limites

El ciclo:

```cpp
for(int i=0;i<=tamano;i++)
```

intenta acceder a:

```cpp
datos[5]
```

cuando las posiciones validas son:

```cpp
datos[0]
hasta
datos[4]
```

AddressSanitizer reporto:

```bash
heap-buffer-overflow
```

---

### Perdida de memoria

La memoria reservada con:

```cpp
new int[tamano]
```

nunca fue liberada.

Valgrind reporto:

```bash
definitely lost
```

---

### Error en el calculo del promedio

La funcion:

```cpp
return suma;
```

solo retorna la suma y no calcula el promedio.

---

## Como se encontro cada error

- La ejecucion normal permitio observar resultados incorrectos.
- AddressSanitizer encontro el acceso fuera de limites.
- Valgrind encontro la perdida de memoria.
- GDB permitio inspeccionar valores internos.

## Correccion realizada

Se realizaron los siguientes cambios:

1. Inicializar `mayor` con el primer elemento.
2. Corregir el limite del ciclo.
3. Dividir la suma entre el tamano.
4. Liberar memoria usando `delete[]`.

## Codigo corregido

```cpp
#include <iostream>

int obtener_mayor(int* datos, int tamano) {

    int mayor = datos[0];

    for(int i=0;i<tamano;i++) {

        if(datos[i] > mayor) {
            mayor = datos[i];
        }

    }

    return mayor;
}

double calcular_promedio(int* datos,int tamano) {

    int suma = 0;

    for(int i=0;i<tamano;i++) {
        suma += datos[i];
    }

    return (double)suma/tamano;
}

int main() {

    int tamano = 5;

    int* datos = new int[tamano];

    datos[0]=-10;
    datos[1]=-20;
    datos[2]=-5;
    datos[3]=-30;
    datos[4]=-15;

    int mayor = obtener_mayor(datos,tamano);

    double promedio = calcular_promedio(datos,tamano);

    std::cout<<"Mayor: "<<mayor<<std::endl;
    std::cout<<"Promedio: "<<promedio<<std::endl;

    delete[] datos;

    return 0;
}
```

## Resultado final

```bash
Mayor: -5
Promedio: -16
```

## Que herramienta fue mas util y por que?

AddressSanitizer fue la herramienta mas util porque detecto rapidamente el acceso fuera de limites y mostro exactamente donde ocurria el problema.

---

# Parte 9: Reflexion final

## Reflexion final

### 1. Que entiende ahora por depuracion?

Es el proceso de encontrar, analizar y corregir errores dentro de un programa.

### 2. Por que no basta con que un programa compile?

Porque un programa puede compilar correctamente y aun asi producir resultados incorrectos o errores durante la ejecucion.

### 3. Cual fue la diferencia entre un error de sintaxis y un error logico?

Un error de sintaxis impide compilar el programa, mientras que un error logico permite la ejecucion pero genera resultados incorrectos.

### 4. Que ventaja tiene usar gdb?

Permite ejecutar paso a paso e inspeccionar variables durante la ejecucion.

### 5. Que ventaja tiene usar valgrind?

Permite detectar errores relacionados con memoria y fugas de memoria.

### 6. Que ventaja tiene usar AddressSanitizer?

Detecta rapidamente errores de memoria durante la ejecucion y muestra informacion detallada.

### 7. Que aprendio sobre errores de memoria?

Aprendi que pueden existir aunque el programa aparentemente funcione correctamente.

### 8. Que aprendio sobre errores de concurrencia?

Aprendi que varios hilos pueden interferir entre si y producir resultados inesperados.

### 9. Cual fue el error mas facil de encontrar?

El error de sintaxis porque el compilador mostraba directamente la linea del problema.

### 10. Cual fue el error mas dificil de entender?

La condicion de carrera porque no ocurria siempre de la misma manera.

### 11. Que herramienta usaria primero si un programa produce un resultado incorrecto?

Usaria GDB.

### 12. Que herramienta usaria primero si un programa falla con segmentation fault?

Usaria AddressSanitizer o GDB.

### 13. Que herramienta usaria primero si sospecha una perdida de memoria?

Usaria Valgrind.

### 14. Que herramienta usaria primero si sospecha un problema con hilos?

Usaria ThreadSanitizer.

### 15. Como aplicaria estas herramientas en proyectos futuros?

Las utilizaria para detectar errores rapidamente y mejorar la calidad y estabilidad de los programas.
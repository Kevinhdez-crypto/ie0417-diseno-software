# Laboratorio de programación concurrente y paralela en C++

## Estudiante
    Nombre: Kevin Hernandez Umana
    Carné: C33773
## Descripción
    Este laboratorio explora conceptos básicos de programación concurrente y paralela usando C++.

## Requisitos
    - g++
    - C++17 o superior
    - Sistema operativo Linux, macOS o Windows con soporte para compilación C++

## Compilación y ejecución

### Parte 1
    Una vez creado el codigo se procede a compilar el archivo.
    Comando para compilar el archivo: g++ -std=c++17 -Wall -Wextra -pthread src/parte1_threads.cpp -o parte1

    Comando para ejecutarlo: ./parte1 
    Todo eso en ese mismo orden y en la terminal ejecutar el programa con "./parte1" 5 veces.

### Parte 2
    Una vez realizado el codigo base, se procede a compilar.
    Comando para compilar el programa es: g++ -std=c++17 -Wall -Wextra -pthread src/parte2_race_condition.cpp -o parte2

    Ahora para ejecutar el programa, en la terminal se escribe: ./parte2 5 veces para comparar valores.

### Parte 3
    Una vez realizado el codigo base, se procede a compilar.
    Comando para compilar el programa es: g++ -std=c++17 -Wall -Wextra -pthread src/parte3_mutex.cpp -o parte3

    Ahora para ejecutar el programa, en la terminal se escribe: ./parte3 5 veces para comparar valores.

### Parte 4
    Una vez realizado el codigo base, se procede a compilar.
    Comando para compilar el programa es: g++ -std=c++17 -O2 -Wall -Wextra -pthread src/parte4_benchmark.cpp -o parte4

    Utilizando el -O2, muy importante, para que el compilador aplique optimizaciones razonables.

    Ahora para ejecutar el programa, en la terminal se escribe: ./parte4 3 veces para llenar la tabla solicitada.

### Parte 5
    Una vez realizado el codigo base, se procede a compilar.
    Comando para compilar el programa es: g++ -std=c++17 -O2 -Wall -Wextra -pthread src/parte5_hilos_vs_rendimiento.cpp -o parte5

    Ahora para ejecutar el programa, en la terminal se escribe: ./parte5 en este caso solo se hace 1 vez.

    Luego utilice el comando nproc para ver la cantidad de nucleos que tenia en la computadora, que eran de 4 nucleos.

### Parte 6

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
    Una vez creado el codigo se procede a compilar el archivo: 
    comando para compilar el archivo: g++ -std=c++17 -Wall -Wextra -pthread src/parte1_threads.cpp -o parte1

    Comando para ejecutarlo: ./parte1

    1.​ ¿Los mensajes aparecen siempre en el mismo orden?
        No, luego de ejecutarlo 5 veces, los mensajes salen en diferente orden. 


    2.​ ¿Por qué podría cambiar el orden de impresión?
        Porque los hilos se ejecutan concurrentemente y el sistema operativo decide cuál hilo corre primero.

    3.​ ¿Qué función cumple join()?
        Hace que el hilo principal espere a que cada hilo termine antes de continuar.


    4.​ ¿Qué podría pasar si no se llama a join()?
        Los hilos podrían terminar abruptamente al cerrar el programa, provocando errores o pérdida de datos.

### Parte 2
    
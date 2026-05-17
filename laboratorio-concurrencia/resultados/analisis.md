### Parte 1
    1.​ ¿Los mensajes aparecen siempre en el mismo orden?
        No, luego de ejecutarlo 5 veces, los mensajes salen en diferente orden. 


    2.​ ¿Por qué podría cambiar el orden de impresión?
        Porque los hilos se ejecutan concurrentemente y el sistema operativo decide cuál hilo corre primero.

    3.​ ¿Qué función cumple join()?
        Hace que el hilo principal espere a que cada hilo termine antes de continuar.


    4.​ ¿Qué podría pasar si no se llama a join()?
        Los hilos podrían terminar abruptamente al cerrar el programa, provocando errores o pérdida de datos.

### Parte 2
    Tabla de valores obtenidos vs esperados:
        Ejecución  Valor esperado  Valor obtenido 
        ---------  --------------  -------------- 
        1          4000000         1680907        
        2          4000000         1181056        
        3          4000000         1800336       
        4          4000000         1971960        
        5          4000000         1745233       


    1.​ ¿El valor obtenido siempre coincide con el valor esperado?
        No, el valor varía y siempre es menor que 4,000,000.

    2.​ ¿Por qué se pierden incrementos?
        Porque varios hilos modifican contador al mismo tiempo y algunos incrementos se sobrescriben.

    3.​ ¿La operación contador++ es realmente una sola operación a nivel de CPU?
        No, implica leer, sumar y escribir, por lo que no es atómica
        
    4.​ ¿Qué problema de concurrencia se está observando?
        Se observa una condición de carrera (race condition), donde hilos concurrentes causan resultados impredecibles.

### Parte 3
    Tabla de valores obtenidos vs esperados con MUTEX:
     Ejecución  Valor esperado  Valor obtenido 
     ---------  ------------  -----------
        1          4000000         4000000        
        2          4000000         4000000        
        3          4000000         4000000        
        4          4000000         4000000        
        5          4000000         4000000        

    *Comparando con la tabla anteriro, la tabla de la parte 2 los resultados obtenidos son diferentes con respecto a los esperados, en cambio esta tabla de la parte 3 (Con Mutex), esta tienen los valores obtenidos iguales a los esperados.

    1.​ ¿Qué cambió con respecto al programa anterior?
        Ahora los incrementos de contador están protegidos por un mutex, evitando que varios hilos modifiquen la variable al mismo tiempo.

    2.​ ¿Qué hace std::mutex?
        Es un mecanismo de exclusión mutua que permite que solo un hilo acceda a la sección crítica (contador) a la vez.

    3.​ ¿Qué hace std::lock_guard?
        Bloquea automáticamente el mutex al entrar en el bloque y lo libera al salir, evitando olvidos de unlock() y asegurando seguridad.

    4.​ ¿Por qué ahora el resultado sí debería ser correcto?
        Porque cada incremento se ejecuta de manera atómica: ningún hilo puede interrumpir otro mientras modifica contador, así que no se pierden incrementos.

    5.​ ¿Qué desventaja podría tener proteger cada incremento individual con un mutex?
        Puede reducir el rendimiento, ya que bloquear y desbloquear el mutex para cada incremento genera sobrecarga, especialmente con millones de operaciones pequeñas.


### Parte 4


### Parte 5


### Parte 6

    
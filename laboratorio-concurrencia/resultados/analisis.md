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


    
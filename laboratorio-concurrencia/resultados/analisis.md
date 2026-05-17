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
    
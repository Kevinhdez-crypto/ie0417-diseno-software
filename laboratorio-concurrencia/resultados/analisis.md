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
    Tabla: 
     Ejecución  Tiempo secuencial (ms)  Tiempo paralelo (ms)  ¿Cuál fue más rápido? 
    ---------  ----------------------  --------------------  --------------------- 
        1          144                     28                    Paralelo              
        2          52                      21                    Paralelo              
        3          57                      21                    Paralelo     

    1.​ ¿El resultado secuencial y el paralelo son iguales?
        Sí, ambos dan 100,000,000, porque suman exactamente los mismos elementos del vector.

    2.​ ¿La versión paralela siempre fue más rápida?
        Sí, en tus ejecuciones el tiempo paralelo fue menor (28 ms y 21 ms) que el secuencial (144 ms, 52 ms, 57 ms), mostrando que dividir el trabajo entre hilos mejora la velocidad para vectores grandes.

    3.​ ¿Por qué dividir el vector en bloques permite paralelizar el trabajo?
        Porque cada hilo procesa su bloque de manera independiente y luego se combinan los resultados parciales, evitando que los hilos interfieran entre sí.

    4.​ ¿Qué costos adicionales tiene la versión paralela?
        Pueden tener varios, pero los mas comunes son: Crear y administrar hilos, sincronizar resultados parciales, esperar con join.

    5.​ ¿Qué podría pasar si el vector fuera muy pequeño?  
        La versión paralela podría ser más lenta que la secuencial debido a la sobrecarga de hilos y sincronización.       

### Parte 5
    Tabla solicitada: 
     Cantidad de hilos  Tiempo obtenido (ms) 
     -----------------  -------------------- 
     1                  147                  
     2                  74                   
     4                  33                   
     8                  46                  
     16                 46                   

     Utilice el comando nproc para ver la cantidad de nucleos que tengo y me dice que tengo 4, lo que tiene sentido, ya que si vemos en la tabla el mejor tiempo fue cuando la cantidad de hilos era de 4, porque mi nucleo es de 4.

    1.​ ¿Cuál cantidad de hilos produjo el mejor tiempo?
        EL de 4

    2.​ ¿El tiempo mejoró siempre al aumentar los hilos?
        No del todo desde 1 a 4 hilos se ve que hay mejora, pero despues de 4 a 8 y de 8 a 16 el tiempo empeora.

    3.​ ¿Cuántos núcleos tiene la computadora donde se ejecutó el programa?
        4 nucleos

    4.​ ¿Qué ocurre cuando se usan más hilos que núcleos disponibles?
        El CPU tiene que hacer context switching, cambiando entre hilos y gastando tiempo en gestión en lugar de computación.

    5.​ ¿Qué relación tiene esto con el context switching?
        Más hilos que núcleos implica que el CPU interrumpe y reanuda hilos constantemente, aumentando la sobrecarga y disminuyendo eficiencia.

    6.​ ¿Por qué la versión con 16 hilos podría no ser la mejor?
        Porque hay demasiados hilos para pocos núcleos, lo que genera más overhead que beneficio, sin mejorar la velocidad de suma.


### Parte 6
    1.​ ¿El programa termina normalmente?
        No, este se queda bloqueado y necesito usar Control C para pararlo.

    2.​ ¿Qué recurso tomó primero el hilo A?
        Hilo A toma el recurso 1.

    3.​ ¿Qué recurso tomó primero el hilo B?
        El hilo B toma el resurso 2 primero.

    4.​ ¿Por qué ninguno de los dos hilos puede continuar?
        Porque cada hilo tiene un recurso y espera a que el otro hilo libere el que necesita. Esto genera un deadlock.

    5.​ ¿Qué significa espera circular?
        Significa que los hilos se están esperando mutuamente en un ciclo: A espera a B y B espera a A, formando un bucle que nunca se rompe.

    6.​ ¿Cómo se podría evitar este problema?
        Se podria evitar tomando los recursos en el mismo orden en todos los hilos, usando std::lock para bloquear varios mutex a la vez sin riesgo de deadlock, evitando mantener un mutex mientras se espera otro recurso.

    7. Explique por qué std::scoped_lock ayuda a evitar este deadlock.
        std::scoped_lock permite bloquear varios mutex al mismo tiempo de manera atómica, esto asegura que ningún hilo puede tomar un mutex si no puede tomar todos al mismo tiempo, evitando la espera en bucle.
        Ademas al liberar automáticamente los mutex al salir del bloque, no hay riesgo de dejar recursos bloqueados.

    
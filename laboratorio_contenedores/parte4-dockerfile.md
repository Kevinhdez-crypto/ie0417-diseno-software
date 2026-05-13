## Qué hace la aplicación.
    La aplicación muestra un mensaje en la página principal (/) y devuelve información del laboratorio en /info.

## Qué rutas tiene.
    Tiene dos rutas: / que muestra un mensaje HTML y /info que devuelve un JSON con información de la aplicación y el laboratorio.

## Qué dependencia utiliza.
    Usa Flask, un framework de Python para crear aplicaciones web.

## Por qué se usa host="0.0.0.0" en lugar de localhost.
    Para que la aplicación escuche en todas las interfaces de red y sea accesible desde fuera del contenedor y no solo adentro.

## ¿Qué hace Flask en esta aplicación?
    Flask permite manejar las rutas web y responder con contenido HTML o JSON según la ruta que se utilice.

## ¿Para qué sirve el archivo requirements.txt?
    Para listar todas las librerías que necesita la aplicación y poder instalarlas fácilmente con pip.
    "En mi caso no pude utilizar pip porque la verison que descargue en mi MV no dejaba"
    Pero use el comando " python3 -m pip install --break-system-packages -r requirements.txt"


## ¿Por qué una aplicación dentro de un contenedor debe escuchar en 0.0.0.0?
    Porque localhost solo funciona dentro del contenedor; 0.0.0.0 permite acceder a la app desde la máquina host.

## ¿Qué diferencia hay entre ejecutar la aplicación localmente y ejecutarla dentro de Docker?
    Localmente usa Python y librerías del sistema pero en Docker corre en un contenedor aislado con sus propias dependencias y hay que mapear puertos para acceder a ella.


# Instrucción del Dockerfile

## FROM
    Basicamente especifica la imagen base del contenedor.

## WORKDIR
    Define el directorio de trabajo dentro del contenedor. Todas las instrucciones posteriores (como COPY o RUN) se ejecutan dentro de esta carpeta, en este caso /app.

## COPY
    Copia archivos desde mi máquina host hacia el contenedor. Primero se copia requirements.txt para instalar dependencias y luego se copia todo el código de la aplicación.

## RUN
    Ejecuta comandos dentro del contenedor, en este caso se usa para instalar las dependencias con pip install -r requirements.txt.

## EXPOSE
    Indica qué puerto escucha la aplicación dentro del contenedor. En este caso, Flask usa el puerto 5000.

## CMD
    Define el comando que se ejecuta cuando el contenedor inicia. Aquí se arranca la aplicación Flask con python app.py.

## Qué significa construir una imagen.
    Construir una imagen es crear un archivo que contiene todo lo necesario para ejecutar una aplicación, como la base del sistema, ependencias, código y configuraciones.

## Qué significa el nombre laboratorio-flask:1.0.
    Es el nombre de la imagen y 1.0 es su versión o tag. Esto permite identificar y usar esa versión especifica de la imagen.

## Qué diferencia hay entre el nombre de la imagen y el nombre del contenedor.
    La imagen es como una plantilla que se puede usar muchas veces, mientras que el contenedor es una instancia en ejecución de esa imagen, que puede tener su propio nombre, estado y datos.

## Resultado de docker images.
        IMAGE                   ID             DISK USAGE   CONTENT SIZE   EXTRA
    hello-world:latest      f9078146db2e       25.9kB         9.49kB    U   
    laboratorio-flask:1.0   f3cffe00932b        210MB         51.1MB        
    python:3.11-slim        a5b427ace490        188MB         47.7MB        
    ubuntu:latest           f3d28607ddd7        160MB         45.3MB    U   


# Reflexion
## ¿Qué es una imagen base?
    Es la imagen de partida que ya incluye un sistema operativo y software preinstalado, sobre la cual se construye el contenedor que yo quiera.

## ¿Por qué se usa una imagen slim?
    Basicamente porque es más ligera, incluye solo lo necesario, reduce el tamaño de la imagen y acelera la construcción.

## ¿Por qué se copian primero las dependencias y luego el resto del código?
    Para aprovechar la cache de Docker. Si no cambian las dependencias, Docker no tiene que reinstalarlas cada vez que cambias tu código, haciendo la construcción más rápida.

## ¿Qué diferencia hay entre RUN y CMD?
    RUN se ejecuta durante la construcción de la imagen y genera capas nuevas, mientras que CMD se ejecuta al iniciar un contenedor desde la imagen.

## ¿Qué pasaría si se elimina la imagen pero no el Dockerfile?
    No pasa nada de otro mundo, se puede reconstruir la imagen en cualquier momento usando el Dockerfile, porque el archivo contiene todas las instrucciones necesarias para crear la imagen desde cero.
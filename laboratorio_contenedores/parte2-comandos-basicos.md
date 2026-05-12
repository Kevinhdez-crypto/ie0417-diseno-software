## 1_Comando ejecutado
    docker run hello-world
## 1_salida Parcial
    Unable to find image 'hello-world:latest' locally
    latest: Pulling from library/hello-world
    4f55086f7dd0: Pull complete 
    d5e71e642bf5: Download complete 
    Digest: sha256:f9078146db2e05e794366b1bfe584a14ea6317f44027d10ef7dad65279026885
    Status: Downloaded newer image for hello-world:latest


## 2_Comando ejecutado
    docker ps
## 2_Salida
    CONTAINER ID   IMAGE     COMMAND   CREATED   STATUS    PORTS     NAMES

## 3_Comando ejecutado
    docker ps -a
## 3_salida
    CONTAINER ID   IMAGE         COMMAND    CREATED         STATUS                     PORTS     NAMES
    38f09e4e54a8   hello-world   "/hello"   2 minutes ago   Exited (0) 2 minutes ago             elated_golick

## ¿Qué hizo el comando docker run hello-world?
    Ejecuta un contenedor con la imagen hello-world. El contenedor imprime un mensaje de prueba para confirmar que Docker está funcionando correctamente.
    En el caso que no se haya instalado antes, Docker la descargó automáticamente desde Docker Hub antes de ejecutar el contenedor.

## Diferencia entre docker ps y docker ps -a
    docker ps muestra solo los contenedores activos en ejecución.
    docker ps -a muestra todos los contenedores, incluyendo los detenidos y pausados.

## ¿Qué es la imagen hello-world?
    Este comando le indicó a Docker que ejecutara un contenedor con la imagen hello-world. El contenedor imprime un mensaje de prueba para confirmar que Docker está funcionando correctamente.


## ¿El contenedor quedó ejecutándose después de imprimir el mensaje?
    No, el contenedor termina automáticamente después de ejecutar su tarea (osea imprimir el mensaje).


## ¿Por qué aparece en docker ps -a pero no necesariamente en docker ps?
    Aparece en docker ps -a porque muestra todos los contenedores, incluidos los detenidos, mientras que docker ps solo muestra los activos.


## ¿Qué demuestra este primer ejemplo sobre Docker?
    Este ejemplo demuestra que Docker puede descargar imágenes, crear contenedores y ejecutarlos correctamente, verificando que la instalación funciona.
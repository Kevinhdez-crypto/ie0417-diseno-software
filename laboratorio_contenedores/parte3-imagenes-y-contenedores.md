## Qué hace docker pull.
    Descarga una imagen de Docker desde un repositorio (como Docker Hub) para poder usarla en los contenedores.

## Qué muestra docker images.
    Muestra una lista con todas las imágenes disponibles en el sistema, mostrando el nombre, etiqueta ID, tamaño y fecha de creación.

## Qué significa ejecutar un contenedor en modo interactivo.
    Permite abrir una sesión dentro del contenedor (por ejemplo, en la erminal) y ejecutar comandos en tiempo real mientras el contenedor está activo.

## Qué observó dentro del contenedor Ubuntu.
    Se mira que se tiene acceso al sistema de archivos de Ubuntu, pudiendo ejecutar comandos típicos de Linux como ls, pwd o instalar programas, todo dentro del contenedor.

## Qué ocurrió al salir del contenedor.
    El contenedor se detuvo automáticamente al cerrar la sesión interactiva, este permanece registrado en docker ps -a cuando se ejecuta en la terminal.

## ¿La imagen Ubuntu es lo mismo que una máquina virtual Ubuntu?
    No, una imagen Docker es solo un paquete con el sistema de archivos y programas de Ubuntu, mientras que una máquina virtual incluye un kernel completo y un sistema operativo independiente.

## ¿Por qué el contenedor puede parecer un sistema Linux si no es una máquina virtual completa?
    Porque contiene todos los archivos y programas necesarios de Ubuntu, pero utiliza el kernel del host en lugar de uno propio, dando la apariencia de un sistema completo.

## ¿Qué significa que el contenedor comparta el kernel con el host?
    Significa que el contenedor no tiene su propio núcleo del sistema operativo; depende del kernel del host para ejecutar procesos, lo que lo hace más liviano que una máquina virtual.

## ¿Qué diferencia hay entre una imagen descargada y un contenedor creado?
    La imagen es solo una plantilla inmutable, mientras que un contenedor es una instancia en ejecución de esa imagen, con su propio estado y procesos.




# Administración de contenedores

## Uso de --name.
    Se le asigna un nombre al contenedor y demas, esto facilita comadnos posteriores como docker stop mi-ubuntu o docker rm mi-ubuntu

## Diferencia entre docker start y docker run.
    docker run crea y ejecuta un nuevo contenedor a partir de una imagen.
    docker start inicia un contenedor ya creado y detenido, sin crear uno nuevo.

## Uso de docker exec.
    Permite ejecutar comandos dentro de un contenedor que ya está en ejecución. Por ejemplo, docker exec -it mi-ubuntu bash abre una terminal interactiva dentro del contenedor.

## Diferencia entre detener y eliminar un contenedor.
    Detener (docker stop) pausa la ejecución del contenedor, pero conserva su estado y archivos.
    Eliminar (docker rm) borra completamente el contenedor del sistema, liberando espacio y eliminando todos los cambios que se hayan hecho dentro de él.

## Qué pasó con el archivo creado dentro del contenedor.
    Cuando se utiliza el comando docker rm, todo lo que se haya creado dentro de ese contenedor se pirde, por ende el mensaje que se habia creado anteriormente se pierde. 

# Reflexion
## ¿Qué ventaja tiene asignar nombres a los contenedores?
    Permite identificar y referirse fácilmente a un contenedor, con esto es mas facil usar los comandos como: docker stop nombre-contenedor o docker exec -it nombre-contenedor bash

## ¿Qué diferencia hay entre crear un contenedor nuevo y reiniciar uno existente?
    Crear un contenedor nuevo (docker run) genera una instancia fresca de la imagen, mientras que reiniciar uno existente (docker start) vuelve a poner en ejecución un contenedor que ya había sido detenido, conservando su estado que tenia antes.

## ¿Qué sucede con los datos creados dentro de un contenedor si este se elimina?
    Todo se pierde si se elimina el contenedor por completo. 

## ¿Por qué se dice que los contenedores son desechables?
    Porque pueden crearse y eliminarse rápidamente sin afectar al host.
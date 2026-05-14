## Qué recursos quedaron creados.
    Usualmente redes, imágenes no usadas y volúmenes que no se eliminaron automáticamente.

## Qué comandos de limpieza ejecutó.
    docker container prune 
    docker image prune 
    docker volume prune

## Qué diferencia hay entre limpiar contenedores, imágenes y volúmenes.
     Si se eliminan contenedores, entonces se borran instancias de ejecución de apps, en las imagenes se eliminan los archivos que generan contenedores, y en cuanto a los volumenes se eliminan datos persistentes almacenados.

## Resultado de docker system df.
    TYPE            TOTAL     ACTIVE    SIZE      RECLAIMABLE
    Images          6         0         583.3MB   35.83MB (6%)
    Containers      0         0         0B        0B
    Local Volumes   1         0         33B       33B (100%)
    Build Cache     0         0         0B        0B



# Preguntas de Reflexion

## ¿Por qué Docker puede consumir mucho espacio en disco?
    Porque guarda contenedores, imagenes y volumenes, incluso si ya no se usan.

## ¿Qué diferencia hay entre eliminar un contenedor y eliminar una imagen?
    Basicamente que el contenedor elimina la instancia en ejecución, no la imagen base, pero en cuanto a la imagen, se elimina los archivos que permiten crear contenedores, afectando futuros contenedores

## ¿Por qué se debe tener cuidado al eliminar volúmenes?
    Porque almacenan datos, y borrarlos significa perder información para siempre.

## ¿Qué buenas prácticas aplicaría para mantener limpio su ambiente local?
    Yo usaria "docker system prune" regularmente, eliminaria contenedores y volumenes no usados y limitaria las imágenes antiguas con "docker image prune".
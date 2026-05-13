## Qué es un volumen.
    Un volumen es un espacio de almacenamiento persistente en Docker que se usa para guardar datos fuera del contenedor, de forma que no se pierdan al eliminarlo.

## Cómo se crea.
    Se crea automáticamente cuando se usa por primera vez en un contenedor con la opción -v.

## Cómo se monta en un contenedor.
    Se monta usando la opción -v nombre_volumen:ruta_dentro_del_contenedor

## Qué pasó con el archivo después de eliminar el primer contenedor.
    El archivo no se perdió, porque estaba guardado en el volumen, que es independiente del contenedor. Al crear otro contenedor con el mismo volumen, el archivo seguía disponible.

## Resultado de docker volume inspect.
    [
    {
        "CreatedAt": "2026-05-12T23:14:25-06:00",
        "Driver": "local",
        "Labels": null,
        "Mountpoint": "/var/lib/docker/volumes/datos-lab/_data",
        "Name": "datos-lab",
        "Options": null,
        "Scope": "local"
    }
]



# Preguntas de Reflexion

## ¿Qué problema resuelven los volúmenes?
    Resuelven la pérdida de datos cuando un contenedor se elimina, ya que permiten almacenar información.

## ¿El volumen pertenece a un contenedor específico?
    No, el volumen es independiente y puede ser usado por uno o varios contenedores.

## ¿Qué diferencia hay entre eliminar un contenedor y eliminar un volumen?
    Eliminar un contenedor borra su entorno, pero el volumen mantiene los datos. En cambio, eliminar el volumen sí borra los datos almacenados.

## ¿Para qué casos reales se usarían volúmenes?
    Se usan para bases de datos, almacenamiento de archivos, logs, backups o cualquier información que deba mantenerse aunque el contenedor se elimine.



# Bind mounts

## Qué diferencia hay entre datos-lab:/datos y "$(pwd)":/app.
    datos-lab:/datos es un volumen administrado por Docker, donde los datos se guardan en una ubicación interna del sistema de Docker y no dependen del sistema de archivos del host. En cambio, "$(pwd)":/app es un bind mount, que conecta directamente una carpeta del host con el contenedor, en este caso la carpeta actual del proyecto con /app dentro del contenedor.

## Qué ocurrió al modificar el código local.s
    Al modificar app.py en la máquina host, los cambios se reflejaron automáticamente dentro del contenedor, ya que la carpeta del host está sincronizada con la del contenedor mediante el bind mount.

## Por qué esto puede ser útil durante el desarrollo.
    Porque permite desarrollar y probar cambios en tiempo real sin necesidad de reconstruir la imagen cada vez, haciendo el proceso más eficiente.


# Preguntas de Reflexion

## ¿Qué diferencia hay entre un volumen y un bind mount?
    Un volumen es gestionado por Docker y almacena datos de forma aislada del sistema del host, mientras que un bind mount conecta directamente una carpeta del host con el contenedor.

## ¿Cuál parece más conveniente para desarrollo?
    El bind mount, porque permite ver cambios en tiempo real sin reconstruir la imagen.

## ¿Cuál parece más conveniente para datos persistentes de una aplicación?
    El volumen, porque es más seguro, gestionado por Docker y menos dependiente del sistema del host.

## ¿Qué riesgos podría tener montar carpetas del host dentro del contenedor?
    Puede haber riesgos de seguridad o de corrupción de datos si el contenedor modifica archivos importantes del host, además de posibles errores si se rompen permisos o rutas críticas.


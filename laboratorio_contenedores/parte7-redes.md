## Qué es una red en Docker.
    Permite que contenedores se comuniquen entre sí y se aíslen de otros contenedores o del host.

## Qué hace docker network create.
    Crea una nueva red de Docker para conectar contenedores.

## Qué significa conectar contenedores a la misma red.
    Que pueden comunicarse entre ellos usando nombres o IP internas.

## Qué ocurrió al ejecutar curl http://servidor-web.
    El contenedor cliente pidió la página de Nginx del contenedor servidor-web dentro de la misma red.

## Por qué se pudo usar el nombre servidor-web.
    Docker resuelve automáticamente los nombres de contenedor dentro de la misma red.

# Preguntas de Reflexion

## ¿Por qué los contenedores necesitan redes?
    Para comunicarse y aislarse de otros contenedores o del host.

## ¿Qué ventaja tiene usar nombres de contenedor en lugar de direcciones IP?
    Los nombres no cambian, mientras que las IPs sí.

## ¿Qué diferencia hay entre publicar un puerto hacia el host y comunicarse dentro de una red Docker?
    Publicar un puerto es accesible desde fuera del host, mientras la comunicacaion interna solo contenedores de la misma red pueden acceder, y lo hace mas seguro.

## ¿Qué ejemplos reales podrían usar una red Docker?
    Algunas aplicaciones web con backend y base de datos, microservicios, entornos de testing, etc.


# Comunicación entre servicios

## Qué es Redis en este ejemplo.
    Es un servidor de base de datos en memoria que almacena y recupera datos.

## Qué representa redis-lab.
    Es el contenedor que ejecuta el servidor Redis.

## Cómo se conectó el cliente al servidor.
    Usando redis-cli -h redis-lab dentro de la misma red Docker.

## Qué significa recibir PONG.
    Es tipo que el servidor Redis respondió correctamente, confirmando que está activo y conectado.

## Qué enseñanza deja este ejemplo sobre aplicaciones con varios contenedores.
    Los contenedores pueden comunicarse fácilmente si están en la misma red; los servicios pueden separarse y probarse de forma aislada.

# Reflexion 

## ¿Por qué una aplicación web podría necesitar comunicarse con una base de datos?
    Para almacenar y recuperar datos de usuarios, sesiones, configuraciones o información de la aplicación.

## ¿Por qué ambos contenedores deben estar en la misma red?
    Para que puedan comunicarse entre sí sin exponer puertos al host ni a internet.

## ¿Qué ventaja tiene separar servicios en contenedores distintos?
    Facilita el mantenimiento, actualización y escalabilidad de cada servicio por separado.

## ¿Qué limitación tiene hacerlo manualmente con varios comandos docker run?
    Puede llegar a ser un poco tedioso y propenso a errores, es difícil de mantener y escalar cuando hay muchos contenedores.
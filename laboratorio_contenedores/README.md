# Laboratorio 2 - Contenedores
    Kevin Hernandez Umaña. C33773.

# indice: 

## Parte 1 - Verificación de instalación de Docker
## Parte 2 - Primer contenedor y comandos básicos
## Parte 3 - Imágenes, contenedores y administración básica
## Parte 4 - Aplicación Flask y Dockerfile
## Parte 5 - Publicación de puertos, logs y variables de entorno
## Parte 6 - Volúmenes y bind mounts
## Parte 7 - Redes Docker y comunicación entre servicios
## Parte 8 - Limpieza del ambiente Docker

# Reflexion final

## 1.​ ¿Qué es un contenedor?
    Es una instancia que puede ejecutar una aplicación de manera aislada, con todo lo necesario para funcionar (ya sea código, librerías, dependencias), sin afectar al resto del sistema.

## 2.​ ¿Qué problema resuelve Docker?
    Evita que aplicaciones tengan conflictos de dependencias entre sí o con el sistema operativo, y permite que funcionen igual en cualquier entorno.

## 3.​ ¿Qué diferencia hay entre una imagen y un contenedor?
    La imagen tiene una plantilla inmutable que define cómo será un contenedor, mientras que un contenedor es una instancia en ejecución de esa imagen.

## 4.​ ¿Qué diferencia hay entre un contenedor y una máquina virtual?
    El contenedor comparte el mismo sistema operativo del host, es más ligero y rápido, mientras que la maquina virtual tiene su propio sistema operativo completo, más pesado y lento de arrancar.

## 5.​ ¿Qué aprendió sobre puertos?
    Aprendi que los puertos permiten que los contenedores se comuniquen con otros contenedores, como un canal de entrada y salida de datos.

## 6.​ ¿Qué aprendió sobre volúmenes?
    Que los volumenes permiten almacenar datos fuera del contenedor, de manera que no se pierdan al detener o eliminar el contenedor.

## 7.​ ¿Qué aprendió sobre redes?
    Que las redes permiten que los contenedores se conecten entre sí y con otros servicios, controlando cómo se comunican dentro y fuera del host.

## 8.​ ¿En qué casos usaría Docker en un proyecto de software?
    Para facilitar desarrollo, pruebas y despliegue, asegurando que la aplicación funcione igual en distintos entornos y máquinas.

## 9.​ ¿Qué parte del laboratorio le pareció más útil?
    Aprender a crear, ejecutar y administrar contenedores, ya que muestra cómo funciona Docker en la vida real.

## 10.​ ¿Qué parte le pareció más confusa?
    Siento que en la parte del archivo parte4, ya que no me servia el pip, de hecho tuve que investigar y el comando que me srivio fue el " python3 -m pip install --break-system-packages -r requirements.txt"



## Qué significa -p 5000:5000.
    Mapea el puerto 5000 del host al puerto 5000 del contenedor.

## Qué significa -p 8080:5000.
    Mapea el puerto 8080 del host al puerto 5000 del contenedor.
    Permite acceder a la misma aplicación usando otro puerto en la máquina local.

## Cuál puerto pertenece al host.
    El primer número del mapeo (5000 o 8080) es el puerto del host, osea es el que uso en el navegador.

## Cuál puerto pertenece al contenedor.
    El segundo número (5000) es el puerto dentro del contenedor.

## Captura del navegador mostrando la aplicación funcionando.
<img width="589" height="276" alt="parte5 lab2" src="https://github.com/user-attachments/assets/31fb0f94-9be4-4762-ad92-11a5e5e7cc01" />



## ¿Por qué no basta con que la aplicación escuche en el puerto 5000 dentro del contenedor?
    Porque el contenedor está aislado y ese puerto no se puede ver desde fuera sin publicarlo.

## ¿Qué función cumple el mapeo de puertos?
    Permite acceder desde el host a la aplicación que corre dentro del contenedor.

## ¿Cuál es la diferencia entre el puerto del host y el puerto del contenedor?
    El host es el puerto externo que usas en el navegador y el contenedor es el puerto interno de la app.

## ¿Qué pasaría si dos contenedores intentan usar el mismo puerto del host?
    El segundo no podría iniciarse porque el puerto ya estaría en uso.


# Logs e inspección

## Qué muestra docker logs.
    Muestra los registros que genera el contenedor, como mensajes de la aplicación, errores o salidas normales desde que se inició.

## Para qué sirve docker logs -f.
    Sirve para ver los logs en tiempo real mientras la aplicación está corriendo, osea se van mostrando a medida que ocurren nuevos eventos.

## Qué tipo de información muestra docker inspect.
    Muestra información detallada del contenedor, como la configuración, red, puertos, estado, variables de entorno y rutas internas.

## Qué información muestra docker stats.
    Muestra el uso de recursos en tiempo real del contenedor, como CPU, memoria, red y almacenamiento.

## Preguntas de reflexión

## ¿Por qué los logs son importantes al trabajar con contenedores?
    Porque permiten ver qué está haciendo la aplicación dentro del contenedor y ayudan a detectar errores o fallos.

## ¿Qué diferencia hay entre ver logs históricos y logs en tiempo real?
    Los logs históricos muestran lo que ya ocurrió, mientras que los logs en tiempo real muestran lo que está pasando en ese momento.

## ¿Qué información útil se puede obtener con docker inspect?
    Se puede ver la configuración completa del contenedor, su red, puertos, variables de entorno y estado general.

## ¿Por qué es importante observar el consumo de recursos?
    Porque ayuda a detectar si el contenedor está consumiendo demasiada memoria o CPU y así evitar problemas de rendimiento.



# Variables de entorno

## Qué hace la opción -e.
    Basicamente se usa para definir variables de entorno dentro del contenedor.

## Qué cambió en la aplicación.
    Cambió el mensaje mostrado por la aplicación según el valor de la variable MENSAJE. Al ejecutar el contenedor con distintos valores, la app muestra diferentes mensajes sin modificar el código.

## Por qué no fue necesario reconstruir la imagen.
    Porque las variables de entorno se aplican en tiempo de ejecución, así que no es necesario cambiar ni reconstruir la imagen para modificar el comportamiento de la aplicación.

## Capturas o salidas de ambas ejecuciones.
    Al abrir http://localhost:5000, se observa el mensaje definido en cada ejecución del contenedor.


# Preguntas de reflexion 

## ¿Por qué es útil configurar aplicaciones mediante variables de entorno?
    Porque permite cambiar la configuración de la aplicación sin modificar el código, haciendo el sistema más flexible.

## ¿Qué tipo de información podría configurarse así?
    Se pueden configurar mensajes, credenciales, claves API, URLs de bases de datos y otros parámetros de configuración.

## ¿Por qué no es buena práctica guardar contraseñas directamente dentro del código?
    Porque es inseguro, difícil de mantener y expone información sensible si el código se comparte o sube a repositorios.

## ¿Qué ventaja tiene usar la misma imagen con diferentes configuraciones?
    Permite reutilizar la misma imagen en distintos entornos solo cambiando variables, sin necesidad de crear nuevas imágenes.

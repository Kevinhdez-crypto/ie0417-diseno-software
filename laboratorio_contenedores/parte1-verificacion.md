## 1_Comando ejecutado
    docker --version
## 1_salida (Version instalada)
    Docker version 29.1.3, build 29.1.3-0ubuntu3~24.04.2 

## Sistema operativo instalado
    Ubuntu 24.04.2 LTS

## 2_Comando ejecutado
    docker info
## 2_salida
            Client:
            Version:    29.1.3
            Context:    default
            Debug Mode: false
            Plugins:
            trust: Manage trust on Docker images (Docker Inc.)
                Version:  29.1.3
                Path:     /usr/libexec/docker/cli-plugins/docker-trust

            Server:
            Containers: 0
            Running: 0
            Paused: 0
            Stopped: 0
            Images: 0
            Server Version: 29.1.3
            Storage Driver: overlayfs
            driver-type: io.containerd.snapshotter.v1
            Logging Driver: json-file
            Cgroup Driver: systemd
            Cgroup Version: 2
            Plugins:
            Volume: local
            Network: bridge host ipvlan macvlan null overlay
            Log: awslogs fluentd gcplogs gelf journald json-file local splunk syslog
            CDI spec directories:
            /etc/cdi
            /var/run/cdi
            Swarm: inactive
            Runtimes: io.containerd.runc.v2 runc
            Default Runtime: runc
            Init Binary: docker-init
            containerd version: 
            runc version: 
            init version: 
            Security Options:
            apparmor
            seccomp
            Profile: builtin
            cgroupns
            Kernel Version: 6.11.0-26-generic
            Operating System: Ubuntu 24.04.2 LTS
            OSType: linux
            Architecture: x86_64
            CPUs: 4
            Total Memory: 4.754GiB
            Name: kevin-hernandez-VirtualBox

## 3_Comando ejecutado
    docker help

## 3_salida
    Basicamnete muestra los comandos que puedes utilizar para hacer uso de docker, como crear imagenes y demas. Una muestra de lo que sale en la terminal es: 

    run         Create and run a new container from an image
    exec        Execute a command in a running container
    ps          List containers
    build       Build an image from a Dockerfile
    pull        Download an image from a registry
    push        Upload an image to a registry
    images      List images


## Explicacion breve sobre lo que muestra docker info
    Basicamente muestra tola la informacion del docker una vez que este se haya instalada, muestre mi usuario, el sistema operativo, contenedores activos, imágenes disponibles, configuraciones de almacenamiento y logging, información de la CPU de la memoria, y detalles del sistema operativo.

## ¿Por que es importante verificar la instalacion antes de continuar?
    Es de suma importancia debido a que ayuda a evitar errores inesperados a la hora de crear imagenes por ejmplo y demas. 

## ¿Qué diferencia hay entre instalar Docker y tener Docker ejecutándose correctamente?
    Instalar Docker significa que los archivos y comandos están disponibles en el sistema, mientras que tenerlo ejecutándose correctamente implica que el daemon de Docker está activo en segundo plano y puede crear y gestionar contenedores.

## ¿Qué información útil muestra el comando docker info?
    uestra el estado de Docker, incluyendo contenedores, imágenes, versión del servidor, drivers de almacenamiento y logging, recursos del sistema y configuración del daemon, lo que permite verificar que todo funciona correctamente.

## ¿Por qué Docker necesita un servicio o daemon ejecutándose en segundo plano?
    Docker requiere un daemon en ejecución porque es quien realmente administra y ejecuta los contenedores, ya que, el cliente solo envía comandos, y sin el daemon los comandos no pueden ejecutarse de una manera correcta.
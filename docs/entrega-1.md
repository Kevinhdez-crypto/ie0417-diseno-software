<p align="center">
  <strong style="font-size: 1.8em;">Auditoría Técnica EIEInfo</strong><br>
  <em style="font-size: 1.1em;">Levantamiento del sistema y diagnóstico inicial</em>
</p>

<p align="center">
  <br>
  <strong>Entrega 1</strong><br>
  <strong>9 de junio de 2026</strong><br>
  <br>
  <strong>Universidad de Costa Rica (UCR)</strong><br>
  <strong>Escuela de Ingeniería Eléctrica</strong><br>
  <strong>Taller de Auditoría Técnica de Software</strong>
</p>

<p align="center">
  <br>
  <strong>Estudiante:</strong> Kevin Hernández Umaña C33773<br>
  <strong>Carrera / Curso:</strong> Ingeniería Eléctrica / Diseño de Software para Ingeniería (IE 0417)<br>
  <strong>Profesor:</strong> Rafael Esteban Badilla Alvarado<br>
</p>

---

## 1. Objetivo

Construir una comprensión técnica sólida del sistema EIEInfo y elaborar un diagnóstico inicial de su arquitectura, organización y riesgos visibles.

## 2. Pregunta central

**¿Qué sistema tenemos enfrente y cuáles son sus principales rasgos de diseño?**

## 3. Resumen de la entrega

Este documento plantea un levantamiento arquitectónico del sistema EIEInfo, e incluye:

- ficha técnica del sistema,
- mapa general del sistema,
- inventario funcional,
- hallazgos iniciales,
- matriz preliminar de riesgos.

## 4. Ficha técnica del sistema

### Stack tecnológico principal

- Python 3.x
- Django 4.1.3
- Gunicorn
- Nginx
- Docker / docker-compose
- MariaDB / MySQL

### Framework y dependencias relevantes

- Django
- django-extensions
- django-ckeditor
- django-crontab
- martor
- sorl-thumbnail
- django-wiki
- django-instagram
- django-select2
- mysqlclient
- requests
- google-api-python-client
- facebook-sdk

### Tipo de base de datos esperada

- MySQL / MariaDB (servicio `db` en `docker-compose.yml`).

### Estrategia de despliegue observable

- `docker-compose.yml` con servicios `db`, `eieinfo_app` y `nginx`.
- Contenedor `db` para la base de datos MariaDB.
- Contenedor `eieinfo_app` para Django + Gunicorn.
- Contenedor `nginx` como proxy inverso y servidor de archivos estáticos.
- Volúmenes compartidos para `static`, `media` y datos de la base de datos.

### Integraciones externas visibles

- SMTP: `smtp.eie.ucr.ac.cr`
- Google API
- Facebook API
- Imgur / Martor
- ReCaptcha
- Servicio de firma digital local

### Tipo de arquitectura predominante

- Arquitectura monolítica modularizada en Django.
- Un solo proyecto Django con múltiples apps especializadas.

## 5. Mapa general del sistema

### Módulos o aplicaciones principales

- `profesores`
- `estudiantes`
- `cursos`
- `eventos`
- `anuncios`
- `webpage`
- `wiki`
- `firma_digital`
- `inventario`
- `postulaciones`
- `trabajos_finales`
- `proyectos`
- `alumni`
- `administrativos`
- `laboratorios`
- `atributos`

### Puntos de entrada importantes

- `src/server/manage.py`
- `src/server/eieinfo/wsgi.py`
- `src/server/eieinfo/urls.py`
- `src/server/eieinfo/settings.py`
- `docker-compose.yml`

### Relación entre portales, dominios y componentes

- Dominio de producción objetivo: `info.eie.ucr.ac.cr`, `eie.ucr.ac.cr`, `www.eie.ucr.ac.cr`.
- `nginx` es la puerta de entrada HTTP.
- `eieinfo_app` gestiona la lógica del sistema.
- `db` almacena datos.
- Archivos estáticos y multimedia se sirven desde volúmenes Docker.
- El sistema integra servicios externos para correo, autenticación y APIs.

### Visión general de backend, infraestructura y despliegue

- Backend centralizado en Django.
- Infraestructura basada en contenedores: app, base de datos y proxy.
- Despliegue gestionado con Docker Compose.

### Diagrama de contexto

```text
[Usuario] --> [Nginx] --> [Django/Gunicorn] --> [MariaDB]
                     |--> [SMTP]
                     |--> [Google API]
                     |--> [Facebook API]
                     |--> [ReCaptcha]
                     |--> [Firma digital local]
```

### Diagrama de módulos / contenedores

```text
+----------+      +----------------+      +---------+
|  Nginx   | ---> | Django app     | ---> | MariaDB |
| (proxy)  |      | (eieinfo_app)  |      | (db)    |
+----------+      +----------------+      +---------+
      |               |
      |               +--> [Static / Media Volumes]
      +--> [Servicios externos]
```

## 6. Inventario funcional

### Tipos de usuarios o actores

- Estudiantes
- Profesores
- Administrativos
- Alumni
- Administradores del sistema
- Usuarios anónimos / público

### Áreas funcionales principales

- Gestión académica
- Comunicación y eventos
- Contenidos y documentación
- Firma digital y documentos
- Postulaciones y procesos académicos
- Inventario y administración interna

### Flujos visibles más importantes

- Autenticación y acceso de usuarios
- Gestión de cursos y profesores
- Publicación de anuncios y eventos
- Carga y firma de documentos
- Generación de contenido web/wiki
- Envío de notificaciones y correos

### Módulos críticos para la operación del sistema

- `profesores`
- `estudiantes`
- `cursos`
- `administrativos`
- `firma_digital`
- `webpage`
- `anuncios`

## 7. Hallazgos iniciales

### 1. Monolito Django con muchas apps
- Descripción: El sistema está construido como un único proyecto Django con diversas apps internas.
- Evidencia: `src/server/eieinfo/settings.py` lista muchas apps como `profesores`, `estudiantes`, `webpage`, `firma_digital`, etc.
- Impacto: centraliza el despliegue pero puede aumentar el acoplamiento y dificultar la evolución.
- Criticidad: Media-Alta

### 2. Deuda técnica por versiones de Django
- Descripción: Hay referencias legacy a Django 1.9.1 mientras el archivo de requisitos usa Django 4.1.3.
- Evidencia: Comentario en `src/server/eieinfo/settings.py` y `requirements.txt`.
- Impacto: riesgo de incompatibilidades y errores en actualizaciones.
- Criticidad: Alta

### 3. Configuración sensible en código
- Descripción: Se manejan credenciales y parámetros sensibles en los settings y se importan secretos.
- Evidencia: `src/server/eieinfo/settings.py` importa `eieinfo.secret.secret_credentials` y define `EMAIL_HOST_PASSWORD`.
- Impacto: vulnerabilidad de seguridad si el repositorio se comparte.
- Criticidad: Alta

### 4. Despliegue Docker definido
- Descripción: El sistema utiliza Docker Compose para app, DB y proxy.
- Evidencia: `docker-compose.yml` con servicios `db`, `eieinfo_app` y `nginx`.
- Impacto: facilita el despliegue, aunque añade complejidad de orquestación.
- Criticidad: Media

### 5. Dependencias externas múltiples
- Descripción: Existen integraciones con APIs externas y servicios de terceros.
- Evidencia: `requirements.txt` incluye `google-api-python-client`, `facebook-sdk`, `imgur`, `django-recaptcha`.
- Impacto: aumenta la superficie de mantenimiento y dependencia.
- Criticidad: Media

### 6. Gestión de archivos estáticos y media
- Descripción: Usa volúmenes Docker para static y media en `/var/info`.
- Evidencia: `settings.py` define `STATIC_ROOT` y `MEDIA_ROOT`; `docker-compose.yml` monta volúmenes.
- Impacto: buen manejo de persistencia, pero sensible a permisos y sincronización.
- Criticidad: Media

### 7. Tareas automáticas programadas
- Descripción: El proyecto configura cron jobs para envíos y notificaciones.
- Evidencia: `CRONJOBS` en `src/server/eieinfo/settings.py`.
- Impacto: importante para la operación, pero requiere monitoreo.
- Criticidad: Media

### 8. Configuración de entornos distintos
- Descripción: `settings.py` cambia comportamiento según si el host es `faraday`.
- Evidencia: condiciones en `settings.py` que ajustan `DEBUG`, `ALLOWED_HOSTS` y rutas.
- Impacto: puede causar diferencias entre desarrollo y producción.
- Criticidad: Media

## 8. Matriz preliminar de riesgos

| Riesgo identificado | Posible causa | Impacto | Probabilidad | Prioridad |
|---|---|---|---|---|
| Compatibilidad de versiones | Comentarios legacy de Django 1.9 y dependencias actuales en Django 4.1 | Alto | Alta | Alta |
| Exposición de credenciales | Configuración sensible en archivos de settings y secretos | Alto | Media | Alta |
| Acoplamiento monolítico | Muchas responsabilidades concentradas en un único proyecto Django | Medio | Media | Media |
| Dependencias externas | APIs y servicios de terceros múltiples | Medio | Alta | Media-Alta |
| Configuración prod/dev diferente | Ajustes distintos en `settings.py` según entorno | Medio | Media | Media |

## 9. Respuestas a preguntas orientadoras

### ¿Qué tan centralizado o fragmentado está el sistema?
El sistema es bastante centralizado: existe un único proyecto Django que agrupa múltiples apps especializadas. No se trata de una arquitectura de microservicios, sino de un monolito modular.

### ¿Cuáles módulos concentran más responsabilidad?
Los módulos que más concentración muestran son `profesores`, `estudiantes`, `cursos`, `administrativos` y `firma_digital`, ya que gestionan usuarios, datos académicos y procesos críticos del sistema.

### ¿Qué partes parecen más activas y cuáles más legadas?
Más activas: las áreas de gestión académica (`profesores`, `estudiantes`, `cursos`), comunicación (`anuncios`, `eventos`) y contenido web (`webpage`, `wiki`). Más legadas: la presencia de comentarios legacy y ajustes de configuración sugiere deuda técnica en el core del proyecto y en migraciones históricas.

### ¿Qué señales hay de crecimiento orgánico y deuda técnica?
Señales de crecimiento orgánico: múltiples apps Django para distintos dominios (academia, eventos, firma digital, inventario, alumni). Señales de deuda técnica: referencias a Django 1.9, configuración sensible mezclada con código, y dependencias antiguas o variadas.

### ¿Dónde se observan los primeros riesgos de mantenimiento o evolución?
Los primeros riesgos aparecen en la compatibilidad de versiones, la seguridad de la configuración y el acoplamiento monolítico. También es relevante el mantenimiento de integraciones externas y la gestión de entornos dev/prod.


## 9. Observaciones finales

EIEInfo es un sistema web monolítico modularizado en Django, desplegado con Docker y orientado a la gestión académica y administrativa. Su diseño está centrado en una única aplicación Django con múltiples módulos especializados y varias integraciones externas.

- El sistema es relativamente centralizado: la mayor parte de la lógica y las responsabilidades están dentro de un solo proyecto Django, lo que facilita el despliegue pero también concentra riesgos.
- La arquitectura muestra crecimiento orgánico: se han incorporado muchas aplicaciones internas (`profesores`, `estudiantes`, `cursos`, `firma_digital`, `webpage`, `alumni`, etc.) para cubrir dominios específicos.
- Hay señales de deuda técnica: comentarios antiguos de Django 1.9, dependencias mixtas, y cambios condicionales en `settings.py` para producción y desarrollo.
- El despliegue en Docker es una fortaleza importante, porque separa DB, aplicación y proxy. Sin embargo, requiere un buen control de volúmenes y configuración para evitar inconsistencias entre entornos.
- Las integraciones externas son un punto crítico: APIs de Google, Facebook, ReCaptcha y servicios de firma digital amplían funcionalidad, pero también agregan dependencias y posibles puntos de falla.

Los riesgos más visibles en esta etapa son:

1. Compatibilidad de versiones y deuda técnica.
2. Exposición de credenciales y configuración sensible.
3. Acoplamiento monolítico con muchas responsabilidades.
4. Dependencias de servicios externos.
5. Configuración distinta entre producción y desarrollo.

En resumen, EIEInfo es un sistema sólido para su propósito, pero debe gestionarse con cuidado en su evolución técnica para evitar que la centralización y la deuda acumulada se conviertan en barreras para su mantenimiento.
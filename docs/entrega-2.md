<p align="center">
  <strong style="font-size: 1.8em;">Auditoría Técnica EIEInfo</strong><br>
  <em style="font-size: 1.1em;">Auditoría profunda de diseño, calidad y riesgos</em>
</p>

<p align="center">
  <br>
  <strong>Entrega 2</strong><br>
  <strong>16 de junio de 2026</strong><br>
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

# 1. Objetivo

Realizar una auditoría técnica profunda del sistema EIEInfo, identificando los principales problemas de diseño, su importancia y cómo se relacionan entre sí.

# 2. Pregunta central

**¿Cuáles son los principales problemas de diseño del sistema, por qué importan y cómo se relacionan entre sí?**

# 3. Resumen del documento

Este documento incluye:

- Portada
- Evaluación por atributos de calidad
- Auditoría modular
- Auditoría del dominio
- Auditoría de calidad de código
- Auditoría de pruebas y confiabilidad
- Auditoría de seguridad y operación
- Registro consolidado de hallazgos
- Conclusiones
- Anexos

---

# 4. Evaluación por atributos de calidad

## 4.1 Mantenibilidad

- **Fortalezas**
  - El proyecto está organizado en apps Django con nombres claros: `estudiantes`, `profesores`, `cursos`, `webpage`, `firma_digital`, `administrativos`, etc.
  - Existe documentación de despliegue y requisitos en `README.md`.

- **Debilidades**
  - Inconsistencia de versiones: `README.md` menciona Django 1.9.1 y `requirements.txt` usa Django 4.1.3.
  - `src/server/eieinfo/settings.py` mezcla compatibilidad antigua y configuraciones actuales.
  - Importaciones cruzadas entre apps dificultan cambios localizados.

- **Evidencia**
  - `README.md`
  - `requirements.txt`
  - `src/server/eieinfo/settings.py`

## 4.2 Modificabilidad

- **Fortalezas**
  - Las apps persiguen dominios funcionales concretos.

- **Debilidades**
  - Importaciones directas entre apps generan acople fuerte.
  - Cambios en entidades centrales pueden afectar muchas áreas.

- **Evidencia**
  - `src/server/estudiantes/models.py` importa modelos de `administrativos`, `cursos`, `laboratorios` y `proyectos`.

## 4.3 Cohesión

- **Fortalezas**
  - Algunas apps tienen propósito claro, como `webpage` o `anuncios`.

- **Debilidades**
  - `eieinfo/misc.py` combina email, generación de PDF/LaTeX y utilidades generales.
  - Modelos grandes mezclan datos con lógica de negocio.

- **Evidencia**
  - `src/server/eieinfo/misc.py`
  - `src/server/estudiantes/models.py`

## 4.4 Acoplamiento

- **Fortalezas**
  - El router central muestra la estructura global de apps.

- **Debilidades**
  - `settings.py` es un punto único de configuración global.
  - Importaciones cruzadas provocan dependencias rígidas.

- **Evidencia**
  - `src/server/eieinfo/urls.py`
  - `src/server/estudiantes/models.py`

## 4.5 Testabilidad

- **Fortalezas**
  - Existen pruebas en apps clave: `estudiantes`, `cursos`, `trabajo_final_de_graduacion`, `asistencias`.
  - Se utiliza `pytest`, `pytest-django` y `coverage`.

- **Debilidades**
  - Cobertura parcial: no todas las apps tienen tests visibles.
  - Faltan pruebas de infraestructura y despliegue.

- **Evidencia**
  - `requirements.txt`
  - archivos `tests.py` en varias apps

## 4.6 Seguridad básica

- **Fortalezas**
  - El diseño propone un archivo `secret_credentials.py` para datos sensibles.

- **Debilidades**
  - `docker-compose.yml` contiene contraseñas en texto claro.
  - Dependencias externas antiguas aumentan el riesgo.

- **Evidencia**
  - `README.md`
  - `docker-compose.yml`
  - `requirements.txt`

## 4.7 Consistencia arquitectónica

- **Fortalezas**
  - La estructura sigue el patrón estándar de Django y Docker.

- **Debilidades**
  - Conviven despliegue tradicional (systemd + NGINX) y Docker.
  - `settings.py` aplica configuraciones distintas según el host.

- **Evidencia**
  - `README.md`
  - `src/server/eieinfo/settings.py`

## 4.8 Observabilidad operativa

- **Fortalezas**
  - Hay logging configurado en `settings.py`.

- **Debilidades**
  - No se identifican métricas ni health checks de la app.
  - El monitoreo se limita a logs locales.

- **Evidencia**
  - `src/server/eieinfo/settings.py`
  - `src/server/eieinfo/misc.py`

---

# 5. Auditoría modular

## 5.1 `estudiantes`

- **Responsabilidad principal**
  - Gestión de estudiantes, solicitudes, asistencias y procesos académicos.

- **Dependencias relevantes**
  - `administrativos`, `cursos`, `laboratorios`, `proyectos`

- **Fortalezas**
  - Domina un dominio académico esencial.

- **Debilidades**
  - Modelo `Estudiante` está sobrecargado.
  - Muchas importaciones cruzadas.

- **Riesgos de cambio**
  - Altamente sensible a modificaciones transversales.

- **Recomendación**
  - Desacoplar integraciones y simplificar el modelo.

## 5.2 `cursos`

- **Responsabilidad principal**
  - Gestión de cursos, plantillas, requisitos y horarios.

- **Dependencias relevantes**
  - `profesores`, `administrativos`, `webpage`

- **Fortalezas**
  - Uso de herencia polimórfica entre `PlantillaCurso` y `Curso`.

- **Debilidades**
  - Mezcla lógica de dominio con persistencia.
  - Modelo muy grande con funciones de ruta.

- **Riesgos de cambio**
  - Cambios en la lógica de cursos afectan procesos académicos clave.

- **Recomendación**
  - Separar lógica de dominio y persistencia.

## 5.3 `trabajo_final_de_graduacion`

- **Responsabilidad principal**
  - Gestión del proceso de TFG.

- **Dependencias relevantes**
  - `profesores`, `estudiantes`, `administrativos`

- **Fortalezas**
  - Pruebas específicas de formularios y validaciones.

- **Debilidades**
  - Posible acoplamiento con UI y flujo de presentación.

- **Riesgos de cambio**
  - Cambios en validaciones pueden romper el proceso.

- **Recomendación**
  - Establecer estados de proceso claros y servicios dedicados.

## 5.4 `eieinfo`

- **Responsabilidad principal**
  - Configuración global, logging y utilidades compartidas.

- **Fortalezas**
  - Centraliza herramientas comunes.

- **Debilidades**
  - Acumula demasiadas responsabilidades en un solo módulo.
  - Cambios tienen impacto transversal.

- **Riesgos de cambio**
  - Alteraciones pueden afectar todo el sistema.

- **Recomendación**
  - Modularizar utilidades en componentes independientes.

## 5.5 `webpage`

- **Responsabilidad principal**
  - Gestión del contenido público y página principal.

- **Dependencias relevantes**
  - `wiki`, `anuncios`, `eventos`

- **Fortalezas**
  - Actúa como la fachada pública del sistema.

- **Debilidades**
  - Riesgo de mezclar datos y presentación.

- **Riesgos de cambio**
  - Cambios en la UI afectan la experiencia de usuario.

- **Recomendación**
  - Mantenerla ligera y delegar datos complejos.

---

# 6. Auditoría del dominio

## 6.1 Entidades principales

- Estudiante
- Profesor
- Funcionario
- Curso
- PlantillaCurso
- Grupo
- Proyecto
- Laboratorio
- Evento
- Conferencia
- Asistencia
- Postulación
- Trabajo Final de Graduación
- Inventario

## 6.2 Relaciones importantes

- `Estudiante` → `PlanDeEstudio`
- `Estudiante` → `Asistencia`
- `Estudiante` → `Proyecto`
- `Estudiante` → `TrabajoFinalDeGraduacion`
- `Profesor` → `Curso`
- `Curso` → `PlantillaCurso`
- `Curso` → requisitos / correquisitos
- `Evento` → `Webpage`
- `Conferencia` → `Eventos`

## 6.3 Jerarquías visibles

- `PlantillaCurso` se especializa en `Curso`
- `Curso` representa una instancia de plantilla académica
- `Estudiante` es la entidad central del dominio

## 6.4 Conceptos compartidos y ambigüedades

- `Curso` y `PlanDeEstudio` comparten el dominio académico.
- `TrabajoFinalDeGraduacion` y `proyectos` comparten reglas de titulación.
- `Estudiante` mezcla datos personales, académicos y financieros.

## 6.5 Diagrama de dominio simplificado

```text
[Estudiante] --(plan_estudio)--> [PlanDeEstudio]
[Estudiante] --(solicita)-> [Asistencia]
[Estudiante] --(participa)-> [Proyecto]
[Estudiante] --(realiza)-> [TrabajoFinalDeGraduacion]
[Profesor] --(dicta)-> [Curso]
[Curso] --(instancia)-> [PlantillaCurso]
[Curso] --(requiere)-> [PlantillaCurso]
[Evento] --(publica)-> [Webpage]
[Conferencia] --(organiza)-> [Eventos]
```

## 6.6 Explicación analítica

El dominio de EIEInfo está centrado en la gestión académica y administrativa, con el estudiante como entidad principal. La herencia de `PlantillaCurso` a `Curso` permite múltiples tipos de oferta académica, pero añade complejidad. Los procesos de proyectos, TFG y laboratorios comparten flujos similares, lo que sugiere posibles ambigüedades conceptuales.

---

# 7. Auditoría de calidad del código

## 7.1 Archivos con alta complejidad o tamaño

- `src/server/estudiantes/models.py`
- `src/server/cursos/models.py`
- `src/server/eieinfo/misc.py`

## 7.2 Mezcla de responsabilidades

- `eieinfo/misc.py` contiene email, LaTeX y utilidades generales.
- `estudiantes/models.py` combina entidad con lógica de negocio.
- `settings.py` mezcla configuración de entorno y despliegue.

## 7.3 Duplicación

- Constantes de estado y modalidades repetidas en varios módulos.
- Lógica de correo y archivos potencialmente duplicada.

## 7.4 Convenciones inconsistentes

- El README exige PEP8, pero el código sigue estilos mixtos.
- La nomenclatura no es completamente uniforme.

## 7.5 Código histórico o legado

- Hay rastros de Django 1.9 coexistiendo con Django 4.1.
- `settings.py` incluye parches de compatibilidad antiguos.

## 7.6 Puntos de acoplamiento difícil

- `eieinfo/urls.py` es un núcleo de enrutamiento centralizado.
- `estudiantes/models.py` depende de múltiples apps externas.

## 7.7 Lógica de negocio en capas inadecuadas

- Funciones de email y PDF en utilidades generales.
- Validaciones dentro de modelos.
- Configuración de despliegue mezclada con settings.

---

# 8. Auditoría de pruebas y confiabilidad

## 8.1 Partes mejor cubiertas

- `estudiantes`: login, registro, recuperación, perfil y recursos.
- `cursos`: paginación, búsqueda y detalle.
- `trabajo_final_de_graduacion`: formularios, validaciones y correo.

## 8.2 Partes frágiles

- Infraestructura y despliegue sin pruebas visibles.
- Módulos administrativos sin cobertura clara.
- Integraciones entre apps no cubiertas.

## 8.3 Estilo de pruebas

- `pytest` / `pytest-django`
- `TestCase`, `TransactionTestCase`
- `override_settings`
- uso de mocks para correo

## 8.4 Confiabilidad de la suite

- Hay pruebas relevantes, pero la cobertura es parcial.
- Falta un plan uniforme de pruebas en todo el proyecto.

## 8.5 Vacíos que dificultan la evolución segura

- Pruebas de Docker y despliegue.
- Pruebas de seguridad y autenticación.
- Pruebas de configuración de entornos.
- Pruebas de APIs externas.

---

# 9. Auditoría de seguridad y operación

## 9.1 Manejo de secretos

- El diseño propone `secret_credentials.py` fuera del repo.
- El riesgo es que `docker-compose.yml` mantiene contraseñas en claro.

## 9.2 Configuración sensible

- `docker-compose.yml` expone `MYSQL_ROOT_PASSWORD` y `MYSQL_PASSWORD`.
- `settings.py` usa rutas fijas como `/var/info/`.

## 9.3 Riesgos en endpoints o autenticación

- `eieinfo/urls.py` expone muchas apps desde un mismo proyecto.
- No se ven controles de acceso finos en el enrutamiento global.

## 9.4 Dependencias problemáticas

- `requirements.txt` incluye paquetes antiguos y Git directos:
  - `django-tagging==0.5.0`
  - `oauth2client==3.0.0`
  - `facebook-sdk==2.0.0`

## 9.5 Prácticas de despliegue y automatización

- Hay Docker Compose y documentación de NGINX + Gunicorn + systemd.
- Existe healthcheck para MariaDB.
- No hay evidencia de CI/CD ni monitoreo integrado.

---

# 10. Registro consolidado de hallazgos

| ID | Severidad | Título | Descripción técnica | Evidencia | Consecuencia | Recomendación |
|---|---|---|---|---|---|---|
| H-01 | Crítico | Inconsistencia de versiones Django | `README.md` indica Django 1.9.1, el código usa Django 4.1.3. | `README.md`, `requirements.txt` | Inestabilidad y fallos de compatibilidad. | Unificar versión y actualizar documentación. |
| H-02 | Crítico | Secretos en texto claro | `docker-compose.yml` contiene credenciales MySQL. | `docker-compose.yml` | Fuga de datos sensibles. | Usar variables de entorno seguras. |
| H-03 | Crítico | Acoplamiento entre apps | `estudiantes/models.py` importa múltiples modelos externos. | `src/server/estudiantes/models.py` | Cambios de un módulo impactan muchos otros. | Desacoplar con servicios o repositorios. |
| H-04 | Alto | `misc.py` sobrecargado | Email, LaTeX y utilidades en un solo archivo. | `src/server/eieinfo/misc.py` | Dificulta pruebas y mantenimiento. | Dividir en módulos independientes. |
| H-05 | Alto | Modelos demasiado grandes | `estudiantes/models.py` y `cursos/models.py` mezclan responsabilidades. | `src/server/estudiantes/models.py`, `src/server/cursos/models.py` | Baja legibilidad y riesgo de regresión. | Extraer lógica a servicios. |
| H-06 | Alto | Pruebas parciales | Muchos módulos no tienen tests visibles. | `requirements.txt`, `tests.py` | Cobertura incompleta. | Ampliar pruebas e integración. |
| H-07 | Alto | Dependencias obsoletas | Paquetes antiguos y Git directos en `requirements.txt`. | `requirements.txt` | Vulnerabilidades e incompatibilidades. | Actualizar dependencias. |
| H-08 | Medio | Configuración inconsistente | `settings.py` mezcla ajustes prod/dev y lógica de entorno. | `src/server/eieinfo/settings.py` | Comportamiento distinto por ambiente. | Separar settings por entorno. |
| H-09 | Medio | Observabilidad limitada | Logging local sin métricas o monitoreo. | `settings.py`, `misc.py` | Dificultad para detectar fallas. | Implementar health checks y métricas. |
| H-10 | Medio | Enrutamiento centralizado | `eieinfo/urls.py` agrupa demasiadas rutas en un solo punto. | `src/server/eieinfo/urls.py` | Acoplamiento estructural. | Modularizar rutas por dominio. |
| H-11 | Medio | Admin expuesto desde el mismo proyecto | Admin y wiki accesibles desde la misma app. | `src/server/eieinfo/urls.py` | Mayor superficie de ataque. | Proteger rutas sensibles. |
| H-12 | Bajo | Generación LaTeX en la app | `misc.py` ejecuta `pdflatex` dentro del servidor. | `src/server/eieinfo/misc.py` | Carga extra y dependencia de plataforma. | Externalizar la generación de documentos. |

---

# 11. Conclusiones

EIEInfo es un sistema funcional y bien organizado para su dominio académico, pero su evolución está limitada por deuda técnica y acoplamientos internos.

- Los principales problemas de diseño son:
  - incompatibilidad de versiones,
  - seguridad de configuración,
  - acoplamiento monolítico,
  - dependencias externas,
  - diferencias entre entornos.

- Estos problemas importan porque afectan mantenimiento, despliegue seguro y capacidad de evolución.
- Están relacionados: la deuda técnica y el acoplamiento aumentan el costo de actualizar dependencias y proteger el sistema.
- Las mejoras prioritarias deben enfocarse en:
  - unificar versiones,
  - asegurar secretos,
  - separar responsabilidades,
  - mejorar pruebas,
  - reforzar observabilidad.

---

# 12. Anexos

## 12.1 Diagrama de dominio simplificado

```text
[Estudiante] --(plan_estudio)--> [PlanDeEstudio]
[Estudiante] --(solicita)-> [Asistencia]
[Estudiante] --(participa)-> [Proyecto]
[Estudiante] --(realiza)-> [TrabajoFinalDeGraduacion]
[Profesor] --(dicta)-> [Curso]
[Curso] --(instancia)-> [PlantillaCurso]
[Curso] --(requiere)-> [PlantillaCurso]
[Evento] --(publica)-> [Webpage]
[Conferencia] --(organiza)-> [Eventos]
```

## 12.2 Matriz de riesgos

| Riesgo | Causa | Impacto | Probabilidad | Prioridad |
|---|---|---|---|---|
| Compatibilidad de versiones | Legacy + dependencias actuales | Alto | Alta | Alta |
| Exposición de credenciales | Secrets en archivos y Docker | Alto | Media | Alta |
| Acoplamiento monolítico | Muchas responsabilidades en un solo proyecto | Medio | Media | Media |
| Dependencias externas | APIs y servicios de terceros | Medio | Alta | Media-Alta |
| Configuración prod/dev distinta | Ajustes condicionales en `settings.py` | Medio | Media | Media |

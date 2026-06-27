# Auditoría Técnica EIEInfo
## Informe final de auditoría y propuesta de evolución

**Entrega 3**  
**30 de junio de 2026**

**Universidad de Costa Rica (UCR)**  
**Escuela de Ingeniería Eléctrica**  
**Taller de Auditoría Técnica de Software**

**Estudiante:** Kevin Hernández Umaña C33773  
**Carrera / Curso:** Ingeniería Eléctrica / Diseño de Software para Ingeniería (IE 0417)  
**Profesor:** Rafael Esteban Badilla Alvarado

---

# 1. Resumen ejecutivo final

EIEInfo es un sistema funcional, con una base tecnológica razonable y un dominio académico claro, pero su capacidad de evolución está limitada por deuda técnica, acoplamiento estructural y riesgos de seguridad y operación. El sistema no requiere una reescritura total, sino una modernización progresiva y bien priorizada.

## 1.1 Estado general del sistema

- El sistema está construido sobre Django con una arquitectura monolítica modularizada.
- Tiene un dominio bien identificado y módulos funcionales relativamente claros.
- Presenta fortalezas en organización modular, despliegue con Docker y separación funcional por apps.
- Sin embargo, muestra problemas sistémicos en compatibilidad de versiones, manejo de secretos, acoplamiento entre módulos y cobertura limitada de pruebas.

## 1.2 Fortalezas rescatables

- Organización por apps de Django con responsabilidades relativamente delimitadas.
- Uso de Docker para facilitar despliegue y reproducibilidad.
- Diseño orientado a procesos académicos y administrativos, con dominio comprensible.
- Existencia de documentación inicial y estructura de proyecto relativamente ordenada.

## 1.3 Riesgos principales

- Inconsistencia entre versiones documentadas y reales de Django.
- Secretos y credenciales expuestos en archivos de configuración.
- Alto acoplamiento entre módulos y entre lógica de negocio y utilidades transversales.
- Dependencias antiguas y riesgo de vulnerabilidades.
- Falta de observabilidad y automatización mínima de operaciones.

## 1.4 Urgencia de intervención

La intervención debe ser inmediata en tres frentes: seguridad, consistencia de dependencias y desacoplamiento de componentes críticos. Estos tres puntos son los que más afectan la continuidad y la evolución del sistema.

## 1.5 Lectura global del diseño actual

El diseño actual permite sostener la operación del sistema, pero está siendo presionado por la acumulación de deuda técnica. El sistema puede seguir funcionando, pero crecerá cada vez más costoso y riesgoso si no se corrigen sus puntos de fragilidad.

---

# 2. Arquitectura actual

La arquitectura actual corresponde a un monolito modular en Django con varias aplicaciones especializadas que comparten configuración global, modelos y utilidades.

## 2.1 Características observadas

- Un único proyecto Django con múltiples apps: `estudiantes`, `profesores`, `cursos`, `administrativos`, `webpage`, entre otras.
- Configuración centralizada en `settings.py`.
- Enrutamiento centralizado en `urls.py`.
- Lógica transversal en `eieinfo/misc.py`.
- Despliegue basado en Docker Compose con servicios de base de datos, aplicación y proxy.

## 2.2 Diagrama simplificado de la arquitectura actual

```text
Usuario
  |
  v
Nginx / proxy
  |
  v
Django app (monolito modular)
  |-- apps: estudiantes, cursos, profesores, administrativos...
  |-- settings global
  |-- utilidades transversales
  |
  v
MySQL / MariaDB
```

---

# 3. Hoja de ruta de evolución

La estrategia recomendada es una evolución por fases, empezando por los riesgos más críticos y terminando en saneamiento y modernización progresiva.

## Fase 1: Mitigación de riesgos críticos (0 a 1 mes)

- **Objetivo:** cerrar brechas inmediatas de seguridad y estabilidad.
- **Alcance:** unificar versiones de Django, mover secretos a variables de entorno, revisar configuraciones sensibles y documentar la arquitectura actual.
- **Beneficio esperado:** reducción inmediata del riesgo operativo y de seguridad.
- **Riesgos:** cambios en configuración pueden afectar el despliegue inicial.
- **Dependencias:** equipo de operaciones, entorno de despliegue, acceso a secretos.
- **Esfuerzo relativo:** Medio.

## Fase 2: Saneamiento técnico inicial (1 a 3 meses)

- **Objetivo:** reducir deuda técnica visible y aumentar control sobre el código.
- **Alcance:** dividir utilidades globales, limpiar imports cruzados, separar settings por entorno e introducir convenciones mínimas de estructura.
- **Beneficio esperado:** mayor mantenibilidad y menor riesgo de regresión.
- **Riesgos:** refactorización incompleta puede generar cambios dispersos.
- **Dependencias:** revisión de módulos críticos y pruebas de regresión.
- **Esfuerzo relativo:** Alto.

## Fase 3: Refactorización modular (3 a 6 meses)

- **Objetivo:** hacer que los módulos del sistema tengan límites más claros.
- **Alcance:** mover lógica de negocio a servicios, reducir dependencias entre apps, extraer módulos compartidos y estabilizar contratos internos.
- **Beneficio esperado:** mayor modificabilidad y menos impacto de cambio.
- **Riesgos:** cambios mal guiados pueden romper flujos existentes.
- **Dependencias:** pruebas automatizadas y diseño de interfaces claras.
- **Esfuerzo relativo:** Alto.

## Fase 4: Fortalecimiento de pruebas y seguridad (6 a 9 meses)

- **Objetivo:** convertir el sistema en algo más confiable y evolutivo.
- **Alcance:** ampliar pruebas unitarias e integración, establecer CI/CD mínimo, agregar health checks y observabilidad básica.
- **Beneficio esperado:** más confianza para cambios futuros.
- **Riesgos:** inversión inicial alta si hay poco soporte de automatización.
- **Dependencias:** infraestructura de CI y cultura de revisión de cambios.
- **Esfuerzo relativo:** Medio-Alto.

## Fase 5: Modernización progresiva (9 a 12 meses)

- **Objetivo:** preparar el sistema para una evolución más sostenible a mediano plazo.
- **Alcance:** mejorar documentación, revisar dependencias obsoletas, introducir estrategias de despliegue más robustas y definir gobernanza técnica.
- **Beneficio esperado:** base sólida para crecimiento y mantenimiento sostenido.
- **Riesgos:** cambios demasiado grandes si no se conservan los procesos actuales.
- **Dependencias:** visión a largo plazo del equipo y continuidad de mantenimiento.
- **Esfuerzo relativo:** Medio.

---

# 4. Intervenciones prioritarias

| Prioridad | Intervención | Problema que atiende | Beneficio esperado | Riesgo | Esfuerzo |
|---|---|---|---|---|---|
| 1 | Unificar versiones de Django y dependencias | Inconsistencia de versiones y deuda técnica | Menor incompatibilidad y mejor estabilidad | Medio | Medio |
| 2 | Externalizar secretos y separar configuraciones por entorno | Riesgo de seguridad y ambiente inconsistente | Mayor seguridad y control de despliegue | Medio | Bajo |
| 3 | Desacoplar utilidades globales como `misc.py` | Mezcla de responsabilidades | Mayor cohesión y facilidad de pruebas | Medio | Medio |
| 4 | Reducir imports cruzados entre apps | Acoplamiento estructural | Cambios más locales y menos riesgosos | Alto | Medio-Alto |
| 5 | Definir servicios de dominio para lógica crítica | Lógica mezclada con modelos y vistas | Mejor mantenibilidad y testabilidad | Medio | Alto |
| 6 | Ampliar la suite de pruebas para módulos críticos | Cobertura limitada | Mayor confiabilidad y menor riesgo de regresión | Medio | Medio |
| 7 | Implementar health checks, logs y métricas mínimas | Baja observabilidad operativa | Mejor diagnóstico y operación | Medio | Medio |
| 8 | Establecer CI/CD básico y revisión de cambios | Falta de automatización y control | Despliegues más seguros y consistentes | Medio | Medio |

---

# 5. Propuesta de gobierno técnico

Para sostener la evolución del sistema, se recomienda un gobierno técnico mínimo pero consistente.

## 5.1 Reglas de manejo de secretos

- No almacenar secretos ni credenciales en archivos de configuración compartidos.
- Usar variables de entorno o herramientas de gestión de secretos.
- Mantener separación entre entornos de desarrollo, prueba y producción.

## 5.2 Criterios para aceptar cambios

- Todo cambio importante debe pasar por revisión técnica.
- Los cambios que afecten módulos críticos deben incluir pruebas o evidencia de validación.
- No se deben introducir nuevas dependencias sin justificar su necesidad y costo.

## 5.3 Estrategia mínima de pruebas

- Tests unitarios para lógica crítica.
- Tests de integración para flujos principales.
- Validación básica de despliegue y configuración.
- Cobertura mínima para módulos de alto riesgo.

## 5.4 Prácticas de revisión técnica

- Revisión de cambios por otro integrante del equipo.
- Evaluación de impacto antes de hacer refactorizaciones grandes.
- Documentación breve de decisiones de arquitectura y cambios relevantes.

## 5.5 Lineamientos de modularidad

- Cada módulo debe tener una responsabilidad clara.
- No mezclar lógica de negocio con utilidades de infraestructura.
- Evitar dependencias cruzadas innecesarias entre apps.
- Mantener interfaces simples y explícitas.

## 5.6 Documentación mínima requerida

- Arquitectura general del sistema.
- Mapa de módulos y dependencias.
- Reglas de despliegue y variables de entorno.
- Guías rápidas para pruebas y diagnóstico de fallas.

---

# 6. Conclusión final

La propuesta de evolución para EIEInfo debe basarse en una estrategia realista, gradual y bien priorizada. El sistema no necesita ser reemplazado ni reescrito desde cero para seguir siendo valioso; por el contrario, su mayor oportunidad está en conservar su base funcional y mejorar aquellas dimensiones que hoy limitan su sostenibilidad. La arquitectura actual, aunque funcional, muestra signos claros de deuda técnica, especialmente en aspectos como compatibilidad de versiones, manejo de secretos, acoplamiento entre módulos y falta de automatización operativa. Estos problemas no solo afectan la calidad técnica del sistema, sino también su capacidad para absorber cambios futuros sin generar riesgos excesivos.

En este sentido, la intervención más conveniente no es una reestructuración radical, sino una evolución controlada que priorice primero los riesgos críticos, luego el saneamiento técnico y, posteriormente, la consolidación de un modelo de desarrollo más modular y confiable. La mejora de la seguridad, la separación de responsabilidades, la reducción del acoplamiento y la ampliación de pruebas deberían considerarse como inversiones estratégicas, porque permiten que el sistema siga operando sin perder estabilidad mientras se adapta a nuevas necesidades. Asimismo, la incorporación de prácticas de gobierno técnico, documentación mínima y revisión de cambios ayudará a que las futuras modificaciones sean más previsibles y menos costosas.

En resumen, EIEInfo tiene bases suficientemente sólidas como para seguir evolucionando, pero requiere disciplina técnica y decisiones de arquitectura más claras. Si se implementan las recomendaciones de forma progresiva y con enfoque en los riesgos más urgentes, el sistema podrá mantenerse útil, seguro y más fácil de mantener durante los próximos años. La clave no está en hacer cambios grandes de golpe, sino en construir una base de evolución sostenible, donde la seguridad, la modularidad y la confiabilidad se conviertan en prioridades permanentes.
# Parte 1 - Preparacion del Proyecto

## Que se hizo

Se preparo la estructura base del proyecto para realizar pruebas automatizadas en C++. Ademas, se configuro CMake como sistema de construccion y se integro Google Test como framework para pruebas unitarias.

## Archivos modificados

- CMakeLists.txt
- docs/parte1-plan-pruebas.md

## Comandos ejecutados

```bash
mkdir -p laboratorio-testing/include
mkdir -p laboratorio-testing/src
mkdir -p laboratorio-testing/tests
mkdir -p laboratorio-testing/docs
mkdir -p laboratorio-testing/.github/workflows
cd laboratorio-testing
```

## Resultado obtenido

Se creo la estructura de carpetas requerida para el laboratorio y se configuro el archivo `CMakeLists.txt` para tener la compilacion del proyecto y la ejecucion de pruebas con Google Test.

## Errores encontrados

No se presentaron errores durante esta etapa.

## Que se aprendio

Se aprendio como organizar un proyecto de C++, utilizar CMake para automatizar la compilacion e integrar Google Test para realizar pruebas unitarias.

---

# Conceptos Teoricos

## Que es CMake

CMake es una herramienta que permite generar automaticamente los archivos necesarios para compilar un proyecto en diferentes plataformas y compiladores. Facilita la administracion de proyectos y evita tener que escribir manualmente comandos complejos de compilacion.

## Para que sirve Google Test

Google Test es un framework de pruebas unitarias para C++. Permite crear y ejecutar pruebas automatizadas para verificar que las funciones del programa produzcan los resultados esperados.

## Que significa automatizar pruebas

Automatizar pruebas consiste en crear casos de prueba que puedan ejecutarse automaticamente mediante herramientas de software, sin necesidad de verificar manualmente cada resultado.

## Que significa que las pruebas sean repetibles

Significa que una prueba puede ejecutarse multiples veces bajo las mismas condiciones y producir siempre el mismo resultado. Esto permite detectar errores de forma confiable y validar cambios en el codigo.

---

# Estructura del Proyecto

Las siguientes carpetas y archivos fueron creados para el laboratorio:

```text
laboratorio-testing/
├── README.md
├── CMakeLists.txt
├── include/
├── src/
├── tests/
├── docs/
└── .github/
    └── workflows/
```

---

# Preguntas de Reflexion

## 1. Por que conviene separar el codigo fuente de las pruebas

Separar el codigo fuente de las pruebas mejora la organizacion del proyecto, facilita el mantenimiento y permite modificar las pruebas sin afectar el codigo principal.

## 2. Que ventaja tiene usar CMake en un proyecto de C++

CMake permite automatizar la compilacion, administrar dependencias y mantener compatibilidad entre distintos sistemas operativos y compiladores.

## 3. Por que es util que las pruebas se puedan ejecutar con un solo comando

Porque permite verificar rapidamente que todo el proyecto funciona correctamente, reduce errores humanos y facilita la integracion continua.

## 4. Que diferencia hay entre probar manualmente y probar automaticamente

Las pruebas manuales requieren que una persona ejecute y verifique cada caso de prueba. Las pruebas automaticas son ejecutadas por herramientas de software y pueden repetirse cuantas veces sea necesario de manera rapida y consistente.

# Parte 9: pruebas funcionales sencillas


## Tabla de casos funcionales

| ID | Requisito | Entrada | Resultado esperado | Tipo de caso |
|---|---|---:|---|---|
| TC-001 | Convertir nota excelente | 95 | A | Normal |
| TC-002 | Limite inferior de A | 90 | A | Borde |
| TC-003 | Limite superior de B | 89 | B | Borde |
| TC-004 | Nota invalida baja | -1 | Excepcion | Invalido |
| TC-005 | Nota invalida alta | 101 | Excepcion | Invalido |

## Casos ya cubiertos por pruebas

- TC-001 Convertir nota excelente
- TC-002 Limite inferior de A
- TC-003 Limite superior de B
- TC-004 Nota invalida baja
- TC-005 Nota invalida alta

Estos casos ya estaban cubiertos en `tests/test_grade_utils.cpp`.

## Casos que se tuvieron que agregar

No fue necesario agregar casos nuevos porque las pruebas existentes ya cubrian todos los escenarios de la tabla.

## Por que estas pruebas son funcionales

Estas pruebas son funcionales porque estan basadas en los requisitos del sistema (conversion de notas a letras). Verifican que el comportamiento del programa cumpla con lo que se espera desde el punto de vista del usuario.

---

# Preguntas de reflexion

## 1. Que diferencia hay entre una prueba unitaria y una prueba funcional?

Una prueba unitaria verifica una funcion o componente individual, mientras que una prueba funcional verifica el comportamiento del sistema basado en requisitos.

## 2. Por que una prueba funcional se relaciona con requisitos?

Porque valida que el sistema cumpla con lo que se espera segun las reglas definidas en el problema o especificacion.

## 3. Que significa pensar desde la perspectiva del usuario o del sistema?

Significa enfocarse en lo que el sistema debe hacer, no en como esta implementado internamente.

## 4. Por que la documentacion de casos de prueba ayuda al equipo?

Porque permite entender claramente que se esta probando, facilita el mantenimiento y asegura que todos validen los mismos requisitos.
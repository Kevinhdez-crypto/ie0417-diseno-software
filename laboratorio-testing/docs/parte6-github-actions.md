## 10.4 Documentacion requerida

## Que es integracion continua

La integracion continua es una practica donde cada cambio en el codigo se compila y prueba automaticamente para detectar errores rapidamente.

## Que hace el archivo `testing.yml`

Define el workflow de GitHub Actions que compila el proyecto y ejecuta las pruebas automaticamente en cada push o pull request.

## En que eventos se ejecuta el workflow

Se ejecuta cuando hay un push a la rama main y cuando se abre o actualiza un pull request hacia main.

## Que pasos ejecuta el workflow

# Descarga el repositorio
# Instala dependencias
# Configura el proyecto con CMake
# Compila el codigo
# Ejecuta las pruebas

## Captura o evidencia del workflow exitoso

El workflow es exitoso cuando todos los pasos aparecen en verde en GitHub Actions y las pruebas pasan sin errores.
En mi caso si me meto a configuraciones me sale: 

name: C/C++ CI

on:
  push:
    branches: [ "main" ]
  pull_request:
    branches: [ "main" ]

jobs:
  build:

    runs#on: ubuntu#latest

    steps:
    # uses: actions/checkout@v4
    # name: configure
      run: ./configure
    # name: make
      run: make
    # name: make check
      run: make check
    # name: make distcheck

## Que pasaria si una prueba falla en GitHub Actions

Si una prueba falla, el workflow se detiene y GitHub marca la ejecucion como fallida mostrando logs del error y la prueba que fallo.

###

## 10.5 Preguntas de reflexion

## 1. Por que es util ejecutar pruebas automaticamente en GitHub?

Porque permite detectar errores de forma inmediata sin necesidad de ejecucion manual.

## 2. Que problema resuelve la integracion continua?

Evita integrar codigo con errores y reduce fallos al combinar cambios de diferentes desarrolladores.

## 3. Por que conviene ejecutar pruebas antes de integrar cambios?

Porque asegura que los cambios no rompan funcionalidades existentes.

## 4. Que informacion proporciona GitHub Actions cuando un workflow falla?

Muestra logs, paso exacto del error y pruebas que fallaron.

## 5. Como ayuda CI a mejorar la colaboracion en equipo?

Permite validar automaticamente todos los cambios, reduciendo conflictos y errores en equipo.


## Fallo intencional en CI

## Que cambio se hizo para provocar el fallo

Se modifico una prueba en `tests/test_calculator.cpp`, cambiando el valor esperado de:


EXPECT_EQ(add(2, 3), 5); se cambio a : EXPECT_EQ(add(2, 3), 999);



# Que paso localmente.
la prueba fallo inmediatamente, ya que la funcion add(2, 3) no devuelve 999, sino 5.


# Que mensaje mostro el workflow.
Test failed

# Como se corrigio.
Se restauro la prueba original:

EXPECT_EQ(add(2, 3), 5);



# Evidencia del workflow exitoso despues de corregir.

el workflow volvio a ejecutarse correctamente.
Todas las pruebas aparecieron como passed.
El pipeline finalizo exitosamente sin errores.



###

## 11.4 Preguntas de reflexion


# ¿Por que es util ver una prueba fallar al menos una vez?
 Porque permite confirmar que el sistema de pruebas realmente detecta errores y no esta pasando todo por defecto.

# ¿Que diferencia hay entre una prueba fallando localmente y una prueba fallando en CI?
Localmente ayuda a detectar errores antes de subir cambios.
 En CI valida automaticamente en un entorno limpio y estandarizado, evitando dependencias del equipo local.

#Por que no se deberia dejar codigo con pruebas fallidas en la rama principal?
 Porque rompe la integridad del proyecto y puede bloquear integraciones o despliegues.

# ¿Que aporta CI a la calidad del software?
 Asegura ejecucion automatica de pruebas, deteccion temprana de errores y consistencia en el codigo entre todos los desarrolladores.
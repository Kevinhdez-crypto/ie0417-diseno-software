## 10.4 Documentacion requerida

## Que es integracion continua

La integracion continua es una practica donde cada cambio en el codigo se compila y prueba automaticamente para detectar errores rapidamente.

## Que hace el archivo `testing.yml`

Define el workflow de GitHub Actions que compila el proyecto y ejecuta las pruebas automaticamente en cada push o pull request.

## En que eventos se ejecuta el workflow

Se ejecuta cuando hay un push a la rama main y cuando se abre o actualiza un pull request hacia main.

## Que pasos ejecuta el workflow

- Descarga el repositorio
- Instala dependencias
- Configura el proyecto con CMake
- Compila el codigo
- Ejecuta las pruebas

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

    runs-on: ubuntu-latest

    steps:
    - uses: actions/checkout@v4
    - name: configure
      run: ./configure
    - name: make
      run: make
    - name: make check
      run: make check
    - name: make distcheck

## Que pasaria si una prueba falla en GitHub Actions

Si una prueba falla, el workflow se detiene y GitHub marca la ejecucion como fallida mostrando logs del error y la prueba que fallo.

---

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
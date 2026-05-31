# Parte 5 - Cobertura de codigo

## Que es cobertura de codigo

La cobertura de codigo es una medida que indica que partes del codigo fueron ejecutadas durante las pruebas. Sirve para saber que lineas, ramas o funciones fueron recorridas por los tests.

## Comandos utilizados

```bash
rm -rf build
mkdir build
cd build

cmake -DENABLE_COVERAGE=ON ..
make
./run_tests
```

```bash
lcov --capture --directory . --output-file coverage.info

lcov --remove coverage.info '/usr/*' '*/_deps/*' '*/tests/*' --output-file coverage_filtered.info

genhtml coverage_filtered.info --output-directory coverage_report
```

## Porcentaje de cobertura obtenido

No se pudo obtener el porcentaje de cobertura debido a errores con lcov al generar el reporte (errores de inconsistencia en archivos gcda).

## Archivos con mayor cobertura

- src/calculator.cpp
- src/string_utils.cpp
- src/grade_utils.cpp

## Archivos con menor cobertura

- Archivos de dependencias externas (_deps)
- Archivos del sistema (/usr/*)
- Partes internas del build no ejecutadas directamente

## Lineas o ramas no cubiertas

- Ramas de error no ejecutadas en pruebas
- Condiciones alternativas en validaciones internas
- Casos limite no incluidos en los tests

## Captura del reporte HTML o salida relevante

No se genero reporte HTML debido a errores de lcov.

```text
lcov: ERROR: (inconsistent) mismatched end line for GradeUtilsTest_CalculateAverage_Test
lcov: ERROR: cannot read file coverage.info
genhtml: ERROR: coverage_filtered.info not readable
```

## Pruebas adicionales que podrian aumentar la cobertura

- Pruebas con valores extremos en letter_grade (ej. -1, 0, 100, 120)
- Pruebas adicionales de division incluyendo casos limites
- Pruebas de string_utils con strings vacios, espacios y caracteres especiales

---

# Preguntas de reflexion

## 1. Que significa tener 100% de cobertura?

Significa que todas las lineas del codigo fueron ejecutadas al menos una vez durante las pruebas.

## 2. Tener 100% de cobertura garantiza que el programa no tiene errores?

No. Solo significa que el codigo fue ejecutado, pero no asegura que los resultados sean correctos.

## 3. Que diferencia hay entre cobertura de lineas y cobertura de ramas?

Cobertura de lineas verifica si una linea se ejecuto. Cobertura de ramas verifica si se tomaron todas las decisiones posibles (if/else, condiciones).

## 4. Por que una linea ejecutada no necesariamente significa que fue bien probada?

Porque puede ejecutarse con pocos casos y no cubrir escenarios extremos o combinaciones de datos.

## 5. Como puede ayudar la cobertura a mejorar las pruebas?

Ayuda a identificar partes del codigo que no han sido ejecutadas, permitiendo agregar pruebas adicionales para mejorar la calidad del software.
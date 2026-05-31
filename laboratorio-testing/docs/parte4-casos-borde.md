# Parte 6 - Diseno de casos borde

## Que se hizo

Se agregaron nuevas pruebas unitarias para verificar el comportamiento del programa en situaciones limite, entradas especiales y casos invalidos.

## Archivos modificados

```text
tests/test_calculator.cpp
tests/test_string_utils.cpp
tests/test_grade_utils.cpp
```

## Casos borde agregados

### Calculator

```cpp
TEST(CalculatorTest, DivideNegativeNumbers)
TEST(CalculatorTest, DividePositiveByNegative)
TEST(CalculatorTest, ZeroIsEven)
```

### StringUtils

```cpp
TEST(StringUtilsTest, EmptyStringToUppercase)
TEST(StringUtilsTest, EmptyStringIsPalindrome)
TEST(StringUtilsTest, SingleLetterIsPalindrome)
```

### GradeUtils

```cpp
TEST(GradeUtilsTest, MinimumValidGrade)
TEST(GradeUtilsTest, MaximumValidGrade)
TEST(GradeUtilsTest, NegativeGradeThrowsException)
TEST(GradeUtilsTest, GradeBoundaryBetweenFAndD)
TEST(GradeUtilsTest, GradeBoundaryBetweenDAndC)
TEST(GradeUtilsTest, GradeBoundaryBetweenCAndB)
TEST(GradeUtilsTest, GradeBoundaryBetweenBAndA)
```

## Que es un caso borde

Un caso borde es una prueba que utiliza valores ubicados en los limites de funcionamiento de una funcion o sistema. Estos casos ayudan a detectar errores que normalmente no aparecen al probar solamente situaciones comunes.

## Por que estos casos son importantes

Los casos borde permiten verificar que el programa funcione correctamente con valores extremos, limites exactos y entradas especiales.

Por ejemplo:

- Verificar que 0 sea considerado un numero par.
- Comprobar el comportamiento de cadenas vacias.
- Validar las notas minima y maxima permitidas.
- Revisar los cambios exactos entre categorias de calificacion.

## Comandos ejecutados

```bash
cd build
make
./run_tests
```

## Resultado de las pruebas

Google Test ejecuto todas las pruebas correctamente.

```text
[==========] Running 40 tests from 3 test suites.
[  PASSED  ] 40 tests.
```

## Cantidad de pruebas ejecutadas

- Total de pruebas: 40

## Cantidad de pruebas exitosas

- Pruebas exitosas: 40

## Cantidad de pruebas fallidas

- Pruebas fallidas: 0

## Alguna prueba fallo?

No.

Todas las pruebas pasaron correctamente despues de agregar los nuevos casos borde y restaurar la implementacion correcta de la funcion `is_even`.

---

# Preguntas de Reflexion

## 1. Por que no basta con probar casos normales?

Porque muchos errores aparecen solamente cuando el programa recibe valores extremos o condiciones poco comunes. Probar solo casos normales no garantiza que el sistema funcione correctamente en todas las situaciones.

## 2. Que es un caso borde?

Es una prueba que utiliza valores ubicados en los limites validos de una funcion para verificar que el comportamiento sea correcto en esas condiciones especiales.

## 3. Que es un caso invalido?

Es una entrada que no cumple las condiciones esperadas por el programa. Por ejemplo, una nota negativa o una division entre cero.

## 4. Que diferencia hay entre probar 85 y probar exactamente 80, 90 o 70?

El valor 85 pertenece al interior de un rango. En cambio, 80, 90 y 70 representan limites entre categorias de notas, por lo que son puntos donde suelen aparecer errores de comparacion.

## 5. Como puede un caso borde revelar errores ocultos?

Porque obliga al programa a trabajar con condiciones extremas o limites exactos donde los errores logicos suelen manifestarse con mayor facilidad.


# Semillas en pruebas

## Que se hizo

Se agrego una prueba unitaria utilizando numeros aleatorios controlados mediante una semilla fija para verificar el correcto funcionamiento de la funcion `add()`.

## Archivo modificado

```text
tests/test_calculator.cpp
```

## Prueba agregada

```cpp
TEST(CalculatorTest, RandomAdditionsWithFixedSeed) {
    std::mt19937 generator(12345);
    std::uniform_int_distribution<int> distribution(-100, 100);

    for (int i = 0; i < 10; i++) {
        int a = distribution(generator);
        int b = distribution(generator);

        EXPECT_EQ(add(a, b), a + b);
    }
}
```

## Que hace la semilla

La semilla determina la secuencia de numeros aleatorios que genera el programa. Utilizando la misma semilla siempre se obtiene la misma secuencia de valores.

## Por que se usa una semilla fija

Una semilla fija permite que las pruebas sean reproducibles. Esto significa que cada ejecucion genera exactamente los mismos datos y produce los mismos resultados.

## Que paso al cambiar la semilla

Se cambio temporalmente la semilla de:

```cpp
std::mt19937 generator(12345);
```

a:

```cpp
std::mt19937 generator(54321);
```

Al ejecutar nuevamente las pruebas se generaron numeros diferentes, pero todas las pruebas continuaron pasando correctamente porque la funcion `add()` produce resultados correctos para cualquier par de valores generados.

## Comandos ejecutados

```bash
cd build
make
./run_tests
```

## Resultado de las pruebas

Google Test ejecuto todas las pruebas correctamente.

```text
[==========] Running 41 tests from 3 test suites.
[  PASSED  ] 41 tests.
```

## Cantidad de pruebas ejecutadas

- Total de pruebas: 41

## Cantidad de pruebas exitosas

- Pruebas exitosas: 41

## Cantidad de pruebas fallidas

- Pruebas fallidas: 0

## Por que esto ayuda en debugging

Las semillas fijas permiten reproducir exactamente la misma secuencia de datos aleatorios. Si aparece un error, se puede volver a ejecutar la prueba con la misma semilla para analizar el problema bajo las mismas condiciones.

---

# Preguntas de Reflexion

## 1. Por que las pruebas con datos aleatorios pueden ser peligrosas si no se controlan?

Porque cada ejecucion podria generar datos diferentes y producir resultados distintos, dificultando la reproduccion y el analisis de errores.

## 2. Que ventaja tiene usar una semilla fija?

Permite obtener siempre la misma secuencia de numeros aleatorios, haciendo que las pruebas sean reproducibles y consistentes.

## 3. Como ayuda la semilla a reproducir errores?

Si una prueba falla con una semilla determinada, se puede utilizar nuevamente esa misma semilla para generar exactamente los mismos datos y volver a analizar el error.

## 4. Por que es importante documentar la semilla usada?

Porque permite que otras personas ejecuten las pruebas bajo las mismas condiciones y obtengan los mismos resultados.
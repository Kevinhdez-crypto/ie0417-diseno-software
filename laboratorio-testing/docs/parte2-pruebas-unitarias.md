
# Parte 2
## Modulos creados

Se crearon tres modulos:

### Calculator
Contiene funciones matematicas basicas:

- add()
- subtract()
- multiply()
- divide()
- is_even()

### String Utils
Contiene funciones para procesar texto:

- to_uppercase()
- is_palindrome()
- count_vowels()

### Grade Utils
Contiene funciones para trabajar con notas:

- average()
- is_passing()
- letter_grade()

---

## Funcion de cada archivo .h

### calculator.h
Declara las funciones matematicas del modulo Calculator.

### string_utils.h
Declara las funciones para el manejo de cadenas de texto.

### grade_utils.h
Declara las funciones relacionadas con notas y calificaciones.

---

## Funcion de cada archivo .cpp

### calculator.cpp
Implementa las operaciones matematicas y las validaciones correspondientes.

### string_utils.cpp
Implementa las funciones de procesamiento de texto.

### grade_utils.cpp
Implementa las funciones para calcular promedios y clasificar notas.

---

## Casos normales, borde e invalidos

### Calculator

- Casos normales: suma, resta, multiplicacion y division con numeros validos.
- Casos borde: operaciones con cero.
- Casos invalidos: division entre cero.

### String Utils

- Casos normales: palabras y frases comunes.
- Casos borde: cadena vacia o con espacios.
- Casos invalidos: no se identifican casos invalidos evidentes.

### Grade Utils

- Casos normales: notas dentro del rango permitido.
- Casos borde: notas limite (60, 70, 80, 90, 100).
- Casos invalidos: lista vacia de notas, notas menores que 0 o mayores que 100.

# Parte 3 - Pruebas Unitarias con Google Test

## Comandos usados para compilar

```bash
mkdir build
cd build
cmake ..
make
```

## Comandos usados para ejecutar las pruebas

```bash
./run_tests
ctest --output-on-failure
```

## Resultado de ./run_tests

```text
[==========] Running 25 tests from 3 test suites.
[  PASSED  ] 25 tests.
```

Todas las pruebas fueron ejecutadas exitosamente sin errores.

## Resultado de ctest --output-on-failure

```text
100% tests passed, 0 tests failed out of 25
```

Todas las pruebas registradas por CTest fueron ejecutadas correctamente.

## Cantidad de pruebas ejecutadas

- 25 pruebas

## Cantidad de pruebas exitosas

- 25 pruebas exitosas
- 0 pruebas fallidas

---

# Explicacion de Pruebas Implementadas

## AddPositiveNumbers

Verifica que la funcion `add()` sume correctamente dos numeros positivos.

```cpp
EXPECT_EQ(add(2, 3), 5);
```

## DivideByZeroThrowsException

Verifica que la funcion `divide()` genere una excepcion cuando se intenta dividir entre cero.

```cpp
EXPECT_THROW(divide(10, 0), std::invalid_argument);
```

## DetectPalindromeWithSpaces

Verifica que la funcion `is_palindrome()` reconozca correctamente una frase palindroma aunque contenga espacios.

```cpp
EXPECT_TRUE(is_palindrome("anita lava la tina"));
```

## CountVowels

Verifica que la funcion `count_vowels()` cuente correctamente la cantidad de vocales presentes en una palabra.

```cpp
EXPECT_EQ(count_vowels("murcielago"), 5);
```

## CalculateAverage

Verifica que la funcion `average()` calcule correctamente el promedio de un conjunto de notas.

```cpp
EXPECT_DOUBLE_EQ(average(grades), 90.0);
```

---

# Preguntas de Reflexion

## 1. Que significa que una prueba pase?

Significa que el resultado obtenido coincide con el resultado esperado y la funcion se comporta correctamente para el caso evaluado.

## 2. Que significa que una prueba falle?

Significa que el resultado obtenido no coincide con el resultado esperado o que ocurrio un error durante la ejecucion de la prueba.

## 3. Que diferencia hay entre probar una funcion manualmente y probarla con Google Test?

Las pruebas manuales requieren que el programador ejecute la funcion y verifique los resultados por su cuenta. Con Google Test las verificaciones se realizan automaticamente y los resultados se reportan de forma inmediata.

## 4. Por que las pruebas unitarias deben ser rapidas?

Porque se ejecutan frecuentemente durante el desarrollo y deben proporcionar retroalimentacion inmediata sin ralentizar el trabajo del programador.

## 5. Por que las pruebas unitarias deben ser deterministas?

Porque deben producir siempre el mismo resultado cuando se ejecutan bajo las mismas condiciones, permitiendo detectar errores de forma confiable.

# Parte 4 - EXPECT vs ASSERT

## Que paso cuando divisor era 2

La prueba se ejecuto correctamente. La condicion `ASSERT_NE(divisor, 0)` fue verdadera, por lo que Google Test continuo ejecutando la siguiente instruccion y la division se realizo correctamente.

## Que paso cuando divisor era 0

La prueba fallo porque la condicion `ASSERT_NE(divisor, 0)` no se cumplio. Google Test detecto que el divisor era igual a cero y detuvo inmediatamente la ejecucion de la prueba.

### Resultado obtenido

```text
Expected: (divisor) != (0), actual: 0 vs 0
```

## Por que ASSERT_NE detuvo la prueba

Las instrucciones `ASSERT_` son verificaciones fatales. Cuando una de ellas falla, Google Test detiene la prueba actual para evitar ejecutar codigo que depende de una condicion invalida.

## Diferencia entre EXPECT_ y ASSERT_

### EXPECT_

- Verifica una condicion.
- Si falla, la prueba continua ejecutandose.
- Permite detectar varios errores en una misma prueba.

### ASSERT_

- Verifica una condicion.
- Si falla, la prueba se detiene inmediatamente.
- Se utiliza cuando no tiene sentido continuar ejecutando la prueba.

---

# Preguntas de Reflexion

## 1. Cuando conviene usar EXPECT_?

Conviene usar `EXPECT_` cuando se desea verificar varias condiciones independientes dentro de una misma prueba.

## 2. Cuando conviene usar ASSERT_?

Conviene usar `ASSERT_` cuando una condicion debe cumplirse obligatoriamente antes de continuar con la prueba.

## 3. Que podria pasar si se usa EXPECT_ cuando en realidad se necesitaba detener la prueba?

La prueba podria continuar ejecutando codigo invalido y generar errores adicionales o resultados incorrectos.

## 4. Que podria pasar si se usa ASSERT_ en exceso?

Las pruebas podrian detenerse demasiado pronto y no mostrar otros errores que tambien estaban presentes en el codigo.
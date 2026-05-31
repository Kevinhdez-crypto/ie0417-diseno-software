# Parte 5 - Pruebas fallidas y correccion de errores

## Que se hizo

Se modifico temporalmente la funcion `is_even` para introducir un error intencional y observar como Google Test detecta fallos en el codigo.

## Archivo modificado

```text
src/calculator.cpp
```

## Cambio incorrecto realizado

### Codigo original

```cpp
bool is_even(int number) {
    return number % 2 == 0;
}
```

### Codigo incorrecto

```cpp
bool is_even(int number) {
    return number % 2 == 1;
}
```

## Comandos ejecutados

```bash
cd build
make
./run_tests
```

## Pruebas que fallaron

- CalculatorTest.DetectEvenNumber
- CalculatorTest.DetectOddNumber

## Mensajes de error mostrados por Google Test

### Error en DetectEvenNumber

```text
Value of: is_even(8)
  Actual: false
Expected: true
```

### Error en DetectOddNumber

```text
Value of: is_even(7)
  Actual: true
Expected: false
```

## Que esperaba la prueba

La prueba esperaba que:

- `is_even(8)` devolviera `true` porque 8 es un numero par.
- `is_even(7)` devolviera `false` porque 7 es un numero impar.

## Que obtuvo realmente

La funcion devolvio:

- `is_even(8)` -> `false`
- `is_even(7)` -> `true`

Esto demostro que la logica de la funcion estaba invertida.

## Resultado obtenido

```text
[  PASSED  ] 25 tests.
[  FAILED  ] 2 tests, listed below:

[  FAILED  ] CalculatorTest.DetectEvenNumber
[  FAILED  ] CalculatorTest.DetectOddNumber

2 FAILED TESTS
```

## Correccion realizada

Se restauro la implementacion correcta de la funcion.

```cpp
bool is_even(int number) {
    return number % 2 == 0;
}
```

## Resultado final

Despues de corregir la funcion y ejecutar nuevamente las pruebas, todas las pruebas pasaron correctamente.

---

# Preguntas de Reflexion

## 1. Como ayudo Google Test a identificar el error?

Google Test indico exactamente cuales pruebas fallaron y mostro los valores esperados y obtenidos, facilitando encontrar el problema.

## 2. Que informacion util muestra una prueba fallida?

Muestra el nombre de la prueba, el valor esperado, el valor obtenido y la ubicacion donde ocurrio el error.

## 3. Por que es importante ejecutar pruebas despues de modificar codigo?

Porque permite verificar que los cambios realizados no introduzcan errores en funcionalidades que antes funcionaban correctamente.

## 4. Que riesgo existe si se cambia codigo y no se ejecutan las pruebas?

Los errores pueden pasar desapercibidos y afectar el funcionamiento correcto del programa.
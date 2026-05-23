# Parte 4: Step, Next y Backtrace

## Codigo original

```cpp
#include <iostream>

int dividir(int a, int b) {
    int resultado = a / b;
    return resultado;
}

int calcular(int x) {
    int divisor = x - 5;
    int resultado = dividir(100, divisor);
    return resultado;
}

int main() {
    int valor = 5;
    int respuesta = calcular(valor);

    std::cout << "Respuesta: " << respuesta << std::endl;

    return 0;
}
```

## Comando de compilacion

```bash
g++ -g -o gdb_funciones codigo/04_gdb_funciones.cpp
```

## Comando de ejecucion

```bash
./gdb_funciones
```

## Error observado

El programa compila correctamente, pero al ejecutarlo ocurre un error por division entre cero.

Ejemplo de salida:

```bash
Floating point exception   (core dumped) ./gdb_funciones
```

## Herramienta usada para depurar

GDB (GNU Debugger)

## Uso de gdb

Abrir el programa:

```bash
gdb ./gdb_funciones
```

Comandos ejecutados:

```gdb
break main
run
next
step
step
print x
print divisor
step
print a
print b
backtrace
quit
```

## Analisis del problema

Valores observados:

```gdb
(gdb) print x
$1 = 5

(gdb) print divisor
$2 = 0

(gdb) print a
$3 = 100

(gdb) print b
$4 = 0
```

Se observo que:

- `valor` tenia el valor `5`
- `x` tenia el valor `5`
- `divisor` tenia el valor `0`
- `b` tenia el valor `0`

La funcion `dividir()` recibia:

```cpp
dividir(100,0)
```

lo que provocaba una division entre cero.

## Diferencia entre next y step

`next` ejecuta la siguiente linea sin entrar dentro de una funcion.

`step` ejecuta la siguiente linea entrando dentro de las funciones llamadas.

## Resultado de backtrace

Ejemplo:

```gdb
(gdb) backtrace

#0 dividir(int, int)
#1 calcular(int)
#2 main()
```

La pila de llamadas muestra el orden en que las funciones fueron ejecutadas hasta llegar al error.

## Correccion realizada

Se agrego una validacion para evitar dividir entre cero.

## Codigo corregido

```cpp
#include <iostream>

int dividir(int a, int b) {

    if (b == 0) {
        std::cout << "Error: no se puede dividir entre cero." << std::endl;
        return 0;
    }

    int resultado = a / b;
    return resultado;
}

int calcular(int x) {
    int divisor = x - 5;
    int resultado = dividir(100, divisor);

    return resultado;
}

int main() {
    int valor = 5;
    int respuesta = calcular(valor);

    std::cout << "Respuesta: " << respuesta << std::endl;

    return 0;
}
```

## Evidencia

Compilacion:

```bash
g++ -g -o gdb_funciones codigo/04_gdb_funciones.cpp
```

Ejecucion:

```bash
./gdb_funciones
```

Salida:

```bash
Error: no se puede dividir entre cero.
Respuesta: 0

```

---

## Reflexion

El uso de `gdb` permite identificar con facilidad donde ocurre un error y que valores tienen las variables durante la ejecucion. Esto ayuda a encontrar problemas que normalmente no son visibles solo viendo el resultado final.

---

# Preguntas de reflexion

## 1. Que diferencia observo entre next y step?

`next` avanza linea por linea sin entrar dentro de las funciones, mientras que `step` entra dentro de las funciones y permite observar su ejecucion interna.

## 2. Para que sirve backtrace?

Sirve para mostrar la pila de llamadas y observar el orden en que fueron ejecutadas las funciones.

## 3. Cual fue la causa del error?

La variable `divisor` obtuvo el valor `0`, provocando una division entre cero.

## 4. Por que este error es de tiempo de ejecucion?

Porque el programa compilaba correctamente y el problema aparecia solamente cuando el programa se ejecutaba.

## 5. Como podria prevenirse este tipo de error desde el diseno del programa?

Se pueden validar entradas y condiciones antes de realizar operaciones que puedan producir errores, como divisiones entre cero.
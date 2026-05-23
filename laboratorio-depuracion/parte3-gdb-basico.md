# Parte 3: Introduccion a gdb

## Codigo original

```cpp
#include <iostream>

int duplicar(int x) {
    int resultado = x * 2;
    return resultado;
}

int sumar(int a, int b) {
    int resultado = a + b;
    return resultado;
}

int main() {
    int numero = 5;
    int doble = duplicar(numero);
    int total = sumar(doble, 10);

    std::cout << "Numero: " << numero << std::endl;
    std::cout << "Doble: " << doble << std::endl;
    std::cout << "Total: " << total << std::endl;

    return 0;
}
```

## Comando de compilacion

```bash
g++ -g -o gdb_basico codigo/03_gdb_basico.cpp
```

## Comando de ejecucion

```bash
./gdb_basico
```

## Resultado observado

```bash
Numero: 5
Doble: 10
Total: 20
```

## Herramienta usada para depurar

GDB (GNU Debugger)

## Uso de gdb

Abrir el programa:

```bash
gdb ./gdb_basico
```

Comandos ejecutados:

```gdb
break main
run
next
next
print numero
next
print doble
next
print total
continue
quit
```

## Explicacion de comandos

### Para que sirve -g?

La opcion `-g` agrega simbolos de depuracion al programa compilado para que herramientas como `gdb` puedan mostrar lineas del codigo, variables y funciones durante la ejecucion.

### Que hace break main?

Crea un breakpoint en la funcion `main`, haciendo que la ejecucion se detenga al llegar a ese punto.

### Que hace run?

Inicia la ejecucion del programa dentro de `gdb`.

### Que hace next?

Ejecuta la siguiente linea del programa sin entrar dentro de las funciones llamadas.

### Que hace print?

Muestra el valor actual de una variable.

---

## Valores observados

### Variable numero

```gdb
(gdb) print numero
$1 = 5
```

### Variable doble

```gdb
(gdb) print doble
$2 = 10
```

### Variable total

```gdb
(gdb) print total
$3 = 20
```

---

## Evidencia

Salida observada en gdb:

```gdb
kevin@Kevin07:~/ie0417-diseno-software/laboratorio-depuracion$ gdb ./gdb_basico
GNU gdb (Ubuntu 17.1-2ubuntu1) 17.1
Copyright (C) 2025 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./gdb_basico...
(gdb) break main
Breakpoint 1 at 0x11cb: file codigo/03_gdb_basico.cpp, line 14.
(gdb) run
Starting program: /home/kevin/ie0417-diseno-software/laboratorio-depuracion/gdb_basico 

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>
Enable debuginfod for this session? (y or [n]) n
Debuginfod has been disabled.
To make this setting permanent, add 'set debuginfod enabled off' to .gdbinit.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at codigo/03_gdb_basico.cpp:14
14	    int numero = 5;
(gdb) next
15	    int doble = duplicar(numero);
(gdb) print numero
$1 = 5
(gdb) next
16	    int total = sumar(doble, 10);
(gdb) print doble
$2 = 10
(gdb) next
18	    std::cout << "Número: " << numero << std::endl;
(gdb) print total
$3 = 20
(gdb) continue
Continuing.
Número: 5
Doble: 10
Total: 20
[Inferior 1 (process 6664) exited normally]
(gdb) quit

```

---

## Reflexion

El uso de `gdb` permite observar el comportamiento interno del programa y seguir su ejecucion paso a paso, facilitando la identificacion de errores y la comprension del flujo del programa.



# Preguntas de reflexion

## 1. Que es un breakpoint?

Es un punto de interrupcion que detiene temporalmente la ejecucion del programa para analizar su comportamiento.

## 2. Que diferencia hay entre ejecutar el programa normalmente y ejecutarlo dentro de gdb?

Al ejecutarlo normalmente solo se observa el resultado final. Con `gdb` es posible detener el programa, avanzar paso a paso y revisar variables internas.

## 3. Que ventaja tiene inspeccionar variables mientras el programa se ejecuta?

Permite observar como cambian los valores y ayuda a encontrar errores mas facilmente.

## 4. Por que next no entra dentro de las funciones?

Porque `next` ejecuta una linea completa y continua a la siguiente linea del mismo nivel. Para entrar dentro de una funcion se usa `step`.
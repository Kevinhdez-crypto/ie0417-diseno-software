## 12.5 Documentacion requerida

### Mini reto de testing

# Funcion implementada:
  Se implemento la funcion is_valid_grade(int grade) que valida si una nota esta en el rango de 0 a 100 inclusive.

# Casos de prueba disenados:
  Caso normal valido: un valor dentro del rango (ej: 85)
  Caso normal invalido: un valor fuera del rango (ej: #50 o 150)
  Borde inferior valido: 0
  Borde superior valido: 100
  Debajo del borde inferior: #1
  Encima del borde superior: 101

# Por que se escogieron esos casos:
  Se eligieron para cubrir valores tipicos dentro del rango, errores comunes y valores limite, ya que los bordes suelen ser donde mas fallos ocurren.

# Resultado de las pruebas:
  Todas las pruebas pasaron correctamente:
  Valores entre 0 y 100 retornaron true
  Valores menores a 0 o mayores a 100 retornaron false

# Subida a GitHub:
  Si, los cambios fueron subidos al repositorio usando git add, git commit y git push.

# GitHub Actions:
  El workflow se ejecuto correctamente y todas las pruebas pasaron sin errores.

## 12.6 Preguntas de reflexion

## 1. Cual fue el caso mas obvio de probar?
Un valor normal dentro del rango como 50 o 85.

## 2. Cual fue el caso borde mas importante?
Los limites 0 y 100.

## 3. Que error podria aparecer si no se prueban los valores 0 y 100?
La funcion podria excluir incorrectamente los limites usando > o < en vez de >= o <=.

## 4. Que diferencia hay entre probar 50 y probar #1, 0, 100 y 101?
50 solo valida comportamiento normal, mientras que los otros prueban limites y valores invalidos.

## 5. Que aprendio sobre diseñar pruebas?
Es importante cubrir casos normales, bordes y valores invalidos para asegurar robustez.

# Parte 13: reflexion final

## Reflexion final

## 1. Que es software testing?
Es el proceso de verificar que el software funciona correctamente bajo distintas condiciones.

## 2. Por que el testing mejora la calidad del software?
Porque permite detectar errores antes de produccion.

## 3. Cual es la diferencia entre verificacion y validacion?
Verificacion es comprobar que el codigo cumple especificaciones.
Validacion es comprobar que cumple lo que el usuario necesita.

## 4. Que es una prueba unitaria?
Es una prueba de una funcion o componente individual.

## 5. Que es una prueba funcional?
Es una prueba del comportamiento completo de una funcionalidad.

## 6. Que diferencia hay entre EXPECT_ y ASSERT_?
EXPECT_ permite continuar la prueba si falla, ASSERT_ detiene la ejecucion.

## 7. Por que las pruebas deben ser deterministas?
Para que siempre den el mismo resultado.

## 8. Por que puede ser util una semilla en pruebas con valores aleatorios?
Porque permite reproducir resultados.

## 9. Que es cobertura de codigo?
Es la medida de cuanto codigo es ejecutado por las pruebas.

## 10. Por que una cobertura alta no garantiza ausencia de errores?
Porque pueden existir casos logicos no probados.

## 11. Que ventaja tiene ejecutar pruebas en GitHub Actions?
Permite automatizar pruebas y detectar errores temprano.

## 12. Que parte del laboratorio le parecio mas util?
La automatizacion de pruebas con GitHub Actions.

## 13. Que parte le parecio mas dificil?
El diseno de casos de prueba borde.

## 14. Como aplicaria pruebas automatizadas en un proyecto futuro?
Integrando pruebas unitarias desde el inicio y usando CI/CD.
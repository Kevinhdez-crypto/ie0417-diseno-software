Kevin Hernandez Umana. C33773
Parte 2. Docuementacion en Sphinx.

Herramienta utilizada: 

Para esta práctica se utilizó Sphinx, una herramienta que permite generar documentación en formato HTML a partir de código fuente en Python, aprovechando los docstrings definidos en las funciones.

Objetivo:

El objetivo fue generar documentación navegable en HTML para un proyecto en Python, asegurando que se incluyeran módulos, funciones y descripciones claras del código.

Procedimiento realizado:

    Se partió de un repositorio que contenía un archivo en Python con funciones definidas (.py).

    Se inicializó Sphinx dentro del proyecto utilizando:

    Comando utilizado: "sphinx-quickstart docs"

    Se configuró el archivo conf.py para permitir que Sphinx reconociera el código del proyecto:

    Se agregó la ruta del proyecto al sistema:

import os
import sys
sys.path.insert(0, os.path.abspath('../../'))

    Se habilitó la extensión necesaria para documentar código automáticamente:

extensions = ['sphinx.ext.autodoc']

    Se creó un archivo .rst correspondiente al módulo del proyecto, donde se indicó a Sphinx que debía documentar automáticamente el contenido del archivo Python:

    Comando utilizado:  .. automodule:: nombre_del_modulo
                            :members:
 
    Se configuró el archivo index.rst para incluir el módulo dentro de la documentación generada mediante un toctree.

    Se generó la documentación en HTML ejecutando:

cd docs
make clean
make html

    Finalmente, se abrió la documentación generada en el navegador para verificar su funcionamiento y estructura.


Problemas encontrados y soluciones

Durante el desarrollo de la práctica se presentaron diversos problemas, los cuales fueron resueltos de la siguiente manera:
*Error: Unknown directive type "automodule"

Causa:
La extensión autodoc no estaba habilitada en el archivo conf.py.

Solución:
Se agregó la siguiente línea:

extensions = ['sphinx.ext.autodoc']

*Error: No module named 'nombre_del_modulo'

Causa:
Sphinx no encontraba el archivo .py dentro del proyecto.

Solución:
Se configuró correctamente la ruta en conf.py:

sys.path.insert(0, os.path.abspath('../../'))

*Problemas con generación de HTML

Causa:
Configuraciones previas o caché de Sphinx.

Solución:
Se utilizó:

make clean
make html

*Problemas con el despliegue en Netlify

Causa:
Se intentó subir una carpeta incorrecta.

Solución:
Se subió únicamente la carpeta:

docs/build/html

*Problemas para visualizar la documentación:

Causa:
Dificultades al abrir el archivo HTML desde la máquina virtual.

Solución:
Se abrió directamente el archivo index.html desde el navegador o se utilizó un servidor local.


Evidencia de la documentación generada:

En esta sección se muestran capturas de pantalla de:

    La página principal de la documentación generada

    La sección donde se visualizan los módulos y funciones documentadas




Publicación de la documentación:

La documentación generada fue desplegada en línea utilizando una plataforma de hosting estático, permitiendo su acceso desde cualquier navegador.



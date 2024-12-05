# How build the project

----

1. Compilar libreria de C y archivos independientes con:
```bash
mingw32-make
```
El compilador que se uso es `tdm-gcc`, aunque en teoqria deberia funcionar con cualquier compilador derivado de `mingw`.

2. Compilar archivos de `src` via CPython con:
```bash
python setup.py install
```
Posiblemente deba instalar el compilador `VS` de C/C++ para que esto sea posible.
tambien puede usar:
```bash
python setup.py build_ext --inplace
```

3. generar archivo distribuible con:
```bash
python setup.py sdist
```
Esto debera generar un archivo .tar.gz con el nombre del proyecto el cual contenga todo.

Una vez generado el archivo distribuible, se puede instalar con:
```bash
pip install dist/CCN_lib-1.0.0.tar.gz
```

Si casualmente necesitara forzar la instalacion por que ya tiene una version instalada u otro motivo:
```bash
pip install --force-reinstall --ignore-installed dist/CCN_lib-1.0.0.tar.gz
```

----
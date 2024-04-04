# Trabajo Práctico Número 4

## Uso del repositorio

Este repositorio utiliza las siguientes herramientas:

1. [clang-format] () para el mantenimiento del formato del código escrito en lenguaje C
1. [pre-commit](https://pre-commit.com) para validaciones generales de formato del repositorio
1. [ceedling]() para ejecutar las pruebas unitarias en forma automatizada
1. [lcov]() para generar los informes de cobertura de las pruebas unitarias

Después de clonar el repositorio base,usted debería ejecutar el siguiente comando:

```
pre-commit install
git add .
pre-commit
git commit -m "lo que se desee comentar"
git push origin main
```

Dentro del repositorio base se tiene:
- inc
- src
- .clang-format
- .gitignore
- .pre-commit-config.yaml
- doxyfile
- LICENSE.txt
- makefile
- README.md

Se debe instalar ruby, gocv y ceedling
'''
sudo apt-get install ruby cogv
sudo gem install ceedling
sudo apt install gcovr
'''
Se instala gcovr si al tipear gcovr --version, nos muestra como comando desconocido.

Ahora iniciamos un nuevo proyecto ceedling, es importante no tener creado la carpeta test y tampo tener el archivo project.yml.
```
ceedling new .
```

Para ejecutar las pruebas unitarias se utiliza el siguiente comando:

```
ceedling test:all
```

Para generar el informe de cobertura de las pruebas se utiliza el siguiente comando:

```
ceedling clobber gcov:all utils:gcov
```

Para generar la documentación del proyecto se utiliza el siguiente comando:

```
make doc

```

Para compilar el proyecto se utiliza el siguiente comando:

```
make all

```
Prueba para hacer pull request.

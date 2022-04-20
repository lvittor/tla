[![✗](https://img.shields.io/badge/Release-v0.1.0-ffb600.svg?style=for-the-badge)](https://github.com/agustin-golmar/Flex-Bison-Compiler/releases)

# Flex/Bison Compiler

An empty compiler built with Flex and Bison.

## Requirements

In order to build the compiler, there are some necesary dependencies:

* [Bison v3.8.2](https://www.gnu.org/software/bison/)
* [CMake v3.22.2](https://cmake.org/)
* [Flex v2.6.4](https://github.com/westes/flex)
* [GCC v11.1.0](https://gcc.gnu.org/)
* [Make v4.3](https://www.gnu.org/software/make/)

## Construction

For more details regarding the construction of the project, you can see our [docs](docs/) directory

## Ejecución

After having followed our construction documentation, before runing the project, you should create the directory out_compiler in the root or the project.
After doing so, the only thing left to do is to call the function:
```
compile
```

The result of all the use cases detailed inside the examples directory will be redirected to the folder out_compiler.

## Visualization

You can also have a visual representation of the grammar used in our work by adding and runing the alias ```graph``` specified in our [build doc][docs/build.md].

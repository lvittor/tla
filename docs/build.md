# Building the compiler

```bash
cmake -S . -B bin                       # build the compiler
cd bin && make clean && make && cd ..   # run make all
cat examples/program | bin/Compiler     # run the compiler
```
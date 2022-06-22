# Building the compiler

```bash
compile(){
rm -rf bin/
cmake -S . -B bin                       # build the compiler
cd bin && make clean && make && cd ..   # run make all
fs=`ls examples/`
for f in $fs
do
    cat examples/$f | bin/Compiler  > out_compiler/$f 2>&1      # run the compiler
done
}
```
```bash
alias c="
rm -rf bin/
rm src/frontend/lexical-analysis/flex-scanner.c src/frontend/syntactic-analysis/bison-parser.*
cmake -S . -B bin                       # build the compiler
cd bin && make clean && make && cd ..   # run make all
cat examples/r1-1 | bin/Compiler        # run the compiler
"
```

## Generate the state graph

```bash
alias graph="
bison -o out/ex.tab.c --report=all -g src/frontend/syntactic-analysis/bison-grammar.y
dot -Tpng -oex.png out/ex.dot
mv ex.png out/
"
```

## Compile generated code with libraries
```bash
alias gen="
cd target
rm *.o
gcc -c program.c ../src/backend/domain-specific/stat-functions.c ../src/backend/domain-specific/z-index-table.c ../src/backend/domain-specific/input-reader.c
gcc stat-functions.o z-index-table.o input-reader.o program.o -o program -lm
"

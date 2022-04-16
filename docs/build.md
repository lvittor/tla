# Building the compiler

```bash
alias compile="
rm -rf bin/
cmake -S . -B bin                       # build the compiler
cd bin && make clean && make && cd ..   # run make all
cat examples/r1-6 | bin/Compiler        # run the compiler
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
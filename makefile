funcAnalys: dMenuFuncAnalys.o uiMenuFuncAnalys.o feFuncAnalys.o beFuncAnalys.o
	gcc -Wall -lrt -o funcAnalys dMenuFuncAnalys.c uiMenuFuncAnalys.o feFuncAnalys.o beFuncAnalys.o
dMenuFuncAnalys.o: dMenuFuncAnalys.c uiMenuFuncAnalys.h feFuncAnalys.h 
	gcc -c dMenuFuncAnalys.c 
uiMenuFuncAnalys.o: uiMenuFuncAnalys.c
	gcc -c uiMenuFuncAnalys.c
feFuncAnalys.o: feFuncAnalys.c 
	gcc -c feFuncAnalys.c
beFuncAnalys.o: beFuncAnalys.c
	gcc -c beFuncAnalys.c
clean: 
	rm *.o
test: funcAnalys
	./funcAnalys
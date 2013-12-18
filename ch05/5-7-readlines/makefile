name = readlines

all:

	gcc -o main.out main.c readlines.c qsort.c alloc.c
	./main.out <${name}.input.txt

test:

	gcc -o ${name}.test.out ${name}.test.c ${name}.c alloc.c
	./${name}.test.out <${name}.input.txt
	rm ${name}.test.out
	
	gcc -o qsort.test.out qsort.test.c qsort.c alloc.c
	./qsort.test.out
	rm qsort.test.out

	

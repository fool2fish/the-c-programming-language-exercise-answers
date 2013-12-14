output = calculator.out

all:
	gcc -o ${output} main.c

run:
	./${output}

test:
	gcc -o getop.out ./src/getop.c ./src/getch.c ./tests/getop.test.c
	./getop.out <./tests/getop.input.txt
	rm ./getop.out
	gcc -o isnumfmt.out ./src/isnumfmt.c ./tests/isnumfmt.test.c
	./isnumfmt.out
	rm ./isnumfmt.out


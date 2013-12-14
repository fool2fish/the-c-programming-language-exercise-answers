output = calculator.out

all:

	gcc -o ${output} main.c getch.c getop.c isnumfmt.c stack.c

run:

	./${output}

test:

	gcc -o getop.out getop.c getch.c tests/getop.test.c
	./getop.out <tests/getop.input.txt
	rm getop.out

	gcc -o isnumfmt.out isnumfmt.c tests/isnumfmt.test.c
	./isnumfmt.out
	rm isnumfmt.out

	gcc -o stack.out stack.c tests/stack.test.c
	./stack.out
	rm stack.out
	
	gcc -o getline2.out getline2.c tests/getline2.test.c
	./getline2.out <tests/getline2.input.txt
	rm getline2.out

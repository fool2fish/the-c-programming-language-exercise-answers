output = calculator.out

all:

	gcc -o ${output} main.c getop.c isnumfmt.c stack.c getline2.c
	./${output}

test:

	gcc -o getline2.out getline2.c tests/getline2.test.c
	./getline2.out <tests/getline2.input.txt
	rm getline2.out

	gcc -o getop.out getop.c getch.c tests/getop.test.c
	./getop.out
	rm getop.out

	gcc -o isnumfmt.out isnumfmt.c tests/isnumfmt.test.c
	./isnumfmt.out
	rm isnumfmt.out

	gcc -o stack.out stack.c tests/stack.test.c
	./stack.out
	rm stack.out
	

test:

	gcc -o isnumfmt.out isnumfmt.c tests/isnumfmt.test.c
	./isnumfmt.out
	rm isnumfmt.out

	gcc -o stack.out stack.c tests/stack.test.c
	./stack.out
	rm stack.out
	
	gcc -o calculate.out calculate.c isnumfmt.c stack.c tests/calculate.test.c
	./calculate.out 2 3 4 + '*'
	rm calculate.out
	

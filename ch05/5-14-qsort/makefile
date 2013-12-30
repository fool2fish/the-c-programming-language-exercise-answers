run:

	gcc main.c getlines.c cmp.c qsort2.c swap.c
	./a.out <main.input.txt
	./a.out -r <main.input.txt
	./a.out -f <main.input.txt
	./a.out -fr <main.input.txt
	./a.out -n <main.input.txt
	./a.out -nr <main.input.txt
	rm a.out
	
test:

	gcc swap.test.c swap.c
	./a.out
	rm a.out
	
	gcc cmp.test.c cmp.c
	./a.out
	rm a.out
	
	gcc getlines.test.c getlines.c
	./a.out <getlines.input.txt
	rm a.out
	
	gcc qsort2.test.c qsort2.c cmp.c swap.c
	./a.out
	rm a.out

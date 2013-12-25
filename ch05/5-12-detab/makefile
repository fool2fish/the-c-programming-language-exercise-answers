name = main.entab.out

run:
	
	gcc -o ${name} main.c entab.c settab.c tabpos.c
	./${name} -2 +8 <entab.input.txt
	rm ${name}
name = main.detab.out

run:
	gcc -o ${name} main.detab.c detab.c settab.c tabpos.c
	./${name} 4 8 16 32 <detab.input.txt
	rm ${name}
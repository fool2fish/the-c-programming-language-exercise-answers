name = main.detab.out
name2 = maiin.entab.out

run:
	gcc -o ${name} main.detab.c detab.c settab.c tabpos.c
	./${name} 4 8 16 32 <detab.input.txt
	rm ${name}
	
	gcc -o ${name2} main.entab.c entab.c settab.c tabpos.c
	./${name2} <entab.input.txt
	rm ${name2}
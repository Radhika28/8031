project: main.o minipro1.o
	cc main.o minipro1.o -o project
main.o: main.c pro.h
	cc -Wall -c main.c
minipro1.o: minipro1.c pro.h 
	cc -Wall -c minipro1.c 




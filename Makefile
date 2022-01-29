all: programa.exe

.PHONY: all clear
	clean : rm *.o

programa.exe : main.o funcoes.o
	gcc -o main.exe main.o funcoes.o -lm

funcoes.o: funcoes.c
	gcc -c funcoes.c

main.o: main.c funcoes.h
	gcc -c main.c

clean: 
	rm *.o

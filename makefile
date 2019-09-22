CC = gcc
CFLAGS = -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0

compile: cola.c minipruebas_cola.c
	$(CC) $(CFLAGS) *.c -o cola_ne -g 

cola: compile
	clear
	./cola_ne

valgrind: compile
	clear
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./cola_ne

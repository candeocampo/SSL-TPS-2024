CC = gcc
CFLAGS = -g -Wall -c -pedantic-errors -std=c2x

.PHONY: clean run

# Objetivo principal
prog: main.o tabla.o conversion.o
	$(CC) main.o tabla.o conversion.o -o prog

# Reglas para compilar
main.o: main.c tabla.h
	$(CC) $(CFLAGS) main.c -o main.o

tabla.o: tabla.c tabla.h conversion.h
	$(CC) $(CFLAGS) tabla.c -o tabla.o

conversion.o: conversion.c conversion.h
	$(CC) $(CFLAGS) conversion.c -o conversion.o

clean:
	rm -f main.o tabla.o conversion.o prog

run: prog
	./prog

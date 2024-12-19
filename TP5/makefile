CC = gcc
CFLAGS = -g -Wall -pedantic-errors -D_GNU_SOURCE -Wno-switch -std=c2x
LEX = flex
YACC = bison -d

TARGET = programa.exe

$(TARGET): main.o parser.o scanner.o
	$(CC) main.o parser.o scanner.o -o $(TARGET) -L/usr/lib/ -lfl

main.o: main.c parser.h scanner.h
	$(CC) $(CFLAGS) -c main.c

parser.o: parser.c
	$(CC) $(CFLAGS) -c parser.c

parser.c parser.h: parser.y
	$(YACC) parser.y

scanner.o: scanner.c
	$(CC) $(CFLAGS) -c scanner.c

scanner.c scanner.h: scanner.l
	$(LEX) -o scanner.c scanner.l

clean:
	del /Q main.o parser.o scanner.o parser.c parser.h scanner.c scanner.h $(TARGET)


CC = gcc
CFLAGS = -g -Wall -pedantic-errors -D_GNU_SOURCE -Wno-switch -std=c2x
LEX = flex
YACC = bison -d

TARGET = transpiler.exe

$(TARGET): main.o parser.o scanner.o symbol.o semantic.o
	$(CC) main.o parser.o scanner.o symbol.o semantic.o -o $(TARGET) -lfl

main.o: main.c parser.h scanner.h semantic.h
	$(CC) $(CFLAGS) -c main.c

parser.o: parser.c
	$(CC) $(CFLAGS) -c parser.c

parser.c parser.h: parser.y
	$(YACC) parser.y

scanner.o: scanner.c
	$(CC) $(CFLAGS) -c scanner.c

scanner.c scanner.h: scanner.l
	$(LEX) -o scanner.c scanner.l

symbol.o: symbol.c symbol.h
	$(CC) $(CFLAGS) -c symbol.c

semantic.o: semantic.c semantic.h
	$(CC) $(CFLAGS) -c semantic.c

clean:
	rm -f *.o parser.c parser.h scanner.c scanner.h $(TARGET)


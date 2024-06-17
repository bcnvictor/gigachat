# Makefile
CC = gcc
CFLAGS = -Wall -Wextra

SRC = main.c socketutils.c
OBJ = main.o socketutils.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

socketutils.o: socketutils.c
	$(CC) $(CFLAGS) -c socketutils.c -o socketutils.o

.PHONY: clean

clean:
	${RM} ${OBJ}
	${RM} main

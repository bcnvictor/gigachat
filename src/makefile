# Makefile
CC = gcc
CFLAGS = -Wall -Wextra -I../header

CLIENT_SRC = client.c socketutils.c
SERVER_SRC = server.c socketutils.c serverutils.c

CLIENT_OBJ = client.o socketutils.o
SERVER_OBJ = server.o socketutils.o serverutils.o

all: client server

client: $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o client $(CLIENT_OBJ)

server: $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o server $(SERVER_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) client server

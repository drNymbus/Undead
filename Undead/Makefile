CC = gcc
CFLAGS = -O2 -Wall -std=c99
LDFLAGS = -lgame -L .

all : undead_text

libgame.a : game.o game_io.o
	ar rcs libgame.a game.o game_io.o

undead_text.o : undead_text.c game.h game_io.h

undead_text : undead_text.o libgame.a
	$(CC) $(CFLAGS) -o undead_text undead_text.o $(LDFLAGS)

.PHONY = clean
clean :
	rm -f undead_text undead_text.o libgame.a

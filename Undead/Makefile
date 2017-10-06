CC = gcc
CFLAGS = -O2 -Wall -std=c99
LDFLAGS = -lgame -L .

OBJ = view.o prompt.o

all : undead_text

view.o : view.c view.h game.h
prompt.o : prompt.c prompt.h game.h

libgame.a : game.o game_io.o $(OBJ)
	ar rcs libgame.a game.o game_io.o $(OBJ)

undead_text.o : undead_text.c game.h game_io.h view.h prompt.h

undead_text : undead_text.o libgame.a
	$(CC) $(CFLAGS) -o undead_text undead_text.o $(LDFLAGS)

.PHONY = clean
clean :
	rm -f undead_text undead_text.o libgame.a view.o prompt.o

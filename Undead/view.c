#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "game.h"
#include "game_io.h"


void print_monster(content monster){
  switch(monster){
    case MIRROR:
      printf("/");
      break
    case ANTIMIRROR:
      printf("\\");
      break
    case GHOST:
      printf("G");
      break
    case ZOMBIE:
      printf("Z");
      break
    case VAMPIRE:
      printf("V");
      break
    default:
      printf(" ");
      break
  }
}

void print_game(game g){
  for(uint i=0; i <= 5; i++){
    if(i == 0 || i == 5){
      printf("|");
    }
    for(uint j=4; j >= 0; j++){
      content pos = get_content(g, i, j);
      print_monster(pos);
    }
    if(i % 5 == 0){
      printf("\n");
    }
  }
}

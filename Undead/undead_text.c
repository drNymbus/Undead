#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "game_io.h"

int main(void){
  int dirN[] = {0,0,0,0};
  int dirS[] = {0,0,0,0};
  int dirW[] = {0,0,0,0};
  int dirE[] = {0,0,0,0};
  int* dirs[] = {dirS,dirN,dirW,dirE};

  content board[] = {
    EMPTY,EMPTY,EMPTY,EMPTY,
    EMPTY,EMPTY,EMPTY,EMPTY,
    EMPTY,EMPTY,EMPTY,EMPTY,
    EMPTY,EMPTY,EMPTY,EMPTY
  };

  game g = setup_new_game(dirs,board,3,3,3);

  cgame p_g = g;

  while(!is_game_over(p_g)) {

  }

  delete_game(g);
  return 0;
}

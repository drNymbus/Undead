#include <stdio.h>
#include <stdlib.h>

#include "game.h"
//#include "game_io.h"

#include "view.h"

void print_content(content monster){
  switch( monster ){
    case ZOMBIE:
      printf("Z");
      break;
    case GHOST:
      printf("G");
      break;
    case VAMPIRE:
      printf("V");
      break;
    case MIRROR:
      printf("/");
      break;
    case ANTIMIRROR:
      printf("\\");
      break;
    case EMPTY:
      printf(" ");
      break;
  }
}

void print_board(game g){

  content monsters[] = {GHOST, VAMPIRE, ZOMBIE};

  printf("|    ");
  for(int i=0; i < 3; i++) {
    if(i == 0)
      printf("G:");
    if(i == 1)
      printf("V:");
    if(i == 2)
      printf("Z:");

    printf("%d ", required_nb_monsters(g, monsters[i]));
  }
  printf("  |\n");

  printf("|  ");
  for(uint i=0; i < NB_COLUMN; i++) {
    printf("   ");
  }
  printf("    |\n");

  for(int i=NB_LINE+1; i >= 0; i--) {
    if(i%5 == 0) {
      printf("|   ");
      for(uint j=0; j < NB_COLUMN; j++) {
        if(i == 0) {
          printf(" %d ", required_nb_seen( g, S, j ));
        } else {
          printf(" %d ", required_nb_seen( g, N, j ));
        }
      }
      printf("   |\n");

    } else {
      printf("|%d  ", required_nb_seen( g, W, i-1 ));
      for(uint j=0; j < NB_COLUMN; j++) {
        printf(" ");
        print_content( get_content(g, j, i-1) );
        printf(" ");
      }
      printf("  %d|\n", required_nb_seen( g, E, i-1 ));
    }

  }

  printf("|  ");
  for(int i=0; i < NB_COLUMN; i++) {
    printf("   ");
  }
  printf("    |\n\n");

}

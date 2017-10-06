#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "game.h"
#include "game_io.h"
#include "view.h"
#include "prompt.h"

int main(void){

  bool display = false;
  char* command = malloc(6*sizeof(char));

  int dirN[] = {1,0,0,1};
  int dirS[] = {0,1,1,0};
  int dirW[] = {2,0,0,2};
  int dirE[] = {0,2,2,0};
  int* dirs[] = {dirN,dirS,dirE,dirW};

  content board[] = {
    EMPTY,EMPTY,EMPTY,EMPTY,
    EMPTY,EMPTY,EMPTY,EMPTY,
    EMPTY,EMPTY,EMPTY,EMPTY,
    EMPTY,EMPTY,EMPTY,EMPTY
  };

  //game g = new_game();

  game g = setup_new_game(dirs,board,3,3,3);

  add_mirror(g, 0, 3, 3);
  add_mirror(g, 0, 3, 1);
  add_mirror(g, 1, 0, 3);
  add_mirror(g, 1, 0, 2);
  add_mirror(g, 1, 0, 0);
  add_mirror(g, 1, 2, 1);
  add_mirror(g, 1, 3, 0);


  //game* p_g = &g;

// displaying board game before asking move
  printf("Display ....\n\n");
  print_board(g);

  while(!is_game_over(g)) {

// reading command entered
    ask_command(command);
// executing command entered
    display = exec_command(g, command);
    printf("%s\n", command);
// displaying board game if move is "valid"
    if( display )
      print_board(g);


  }

  free(command);

  delete_game(g);
  return 0;
}

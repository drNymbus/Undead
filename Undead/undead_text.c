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

  int dirN[] = {0,3,3,0};
  int dirS[] = {0,3,2,3};
  int dirW[] = {0,2,3,3};
  int dirE[] = {0,0,3,2};
  int* dirs[] = {dirN,dirS,dirE,dirW};

  content board[] = {
    ANTIMIRROR,EMPTY,EMPTY,ANTIMIRROR,
    EMPTY,EMPTY,ANTIMIRROR,MIRROR,
    ANTIMIRROR,EMPTY,EMPTY,EMPTY,
    ANTIMIRROR,EMPTY,EMPTY,MIRROR
  };

  int nb_zombie = 5, nb_ghost = 2, nb_vampire = 2;
  game g = setup_new_game(dirs,board,nb_zombie,nb_ghost,nb_vampire);

  add_mirror(g, 0, 3, 3);
  add_mirror(g, 0, 3, 1);
  add_mirror(g, 1, 0, 3);
  add_mirror(g, 1, 0, 2);
  add_mirror(g, 1, 0, 0);
  add_mirror(g, 1, 2, 1);
  add_mirror(g, 1, 3, 0);

  /*  Autre version fonctionnel
initialisee avec les fonctions de game.h

    game g = new_game();

    add_mirror(g, 0, 3, 3);
    add_mirror(g, 0, 3, 1);
    add_mirror(g, 1, 0, 3);
    add_mirror(g, 1, 0, 2);
    add_mirror(g, 1, 0, 0);
    add_mirror(g, 1, 2, 1);
    add_mirror(g, 1, 3, 0);

    for(int i=0; i < 4; i++) set_required_nb_seen(g, N, i, dirN[i]);
    for(int i=0; i < 4; i++) set_required_nb_seen(g, S, i, dirS[i]);
    for(int i=0; i < 4; i++) set_required_nb_seen(g, E, i, dirE[i]);
    for(int i=0; i < 4; i++) set_required_nb_seen(g, W, i, dirW[i]);

    set_required_nb_monsters(g, ZOMBIE,  5);
    set_required_nb_monsters(g, VAMPIRE, 2);
    set_required_nb_monsters(g, GHOST,   2);
  */

// displaying board game before asking move
  printf("Display ....\n\n");
  print_board(g);

  while( !is_game_over(g) ) {

// reading command entered
    ask_command(command);
// Test if command well entered before executing command entered
    command = check_command(command);
    display = exec_command(g, command);
// displaying board game if move is "valid"
    if( display )
      print_board(g);

  }

  printf("YOU WIN\n");
  printf("GAME OVER\n");

  free(command);

  delete_game(g);
  return 0;
}

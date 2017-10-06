#include <stdio.h>
#include <stdlib.h>
//#include <std.h>

#include "game.h"
//#include "game_io.h"
#include "prompt.h"

void ask_command(char* command) {

  printf("Enter your command, following the scheme :\n");
  printf("<COLUMN> <LINE> <G|V|Z>  (!put a space between each command!)\n\n");

  fgets(command, 7, stdin);

  if(command == NULL) {
    fprintf(stderr, "Not enough memory\n");
    fprintf(stderr, "Or bad command entered\n");
    exit(EXIT_FAILURE);

  }
}

bool exec_command(game g, char* command) {
  if(command == NULL){
    return false;
  }

  content monster = EMPTY;
  char m = command[0];
  switch( m ) {
    default:  monster = EMPTY;
    break;
    case 'G': monster = GHOST;
      break;
    case 'V': monster = VAMPIRE;
      break;
    case 'Z': monster = ZOMBIE;
      break;
  }

  int col = command[2] - '0';
  int lin = command[4] - '0';

  bool in_board = false;
  if( monster != EMPTY ) {
    in_board = add_monster(g, monster, col, lin);
  } else {
    printf("\nCommand not recognized\n");
    return false;
  }

  if( in_board ) {
    printf("\n");
    return true;
  }
  printf("YOU CANNOT PLACE MONSTER THERE !\n\n");
  printf("\n");
  return false;

}

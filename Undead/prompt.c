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

char* check_command(char* command) {
  if((int)command[0] < 48 || (int)command[0] > 57) {
    printf("Invalid column index\n");
    return NULL;

  } else if((int)command[2] < 48 || (int)command[2] > 57) {
    printf("Invalid line index\n");
    return NULL;

  } else if(command[4] != 'Z' && command[4] != 'G' && command[4] != 'V') {
    if(command[4] != 'z' && command[4] != 'g' && command[4] != 'v') {
      printf("Monster not recognized\n");
      return NULL;
    }
    command[4] = command[4] + ('A'-'a');
  }

  if((int)command[1] != 32 || (int)command[3] != 32) {
    printf("Spaces not respected\n");
    return NULL;
  }

  return command;
}

bool exec_command(game g, char* command) {
  if(command == NULL)
    return false;

  content monster = EMPTY;
  char m = command[4];
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

  int col = command[0] - '0';
  int lin = command[2] - '0';

  bool in_board = add_monster(g, monster, col, lin);

//test if command has been realized
  if( in_board ) {
    printf("\n");
    return true;
  }
  printf("YOU CANNOT PLACE MONSTER THERE !\n\n");
  printf("\n");
  return false;

}

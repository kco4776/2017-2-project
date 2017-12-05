#include "struct.h"

int main(void) {
  int movie_serial = 1;
  int director_serial = 1;
  int actor_serial = 1;
  link *data;
  data = (link *)malloc(sizeof(link));
  data->mv = NULL;
  data->act = NULL;
  data->dir = NULL;

  char *command;
  command = (char *)calloc(100, sizeof(char));
  char *secondcommand;
  secondcommand = (char *)calloc(100, sizeof(char));
  char *tokenstring;
  tokenstring = (char *)calloc(100, sizeof(char));

  printf(">> Welcome to My Movie <<\n");
  printf("File Loading.....\n");
  loading(data);
  printf("You can use add, update, delete, search, sort, save, end commands.\n");
  do {
    printf("(movie) ");
    fgets(command, 100, stdin);

    if(!strcmp(command, "add m\n")) {
      add_m(movie_serial);
      free(command);
      command = (char *)calloc(50, sizeof(char));

    }
    else if(!strcmp(command, "add d\n")) {
      add_d(director_serial);
      free(command);
      command = (char *)calloc(50, sizeof(char));

    }
    else if(!strcmp(command, "add a\n")) {
      add_a(actor_serial);
      free(command);
      command = (char *)calloc(50, sizeof(char));
    }
    else if(!strcmp(secondcommand, "print m")) {
      tokenstring = strtok(command, " ");
      tokenstring = strtok(NULL, " ");
      tokenstring = strtok(NULL, " ");
      print_m(data, tokenstring);
      free(command);
      free(secondcommand);
      free(tokenstring);
      command = (char *)calloc(50, sizeof(char));
      secondcommand = (char *)calloc(100, sizeof(char));
      tokenstring = (char *)calloc(100, sizeof(char));
    }
    else if(!strcmp(secondcommand, "print d")) {
      tokenstring = strtok(command, " ");
      tokenstring = strtok(NULL, " ");
      tokenstring = strtok(NULL, " ");
      print_d(data, tokenstring);
      free(command);
      free(secondcommand);
      free(tokenstring);
      command = (char *)calloc(50, sizeof(char));
      secondcommand = (char *)calloc(100, sizeof(char));
      tokenstring = (char *)calloc(100, sizeof(char));
    }
    else if(!strcmp(secondcommand, "print a")) {
      tokenstring = strtok(command, " ");
      tokenstring = strtok(NULL, " ");
      tokenstring = strtok(NULL, " ");
      print_a(data, tokenstring);
      free(command);
      free(secondcommand);
      free(tokenstring);
      command = (char *)calloc(50, sizeof(char));
      secondcommand = (char *)calloc(100, sizeof(char));
      tokenstring = (char *)calloc(100, sizeof(char));
    }
  } while(strcmp(command, "end\n"));

  return 0;
}

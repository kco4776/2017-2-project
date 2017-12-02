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

  printf(">> Welcome to My Movie <<\n");
  printf("File Loading.....\n");
  init_movie(data);
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
  } while(strcmp(command, "end\n"));

  return 0;
}

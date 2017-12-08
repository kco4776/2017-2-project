#include "struct.h"

int main(void) {
  link *data;
  data = (link *)malloc(sizeof(link));
  data->mv = NULL;
  data->act = NULL;
  data->dir = NULL;

  char *command;
  command = (char *)calloc(100, sizeof(char));

  printf(">> Welcome to My Movie <<\n");
  printf("File Loading.....\n");
  loading(data);
  printf("You can use add, update, delete, search, sort, save, end commands.\n");
  do {
    printf("(movie) ");
    fgets(command, 100, stdin);

    if(!strcmp(command, "add m\n")) {
      add_m(data);
      free(command);
      command = (char *)calloc(50, sizeof(char));

    }
    else if(!strcmp(command, "add d\n")) {
      add_d(data);
      free(command);
      command = (char *)calloc(50, sizeof(char));

    }
    else if(!strcmp(command, "add a\n")) {
      add_a(data);
      free(command);
      command = (char *)calloc(50, sizeof(char));
    }
    else if(!strncmp(command, "delete m", 8)) {
      
    }
  } while(strcmp(command, "end\n"));

  return 0;
}

#include "struct.h"

void add_m(link *data) {
  FILE *movie_log = fopen("movie_log", "a");

  char *string;
  string = (char *)calloc(100, sizeof(char));

  fprintf(movie_log, "add:%d:", count_serial(data, 1)+1);
  printf("title > ");
  fgets(get_data(string), 100, stdin);
  fprintf(movie_log, "%s:", delete_null(string));
  printf("genre > ");
  fgets(get_data(string), 100, stdin);
  fprintf(movie_log, "%s:", delete_null(string));
  printf("director > ");
  fgets(get_data(string), 100, stdin);
  fprintf(movie_log, "%s:", delete_null(string));
  printf("year > ");
  fgets(get_data(string), 100, stdin);
  fprintf(movie_log, "%s:", delete_null(string));
  printf("time > ");
  fgets(get_data(string), 100, stdin);
  fprintf(movie_log, "%s:", delete_null(string));
  printf("actor > ");
  fgets(get_data(string), 100, stdin);
  fprintf(movie_log, "%s\n", delete_null(string));
  loading(data);
}

void add_d(link *data) {
  FILE *director_log = fopen("director_log", "a");

  char *string;
  string = (char *)calloc(100, sizeof(char));

  fprintf(director_log, "add:%d:", count_serial(data, 2)+1);
  printf("name > ");
  fgets(get_data(string), 100, stdin);
  fprintf(director_log, "%s:", delete_null(string));
  printf("sex > ");
  fgets(get_data(string), 100, stdin);
  fprintf(director_log, "%s:", delete_null(string));
  printf("birth > ");
  fgets(get_data(string), 100, stdin);
  fprintf(director_log, "%s:", delete_null(string));
  printf("best_movies > ");
  fgets(get_data(string), 100, stdin);
  fprintf(director_log, "%s\n", delete_null(string));
  loading(data);
}

void add_a(link *data) {
  FILE *actor_log = fopen("actor_log", "a");

  char *string;
  string = (char *)calloc(100, sizeof(char));

  fprintf(actor_log, "add:%d:", count_serial(data, 3));
  printf("name > ");
  fgets(get_data(string), 100, stdin);
  fprintf(actor_log, "%s:", delete_null(string));
  printf("sex > ");
  fgets(get_data(string), 100, stdin);
  fprintf(actor_log, "%s:", delete_null(string));
  printf("birth > ");
  fgets(get_data(string), 100, stdin);
  fprintf(actor_log, "%s:", delete_null(string));
  printf("best_movies > ");
  fgets(get_data(string), 100, stdin);
  fprintf(actor_log, "%s\n", delete_null(string));
  loading(data);
}

char *delete_null(char *string) {
  int i=0;
  while(*(string+i) != '\n')
    i++;
  *(string+i) = '\0';
  return string;
}

char *get_data(char *p) {
  free(p);
  p = (char *)calloc(100, sizeof(char));
  return p;
}

int count_serial(link *data, int mode) {
  if(mode == 1) {
    movie *tmp = data->mv;
    while(tmp->next != NULL) {
      tmp = tmp->next;
    }
    return tmp->serial;
  }
  else if(mode == 2) {
    director *tmp = data->dir;
    while(tmp->next != NULL) {
      tmp = tmp->next;
    }
    return tmp->serial;
  }
  else if(mode == 3) {
    actor *tmp = data->act;
    while(tmp->next != NULL) {
      tmp = tmp->next;
    }
    return tmp->serial;
  }
  return 0;
}

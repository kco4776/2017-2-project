#include "struct.h"

void init_movie(link *data) {
  FILE *movie_log = fopen("movie_log", "r");
  data->movie = (movie *)malloc(sizeof(movie));
  data->movie->title = (char *)calloc(50, sizeof(char));
  data->movie->genre = (char *)calloc(50, sizeof(char));
  data->movie->mv_act = (actor_p *)malloc(sizeof(actor_p));
  data->movie->mv_act->title = (char *)calloc(50, sizeof(char));
  data->movie->mv_act->act_p = NULL;
  data->movie->mv_act->next = NULL;

  char *tag;
  tag = (char *)calloc(3, sizeof(char));

  fscanf(movie_log, "%[^:]", tag);
  fseek(movie_log, 1, SEEK_CUR);

  if(!strcmp(tag, "add")) {
    fscanf(movie_log, "%[^:]", data->movie->serial);
  }
}

#include "struct.h"

void init_movie(link *data) {
  FILE *movie_log = fopen("movie_log", "r");
  data->mv = (movie *)malloc(sizeof(movie));
  data->mv->title = (char *)calloc(50, sizeof(char));
  data->mv->genre = (char *)calloc(50, sizeof(char));
  data->mv->mv_dir = (director_p *)malloc(sizeof(director_p));
  data->mv->mv_dir->name = (char *)calloc(50, sizeof(char));
  data->mv->mv_dir->dir_p = NULL;
  data->mv->mv_act = (actor_p *)malloc(sizeof(actor_p));
  data->mv->mv_act->name = (char *)calloc(50, sizeof(char));
  data->mv->mv_act->act_p = NULL;
  data->mv->mv_act->next = NULL;

  char *tag;
  tag = (char *)calloc(3, sizeof(char));

  fscanf(movie_log, "%[^:]", tag);
  fseek(movie_log, 1, SEEK_CUR);

  if(!strcmp(tag, "add")) {
    fscanf(movie_log, "%[^:]", data->mv->serial);
    
  }
}

#include "struct.h"

void init_movie(link *data) {
  FILE *movie_log = fopen("movie_log", "r");
  data->mv = (movie *)malloc(sizeof(movie));
  data->mv->title = (char *)calloc(50, sizeof(char));
  data->mv->genre = (char *)calloc(50, sizeof(char));
  data->mv->mv_dir = (director_p *)malloc(sizeof(director_p));
  data->mv->mv_dir->name = (char *)calloc(50, sizeof(char));
  data->mv->mv_dir->dir_p = NULL;
  data->mv->year = (char *)calloc(10, sizeof(char));
  data->mv->time = (char *)calloc(4, sizeof(char));
  data->mv->mv_act = (actor_p *)malloc(sizeof(actor_p));
  data->mv->mv_act->name = (char *)calloc(50, sizeof(char));
  data->mv->mv_act->act_p = NULL;
  data->mv->mv_act->next = NULL;

  char *tag;
  tag = (char *)calloc(3, sizeof(char));
  char *serial;
  serial = (char *)calloc(5, sizeof(char));
  char *names;
  names = (char *)calloc(100, sizeof(char));
  char *name;
  name = (char *)calloc(50, sizeof(char));

  fscanf(movie_log, "%[^:]", tag);
  fseek(movie_log, 1, SEEK_CUR);

  if(!strcmp(tag, "add")) {
    fscanf(movie_log, "%[^:]", serial);
    data->mv->serial = atoi(serial);
    fseek(movie_log, 1, SEEK_CUR);
    fscanf(movie_log, "%[^:]", data->mv->title);
    fseek(movie_log, 1, SEEK_CUR);
    fscanf(movie_log, "%[^:]", data->mv->genre);
    fseek(movie_log, 1, SEEK_CUR);
    fscanf(movie_log, "%[^:]", data->mv->mv_dir->name);
    fseek(movie_log, 1, SEEK_CUR);
    fscanf(movie_log, "%[^:]", data->mv->year);
    fseek(movie_log, 1, SEEK_CUR);
    fscanf(movie_log, "%[^:]", data->mv->time);
    fseek(movie_log, 1, SEEK_CUR);
    fscanf(movie_log, "%[^\n]", names);
    name = strtok(names, ",");
    data->mv->mv_act->name = name;
    while(name = strtok(NULL, ",")) {
      add_actorp(data->mv->mv_act, name);
    }
    fseek(movie_log, 1, SEEK_CUR);
  }

  els

  free(tag);
  free(serial);
  free(names);
  free(name);
}

void add_actorp(actor_p *mv_act, char *actor) {
  mv_act->next = (actor_p *)malloc(sizeof(actor_p));
  mv_act->next->name = (char *)calloc(50, sizeof(char));
  mv_act->next->next = NULL;
  mv_act->next->name = actor;
}

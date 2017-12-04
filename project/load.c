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
  actor_p *tmp;

  char *tag;
  tag = (char *)calloc(10, sizeof(char));
  char *serial;
  serial = (char *)calloc(5, sizeof(char));
  char *names;
  names = (char *)calloc(100, sizeof(char));
  char *name;
  name = (char *)calloc(50, sizeof(char));

  while(fscanf(movie_log, "%[^:]", tag) != EOF) {
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
      tmp = data->mv->mv_act;
      while(name = strtok(NULL, ",")) {
        add_actorp(tmp, name);
      }
      fseek(movie_log, 1, SEEK_CUR);
      free(tag);
      free(serial);
      free(names);
      free(name);
      tag = (char *)calloc(10, sizeof(char));
      serial = (char *)calloc(5, sizeof(char));
      names = (char *)calloc(100, sizeof(char));
      name = (char *)calloc(50, sizeof(char));
    }

    else if(!strcmp(tag, "update")) {

    }

    else if(!strcmp(tag, "delete")) {

    }

  }
}

void init_director(link *data) {
  FILE *director_log = fopen("director_log", "r");
  data->dir = (director *)malloc(sizeof(director));
  data->dir->name = (char *)calloc(50, sizeof(char));
  data->dir->birth = (char *)calloc(10, sizeof(char));
  data->dir->best = (movie_p *)malloc(sizeof(movie_p));
  data->dir->best->title = (char *)calloc(50, sizeof(char));
  data->dir->best->mv_p = NULL;
  data->dir->best->next = NULL;
  data->dir->next = NULL;
  movie_p *tmp;

  char *tag;
  tag = (char *)calloc(10, sizeof(char));
  char *serial;
  serial = (char *)calloc(5, sizeof(char));
  char *best_mvs;
  best_mvs = (char *)calloc(100, sizeof(char));
  char *best_mv;
  best_mv = (char *)calloc(50, sizeof(char));

  while(fscanf(director_log, "%[^:]", tag) != EOF) {
    fseek(director_log, 1, SEEK_CUR);

    if(!strcmp(tag, "add")) {
      fscanf(director_log, "%[^:]", serial);
      fseek(director_log, 1, SEEK_CUR);
      fscanf(director_log, "%[^:]", data->dir->name);
      fseek(director_log, 1, SEEK_CUR);
      fscanf(director_log, "%[^:]", &(data->dir->sex));
      fseek(director_log, 1, SEEK_CUR);
      fscanf(director_log, "%[^:]", data->dir->birth);
      fseek(director_log, 1, SEEK_CUR);
      fscanf(director_log, "%[^\n]", best_mvs);
      best_mv = strtok(best_mvs, ",");
      data->dir->best->title = best_mv;
      tmp = data->dir->best;
      while(best_mv = strtok(NULL, ",")) {
        add_moviep(tmp, best_mv);
      }
    }

    else if(!strcmp(tag, "update")) {

    }

    else if(!strcmp(tag, "delete")) {

    }

  }
}

void add_actorp(actor_p *tmp, char *actor) {
  tmp->next = (actor_p *)malloc(sizeof(actor_p));
  tmp->next->name = (char *)calloc(50, sizeof(char));
  tmp->next->next = NULL;
  tmp->next->name = actor;
  tmp = tmp->next;
}

void add_moviep(movie_p *tmp, char *best_mv) {
  tmp->next = (movie_p *)malloc(sizeof(movie_p));
  tmp->next->title = (char *)calloc(50, sizeof(char));
  tmp->next->next = NULL;
  tmp->next->title = best_mv;
  tmp = tmp->next;
}

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
      strcpy(data->mv->mv_act->name, name);
      printf("name:%s\n", data->mv->mv_act->name);
      tmp = data->mv->mv_act;
      while(name = strtok(NULL, ",")) {
        add_actorp(&tmp, name);
        printf("name:%s\n", name);
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
      strcpy(data->dir->best->title, best_mv);
      tmp = data->dir->best;
      while(best_mv = strtok(NULL, ",")) {
        add_moviep(&tmp, best_mv);
      }
      fseek(director_log, 1, SEEK_CUR);
      free(tag);
      free(serial);
      free(best_mv);
      free(best_mvs);
      tag = (char *)calloc(10, sizeof(char));
      serial = (char *)calloc(5, sizeof(char));
      best_mvs = (char *)calloc(100, sizeof(char));
      best_mv = (char *)calloc(50, sizeof(char));
    }

    else if(!strcmp(tag, "update")) {

    }

    else if(!strcmp(tag, "delete")) {

    }

  }
}

void init_actor(link *data) {
  FILE *actor_log = fopen("actor_log", "r");
  data->act = (actor *)malloc(sizeof(actor));
  data->act->name = (char *)calloc(50, sizeof(char));
  data->act->birth = (char *)calloc(10, sizeof(char));
  data->act->best = (movie_p *)malloc(sizeof(movie_p));
  data->act->best->title = (char *)calloc(50, sizeof(char));
  data->act->best->mv_p = NULL;
  data->act->best->next = NULL;
  data->act->next = NULL;
  movie_p *tmp;

  char *tag;
  tag = (char *)calloc(10, sizeof(char));
  char *serial;
  serial = (char *)calloc(5, sizeof(char));
  char *best_mvs;
  best_mvs = (char *)calloc(100, sizeof(char));
  char *best_mv;
  best_mv = (char *)calloc(50, sizeof(char));

  while(fscanf(actor_log, "%[^:]", tag) != EOF) {
    fseek(actor_log, 1, SEEK_CUR);

    if(!strcmp(tag, "add")) {
      fscanf(actor_log, "%[^:]", serial);
      fseek(actor_log, 1, SEEK_CUR);
      fscanf(actor_log, "%[^:]", data->act->name);
      fseek(actor_log, 1, SEEK_CUR);
      fscanf(actor_log, "%[^:]", &(data->act->sex));
      fseek(actor_log, 1, SEEK_CUR);
      fscanf(actor_log, "%[^:]", data->act->birth);
      fseek(actor_log, 1, SEEK_CUR);
      fscanf(actor_log, "%[^\n]", best_mvs);
      best_mv = strtok(best_mvs, ",");
      strcpy(data->act->best->title, best_mv);
      tmp = data->act->best;
      while(best_mv = strtok(NULL, ",")) {
        add_moviep(&tmp, best_mv);
      }
      fseek(actor_log, 1, SEEK_CUR);
      free(tag);
      free(serial);
      free(best_mv);
      free(best_mvs);
      tag = (char *)calloc(10, sizeof(char));
      serial = (char *)calloc(5, sizeof(char));
      best_mvs = (char *)calloc(100, sizeof(char));
      best_mv = (char *)calloc(50, sizeof(char));
    }

    else if(!strcmp(tag, "update")) {

    }

    else if(!strcmp(tag, "delete")) {

    }

  }
}

void link_data(link *data) {
  movie *tmp_m = data->mv;
  actor *tmp_a = data->act;
  director *tmp_d = data->dir;
  actor_p *tmp_ap;
  movie_p *tmp_mp;

  while(tmp_m != NULL) {
    while(tmp_d != NULL) {
      if(!strcmp(tmp_m->mv_dir->name, tmp_d->name))
        tmp_m->mv_dir->dir_p = tmp_d;

      tmp_d = tmp_d->next;
    }
    tmp_m = tmp_m->next;
  }

  tmp_m = data->mv;
  tmp_a = data->act;
  tmp_d = data->dir;

  while(tmp_m != NULL) {
    tmp_ap = tmp_m->mv_act;
    while(tmp_ap != NULL) {
      while(tmp_a != NULL) {
        if(!strcmp(tmp_ap->name, tmp_a->name))
          tmp_ap->act_p = tmp_a;

        tmp_a = tmp_a->next;
      }
      tmp_ap = tmp_ap->next;
    }
    tmp_m = tmp_m->next;
  }

  tmp_m = data->mv;
  tmp_a = data->act;
  tmp_d = data->dir;

  while(tmp_a != NULL) {
    tmp_mp = tmp_a->best;
    while(tmp_mp != NULL) {
      while(tmp_m != NULL) {
        if(!strcmp(tmp_mp->title, tmp_m->title))
          tmp_mp->mv_p = tmp_m;

        tmp_m = tmp_m->next;
      }
      tmp_mp = tmp_mp->next;
    }
    tmp_a = tmp_a->next;
  }

  tmp_m = data->mv;
  tmp_a = data->act;
  tmp_d = data->dir;

  while(tmp_d != NULL) {
    tmp_mp = tmp_d->best;
    while(tmp_mp != NULL) {
      while(tmp_m != NULL) {
        if(!strcmp(tmp_mp->title, tmp_m->title))
          tmp_mp->mv_p = tmp_m;

        tmp_m = tmp_m->next;
      }
      tmp_mp = tmp_mp->next;
    }
    tmp_d = tmp_d->next;
  }

}

void add_actorp(actor_p **tmp, char *actor) {
  (*tmp)->next = (actor_p *)malloc(sizeof(actor_p));
  (*tmp)->next->name = (char *)calloc(50, sizeof(char));
  (*tmp)->next->next = NULL;
  strcpy((*tmp)->next->name, actor);
  (*tmp) = (*tmp)->next;
}

void add_moviep(movie_p **tmp, char *best_mv) {
  (*tmp)->next = (movie_p *)malloc(sizeof(movie_p));
  (*tmp)->next->title = (char *)calloc(50, sizeof(char));
  (*tmp)->next->next = NULL;
  (*tmp)->next->title = best_mv;
  (*tmp) = (*tmp)->next;
}

void loading(link *data) {
  init_movie(data);
  init_actor(data);
  init_director(data);
  link_data(data);
}

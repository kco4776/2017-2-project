#include "struct.h"

void init_movie(link_d *data) { //movie_log파일을 읽고 구조체에 저장.
  FILE *movie_log = fopen("movie_log", "r");
  actor_p *mv_ap;
  movie *tmp_m;

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
      if(data->mv == NULL) {
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
        data->mv->next = NULL;

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
        fscanf(movie_log, "%[^\n\r]", names);
        name = strtok(names, ",");
        strcpy(data->mv->mv_act->name, name);
        mv_ap = data->mv->mv_act;
        while(name = strtok(NULL, ",")) {
          add_actorp(&mv_ap, name+1);
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

      else {
        if(data->mv->next == NULL) {
          data->mv->next = (movie *)malloc(sizeof(movie));
          data->mv->next->title = (char *)calloc(50, sizeof(char));
          data->mv->next->genre = (char *)calloc(50, sizeof(char));
          data->mv->next->mv_dir = (director_p *)malloc(sizeof(director_p));
          data->mv->next->mv_dir->name = (char *)calloc(50, sizeof(char));
          data->mv->next->mv_dir->dir_p = NULL;
          data->mv->next->year = (char *)calloc(10, sizeof(char));
          data->mv->next->time = (char *)calloc(4, sizeof(char));
          data->mv->next->mv_act = (actor_p *)malloc(sizeof(actor_p));
          data->mv->next->mv_act->name = (char *)calloc(50, sizeof(char));
          data->mv->next->mv_act->act_p = NULL;
          data->mv->next->mv_act->next = NULL;
          data->mv->next->next = NULL;

          fscanf(movie_log, "%[^:]", serial);
          data->mv->next->serial = atoi(serial);
          fseek(movie_log, 1, SEEK_CUR);
          fscanf(movie_log, "%[^:]", data->mv->next->title);
          fseek(movie_log, 1, SEEK_CUR);
          fscanf(movie_log, "%[^:]", data->mv->next->genre);
          fseek(movie_log, 1, SEEK_CUR);
          fscanf(movie_log, "%[^:]", data->mv->next->mv_dir->name);
          fseek(movie_log, 1, SEEK_CUR);
          fscanf(movie_log, "%[^:]", data->mv->next->year);
          fseek(movie_log, 1, SEEK_CUR);
          fscanf(movie_log, "%[^:]", data->mv->next->time);
          fseek(movie_log, 1, SEEK_CUR);
          fscanf(movie_log, "%[^\n\r]", names);
          name = strtok(names, ",");
          strcpy(data->mv->next->mv_act->name, name);
          mv_ap = data->mv->next->mv_act;
          while(name = strtok(NULL, ",")) {
            add_actorp(&mv_ap, name+1);
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

        else {
          tmp_m = data->mv;
          while(tmp_m->next != NULL) {
            tmp_m = tmp_m->next;
          }
            tmp_m->next = (movie *)malloc(sizeof(movie));
            tmp_m->next->title = (char *)calloc(50, sizeof(char));
            tmp_m->next->genre = (char *)calloc(50, sizeof(char));
            tmp_m->next->mv_dir = (director_p *)malloc(sizeof(director_p));
            tmp_m->next->mv_dir->name = (char *)calloc(50, sizeof(char));
            tmp_m->next->mv_dir->dir_p = NULL;
            tmp_m->next->year = (char *)calloc(10, sizeof(char));
            tmp_m->next->time = (char *)calloc(4, sizeof(char));
            tmp_m->next->mv_act = (actor_p *)malloc(sizeof(actor_p));
            tmp_m->next->mv_act->name = (char *)calloc(50, sizeof(char));
            tmp_m->next->mv_act->act_p = NULL;
            tmp_m->next->mv_act->next = NULL;
            tmp_m->next->next = NULL;

            fscanf(movie_log, "%[^:]", serial);
            tmp_m->next->serial = atoi(serial);
            fseek(movie_log, 1, SEEK_CUR);
            fscanf(movie_log, "%[^:]", tmp_m->next->title);
            fseek(movie_log, 1, SEEK_CUR);
            fscanf(movie_log, "%[^:]", tmp_m->next->genre);
            fseek(movie_log, 1, SEEK_CUR);
            fscanf(movie_log, "%[^:]", tmp_m->next->mv_dir->name);
            fseek(movie_log, 1, SEEK_CUR);
            fscanf(movie_log, "%[^:]", tmp_m->next->year);
            fseek(movie_log, 1, SEEK_CUR);
            fscanf(movie_log, "%[^:]", tmp_m->next->time);
            fseek(movie_log, 1, SEEK_CUR);
            fscanf(movie_log, "%[^\n\r]", names);
            name = strtok(names, ",");
            strcpy(tmp_m->next->mv_act->name, name);
            mv_ap = tmp_m->next->mv_act;
            while(name = strtok(NULL, ",")) {
              add_actorp(&mv_ap, name+1);
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

      }

    }

    else if(!strcmp(tag, "update")) {

    }

    else if(!strcmp(tag, "delete")) {
      movie *tmp_m1;
      tmp_m = data->mv;

      fscanf(movie_log, "%[^:]", serial);

      while(tmp_m->next != NULL) {
        if (tmp_m->next->serial==atoi(serial)) {
          tmp_m1 = tmp_m->next->next;
          tmp_m->next = tmp_m1;
          tmp_m->next = NULL;
        }
        tmp_m = tmp_m->next;
      }
    }

  }
  fclose(movie_log);
}

void init_director(link_d *data) { //director_log파일을 읽고 구조체에 저장.
  FILE *director_log = fopen("director_log", "r");
  movie_p *tmp_mp;
  director *tmp_d;

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
      if(data->dir == NULL) {
        data->dir = (director *)malloc(sizeof(director));
        data->dir->name = (char *)calloc(50, sizeof(char));
        data->dir->birth = (char *)calloc(10, sizeof(char));
        data->dir->best = (movie_p *)malloc(sizeof(movie_p));
        data->dir->best->title = (char *)calloc(50, sizeof(char));
        data->dir->best->mv_p = NULL;
        data->dir->best->next = NULL;
        data->dir->next = NULL;

        fscanf(director_log, "%[^:]", serial);
        data->dir->serial = atoi(serial);
        fseek(director_log, 1, SEEK_CUR);
        fscanf(director_log, "%[^:]", data->dir->name);
        fseek(director_log, 1, SEEK_CUR);
        fscanf(director_log, "%[^:]", &(data->dir->sex));
        fseek(director_log, 1, SEEK_CUR);
        fscanf(director_log, "%[^:]", data->dir->birth);
        fseek(director_log, 1, SEEK_CUR);
        fscanf(director_log, "%[^\n\r]", best_mvs);
        best_mv = strtok(best_mvs, ",");
        strcpy(data->dir->best->title, best_mv);
        tmp_mp = data->dir->best;
        while(best_mv = strtok(NULL, ",")) {
          add_moviep(&tmp_mp, best_mv+1);
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

      else {
        if(data->dir->next == NULL) {
          data->dir->next = (director *)malloc(sizeof(director));
          data->dir->next->name = (char *)calloc(50, sizeof(char));
          data->dir->next->birth = (char *)calloc(10, sizeof(char));
          data->dir->next->best = (movie_p *)malloc(sizeof(movie_p));
          data->dir->next->best->title = (char *)calloc(50, sizeof(char));
          data->dir->next->best->mv_p = NULL;
          data->dir->next->best->next = NULL;
          data->dir->next->next = NULL;

          fscanf(director_log, "%[^:]", serial);
          data->dir->next->serial = atoi(serial);
          fseek(director_log, 1, SEEK_CUR);
          fscanf(director_log, "%[^:]", data->dir->next->name);
          fseek(director_log, 1, SEEK_CUR);
          fscanf(director_log, "%[^:]", &(data->dir->next->sex));
          fseek(director_log, 1, SEEK_CUR);
          fscanf(director_log, "%[^:]", data->dir->next->birth);
          fseek(director_log, 1, SEEK_CUR);
          fscanf(director_log, "%[^\n\r]", best_mvs);
          best_mv = strtok(best_mvs, ",");
          strcpy(data->dir->next->best->title, best_mv);
          tmp_mp = data->dir->next->best;
          while(best_mv = strtok(NULL, ",")) {
            add_moviep(&tmp_mp, best_mv+1);
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
        else {
          tmp_d = data->dir;
          while(tmp_d->next != NULL)
            tmp_d = tmp_d->next;

            tmp_d->next = (director *)malloc(sizeof(director));
            tmp_d->next->name = (char *)calloc(50, sizeof(char));
            tmp_d->next->birth = (char *)calloc(10, sizeof(char));
            tmp_d->next->best = (movie_p *)malloc(sizeof(movie_p));
            tmp_d->next->best->title = (char *)calloc(50, sizeof(char));
            tmp_d->next->best->mv_p = NULL;
            tmp_d->next->best->next = NULL;
            tmp_d->next->next = NULL;

            fscanf(director_log, "%[^:]", serial);
            tmp_d->next->serial = atoi(serial);
            fseek(director_log, 1, SEEK_CUR);
            fscanf(director_log, "%[^:]", tmp_d->next->name);
            fseek(director_log, 1, SEEK_CUR);
            fscanf(director_log, "%[^:]", &(tmp_d->next->sex));
            fseek(director_log, 1, SEEK_CUR);
            fscanf(director_log, "%[^:]", tmp_d->next->birth);
            fseek(director_log, 1, SEEK_CUR);
            fscanf(director_log, "%[^\n\r]", best_mvs);
            best_mv = strtok(best_mvs, ",");
            strcpy(tmp_d->next->best->title, best_mv);
            tmp_mp = tmp_d->next->best;
            while(best_mv = strtok(NULL, ",")) {
              add_moviep(&tmp_mp, best_mv+1);
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
      }
    }

    else if(!strcmp(tag, "update")) {

    }

    else if(!strcmp(tag, "delete")) {

    }

  }
}

void init_actor(link_d *data) { //actor_log파일을 읽고 구조체에 저장.
  FILE *actor_log = fopen("actor_log", "r");
  movie_p *tmp_mp;
  actor *tmp_a;

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
      if(data->act == NULL) {
        data->act = (actor *)malloc(sizeof(actor));
        data->act->name = (char *)calloc(50, sizeof(char));
        data->act->birth = (char *)calloc(10, sizeof(char));
        data->act->best = (movie_p *)malloc(sizeof(movie_p));
        data->act->best->title = (char *)calloc(50, sizeof(char));
        data->act->best->mv_p = NULL;
        data->act->best->next = NULL;
        data->act->next = NULL;

        fscanf(actor_log, "%[^:]", serial);
        data->act->serial = atoi(serial);
        fseek(actor_log, 1, SEEK_CUR);
        fscanf(actor_log, "%[^:]", data->act->name);
        fseek(actor_log, 1, SEEK_CUR);
        fscanf(actor_log, "%[^:]", &(data->act->sex));
        fseek(actor_log, 1, SEEK_CUR);
        fscanf(actor_log, "%[^:]", data->act->birth);
        fseek(actor_log, 1, SEEK_CUR);
        fscanf(actor_log, "%[^\n\r]", best_mvs);
        best_mv = strtok(best_mvs, ",");
        strcpy(data->act->best->title, best_mv);
        tmp_mp = data->act->best;
        while(best_mv = strtok(NULL, ",")) {
          add_moviep(&tmp_mp, best_mv+1);
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

      else {
        if(data->act->next == NULL) {
          data->act->next = (actor *)malloc(sizeof(actor));
          data->act->next->name = (char *)calloc(50, sizeof(char));
          data->act->next->birth = (char *)calloc(10, sizeof(char));
          data->act->next->best = (movie_p *)malloc(sizeof(movie_p));
          data->act->next->best->title = (char *)calloc(50, sizeof(char));
          data->act->next->best->mv_p = NULL;
          data->act->next->best->next = NULL;
          data->act->next->next = NULL;

          fscanf(actor_log, "%[^:]", serial);
          data->act->next->serial = atoi(serial);
          fseek(actor_log, 1, SEEK_CUR);
          fscanf(actor_log, "%[^:]", data->act->next->name);
          fseek(actor_log, 1, SEEK_CUR);
          fscanf(actor_log, "%[^:]", &(data->act->next->sex));
          fseek(actor_log, 1, SEEK_CUR);
          fscanf(actor_log, "%[^:]", data->act->next->birth);
          fseek(actor_log, 1, SEEK_CUR);
          fscanf(actor_log, "%[^\n\r]", best_mvs);
          best_mv = strtok(best_mvs, ",");
          strcpy(data->act->next->best->title, best_mv);
          tmp_mp = data->act->next->best;
          while(best_mv = strtok(NULL, ",")) {
            add_moviep(&tmp_mp, best_mv+1);
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
        else {
          tmp_a = data->act;
          while(tmp_a->next != NULL)
            tmp_a = tmp_a->next;

            tmp_a->next = (actor *)malloc(sizeof(actor));
            tmp_a->next->name = (char *)calloc(50, sizeof(char));
            tmp_a->next->birth = (char *)calloc(10, sizeof(char));
            tmp_a->next->best = (movie_p *)malloc(sizeof(movie_p));
            tmp_a->next->best->title = (char *)calloc(50, sizeof(char));
            tmp_a->next->best->mv_p = NULL;
            tmp_a->next->best->next = NULL;
            tmp_a->next->next = NULL;

            fscanf(actor_log, "%[^:]", serial);
            tmp_a->next->serial = atoi(serial);
            fseek(actor_log, 1, SEEK_CUR);
            fscanf(actor_log, "%[^:]", tmp_a->next->name);
            fseek(actor_log, 1, SEEK_CUR);
            fscanf(actor_log, "%[^:]", &(tmp_a->next->sex));
            fseek(actor_log, 1, SEEK_CUR);
            fscanf(actor_log, "%[^:]", tmp_a->next->birth);
            fseek(actor_log, 1, SEEK_CUR);
            fscanf(actor_log, "%[^\n\r]", best_mvs);
            best_mv = strtok(best_mvs, ",");
            strcpy(tmp_a->next->best->title, best_mv);
            tmp_mp = tmp_a->next->best;
            while(best_mv = strtok(NULL, ",")) {
              add_moviep(&tmp_mp, best_mv+1);
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
      }
    }

    else if(!strcmp(tag, "update")) {

    }

    else if(!strcmp(tag, "delete")) {

    }

  }
}

void link_data(link_d *data) { //같은 정보를 갖는 노드를 포인트.
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
    tmp_d = data->dir;
    tmp_m = tmp_m->next;
  }

  tmp_m = data->mv;
  tmp_a = data->act;
  tmp_d = data->dir;

  while(tmp_m != NULL) {
    tmp_ap = tmp_m->mv_act;
    while(tmp_ap != NULL) {
      while(tmp_a != NULL) {
        if(!strncmp(tmp_ap->name, tmp_a->name, strlen(tmp_a->name)))
          tmp_ap->act_p = tmp_a;

        tmp_a = tmp_a->next;
      }
      tmp_a = data->act;
      tmp_ap = tmp_ap->next;
    }
    tmp_m = tmp_m->next;
  }

  tmp_m = data->mv;
  tmp_a = data->act;
  tmp_d = data->dir;

  while(tmp_d != NULL) {
    tmp_mp = tmp_d->best;
    while(tmp_mp != NULL) {
      while(tmp_m != NULL) {
        if(!strncmp(tmp_mp->title, tmp_m->title, strlen(tmp_m->title)))
          tmp_mp->mv_p = tmp_m;

        tmp_m = tmp_m->next;
      }
      tmp_m = data->mv;
      tmp_mp = tmp_mp->next;
    }
    tmp_d = tmp_d->next;
  }

  tmp_m = data->mv;
  tmp_a = data->act;
  tmp_d = data->dir;

  while(tmp_a != NULL) {
    tmp_mp = tmp_a->best;
    while(tmp_mp != NULL) {
      while(tmp_m != NULL) {
        if(!strncmp(tmp_mp->title, tmp_m->title, strlen(tmp_m->title))) {
          tmp_mp->mv_p = tmp_m;
          break;
        }

        tmp_m = tmp_m->next;
      }
      tmp_m = data->mv;
      tmp_mp = tmp_mp->next;
    }
    tmp_a = tmp_a->next;
  }

  tmp_m = data->mv;
  tmp_a = data->act;
  tmp_d = data->dir;
}

void add_actorp(actor_p **tmp, char *actor) { //actor를 linked list에 저장.
  if((*tmp)->next == NULL) {
    (*tmp)->next = (actor_p *)malloc(sizeof(actor_p));
    (*tmp)->next->name = (char *)calloc(50, sizeof(char));
    (*tmp)->next->act_p = NULL;
    (*tmp)->next->next = NULL;
    strcpy((*tmp)->next->name, actor);
  }
  else {
    while((*tmp)->next != NULL)
      (*tmp)->next = (*tmp)->next->next;
      (*tmp)->next = (actor_p *)malloc(sizeof(actor_p));
      (*tmp)->next->name = (char *)calloc(50, sizeof(char));
      (*tmp)->next->act_p = NULL;
      (*tmp)->next->next = NULL;
      strcpy((*tmp)->next->name, actor);
  }
  (*tmp) = (*tmp)->next;
}

void add_moviep(movie_p **tmp, char *best_mv) {//movie를 linked list에 저장.
  if((*tmp)->next == NULL) {
    (*tmp)->next = (movie_p *)malloc(sizeof(movie_p));
    (*tmp)->next->title = (char *)calloc(50, sizeof(char));
    (*tmp)->next->mv_p = NULL;
    (*tmp)->next->next = NULL;
    strcpy((*tmp)->next->title, best_mv);
  }
  else {
    while((*tmp)->next != NULL)
      (*tmp)->next = (*tmp)->next->next;
      (*tmp)->next = (movie_p *)malloc(sizeof(movie_p));
      (*tmp)->next->title = (char *)calloc(50, sizeof(char));
      (*tmp)->next->mv_p = NULL;
      (*tmp)->next->next = NULL;
      strcpy((*tmp)->next->title, best_mv);
  }
  (*tmp) = (*tmp)->next;
}

void loading(link_d *data) { //log파일 읽고 구조체에 저장.
  free(data);
  data = (link_d *)malloc(sizeof(link_d));
  data->mv = NULL;
  data->act = NULL;
  data->dir = NULL;
  init_movie(data);
  init_actor(data);
  init_director(data);
  link_data(data);
}

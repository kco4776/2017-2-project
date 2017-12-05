#include "struct.h"

void print_m(link *data, char *tokenstring){
  FILE *movie_list = fopen("movie_list", "r");

  int compare=0,i=1;
  compare = atoi(tokenstring);
  while(data->mv->serial != compare) {
    data->mv = data->mv->next;
  }
  printf("%d, %s, %s\n", compare, data->mv->title, data->mv->genre);
  printf("D : %s(%s)\n", data->mv->mv_dir->name, data->mv->mv_dir->dir_p->birth);
  printf("A%d : %s(%s)\n", i++, data->mv->mv_act->name, data->mv->mv_act->act_p->birth);
  while(data->mv->mv_act->next != NULL) {
    data->mv->mv_act = data->mv->mv_act->next;
    printf("A%d : %s(%s)\n", i++, data->mv->mv_act->name, data->mv->mv_act->act_p->birth);
  }
}

void print_d(link *data, char *tokenstring) {
  FILE *movie_list = fopen("movie_list", "r");

  int compare=0,i=1;
  compare = atoi(tokenstring);
  while(data->dir->serial != compare) {
    data->dir=data->dir->next;
  }
  printf("%d, %s, %c, %s\n", compare, data->dir->name, data->dir->sex, data->dir->birth);
  printf("%s, %s, %s\n", data->dir->best->title, data->dir->best->mv_p->year, data->dir->best->mv_p->time);
  while(data->dir->best->next != NULL) {
    data->dir->best = data->dir->best->next;
    printf("%s, %s, %s\n", data->dir->best->title, data->dir->best->mv_p->year, data->dir->best->mv_p->time);
  }
}

void print_a(link *data, char *tokenstring) {
  FILE *movie_list = fopen("movie_list", "r");

  int compare=0,i=1;
  compare = atoi(tokenstring);
  while(data->act->serial != compare) {
    data->act=data->act->next;
  }
  printf("%d, %s, %c, %s\n", compare, data->act->name, data->act->sex, data->act->birth);
  printf("%s, %s, %s\n", data->act->best->title, data->act->best->mv_p->year, data->act->best->mv_p->time);
  while(data->act->best->next != NULL) {
    data->act->best = data->act->best->next;
    printf("%s, %s, %s\n", data->act->best->title, data->act->best->mv_p->year, data->act->best->mv_p->time);
  }
}

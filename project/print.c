#include "struct.h"

void print_m(link *data, char *tokenstring){
  FILE *movie_list = fopen("movie_list", "r");
  actor_p *tmp_ap;
  movie *tmp_m = data->mv;


  int compare=0,i=1;
  compare = atoi(tokenstring);
  while(tmp_m->serial != compare) {
    tmp_m = tmp_m->next;
  }
  tmp_ap = tmp_m->mv_act;
  director *checkdata = data->dir;

  printf("%d, %s, %s\n", compare, tmp_m->title, tmp_m->genre);
  while(checkdata->next!=NULL) {
    if (!strcmp(checkdata->name, tmp_m->mv_dir->name))
      printf("D : %s(%s)\n", tmp_m->mv_dir->name, tmp_m->mv_dir->dir_p->birth);
    checkdata = checkdata->next;
  //while(checkdata->next!=NULL) {
  //  if (!strcmp(checkdata->name, tmp_m->mv_dir->name))
      printf("D : %s(%s)\n", tmp_m->mv_dir->name, tmp_m->mv_dir->dir_p->birth);
      printf("1");
    //checkdata = checkdata->next;
  //}
  printf("D : %s\n", tmp_m->mv_dir->name);
  printf("A%d : %s()\n", i++, tmp_ap->name, tmp_ap->act_p->birth);
  while(tmp_ap->next != NULL) {
    tmp_ap = tmp_ap->next;
    printf("A%d : %s(%s)\n", i++, tmp_ap->name, tmp_ap->act_p->birth);
  }
  printf("D : %s\n", tmp_m->mv_dir->name);
  printf("A%d : %s()\n", i++, tmp_ap->name); //tmp_ap->act_p->birth);
  /*while(tmp_ap->next != NULL) {
    tmp_ap = tmp_ap->next;
    printf("A%d : %s(%s)\n", i++, tmp_ap->name, tmp_ap->act_p->birth);
  }*/
}

void print_d(link *data, char *tokenstring) {
  FILE *movie_list = fopen("movie_list", "r");
  director_p *tmp_dp;
  movie_p *tmp_mp;
  director *tmp_d = data->dir;

  int compare=0,i=1;
  compare = atoi(tokenstring);
  while(tmp_d->serial != compare) {
    tmp_d=tmp_d->next;
  }
  tmp_dp = tmp_d->best;
  tmp_mp = tmp_d->best;
  printf("%d, %s, %c, %s\n", compare, data->dir->name, data->dir->sex, data->dir->birth);
  printf("%s, %s, %s\n", data->dir->best->title, data->dir->best->mv_p->year, data->dir->best->mv_p->time);
  while(data->dir->best->next != NULL) {
    data->dir->best = data->dir->best->next;
    printf("%s, %s, %s\n", data->dir->best->title, data->dir->best->mv_p->year, data->dir->best->mv_p->time);
  }
}

void print_a(link *data, char *tokenstring) {
  FILE *movie_list = fopen("movie_list", "r");
  movie_p *tmp_mp;


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

void test_print(link *data) {
  printf("actor1:%s\n", data->mv->mv_act->name);
}

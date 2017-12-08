#include "struct.h"

void print_m(link *data, char *tokenstring){
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
  //while(checkdata->next!=NULL) {
  //  if (!strcmp(checkdata->name, tmp_m->mv_dir->name))
      printf("D : %s(%s)\n", tmp_m->mv_dir->name, tmp_m->mv_dir->dir_p->birth);

    //checkdata = checkdata->next;
  //}
  printf("D : %s\n", tmp_m->mv_dir->name);
  printf("A%d : %s()\n", i++, tmp_ap->name, tmp_ap->act_p->birth);
  while(tmp_ap->next != NULL) {
    tmp_ap = tmp_ap->next;
    printf("A%d : %s(%s)\n", i++, tmp_ap->name, tmp_ap->act_p->birth);
  }
}

void print_d(link *data, char *tokenstring) {
  movie_p *tmp_mp;
  director *tmp_d = data->dir;
  int compare=0,i=1;
  compare = atoi(tokenstring);
  while(tmp_d->serial != compare) {
    tmp_d=tmp_d->next;
  }
  tmp_mp = tmp_d->best;
  printf("%d, %s, %c, %s\n", compare, tmp_d->name, tmp_d->sex, tmp_d->birth);
  printf("%s, %s, %s\n", tmp_mp->title, tmp_mp->mv_p->year, tmp_mp->mv_p->time);
  while(tmp_mp->next != NULL) {
    tmp_mp = tmp_mp->next;
    printf("%s, %s, %s\n", tmp_mp->title, tmp_mp->mv_p->year, tmp_mp->mv_p->time);
  }
}

void print_a(link *data, char *tokenstring) {
  movie_p *tmp_mp;
  actor *tmp_a = tmp_a;

  int compare=0,i=1;
  compare = atoi(tokenstring);
  while(tmp_a->serial != compare) {
    tmp_a=tmp_a->next;
  }
  tmp_mp = tmp_mp;
  printf("%d, %s, %c, %s\n", compare, tmp_a->name, tmp_a->sex, tmp_a->birth);
  printf("%s, %s, %s\n", tmp_mp->title, tmp_mp->mv_p->year, tmp_mp->mv_p->time);
  while(tmp_mp->next != NULL) {
    tmp_mp = tmp_mp->next;
    printf("%s, %s, %s\n", tmp_mp->title, tmp_mp->mv_p->year, tmp_mp->mv_p->time);
  }
}

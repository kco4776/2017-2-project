#include "struct.h"

void print_m(link *data, int num) {
  movie *tmp = data->mv;
  actor_p *tmp_ap;
  while(tmp->serial != num) {
    tmp = tmp->next;
  }
  tmp_ap = tmp->mv_act;
  printf("%d, %s, %s\n", num, tmp->title, tmp->genre);
  printf("  D :%s(%s)\n", tmp->mv_dir->name, dir_birth_check(tmp->mv_dir));
  for(int i=1; tmp_ap != NULL; i++) {
    printf("  A%d :%s", i, tmp_ap->name);
    printf("(%s)\n" ,act_birth_check(tmp_ap));
    tmp_ap = tmp_ap->next;
  }
}

void print_d(link *data, int num) {
    director *tmp = data->dir;
    movie_p *tmp_mp;
    while(tmp->serial != num)
      tmp = tmp->next;
    tmp_mp = tmp->best;
    printf("%d, %s, %c, %s\n", num, tmp->name, tmp->sex, tmp->birth);
    for(int i=1; tmp_mp != NULL; i++) {
      printf("%s, %s, %s\n", tmp_mp->title, mv_year_check(tmp_mp), mv_time_check(tmp_mp));
      tmp_mp = tmp_mp->next;
    }
}

char* act_birth_check(actor_p *tmp_ap) {
  if(tmp_ap->act_p == NULL) {
    return "-";
  }
  else if(tmp_ap->act_p != NULL) {
    return tmp_ap->act_p->birth;
  }
}

char* dir_birth_check(director_p *tmp_dp) {
  if(tmp_dp->dir_p == NULL)
    return "-";
  else if(tmp_dp->dir_p != NULL)
    return tmp_dp->dir_p->birth;
}

char* mv_year_check(movie_p *tmp) {
  if(tmp->mv_p == NULL)
    return "-";
  else
    return tmp->mv_p->year;
}

char* mv_time_check(movie_p *tmp) {
  if(tmp->mv_p == NULL)
    return "-";
  else
    return tmp->mv_p->time;
}

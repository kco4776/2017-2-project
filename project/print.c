#include "struct.h"

void print_m(link *data, int num) {
  movie *tmp = data->mv;
  actor_p *tmp_ap;
  while(tmp->serial != num) {
    tmp = tmp->next;
  }
  tmp_ap = tmp->mv_act;
  printf("%d, %s, %s\n", num, tmp->title, tmp->genre);
  printf("  D :%s(%s)\n", tmp->mv_dir->name, tmp->mv_dir->dir_p->birth);
  for(int i=1; tmp_ap != NULL; i++) {
    printf("  A%d :%s(%s)\n", i, tmp_ap->name, birth_check(tmp_ap));
    tmp_ap = tmp_ap->next;
  }
}

char* birth_check(actor_p *tmp_ap) {
  if(tmp_ap->act_p == NULL) {
    return "-";
  }
  else if(tmp_ap->act_p != NULL) {
    return tmp_ap->act_p->birth;
  }
}

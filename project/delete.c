#include "struct.h"

void delete_m(link *data, int num) {
  FILE *movie_log = fopen("movie_log", "a");

  movie *tmp_m1 = data->mv;
  movie *tmp_m2 = tmp_m1->next;
  movie *tmp_m3;

  link *tmp = data;

  if (tmp_m1->serial != num) {
    while(tmp_m2->serial != num) {
       tmp_m2 = tmp_m2->next;
       if(tmp_m2->next == NULL) {
         printf("No such record\n");
         break;
       }
    }
    if (tmp_m2->serial == num) {
        while (tmp_m1->next->serial != tmp_m2->serial) {
          tmp_m1 = tmp_m1->next;
        }
        tmp_m1->next = tmp_m2;
        /*while (tmp->dir->next != NULL) {
          if (!strcmp(tmp->dir->best->mv_p->title, tmp_m2->title)) {
            printf("%s %s\n", tmp_m2->title, tmp_m1->next->title);
            tmp->dir->best->mv_p = NULL;
          }
          tmp->dir = tmp->dir->next;
        }*/
        tmp_m1->next = tmp_m2->next;
        tmp_m1->next = NULL;

        fprintf(movie_log, "delete:%d::::\n", num);
        printf("@Done\n");
        loading(data);
    }


  }
  else {
    if (tmp_m1 == NULL)
      printf("No such record\n");
    tmp_m3->next = tmp_m1->next;
    tmp_m1=NULL;
    fprintf(movie_log, "delete:%d::::\n", num);
    printf("@Done\n");
    loading(data);
  }
}

#include "struct.h"

void print_m(link_d *data, int num) { //입력된 번호와 같은 시리얼 번호를 가지는 영화를 출력하는 함수
  movie *tmp = data->mv;
  actor_p *tmp_ap;
  while(tmp->serial != num) { //입력된 번호와 영화의 시리얼 번호 비교
    tmp = tmp->next;
  }
  tmp_ap = tmp->mv_act; //출연 배우들 이름이 저장된 노드
  printf("%d, %s, %s\n", num, replaceAll(tmp->title, "??;", ":"), tmp->genre); //serial num, title, genre출력
  printf("  D  :%s(%s)\n", tmp->mv_dir->name, dir_birth_check(tmp->mv_dir)); // director name, 그 감독이 감독리스트에 있으면 birth 출력
  for(int i=1; tmp_ap != NULL; i++) {  //출연 배우들의 name, birth 출력
    printf("  A%d :%s", i, tmp_ap->name);
    printf("(%s)\n" ,act_birth_check(tmp_ap));  //배우 리스트에 해당 배우가 있다면 그 배우의 birth 출력
    tmp_ap = tmp_ap->next;
  }
}

void print_d(link_d *data, int num) { //입력된 번호와 같은 시리얼 번호를 가지는 감독을 출력하는 함수
    director *tmp = data->dir;
    movie_p *tmp_mp;
    while(tmp->serial != num)   //입력된 번호와 감독의 시리얼 번호 비교
      tmp = tmp->next;
    tmp_mp = tmp->best; //감독의 대표작들이 저장된 노드
    printf("%d, %s, %c, %s\n", num, tmp->name, tmp->sex, tmp->birth); //serial num, sex, birth 출력
    while(tmp_mp != NULL) { //감독의 대표작 출력
      printf("%s, %s, %s\n", tmp_mp->title, mv_year_check(tmp_mp), mv_time_check(tmp_mp)); //대표작이 영화리스트에 있다면 제작년도와 상영시간 출력
      tmp_mp = tmp_mp->next;
    }
}

void print_a(link_d *data, int num) {   //입력된 번호와 같은 시리얼 번호를 가지는 배우를 출력하는 함수
  actor *tmp = data->act;
  movie_p *tmp_mp;
  while(tmp->serial != num)   //입력된 번호와 배우의 시리얼 번호 비교
    tmp = tmp->next;
  tmp_mp = tmp->best; //배우의 대표작들이 저장된 노드
  printf("%d, %s, %c, %s\n", num, tmp->name, tmp->sex, tmp->birth);  //serial num, sex, birth 출력
  while(tmp_mp != NULL) { //배우의 대표작 출력
    printf("%s, %s, %s\n", tmp_mp->title, mv_year_check(tmp_mp), mv_time_check(tmp_mp)); //대표작이 영화리스트에 있다면 제작년도와 상영시간 출력
    tmp_mp = tmp_mp->next;
  }
}

char* act_birth_check(actor_p *tmp_ap) { //입력된 배우가 배우 리스트에 있다면 생년월일을 리턴하는 함수
  if(tmp_ap->act_p == NULL) {
    return "-";
  }
  else if(tmp_ap->act_p != NULL) {
    return tmp_ap->act_p->birth;
  }
}

char* dir_birth_check(director_p *tmp_dp) { //입력된 감독이 감독 리스트에 있다면 생년월일을 리턴하는 함수
  if(tmp_dp->dir_p == NULL)
    return "-";
  else if(tmp_dp->dir_p != NULL)
    return tmp_dp->dir_p->birth;
}

char* mv_year_check(movie_p *tmp) { //입력된 영화가 영화 리스트에 있다면 제작년도를 리턴하는 함수
  if(tmp->mv_p == NULL)
    return "-";
  else
    return tmp->mv_p->year;
}

char* mv_time_check(movie_p *tmp) { //입력된 영화가 영화 리스트에 있다면 상영시간을 리턴하는 함수
  if(tmp->mv_p == NULL)
    return "-";
  else
    return tmp->mv_p->time;
}

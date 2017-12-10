#include "struct.h"

void add_m(link_d *data) {  //영화 추가 함수
  FILE *movie_log = fopen("movie_log", "a");

  char *string;
  string = (char *)calloc(100, sizeof(char));

  printf("title > ");
  fgets(get_data(string), 100, stdin);   // get_data 함수로 free 후에 다시 동적 할당한 다음 입력받기
  if(check_mv_record(data, string))      // 이미 있는 영화인지 확인
    printf("You have the same record.\n");
  else { //리스트에 없는 영화 일때
    fprintf(movie_log, "add:%d:", count_serial(data, 1)+1); // 리턴된 serial+1
    fprintf(movie_log, "%s:", replaceAll(delete_null(string), ":", "??;")); // :이 있으면 :을 ??;로 변환
    printf("genre > ");
    fgets(get_data(string), 100, stdin);
    fprintf(movie_log, "%s:", delete_null(string));
    printf("director > ");
    fgets(get_data(string), 100, stdin);
    fprintf(movie_log, "%s:", delete_null(string));
    printf("year > ");
    fgets(get_data(string), 100, stdin);
    fprintf(movie_log, "%s:", delete_null(string));
    printf("time > ");
    fgets(get_data(string), 100, stdin);
    fprintf(movie_log, "%s:", delete_null(string));
    printf("actor > ");
    fgets(get_data(string), 100, stdin);
    fprintf(movie_log, "%s\n", delete_null(string));
    fclose(movie_log);
    loading(data);
    make_mvlist();
  }
}

void add_d(link_d *data) {   //영화 감독 추가 함수
  FILE *director_log = fopen("director_log", "a");

  char *string;
  string = (char *)calloc(100, sizeof(char));

  printf("name > ");
  fgets(get_data(string), 100, stdin); //get_data 함수로 free 후에 다시 동적 할당한 다음 입력받기
  if(check_dir_record(data, string))   //이미 있는 감독인지 확인
    printf("You have the same record.\n");
  else { //리스트에 없는 감독일 때
    fprintf(director_log, "add:%d:", count_serial(data, 2)+1); //리턴된 seiral+1
    fprintf(director_log, "%s:", delete_null(string));
    printf("sex > ");
    fgets(get_data(string), 100, stdin);
    fprintf(director_log, "%s:", delete_null(string));
    printf("birth > ");
    fgets(get_data(string), 100, stdin);
    fprintf(director_log, "%s:", delete_null(string));
    printf("best_movies > ");
    fgets(get_data(string), 100, stdin);
    fprintf(director_log, "%s\n", delete_null(string));
    fclose(director_log);
    loading(data);
    make_dirlist();
  }
}

void add_a(link_d *data) { //영화 배우 추가 함수
  FILE *actor_log = fopen("actor_log", "a");

  char *string;
  string = (char *)calloc(100, sizeof(char));

  printf("name > ");
  fgets(get_data(string), 100, stdin);  //get_data 함수로 free 후에 다시 동적 할당한 다음 입력받기
  if(check_act_record(data, string))    //이미 있는 배우인지 확인
    printf("You have the same record.\n");
  else {  //리스트에 없는 배우일 때
    fprintf(actor_log, "add:%d:", count_serial(data, 3)+1); //리턴된 serial + 1
    fprintf(actor_log, "%s:", delete_null(string));
    printf("sex > ");
    fgets(get_data(string), 100, stdin);
    fprintf(actor_log, "%s:", delete_null(string));
    printf("birth > ");
    fgets(get_data(string), 100, stdin);
    fprintf(actor_log, "%s:", delete_null(string));
    printf("best_movies > ");
    fgets(get_data(string), 100, stdin);
    fprintf(actor_log, "%s\n", delete_null(string));
    fclose(actor_log);
    loading(data);
    make_actlist();
  }
}

int check_mv_record(link_d *data, char *string) {     //입력받은 영화가 레코드에 입력된 영화인지 검사하는 함수
  movie *tmp = data->mv;
  while(tmp != NULL) { //tmp가 NULL일 때까지 tmp=tmp->next
    if(!strncmp(string, tmp->title, strlen(tmp->title)))  // 같은 이름의 영화가 있을 때
      return 1;                                           // 1 반환
    tmp = tmp->next;
  }
  return 0;
}

int check_act_record(link_d *data, char *string) {    //입력받은 배우가 레코드에 입력된 배우인지 검사하는 함수
  actor *tmp = data->act;
  while(tmp != NULL) { //tmp가 NULL일 때까지 tmp=tmp->next
    if(!strncmp(string, tmp->name, strlen(tmp->name)))  // 같은 이름의 배우가 있을 때
      return 1;                                         // 1 반환
    tmp = tmp->next;
  }
  return 0;
}

int check_dir_record(link_d *data, char *string) {    //입력받은 감독이 레코드에 입력된 감독인지 검사하는 함수
  director *tmp = data->dir;
  while(tmp != NULL) {  //tmp가 NULL일 때까지 tmp=tmp->next
    if(!strncmp(string, tmp->name, strlen(tmp->name)))  // 같은 이름의 감독이 있을 때
      return 1;                                         // 1 반환
    tmp = tmp->next;
  }
  return 0;
}

char *delete_null(char *string) { //string 끝에 NULL 제거하는 함수
  int i=0;
  while(*(string+i) != '\n')
    i++;
  *(string+i) = '\0';
  return string;
}

char *get_data(char *p) {  //문자열 포인터를 free 후 다시 동적할당 해주는 함수
  free(p);
  p = (char *)calloc(100, sizeof(char));
  return p;
}

int count_serial(link_d *data, int mode) { //serial num count function
  if(mode == 1) {                        // mode == 1 은 movie
    if(data->mv != NULL) {
      movie *tmp = data->mv;
      while(tmp->next != NULL) {
        tmp = tmp->next;
      }
      return tmp->serial;
    }
    else
      return 0;
  }
  else if(mode == 2) {                   // mode == 2 는 director
    if(data->dir != NULL) {
      director *tmp = data->dir;
      while(tmp->next != NULL) {
        tmp = tmp->next;
      }
      return tmp->serial;
    }
    else
      return 0;
  }
  else if(mode == 3) {                   // mode == 3 은 actor
    if(data->act != NULL) {
      actor *tmp = data->act;
      while(tmp->next != NULL) {
        tmp = tmp->next;
      }
      return tmp->serial;
    }
    else
      return 0;
  }
  return 0;
}

char *replaceAll(char *s, const char *olds, const char *news) { // 메타 문자 처리 함수
  char *result, *sr;
  size_t i, count = 0;
  size_t oldlen = strlen(olds); if (oldlen < 1) return s;
  size_t newlen = strlen(news);


  if (newlen != oldlen) {
    for (i = 0; *(s+i) != '\0';) {
      if (memcmp(s+i, olds, oldlen) == 0) count++, i += oldlen;
      else i++;
    }
  } else i = strlen(s);


  result = (char *) malloc(i + 1 + count * (newlen - oldlen));
  if (result == NULL) return NULL;


  sr = result;
  while (*s) {
    if (memcmp(s, olds, oldlen) == 0) {
      memcpy(sr, news, newlen);
      sr += newlen;
      s  += oldlen;
    } else *sr++ = *s++;
  }
  *sr = '\0';

  return result;
}

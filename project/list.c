#include "struct.h"


void ctrl_c(int sig) { //신호 처리를 위한 신호처리 함수
  char *answer;
  answer = (char *)calloc(10, sizeof(char));
  printf("Control+C\n");
  printf("Get Interrupt Signal\n");
  printf("Do you want to exit myMOVIE program? (Y/N) ");
  scanf("%s", answer);
  if (*answer=='y' || *answer=='Y')
    exit(1);
}


void movie_list() {  //영화 리스트를 만드는 함수
  time_t timer;
  struct tm *t;
  int size; //파일 크기를 저장하기 위한 변수
  int mode = F_OK;

  timer = time(NULL);

  t = localtime(&timer);
  char *nowtime; //현재 시간 저장 문자열
  nowtime = (char *)calloc(100, sizeof(char));
  sprintf(nowtime, "movie_list.%04d%02d%02d%02d%02d", t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min);
  char *buffer; //기존의 영화 리스트 파일을 복사하기 위한 문자열
  if (access("movie_list", mode)==0) //기존에 movie_list가 있을 때
  {
    FILE *cur_movie_list = fopen("movie_list", "r");
    FILE *last_movie_list = fopen(nowtime, "w");

    fseek(cur_movie_list, 0, SEEK_END); //파일 끝으로 이동
    size=ftell(cur_movie_list);  //파일 크기 확인
    buffer=(char *)calloc(size+1, sizeof(char));
    rewind(cur_movie_list); //파일 처음으로 이동
    fread(buffer, size, 1, cur_movie_list); //buffer에 파일 내용 복사
    fprintf(last_movie_list, "%s", buffer); //파일에 buffer 내용 쓰기
    fclose(last_movie_list);
    fclose(cur_movie_list);
  }
  free(nowtime);

  FILE *movie_log = fopen("movie_log", "r");
  FILE *movie_list = fopen("movie_list", "w");

  char *string;
  string = (char *)calloc(100, sizeof(char));
  char *tag;
  tag = (char *)calloc(100, sizeof(char));
  char *serial;
  serial = (char *)calloc(100, sizeof(char));

  while(fscanf(movie_log, "%[^:]", tag) != EOF) {

      if (!strcmp(tag, "add")) {

        fscanf(movie_log, "%[^\n]", string); //개행 나올 때까지 string에 저장
        fprintf(movie_list,"%s\n",string+1); // 제일 앞에 : 콜론을 제외한 내용 파일에 쓰기
        fseek(movie_log, 1, SEEK_CUR);
      }
      else if(!strcmp(tag, "delete")) {

      }
    }
    free(string);
    free(tag);
    free(serial);
}

void director_list() {  //감독 리스트를 만드는 함수
  time_t timer;
  struct tm *t;
  int size; //파일 크기를 저장하기 위한 변수
  int mode = F_OK;

  timer = time(NULL);

  t = localtime(&timer);
  char *nowtime; //현재 시간 저장 문자열
  nowtime = (char *)calloc(100, sizeof(char));
  sprintf(nowtime, "director_list.%04d%02d%02d%02d%02d", t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min);
  char *buffer; //기존의 감독 리스트 파일을 복사하기 위한 문자열
  if (access("director_list", mode)==0) //기존에 director_list가 있을 때
  {
    FILE *cur_director_list = fopen("director_list", "r");
    FILE *last_director_list = fopen(nowtime, "w");

    fseek(cur_director_list, 0, SEEK_END); //파일 끝으로 이동
    size=ftell(cur_director_list);  //파일 크기 확인
    buffer=(char *)calloc(size+1, sizeof(char));
    rewind(cur_director_list); //파일 처음으로 이동
    fread(buffer, size, 1, cur_director_list); //buffer에 파일 내용 복사
    fprintf(last_director_list, "%s", buffer); //파일에 buffer 내용 쓰기
    fclose(last_director_list);
    fclose(cur_director_list);
  }
  free(nowtime);

  FILE *director_log = fopen("director_log", "r");
  FILE *director_list = fopen("director_list", "w");

  char *string;
  string = (char *)calloc(100, sizeof(char));
  char *tag;
  tag = (char *)calloc(100, sizeof(char));
  char *serial;
  serial = (char *)calloc(100, sizeof(char));

  while(fscanf(director_log, "%[^:]", tag) != EOF) {

      if (!strcmp(tag, "add")) {

        fscanf(director_log, "%[^\n]", string); //개행 나올 때까지 string에 저장
        fprintf(director_list,"%s\n",string+1); // 제일 앞에 : 콜론을 제외한 내용 파일에 쓰기
        fseek(director_log, 1, SEEK_CUR);
      }
      else if(!strcmp(tag, "delete")) {
        fscanf(director_log,"%[^:]", serial);


      }
    }
    fclose(director_log);
    fclose(director_list);
    free(string);
    free(tag);
    free(serial);

}

void actor_list() {   // 배우 리스트를 만드는 함수
  time_t timer;
  struct tm *t;
  int size; //파일 크기를 저장하기 위한 변수
  int mode = F_OK;

  timer = time(NULL);

  t = localtime(&timer);
  char *nowtime; //현재 시간 저장 문자열
  nowtime = (char *)calloc(100, sizeof(char));
  sprintf(nowtime, "actor_list.%04d%02d%02d%02d%02d", t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min);
  char *buffer; //기존의 배우 리스트 파일을 복사하기 위한 문자열
  if (access("actor_list", mode)==0) //기존에 actor_list가 있을 때
  {
    FILE *cur_actor_list = fopen("actor_list", "r");
    FILE *last_actor_list = fopen(nowtime, "w");

    fseek(cur_actor_list, 0, SEEK_END); //파일 끝으로 이동
    size=ftell(cur_actor_list);  //파일 크기 확인
    buffer=(char *)calloc(size+1, sizeof(char));
    rewind(cur_actor_list); //파일 처음으로 이동
    fread(buffer, size, 1, cur_actor_list); //buffer에 파일 내용 복사
    fprintf(last_actor_list, "%s", buffer); //파일에 buffer 내용 쓰기
    fclose(last_actor_list);
    fclose(cur_actor_list);
  }
  free(nowtime);

  FILE *actor_log = fopen("actor_log", "r");
  FILE *actor_list = fopen("actor_list", "w");

  char *string;
  string = (char *)calloc(100, sizeof(char));
  char *tag;
  tag = (char *)calloc(100, sizeof(char));
  char *serial;
  serial = (char *)calloc(100, sizeof(char));

  while(fscanf(actor_log, "%[^:]", tag) != EOF) {

      if (!strcmp(tag, "add")) {

        fscanf(actor_log, "%[^\n]", string); //개행 나올 때까지 string에 저장
        fprintf(actor_list,"%s\n",string+1); // 제일 앞에 : 콜론을 제외한 내용 파일에 쓰기
        fseek(actor_log, 1, SEEK_CUR);
      }
      else if(!strcmp(tag, "delete")) {
        fscanf(actor_log,"%[^:]", serial);


      }
    }
    fclose(actor_log);
    fclose(actor_list);
    free(string);
    free(tag);
    free(serial);

}

int command_num(char *command) {   // 명령어 번호를 얻기 위해 문자열 자르기
  char *string;
  string = (char *)calloc(100, sizeof(char));
  string = strtok(command, " ");
  string = strtok(NULL, " ");
  string = strtok(NULL, " ");
  return atoi(string);
}

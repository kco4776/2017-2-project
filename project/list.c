#include "struct.h"

void ctrl_c(int sig) {
  char *answer;
  answer = (char *)calloc(10, sizeof(char));
  printf("Control+C\n");
  printf("Get Interrupt Signal\n");
  printf("Do you want to exit myMOVIE program? (Y/N) ");
  scanf("%s", answer);
  if (*answer=='y' || *answer=='Y')
    exit(1);
}


void movie_list() {
  time_t timer;
  struct tm *t;
  int size;

  timer = time(NULL);

  t = localtime(&timer);
  char *nowtime;
  nowtime = (char *)calloc(100, sizeof(char));
  sprintf(nowtime, "movie_list.%04d%02d%02d%02d%02d", t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min);
  char *buffer;
  FILE *cur_movie_list = fopen("movie_list", "r");
  FILE *last_movie_list = fopen(nowtime, "w");

  fseek(cur_movie_list, 0, SEEK_END);
  size=ftell(cur_movie_list);
  buffer=(char *)calloc(size+1, sizeof(char));
  rewind(cur_movie_list);
  fread(buffer, size, 1, cur_movie_list);
  fprintf(last_movie_list, "%s", buffer);
  fclose(last_movie_list);
  fclose(cur_movie_list);


  FILE *movie_log = fopen("movie_log", "r");
  FILE *movie_list = fopen("movie_list", "a");

  char *string;
  string = (char *)calloc(100, sizeof(char));
  char *tag;
  tag = (char *)calloc(100, sizeof(char));
  char *serial;
  serial = (char *)calloc(100, sizeof(char));

  while(fscanf(movie_log, "%[^:]", tag) != EOF) {

      if (!strcmp(tag, "add")) {
        fscanf(movie_log, "%[^\n]", string);
        fprintf(movie_list,"%s\n",string+1);
        fseek(movie_log, 1, SEEK_CUR);
      }
      else if(!strcmp(tag, "delete")) {
        //fscanf(movie_log,"%[^:]", serial);

      }
    }
    fclose(movie_log);
    fclose(movie_list);
}

int command_num(char *command) {
  char *string;
  string = (char *)calloc(100, sizeof(char));
  string = strtok(command, " ");
  string = strtok(NULL, " ");
  string = strtok(NULL, " ");
  return atoi(string);
}

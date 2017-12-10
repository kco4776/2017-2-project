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

int command_num(char *command) {   // 명령어 번호를 얻기 위해 문자열 자르기
  char *string;
  string = (char *)calloc(100, sizeof(char));
  string = strtok(command, " ");
  string = strtok(NULL, " ");
  string = strtok(NULL, " ");
  return atoi(string);
}

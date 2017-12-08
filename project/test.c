#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *string;
  string = (char *)calloc(50, sizeof(char));
  stringcopy(string);
  printf("string:%s\n", string);

  return 0;
}

void stringcopy(char *string) {
  char tmp[50];
  printf("입력:");
  scanf("%s", tmp);
  strcpy(string, tmp);
}

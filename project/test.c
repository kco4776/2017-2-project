#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_m(char *string);

int main(void) {
  FILE *ip_m = fopen("movie_log", "r");
  char tag[4];
  char *string;
  string = (char *)calloc(50, sizeof(char));
  fgets(tag, 4, ip_m);
  printf("tag:%s\n", tag);
  if(!strcmp(tag, "add")) {
    init_m(string);
    printf("string:%s\n", string);
  }
}

void init_m(char *string) {
  FILE *ip_m = fopen("movie_log", "r");
  fgets(string, 3, ip_m);
}

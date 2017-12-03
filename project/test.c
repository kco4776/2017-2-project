#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *test_movie = fopen("movie_log", "r");
  char tag[10];
  int serial;
  char title[50];
  char genre[50];
  char dirname[50];
  int year;
  char runtime[4];
  char names[100];
  char *p;

  fscanf(test_movie, "%[^:]", tag);
  printf("tag:%s\n", tag);
  fseek(test_movie, 1, SEEK_CUR);
  fscanf(test_movie, "%1d", &serial);
  printf("serial:%d\n", serial);
  fseek(test_movie, 1, SEEK_CUR);
  fscanf(test_movie, "%[^:]", title);
  printf("title:%s\n", title);
  fseek(test_movie, 1, SEEK_CUR);
  fscanf(test_movie, "%[^:]", genre);
  printf("genre:%s\n", genre);
  fseek(test_movie, 1, SEEK_CUR);
  fscanf(test_movie, "%[^:]", dirname);
  printf("director:%s\n", dirname);
  fseek(test_movie, 1, SEEK_CUR);
  fscanf(test_movie, "%4d", &year);
  printf("year:%d\n", year);
  fseek(test_movie, 1, SEEK_CUR);
  fscanf(test_movie, "%[^:]", runtime);
  printf("time:%s\n", runtime);
  fseek(test_movie, 1, SEEK_CUR);
  fscanf(test_movie, "%[^\n]", names);
  printf("names:%s\n", names);
  p = strtok(names, ",");
  printf("name:%s\n", p);
  while(p = strtok(NULL, ", "))
    printf("name:%s\n", p);
}

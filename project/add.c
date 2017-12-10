#include "struct.h"

void add_m(link_d *data) {
  FILE *movie_log = fopen("movie_log", "a");

  char *string;
  string = (char *)calloc(100, sizeof(char));

  printf("title > ");
  fgets(get_data(string), 100, stdin);
  if(check_mv_record(data, string))
    printf("You have the same record.\n");
  else {
    fprintf(movie_log, "add:%d:", count_serial(data, 1)+1);
    fprintf(movie_log, "%s:", replaceAll(delete_null(string), ":", "??;"));
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
    fflush(movie_log);
    fclose(movie_log);
    loading(data);
  }
}

void add_d(link_d *data) {
  FILE *director_log = fopen("director_log", "a");

  char *string;
  string = (char *)calloc(100, sizeof(char));

  printf("name > ");
  fgets(get_data(string), 100, stdin);
  if(check_dir_record(data, string))
    printf("You have the same record.\n");
  else {
    fprintf(director_log, "add:%d:", count_serial(data, 2)+1);
    fprintf(director_log, "%s:", delete_null(string));
    printf("sex > ");
    fgets(get_data(string), 100, stdin);
    fprintf(director_log, "%s:", delete_null(string));
    printf("birth > ");
    fgets(get_data(string), 100, stdin);
    fprintf(director_log, "%s:", delete_null(string));
    printf("best_movies > ");
    fgets(get_data(string), 100, stdin);
    fprintf(director_log, "%s\n", replaceAll(delete_null(string), ":", "??;"));
    fclose(director_log);
    loading(data);
  }
}

void add_a(link_d *data) {
  FILE *actor_log = fopen("actor_log", "a");

  char *string;
  string = (char *)calloc(100, sizeof(char));

  printf("name > ");
  fgets(get_data(string), 100, stdin);
  if(check_act_record(data, string))
    printf("You have the same record.\n");
  else {
    fprintf(actor_log, "add:%d:", count_serial(data, 3)+1);
    fprintf(actor_log, "%s:", delete_null(string));
    printf("sex > ");
    fgets(get_data(string), 100, stdin);
    fprintf(actor_log, "%s:", delete_null(string));
    printf("birth > ");
    fgets(get_data(string), 100, stdin);
    fprintf(actor_log, "%s:", delete_null(string));
    printf("best_movies > ");
    fgets(get_data(string), 100, stdin);
    fprintf(actor_log, "%s\n", replaceAll(delete_null(string), ":", "??;"));
    fclose(actor_log);
    loading(data);
  }
}

int check_mv_record(link_d *data, char *string) {
  movie *tmp = data->mv;
  while(tmp != NULL) {
    if(!strncmp(string, tmp->title, strlen(tmp->title)))
      return 1;
    tmp = tmp->next;
  }
  return 0;
}

int check_act_record(link_d *data, char *string) {
  actor *tmp = data->act;
  while(tmp != NULL) {
    if(!strncmp(string, tmp->name, strlen(tmp->name)))
      return 1;
    tmp = tmp->next;
  }
  return 0;
}

int check_dir_record(link_d *data, char *string) {
  director *tmp = data->dir;
  while(tmp != NULL) {
    if(!strncmp(string, tmp->name, strlen(tmp->name)))
      return 1;
    tmp = tmp->next;
  }
  return 0;
}

char *delete_null(char *string) {
  int i=0;
  while(*(string+i) != '\n')
    i++;
  *(string+i) = '\0';
  return string;
}

char *get_data(char *p) {
  free(p);
  p = (char *)calloc(100, sizeof(char));
  return p;
}

int count_serial(link_d *data, int mode) {
  if(mode == 1) {
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
  else if(mode == 2) {
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
  else if(mode == 3) {
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

char *replaceAll(char *s, const char *olds, const char *news) {
  char *result, *sr;
  size_t i, count = 0;
  size_t oldlen = strlen(olds); if (oldlen < 1) return s;
  size_t newlen = strlen(news);


  if (newlen != oldlen) {
    for (i = 0; s[i] != '\0';) {
      if (memcmp(&s[i], olds, oldlen) == 0) count++, i += oldlen;
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

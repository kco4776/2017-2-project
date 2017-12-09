#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct movie {
  int serial;
  char *title;
  char *genre;
  struct director_p *mv_dir;
  char *year;
  char *time;
  struct actor_p *mv_act;
  struct movie *next;
} movie;

typedef struct actor {
  int serial;
  char *name;
  char sex;
  char *birth;
  struct movie_p *best;
  struct actor *next;
} actor;

typedef struct director {
  int serial;
  char *name;
  char sex;
  char *birth;
  struct movie_p *best;
  struct director *next;
} director;

typedef struct movie_p {
  char *title;
  struct movie *mv_p;
  struct movie_p *next;
} movie_p;

typedef struct actor_p {
  char *name;
  struct actor *act_p;
  struct actor_p *next;
} actor_p;

typedef struct director_p {
  char *name;
  struct director *dir_p;
} director_p;

typedef struct link {
  struct movie *mv;
  struct actor *act;
  struct director *dir;
} link;

void init_movie(link *data);
void add_actorp(actor_p **tmp, char *actor);
void init_director(link *data);
void add_moviep(movie_p **tmp, char *best_mv);
void init_actor(link *data);
void link_data(link *data);
void loading(link *data);
void add_m(link *data);
void add_d(link *data);
void add_a(link *data);
char *delete_null(char *string);
char *get_data(char *p);
int count_serial(link *data, int mode);
void print_m(link *data, int num);
char* birth_check(actor_p *tmp_ap);

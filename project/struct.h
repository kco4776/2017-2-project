#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

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

typedef struct link_d {
  struct movie *mv;
  struct actor *act;
  struct director *dir;
} link_d;

void init_movie(link_d *data);
void add_actorp(actor_p **tmp, char *actor);
void init_director(link_d *data);
void add_moviep(movie_p **tmp, char *best_mv);
void init_actor(link_d *data);
void link_data(link_d *data);
void loading(link_d *data);

void add_m(link_d *data);
void add_d(link_d *data);
void add_a(link_d *data);
int check_mv_record(link_d *data, char *string);
int check_act_record(link_d *data, char *string);
int check_dir_record(link_d *data, char *string);
char *delete_null(char *string);
char *get_data(char *p);
int count_serial(link_d *data, int mode);
char *replaceAll(char *s, const char *olds, const char *news);

void print_m(link_d *data, int num);
void print_d(link_d *data, int num);
void print_a(link_d *data, int num);
char* act_birth_check(actor_p *tmp_ap);
char* dir_birth_check(director_p *tmp_dp);
char* mv_year_check(movie_p *tmp);
char* mv_time_check(movie_p *tmp);

void make_mvlist(void);
void make_dirlist(void);
void make_actlist();

void ctrl_c(int sig);
int command_num(char *command);

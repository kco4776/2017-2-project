#include "struct.h"

void delete_m(link *data, int num) {
  movie *tmp = data->mv;
  while(tmp->serial != num) {
    tmp = tmp->next;
    if(tmp == NULL)
      break;
  }
  
}

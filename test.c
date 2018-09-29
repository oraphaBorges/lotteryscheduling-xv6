#include "types.h"
#include "stat.h"
#include "user.h"
#include "rand.c"

#define N 50

int main(){
  int proc[N], i, chosen_one, r_tickets = 50;
  for(i=0;i<N;++i) {
    chosen_one = rand() % r_tickets;
    proc[i] = fork(chosen_one);
    if (proc[i] < 0)
      return 0;
    else if (proc[i] == 0)
      for(;;);
  }
  exit();
  return 0;
}

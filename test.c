#include "types.h"
#include "stat.h"
#include "user.h"
#include "rand.c"

#define N 20                          // Quantidade de processos

int main(){

  int proc[N], i;
  int chosen_one;
  int r_tickets = 50;                 // Intervalo da quantidade de tíckets
                                      //  que será sorteado

  for(i=0;i<N;++i) {                  // Percorrendo os processos para atribuir
                                      //  os bilhetes

    chosen_one = rand() % r_tickets;  // Quantidade de tíckets escolhido
    proc[i] = fork(chosen_one);       // Atribuindo a quantidade de tícketes
                                      //  aos tíckets.

    if (proc[i] < 0)                  // Tratamento de erro das atribuições de  
                                      //  tíckets
      return 0;
    else if (proc[i] == 0)
      for(;;);
  }
  exit();
  return 0;
}

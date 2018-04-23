#include <stdio.h>
#include "global.h"

void printA(struct Board1 *A){
    int i = 0, j = 0;
    while(j < N){
      printf("\n %2d", A[j].Y);
      while(i < (j + 8)){
          printf("%2c",A[i].name_f);
          i++;
      }
      j = i;
    }
    printf("\n   ");
    while((i - 8) < N){printf("%2c", A[i - 8].X); i++;}
}

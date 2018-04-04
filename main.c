#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main(){
  FILE *board;
  struct Board1{
      int Y;
      char name_f;
      char X;
  };
  struct Board1 A[64];
  int i = 0, j = 0, k = 1;
  board = fopen("board.txt", "r");
  while(j < 64){
    fscanf(board, "%d\n", &(A[j].Y));
    printf("\n %2d", A[j].Y);
    while(i < (j + 8)){
        A[i].Y = A[j].Y;
        if((k > 2) && (k < 7)) A[i].name_f = ' ';
        else fscanf(board,"%c\n", &(A[i].name_f));
        printf("%2c",A[i].name_f);
        i++;
    }
    j = i;
    k++;
  }
  printf("\n   ");
  i = 0;
  while(i < (j - 8)){
      while((j - 8) < 64){
          fscanf(board,"%c\n",&(A[j - 8].X));
          A[i].X = A[j - 8].X;
          j++;
          i++;
      }
      j = 64;
  }
  while((j - 8) < 64){ printf("%2c", A[j - 8].X); j++;}
  //printf("\n A[%d][%c] - !%c!", A[0].Y, A[0].X, A[0].name_f);
}

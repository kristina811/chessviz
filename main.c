#include<stdio.h>

#define N 10

int main(){
  FILE *board;
  char arr[N];
  board = fopen("board.txt","r");
  while (fgets(arr, N, board) !=  NULL)
    printf("%s", arr);
  printf("\n");
  fclose(board);
  }

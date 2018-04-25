#include <stdio.h>
#include <conio.h>
#include "functions.h"
#include "global.h"

int main(){
  FILE *board;
  struct Board1 A[N];
  int i = 0, j = 0, k = 1, color = 0;
  board = fopen("board.txt", "r");
  /*recording from the file to the structure of the name of the figures and the position on Y*/
  while(j < N){ //64 possible positions of figures
    fscanf(board, "%d\n", &(A[j].Y)); /*write the first character from file to position Y*/
    while(i < (j + 8)){
        //The Y position changes after 8 characters
        A[i].Y = A[j].Y;
        //position where are no figures
        if((k > 2) && (k < 7)) A[i].name_f = ' ';
        //write figures
        else fscanf(board,"%c\n", &(A[i].name_f));
        i++;
    }
    j = i;  //provides a change of position on Y
    k++;
  }
  i = 0;
  //added position of elements on X
  while(i < (j - 8)){
      while((j - 8) < N){
          fscanf(board,"%c\n",&(A[j - 8].X));
          A[i].X = A[j - 8].X;
          j++; i++;
      }
      j = 64;
  }
  printA(A);
  while(k){
      move(A, color);
      printA(A);
      printf("\n 1 - make a move  0 - give in  ");
      scanf("%d", &k);
      color = 1 - color;
  }
  printA(A);
  fclose(board);
  getch();
}

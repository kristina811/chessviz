#include <stdio.h>
#include "print.h"
#include "global.h"

int check_Y(char, int, int, int);

void move(struct Board1 *A, int color){
    int Y_first, Y_last;
    char X_first, X_last;
    char temp;
    fflush(stdin);
    printf("\n enter your move: ");
    scanf("%c%d - %c%d", &X_first, &Y_first, &X_last, &Y_last);
    for(int i = 0; i < N; i++){
        if((A[i].X == X_first) && (A[i].Y == Y_first)) {
            temp = A[i].name_f;
            for(int j = 0; j < N; j++){
                if((A[j].X == X_last) && (A[j].Y == Y_last)){
                    if(check_Y(temp, Y_first, Y_last, color)){
                        A[i].name_f = A[j].name_f;
                        A[j].name_f = temp;
                    }
                    else move(A, color);
                }
            }
        }
    }
}

int check_Y(char temp, int Y_first, int Y_last, int color){
    if(color){
        if((temp == 'P') && (Y_first == 2) && ((Y_last == 3) || (Y_last == 4)))
            return 1;
        if((temp == 'P') && (Y_last == Y_first + 1))
            return 1;
    }
    if(!color){
        if((temp == 'p') && (Y_first == 7) && ((Y_last == 6) || (Y_last == 5)))
            return 1;
        if((temp == 'p') && Y_last == Y_first - 1)
            return 1;
    }
    return 0;
}

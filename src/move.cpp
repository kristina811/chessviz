#include <stdio.h>
#include "print.h"
#include "global.h"

int check_X(char, int, int);

void move(struct Board1 *A, int color){
    int Y_first, Y_last;
    char X_first, X_last;
    char temp_name;
    printf("\n enter your move: ");
    scanf("%c%d - %c%d", &X_first, &Y_first, &X_last, &Y_last);
    for(int i = 0; i < N; i++){
        if((A[i].X == X_last) && (A[i].Y == Y_last)) {
            temp_name = A[i].name_f;
        for(int j = 0; j < N; j++){
            if((A[j].X == X_first) && (A[j].Y == Y_first)){
                A[i].name_f = A[j].name_f;
                A[j].name_f = temp_name;
            }
        }
    }
}

int check_X(char temp, int X_first, int X_last){
    if((temp == 'P') && (X_first == 2) && (X_last == 3 || X_last == 4))
    return 1;
    return 0;
}

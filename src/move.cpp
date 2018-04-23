#include "print.h"
#include <stdio.h>
#include "global.h"

void move(struct Board1 *A){
    int Y_first, Y_last;
    char X_first, X_last;
    char temp1;
    printf("\n enter your move: ");
    scanf("%c%d - %c%d", &X_first, &Y_first, &X_last, &Y_last);
    for(int i = 0; i < N; i++){
        if((A[i].X == X_last) && (A[i].Y == Y_last)) {
            temp1 = A[i].name_f;
        for(int j = 0; j < N; j++){
            if((A[j].X == X_first) && (A[j].Y == Y_first)){
                A[i].name_f = A[j].name_f;
                A[j].name_f = temp1;
            }
        }
        }
    }
}

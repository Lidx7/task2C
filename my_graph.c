#include <stdio.h>
#include <stdlib.h>  
#include "my_mat.h"
#define J 10

int main(){
    char action;
    //int A[J][J];
    int x = 0;
    int y = 0;


    printf("Choose an action \nFor function 1, type 'A' \nFor function 2, type 'B' \nFor function 3, type 'C' \nTo exit, type 'D' or EOF \n");
    while(1){

        scanf(" %c", &action);

        switch (action){

            case 'A':
                getMatrix();
                break;
        
            case 'B':
                //printf("enter two parameters \n");
                scanf("%d", &x);
                scanf("%d", &y);
                int ans = isShortest(x, y);

                if(ans == 1)
                    printf("True \n");
                else
                    printf("False \n");

                break;

            case 'C':
                //printf("enter two parameters \n");
                scanf("%d", &x);
                scanf("%d", &y);

                printf("%d \n", shortestPath(x, y));
                break;

            case 'D':
                exit(0);
                break;

            case EOF:
                exit(0);
                break;


            default:
                printf("no such action. try again\n");

        }
    }
}
#include <stdio.h>
#include <stdlib.h>  
#include "my_mat.h"

int main(void){
    char action = '';

    printf("Choose an action /nFor function 1, type 'A' /nFor function 2, type 'B' /nFor function 3, type 'C' /nTo exit, type 'D' or EOF");
    while(true){

        scanf("%c", action);

        switch (action){

            case 'A':
                getMatrix();
                break;
        
            case 'B':
                shortestPath();
                break;

            case 'C':
                isShortest();
                break;

            case 'D':
                exit();
                break;

            case EOF:
                exit();
                break;

            default:
                printf("no such action. try again/n");

        }
    }
}
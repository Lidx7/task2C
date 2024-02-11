#include <stdio.h>
#include <stdlib.h>  
#include "my_mat.h"

int main(void){
    char action = '/0';
    char* actionPoint = &action;
    char catcher = '/0';

    printf("Choose an action \nFor function 1, type 'A' \nFor function 2, type 'B' \nFor function 3, type 'C' \nTo exit, type 'D' or EOF \n");
    while(1){

        scanf("%c", &action);
        //scanf("%c", &catcher); //catches the Enter key
        //printf("%c", catcher);

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
                exit(0);
                break;

            case EOF:
                exit(0);
                break;

            case '\n':
                break;

            default:
                printf("no such action. try again\n");

        }
    }
}
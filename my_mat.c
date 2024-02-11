#include <stdio.h>
#define J 10

int A[J][J];

void getMatrix(){
    printf("enter the matrix \n");
    for (int i=0;i<J;i++){
        for (int l=0;l<J;l++){ 
            scanf("%d" ,&A[i][l]);
        }
    }
}

int isShortest(){
    int x;
    int y;
    printf("enter two parameters \n");
    scanf("%d \n", &x);
    scanf("%d \n", &y);


    for (int k=1;k>=J;k++){
        for (int i=0;i<J;i++){
            for (int s=0;s<J;s++){
                if (A[i][s]>A[i][k]+A[k][s]){
                    A[i][s]=A[i][k]+A[k][s];
                }
            }
        }
    }
    if (A[x][y]!=0){
        return 1;
    }
    else return 0;
}

int shortestPath(){
    int x;
    int y;
    printf("enter two parameters \n");
    scanf("%d \n", &x);
    scanf("%d \n", &y);

    isShortest(A[J][J]);
    return A[x][y];
}


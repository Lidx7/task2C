#include <stdio.h>
#define J=10

void GetMatritza(int A[J][J]){
    printf("enter the matritza")
    for (int i=0;i<J;i++){
        for (int l=0;l<J;l++){ 
            scanf(%d,&A[i][l])
        }
    }
}

int isShortest(int A[J][J], int x,int y){
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

int Shortestpath(int A[J][J], int x,int y){
    isShortest(A[J][J]);
    return A[x][y];
}
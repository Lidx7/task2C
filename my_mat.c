#include <stdio.h>
#include "my_mat.h"
#define J 10
int A[J][J];


void getMatrix(){
    //printf("enter the matrix \n");
    for (int i=0; i<J; i++){
        for (int l=0; l<J; l++){ 
            scanf("%d" ,&A[i][l]);
            //printf("%d \n" ,A[i][l]);

        }
    }

}

int isShortest(int x ,int y){
    int min;
    if (x==y)return 0;
    for (int k=0;k<J;k++){
        for (int i=0;i<J;i++){
            for (int s=0;s<J;s++){
                if(A[i][k]!=0 && A[k][s]!=0)
               {
                   if ((A[i][s]>= A[i][k]+A[k][s])) min=A[i][k]+A[k][s];
                   else min = A[i][s];
                   if(min != A[i][s] || A[i][s]==0)
                   {
                       A[i][s] = A[i][k]+ A[k][s];
                   }   
               }
        }
    }
    }
    if (A[x][y]!=0){
        return 1;
    }
    else return 0;
}

int shortestPath(int x, int y){
    if(isShortest(x, y)){
        return A[x][y];
    }
    return -1;
}


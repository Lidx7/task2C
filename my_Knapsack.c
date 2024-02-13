#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define SIZE 5
#define MIN 0

int knapsack(int weights[], int values[], int selected_bool[]);
int max(int a, int b){
    if (a > b) return a;
    return b;

}

int main(){
    int num;
    char place;
    int selected_bool[SIZE] = {0, 0, 0, 0, 0};
    int values[SIZE];
    int weights[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%c ", &place);
        scanf("%d ", &num);
        values[i] = num;
        scanf("%d ", &num);
        weights[i] = num;  
    }
    knapsack(values, weights, selected_bool);

}

int compare(const void *a, const void *b) {
    float ratio_a = *((float *)a);
    float ratio_b = *((float *)b);
    if (ratio_a > ratio_b) return -1;
    if (ratio_a < ratio_b) return 1;
    return 0;
}

int knapsack(int values[], int weights[], int selected_bool[]) {
    // int max = 20;
    // int min = 0;
    // int total = 0;
    // float ratio[SIZE] = {0};
    // for (int i = 0; i < SIZE; i++) {
    //     ratio[i] = (float)weights[i] / values[i];
    // }
    
    // qsort(ratio, SIZE, sizeof(float), compare);
    // int i = 0;
    // int koren_s = 0;
    // while (min < max&& koren_s<SIZE ) {
    //     for (int k = 4; k > -1; k--) {
    //         for (int i = 0; i < SIZE; i++) {
    //         if (ratio[k] == (float)weights[i]/ values[i]) {
    //             if (min + weights[i] <= max) {
    //                 total += values[i];
    //                 min += weights[i];
    //                 selected_bool[i] = 1;
    //             }
    //         }
    //     }
    //     koren_s++;}
    // }
    int m=20;
    int n=5;
    int weights1[6]={0};
    int values1[6]={0};
    for (int i = 1; i < SIZE+1; i++) {
        weights1[i] = weights[i-1];
        values1[i] = values[i-1];
    }
    int k[6][21];
    for (int i = 0; i <= n; i++) {
       for (int  w = 0; w <=m; w++) {
            if (i==0||w==0){
                k[i][w]=0;}
                else if (weights1[i]<=w){
                    k[i][w]=max(values1[i]+k[i-1][w-weights1[i]],k[i-1][w]);
                }
                else{
                    k[i][w]=k[i-1][w];
                }
            }
            }
    int total123 = k[5][20];
    while (n>0 && m>0){
        if (k[n][m]!=k[n-1][m]){
            selected_bool[n]=1;
            n--;
            m=m-weights1[n];
        }
        else{
            n--;
        }
    }
    {
        /* code */
    }
    int total_new =0;
    char selected_bool11[] ={'A','B','C','D','E'};
    printf("Items that give the maximum profit: [");
    for (int i = 0; i < SIZE; i++) {
        if (selected_bool[i] == 1) {
             total_new += values[i];
            printf("%c ", selected_bool11[i]);
        }
    }
    total123 = k[5][20];
    printf("]\n");
    printf("%d\n", total123);


    return total_new;
}

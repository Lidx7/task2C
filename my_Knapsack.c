#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define SIZE 5
#define MIN 0

int knapsack(int weights[], int vlues[], int selected_bool[]){
    int max = MAX;
    int min = MIN;
    int total = 0;

    float ratio[SIZE] = {0};
    for (int i = 0; i<SIZE ;i++){
        ratio[i]=vlues[i]/weights[i];
    }
    qsort(ratio[]);
    while (min < max){
        int k=0;
        int i=0;
        while (min<max){
        while (i<5){
            if (ratio[k]=vlues[i]/weights[i]){
                if  (min+weights[i]<max){
                 total+=vlues[i];             
                 min+=weights[i];
                    selected_bool[i]=1;
                }

                i=0;
                k++;
            }
            i++;
            }
        }
    }

    return total;
}
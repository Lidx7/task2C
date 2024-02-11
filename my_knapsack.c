#include <stdio.h>
#define int max =20;
#define int size= 5;
#define int min =0
#define int totalValue=0;

int knapsack(int weights[],int vlues[],int selected_bool[]){
    double ratio[size] = {0};
    for (int i =0;i<soze;i++){
        ratio[i]=vlues[i]/weights[i];
    }
    qsort(ratio);
    while (int min <int max){
        int k=0
        int i=0;
        while(min<max){
        while (i<5){
            if (ratio[k]=vlues[i]/weights[i]){
                if (min+weights[i]<max){
                    totalValue+=vlues[i];             
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

    return totalValue;
}
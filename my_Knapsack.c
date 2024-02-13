#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define SIZE 5
#define MIN 0

int knapsack(int weights[], int values[], int selected_bool[]);

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
    
    char selected_bool11[] ={'A','B','C','D','E'};
    printf("%d\n", total);
    printf("Items that give the maximum profit: [");
    for (int i = 0; i < SIZE; i++) {
        if (selected_bool[i] == 1) {
            printf("%c ", selected_bool11[i]);
        }
    }
    printf("]");

    return total;
}

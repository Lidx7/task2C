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

int compare(const void *a, const void *b) {
    float ratio_a = *((float *)a);
    float ratio_b = *((float *)b);
    if (ratio_a > ratio_b) return -1;
    if (ratio_a < ratio_b) return 1;
    return 0;
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


int knapsack(int values[], int weights[], int selected_bool[]) {
    int k[SIZE+1][MAX+1] = {0};
    int val_org;
    int wei_org;
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= MAX; j++)
        {
            if(i>0||j>0){
                k[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= MAX; j++)
        {
            val_org = values[i-1];
            wei_org = weights[i-1];
            if (wei_org <= j)
            {
                k[i][j] = max(val_org + k[i-1][j-wei_org], k[i-1][j]);
            }
            else
            {
                k[i][j] = k[i][j-1];
            }
        }

    }
    int total123 = k[SIZE][MAX];
    int s = MAX;
    int r = SIZE;
    while (r > 0 && s> 0)
    {
        if (k[r][s] != k[r-1][s])
        {
            selected_bool[r-1] = 1;
            s -= weights[r-1];
        }
        r--;
    }

    char selected_bool11[] ={'a','b','c','d','e'};
    int place = 0;

    printf("Maximum profit: %d\n", total123);
    printf("Selected items: ");
    for (int i = 0; i < SIZE; i++) {
        if (selected_bool[i] == 1) {
            if(place != 0) printf(" ");
            printf("%c", selected_bool11[i]);
            place++;
        }
    }


    // for(int i = 0; i < SIZE; i++) {
    //     if(selected_bool[i] == 1) {
    //         if(place != 0) printf(" ");
    //         place++;

    //         switch (i) {
    //             case 0:
    //                 printf("a");
    //                 break;
    //             case 1:
    //                 printf("b");
    //                 break;
    //             case 2:
    //                 printf("c");
    //                 break;
    //             case 3:
    //                 printf("d");
    //                 break;
    //             case 4:
    //                 printf("e");
    //                 break;
    //         }
    //     }
    // }


    // for (int i = 0; i < SIZE; i++) {
    //     if (selected_bool[i] == 1) {
    //         total_new += values[i];
    //         selected_result[place*2] = selected_bool11[i];
    //         selected_result[place+1] = ' ';
    //         last_char = place+1;
    //         place *= 2;
    //     }
    // }
    // selected_result[last_char] = '\0';
    // printf("%s\n", selected_result);



    return 0;
}

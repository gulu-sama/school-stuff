#include <stdio.h>
#define MAX 100

int max(int a, int b) {
    if (a>b)
        return a;
    else
        return b;
}
int knapsack(int capacity, int num, int weight[], int profit[]){
    int x[MAX][MAX];
    int i,j;

    for (i=0;i<=num;i++){
        for (j=0;j<=capacity;j++){
            if (i==0||j==0) {
                x[i][j] = 0;
            } else if (weight[i-1]<=j){
                x[i][j] = max(x[i-1][j],x[i-1][j-weight[i-1]] + profit[i-1]);
            }else{
                x[i][j]=x[i-1][j];
            }
        }
    }

    return x[num][capacity];
}

int main() {
    int num, i, capacity;
    int weight[MAX], profit[MAX];

    printf("No. of items: ");
    scanf("%d",&num);

    if (num<=0||num>MAX) {
        printf("Invalid number of items.\n");
        return 1;
    }

    for (i=0;i<num;i++) {
        printf("Put 'profit' and 'weight' for item %d: ", i + 1);
        scanf("%d %d",&profit[i],&weight[i]);

        if (profit[i]<0 || weight[i]<=0) {
            printf("Invalid profit or weight.\n");
            return 1;
        }
    }

    printf("Enter maximum: ");
    scanf("%d", &capacity);

    if (capacity<=0 || capacity >MAX) {
        printf("Invalid knapsack capacity!!!.\n");
        return 1;
    }

    int result=knapsack(capacity, num, weight, profit);
    printf("Maximum value is: %d\n", result);

    return 0;
}

/* 
No. of items: 7
Put 'profit' and 'weight' for item 1: 2 10
Put 'profit' and 'weight' for item 2: 3 5
Put 'profit' and 'weight' for item 3: 5 15
Put 'profit' and 'weight' for item 4: 7 7
Put 'profit' and 'weight' for item 5: 1 6
Put 'profit' and 'weight' for item 6: 4 18
Put 'profit' and 'weight' for item 7: 1 3
Enter maximum: 15
Maximum value is: 11
*/
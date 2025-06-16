#include <stdio.h>
#include<time.h>
#define INF 999

void printMatrix(int matrix[][100], int nV, int iteration);
void floydWarshall(int graph[][100], int nV);

int main() {
    int nV;
    clock_t start,end;
    double total_time;
    start = clock();
    
    printf("Enter the number of vertices: ");
    scanf("%d", &nV);
    
    int graph[100][100];
    
    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    floydWarshall(graph, nV);
    
    end=clock();
    total_time=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nThe total time : %f second .",total_time);
    return 0;
}

void floydWarshall(int graph[][100], int nV) {
    int matrix[100][100], i, j, k;

    for (i = 0; i < nV; i++)
        for (j = 0; j < nV; j++)
            matrix[i][j] = graph[i][j];

    for (k = 0; k < nV; k++) {
        printf("\nIteration %d:", k + 1);
        for (i = 0; i < nV; i++) {
            for (j = 0; j < nV; j++) {
                if (matrix[i][k] != INF && matrix[k][j] != INF && matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
        printMatrix(matrix, nV, k + 1);
    }
}

void printMatrix(int matrix[][100], int nV, int iteration) {
    printf("\nCost matrix after iteration %d:\n", iteration);
    for (int i = 0; i < nV; i++) {
        for (int j = 0; j < nV; j++) {
            if (matrix[i][j] == INF)
                printf("%5s", "INF");
            else
                printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

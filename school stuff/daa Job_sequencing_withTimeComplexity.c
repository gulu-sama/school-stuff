#include <stdio.h>
#include <time.h>
#define MAX 100

typedef struct Job {
    char id[5];
    int deadline;
    int profit;
} Job;
void job_Sequencing_greedy(Job jobs[], int n);
int minValue(int x, int y) {
  if(x < y) return x;
  return y;
}
int main(void) {
    int i, j, n;
    clock_t start, end;       // Clock variables to measure execution time
    double total_time;
    Job jobs[MAX], temp;
    
    start = clock();
    
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter Job ID, Deadline and Profit for job %d: ", i + 1);
        scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }
    
    
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (jobs[j + 1].profit > jobs[j].profit) {
                temp = jobs[j + 1];
                jobs[j + 1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
    printf("\n%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for (i = 0; i < n; i++) {
        printf("%10s %10d %10d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }
    job_Sequencing_greedy(jobs, n);
    
    end = clock();
    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTotal Execution Time: %f seconds\n", total_time);

    return 0;
}
void job_Sequencing_greedy(Job jobs[], int n) {
    int i, k, maxprofit;
    int timeslot[MAX];
    int filledTimeSlot = 0;
    int dmax = 0;
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > dmax) {
            dmax = jobs[i].deadline;
        }
    }
    for (i = 0; i <= dmax; i++) {
        timeslot[i] = -1;
    }
    printf("\ndmax: %d\n", dmax);
    for (i = 0; i < n; i++) {
        k = minValue(dmax, jobs[i].deadline);
        while (k >= 1) {
            if (timeslot[k] == -1) {
                timeslot[k] = i;
                filledTimeSlot++;
                break;
            }
            k--;
        }
        if (filledTimeSlot == dmax) {
            break;
        }
    }
    printf("\nRequired jobs sequence: ");
    for (i = 1; i <= dmax; i++) {
        if (timeslot[i] != -1)
            printf("%s", jobs[timeslot[i]].id);
        else
            printf("None");

        if (i < dmax) {
            printf(" --> ");
        }
    }
    maxprofit = 0;
    for (i = 1; i <= dmax; i++) {
        if (timeslot[i] != -1)
            maxprofit += jobs[timeslot[i]].profit;
    }
    printf("\nMax profit: %d\n", maxprofit);
}

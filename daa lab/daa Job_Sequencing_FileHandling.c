#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

typedef struct Job {
    char id[5];
    int deadline;
    int profit;
} Job;

void job_Sequencing_greedy(Job jobs[], int n, FILE *fp_output);
int minValue(int x, int y) {
    return (x < y) ? x : y;
}

int main(void) {
    int i, j, n;
    clock_t start, end;
    double total_time;
    Job jobs[MAX], temp;
    FILE *fp;

    start = clock();

    // Open the file for reading
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    // Read number of jobs
    fscanf(fp, "%d", &n);

    // Read job details
    for (i = 0; i < n; i++) {
        fscanf(fp, "%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }
    fclose(fp);  // Close after reading

    // Sort jobs by profit (descending)
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (jobs[j + 1].profit > jobs[j].profit) {
                temp = jobs[j + 1];
                jobs[j + 1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    // Open the file in append mode to write results
    fp = fopen("input.txt", "a");
    if (fp == NULL) {
        printf("Error opening input file for appending!\n");
        return 1;
    }

    // Display sorted jobs and write to file
    fprintf(fp, "\n%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for (i = 0; i < n; i++) {
        fprintf(fp, "%10s %10d %10d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }

    // Perform job sequencing and write output to file
    job_Sequencing_greedy(jobs, n, fp);

    end = clock();
    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    fprintf(fp, "\nTotal Execution Time: %f seconds\n", total_time);
    fclose(fp);

    printf("Job sequencing and results appended to input.txt successfully.\n");
    return 0;
}

void job_Sequencing_greedy(Job jobs[], int n, FILE *fp_output) {
    int i, k, maxprofit = 0;
    int timeslot[MAX];
    int filledTimeSlot = 0;
    int dmax = 0;

    // Find maximum deadline
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > dmax) {
            dmax = jobs[i].deadline;
        }
    }

    // Initialize timeslots
    for (i = 0; i <= dmax; i++) {
        timeslot[i] = -1;
    }

    fprintf(fp_output, "\nMaximum deadline (dmax): %d\n", dmax);

    // Assign jobs to timeslots greedily
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

    // Print job sequence
    fprintf(fp_output, "\nRequired job sequence: ");
    for (i = 1; i <= dmax; i++) {
        if (timeslot[i] != -1)
            fprintf(fp_output, "%s", jobs[timeslot[i]].id);
        else
            fprintf(fp_output, "None");

        if (i < dmax) {
            fprintf(fp_output, " --> ");
        }
    }

    // Calculate max profit
    for (i = 1; i <= dmax; i++) {
        if (timeslot[i] != -1)
            maxprofit += jobs[timeslot[i]].profit;
    }

    fprintf(fp_output, "\nMaximum Profit: %d\n", maxprofit);
}


#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct Job {
  char id[10];
  int deadline;
  int profit;
} Job;

void job_Sequencing_greedy(Job jobs[], int n);
int minValue(int x, int y) { 
    return (x < y) ? x : y; 
    
}

int main(void) {
  int i, j, n;
  
  printf("Enter the number of jobs: ");
  scanf("%d", &n);

  Job jobs[n], temp;

  // Taking input from user
  for(i = 0; i < n; i++) {
    printf("\nEnter Job ID for job %d: ", i + 1);
    scanf("%s", jobs[i].id);
    printf("Enter Deadline for job %d: ", i + 1);
    scanf("%d", &jobs[i].deadline);
    printf("Enter Profit for job %d: ", i + 1);
    scanf("%d", &jobs[i].profit);
  }

  // Sort the jobs by profit in descending order
  for(i = 1; i < n; i++) {
    for(j = 0; j < n - i; j++) {
      if(jobs[j+1].profit > jobs[j].profit) {
        temp = jobs[j+1];
        jobs[j+1] = jobs[j];
        jobs[j] = temp;
      }
    }
  }

  printf("\n%10s %10s %10s\n", "Job", "Deadline", "Profit");
  for(i = 0; i < n; i++) {
    printf("%10s %10d %10d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
  }

  job_Sequencing_greedy(jobs, n);

  return 0;
}

void job_Sequencing_greedy(Job jobs[], int n) {
  int i, j, k, maxprofit = 0;
  int timeslot[MAX];
  int filledTimeSlot = 0;
  int dmax = 0;

  for(i = 0; i < n; i++) {
    if(jobs[i].deadline > dmax) {
      dmax = jobs[i].deadline;
    }
  }

  for(i = 1; i <= dmax; i++) {
    timeslot[i] = -1;
  }

  printf("\nMax Deadline: %d\n", dmax);

  for(i = 1; i <= n; i++) {
    k = minValue(dmax, jobs[i - 1].deadline);
    while(k >= 1) {
      if(timeslot[k] == -1) {
        timeslot[k] = i-1;
        filledTimeSlot++;
        break;
      }
      k--;
    }

    if(filledTimeSlot == dmax) {
      break;
    }
  }

  printf("\nSelected Jobs: ");
  for(i = 1; i <= dmax; i++) {
    printf("%s", jobs[timeslot[i]].id);
    if(i < dmax) {
      printf(" --> ");
    }
  }

  for(i = 1; i <= dmax; i++) {
    maxprofit += jobs[timeslot[i]].profit;
  }
  printf("\nMax Profit: %d\n", maxprofit);
}

/*
       Job   Deadline     Profit
        j4          2        300
        j1          5        200
        j3          3        190
        j2          3        180
        j5          4        120
        j6          2        100
dmax: 5

Required Jobs: j2 --> j4 --> j3 --> j5 --> j1
Max Profit: 990
*/
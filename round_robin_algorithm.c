#include <stdio.h>

typedef struct {
    int processID;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnAroundTime;
} Process;

void findWaitingTime(Process processes[], int n, int quantum) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        processes[i].remainingTime = processes[i].burstTime;
    }

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                done = 0;
                if (processes[i].remainingTime > quantum) {
                    time += quantum;
                    processes[i].remainingTime -= quantum;
                } else {
                    time += processes[i].remainingTime;
                    processes[i].waitingTime = time - processes[i].burstTime;
                    processes[i].remainingTime = 0;
                }
            }
        }
        if (done) break;
    }
}

void findTurnAroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void findAverageTimes(Process processes[], int n) {
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
    }
    printf("\nAverage Waiting Time: %.2f", (float)totalWaitingTime / n);
    printf("\nAverage Turnaround Time: %.2f", (float)totalTurnAroundTime / n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    Process processes[n];
    
    for (int i = 0; i < n; i++) {
        processes[i].processID = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    findWaitingTime(processes, n, quantum);
    findTurnAroundTime(processes, n);

    printf("\nProcess ID | Burst Time | Waiting Time | Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d          | %d          | %d            | %d\n", processes[i].processID, processes[i].burstTime, processes[i].waitingTime, processes[i].turnAroundTime);
    }

    findAverageTimes(processes, n);

    return 0;
}


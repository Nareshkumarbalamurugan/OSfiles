#include <stdio.h>

typedef struct {
    int processID;
    int burstTime;
    int priority;
    int waitingTime;
    int turnAroundTime;
} Process;

void sortByPriority(Process processes[], int n) {
    Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].priority > processes[j].priority) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void findWaitingTime(Process processes[], int n) {
    processes[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}

void findTurnAroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].burstTime + processes[i].waitingTime;
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
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].processID = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
    }

    sortByPriority(processes, n);
    findWaitingTime(processes, n);
    findTurnAroundTime(processes, n);

    printf("\nProcess ID | Burst Time | Priority | Waiting Time | Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d          | %d          | %d        | %d            | %d\n", processes[i].processID, processes[i].burstTime, processes[i].priority, processes[i].waitingTime, processes[i].turnAroundTime);
    }

    findAverageTimes(processes, n);

    return 0;
}


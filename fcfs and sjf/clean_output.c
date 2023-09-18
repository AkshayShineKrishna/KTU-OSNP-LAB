#include <stdio.h>

int n;

struct process
{
    char pid[5];
    int bt;
    int tat;
    int wt;
} p[10];

void waitingTime()
{
    for (int i = 1; i < n; i++)
    {
        p[i].wt = p[i - 1].tat;
    }
}

void turnAroundTime()
{
    for (int i = 1; i < n; i++)
    {
        p[i].tat = p[i - 1].tat + p[i].bt;
    }
}

void readProcessDetails()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the details of process %d:\n", i + 1);
        printf("PID: ");
        scanf("%s", p[i].pid);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
    }
}

void displayProcessDetails()
{
    printf("\n\nProcess Details:\n");
    printf("| %-5s | %-10s | %-12s | %-15s |\n", "PID", "Burst Time", "Waiting Time", "Turnaround Time");
    printf("|-------|------------|--------------|-----------------|\n");
    for (int i = 0; i < n; i++)
    {
        printf("| %-5s | %-10d | %-12d | %-15d |\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
    }
}

float calculateAvgWaitingTime()
{
    float sum = 0, avg = 0;
    for (int i = 0; i < n; i++)
    {
        sum += p[i].wt;
    }
    avg = sum / n;
    return avg;
}

float calculateAvgTurnAroundTime()
{
    float sum = 0, avg = 0;
    for (int i = 0; i < n; i++)
    {
        sum += p[i].tat;
    }
    avg = sum / n;
    return avg;
}

void displayProcessSchedule()
{
    printf("\nProcess Schedule:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s", p[i].pid);
        if (i != n - 1)
        {
            printf(" -> ");
        }
    }
    printf("\n");
}

void sortProcess()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].bt > p[j + 1].bt)
            {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void initializeProcess() {
    p[0].tat = p[0].bt;
    p[0].wt = 0;
}

void fcfs()
{
    printf("\n\nFCFS:\n");
    initializeProcess();
    turnAroundTime();
    waitingTime();
    displayProcessDetails();
    displayProcessSchedule();
    float avgWt = calculateAvgWaitingTime();
    float avgTat = calculateAvgTurnAroundTime();
    printf("\nAverage Waiting Time: %.2f ms", avgWt);
    printf("\nAverage Turnaround Time: %.2f ms", avgTat);
}

void sjf()
{
    printf("\n\nSJF:\n");
    sortProcess();
    initializeProcess();
    turnAroundTime();
    waitingTime();
    displayProcessDetails();
    displayProcessSchedule();
    float avgWt = calculateAvgWaitingTime();
    float avgTat = calculateAvgTurnAroundTime();
    printf("\nAverage Waiting Time: %.2f ms", avgWt);
    printf("\nAverage Turnaround Time: %.2f ms", avgTat);
}

int main()
{
    readProcessDetails();
    fcfs();
    sjf();
    return 0;
}

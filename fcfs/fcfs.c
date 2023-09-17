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
    for (int i = 0; i < n; i++)
    {
        printf("Enter the details of process [ %d / %d ] : \n", i + 1, n);
        printf("Enter the PID : ");
        scanf("%s", p[i].pid);
        printf("Enter the BURST TIME : ");
        scanf("%d", &p[i].bt);
        printf("-----------------------\n");
        if (i == 0)
        {
            p[i].tat = p[i].bt;
            p[0].wt = 0;
        }
    }
    turnAroundTime();
    waitingTime();
}

void displayProcessDetails()
{
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Details of process %d : \n", i + 1);
        printf("-----------------------\n");
        printf("pid : %s \n", p[i].pid);
        printf("burst time : %d \n", p[i].bt);
        printf("waiting time : %d \n", p[i].wt);
        printf("turn around time : %d \n", p[i].tat);
        printf("-----------------------\n");
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
    return (avg);
}

float calculateAvgTurnAroundTime()
{
    float avg = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += p[i].tat;
    }
    avg = sum / n;
    return (avg);
}

int main()
{
    printf("Enter the number of process : ");
    scanf("%d", &n);
    readProcessDetails();
    displayProcessDetails();
    float avgWt = calculateAvgWaitingTime();
    float avgTat = calculateAvgTurnAroundTime();
    printf("\nAverage Waiting Time : %.2f ms", avgWt);
    printf("\nAverage Turn Around Time : %.2f ms", avgTat);
    return 0;
}
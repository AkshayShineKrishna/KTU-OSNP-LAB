#include <stdio.h>

int size;

struct process
{
    char pid[5];
    int bt, tat, wt;
} p[10];

void waitingTime()
{
    for (int i = 1; i < size; i++)
    {
        p[i].wt = p[i - 1].tat;
    }
}

void turnAroundTime()
{
    for (int i = 1; i < size; i++)
    {
        p[i].tat = p[i - 1].tat + p[i].bt;
    }
}

void readProcessDetails()
{
    printf("Enter the number of processes: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("\nEnter the details of process %d:\n", i + 1);
        printf("PID: ");
        scanf("%s", p[i].pid);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
    }
}

float calculateAvgWaitingTime()
{
    float sum = 0, avg = 0;
    for (int i = 0; i < size; i++)
    {
        sum += p[i].wt;
    }
    avg = sum / size;
    return avg;
}

float calculateAvgTurnAroundTime()
{
    float sum = 0, avg = 0;
    for (int i = 0; i < size; i++)
    {
        sum += p[i].tat;
    }
    avg = sum / size;
    return avg;
}

int calculateResultantStringLength()
{

    int totalLength = 0;
    for (int i = 0; i < size; i++)
    {
        totalLength += p[i].bt + 3;
    }

    return (totalLength + 1);
}

void drawLine()
{
    int resultant = calculateResultantStringLength();
    for (int i = 0; i < resultant; i++)
    {
        printf("-");
    }
}

void ganttChart()
{
    int spaceLength;
    printf("\nGantt Chart :\n\n");
    drawLine();
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("| %-*s ", p[i].bt, p[i].pid);
    }
    printf("|\n");
    drawLine();
    printf("\n0");
    for (int i = 0; i < size; i++)
    {
        if (p[i].tat >= 10)
        {
            spaceLength = p[i].bt + 1;
        }
        else
        {
            spaceLength = p[i].bt + 2;
        }
        for (int j = 0; j < spaceLength; j++)
        {
            printf(" ");
        }
        printf("%d", p[i].tat);
    }
    printf("\n");
}


void initializeProcess()
{
    p[0].tat = p[0].bt;
    p[0].wt = 0;
}

void fcfs()
{
    printf("\nFirst-Come-First-Served Scheduling (FCFS) :");
    initializeProcess();
    turnAroundTime();
    waitingTime();
}

int main()
{
    readProcessDetails();
    fcfs();
    ganttChart();
    float avgWt = calculateAvgWaitingTime();
    float avgTat = calculateAvgTurnAroundTime();
    printf("\nAverage Waiting Time: %.2f ms", avgWt);
    printf("\nAverage Turnaround Time: %.2f ms\n", avgTat);
    return 0;
}

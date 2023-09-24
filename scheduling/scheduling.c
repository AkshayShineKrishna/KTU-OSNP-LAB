#include <stdio.h>

int n;

struct process
{
    char pid[5];
    int bt, tat, wt, priority;
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

int calculateResultantStringLength()
{

    int totalLength = 0;
    for (int i = 0; i < n; i++)
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
    for (int i = 0; i < n; i++)
    {
        printf("| %-*s ", p[i].bt, p[i].pid);
    }
    printf("|\n");
    drawLine();
    printf("\n0");
    for (int i = 0; i < n; i++)
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
    float avgWt = calculateAvgWaitingTime();
    float avgTat = calculateAvgTurnAroundTime();
    printf("\nAverage Waiting Time: %.2f ms", avgWt);
    printf("\nAverage Turnaround Time: %.2f ms\n", avgTat);
    ganttChart();
}

void sjf()
{
    printf("\nShortest Job First Scheduling (SJF) :");
    sortProcess();
    initializeProcess();
    turnAroundTime();
    waitingTime();
    float avgWt = calculateAvgWaitingTime();
    float avgTat = calculateAvgTurnAroundTime();
    printf("\nAverage Waiting Time: %.2f ms", avgWt);
    printf("\nAverage Turnaround Time: %.2f ms\n", avgTat);
    ganttChart();
}

void sortPriority()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].priority > p[j + 1].priority)
            {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void readPriority() {
    printf("\nEnter the priority value for the processes : \n");
    for(int i=0;i<n;i++){
        printf("PID (%s) : ",p[i].pid);
        scanf("%d",&p[i].priority);
    }
}

void prioritySchedule() {
    printf("\nPriority Schedule (PS) :");
    readPriority();
    sortPriority();
    initializeProcess();
    turnAroundTime();
    waitingTime();
    float avgWt = calculateAvgWaitingTime();
    float avgTat = calculateAvgTurnAroundTime();
    printf("\nAverage Waiting Time: %.2f ms", avgWt);
    printf("\nAverage Turnaround Time: %.2f ms\n", avgTat);
    ganttChart();
}

int main()
{
    readProcessDetails();
    fcfs();
    sjf();
    prioritySchedule();
    return 0;
}

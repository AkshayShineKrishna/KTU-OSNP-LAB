#include <stdio.h>
#include <string.h>

int size, timeQuantum, queueSize;

struct process
{
    char pid[5];
    int bt, tat, wt, remaining;
} p[10];

struct readyQueue
{
    char pid[5];
    int bt, tat;
} q[30];

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
        p[i].remaining = p[i].bt;
    }

    printf("\nEnter Time Quantum : ");
    scanf("%d", &timeQuantum);
}

void roundRobin()
{
    queueSize = 0;

    // varibale to store no. of completed processes
    int completed = 0;

    // variable to store cummulative burst time
    int currentTime = 0;

    // loops until all processes are completed
    while (completed < size)
    {
        // iterate over each process
        for (int i = 0; i < size; i++)
        {
            // checks for incomplete processes
            if (p[i].remaining != 0)
            {
                if (p[i].remaining > timeQuantum)
                {
                    strcpy(q[queueSize].pid, p[i].pid);
                    q[queueSize].bt += timeQuantum;
                    p[i].remaining -= timeQuantum;
                    currentTime += timeQuantum;
                    q[queueSize].tat = currentTime;
                }
                else if(p[i].remaining == timeQuantum){
                    strcpy(q[queueSize].pid, p[i].pid);
                    q[queueSize].bt += p[i].remaining;
                    currentTime += p[i].remaining;
                    p[i].tat = currentTime;
                    p[i].remaining = 0;
                    q[queueSize].tat = currentTime;
                    completed++;
                }
                else
                {
                    strcpy(q[queueSize].pid, p[i].pid);
                    q[queueSize].bt += p[i].remaining;
                    currentTime += p[i].remaining;
                    p[i].tat = currentTime;
                    p[i].remaining = 0;
                    q[queueSize].tat = currentTime;
                    completed++;
                }
                queueSize++;
            }
        }
    }
}

float calculateWaitingTime() {
    float sum = 0, avg = 0;
    for (int i = 0; i < size; i++)
    {
        p[i].wt = p[i].tat - p[i].bt;
        sum += p[i].wt;
    }
    avg = sum / size;
    return avg;
    
}

float calculateTurnAroundTime() {
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
    for (int i = 0; i < queueSize; i++)
    {
        /* calculating reguired length of top and bottom lines
           + 3 is for including divider( " | " ) and 2 extra spaces( " " ) in the print statement
        */
        totalLength += q[i].bt + 3;
    }

    // + 1 for including the last divider( " | " )
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
    for (int i = 0; i < queueSize; i++)
    {
        // * is the width specifier, so a min length of burst time will be printed with pid left aligned and extra spaces to the right
        printf("| %-*s ", q[i].bt, q[i].pid);
    }
    printf("|\n");
    drawLine();
    printf("\n0");
    for (int i = 0; i < queueSize; i++)
    {
        /* Note this step is not necessary just burst time as spacelenth is enough
           done just for proper spacing (beautification) */
        if (q[i].tat >= 10)
        {
            // if tat is 2 digits, then the first digit will be placed just before the divider
            spaceLength = q[i].bt + 1;
        }
        else
        {
             // if tat is 1 digit, then it will be placed under the divider
            spaceLength = q[i].bt + 2;
        }
        for (int j = 0; j < spaceLength; j++)
        {
            printf(" ");
        }
        printf("%d", q[i].tat);
    }
    printf("\n");
}
int main()
{
    readProcessDetails();
    roundRobin();
    float avgTat = calculateTurnAroundTime();
    float avgWt = calculateWaitingTime();
    ganttChart();
    printf("\nAverage Waiting Time: %.2f ms", avgWt);
    printf("\nAverage Turnaround Time: %.2f ms\n", avgTat);
    return 0;
}
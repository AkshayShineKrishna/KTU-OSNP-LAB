#include <stdio.h>

int size;

struct process
{
    char pid[5];
    int bt, tat, wt, priority;
} p[10];

// code to display process table
// use this to see what's happening for better understanding 
void displayProcessDetails()
{
    printf("\n\nProcess Details:\n");
    printf("| %-5s | %-10s | %-12s | %-15s | %-10s |\n", "PID", "Burst Time", "Waiting Time", "Turnaround Time","Priority");
    printf("|-------|------------|--------------|-----------------|\n");
    for (int i = 0; i < size; i++)
    {
        printf("| %-5s | %-10d | %-12d | %-15d | %-10d |\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat,p[i].priority);
    }
}
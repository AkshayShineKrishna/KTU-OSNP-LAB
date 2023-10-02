# Output

## [First-Come-First-Served (FCFS)](https://github.com/AkshayShineKrishna/KTU-OSNP-LAB/blob/main/scheduling/fcfs.c)

```
Enter the number of processes: 3

Enter the details of process 1:
PID: p1
Burst Time: 5

Enter the details of process 2:
PID: p2
Burst Time: 3

Enter the details of process 3:
PID: p3
Burst Time: 4

First-Come-First-Served Scheduling (FCFS) :
Gantt Chart :

----------------------
| p1    | p2  | p3   |
----------------------
0       5     8     12

Average Waiting Time: 4.33 ms
Average Turnaround Time: 8.33 ms
```

## [Shortest Job First (SJF)](https://github.com/AkshayShineKrishna/KTU-OSNP-LAB/blob/main/scheduling/sjf.c)

```
Enter the number of processes: 4

Enter the details of process 1:
PID: p1
Burst Time: 5

Enter the details of process 2:
PID: p2
Burst Time: 3

Enter the details of process 3:
PID: p3
Burst Time: 4

Enter the details of process 4:
PID: p4
Burst Time: 2

Shortest Job First Scheduling (SJF) :
Gantt Chart :

---------------------------
| p4 | p2  | p3   | p1    |
---------------------------
0    2     5      9      14

Average Waiting Time: 4.00 ms
Average Turnaround Time: 7.50 ms
```

## [Priority Scheduling](https://github.com/AkshayShineKrishna/KTU-OSNP-LAB/blob/main/scheduling/priority.c)

```
Enter the number of processes: 4

Enter the details of process 1:
PID: p2
Burst Time: 5
Priority : 3

Enter the details of process 2:
PID: p4
Burst Time: 7
Priority : 1

Enter the details of process 3:
PID: p3
Burst Time: 2
Priority : 5

Enter the details of process 4:
PID: p1
Burst Time: 4
Priority : 2

Priority Schedule (PS) :
Gantt Chart :

-------------------------------
| p4      | p1   | p2    | p3 |
-------------------------------
0         7     11      16   18

Average Waiting Time: 8.50 ms
Average Turnaround Time: 13.00 ms
```

## [Round Robin](https://github.com/AkshayShineKrishna/KTU-OSNP-LAB/blob/main/scheduling/rr.c)

```
Enter the number of processes: 3

Enter the details of process 1:
PID: p1
Burst Time: 20

Enter the details of process 2:
PID: p2
Burst Time: 3

Enter the details of process 3:
PID: p3
Burst Time: 4

Enter Time Quantum : 4

Round Robin (RR) :
Gantt Chart :

-------------------------------------------------
| p1   | p2  | p3   | p1   | p1   | p1   | p1   |
-------------------------------------------------
0      4     7     11     15     19     23     27

Average Waiting Time: 6.00 ms
Average Turnaround Time: 15.00 ms
```

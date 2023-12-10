# Output

## EXIT()

```
KTU-OSNP-LAB/OS/System Calls$ cc exit.c
KTU-OSNP-LAB/OS/System Calls$ ./a.out
0
1
2
3
4
```

## OPEN() AND CLOSE()

```
KTU-OSNP-LAB/OS/System Calls$ cc OpenAndClose.c 
KTU-OSNP-LAB/OS/System Calls$ ./a.out
fd =3
file opened
file closed
```

## GETPPID() AND GETPID()

```
KTU-OSNP-LAB/OS/System Calls$ ./a.out
Process id of parent is 5344
Process id of child is 28262
```

## FORK()

```
KTU-OSNP-LAB/OS/System Calls$ ./a.out
parent has x = 0
child has x = 2
```

## WAIT()

```
KTU-OSNP-LAB/OS/System Calls$ ./a.out
child has x = 2
parent has x = 0
```

#include <stdio.h>

int bSize,pSize;

struct process{
    int pid;
    int size, bid;
}p[10];

struct block{
    int bid,size;
}b[10];

int main() {
    printf("Enter no of blocks : ");
    scanf("%d",&bSize);
    for (int i = 0; i < bSize; i++)
    {
        printf("Enter id :");
        scanf("%d",&b[i].bid);
        printf("Enter size :");
        scanf("%d",&b[i].size);
    }
    
    printf("Enter no of process : ");
    scanf("%d",&pSize);
    for (int i = 0; i < pSize; i++)
    {
        printf("Enter id :");
        scanf("%d",&p[i].pid);
        printf("Enter size :");
        scanf("%d",&p[i].size);
    }

    for (int i = 0; i < pSize; i++)
    {
        for (int j = 0; j < bSize; j++)
        {
            if (p[i].size <= b[j].size){
                p[i].bid = b[j].bid;
                b[j].size = b[j].size - p[i].size;
                break;

            }
        }
    }

    printf("First Fit : \n");
    printf("pid\tsize\tbid\n");
    for (int i = 0; i < pSize; i++)
    {
        printf("%d\t%d\t%d\n",p[i].pid,p[i].size,p[i].bid);
    }
    
    return 0;
}
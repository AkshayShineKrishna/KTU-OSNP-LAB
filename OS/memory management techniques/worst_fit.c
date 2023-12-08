#include <stdio.h>

int bSize,pSize;

struct process{
    int pid;
    int size, bid;
}p[10];

struct block{
    int bid,size;
}b[10];

void sort(){
    for (int i = 0; i < bSize; i++)
    {
        for (int j = 0; j < bSize - i -1; j++)
        {
            if (b[j].size < b[j+1].size){
                struct block temp;
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}

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
        sort();
        for (int j = 0; j < bSize; j++)
        {
            if (p[i].size <= b[j].size){
                p[i].bid = b[j].bid;
                b[j].size = b[j].size - p[i].size;
                break;

            }
        }
    }

    printf("Worst Fit : \n");
    printf("pid\tsize\tbid\n");
    for (int i = 0; i < pSize; i++)
    {
        printf("%d\t%d\t%d\n",p[i].pid,p[i].size,p[i].bid);
    }
    
    return 0;
}
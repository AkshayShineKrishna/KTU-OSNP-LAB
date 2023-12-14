#include <stdio.h>

int buffer, item, counter = 0, in = 0, out = 0;
int mq[10];

void send() {
    if (counter == buffer) {
        printf("Queue is full\n");
    } else {
        printf("Enter item: ");
        scanf("%d", &item);
        mq[in] = item;
        in = (in + 1) % buffer;
        counter++;
    }
}

void receive() {
    if (counter == 0) {
        printf("Empty queue\n");
    } else {
        item = mq[out];
        out = (out + 1) % buffer;
        counter--;
        printf("Received item: %d\n", item);
    }
}

void display() {
    printf("\nMessage queue:\n");
    if (counter > 0) {
        int i = out;
        do {
            printf("%d ", mq[i]);
            i = (i + 1) % buffer;
        } while (i != in);
    } else {
        printf("EMPTY");
    }
    printf("\n");
}

int main() {
    printf("Enter size of queue: ");
    scanf("%d", &buffer);
    int op;
    while (1) {
        printf("\nMENU\n1.SEND\n2.RECEIVE\n3.DISPLAY\n4.EXIT\nEnter your choice: ");
        scanf("%d", &op);
        if (op == 1) {
            send();
        } else if (op == 2) {
            receive();
        } else if (op == 3) {
            display();
        } else if (op == 4) {
            break;
        } else {
            printf("INVALID\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>


struct queue {
    int data;
    struct queue *next;
};

typedef struct queue node;
node *newnode;
node *front = NULL;
node *rear = NULL;

void enqueue(int);
void dequeue();
void display();

int main() {
    int choice, x;
    do {
        printf("<<<<<<<<<<<<<<<-MENU->>>>>>>>>>>>>>>\n");
        printf("\n 1.ENQUEUE \n 2.DEQUEUE \n 3.Display \n 4.Exit \n");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("ENTER THE DATA TO ENQUEUE: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("QUITTING......PRESS ANY KEY!!");
                break;
                
            default:
                printf("INVALID CHOICE! TRY AGAIN.\n");
        }
        
    } while (choice != 4);

    return 0; 
}

void enqueue(int x) {
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("MEMORY NOT SUFFICIENT !! ");
        return;
    }
    newnode->data = x;
    newnode->next = NULL;

    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("%d WAS ENQUEUED! \n", x);
}

void dequeue() {
    node *temp;
    if (front == NULL) {
        printf("QUEUE UNDERFLOW!\n");
        return;
    }

    temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }

    printf("DEQUEUED DATA IS: %d\n", temp->data);
    free(temp);
}

void display() {
    node *temp;
    if (front == NULL) {
        printf("QUEUE IS EMPTY!\n");
    } else {
        printf("DATA ITEMS IN QUEUE ARE: ");
        temp = front;
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


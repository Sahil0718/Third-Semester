#include <stdio.h>
#include <stdlib.h>

// Structure of a circular linked list node
struct cllist {
    int info;
    struct cllist* next;
};

typedef struct cllist node;

node *start, *last, *newnode;

// Function to add a node at the beginning of the circular linked list
void addbeginning(int x) {
    newnode = (node*)malloc(sizeof(node));
    newnode->info = x;
    if (start == NULL) {
        start = newnode;
        last = newnode;
        last->next = start;
    } else {
        newnode->next = start;
        start = newnode;
        last->next = start;
    }
}

// Function to add a node at the end of the circular linked list
void addLast(int x) {
    newnode = (node*)malloc(sizeof(node));
    newnode->info = x;
    if (last == NULL) {
        start = newnode;
        last = newnode;
        last->next = start;
    } else {
        last->next = newnode;
        last = newnode;
        last->next = start;
    }
}

// Function to insert a node at the nth position of the circular linked list
void insertNth(int x, int position) {
    newnode = (node*)malloc(sizeof(node));
    newnode->info = x;
    if (start == NULL) {
        start = newnode;
        last = newnode;
        last->next = start;
    } else {
        if (position <= 1) {
            addbeginning(x);
            return;
        }
        node* temp = start;
        int count = 1;
        while (count < position - 1 && temp->next != start) {
            temp = temp->next;
            count++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        if (temp == last) {
            last = newnode;
        }
    }
}

// Function to delete a node from the beginning of the circular linked list
void deleteBeginning() {
    if (start == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    } else if (start == last) {
        free(start);
        start = last = NULL;
    } else {
        node* temp = start;
        start = start->next;
        last->next = start;
        free(temp);
    }
}

// Function to delete a node from the end of the circular linked list
void deleteEnd() {
    if (start == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    } else if (start == last) {
        free(start);
        start = last = NULL;
    } else {
        node* temp = start;
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = start;
        free(last);
        last = temp;
    }
}
// Function to delete a node from the nth position of the circular linked list
void deleteNth(int position) {
    if (start == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    }
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        deleteBeginning();
        return;
    }
    int count = 1;
    node* temp = start;
    node* prev = NULL;
    while (count < position && temp->next != start) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (temp == start) {
        printf("Position exceeds the length of the circular linked list\n");
        return;
    }
    if (temp == last) {
        deleteEnd();
        return;
    }
    prev->next = temp->next;
    free(temp);
}
// Function to display the circular linked list
void display() {
    if (start == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    }
    node* temp = start;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != start);
    printf("\n");
}

int main() {
    int choice, x, position;

    start = last = NULL;

    printf("<<<<<<<<<-MENU->>>>>>>>>\n");
    printf("\n 1. Insert at the beginning\n 2. Insert at the end\n 3. Insert at nth position\n 4. Delete from the beginning\n 5. Delete from the end\n 6. Delete from the nth position \n 7. Display\n 8. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the beginning: ");
                scanf("%d", &x);
                addbeginning(x);
                break;
            case 2:
                printf("Enter the element to insert at the end: ");
                scanf("%d", &x);
                addLast(x);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &x);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertNth(x, position);
                break;
            case 4:
                deleteBeginning();
                printf("Deleted from the beginning\n");
                break;
            case 5:
                deleteEnd();
                printf("Deleted from the end\n");
                break;
            case 6:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                deleteNth(position);
                printf("Deleted from position %d \n", position, );
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (choice != 8);

    return 0;
}


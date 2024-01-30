#include <stdio.h>

#define MAX_SIZE 100

void displayList(int list[], int size) {
    if (size == 0) {
        printf("The list is empty.\n");
    } else {
        printf("Elements in the list: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", list[i]);
        }
        printf("\n");
    }
}

void insertElement(int list[], int* size, int element) {
    if (*size == MAX_SIZE) {
        printf("List is full. Cannot insert element.\n");
    } else {
        list[*size] = element;
        (*size)++;
        printf("Element %d inserted successfully.\n", element);
    }
}

void deleteElement(int list[], int* size, int element) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (list[i] == element) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                list[j] = list[j + 1];
            }
            (*size)--;
            break;
        }
    }

    if (found) {
        printf("Element %d deleted successfully.\n", element);
    } else {
        printf("Element %d not found in the list.\n", element);
    }
}

int searchElement(int list[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (list[i] == element) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int list[MAX_SIZE];
    int size = 0;
    int choice, element;

    do {
        printf("\n---- Linear List Menu ----\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Search element\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(list, &size, element);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                deleteElement(list, &size, element);
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                if (searchElement(list, size, element)) {
                    printf("Element %d found in the list.\n", element);
                } else {
                    printf("Element %d not found in the list.\n", element);
                }
                break;
            case 4:
                displayList(list, size);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}


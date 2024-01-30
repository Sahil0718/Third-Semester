#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int A[10], int n) {
    int i, temp, j;
    for (i = 0; i < n; i++) {
        temp = A[i];
        j = i - 1;
        while (j >= 0 && temp < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}

int main() {
    int A[10], n, i;
    printf("ENTER THE NUMBER OF ELEMENTS FOR SORTING: \n");
    scanf("%d", &n);
    printf("ENTER THE ELEMENTS FOR SORTING: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("THE ELEMENTS BEFORE SORTING ARE:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
    insertion_sort(A, n);
    printf("\nTHE ELEMENTS AFTER SORTING ARE: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");
    return 0;
}

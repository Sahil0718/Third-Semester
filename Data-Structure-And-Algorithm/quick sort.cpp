#include <stdio.h>

int partition(int a[], int lb, int ub) {
    int down, up, p, temp;
    p = a[lb];
    down = lb;
    up = ub;
    while (down < up) {
        while (a[down] <= p && down <= ub) {
            down++;
        }
        while (a[up] > p && up >= lb) {
            up--;
        }
        if (down < up) {
            temp = a[down];
            a[down] = a[up];
            a[up] = temp;
        }
    }
    a[lb] = a[up];
    a[up] = p;
    return up;
}

void quick_sort(int a[], int lb, int ub) {
    int pl;
    if (lb < ub) {
        pl = partition(a, lb, ub);
        quick_sort(a, lb, pl - 1);
        quick_sort(a, pl + 1, ub);
    }
}

int main() {
    int a[10], i, n;
    printf("How many integers to sort? ");
    scanf("%d", &n);
    if (n > 10) {
        printf("Maximum limit exceeded. Please enter up to 10 integers.\n");
        return 1; // Exit with an error code
    }
    printf("Enter %d integers to sort: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Before sorting list is: ");
    for (i = 0; i < n; i++)
        printf("%-6d", a[i]);
    quick_sort(a, 0, n - 1);
    printf("\nAfter sorting list is: ");
    for (i = 0; i < n; i++)
        printf("%-6d", a[i]);
    printf("\n");
    return 0; // Exit successfully
}

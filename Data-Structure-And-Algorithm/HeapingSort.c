#include <stdio.h >
#include <stdlib.h>
#include <conio.h>

void swap(int *p, int *q)
{
    int t;
    t = *p;
    *p = *q;
    *q = t;
}

void heapify(int a[], int n, int i)
{
    int largest, lc, rc;
    largest = i;
    lc = 2 * i + 1;
    rc = lc + 1;
    if (lc < n && a[lc] > a[largest])
        largest = lc;
    if (rc < n && a[rc] > a[largest])
        largest = rc;
    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void main()
{
    int a[10], i, n;
    printf("HOW MANY INTEGERS TO SORT? ");
    scanf("%d", &n);
    printf("ENTER %d INTEGER TO SORT: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("BEFORE SORTING LIST IS: ");
    for (i = 0; i < n; i++)
        printf("%-6d", a[i]);
    heap_sort(a, n);
    printf("\n AFTER SORTING LIST IS: ");
    for (i = 0; i < n; i++)
        printf("%-6d", a[i]);
    getch();
}
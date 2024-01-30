#include <stdio.h>
#include <stdlib.h>

void shell_sort(int a[], int n)
{
    int incr[] = {5, 3, 1}; // sub-files declared manually
    int i, j, shift;
    for (i = 0; i < 3; i++)
    {
        shift = incr[i];

        for (j = shift; j < n; j += shift)
        {
            int temp, k;
            temp = a[j]; // the previous element is a[k]
            k = j - shift;
            while (temp < a[k] && k >= 0)
            {
                a[k + 1] = a[k]; // a[k]is shifted one position to the right to make room for the current element
                k -= shift;      // k gets decremented by shift to compare the current element with the previous element
            }
            if (k < j - shift)
                a[k + shift] = temp; // after correct position is found i.e k becomes negative
        }
    }
}

int main()
{

    int a[10], i, n;
    printf("How many integer to sort? ");
    scanf("%d", &n);
    printf("Enter %d integer to sort: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Before Sorting list is : ");
    for (i = 0; i < n; i++)
    {
        printf("%-6d", a[i]);
    }
    shell_sort(a, n);
    printf("\nAfter Sorting list is : ");
    for (i = 0; i < n; i++)
    {
        printf("%-6d", a[i]);
    }
    return 0;
}
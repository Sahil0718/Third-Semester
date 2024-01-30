#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a[100], sum = 0, x;
    int n, i;

    printf("\n ENTER THE DEGREE OF THE POLYNOMIAL X: ");
    scanf("%d", &n);

    printf("\n ENTER THE COEFFICIENT OF THE POLYNOMIAL X: \n");

    for (i = n; i >= 0; i--)
    {
        printf("\nENTER THE COEFFICIENT OD [X^%d]: ", i);
        scanf("%f", &a[i]);
    }

    printf("\n ENTER THE VALUE OF X: ");
    scanf("%f", &x);

    for (i = n; i > 0; i--)
    {
        sum = (sum + a[i]) * x;
    }
    sum = sum + a[0];
    printf("\n Value of the polynomial is = [%f]\n", sum);
    return 0;
}
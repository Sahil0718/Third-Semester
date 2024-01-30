#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, n;
    float A[20][20], r, x[10], sum = 0.0;
    printf("\n ENTER THE ORDER OF THE MATRIX: ");
    scanf("%d", &n);

    printf("ENTER THE ELEMENTS OF THE AUGMENTED MATRIX ROW WISE :\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    // GENERATING OF UPPER TRIANGULAR MATRIX
    for (j = 0; j < n; j++)
    {
        for (i = j + 1; i < n; i++)
        {
            r = A[i][j] / A[j][j];
            for (k = 0; k <= n; k++)
            {
                A[i][k] = A[i][k] - r * A[j][k];
            }
        }
    }

    x[n - 1] = A[n - 1][n] / A[n - 1][n - 1];

    // BACKWARD SUBSTITUTION
    for (i = n - 2; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j < n; j++)
        {
            sum = sum + A[i][j] * x[j];
        }
        x[i] = (A[i][n] - sum) / A[i][i];
    }

    printf("\n THE SOLUTION IS: \n");
    for (i = 0; i < n; i++)
    {
        printf("\n%d = %f\t", i + 1, x[i]);
    }
    return 0;
}
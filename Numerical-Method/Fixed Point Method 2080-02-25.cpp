#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

float g(float x)
{
    float y;
    y = 2.0 - x * x;
    return y;
}
int main()
{
    float x0, x, error, E = 0.00001;
    printf("INPUT INITIAL ESTIMATE OF A ROOT: \n");
    scanf("%f", &x0);
    while (1)
    {
        x = g(x0);
        error = (x - x0) / x;
        if (fabs(error) < E)
        {
            printf("\nRoot = %f", x0);
            break;
        }
        x0 = x;
    }
    getch();
    return 0;
}

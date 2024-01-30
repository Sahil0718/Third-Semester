#include <stdio.h>
#include <conio.h>
#include <math.h>
int decimaltobinary(long n)
{
    int remainder;
    long binary = 0;
    int i = 1;
    while (n != 0)
    {
        remainder = n % 2;
        n = n / 2;
        binary = binary + (remainder * i);
        i = i * 10;
    }
    return binary;
}
int main()
{
    long integernum;
    printf("ENTER A DECIMAL NUMBER:");
    scanf("%d", &integernum);
    printf("THE EQUIVALENT BINARY NUMBER IS: %d", decimaltobinary(integernum));
    getch();
    return 0;
}

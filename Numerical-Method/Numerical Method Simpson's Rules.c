/*
//SIMPSONS 1/3 RULE
#include <stdio.h>
#include <conio.h>
#include <math.h>

float f(float x){
//return (1-exp(-x/2.0));
return sin(sqrt(x));    //use initial and final points as 0 and 2 , where n = 8
}
void main(){
float a,b,h,x, ans, sum = 0;
int n,i;
printf("ENTER THE INITIAL AND FINAL VALUE OF X: \n");
scanf("%f%f", &a, &b);
printf("\nNUMBER OF SEGMENTS: ");
scanf("%d", &n);
h = (b-a)/n;
for(i = 1; i<n; i++){
    x = a+i*h;
    if(i%2 == 0){
        sum = sum + 2*f(x);
    }else{
    sum = sum + 4*f(x);
    }
}
ans = (h/3)*(f(a) + f(b) +sum);
printf("\nINTERGRAL VALUE OF F(x) = %f", ans);
getch();
}
*/

/*
//SIMPSON 3h/8 RULE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
//return (1-exp(-x/2.0))
return cos(x);   //use 0 and 1.57079 as initial and final points and n = 8
;
}
void main(){
float a,b,h,x,ans, sum =0;
int n,i;
printf("ENTER THE INITIAL AND FINAL VALUE OF X: \n");
scanf("%f%f", &a, &b);
printf("\nNUMBER OF SEGMENTS: ");
scanf("%d", &n);
h = (b-a)/n;
for(i = 1; i<n; i++){
    x = a+i*h;
    if(i%3 == 0){
        sum = sum + 2*f(x);
    }else{
    sum = sum+3*f(x);
    }
}
ans = (3*h/8)*(f(a) + f(b) +sum);
printf("\nINTERGRAL VALUE OF F(x) = %f", ans);
getch();
}
*/

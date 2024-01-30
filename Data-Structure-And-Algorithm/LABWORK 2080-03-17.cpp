/*
#include <stdio.h>
#include <stdlib.h>

float power(float b, int p){
	if(p==0)
		return 1.0;
	else if(p>0)
		return (b * power(b, p-1));
	else
		return (power(b,p+1)/b);
}

int main(){
	float b;
	int p;
	printf("ENTER THE COEFFICIENT: " );
	scanf("%f", &b);
	printf("ENTER THE POWER: ");
	scanf("%d" , &p);
	printf("THE RESULT WILL BE: %g", power(b,p));
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

int fact(int n){
	if(n == 0){
		return 1;
	}
	else{
		return (n*(n-1));
	}
}

int main(){
	int number;
	printf("ENTER THE Nth number for the factorial: ");
	scanf("%d", &number);
	printf("THE FACTORIAL OF NON_NEGATIVE IS: %d\t", fact(number));
	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int GCD(int a , int b){
	if(b == 0){
		return a;
	}else{
		return GCD(b,a%b);
	}
}

int main(){
	int a, b;
	printf("ENTER THE FIRST NUMBER: ");
	scanf("%d", &a);
	printf("ENTER THE SECOND NUMBER: ");
	scanf("%d", &b);
	
	printf("THE GCD OF THE NUMBERS ARE: %d", GCD(a,b));
	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
	if(n == 0){
		return 0;
	}
	else if(n == 1){
		return 1;
	}
	else{
		return (fibonacci(n-1)+fibonacci(n-2));
	}
}

int main(){
	int n,i;
	printf("ENTER THE N for the fibonacci: ");
	scanf("%d", &n);
	printf("THE FIBONACCI ELEMENTS ARE: ");
	for(i = 0; i < n ; i++){
		printf("%d \t", fibonacci(i));
	}
	return 0;
}

*/

/*
#include <stdio.h>
#include <stdlib.h>
static int count = 0;
int TOH(int n , char from , char to , char by){
	if(n == 1){
		printf("MOVE DISK %d FROM %c to %c\n", n, from,to); //source to destination
		count++;
	}
	else{
	TOH(n-1, from ,by, to); //From source to auxillary using destination
	printf("MOVE DISK %d FROM %c to %c\n", n,from,to);
	TOH(n-1,by, to , from); //FROM AUXILLARY TO DESTINATION USING SOURCE
	count++;
	}	
	return count;
}

int main(){
	int n;
	printf("ENTER THE NUMBER OF DISC: " );
	scanf("%d" ,&n);
	TOH(n,'L','R','C');
        printf("\nTHE NUMBERS OF STEPS REQUIED IS: %d", count);
	return 0;
}
*/

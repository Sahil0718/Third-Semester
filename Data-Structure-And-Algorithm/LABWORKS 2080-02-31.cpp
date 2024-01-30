//WAP to read N integer numbers dynamically and find the largest number

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
	int SIZE, *ptr;
	int max[SIZE],i;
	printf("ENTER THE SIZE OF THE ARRAY: ");
	scanf("%d", &SIZE);
	
	ptr = (int *)malloc(SIZE * sizeof(int));
	
	if( ptr == '\0'){
		printf("MEMORY ALLOCATION FAILED!!");
		getch();
		exit(0);
	}
	
	printf("ENTER THE %d INTEGER FOR ARRAY: \n", SIZE);
	for(i = 0; i<SIZE; i++){
		scanf("%d", ptr+i);
	}
	
	printf("NUMBERS YOU ENTERED ARE: \n");
	for(i = 0 ; i<SIZE; i++){
		printf("%d\t", *(ptr+i));
	}
	
	for(i = 0 ; i<SIZE; ++i){
		if(*ptr < *(ptr+i)){
			*ptr = *(ptr+i);
		}
	}
	printf("LARGEST NUMBERS IN THE ARRAY ALLOCATED DYNAMICALLY IS: %d ", *ptr);

}

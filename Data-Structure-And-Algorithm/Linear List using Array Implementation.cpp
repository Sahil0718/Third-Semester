#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>


int list[5]; //declaration of array
int SIZE = 5;

void Entry(){
	int i; 
	//int count;
	for(i = 0; i<SIZE ; i++){
		scanf("%d", &list[i]);
		  //to find out the number of elements in the list
	}
}
void Insert(int position){
	int i,number;
	if(position-1 == SIZE){
	
		printf("THE POSITION IS NOT VALID!");
		exit(1);
	}
	else{
	
		printf("WHAT NUMBER DO YOU WANT TO INSERT? :"); //insertion of the element at the required position  
		scanf("%d", &number);
	
		for(i = SIZE-1 ; i>= position-1; i--){ //shifting from right
			list[i+1] = list[i];
		
	
}
		list[position-1] = number;
        SIZE++;
}
}

void Delete(int position){
	int i ;
	//printf("THE DELETED ITEM IS : %d", list[position - 1]); 
	for(i = position-1 ; i<=SIZE-1; i++){
		list[i] = list[i+1];
	
	}
	
	SIZE--;
}

void traverse(){
	int i;
	for(i = 0; i<SIZE ; i++){
		printf("%d\t", list[i]);
	}
}

void search(){
	int key,i; //the number that you want to find out
	printf("ENTER THE KEY: " );
	scanf("%d", &key);
	
	for( i = 0; i<SIZE ; i++){
		if(list[i] == key){
			printf("THE NUMBER YOU SEARCHED FOR IS FOUND!! : %d", i+1);
			break;
		}
	}
}

int main(){
	int choice ,x ;
	MENU:
		system("cls");
		printf("1.ENTER THE LIST \n");
		printf("2.ADD IN THE REQUIRED POSITION\n");
		printf("3.DELETE AT THE REQUIRED POSITION \n");
		printf("4.TRAVERSE A LIST\n");
		printf("5.SEARCH A CERTAIN NUMBER\n");
		printf("6.--EXIT--\n");
		printf("ENTER YOUR CHOICE: ");
		scanf("%d", &choice);
		
		
		switch(choice){
			case 1:
				Entry();
				break;
				
			case 2:
				printf("ENTER THE POSITION:");
				scanf("%d", &x);
				Insert(x);
				break;
				
				case 3:
					printf("ENTER THE POSITION:" );
					scanf("%d", &x);
					Delete(x);
					break;
					
					case 4:
						traverse();
						getch();
						break;
					case 5:
					search();
					getch();
					break;
					
					case 6:
					printf("NOW EXITING!!!");
					getch();
					exit(1);
		};
		if(choice != 7){
			goto MENU;
		}
		return 0;
}

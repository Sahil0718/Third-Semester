#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct stack{
	int data;
	struct stack *next;
};

typedef struct stack node;
node *newnode;
node *top = NULL;
 
 void push(int);
 void pop();
 void display();
 
 int main(){
 	int choice, x;
 	do{
 		printf("<<<<<<<<<<<<<<<-MENU->>>>>>>>>>>>>>>\n");
 		printf("\n 1.PUSH \n 2.POP \n 3.Display \n 4.Exit \n");
 		printf("\nENTER YOUR CHOICE: ");
 		scanf("%d", &choice);
 		
 		switch(choice){
 			case 1:
 				printf("ENTER THE DATA TO PUSH: ");
 				scanf("%d", &x);
 				push(x);
 				break;
 			
 			case 2:
 				pop();
 				break;
 			
 			case 3:
 				display();
 				break;
 			case 4:
 				printf("QUITING......PRESS ANY KEY!!");
 				break;
 			}
 				getch();
		 }
		 while(choice !=4 );
		 
	 }
	 
	 void push(int x){
	 	newnode = (node *)malloc(sizeof(node));
	 	if(newnode  == NULL){
	 		printf("MEMORY NOT SUFFICIENT !! ");
	 		return ;
	 		
		 }
		 if(top == NULL){
		 	newnode -> data = x;
		 	newnode -> next = NULL;
		 	top = newnode;
		 	
		 }
		 else{
		 	newnode -> data = x;
		 	newnode -> next = top;
		 	top = newnode;
		 }
		 printf("%d WAS PUSHED! \n", x);
	 }
	 
	 void pop(){
	 	node  *temp;
	 	if(top == NULL){
	 		printf("STACK UNDERFLOW!");
	 		return;
		 }
		 printf("POPED DATA IS: %d", top -> data);
		 temp = top;
		 top = top -> next;
		 free(temp);
	 }
	 
	 void display(){
	 	node *temp;
	 	if(top == NULL){
	 		printf("STACK IS EMPTY!");
	 		
		 }else{
		 	printf("DATA ITEM IN STACK ARE :");
		 	temp = top ;
		 	while(temp != NULL){
		 		printf("%d\t", temp -> data );
		 		temp = temp -> next;
			 }
		 }
	 }
 

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define size 5

 struct linearqueue{
 	int lq[size];
 	int front,rear;
 	int x;
 };
 
 typedef struct linearqueue lqueue;
 
 
 void enqueue(lqueue *);
 void dequeue(lqueue *);
 void display(lqueue);
 
int main(){
 	int choice;
 	lqueue q;
 	q.front = 0;
 	q.rear = -1;
 	do {
 		system("cls");
 		printf("-----------MENU-----------");
 		printf("\n 1.ENQUEUE \n 2.DEQUEUE \n 3.Display \n 4.Exit \n");
 		printf("ENTER YOUR DESIRED CHOICE:");
 		scanf("%d", &choice);
 		
 		switch(choice){
 			case 1:
 				enqueue(&q);
 				break;
 			
 			case 2:
 				dequeue(&q);
 				getch();
 				break;
 			
 			case 3:
 				display(q);
 				getch();
 				break;
 				
 			case 4:
 				printf("QUITING>>>>>>PRESS ANY KEY!!");
 				getch();
 				break;
 		}
 		
		 }
		 while(choice != 4); //if 4 then exit
		 
	 }
	 
	 void enqueue(lqueue *q){
	 	int x;
		 if(q->rear == size-1){
	 		printf("OHH NO! , THE QUEUE IS FULL!");
	 		getch();
	 		return;
		 }
		 printf("ENTER THE DATA TO INSERT: ");
		 scanf("%d",&x);
		 q -> lq[++q -> rear] = x;
		 
	 }
	 
	 void dequeue(lqueue *q) {
	 	if(q -> rear < q -> front){
	 		printf("QUEUE IS EMPTY!!");
	 		getch();
	 		return; 
	 	}
	 	printf("DELETED ELEMENT IS: %d", q -> lq[q -> front]);
	 	int i ; 
	 	
		 for(i = q -> front+1 ; i<= q -> rear; i++){
	 		q -> lq[i-1] = q -> lq[i];
		 }
		 q -> rear--;
		 }
		
	 void display(lqueue q){
	 	if(q.rear < q.front){
	 		printf("QUEUE IS EMPTY !!");
	 		getch();
	 		return; 
		 }
		 printf("ELEMENTS ON QUEUE ARE: ");
		 for(int i = q.front; i<= q.rear; i++){
		 	printf("%d\t", q.lq[i]);
		 }
	 }
 

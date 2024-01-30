#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5

struct Queue{
	int front;
	int rear;
	int Que[SIZE]; 
};
void Enqueue(struct Queue *Q){
	int num;
	//printf("rr");
	if((Q->rear+1)%SIZE == Q->front){
		printf("The Queue is full");
		//return;
		getch();
	}
	else{
		printf("Enter a number to enqueue: ");
		scanf("%d",&num);
		Q->rear=(Q->rear+1)%SIZE;
		Q->Que[Q->rear]=num;
	}
}
void Dequeue(struct Queue *Q){ //this function dequeues 
	int number;
	if(Q->rear==Q->front){
		printf("The Queue is empty: ");
		return;
	}
	else{
		Q->front=(Q->front+1)%SIZE;
		number=Q->Que[Q->front];
		printf("The dequeued item is %d",number);
		getch();
	}
}
void show(struct Queue Q){
	int i;
	if(Q.front==Q.rear)
		printf("Empty");
	else if(Q.front<Q.rear){
		for(i=Q.front+1;i<=Q.rear;i++){ //displays queue when front is smaller than rear
			printf("%d\t",Q.Que[i]);
		}
	}
	else {
	for(i=Q.front+1;i<=SIZE-1;i++){  //displaying when front is lesser than rear 
		printf("%d\t",Q.Que[i]);
	}
	for(i=0;i<=Q.rear;i++){
		printf("%d\t",Q.Que[i]); //displaying from index [0] to rear 
	}
	}
}
	int main(){
	int ch;
	int Dequeued;
	struct Queue Q;
	Q.front=SIZE -1;
	Q.rear=SIZE-1;
	MENU:
		
		system("cls");
		printf("1.Enqueue Operation\n");
		printf("2.Dequeue Operation\n");
		printf("3.Display Queue\n");
		printf("4.Exit\n");
		printf("What do you want to operate? ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				Enqueue(&Q);
				break;
				//return;
			case 2:
				Dequeue(&Q);
				//printf("%d has been dequeued",Dequeued);
				
				break;
				
				//return;
            case 3:
			show(Q);
				getch();
				break;
				//return;
			/*case 4:
			    printf("Exiting.... Please press a key");
				exit(1);*/	
		}
	if(ch!=4){
		goto MENU;
	}
	return 0;
}



#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 5

int arr[size];
int top = -1;
void push(int data);
void pop();
void display();

void main()
{
	char ch;
	int num, choice;
	do
	{
		printf("------------------MENU-------------------");
		printf("\n 1.Push");
		printf("\n 2.Pop");
		printf("\n 3.DISPLAY THE ITEMS: ");
		printf("\n 4.ENTER YOUR CHOICE: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\n ENTER THE ITEM TO PUSH: ");
			scanf("%d", &num);

			push(num);
			break;

		case 2:
			pop();
			break;

		case 3:
			display();
			break;

		default:
			printf("\nINVALID CHOICE!!");
		}
		printf("\n DO YOU WANT TO CONTINUE? : ");
		scanf("%s", &ch);
	} while (ch == 'Y' || ch == 'y');
}

void push(int data)
{
	if (top >= size - 1)
	{
		printf("STACK IS FULL AND CANNOT ADD MORE ITEMS!!");
	}
	else
	{
		top++;
		arr[top] = data;
		printf("ITEM IS PUSHED IN STACK !!");
	}
}

void pop()
{
	if (top < 0)
	{
		printf("STACK IS EMPTY CANNOT POP!! ");
	}
	top--;
}

void display()
{
	int i;
	for (i = 0; i <= top; i++)
	{
		printf("\n %d", arr[i]);
	}
}
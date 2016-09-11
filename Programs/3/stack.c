#include<stdio.h>
#include<stdlib.h>
int arr[20];
int top=-1, max=20;

void menu(){
	printf("\n-----MENU-----\n1. Insert\n2. Pop\n3. Peek\n4. Print\n 5. Exit\n");
}
void insert(int n)
{
	if(top==max-1)
	{
		printf("Stack is full!");
	}
	else
	{
		top++;
		arr[top]=n;
	}
}

void pop()
{
	if(top==-1)
	{
		printf("Stack is empty!");
	}
	else
	{
		top--;
	}
}

void peek()
{
	if(top==-1)
		printf("Stack is empty!");
	else
		printf("%d", arr[top]);
}

void print()
{
	for(int i=0;i<=top;i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int opt,n;
	menu();
	do{
		printf("\n\t> ");
		scanf("%d", &opt);
		switch(opt)
		{
			case(1):
				printf("Enter the element: ");
				scanf("%d", &n);
				insert(n);
				break;
			case(2):
				pop();
				break;
			case(3):
				peek();
				break;
			case(4):
				print();
				break;
			case(5):
				exit(0);
			default:
				printf("Invalid option!");
		}
	}while(1);
}
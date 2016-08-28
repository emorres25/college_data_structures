#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
struct node *head = NULL;


void printlist()
{
	struct node *current;
	printf("The following is the created list: \n");

	current = head;
	while(current!=NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}


void createlist(int n)
{
	struct node *new_node, *current;
	int i;
	for(i=0;i<n;i++)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		printf("Enter the data for %d student: ", i+1);
		scanf("%d", &new_node->data);

		if(head==NULL)
		{
			head = new_node;
			current=new_node;
		}
		else{
			current->next = new_node;
			current = new_node;
		}
	}
}

void deletelist(int del_roll)
{
	int i=1,n;
	struct node *current,*new_node;
	current = head;
	while(current!=NULL)
	{
		//printf("%d ", current->data);
		if(current->data == del_roll){
			printf("Value found at %d\n", i);
			break;
		}
		current = current->next;
		i+=1;
	}
	
	//Deleting
	current = head;
	for(n=0;n<i-2;n++)
	{
		current = current->next;
	}
	new_node = current->next;
	current->next = new_node->next;

}

int main()
{
	int n,i, pos, new_data, del_roll;
	struct node *new_node, *current;
	
	printf("Enter the number of students: ");
	scanf("%d", &n);

	createlist(n);
	printlist();

	printf("Which roll number do you want to delete?");
	scanf("%d", &del_roll);

	deletelist(del_roll);

	printlist();

	return 0;
}